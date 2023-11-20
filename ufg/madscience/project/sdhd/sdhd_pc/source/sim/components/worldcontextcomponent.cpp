// File Line: 85
// RVA: 0x15441E0
__int64 dynamic_initializer_for__UFG::WorldContextComponent::s_WorldContextComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WorldContextComponent::s_WorldContextComponentList__);
}

// File Line: 86
// RVA: 0x15437F0
__int64 dynamic_initializer_for__UFG::WorldContextComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::WorldContextComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::WorldContextComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::WorldContextComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::WorldContextComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 104
// RVA: 0x547280
UFG::SimComponent *__fastcall UFG::WorldContextComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_WorldContext *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_WorldContext::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = (component_WorldContext *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x270ui64, "WorldContextComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::WorldContextComponent::WorldContextComponent((UFG::WorldContextComponent *)v10, v3->m_NameUID, v7);
    v6 = v11;
  }
  v12 = v3->m_pSimObject;
  if ( (v12->m_Flags >> 14) & 1 )
    v13 = 28;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v12, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v6, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v6;
}

// File Line: 124
// RVA: 0x154C290
__int64 UFG::_dynamic_initializer_for__qSymbol_WC_StinkyFeet__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("WC_StinkyFeet", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_WC_StinkyFeet, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_WC_StinkyFeet__);
}

// File Line: 129
// RVA: 0x51A1C0
void __fastcall UFG::WorldContextComponent::WorldContextComponent(UFG::WorldContextComponent *this, unsigned int name_uid, component_WorldContext *dataPtr)
{
  component_WorldContext *v3; // rdi
  UFG::WorldContextComponent *v4; // rsi
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v5; // rbx
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v6; // rax
  __m128 v7; // xmm4
  __m128 v8; // xmm3
  char v9; // cl
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v10; // [rsp+60h] [rbp+18h]
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v11; // [rsp+60h] [rbp+18h]
  UFG::qList<Attachment,Attachment,1,0> *v12; // [rsp+60h] [rbp+18h]

  v3 = dataPtr;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WorldContextComponent::`vftable;
  v10 = &v4->mFocusParkourHandle;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v4->mFocusParkourHandle.m_pPointer = 0i64;
  v11 = &v4->mParkourHandle;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->mParkourHandle.m_pPointer = 0i64;
  UFG::CoverCornerHandle::CoverCornerHandle(&v4->mFocusCoverCornerHandle);
  UFG::CoverCornerHandle::CoverCornerHandle(&v4->mLatchedCoverCornerHandle);
  v12 = &v4->mAttachments;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&v4->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->mActionTreeComponent);
  v6 = UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev;
  UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&UFG::WorldContextComponent::s_WorldContextComponentList;
  UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::WorldContextComponent::_WorldContextComponentTypeUID,
    "WorldContextComponent");
  v7 = 0i64;
  v8 = 0i64;
  v8.m128_f32[0] = (float)1;
  v4->mLatchTest.v0 = (UFG::qVector4)v8;
  v4->mLatchTest.v1 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 81);
  v4->mLatchTest.v2 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 69);
  v4->mLatchTest.v3 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 21);
  v7.m128_f32[0] = (float)1;
  v4->mWorldAnchor.v0 = (UFG::qVector4)v7;
  v4->mWorldAnchor.v1 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 81);
  v4->mWorldAnchor.v2 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 69);
  v4->mWorldAnchor.v3 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 21);
  v4->mSyncLatchedHandle = 0;
  *(_WORD *)&v4->mbSyncingCoverLCorner = 0;
  v4->mbSyncingCoverParkour = 0;
  v4->mSyncBoneIndex = 0;
  v4->mSyncPositionOnly = 0;
  *(_DWORD *)&v4->mSyncPlanar = 0;
  *(_WORD *)&v4->mLockSyncPosition = 0;
  v4->mDistanceFromEdge = 0.40000001;
  v4->mBlendRate = 1.0;
  v4->mBlendWeight = 1.0;
  v4->mpCoverPosition = 0i64;
  v4->mToSwimming = 0i64;
  v4->mSyncFeet = v3->WC_StinkyFeet;
  v9 = tweaks_added;
  if ( !tweaks_added )
    v9 = 1;
  tweaks_added = v9;
}

// File Line: 179
// RVA: 0x51D620
void __fastcall UFG::WorldContextComponent::~WorldContextComponent(UFG::WorldContextComponent *this)
{
  UFG::WorldContextComponent *v1; // rdi
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v2; // rsi
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v3; // rcx
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v4; // rax
  UFG::qNode<Attachment,Attachment> *v5; // rcx
  UFG::qNode<Attachment,Attachment> *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v17; // rcx
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WorldContextComponent::`vftable;
  UFG::WorldContextComponent::DetachAll(this);
  if ( v1 == UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator )
    UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator = (UFG::WorldContextComponent *)&v1->mPrev[-4];
  v2 = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCharacterPhysicsComponent);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->mAttachments);
  v5 = v1->mAttachments.mNode.mPrev;
  v6 = v1->mAttachments.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mAttachments.mNode.mPrev = &v1->mAttachments.mNode;
  v1->mAttachments.mNode.mNext = &v1->mAttachments.mNode;
  UFG::CoverCornerHandle::~CoverCornerHandle(&v1->mLatchedCoverCornerHandle);
  UFG::CoverCornerHandle::~CoverCornerHandle(&v1->mFocusCoverCornerHandle);
  v7 = &v1->mParkourHandle;
  if ( v1->mParkourHandle.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mParkourHandle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mParkourHandle.mPrev;
  }
  v1->mParkourHandle.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mParkourHandle.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mParkourHandle.mPrev;
  v12 = &v1->mFocusParkourHandle;
  if ( v1->mFocusParkourHandle.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mFocusParkourHandle.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mFocusParkourHandle.mPrev;
  }
  v1->mFocusParkourHandle.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mFocusParkourHandle.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mFocusParkourHandle.mPrev;
  v17 = v2->mPrev;
  v18 = v1->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 206
// RVA: 0x536560
void __fastcall UFG::WorldContextComponent::InitActionTree(UFG::WorldContextComponent *this)
{
  UFG::WorldContextComponent *v1; // rbx

  v1 = this;
  if ( !(_S62_0 & 1) )
  {
    _S62_0 |= 1u;
    pathToSwimmingOpps.mPath.mCount = 0;
    pathToSwimmingOpps.mPath.mData.mOffset = 0i64;
    ActionPath::Append(
      &pathToSwimmingOpps,
      "\\Global\\GlobalActions\\Swimming\\OpportunityToSwimFromWorldContextComponent");
    atexit(UFG::WorldContextComponent::InitActionTree_::_2_::_dynamic_atexit_destructor_for__pathToSwimmingOpps__);
  }
  v1->mToSwimming = ActionNode::Find(&pathToSwimmingOpps, 0i64);
}

// File Line: 221
// RVA: 0x53F3A0
void __fastcall UFG::WorldContextComponent::OnAttach(UFG::WorldContextComponent *this, UFG::SimObject *object)
{
  UFG::WorldContextComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v3; // rcx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v2 = this;
  v3 = &this->mCharacterPhysicsComponent;
  v4 = (UFG::SimObjectCharacter *)object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::CharacterPhysicsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::BindInternal<UFG::SimObject>(
    v3,
    (UFG::SimObject *)&v4->vfptr);
  v9 = &v2->mActionTreeComponent;
  if ( v2->mActionTreeComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mActionTreeComponent.m_pSimObject = 0i64;
    v2->mActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mActionTreeComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->mActionTreeComponent.mNext != &v2->mActionTreeComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mActionTreeComponent.m_Changed = 1;
  v2->mActionTreeComponent.m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v2->mActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mActionTreeComponent,
    (UFG::SimObject *)&v4->vfptr);
  if ( v4 == UFG::GetLocalPlayer() )
    v2->mSyncFeet = 1;
  UFG::WorldContextComponent::InitActionTree(v2);
}

// File Line: 236
// RVA: 0x5412E0
void __fastcall UFG::WorldContextComponent::OnDetach(UFG::WorldContextComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v1; // r8
  UFG::WorldContextComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::CoverPosition *v12; // rcx
  bool v13; // zf

  v1 = &this->mCharacterPhysicsComponent;
  v2 = this;
  if ( this->mCharacterPhysicsComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mCharacterPhysicsComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mCharacterPhysicsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)this->mCharacterPhysicsComponent.mNext != &this->mCharacterPhysicsComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->mActionTreeComponent;
  v1->m_Changed = 1;
  if ( v2->mActionTreeComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->mActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mActionTreeComponent.m_pSimObject = 0i64;
    v2->mActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mActionTreeComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->mActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->mActionTreeComponent.mNext != &v2->mActionTreeComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->mActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->mActionTreeComponent.m_Changed = 1;
  v12 = v2->mpCoverPosition;
  if ( v12 )
  {
    v13 = v12->m_iRefCount-- == 1;
    if ( v13 )
      v12->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v12->vfptr, 1u);
    v2->mpCoverPosition = 0i64;
  }
}

// File Line: 245
// RVA: 0x54D1B0
void __fastcall UFG::WorldContextComponent::SetFocusParkourHandle(UFG::WorldContextComponent *this, UFG::ParkourHandle *newHandle, ActionNode *node)
{
  UFG::ParkourHandle *v3; // rax
  UFG::ParkourHandle *v4; // r10
  UFG::WorldContextComponent *v5; // r9
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rax

  v3 = this->mFocusParkourHandle.m_pPointer;
  v4 = newHandle;
  v5 = this;
  if ( v3 )
  {
    *((_DWORD *)v3 + 38) &= 0xFFFFFFFE;
    v6 = &this->mFocusParkourHandle;
    if ( this->mFocusParkourHandle.m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = 0i64;
  }
  if ( newHandle )
  {
    v9 = &v5->mFocusParkourHandle;
    if ( v5->mFocusParkourHandle.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v5->mFocusParkourHandle.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v5->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v5->mFocusParkourHandle.mPrev;
    }
    v5->mFocusParkourHandle.m_pPointer = v4;
    v12 = v4->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v5->mFocusParkourHandle.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    *((_DWORD *)v5->mFocusParkourHandle.m_pPointer + 38) |= 1u;
    v5->mFocusLatchCount = 0;
  }
}

// File Line: 281
// RVA: 0x53C880
void __fastcall UFG::WorldContextComponent::LatchFocusParkourHandle(UFG::WorldContextComponent *this)
{
  UFG::ParkourHandle *v1; // rdx
  UFG::WorldContextComponent *v2; // rbx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this->mFocusParkourHandle.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    UFG::WorldContextComponent::LatchParkourHandle(this, v1);
    v3 = &v2->mFocusParkourHandle;
    if ( v2->mFocusParkourHandle.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v2->mFocusParkourHandle.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v2->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mFocusParkourHandle.mPrev;
    }
    v2->mFocusParkourHandle.m_pPointer = 0i64;
  }
}

// File Line: 292
// RVA: 0x53C8D0
void __fastcall UFG::WorldContextComponent::LatchParkourHandle(UFG::WorldContextComponent *this, UFG::ParkourHandle *newHandle)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::ParkourHandle *v6; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&this->mParkourHandle.mPrev;
  if ( this->mParkourHandle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = this->mParkourHandle.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    this->mParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&this->mParkourHandle.mPrev;
  }
  this->mParkourHandle.m_pPointer = newHandle;
  if ( newHandle )
  {
    v5 = newHandle->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    this->mParkourHandle.mNext = &newHandle->m_SafePointerList.mNode;
    newHandle->m_SafePointerList.mNode.mPrev = v2;
  }
  v6 = this->mParkourHandle.m_pPointer;
  if ( v6 )
    *((_DWORD *)v6 + 38) |= 1u;
  if ( UFG::WorldContextComponent::s_SimPauseOnSync )
  {
    UFG::Metrics::msInstance.mSimPausedDebug = 1;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  }
}

// File Line: 309
// RVA: 0x522DB0
void __fastcall UFG::WorldContextComponent::ClearLatchedParkourHandle(UFG::WorldContextComponent *this)
{
  UFG::ParkourHandle *v1; // rax
  UFG::WorldContextComponent *v2; // r8
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::ParkourHandle *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this->mParkourHandle.m_pPointer;
  v2 = this;
  if ( v1 )
    *((_DWORD *)v1 + 38) &= 0xFFFFFFFE;
  v3 = &this->mParkourHandle;
  if ( this->mParkourHandle.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v6 = v2->mFocusParkourHandle.m_pPointer;
  if ( v6 )
    *((_DWORD *)v6 + 38) &= 0xFFFFFFFE;
  v7 = &v2->mFocusParkourHandle;
  if ( v2->mFocusParkourHandle.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->mFocusParkourHandle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mFocusParkourHandle.mPrev;
  }
  v2->mFocusParkourHandle.m_pPointer = 0i64;
}

// File Line: 337
// RVA: 0x550050
void __fastcall UFG::WorldContextComponent::StartSyncHandle(UFG::WorldContextComponent *this, int syncBoneIndex, bool positionOnly, bool syncToClosestEndpoint, bool planer, bool syncXforward, bool syncLeftEdge, bool syncRightEdge, float distanceFromEdge, float blendIn)
{
  this->mSyncPlanar = planer;
  this->mSyncLatchedHandle = 1;
  this->mDistanceFromEdge = distanceFromEdge;
  this->mSyncXForward = syncXforward;
  this->mSyncBoneIndex = syncBoneIndex;
  this->mSyncLeftEdge = syncLeftEdge;
  this->mSyncPositionOnly = positionOnly;
  this->mSyncToClosestEndpoint = syncToClosestEndpoint;
  *(_WORD *)&this->mLockSyncPosition = 0;
  this->mSyncRightEdge = syncRightEdge;
  if ( blendIn <= 0.0 )
  {
    this->mBlendRate = 1.0;
    this->mBlendWeight = 1.0;
  }
  else
  {
    this->mBlendWeight = 0.0;
    this->mBlendRate = 1.0 / blendIn;
  }
}

// File Line: 358
// RVA: 0x54FFB0
void __fastcall UFG::WorldContextComponent::StartSync(UFG::WorldContextComponent *this, int syncBoneIndex, bool positionOnly, bool syncToClosestEndpoint, bool planer, bool syncXforward, bool syncLeftEdge, bool syncRightEdge, float distanceFromEdge, float blendIn)
{
  this->mSyncPlanar = planer;
  this->mSyncBoneIndex = syncBoneIndex;
  this->mDistanceFromEdge = distanceFromEdge;
  this->mSyncXForward = syncXforward;
  this->mSyncPositionOnly = positionOnly;
  this->mSyncLeftEdge = syncLeftEdge;
  this->mSyncToClosestEndpoint = syncToClosestEndpoint;
  this->mSyncRightEdge = syncRightEdge;
  *(_WORD *)&this->mLockSyncPosition = 0;
  if ( blendIn <= 0.0 )
  {
    this->mBlendRate = 1.0;
    this->mBlendWeight = 1.0;
  }
  else
  {
    this->mBlendWeight = 0.0;
    this->mBlendRate = 1.0 / blendIn;
  }
}

// File Line: 390
// RVA: 0x54C6A0
void __fastcall UFG::WorldContextComponent::SetCoverPosition(UFG::WorldContextComponent *this, UFG::CoverPosition *pPosition)
{
  UFG::WorldContextComponent *v2; // rdi
  UFG::CoverPosition *v3; // rcx
  UFG::CoverPosition *v4; // rbx
  bool v5; // zf

  v2 = this;
  v3 = this->mpCoverPosition;
  v4 = pPosition;
  if ( v3 )
  {
    v5 = v3->m_iRefCount-- == 1;
    if ( v5 )
      v3->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v3->vfptr, 1u);
    v2->mpCoverPosition = 0i64;
  }
  if ( v4 )
  {
    v2->mpCoverPosition = v4;
    ++v4->m_iRefCount;
  }
}

// File Line: 407
// RVA: 0x55CFA0
void __fastcall UFG::WorldContextComponent::Update(UFG::WorldContextComponent *this, float delta_sec)
{
  float v2; // xmm15_4
  UFG::WorldContextComponent *v3; // rbx
  float v4; // xmm10_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  __int64 v7; // rsi
  ActionNodeRoot *v8; // rax
  ActionNodeRoot *v9; // rdi
  __int64 v10; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // r8
  UFG::ActionTreeComponentBase *v12; // rcx
  ActionNodePlayable *v13; // rax
  Render::DebugDrawContext *v14; // r15
  Render::DebugDrawContext *v15; // r12
  UFG::SimObject *v16; // rsi
  UFG::TransformNodeComponent *v17; // rsi
  signed __int64 v18; // rdi
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  __m128 v23; // xmm5
  float v24; // xmm3_4
  __m128 v25; // xmm2
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  int v30; // xmm8_4
  int v31; // xmm7_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm8_4
  float v35; // xmm7_4
  float v36; // xmm13_4
  float v37; // xmm14_4
  float v38; // xmm11_4
  __m128 v39; // xmm2
  float v40; // xmm7_4
  float v41; // xmm8_4
  float v42; // xmm6_4
  float v43; // xmm3_4
  float v44; // xmm4_4
  float v45; // xmm1_4
  float v46; // xmm0_4
  UFG::SimObject *v47; // rcx
  UFG::SensorComponent *v48; // rdi
  unsigned __int16 v49; // dx
  unsigned int v50; // er8
  unsigned int v51; // er10
  signed __int64 v52; // rdx
  unsigned int v53; // er8
  unsigned int v54; // er10
  UFG::SimObjectProp *v55; // rcx
  UFG::CharacterAnimationComponent *v56; // rcx
  unsigned __int16 v57; // dx
  UFG::CharacterAnimationComponent *v58; // rax
  unsigned int v59; // er8
  unsigned int v60; // er10
  UFG::SimComponentHolder *v61; // rsi
  UFG::SimObject *v62; // rsi
  UFG::TransformNodeComponent *v63; // rsi
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm8_4
  unsigned int i; // er14
  UFG::ParkourHandle *v70; // rdi
  float v71; // xmm3_4
  int v72; // xmm1_4
  int v73; // xmm2_4
  UFG::ParkourHandle *v74; // rax
  UFG::ParkourHandle *v75; // rax
  UFG::ParkourHandle *v76; // rax
  UFG::ParkourHandle *v77; // rax
  UFG::qVector3 *v78; // rax
  float v79; // xmm6_4
  float v80; // xmm7_4
  UFG::qVector3 *v81; // rax
  float v82; // xmm3_4
  __m128 v83; // xmm4
  float v84; // xmm5_4
  __m128 v85; // xmm2
  float v86; // xmm1_4
  float v87; // xmm15_4
  float v88; // xmm1_4
  float v89; // xmm2_4
  float v90; // xmm3_4
  float v91; // xmm1_4
  float v92; // xmm2_4
  float v93; // xmm3_4
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm3_4
  float v97; // xmm1_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  float v100; // xmm13_4
  float v101; // xmm14_4
  float v102; // xmm12_4
  float v103; // xmm14_4
  float v104; // xmm4_4
  float v105; // xmm14_4
  UFG::ParkourHandle *v106; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v107; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v108; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v109; // rax
  UFG::qNode<Attachment,Attachment> **v110; // rdi
  signed __int64 j; // rbx
  UFG::qVector3 p1; // [rsp+80h] [rbp-80h]
  float v113; // [rsp+90h] [rbp-70h]
  float v114; // [rsp+94h] [rbp-6Ch]
  float v115; // [rsp+98h] [rbp-68h]
  UFG::qVector3 world_position; // [rsp+A0h] [rbp-60h]
  float v117; // [rsp+B0h] [rbp-50h]
  float v118; // [rsp+B4h] [rbp-4Ch]
  float v119; // [rsp+B8h] [rbp-48h]
  float v120; // [rsp+BCh] [rbp-44h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h]
  UFG::qVector3 vmax; // [rsp+100h] [rbp+0h]
  UFG::qVector3 v123; // [rsp+110h] [rbp+10h]
  UFG::qVector3 v124; // [rsp+11Ch] [rbp+1Ch]
  float v125; // [rsp+128h] [rbp+28h]
  int v126; // [rsp+12Ch] [rbp+2Ch]
  int v127; // [rsp+130h] [rbp+30h]
  UFG::qVector3 vmin; // [rsp+138h] [rbp+38h]
  UFG::qMatrix44 d; // [rsp+150h] [rbp+50h]
  __int64 v130; // [rsp+190h] [rbp+90h]
  __int64 v131; // [rsp+198h] [rbp+98h]
  UFG::qVector3 result; // [rsp+1A0h] [rbp+A0h]
  UFG::qVector3 v133; // [rsp+1ACh] [rbp+ACh]
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+1C0h] [rbp+C0h]
  char v135; // [rsp+4AC0h] [rbp+49C0h]
  float v136; // [rsp+4AC8h] [rbp+49C8h]
  float v137; // [rsp+4AD0h] [rbp+49D0h]
  float v138; // [rsp+4AD8h] [rbp+49D8h]

  v136 = delta_sec;
  v131 = -2i64;
  v2 = delta_sec;
  v3 = this;
  if ( (LOBYTE(this->m_Flags) >> 1) & 1 )
    return;
  v4 = *(float *)&FLOAT_1_0;
  if ( this->mSyncLatchedHandle || *(_WORD *)&this->mbSyncingCoverParkour || this->mbSyncingCoverRCorner )
  {
    v5 = this->mBlendRate;
    if ( v5 != 0.0 )
    {
      v6 = (float)(v5 * v2) + this->mBlendWeight;
      this->mBlendWeight = v6;
      if ( v5 <= 0.0 )
      {
        if ( v6 <= 0.0 )
          this->mBlendWeight = 0.0;
      }
      else if ( v6 > 1.0 )
      {
        this->mBlendWeight = 1.0;
      }
    }
  }
  if ( this->mToSwimming
    && this->mCharacterPhysicsComponent.m_pSimComponent
    && UFG::CharacterPhysicsComponent::IsInWater((UFG::CharacterPhysicsComponent *)this->mCharacterPhysicsComponent.m_pSimComponent) )
  {
    v7 = ((__int64 (*)(void))v3->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext->mPrev[9].mNext)();
    v8 = (ActionNodeRoot *)((__int64 (*)(void))v3->mToSwimming->vfptr[1].GetResourceOwner)();
    v9 = v8;
    v10 = v8->mActionTreeType.mValue;
    v11 = v3->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    if ( (*((_QWORD *)&v11[4].mNext + v10) || v11[5].mPrev) && (ActionNodeRoot *)v7 != v8 )
    {
      v12 = (UFG::ActionTreeComponentBase *)*((_QWORD *)&v11[4].mNext + v10);
      if ( !v12 )
        v12 = (UFG::ActionTreeComponentBase *)v11[5].mPrev;
      if ( UFG::ActionTreeComponentBase::AllocateFor(v12, v8) )
        ActionNodeRoot::Init(
          v9,
          (ActionContext *)v3->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext);
    }
    v13 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))v3->mToSwimming->vfptr[2].GetClassNameUID)(
                                  v3->mToSwimming,
                                  v3->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext);
    if ( v13 )
      ActionController::PlayTracks((ActionController *)&v3->mActionTreeComponent.m_pSimComponent[3], v13, 0, 0.0);
  }
  v14 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v15 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  if ( UFG::WorldContextComponent::s_DrawGroundDebug )
  {
    v16 = v3->m_pSimObject;
    v17 = v16 ? v16->m_pTransformNodeComponent : 0i64;
    if ( v3->mCharacterPhysicsComponent.m_pSimComponent )
    {
      v18 = (signed __int64)&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_TypeUID;
      v19 = *((float *)&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_pSimObject + 1)
          + *(float *)&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_Flags;
      v20 = *(float *)&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_pSimObject
          + *(float *)&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_NameUID;
      p1.x = *(float *)(&v3->mCharacterPhysicsComponent.m_pSimComponent[5].m_SimObjIndex + 1) + *(float *)v18;
      p1.y = v20;
      p1.z = v19;
      Render::DebugDrawContext::DrawLine(
        v14,
        (UFG::qVector3 *)v18,
        &p1,
        &UFG::qColour::Cyan,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      v21 = *(float *)(v18 + 20);
      if ( v21 < 0.94999999 && v21 > 0.050000001 )
      {
        v22 = *(float *)(v18 + 12);
        v23 = (__m128)*(unsigned int *)(v18 + 16);
        v24 = v21 - (float)(1.0 / v21);
        v25 = v23;
        v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
        v26 = v25.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
        v27 = v26 * v24;
        v28 = v26 * v23.m128_f32[0];
        v29 = v26 * v22;
        v30 = LODWORD(v27) ^ _xmm[0];
        v31 = LODWORD(v28) ^ _xmm[0];
        v32 = v27 + *(float *)(v18 + 8);
        v33 = v28 + *(float *)(v18 + 4);
        p1.x = v29 + *(float *)v18;
        p1.y = v33;
        p1.z = v32;
        Render::DebugDrawContext::DrawLine(
          v14,
          (UFG::qVector3 *)v18,
          &p1,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        v34 = *(float *)&v30 + *(float *)(v18 + 8);
        v35 = *(float *)&v31 + *(float *)(v18 + 4);
        p1.x = COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) + *(float *)v18;
        p1.y = v35;
        p1.z = v34;
        Render::DebugDrawContext::DrawLine(
          v14,
          (UFG::qVector3 *)v18,
          &p1,
          &UFG::qColour::Red,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        if ( v17 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v17);
          v36 = v17->mWorldTransform.v3.x;
          v37 = v17->mWorldTransform.v3.y;
          v38 = v17->mWorldTransform.v3.z;
          UFG::TransformNodeComponent::UpdateWorldTransform(v17);
          v39 = (__m128)LODWORD(v17->mWorldTransform.v0.y);
          v40 = *(float *)(v18 + 16);
          v41 = *(float *)(v18 + 12);
          v42 = *(float *)(v18 + 20);
          v43 = (float)((float)(v17->mWorldTransform.v0.x * v41) + (float)(v17->mWorldTransform.v0.y * v40))
              + (float)(v17->mWorldTransform.v0.z * v42);
          if ( v43 > -0.94999999 && v43 < 0.94999999 )
          {
            v44 = v17->mWorldTransform.v0.z - (float)(v42 * v43);
            v39.m128_f32[0] = (float)((float)((float)(v39.m128_f32[0] - (float)(v40 * v43))
                                            * (float)(v39.m128_f32[0] - (float)(v40 * v43)))
                                    + (float)((float)(v17->mWorldTransform.v0.x - (float)(v41 * v43))
                                            * (float)(v17->mWorldTransform.v0.x - (float)(v41 * v43))))
                            + (float)(v44 * v44);
            if ( v39.m128_f32[0] == 0.0 )
              v45 = 0.0;
            else
              v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
            v46 = v44 * v45;
            UFG::qASin(v44 * v45);
            p1.x = v36;
            p1.y = v37;
            p1.z = v38 + 0.1;
            Render::DebugDrawContext::DrawText(
              v14,
              &p1,
              &UFG::qColour::Green,
              "Grade:%0.3f:",
              (float)((float)(v46 * 180.0) * 0.31830987));
          }
        }
      }
    }
  }
  if ( UFG::WorldContextComponent::s_DrawParkourSensing )
  {
    gDebugPark = 1;
    v47 = v3->m_pSimObject;
    if ( !v47 )
    {
LABEL_42:
      v48 = 0i64;
      goto LABEL_61;
    }
    v49 = v47->m_Flags;
    if ( (v49 >> 14) & 1 )
    {
      v48 = (UFG::SensorComponent *)v47->m_Components.p[26].m_pComponent;
      goto LABEL_61;
    }
    if ( (v49 & 0x8000u) != 0 )
    {
      v48 = (UFG::SensorComponent *)v47->m_Components.p[26].m_pComponent;
      goto LABEL_61;
    }
    if ( (v49 >> 13) & 1 )
    {
      v50 = (unsigned int)v47[1].vfptr;
      v51 = v47->m_Components.size;
      if ( v50 >= v51 )
        goto LABEL_42;
      while ( 1 )
      {
        v52 = (signed __int64)&v47->m_Components.p[v50];
        if ( (*(_DWORD *)(v52 + 8) & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && !(UFG::SensorComponent::_TypeUID & ~*(_DWORD *)(v52 + 8) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v50 >= v51 )
          goto LABEL_42;
      }
    }
    else
    {
      if ( !((v49 >> 12) & 1) )
      {
        v48 = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(v47, UFG::SensorComponent::_TypeUID);
LABEL_61:
        v55 = (UFG::SimObjectProp *)v3->m_pSimObject;
        if ( !v55 )
        {
LABEL_62:
          v56 = 0i64;
          goto LABEL_85;
        }
        v57 = v55->m_Flags;
        if ( (v57 >> 14) & 1 )
        {
          v56 = (UFG::CharacterAnimationComponent *)v55->m_Components.p[9].m_pComponent;
          if ( v56 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v56->m_TypeUID) & 0xFE000000) )
          {
            if ( UFG::CharacterAnimationComponent::_TypeUID & ~v56->m_TypeUID & 0x1FFFFFF )
              v56 = 0i64;
            goto LABEL_85;
          }
          goto LABEL_62;
        }
        if ( (v57 & 0x8000u) != 0 )
        {
          v56 = (UFG::CharacterAnimationComponent *)v55->m_Components.p[9].m_pComponent;
          if ( v56 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v56->m_TypeUID) & 0xFE000000) )
          {
            if ( UFG::CharacterAnimationComponent::_TypeUID & ~v56->m_TypeUID & 0x1FFFFFF )
              v56 = 0i64;
            goto LABEL_85;
          }
          goto LABEL_62;
        }
        if ( (v57 >> 13) & 1 )
        {
          v58 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v55);
        }
        else
        {
          if ( (v57 >> 12) & 1 )
          {
            v59 = v55->mComponentTableEntryCount;
            v60 = v55->m_Components.size;
            if ( v59 < v60 )
            {
              v61 = v55->m_Components.p;
              while ( (v61[v59].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || UFG::CharacterAnimationComponent::_TypeUID & ~v61[v59].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v59 >= v60 )
                  goto LABEL_62;
              }
              v56 = (UFG::CharacterAnimationComponent *)v61[v59].m_pComponent;
              goto LABEL_85;
            }
            goto LABEL_62;
          }
          v58 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v55->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v56 = v58;
LABEL_85:
        v62 = v3->m_pSimObject;
        if ( v62 )
          v63 = v62->m_pTransformNodeComponent;
        else
          v63 = 0i64;
        if ( v48 && v56 && v63 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v63);
          v64 = v63->mWorldTransform.v3.y;
          v65 = v63->mWorldTransform.v3.z;
          p1.x = v63->mWorldTransform.v3.x;
          p1.y = v64;
          p1.z = v65;
          UFG::TransformNodeComponent::UpdateWorldTransform(v63);
          v130 = 0i64;
          v118 = FLOAT_3_4028235e38;
          UFG::SensorComponent::GetExtents(v48, &vmin, &vmax);
          LODWORD(v66) = COERCE_UNSIGNED_INT(vmax.x - vmin.x) & _xmm;
          LODWORD(v119) = COERCE_UNSIGNED_INT(vmax.x - vmin.x) & _xmm;
          LODWORD(v67) = COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm;
          LODWORD(v117) = COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm;
          LODWORD(v68) = COERCE_UNSIGNED_INT(vmax.z - vmin.z) & _xmm;
          LODWORD(v120) = COERCE_UNSIGNED_INT(vmax.z - vmin.z) & _xmm;
          `eh vector constructor iterator(
            out.p,
            0x18ui64,
            768,
            (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
          out.size = 0;
          UFG::SensorComponent::GetParkourHandles(v48, &out);
          v135 = 0;
          for ( i = 0; i < out.size; ++i )
          {
            v70 = (UFG::ParkourHandle *)*((_QWORD *)&out.p[0].m_pPointer + 3 * i);
            if ( v70 )
            {
              if ( v66 >= v67 )
                v71 = v67;
              else
                v71 = v66;
              v72 = LODWORD(v63->mWorldTransform.v0.y);
              v73 = LODWORD(v63->mWorldTransform.v0.z);
              v125 = v63->mWorldTransform.v0.x;
              v126 = v72;
              v127 = v73;
              compareParkourHandles(
                0xFFFFFFFF,
                &p1,
                (UFG::qVector3 *)&v125,
                3.1415927,
                0.0,
                0.0,
                v71,
                0.0,
                v68,
                &world_position,
                v70,
                (UFG::ParkourHandle **)&v130,
                &v118,
                (bool *)&v135);
              v74 = v3->mFocusParkourHandle.m_pPointer;
              if ( v74 && v70 == v74 )
              {
                Render::DebugDrawContext::DrawLine(
                  v15,
                  &p1,
                  &world_position,
                  &UFG::qColour::Cyan,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                Render::DebugDrawContext::DrawText(v14, &world_position, &UFG::qColour::Cyan, "FocusHandle");
              }
              v75 = v3->mParkourHandle.m_pPointer;
              if ( v75 && v70 == v75 )
              {
                Render::DebugDrawContext::DrawLine(
                  v15,
                  &p1,
                  &world_position,
                  &UFG::qColour::DeepPink,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                v124.x = world_position.x;
                v124.y = world_position.y;
                v124.z = world_position.z - 0.1;
                Render::DebugDrawContext::DrawText(v14, &v124, &UFG::qColour::DeepPink, "LatchedHandle");
              }
              v76 = v3->mFocusParkourHandle.m_pPointer;
              if ( v76 && v70 == v76 || (v77 = v3->mParkourHandle.m_pPointer) != 0i64 && v70 == v77 )
              {
                v78 = UFG::ParkourHandle::GetPosition(v70, &result);
                v137 = v78->x;
                v79 = v78->y;
                v138 = v78->y;
                v80 = v78->z;
                v113 = v78->z;
                v81 = UFG::ParkourHandle::GetAxis(v70, &v133);
                v82 = v81->y;
                v83 = (__m128)LODWORD(v81->x);
                v84 = v81->z;
                v85 = v83;
                v85.m128_f32[0] = (float)((float)(v83.m128_f32[0] * v83.m128_f32[0]) + (float)(v82 * v82))
                                + (float)(v84 * v84);
                if ( v85.m128_f32[0] == 0.0 )
                  v86 = 0.0;
                else
                  v86 = v4 / COERCE_FLOAT(_mm_sqrt_ps(v85));
                v87 = v86 * v84;
                v114 = v86 * v82;
                v115 = v86 * v83.m128_f32[0];
                UFG::TransformNodeComponent::UpdateWorldTransform(v63);
                v88 = v63->mWorldTransform.v0.y;
                v89 = v63->mWorldTransform.v0.z;
                v90 = v63->mWorldTransform.v0.w;
                m.v0.x = v63->mWorldTransform.v0.x;
                m.v0.y = v88;
                m.v0.z = v89;
                m.v0.w = v90;
                v91 = v63->mWorldTransform.v1.y;
                v92 = v63->mWorldTransform.v1.z;
                v93 = v63->mWorldTransform.v1.w;
                m.v1.x = v63->mWorldTransform.v1.x;
                m.v1.y = v91;
                m.v1.z = v92;
                m.v1.w = v93;
                v94 = v63->mWorldTransform.v2.y;
                v95 = v63->mWorldTransform.v2.z;
                v96 = v63->mWorldTransform.v2.w;
                m.v2.x = v63->mWorldTransform.v2.x;
                m.v2.y = v94;
                m.v2.z = v95;
                m.v2.w = v96;
                v97 = v63->mWorldTransform.v3.y;
                v98 = v63->mWorldTransform.v3.z;
                v99 = v63->mWorldTransform.v3.w;
                m.v3.x = v63->mWorldTransform.v3.x;
                m.v3.y = v97;
                m.v3.z = v98;
                m.v3.w = v99;
                UFG::qInverseAffine(&d, &m);
                v100 = (float)((float)((float)(v137 * d.v0.x) + (float)(v79 * d.v1.x)) + (float)(v80 * d.v2.x)) + d.v3.x;
                v101 = (float)((float)((float)(v137 * d.v0.y) + (float)(v79 * d.v1.y)) + (float)(v80 * d.v2.y)) + d.v3.y;
                v102 = (float)((float)((float)(v137 * d.v0.z) + (float)(v138 * d.v1.z)) + (float)(v113 * d.v2.z))
                     + d.v3.z;
                v137 = (float)((float)((float)(v137 * d.v0.w) + (float)(v138 * d.v1.w)) + (float)(v113 * d.v2.w))
                     + d.v3.w;
                LODWORD(v103) = COERCE_UNSIGNED_INT(
                                  v101
                                / (float)((float)((float)(v114 * d.v1.y) + (float)(d.v0.y * v115))
                                        + (float)(v87 * d.v2.y))) ^ _xmm[0];
                v104 = (float)(v103
                             * (float)((float)((float)(v114 * d.v1.x) + (float)(d.v0.x * v115)) + (float)(v87 * d.v2.x)))
                     + v100;
                v105 = (float)(v103
                             * (float)((float)((float)(v114 * d.v1.z) + (float)(d.v0.z * v115)) + (float)(v87 * d.v2.z)))
                     + v102;
                v123.x = (float)((float)((float)(m.v0.x * v104) + (float)(m.v1.x * 0.0)) + (float)(m.v2.x * v105))
                       + (float)(m.v3.x * v137);
                v123.y = (float)((float)((float)(m.v0.y * v104) + (float)(m.v1.y * 0.0)) + (float)(m.v2.y * v105))
                       + (float)(m.v3.y * v137);
                v123.z = (float)((float)((float)(m.v0.z * v104) + (float)(m.v1.z * 0.0)) + (float)(m.v2.z * v105))
                       + (float)(m.v3.z * v137);
                Render::DebugDrawContext::DrawLine(
                  v15,
                  &p1,
                  &v123,
                  &UFG::qColour::Cyan,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                v66 = v119;
                v67 = v117;
                v68 = v120;
                v4 = *(float *)&FLOAT_1_0;
              }
            }
          }
          out.size = 0;
          `eh vector destructor iterator(
            out.p,
            0x18ui64,
            768,
            (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
        }
        goto LABEL_112;
      }
      v53 = (unsigned int)v47[1].vfptr;
      v54 = v47->m_Components.size;
      if ( v53 >= v54 )
        goto LABEL_42;
      while ( 1 )
      {
        v52 = (signed __int64)&v47->m_Components.p[v53];
        if ( (*(_DWORD *)(v52 + 8) & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && !(UFG::SensorComponent::_TypeUID & ~*(_DWORD *)(v52 + 8) & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v53 >= v54 )
          goto LABEL_42;
      }
    }
    v48 = *(UFG::SensorComponent **)v52;
    goto LABEL_61;
  }
LABEL_112:
  v106 = v3->mFocusParkourHandle.m_pPointer;
  if ( v106 )
  {
    if ( v3->mFocusLatchCount > 10 )
    {
      *((_DWORD *)v106 + 38) &= 0xFFFFFFFE;
      v107 = &v3->mFocusParkourHandle;
      if ( v3->mFocusParkourHandle.m_pPointer )
      {
        v108 = v107->mPrev;
        v109 = v3->mFocusParkourHandle.mNext;
        v108->mNext = v109;
        v109->mPrev = v108;
        v107->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v107->mPrev;
        v3->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->mFocusParkourHandle.mPrev;
      }
      v3->mFocusParkourHandle.m_pPointer = 0i64;
    }
    ++v3->mFocusLatchCount;
  }
  v110 = &v3->mAttachments.mNode.mNext[-1].mNext;
  for ( j = (signed __int64)&v3->mbSyncingCoverParkour;
        v110 != (UFG::qNode<Attachment,Attachment> **)j;
        v110 = &v110[2][-1].mNext )
  {
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))(*v110)->mNext)(v110);
  }
}ePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v107->mPrev;
        v3->mFocusParkourHandle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v3->mFocusParkourHandle.mPrev;
      }
      v3->mFocusParkourHandle.m_pPointer = 0i64;
    }
    ++v3->mFocusLatchCount;
  }
  v110 = &v3->mAttachments.mNode.mNext[-1].mNext;
  for ( j = (signed __int64)&v3->mbSyncingCoverParkour;
 

// File Line: 737
// RVA: 0x564070
void __fastcall UFG::adjustTransformInReferanceFrame_RotX(UFG::qMatrix44 *inputOutputFrame, UFG::qMatrix44 *adjustmentFrame, float rotX)
{
  UFG::qMatrix44 *v3; // rdi
  UFG::qMatrix44 *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qMatrix44 result; // [rsp+20h] [rbp-188h]
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-148h]
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-108h]
  UFG::qMatrix44 v12; // [rsp+E0h] [rbp-C8h]

  v3 = inputOutputFrame;
  v4 = adjustmentFrame;
  UFG::qInverseAffine(&b, adjustmentFrame);
  UFG::qMatrix44::operator*(v3, &result, &b);
  UFG::qRotationMatrixX(&dest, rotX);
  result.v0 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 0),
                                       (__m128)dest.v0),
                                     (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 85), (__m128)dest.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 170), (__m128)dest.v2)),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)result.v0, (__m128)result.v0, 255), (__m128)dest.v3));
  result.v1 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 0),
                                       (__m128)dest.v0),
                                     (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 85), (__m128)dest.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 170), (__m128)dest.v2)),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)result.v1, (__m128)result.v1, 255), (__m128)dest.v3));
  result.v2 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 0),
                                       (__m128)dest.v0),
                                     (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 85), (__m128)dest.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 170), (__m128)dest.v2)),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)result.v2, (__m128)result.v2, 255), (__m128)dest.v3));
  result.v3 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 85), (__m128)dest.v1),
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 0),
                                       (__m128)dest.v0),
                                     (__m128)0i64)),
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 170), (__m128)dest.v2)),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)result.v3, (__m128)result.v3, 255), (__m128)dest.v3));
  v5 = UFG::qMatrix44::operator*(&result, &v12, v4);
  v6 = v5->v1;
  v7 = v5->v2;
  v8 = v5->v3;
  v3->v0 = v5->v0;
  v3->v1 = v6;
  v3->v2 = v7;
  v3->v3 = v8;
}

// File Line: 751
// RVA: 0x154C560
__int64 UFG::_dynamic_initializer_for__sLeftArmIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftArmIK", 0xFFFFFFFF);
  UFG::sLeftArmIKNameUID = result;
  return result;
}

// File Line: 752
// RVA: 0x154C600
__int64 UFG::_dynamic_initializer_for__sRightArmIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightArmIK", 0xFFFFFFFF);
  UFG::sRightArmIKNameUID = result;
  return result;
}

// File Line: 753
// RVA: 0x154C5A0
__int64 UFG::_dynamic_initializer_for__sLeftLegIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftLegIK", 0xFFFFFFFF);
  UFG::sLeftLegIKNameUID = result;
  return result;
}

// File Line: 754
// RVA: 0x154C640
__int64 UFG::_dynamic_initializer_for__sRightLegIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightLegIK", 0xFFFFFFFF);
  UFG::sRightLegIKNameUID = result;
  return result;
}

// File Line: 756
// RVA: 0x154C660
__int64 UFG::_dynamic_initializer_for__sRightShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwist", 0xFFFFFFFF);
  UFG::sRightShoulderTwistUID = result;
  return result;
}

// File Line: 757
// RVA: 0x154C5C0
__int64 UFG::_dynamic_initializer_for__sLeftShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwist", 0xFFFFFFFF);
  UFG::sLeftShoulderTwistUID = result;
  return result;
}

// File Line: 758
// RVA: 0x154C620
__int64 UFG::_dynamic_initializer_for__sRightForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightForearmTwist", 0xFFFFFFFF);
  UFG::sRightForearmTwistUID = result;
  return result;
}

// File Line: 759
// RVA: 0x154C580
__int64 UFG::_dynamic_initializer_for__sLeftForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftForearmTwist", 0xFFFFFFFF);
  UFG::sLeftForearmTwistUID = result;
  return result;
}

// File Line: 761
// RVA: 0x154C9E0
__int64 UFG::_dynamic_initializer_for__sSyncUID__()
{
  UFG::qSymbolUC::create_from_string(&UFG::sSyncUID, "Sync01");
  return atexit(UFG::_dynamic_atexit_destructor_for__sSyncUID__);
}

// File Line: 775
// RVA: 0x56DAD0
void __fastcall UFG::syncHands(Creature *creature, UFG::qVector3 *origin, UFG::qVector3 *axis)
{
  UFG::qVector3 *v3; // rbx
  Creature *v4; // rbp
  signed __int64 v5; // rdi
  UFG::qNode<PoseDriver,PoseDriver> *v6; // rax
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v7; // rcx
  signed __int64 v8; // rax
  signed __int64 v9; // r15
  signed __int64 v10; // r14
  signed __int64 v11; // rsi
  __int64 v12; // rdx
  __int64 v13; // rdx
  int v14; // eax
  int v15; // eax
  bool v16; // zf
  __m128 v17; // xmm2
  int v18; // eax
  float v19; // xmm5_4
  __m128 v20; // xmm2
  float v21; // xmm4_4
  __m128 v22; // xmm1
  float v23; // xmm3_4
  float v24; // xmm8_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // xmm6_4
  __int64 v28; // rdx
  UFG::qMatrix44 adjustmentFrame; // [rsp+20h] [rbp-148h]
  __m128 v30; // [rsp+60h] [rbp-108h]
  __m128 v31; // [rsp+70h] [rbp-F8h]
  __m128 v32; // [rsp+80h] [rbp-E8h]
  __m128 v33; // [rsp+90h] [rbp-D8h]
  UFG::qMatrix44 transform; // [rsp+A0h] [rbp-C8h]
  UFG::qMatrix44 inputOutputFrame; // [rsp+E0h] [rbp-88h]

  v3 = axis;
  v4 = creature;
  if ( sEnableSyncHands )
  {
    v5 = 0i64;
    v6 = creature->mPoseDrivers.mNode.mNext;
    v7 = &creature->m_SafePointerList;
    v8 = (signed __int64)&v6[-1];
    v9 = 0i64;
    v10 = 0i64;
    v11 = 0i64;
    if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != v7 )
    {
      v12 = (unsigned int)sEnableForarmTwistTest;
      do
      {
        if ( !v5 && *(_DWORD *)(v8 + 44) == UFG::sLeftArmIKNameUID )
          v5 = v8;
        if ( !v9 && *(_DWORD *)(v8 + 44) == UFG::sRightArmIKNameUID )
          v9 = v8;
        if ( sEnableForarmTwistTest )
        {
          if ( !v10 && *(_DWORD *)(v8 + 44) == UFG::sLeftForearmTwistUID )
            v10 = v8;
          if ( !v11 && *(_DWORD *)(v8 + 44) == UFG::sRightForearmTwistUID )
            v11 = v8;
        }
        v8 = *(_QWORD *)(v8 + 24) - 16i64;
      }
      while ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != v7 );
      if ( v5 && v9 )
      {
        LOBYTE(v12) = 1;
        (*(void (__fastcall **)(signed __int64, __int64, _QWORD, _QWORD))(*(_QWORD *)v5 + 88i64))(
          v5,
          v12,
          UFG::sLeftArmIKNameUID,
          UFG::sRightArmIKNameUID);
        LOBYTE(v13) = 1;
        (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v9 + 88i64))(v9, v13);
        v14 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v5 + 112i64))(v5);
        Creature::GetTransform(v4, v14, &transform);
        v15 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v9 + 112i64))(v9);
        Creature::GetTransform(v4, v15, &inputOutputFrame);
        Creature::GetTransform(v4, sFollowJointID, &adjustmentFrame);
        v16 = v4->mPose.mRigHandle.mData == 0i64;
        v17 = 0i64;
        v17.m128_f32[0] = (float)1;
        v30 = v17;
        v33 = _mm_shuffle_ps(v17, v17, 21);
        v31 = _mm_shuffle_ps(v17, v17, 81);
        v32 = _mm_shuffle_ps(v17, v17, 69);
        if ( v16 )
          v18 = -1;
        else
          v18 = Skeleton::GetBoneID(v4->mPose.mRigHandle.mUFGSkeleton, UFG::sSyncUID.mUID);
        Creature::GetTransform(v4, v18, &adjustmentFrame);
        v19 = v3->x;
        v20 = (__m128)LODWORD(v3->y);
        v21 = *(float *)&FLOAT_1_0;
        v22 = v20;
        v22.m128_f32[0] = (float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v19 * v19);
        if ( v22.m128_f32[0] == 0.0 )
          v23 = 0.0;
        else
          v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
        v24 = v3->z;
        v25 = (float)((float)(v20.m128_f32[0] * (float)(v20.m128_f32[0] * v23)) + (float)(v19 * (float)(v19 * v23)))
            + (float)(v3->z * (float)(v23 * 0.0));
        if ( v25 <= -1.0 )
        {
          v25 = FLOAT_N1_0;
        }
        else if ( v25 >= 1.0 )
        {
          goto LABEL_31;
        }
        v21 = v25;
LABEL_31:
        v26 = acosf(v21);
        v27 = LODWORD(v26);
        if ( v24 < 0.0 )
          v27 = LODWORD(v26) ^ _xmm[0];
        UFG::adjustTransformInReferanceFrame_RotX(&transform, &adjustmentFrame, *(float *)&v27);
        UFG::adjustTransformInReferanceFrame_RotX(&inputOutputFrame, &adjustmentFrame, *(float *)&v27);
        (*(void (__fastcall **)(signed __int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v5 + 120i64))(
          v5,
          &v4->mPose,
          &transform);
        (*(void (__fastcall **)(signed __int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v9 + 120i64))(
          v9,
          &v4->mPose,
          &inputOutputFrame);
        if ( v10 )
        {
          LOBYTE(v28) = 1;
          (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v10 + 88i64))(v10, v28);
        }
        if ( v11 )
        {
          LOBYTE(v28) = 1;
          (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v11 + 88i64))(v11, v28);
        }
        Creature::updateEffectorsToPose(v4);
        (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v5 + 88i64))(v5, 0i64);
        (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v9 + 88i64))(v9, 0i64);
        if ( v10 )
          (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v10 + 88i64))(v10, 0i64);
        if ( v11 )
          (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v11 + 88i64))(v11, 0i64);
        return;
      }
    }
  }
}

// File Line: 892
// RVA: 0x154C520
void UFG::_dynamic_initializer_for__sGroundNormalFilter__()
{
  sGroundNormalFilter = cosf(1.0471976);
}

// File Line: 894
// RVA: 0x563E30
__int64 __fastcall UFG::adJustEffectorToGround(Creature *creature, int jointID, UFG::qMatrix44 *inputOutupMatrix, UFG::CollisionLayers layer, float legUp)
{
  unsigned int v5; // ebx
  UFG::qMatrix44 *v6; // rsi
  unsigned __int8 v7; // di
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  Render::DebugDrawContext *v15; // rbx
  Render::DebugDrawContext *v16; // rax
  UFG::qColour *v17; // r9
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-B0h]
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h]

  v5 = layer;
  v6 = inputOutupMatrix;
  v7 = 0;
  Creature::GetTransform(creature, jointID, inputOutupMatrix);
  v8 = v6->v3.x;
  v9 = v6->v3.y;
  v10 = v6->v3.x;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeyIndex = 0;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mOutput.m_rootCollidable = 0i64;
  v11 = v6->v3.z;
  rayStart.x = v10 + (float)(UFG::qVector3::msDirUp.x * legUp);
  data.mDebugName = 0i64;
  data.mCollisionModelName.mUID = -1;
  rayStart.y = v9 + (float)(UFG::qVector3::msDirUp.y * legUp);
  rayEnd.x = v8 - (float)(UFG::qVector3::msDirUp.x * sDownLeg);
  rayEnd.y = v9 - (float)(UFG::qVector3::msDirUp.y * sDownLeg);
  rayEnd.z = v11 - (float)(UFG::qVector3::msDirUp.z * sDownLeg);
  rayStart.z = v11 + (float)(UFG::qVector3::msDirUp.z * legUp);
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, v5);
  if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
  {
    v12 = data.point.x;
    v13 = data.point.y;
    v7 = 0;
    v6->v3.w = 1.0;
    v6->v3.x = v12;
    v14 = data.point.z;
    v6->v3.y = v13;
    v6->v3.z = v14;
    if ( data.normal.z >= sGroundNormalFilter )
      v7 = 1;
  }
  if ( sDebugDraw )
  {
    v15 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    if ( v7 )
    {
      Render::DebugDrawContext::DrawCoord(v16, v6, sContactScale, 0i64);
      v17 = &UFG::qColour::Gold;
    }
    else
    {
      v17 = &UFG::qColour::DeepPink;
    }
    Render::DebugDrawContext::DrawLine(v15, &rayStart, &rayEnd, v17, &UFG::qMatrix44::msIdentity, 0i64, 0);
  }
  return v7;
}

// File Line: 942
// RVA: 0x56D880
void __fastcall UFG::syncFeet(Creature *creature, UFG::CollisionLayers layer, float legUp)
{
  UFG::CollisionLayers v3; // ebp
  Creature *v4; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *v5; // rax
  signed __int64 v6; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v7; // rcx
  signed __int64 v8; // rax
  signed __int64 v9; // rdi
  int v10; // eax
  __int64 v11; // rdx
  __int64 v12; // rax
  int v13; // eax
  __int64 v14; // rdx
  __int64 v15; // rax
  UFG::qMatrix44 inputOutupMatrix; // [rsp+30h] [rbp-98h]
  UFG::qMatrix44 v17; // [rsp+70h] [rbp-58h]

  v3 = layer;
  v4 = creature;
  if ( sEnableSyncFeet )
  {
    v5 = creature->mPoseDrivers.mNode.mNext;
    v6 = 0i64;
    v7 = &creature->m_SafePointerList;
    v8 = (signed __int64)&v5[-1];
    v9 = 0i64;
    if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != v7 )
    {
      do
      {
        if ( !v6 && *(_DWORD *)(v8 + 44) == UFG::sLeftLegIKNameUID )
          v6 = v8;
        if ( !v9 && *(_DWORD *)(v8 + 44) == UFG::sRightLegIKNameUID )
          v9 = v8;
        v8 = *(_QWORD *)(v8 + 24) - 16i64;
      }
      while ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != v7 );
      if ( v6 && v9 )
      {
        v10 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, _QWORD))(*(_QWORD *)v6 + 112i64))(
                v6,
                UFG::sLeftLegIKNameUID,
                UFG::sRightLegIKNameUID);
        if ( (unsigned __int8)UFG::adJustEffectorToGround(v4, v10, &inputOutupMatrix, v3, legUp) )
        {
          v12 = *(_QWORD *)v6;
          LOBYTE(v11) = 1;
          inputOutupMatrix.v3.w = 1.0;
          inputOutupMatrix.v3.x = inputOutupMatrix.v3.x + (float)(UFG::qVector3::msDirUp.x * sDownLeg);
          inputOutupMatrix.v3.y = inputOutupMatrix.v3.y + (float)(UFG::qVector3::msDirUp.y * sDownLeg);
          inputOutupMatrix.v3.z = inputOutupMatrix.v3.z + (float)(UFG::qVector3::msDirUp.z * sDownLeg);
          (*(void (__fastcall **)(signed __int64, __int64))(v12 + 88))(v6, v11);
          (*(void (__fastcall **)(signed __int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v6 + 120i64))(
            v6,
            &v4->mPose,
            &inputOutupMatrix);
        }
        v13 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v9 + 112i64))(v9);
        if ( (unsigned __int8)UFG::adJustEffectorToGround(v4, v13, &v17, v3, legUp) )
        {
          v15 = *(_QWORD *)v9;
          LOBYTE(v14) = 1;
          v17.v3.w = 1.0;
          v17.v3.x = v17.v3.x + (float)(UFG::qVector3::msDirUp.x * sDownLeg);
          v17.v3.y = v17.v3.y + (float)(UFG::qVector3::msDirUp.y * sDownLeg);
          v17.v3.z = v17.v3.z + (float)(UFG::qVector3::msDirUp.z * sDownLeg);
          (*(void (__fastcall **)(signed __int64, __int64))(v15 + 88))(v9, v14);
          (*(void (__fastcall **)(signed __int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v9 + 120i64))(
            v9,
            &v4->mPose,
            &v17);
        }
        Creature::updateEffectorsToPose(v4);
        (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v6 + 88i64))(v6, 0i64);
        (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v9 + 88i64))(v9, 0i64);
      }
    }
  }
}

// File Line: 1013
// RVA: 0x5619B0
void __fastcall UFG::WorldContextComponent::UpdateTransformsPost(UFG::WorldContextComponent *this)
{
  UFG::WorldContextComponent *v1; // rsi
  UFG::SimComponent *v2; // r14
  UFG::SimObjectProp *v3; // rcx
  unsigned __int16 v4; // dx
  __int64 v5; // rdx
  UFG::CharacterAnimationComponent *v6; // rcx
  UFG::CharacterAnimationComponent *v7; // rax
  bool v8; // zf
  unsigned int v9; // er9
  unsigned int v10; // er11
  signed __int64 v11; // r8
  Creature *v12; // r15
  float v13; // xmm10_4
  float v14; // xmm11_4
  __m128 v15; // xmm7
  UFG::CoverPosition *v16; // rcx
  UFG::CoverCornerHandle *v17; // rcx
  UFG::CoverCorner *v18; // rax
  float v19; // xmm8_4
  float v20; // xmm9_4
  __m128 v21; // xmm5
  float v22; // xmm6_4
  float v23; // xmm0_4
  __m128 v24; // xmm2
  float v25; // xmm14_4
  float v26; // xmm9_4
  float v27; // xmm8_4
  float v28; // xmm9_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  UFG::qVector4 v34; // xmm1
  UFG::ParkourHandle *v35; // rbx
  UFG::CoverPosition *v36; // rbx
  UFG::qVector3 *v37; // rax
  float v38; // xmm15_4
  float v39; // xmm6_4
  float v40; // xmm9_4
  UFG::qVector3 *v41; // rax
  float v42; // xmm3_4
  __m128 v43; // xmm4
  float v44; // xmm5_4
  __m128 v45; // xmm2
  float v46; // xmm10_4
  float v47; // xmm11_4
  float v48; // xmm0_4
  float v49; // xmm6_4
  float v50; // xmm9_4
  float v51; // xmm15_4
  float v52; // xmm0_4
  float v53; // xmm13_4
  UFG::CoverPosition *v54; // rcx
  float v55; // xmm13_4
  __m128 v56; // xmm6
  float v57; // xmm9_4
  float v58; // xmm0_4
  __m128 v59; // xmm2
  float v60; // xmm8_4
  float v61; // xmm0_4
  UFG::CoverPosition *v62; // rax
  float v63; // xmm13_4
  float v64; // xmm6_4
  float v65; // xmm9_4
  int v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm6_4
  float v70; // xmm9_4
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm9_4
  float v75; // xmm9_4
  float v76; // xmm6_4
  __m128 v77; // xmm9
  float v78; // xmm13_4
  float v79; // xmm0_4
  __m128 v80; // xmm2
  float v81; // xmm8_4
  float v82; // xmm0_4
  float v83; // xmm6_4
  bool v84; // al
  float v85; // xmm2_4
  int v86; // er8
  bool v87; // al
  int v88; // er8
  bool v89; // ST58_1
  bool v90; // al
  bool v91; // ST50_1
  bool v92; // al
  bool v93; // ST40_1
  bool fSegmentLength; // ST28_1
  Render::DebugDrawContext *v95; // rbx
  Render::DebugDrawManager *v96; // rax
  Render::DebugDrawContext *v97; // rdi
  const char *v98; // rax
  UFG::SimComponent *v99; // rax
  char v100; // di
  UFG::SimObjectProp *v101; // rcx
  unsigned __int16 v102; // r8
  UFG::CharacterAnimationComponent *v103; // rcx
  UFG::CharacterAnimationComponent *v104; // rax
  unsigned int v105; // er9
  unsigned int v106; // er11
  signed __int64 v107; // r8
  Creature *v108; // rbx
  UFG::SimObject *v109; // rcx
  unsigned __int16 v110; // dx
  unsigned int v111; // er8
  unsigned int v112; // er10
  signed __int64 v113; // rdx
  unsigned int v114; // er8
  unsigned int v115; // er10
  unsigned int v116; // er8
  unsigned int v117; // er10
  float v118; // xmm2_4
  UFG::CollisionLayers v119; // edx
  UFG::qNode<Attachment,Attachment> *v120; // rbx
  signed __int64 v121; // rsi
  UFG::qNode<Attachment,Attachment> **i; // rbx
  float fLeftConstraint; // [rsp+30h] [rbp-C0h]
  float fRightConstraint; // [rsp+38h] [rbp-B8h]
  bool syncPositionOnly; // [rsp+40h] [rbp-B0h]
  bool syncForward; // [rsp+48h] [rbp-A8h]
  bool syncClosestEndPoint; // [rsp+50h] [rbp-A0h]
  bool syncPlanar; // [rsp+58h] [rbp-98h]
  UFG::qVector3 p1; // [rsp+60h] [rbp-90h]
  UFG::qVector3 result; // [rsp+70h] [rbp-80h]
  float v131; // [rsp+7Ch] [rbp-74h]
  float v132; // [rsp+80h] [rbp-70h]
  int v133; // [rsp+88h] [rbp-68h]
  int v134; // [rsp+8Ch] [rbp-64h]
  int v135; // [rsp+90h] [rbp-60h]
  UFG::qMatrix44 outMatrix; // [rsp+A0h] [rbp-50h]
  float vars0; // [rsp+1C0h] [rbp+D0h]
  float retaddr; // [rsp+1C8h] [rbp+D8h]
  float v139; // [rsp+1D0h] [rbp+E0h]
  float v140; // [rsp+1D8h] [rbp+E8h]

  v1 = this;
  if ( (LOBYTE(this->m_Flags) >> 1) & 1 )
    return;
  v2 = 0i64;
  if ( !this->mSyncLatchedHandle && !*(_WORD *)&this->mbSyncingCoverParkour && !this->mbSyncingCoverRCorner )
    goto LABEL_79;
  v3 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v3 )
    goto LABEL_79;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    v6 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    if ( !v6
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v6->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_10;
    }
    goto LABEL_28;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    v6 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    if ( !v6 || (UFG::CharacterAnimationComponent::_TypeUID ^ v6->m_TypeUID) & 0xFE000000 )
      goto LABEL_10;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
      v6 = 0i64;
    goto LABEL_28;
  }
  if ( (v4 >> 13) & 1 )
  {
    v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v3);
LABEL_27:
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    v6 = v7;
    goto LABEL_28;
  }
  v8 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v8 )
  {
    v7 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_27;
  }
  v9 = v3->mComponentTableEntryCount;
  v10 = v3->m_Components.size;
  if ( v9 >= v10 )
  {
LABEL_10:
    v6 = 0i64;
    goto LABEL_28;
  }
  v11 = (signed __int64)&v3->m_Components.p[v9];
  while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
  {
    ++v9;
    v11 += 16i64;
    if ( v9 >= v10 )
    {
      v6 = 0i64;
      goto LABEL_28;
    }
  }
  v6 = *(UFG::CharacterAnimationComponent **)v11;
LABEL_28:
  if ( !v6 )
    goto LABEL_80;
  v12 = v6->mCreature;
  if ( !v12 )
    return;
  v13 = UFG::qVector3::msDirRight.x;
  v14 = UFG::qVector3::msDirRight.y;
  v15.m128_i32[0] = LODWORD(UFG::qVector3::msDirRight.z);
  if ( v1->mSyncLatchedHandle )
  {
    v35 = v1->mParkourHandle.m_pPointer;
  }
  else
  {
    if ( !v1->mbSyncingCoverParkour )
    {
      v16 = v1->mpCoverPosition;
      if ( v16 )
      {
        if ( v1->mbSyncingCoverLCorner )
          v17 = &v16->m_LeftCorner;
        else
          v17 = &v16->m_RightCorner;
        v18 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v17);
        if ( !v18 || v1->mSyncBoneIndex < 0 )
          goto LABEL_79;
        UFG::CoverCorner::GetSyncMatrix(v18, &outMatrix);
        v1->mpCoverPosition->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v1->mpCoverPosition->vfptr, &p1);
        v21 = (__m128)LODWORD(p1.z);
        v19 = 0.0;
        v20 = (float)(p1.y * UFG::qVector3::msDirUp.z) - (float)(p1.z * UFG::qVector3::msDirUp.y);
        v21.m128_f32[0] = (float)(p1.z * UFG::qVector3::msDirUp.x) - (float)(p1.x * UFG::qVector3::msDirUp.z);
        v22 = (float)(p1.x * UFG::qVector3::msDirUp.y) - (float)(p1.y * UFG::qVector3::msDirUp.x);
        v23 = v20 * v20;
        v24 = v21;
        v24.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
        if ( v24.m128_f32[0] != 0.0 )
        {
          LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v24);
          v19 = 1.0 / v23;
        }
        v25 = v19 * v20;
        v26 = v19;
        v27 = v19 * v22;
        v28 = v26 * v21.m128_f32[0];
        v29 = UFG::CoverObjectBase::GetSideOffset((UFG::CoverObjectBase *)&v1->mpCoverPosition->vfptr, v23);
        v30 = v29;
        v31 = UFG::CoverObjectBase::GetFrontOffset((UFG::CoverObjectBase *)&v1->mpCoverPosition->vfptr, v29);
        v32 = outMatrix.v3.x + (float)(v31 * p1.x);
        v33 = outMatrix.v3.y + (float)(v31 * p1.y);
        if ( v1->mbSyncingCoverLCorner )
          LODWORD(v30) ^= _xmm[0];
        outMatrix.v3.w = (float)(outMatrix.v3.w + 1.0) + 1.0;
        outMatrix.v3.z = (float)(outMatrix.v3.z + (float)(v31 * p1.z)) + (float)(v30 * v27);
        v34 = outMatrix.v2;
        v1->mWorldAnchor.v0 = outMatrix.v0;
        outMatrix.v3.x = v32 + (float)(v30 * v25);
        outMatrix.v3.y = v33 + (float)(v30 * v28);
        v1->mWorldAnchor.v1 = outMatrix.v1;
        v1->mWorldAnchor.v2 = v34;
        v1->mWorldAnchor.v3 = outMatrix.v3;
LABEL_78:
        Creature::Attach(v12, v1->mSyncBoneIndex, 2, &v1->mWorldAnchor, v1->mBlendWeight);
        LODWORD(result.x) = LODWORD(v13) ^ _xmm[0];
        LODWORD(result.y) = LODWORD(v14) ^ _xmm[0];
        LODWORD(result.z) = v15.m128_i32[0] ^ _xmm[0];
        UFG::syncHands(v12, (UFG::qVector3 *)((char *)&result + 8), &result);
LABEL_79:
        v5 = UFG::CharacterAnimationComponent::_TypeUID;
        goto LABEL_80;
      }
      goto LABEL_80;
    }
    v36 = v1->mpCoverPosition;
    if ( !v36 )
      goto LABEL_80;
    v35 = v36->m_pParkourHandle.m_pPointer;
  }
  if ( v35 && v1->mSyncBoneIndex >= 0 )
  {
    v37 = UFG::ParkourHandle::GetPosition(v35, &result);
    v38 = v37->x;
    v39 = v37->y;
    v40 = v37->z;
    v41 = UFG::ParkourHandle::GetAxis(v35, &result);
    v42 = v41->y;
    v43 = (__m128)LODWORD(v41->x);
    v44 = v41->z;
    v45 = v43;
    v45.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v43.m128_f32[0]) + (float)(v42 * v42)) + (float)(v44 * v44);
    if ( v45.m128_f32[0] == 0.0 )
    {
      v15 = 0i64;
    }
    else
    {
      v15 = (__m128)(unsigned int)FLOAT_1_0;
      v15.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v45));
    }
    v46 = v15.m128_f32[0];
    v47 = v15.m128_f32[0];
    v15.m128_f32[0] = v15.m128_f32[0] * v44;
    v13 = v46 * v43.m128_f32[0];
    v14 = v47 * v42;
    v48 = UFG::ParkourHandle::GetHalfLength(v35);
    v49 = v39 + (float)(v14 * v48);
    v50 = v40 + (float)(v15.m128_f32[0] * v48);
    v51 = v38 + (float)(v13 * v48);
    v139 = v49;
    v140 = v50;
    v52 = UFG::ParkourHandle::GetHalfLength(v35);
    retaddr = 0.0;
    vars0 = 0.0;
    v53 = v52 * 2.0;
    result.x = v52 * 2.0;
    if ( v1->mbSyncingCoverParkour )
    {
      v54 = v1->mpCoverPosition;
      if ( v54 && !v1->mSyncPositionLocked )
      {
        if ( v1->mLockSyncPosition == 1 )
          v1->mSyncPositionLocked = 1;
        if ( v54->m_bInbetweenParkourLine )
        {
          v56 = (__m128)LODWORD(v54->m_vInbetweenParkourAxis.z);
          v55 = (float)(v54->m_vInbetweenParkourAxis.y * UFG::qVector3::msDirUp.z)
              - (float)(v56.m128_f32[0] * UFG::qVector3::msDirUp.y);
          v56.m128_f32[0] = (float)(v56.m128_f32[0] * UFG::qVector3::msDirUp.x)
                          - (float)(v54->m_vInbetweenParkourAxis.x * UFG::qVector3::msDirUp.z);
          v57 = (float)(v54->m_vInbetweenParkourAxis.x * UFG::qVector3::msDirUp.y)
              - (float)(v54->m_vInbetweenParkourAxis.y * UFG::qVector3::msDirUp.x);
          v58 = v55 * v55;
          v59 = v56;
          v59.m128_f32[0] = (float)((float)(v56.m128_f32[0] * v56.m128_f32[0]) + (float)(v55 * v55))
                          + (float)(v57 * v57);
          if ( v59.m128_f32[0] == 0.0 )
          {
            v60 = 0.0;
          }
          else
          {
            LODWORD(v58) = (unsigned __int128)_mm_sqrt_ps(v59);
            v60 = 1.0 / v58;
          }
          v61 = UFG::CoverObjectBase::GetFrontOffset((UFG::CoverObjectBase *)&v54->vfptr, v58);
          v62 = v1->mpCoverPosition;
          v63 = (float)((float)(v55 * v60) * v61) + v62->m_vInbetweenParkourPosition.x;
          v64 = (float)((float)(v56.m128_f32[0] * v60) * v61) + v62->m_vInbetweenParkourPosition.y;
          v65 = (float)((float)(v57 * v60) * v61) + v62->m_vInbetweenParkourPosition.z;
          v66 = LODWORD(v62->m_vInbetweenParkourAxis.y) ^ _xmm[0];
          LODWORD(p1.x) = LODWORD(v62->m_vInbetweenParkourAxis.x) ^ _xmm[0];
          v67 = v62->m_vInbetweenParkourAxis.z;
          result.x = v63;
          syncPlanar = v1->mSyncPlanar;
          syncClosestEndPoint = v1->mSyncToClosestEndpoint;
          LOBYTE(v62) = v1->mSyncXForward;
          LODWORD(p1.z) = LODWORD(v67) ^ _xmm[0];
          result.y = v64;
          syncForward = (char)v62;
          LOBYTE(v62) = v1->mSyncPositionOnly;
          result.z = v65;
          LODWORD(p1.y) = v66;
          syncPositionOnly = (char)v62;
          fRightConstraint = FLOAT_N3_4028235e38;
          fLeftConstraint = FLOAT_N3_4028235e38;
          v68 = FLOAT_2_0;
        }
        else
        {
          if ( v54->m_pParkourHandle.m_pPointer )
          {
            v69 = v54->m_fDistToLeft;
            v70 = v54->m_fDistToRight;
            v71 = UFG::ParkourHandle::GetHalfLength(v54->m_pParkourHandle.m_pPointer);
            v54 = v1->mpCoverPosition;
            v72 = v71 + v54->m_fParkourTVal;
            v73 = (float)((float)(v71 * 2.0) - v72) - v70;
            v74 = v70 + v69;
            retaddr = v72 - v69;
            vars0 = v73;
            if ( v74 < 0.0 )
            {
              v75 = v74 * 0.5;
              retaddr = (float)(v72 - v69) + v75;
              vars0 = v73 + v75;
            }
          }
          v77 = v15;
          v76 = (float)(v14 * UFG::qVector3::msDirUp.z) - (float)(v15.m128_f32[0] * UFG::qVector3::msDirUp.y);
          v77.m128_f32[0] = (float)(v15.m128_f32[0] * UFG::qVector3::msDirUp.x)
                          - (float)(v13 * UFG::qVector3::msDirUp.z);
          v80 = v77;
          v78 = (float)(v13 * UFG::qVector3::msDirUp.y) - (float)(v14 * UFG::qVector3::msDirUp.x);
          v79 = v76 * v76;
          v80.m128_f32[0] = (float)((float)(v77.m128_f32[0] * v77.m128_f32[0]) + (float)(v76 * v76))
                          + (float)(v78 * v78);
          if ( v80.m128_f32[0] == 0.0 )
          {
            v81 = 0.0;
          }
          else
          {
            LODWORD(v79) = (unsigned __int128)_mm_sqrt_ps(v80);
            v81 = 1.0 / v79;
          }
          v82 = UFG::CoverObjectBase::GetFrontOffset((UFG::CoverObjectBase *)&v54->vfptr, v79);
          syncPlanar = v1->mSyncPlanar;
          v83 = (float)(v76 * v81) * v82;
          syncClosestEndPoint = v1->mSyncToClosestEndpoint;
          syncForward = v1->mSyncXForward;
          v84 = v1->mSyncPositionOnly;
          result.z = v140 + (float)(v82 * (float)(v78 * v81));
          LODWORD(p1.x) = LODWORD(v13) ^ _xmm[0];
          v85 = v139 + (float)(v82 * (float)(v77.m128_f32[0] * v81));
          syncPositionOnly = v84;
          LODWORD(p1.z) = v15.m128_i32[0] ^ _xmm[0];
          LODWORD(p1.y) = LODWORD(v14) ^ _xmm[0];
          fRightConstraint = vars0;
          v68 = result.x;
          fLeftConstraint = retaddr;
          result.x = v51 + v83;
          result.y = v85;
        }
        v86 = v1->mSyncBoneIndex;
        v131 = 1.0;
        UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(
          &v1->mWorldAnchor,
          v12,
          v86,
          (UFG::qVector4 *)&result,
          &p1,
          v68,
          fLeftConstraint,
          fRightConstraint,
          syncPositionOnly,
          syncForward,
          syncClosestEndPoint,
          syncPlanar);
      }
    }
    else
    {
      if ( !v1->mSyncPositionLocked )
      {
        if ( v1->mLockSyncPosition == 1 )
          v1->mSyncPositionLocked = 1;
        getParkourEdgeConstraints(
          v35,
          v1->mSyncLeftEdge,
          v1->mSyncRightEdge,
          v1->mDistanceFromEdge,
          v1->mDistanceFromEdge,
          &retaddr,
          &vars0);
        v87 = v1->mSyncPlanar;
        result.x = v51;
        v88 = v1->mSyncBoneIndex;
        v89 = v87;
        v90 = v1->mSyncToClosestEndpoint;
        result.y = v49;
        result.z = v50;
        LODWORD(p1.x) = LODWORD(v13) ^ _xmm[0];
        LODWORD(p1.y) = LODWORD(v14) ^ _xmm[0];
        v91 = v90;
        v92 = v1->mSyncXForward;
        LODWORD(p1.z) = v15.m128_i32[0] ^ _xmm[0];
        v93 = v1->mSyncPositionOnly;
        v131 = 1.0;
        UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(
          &v1->mWorldAnchor,
          v12,
          v88,
          (UFG::qVector4 *)&result,
          &p1,
          v53,
          retaddr,
          vars0,
          v93,
          v92,
          v91,
          v89);
      }
      if ( UFG::WorldContextComponent::s_DrawParkourSensing )
      {
        Creature::GetTransform(v12, v1->mSyncBoneIndex, &outMatrix);
        fSegmentLength = v1->mSyncToClosestEndpoint;
        v133 = LODWORD(v13) ^ _xmm[0];
        p1 = *(UFG::qVector3 *)&outMatrix.v3.x;
        v135 = v15.m128_i32[0] ^ _xmm[0];
        v134 = LODWORD(v14) ^ _xmm[0];
        v131 = v49;
        v132 = v50;
        result = *(UFG::qVector3 *)&outMatrix.v3.x;
        constrainPos(&p1, &result, (UFG::qVector3 *)((char *)&result + 8), (UFG::qVector3 *)&v133, v53, fSegmentLength);
        v95 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
        v96 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        result = *(UFG::qVector3 *)&outMatrix.v3.x;
        v97 = (Render::DebugDrawContext *)v96;
        Render::DebugDrawContext::DrawLine(
          v95,
          &result,
          &p1,
          &UFG::qColour::Orange,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        result.x = p1.x;
        result.y = p1.y;
        result.z = sToTextOffsetZ + p1.z;
        Render::DebugDrawContext::DrawLine(
          v95,
          &p1,
          &result,
          &UFG::qColour::Orange,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        v98 = "N";
        result.x = p1.x;
        result.y = p1.y;
        result.z = sToTextOffsetZ + p1.z;
        if ( v1->mSyncPlanar )
          v98 = "P";
        Render::DebugDrawContext::DrawText(v97, &result, &UFG::qColour::Orange, "Syncing:%s", v98);
      }
    }
    goto LABEL_78;
  }
LABEL_80:
  v99 = v1->mCharacterPhysicsComponent.m_pSimComponent;
  v100 = 0;
  if ( v99 && v99[9].m_TypeUID )
  {
    v100 = 1;
  }
  else if ( !v1->mSyncFeet )
  {
    goto LABEL_141;
  }
  v101 = (UFG::SimObjectProp *)v1->m_pSimObject;
  if ( !v101 )
    goto LABEL_141;
  v102 = v101->m_Flags;
  if ( (v102 >> 14) & 1 )
  {
    v103 = (UFG::CharacterAnimationComponent *)v101->m_Components.p[9].m_pComponent;
    if ( !v103 || ((unsigned int)v5 ^ v103->m_TypeUID) & 0xFE000000 || (unsigned int)v5 & ~v103->m_TypeUID & 0x1FFFFFF )
      goto LABEL_89;
    goto LABEL_107;
  }
  if ( (v102 & 0x8000u) != 0 )
  {
    v103 = (UFG::CharacterAnimationComponent *)v101->m_Components.p[9].m_pComponent;
    if ( !v103 || ((unsigned int)v5 ^ v103->m_TypeUID) & 0xFE000000 )
      goto LABEL_89;
    if ( (unsigned int)v5 & ~v103->m_TypeUID & 0x1FFFFFF )
      v103 = 0i64;
    goto LABEL_107;
  }
  if ( (v102 >> 13) & 1 )
  {
    v104 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v101);
LABEL_106:
    v103 = v104;
    goto LABEL_107;
  }
  if ( !((v102 >> 12) & 1) )
  {
    v104 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v101->vfptr, v5);
    goto LABEL_106;
  }
  v105 = v101->mComponentTableEntryCount;
  v106 = v101->m_Components.size;
  if ( v105 >= v106 )
  {
LABEL_89:
    v103 = 0i64;
    goto LABEL_107;
  }
  v107 = (signed __int64)&v101->m_Components.p[v105];
  while ( (*(_DWORD *)(v107 + 8) & 0xFE000000) != (v5 & 0xFE000000)
       || (unsigned int)v5 & ~*(_DWORD *)(v107 + 8) & 0x1FFFFFF )
  {
    ++v105;
    v107 += 16i64;
    if ( v105 >= v106 )
    {
      v103 = 0i64;
      goto LABEL_107;
    }
  }
  v103 = *(UFG::CharacterAnimationComponent **)v107;
LABEL_107:
  if ( v103 )
  {
    v108 = v103->mCreature;
    if ( v108 )
    {
      v109 = v1->m_pSimObject;
      if ( !v109 )
        goto LABEL_137;
      v110 = v109->m_Flags;
      if ( (v110 >> 14) & 1 )
      {
        v2 = v109->m_Components.p[44].m_pComponent;
        goto LABEL_135;
      }
      if ( (v110 & 0x8000u) != 0 )
      {
        v111 = (unsigned int)v109[1].vfptr;
        v112 = v109->m_Components.size;
        if ( v111 >= v112 )
          goto LABEL_135;
        v113 = (signed __int64)&v109->m_Components.p[v111];
        while ( (*(_DWORD *)(v113 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v113 + 8) & 0x1FFFFFF )
        {
          ++v111;
          v113 += 16i64;
          if ( v111 >= v112 )
            goto LABEL_135;
        }
        goto LABEL_119;
      }
      if ( (v110 >> 13) & 1 )
      {
        v114 = (unsigned int)v109[1].vfptr;
        v115 = v109->m_Components.size;
        if ( v114 < v115 )
        {
          v113 = (signed __int64)&v109->m_Components.p[v114];
          while ( (*(_DWORD *)(v113 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v113 + 8) & 0x1FFFFFF )
          {
            ++v114;
            v113 += 16i64;
            if ( v114 >= v115 )
              goto LABEL_135;
          }
LABEL_119:
          v2 = *(UFG::SimComponent **)v113;
          goto LABEL_135;
        }
      }
      else if ( (v110 >> 12) & 1 )
      {
        v116 = (unsigned int)v109[1].vfptr;
        v117 = v109->m_Components.size;
        if ( v116 < v117 )
        {
          v113 = (signed __int64)&v109->m_Components.p[v116];
          while ( (*(_DWORD *)(v113 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v113 + 8) & 0x1FFFFFF )
          {
            ++v116;
            v113 += 16i64;
            if ( v116 >= v117 )
              goto LABEL_135;
          }
          goto LABEL_119;
        }
      }
      else
      {
        v2 = UFG::SimObject::GetComponentOfType(v109, UFG::CharacterOccupantComponent::_TypeUID);
      }
LABEL_135:
      if ( v2 )
      {
        v118 = sUpLegVehicle;
        v119 = 14;
LABEL_140:
        UFG::syncFeet(v108, v119, v118);
        goto LABEL_141;
      }
LABEL_137:
      v119 = 12;
      if ( v100 )
        v118 = sUpLegGrapple;
      else
        v118 = sUpLeg;
      goto LABEL_140;
    }
  }
LABEL_141:
  v120 = v1->mAttachments.mNode.mNext;
  v121 = (signed __int64)&v1->mbSyncingCoverParkour;
  for ( i = &v120[-1].mNext; i != (UFG::qNode<Attachment,Attachment> **)v121; i = &i[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **, __int64))(*i)[1].mPrev)(i, v5);
}

// File Line: 1324
// RVA: 0x523640
void __fastcall UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(UFG::qMatrix44 *newWorldAnchor, Creature *pCreature, int syncBoneIndex, UFG::qVector4 *vHandleOrigin, UFG::qVector3 *vHandleAxis, float fSegmentLength, float fLeftConstraint, float fRightConstraint, bool syncPositionOnly, bool syncForward, bool syncClosestEndPoint, bool syncPlanar)
{
  UFG::qMatrix44 *v12; // rdi
  Creature *v13; // rbx
  UFG::qVector4 *v14; // r14
  UFG::qVector3 *v15; // rbx
  __m128 v16; // xmm6
  float v17; // xmm15_4
  float v18; // xmm3_4
  __m128 v19; // xmm2
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm15_4
  float v23; // xmm7_4
  UFG::qVector4 v24; // xmm9
  UFG::qVector4 v25; // xmm14
  float v26; // xmm10_4
  float v27; // xmm12_4
  float v28; // xmm13_4
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm4
  __m128 v32; // xmm11
  __m128 v33; // xmm4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm8_4
  float v37; // xmm9_4
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  float v40; // xmm10_4
  float v41; // xmm3_4
  UFG::qVector4 vSyncPosition; // [rsp+50h] [rbp-A8h]
  __m128 v43; // [rsp+60h] [rbp-98h]
  __m128 v44; // [rsp+70h] [rbp-88h]
  float v45; // [rsp+80h] [rbp-78h]
  int v46; // [rsp+84h] [rbp-74h]
  UFG::qVector4 v47; // [rsp+88h] [rbp-70h]
  UFG::qVector4 result; // [rsp+98h] [rbp-60h]
  UFG::qMatrix44 transform; // [rsp+A8h] [rbp-50h]
  UFG::qVector4 v50; // [rsp+E8h] [rbp-10h]
  UFG::qMatrix44 d; // [rsp+F8h] [rbp+0h]
  UFG::qMatrix44 v52; // [rsp+138h] [rbp+40h]
  float retaddr; // [rsp+228h] [rbp+130h]
  UFG::qVector3 *v54; // [rsp+248h] [rbp+150h]
  float v55; // [rsp+248h] [rbp+150h]

  v12 = newWorldAnchor;
  v13 = pCreature;
  v14 = vHandleOrigin;
  Creature::GetTransform(pCreature, syncBoneIndex, &transform);
  Creature::GetTransform(v13, 2, &v52);
  v15 = v54;
  v16 = (__m128)LODWORD(v54->y);
  v16.m128_f32[0] = (float)(v16.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v54->z * UFG::qVector3::msDirUp.y);
  v19 = v16;
  v17 = (float)(v54->x * UFG::qVector3::msDirUp.y) - (float)(v54->y * UFG::qVector3::msDirUp.x);
  v18 = (float)(v54->z * UFG::qVector3::msDirUp.x) - (float)(v54->x * UFG::qVector3::msDirUp.z);
  v19.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v18 * v18)) + (float)(v17 * v17);
  if ( v19.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
  v21 = v16.m128_f32[0] * v20;
  v22 = v17 * v20;
  v44.m128_u64[1] = LODWORD(UFG::qVector3::msDirUp.x);
  v45 = UFG::qVector3::msDirUp.z;
  v46 = 0;
  v23 = v20 * v18;
  v43.m128_f32[0] = v21;
  v43.m128_u64[1] = LODWORD(v22);
  v55 = v21;
  v24 = *(UFG::qVector4 *)((char *)&v44 + 8);
  v43.m128_f32[1] = v20 * v18;
  retaddr = v20 * v18;
  v44.m128_f32[0] = (float)(v22 * UFG::qVector3::msDirUp.y) - (float)((float)(v20 * v18) * UFG::qVector3::msDirUp.z);
  v44.m128_f32[1] = (float)(v21 * UFG::qVector3::msDirUp.z) - (float)(v22 * UFG::qVector3::msDirUp.x);
  v47 = (UFG::qVector4)_xmm;
  v44.m128_f32[2] = (float)((float)(v20 * v18) * UFG::qVector3::msDirUp.x) - (float)(v21 * UFG::qVector3::msDirUp.y);
  v25 = (UFG::qVector4)v44;
  v50 = (UFG::qVector4)v43;
  if ( LOBYTE(fRightConstraint) )
  {
    v26 = transform.v3.x;
    v27 = transform.v3.y;
    v28 = transform.v3.z;
    vSyncPosition = transform.v3;
  }
  else
  {
    UFG::qInverseAffine(&d, &transform);
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v52.v0, (__m128)v52.v0, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v0, (__m128)v52.v0, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v0, (__m128)v52.v0, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v0, (__m128)v52.v0, 255), (__m128)d.v3));
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v52.v1, (__m128)v52.v1, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v1, (__m128)v52.v1, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v1, (__m128)v52.v1, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v1, (__m128)v52.v1, 255), (__m128)d.v3));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v52.v2, (__m128)v52.v2, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v2, (__m128)v52.v2, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v2, (__m128)v52.v2, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v2, (__m128)v52.v2, 255), (__m128)d.v3));
    v24 = *(UFG::qVector4 *)((char *)&v44 + 8);
    v32 = _mm_add_ps(
            _mm_mul_ps((__m128)d.v3, _mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 170), (__m128)d.v2)));
    v27 = transform.v3.y;
    d.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v43), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v44)),
                              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), *(__m128 *)((char *)&v44 + 8))),
                            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 255), (__m128)_xmm));
    d.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v43), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v44)),
                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *(__m128 *)((char *)&v44 + 8))),
                            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), (__m128)_xmm));
    v28 = transform.v3.z;
    v26 = transform.v3.x;
    d.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v43), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v44)),
                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), *(__m128 *)((char *)&v44 + 8))),
                            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), (__m128)_xmm));
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v43), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v44)),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), *(__m128 *)((char *)&v44 + 8))),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), (__m128)_xmm));
    vSyncPosition.x = v52.v3.x - v33.m128_f32[0];
    vSyncPosition.y = COERCE_FLOAT(_mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 85))
                    - COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85));
    vSyncPosition.w = v52.v3.w - COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 255));
    vSyncPosition.z = COERCE_FLOAT(_mm_shuffle_ps((__m128)v52.v3, (__m128)v52.v3, 170))
                    - COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170));
    v21 = v55;
    v23 = retaddr;
    v25 = (UFG::qVector4)v44;
  }
  UFG::WorldContextComponent::GetClosestAnchorOnLine(
    &result,
    &vSyncPosition,
    v14,
    v15,
    *(float *)&vHandleAxis,
    fSegmentLength,
    fLeftConstraint,
    syncForward,
    syncClosestEndPoint);
  v34 = result.x;
  v35 = result.y;
  v36 = result.z;
  v47 = result;
  if ( LOBYTE(fRightConstraint) )
  {
    if ( syncPositionOnly )
    {
      v38 = (__m128)LODWORD(result.y);
      v37 = result.x - v26;
      v38.m128_f32[0] = result.y - v27;
      v39 = v38;
      v40 = result.z - v28;
      v39.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37)) + (float)(v40 * v40);
      if ( COERCE_FLOAT(_mm_sqrt_ps(v39)) >= 0.000099999997 )
      {
        v41 = (float)((float)(v38.m128_f32[0] * v23) + (float)(v37 * v21)) + (float)(v40 * v22);
        if ( v41 < 0.0 )
        {
          v34 = result.x - (float)(v21 * v41);
          v35 = result.y - (float)(v23 * v41);
          v36 = result.z - (float)(v22 * v41);
        }
      }
    }
    v25 = transform.v1;
    v24 = transform.v2;
    v50 = transform.v0;
    *(_QWORD *)&v47.x = __PAIR__(LODWORD(v35), LODWORD(v34));
    *(_QWORD *)&v47.z = __PAIR__(1065353216, LODWORD(v36));
  }
  v12->v0 = v50;
  v12->v1 = v25;
  v12->v2 = v24;
  v12->v3 = v47;
}

// File Line: 1425
// RVA: 0x52B2E0
UFG::qVector4 *__fastcall UFG::WorldContextComponent::GetClosestAnchorOnLine(UFG::qVector4 *result, UFG::qVector4 *vSyncPosition, UFG::qVector4 *vHandleOrigin, UFG::qVector3 *vHandleAxis, float fSegmentLength, float fLeftConstraint, float fRightConstraint, bool syncToClosestEndpoint, bool syncPlanar)
{
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm6_4
  __m128 v12; // xmm10
  float v13; // xmm7_4
  __m128 v14; // xmm0
  float v15; // xmm11_4
  float v16; // xmm1_4
  __m128 v17; // xmm2
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // eax
  float v21; // xmm11_4
  float v22; // xmm12_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm11_4
  float v26; // xmm2_4

  v9 = vHandleAxis->z;
  v10 = vHandleAxis->x;
  v11 = vHandleOrigin->x;
  v12 = (__m128)LODWORD(vHandleAxis->y);
  v13 = vHandleOrigin->y;
  v17 = v12;
  v14 = (__m128)(unsigned int)FLOAT_1_0;
  v14.m128_f32[0] = 1.0 - (float)(v9 * v9);
  v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
  v16 = 0.0;
  v17.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v10 * v10);
  if ( v17.m128_f32[0] != 0.0 )
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  v18 = (float)((float)((float)(v12.m128_f32[0] * v16) * (float)(vSyncPosition->y - v13))
              + (float)((float)(v10 * v16) * (float)(vSyncPosition->x - vHandleOrigin->x)))
      * v15;
  if ( syncToClosestEndpoint )
  {
    if ( (float)(v18 / fSegmentLength) < 0.5 )
    {
      v20 = vHandleOrigin->z;
      result->x = v11;
      result->y = v13;
      result->z = v20;
      result->w = vHandleOrigin->w;
    }
    else
    {
      v19 = vHandleOrigin->w + 1.0;
      result->z = (float)(v9 * fSegmentLength) + vHandleOrigin->z;
      result->x = v11 + (float)(v10 * fSegmentLength);
      result->y = v13 + (float)(v12.m128_f32[0] * fSegmentLength);
      result->w = v19;
    }
  }
  else
  {
    v21 = vHandleOrigin->z;
    v22 = vHandleOrigin->w + 1.0;
    result->w = v22;
    result->x = v11 + (float)(v10 * v18);
    result->z = v21 + (float)(v9 * v18);
    result->y = v13 + (float)(v12.m128_f32[0] * v18);
    if ( v18 >= fRightConstraint )
    {
      v26 = fSegmentLength - fLeftConstraint;
      if ( v18 <= (float)(fSegmentLength - fLeftConstraint) )
        goto LABEL_12;
      v25 = v21 + (float)(v26 * v9);
      v23 = v11 + (float)(v26 * v10);
      v24 = v13 + (float)(v26 * v12.m128_f32[0]);
    }
    else
    {
      v23 = v11 + (float)(v10 * fRightConstraint);
      v24 = v13 + (float)(v12.m128_f32[0] * fRightConstraint);
      v25 = v21 + (float)(v9 * fRightConstraint);
    }
    result->w = v22;
    result->z = v25;
    result->y = v24;
    result->x = v23;
  }
LABEL_12:
  result->w = 1.0;
  if ( syncPlanar )
    result->z = vSyncPosition->z;
  return result;
}

// File Line: 1473
// RVA: 0x5528C0
void __fastcall UFG::WorldContextComponent::StopSync(UFG::WorldContextComponent *this)
{
  UFG::SimObjectProp *v1; // rcx
  __int64 v2; // rdx
  UFG::CharacterAnimationComponent *v3; // rcx
  UFG::CharacterAnimationComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  Creature *v7; // rcx

  this->mSyncLatchedHandle = 0;
  *(_WORD *)&this->mbSyncingCoverLCorner = 0;
  this->mbSyncingCoverParkour = 0;
  v1 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v1 )
    return;
  v2 = v1->m_Flags;
  if ( ((unsigned __int16)v2 >> 14) & 1 )
  {
    v3 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
    if ( !v3
      || (v2 = v3->m_TypeUID, ((unsigned int)v2 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000)
      || (v2 = UFG::CharacterAnimationComponent::_TypeUID & ~(_DWORD)v2, v2 & 0x1FFFFFF) )
    {
LABEL_6:
      v3 = 0i64;
      goto LABEL_24;
    }
  }
  else
  {
    if ( (v2 & 0x8000u) != 0i64 )
    {
      v3 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
      if ( v3 )
      {
        v2 = v3->m_TypeUID;
        if ( !(((unsigned int)v2 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) )
        {
          v2 = UFG::CharacterAnimationComponent::_TypeUID & ~(_DWORD)v2;
          if ( v2 & 0x1FFFFFF )
            v3 = 0i64;
          goto LABEL_24;
        }
      }
      goto LABEL_6;
    }
    if ( ((unsigned __int16)v2 >> 13) & 1 )
    {
      v4 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v1);
    }
    else
    {
      if ( ((unsigned __int16)v2 >> 12) & 1 )
      {
        v5 = v1->mComponentTableEntryCount;
        v6 = v1->m_Components.size;
        v2 = v5;
        if ( v5 < v6 )
        {
          v2 = (__int64)&v1->m_Components.p[v5];
          while ( (*(_DWORD *)(v2 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v2 + 8) & 0x1FFFFFF )
          {
            ++v5;
            v2 += 16i64;
            if ( v5 >= v6 )
              goto LABEL_6;
          }
          v3 = *(UFG::CharacterAnimationComponent **)v2;
          goto LABEL_24;
        }
        goto LABEL_6;
      }
      v4 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v1->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
    v3 = v4;
  }
LABEL_24:
  if ( v3 )
  {
    v7 = v3->mCreature;
    if ( v7 )
      Creature::MakeUpright(v7, 0.0, v2);
  }
}

// File Line: 1503
// RVA: 0x5224E0
void __fastcall UFG::WorldContextComponent::AttachTo(UFG::WorldContextComponent *this, UFG::SimObject *simObject, UFG::TransformNodeComponent *transformNodeComponent, int attachmentBoneID, float blendIn, bool positionOnly, bool positionXY, bool useRubberBand)
{
  int v8; // er12
  UFG::TransformNodeComponent *v9; // r15
  UFG::SimObject *v10; // rbp
  UFG::WorldContextComponent *v11; // r14
  bool *v12; // rax
  UFG::SimObjectProp *v13; // rbx
  unsigned __int16 v14; // cx
  UFG::RigidBody *v15; // rdi
  UFG::CharacterAnimationComponent *v16; // rsi
  unsigned int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // eax
  UFG::CharacterAnimationComponent *v20; // rax
  unsigned int v21; // ecx
  unsigned int v22; // er8
  UFG::SimComponentHolder *v23; // r11
  UFG::allocator::free_link *v24; // rax
  __int64 v25; // rax
  __int64 v26; // r8
  UFG::qNode<Attachment,Attachment> **v27; // rcx
  UFG::qNode<Attachment,Attachment> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  __int64 *v33; // rdx
  __int64 v34; // rcx
  _QWORD *v35; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v36; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax
  unsigned __int16 v48; // cx
  unsigned int v49; // er8
  unsigned int v50; // er9
  UFG::SimComponentHolder *v51; // rbx
  signed __int64 v52; // rdx
  unsigned int v53; // er8
  unsigned int v54; // er9
  unsigned int v55; // er8
  unsigned int v56; // er9
  unsigned int v57; // er8
  unsigned int v58; // er9

  if ( attachmentBoneID == -1 )
    return;
  v8 = attachmentBoneID;
  v9 = transformNodeComponent;
  v10 = simObject;
  v11 = this;
  v12 = (bool *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( v12 == &this->mbSyncingCoverParkour )
  {
LABEL_5:
    v13 = (UFG::SimObjectProp *)this->m_pSimObject;
    if ( !v13 )
      return;
    v14 = v13->m_Flags;
    v15 = 0i64;
    if ( (v14 >> 14) & 1 )
    {
      v16 = (UFG::CharacterAnimationComponent *)v13->m_Components.p[9].m_pComponent;
      if ( v16 )
      {
        v17 = v16->m_TypeUID;
        v18 = UFG::CharacterAnimationComponent::_TypeUID;
        v19 = v17 ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_9:
        if ( v19 & 0xFE000000 || v18 & ~v17 & 0x1FFFFFF )
          goto LABEL_11;
LABEL_27:
        if ( !v16 )
          return;
        v24 = UFG::qMalloc(0x110ui64, "WorldContextComponent.Attachment", 0i64);
        if ( v24 )
        {
          AttachmentCreatureToTransformNode::AttachmentCreatureToTransformNode((AttachmentCreatureToTransformNode *)v24);
          v26 = v25;
        }
        else
        {
          v26 = 0i64;
        }
        v27 = (UFG::qNode<Attachment,Attachment> **)(v26 + 8);
        v28 = v11->mAttachments.mNode.mPrev;
        v28->mNext = (UFG::qNode<Attachment,Attachment> *)(v26 + 8);
        *v27 = v28;
        v27[1] = &v11->mAttachments.mNode;
        v11->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v26 + 8);
        *(_DWORD *)(v26 + 32) = 0;
        v29 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v26 + 40);
        if ( *(_QWORD *)(v26 + 56) )
        {
          v30 = v29->mPrev;
          v31 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v26 + 48);
          v30->mNext = v31;
          v31->mPrev = v30;
          v29->mPrev = v29;
          *(_QWORD *)(v26 + 48) = v26 + 40;
        }
        *(_QWORD *)(v26 + 56) = v10;
        if ( v10 )
        {
          v32 = v10->m_SafePointerList.mNode.mPrev;
          v32->mNext = v29;
          v29->mPrev = v32;
          *(_QWORD *)(v26 + 48) = (char *)v10 + 8;
          v10->m_SafePointerList.mNode.mPrev = v29;
        }
        v33 = (__int64 *)(v26 + 64);
        if ( *(_QWORD *)(v26 + 80) )
        {
          v34 = *v33;
          v35 = *(_QWORD **)(v26 + 72);
          *(_QWORD *)(v34 + 8) = v35;
          *v35 = v34;
          *v33 = (__int64)v33;
          *(_QWORD *)(v26 + 72) = v26 + 64;
        }
        *(_QWORD *)(v26 + 80) = 0i64;
        v36 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v26 + 88);
        if ( *(_QWORD *)(v26 + 104) )
        {
          v37 = v36->mPrev;
          v38 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v26 + 96);
          v37->mNext = v38;
          v38->mPrev = v37;
          v36->mPrev = v36;
          *(_QWORD *)(v26 + 96) = v26 + 88;
        }
        *(_QWORD *)(v26 + 104) = v13;
        v39 = v13->m_SafePointerList.mNode.mPrev;
        v39->mNext = v36;
        v36->mPrev = v39;
        *(_QWORD *)(v26 + 96) = (char *)v13 + 8;
        v13->m_SafePointerList.mNode.mPrev = v36;
        *(_BYTE *)(v26 + 26) = 0;
        if ( blendIn > 0.0 )
        {
          *(float *)(v26 + 188) = 1.0 / blendIn;
          *(_DWORD *)(v26 + 192) = 0;
        }
        else
        {
          *(_DWORD *)(v26 + 188) = 1065353216;
          *(_DWORD *)(v26 + 192) = 1065353216;
        }
        v40 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v26 + 208);
        if ( *(_QWORD *)(v26 + 224) )
        {
          v41 = v40->mPrev;
          v42 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v26 + 216);
          v41->mNext = v42;
          v42->mPrev = v41;
          v40->mPrev = v40;
          *(_QWORD *)(v26 + 216) = v26 + 208;
        }
        *(_QWORD *)(v26 + 224) = v9;
        if ( v9 )
        {
          v43 = v9->m_SafePointerList.mNode.mPrev;
          v43->mNext = v40;
          v40->mPrev = v43;
          *(_QWORD *)(v26 + 216) = (char *)v9 + 8;
          v9->m_SafePointerList.mNode.mPrev = v40;
        }
        *(_DWORD *)(v26 + 232) = v8;
        v44 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v26 + 240);
        if ( *(_QWORD *)(v26 + 256) )
        {
          v45 = v44->mPrev;
          v46 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v26 + 248);
          v45->mNext = v46;
          v46->mPrev = v45;
          v44->mPrev = v44;
          *(_QWORD *)(v26 + 248) = v26 + 240;
        }
        *(_QWORD *)(v26 + 256) = v16;
        v47 = v16->m_SafePointerList.mNode.mPrev;
        v47->mNext = v44;
        v44->mPrev = v47;
        *(_QWORD *)(v26 + 248) = (char *)v16 + 8;
        v16->m_SafePointerList.mNode.mPrev = v44;
        *(_BYTE *)(v26 + 24) = positionOnly;
        *(_BYTE *)(v26 + 25) = positionXY;
        *(_BYTE *)(v26 + 28) = useRubberBand;
        v48 = v13->m_Flags;
        if ( (v48 >> 14) & 1 )
        {
          v49 = v13->mComponentTableEntryCount;
          v50 = v13->m_Components.size;
          if ( v49 >= v50 )
            goto LABEL_78;
          v51 = v13->m_Components.p;
          while ( 1 )
          {
            v52 = v49;
            if ( (v51[v49].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~v51[v49].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_55;
            }
            if ( ++v49 >= v50 )
              goto LABEL_78;
          }
        }
        if ( (v48 & 0x8000u) == 0 )
        {
          if ( (v48 >> 13) & 1 )
          {
            v55 = v13->mComponentTableEntryCount;
            v56 = v13->m_Components.size;
            if ( v55 < v56 )
            {
              v51 = v13->m_Components.p;
              do
              {
                v52 = v55;
                if ( (v51[v55].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && !(UFG::RigidBodyComponent::_TypeUID & ~v51[v55].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_55;
                }
              }
              while ( ++v55 < v56 );
            }
          }
          else if ( (v48 >> 12) & 1 )
          {
            v57 = v13->mComponentTableEntryCount;
            v58 = v13->m_Components.size;
            if ( v57 < v58 )
            {
              v51 = v13->m_Components.p;
              do
              {
                v52 = v57;
                if ( (v51[v57].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && !(UFG::RigidBodyComponent::_TypeUID & ~v51[v57].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_55;
                }
              }
              while ( ++v57 < v58 );
            }
          }
          else
          {
            v15 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v13->vfptr,
                                      UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v53 = v13->mComponentTableEntryCount;
          v54 = v13->m_Components.size;
          if ( v53 < v54 )
          {
            v51 = v13->m_Components.p;
            while ( 1 )
            {
              v52 = v53;
              if ( (v51[v53].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && !(UFG::RigidBodyComponent::_TypeUID & ~v51[v53].m_TypeUID & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v53 >= v54 )
                goto LABEL_78;
            }
LABEL_55:
            v15 = (UFG::RigidBody *)v51[v52].m_pComponent;
            goto LABEL_78;
          }
        }
LABEL_78:
        if ( v15 )
          UFG::RigidBody::SetMotionType(v15, 0x100u);
        return;
      }
    }
    else
    {
      if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v13);
        }
        else
        {
          if ( (v14 >> 12) & 1 )
          {
            v21 = v13->mComponentTableEntryCount;
            v22 = v13->m_Components.size;
            if ( v21 < v22 )
            {
              v23 = v13->m_Components.p;
              while ( (v23[v21].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || UFG::CharacterAnimationComponent::_TypeUID & ~v23[v21].m_TypeUID & 0x1FFFFFF )
              {
                if ( ++v21 >= v22 )
                  goto LABEL_11;
              }
              v16 = (UFG::CharacterAnimationComponent *)v23[v21].m_pComponent;
              goto LABEL_27;
            }
            goto LABEL_11;
          }
          v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v13->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v16 = v20;
        goto LABEL_27;
      }
      v16 = (UFG::CharacterAnimationComponent *)v13->m_Components.p[9].m_pComponent;
      if ( v16 )
      {
        v17 = v16->m_TypeUID;
        v18 = UFG::CharacterAnimationComponent::_TypeUID;
        v19 = UFG::CharacterAnimationComponent::_TypeUID ^ v16->m_TypeUID;
        goto LABEL_9;
      }
    }
LABEL_11:
    v16 = 0i64;
    goto LABEL_27;
  }
  while ( *((UFG::SimObject **)v12 + 7) != simObject )
  {
    v12 = (bool *)(*((_QWORD *)v12 + 2) - 8i64);
    if ( v12 == &this->mbSyncingCoverParkour )
      goto LABEL_5;
  }
}

// File Line: 1559
// RVA: 0x525A30
void __fastcall UFG::WorldContextComponent::DetachFrom(UFG::WorldContextComponent *this, UFG::SimObject *simObject, UFG::TransformNodeComponent *transformNodeComponent)
{
  UFG::qNode<Attachment,Attachment> *v3; // rbx
  Attachment *v4; // rcx
  Attachment *v5; // rbx
  UFG::qNode<Attachment,Attachment> *v6; // rcx
  UFG::qNode<Attachment,Attachment> *v7; // rax
  UFG::qNode<Attachment,Attachment> *v8; // rdx

  v3 = this->mAttachments.mNode.mNext;
  v4 = (Attachment *)&this->mbSyncingCoverParkour;
  v5 = (Attachment *)&v3[-1].mNext;
  if ( v5 != v4 )
  {
    while ( v5->mRootSimObject.m_pPointer != simObject )
    {
      v5 = (Attachment *)&v5->mNext[-1].mNext;
      if ( v5 == v4 )
        return;
    }
    ((void (__fastcall *)(Attachment *, UFG::SimObject *, UFG::TransformNodeComponent *))v5->vfptr->OnRemove)(
      v5,
      simObject,
      transformNodeComponent);
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v8 = (UFG::qNode<Attachment,Attachment> *)&v5->mPrev;
    v6->mNext = v7;
    v7->mPrev = v6;
    v8->mPrev = v8;
    v8->mNext = v8;
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
}

// File Line: 1570
// RVA: 0x5259A0
void __fastcall UFG::WorldContextComponent::DetachAll(UFG::WorldContextComponent *this)
{
  bool *v1; // rsi
  UFG::WorldContextComponent *v2; // rdi
  UFG::qNode<Attachment,Attachment> *v3; // rbx
  UFG::qNode<Attachment,Attachment> *v4; // rdx
  UFG::qNode<Attachment,Attachment> *v5; // rax

  v1 = &this->mbSyncingCoverParkour;
  v2 = this;
  if ( (bool *)&this->mAttachments.mNode.mNext[-1].mNext != &this->mbSyncingCoverParkour )
  {
    do
    {
      v3 = v2->mAttachments.mNode.mNext;
      ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))v3[-1].mNext[4].mNext)(&v3[-1].mNext);
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **, signed __int64))v3[-1].mNext->mPrev)(
        &v3[-1].mNext,
        1i64);
    }
    while ( (bool *)&v2->mAttachments.mNode.mNext[-1].mNext != v1 );
  }
}

// File Line: 1596
// RVA: 0x5215D0
void __fastcall UFG::WorldContextComponent::AdvanceParkourNeighbor(UFG::WorldContextComponent *this, const bool bAdvanceRightNeighbor)
{
  UFG::ParkourHandle *v2; // rbx
  UFG::WorldContextComponent *v3; // rdi
  UFG::ParkourHandle *v4; // rbx

  v2 = this->mParkourHandle.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    if ( bAdvanceRightNeighbor )
      v4 = v2->mCachedRightNeighbor.m_pPointer;
    else
      v4 = v2->mCachedLeftNeighbor.m_pPointer;
    if ( v4 )
    {
      UFG::WorldContextComponent::ClearLatchedParkourHandle(this);
      UFG::WorldContextComponent::LatchParkourHandle(v3, v4);
    }
  }
}

