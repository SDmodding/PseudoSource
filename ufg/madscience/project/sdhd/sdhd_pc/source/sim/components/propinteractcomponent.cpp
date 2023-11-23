// File Line: 27
// RVA: 0x1543FE0
__int64 dynamic_initializer_for__UFG::PropInteractComponent::s_PropInteractComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PropInteractComponent::s_PropInteractComponentList__);
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
void __fastcall UFG::PropInteractComponent::PropInteractComponent(
        UFG::PropInteractComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent>;
  this->mNext = &this->UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PropInteractComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->mActionTreeComponent);
  this->mInteractingSimObject.mPrev = &this->mInteractingSimObject;
  this->mInteractingSimObject.mNext = &this->mInteractingSimObject;
  this->mInteractingSimObject.m_pPointer = 0i64;
  mPrev = UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev;
  UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)&UFG::PropInteractComponent::s_PropInteractComponentList;
  UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mPrev = &this->UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent>;
  UFG::SimComponent::AddType(this, UFG::PropInteractComponent::_PropInteractComponentTypeUID, "PropInteractComponent");
  this->mHoldCurrentInteraction = 0;
  this->mInteractionOpeningBranch = 0i64;
}

// File Line: 52
// RVA: 0x535760
bool __fastcall UFG::PropInteractComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentPropInteract,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 58
// RVA: 0x545450
UFG::PropInteractComponent *__fastcall UFG::PropInteractComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB0ui64, "PropInteractComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = sceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sceneObject->mpConstProperties;
    UFG::PropInteractComponent::PropInteractComponent(
      (UFG::PropInteractComponent *)v3,
      sceneObject->m_NameUID,
      mpWritableProperties,
      0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_11;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
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
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::PropInteractComponent *)v6;
}

// File Line: 69
// RVA: 0x51C350
void __fastcall UFG::PropInteractComponent::~PropInteractComponent(UFG::PropInteractComponent *this)
{
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v2; // rdi
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *mPrev; // rcx
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mInteractingSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v10; // rcx
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PropInteractComponent::`vftable;
  if ( this == UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator )
    UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator = (UFG::PropInteractComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mInteractingSimObject = &this->mInteractingSimObject;
  if ( this->mInteractingSimObject.m_pPointer )
  {
    v6 = p_mInteractingSimObject->mPrev;
    v7 = this->mInteractingSimObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mInteractingSimObject->mPrev = p_mInteractingSimObject;
    this->mInteractingSimObject.mNext = &this->mInteractingSimObject;
  }
  this->mInteractingSimObject.m_pPointer = 0i64;
  v8 = p_mInteractingSimObject->mPrev;
  v9 = this->mInteractingSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mInteractingSimObject->mPrev = p_mInteractingSimObject;
  this->mInteractingSimObject.mNext = &this->mInteractingSimObject;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActionTreeComponent);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 76
// RVA: 0x53E5A0
void __fastcall UFG::PropInteractComponent::OnAttach(UFG::PropInteractComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rdi
  int v10; // eax
  __int64 v11; // r8
  int v12; // [rsp+30h] [rbp+8h] BYREF

  p_mActionTreeComponent = &this->mActionTreeComponent;
  if ( p_mActionTreeComponent->m_pSimComponent )
  {
    mNext = p_mActionTreeComponent->mNext;
    mPrev = p_mActionTreeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mActionTreeComponent->m_pSimComponent = 0i64;
  }
  else
  {
    if ( !p_mActionTreeComponent->m_pSimObject
      || p_mActionTreeComponent->mPrev == p_mActionTreeComponent
      && p_mActionTreeComponent->mNext == p_mActionTreeComponent )
    {
      goto LABEL_8;
    }
    v7 = p_mActionTreeComponent->mNext;
    v8 = p_mActionTreeComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
  }
  p_mActionTreeComponent->m_pSimObject = 0i64;
  p_mActionTreeComponent->mNext = p_mActionTreeComponent;
  p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
LABEL_8:
  p_mActionTreeComponent->m_Changed = 1;
  p_mActionTreeComponent->m_pSimObject = object;
  p_mActionTreeComponent->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    p_mActionTreeComponent,
    object);
  v9 = this->mActionTreeComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext;
  if ( v9 )
  {
    v10 = UFG::qStringHashUpper32("Interactions", -1);
    LOBYTE(v11) = 1;
    v12 = v10;
    this->mInteractionOpeningBranch = (ActionNode *)((__int64 (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, int *, __int64))v9->mPrev[6].mPrev)(
                                                      v9,
                                                      &v12,
                                                      v11);
  }
}

// File Line: 96
// RVA: 0x525AB0
void __fastcall UFG::PropInteractComponent::DetachFromObject(
        UFG::PropInteractComponent *this,
        UFG::SimObject *pAttachedToSimObject,
        __int64 a3,
        __int64 vfptr_low)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mInteractingSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  signed __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  unsigned int size; // r10d
  UFG::SimComponentHolder *v11; // rdx
  unsigned int v12; // r10d

  p_mInteractingSimObject = &this->mInteractingSimObject;
  if ( this->mInteractingSimObject.m_pPointer )
  {
    mPrev = p_mInteractingSimObject->mPrev;
    mNext = p_mInteractingSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mInteractingSimObject->mPrev = p_mInteractingSimObject;
    p_mInteractingSimObject->mNext = p_mInteractingSimObject;
  }
  p_mInteractingSimObject->m_pPointer = 0i64;
  if ( pAttachedToSimObject )
  {
    m_Flags = pAttachedToSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)pAttachedToSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)pAttachedToSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr_low = LODWORD(pAttachedToSimObject[1].vfptr);
      size = pAttachedToSimObject->m_Components.size;
      if ( (unsigned int)vfptr_low < size )
      {
        v11 = &pAttachedToSimObject->m_Components.p[(unsigned int)vfptr_low];
        while ( (v11->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v11->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          vfptr_low = (unsigned int)(vfptr_low + 1);
          ++v11;
          if ( (unsigned int)vfptr_low >= size )
          {
            m_pComponent = 0i64;
            goto LABEL_24;
          }
        }
LABEL_15:
        m_pComponent = (UFG::TargetingSystemBaseComponent *)v11->m_pComponent;
        goto LABEL_24;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              pAttachedToSimObject,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
        if ( m_pComponent )
        {
          LOBYTE(vfptr_low) = 1;
          ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
            m_pComponent,
            40i64,
            0i64,
            vfptr_low,
            0,
            "PropInteractComponent::DetachFromObject",
            0i64,
            0i64);
        }
        return;
      }
      vfptr_low = LODWORD(pAttachedToSimObject[1].vfptr);
      v12 = pAttachedToSimObject->m_Components.size;
      if ( (unsigned int)vfptr_low < v12 )
      {
        v11 = &pAttachedToSimObject->m_Components.p[(unsigned int)vfptr_low];
        while ( (v11->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v11->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          vfptr_low = (unsigned int)(vfptr_low + 1);
          ++v11;
          if ( (unsigned int)vfptr_low >= v12 )
            goto LABEL_22;
        }
        goto LABEL_15;
      }
    }
LABEL_22:
    m_pComponent = 0i64;
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
  unsigned int v2; // eax
  unsigned int MostUsedIndex; // eax

  v2 = _S61;
  if ( (_S61 & 1) == 0 )
  {
    _S61 |= 1u;
    IDNotInteractable.mUID = UFG::qStringHashUpper32("NotInteractable", -1);
    v2 = _S61;
  }
  if ( (v2 & 2) != 0 )
  {
    MostUsedIndex = index_MostUsed_IDNotInteractable;
  }
  else
  {
    _S61 = v2 | 2;
    MostUsedIndex = GetMostUsedIndex(IDNotInteractable.mUID);
    index_MostUsed_IDNotInteractable = MostUsedIndex;
  }
  return ActionController::IsPlaying(
           (ActionController *)&this->mActionTreeComponent.m_pSimComponent[3],
           &IDNotInteractable,
           MostUsedIndex,
           0);
}

// File Line: 165
// RVA: 0x53AF90
bool __fastcall UFG::PropInteractComponent::IsInteractionAvailable(
        UFG::PropInteractComponent *this,
        ActionContext *pContext)
{
  Expression::IMemberMap *v4; // rbp
  ActionNodeRoot *v5; // rax
  ActionNodeRoot *v6; // rsi
  __int64 mValue; // r8
  UFG::ActionTreeComponentBase *v8; // rcx
  ActionNodePlayable *v9; // rax
  bool result; // al

  if ( this->mHoldCurrentInteraction
    || this->mCurrentInteractionAvailable
    || !this->mInteractionOpeningBranch
    || this->mInteractingSimObject.m_pPointer
    || UFG::PropInteractComponent::NotInteractable(this) )
  {
    return 0;
  }
  v4 = pContext->m_OpeningBranch->vfptr[1].GetResourceOwner(pContext->m_OpeningBranch);
  v5 = (ActionNodeRoot *)this->mInteractionOpeningBranch->vfptr[1].GetResourceOwner(this->mInteractionOpeningBranch);
  v6 = v5;
  mValue = v5->mActionTreeType.mValue;
  if ( (pContext->mActionTreeComponentBase[mValue] || pContext->mActionTreeComponentBase[1]) && v4 != v5 )
  {
    v8 = pContext->mActionTreeComponentBase[mValue];
    if ( !v8 )
      v8 = pContext->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v8, v5) )
      ActionNodeRoot::Init(v6, pContext);
  }
  v9 = (ActionNodePlayable *)((__int64 (__fastcall *)(ActionNode *, ActionContext *))this->mInteractionOpeningBranch->vfptr[2].GetClassNameUID)(
                               this->mInteractionOpeningBranch,
                               pContext);
  this->mCurrentInteractionAvailable = v9;
  result = v9 != 0i64;
  this->mHoldCurrentInteraction = result;
  return result;
}

// File Line: 198
// RVA: 0x53B260
bool __fastcall UFG::PropInteractComponent::IsOrientedToInteract(
        UFG::PropInteractComponent *this,
        UFG::qMatrix44 *matTest,
        UFG::qSymbolUC *uSyncNameUID,
        const float fMaxDistance,
        float fMaxAngleBetween)
{
  UFG::SimObjectProp *m_pSimObject; // rcx
  Creature *mCreature; // rbx
  __int16 m_Flags; // r9
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v12; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v16; // rdx
  int BoneID; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-78h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-68h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-58h] BYREF

  m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
  mCreature = 0i64;
  if ( !m_pSimObject )
    goto LABEL_26;
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
        v12 = m_pComponent->m_TypeUID;
        if ( ((v12 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v12 & 0x1FFFFFF) != 0 )
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
          v16 = (__int64)&m_pSimObject->m_Components.p[mComponentTableEntryCount];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            v16 += 16i64;
            if ( mComponentTableEntryCount >= size )
            {
              m_pComponent = 0i64;
              goto LABEL_24;
            }
          }
          m_pComponent = *(UFG::CharacterAnimationComponent **)v16;
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
    mCreature = m_pComponent->mCreature;
  if ( !mCreature )
    return 0;
  if ( !mCreature->mPose.mRigHandle.mData )
    return 0;
  BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, uSyncNameUID->mUID);
  if ( BoneID < 0 )
    return 0;
  Creature::GetTransform(mCreature, BoneID, &transform);
  if ( (float)((float)((float)((float)(matTest->v3.y - transform.v3.y) * (float)(matTest->v3.y - transform.v3.y))
                     + (float)((float)(matTest->v3.x - transform.v3.x) * (float)(matTest->v3.x - transform.v3.x)))
             + (float)((float)(matTest->v3.z - transform.v3.z) * (float)(matTest->v3.z - transform.v3.z))) > (float)(fMaxDistance * fMaxDistance) )
    return 0;
LABEL_26:
  x = matTest->v0.x;
  y = matTest->v0.y;
  v1.z = 0.0;
  v2.z = 0.0;
  v1.x = x;
  v1.y = y;
  v2.x = transform.v0.x;
  v2.y = transform.v0.y;
  return UFG::qAngleBetween(&v1, &v2) <= fMaxAngleBetween;
}

