// File Line: 85
// RVA: 0x15441E0
__int64 dynamic_initializer_for__UFG::WorldContextComponent::s_WorldContextComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WorldContextComponent::s_WorldContextComponentList__);
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
UFG::SimComponent *__fastcall UFG::WorldContextComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  component_WorldContext *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_WorldContext::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = (component_WorldContext *)UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x270ui64, "WorldContextComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::WorldContextComponent::WorldContextComponent(
      (UFG::WorldContextComponent *)v10,
      pSceneObj->m_NameUID,
      MemImagePtr);
    v6 = v11;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v13 = 28;
  else
    v13 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qSymbol_WC_StinkyFeet__);
}

// File Line: 129
// RVA: 0x51A1C0
void __fastcall UFG::WorldContextComponent::WorldContextComponent(
        UFG::WorldContextComponent *this,
        unsigned int name_uid,
        component_WorldContext *dataPtr)
{
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *mPrev; // rax
  UFG::qVector4 v6; // xmm4
  UFG::qVector4 v7; // xmm3
  char v8; // cl

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  this->mNext = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WorldContextComponent::`vftable;
  this->mFocusParkourHandle.mPrev = &this->mFocusParkourHandle;
  this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
  this->mFocusParkourHandle.m_pPointer = 0i64;
  this->mParkourHandle.mPrev = &this->mParkourHandle;
  this->mParkourHandle.mNext = &this->mParkourHandle;
  this->mParkourHandle.m_pPointer = 0i64;
  UFG::CoverCornerHandle::CoverCornerHandle(&this->mFocusCoverCornerHandle);
  UFG::CoverCornerHandle::CoverCornerHandle(&this->mLatchedCoverCornerHandle);
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&this->mCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->mActionTreeComponent);
  mPrev = UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev;
  UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)&UFG::WorldContextComponent::s_WorldContextComponentList;
  UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mPrev = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  UFG::SimComponent::AddType(this, UFG::WorldContextComponent::_WorldContextComponentTypeUID, "WorldContextComponent");
  v6 = 0i64;
  v7 = 0i64;
  v7.x = (float)1;
  this->mLatchTest.v0 = v7;
  this->mLatchTest.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 81);
  this->mLatchTest.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 69);
  this->mLatchTest.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 21);
  v6.x = (float)1;
  this->mWorldAnchor.v0 = v6;
  this->mWorldAnchor.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 81);
  this->mWorldAnchor.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 69);
  this->mWorldAnchor.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 21);
  this->mSyncLatchedHandle = 0;
  *(_WORD *)&this->mbSyncingCoverLCorner = 0;
  this->mbSyncingCoverParkour = 0;
  this->mSyncBoneIndex = 0;
  this->mSyncPositionOnly = 0;
  *(_DWORD *)&this->mSyncPlanar = 0;
  *(_WORD *)&this->mLockSyncPosition = 0;
  this->mDistanceFromEdge = 0.40000001;
  this->mBlendRate = 1.0;
  this->mBlendWeight = 1.0;
  this->mpCoverPosition = 0i64;
  this->mToSwimming = 0i64;
  this->mSyncFeet = dataPtr->WC_StinkyFeet;
  v8 = tweaks_added;
  if ( !tweaks_added )
    v8 = 1;
  tweaks_added = v8;
}

// File Line: 179
// RVA: 0x51D620
void __fastcall UFG::WorldContextComponent::~WorldContextComponent(UFG::WorldContextComponent *this)
{
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v2; // rsi
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *mPrev; // rcx
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *mNext; // rax
  UFG::qNode<Attachment,Attachment> *v5; // rcx
  UFG::qNode<Attachment,Attachment> *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mFocusParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v17; // rcx
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v18; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WorldContextComponent::`vftable;
  UFG::WorldContextComponent::DetachAll(this);
  if ( this == UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator )
    UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator = (UFG::WorldContextComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  this->mNext = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCharacterPhysicsComponent);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mAttachments);
  v5 = this->mAttachments.mNode.mPrev;
  v6 = this->mAttachments.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  UFG::CoverCornerHandle::~CoverCornerHandle(&this->mLatchedCoverCornerHandle);
  UFG::CoverCornerHandle::~CoverCornerHandle(&this->mFocusCoverCornerHandle);
  p_mParkourHandle = &this->mParkourHandle;
  if ( this->mParkourHandle.m_pPointer )
  {
    v8 = p_mParkourHandle->mPrev;
    v9 = this->mParkourHandle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mParkourHandle->mPrev = p_mParkourHandle;
    this->mParkourHandle.mNext = &this->mParkourHandle;
  }
  this->mParkourHandle.m_pPointer = 0i64;
  v10 = p_mParkourHandle->mPrev;
  v11 = this->mParkourHandle.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mParkourHandle->mPrev = p_mParkourHandle;
  this->mParkourHandle.mNext = &this->mParkourHandle;
  p_mFocusParkourHandle = &this->mFocusParkourHandle;
  if ( this->mFocusParkourHandle.m_pPointer )
  {
    v13 = p_mFocusParkourHandle->mPrev;
    v14 = this->mFocusParkourHandle.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
    this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
  }
  this->mFocusParkourHandle.m_pPointer = 0i64;
  v15 = p_mFocusParkourHandle->mPrev;
  v16 = this->mFocusParkourHandle.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
  this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
  v17 = v2->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mPrev = v2;
  this->mNext = &this->UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 206
// RVA: 0x536560
void __fastcall UFG::WorldContextComponent::InitActionTree(UFG::WorldContextComponent *this)
{
  if ( (_S62_0 & 1) == 0 )
  {
    _S62_0 |= 1u;
    pathToSwimmingOpps.mPath.mCount = 0;
    pathToSwimmingOpps.mPath.mData.mOffset = 0i64;
    ActionPath::Append(
      &pathToSwimmingOpps,
      "\\Global\\GlobalActions\\Swimming\\OpportunityToSwimFromWorldContextComponent");
    atexit(UFG::WorldContextComponent::InitActionTree_::_2_::_dynamic_atexit_destructor_for__pathToSwimmingOpps__);
  }
  this->mToSwimming = ActionNode::Find(&pathToSwimmingOpps, 0i64);
}

// File Line: 221
// RVA: 0x53F3A0
void __fastcall UFG::WorldContextComponent::OnAttach(UFG::WorldContextComponent *this, UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_mCharacterPhysicsComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  p_mCharacterPhysicsComponent = &this->mCharacterPhysicsComponent;
  if ( p_mCharacterPhysicsComponent->m_pSimComponent )
  {
    mPrev = p_mCharacterPhysicsComponent->mPrev;
    mNext = p_mCharacterPhysicsComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCharacterPhysicsComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mCharacterPhysicsComponent->m_pSimObject = 0i64;
    p_mCharacterPhysicsComponent->mNext = p_mCharacterPhysicsComponent;
    p_mCharacterPhysicsComponent->mPrev = p_mCharacterPhysicsComponent;
    goto LABEL_8;
  }
  if ( p_mCharacterPhysicsComponent->m_pSimObject
    && (p_mCharacterPhysicsComponent->mPrev != p_mCharacterPhysicsComponent
     || p_mCharacterPhysicsComponent->mNext != p_mCharacterPhysicsComponent) )
  {
    v7 = p_mCharacterPhysicsComponent->mPrev;
    v8 = p_mCharacterPhysicsComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mCharacterPhysicsComponent->m_Changed = 1;
  p_mCharacterPhysicsComponent->m_pSimObject = object;
  p_mCharacterPhysicsComponent->m_TypeUID = UFG::CharacterPhysicsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::BindInternal<UFG::SimObject>(
    p_mCharacterPhysicsComponent,
    object);
  p_mActionTreeComponent = &this->mActionTreeComponent;
  if ( this->mActionTreeComponent.m_pSimComponent )
  {
    v10 = p_mActionTreeComponent->mPrev;
    v11 = this->mActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mActionTreeComponent.m_pSimObject = 0i64;
    this->mActionTreeComponent.mNext = &this->mActionTreeComponent;
    p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->mActionTreeComponent.m_pSimObject
    && (p_mActionTreeComponent->mPrev != p_mActionTreeComponent
     || this->mActionTreeComponent.mNext != &this->mActionTreeComponent) )
  {
    v12 = p_mActionTreeComponent->mPrev;
    v13 = this->mActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mActionTreeComponent.m_Changed = 1;
  this->mActionTreeComponent.m_pSimObject = object;
  this->mActionTreeComponent.m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &this->mActionTreeComponent,
    object);
  if ( object == UFG::GetLocalPlayer() )
    this->mSyncFeet = 1;
  UFG::WorldContextComponent::InitActionTree(this);
}

// File Line: 236
// RVA: 0x5412E0
void __fastcall UFG::WorldContextComponent::OnDetach(UFG::WorldContextComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_mCharacterPhysicsComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::CoverPosition *mpCoverPosition; // rcx

  p_mCharacterPhysicsComponent = &this->mCharacterPhysicsComponent;
  if ( this->mCharacterPhysicsComponent.m_pSimComponent )
  {
    mPrev = p_mCharacterPhysicsComponent->mPrev;
    mNext = this->mCharacterPhysicsComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mCharacterPhysicsComponent->m_pSimObject = 0i64;
    p_mCharacterPhysicsComponent->mNext = p_mCharacterPhysicsComponent;
    p_mCharacterPhysicsComponent->mPrev = p_mCharacterPhysicsComponent;
    goto LABEL_8;
  }
  if ( this->mCharacterPhysicsComponent.m_pSimObject
    && (p_mCharacterPhysicsComponent->mPrev != p_mCharacterPhysicsComponent
     || this->mCharacterPhysicsComponent.mNext != &this->mCharacterPhysicsComponent) )
  {
    v5 = p_mCharacterPhysicsComponent->mPrev;
    v6 = p_mCharacterPhysicsComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mActionTreeComponent = &this->mActionTreeComponent;
  p_mCharacterPhysicsComponent->m_Changed = 1;
  if ( this->mActionTreeComponent.m_pSimComponent )
  {
    v8 = p_mActionTreeComponent->mPrev;
    v9 = this->mActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mActionTreeComponent.m_pSimObject = 0i64;
    this->mActionTreeComponent.mNext = &this->mActionTreeComponent;
    p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->mActionTreeComponent.m_pSimObject
    && (p_mActionTreeComponent->mPrev != p_mActionTreeComponent
     || this->mActionTreeComponent.mNext != &this->mActionTreeComponent) )
  {
    v10 = p_mActionTreeComponent->mPrev;
    v11 = this->mActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->mActionTreeComponent.m_Changed = 1;
  mpCoverPosition = this->mpCoverPosition;
  if ( mpCoverPosition )
  {
    if ( mpCoverPosition->m_iRefCount-- == 1 )
      mpCoverPosition->vfptr->__vecDelDtor(mpCoverPosition, 1u);
    this->mpCoverPosition = 0i64;
  }
}

// File Line: 245
// RVA: 0x54D1B0
void __fastcall UFG::WorldContextComponent::SetFocusParkourHandle(
        UFG::WorldContextComponent *this,
        UFG::ParkourHandle *newHandle,
        ActionNode *node)
{
  UFG::ParkourHandle *m_pPointer; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mFocusParkourHandle; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v12; // rax

  m_pPointer = this->mFocusParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    *((_DWORD *)m_pPointer + 38) &= ~1u;
    p_mFocusParkourHandle = &this->mFocusParkourHandle;
    if ( this->mFocusParkourHandle.m_pPointer )
    {
      mPrev = p_mFocusParkourHandle->mPrev;
      mNext = p_mFocusParkourHandle->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
      p_mFocusParkourHandle->mNext = p_mFocusParkourHandle;
    }
    p_mFocusParkourHandle->m_pPointer = 0i64;
  }
  if ( newHandle )
  {
    v9 = &this->mFocusParkourHandle;
    if ( this->mFocusParkourHandle.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = this->mFocusParkourHandle.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
      this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
    }
    this->mFocusParkourHandle.m_pPointer = newHandle;
    v12 = newHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    v12->mNext = v9;
    v9->mPrev = v12;
    this->mFocusParkourHandle.mNext = &newHandle->m_SafePointerList.mNode;
    newHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = v9;
    *((_DWORD *)this->mFocusParkourHandle.m_pPointer + 38) |= 1u;
    this->mFocusLatchCount = 0;
  }
}

// File Line: 281
// RVA: 0x53C880
void __fastcall UFG::WorldContextComponent::LatchFocusParkourHandle(UFG::WorldContextComponent *this)
{
  UFG::ParkourHandle *m_pPointer; // rdx
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mFocusParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = this->mFocusParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    UFG::WorldContextComponent::LatchParkourHandle(this, m_pPointer);
    p_mFocusParkourHandle = &this->mFocusParkourHandle;
    if ( this->mFocusParkourHandle.m_pPointer )
    {
      mPrev = p_mFocusParkourHandle->mPrev;
      mNext = this->mFocusParkourHandle.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
      this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
    }
    this->mFocusParkourHandle.m_pPointer = 0i64;
  }
}

// File Line: 292
// RVA: 0x53C8D0
void __fastcall UFG::WorldContextComponent::LatchParkourHandle(
        UFG::WorldContextComponent *this,
        UFG::ParkourHandle *newHandle)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mParkourHandle; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::ParkourHandle *m_pPointer; // rax

  p_mParkourHandle = &this->mParkourHandle;
  if ( this->mParkourHandle.m_pPointer )
  {
    mPrev = p_mParkourHandle->mPrev;
    mNext = this->mParkourHandle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourHandle->mPrev = p_mParkourHandle;
    this->mParkourHandle.mNext = &this->mParkourHandle;
  }
  this->mParkourHandle.m_pPointer = newHandle;
  if ( newHandle )
  {
    v5 = newHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
    v5->mNext = p_mParkourHandle;
    p_mParkourHandle->mPrev = v5;
    this->mParkourHandle.mNext = &newHandle->m_SafePointerList.mNode;
    newHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = p_mParkourHandle;
  }
  m_pPointer = this->mParkourHandle.m_pPointer;
  if ( m_pPointer )
    *((_DWORD *)m_pPointer + 38) |= 1u;
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
  UFG::ParkourHandle *m_pPointer; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::ParkourHandle *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mFocusParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax

  m_pPointer = this->mParkourHandle.m_pPointer;
  if ( m_pPointer )
    *((_DWORD *)m_pPointer + 38) &= ~1u;
  p_mParkourHandle = &this->mParkourHandle;
  if ( this->mParkourHandle.m_pPointer )
  {
    mPrev = p_mParkourHandle->mPrev;
    mNext = p_mParkourHandle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParkourHandle->mPrev = p_mParkourHandle;
    p_mParkourHandle->mNext = p_mParkourHandle;
  }
  p_mParkourHandle->m_pPointer = 0i64;
  v6 = this->mFocusParkourHandle.m_pPointer;
  if ( v6 )
    *((_DWORD *)v6 + 38) &= ~1u;
  p_mFocusParkourHandle = &this->mFocusParkourHandle;
  if ( this->mFocusParkourHandle.m_pPointer )
  {
    v8 = p_mFocusParkourHandle->mPrev;
    v9 = this->mFocusParkourHandle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
    this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
  }
  this->mFocusParkourHandle.m_pPointer = 0i64;
}

// File Line: 337
// RVA: 0x550050
void __fastcall UFG::WorldContextComponent::StartSyncHandle(
        UFG::WorldContextComponent *this,
        int syncBoneIndex,
        bool positionOnly,
        bool syncToClosestEndpoint,
        bool planer,
        bool syncXforward,
        bool syncLeftEdge,
        bool syncRightEdge,
        float distanceFromEdge,
        float blendIn)
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
void __fastcall UFG::WorldContextComponent::StartSync(
        UFG::WorldContextComponent *this,
        int syncBoneIndex,
        bool positionOnly,
        bool syncToClosestEndpoint,
        bool planer,
        bool syncXforward,
        bool syncLeftEdge,
        bool syncRightEdge,
        float distanceFromEdge,
        float blendIn)
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
void __fastcall UFG::WorldContextComponent::SetCoverPosition(
        UFG::WorldContextComponent *this,
        UFG::CoverPosition *pPosition)
{
  UFG::CoverPosition *mpCoverPosition; // rcx

  mpCoverPosition = this->mpCoverPosition;
  if ( mpCoverPosition )
  {
    if ( mpCoverPosition->m_iRefCount-- == 1 )
      mpCoverPosition->vfptr->__vecDelDtor(mpCoverPosition, 1u);
    this->mpCoverPosition = 0i64;
  }
  if ( pPosition )
  {
    this->mpCoverPosition = pPosition;
    ++pPosition->m_iRefCount;
  }
}

// File Line: 407
// RVA: 0x55CFA0
void __fastcall UFG::WorldContextComponent::Update(UFG::WorldContextComponent *this, float delta_sec)
{
  float v4; // xmm10_4
  float mBlendRate; // xmm1_4
  float v6; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx
  __int64 v8; // rsi
  ActionNodeRoot *v9; // rax
  ActionNodeRoot *v10; // rdi
  __int64 mValue; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // r8
  UFG::ActionTreeComponentBase *mPrev; // rcx
  ActionNodePlayable *v14; // rax
  Render::DebugDrawContext *Context; // r15
  Render::DebugDrawContext *v16; // r12
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *v18; // rsi
  UFG::qVector3 *p_m_TypeUID; // rdi
  float v20; // xmm2_4
  float v21; // xmm1_4
  float z; // xmm3_4
  float x; // xmm4_4
  __m128 y_low; // xmm5
  float v25; // xmm3_4
  __m128 v26; // xmm2
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  int v31; // xmm8_4
  int v32; // xmm7_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm8_4
  float v36; // xmm7_4
  float v37; // xmm13_4
  float y; // xmm14_4
  float v39; // xmm11_4
  __m128 v40; // xmm2
  float v41; // xmm7_4
  float v42; // xmm8_4
  double v43; // xmm4_8
  float v44; // xmm6_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  double v47; // xmm0_8
  UFG::SimObject *v48; // rcx
  UFG::SensorComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v53; // rdx
  unsigned int v54; // r8d
  unsigned int v55; // r10d
  UFG::SimObjectProp *v56; // rcx
  UFG::CharacterAnimationComponent *v57; // rcx
  __int16 v58; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v61; // r10d
  UFG::SimComponentHolder *p; // rsi
  UFG::SimObject *v63; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v65; // xmm1_4
  float v66; // xmm2_4
  int v67; // xmm6_4
  int v68; // xmm7_4
  int v69; // xmm8_4
  unsigned int i; // r14d
  UFG::ParkourHandle *v71; // rdi
  float v72; // xmm3_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  UFG::ParkourHandle *m_pPointer; // rax
  UFG::ParkourHandle *v76; // rax
  UFG::ParkourHandle *v77; // rax
  UFG::ParkourHandle *v78; // rax
  UFG::qVector3 *Position; // rax
  float v80; // xmm6_4
  float v81; // xmm7_4
  UFG::qVector3 *Axis; // rax
  float v83; // xmm3_4
  __m128 x_low; // xmm4
  float v85; // xmm5_4
  __m128 v86; // xmm2
  float v87; // xmm1_4
  float v88; // xmm15_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  float w; // xmm3_4
  float v92; // xmm1_4
  float v93; // xmm2_4
  float v94; // xmm3_4
  float v95; // xmm1_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm3_4
  float v101; // xmm13_4
  float v102; // xmm14_4
  float v103; // xmm12_4
  float v104; // xmm14_4
  float v105; // xmm4_4
  float v106; // xmm14_4
  UFG::ParkourHandle *v107; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mFocusParkourHandle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v109; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v110; // rax
  bool *p_mNext; // rdi
  bool *j; // rbx
  UFG::qVector3 p1; // [rsp+80h] [rbp-80h] BYREF
  float v114; // [rsp+90h] [rbp-70h]
  float v115; // [rsp+94h] [rbp-6Ch]
  float v116; // [rsp+98h] [rbp-68h]
  UFG::qVector3 world_position; // [rsp+A0h] [rbp-60h] BYREF
  int v118; // [rsp+B0h] [rbp-50h]
  float v119; // [rsp+B4h] [rbp-4Ch] BYREF
  int v120; // [rsp+B8h] [rbp-48h]
  int v121; // [rsp+BCh] [rbp-44h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qVector3 vmax; // [rsp+100h] [rbp+0h] BYREF
  UFG::qVector3 v124; // [rsp+110h] [rbp+10h] BYREF
  UFG::qVector3 v125; // [rsp+11Ch] [rbp+1Ch] BYREF
  UFG::qVector3 v126; // [rsp+128h] [rbp+28h] BYREF
  UFG::qVector3 vmin; // [rsp+138h] [rbp+38h] BYREF
  UFG::qMatrix44 d; // [rsp+150h] [rbp+50h] BYREF
  UFG::ParkourHandle *v129[2]; // [rsp+190h] [rbp+90h] BYREF
  UFG::qVector3 result; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qVector3 v131; // [rsp+1ACh] [rbp+ACh] BYREF
  UFG::qFixedArray<UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle>,768> out; // [rsp+1C0h] [rbp+C0h] BYREF
  bool v133; // [rsp+4AC0h] [rbp+49C0h] BYREF
  float v134; // [rsp+4AC8h] [rbp+49C8h]
  float v135; // [rsp+4AD0h] [rbp+49D0h]
  float v136; // [rsp+4AD8h] [rbp+49D8h]

  v134 = delta_sec;
  v129[1] = (UFG::ParkourHandle *)-2i64;
  if ( (this->m_Flags & 2) != 0 )
    return;
  v4 = *(float *)&FLOAT_1_0;
  if ( this->mSyncLatchedHandle
    || this->mbSyncingCoverParkour
    || this->mbSyncingCoverLCorner
    || this->mbSyncingCoverRCorner )
  {
    mBlendRate = this->mBlendRate;
    if ( mBlendRate != 0.0 )
    {
      v6 = (float)(mBlendRate * delta_sec) + this->mBlendWeight;
      this->mBlendWeight = v6;
      if ( mBlendRate <= 0.0 )
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
    mNext = this->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext;
    v8 = ((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))mNext->mPrev[9].mNext)(mNext);
    v9 = (ActionNodeRoot *)this->mToSwimming->vfptr[1].GetResourceOwner(this->mToSwimming);
    v10 = v9;
    mValue = v9->mActionTreeType.mValue;
    v12 = this->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    if ( (*((_QWORD *)&v12[4].mNext + mValue) || v12[5].mPrev) && (ActionNodeRoot *)v8 != v9 )
    {
      mPrev = (UFG::ActionTreeComponentBase *)*((_QWORD *)&v12[4].mNext + mValue);
      if ( !mPrev )
        mPrev = (UFG::ActionTreeComponentBase *)v12[5].mPrev;
      if ( UFG::ActionTreeComponentBase::AllocateFor(mPrev, v9) )
        ActionNodeRoot::Init(
          v10,
          (ActionContext *)this->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext);
    }
    v14 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *))this->mToSwimming->vfptr[2].GetClassNameUID)(
                                  this->mToSwimming,
                                  this->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext);
    if ( v14 )
      ActionController::PlayTracks((ActionController *)&this->mActionTreeComponent.m_pSimComponent[3], v14, 0, 0.0);
  }
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  if ( UFG::WorldContextComponent::s_DrawGroundDebug )
  {
    m_pSimObject = this->m_pSimObject;
    v18 = m_pSimObject ? m_pSimObject->m_pTransformNodeComponent : 0i64;
    if ( this->mCharacterPhysicsComponent.m_pSimComponent )
    {
      p_m_TypeUID = (UFG::qVector3 *)&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_TypeUID;
      v20 = *((float *)&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_pSimObject + 1)
          + *(float *)&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_Flags;
      v21 = *(float *)&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_pSimObject
          + *(float *)&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_NameUID;
      p1.x = *(float *)(&this->mCharacterPhysicsComponent.m_pSimComponent[5].m_SimObjIndex + 1) + p_m_TypeUID->x;
      p1.y = v21;
      p1.z = v20;
      Render::DebugDrawContext::DrawLine(
        Context,
        p_m_TypeUID,
        &p1,
        &UFG::qColour::Cyan,
        &UFG::qMatrix44::msIdentity,
        0i64,
        0);
      z = p_m_TypeUID[1].z;
      if ( z < 0.94999999 && z > 0.050000001 )
      {
        x = p_m_TypeUID[1].x;
        y_low = (__m128)LODWORD(p_m_TypeUID[1].y);
        v25 = z - (float)(1.0 / z);
        v26 = y_low;
        v26.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(v25 * v25);
        v27 = v26.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
        v28 = v27 * v25;
        v29 = v27 * y_low.m128_f32[0];
        v30 = v27 * x;
        v31 = LODWORD(v28) ^ _xmm[0];
        v32 = LODWORD(v29) ^ _xmm[0];
        v33 = v28 + p_m_TypeUID->z;
        v34 = v29 + p_m_TypeUID->y;
        p1.x = v30 + p_m_TypeUID->x;
        p1.y = v34;
        p1.z = v33;
        Render::DebugDrawContext::DrawLine(
          Context,
          p_m_TypeUID,
          &p1,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        v35 = *(float *)&v31 + p_m_TypeUID->z;
        v36 = *(float *)&v32 + p_m_TypeUID->y;
        p1.x = COERCE_FLOAT(LODWORD(v30) ^ _xmm[0]) + p_m_TypeUID->x;
        p1.y = v36;
        p1.z = v35;
        Render::DebugDrawContext::DrawLine(
          Context,
          p_m_TypeUID,
          &p1,
          &UFG::qColour::Red,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        if ( v18 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v18);
          v37 = v18->mWorldTransform.v3.x;
          y = v18->mWorldTransform.v3.y;
          v39 = v18->mWorldTransform.v3.z;
          UFG::TransformNodeComponent::UpdateWorldTransform(v18);
          v40 = (__m128)LODWORD(v18->mWorldTransform.v0.y);
          v41 = p_m_TypeUID[1].y;
          v42 = p_m_TypeUID[1].x;
          *(_QWORD *)&v43 = LODWORD(v18->mWorldTransform.v0.z);
          v44 = p_m_TypeUID[1].z;
          v45 = (float)((float)(v18->mWorldTransform.v0.x * v42) + (float)(v18->mWorldTransform.v0.y * v41))
              + (float)(v18->mWorldTransform.v0.z * v44);
          if ( v45 > -0.94999999 && v45 < 0.94999999 )
          {
            *(float *)&v43 = *(float *)&v43 - (float)(v44 * v45);
            v40.m128_f32[0] = (float)((float)((float)(v40.m128_f32[0] - (float)(v41 * v45))
                                            * (float)(v40.m128_f32[0] - (float)(v41 * v45)))
                                    + (float)((float)(v18->mWorldTransform.v0.x - (float)(v42 * v45))
                                            * (float)(v18->mWorldTransform.v0.x - (float)(v42 * v45))))
                            + (float)(*(float *)&v43 * *(float *)&v43);
            if ( v40.m128_f32[0] == 0.0 )
              v46 = 0.0;
            else
              v46 = 1.0 / _mm_sqrt_ps(v40).m128_f32[0];
            *(float *)&v43 = *(float *)&v43 * v46;
            v47 = UFG::qASin(v43);
            p1.x = v37;
            p1.y = y;
            p1.z = v39 + 0.1;
            Render::DebugDrawContext::DrawText(
              Context,
              &p1,
              &UFG::qColour::Green,
              "Grade:%0.3f:",
              (float)((float)(*(float *)&v47 * 180.0) * 0.31830987));
          }
        }
      }
    }
  }
  if ( UFG::WorldContextComponent::s_DrawParkourSensing )
  {
    gDebugPark = 1;
    v48 = this->m_pSimObject;
    if ( !v48 )
    {
LABEL_43:
      m_pComponent = 0i64;
      goto LABEL_62;
    }
    m_Flags = v48->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::SensorComponent *)v48->m_Components.p[26].m_pComponent;
      goto LABEL_62;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::SensorComponent *)v48->m_Components.p[26].m_pComponent;
      goto LABEL_62;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)v48[1].vfptr;
      size = v48->m_Components.size;
      if ( vfptr >= size )
        goto LABEL_43;
      while ( 1 )
      {
        v53 = (__int64)&v48->m_Components.p[vfptr];
        if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && (UFG::SensorComponent::_TypeUID & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_43;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::SensorComponent *)UFG::SimObject::GetComponentOfType(v48, UFG::SensorComponent::_TypeUID);
LABEL_62:
        v56 = (UFG::SimObjectProp *)this->m_pSimObject;
        if ( !v56 )
        {
LABEL_63:
          v57 = 0i64;
          goto LABEL_86;
        }
        v58 = v56->m_Flags;
        if ( (v58 & 0x4000) != 0 )
        {
          v57 = (UFG::CharacterAnimationComponent *)v56->m_Components.p[9].m_pComponent;
          if ( v57 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v57->m_TypeUID) & 0xFE000000) == 0 )
          {
            if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v57->m_TypeUID & 0x1FFFFFF) != 0 )
              v57 = 0i64;
            goto LABEL_86;
          }
          goto LABEL_63;
        }
        if ( v58 < 0 )
        {
          v57 = (UFG::CharacterAnimationComponent *)v56->m_Components.p[9].m_pComponent;
          if ( v57 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v57->m_TypeUID) & 0xFE000000) == 0 )
          {
            if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v57->m_TypeUID & 0x1FFFFFF) != 0 )
              v57 = 0i64;
            goto LABEL_86;
          }
          goto LABEL_63;
        }
        if ( (v58 & 0x2000) != 0 )
        {
          ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v56);
        }
        else
        {
          if ( (v58 & 0x1000) != 0 )
          {
            mComponentTableEntryCount = v56->mComponentTableEntryCount;
            v61 = v56->m_Components.size;
            if ( mComponentTableEntryCount < v61 )
            {
              p = v56->m_Components.p;
              while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++mComponentTableEntryCount >= v61 )
                  goto LABEL_63;
              }
              v57 = (UFG::CharacterAnimationComponent *)p[mComponentTableEntryCount].m_pComponent;
              goto LABEL_86;
            }
            goto LABEL_63;
          }
          ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v56,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
        }
        v57 = ComponentOfType;
LABEL_86:
        v63 = this->m_pSimObject;
        if ( v63 )
          m_pTransformNodeComponent = v63->m_pTransformNodeComponent;
        else
          m_pTransformNodeComponent = 0i64;
        if ( m_pComponent && v57 && m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v65 = m_pTransformNodeComponent->mWorldTransform.v3.y;
          v66 = m_pTransformNodeComponent->mWorldTransform.v3.z;
          p1.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
          p1.y = v65;
          p1.z = v66;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v129[0] = 0i64;
          v119 = FLOAT_3_4028235e38;
          UFG::SensorComponent::GetExtents(m_pComponent, &vmin, &vmax);
          v67 = COERCE_UNSIGNED_INT(vmax.x - vmin.x) & _xmm;
          v120 = v67;
          v68 = COERCE_UNSIGNED_INT(vmax.y - vmin.y) & _xmm;
          v118 = v68;
          v69 = COERCE_UNSIGNED_INT(vmax.z - vmin.z) & _xmm;
          v121 = v69;
          `eh vector constructor iterator(
            out.p,
            0x18ui64,
            768,
            (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
          out.size = 0;
          UFG::SensorComponent::GetParkourHandles(m_pComponent, &out);
          v133 = 0;
          for ( i = 0; i < out.size; ++i )
          {
            v71 = (UFG::ParkourHandle *)*((_QWORD *)&out.p[0].m_pPointer + 3 * i);
            if ( v71 )
            {
              if ( *(float *)&v67 >= *(float *)&v68 )
                v72 = *(float *)&v68;
              else
                v72 = *(float *)&v67;
              v73 = m_pTransformNodeComponent->mWorldTransform.v0.y;
              v74 = m_pTransformNodeComponent->mWorldTransform.v0.z;
              v126.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
              v126.y = v73;
              v126.z = v74;
              compareParkourHandles(
                -1,
                &p1,
                &v126,
                3.1415927,
                0.0,
                0.0,
                v72,
                0.0,
                *(const float *)&v69,
                &world_position,
                v71,
                v129,
                &v119,
                &v133);
              m_pPointer = this->mFocusParkourHandle.m_pPointer;
              if ( m_pPointer && v71 == m_pPointer )
              {
                Render::DebugDrawContext::DrawLine(
                  v16,
                  &p1,
                  &world_position,
                  &UFG::qColour::Cyan,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                Render::DebugDrawContext::DrawText(Context, &world_position, &UFG::qColour::Cyan, "FocusHandle");
              }
              v76 = this->mParkourHandle.m_pPointer;
              if ( v76 && v71 == v76 )
              {
                Render::DebugDrawContext::DrawLine(
                  v16,
                  &p1,
                  &world_position,
                  &UFG::qColour::DeepPink,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                v125.x = world_position.x;
                v125.y = world_position.y;
                v125.z = world_position.z - 0.1;
                Render::DebugDrawContext::DrawText(Context, &v125, &UFG::qColour::DeepPink, "LatchedHandle");
              }
              v77 = this->mFocusParkourHandle.m_pPointer;
              if ( v77 && v71 == v77 || (v78 = this->mParkourHandle.m_pPointer) != 0i64 && v71 == v78 )
              {
                Position = UFG::ParkourHandle::GetPosition(v71, &result);
                v135 = Position->x;
                v80 = Position->y;
                v136 = v80;
                v81 = Position->z;
                v114 = v81;
                Axis = UFG::ParkourHandle::GetAxis(v71, &v131);
                v83 = Axis->y;
                x_low = (__m128)LODWORD(Axis->x);
                v85 = Axis->z;
                v86 = x_low;
                v86.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v83 * v83))
                                + (float)(v85 * v85);
                if ( v86.m128_f32[0] == 0.0 )
                  v87 = 0.0;
                else
                  v87 = v4 / _mm_sqrt_ps(v86).m128_f32[0];
                v88 = v87 * v85;
                v115 = v87 * v83;
                v116 = v87 * x_low.m128_f32[0];
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                v89 = m_pTransformNodeComponent->mWorldTransform.v0.y;
                v90 = m_pTransformNodeComponent->mWorldTransform.v0.z;
                w = m_pTransformNodeComponent->mWorldTransform.v0.w;
                m.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
                m.v0.y = v89;
                m.v0.z = v90;
                m.v0.w = w;
                v92 = m_pTransformNodeComponent->mWorldTransform.v1.y;
                v93 = m_pTransformNodeComponent->mWorldTransform.v1.z;
                v94 = m_pTransformNodeComponent->mWorldTransform.v1.w;
                m.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
                m.v1.y = v92;
                m.v1.z = v93;
                m.v1.w = v94;
                v95 = m_pTransformNodeComponent->mWorldTransform.v2.y;
                v96 = m_pTransformNodeComponent->mWorldTransform.v2.z;
                v97 = m_pTransformNodeComponent->mWorldTransform.v2.w;
                m.v2.x = m_pTransformNodeComponent->mWorldTransform.v2.x;
                m.v2.y = v95;
                m.v2.z = v96;
                m.v2.w = v97;
                v98 = m_pTransformNodeComponent->mWorldTransform.v3.y;
                v99 = m_pTransformNodeComponent->mWorldTransform.v3.z;
                v100 = m_pTransformNodeComponent->mWorldTransform.v3.w;
                m.v3.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
                m.v3.y = v98;
                m.v3.z = v99;
                m.v3.w = v100;
                UFG::qInverseAffine(&d, &m);
                v101 = (float)((float)((float)(v135 * d.v0.x) + (float)(v80 * d.v1.x)) + (float)(v81 * d.v2.x)) + d.v3.x;
                v102 = (float)((float)((float)(v135 * d.v0.y) + (float)(v80 * d.v1.y)) + (float)(v81 * d.v2.y)) + d.v3.y;
                v103 = (float)((float)((float)(v135 * d.v0.z) + (float)(v136 * d.v1.z)) + (float)(v114 * d.v2.z))
                     + d.v3.z;
                v135 = (float)((float)((float)(v135 * d.v0.w) + (float)(v136 * d.v1.w)) + (float)(v114 * d.v2.w))
                     + d.v3.w;
                LODWORD(v104) = COERCE_UNSIGNED_INT(
                                  v102
                                / (float)((float)((float)(v115 * d.v1.y) + (float)(d.v0.y * v116))
                                        + (float)(v88 * d.v2.y))) ^ _xmm[0];
                v105 = (float)(v104
                             * (float)((float)((float)(v115 * d.v1.x) + (float)(d.v0.x * v116)) + (float)(v88 * d.v2.x)))
                     + v101;
                v106 = (float)(v104
                             * (float)((float)((float)(v115 * d.v1.z) + (float)(d.v0.z * v116)) + (float)(v88 * d.v2.z)))
                     + v103;
                v124.x = (float)((float)((float)(m.v0.x * v105) + (float)(m.v1.x * 0.0)) + (float)(m.v2.x * v106))
                       + (float)(m.v3.x * v135);
                v124.y = (float)((float)((float)(m.v0.y * v105) + (float)(m.v1.y * 0.0)) + (float)(m.v2.y * v106))
                       + (float)(m.v3.y * v135);
                v124.z = (float)((float)((float)(m.v0.z * v105) + (float)(m.v1.z * 0.0)) + (float)(m.v2.z * v106))
                       + (float)(m.v3.z * v135);
                Render::DebugDrawContext::DrawLine(
                  v16,
                  &p1,
                  &v124,
                  &UFG::qColour::Cyan,
                  &UFG::qMatrix44::msIdentity,
                  0i64,
                  0);
                v67 = v120;
                v68 = v118;
                v69 = v121;
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
        goto LABEL_113;
      }
      v54 = (unsigned int)v48[1].vfptr;
      v55 = v48->m_Components.size;
      if ( v54 >= v55 )
        goto LABEL_43;
      while ( 1 )
      {
        v53 = (__int64)&v48->m_Components.p[v54];
        if ( (*(_DWORD *)(v53 + 8) & 0xFE000000) == (UFG::SensorComponent::_TypeUID & 0xFE000000)
          && (UFG::SensorComponent::_TypeUID & ~*(_DWORD *)(v53 + 8) & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v54 >= v55 )
          goto LABEL_43;
      }
    }
    m_pComponent = *(UFG::SensorComponent **)v53;
    goto LABEL_62;
  }
LABEL_113:
  v107 = this->mFocusParkourHandle.m_pPointer;
  if ( v107 )
  {
    if ( this->mFocusLatchCount > 10 )
    {
      *((_DWORD *)v107 + 38) &= ~1u;
      p_mFocusParkourHandle = &this->mFocusParkourHandle;
      if ( this->mFocusParkourHandle.m_pPointer )
      {
        v109 = p_mFocusParkourHandle->mPrev;
        v110 = this->mFocusParkourHandle.mNext;
        v109->mNext = v110;
        v110->mPrev = v109;
        p_mFocusParkourHandle->mPrev = p_mFocusParkourHandle;
        this->mFocusParkourHandle.mNext = &this->mFocusParkourHandle;
      }
      this->mFocusParkourHandle.m_pPointer = 0i64;
    }
    ++this->mFocusLatchCount;
  }
  p_mNext = (bool *)&this->mAttachments.mNode.mNext[-1].mNext;
  for ( j = &this->mbSyncingCoverParkour; p_mNext != j; p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64) )
    (*(void (__fastcall **)(bool *))(*(_QWORD *)p_mNext + 8i64))(p_mNext);
}

// File Line: 737
// RVA: 0x564070
void __fastcall UFG::adjustTransformInReferanceFrame_RotX(
        UFG::qMatrix44 *inputOutputFrame,
        UFG::qMatrix44 *adjustmentFrame,
        float rotX)
{
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qMatrix44 result; // [rsp+20h] [rbp-188h] BYREF
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-148h] BYREF
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-108h] BYREF
  UFG::qMatrix44 v12; // [rsp+E0h] [rbp-C8h] BYREF

  UFG::qInverseAffine(&b, adjustmentFrame);
  UFG::qMatrix44::operator*(inputOutputFrame, &result, &b);
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
  v5 = UFG::qMatrix44::operator*(&result, &v12, adjustmentFrame);
  v6 = v5->v1;
  v7 = v5->v2;
  v8 = v5->v3;
  inputOutputFrame->v0 = v5->v0;
  inputOutputFrame->v1 = v6;
  inputOutputFrame->v2 = v7;
  inputOutputFrame->v3 = v8;
} = v6;
  inputOutputFrame->v2 = v7;
  inputOutputFram

// File Line: 751
// RVA: 0x154C560
__int64 UFG::_dynamic_initializer_for__sLeftArmIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftArmIK", -1);
  UFG::sLeftArmIKNameUID = result;
  return result;
}

// File Line: 752
// RVA: 0x154C600
__int64 UFG::_dynamic_initializer_for__sRightArmIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightArmIK", -1);
  UFG::sRightArmIKNameUID = result;
  return result;
}

// File Line: 753
// RVA: 0x154C5A0
__int64 UFG::_dynamic_initializer_for__sLeftLegIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftLegIK", -1);
  UFG::sLeftLegIKNameUID = result;
  return result;
}

// File Line: 754
// RVA: 0x154C640
__int64 UFG::_dynamic_initializer_for__sRightLegIKNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightLegIK", -1);
  UFG::sRightLegIKNameUID = result;
  return result;
}

// File Line: 756
// RVA: 0x154C660
__int64 UFG::_dynamic_initializer_for__sRightShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwist", -1);
  UFG::sRightShoulderTwistUID = result;
  return result;
}

// File Line: 757
// RVA: 0x154C5C0
__int64 UFG::_dynamic_initializer_for__sLeftShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwist", -1);
  UFG::sLeftShoulderTwistUID = result;
  return result;
}

// File Line: 758
// RVA: 0x154C620
__int64 UFG::_dynamic_initializer_for__sRightForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightForearmTwist", -1);
  UFG::sRightForearmTwistUID = result;
  return result;
}

// File Line: 759
// RVA: 0x154C580
__int64 UFG::_dynamic_initializer_for__sLeftForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftForearmTwist", -1);
  UFG::sLeftForearmTwistUID = result;
  return result;
}

// File Line: 761
// RVA: 0x154C9E0
__int64 UFG::_dynamic_initializer_for__sSyncUID__()
{
  UFG::qSymbolUC::create_from_string(&UFG::sSyncUID, "Sync01");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSyncUID__);
}

// File Line: 775
// RVA: 0x56DAD0
void __fastcall UFG::syncHands(Creature *creature, UFG::qVector3 *origin, UFG::qVector3 *axis)
{
  __int64 v5; // rdi
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rax
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  __int64 v8; // rax
  __int64 v9; // r15
  __int64 v10; // r14
  __int64 v11; // rsi
  __int64 v12; // rdx
  __int64 v13; // rdx
  int v14; // eax
  int v15; // eax
  bool v16; // zf
  __m128 v17; // xmm2
  int BoneID; // eax
  float x; // xmm5_4
  __m128 y_low; // xmm2
  float v21; // xmm4_4
  __m128 v22; // xmm1
  float v23; // xmm3_4
  float z; // xmm8_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // xmm6_4
  __int64 v28; // rdx
  UFG::qMatrix44 adjustmentFrame; // [rsp+20h] [rbp-148h] BYREF
  __m128 v30; // [rsp+60h] [rbp-108h]
  __m128 v31; // [rsp+70h] [rbp-F8h]
  __m128 v32; // [rsp+80h] [rbp-E8h]
  __m128 v33; // [rsp+90h] [rbp-D8h]
  UFG::qMatrix44 transform; // [rsp+A0h] [rbp-C8h] BYREF
  UFG::qMatrix44 inputOutputFrame; // [rsp+E0h] [rbp-88h] BYREF

  if ( sEnableSyncHands )
  {
    v5 = 0i64;
    mNext = creature->mPoseDrivers.mNode.mNext;
    p_m_SafePointerList = &creature->m_SafePointerList;
    v8 = (__int64)&mNext[-1];
    v9 = 0i64;
    v10 = 0i64;
    v11 = 0i64;
    if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != p_m_SafePointerList )
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
      while ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != p_m_SafePointerList );
      if ( v5 && v9 )
      {
        LOBYTE(v12) = 1;
        (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD))(*(_QWORD *)v5 + 88i64))(
          v5,
          v12,
          UFG::sLeftArmIKNameUID,
          UFG::sRightArmIKNameUID);
        LOBYTE(v13) = 1;
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v9 + 88i64))(v9, v13);
        v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 112i64))(v5);
        Creature::GetTransform(creature, v14, &transform);
        v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 112i64))(v9);
        Creature::GetTransform(creature, v15, &inputOutputFrame);
        Creature::GetTransform(creature, sFollowJointID, &adjustmentFrame);
        v16 = creature->mPose.mRigHandle.mData == 0i64;
        v17 = 0i64;
        v17.m128_f32[0] = (float)1;
        v30 = v17;
        v33 = _mm_shuffle_ps(v17, v17, 21);
        v31 = _mm_shuffle_ps(v17, v17, 81);
        v32 = _mm_shuffle_ps(v17, v17, 69);
        if ( v16 )
          BoneID = -1;
        else
          BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, UFG::sSyncUID.mUID);
        Creature::GetTransform(creature, BoneID, &adjustmentFrame);
        x = axis->x;
        y_low = (__m128)LODWORD(axis->y);
        v21 = *(float *)&FLOAT_1_0;
        v22 = y_low;
        v22.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
        if ( v22.m128_f32[0] == 0.0 )
          v23 = 0.0;
        else
          v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
        z = axis->z;
        v25 = (float)((float)(y_low.m128_f32[0] * (float)(y_low.m128_f32[0] * v23)) + (float)(x * (float)(x * v23)))
            + (float)(z * (float)(v23 * 0.0));
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
        if ( z < 0.0 )
          v27 = LODWORD(v26) ^ _xmm[0];
        UFG::adjustTransformInReferanceFrame_RotX(&transform, &adjustmentFrame, *(float *)&v27);
        UFG::adjustTransformInReferanceFrame_RotX(&inputOutputFrame, &adjustmentFrame, *(float *)&v27);
        (*(void (__fastcall **)(__int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v5 + 120i64))(
          v5,
          &creature->mPose,
          &transform);
        (*(void (__fastcall **)(__int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v9 + 120i64))(
          v9,
          &creature->mPose,
          &inputOutputFrame);
        if ( v10 )
        {
          LOBYTE(v28) = 1;
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 88i64))(v10, v28);
        }
        if ( v11 )
        {
          LOBYTE(v28) = 1;
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 88i64))(v11, v28);
        }
        Creature::updateEffectorsToPose(creature);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v5 + 88i64))(v5, 0i64);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 88i64))(v9, 0i64);
        if ( v10 )
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 88i64))(v10, 0i64);
        if ( v11 )
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v11 + 88i64))(v11, 0i64);
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
__int64 __fastcall UFG::adJustEffectorToGround(
        Creature *creature,
        int jointID,
        UFG::qMatrix44 *inputOutupMatrix,
        unsigned int layer,
        float legUp)
{
  unsigned __int8 v7; // di
  float x; // xmm6_4
  float y; // xmm5_4
  float z; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  Render::DebugDrawContext *Context; // rbx
  Render::DebugDrawContext *v15; // rax
  UFG::qColour *v16; // r9
  UFG::qVector3 rayStart; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 rayEnd; // [rsp+50h] [rbp-B0h] BYREF
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h] BYREF

  v7 = 0;
  Creature::GetTransform(creature, jointID, inputOutupMatrix);
  x = inputOutupMatrix->v3.x;
  y = inputOutupMatrix->v3.y;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeyIndex = 0;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mOutput.m_rootCollidable = 0i64;
  z = inputOutupMatrix->v3.z;
  rayStart.x = x + (float)(UFG::qVector3::msDirUp.x * legUp);
  data.mDebugName = 0i64;
  data.mCollisionModelName.mUID = -1;
  rayStart.y = y + (float)(UFG::qVector3::msDirUp.y * legUp);
  rayEnd.x = x - (float)(UFG::qVector3::msDirUp.x * sDownLeg);
  rayEnd.y = y - (float)(UFG::qVector3::msDirUp.y * sDownLeg);
  rayEnd.z = z - (float)(UFG::qVector3::msDirUp.z * sDownLeg);
  rayStart.z = z + (float)(UFG::qVector3::msDirUp.z * legUp);
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, layer);
  if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
  {
    v11 = data.point.x;
    v12 = data.point.y;
    v7 = 0;
    inputOutupMatrix->v3.w = 1.0;
    inputOutupMatrix->v3.x = v11;
    v13 = data.point.z;
    inputOutupMatrix->v3.y = v12;
    inputOutupMatrix->v3.z = v13;
    if ( data.normal.z >= sGroundNormalFilter )
      v7 = 1;
  }
  if ( sDebugDraw )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v15 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    if ( v7 )
    {
      Render::DebugDrawContext::DrawCoord(v15, inputOutupMatrix, sContactScale, 0i64);
      v16 = &UFG::qColour::Gold;
    }
    else
    {
      v16 = &UFG::qColour::DeepPink;
    }
    Render::DebugDrawContext::DrawLine(Context, &rayStart, &rayEnd, v16, &UFG::qMatrix44::msIdentity, 0i64, 0);
  }
  return v7;
}

// File Line: 942
// RVA: 0x56D880
void __fastcall UFG::syncFeet(Creature *creature, unsigned int layer, float legUp)
{
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rax
  __int64 v6; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  __int64 v8; // rax
  __int64 v9; // rdi
  int v10; // eax
  __int64 v11; // rdx
  __int64 v12; // rax
  int v13; // eax
  __int64 v14; // rdx
  __int64 v15; // rax
  UFG::qMatrix44 inputOutupMatrix; // [rsp+30h] [rbp-98h] BYREF
  UFG::qMatrix44 v17; // [rsp+70h] [rbp-58h] BYREF

  if ( sEnableSyncFeet )
  {
    mNext = creature->mPoseDrivers.mNode.mNext;
    v6 = 0i64;
    p_m_SafePointerList = &creature->m_SafePointerList;
    v8 = (__int64)&mNext[-1];
    v9 = 0i64;
    if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != p_m_SafePointerList )
    {
      do
      {
        if ( !v6 && *(_DWORD *)(v8 + 44) == UFG::sLeftLegIKNameUID )
          v6 = v8;
        if ( !v9 && *(_DWORD *)(v8 + 44) == UFG::sRightLegIKNameUID )
          v9 = v8;
        v8 = *(_QWORD *)(v8 + 24) - 16i64;
      }
      while ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != p_m_SafePointerList );
      if ( v6 && v9 )
      {
        v10 = (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v6 + 112i64))(
                v6,
                UFG::sLeftLegIKNameUID,
                UFG::sRightLegIKNameUID);
        if ( (unsigned __int8)UFG::adJustEffectorToGround(creature, v10, &inputOutupMatrix, layer, legUp) )
        {
          v12 = *(_QWORD *)v6;
          LOBYTE(v11) = 1;
          inputOutupMatrix.v3.w = 1.0;
          inputOutupMatrix.v3.x = inputOutupMatrix.v3.x + (float)(UFG::qVector3::msDirUp.x * sDownLeg);
          inputOutupMatrix.v3.y = inputOutupMatrix.v3.y + (float)(UFG::qVector3::msDirUp.y * sDownLeg);
          inputOutupMatrix.v3.z = inputOutupMatrix.v3.z + (float)(UFG::qVector3::msDirUp.z * sDownLeg);
          (*(void (__fastcall **)(__int64, __int64))(v12 + 88))(v6, v11);
          (*(void (__fastcall **)(__int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v6 + 120i64))(
            v6,
            &creature->mPose,
            &inputOutupMatrix);
        }
        v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 112i64))(v9);
        if ( (unsigned __int8)UFG::adJustEffectorToGround(creature, v13, &v17, layer, legUp) )
        {
          v15 = *(_QWORD *)v9;
          LOBYTE(v14) = 1;
          v17.v3.w = 1.0;
          v17.v3.x = v17.v3.x + (float)(UFG::qVector3::msDirUp.x * sDownLeg);
          v17.v3.y = v17.v3.y + (float)(UFG::qVector3::msDirUp.y * sDownLeg);
          v17.v3.z = v17.v3.z + (float)(UFG::qVector3::msDirUp.z * sDownLeg);
          (*(void (__fastcall **)(__int64, __int64))(v15 + 88))(v9, v14);
          (*(void (__fastcall **)(__int64, SkeletalPose *, UFG::qMatrix44 *))(*(_QWORD *)v9 + 120i64))(
            v9,
            &creature->mPose,
            &v17);
        }
        Creature::updateEffectorsToPose(creature);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 88i64))(v6, 0i64);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 88i64))(v9, 0i64);
      }
    }
  }
}

// File Line: 1013
// RVA: 0x5619B0
void __fastcall UFG::WorldContextComponent::UpdateTransformsPost(UFG::WorldContextComponent *this)
{
  UFG::SimComponent *v2; // r14
  UFG::SimObjectProp *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  __int64 v5; // rdx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  bool v8; // zf
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int size; // r11d
  __int64 v11; // r8
  Creature *mCreature; // r15
  float x; // xmm10_4
  float y; // xmm11_4
  __m128 v15; // xmm7
  UFG::CoverPosition *mpCoverPosition; // rcx
  UFG::CoverCornerHandle *p_m_LeftCorner; // rcx
  UFG::CoverCorner *v18; // rax
  float v19; // xmm8_4
  float v20; // xmm9_4
  __m128 z_low; // xmm5
  float v22; // xmm6_4
  __m128 v23; // xmm2
  float v24; // xmm14_4
  float v25; // xmm9_4
  float v26; // xmm8_4
  float v27; // xmm9_4
  float SideOffset; // xmm6_4
  float FrontOffset; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  UFG::qVector4 v32; // xmm1
  UFG::ParkourHandle *m_pPointer; // rbx
  UFG::CoverPosition *v34; // rbx
  UFG::qVector3 *Position; // rax
  float v36; // xmm15_4
  float v37; // xmm6_4
  float z; // xmm9_4
  UFG::qVector3 *Axis; // rax
  float v40; // xmm3_4
  __m128 x_low; // xmm4
  float v42; // xmm5_4
  __m128 v43; // xmm2
  float v44; // xmm10_4
  float v45; // xmm11_4
  float HalfLength; // xmm0_4
  float v47; // xmm6_4
  float v48; // xmm9_4
  float v49; // xmm15_4
  float v50; // xmm0_4
  float v51; // xmm13_4
  UFG::CoverPosition *v52; // rcx
  float v53; // xmm13_4
  __m128 v54; // xmm6
  float v55; // xmm9_4
  __m128 v56; // xmm2
  float v57; // xmm8_4
  float v58; // xmm0_4
  UFG::CoverPosition *v59; // rax
  float v60; // xmm13_4
  float v61; // xmm6_4
  float v62; // xmm9_4
  int v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm0_4
  float m_fDistToLeft; // xmm6_4
  float m_fDistToRight; // xmm9_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  float v71; // xmm9_4
  float v72; // xmm9_4
  float v73; // xmm6_4
  __m128 v74; // xmm9
  float v75; // xmm13_4
  __m128 v76; // xmm2
  float v77; // xmm8_4
  float v78; // xmm0_4
  float v79; // xmm6_4
  bool mSyncPositionOnly; // al
  float v81; // xmm2_4
  int mSyncBoneIndex; // r8d
  bool mSyncPlanar; // al
  int v84; // r8d
  bool mSyncToClosestEndpoint; // al
  bool mSyncXForward; // al
  Render::DebugDrawContext *Context; // rbx
  Render::DebugDrawManager *v88; // rax
  Render::DebugDrawContext *v89; // rdi
  const char *v90; // rax
  UFG::SimComponent *m_pSimComponent; // rax
  char v92; // di
  UFG::SimObjectProp *v93; // rcx
  __int16 v94; // r8
  UFG::CharacterAnimationComponent *v95; // rcx
  UFG::CharacterAnimationComponent *v96; // rax
  unsigned int v97; // r9d
  unsigned int v98; // r11d
  __int64 v99; // r8
  Creature *v100; // rbx
  UFG::SimObject *v101; // rcx
  __int16 v102; // dx
  unsigned int vfptr; // r8d
  unsigned int v104; // r10d
  __int64 v105; // rdx
  unsigned int v106; // r8d
  unsigned int v107; // r10d
  unsigned int v108; // r8d
  unsigned int v109; // r10d
  float v110; // xmm2_4
  UFG::CollisionLayers v111; // edx
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  bool *p_mbSyncingCoverParkour; // rsi
  bool *i; // rbx
  bool fSegmentLength; // [rsp+28h] [rbp-C8h]
  float fLeftConstraint; // [rsp+30h] [rbp-C0h]
  char fRightConstraint; // [rsp+38h] [rbp-B8h]
  bool syncPositionOnly; // [rsp+40h] [rbp-B0h]
  bool syncPositionOnlya; // [rsp+40h] [rbp-B0h]
  bool syncForward; // [rsp+48h] [rbp-A8h]
  bool syncClosestEndPoint; // [rsp+50h] [rbp-A0h]
  bool syncClosestEndPointa; // [rsp+50h] [rbp-A0h]
  bool syncPlanar; // [rsp+58h] [rbp-98h]
  bool syncPlanara; // [rsp+58h] [rbp-98h]
  UFG::qVector3 p1; // [rsp+60h] [rbp-90h] BYREF
  UFG::qVector4 result; // [rsp+70h] [rbp-80h] BYREF
  float v127; // [rsp+80h] [rbp-70h]
  UFG::qVector3 v128; // [rsp+88h] [rbp-68h] BYREF
  UFG::qMatrix44 outMatrix; // [rsp+A0h] [rbp-50h] BYREF
  float vars0; // [rsp+1C0h] [rbp+D0h] BYREF
  void *retaddr; // [rsp+1C8h] [rbp+D8h] BYREF
  float v132; // [rsp+1D0h] [rbp+E0h]
  float v133; // [rsp+1D8h] [rbp+E8h]

  if ( (this->m_Flags & 2) != 0 )
    return;
  v2 = 0i64;
  if ( !this->mSyncLatchedHandle
    && !this->mbSyncingCoverParkour
    && !this->mbSyncingCoverLCorner
    && !this->mbSyncingCoverRCorner )
  {
    goto LABEL_80;
  }
  m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_80;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_11;
    }
    goto LABEL_29;
  }
  if ( m_Flags < 0 )
  {
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_11;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_29;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
LABEL_28:
    v5 = UFG::CharacterAnimationComponent::_TypeUID;
    m_pComponent = ComponentOfType;
    goto LABEL_29;
  }
  v8 = (m_Flags & 0x1000) == 0;
  v5 = UFG::CharacterAnimationComponent::_TypeUID;
  if ( v8 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pSimObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_28;
  }
  mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
  size = m_pSimObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_11:
    m_pComponent = 0i64;
    goto LABEL_29;
  }
  v11 = (__int64)&m_pSimObject->m_Components.p[mComponentTableEntryCount];
  while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    v11 += 16i64;
    if ( mComponentTableEntryCount >= size )
    {
      m_pComponent = 0i64;
      goto LABEL_29;
    }
  }
  m_pComponent = *(UFG::CharacterAnimationComponent **)v11;
LABEL_29:
  if ( !m_pComponent )
    goto LABEL_81;
  mCreature = m_pComponent->mCreature;
  if ( !mCreature )
    return;
  x = UFG::qVector3::msDirRight.x;
  y = UFG::qVector3::msDirRight.y;
  v15.m128_i32[0] = LODWORD(UFG::qVector3::msDirRight.z);
  if ( this->mSyncLatchedHandle )
  {
    m_pPointer = this->mParkourHandle.m_pPointer;
  }
  else
  {
    if ( !this->mbSyncingCoverParkour )
    {
      mpCoverPosition = this->mpCoverPosition;
      if ( mpCoverPosition )
      {
        if ( this->mbSyncingCoverLCorner )
          p_m_LeftCorner = &mpCoverPosition->m_LeftCorner;
        else
          p_m_LeftCorner = &mpCoverPosition->m_RightCorner;
        v18 = UFG::CoverCornerHandle::Get(p_m_LeftCorner);
        if ( !v18 || this->mSyncBoneIndex < 0 )
          goto LABEL_80;
        UFG::CoverCorner::GetSyncMatrix(v18, &outMatrix);
        this->mpCoverPosition->vfptr->GetWallNormal(this->mpCoverPosition, &p1);
        z_low = (__m128)LODWORD(p1.z);
        v19 = 0.0;
        v20 = (float)(p1.y * UFG::qVector3::msDirUp.z) - (float)(p1.z * UFG::qVector3::msDirUp.y);
        z_low.m128_f32[0] = (float)(p1.z * UFG::qVector3::msDirUp.x) - (float)(p1.x * UFG::qVector3::msDirUp.z);
        v22 = (float)(p1.x * UFG::qVector3::msDirUp.y) - (float)(p1.y * UFG::qVector3::msDirUp.x);
        v23 = z_low;
        v23.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v20 * v20))
                        + (float)(v22 * v22);
        if ( v23.m128_f32[0] != 0.0 )
          v19 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
        v24 = v19 * v20;
        v25 = v19;
        v26 = v19 * v22;
        v27 = v25 * z_low.m128_f32[0];
        SideOffset = UFG::CoverObjectBase::GetSideOffset(this->mpCoverPosition);
        FrontOffset = UFG::CoverObjectBase::GetFrontOffset(this->mpCoverPosition);
        v30 = outMatrix.v3.x + (float)(FrontOffset * p1.x);
        v31 = outMatrix.v3.y + (float)(FrontOffset * p1.y);
        if ( this->mbSyncingCoverLCorner )
          LODWORD(SideOffset) ^= _xmm[0];
        outMatrix.v3.w = (float)(outMatrix.v3.w + 1.0) + 1.0;
        outMatrix.v3.z = (float)(outMatrix.v3.z + (float)(FrontOffset * p1.z)) + (float)(SideOffset * v26);
        v32 = outMatrix.v2;
        this->mWorldAnchor.v0 = outMatrix.v0;
        outMatrix.v3.x = v30 + (float)(SideOffset * v24);
        outMatrix.v3.y = v31 + (float)(SideOffset * v27);
        this->mWorldAnchor.v1 = outMatrix.v1;
        this->mWorldAnchor.v2 = v32;
        this->mWorldAnchor.v3 = outMatrix.v3;
LABEL_79:
        Creature::Attach(mCreature, this->mSyncBoneIndex, 2, &this->mWorldAnchor, this->mBlendWeight);
        LODWORD(result.x) = LODWORD(x) ^ _xmm[0];
        LODWORD(result.y) = LODWORD(y) ^ _xmm[0];
        LODWORD(result.z) = v15.m128_i32[0] ^ _xmm[0];
        UFG::syncHands(mCreature, (UFG::qVector3 *)&result.z, (UFG::qVector3 *)&result);
LABEL_80:
        v5 = UFG::CharacterAnimationComponent::_TypeUID;
        goto LABEL_81;
      }
      goto LABEL_81;
    }
    v34 = this->mpCoverPosition;
    if ( !v34 )
      goto LABEL_81;
    m_pPointer = v34->m_pParkourHandle.m_pPointer;
  }
  if ( m_pPointer && this->mSyncBoneIndex >= 0 )
  {
    Position = UFG::ParkourHandle::GetPosition(m_pPointer, (UFG::qVector3 *)&result);
    v36 = Position->x;
    v37 = Position->y;
    z = Position->z;
    Axis = UFG::ParkourHandle::GetAxis(m_pPointer, (UFG::qVector3 *)&result);
    v40 = Axis->y;
    x_low = (__m128)LODWORD(Axis->x);
    v42 = Axis->z;
    v43 = x_low;
    v43.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
    if ( v43.m128_f32[0] == 0.0 )
    {
      v15 = 0i64;
    }
    else
    {
      v15 = (__m128)(unsigned int)FLOAT_1_0;
      v15.m128_f32[0] = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
    }
    v44 = v15.m128_f32[0];
    v45 = v15.m128_f32[0];
    v15.m128_f32[0] = v15.m128_f32[0] * v42;
    x = v44 * x_low.m128_f32[0];
    y = v45 * v40;
    HalfLength = UFG::ParkourHandle::GetHalfLength(m_pPointer);
    v47 = v37 + (float)(y * HalfLength);
    v48 = z + (float)(v15.m128_f32[0] * HalfLength);
    v49 = v36 + (float)(x * HalfLength);
    v132 = v47;
    v133 = v48;
    v50 = UFG::ParkourHandle::GetHalfLength(m_pPointer);
    LODWORD(retaddr) = 0;
    vars0 = 0.0;
    v51 = v50 * 2.0;
    result.x = v50 * 2.0;
    if ( this->mbSyncingCoverParkour )
    {
      v52 = this->mpCoverPosition;
      if ( v52 && !this->mSyncPositionLocked )
      {
        if ( this->mLockSyncPosition )
          this->mSyncPositionLocked = 1;
        if ( v52->m_bInbetweenParkourLine )
        {
          v54 = (__m128)LODWORD(v52->m_vInbetweenParkourAxis.z);
          v53 = (float)(v52->m_vInbetweenParkourAxis.y * UFG::qVector3::msDirUp.z)
              - (float)(v54.m128_f32[0] * UFG::qVector3::msDirUp.y);
          v54.m128_f32[0] = (float)(v54.m128_f32[0] * UFG::qVector3::msDirUp.x)
                          - (float)(v52->m_vInbetweenParkourAxis.x * UFG::qVector3::msDirUp.z);
          v55 = (float)(v52->m_vInbetweenParkourAxis.x * UFG::qVector3::msDirUp.y)
              - (float)(v52->m_vInbetweenParkourAxis.y * UFG::qVector3::msDirUp.x);
          v56 = v54;
          v56.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v53 * v53))
                          + (float)(v55 * v55);
          if ( v56.m128_f32[0] == 0.0 )
            v57 = 0.0;
          else
            v57 = 1.0 / _mm_sqrt_ps(v56).m128_f32[0];
          v58 = UFG::CoverObjectBase::GetFrontOffset(v52);
          v59 = this->mpCoverPosition;
          v60 = (float)((float)(v53 * v57) * v58) + v59->m_vInbetweenParkourPosition.x;
          v61 = (float)((float)(v54.m128_f32[0] * v57) * v58) + v59->m_vInbetweenParkourPosition.y;
          v62 = (float)((float)(v55 * v57) * v58) + v59->m_vInbetweenParkourPosition.z;
          v63 = LODWORD(v59->m_vInbetweenParkourAxis.y) ^ _xmm[0];
          LODWORD(p1.x) = LODWORD(v59->m_vInbetweenParkourAxis.x) ^ _xmm[0];
          v64 = v59->m_vInbetweenParkourAxis.z;
          result.x = v60;
          syncPlanar = this->mSyncPlanar;
          syncClosestEndPoint = this->mSyncToClosestEndpoint;
          LOBYTE(v59) = this->mSyncXForward;
          LODWORD(p1.z) = LODWORD(v64) ^ _xmm[0];
          result.y = v61;
          syncForward = (char)v59;
          LOBYTE(v59) = this->mSyncPositionOnly;
          result.z = v62;
          LODWORD(p1.y) = v63;
          syncPositionOnly = (char)v59;
          fRightConstraint = LOBYTE(FLOAT_N3_4028235e38);
          fLeftConstraint = FLOAT_N3_4028235e38;
          v65 = FLOAT_2_0;
        }
        else
        {
          if ( v52->m_pParkourHandle.m_pPointer )
          {
            m_fDistToLeft = v52->m_fDistToLeft;
            m_fDistToRight = v52->m_fDistToRight;
            v68 = UFG::ParkourHandle::GetHalfLength(v52->m_pParkourHandle.m_pPointer);
            v52 = this->mpCoverPosition;
            v69 = v68 + v52->m_fParkourTVal;
            v70 = (float)((float)(v68 * 2.0) - v69) - m_fDistToRight;
            v71 = m_fDistToRight + m_fDistToLeft;
            *(float *)&retaddr = v69 - m_fDistToLeft;
            vars0 = v70;
            if ( v71 < 0.0 )
            {
              v72 = v71 * 0.5;
              *(float *)&retaddr = (float)(v69 - m_fDistToLeft) + v72;
              vars0 = v70 + v72;
            }
          }
          v74 = v15;
          v73 = (float)(y * UFG::qVector3::msDirUp.z) - (float)(v15.m128_f32[0] * UFG::qVector3::msDirUp.y);
          v74.m128_f32[0] = (float)(v15.m128_f32[0] * UFG::qVector3::msDirUp.x) - (float)(x * UFG::qVector3::msDirUp.z);
          v76 = v74;
          v75 = (float)(x * UFG::qVector3::msDirUp.y) - (float)(y * UFG::qVector3::msDirUp.x);
          v76.m128_f32[0] = (float)((float)(v74.m128_f32[0] * v74.m128_f32[0]) + (float)(v73 * v73))
                          + (float)(v75 * v75);
          if ( v76.m128_f32[0] == 0.0 )
            v77 = 0.0;
          else
            v77 = 1.0 / _mm_sqrt_ps(v76).m128_f32[0];
          v78 = UFG::CoverObjectBase::GetFrontOffset(v52);
          syncPlanar = this->mSyncPlanar;
          v79 = (float)(v73 * v77) * v78;
          syncClosestEndPoint = this->mSyncToClosestEndpoint;
          syncForward = this->mSyncXForward;
          mSyncPositionOnly = this->mSyncPositionOnly;
          result.z = v133 + (float)(v78 * (float)(v75 * v77));
          LODWORD(p1.x) = LODWORD(x) ^ _xmm[0];
          v81 = v132 + (float)(v78 * (float)(v74.m128_f32[0] * v77));
          syncPositionOnly = mSyncPositionOnly;
          LODWORD(p1.z) = v15.m128_i32[0] ^ _xmm[0];
          LODWORD(p1.y) = LODWORD(y) ^ _xmm[0];
          fRightConstraint = LOBYTE(vars0);
          v65 = result.x;
          fLeftConstraint = *(float *)&retaddr;
          result.x = v49 + v79;
          result.y = v81;
        }
        mSyncBoneIndex = this->mSyncBoneIndex;
        result.w = 1.0;
        UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(
          &this->mWorldAnchor,
          mCreature,
          mSyncBoneIndex,
          &result,
          &p1,
          v65,
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
      if ( !this->mSyncPositionLocked )
      {
        if ( this->mLockSyncPosition )
          this->mSyncPositionLocked = 1;
        getParkourEdgeConstraints(
          m_pPointer,
          this->mSyncLeftEdge,
          this->mSyncRightEdge,
          this->mDistanceFromEdge,
          this->mDistanceFromEdge,
          (float *)&retaddr,
          &vars0);
        mSyncPlanar = this->mSyncPlanar;
        result.x = v49;
        v84 = this->mSyncBoneIndex;
        syncPlanara = mSyncPlanar;
        mSyncToClosestEndpoint = this->mSyncToClosestEndpoint;
        result.y = v47;
        result.z = v48;
        LODWORD(p1.x) = LODWORD(x) ^ _xmm[0];
        LODWORD(p1.y) = LODWORD(y) ^ _xmm[0];
        syncClosestEndPointa = mSyncToClosestEndpoint;
        mSyncXForward = this->mSyncXForward;
        LODWORD(p1.z) = v15.m128_i32[0] ^ _xmm[0];
        syncPositionOnlya = this->mSyncPositionOnly;
        result.w = 1.0;
        UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(
          &this->mWorldAnchor,
          mCreature,
          v84,
          &result,
          &p1,
          v51,
          *(float *)&retaddr,
          SLOBYTE(vars0),
          syncPositionOnlya,
          mSyncXForward,
          syncClosestEndPointa,
          syncPlanara);
      }
      if ( UFG::WorldContextComponent::s_DrawParkourSensing )
      {
        Creature::GetTransform(mCreature, this->mSyncBoneIndex, &outMatrix);
        fSegmentLength = this->mSyncToClosestEndpoint;
        LODWORD(v128.x) = LODWORD(x) ^ _xmm[0];
        p1.x = outMatrix.v3.x;
        p1.y = outMatrix.v3.y;
        p1.z = outMatrix.v3.z;
        LODWORD(v128.z) = v15.m128_i32[0] ^ _xmm[0];
        LODWORD(v128.y) = LODWORD(y) ^ _xmm[0];
        result.w = v47;
        v127 = v48;
        result.x = outMatrix.v3.x;
        result.y = outMatrix.v3.y;
        result.z = outMatrix.v3.z;
        constrainPos(&p1, (UFG::qVector3 *)&result, (UFG::qVector3 *)&result.z, &v128, v51, fSegmentLength);
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                2u);
        v88 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        result.x = outMatrix.v3.x;
        result.y = outMatrix.v3.y;
        result.z = outMatrix.v3.z;
        v89 = (Render::DebugDrawContext *)v88;
        Render::DebugDrawContext::DrawLine(
          Context,
          (UFG::qVector3 *)&result,
          &p1,
          &UFG::qColour::Orange,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        result.x = p1.x;
        result.y = p1.y;
        result.z = sToTextOffsetZ + p1.z;
        Render::DebugDrawContext::DrawLine(
          Context,
          &p1,
          (UFG::qVector3 *)&result,
          &UFG::qColour::Orange,
          &UFG::qMatrix44::msIdentity,
          0i64,
          0);
        v90 = "N";
        result.x = p1.x;
        result.y = p1.y;
        result.z = sToTextOffsetZ + p1.z;
        if ( this->mSyncPlanar )
          v90 = "P";
        Render::DebugDrawContext::DrawText(v89, (UFG::qVector3 *)&result, &UFG::qColour::Orange, "Syncing:%s", v90);
      }
    }
    goto LABEL_79;
  }
LABEL_81:
  m_pSimComponent = this->mCharacterPhysicsComponent.m_pSimComponent;
  v92 = 0;
  if ( m_pSimComponent && m_pSimComponent[9].m_TypeUID )
  {
    v92 = 1;
  }
  else if ( !this->mSyncFeet )
  {
    goto LABEL_142;
  }
  v93 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v93 )
    goto LABEL_142;
  v94 = v93->m_Flags;
  if ( (v94 & 0x4000) != 0 )
  {
    v95 = (UFG::CharacterAnimationComponent *)v93->m_Components.p[9].m_pComponent;
    if ( !v95
      || (((unsigned int)v5 ^ v95->m_TypeUID) & 0xFE000000) != 0
      || ((unsigned int)v5 & ~v95->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_90;
    }
    goto LABEL_108;
  }
  if ( v94 < 0 )
  {
    v95 = (UFG::CharacterAnimationComponent *)v93->m_Components.p[9].m_pComponent;
    if ( !v95 || (((unsigned int)v5 ^ v95->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_90;
    if ( ((unsigned int)v5 & ~v95->m_TypeUID & 0x1FFFFFF) != 0 )
      v95 = 0i64;
    goto LABEL_108;
  }
  if ( (v94 & 0x2000) != 0 )
  {
    v96 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v93);
LABEL_107:
    v95 = v96;
    goto LABEL_108;
  }
  if ( (v94 & 0x1000) == 0 )
  {
    v96 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(v93, v5);
    goto LABEL_107;
  }
  v97 = v93->mComponentTableEntryCount;
  v98 = v93->m_Components.size;
  if ( v97 >= v98 )
  {
LABEL_90:
    v95 = 0i64;
    goto LABEL_108;
  }
  v99 = (__int64)&v93->m_Components.p[v97];
  while ( (*(_DWORD *)(v99 + 8) & 0xFE000000) != (v5 & 0xFE000000)
       || ((unsigned int)v5 & ~*(_DWORD *)(v99 + 8) & 0x1FFFFFF) != 0 )
  {
    ++v97;
    v99 += 16i64;
    if ( v97 >= v98 )
    {
      v95 = 0i64;
      goto LABEL_108;
    }
  }
  v95 = *(UFG::CharacterAnimationComponent **)v99;
LABEL_108:
  if ( v95 )
  {
    v100 = v95->mCreature;
    if ( v100 )
    {
      v101 = this->m_pSimObject;
      if ( !v101 )
        goto LABEL_138;
      v102 = v101->m_Flags;
      if ( (v102 & 0x4000) != 0 )
      {
        v2 = v101->m_Components.p[44].m_pComponent;
        goto LABEL_136;
      }
      if ( v102 < 0 )
      {
        vfptr = (unsigned int)v101[1].vfptr;
        v104 = v101->m_Components.size;
        if ( vfptr >= v104 )
          goto LABEL_136;
        v105 = (__int64)&v101->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v105 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v105 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v105 += 16i64;
          if ( vfptr >= v104 )
            goto LABEL_136;
        }
        goto LABEL_120;
      }
      if ( (v102 & 0x2000) != 0 )
      {
        v106 = (unsigned int)v101[1].vfptr;
        v107 = v101->m_Components.size;
        if ( v106 < v107 )
        {
          v105 = (__int64)&v101->m_Components.p[v106];
          while ( (*(_DWORD *)(v105 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v105 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v106;
            v105 += 16i64;
            if ( v106 >= v107 )
              goto LABEL_136;
          }
LABEL_120:
          v2 = *(UFG::SimComponent **)v105;
        }
      }
      else if ( (v102 & 0x1000) != 0 )
      {
        v108 = (unsigned int)v101[1].vfptr;
        v109 = v101->m_Components.size;
        if ( v108 < v109 )
        {
          v105 = (__int64)&v101->m_Components.p[v108];
          while ( (*(_DWORD *)(v105 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v105 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v108;
            v105 += 16i64;
            if ( v108 >= v109 )
              goto LABEL_136;
          }
          goto LABEL_120;
        }
      }
      else
      {
        v2 = UFG::SimObject::GetComponentOfType(v101, UFG::CharacterOccupantComponent::_TypeUID);
      }
LABEL_136:
      if ( v2 )
      {
        v110 = sUpLegVehicle;
        v111 = USER_RAYCAST_LAYER_3;
LABEL_141:
        UFG::syncFeet(v100, v111, v110);
        goto LABEL_142;
      }
LABEL_138:
      v111 = USER_RAYCAST_LAYER_1;
      if ( v92 )
        v110 = sUpLegGrapple;
      else
        v110 = sUpLeg;
      goto LABEL_141;
    }
  }
LABEL_142:
  mNext = this->mAttachments.mNode.mNext;
  p_mbSyncingCoverParkour = &this->mbSyncingCoverParkour;
  for ( i = (bool *)&mNext[-1].mNext; i != p_mbSyncingCoverParkour; i = (bool *)(*((_QWORD *)i + 2) - 8i64) )
    (*(void (__fastcall **)(bool *, __int64))(*(_QWORD *)i + 16i64))(i, v5);
}ent::_TypeUID);
      }
LABEL_136:
      if ( v2 )
      {
        v110 = sUpLegVehicle;
        v111 = USER_RAYCAST_LAYER_3;
LABEL_141:
        UFG::syncFeet(v100, v111, v110);
        goto LABEL_142;
      }
LABEL_138:
      v111 = USER_RAYCAST_LAYER_1;
      if ( v92 )
        v110 = sUpLegGrapple;
      else
        v110 = sUpLeg;
      goto LABEL_141;
    }
  }
LABEL_142:
  mNext = thi

// File Line: 1324
// RVA: 0x523640
void __fastcall UFG::WorldContextComponent::ConstrainSyncBoneWorldAnchorToLine(
        UFG::qMatrix44 *newWorldAnchor,
        Creature *pCreature,
        int syncBoneIndex,
        UFG::qVector4 *vHandleOrigin,
        UFG::qVector3 *vHandleAxis,
        float fSegmentLength,
        float fLeftConstraint,
        char fRightConstraint,
        bool syncPositionOnly,
        bool syncForward,
        bool syncClosestEndPoint,
        bool syncPlanar)
{
  UFG::qVector3 *v15; // rbx
  float v16; // xmm1_4
  __m128 y_low; // xmm6
  float v18; // xmm15_4
  float v19; // xmm3_4
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm15_4
  float v24; // xmm7_4
  UFG::qVector4 v25; // xmm9
  UFG::qVector4 v26; // xmm14
  float x; // xmm10_4
  float y; // xmm12_4
  float z; // xmm13_4
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm4
  __m128 v33; // xmm11
  __m128 v34; // xmm4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm8_4
  float v38; // xmm9_4
  __m128 v39; // xmm3
  __m128 v40; // xmm2
  float v41; // xmm10_4
  float v42; // xmm3_4
  UFG::qVector4 vSyncPosition; // [rsp+50h] [rbp-A8h] BYREF
  __m128 v44; // [rsp+60h] [rbp-98h]
  _BYTE v45[24]; // [rsp+70h] [rbp-88h]
  __int128 v46; // [rsp+88h] [rbp-70h]
  UFG::qVector4 result; // [rsp+98h] [rbp-60h] BYREF
  UFG::qMatrix44 transform; // [rsp+A8h] [rbp-50h] BYREF
  __m128 v49; // [rsp+E8h] [rbp-10h]
  UFG::qMatrix44 d; // [rsp+F8h] [rbp+0h] BYREF
  UFG::qMatrix44 v51; // [rsp+138h] [rbp+40h] BYREF
  void *retaddr; // [rsp+228h] [rbp+130h]
  UFG::qVector3 *v53; // [rsp+248h] [rbp+150h]
  float v54; // [rsp+248h] [rbp+150h]

  Creature::GetTransform(pCreature, syncBoneIndex, &transform);
  Creature::GetTransform(pCreature, 2, &v51);
  v15 = v53;
  y_low = (__m128)LODWORD(v53->y);
  v16 = y_low.m128_f32[0] * UFG::qVector3::msDirUp.x;
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v53->z * UFG::qVector3::msDirUp.y);
  v20 = y_low;
  v18 = (float)(v53->x * UFG::qVector3::msDirUp.y) - v16;
  v19 = (float)(v53->z * UFG::qVector3::msDirUp.x) - (float)(v53->x * UFG::qVector3::msDirUp.z);
  v20.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v19 * v19)) + (float)(v18 * v18);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
  v22 = y_low.m128_f32[0] * v21;
  v23 = v18 * v21;
  *(_QWORD *)&v45[8] = LODWORD(UFG::qVector3::msDirUp.x);
  *(float *)&v45[16] = UFG::qVector3::msDirUp.z;
  *(_DWORD *)&v45[20] = 0;
  v24 = v21 * v19;
  v44.m128_f32[0] = v22;
  v44.m128_u64[1] = LODWORD(v23);
  v54 = v22;
  v25 = *(UFG::qVector4 *)&v45[8];
  v44.m128_f32[1] = v21 * v19;
  *(float *)&retaddr = v21 * v19;
  *(float *)v45 = (float)(v23 * UFG::qVector3::msDirUp.y) - (float)((float)(v21 * v19) * UFG::qVector3::msDirUp.z);
  *(float *)&v45[4] = (float)(v22 * UFG::qVector3::msDirUp.z) - (float)(v23 * UFG::qVector3::msDirUp.x);
  v46 = _xmm;
  *(float *)&v45[8] = (float)((float)(v21 * v19) * UFG::qVector3::msDirUp.x) - (float)(v22 * UFG::qVector3::msDirUp.y);
  v26 = *(UFG::qVector4 *)v45;
  v49 = v44;
  if ( fRightConstraint )
  {
    x = transform.v3.x;
    y = transform.v3.y;
    z = transform.v3.z;
    vSyncPosition = transform.v3;
  }
  else
  {
    UFG::qInverseAffine(&d, &transform);
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v51.v0, (__m128)v51.v0, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v0, (__m128)v51.v0, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v0, (__m128)v51.v0, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v0, (__m128)v51.v0, 255), (__m128)d.v3));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v51.v1, (__m128)v51.v1, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v1, (__m128)v51.v1, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v1, (__m128)v51.v1, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v1, (__m128)v51.v1, 255), (__m128)d.v3));
    v32 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v51.v2, (__m128)v51.v2, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v2, (__m128)v51.v2, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v2, (__m128)v51.v2, 170), (__m128)d.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v2, (__m128)v51.v2, 255), (__m128)d.v3));
    v25 = *(UFG::qVector4 *)&v45[8];
    v33 = _mm_add_ps(
            _mm_mul_ps((__m128)d.v3, _mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 0), (__m128)d.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 85), (__m128)d.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 170), (__m128)d.v2)));
    y = transform.v3.y;
    d.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v44), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), *(__m128 *)v45)),
                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), *(__m128 *)&v45[8])),
                            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), (__m128)_xmm));
    d.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v44), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), *(__m128 *)v45)),
                              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), *(__m128 *)&v45[8])),
                            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), (__m128)_xmm));
    z = transform.v3.z;
    x = transform.v3.x;
    d.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v44), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), *(__m128 *)v45)),
                              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *(__m128 *)&v45[8])),
                            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), (__m128)_xmm));
    v34 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v44), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), *(__m128 *)v45)),
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), *(__m128 *)&v45[8])),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), (__m128)_xmm));
    vSyncPosition.x = v51.v3.x - v34.m128_f32[0];
    vSyncPosition.y = _mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 85).m128_f32[0]
                    - _mm_shuffle_ps(v34, v34, 85).m128_f32[0];
    vSyncPosition.w = v51.v3.w - _mm_shuffle_ps(v34, v34, 255).m128_f32[0];
    vSyncPosition.z = _mm_shuffle_ps((__m128)v51.v3, (__m128)v51.v3, 170).m128_f32[0]
                    - _mm_shuffle_ps(v34, v34, 170).m128_f32[0];
    v22 = v54;
    v24 = *(float *)&retaddr;
    v26 = *(UFG::qVector4 *)v45;
  }
  UFG::WorldContextComponent::GetClosestAnchorOnLine(
    &result,
    &vSyncPosition,
    vHandleOrigin,
    v15,
    *(float *)&vHandleAxis,
    fSegmentLength,
    fLeftConstraint,
    syncForward,
    syncClosestEndPoint);
  v35 = result.x;
  v36 = result.y;
  v37 = result.z;
  v46 = (__int128)result;
  if ( fRightConstraint )
  {
    if ( syncPositionOnly )
    {
      v39 = (__m128)LODWORD(result.y);
      v38 = result.x - x;
      v39.m128_f32[0] = result.y - y;
      v40 = v39;
      v41 = result.z - z;
      v40.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v41 * v41);
      if ( _mm_sqrt_ps(v40).m128_f32[0] >= 0.000099999997 )
      {
        v42 = (float)((float)(v39.m128_f32[0] * v24) + (float)(v38 * v22)) + (float)(v41 * v23);
        if ( v42 < 0.0 )
        {
          v35 = result.x - (float)(v22 * v42);
          v36 = result.y - (float)(v24 * v42);
          v37 = result.z - (float)(v23 * v42);
        }
      }
    }
    v26 = transform.v1;
    v25 = transform.v2;
    v49 = (__m128)transform.v0;
    *(_QWORD *)&v46 = __PAIR64__(LODWORD(v36), LODWORD(v35));
    *((_QWORD *)&v46 + 1) = LODWORD(v37) | 0x3F80000000000000i64;
  }
  newWorldAnchor->v0 = (UFG::qVector4)v49;
  newWorldAnchor->v1 = v26;
  newWorldAnchor->v2 = v25;
  newWorldAnchor->v3 = (UFG::qVector4)v46;
}

// File Line: 1425
// RVA: 0x52B2E0
UFG::qVector4 *__fastcall UFG::WorldContextComponent::GetClosestAnchorOnLine(
        UFG::qVector4 *result,
        UFG::qVector4 *vSyncPosition,
        UFG::qVector4 *vHandleOrigin,
        UFG::qVector3 *vHandleAxis,
        float fSegmentLength,
        float fLeftConstraint,
        float fRightConstraint,
        bool syncToClosestEndpoint,
        bool syncPlanar)
{
  float z; // xmm8_4
  float x; // xmm9_4
  float v11; // xmm6_4
  __m128 y_low; // xmm10
  float y; // xmm7_4
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

  z = vHandleAxis->z;
  x = vHandleAxis->x;
  v11 = vHandleOrigin->x;
  y_low = (__m128)LODWORD(vHandleAxis->y);
  y = vHandleOrigin->y;
  v17 = y_low;
  v14 = (__m128)(unsigned int)FLOAT_1_0;
  v14.m128_f32[0] = 1.0 - (float)(z * z);
  v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
  v16 = 0.0;
  v17.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
  if ( v17.m128_f32[0] != 0.0 )
    v16 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
  v18 = (float)((float)((float)(y_low.m128_f32[0] * v16) * (float)(vSyncPosition->y - y))
              + (float)((float)(x * v16) * (float)(vSyncPosition->x - vHandleOrigin->x)))
      * v15;
  if ( syncToClosestEndpoint )
  {
    if ( (float)(v18 / fSegmentLength) < 0.5 )
    {
      v20 = vHandleOrigin->z;
      result->x = v11;
      result->y = y;
      result->z = v20;
      result->w = vHandleOrigin->w;
    }
    else
    {
      v19 = vHandleOrigin->w + 1.0;
      result->z = (float)(z * fSegmentLength) + vHandleOrigin->z;
      result->x = v11 + (float)(x * fSegmentLength);
      result->y = y + (float)(y_low.m128_f32[0] * fSegmentLength);
      result->w = v19;
    }
  }
  else
  {
    v21 = vHandleOrigin->z;
    v22 = vHandleOrigin->w + 1.0;
    result->w = v22;
    result->x = v11 + (float)(x * v18);
    result->z = v21 + (float)(z * v18);
    result->y = y + (float)(y_low.m128_f32[0] * v18);
    if ( v18 >= fRightConstraint )
    {
      v26 = fSegmentLength - fLeftConstraint;
      if ( v18 <= (float)(fSegmentLength - fLeftConstraint) )
        goto LABEL_12;
      v25 = v21 + (float)(v26 * z);
      v23 = v11 + (float)(v26 * x);
      v24 = y + (float)(v26 * y_low.m128_f32[0]);
    }
    else
    {
      v23 = v11 + (float)(x * fRightConstraint);
      v24 = y + (float)(y_low.m128_f32[0] * fRightConstraint);
      v25 = v21 + (float)(z * fRightConstraint);
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
  UFG::SimObjectProp *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v5; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx
  Creature *mCreature; // rcx

  this->mSyncLatchedHandle = 0;
  *(_WORD *)&this->mbSyncingCoverLCorner = 0;
  this->mbSyncingCoverParkour = 0;
  m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !m_pSimObject )
    return;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || (m_TypeUID = m_pComponent->m_TypeUID,
          ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0)
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
LABEL_6:
      m_pComponent = 0i64;
    }
  }
  else
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      if ( m_pComponent )
      {
        v5 = m_pComponent->m_TypeUID;
        if ( ((v5 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v5 & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_24;
        }
      }
      goto LABEL_6;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
        size = m_pSimObject->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          v9 = (__int64)&m_pSimObject->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v9 += 16i64;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_6;
          }
          m_pComponent = *(UFG::CharacterAnimationComponent **)v9;
          goto LABEL_24;
        }
        goto LABEL_6;
      }
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pSimObject,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    m_pComponent = ComponentOfType;
  }
LABEL_24:
  if ( m_pComponent )
  {
    mCreature = m_pComponent->mCreature;
    if ( mCreature )
      Creature::MakeUpright(mCreature, 0.0);
  }
}

// File Line: 1503
// RVA: 0x5224E0
void __fastcall UFG::WorldContextComponent::AttachTo(
        UFG::WorldContextComponent *this,
        UFG::SimObject *simObject,
        UFG::TransformNodeComponent *transformNodeComponent,
        int attachmentBoneID,
        float blendIn,
        bool positionOnly,
        bool positionXY,
        bool useRubberBand)
{
  bool *p_mNext; // rax
  UFG::SimObjectProp *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::CharacterAnimationComponent *m_pComponent; // rsi
  unsigned int m_TypeUID; // ecx
  unsigned int v18; // edx
  unsigned int v19; // eax
  UFG::CharacterAnimationComponent *v20; // rax
  unsigned int v21; // ecx
  unsigned int v22; // r8d
  UFG::SimComponentHolder *v23; // r11
  UFG::allocator::free_link *v24; // rax
  __int64 v25; // rax
  __int64 v26; // r8
  UFG::qNode<Attachment,Attachment> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  __int64 *v32; // rdx
  __int64 v33; // rcx
  _QWORD *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v45; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rax
  __int16 v47; // cx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v51; // rdx
  unsigned int v52; // r8d
  unsigned int v53; // r9d
  unsigned int v54; // r8d
  unsigned int v55; // r9d
  unsigned int v56; // r8d
  unsigned int v57; // r9d

  if ( attachmentBoneID == -1 )
    return;
  p_mNext = (bool *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext == &this->mbSyncingCoverParkour )
  {
LABEL_5:
    m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
    if ( !m_pSimObject )
      return;
    m_Flags = m_pSimObject->m_Flags;
    ComponentOfType = 0i64;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      if ( m_pComponent )
      {
        m_TypeUID = m_pComponent->m_TypeUID;
        v18 = UFG::CharacterAnimationComponent::_TypeUID;
        v19 = m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_9:
        if ( (v19 & 0xFE000000) != 0 || (v18 & ~m_TypeUID & 0x1FFFFFF) != 0 )
          goto LABEL_11;
LABEL_27:
        if ( !m_pComponent )
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
        mPrev = this->mAttachments.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<Attachment,Attachment> *)(v26 + 8);
        *(_QWORD *)(v26 + 8) = mPrev;
        *(_QWORD *)(v26 + 16) = &this->mAttachments;
        this->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v26 + 8);
        *(_DWORD *)(v26 + 32) = 0;
        v28 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v26 + 40);
        if ( *(_QWORD *)(v26 + 56) )
        {
          v29 = v28->mPrev;
          v30 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v26 + 48);
          v29->mNext = v30;
          v30->mPrev = v29;
          v28->mPrev = v28;
          *(_QWORD *)(v26 + 48) = v26 + 40;
        }
        *(_QWORD *)(v26 + 56) = simObject;
        if ( simObject )
        {
          v31 = simObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v31->mNext = v28;
          v28->mPrev = v31;
          *(_QWORD *)(v26 + 48) = &simObject->m_SafePointerList;
          simObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v28;
        }
        v32 = (__int64 *)(v26 + 64);
        if ( *(_QWORD *)(v26 + 80) )
        {
          v33 = *v32;
          v34 = *(_QWORD **)(v26 + 72);
          *(_QWORD *)(v33 + 8) = v34;
          *v34 = v33;
          *v32 = (__int64)v32;
          *(_QWORD *)(v26 + 72) = v26 + 64;
        }
        *(_QWORD *)(v26 + 80) = 0i64;
        v35 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v26 + 88);
        if ( *(_QWORD *)(v26 + 104) )
        {
          v36 = v35->mPrev;
          v37 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v26 + 96);
          v36->mNext = v37;
          v37->mPrev = v36;
          v35->mPrev = v35;
          *(_QWORD *)(v26 + 96) = v26 + 88;
        }
        *(_QWORD *)(v26 + 104) = m_pSimObject;
        v38 = m_pSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v38->mNext = v35;
        v35->mPrev = v38;
        *(_QWORD *)(v26 + 96) = &m_pSimObject->m_SafePointerList;
        m_pSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v35;
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
        v39 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v26 + 208);
        if ( *(_QWORD *)(v26 + 224) )
        {
          v40 = v39->mPrev;
          v41 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v26 + 216);
          v40->mNext = v41;
          v41->mPrev = v40;
          v39->mPrev = v39;
          *(_QWORD *)(v26 + 216) = v26 + 208;
        }
        *(_QWORD *)(v26 + 224) = transformNodeComponent;
        if ( transformNodeComponent )
        {
          v42 = transformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
          v42->mNext = v39;
          v39->mPrev = v42;
          *(_QWORD *)(v26 + 216) = &transformNodeComponent->m_SafePointerList;
          transformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v39;
        }
        *(_DWORD *)(v26 + 232) = attachmentBoneID;
        v43 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v26 + 240);
        if ( *(_QWORD *)(v26 + 256) )
        {
          v44 = v43->mPrev;
          v45 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v26 + 248);
          v44->mNext = v45;
          v45->mPrev = v44;
          v43->mPrev = v43;
          *(_QWORD *)(v26 + 248) = v26 + 240;
        }
        *(_QWORD *)(v26 + 256) = m_pComponent;
        v46 = m_pComponent->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v46->mNext = v43;
        v43->mPrev = v46;
        *(_QWORD *)(v26 + 248) = &m_pComponent->m_SafePointerList;
        m_pComponent->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v43;
        *(_BYTE *)(v26 + 24) = positionOnly;
        *(_BYTE *)(v26 + 25) = positionXY;
        *(_BYTE *)(v26 + 28) = useRubberBand;
        v47 = m_pSimObject->m_Flags;
        if ( (v47 & 0x4000) != 0 )
        {
          mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
          size = m_pSimObject->m_Components.size;
          if ( mComponentTableEntryCount >= size )
            goto LABEL_78;
          p = m_pSimObject->m_Components.p;
          while ( 1 )
          {
            v51 = mComponentTableEntryCount;
            if ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_55;
            }
            if ( ++mComponentTableEntryCount >= size )
              goto LABEL_78;
          }
        }
        if ( v47 >= 0 )
        {
          if ( (v47 & 0x2000) != 0 )
          {
            v54 = m_pSimObject->mComponentTableEntryCount;
            v55 = m_pSimObject->m_Components.size;
            if ( v54 < v55 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v51 = v54;
                if ( (p[v54].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && (UFG::RigidBodyComponent::_TypeUID & ~p[v54].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_55;
                }
              }
              while ( ++v54 < v55 );
            }
          }
          else if ( (v47 & 0x1000) != 0 )
          {
            v56 = m_pSimObject->mComponentTableEntryCount;
            v57 = m_pSimObject->m_Components.size;
            if ( v56 < v57 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v51 = v56;
                if ( (p[v56].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                  && (UFG::RigidBodyComponent::_TypeUID & ~p[v56].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_55;
                }
              }
              while ( ++v56 < v57 );
            }
          }
          else
          {
            ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  m_pSimObject,
                                                  UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v52 = m_pSimObject->mComponentTableEntryCount;
          v53 = m_pSimObject->m_Components.size;
          if ( v52 < v53 )
          {
            p = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v51 = v52;
              if ( (p[v52].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                && (UFG::RigidBodyComponent::_TypeUID & ~p[v52].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++v52 >= v53 )
                goto LABEL_78;
            }
LABEL_55:
            ComponentOfType = (UFG::RigidBody *)p[v51].m_pComponent;
          }
        }
LABEL_78:
        if ( ComponentOfType )
          UFG::RigidBody::SetMotionType(ComponentOfType, 0x100u);
        return;
      }
    }
    else
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
          {
            v21 = m_pSimObject->mComponentTableEntryCount;
            v22 = m_pSimObject->m_Components.size;
            if ( v21 < v22 )
            {
              v23 = m_pSimObject->m_Components.p;
              while ( (v23[v21].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                   || (UFG::CharacterAnimationComponent::_TypeUID & ~v23[v21].m_TypeUID & 0x1FFFFFF) != 0 )
              {
                if ( ++v21 >= v22 )
                  goto LABEL_11;
              }
              m_pComponent = (UFG::CharacterAnimationComponent *)v23[v21].m_pComponent;
              goto LABEL_27;
            }
            goto LABEL_11;
          }
          v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        m_pComponent = v20;
        goto LABEL_27;
      }
      m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      if ( m_pComponent )
      {
        m_TypeUID = m_pComponent->m_TypeUID;
        v18 = UFG::CharacterAnimationComponent::_TypeUID;
        v19 = UFG::CharacterAnimationComponent::_TypeUID ^ m_TypeUID;
        goto LABEL_9;
      }
    }
LABEL_11:
    m_pComponent = 0i64;
    goto LABEL_27;
  }
  while ( *((UFG::SimObject **)p_mNext + 7) != simObject )
  {
    p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64);
    if ( p_mNext == &this->mbSyncingCoverParkour )
      goto LABEL_5;
  }
}

// File Line: 1559
// RVA: 0x525A30
void __fastcall UFG::WorldContextComponent::DetachFrom(
        UFG::WorldContextComponent *this,
        UFG::SimObject *simObject,
        UFG::TransformNodeComponent *transformNodeComponent)
{
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  bool *p_mbSyncingCoverParkour; // rcx
  Attachment *p_mNext; // rbx
  UFG::qNode<Attachment,Attachment> *mPrev; // rcx
  UFG::qNode<Attachment,Attachment> *v7; // rax

  mNext = this->mAttachments.mNode.mNext;
  p_mbSyncingCoverParkour = &this->mbSyncingCoverParkour;
  p_mNext = (Attachment *)&mNext[-1].mNext;
  if ( p_mNext != (Attachment *)p_mbSyncingCoverParkour )
  {
    while ( p_mNext->mRootSimObject.m_pPointer != simObject )
    {
      p_mNext = (Attachment *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (Attachment *)p_mbSyncingCoverParkour )
        return;
    }
    ((void (__fastcall *)(Attachment *, UFG::SimObject *, UFG::TransformNodeComponent *))p_mNext->vfptr->OnRemove)(
      p_mNext,
      simObject,
      transformNodeComponent);
    mPrev = p_mNext->mPrev;
    v7 = p_mNext->mNext;
    mPrev->mNext = v7;
    v7->mPrev = mPrev;
    p_mNext->mPrev = &p_mNext->UFG::qNode<Attachment,Attachment>;
    p_mNext->mNext = &p_mNext->UFG::qNode<Attachment,Attachment>;
    p_mNext->vfptr->__vecDelDtor(p_mNext, 1i64);
  }
}

// File Line: 1570
// RVA: 0x5259A0
void __fastcall UFG::WorldContextComponent::DetachAll(UFG::WorldContextComponent *this)
{
  bool *p_mbSyncingCoverParkour; // rsi
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  UFG::qNode<Attachment,Attachment> *mPrev; // rdx
  UFG::qNode<Attachment,Attachment> *v5; // rax

  p_mbSyncingCoverParkour = &this->mbSyncingCoverParkour;
  while ( (bool *)&this->mAttachments.mNode.mNext[-1].mNext != p_mbSyncingCoverParkour )
  {
    mNext = this->mAttachments.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))mNext[-1].mNext[4].mNext)(&mNext[-1].mNext);
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **, __int64))mNext[-1].mNext->mPrev)(&mNext[-1].mNext, 1i64);
  }
}

// File Line: 1596
// RVA: 0x5215D0
void __fastcall UFG::WorldContextComponent::AdvanceParkourNeighbor(
        UFG::WorldContextComponent *this,
        const bool bAdvanceRightNeighbor)
{
  UFG::ParkourHandle *m_pPointer; // rbx
  UFG::ParkourHandle *v4; // rbx

  m_pPointer = this->mParkourHandle.m_pPointer;
  if ( m_pPointer )
  {
    if ( bAdvanceRightNeighbor )
      v4 = m_pPointer->mCachedRightNeighbor.m_pPointer;
    else
      v4 = m_pPointer->mCachedLeftNeighbor.m_pPointer;
    if ( v4 )
    {
      UFG::WorldContextComponent::ClearLatchedParkourHandle(this);
      UFG::WorldContextComponent::LatchParkourHandle(this, v4);
    }
  }
}

