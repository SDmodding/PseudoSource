// File Line: 53
// RVA: 0x154C5E0
void dynamic_initializer_for__sMidLODDistSqr__()
{
  sMidLODDistSqr = sMidLODDist * sMidLODDist;
}

// File Line: 54
// RVA: 0x154C500
void dynamic_initializer_for__sFarLODDistSqr__()
{
  sFarLODDistSqr = sFarLODDist * sFarLODDist;
}

// File Line: 56
// RVA: 0x154C4C0
void dynamic_initializer_for__sExtendedMidLODDistSqr__()
{
  sExtendedMidLODDistSqr = sExtendedMidLODDist * sExtendedMidLODDist;
}

// File Line: 57
// RVA: 0x154C4A0
void dynamic_initializer_for__sExtendedFarLODDistSqr__()
{
  sExtendedFarLODDistSqr = sExtendedFarLODDist * sExtendedFarLODDist;
}

// File Line: 59
// RVA: 0x154C4E0
void dynamic_initializer_for__sFacialLODDistSqr__()
{
  sFacialLODDistSqr = sFacialLODDist * sFacialLODDist;
}

// File Line: 60
// RVA: 0x154C540
void dynamic_initializer_for__sHysteresisSqr__()
{
  sHysteresisSqr = sHysteresis * sHysteresis;
}

// File Line: 73
// RVA: 0x154C7C0
void dynamic_initializer_for__sSkeletalLODDistSqr__()
{
  sSkeletalLODDistSqr = sSkeletalLODDist * sSkeletalLODDist;
}

// File Line: 105
// RVA: 0x1543D60
__int64 dynamic_initializer_for__UFG::AnimationLODComponent::s_AnimationLODComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AnimationLODComponent::s_AnimationLODComponentList__);
}

// File Line: 106
// RVA: 0x1542FB0
__int64 dynamic_initializer_for__UFG::AnimationLODComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AnimationLODComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AnimationLODComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AnimationLODComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 117
// RVA: 0x515F10
void __fastcall UFG::AnimationLODComponent::AnimationLODComponent(
        UFG::AnimationLODComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *mPrev; // rax
  char v4; // cl

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent>;
  this->mNext = &this->UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimationLODComponent::`vftable;
  this->mHasBeenUpdatedOnce = 0;
  this->mUpdatePeriod = 1;
  this->mMinUpdatePeriod = -1;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->mCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>(&this->mFacialActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>(&this->mCompositeDrawableComponent);
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0>::RebindingComponentHandle<UFG::WorldContextComponent,0>(&this->mWorldContextComponent);
  this->mCreature.mPrev = &this->mCreature;
  this->mCreature.mNext = &this->mCreature;
  this->mCreature.m_pPointer = 0i64;
  *((_BYTE *)this + 312) &= 0xF0u;
  this->m_AnimationLockHighLODList.mNode.mPrev = &this->m_AnimationLockHighLODList.mNode;
  this->m_AnimationLockHighLODList.mNode.mNext = &this->m_AnimationLockHighLODList.mNode;
  mPrev = UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev;
  UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&UFG::AnimationLODComponent::s_AnimationLODComponentList;
  UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent>;
  UFG::SimComponent::AddType(this, UFG::AnimationLODComponent::_AnimationLODComponentTypeUID, "AnimationLODComponent");
  v4 = UFG::AnimationLODComponent::sInitStatic;
  if ( !UFG::AnimationLODComponent::sInitStatic )
    v4 = 1;
  UFG::AnimationLODComponent::sInitStatic = v4;
  this->mSequenceID = UFG::AnimationLODComponent::sSequenceIDMaster++;
}

// File Line: 186
// RVA: 0x51AC10
void __fastcall UFG::AnimationLODComponent::~AnimationLODComponent(UFG::AnimationLODComponent *this)
{
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v2; // rdi
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *mPrev; // rcx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *mNext; // rax
  UFG::qSafePointer<Creature,Creature> *p_mCreature; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v10; // rcx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimationLODComponent::`vftable;
  if ( this == UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator )
    UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&this->m_AnimationLockHighLODList);
  p_mCreature = &this->mCreature;
  if ( this->mCreature.m_pPointer )
  {
    v6 = p_mCreature->mPrev;
    v7 = this->mCreature.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mCreature->mPrev = p_mCreature;
    this->mCreature.mNext = &this->mCreature;
  }
  this->mCreature.m_pPointer = 0i64;
  v8 = p_mCreature->mPrev;
  v9 = this->mCreature.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mCreature->mPrev = p_mCreature;
  this->mCreature.mNext = &this->mCreature;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mWorldContextComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCompositeDrawableComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mFacialActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mCharacterAnimationComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 200
// RVA: 0x545F00
UFG::AnimationLODComponent *__fastcall UFG::AnimationLODComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *scene_object_properties,
        bool required)
{
  unsigned int m_NameUID; // edi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = scene_object_properties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x150ui64, "AnimationLODComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::AnimationLODComponent::AnimationLODComponent((UFG::AnimationLODComponent *)v5, m_NameUID);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  m_pSimObject = scene_object_properties->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v10 = 13;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v7, v10);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return (UFG::AnimationLODComponent *)v7;
}

// File Line: 210
// RVA: 0x53D2A0
void __fastcall UFG::AnimationLODComponent::OnAttach(UFG::AnimationLODComponent *this, UFG::SimObject *pSimObject)
{
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mCharacterAnimationComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *p_mFacialActionTreeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *p_mCompositeDrawableComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *p_mWorldContextComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  p_mCharacterAnimationComponent = &this->mCharacterAnimationComponent;
  if ( p_mCharacterAnimationComponent->m_pSimComponent )
  {
    mPrev = p_mCharacterAnimationComponent->mPrev;
    mNext = p_mCharacterAnimationComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCharacterAnimationComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mCharacterAnimationComponent->m_pSimObject = 0i64;
    p_mCharacterAnimationComponent->mNext = p_mCharacterAnimationComponent;
    p_mCharacterAnimationComponent->mPrev = p_mCharacterAnimationComponent;
    goto LABEL_8;
  }
  if ( p_mCharacterAnimationComponent->m_pSimObject
    && (p_mCharacterAnimationComponent->mPrev != p_mCharacterAnimationComponent
     || p_mCharacterAnimationComponent->mNext != p_mCharacterAnimationComponent) )
  {
    v7 = p_mCharacterAnimationComponent->mPrev;
    v8 = p_mCharacterAnimationComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mCharacterAnimationComponent->m_Changed = 1;
  p_mCharacterAnimationComponent->m_pSimObject = pSimObject;
  p_mCharacterAnimationComponent->m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(
    p_mCharacterAnimationComponent,
    pSimObject);
  p_mFacialActionTreeComponent = &this->mFacialActionTreeComponent;
  if ( this->mFacialActionTreeComponent.m_pSimComponent )
  {
    v10 = p_mFacialActionTreeComponent->mPrev;
    v11 = this->mFacialActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mFacialActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mFacialActionTreeComponent.m_pSimObject = 0i64;
    this->mFacialActionTreeComponent.mNext = &this->mFacialActionTreeComponent;
    p_mFacialActionTreeComponent->mPrev = p_mFacialActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->mFacialActionTreeComponent.m_pSimObject
    && (p_mFacialActionTreeComponent->mPrev != p_mFacialActionTreeComponent
     || this->mFacialActionTreeComponent.mNext != &this->mFacialActionTreeComponent) )
  {
    v12 = p_mFacialActionTreeComponent->mPrev;
    v13 = this->mFacialActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mFacialActionTreeComponent.m_Changed = 1;
  this->mFacialActionTreeComponent.m_pSimObject = pSimObject;
  this->mFacialActionTreeComponent.m_TypeUID = UFG::FacialActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &this->mFacialActionTreeComponent,
    pSimObject);
  p_mCompositeDrawableComponent = &this->mCompositeDrawableComponent;
  if ( this->mCompositeDrawableComponent.m_pSimComponent )
  {
    v15 = p_mCompositeDrawableComponent->mPrev;
    v16 = this->mCompositeDrawableComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->mCompositeDrawableComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mCompositeDrawableComponent.m_pSimObject = 0i64;
    this->mCompositeDrawableComponent.mNext = &this->mCompositeDrawableComponent;
    p_mCompositeDrawableComponent->mPrev = p_mCompositeDrawableComponent;
    goto LABEL_22;
  }
  if ( this->mCompositeDrawableComponent.m_pSimObject
    && (p_mCompositeDrawableComponent->mPrev != p_mCompositeDrawableComponent
     || this->mCompositeDrawableComponent.mNext != &this->mCompositeDrawableComponent) )
  {
    v17 = p_mCompositeDrawableComponent->mPrev;
    v18 = this->mCompositeDrawableComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->mCompositeDrawableComponent.m_Changed = 1;
  this->mCompositeDrawableComponent.m_pSimObject = pSimObject;
  this->mCompositeDrawableComponent.m_TypeUID = UFG::CompositeDrawableComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>::BindInternal<UFG::SimObject>(
    &this->mCompositeDrawableComponent,
    pSimObject);
  p_mWorldContextComponent = &this->mWorldContextComponent;
  if ( this->mWorldContextComponent.m_pSimComponent )
  {
    v20 = p_mWorldContextComponent->mPrev;
    v21 = this->mWorldContextComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    this->mWorldContextComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->mWorldContextComponent.m_pSimObject = 0i64;
    this->mWorldContextComponent.mNext = &this->mWorldContextComponent;
    p_mWorldContextComponent->mPrev = p_mWorldContextComponent;
    goto LABEL_29;
  }
  if ( this->mWorldContextComponent.m_pSimObject
    && (p_mWorldContextComponent->mPrev != p_mWorldContextComponent
     || this->mWorldContextComponent.mNext != &this->mWorldContextComponent) )
  {
    v22 = p_mWorldContextComponent->mPrev;
    v23 = this->mWorldContextComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  this->mWorldContextComponent.m_Changed = 1;
  this->mWorldContextComponent.m_pSimObject = pSimObject;
  this->mWorldContextComponent.m_TypeUID = UFG::WorldContextComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0>::BindInternal<UFG::SimObject>(
    &this->mWorldContextComponent,
    pSimObject);
}

// File Line: 220
// RVA: 0x53FC80
void __fastcall UFG::AnimationLODComponent::OnDetach(UFG::AnimationLODComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *p_mCompositeDrawableComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *p_mFacialActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_mCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *p_mWorldContextComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax

  p_mCompositeDrawableComponent = &this->mCompositeDrawableComponent;
  if ( this->mCompositeDrawableComponent.m_pSimComponent )
  {
    mPrev = p_mCompositeDrawableComponent->mPrev;
    mNext = this->mCompositeDrawableComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mCompositeDrawableComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mCompositeDrawableComponent->m_pSimObject = 0i64;
    p_mCompositeDrawableComponent->mNext = p_mCompositeDrawableComponent;
    p_mCompositeDrawableComponent->mPrev = p_mCompositeDrawableComponent;
    goto LABEL_8;
  }
  if ( this->mCompositeDrawableComponent.m_pSimObject
    && (p_mCompositeDrawableComponent->mPrev != p_mCompositeDrawableComponent
     || this->mCompositeDrawableComponent.mNext != &this->mCompositeDrawableComponent) )
  {
    v5 = p_mCompositeDrawableComponent->mPrev;
    v6 = p_mCompositeDrawableComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mFacialActionTreeComponent = &this->mFacialActionTreeComponent;
  p_mCompositeDrawableComponent->m_Changed = 1;
  if ( this->mFacialActionTreeComponent.m_pSimComponent )
  {
    v8 = p_mFacialActionTreeComponent->mPrev;
    v9 = this->mFacialActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mFacialActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mFacialActionTreeComponent.m_pSimObject = 0i64;
    this->mFacialActionTreeComponent.mNext = &this->mFacialActionTreeComponent;
    p_mFacialActionTreeComponent->mPrev = p_mFacialActionTreeComponent;
    goto LABEL_15;
  }
  if ( this->mFacialActionTreeComponent.m_pSimObject
    && (p_mFacialActionTreeComponent->mPrev != p_mFacialActionTreeComponent
     || this->mFacialActionTreeComponent.mNext != &this->mFacialActionTreeComponent) )
  {
    v10 = p_mFacialActionTreeComponent->mPrev;
    v11 = this->mFacialActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->mFacialActionTreeComponent.m_Changed = 1;
  p_mCharacterAnimationComponent = &this->mCharacterAnimationComponent;
  if ( this->mCharacterAnimationComponent.m_pSimComponent )
  {
    v13 = p_mCharacterAnimationComponent->mPrev;
    v14 = this->mCharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->mCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mCharacterAnimationComponent.m_pSimObject = 0i64;
    this->mCharacterAnimationComponent.mNext = &this->mCharacterAnimationComponent;
    p_mCharacterAnimationComponent->mPrev = p_mCharacterAnimationComponent;
    goto LABEL_22;
  }
  if ( this->mCharacterAnimationComponent.m_pSimObject
    && (p_mCharacterAnimationComponent->mPrev != p_mCharacterAnimationComponent
     || this->mCharacterAnimationComponent.mNext != &this->mCharacterAnimationComponent) )
  {
    v15 = p_mCharacterAnimationComponent->mPrev;
    v16 = this->mCharacterAnimationComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->mCharacterAnimationComponent.m_Changed = 1;
  p_mWorldContextComponent = &this->mWorldContextComponent;
  if ( this->mWorldContextComponent.m_pSimComponent )
  {
    v18 = p_mWorldContextComponent->mPrev;
    v19 = this->mWorldContextComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->mWorldContextComponent.m_pSimComponent = 0i64;
    this->mWorldContextComponent.m_pSimObject = 0i64;
    this->mWorldContextComponent.mNext = &this->mWorldContextComponent;
    p_mWorldContextComponent->mPrev = p_mWorldContextComponent;
    this->mWorldContextComponent.m_Changed = 1;
  }
  else
  {
    if ( this->mWorldContextComponent.m_pSimObject
      && (p_mWorldContextComponent->mPrev != p_mWorldContextComponent
       || this->mWorldContextComponent.mNext != &this->mWorldContextComponent) )
    {
      v20 = p_mWorldContextComponent->mPrev;
      v21 = this->mWorldContextComponent.mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      this->mWorldContextComponent.m_pSimObject = 0i64;
      this->mWorldContextComponent.mNext = &this->mWorldContextComponent;
      p_mWorldContextComponent->mPrev = p_mWorldContextComponent;
    }
    this->mWorldContextComponent.m_Changed = 1;
  }
}

// File Line: 427
// RVA: 0x558EA0
void __fastcall UFG::AnimationLODComponent::Update(
        UFG::AnimationLODComponent *this,
        float fDeltaS,
        bool cameraUsingHighZoom,
        UFG::qVector3 *testWorldPosition)
{
  char v5; // bp
  Creature *m_pPointer; // rsi
  UFG::SimComponent *v7; // rsi
  UFG::qSafePointer<Creature,Creature> *p_mCreature; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  char mLowPowerModeEnabled; // r14
  bool v14; // r13
  char v15; // bl
  UFG::WorldContextComponent *m_pSimComponent; // rcx
  bool v17; // al
  char v18; // bl
  bool v19; // r12
  bool v20; // bl
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimObject *v22; // r15
  float v23; // xmm1_4
  char v24; // bl
  UFG::SimComponent *v25; // rcx
  unsigned int v26; // eax
  UFG::SimComponent *v27; // rcx
  unsigned int mMinUpdatePeriod; // ecx
  UFG::SimObject *v29; // rbx
  NISManager *Instance; // rax
  char v31; // r12
  float mBoneUpdateCount; // xmm1_4
  int v33; // r14d
  Render::DebugDrawContext *Context; // r13
  const char *v35; // rcx
  const char *v36; // r15
  const char *v37; // rbx
  __int64 v38; // rax
  const char *v39; // rax
  UFG::qColour *v40; // r8
  float v41; // xmm0_4
  char v42; // [rsp+60h] [rbp-C8h]
  char v43; // [rsp+61h] [rbp-C7h]
  UFG::qVector3 world_position; // [rsp+68h] [rbp-C0h] BYREF
  __int64 v45; // [rsp+78h] [rbp-B0h]
  UFG::qMatrix44 transform; // [rsp+80h] [rbp-A8h] BYREF
  UFG::qString v47; // [rsp+C0h] [rbp-68h] BYREF
  char v48; // [rsp+130h] [rbp+8h]

  v45 = -2i64;
  v5 = 0;
  m_pPointer = this->mCreature.m_pPointer;
  if ( m_pPointer )
  {
LABEL_9:
    v42 = 0;
    LOBYTE(m_pTransformNodeComponent) = 0;
    v48 = 0;
    mLowPowerModeEnabled = m_pPointer->mLowPowerModeEnabled;
    v14 = 0;
    v43 = 0;
    v15 = *((_BYTE *)this + 312);
    v17 = 1;
    if ( (v15 & 8) == 0 && (v15 & 1) == 0 && (v15 & 4) == 0 )
    {
      m_pSimComponent = (UFG::WorldContextComponent *)this->mWorldContextComponent.m_pSimComponent;
      if ( !m_pSimComponent || !UFG::WorldContextComponent::IsSyncing(m_pSimComponent) )
        v17 = 0;
    }
    v18 = v15 & 0xFB;
    *((_BYTE *)this + 312) = v18;
    if ( v17 )
    {
      v19 = 1;
      mLowPowerModeEnabled = 0;
      goto LABEL_45;
    }
    v20 = (v18 & 2) != 0;
    m_pSimObject = this->mCompositeDrawableComponent.m_pSimComponent[19].m_pSimObject;
    if ( m_pSimObject )
    {
      v19 = LOBYTE(m_pSimObject->vfptr) <= 1u;
      if ( LOBYTE(m_pSimObject->vfptr) > 1u )
      {
        mLowPowerModeEnabled = 1;
        LOBYTE(m_pTransformNodeComponent) = 1;
        v48 = 1;
        goto LABEL_45;
      }
    }
    else
    {
      v19 = 1;
    }
    v22 = this->m_pSimObject;
    if ( v22 )
      m_pTransformNodeComponent = v22->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    if ( !m_pTransformNodeComponent )
      goto LABEL_45;
    v19 = 1;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v23 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - testWorldPosition->x)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - testWorldPosition->x))
        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - testWorldPosition->y)
                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - testWorldPosition->y));
    if ( cameraUsingHighZoom
      && v23 < (float)(UFG::PedSpawnManager::msAlwaysActiveDistance * UFG::PedSpawnManager::msAlwaysActiveDistance) )
    {
      v23 = sMidLODDistSqr * 0.25;
    }
    if ( v20 )
    {
      if ( v23 >= sExtendedMidLODDistSqr )
      {
        if ( v23 >= sExtendedFarLODDistSqr )
        {
LABEL_32:
          LOBYTE(m_pTransformNodeComponent) = 1;
          v48 = 1;
          goto LABEL_37;
        }
        goto LABEL_35;
      }
    }
    else if ( v23 >= sMidLODDistSqr )
    {
      if ( v23 >= sFarLODDistSqr )
        goto LABEL_32;
LABEL_35:
      v42 = 1;
    }
    LOBYTE(m_pTransformNodeComponent) = 0;
LABEL_37:
    if ( v23 <= sSkeletalLODDistSqr )
    {
      if ( (float)(sSkeletalLODDistSqr - sHysteresisSqr) > v23 )
        mLowPowerModeEnabled = 0;
    }
    else
    {
      mLowPowerModeEnabled = 1;
    }
    if ( gSkeletonLODEnabled )
      v14 = v23 > sSkeletalLODDistSqr;
    if ( v23 > sFacialLODDistSqr )
    {
      v24 = 1;
      v43 = 1;
LABEL_46:
      m_pPointer->mLowPowerModeEnabled = 1;
      m_pPointer->mPose.mBoneUpdateCount = gSkeletalLODBoneCount;
      if ( this->mFacialActionTreeComponent.m_pSimComponent )
      {
        v25 = this->mFacialActionTreeComponent.m_pSimComponent;
        LOBYTE(v25[7].m_Flags) |= 2u;
        UFG::FacialActionTreeComponent::SyncUpdateList((UFG::FacialActionTreeComponent *)v25);
      }
      if ( v19 )
      {
        if ( (_BYTE)m_pTransformNodeComponent )
        {
          v26 = sFarUpdateFrequency;
        }
        else
        {
          v26 = sMidUpdateFrequency;
          if ( !v42 )
            v26 = 1;
        }
        this->mUpdatePeriod = v26;
        if ( !mLowPowerModeEnabled )
          m_pPointer->mLowPowerModeEnabled = 0;
        if ( !v14 )
          m_pPointer->mPose.mBoneUpdateCount = -1;
        if ( this->mFacialActionTreeComponent.m_pSimComponent && !v24 )
        {
          v27 = this->mFacialActionTreeComponent.m_pSimComponent;
          LOBYTE(v27[7].m_Flags) &= ~2u;
          UFG::FacialActionTreeComponent::SyncUpdateList((UFG::FacialActionTreeComponent *)v27);
        }
      }
      else
      {
        this->mUpdatePeriod = 30;
      }
      mMinUpdatePeriod = this->mMinUpdatePeriod;
      if ( this->mUpdatePeriod < mMinUpdatePeriod )
        mMinUpdatePeriod = this->mUpdatePeriod;
      this->mUpdatePeriod = mMinUpdatePeriod;
      if ( this->mHasBeenUpdatedOnce
        && (v29 = this->m_pSimObject, Instance = NISManager::GetInstance(), !NISManager::IsActiveInNIS(Instance, v29))
        && (UFG::Metrics::msInstance.mSimFrameCount + this->mSequenceID) % this->mUpdatePeriod )
      {
        v31 = 0;
        LOBYTE(this->mCharacterAnimationComponent.m_pSimComponent[3].m_TypeUID) = 0;
      }
      else
      {
        v31 = 1;
        this->mHasBeenUpdatedOnce = 1;
        LOBYTE(this->mCharacterAnimationComponent.m_pSimComponent[3].m_TypeUID) = 1;
      }
      if ( gLODDebug )
      {
        Creature::GetTransform(m_pPointer, &transform);
        transform.v3.z = transform.v3.z + sLODDisplayOffsetZ;
        mBoneUpdateCount = (float)m_pPointer->mPose.mBoneUpdateCount;
        if ( mBoneUpdateCount >= (float)gMaxNumTransformTracks )
          mBoneUpdateCount = (float)gMaxNumTransformTracks;
        v33 = (int)mBoneUpdateCount;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                1u);
        v35 = "NONE";
        v36 = "FALSE";
        if ( this->mFacialActionTreeComponent.m_pSimComponent )
        {
          v37 = "FALSE";
          if ( v43 )
            v37 = "TRUE";
        }
        else
        {
          v37 = "NONE";
        }
        if ( v33 >= 0 )
        {
          UFG::qString::qString(&v47, "%d", (unsigned int)v33);
          v5 = 1;
          v35 = *(const char **)(v38 + 24);
        }
        if ( v48 )
        {
          v39 = "FAR";
        }
        else
        {
          v39 = "NEAR";
          if ( v42 )
            v39 = "MID";
        }
        v40 = &UFG::qColour::Red;
        if ( v31 )
          v40 = &UFG::qColour::Green;
        world_position.x = transform.v3.x;
        world_position.y = transform.v3.y;
        world_position.z = transform.v3.z;
        LODWORD(v41) = _mm_sqrt_ps((__m128)LODWORD(FLOAT_N1_0)).m128_u32[0];
        if ( m_pPointer->mLowPowerModeEnabled )
          v36 = "TRUE";
        Render::DebugDrawContext::DrawText(
          Context,
          &world_position,
          v40,
          "Pixel Coverage     : %5.3f\n"
          "TestDist (RealDist): %6.3f (%6.3f)\n"
          "Update Period      : %d (%s)\n"
          "Low Power          : %s\n"
          "Skeletal LOD       : %s\n"
          "Facial LOD         : %s\n",
          (double)DOUBLE_N1_0,
          v41,
          (double)DOUBLE_N1_0,
          this->mUpdatePeriod,
          v39,
          v36,
          v35,
          v37);
        if ( (v5 & 1) != 0 )
          UFG::qString::~qString(&v47);
      }
      return;
    }
LABEL_45:
    v24 = 0;
    goto LABEL_46;
  }
  v7 = this->mCharacterAnimationComponent.m_pSimComponent;
  if ( v7 )
    m_pPointer = *(Creature **)&v7[2].m_TypeUID;
  else
    m_pPointer = 0i64;
  p_mCreature = &this->mCreature;
  if ( this->mCreature.m_pPointer )
  {
    mPrev = p_mCreature->mPrev;
    mNext = p_mCreature->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCreature->mPrev = p_mCreature;
    p_mCreature->mNext = p_mCreature;
  }
  p_mCreature->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v11 = m_pPointer->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_mCreature;
    p_mCreature->mPrev = v11;
    p_mCreature->mNext = &m_pPointer->m_SafePointerList.mNode;
    m_pPointer->m_SafePointerList.mNode.mPrev = p_mCreature;
    goto LABEL_9;
  }
}

// File Line: 656
// RVA: 0x55DFC0
void __fastcall UFG::AnimationLODComponent::UpdateAll(float sim_time_delta)
{
  bool IsCameraUsingHighZoom; // di
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v2; // rcx
  UFG::qVector3 testWorldPosition; // [rsp+20h] [rbp-28h] BYREF

  IsCameraUsingHighZoom = UFG::IsCameraUsingHighZoom();
  UFG::AnimationLODComponent::getLodTestPoint(&testWorldPosition);
  v2 = UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mNext - 4;
  for ( UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)&UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)(&UFG::AnimationLODComponent::s_AnimationLODComponentList
                                                                                  - 4);
        UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::AnimationLODComponent::Update(
        (UFG::AnimationLODComponent *)v2,
        sim_time_delta,
        IsCameraUsingHighZoom,
        &testWorldPosition);
      v2 = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = 0i64;
}

// File Line: 677
// RVA: 0x53CAD0
void __fastcall UFG::AnimationLODComponent::MakeHighLOD(UFG::AnimationLODComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdx
  __int64 v2; // rdx

  m_pSimComponent = this->mCharacterAnimationComponent.m_pSimComponent;
  this->mUpdatePeriod = 1;
  if ( m_pSimComponent )
  {
    v2 = *(_QWORD *)&m_pSimComponent[2].m_TypeUID;
    if ( v2 )
      *(_DWORD *)(v2 + 240) = -1;
    LOBYTE(this->mCharacterAnimationComponent.m_pSimComponent[3].m_TypeUID) = 1;
    *(_BYTE *)(v2 + 633) = 0;
  }
}

// File Line: 697
// RVA: 0x54C8E0
void __fastcall UFG::AnimationLODComponent::SetExtendedLOD(UFG::AnimationLODComponent *this, bool extended_lod)
{
  *((_BYTE *)this + 312) &= ~2u;
  *((_BYTE *)this + 312) |= 2 * extended_lod;
}

// File Line: 709
// RVA: 0x520910
void __fastcall UFG::AnimationLODComponent::AddAnimationLockHighLODTask(
        UFG::AnimationLODComponent *this,
        AnimationLockHighLODTask *pAnimationLockHighLODTask)
{
  UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *v2; // rdx
  UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *mPrev; // rax

  v2 = &pAnimationLockHighLODTask->UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList>;
  mPrev = this->m_AnimationLockHighLODList.mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &this->m_AnimationLockHighLODList.mNode;
  this->m_AnimationLockHighLODList.mNode.mPrev = v2;
  *((_BYTE *)this + 312) |= 1u;
}

// File Line: 717
// RVA: 0x5686A0
void __fastcall UFG::AnimationLODComponent::getLodTestPoint(UFG::qVector3 *testWorldPosition)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::BaseCameraComponent *mCurrentCamera; // rdi
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  UFG::BaseCameraComponent *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm1_4

  if ( UFG::AnimationLODComponent::sUsePlayerPositionForLODTest )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      y = m_pTransformNodeComponent->mLocalTransform.v3.y;
      z = m_pTransformNodeComponent->mLocalTransform.v3.z;
      testWorldPosition->x = m_pTransformNodeComponent->mLocalTransform.v3.x;
      testWorldPosition->y = y;
      testWorldPosition->z = z;
    }
  }
  else
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    if ( sUseGameCamLOD )
    {
      CurrentBaseCamera = UFG::GetCurrentBaseCamera();
      v8 = CurrentBaseCamera;
      if ( CurrentBaseCamera )
      {
        if ( UFG::SimComponent::IsType(CurrentBaseCamera, UFG::DebugCameraComponent::_DebugCameraComponentTypeUID) )
          v8 = *(UFG::BaseCameraComponent **)&v8[1].m_TypeUID;
        if ( v8 )
          mCurrentCamera = (UFG::BaseCameraComponent *)&v8->mCamera;
      }
    }
    if ( mCurrentCamera )
    {
      v9 = mCurrentCamera->mCamera.mView.v2.y;
      v10 = mCurrentCamera->mCamera.mView.v2.z;
      testWorldPosition->x = mCurrentCamera->mCamera.mView.v2.x;
      testWorldPosition->y = v9;
      testWorldPosition->z = v10;
    }
  }
}

