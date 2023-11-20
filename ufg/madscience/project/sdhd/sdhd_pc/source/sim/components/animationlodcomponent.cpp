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
  return atexit(dynamic_atexit_destructor_for__UFG::AnimationLODComponent::s_AnimationLODComponentList__);
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
void __fastcall UFG::AnimationLODComponent::AnimationLODComponent(UFG::AnimationLODComponent *this, unsigned int name_uid)
{
  UFG::AnimationLODComponent *v2; // rdi
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v3; // rbx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v4; // rax
  char v5; // cl
  UFG::qSafePointer<Creature,Creature> *v6; // [rsp+50h] [rbp+18h]
  UFG::qList<AnimationLockHighLODTask,AnimationLockHighLODList,0,0> *v7; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimationLODComponent::`vftable';
  v2->mHasBeenUpdatedOnce = 0;
  v2->mUpdatePeriod = 1;
  v2->mMinUpdatePeriod = -1;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v2->mCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>(&v2->mFacialActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>(&v2->mCompositeDrawableComponent);
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0>::RebindingComponentHandle<UFG::WorldContextComponent,0>(&v2->mWorldContextComponent);
  v6 = &v2->mCreature;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v2->mCreature.m_pPointer = 0i64;
  *((_BYTE *)v2 + 312) &= 0xF0u;
  v7 = &v2->m_AnimationLockHighLODList;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v4 = UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev;
  UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&UFG::AnimationLODComponent::s_AnimationLODComponentList;
  UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mPrev = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AnimationLODComponent::_AnimationLODComponentTypeUID,
    "AnimationLODComponent");
  v5 = UFG::AnimationLODComponent::sInitStatic;
  if ( !UFG::AnimationLODComponent::sInitStatic )
    v5 = 1;
  UFG::AnimationLODComponent::sInitStatic = v5;
  v2->mSequenceID = UFG::AnimationLODComponent::sSequenceIDMaster++;
}

// File Line: 186
// RVA: 0x51AC10
void __fastcall UFG::AnimationLODComponent::~AnimationLODComponent(UFG::AnimationLODComponent *this)
{
  UFG::AnimationLODComponent *v1; // rbx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v2; // rdi
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v3; // rcx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v4; // rax
  UFG::qSafePointer<Creature,Creature> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v10; // rcx
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AnimationLODComponent::`vftable';
  if ( this == UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator )
    UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>((UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)&v1->m_AnimationLockHighLODList);
  v5 = &v1->mCreature;
  if ( v1->mCreature.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mCreature.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mCreature.mPrev;
  }
  v1->mCreature.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mCreature.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mCreature.mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v1->mCreature.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mWorldContextComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCompositeDrawableComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mFacialActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mCharacterAnimationComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 200
// RVA: 0x545F00
UFG::SimComponent *__fastcall UFG::AnimationLODComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *scene_object_properties, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  unsigned int v3; // edi
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *v8; // rdx
  unsigned __int16 v9; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = scene_object_properties;
  v3 = scene_object_properties->m_NameUID;
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0x150ui64, "AnimationLODComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::AnimationLODComponent::AnimationLODComponent((UFG::AnimationLODComponent *)v5, v3);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->m_pSimObject;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 || (v9 & 0x8000u) != 0 )
    v10 = 13;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v12, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v7, v10);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return v7;
}

// File Line: 210
// RVA: 0x53D2A0
void __fastcall UFG::AnimationLODComponent::OnAttach(UFG::AnimationLODComponent *this, UFG::SimObject *pSimObject)
{
  UFG::AnimationLODComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  v2 = this;
  v3 = &this->mCharacterAnimationComponent;
  v4 = pSimObject;
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
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = &v2->mFacialActionTreeComponent;
  if ( v2->mFacialActionTreeComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mFacialActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mFacialActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mFacialActionTreeComponent.m_pSimObject = 0i64;
    v2->mFacialActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mFacialActionTreeComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mFacialActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *)v2->mFacialActionTreeComponent.mNext != &v2->mFacialActionTreeComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mFacialActionTreeComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mFacialActionTreeComponent.m_Changed = 1;
  v2->mFacialActionTreeComponent.m_pSimObject = v4;
  v2->mFacialActionTreeComponent.m_TypeUID = UFG::FacialActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mFacialActionTreeComponent,
    v4);
  v14 = &v2->mCompositeDrawableComponent;
  if ( v2->mCompositeDrawableComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->mCompositeDrawableComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->mCompositeDrawableComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mCompositeDrawableComponent.m_pSimObject = 0i64;
    v2->mCompositeDrawableComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mCompositeDrawableComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->mCompositeDrawableComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *)v2->mCompositeDrawableComponent.mNext != &v2->mCompositeDrawableComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->mCompositeDrawableComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->mCompositeDrawableComponent.m_Changed = 1;
  v2->mCompositeDrawableComponent.m_pSimObject = v4;
  v2->mCompositeDrawableComponent.m_TypeUID = UFG::CompositeDrawableComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mCompositeDrawableComponent,
    v4);
  v19 = &v2->mWorldContextComponent;
  if ( v2->mWorldContextComponent.m_pSimComponent )
  {
    v20 = v19->mPrev;
    v21 = v2->mWorldContextComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v2->mWorldContextComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->mWorldContextComponent.m_pSimObject = 0i64;
    v2->mWorldContextComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mWorldContextComponent.mPrev;
    v19->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v19->mPrev;
    goto LABEL_29;
  }
  if ( v2->mWorldContextComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *)v2->mWorldContextComponent.mNext != &v2->mWorldContextComponent) )
  {
    v22 = v19->mPrev;
    v23 = v2->mWorldContextComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v2->mWorldContextComponent.m_Changed = 1;
  v2->mWorldContextComponent.m_pSimObject = v4;
  v2->mWorldContextComponent.m_TypeUID = UFG::WorldContextComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mWorldContextComponent,
    v4);
}

// File Line: 220
// RVA: 0x53FC80
void __fastcall UFG::AnimationLODComponent::OnDetach(UFG::AnimationLODComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *v1; // r8
  UFG::AnimationLODComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax

  v1 = &this->mCompositeDrawableComponent;
  v2 = this;
  if ( this->mCompositeDrawableComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mCompositeDrawableComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mCompositeDrawableComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mCompositeDrawableComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent,0> *)this->mCompositeDrawableComponent.mNext != &this->mCompositeDrawableComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->mFacialActionTreeComponent;
  v1->m_Changed = 1;
  if ( v2->mFacialActionTreeComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->mFacialActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->mFacialActionTreeComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mFacialActionTreeComponent.m_pSimObject = 0i64;
    v2->mFacialActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mFacialActionTreeComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->mFacialActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::FacialActionTreeComponent,0> *)v2->mFacialActionTreeComponent.mNext != &v2->mFacialActionTreeComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->mFacialActionTreeComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->mFacialActionTreeComponent.m_Changed = 1;
  v12 = &v2->mCharacterAnimationComponent;
  if ( v2->mCharacterAnimationComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->mCharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->mCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mCharacterAnimationComponent.m_pSimObject = 0i64;
    v2->mCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mCharacterAnimationComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->mCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v2->mCharacterAnimationComponent.mNext != &v2->mCharacterAnimationComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->mCharacterAnimationComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->mCharacterAnimationComponent.m_Changed = 1;
  v17 = &v2->mWorldContextComponent;
  if ( v2->mWorldContextComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->mWorldContextComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->mWorldContextComponent.m_pSimComponent = 0i64;
    v2->mWorldContextComponent.m_pSimObject = 0i64;
    v2->mWorldContextComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mWorldContextComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    v2->mWorldContextComponent.m_Changed = 1;
  }
  else
  {
    if ( v2->mWorldContextComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *)v17->mPrev != v17
       || (UFG::RebindingComponentHandle<UFG::WorldContextComponent,0> *)v2->mWorldContextComponent.mNext != &v2->mWorldContextComponent) )
    {
      v20 = v17->mPrev;
      v21 = v2->mWorldContextComponent.mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      v2->mWorldContextComponent.m_pSimObject = 0i64;
      v2->mWorldContextComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mWorldContextComponent.mPrev;
      v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    }
    v2->mWorldContextComponent.m_Changed = 1;
  }
}

// File Line: 427
// RVA: 0x558EA0
void __fastcall UFG::AnimationLODComponent::Update(UFG::AnimationLODComponent *this, float fDeltaS, bool cameraUsingHighZoom, UFG::qVector3 *testWorldPosition)
{
  UFG::AnimationLODComponent *v4; // rdi
  char v5; // bp
  Creature *v6; // rsi
  UFG::SimComponent *v7; // rsi
  UFG::qSafePointer<Creature,Creature> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::TransformNodeComponent *v12; // r15
  char v13; // r14
  char v14; // r13
  char v15; // bl
  UFG::WorldContextComponent *v16; // rcx
  bool v17; // al
  unsigned __int8 v18; // bl
  bool v19; // r12
  char v20; // bl
  UFG::SimObject *v21; // rcx
  UFG::SimObject *v22; // r15
  float v23; // xmm1_4
  char v24; // bl
  UFG::SimComponent *v25; // rcx
  signed int v26; // eax
  UFG::SimComponent *v27; // rcx
  unsigned int v28; // ecx
  UFG::SimObject *v29; // rbx
  NISManager *v30; // rax
  char v31; // r12
  float v32; // xmm1_4
  signed int v33; // er14
  Render::DebugDrawContext *v34; // r13
  const char *v35; // rcx
  const char *v36; // r15
  const char *v37; // rbx
  __int64 v38; // rax
  const char *v39; // rax
  UFG::qColour *v40; // r8
  int v41; // xmm0_4
  __int64 v42; // [rsp+38h] [rbp-F0h]
  char v43; // [rsp+60h] [rbp-C8h]
  char v44; // [rsp+61h] [rbp-C7h]
  UFG::qVector3 world_position; // [rsp+68h] [rbp-C0h]
  __int64 v46; // [rsp+78h] [rbp-B0h]
  UFG::qMatrix44 transform; // [rsp+80h] [rbp-A8h]
  UFG::qString v48; // [rsp+C0h] [rbp-68h]
  char v49; // [rsp+130h] [rbp+8h]
  bool v50; // [rsp+140h] [rbp+18h]
  UFG::qVector3 *v51; // [rsp+148h] [rbp+20h]

  v51 = testWorldPosition;
  v50 = cameraUsingHighZoom;
  v46 = -2i64;
  v4 = this;
  v5 = 0;
  v6 = this->mCreature.m_pPointer;
  if ( v6 )
  {
LABEL_9:
    v43 = 0;
    LOBYTE(v12) = 0;
    v49 = 0;
    v13 = v6->mLowPowerModeEnabled;
    v14 = 0;
    v44 = 0;
    v15 = *((_BYTE *)v4 + 312);
    v17 = 1;
    if ( !(v15 & 8) && !(v15 & 1) && !(v15 & 4) )
    {
      v16 = (UFG::WorldContextComponent *)v4->mWorldContextComponent.m_pSimComponent;
      if ( !v16 || !UFG::WorldContextComponent::IsSyncing(v16) )
        v17 = 0;
    }
    v18 = v15 & 0xFB;
    *((_BYTE *)v4 + 312) = v18;
    if ( v17 )
    {
      v19 = 1;
      v13 = 0;
      goto LABEL_46;
    }
    v20 = (v18 >> 1) & 1;
    v21 = v4->mCompositeDrawableComponent.m_pSimComponent[19].m_pSimObject;
    if ( v21 )
    {
      v19 = LOBYTE(v21->vfptr) <= 1u;
      if ( LOBYTE(v21->vfptr) > 1u )
      {
        v13 = 1;
        LOBYTE(v12) = 1;
        v49 = 1;
        goto LABEL_46;
      }
    }
    else
    {
      v19 = 1;
    }
    v22 = v4->m_pSimObject;
    if ( v22 )
      v12 = v22->m_pTransformNodeComponent;
    else
      v12 = 0i64;
    if ( !v12 )
      goto LABEL_46;
    v19 = 1;
    UFG::TransformNodeComponent::UpdateWorldTransform(v12);
    v23 = (float)((float)(v12->mWorldTransform.v3.x - v51->x) * (float)(v12->mWorldTransform.v3.x - v51->x))
        + (float)((float)(v12->mWorldTransform.v3.y - v51->y) * (float)(v12->mWorldTransform.v3.y - v51->y));
    if ( v50
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
          LOBYTE(v12) = 1;
          v49 = 1;
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
      v43 = 1;
      goto LABEL_36;
    }
LABEL_36:
    LOBYTE(v12) = 0;
LABEL_37:
    if ( v23 <= sSkeletalLODDistSqr )
    {
      if ( (float)(sSkeletalLODDistSqr - sHysteresisSqr) > v23 )
        v13 = 0;
    }
    else
    {
      v13 = 1;
    }
    if ( gSkeletonLODEnabled )
    {
      v14 = 0;
      if ( v23 > sSkeletalLODDistSqr )
        v14 = 1;
    }
    if ( v23 > sFacialLODDistSqr )
    {
      v24 = 1;
      v44 = 1;
LABEL_47:
      v6->mLowPowerModeEnabled = 1;
      v6->mPose.mBoneUpdateCount = gSkeletalLODBoneCount;
      if ( v4->mFacialActionTreeComponent.m_pSimComponent )
      {
        v25 = v4->mFacialActionTreeComponent.m_pSimComponent;
        LOBYTE(v25[7].m_Flags) |= 2u;
        UFG::FacialActionTreeComponent::SyncUpdateList((UFG::FacialActionTreeComponent *)v25);
      }
      if ( v19 )
      {
        if ( (_BYTE)v12 )
        {
          v26 = sFarUpdateFrequency;
        }
        else
        {
          v26 = sMidUpdateFrequency;
          if ( !v43 )
            v26 = 1;
        }
        v4->mUpdatePeriod = v26;
        if ( !v13 )
          v6->mLowPowerModeEnabled = 0;
        if ( !v14 )
          v6->mPose.mBoneUpdateCount = -1;
        if ( v4->mFacialActionTreeComponent.m_pSimComponent && !v24 )
        {
          v27 = v4->mFacialActionTreeComponent.m_pSimComponent;
          LOBYTE(v27[7].m_Flags) &= 0xFDu;
          UFG::FacialActionTreeComponent::SyncUpdateList((UFG::FacialActionTreeComponent *)v27);
        }
      }
      else
      {
        v4->mUpdatePeriod = 30;
      }
      v28 = v4->mMinUpdatePeriod;
      if ( v4->mUpdatePeriod < v28 )
        v28 = v4->mUpdatePeriod;
      v4->mUpdatePeriod = v28;
      if ( v4->mHasBeenUpdatedOnce
        && (v29 = v4->m_pSimObject, v30 = NISManager::GetInstance(), !NISManager::IsActiveInNIS(v30, v29))
        && (UFG::Metrics::msInstance.mSimFrameCount + v4->mSequenceID) % v4->mUpdatePeriod )
      {
        v31 = 0;
        LOBYTE(v4->mCharacterAnimationComponent.m_pSimComponent[3].m_TypeUID) = 0;
      }
      else
      {
        v31 = 1;
        v4->mHasBeenUpdatedOnce = 1;
        LOBYTE(v4->mCharacterAnimationComponent.m_pSimComponent[3].m_TypeUID) = 1;
      }
      if ( gLODDebug )
      {
        Creature::GetTransform(v6, &transform);
        transform.v3.z = transform.v3.z + sLODDisplayOffsetZ;
        v32 = (float)v6->mPose.mBoneUpdateCount;
        if ( v32 >= (float)gMaxNumTransformTracks )
          v32 = (float)gMaxNumTransformTracks;
        v33 = (signed int)v32;
        v34 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        v35 = "NONE";
        v36 = "FALSE";
        if ( v4->mFacialActionTreeComponent.m_pSimComponent )
        {
          v37 = "FALSE";
          if ( v44 )
            v37 = "TRUE";
        }
        else
        {
          v37 = "NONE";
        }
        if ( v33 >= 0 )
        {
          UFG::qString::qString(&v48, "%d", (unsigned int)v33, "TRUE");
          v5 = 1;
          v35 = *(const char **)(v38 + 24);
        }
        if ( v49 )
        {
          v39 = "FAR";
        }
        else
        {
          v39 = "NEAR";
          if ( v43 )
            v39 = "MID";
        }
        v40 = &UFG::qColour::Red;
        if ( v31 )
          v40 = &UFG::qColour::Green;
        world_position = *(UFG::qVector3 *)&transform.v3.x;
        v41 = (unsigned __int128)_mm_sqrt_ps((__m128)LODWORD(FLOAT_N1_0));
        if ( v6->mLowPowerModeEnabled )
          v36 = "TRUE";
        LODWORD(v42) = v4->mUpdatePeriod;
        Render::DebugDrawContext::DrawText(
          v34,
          &world_position,
          v40,
          "Pixel Coverage     : %5.3f\n"
          "TestDist (RealDist): %6.3f (%6.3f)\n"
          "Update Period      : %d (%s)\n"
          "Low Power          : %s\n"
          "Skeletal LOD       : %s\n"
          "Facial LOD         : %s\n",
          DOUBLE_N1_0,
          v41,
          DOUBLE_N1_0,
          v42,
          v39,
          v36,
          v35,
          v37);
        if ( v5 & 1 )
          UFG::qString::~qString(&v48);
      }
      return;
    }
LABEL_46:
    v24 = 0;
    goto LABEL_47;
  }
  v7 = this->mCharacterAnimationComponent.m_pSimComponent;
  if ( v7 )
    v6 = *(Creature **)&v7[2].m_TypeUID;
  else
    v6 = 0i64;
  v8 = &this->mCreature;
  if ( this->mCreature.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v8->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v8->m_pPointer = v6;
  if ( v6 )
  {
    v11 = v6->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v8->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    goto LABEL_9;
  }
}

// File Line: 656
// RVA: 0x55DFC0
void __fastcall UFG::AnimationLODComponent::UpdateAll(float sim_time_delta)
{
  bool v1; // di
  UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *v2; // rcx
  UFG::qVector3 testWorldPosition; // [rsp+20h] [rbp-28h]

  v1 = UFG::IsCameraUsingHighZoom();
  UFG::AnimationLODComponent::getLodTestPoint(&testWorldPosition);
  v2 = UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mNext - 4;
  for ( UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)&UFG::AnimationLODComponent::s_AnimationLODComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AnimationLODComponent,UFG::AnimationLODComponent> *)(&UFG::AnimationLODComponent::s_AnimationLODComponentList
                                                                                  - 4);
        UFG::AnimationLODComponent::s_AnimationLODComponentpCurrentIterator = (UFG::AnimationLODComponent *)v2 )
  {
    if ( ((_QWORD)v2[2].mPrev & 3) == 1 )
    {
      UFG::AnimationLODComponent::Update((UFG::AnimationLODComponent *)v2, sim_time_delta, v1, &testWorldPosition);
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
  UFG::SimComponent *v1; // rdx
  __int64 v2; // rdx

  v1 = this->mCharacterAnimationComponent.m_pSimComponent;
  this->mUpdatePeriod = 1;
  if ( v1 )
  {
    v2 = *(_QWORD *)&v1[2].m_TypeUID;
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
  *((_BYTE *)this + 312) &= 0xFDu;
  *((_BYTE *)this + 312) |= 2 * extended_lod;
}

// File Line: 709
// RVA: 0x520910
void __fastcall UFG::AnimationLODComponent::AddAnimationLockHighLODTask(UFG::AnimationLODComponent *this, AnimationLockHighLODTask *pAnimationLockHighLODTask)
{
  UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *v2; // rdx
  UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *v3; // rax

  v2 = (UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *)&pAnimationLockHighLODTask->mPrev;
  v3 = this->m_AnimationLockHighLODList.mNode.mPrev;
  v3->mNext = v2;
  v2->mPrev = v3;
  v2->mNext = &this->m_AnimationLockHighLODList.mNode;
  this->m_AnimationLockHighLODList.mNode.mPrev = v2;
  *((_BYTE *)this + 312) |= 1u;
}

// File Line: 717
// RVA: 0x5686A0
void __fastcall UFG::AnimationLODComponent::getLodTestPoint(UFG::qVector3 *testWorldPosition)
{
  UFG::qVector3 *v1; // rsi
  UFG::SimObjectCharacter *v2; // rax
  UFG::TransformNodeComponent *v3; // rax
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::BaseCameraComponent *v6; // rdi
  UFG::BaseCameraComponent *v7; // rax
  UFG::BaseCameraComponent *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm1_4

  v1 = testWorldPosition;
  if ( UFG::AnimationLODComponent::sUsePlayerPositionForLODTest )
  {
    v2 = UFG::GetLocalPlayer();
    if ( v2 )
    {
      v3 = v2->m_pTransformNodeComponent;
      v4 = v3->mLocalTransform.v3.y;
      v5 = v3->mLocalTransform.v3.z;
      v1->x = v3->mLocalTransform.v3.x;
      v1->y = v4;
      v1->z = v5;
    }
  }
  else
  {
    v6 = UFG::Director::Get()->mCurrentCamera;
    if ( v6 )
      v6 = (UFG::BaseCameraComponent *)((char *)v6 + 80);
    if ( sUseGameCamLOD )
    {
      v7 = UFG::GetCurrentBaseCamera();
      v8 = v7;
      if ( v7 )
      {
        if ( UFG::SimComponent::IsType(
               (UFG::SimComponent *)&v7->vfptr,
               UFG::DebugCameraComponent::_DebugCameraComponentTypeUID) )
        {
          v8 = *(UFG::BaseCameraComponent **)&v8[1].m_TypeUID;
        }
        if ( v8 )
          v6 = (UFG::BaseCameraComponent *)((char *)v8 + 80);
      }
    }
    if ( v6 )
    {
      v9 = v6->mCamera.mView.v2.y;
      v10 = v6->mCamera.mView.v2.z;
      v1->x = v6->mCamera.mView.v2.x;
      v1->y = v9;
      v1->z = v10;
    }
  }
}

