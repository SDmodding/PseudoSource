// File Line: 27
// RVA: 0x1543FE0
__int64 dynamic_initializer_for__UFG::PropInteractComponent::s_PropInteractComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PropInteractComponent::s_PropInteractComponentList__);
}

// File Line: 28
// RVA: 0x1543490
__int64 dynamic_initializer_for__UFG::PropInteractComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::PropInteractComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::PropInteractComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::PropInteractComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::PropInteractComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 33
// RVA: 0x5187A0
void __fastcall UFG::PropInteractComponent::PropInteractComponent(UFG::PropInteractComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::PropInteractComponent *v4; // rdi
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v5; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // ST28_8
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v7; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PropInteractComponent::`vftable';
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->mActionTreeComponent);
  v6 = &v4->mInteractingSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->mInteractingSimObject.m_pPointer = 0i64;
  v7 = UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev;
  UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&v4->mPrev;
  v5->mPrev = v7;
  v4->mNext = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&UFG::PropInteractComponent::s_PropInteractComponentList;
  UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::PropInteractComponent::_PropInteractComponentTypeUID,
    "PropInteractComponent");
  v4->mHoldCurrentInteraction = 0;
  v4->mInteractionOpeningBranch = 0i64;
}

// File Line: 52
// RVA: 0x535760
bool __fastcall UFG::PropInteractComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentPropInteract.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 58
// RVA: 0x545450
UFG::SimComponent *__fastcall UFG::PropInteractComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xB0ui64, "PropInteractComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::PropInteractComponent::PropInteractComponent((UFG::PropInteractComponent *)v3, v1->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
    goto LABEL_11;
  if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
    {
      v9 = 13;
      goto LABEL_12;
    }
LABEL_11:
    v9 = -1;
    goto LABEL_12;
  }
  v9 = 33;
LABEL_12:
  UFG::SimObjectModifier::SimObjectModifier(&v11, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 69
// RVA: 0x51C350
void __fastcall UFG::PropInteractComponent::~PropInteractComponent(UFG::PropInteractComponent *this)
{
  UFG::PropInteractComponent *v1; // rbx
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v2; // rdi
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v3; // rcx
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v10; // rcx
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PropInteractComponent::`vftable';
  if ( this == UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator )
    UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator = (UFG::PropInteractComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mInteractingSimObject;
  if ( v1->mInteractingSimObject.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mInteractingSimObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mInteractingSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mInteractingSimObject.mPrev;
  }
  v1->mInteractingSimObject.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mInteractingSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mInteractingSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mInteractingSimObject.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActionTreeComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 76
// RVA: 0x53E5A0
void __fastcall UFG::PropInteractComponent::OnAttach(UFG::PropInteractComponent *this, UFG::SimObject *object)
{
  UFG::PropInteractComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v3; // rcx
  UFG::SimObject *v4; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rdi
  int v10; // eax
  __int64 v11; // r8
  int v12; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = &this->mActionTreeComponent;
  v4 = object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->m_pSimComponent = 0i64;
  }
  else
  {
    if ( !v3->m_pSimObject
      || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v3->mPrev == v3
      && (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v3->mNext == v3 )
    {
      goto LABEL_8;
    }
    v7 = v3->mNext;
    v8 = v3->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
  }
  v3->m_pSimObject = 0i64;
  v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
  v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = v2->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext;
  if ( v9 )
  {
    v10 = UFG::qStringHashUpper32("Interactions", 0xFFFFFFFF);
    LOBYTE(v11) = 1;
    v12 = v10;
    v2->mInteractionOpeningBranch = (ActionNode *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, int *, __int64))v9->mPrev[6].mPrev)(
                                                    v9,
                                                    &v12,
                                                    v11);
  }
}

// File Line: 96
// RVA: 0x525AB0
void __fastcall UFG::PropInteractComponent::DetachFromObject(UFG::PropInteractComponent *this, UFG::SimObject *pAttachedToSimObject, __int64 a3, __int64 a4)
{
  UFG::SimObject *v4; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  unsigned __int16 v8; // cx
  UFG::TargetingSystemBaseComponent *v9; // rax
  unsigned int v10; // er10
  signed __int64 v11; // rdx
  unsigned int v12; // er10
  int v13; // ST20_4

  v4 = pAttachedToSimObject;
  v5 = &this->mInteractingSimObject;
  if ( this->mInteractingSimObject.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
  if ( v4 )
  {
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (v8 & 0x8000u) != 0 )
    {
      v9 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (v8 >> 13) & 1 )
    {
      a4 = LODWORD(v4[1].vfptr);
      v10 = v4->m_Components.size;
      if ( (unsigned int)a4 < v10 )
      {
        v11 = (signed __int64)&v4->m_Components.p[(unsigned int)a4];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          a4 = (unsigned int)(a4 + 1);
          v11 += 16i64;
          if ( (unsigned int)a4 >= v10 )
          {
            v9 = 0i64;
            goto LABEL_24;
          }
        }
LABEL_15:
        v9 = *(UFG::TargetingSystemBaseComponent **)v11;
        goto LABEL_24;
      }
    }
    else
    {
      if ( !((v8 >> 12) & 1) )
      {
        v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                    v4,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
        if ( v9 )
        {
          v13 = 0;
          LOBYTE(a4) = 1;
          ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, signed __int64, _QWORD, __int64, int, const char *, _QWORD, _QWORD))v9->vfptr[14].__vecDelDtor)(
            v9,
            40i64,
            0i64,
            a4,
            v13,
            "PropInteractComponent::DetachFromObject",
            0i64,
            0i64);
        }
        return;
      }
      a4 = LODWORD(v4[1].vfptr);
      v12 = v4->m_Components.size;
      if ( (unsigned int)a4 < v12 )
      {
        v11 = (signed __int64)&v4->m_Components.p[(unsigned int)a4];
        while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
        {
          a4 = (unsigned int)(a4 + 1);
          v11 += 16i64;
          if ( (unsigned int)a4 >= v12 )
            goto LABEL_22;
        }
        goto LABEL_15;
      }
    }
LABEL_22:
    v9 = 0i64;
    goto LABEL_24;
  }
}

// File Line: 141
// RVA: 0x55C4F0
void __fastcall UFG::PropInteractComponent::Update(UFG::PropInteractComponent *this, float delta_sec)
{
  if ( this->mHoldCurrentInteraction )
    this->mHoldCurrentInteraction = 0;
  else
    this->mCurrentInteractionAvailable = 0i64;
}

// File Line: 157
// RVA: 0x53CB10
unsigned __int8 __fastcall UFG::PropInteractComponent::NotInteractable(UFG::PropInteractComponent *this)
{
  UFG::PropInteractComponent *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax

  v1 = this;
  v2 = _S61;
  if ( !(_S61 & 1) )
  {
    _S61 |= 1u;
    IDNotInteractable.mUID = UFG::qStringHashUpper32("NotInteractable", 0xFFFFFFFF);
    v2 = _S61;
  }
  if ( v2 & 2 )
  {
    v3 = index_MostUsed_IDNotInteractable;
  }
  else
  {
    _S61 = v2 | 2;
    v3 = GetMostUsedIndex(IDNotInteractable.mUID);
    index_MostUsed_IDNotInteractable = v3;
  }
  return ActionController::IsPlaying(
           (ActionController *)&v1->mActionTreeComponent.m_pSimComponent[3],
           &IDNotInteractable,
           v3,
           0);
}

// File Line: 165
// RVA: 0x53AF90
bool __fastcall UFG::PropInteractComponent::IsInteractionAvailable(UFG::PropInteractComponent *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  UFG::PropInteractComponent *v3; // rbx
  __int64 v4; // rbp
  ActionNodeRoot *v5; // rax
  ActionNodeRoot *v6; // rsi
  __int64 v7; // r8
  UFG::ActionTreeComponentBase *v8; // rcx
  __int64 v9; // rax
  bool result; // al

  v2 = pContext;
  v3 = this;
  if ( this->mHoldCurrentInteraction
    || this->mCurrentInteractionAvailable
    || !this->mInteractionOpeningBranch
    || this->mInteractingSimObject.m_pPointer
    || UFG::PropInteractComponent::NotInteractable(this) )
  {
    return 0;
  }
  v4 = ((__int64 (*)(void))v2->m_OpeningBranch->vfptr[1].GetResourceOwner)();
  v5 = (ActionNodeRoot *)((__int64 (*)(void))v3->mInteractionOpeningBranch->vfptr[1].GetResourceOwner)();
  v6 = v5;
  v7 = v5->mActionTreeType.mValue;
  if ( (v2->mActionTreeComponentBase[v7] || v2->mActionTreeComponentBase[1]) && (ActionNodeRoot *)v4 != v5 )
  {
    v8 = v2->mActionTreeComponentBase[v7];
    if ( !v8 )
      v8 = v2->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v8, v5) )
      ActionNodeRoot::Init(v6, v2);
  }
  v9 = ((__int64 (__fastcall *)(ActionNode *, ActionContext *))v3->mInteractionOpeningBranch->vfptr[2].GetClassNameUID)(
         v3->mInteractionOpeningBranch,
         v2);
  v3->mCurrentInteractionAvailable = (ActionNodePlayable *)v9;
  result = v9 != 0;
  v3->mHoldCurrentInteraction = result;
  return result;
}

// File Line: 198
// RVA: 0x53B260
char __fastcall UFG::PropInteractComponent::IsOrientedToInteract(UFG::PropInteractComponent *this, UFG::qMatrix44 *matTest, UFG::qSymbolUC *uSyncNameUID, const float fMaxDistance, const float fMaxAngleBetween)
{
  UFG::SimObjectProp *v5; // rcx
  Creature *v6; // rbx
  UFG::qSymbolUC *v7; // rsi
  UFG::qMatrix44 *v8; // rdi
  unsigned __int16 v9; // r9
  UFG::CharacterAnimationComponent *v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // edx
  UFG::CharacterAnimationComponent *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er9
  signed __int64 v16; // rdx
  int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm1_4
  char result; // al
  UFG::qVector3 v2; // [rsp+20h] [rbp-78h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-68h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-58h]

  v5 = (UFG::SimObjectProp *)this->m_pSimObject;
  v6 = 0i64;
  v7 = uSyncNameUID;
  v8 = matTest;
  if ( !v5 )
    goto LABEL_26;
  v9 = v5->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
    if ( !v10
      || (v11 = v10->m_TypeUID, (v11 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000)
      || UFG::CharacterAnimationComponent::_TypeUID & ~v11 & 0x1FFFFFF )
    {
LABEL_6:
      v10 = 0i64;
      goto LABEL_24;
    }
  }
  else
  {
    if ( (v9 & 0x8000u) != 0 )
    {
      v10 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
      if ( v10 )
      {
        v12 = v10->m_TypeUID;
        if ( !((v12 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::CharacterAnimationComponent::_TypeUID & ~v12 & 0x1FFFFFF )
            v10 = 0i64;
          goto LABEL_24;
        }
      }
      goto LABEL_6;
    }
    if ( (v9 >> 13) & 1 )
    {
      v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v5);
    }
    else
    {
      if ( (v9 >> 12) & 1 )
      {
        v14 = v5->mComponentTableEntryCount;
        v15 = v5->m_Components.size;
        if ( v14 < v15 )
        {
          v16 = (signed __int64)&v5->m_Components.p[v14];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v14;
            v16 += 16i64;
            if ( v14 >= v15 )
            {
              v10 = 0i64;
              goto LABEL_24;
            }
          }
          v10 = *(UFG::CharacterAnimationComponent **)v16;
          goto LABEL_24;
        }
        goto LABEL_6;
      }
      v13 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v5->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v10 = v13;
  }
LABEL_24:
  if ( v10 )
    v6 = v10->mCreature;
  if ( !v6 )
    goto LABEL_35;
  if ( !v6->mPose.mRigHandle.mData )
    goto LABEL_35;
  v17 = Skeleton::GetBoneID(v6->mPose.mRigHandle.mUFGSkeleton, v7->mUID);
  if ( v17 < 0 )
    goto LABEL_35;
  Creature::GetTransform(v6, v17, &transform);
  if ( (float)((float)((float)((float)(v8->v3.y - transform.v3.y) * (float)(v8->v3.y - transform.v3.y))
                     + (float)((float)(v8->v3.x - transform.v3.x) * (float)(v8->v3.x - transform.v3.x)))
             + (float)((float)(v8->v3.z - transform.v3.z) * (float)(v8->v3.z - transform.v3.z))) > (float)(fMaxDistance * fMaxDistance) )
    goto LABEL_35;
LABEL_26:
  v18 = v8->v0.x;
  v19 = v8->v0.y;
  v1.z = 0.0;
  v2.z = 0.0;
  v1.x = v18;
  v1.y = v19;
  v2.x = transform.v0.x;
  v2.y = transform.v0.y;
  if ( UFG::qAngleBetween(&v1, &v2) <= fMaxAngleBetween )
    result = 1;
  else
LABEL_35:
    result = 0;
  return result;
}

