// File Line: 91
// RVA: 0x1543EC0
__int64 dynamic_initializer_for__UFG::HitReactionComponent::s_HitReactionComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HitReactionComponent::s_HitReactionComponentList__);
}

// File Line: 92
// RVA: 0x52CA30
UFG::ComponentIDDesc *__fastcall UFG::HitReactionComponent::GetDesc(UFG::HitReactionComponent *this)
{
  return &UFG::HitReactionComponent::_TypeIDesc;
}

// File Line: 108
// RVA: 0x517A50
void __fastcall UFG::HitReactionComponent::HitReactionComponent(
        UFG::HitReactionComponent *this,
        unsigned int name_uid,
        component_HitReaction *data_ptr,
        UFG::qSymbol *propSetName)
{
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *mPrev; // rax
  __int64 mOffset; // rax
  char *v8; // rcx
  char v9; // cl

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent>;
  this->mNext = &this->UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HitReactionComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HitReactionComponent::`vftable{for `UFG::UpdateInterface};
  UFG::qSharedString::qSharedString(&this->mHitTreeFileName);
  this->mHitReactionOpeningBranchFullPath.mPath.mCount = 0;
  this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
  this->mHitTree = 0i64;
  *(_QWORD *)&this->mIncomingAttackInfo.mAttackPhaseEnum = 0i64;
  this->mIncomingAttackInfo.mAttacker.mPrev = &this->mIncomingAttackInfo.mAttacker;
  this->mIncomingAttackInfo.mAttacker.mNext = &this->mIncomingAttackInfo.mAttacker;
  this->mIncomingAttackInfo.mAttacker.m_pPointer = 0i64;
  *(_QWORD *)&this->mIncomingAttackInfo.mAttackLocationLateralID = 0i64;
  this->mIncomingAttackInfo.mTimeSinceUpdated = 1000;
  UFG::HitRecord::HitRecord(&this->mHitRecord);
  this->mNumHits = 0;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->mActionTreeComponent);
  mPrev = UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev;
  UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&UFG::HitReactionComponent::s_HitReactionComponentList;
  UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent>;
  UFG::SimComponent::AddType(this, UFG::HitReactionComponent::_HitReactionComponentTypeUID, "HitReactionComponent");
  if ( this->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
  {
    mOffset = this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
    if ( mOffset )
    {
      v8 = (char *)&this->mHitReactionOpeningBranchFullPath.mPath.mData + mOffset;
      if ( v8 )
        operator delete[](v8);
    }
    this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
    this->mHitReactionOpeningBranchFullPath.mPath.mCount &= 0x80000000;
  }
  ActionPath::Append(&this->mHitReactionOpeningBranchFullPath, &customCaption);
  if ( data_ptr )
  {
    UFG::HitReactionComponent::PropertiesLoad(this, data_ptr);
  }
  else
  {
    UFG::qSharedString::operator=(&this->mHitTreeFileName, "Data\\Act\\HitTree.act");
    this->mReceiverDamageMultiplierPct = 100;
  }
  v9 = tweaks_added_0;
  if ( !tweaks_added_0 )
    v9 = 1;
  tweaks_added_0 = v9;
  UFG::HitReactionComponent::Reset(this);
  this->mWasProxy = 0;
}

// File Line: 166
// RVA: 0x51BA30
void __fastcall UFG::HitReactionComponent::~HitReactionComponent(UFG::HitReactionComponent *this)
{
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v2; // rdi
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *mPrev; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  ActionPath *p_mHitReactionOpeningBranchFullPath; // rsi
  __int64 mOffset; // rax
  __int64 v12; // rax
  char *v13; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v14; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v15; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HitReactionComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HitReactionComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator )
    UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator = (UFG::HitReactionComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HitReactionComponent::CleanUpHitRecords(this);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActionTreeComponent);
  UFG::HitRecord::~HitRecord(&this->mHitRecord);
  p_mAttacker = &this->mIncomingAttackInfo.mAttacker;
  if ( this->mIncomingAttackInfo.mAttacker.m_pPointer )
  {
    v6 = p_mAttacker->mPrev;
    v7 = this->mIncomingAttackInfo.mAttacker.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mAttacker->mPrev = p_mAttacker;
    this->mIncomingAttackInfo.mAttacker.mNext = &this->mIncomingAttackInfo.mAttacker;
  }
  this->mIncomingAttackInfo.mAttacker.m_pPointer = 0i64;
  v8 = p_mAttacker->mPrev;
  v9 = this->mIncomingAttackInfo.mAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mAttacker->mPrev = p_mAttacker;
  this->mIncomingAttackInfo.mAttacker.mNext = &this->mIncomingAttackInfo.mAttacker;
  p_mHitReactionOpeningBranchFullPath = &this->mHitReactionOpeningBranchFullPath;
  if ( this->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
  {
    mOffset = this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_mHitReactionOpeningBranchFullPath->mPath.mData + mOffset) )
    {
      v12 = this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
      if ( v12 )
        v13 = (char *)&this->mHitReactionOpeningBranchFullPath.mPath.mData + v12;
      else
        v13 = 0i64;
      operator delete[](v13);
    }
    this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
    p_mHitReactionOpeningBranchFullPath->mPath.mCount &= 0x80000000;
  }
  UFG::qSharedString::~qSharedString(&this->mHitTreeFileName);
  v14 = v2->mPrev;
  v15 = v2->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 173
// RVA: 0x553170
void __fastcall UFG::HitReactionComponent::Suspend(UFG::HitReactionComponent *this)
{
  this->m_Flags |= 2u;
  UFG::HitReactionComponent::CleanUpHitRecords(this);
}

// File Line: 180
// RVA: 0x522CE0
void __fastcall UFG::HitReactionComponent::CleanUpHitRecords(UFG::HitReactionComponent *this)
{
  UFG::HitRecord *mNext; // rbx
  UFG::HitRecord *v3; // rdi

  mNext = this->mHitRecord.mNext;
  if ( mNext )
  {
    do
    {
      v3 = mNext->mNext;
      UFG::HitRecord::~HitRecord(mNext);
      operator delete[](mNext);
      --this->mNumHits;
      mNext = v3;
    }
    while ( v3 );
    this->mHitRecord.mNext = 0i64;
  }
  else
  {
    this->mHitRecord.mNext = 0i64;
  }
}

// File Line: 205
// RVA: 0x5440F0
void __fastcall UFG::HitReactionComponent::PropertiesLoad(
        UFG::HitReactionComponent *this,
        component_HitReaction *data_ptr)
{
  const char *v4; // rdx
  __int64 mOffset; // rax
  const char *v6; // rbp
  __int64 v7; // rax
  char *v8; // rcx

  if ( !data_ptr->HitActFilename.mOffset || (v4 = (char *)data_ptr + data_ptr->HitActFilename.mOffset) == 0i64 || !*v4 )
    v4 = "Data\\Global\\Act\\HitTree.act";
  UFG::qSharedString::operator=(&this->mHitTreeFileName, v4);
  mOffset = data_ptr->HitReactionOpeningBranchFullPath.mOffset;
  if ( mOffset )
  {
    v6 = (char *)&data_ptr->HitReactionOpeningBranchFullPath + mOffset;
    if ( v6 && *v6 )
    {
      if ( this->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
      {
        v7 = this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
        if ( v7 )
        {
          v8 = (char *)&this->mHitReactionOpeningBranchFullPath.mPath.mData + v7;
          if ( v8 )
            operator delete[](v8);
        }
        this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
        this->mHitReactionOpeningBranchFullPath.mPath.mCount &= 0x80000000;
      }
      ActionPath::Append(&this->mHitReactionOpeningBranchFullPath, v6);
      this->mReceiverDamageMultiplierPct = data_ptr->HitReceiverDamageMultiplierPct;
    }
    else
    {
      this->mReceiverDamageMultiplierPct = data_ptr->HitReceiverDamageMultiplierPct;
    }
  }
  else
  {
    this->mReceiverDamageMultiplierPct = data_ptr->HitReceiverDamageMultiplierPct;
  }
}

// File Line: 234
// RVA: 0x546440
UFG::SimComponent *__fastcall UFG::HitReactionComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_HitReaction::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x220ui64, "HitReactionComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = sceneObject->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sceneObject->mpConstProperties;
    UFG::HitReactionComponent::HitReactionComponent(
      (UFG::HitReactionComponent *)v10,
      sceneObject->m_NameUID,
      (component_HitReaction *)MemImagePtr,
      &mpConstProperties->mName);
    v6 = v12;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v15 = 15;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 261
// RVA: 0x5363D0
void __fastcall UFG::HitReactionComponent::InitActionTree(UFG::HitReactionComponent *this)
{
  ActionNode *v2; // rax
  char *v3; // rax
  ActionNode *v4; // rax
  ActionNode *mHitTree; // rcx
  __int64 v6; // rax
  UFG::SimObject *m_pSimObject; // rcx
  ActionNodeRoot *v8; // rdi
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  __int64 v13; // rbx

  v2 = (ActionNode *)ActionNode::Load(this->mHitTreeFileName.mText);
  this->mHitTree = v2;
  if ( !v2 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qPrintf(
      "WARNING: HitReactionComponent::InitActionTree: Could Not Find Hit Tree: %s for SimObject: %s\n",
      this->mHitTreeFileName.mText,
      v3);
  }
  if ( (this->mHitReactionOpeningBranchFullPath.mPath.mCount & 0x7FFFFFFF) != 0 )
  {
    v4 = ActionNode::Find(&this->mHitReactionOpeningBranchFullPath, 0i64);
    if ( v4 )
      this->mHitTree = v4;
  }
  mHitTree = this->mHitTree;
  if ( mHitTree )
  {
    v6 = (__int64)mHitTree->vfptr[1].GetResourceOwner(mHitTree);
    m_pSimObject = this->m_pSimObject;
    v8 = (ActionNodeRoot *)v6;
    if ( !m_pSimObject )
    {
LABEL_8:
      m_pComponent = 0i64;
      goto LABEL_24;
    }
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
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr < size )
          {
            v13 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || (UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v13 += 16i64;
              if ( vfptr >= size )
              {
                m_pComponent = 0i64;
                goto LABEL_24;
              }
            }
            m_pComponent = *(UFG::SimComponent **)v13;
            goto LABEL_24;
          }
          goto LABEL_8;
        }
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
    }
LABEL_24:
    if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&m_pComponent[1], v8) )
      ActionNodeRoot::Init(v8, (ActionContext *)m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
  }
}

// File Line: 295
// RVA: 0x53E110
void __fastcall UFG::HitReactionComponent::OnAttach(UFG::HitReactionComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v9; // [rsp+30h] [rbp-18h] BYREF

  p_mActionTreeComponent = &this->mActionTreeComponent;
  if ( p_mActionTreeComponent->m_pSimComponent )
  {
    mPrev = p_mActionTreeComponent->mPrev;
    mNext = p_mActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mActionTreeComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mActionTreeComponent->m_pSimObject = 0i64;
    p_mActionTreeComponent->mNext = p_mActionTreeComponent;
    p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
    goto LABEL_8;
  }
  if ( p_mActionTreeComponent->m_pSimObject
    && (p_mActionTreeComponent->mPrev != p_mActionTreeComponent
     || p_mActionTreeComponent->mNext != p_mActionTreeComponent) )
  {
    v7 = p_mActionTreeComponent->mPrev;
    v8 = p_mActionTreeComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mActionTreeComponent->m_Changed = 1;
  p_mActionTreeComponent->m_pSimObject = object;
  p_mActionTreeComponent->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(
    p_mActionTreeComponent,
    object);
  v9.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v9.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::HitReactionComponent::TargetSphereEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v9,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

// File Line: 301
// RVA: 0x540710
void __fastcall UFG::HitReactionComponent::OnDetach(UFG::HitReactionComponent *this)
{
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_mActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v7; // [rsp+20h] [rbp-18h] BYREF

  v7.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::HitReactionComponent::TargetSphereEventHandler;
  v7.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    &v7,
    UFG::gBulletImpactDamageSphereEventChannel.mUID);
  p_mActionTreeComponent = &this->mActionTreeComponent;
  if ( this->mActionTreeComponent.m_pSimComponent )
  {
    mPrev = p_mActionTreeComponent->mPrev;
    mNext = this->mActionTreeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mActionTreeComponent.m_pSimObject = 0i64;
    this->mActionTreeComponent.mNext = &this->mActionTreeComponent;
    p_mActionTreeComponent->mPrev = p_mActionTreeComponent;
    goto LABEL_8;
  }
  if ( this->mActionTreeComponent.m_pSimObject
    && (p_mActionTreeComponent->mPrev != p_mActionTreeComponent
     || this->mActionTreeComponent.mNext != &this->mActionTreeComponent) )
  {
    v5 = p_mActionTreeComponent->mPrev;
    v6 = this->mActionTreeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  this->mActionTreeComponent.m_Changed = 1;
  this->mHitTree = 0i64;
  UFG::HitReactionComponent::CleanUpHitRecords(this);
}

// File Line: 309
// RVA: 0x549810
void __fastcall UFG::HitReactionComponent::Reset(UFG::HitReactionComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  __int64 v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  __int64 *v7; // rcx
  __int64 **v8; // rax
  __int64 *v9; // rcx
  __int64 **v10; // rax
  __int64 *v11; // [rsp+30h] [rbp-30h] BYREF
  __int64 **v12; // [rsp+38h] [rbp-28h]
  __int64 v13; // [rsp+40h] [rbp-20h]
  __int64 v14; // [rsp+48h] [rbp-18h]
  int v15; // [rsp+50h] [rbp-10h]

  this->mStateVariables = (UFG::HitReactionComponent::StateVariables)1148846080i64;
  this->mHitRecordProcessing = 0;
  v11 = (__int64 *)&v11;
  v12 = &v11;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 1000;
  this->mIncomingAttackInfo.mAttackPhaseEnum = eATTACK_PHASE_INVALID;
  this->mIncomingAttackInfo.mAttackTypeID = 0;
  p_mAttacker = &this->mIncomingAttackInfo.mAttacker;
  v3 = v13;
  if ( this->mIncomingAttackInfo.mAttacker.m_pPointer )
  {
    mPrev = p_mAttacker->mPrev;
    mNext = p_mAttacker->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttacker->mPrev = p_mAttacker;
    p_mAttacker->mNext = p_mAttacker;
  }
  p_mAttacker->m_pPointer = (UFG::SimObject *)v3;
  if ( v3 )
  {
    v6 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v3 + 8);
    v6->mNext = p_mAttacker;
    p_mAttacker->mPrev = v6;
    p_mAttacker->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v3 + 8);
    *(_QWORD *)(v3 + 8) = p_mAttacker;
  }
  *(_QWORD *)&this->mIncomingAttackInfo.mAttackLocationLateralID = v14;
  this->mIncomingAttackInfo.mTimeSinceUpdated = v15;
  if ( v13 )
  {
    v7 = v11;
    v8 = v12;
    v11[1] = (__int64)v12;
    *v8 = v7;
    v11 = (__int64 *)&v11;
    v12 = &v11;
  }
  v13 = 0i64;
  v9 = v11;
  v10 = v12;
  v11[1] = (__int64)v12;
  *v10 = v9;
  v11 = (__int64 *)&v11;
  v12 = &v11;
  if ( this->mNumHits > 1 )
    UFG::HitReactionComponent::CleanUpHitRecords(this);
  UFG::HitRecord::Reset(&this->mHitRecord);
  this->mHitRecord.mHitRecordProcessed = 1;
  this->mHitTree = 0i64;
}

// File Line: 330
// RVA: 0x55B840
void __fastcall UFG::HitReactionComponent::Update(UFG::HitReactionComponent *this, float delta_sec)
{
  char *v3; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  float v6; // xmm0_4
  UFG::UpdateInterfaceVtbl *vfptr; // rcx
  ActionNode *v8; // rax
  ActionNodePlayable *v9; // rsi
  int mCount; // edx
  UEL::ParametersBase *v11; // rbp
  UFG::SimObject *v12; // r8
  __int16 m_Flags; // cx
  UEL::ParametersBase *m_pComponent; // rax
  unsigned int v15; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  char *v18; // rax
  ActionPath pathToPopulate; // [rsp+28h] [rbp-30h] BYREF

  if ( UFG::HitReactionComponent::msUpdating )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[-1].mActionTreeComponent.m_pSimObject->m_Name);
    UFG::qPrintf("HitReactionComponent: skipping duplicate Update() for SimObject: %s\n", v3);
  }
  else
  {
    UFG::HitReactionComponent::msUpdating = 1;
    Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    m_pSimObject = this[-1].mActionTreeComponent.m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    }
    v6 = *(float *)&this->m_TypeUID;
    if ( v6 < 3.4028235e38 )
      *(float *)&this->m_TypeUID = v6 + delta_sec;
    if ( !LOBYTE(this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset) )
    {
      if ( !this->UFG::UpdateInterface::vfptr )
        UFG::HitReactionComponent::InitActionTree((UFG::HitReactionComponent *)((char *)this - 64));
      vfptr = this->UFG::UpdateInterface::vfptr;
      if ( vfptr )
      {
        v8 = (ActionNode *)(*((__int64 (__fastcall **)(UFG::UpdateInterfaceVtbl *, _QWORD))vfptr->Update + 25))(
                             vfptr,
                             *(_QWORD *)(*(_QWORD *)&this->mHitRecord.mDistanceFromExplosionSquared + 184i64));
        v9 = (ActionNodePlayable *)v8;
        if ( v8 )
        {
          if ( UFG::HitReactionComponent::msSpewHitReactions )
          {
            pathToPopulate.mPath.mCount = 0;
            pathToPopulate.mPath.mData.mOffset = 0i64;
            ActionNode::GetNameFullPath(v8, &pathToPopulate);
            mCount = pathToPopulate.mPath.mCount;
            if ( pathToPopulate.mPath.mCount >= 0 )
            {
              if ( pathToPopulate.mPath.mData.mOffset
                && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                + pathToPopulate.mPath.mData.mOffset) )
              {
                operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                mCount = pathToPopulate.mPath.mCount;
              }
              pathToPopulate.mPath.mData.mOffset = 0i64;
              pathToPopulate.mPath.mCount = mCount & 0x80000000;
            }
          }
          v11 = UEL::gCurrentParameters;
          v12 = this[-1].mActionTreeComponent.m_pSimObject;
          if ( v12 )
          {
            m_Flags = v12->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              m_pComponent = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
            }
            else if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 )
              {
                m_pComponent = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
              }
              else if ( (m_Flags & 0x1000) != 0 )
              {
                v15 = (unsigned int)v12[1].vfptr;
                size = v12->m_Components.size;
                if ( v15 >= size )
                {
LABEL_34:
                  m_pComponent = 0i64;
                }
                else
                {
                  p = v12->m_Components.p;
                  while ( (p[v15].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                       || (UFG::UELComponent::_TypeUID & ~p[v15].m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    if ( ++v15 >= size )
                      goto LABEL_34;
                  }
                  m_pComponent = (UEL::ParametersBase *)p[v15].m_pComponent;
                }
              }
              else
              {
                m_pComponent = (UEL::ParametersBase *)UFG::SimObject::GetComponentOfType(
                                                        this[-1].mActionTreeComponent.m_pSimObject,
                                                        UFG::UELComponent::_TypeUID);
              }
            }
            else
            {
              m_pComponent = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
            }
            if ( m_pComponent )
              UEL::gCurrentParameters = m_pComponent + 88;
          }
          ActionController::PlayTracks(
            (ActionController *)(*(_QWORD *)&this->mHitRecord.mDistanceFromExplosionSquared + 0xC0i64),
            v9,
            0,
            0.0);
          LOBYTE(this->m_Flags) = 1;
          ActionController::Update(
            (ActionController *)(*(_QWORD *)&this->mHitRecord.mDistanceFromExplosionSquared + 192i64),
            0.0);
          LOBYTE(this->m_Flags) = 0;
          UEL::gCurrentParameters = v11;
        }
        else
        {
          v18 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[-1].mActionTreeComponent.m_pSimObject->m_Name);
          UFG::qPrintf("HandleHitReaction: %s NO MATCH\n", v18);
        }
        LOBYTE(this->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset) = 1;
      }
    }
    *(float *)&this->mIncomingAttackInfo.mAttacker.m_pPointer = delta_sec
                                                              + *(float *)&this->mIncomingAttackInfo.mAttacker.m_pPointer;
    ++HIDWORD(this->mIncomingAttackInfo.mAttacker.m_pPointer);
    if ( ++this->mHitReactionOpeningBranchFullPath.mPath.mCount > 1 )
      LODWORD(this->mPrev) = 0;
    UFG::HitReactionComponent::msUpdating = 0;
  }
}

// File Line: 525
// RVA: 0x521420
void __fastcall UFG::HitReactionComponent::AddToCurrentHitRecord(
        UFG::HitReactionComponent *this,
        UFG::HitRecord *hitrecord)
{
  UFG::allocator::free_link *v4; // rax
  UFG::HitRecord *v5; // rax
  UFG::HitRecord *v6; // rbx
  UFG::HitRecord *mNext; // rax

  ++this->mNumHits;
  v4 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
  if ( v4 )
  {
    UFG::HitRecord::HitRecord((UFG::HitRecord *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::HitRecord::operator=(v6, hitrecord);
  mNext = this->mHitRecord.mNext;
  this->mHitRecord.mNext = v6;
  v6->mNext = mNext;
}

// File Line: 546
// RVA: 0x54D4E0
void __fastcall UFG::HitReactionComponent::SetHitRecord(UFG::HitReactionComponent *this, UFG::HitRecord *hitrecord)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  __int64 v9; // rdi
  unsigned int v10; // edx
  unsigned int v11; // r8d
  UFG::SimObject *m_pPointer; // rdx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // cl
  __int64 v15; // rbx
  __int64 v16; // rax

  if ( this->mNumHits > 1 )
    UFG::HitReactionComponent::CleanUpHitRecords(this);
  UFG::HitRecord::operator=(&this->mHitRecord, hitrecord);
  m_pSimObject = this->m_pSimObject;
  this->mNumHits = 1;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_14;
        }
LABEL_15:
        m_pComponent = *(UFG::SimComponent **)v9;
        goto LABEL_24;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
        if ( m_pComponent )
        {
          m_pPointer = this->mHitRecord.mAttacker.m_pPointer;
          if ( m_pPointer )
          {
            v13 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 10i64);
            if ( v13 )
              UFG::TargetingSimObject::SetTarget(
                (UFG::TargetingSimObject *)(*(_QWORD *)&m_pComponent[1].m_TypeUID + 56i64 * v13),
                m_pPointer);
          }
          else
          {
            v14 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 10i64);
            if ( v14 )
            {
              v15 = 56i64 * v14;
              UFG::TargetingSimObject::SetTarget(
                (UFG::TargetingSimObject *)(v15 + *(_QWORD *)&m_pComponent[1].m_TypeUID),
                0i64);
              v16 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
              if ( *(_BYTE *)(v15 + v16 + 49) )
                *(_BYTE *)(v15 + v16 + 49) = 0;
            }
          }
        }
        return;
      }
      v10 = (unsigned int)m_pSimObject[1].vfptr;
      v11 = m_pSimObject->m_Components.size;
      if ( v10 < v11 )
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[v10];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v10;
          v9 += 16i64;
          if ( v10 >= v11 )
          {
            m_pComponent = 0i64;
            goto LABEL_24;
          }
        }
        goto LABEL_15;
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
}

// File Line: 593
// RVA: 0x534420
void __fastcall UFG::HitReactionComponent::HandleHitReaction(
        UFG::HitReactionComponent *this,
        UFG::HitRecord *hitrecord)
{
  int mAttackTypeID; // r8d
  bool v3; // al
  bool v4; // r8

  if ( this->mHitRecord.mHitRecordProcessed )
    goto LABEL_8;
  mAttackTypeID = hitrecord->mAttackTypeID;
  v3 = mAttackTypeID == gAttackCollisionProjectile.m_EnumValue
    && this->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
  v4 = mAttackTypeID > this->mHitRecord.mAttackTypeID;
  if ( v3 )
  {
    UFG::HitReactionComponent::AddToCurrentHitRecord(this, hitrecord);
  }
  else if ( v4 )
  {
LABEL_8:
    UFG::HitReactionComponent::SetHitRecord(this, hitrecord);
  }
}

// File Line: 653
// RVA: 0x534470
void __fastcall UFG::HitReactionComponent::HandleIncomingAttack(
        UFG::HitReactionComponent *this,
        UFG::IncomingAttackInfo *incomingAttackInfo)
{
  UFG::SimObject *m_pSimObject; // rax

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
    UFG::IncomingAttackInfo::operator=(&this->mIncomingAttackInfo, incomingAttackInfo);
}

// File Line: 663
// RVA: 0x5566D0
void __fastcall UFG::HitReactionComponent::TargetSphereEventHandler(UFG::HitReactionComponent *this, UFG::Event *e)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *ComponentOfType; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v9; // rdx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::qVector3 v15; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 v16; // [rsp+40h] [rbp-18h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_18;
  if ( (m_pSimObject->m_Flags & 0x400) != 0 )
    return;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_18;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
LABEL_18:
      if ( *(UFG::SimObject **)(e[2].mUserData0 + 48) == this->m_pSimObject )
      {
        v10 = *((float *)&e[2].mPrev + 1);
        v15.x = *(float *)&e[2].mPrev;
        v11 = *(float *)&e[2].mNext;
        v15.y = v10;
        v12 = *((float *)&e[2].mNext + 1);
        v15.z = v11;
        v13 = *(float *)&e[2].m_EventUID;
        v16.x = v12;
        v14 = *((float *)&e[2].m_EventUID + 1);
        v16.y = v13;
        v16.z = v14;
        UFG::HitReactionComponent::ApplyBulletImpactImpulse(this, &v16, &v15, (UFG::ProjectileInfo *)&e[1].m_EventUID);
      }
      return;
    }
    if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_13:
        ComponentOfType = 0i64;
      }
      else
      {
        v9 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || (UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v9 += 16i64;
          if ( vfptr >= size )
            goto LABEL_13;
        }
        ComponentOfType = *(UFG::PhysicsMoverInterface **)v9;
      }
    }
    else
    {
      ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
  }
  if ( !ComponentOfType
    || !UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(
          ComponentOfType,
          (UFG::SimObject *)e[1].mNext) )
  {
    goto LABEL_18;
  }
}

// File Line: 690
// RVA: 0x5218A0
void __fastcall UFG::HitReactionComponent::ApplyBulletImpactImpulse(
        UFG::HitReactionComponent *this,
        UFG::qVector3 *vPoint,
        UFG::qVector3 *vBulletVelocity,
        UFG::ProjectileInfo *projectileInfo)
{
  float y; // xmm8_4
  __m128 x_low; // xmm10
  float z; // xmm9_4
  __m128 v11; // xmm2
  float v12; // xmm3_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  float v15; // xmm10_4
  UFG::HitRecord *v16; // rsi
  int v17; // ebx
  UFG::SimComponent *m_pPointer; // rax
  float v19; // xmm0_4
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v25; // rdx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v27; // r8d
  unsigned int v28; // r9d
  unsigned int v29; // r8d
  unsigned int v30; // r9d
  unsigned int v31; // r8d
  unsigned int v32; // r9d
  UFG::SimComponent *v33; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  int v35; // ebx
  bool IsAnyLocalPlayer; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  float v40; // xmm7_4
  __m128 v41; // xmm5
  float v42; // xmm6_4
  __m128 v43; // xmm2
  float v44; // xmm4_4
  float v45; // xmm1_4
  UFG::SimComponent *v46; // rdx
  __int64 v47; // rcx
  _QWORD *v48; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v49; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::HitRecord *v52; // rax
  UFG::HitRecord *v53; // rax
  UFG::HitRecord __that; // [rsp+20h] [rbp-B8h] BYREF
  UFG::allocator::free_link *retaddr; // [rsp+1D8h] [rbp+100h]
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v56; // [rsp+1E0h] [rbp+108h]

  *(_QWORD *)&__that.mDistanceFromExplosionSquared = -2i64;
  y = vBulletVelocity->y;
  x_low = (__m128)LODWORD(vBulletVelocity->x);
  z = vBulletVelocity->z;
  v11 = x_low;
  v11.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  v12 = 0.0;
  if ( v11.m128_f32[0] != 0.0 )
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v13 = z * v12;
  v14 = y * v12;
  v15 = x_low.m128_f32[0] * v12;
  v16 = 0i64;
  v17 = 0;
  m_pPointer = projectileInfo->m_pSOWPC.m_pPointer;
  if ( m_pPointer )
  {
    v19 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                     + HIDWORD(m_pPointer[2].m_pSimObject))
                   + 92i64);
    v15 = v15 * v19;
    v14 = v14 * v19;
    v13 = v13 * v19;
    m_pSimObject = this->m_pSimObject;
    if ( !m_pSimObject )
    {
LABEL_38:
      v33 = projectileInfo->m_pSOWPC.m_pPointer;
      mPrev = v33[2].m_BoundComponentHandles.mNode.mPrev;
      v35 = (int)(float)(*(float *)(*((_QWORD *)&mPrev->mNext + HIDWORD(v33[2].m_pSimObject)) + 140i64) * 100.0);
      if ( projectileInfo->m_bIsHardLocked )
        v35 = (int)(float)((float)v35 * *(float *)(*((_QWORD *)&mPrev->mNext + HIDWORD(v33[2].m_pSimObject)) + 132i64));
      IsAnyLocalPlayer = UFG::IsAnyLocalPlayer((UFG::SimObjectCharacter *)retaddr);
      v17 = (int)(float)((float)v35
                       * UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileDamage(
                           (UFG::SimObjectWeaponPropertiesComponent *)projectileInfo->m_pSOWPC.m_pPointer,
                           !IsAnyLocalPlayer));
      goto LABEL_41;
    }
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        p = m_pSimObject->m_Components.p;
        while ( 1 )
        {
          v25 = vfptr;
          if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && (UFG::RigidBodyComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++vfptr >= size )
            goto LABEL_13;
        }
LABEL_12:
        m_pComponent = p[v25].m_pComponent;
        goto LABEL_36;
      }
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v29 = (unsigned int)m_pSimObject[1].vfptr;
        v30 = m_pSimObject->m_Components.size;
        if ( v29 < v30 )
        {
          p = m_pSimObject->m_Components.p;
          do
          {
            v25 = v29;
            if ( (p[v29].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~p[v29].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_12;
            }
          }
          while ( ++v29 < v30 );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::RigidBodyComponent::_TypeUID);
LABEL_36:
          if ( m_pComponent )
          {
            v17 = (int)(float)(*(float *)(*((_QWORD *)&projectileInfo->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                          + HIDWORD(projectileInfo->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                        + 144i64)
                             * 100.0);
            goto LABEL_41;
          }
          goto LABEL_38;
        }
        v31 = (unsigned int)m_pSimObject[1].vfptr;
        v32 = m_pSimObject->m_Components.size;
        if ( v31 < v32 )
        {
          p = m_pSimObject->m_Components.p;
          do
          {
            v25 = v31;
            if ( (p[v31].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && (UFG::RigidBodyComponent::_TypeUID & ~p[v31].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_12;
            }
          }
          while ( ++v31 < v32 );
        }
      }
    }
    else
    {
      v27 = (unsigned int)m_pSimObject[1].vfptr;
      v28 = m_pSimObject->m_Components.size;
      if ( v27 < v28 )
      {
        p = m_pSimObject->m_Components.p;
        do
        {
          v25 = v27;
          if ( (p[v27].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && (UFG::RigidBodyComponent::_TypeUID & ~p[v27].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_12;
          }
        }
        while ( ++v27 < v28 );
      }
    }
LABEL_13:
    m_pComponent = 0i64;
    goto LABEL_36;
  }
LABEL_41:
  if ( projectileInfo->m_bIsFullyAccurate )
    v17 = (int)(float)((float)v17
                     * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFullyAccurateDamageMultiplier);
  UFG::HitRecord::HitRecord(&__that);
  __that.mAttackTypeID = gAttackCollisionProjectile.m_EnumValue;
  __that.mDamage = v17;
  if ( __that.mAttacker.m_pPointer )
  {
    v37 = __that.mAttacker.mPrev;
    mNext = __that.mAttacker.mNext;
    __that.mAttacker.mPrev->mNext = __that.mAttacker.mNext;
    mNext->mPrev = v37;
    __that.mAttacker.mPrev = &__that.mAttacker;
    __that.mAttacker.mNext = &__that.mAttacker;
  }
  __that.mAttacker.m_pPointer = (UFG::SimObject *)retaddr;
  if ( retaddr )
  {
    v39 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)retaddr[1].mNext;
    v39->mNext = &__that.mAttacker;
    __that.mAttacker.mPrev = v39;
    __that.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&retaddr[1];
    retaddr[1].mNext = (UFG::allocator::free_link *)&__that.mAttacker;
  }
  *(_QWORD *)&__that.mTimeSinceHit = 0i64;
  v40 = vBulletVelocity->y;
  v41 = (__m128)LODWORD(vBulletVelocity->x);
  v42 = vBulletVelocity->z;
  v43 = v41;
  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
  LODWORD(v44) = _mm_sqrt_ps(v43).m128_u32[0];
  __that.mProjectileInfo.m_pSOWPC.mPrev = v56;
  memset(&__that.mProjectileInfo.m_pSOWPC.mNext, 0, 24);
  v45 = vPoint->y;
  v43.m128_i32[0] = LODWORD(vPoint->z);
  *(float *)&__that.mProjectileInfo.m_bIsFullyAccurate = vPoint->x;
  *(float *)(&__that.mProjectileInfo.m_bIsHardLocked + 3) = v45;
  __that.mCollisionInfo.mPhysicsObjectPropertyHandleUID = __PAIR64__(LODWORD(v15), v43.m128_u32[0]);
  __that.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = __PAIR64__(LODWORD(v13), LODWORD(v14));
  __that.mCollisionInfo.mSurfacePropertyHandleUID = __PAIR64__(LODWORD(v40), v41.m128_u32[0]);
  __that.mCollisionInfo.mAttackerSurfacePropertyHandleUID = __PAIR64__(LODWORD(v44), LODWORD(v42));
  __that.mCollisionInfo.mHitLocation.x = v44;
  __that.mCollisionInfo.mHitLocation.y = FLOAT_N1_0;
  v46 = projectileInfo->m_pSOWPC.m_pPointer;
  if ( *(_QWORD *)&__that.mMeleeInfo.mHitNormal.z )
  {
    v47 = *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y;
    v48 = *(_QWORD **)&__that.mMeleeInfo.mHitNormal.x;
    *(_QWORD *)(*(_QWORD *)&__that.mMeleeInfo.mHitDirection.y + 8i64) = *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x;
    *v48 = v47;
    *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y = &__that.mMeleeInfo.mHitDirection.y;
    *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x = &__that.mMeleeInfo.mHitDirection.y;
  }
  *(_QWORD *)&__that.mMeleeInfo.mHitNormal.z = v46;
  if ( v46 )
  {
    v49 = v46->m_SafePointerList.mNode.mPrev;
    v49->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&__that.mMeleeInfo.mHitDirection.y;
    *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y = v49;
    *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x = &v46->m_SafePointerList;
    v46->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&__that.mMeleeInfo.mHitDirection.y;
  }
  *(_QWORD *)&__that.mMeleeInfo.mActionPath.mPath.mCount = projectileInfo->m_pSubTargetingLocation;
  LOWORD(__that.mMeleeInfo.mActionPath.mPath.mData.mOffset) = *(_WORD *)&projectileInfo->m_bIsFullyAccurate;
  if ( this->mHitRecord.mHitRecordProcessed )
    goto LABEL_61;
  if ( __that.mAttackTypeID != gAttackCollisionProjectile.m_EnumValue
    || this->mHitRecord.mAttackTypeID != gAttackCollisionProjectile.m_EnumValue )
  {
    if ( __that.mAttackTypeID <= this->mHitRecord.mAttackTypeID )
      goto LABEL_62;
LABEL_61:
    UFG::HitReactionComponent::SetHitRecord(this, &__that);
    goto LABEL_62;
  }
  ++this->mNumHits;
  v51 = UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
  retaddr = v51;
  if ( v51 )
  {
    UFG::HitRecord::HitRecord((UFG::HitRecord *)v51);
    v16 = v52;
  }
  UFG::HitRecord::operator=(v16, &__that);
  v53 = this->mHitRecord.mNext;
  this->mHitRecord.mNext = v16;
  v16->mNext = v53;
LABEL_62:
  UFG::HitRecord::~HitRecord(&__that);
}

// File Line: 733
// RVA: 0x549970
void __fastcall UFG::HitRecord::Reset(UFG::HitRecord *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::ProjectileInfo *p_mProjectileInfo; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  p_mAttacker = &this->mAttacker;
  this->mTimeSinceHit = 1000.0;
  this->mFramesSinceHit = 1000;
  this->mEffectBone = -1;
  this->mDistanceFromExplosionSquared = -1.0;
  *(_QWORD *)&this->mAttackTypeID = 0i64;
  *(_DWORD *)&this->mHitRecordProcessed = 0;
  this->mExplosionInfo = 0i64;
  this->mNext = 0i64;
  if ( this->mAttacker.m_pPointer )
  {
    mPrev = p_mAttacker->mPrev;
    mNext = p_mAttacker->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttacker->mPrev = p_mAttacker;
    p_mAttacker->mNext = p_mAttacker;
  }
  p_mAttacker->m_pPointer = 0i64;
  this->mAttackerNetworkID = 0;
  this->mEffectBone = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mEffectOffset.x = UFG::qVector3::msZero.x;
  this->mEffectOffset.y = y;
  this->mEffectOffset.z = z;
  this->mCollisionInfo.mPhysicsObjectPropertyHandleUID = 0i64;
  this->mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = 0i64;
  this->mCollisionInfo.mSurfacePropertyHandleUID = 0i64;
  this->mCollisionInfo.mAttackerSurfacePropertyHandleUID = 0i64;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->mCollisionInfo.mHitLocation.x = UFG::qVector3::msZero.x;
  this->mCollisionInfo.mHitLocation.y = v7;
  this->mCollisionInfo.mHitLocation.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mCollisionInfo.mHitImpulse.x = UFG::qVector3::msZero.x;
  this->mCollisionInfo.mHitImpulse.y = v9;
  this->mCollisionInfo.mHitImpulse.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mCollisionInfo.mOtherVelocity.x = UFG::qVector3::msZero.x;
  this->mCollisionInfo.mOtherVelocity.y = v11;
  this->mCollisionInfo.mOtherVelocity.z = v12;
  *(_QWORD *)&this->mCollisionInfo.mSpeed = 0i64;
  this->mCollisionInfo.mEstimatedImpulseMagnitude = -1.0;
  UFG::MeleeInfo::Reset(&this->mMeleeInfo);
  p_mProjectileInfo = &this->mProjectileInfo;
  if ( p_mProjectileInfo->m_pSOWPC.m_pPointer )
  {
    v14 = p_mProjectileInfo->m_pSOWPC.mPrev;
    v15 = p_mProjectileInfo->m_pSOWPC.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_mProjectileInfo->m_pSOWPC.mPrev = &p_mProjectileInfo->m_pSOWPC;
    p_mProjectileInfo->m_pSOWPC.mNext = &p_mProjectileInfo->m_pSOWPC;
  }
  p_mProjectileInfo->m_pSOWPC.m_pPointer = 0i64;
  p_mProjectileInfo->m_pSubTargetingLocation = 0i64;
  *(_WORD *)&p_mProjectileInfo->m_bIsFullyAccurate = 0;
}

// File Line: 761
// RVA: 0x517BF0
void __fastcall UFG::HitRecord::HitRecord(UFG::HitRecord *this)
{
  UFG::ProjectileInfo *p_mProjectileInfo; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mAttacker.mPrev = &this->mAttacker;
  this->mAttacker.mNext = &this->mAttacker;
  this->mAttacker.m_pPointer = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mAttackLocationLateralID = 0i64;
  this->mMeleeInfo.mAttackFromBehind = 0;
  *(_QWORD *)&this->mMeleeInfo.mAttackMaterialUID = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mAttackIntensityUID = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mHitPosition.y = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mHitDirection.x = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mHitDirection.z = 0i64;
  *(_QWORD *)&this->mMeleeInfo.mHitNormal.y = 0i64;
  this->mMeleeInfo.mActionPath.mPath.mCount = 0;
  this->mMeleeInfo.mActionPath.mPath.mData.mOffset = 0i64;
  p_mProjectileInfo = &this->mProjectileInfo;
  this->mProjectileInfo.m_pSOWPC.mPrev = &this->mProjectileInfo.m_pSOWPC;
  this->mProjectileInfo.m_pSOWPC.mNext = &this->mProjectileInfo.m_pSOWPC;
  this->mProjectileInfo.m_pSOWPC.m_pPointer = 0i64;
  if ( this->mProjectileInfo.m_pSOWPC.m_pPointer )
  {
    mPrev = p_mProjectileInfo->m_pSOWPC.mPrev;
    mNext = p_mProjectileInfo->m_pSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mProjectileInfo->m_pSOWPC.mPrev = &p_mProjectileInfo->m_pSOWPC;
    p_mProjectileInfo->m_pSOWPC.mNext = &p_mProjectileInfo->m_pSOWPC;
  }
  p_mProjectileInfo->m_pSOWPC.m_pPointer = 0i64;
  p_mProjectileInfo->m_pSubTargetingLocation = 0i64;
  *(_WORD *)&p_mProjectileInfo->m_bIsFullyAccurate = 0;
  UFG::HitRecord::Reset(this);
}

