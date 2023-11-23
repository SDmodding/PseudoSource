// File Line: 61
// RVA: 0x1543DE0
__int64 dynamic_initializer_for__UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList__);
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
void __fastcall UFG::CharacterSubjectComponent::CharacterSubjectComponent(
        UFG::CharacterSubjectComponent *this,
        unsigned int name_uid)
{
  __int64 v3; // rbp
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0> *p_pSocialTargetOverrideComponent; // rsi
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *mPrev; // rax
  UFG::qSymbol *p_mUID; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  UFG::qVector4 v25; // xmm4
  UFG::qVector4 v26; // xmm3
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm3
  UFG::qVector4 v29; // xmm3
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax

  UFG::CameraSubject::CameraSubject(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent>;
  this->mNext = &this->UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterSubjectComponent::`vftable;
  v3 = 4i64;
  `eh vector constructor iterator(
    this->mContextOverrideScriptGlobal,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(
    this->mContextOverrideFreemanNPC,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(
    this->mContextOverrideFreemanPlayer,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(
    this->mContextOverrideScriptLocal,
    8ui64,
    4,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  *(_QWORD *)&this->mBox.mMin.x = 0i64;
  *(_QWORD *)&this->mBox.mMin.z = 0i64;
  *(_QWORD *)&this->mBox.mMax.y = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&this->pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->pTargetingSystemBaseComponent);
  p_pSocialTargetOverrideComponent = &this->pSocialTargetOverrideComponent;
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>(&this->pSocialTargetOverrideComponent);
  mPrev = UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev;
  UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *)&UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList;
  UFG::CharacterSubjectComponent::s_CharacterSubjectComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CharacterSubjectComponent::_CharacterSubjectComponentTypeUID,
    "CharacterSubjectComponent");
  *(_QWORD *)&this->mIsHostage = 0i64;
  *(_WORD *)&this->mSprinting = 0;
  *(_QWORD *)&this->mActionHijacking = 0i64;
  p_mUID = (UFG::qSymbol *)&this->mContextOverrideScriptGlobal[0].mUID;
  do
  {
    p_mUID[-1].mUID = UFG::gNullQSymbol.mUID;
    p_mUID->mUID = -1;
    p_mUID[7].mUID = UFG::gNullQSymbol.mUID;
    p_mUID[8].mUID = -1;
    p_mUID[15].mUID = UFG::gNullQSymbol.mUID;
    p_mUID[16].mUID = -1;
    p_mUID[23].mUID = UFG::gNullQSymbol.mUID;
    p_mUID[24].mUID = -1;
    p_mUID += 2;
    --v3;
  }
  while ( v3 );
  this->mTypeOverrideFreeman = -1;
  this->bGotoRise = 0;
  *(_QWORD *)&this->rGotoRise = 0i64;
  this->rGotoRisePatience = 0.0;
  this->bGotoRadius = 0;
  *(_QWORD *)&this->rGotoRadius = 0i64;
  this->rGotoRadiusPatience = 0.0;
  this->bGotoAngle = 0;
  *(_QWORD *)&this->rGotoAngle = 0i64;
  this->rGotoAnglePatience = 0.0;
  *(_WORD *)&this->bGotoAngleWorldSpace = 0;
  this->rGotoAngleSecond = 0.0;
  *(_WORD *)&this->bGotoAngleFarthestAngle = 0;
  this->bElevationLock = 0;
  *(_QWORD *)&this->rLockedElevationDef = 0i64;
  *(_QWORD *)&this->rLockedElevationHip = 0i64;
  *(_QWORD *)&this->rLockedElevationFocusCreatureCambone = 0i64;
  this->rLockedElevationFocusCreatureHead = 0.0;
  this->mParkourHandle = 0i64;
  this->mFilteredSpeed = 0.0;
  this->mPositionFilterSpeed = 1.0;
  this->mVelocityFilterSpeed = 10.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mFilteredPosition.x = UFG::qVector3::msZero.x;
  this->mFilteredPosition.y = y;
  this->mFilteredPosition.z = z;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mFilteredVelocity.x = UFG::qVector3::msZero.x;
  this->mFilteredVelocity.y = v9;
  this->mFilteredVelocity.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mLastAliveHeadPosition.x = UFG::qVector3::msZero.x;
  this->mLastAliveHeadPosition.y = v11;
  this->mLastAliveHeadPosition.z = v12;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  this->mAntiJitterPosition.x = UFG::qVector3::msZero.x;
  this->mAntiJitterPosition.y = v13;
  this->mAntiJitterPosition.z = v14;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  this->mGrapplePosition.x = UFG::qVector3::msZero.x;
  this->mGrapplePosition.y = v15;
  this->mGrapplePosition.z = v16;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  this->mHeadPosition.x = UFG::qVector3::msZero.x;
  this->mHeadPosition.y = v17;
  this->mHeadPosition.z = v18;
  v19 = UFG::qVector3::msZero.y;
  v20 = UFG::qVector3::msZero.z;
  this->mCambonePosition.x = UFG::qVector3::msZero.x;
  this->mCambonePosition.y = v19;
  this->mCambonePosition.z = v20;
  v21 = UFG::qVector3::msZero.y;
  v22 = UFG::qVector3::msZero.z;
  this->mPelvisPosition.x = UFG::qVector3::msZero.x;
  this->mPelvisPosition.y = v21;
  this->mPelvisPosition.z = v22;
  v23 = UFG::qVector3::msZero.y;
  v24 = UFG::qVector3::msZero.z;
  this->mSyncPosition.x = UFG::qVector3::msZero.x;
  this->mSyncPosition.y = v23;
  this->mSyncPosition.z = v24;
  v25 = 0i64;
  v26 = 0i64;
  v26.x = (float)1;
  this->mHeadTransformation.v0 = v26;
  this->mHeadTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v26, (__m128)v26, 81);
  this->mHeadTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v26, (__m128)v26, 69);
  this->mHeadTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v26, (__m128)v26, 21);
  v27 = 0i64;
  v27.x = (float)1;
  this->mCamboneTransformation.v0 = v27;
  this->mCamboneTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v27, (__m128)v27, 81);
  this->mCamboneTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v27, (__m128)v27, 69);
  this->mCamboneTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v27, (__m128)v27, 21);
  v28 = 0i64;
  v28.x = (float)1;
  this->mPelvisTransformation.v0 = v28;
  this->mPelvisTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v28, (__m128)v28, 81);
  this->mPelvisTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v28, (__m128)v28, 69);
  this->mPelvisTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v28, (__m128)v28, 21);
  v29 = 0i64;
  v29.x = (float)1;
  this->mSyncTransformation.v0 = v29;
  this->mSyncTransformation.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v29, (__m128)v29, 81);
  this->mSyncTransformation.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v29, (__m128)v29, 69);
  this->mSyncTransformation.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v29, (__m128)v29, 21);
  *(_QWORD *)&this->mBoneHead = -1i64;
  *(_QWORD *)&this->mBonePelvis = -1i64;
  this->mRadius = 0.0;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  this->mBox.mMin.x = UFG::qVector3::msZero.x;
  this->mBox.mMin.y = v30;
  this->mBox.mMin.z = v31;
  v32 = UFG::qVector3::msZero.y;
  v33 = UFG::qVector3::msZero.z;
  this->mBox.mMax.x = UFG::qVector3::msZero.x;
  this->mBox.mMax.y = v32;
  this->mBox.mMax.z = v33;
  if ( this->pSocialTargetOverrideComponent.m_pSimComponent )
  {
    v34 = p_pSocialTargetOverrideComponent->mPrev;
    mNext = this->pSocialTargetOverrideComponent.mNext;
    v34->mNext = mNext;
    mNext->mPrev = v34;
    this->pSocialTargetOverrideComponent.m_pSimComponent = 0i64;
LABEL_9:
    this->pSocialTargetOverrideComponent.m_pSimObject = 0i64;
    this->pSocialTargetOverrideComponent.mNext = &this->pSocialTargetOverrideComponent;
    p_pSocialTargetOverrideComponent->mPrev = p_pSocialTargetOverrideComponent;
    goto LABEL_10;
  }
  if ( this->pSocialTargetOverrideComponent.m_pSimObject )
  {
    v36 = p_pSocialTargetOverrideComponent->mPrev;
    if ( p_pSocialTargetOverrideComponent->mPrev != p_pSocialTargetOverrideComponent
      || this->pSocialTargetOverrideComponent.mNext != &this->pSocialTargetOverrideComponent )
    {
      v37 = this->pSocialTargetOverrideComponent.mNext;
      v36->mNext = v37;
      v37->mPrev = v36;
      goto LABEL_9;
    }
  }
LABEL_10:
  this->pSocialTargetOverrideComponent.m_Changed = 1;
  this->pSocialTargetOverrideComponent.m_TypeUID = UFG::CharacterSubjectComponent::_TypeUID;
  *(_DWORD *)&this->mHeadDirty = 16843009;
  v25.x = (float)1;
  this->mTargetWorld.v0 = v25;
  this->mTargetWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v25, (__m128)v25, 81);
  this->mTargetWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v25, (__m128)v25, 69);
  this->mTargetWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v25, (__m128)v25, 21);
}

// File Line: 159
// RVA: 0x51B120
void __fastcall UFG::CharacterSubjectComponent::~CharacterSubjectComponent(UFG::CharacterSubjectComponent *this)
{
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v2; // rbx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *mPrev; // rcx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *mNext; // rax
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v5; // rcx
  UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CharacterSubjectComponent::`vftable;
  if ( this == UFG::CharacterSubjectComponent::s_CharacterSubjectComponentpCurrentIterator )
    UFG::CharacterSubjectComponent::s_CharacterSubjectComponentpCurrentIterator = (UFG::CharacterSubjectComponent *)&this->mPrev[-18];
  v2 = &this->UFG::qNode<UFG::CharacterSubjectComponent,UFG::CharacterSubjectComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pSocialTargetOverrideComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pCharacterPhysicsComponent);
  `eh vector destructor iterator(this->mContextOverrideScriptLocal, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mContextOverrideFreemanPlayer, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mContextOverrideFreemanNPC, 8ui64, 4, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mContextOverrideScriptGlobal, 8ui64, 4, (void (__fastcall *)(void *))_);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::CameraSubject::~CameraSubject(this);
}

// File Line: 164
// RVA: 0x530BA0
UFG::SimObject *__fastcall UFG::RegionComponent::GetXformNode(UFG::RegionComponent *this)
{
  UFG::SimObject *result; // rax

  result = this->m_pSimObject;
  if ( result )
    return (UFG::SimObject *)result->m_pTransformNodeComponent;
  return result;
}

// File Line: 165
// RVA: 0x530AE0
UFG::TargetingSystemBaseComponent *__fastcall UFG::CharacterSubjectComponent::GetTargetingSystem(
        UFG::CharacterSubjectComponent *this)
{
  return (UFG::TargetingSystemBaseComponent *)this->pTargetingSystemBaseComponent.m_pSimComponent;
}

// File Line: 175
// RVA: 0x546110
UFG::CharacterSubjectComponent *__fastcall UFG::CharacterSubjectComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *scene_object_properties,
        bool required)
{
  unsigned int m_NameUID; // edi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = scene_object_properties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x4E0ui64, "CharacterSubjectComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::CharacterSubjectComponent::CharacterSubjectComponent((UFG::CharacterSubjectComponent *)v5, m_NameUID);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  m_pSimObject = scene_object_properties->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v9 = 37;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::CharacterSubjectComponent *)v7;
}

// File Line: 186
// RVA: 0x53D5B0
void __fastcall UFG::CharacterSubjectComponent::OnAttach(
        UFG::CharacterSubjectComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_pCharacterAnimationComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  UFG::CameraSubject::OnAttach(this, object);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->pCharacterPhysicsComponent,
    object);
  p_pCharacterAnimationComponent = &this->pCharacterAnimationComponent;
  if ( this->pCharacterAnimationComponent.m_pSimComponent )
  {
    mNext = this->pCharacterAnimationComponent.mNext;
    mPrev = p_pCharacterAnimationComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->pCharacterAnimationComponent.mNext = &this->pCharacterAnimationComponent;
    p_pCharacterAnimationComponent->mPrev = p_pCharacterAnimationComponent;
    goto LABEL_8;
  }
  if ( this->pCharacterAnimationComponent.m_pSimObject
    && (p_pCharacterAnimationComponent->mPrev != p_pCharacterAnimationComponent
     || this->pCharacterAnimationComponent.mNext != &this->pCharacterAnimationComponent) )
  {
    v7 = this->pCharacterAnimationComponent.mNext;
    v8 = p_pCharacterAnimationComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  this->pCharacterAnimationComponent.m_Changed = 1;
  this->pCharacterAnimationComponent.m_pSimObject = object;
  this->pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    p_pCharacterAnimationComponent,
    object);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->pTargetingSystemBaseComponent,
    object);
  UFG::CharacterSubjectComponent::UpdateTargetWorld(this);
}

// File Line: 198
// RVA: 0x53FF40
void __fastcall UFG::CharacterSubjectComponent::OnDetach(UFG::CharacterSubjectComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_pCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_pCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax

  p_pTargetingSystemBaseComponent = &this->pTargetingSystemBaseComponent;
  if ( this->pTargetingSystemBaseComponent.m_pSimComponent )
  {
    mPrev = p_pTargetingSystemBaseComponent->mPrev;
    mNext = this->pTargetingSystemBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_pTargetingSystemBaseComponent->m_pSimObject = 0i64;
    p_pTargetingSystemBaseComponent->mNext = p_pTargetingSystemBaseComponent;
    p_pTargetingSystemBaseComponent->mPrev = p_pTargetingSystemBaseComponent;
    goto LABEL_8;
  }
  if ( this->pTargetingSystemBaseComponent.m_pSimObject
    && (p_pTargetingSystemBaseComponent->mPrev != p_pTargetingSystemBaseComponent
     || this->pTargetingSystemBaseComponent.mNext != &this->pTargetingSystemBaseComponent) )
  {
    v5 = p_pTargetingSystemBaseComponent->mPrev;
    v6 = p_pTargetingSystemBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_pCharacterAnimationComponent = &this->pCharacterAnimationComponent;
  p_pTargetingSystemBaseComponent->m_Changed = 1;
  if ( this->pCharacterAnimationComponent.m_pSimComponent )
  {
    v8 = p_pCharacterAnimationComponent->mPrev;
    v9 = this->pCharacterAnimationComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->pCharacterAnimationComponent.mNext = &this->pCharacterAnimationComponent;
    p_pCharacterAnimationComponent->mPrev = p_pCharacterAnimationComponent;
    goto LABEL_15;
  }
  if ( this->pCharacterAnimationComponent.m_pSimObject
    && (p_pCharacterAnimationComponent->mPrev != p_pCharacterAnimationComponent
     || this->pCharacterAnimationComponent.mNext != &this->pCharacterAnimationComponent) )
  {
    v10 = p_pCharacterAnimationComponent->mPrev;
    v11 = this->pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->pCharacterAnimationComponent.m_Changed = 1;
  p_pCharacterPhysicsComponent = &this->pCharacterPhysicsComponent;
  if ( this->pCharacterPhysicsComponent.m_pSimComponent )
  {
    v13 = p_pCharacterPhysicsComponent->mPrev;
    v14 = this->pCharacterPhysicsComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->pCharacterPhysicsComponent.m_pSimObject = 0i64;
    this->pCharacterPhysicsComponent.mNext = &this->pCharacterPhysicsComponent;
    p_pCharacterPhysicsComponent->mPrev = p_pCharacterPhysicsComponent;
    goto LABEL_22;
  }
  if ( this->pCharacterPhysicsComponent.m_pSimObject
    && (p_pCharacterPhysicsComponent->mPrev != p_pCharacterPhysicsComponent
     || this->pCharacterPhysicsComponent.mNext != &this->pCharacterPhysicsComponent) )
  {
    v15 = p_pCharacterPhysicsComponent->mPrev;
    v16 = this->pCharacterPhysicsComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->pCharacterPhysicsComponent.m_Changed = 1;
  UFG::CameraSubject::OnDetach(this);
  *(_QWORD *)&this->mBoneHead = -1i64;
  *(_QWORD *)&this->mBonePelvis = -1i64;
}

// File Line: 213
// RVA: 0x55F750
void __fastcall UFG::CharacterSubjectComponent::UpdateFilteredVelocity(
        UFG::CharacterSubjectComponent *this,
        float delta_sec,
        UFG::qVector3 *raw_velocity)
{
  __m128 y_low; // xmm3
  float v4; // xmm5_4
  float v5; // xmm4_4
  __m128 v6; // xmm2
  float x; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4

  y_low = (__m128)LODWORD(raw_velocity->y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mFilteredVelocity.y;
  v4 = raw_velocity->z - this->mFilteredVelocity.z;
  v5 = COERCE_FLOAT(LODWORD(delta_sec) & _xmm) * this->mVelocityFilterSpeed;
  v6 = y_low;
  x = this->mFilteredVelocity.x;
  v8 = raw_velocity->x - x;
  v6.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v4 * v4);
  LODWORD(v9) = _mm_sqrt_ps(v6).m128_u32[0];
  if ( v5 > 0.00000011920929 && v9 > v5 )
  {
    v10 = v5 / v9;
    v8 = v8 * v10;
    y_low.m128_f32[0] = y_low.m128_f32[0] * v10;
    v4 = v4 * v10;
  }
  this->mFilteredVelocity.x = x + v8;
  y_low.m128_f32[0] = y_low.m128_f32[0] + this->mFilteredVelocity.y;
  v11 = v4 + this->mFilteredVelocity.z;
  LODWORD(this->mFilteredVelocity.y) = y_low.m128_i32[0];
  this->mFilteredVelocity.z = v11;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                            + (float)(this->mFilteredVelocity.x * this->mFilteredVelocity.x))
                    + (float)(v11 * v11);
  LODWORD(this->mFilteredSpeed) = _mm_sqrt_ps(y_low).m128_u32[0];
}

// File Line: 226
// RVA: 0x55F670
void __fastcall UFG::CharacterSubjectComponent::UpdateFilteredPosition(
        UFG::CharacterSubjectComponent *this,
        float delta_sec)
{
  __int64 v3; // rax
  float x; // xmm7_4
  float v5; // xmm6_4
  __m128 v6; // xmm3
  float v7; // xmm4_4
  __m128 v8; // xmm2
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm4_4

  v3 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[17].__vecDelDtor)(this);
  x = this->mFilteredPosition.x;
  v5 = COERCE_FLOAT(LODWORD(delta_sec) & _xmm) * this->mPositionFilterSpeed;
  v6 = (__m128)*(unsigned int *)(v3 + 4);
  v6.m128_f32[0] = v6.m128_f32[0] - this->mFilteredPosition.y;
  v7 = *(float *)(v3 + 8) - this->mFilteredPosition.z;
  v8 = v6;
  v9 = *(float *)v3 - x;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v9 * v9)) + (float)(v7 * v7);
  LODWORD(v10) = _mm_sqrt_ps(v8).m128_u32[0];
  if ( v5 > 0.00000011920929 && v10 > v5 )
  {
    v11 = v5 / v10;
    v9 = v9 * v11;
    v6.m128_f32[0] = v6.m128_f32[0] * v11;
    v7 = v7 * v11;
  }
  this->mFilteredPosition.x = x + v9;
  v12 = v7 + this->mFilteredPosition.z;
  this->mFilteredPosition.y = v6.m128_f32[0] + this->mFilteredPosition.y;
  this->mFilteredPosition.z = v12;
}

// File Line: 238
// RVA: 0x52FC40
void __fastcall UFG::CharacterSubjectComponent::GetRigidBodyPosition(
        UFG::CharacterSubjectComponent *this,
        UFG::qVector3 *dest)
{
  float y; // xmm1_4
  float z; // xmm2_4
  hkpRigidBody *RigidBody; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4

  y = this->mTargetWorld.v3.y;
  z = this->mTargetWorld.v3.z;
  dest->x = this->mTargetWorld.v3.x;
  dest->y = y;
  dest->z = z;
  if ( this->pCharacterPhysicsComponent.m_pSimComponent )
  {
    RigidBody = UFG::CharacterPhysicsComponent::GetRigidBody((UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent);
    if ( RigidBody )
    {
      v6 = RigidBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
      v7 = RigidBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
      LODWORD(dest->x) = RigidBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_i32[0];
      dest->y = v6;
      dest->z = v7;
    }
  }
}

// File Line: 252
// RVA: 0x561060
void __fastcall UFG::CharacterSubjectComponent::UpdateTargetWorld(UFG::CharacterSubjectComponent *this)
{
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
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  __int64 v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4

  v2 = (float *)((__int64 (*)(void))this->vfptr[16].__vecDelDtor)();
  v3 = v2[2];
  v4 = (__m128)*(unsigned int *)v2;
  v5 = v2[1];
  LODWORD(v6) = LODWORD(v3) & _xmm;
  if ( COERCE_FLOAT(LODWORD(v3) & _xmm) > 0.80000001 )
  {
    if ( v6 >= 1.0 )
      v6 = *(float *)&FLOAT_1_0;
    v7 = (__m128)(unsigned int)FLOAT_1_0;
    v8 = sinf((float)(v6 - 0.80000001) * 7.8539824);
    v9 = v8 * v8;
    v7.m128_f32[0] = 1.0 - (float)(v9 * v9);
    v10 = _mm_sqrt_ps(v7).m128_f32[0];
    v11 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[14].__vecDelDtor)(this);
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
    v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
  v18 = v14 * v17;
  v19 = v13.m128_f32[0] * v17;
  this->mTargetWorld.v0.w = 0.0;
  v20 = v15 * v17;
  this->mTargetWorld.v0.z = (float)(v18 * 0.0) - (float)(v19 * 0.0);
  this->mTargetWorld.v0.y = (float)(v20 * 0.0) - v18;
  this->mTargetWorld.v0.x = v19 - (float)(v20 * 0.0);
  this->mTargetWorld.v1.x = v18;
  *(_QWORD *)&this->mTargetWorld.v1.w = 0i64;
  this->mTargetWorld.v1.y = v19;
  this->mTargetWorld.v1.z = v20;
  this->mTargetWorld.v2.y = 0.0;
  vfptr = this->vfptr;
  *(_QWORD *)&this->mTargetWorld.v2.z = 1065353216i64;
  v22 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))vfptr[18].__vecDelDtor)(this);
  v23 = *(float *)(v22 + 52);
  v24 = *(float *)(v22 + 56);
  v25 = *(float *)(v22 + 60);
  this->mTargetWorld.v3.x = *(float *)(v22 + 48);
  this->mTargetWorld.v3.y = v23;
  this->mTargetWorld.v3.z = v24;
  this->mTargetWorld.v3.w = v25;
}

// File Line: 295
// RVA: 0x154CC10
__int64 UFG::_dynamic_initializer_for__symBip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBip01Head, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symBip01Head__);
}

// File Line: 299
// RVA: 0x55F880
void __fastcall UFG::CharacterSubjectComponent::UpdateHead(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rsi
  int BoneID; // eax
  Creature *v4; // rsi
  int mBoneHead; // edx
  float v6; // xmm4_4
  float v7; // xmm2_4
  __int64 v8; // rax
  __int128 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  __int128 v11; // xmm3
  UFG::SimComponent *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  UFG::SimObject **p_m_pSimObject; // rcx
  float y; // xmm0_4
  float z; // xmm1_4

  m_pSimComponent = this->pCharacterAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    BoneID = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBoneHead == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::symBip01Head.mUID);
        this->mBoneHead = BoneID;
      }
      mBoneHead = this->mBoneHead;
      if ( mBoneHead != -1 )
      {
        Creature::GetTransform(v4, mBoneHead, &this->mHeadTransformation);
        v6 = (float)((float)((float)(this->mHeadTransformation.v0.y * 0.1)
                           + (float)(this->mHeadTransformation.v1.y * 0.0))
                   + (float)(this->mHeadTransformation.v2.y * 0.0))
           + this->mHeadTransformation.v3.y;
        v7 = (float)((float)((float)(this->mHeadTransformation.v0.z * 0.1)
                           + (float)(this->mHeadTransformation.v1.z * 0.0))
                   + (float)(this->mHeadTransformation.v2.z * 0.0))
           + this->mHeadTransformation.v3.z;
        this->mHeadPosition.x = (float)((float)((float)(this->mHeadTransformation.v1.x * 0.0)
                                              + (float)(this->mHeadTransformation.v0.x * 0.1))
                                      + (float)(this->mHeadTransformation.v2.x * 0.0))
                              + this->mHeadTransformation.v3.x;
        this->mHeadPosition.y = v6;
        this->mHeadPosition.z = v7;
      }
    }
    if ( this->mBoneHead == -1 )
    {
      v8 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
      v9 = *(_OWORD *)(v8 + 16);
      v10 = *(UFG::qVector4 *)(v8 + 32);
      v11 = *(_OWORD *)(v8 + 48);
      this->mHeadTransformation.v0 = *(UFG::qVector4 *)v8;
      this->mHeadTransformation.v1 = (UFG::qVector4)v9;
      this->mHeadTransformation.v2 = v10;
      this->mHeadTransformation.v3 = (UFG::qVector4)v11;
      *(float *)&v11 = (float)((float)((float)(this->mHeadTransformation.v1.y + this->mHeadTransformation.v0.y) * 0.0)
                             + (float)(this->mHeadTransformation.v2.y * 1.7))
                     + this->mHeadTransformation.v3.y;
      *(float *)&v9 = (float)((float)((float)(this->mHeadTransformation.v1.z + this->mHeadTransformation.v0.z) * 0.0)
                            + (float)(this->mHeadTransformation.v2.z * 1.7))
                    + this->mHeadTransformation.v3.z;
      this->mHeadPosition.x = (float)((float)((float)(this->mHeadTransformation.v1.x + this->mHeadTransformation.v0.x)
                                            * 0.0)
                                    + (float)(this->mHeadTransformation.v2.x * 1.7))
                            + this->mHeadTransformation.v3.x;
      LODWORD(this->mHeadPosition.y) = v11;
      LODWORD(this->mHeadPosition.z) = v9;
    }
    if ( UFG::CharacterSubjectComponent::IsDowned(this)
      && (v12 = this->pTargetingSystemBaseComponent.m_pSimComponent) != 0i64
      && (mPrev = v12[1].m_BoundComponentHandles.mNode.mPrev,
          p_m_pSimObject = &v12[1].m_pSimObject,
          mPrev != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_m_pSimObject) )
    {
      while ( LOBYTE(mPrev[3].mPrev) != 22 || !mPrev[2].mNext || !BYTE1(mPrev[3].mPrev) )
      {
        mPrev = mPrev->mNext;
        if ( mPrev == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_m_pSimObject )
          goto LABEL_20;
      }
    }
    else
    {
LABEL_20:
      y = this->mHeadPosition.y;
      z = this->mHeadPosition.z;
      this->mLastAliveHeadPosition.x = this->mHeadPosition.x;
      this->mLastAliveHeadPosition.y = y;
      this->mLastAliveHeadPosition.z = z;
    }
    this->mHeadDirty = 0;
  }
}

// File Line: 340
// RVA: 0x1549980
__int64 UFG::_dynamic_initializer_for___symBip01Head__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("CameraSync01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::_symBip01Head, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for___symBip01Head__);
}

// File Line: 344
// RVA: 0x55E8C0
void __fastcall UFG::CharacterSubjectComponent::UpdateCambone(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rsi
  int BoneID; // eax
  Creature *v4; // rsi
  int mBoneCamera; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  __int64 v8; // rax
  __int128 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  __int128 v11; // xmm3

  m_pSimComponent = this->pCharacterAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    BoneID = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBoneCamera == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::_symBip01Head.mUID);
        this->mBoneCamera = BoneID;
      }
      mBoneCamera = this->mBoneCamera;
      if ( mBoneCamera != -1 )
      {
        Creature::GetTransform(v4, mBoneCamera, &this->mCamboneTransformation);
        v6 = (float)((float)((float)(this->mCamboneTransformation.v1.y + this->mCamboneTransformation.v0.y)
                           + this->mCamboneTransformation.v2.y)
                   * 0.0)
           + this->mCamboneTransformation.v3.y;
        v7 = (float)((float)((float)(this->mCamboneTransformation.v1.z + this->mCamboneTransformation.v0.z)
                           + this->mCamboneTransformation.v2.z)
                   * 0.0)
           + this->mCamboneTransformation.v3.z;
        this->mCambonePosition.x = (float)((float)((float)(this->mCamboneTransformation.v1.x
                                                         + this->mCamboneTransformation.v0.x)
                                                 + this->mCamboneTransformation.v2.x)
                                         * 0.0)
                                 + this->mCamboneTransformation.v3.x;
        this->mCambonePosition.y = v6;
        this->mCambonePosition.z = v7;
      }
    }
    if ( this->mBoneCamera == -1 )
    {
      v8 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
      v9 = *(_OWORD *)(v8 + 16);
      v10 = *(UFG::qVector4 *)(v8 + 32);
      v11 = *(_OWORD *)(v8 + 48);
      this->mCamboneTransformation.v0 = *(UFG::qVector4 *)v8;
      this->mCamboneTransformation.v1 = (UFG::qVector4)v9;
      this->mCamboneTransformation.v2 = v10;
      this->mCamboneTransformation.v3 = (UFG::qVector4)v11;
      *(float *)&v11 = (float)((float)((float)(this->mCamboneTransformation.v1.y + this->mCamboneTransformation.v0.y)
                                     * 0.0)
                             + (float)(this->mCamboneTransformation.v2.y * 0.85000002))
                     + this->mCamboneTransformation.v3.y;
      *(float *)&v9 = (float)((float)((float)(this->mCamboneTransformation.v1.z + this->mCamboneTransformation.v0.z)
                                    * 0.0)
                            + (float)(this->mCamboneTransformation.v2.z * 0.85000002))
                    + this->mCamboneTransformation.v3.z;
      this->mCambonePosition.x = (float)((float)((float)(this->mCamboneTransformation.v1.x
                                                       + this->mCamboneTransformation.v0.x)
                                               * 0.0)
                                       + (float)(this->mCamboneTransformation.v2.x * 0.85000002))
                               + this->mCamboneTransformation.v3.x;
      LODWORD(this->mCambonePosition.y) = v11;
      LODWORD(this->mCambonePosition.z) = v9;
    }
    this->mCamboneDirty = 0;
  }
}

// File Line: 376
// RVA: 0x154CC50
__int64 UFG::_dynamic_initializer_for__symBip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symBip01Pelvis, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symBip01Pelvis__);
}

// File Line: 380
// RVA: 0x5606B0
void __fastcall UFG::CharacterSubjectComponent::UpdatePelvis(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rsi
  int BoneID; // eax
  Creature *v4; // rsi
  int mBonePelvis; // edx
  float v6; // xmm1_4
  float v7; // xmm0_4
  __int64 v8; // rax
  __int128 v9; // xmm1
  UFG::qVector4 v10; // xmm2
  __int128 v11; // xmm3

  m_pSimComponent = this->pCharacterAnimationComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    BoneID = -1;
    if ( this->pCharacterAnimationComponent.m_Changed )
    {
      this->mBoneHead = -1;
      this->mBoneCamera = -1;
      this->mBonePelvis = -1;
      this->mBoneSync = -1;
      this->pCharacterAnimationComponent.m_Changed = 0;
    }
    v4 = *(Creature **)&m_pSimComponent[2].m_TypeUID;
    if ( v4 )
    {
      if ( this->mBonePelvis == -1 )
      {
        if ( v4->mPose.mRigHandle.mData )
          BoneID = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::symBip01Pelvis.mUID);
        this->mBonePelvis = BoneID;
      }
      mBonePelvis = this->mBonePelvis;
      if ( mBonePelvis != -1 )
      {
        Creature::GetTransform(v4, mBonePelvis, &this->mPelvisTransformation);
        v6 = (float)((float)((float)(this->mPelvisTransformation.v1.y + this->mPelvisTransformation.v0.y)
                           + this->mPelvisTransformation.v2.y)
                   * 0.0)
           + this->mPelvisTransformation.v3.y;
        v7 = (float)((float)((float)(this->mPelvisTransformation.v1.z + this->mPelvisTransformation.v0.z)
                           + this->mPelvisTransformation.v2.z)
                   * 0.0)
           + this->mPelvisTransformation.v3.z;
        this->mPelvisPosition.x = (float)((float)((float)(this->mPelvisTransformation.v1.x
                                                        + this->mPelvisTransformation.v0.x)
                                                + this->mPelvisTransformation.v2.x)
                                        * 0.0)
                                + this->mPelvisTransformation.v3.x;
        this->mPelvisPosition.y = v6;
        this->mPelvisPosition.z = v7;
      }
    }
    if ( this->mBonePelvis == -1 )
    {
      v8 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
      v9 = *(_OWORD *)(v8 + 16);
      v10 = *(UFG::qVector4 *)(v8 + 32);
      v11 = *(_OWORD *)(v8 + 48);
      this->mPelvisTransformation.v0 = *(UFG::qVector4 *)v8;
      this->mPelvisTransformation.v1 = (UFG::qVector4)v9;
      this->mPelvisTransformation.v2 = v10;
      this->mPelvisTransformation.v3 = (UFG::qVector4)v11;
      *(float *)&v11 = (float)((float)((float)(this->mPelvisTransformation.v1.y + this->mPelvisTransformation.v0.y) * 0.0)
                             + (float)(this->mPelvisTransformation.v2.y * 0.85000002))
                     + this->mPelvisTransformation.v3.y;
      *(float *)&v9 = (float)((float)((float)(this->mPelvisTransformation.v1.z + this->mPelvisTransformation.v0.z) * 0.0)
                            + (float)(this->mPelvisTransformation.v2.z * 0.85000002))
                    + this->mPelvisTransformation.v3.z;
      this->mPelvisPosition.x = (float)((float)((float)(this->mPelvisTransformation.v1.x
                                                      + this->mPelvisTransformation.v0.x)
                                              * 0.0)
                                      + (float)(this->mPelvisTransformation.v2.x * 0.85000002))
                              + this->mPelvisTransformation.v3.x;
      LODWORD(this->mPelvisPosition.y) = v11;
      LODWORD(this->mPelvisPosition.z) = v9;
    }
    this->mPelvisDirty = 0;
  }
}

// File Line: 413
// RVA: 0x154CDD0
__int64 UFG::_dynamic_initializer_for__symSync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Sync01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symSync01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSync01__);
}

// File Line: 445
// RVA: 0x1544920
__int64 UFG::_dynamic_initializer_for__HASH_Hostage__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Hostage", -1);
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

  result = UFG::qStringHashUpper32("ActionHijack", -1);
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

  result = UFG::qStringHashUpper32("Run", -1);
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

  result = UFG::qStringHashUpper32("Walk", -1);
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
  UFG::CharacterSubjectComponent::LazyState mIsHostage; // edx
  bool result; // al
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx

  mIsHostage = this->mIsHostage;
  if ( mIsHostage )
    return mIsHostage == STATE_TRUE;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_22;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_16:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_16;
        }
        m_pComponent = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  if ( m_pComponent
    && ActionController::IsPlaying((ActionController *)&m_pComponent[3], &HASH_Hostage, mostUsedIndex_Hostage, 0) )
  {
    result = 1;
  }
  else
  {
LABEL_22:
    result = 0;
  }
  this->mIsHostage = 2 - result;
  return result;
}

// File Line: 474
// RVA: 0x539630
bool __fastcall UFG::CharacterSubjectComponent::IsActionHijacking(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState mActionHijacking; // edx
  bool result; // al
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx

  mActionHijacking = this->mActionHijacking;
  if ( mActionHijacking )
    return mActionHijacking == STATE_TRUE;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_22;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_16:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_16;
        }
        m_pComponent = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  if ( m_pComponent
    && ActionController::IsPlaying(
         (ActionController *)&m_pComponent[3],
         &HASH_ActionHijack_0,
         mostUsedIndex_ActionHijack_0,
         0) )
  {
    result = 1;
  }
  else
  {
LABEL_22:
    result = 0;
  }
  this->mActionHijacking = 2 - result;
  return result;
}

// File Line: 493
// RVA: 0x53B0A0
bool __fastcall UFG::CharacterSubjectComponent::IsJogging(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState mJogging; // edx
  bool result; // al
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx

  mJogging = this->mJogging;
  if ( mJogging )
    return mJogging == STATE_TRUE;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_23;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_16:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_16;
        }
        m_pComponent = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  if ( m_pComponent
    && ActionController::IsPlaying((ActionController *)&m_pComponent[3], &HASH_Run, mostUsedIndex_Run, 1)
    && !this->mSprinting )
  {
    result = 1;
  }
  else
  {
LABEL_23:
    result = 0;
  }
  this->mJogging = 2 - result;
  return result;
}

// File Line: 512
// RVA: 0x53C2F0
bool __fastcall UFG::CharacterSubjectComponent::IsWalking(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterSubjectComponent::LazyState mWalking; // edx
  bool result; // al
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx

  mWalking = this->mWalking;
  if ( mWalking )
    return mWalking == STATE_TRUE;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_23;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_16:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_16;
        }
        m_pComponent = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  if ( m_pComponent
    && ActionController::IsPlaying((ActionController *)&m_pComponent[3], &HASH_Walk, mostUsedIndex_Walk, 1)
    && !this->mSprinting )
  {
    result = 1;
  }
  else
  {
LABEL_23:
    result = 0;
  }
  this->mWalking = 2 - result;
  return result;
}

// File Line: 531
// RVA: 0x55A530
void __fastcall UFG::CharacterSubjectComponent::Update(UFG::CharacterSubjectComponent *this, float delta_sec)
{
  UFG::CharacterPhysicsComponent *m_pSimComponent; // rcx
  UFG::ParkourHandle *v5; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float Radius; // xmm6_4
  UFG::qVector3 *Velocity; // rax
  UFG::SimComponent *v10; // rcx
  UFG::CharacterCollisionMode mPrev; // edx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float Height; // xmm0_4
  int v15; // xmm6_4
  __m128 x_low; // xmm2
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v26; // rdx
  unsigned int v27; // r8d
  unsigned int v28; // r10d
  unsigned int v29; // r8d
  unsigned int v30; // r10d
  __int64 v31; // rax
  float v32; // xmm7_4
  float v33; // xmm8_4
  float rLockedElevationDef; // xmm6_4
  UFG::SimObject **p_m_pSimObject; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qVector3 raw_velocity; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF

  UFG::CameraSubject::UpdateBase(this, delta_sec, UFG::bCameraDebugDraw, &UFG::gCameraSubjectUpdateParams);
  m_pSimComponent = (UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent;
  v5 = 0i64;
  *(_QWORD *)&this->mIsHostage = 0i64;
  *(_QWORD *)&this->mActionHijacking = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  raw_velocity = UFG::qVector3::msZero;
  if ( m_pSimComponent )
  {
    Radius = UFG::CharacterPhysicsComponent::GetRadius(m_pSimComponent);
    Velocity = UFG::CharacterPhysicsComponent::GetVelocity(
                 (UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent,
                 &result);
    v10 = this->pCharacterPhysicsComponent.m_pSimComponent;
    mPrev = (UFG::CharacterCollisionMode)v10[8].m_BoundComponentHandles.mNode.mPrev;
    v12 = Velocity->y;
    raw_velocity.x = Velocity->x;
    v13 = Velocity->z;
    raw_velocity.y = v12;
    raw_velocity.z = v13;
    Height = UFG::CharacterPhysicsComponent::GetHeight((UFG::CharacterPhysicsComponent *)v10, mPrev);
    this->mBox.mMax.x = Radius;
    this->mBox.mMax.y = Radius;
    v15 = LODWORD(Radius) ^ _xmm[0];
    this->mBox.mMax.z = Height;
    LODWORD(this->mBox.mMin.x) = v15;
    LODWORD(this->mBox.mMin.y) = v15;
    this->mBox.mMin.z = 0.0;
    x_low = (__m128)LODWORD(this->mBox.mMax.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                              + (float)(this->mBox.mMax.y * this->mBox.mMax.y))
                      + (float)(this->mBox.mMax.z * this->mBox.mMax.z);
    LODWORD(this->mRadius) = _mm_sqrt_ps(x_low).m128_u32[0];
  }
  else
  {
    this->mFilteredVelocity.x = UFG::qVector3::msZero.x;
    this->mFilteredVelocity.y = y;
    this->mFilteredVelocity.z = z;
    v17 = UFG::qVector3::msZero.y;
    v18 = UFG::qVector3::msZero.z;
    this->mBox.mMin.x = UFG::qVector3::msZero.x;
    this->mBox.mMin.y = v17;
    this->mBox.mMin.z = v18;
    v19 = UFG::qVector3::msZero.y;
    v20 = UFG::qVector3::msZero.z;
    this->mBox.mMax.x = UFG::qVector3::msZero.x;
    this->mBox.mMax.y = v19;
    this->mBox.mMax.z = v20;
    this->mRadius = 0.0;
  }
  UFG::CharacterSubjectComponent::UpdateFilteredVelocity(this, delta_sec, &raw_velocity);
  UFG::CharacterSubjectComponent::UpdateFilteredPosition(this, delta_sec);
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_32;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[28].m_pComponent;
    goto LABEL_30;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v26 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v26 += 16i64;
        if ( vfptr >= size )
          goto LABEL_13;
      }
LABEL_14:
      m_pComponent = *(UFG::SimComponent **)v26;
      goto LABEL_30;
    }
    goto LABEL_13;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v27 = (unsigned int)m_pSimObject[1].vfptr;
    v28 = m_pSimObject->m_Components.size;
    if ( v27 < v28 )
    {
      v26 = (__int64)&m_pSimObject->m_Components.p[v27];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v27;
        v26 += 16i64;
        if ( v27 >= v28 )
        {
          m_pComponent = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_14;
    }
LABEL_13:
    m_pComponent = 0i64;
    goto LABEL_30;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v29 = (unsigned int)m_pSimObject[1].vfptr;
    v30 = m_pSimObject->m_Components.size;
    if ( v29 < v30 )
    {
      v26 = (__int64)&m_pSimObject->m_Components.p[v29];
      while ( (*(_DWORD *)(v26 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
           || (UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v26 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v29;
        v26 += 16i64;
        if ( v29 >= v30 )
        {
          m_pComponent = 0i64;
          goto LABEL_30;
        }
      }
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::WorldContextComponent::_TypeUID);
LABEL_30:
  if ( m_pComponent )
    v5 = *(UFG::ParkourHandle **)&m_pComponent[5].m_TypeUID;
LABEL_32:
  this->mParkourHandle = v5;
  UFG::CharacterSubjectComponent::UpdateTargetWorld(this);
  v31 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[17].__vecDelDtor)(this);
  v32 = *(float *)v31;
  v33 = *(float *)(v31 + 4);
  rLockedElevationDef = *(float *)(v31 + 8);
  if ( this->bElevationLock )
    rLockedElevationDef = this->rLockedElevationDef;
  if ( UFG::CharacterSubjectComponent::IsDowned(this)
    && this->pTargetingSystemBaseComponent.m_pSimComponent
    && (p_m_pSimObject = &this->pTargetingSystemBaseComponent.m_pSimComponent[1].m_pSimObject,
        v36 = this->pTargetingSystemBaseComponent.m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev,
        v36 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_m_pSimObject) )
  {
    while ( LOBYTE(v36[3].mPrev) != 22 || !v36[2].mNext || !BYTE1(v36[3].mPrev) )
    {
      v36 = v36->mNext;
      if ( v36 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_m_pSimObject )
        goto LABEL_41;
    }
  }
  else
  {
LABEL_41:
    this->mGrapplePosition.x = v32;
    this->mGrapplePosition.y = v33;
    this->mGrapplePosition.z = rLockedElevationDef;
  }
  if ( this->pCharacterAnimationComponent.m_pSimComponent )
    *(_DWORD *)&this->mHeadDirty = 16843009;
}

// File Line: 620
// RVA: 0x54F940
bool __fastcall UFG::CharacterSubjectComponent::ShouldHide(UFG::CharacterSubjectComponent *this)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  __int64 v3; // rax
  bool v4; // zf
  float v5; // xmm1_4
  float v6; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::BaseCameraComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qVector3 P; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 lA1; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector3 lA0; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector3 closest_point; // [rsp+50h] [rbp-28h] BYREF

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( !mCurrentCamera || mCurrentCamera == (UFG::BaseCameraComponent *)-80i64 )
    return 0;
  v3 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[26].__vecDelDtor)(this);
  v4 = !this->mPelvisDirty;
  v5 = *(float *)(v3 + 4);
  v6 = *(float *)(v3 + 8);
  lA1.x = *(float *)v3;
  lA1.y = v5;
  lA1.z = v6;
  if ( !v4 )
    UFG::CharacterSubjectComponent::UpdatePelvis(this);
  y = this->mPelvisPosition.y;
  lA0.x = this->mPelvisPosition.x;
  z = this->mPelvisPosition.z;
  lA0.y = y;
  lA0.z = z;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    v9 = (UFG::BaseCameraComponent *)((char *)v9 + 80);
  v10 = v9->mCamera.mView.v2.y;
  v11 = v9->mCamera.mView.v2.z;
  P.x = v9->mCamera.mView.v2.x;
  P.y = v10;
  P.z = v11;
  UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &lA1, &P);
  if ( UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)this->m_pSimObject) )
    v12 = UFG::gFadeThresholdPlayer;
  else
    v12 = UFG::gFadeThresholdNPC;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( ComponentOfType[24].m_NameUID == 5 )
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
void __fastcall UFG::CharacterSubjectComponent::GetHeadTransform(
        UFG::CharacterSubjectComponent *this,
        UFG::qMatrix44 *m)
{
  int mBoneHead; // edx
  Creature *v5; // rcx
  __int64 v6; // rbx
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

  if ( this->mHeadDirty )
    UFG::CharacterSubjectComponent::UpdateHead(this);
  mBoneHead = this->mBoneHead;
  if ( mBoneHead == -1 || !this->pCharacterAnimationComponent.m_pSimComponent )
  {
    v6 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 1.7)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 1.7)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 1.7)) + v7[15];
    m->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 1.7)) + v7[12];
    m->v3.y = v8;
    m->v3.w = v10;
    m->v3.z = v9;
    LODWORD(v7) = *(_DWORD *)v6;
    v11 = *(float *)(v6 + 8);
    v12 = *(float *)(v6 + 12);
    m->v0.y = *(float *)(v6 + 4);
    LODWORD(m->v0.x) = (_DWORD)v7;
    m->v0.z = v11;
    m->v0.w = v12;
    LODWORD(v7) = *(_DWORD *)(v6 + 16);
    v13 = *(float *)(v6 + 24);
    v14 = *(float *)(v6 + 28);
    m->v1.y = *(float *)(v6 + 20);
    LODWORD(m->v1.x) = (_DWORD)v7;
    m->v1.z = v13;
    m->v1.w = v14;
    v15 = *(float *)(v6 + 40);
    v16 = *(float *)(v6 + 44);
    *(_QWORD *)&m->v2.x = *(_QWORD *)(v6 + 32);
    m->v2.z = v15;
    m->v2.w = v16;
  }
  else
  {
    v5 = *(Creature **)&this->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, mBoneHead, m);
  }
}

// File Line: 690
// RVA: 0x52AD20
void __fastcall UFG::CharacterSubjectComponent::GetCamboneTransform(
        UFG::CharacterSubjectComponent *this,
        UFG::qMatrix44 *m)
{
  int mBoneCamera; // edx
  Creature *v5; // rcx
  __int64 v6; // rbx
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

  if ( this->mCamboneDirty )
    UFG::CharacterSubjectComponent::UpdateCambone(this);
  mBoneCamera = this->mBoneCamera;
  if ( mBoneCamera == -1 || !this->pCharacterAnimationComponent.m_pSimComponent )
  {
    v6 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 0.85000002)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 0.85000002)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 0.85000002)) + v7[15];
    m->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 0.85000002)) + v7[12];
    m->v3.y = v8;
    m->v3.w = v10;
    m->v3.z = v9;
    LODWORD(v7) = *(_DWORD *)v6;
    v11 = *(float *)(v6 + 8);
    v12 = *(float *)(v6 + 12);
    m->v0.y = *(float *)(v6 + 4);
    LODWORD(m->v0.x) = (_DWORD)v7;
    m->v0.z = v11;
    m->v0.w = v12;
    LODWORD(v7) = *(_DWORD *)(v6 + 16);
    v13 = *(float *)(v6 + 24);
    v14 = *(float *)(v6 + 28);
    m->v1.y = *(float *)(v6 + 20);
    LODWORD(m->v1.x) = (_DWORD)v7;
    m->v1.z = v13;
    m->v1.w = v14;
    v15 = *(float *)(v6 + 40);
    v16 = *(float *)(v6 + 44);
    *(_QWORD *)&m->v2.x = *(_QWORD *)(v6 + 32);
    m->v2.z = v15;
    m->v2.w = v16;
  }
  else
  {
    v5 = *(Creature **)&this->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, mBoneCamera, m);
  }
}

// File Line: 714
// RVA: 0x52F450
void __fastcall UFG::CharacterSubjectComponent::GetPelvisTransform(
        UFG::CharacterSubjectComponent *this,
        UFG::qMatrix44 *m)
{
  int mBonePelvis; // edx
  Creature *v5; // rcx
  __int64 v6; // rbx
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

  if ( this->mPelvisDirty )
    UFG::CharacterSubjectComponent::UpdatePelvis(this);
  mBonePelvis = this->mBonePelvis;
  if ( mBonePelvis == -1 || !this->pCharacterAnimationComponent.m_pSimComponent )
  {
    v6 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v7 = (float *)((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[18].__vecDelDtor)(this);
    v8 = (float)((float)((float)(v7[5] + v7[1]) * 0.0) + (float)(v7[9] * 0.85000002)) + v7[13];
    v9 = (float)((float)((float)(v7[6] + v7[2]) * 0.0) + (float)(v7[10] * 0.85000002)) + v7[14];
    v10 = (float)((float)((float)(v7[7] + v7[3]) * 0.0) + (float)(v7[11] * 0.85000002)) + v7[15];
    m->v3.x = (float)((float)((float)(v7[4] + *v7) * 0.0) + (float)(v7[8] * 0.85000002)) + v7[12];
    m->v3.y = v8;
    m->v3.w = v10;
    m->v3.z = v9;
    LODWORD(v7) = *(_DWORD *)v6;
    v11 = *(float *)(v6 + 8);
    v12 = *(float *)(v6 + 12);
    m->v0.y = *(float *)(v6 + 4);
    LODWORD(m->v0.x) = (_DWORD)v7;
    m->v0.z = v11;
    m->v0.w = v12;
    LODWORD(v7) = *(_DWORD *)(v6 + 16);
    v13 = *(float *)(v6 + 24);
    v14 = *(float *)(v6 + 28);
    m->v1.y = *(float *)(v6 + 20);
    LODWORD(m->v1.x) = (_DWORD)v7;
    m->v1.z = v13;
    m->v1.w = v14;
    v15 = *(float *)(v6 + 40);
    v16 = *(float *)(v6 + 44);
    *(_QWORD *)&m->v2.x = *(_QWORD *)(v6 + 32);
    m->v2.z = v15;
    m->v2.w = v16;
  }
  else
  {
    v5 = *(Creature **)&this->pCharacterAnimationComponent.m_pSimComponent[2].m_TypeUID;
    if ( v5 )
      Creature::GetTransform(v5, mBonePelvis, m);
  }
}

// File Line: 738
// RVA: 0x556920
void __fastcall UFG::CharacterSubjectComponent::TeleportEventHandler(
        UFG::CharacterSubjectComponent *this,
        UFG::Event *event)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // eax
  float v8; // xmm0_4
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v11; // rdi
  UFG::SimObject *v12; // rbx

  v2 = *((float *)&event[2].mNext + 1);
  v3 = *(float *)&event[2].m_EventUID;
  this->mLastAliveHeadPosition.x = *(float *)&event[2].mNext;
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
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FollowCameraComponent::_TypeUID);
    v11 = ComponentOfType;
    if ( ComponentOfType )
    {
      v12 = this->m_pSimObject;
      if ( v12 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
        ((void (__fastcall *)(UFG::SimComponent *))v11->vfptr[14].__vecDelDtor)(v11);
    }
  }
}

// File Line: 756
// RVA: 0x53A000
bool __fastcall UFG::CharacterSubjectComponent::IsCop(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 i; // rdx
  unsigned int v7; // r8d
  unsigned int v8; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return m_pSimObject->m_Components.p[17].m_pComponent != 0i64;
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[vfptr];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::CopUnitComponent::_TypeUID & 0xFE000000)
         || (UFG::CopUnitComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++vfptr >= size )
          return 0;
      }
      return *(_QWORD *)i != 0i64;
    }
    return 0;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v7 = (unsigned int)m_pSimObject[1].vfptr;
    v8 = m_pSimObject->m_Components.size;
    if ( v7 < v8 )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[v7];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::CopUnitComponent::_TypeUID & 0xFE000000)
         || (UFG::CopUnitComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++v7 >= v8 )
          return 0;
      }
      return *(_QWORD *)i != 0i64;
    }
    return 0;
  }
  return UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CopUnitComponent::_TypeUID) != 0i64;
}

// File Line: 762
// RVA: 0x532DC0
UFG::qVector3 *__fastcall UFG::CharacterSubjectComponent::GetVelocity(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v5; // r8d
  unsigned int v6; // r9d
  __int64 v7; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rcx
  int v15; // edx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return &this->mFilteredVelocity;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v7 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v7 += 16i64;
            if ( vfptr >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)m_pSimObject[1].vfptr;
        v11 = m_pSimObject->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (__int64)&m_pSimObject->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)m_pSimObject[1].vfptr;
      v6 = m_pSimObject->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (__int64)&m_pSimObject->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        ComponentOfType = *(UFG::SimComponent **)v7;
        goto LABEL_27;
      }
    }
LABEL_10:
    ComponentOfType = 0i64;
    goto LABEL_27;
  }
  ComponentOfType = m_pSimObject->m_Components.p[44].m_pComponent;
LABEL_27:
  if ( ComponentOfType )
  {
    mPrev = ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev;
    if ( mPrev )
    {
      mNext = mPrev[2].mNext;
      if ( mNext )
      {
        v14 = mNext[6].mNext[31].mPrev;
        if ( v14 )
        {
          v15 = (int)v14[1].mNext;
          if ( ((v15 ^ UFG::VehicleSubjectComponent::_TypeUID) & 0xFE000000) == 0
            && (UFG::VehicleSubjectComponent::_TypeUID & ~v15 & 0x1FFFFFF) == 0 )
          {
            return (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v14->mPrev[10].mPrev)(v14);
          }
        }
      }
    }
  }
  return &this->mFilteredVelocity;
}

// File Line: 783
// RVA: 0x53AA60
bool __fastcall UFG::CharacterSubjectComponent::IsInVehicle(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 i; // rdx
  unsigned int v7; // r8d
  unsigned int v8; // r9d
  unsigned int v9; // r8d
  unsigned int v10; // r9d

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return m_pSimObject->m_Components.p[44].m_pComponent != 0i64;
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[vfptr];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
         || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++vfptr >= size )
          return 0;
      }
      return *(_QWORD *)i != 0i64;
    }
    return 0;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v7 = (unsigned int)m_pSimObject[1].vfptr;
    v8 = m_pSimObject->m_Components.size;
    if ( v7 < v8 )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[v7];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
         || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++v7 >= v8 )
          return 0;
      }
      return *(_QWORD *)i != 0i64;
    }
    return 0;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[v9];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
         || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++v9 >= v10 )
          return 0;
      }
      return *(_QWORD *)i != 0i64;
    }
    return 0;
  }
  return UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 789
// RVA: 0x53A160
bool __fastcall UFG::CharacterSubjectComponent::IsDowned(UFG::CharacterSubjectComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ActionTreeComponent *ComponentOfType; // rdi
  UFG::HealthComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v8; // rdx
  unsigned int v9; // r8d
  unsigned int v10; // r9d
  UFG::SimObject *v11; // rcx
  __int16 v12; // dx
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  __int64 i; // rdx

  m_pSimObject = this->m_pSimObject;
  ComponentOfType = 0i64;
  if ( !m_pSimObject )
    goto LABEL_2;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
    goto LABEL_23;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v8 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v8 += 16i64;
        if ( vfptr >= size )
        {
          m_pComponent = 0i64;
          goto LABEL_23;
        }
      }
LABEL_14:
      m_pComponent = *(UFG::HealthComponent **)v8;
      goto LABEL_23;
    }
    goto LABEL_2;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (__int64)&m_pSimObject->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
        {
          m_pComponent = 0i64;
          goto LABEL_23;
        }
      }
      goto LABEL_14;
    }
LABEL_2:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  m_pComponent = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                           m_pSimObject,
                                           UFG::HealthComponent::_TypeUID);
LABEL_23:
  v11 = this->m_pSimObject;
  if ( v11 )
  {
    v12 = v11->m_Flags;
    if ( (v12 & 0x4000) != 0 || v12 < 0 )
    {
      ComponentOfType = (UFG::ActionTreeComponent *)v11->m_Components.p[7].m_pComponent;
    }
    else if ( (v12 & 0x2000) != 0 )
    {
      ComponentOfType = (UFG::ActionTreeComponent *)v11->m_Components.p[6].m_pComponent;
    }
    else if ( (v12 & 0x1000) != 0 )
    {
      v13 = (unsigned int)v11[1].vfptr;
      v14 = v11->m_Components.size;
      if ( v13 < v14 )
      {
        for ( i = (__int64)&v11->m_Components.p[v13];
              (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
           || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
              i += 16i64 )
        {
          if ( ++v13 >= v14 )
            return UFG::IsDowned(ComponentOfType, m_pComponent);
        }
        ComponentOfType = *(UFG::ActionTreeComponent **)i;
      }
    }
    else
    {
      ComponentOfType = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                      v11,
                                                      UFG::ActionTreeComponent::_TypeUID);
    }
  }
  return UFG::IsDowned(ComponentOfType, m_pComponent);
}

// File Line: 809
// RVA: 0x539770
bool __fastcall UFG::CharacterSubjectComponent::IsAirborne(UFG::CharacterSubjectComponent *this)
{
  UFG::CharacterPhysicsComponent *m_pSimComponent; // rcx
  UFG::SimComponent *v3; // rax
  bool result; // al

  m_pSimComponent = (UFG::CharacterPhysicsComponent *)this->pCharacterPhysicsComponent.m_pSimComponent;
  result = 0;
  if ( m_pSimComponent )
  {
    if ( !UFG::CharacterPhysicsComponent::IsInWater(m_pSimComponent) )
    {
      v3 = this->pCharacterPhysicsComponent.m_pSimComponent;
      if ( (v3[6].m_NameUID & 2) == 0 && *(float *)&v3[5].m_BoundComponentHandles.mNode.mPrev > 1.0 )
        return 1;
    }
  }
  return result;
}

// File Line: 823
// RVA: 0x53B240
bool __fastcall UFG::CharacterSubjectComponent::IsOnGround(UFG::CharacterSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pCharacterPhysicsComponent.m_pSimComponent;
  return m_pSimComponent && (m_pSimComponent[6].m_NameUID & 2) != 0;
}

// File Line: 830
// RVA: 0x54C830
void __fastcall UFG::CharacterSubjectComponent::SetElevationLock(UFG::CharacterSubjectComponent *this, bool lock)
{
  __int64 v4; // rax
  bool v5; // zf
  float v6; // ecx
  float rLockedElevationCam; // eax
  float rLockedElevationHip; // eax

  if ( this->bElevationLock != lock )
  {
    v4 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[17].__vecDelDtor)(this);
    v5 = !this->mCamboneDirty;
    this->rLockedElevationDef = *(float *)(v4 + 8);
    if ( !v5 )
      UFG::CharacterSubjectComponent::UpdateCambone(this);
    v5 = !this->mPelvisDirty;
    this->rLockedElevationCam = this->mCambonePosition.z;
    if ( !v5 )
      UFG::CharacterSubjectComponent::UpdatePelvis(this);
    this->rLockedElevationHip = this->mPelvisPosition.z;
    v6 = *(float *)(((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[26].__vecDelDtor)(this) + 8);
    rLockedElevationCam = this->rLockedElevationCam;
    this->bElevationLock = lock;
    this->rLockedElevationFocusCreatureCambone = rLockedElevationCam;
    rLockedElevationHip = this->rLockedElevationHip;
    this->rLockedElevationHed = v6;
    this->rLockedElevationFocusCreaturePelvis = rLockedElevationHip;
    this->rLockedElevationFocusCreatureHead = v6;
  }
}

// File Line: 859
// RVA: 0x53B4C0
char __fastcall UFG::CharacterSubjectComponent::IsOverrideSymbolValid(_DWORD *_override)
{
  UFG::qSymbol *v2; // rbx
  UFG::qSymbol *v3; // rsi
  const char **v4; // rdi
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+38h] [rbp-40h] BYREF
  UFG::qSymbol v8; // [rsp+80h] [rbp+8h] BYREF

  if ( *_override != UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v8, 0xFFFFFFFF)->mUID )
  {
    v2 = cached_names;
    if ( (_S13_6 & 1) == 0 )
    {
      _S13_6 |= 1u;
      `eh vector constructor iterator(cached_names, 4ui64, 106, (void (__fastcall *)(void *))BackInfo::BackInfo);
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
      while ( (__int64)v4 < (__int64)&gIconSocialHubAvatarPlayer_ChallengeOutgoing_17 );
    }
    while ( *_override != v2->mUID )
    {
      if ( (__int64)++v2 >= (__int64)&_S13_6 )
        return 0;
    }
  }
  return 1;
}

// File Line: 891
// RVA: 0x54C590
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(
        UFG::CharacterSubjectComponent *this,
        int type,
        unsigned int *override)
{
  __int64 v4; // rsi

  v4 = type;
  if ( (_S14_2 & 1) == 0 )
  {
    _S14_2 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_1, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  this->mContextOverrideScriptGlobal[v4].mSymbol.mUID = *override;
  this->mContextOverrideScriptGlobal[v4].mUID = -1;
}

// File Line: 918
// RVA: 0x54BF80
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanNPC(
        UFG::CharacterSubjectComponent *this,
        ActionContext *ac,
        int type,
        unsigned int *override,
        unsigned int uid)
{
  this->mContextOverrideFreemanNPC[type].mSymbol.mUID = *override;
  this->mContextOverrideFreemanNPC[type].mUID = uid;
}

// File Line: 953
// RVA: 0x52C100
__int64 __fastcall UFG::CharacterSubjectComponent::GetContextOverrideFreemanNPC_ID(
        UFG::CharacterSubjectComponent *this,
        int type)
{
  return this->mContextOverrideFreemanNPC[type].mUID;
}

// File Line: 960
// RVA: 0x54BFA0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer(
        UFG::CharacterSubjectComponent *this,
        ActionContext *ac,
        int type,
        unsigned int *override,
        unsigned int uid)
{
  __int64 v6; // rsi
  unsigned int v8; // eax

  v6 = type;
  v8 = _S15_3;
  if ( (_S15_3 & 1) == 0 )
  {
    _S15_3 |= 1u;
    UFG::qSymbol::create_from_string(&combatBasicSymbol, "Cameras-FollowCameraCombatBasic");
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__combatBasicSymbol__);
    v8 = _S15_3;
  }
  if ( (v8 & 2) == 0 )
  {
    _S15_3 = v8 | 2;
    UFG::qSymbol::create_from_string(&combatBasicTargetedSymbol, "Cameras-FollowCameraCombatBasicTargeted");
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__combatBasicTargetedSymbol__);
    v8 = _S15_3;
  }
  if ( (v8 & 4) == 0 )
  {
    _S15_3 = v8 | 4;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_2, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayer_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  if ( *override == combatBasicSymbol.mUID )
  {
    if ( this->mContextOverrideFreemanPlayer[v6].mSymbol.mUID == combatBasicTargetedSymbol.mUID )
      return;
    if ( UFG::LocalPlayerIsInCombatManager::IsInMeleeCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0) )
      *override = combatBasicTargetedSymbol.mUID;
  }
  this->mContextOverrideFreemanPlayer[v6].mSymbol.mUID = *override;
  this->mContextOverrideFreemanPlayer[v6].mUID = uid;
}

// File Line: 1010
// RVA: 0x52C110
__int64 __fastcall UFG::CharacterSubjectComponent::GetContextOverrideFreemanPlayer_ID(
        UFG::CharacterSubjectComponent *this,
        int type)
{
  return this->mContextOverrideFreemanPlayer[type].mUID;
}

// File Line: 1016
// RVA: 0x54C3C0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI(
        UFG::CharacterSubjectComponent *this,
        ActionContext *ac,
        UFG::SimObject *poiobj,
        int type,
        unsigned int *override_left,
        unsigned int *override_right)
{
  __int64 v6; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rbp
  float y; // xmm1_4
  float z; // xmm2_4
  __int64 v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  unsigned int mUID; // ecx
  unsigned int *v18; // rax
  UFG::qVector2 viewport_scale; // [rsp+30h] [rbp-58h] BYREF
  __int64 v20; // [rsp+38h] [rbp-50h]
  UFG::qVector3 world_pos; // [rsp+40h] [rbp-48h] BYREF
  UFG::qVector3 v22; // [rsp+50h] [rbp-38h] BYREF
  UFG::qVector3 v23; // [rsp+60h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+70h] [rbp-18h] BYREF
  bool is_on_screen; // [rsp+A0h] [rbp+18h] BYREF

  v20 = -2i64;
  v6 = type;
  if ( (_S16_3 & 1) == 0 )
  {
    _S16_3 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_3, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerPOI_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  if ( !poiobj )
    goto LABEL_15;
  m_pTransformNodeComponent = poiobj->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    goto LABEL_15;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  world_pos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  world_pos.y = y;
  world_pos.z = z;
  v14 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[17].__vecDelDtor)(this);
  v15 = *(float *)(v14 + 4);
  v16 = *(float *)(v14 + 8);
  v22.x = *(float *)v14;
  v22.y = v15;
  v22.z = v16;
  is_on_screen = 0;
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::Camera::GetScreenCoord(p_mCamera, &result, &world_pos, &viewport_scale, &is_on_screen);
  viewport_scale.x = 1.0;
  viewport_scale.y = 1.0;
  UFG::Camera::GetScreenCoord(p_mCamera, &v23, &v22, &viewport_scale, &is_on_screen);
  mUID = this->mContextOverrideFreemanPlayer[v6].mSymbol.mUID;
  if ( v23.x >= result.x )
  {
    if ( mUID == nullSym_3.mUID || mUID != *override_left )
    {
      v18 = override_right;
LABEL_16:
      this->mContextOverrideFreemanPlayer[v6].mSymbol.mUID = *v18;
      this->mContextOverrideFreemanPlayer[v6].mUID = -1;
    }
  }
  else if ( mUID == nullSym_3.mUID || mUID != *override_right )
  {
LABEL_15:
    v18 = override_left;
    goto LABEL_16;
  }
}

// File Line: 1090
// RVA: 0x530BB0
__int64 __fastcall UFG::CharacterSubjectComponent::GetTransformType(int *tag)
{
  unsigned int v2; // eax
  __int64 result; // rax
  int v4; // ecx

  v2 = _S17_4;
  if ( (_S17_4 & 1) == 0 )
  {
    _S17_4 |= 1u;
    UFG::qSymbol::create_from_string(&def, "def");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__def__);
    v2 = _S17_4;
  }
  if ( (v2 & 2) == 0 )
  {
    _S17_4 = v2 | 2;
    UFG::qSymbol::create_from_string(&cam, "cam");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__cam__);
    v2 = _S17_4;
  }
  if ( (v2 & 4) == 0 )
  {
    _S17_4 = v2 | 4;
    UFG::qSymbol::create_from_string(&hip, "hip");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hip__);
    v2 = _S17_4;
  }
  if ( (v2 & 8) == 0 )
  {
    _S17_4 = v2 | 8;
    UFG::qSymbol::create_from_string(&pel, "pel");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__pel__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x10) == 0 )
  {
    _S17_4 = v2 | 0x10;
    UFG::qSymbol::create_from_string(&hed, "hed");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hed__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x20) == 0 )
  {
    _S17_4 = v2 | 0x20;
    UFG::qSymbol::create_from_string(&poi, "poi");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__poi__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x40) == 0 )
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
  if ( (v2 & 0x100) == 0 )
  {
    _S17_4 = v2 | 0x100;
    UFG::qSymbol::create_from_string(&car, "car");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__car__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x200) == 0 )
  {
    _S17_4 = v2 | 0x200;
    UFG::qSymbol::create_from_string(&foc, "foc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__foc__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x400) == 0 )
  {
    _S17_4 = v2 | 0x400;
    UFG::qSymbol::create_from_string(&fcc, "fcc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fcc__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x800) == 0 )
  {
    _S17_4 = v2 | 0x800;
    UFG::qSymbol::create_from_string(&fcp, "fcp");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fcp__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x1000) == 0 )
  {
    _S17_4 = v2 | 0x1000;
    UFG::qSymbol::create_from_string(&fch, "fch");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__fch__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x2000) == 0 )
  {
    _S17_4 = v2 | 0x2000;
    UFG::qSymbol::create_from_string(&soc, "soc");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__soc__);
    v2 = _S17_4;
  }
  if ( (v2 & 0x4000) == 0 )
  {
    _S17_4 = v2 | 0x4000;
    UFG::qSymbol::create_from_string(&hhm, "hhm");
    atexit(UFG::CharacterSubjectComponent::GetTransformType_::_2_::_dynamic_atexit_destructor_for__hhm__);
  }
  result = 0i64;
  v4 = *tag;
  if ( *tag != def.mUID )
  {
    if ( v4 == cam.mUID )
    {
      return 1i64;
    }
    else if ( v4 == hip.mUID || v4 == pel.mUID )
    {
      return 2i64;
    }
    else if ( v4 == hed.mUID )
    {
      return 3i64;
    }
    else if ( v4 == poi.mUID )
    {
      return 4i64;
    }
    else if ( v4 == pip.mUID )
    {
      return 5i64;
    }
    else if ( v4 == veh.mUID || v4 == car.mUID )
    {
      return 6i64;
    }
    else if ( v4 == foc.mUID )
    {
      return 7i64;
    }
    else if ( v4 == fcc.mUID )
    {
      return 8i64;
    }
    else if ( v4 == fcp.mUID )
    {
      return 9i64;
    }
    else if ( v4 == fch.mUID )
    {
      return 10i64;
    }
    else if ( v4 == soc.mUID || v4 == hhm.mUID )
    {
      return 11i64;
    }
  }
  return result;
}

// File Line: 1138
// RVA: 0x531870
void __fastcall UFG::CharacterSubjectComponent::GetTransformTypePosition(
        UFG::CharacterSubjectComponent *this,
        UFG::qVector3 *pos,
        UFG::CharacterSubjectComponent::SrcTransform transType,
        bool antiJitter)
{
  UFG::CharacterSubjectComponent *v6; // rsi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::qVector3 *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  __int64 v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::SimComponent *m_pSimComponent; // r8
  __int64 v19; // rcx
  int v20; // edi
  int v21; // edi
  int v22; // edi
  __int64 v23; // rbx
  UFG::TransformNodeComponent *v24; // rbx
  UFG::SimComponent *v25; // rdx
  Creature *v26; // rbx
  UFG::SimObjectCharacter *v27; // rsi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v32; // rdx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // edx
  int BoneID; // eax
  int v37; // edi
  int v38; // edi
  UFG::SimComponent *v39; // rdx
  UFG::eSocialInteractionResultEnum v40; // ebx
  UFG::SimObject *m_pSimObject; // rsi
  UFG::SimComponent *ComponentOfType; // rdi
  __int16 v43; // cx
  unsigned int v44; // r8d
  unsigned int v45; // r9d
  UFG::SimComponentHolder *p; // rdi
  __int64 v47; // rdx
  unsigned int vfptr; // r8d
  unsigned int v49; // r9d
  unsigned int v50; // r8d
  unsigned int v51; // r9d
  float v52; // xmm12_4
  float x; // xmm8_4
  float v54; // xmm9_4
  float v55; // xmm7_4
  float v56; // xmm10_4
  float v57; // xmm11_4
  float v58; // xmm6_4
  __int16 v59; // cx
  UFG::FaceActionComponent *v60; // rdi
  unsigned int v61; // r8d
  unsigned int v62; // r9d
  UFG::SimComponentHolder *v63; // rdi
  __int64 v64; // rdx
  unsigned int v65; // r8d
  unsigned int v66; // r9d
  unsigned int v67; // r8d
  unsigned int v68; // r9d
  UFG::Conversation *ConversationReference; // rax
  UFG::TransformNodeComponent *mNext; // rbx
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm7_4
  float v74; // xmm3_4
  __m128 y_low; // xmm4
  float v76; // xmm5_4
  __m128 v77; // xmm2
  float v78; // xmm1_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  UFG::qMatrix44 transform; // [rsp+30h] [rbp-C8h] BYREF

  v6 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  y = v6->mTargetWorld.v3.y;
  z = v6->mTargetWorld.v3.z;
  pos->x = v6->mTargetWorld.v3.x;
  pos->y = y;
  pos->z = z;
  switch ( transType )
  {
    case SrcTransform_Camera:
      v9 = UFG::CharacterSubjectComponent::CambonePosition(v6);
      v10 = v9->y;
      v11 = v9->z;
      pos->x = v9->x;
      pos->y = v10;
      pos->z = v11;
      goto LABEL_138;
    case SrcTransform_Pelvis:
      v12 = UFG::CharacterSubjectComponent::PelvisPosition(v6);
      v13 = v12->y;
      v14 = v12->z;
      pos->x = v12->x;
      pos->y = v13;
      pos->z = v14;
      goto LABEL_138;
    case SrcTransform_Head:
      v15 = (__int64)v6->vfptr[26].__vecDelDtor(v6, 0x40000000u);
      v16 = *(float *)(v15 + 4);
      v17 = *(float *)(v15 + 8);
      pos->x = *(float *)v15;
      pos->y = v16;
      pos->z = v17;
      goto LABEL_138;
    case SrcTransform_POI:
    case SrcTransform_POIParent:
    case SrcTransform_Vehicle:
    case SrcTransform_Focus:
      m_pSimComponent = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v19 = 26i64;
      v20 = transType - 4;
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
      if ( m_pSimComponent
        && (v23 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pSimComponent[1].m_Flags + v19 + 8)
                            + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
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
        pos->x = v24->mWorldTransform.v3.x;
        pos->y = v24->mWorldTransform.v3.y;
        pos->z = v24->mWorldTransform.v3.z;
      }
      goto LABEL_138;
    case SrcTransform_FocusCreatureCambone:
    case SrcTransform_FocusCreaturePelvis:
    case SrcTransform_FocusCreatureHead:
      v25 = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v26 = 0i64;
      if ( v25 )
      {
        v27 = *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v25[1].m_Flags + 86i64)
                                          + *(_QWORD *)&v25[1].m_TypeUID
                                          + 40);
        if ( !v27 )
          goto LABEL_54;
        m_Flags = v27->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v27->m_Components.p[9].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = v27->m_Components.p[8].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            mComponentTableEntryCount = v27->mComponentTableEntryCount;
            size = v27->m_Components.size;
            if ( mComponentTableEntryCount >= size )
            {
LABEL_33:
              m_pComponent = 0i64;
            }
            else
            {
              while ( 1 )
              {
                v32 = &v27->m_Components.p[mComponentTableEntryCount];
                if ( (v32->m_TypeUID & 0xFE000000) == (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
                  && (UFG::BaseAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  break;
                }
                if ( ++mComponentTableEntryCount >= size )
                  goto LABEL_33;
              }
              m_pComponent = v32->m_pComponent;
            }
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(v27, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = v27->m_Components.p[9].m_pComponent;
        }
        if ( m_pComponent )
          v26 = *(Creature **)&m_pComponent[2].m_TypeUID;
      }
      else
      {
        v27 = 0i64;
      }
      if ( v27 && v26 )
      {
        v33 = _S18_4;
        if ( (_S18_4 & 1) == 0 )
        {
          _S18_4 |= 1u;
          camBoneUID = UFG::qStringHashUpper32("CameraSync01", -1);
          v33 = _S18_4;
        }
        if ( (v33 & 2) == 0 )
        {
          _S18_4 = v33 | 2;
          pelBoneUID = UFG::qStringHashUpper32("Bip01 Pelvis", -1);
          v33 = _S18_4;
        }
        if ( (v33 & 4) != 0 )
        {
          v34 = hedBoneUID;
        }
        else
        {
          _S18_4 = v33 | 4;
          v34 = UFG::qStringHashUpper32("Bip01 Head", -1);
          hedBoneUID = v34;
        }
        v35 = camBoneUID;
        if ( transType == SrcTransform_FocusCreaturePelvis )
        {
          v35 = pelBoneUID;
        }
        else if ( transType == SrcTransform_FocusCreatureHead )
        {
          v35 = v34;
        }
        if ( v26->mPose.mRigHandle.mData )
        {
          BoneID = Skeleton::GetBoneID(v26->mPose.mRigHandle.mUFGSkeleton, v35);
          if ( BoneID != -1 )
          {
            Creature::GetTransform(v26, BoneID, &transform);
            pos->x = transform.v3.x;
            pos->y = transform.v3.y;
            pos->z = transform.v3.z;
          }
        }
        goto LABEL_137;
      }
LABEL_54:
      v6 = this;
      v37 = transType - 8;
      if ( v37 )
      {
        v38 = v37 - 1;
        if ( v38 )
        {
          if ( v38 == 1 )
            UFG::CharacterSubjectComponent::GetTransformTypePosition(this, pos, SrcTransform_Head, 1);
        }
        else
        {
          UFG::CharacterSubjectComponent::GetTransformTypePosition(this, pos, SrcTransform_Pelvis, 1);
        }
      }
      else
      {
        UFG::CharacterSubjectComponent::GetTransformTypePosition(this, pos, SrcTransform_Camera, 1);
      }
      goto LABEL_138;
    case SrcTransform_Social:
      v39 = v6->pTargetingSystemBaseComponent.m_pSimComponent;
      v40 = eSOCIALINTERACTIONRESULT_INVALID;
      if ( v6->pSocialTargetOverrideComponent.m_pSimComponent )
        m_pSimObject = v6->pSocialTargetOverrideComponent.m_pSimComponent->m_pSimObject;
      else
        m_pSimObject = 0i64;
      if ( m_pSimObject )
        goto LABEL_69;
      if ( !v39 )
      {
        m_pSimObject = 0i64;
        goto LABEL_68;
      }
      m_pSimObject = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v39[1].m_Flags + 58i64)
                                        + *(_QWORD *)&v39[1].m_TypeUID
                                        + 40);
      if ( !m_pSimObject )
      {
LABEL_68:
        ComponentOfType = 0i64;
        goto LABEL_97;
      }
LABEL_69:
      v43 = m_pSimObject->m_Flags;
      if ( (v43 & 0x4000) == 0 )
      {
        if ( v43 >= 0 )
        {
          if ( (v43 & 0x2000) != 0 )
          {
            vfptr = (unsigned int)m_pSimObject[1].vfptr;
            v49 = m_pSimObject->m_Components.size;
            if ( vfptr < v49 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v47 = vfptr;
                if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                  && (UFG::CharacterSubjectComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_81;
                }
              }
              while ( ++vfptr < v49 );
            }
          }
          else
          {
            if ( (v43 & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::CharacterSubjectComponent::_TypeUID);
              goto LABEL_97;
            }
            v50 = (unsigned int)m_pSimObject[1].vfptr;
            v51 = m_pSimObject->m_Components.size;
            if ( v50 < v51 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v47 = v50;
                if ( (p[v50].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                  && (UFG::CharacterSubjectComponent::_TypeUID & ~p[v50].m_TypeUID & 0x1FFFFFF) == 0 )
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
          v44 = (unsigned int)m_pSimObject[1].vfptr;
          v45 = m_pSimObject->m_Components.size;
          if ( v44 < v45 )
          {
            p = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v47 = v44;
              if ( (p[v44].m_TypeUID & 0xFE000000) == (UFG::CharacterSubjectComponent::_TypeUID & 0xFE000000)
                && (UFG::CharacterSubjectComponent::_TypeUID & ~p[v44].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v44 >= v45 )
                goto LABEL_73;
            }
LABEL_81:
            ComponentOfType = p[v47].m_pComponent;
            goto LABEL_97;
          }
        }
LABEL_73:
        ComponentOfType = 0i64;
        goto LABEL_97;
      }
      ComponentOfType = m_pSimObject->m_Components.p[37].m_pComponent;
      if ( !ComponentOfType
        || ((UFG::CharacterSubjectComponent::_TypeUID ^ ComponentOfType->m_TypeUID) & 0xFE000000) != 0
        || (UFG::CharacterSubjectComponent::_TypeUID & ~ComponentOfType->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        goto LABEL_73;
      }
LABEL_97:
      if ( ComponentOfType )
      {
        v52 = *(float *)(((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))this->vfptr[26].__vecDelDtor)(this)
                       + 8);
        x = this->mTargetWorld.v3.x;
        v54 = this->mTargetWorld.v3.y;
        v55 = *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[26].__vecDelDtor)(ComponentOfType)
                       + 8);
        v56 = *(float *)&ComponentOfType[9].m_Flags;
        v57 = *(float *)(&ComponentOfType[9].m_SimObjIndex + 1);
        v58 = UFG::FollowCameraComponent::rSocialSlideBasePercent;
        if ( !m_pSimObject )
        {
LABEL_132:
          pos->x = x + (float)(v58 * (float)(v56 - x));
          pos->y = v54 + (float)(v58 * (float)(v57 - v54));
          pos->z = (float)((float)(v55 - v52) * v58) + v52;
          goto LABEL_137;
        }
        v59 = m_pSimObject->m_Flags;
        if ( (v59 & 0x4000) != 0 )
        {
          v60 = (UFG::FaceActionComponent *)m_pSimObject->m_Components.p[45].m_pComponent;
          goto LABEL_125;
        }
        if ( v59 >= 0 )
        {
          if ( (v59 & 0x2000) != 0 )
          {
            v65 = (unsigned int)m_pSimObject[1].vfptr;
            v66 = m_pSimObject->m_Components.size;
            if ( v65 < v66 )
            {
              v63 = m_pSimObject->m_Components.p;
              do
              {
                v64 = v65;
                if ( (v63[v65].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && (UFG::FaceActionComponent::_TypeUID & ~v63[v65].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_108;
                }
              }
              while ( ++v65 < v66 );
            }
          }
          else
          {
            if ( (v59 & 0x1000) == 0 )
            {
              v60 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                  m_pSimObject,
                                                  UFG::FaceActionComponent::_TypeUID);
LABEL_125:
              if ( v60 )
              {
                while ( 1 )
                {
                  ConversationReference = UFG::FaceActionComponent::GetConversationReference(v60, v40);
                  if ( ConversationReference )
                  {
                    if ( ConversationReference->m_state == eConversationState_Playing )
                      break;
                  }
                  if ( ++v40 >= NUM_SOCIAL_INTERACTION_RESULT )
                    goto LABEL_132;
                }
                if ( UFG::Conversation::IsSpeaker(ConversationReference, m_pSimObject) )
                  v58 = v58 + UFG::FollowCameraComponent::rSocialTargetTalkPercent;
              }
              goto LABEL_132;
            }
            v67 = (unsigned int)m_pSimObject[1].vfptr;
            v68 = m_pSimObject->m_Components.size;
            if ( v67 < v68 )
            {
              v63 = m_pSimObject->m_Components.p;
              do
              {
                v64 = v67;
                if ( (v63[v67].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                  && (UFG::FaceActionComponent::_TypeUID & ~v63[v67].m_TypeUID & 0x1FFFFFF) == 0 )
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
          v61 = (unsigned int)m_pSimObject[1].vfptr;
          v62 = m_pSimObject->m_Components.size;
          if ( v61 < v62 )
          {
            v63 = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v64 = v61;
              if ( (v63[v61].m_TypeUID & 0xFE000000) == (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
                && (UFG::FaceActionComponent::_TypeUID & ~v63[v61].m_TypeUID & 0x1FFFFFF) == 0 )
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
      v6 = this;
LABEL_138:
      if ( antiJitter && UFG::gAntiJitterRadius > 0.000099999997 )
      {
        v73 = v6->mAntiJitterPosition.x;
        v74 = pos->x - v73;
        y_low = (__m128)LODWORD(pos->y);
        y_low.m128_f32[0] = y_low.m128_f32[0] - v6->mAntiJitterPosition.y;
        v76 = pos->z - v6->mAntiJitterPosition.z;
        v77 = y_low;
        v77.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v74 * v74))
                        + (float)(v76 * v76);
        v78 = _mm_sqrt_ps(v77).m128_f32[0];
        if ( v78 > UFG::gAntiJitterRadius )
        {
          v79 = (float)(v78 - UFG::gAntiJitterRadius) / v78;
          v6->mAntiJitterPosition.x = (float)(v74 * v79) + v73;
          v6->mAntiJitterPosition.y = (float)(y_low.m128_f32[0] * v79) + v6->mAntiJitterPosition.y;
          v6->mAntiJitterPosition.z = (float)(v76 * v79) + v6->mAntiJitterPosition.z;
        }
        v80 = v6->mAntiJitterPosition.y;
        v81 = v6->mAntiJitterPosition.z;
        pos->x = v6->mAntiJitterPosition.x;
        pos->y = v80;
        pos->z = v81;
      }
      return;
    case SrcTransform_TransformNode:
      mNext = (UFG::TransformNodeComponent *)v6->m_pSimObject;
      if ( mNext )
        mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
      if ( mNext )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
        v71 = mNext->mWorldTransform.v3.y;
        v72 = mNext->mWorldTransform.v3.z;
        pos->x = mNext->mWorldTransform.v3.x;
        pos->y = v71;
        pos->z = v72;
      }
      goto LABEL_138;
    default:
      goto LABEL_138;
  }
}

// File Line: 1345
// RVA: 0x532260
void __fastcall UFG::CharacterSubjectComponent::GetTransformTypePosition(
        UFG::CharacterSubjectComponent *this,
        UFG::qVector3 *pos,
        UFG::CharacterSubjectComponent::SrcTransform transType,
        bool antiJitter)
{
  UFG::CharacterSubjectComponent::GetTransformTypePosition(this, pos, transType, antiJitter);
  pos[1].x = 1.0;
}

// File Line: 1352
// RVA: 0x530FC0
UFG::CharacterSubjectComponent::GetTransformTypeOrientation

// File Line: 1535
// RVA: 0x54C0B0
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose(
        UFG::CharacterSubjectComponent *this,
        ActionContext *ac,
        int type,
        unsigned int *left)
{
  __int64 v5; // r12
  unsigned int mUID; // eax
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::Camera *p_mCamera; // r14
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v16; // rdx
  unsigned int v17; // r8d
  unsigned int v18; // r9d
  UFG::CharacterSubjectComponent::SrcTransform TransformType; // edi
  UFG::CharacterSubjectComponent::SrcTransform v20; // ebx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  unsigned int v22; // eax
  UFG::qVector2 tag[2]; // [rsp+8h] [rbp-41h] BYREF
  UFG::qVector3 world_pos; // [rsp+20h] [rbp-29h] BYREF
  UFG::qVector3 pos; // [rsp+30h] [rbp-19h] BYREF
  UFG::qVector3 v26; // [rsp+40h] [rbp-9h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp+7h] BYREF
  bool is_on_screen; // [rsp+B0h] [rbp+67h] BYREF
  unsigned int *retaddr; // [rsp+B8h] [rbp+6Fh]
  _DWORD *v30; // [rsp+C0h] [rbp+77h]
  _DWORD *v31; // [rsp+C8h] [rbp+7Fh]

  tag[1] = (UFG::qVector2)-2i64;
  v5 = type;
  if ( (_S20_0 & 1) == 0 )
  {
    _S20_0 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_4, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::SetContextOverrideFreemanPlayerChoose_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  mUID = nullSym_4.mUID;
  if ( *left == nullSym_4.mUID || *retaddr == nullSym_4.mUID || *v30 == nullSym_4.mUID || *v31 == nullSym_4.mUID )
    goto LABEL_40;
  if ( !ac )
    return;
  m_pPointer = ac->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  p_mCamera = 0i64;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    goto LABEL_30;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    goto LABEL_30;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)m_pPointer[1].vfptr;
    size = m_pPointer->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pPointer->m_Components.p;
      while ( 1 )
      {
        v16 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_21;
      }
LABEL_20:
      m_pComponent = p[v16].m_pComponent;
      goto LABEL_30;
    }
LABEL_21:
    m_pComponent = 0i64;
    goto LABEL_30;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v17 = (unsigned int)m_pPointer[1].vfptr;
    v18 = m_pPointer->m_Components.size;
    if ( v17 < v18 )
    {
      p = m_pPointer->m_Components.p;
      while ( 1 )
      {
        v16 = v17;
        if ( (p[v17].m_TypeUID & 0xFE000000) == (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
          && (UFG::TargetingSystemBaseComponent::_TypeUID & ~p[v17].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_20;
        }
        if ( ++v17 >= v18 )
          goto LABEL_21;
      }
    }
    goto LABEL_21;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_30:
  if ( !m_pComponent )
    return;
  TransformType = (unsigned int)UFG::CharacterSubjectComponent::GetTransformType((int *)tag);
  v20 = (unsigned int)UFG::CharacterSubjectComponent::GetTransformType((int *)tag);
  UFG::CharacterSubjectComponent::GetTransformTypePosition(this, &pos, TransformType, 1);
  UFG::CharacterSubjectComponent::GetTransformTypePosition(this, &world_pos, v20, 1);
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  is_on_screen = 0;
  UFG::Camera::GetScreenCoord(p_mCamera, &result, &world_pos, tag, &is_on_screen);
  UFG::Camera::GetScreenCoord(p_mCamera, &v26, &pos, tag, &is_on_screen);
  v22 = this->mContextOverrideFreemanPlayer[v5].mSymbol.mUID;
  if ( v26.x >= result.x )
  {
    if ( v22 == nullSym_4.mUID || v22 != *left )
    {
      mUID = *retaddr;
      goto LABEL_40;
    }
  }
  else if ( v22 == nullSym_4.mUID || v22 != *retaddr )
  {
    mUID = *left;
LABEL_40:
    this->mContextOverrideFreemanPlayer[v5].mSymbol.mUID = mUID;
    this->mContextOverrideFreemanPlayer[v5].mUID = -1;
  }
}

// File Line: 1620
// RVA: 0x54C610
void __fastcall UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(
        UFG::CharacterSubjectComponent *this,
        int type,
        unsigned int *override)
{
  this->mContextOverrideScriptLocal[type].mSymbol.mUID = *override;
  this->mContextOverrideScriptLocal[type].mUID = -1;
}

// File Line: 1646
// RVA: 0x52BC20
UFG::qSymbol *__fastcall UFG::CharacterSubjectComponent::GetContextOverride(
        UFG::CharacterSubjectComponent *this,
        UFG::qSymbol *result,
        int type)
{
  __int64 v3; // r15
  UFG::SimObject *m_pSimObject; // rbx
  UFG::HealthComponent *m_pComponent; // rbp
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v10; // ecx
  unsigned int v11; // r9d
  __int64 v12; // r8
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  unsigned int v15; // ecx
  unsigned int v16; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::VehicleSubjectComponent *mPrev; // rdi
  unsigned int mUID; // eax
  unsigned int v20; // ecx
  __int16 v21; // r8
  unsigned int v22; // r8d
  unsigned int v23; // r11d
  UFG::SimComponentHolder *p; // r14
  __int64 v25; // r10
  unsigned int v26; // r8d
  unsigned int v27; // r11d
  unsigned int v28; // r8d
  UFG::qSymbol resulta; // [rsp+20h] [rbp-48h] BYREF
  UFG::qSymbol v31; // [rsp+24h] [rbp-44h] BYREF
  UFG::qSymbol v32; // [rsp+28h] [rbp-40h] BYREF
  __int64 v33; // [rsp+30h] [rbp-38h]
  UFG::qSymbol *p_override; // [rsp+38h] [rbp-30h]
  UFG::qSymbol name_a; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol _override; // [rsp+88h] [rbp+20h] BYREF

  v33 = -2i64;
  v3 = type;
  if ( (_S21_0 & 1) == 0 )
  {
    _S21_0 |= 1u;
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&nullSym_5, 0xFFFFFFFF);
    atexit(UFG::CharacterSubjectComponent::GetContextOverride_::_2_::_dynamic_atexit_destructor_for__nullSym__);
  }
  m_pSimObject = this->m_pSimObject;
  m_pComponent = 0i64;
  if ( !m_pSimObject )
    goto LABEL_33;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          do
          {
            v12 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) == 0 )
            {
              goto LABEL_12;
            }
          }
          while ( ++vfptr < size );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(
                              this->m_pSimObject,
                              UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_27;
        }
        v15 = (unsigned int)m_pSimObject[1].vfptr;
        v16 = m_pSimObject->m_Components.size;
        if ( v15 < v16 )
        {
          do
          {
            v12 = (__int64)&m_pSimObject->m_Components.p[v15];
            if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) == 0 )
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
      v10 = (unsigned int)m_pSimObject[1].vfptr;
      v11 = m_pSimObject->m_Components.size;
      if ( v10 < v11 )
      {
        while ( 1 )
        {
          v12 = (__int64)&m_pSimObject->m_Components.p[v10];
          if ( (*(_DWORD *)(v12 + 8) & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
            && (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v10 >= v11 )
            goto LABEL_13;
        }
LABEL_12:
        ComponentOfType = *(UFG::SimComponent **)v12;
        goto LABEL_27;
      }
    }
LABEL_13:
    ComponentOfType = 0i64;
    goto LABEL_27;
  }
  ComponentOfType = m_pSimObject->m_Components.p[44].m_pComponent;
LABEL_27:
  if ( !ComponentOfType
    || !ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev
    || (mNext = ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev[2].mNext) == 0i64
    || (mPrev = (UFG::VehicleSubjectComponent *)mNext[6].mNext[31].mPrev) == 0i64
    || ((UFG::VehicleSubjectComponent::_TypeUID ^ mPrev->m_TypeUID) & 0xFE000000) != 0
    || (UFG::VehicleSubjectComponent::_TypeUID & ~mPrev->m_TypeUID & 0x1FFFFFF) != 0 )
  {
LABEL_33:
    mPrev = 0i64;
  }
  mUID = nullSym_5.mUID;
  v20 = nullSym_5.mUID;
  name_a.mUID = nullSym_5.mUID;
  if ( !mPrev )
    goto LABEL_44;
  if ( !((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))mPrev->vfptr[32].__vecDelDtor)(mPrev) )
  {
LABEL_42:
    v20 = name_a.mUID;
    goto LABEL_43;
  }
  if ( (_DWORD)v3 )
  {
    if ( (_DWORD)v3 == 1 )
    {
      v20 = UFG::VehicleSubjectComponent::GetFollowOverrideContext(mPrev, &resulta)->mUID;
      name_a.mUID = v20;
      mUID = nullSym_5.mUID;
      if ( v20 == nullSym_5.mUID )
        goto LABEL_44;
      name_a.mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&v31, &name_a, "Aim")->mUID;
      p_override = &_override;
      _override.mUID = name_a.mUID;
      if ( !UFG::CharacterSubjectComponent::IsOverrideSymbolValid((UFG::qSymbol)&_override) )
      {
        mUID = nullSym_5.mUID;
        v20 = nullSym_5.mUID;
        name_a.mUID = nullSym_5.mUID;
        goto LABEL_44;
      }
    }
    goto LABEL_42;
  }
  v20 = UFG::VehicleSubjectComponent::GetFollowOverrideContext(mPrev, &v32)->mUID;
  name_a.mUID = v20;
LABEL_43:
  mUID = nullSym_5.mUID;
LABEL_44:
  if ( !m_pSimObject )
    goto LABEL_74;
  v21 = m_pSimObject->m_Flags;
  if ( (v21 & 0x4000) != 0 )
  {
    m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
    goto LABEL_65;
  }
  if ( v21 < 0 )
  {
    m_pComponent = (UFG::HealthComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
    goto LABEL_65;
  }
  if ( (v21 & 0x2000) != 0 )
  {
    v22 = (unsigned int)m_pSimObject[1].vfptr;
    v23 = m_pSimObject->m_Components.size;
    if ( v22 >= v23 )
      goto LABEL_65;
    p = m_pSimObject->m_Components.p;
    while ( 1 )
    {
      v25 = v22;
      if ( (p[v22].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
        && (UFG::HealthComponent::_TypeUID & ~p[v22].m_TypeUID & 0x1FFFFFF) == 0 )
      {
        goto LABEL_56;
      }
      if ( ++v22 >= v23 )
        goto LABEL_65;
    }
  }
  if ( (v21 & 0x1000) != 0 )
  {
    v26 = (unsigned int)m_pSimObject[1].vfptr;
    v27 = m_pSimObject->m_Components.size;
    if ( v26 < v27 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v25 = v26;
        if ( (p[v26].m_TypeUID & 0xFE000000) == (UFG::HealthComponent::_TypeUID & 0xFE000000)
          && (UFG::HealthComponent::_TypeUID & ~p[v26].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v26 >= v27 )
          goto LABEL_65;
      }
LABEL_56:
      m_pComponent = (UFG::HealthComponent *)p[v25].m_pComponent;
    }
  }
  else
  {
    m_pComponent = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                             m_pSimObject,
                                             UFG::HealthComponent::_TypeUID);
    v20 = name_a.mUID;
    mUID = nullSym_5.mUID;
  }
LABEL_65:
  if ( m_pComponent )
  {
    if ( (UFG::HealthComponent::GetIsKilled(m_pComponent)
       || m_pComponent->m_bIsKnockedOut
       || m_pComponent->m_bHealthClampedToMinimum)
      && !(_DWORD)v3 )
    {
      if ( (_S21_0 & 2) == 0 )
      {
        _S21_0 |= 2u;
        UFG::qSymbol::create_from_string(&contextSymbolRagdoll, "Cameras-FollowCameraRagDoll");
        atexit(UFG::CharacterSubjectComponent::GetContextOverride_::_15_::_dynamic_atexit_destructor_for__contextSymbolRagdoll__);
      }
      mUID = contextSymbolRagdoll.mUID;
      goto LABEL_81;
    }
    v20 = name_a.mUID;
    mUID = nullSym_5.mUID;
  }
LABEL_74:
  v28 = this->mContextOverrideScriptGlobal[v3].mSymbol.mUID;
  if ( v28 == mUID
    && (v28 = this->mContextOverrideFreemanNPC[v3].mSymbol.mUID, v28 == mUID)
    && (v28 = this->mContextOverrideFreemanPlayer[v3].mSymbol.mUID, v28 == mUID) )
  {
    if ( v20 == mUID )
    {
      v20 = this->mContextOverrideScriptLocal[v3].mSymbol.mUID;
      if ( v20 == mUID )
      {
LABEL_81:
        result->mUID = mUID;
        return result;
      }
    }
    result->mUID = v20;
  }
  else
  {
    result->mUID = v28;
  }
  return result;
}

// File Line: 1703
// RVA: 0x54D3B0
void __fastcall UFG::CharacterSubjectComponent::SetGotoRise(
        UFG::CharacterSubjectComponent *this,
        float rise,
        float rate,
        float patience)
{
  this->rGotoRise = rise;
  this->rGotoRiseRate = rate;
  this->rGotoRisePatience = patience;
  this->bGotoRise = 1;
}

// File Line: 1712
// RVA: 0x52A9C0
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoRise(
        UFG::CharacterSubjectComponent *this,
        float *rise,
        float *rate,
        float *patience)
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
void __fastcall UFG::CharacterSubjectComponent::SetGotoRadius(
        UFG::CharacterSubjectComponent *this,
        float radius,
        float rate,
        float patience)
{
  this->rGotoRadius = radius;
  this->rGotoRadiusRate = rate;
  this->rGotoRadiusPatience = patience;
  this->bGotoRadius = 1;
}

// File Line: 1734
// RVA: 0x52A990
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoRadius(
        UFG::CharacterSubjectComponent *this,
        float *radius,
        float *rate,
        float *patience)
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
void __fastcall UFG::CharacterSubjectComponent::SetGotoAngle(
        UFG::CharacterSubjectComponent *this,
        float angle,
        float rate,
        float patience,
        bool worldSpace,
        bool useSecond,
        float angleSecond,
        bool farthestAngle,
        bool angleAdditive)
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
char __fastcall UFG::CharacterSubjectComponent::GetAndClearGotoAngle(
        UFG::CharacterSubjectComponent *this,
        float *angle,
        float *rate,
        float *patience,
        bool *localSpace,
        bool *useSecond,
        float *angleSecond,
        bool *farthestAngle,
        bool *angleAdditive)
{
  if ( !this->bGotoAngle )
    return 0;
  *angle = (float)(this->rGotoAngle * 3.1415927) * 0.0055555557;
  *rate = (float)(this->rGotoAngleRate * 3.1415927) * 0.0055555557;
  *patience = this->rGotoAnglePatience;
  *localSpace = !this->bGotoAngleWorldSpace;
  *useSecond = this->bGotoAngleUseSecond;
  *angleSecond = (float)(this->rGotoAngleSecond * 3.1415927) * 0.0055555557;
  *farthestAngle = this->bGotoAngleFarthestAngle;
  *angleAdditive = this->bGotoAngleAdditive;
  this->bGotoAngle = 0;
  return 1;
}

