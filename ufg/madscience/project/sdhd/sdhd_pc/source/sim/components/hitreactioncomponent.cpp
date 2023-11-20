// File Line: 91
// RVA: 0x1543EC0
__int64 dynamic_initializer_for__UFG::HitReactionComponent::s_HitReactionComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::HitReactionComponent::s_HitReactionComponentList__);
}

// File Line: 92
// RVA: 0x52CA30
UFG::ComponentIDDesc *__fastcall UFG::HitReactionComponent::GetDesc(UFG::HitReactionComponent *this)
{
  return &UFG::HitReactionComponent::_TypeIDesc;
}

// File Line: 108
// RVA: 0x517A50
void __fastcall UFG::HitReactionComponent::HitReactionComponent(UFG::HitReactionComponent *this, unsigned int name_uid, component_HitReaction *data_ptr, UFG::qSymbol *propSetName)
{
  component_HitReaction *v4; // rbp
  UFG::HitReactionComponent *v5; // rdi
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v6; // rbx
  signed __int64 v7; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // ST28_8
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v9; // rax
  __int64 v10; // rax
  char *v11; // rcx
  char v12; // cl

  v4 = data_ptr;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable';
  v6 = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HitReactionComponent::`vftable'{for `UFG::SimComponent'};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HitReactionComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::qSharedString::qSharedString(&v5->mHitTreeFileName);
  v7 = (signed __int64)&v5->mHitReactionOpeningBranchFullPath;
  *(_DWORD *)v7 = 0;
  *(_QWORD *)(v7 + 8) = 0i64;
  v5->mHitTree = 0i64;
  *(_QWORD *)&v5->mIncomingAttackInfo.mAttackPhaseEnum = 0i64;
  v8 = &v5->mIncomingAttackInfo.mAttacker;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v5->mIncomingAttackInfo.mAttacker.m_pPointer = 0i64;
  *(_QWORD *)&v5->mIncomingAttackInfo.mAttackLocationLateralID = 0i64;
  v5->mIncomingAttackInfo.mTimeSinceUpdated = 1000;
  UFG::HitRecord::HitRecord(&v5->mHitRecord);
  v5->mNumHits = 0;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v5->mActionTreeComponent);
  v9 = UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev;
  UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&v5->mPrev;
  v6->mPrev = v9;
  v5->mNext = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&UFG::HitReactionComponent::s_HitReactionComponentList;
  UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mPrev = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::HitReactionComponent::_HitReactionComponentTypeUID,
    "HitReactionComponent");
  if ( v5->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
  {
    v10 = v5->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
    if ( v10 )
    {
      v11 = (char *)&v5->mHitReactionOpeningBranchFullPath.mPath.mData + v10;
      if ( v11 )
        operator delete[](v11);
    }
    v5->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
    *(_DWORD *)v7 &= 0x80000000;
  }
  ActionPath::Append(&v5->mHitReactionOpeningBranchFullPath, &customWorldMapCaption);
  if ( v4 )
  {
    UFG::HitReactionComponent::PropertiesLoad(v5, v4);
  }
  else
  {
    UFG::qSharedString::operator=(&v5->mHitTreeFileName, "Data\\Act\\HitTree.act");
    v5->mReceiverDamageMultiplierPct = 100;
  }
  v12 = tweaks_added_0;
  if ( !tweaks_added_0 )
    v12 = 1;
  tweaks_added_0 = v12;
  UFG::HitReactionComponent::Reset(v5);
  v5->mWasProxy = 0;
}

// File Line: 166
// RVA: 0x51BA30
void __fastcall UFG::HitReactionComponent::~HitReactionComponent(UFG::HitReactionComponent *this)
{
  UFG::HitReactionComponent *v1; // rbx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v2; // rdi
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v3; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  ActionPath *v10; // rsi
  __int64 v11; // rax
  __int64 v12; // rax
  char *v13; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v14; // rcx
  UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *v15; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HitReactionComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HitReactionComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator )
    UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator = (UFG::HitReactionComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::HitReactionComponent,UFG::HitReactionComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HitReactionComponent::CleanUpHitRecords(v1);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActionTreeComponent);
  UFG::HitRecord::~HitRecord(&v1->mHitRecord);
  v5 = &v1->mIncomingAttackInfo.mAttacker;
  if ( v1->mIncomingAttackInfo.mAttacker.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mIncomingAttackInfo.mAttacker.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mIncomingAttackInfo.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mIncomingAttackInfo.mAttacker.mPrev;
  }
  v1->mIncomingAttackInfo.mAttacker.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mIncomingAttackInfo.mAttacker.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mIncomingAttackInfo.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mIncomingAttackInfo.mAttacker.mPrev;
  v10 = &v1->mHitReactionOpeningBranchFullPath;
  if ( v1->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
  {
    v11 = v1->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
    if ( v11 && (UFG::qOffset64<ActionID *> *)((char *)&v10->mPath.mData + v11) )
    {
      v12 = v1->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
      if ( v12 )
        v13 = (char *)&v1->mHitReactionOpeningBranchFullPath.mPath.mData + v12;
      else
        v13 = 0i64;
      operator delete[](v13);
    }
    v1->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
    v10->mPath.mCount &= 0x80000000;
  }
  UFG::qSharedString::~qSharedString(&v1->mHitTreeFileName);
  v14 = v2->mPrev;
  v15 = v2->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
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
  UFG::HitRecord *v1; // rbx
  UFG::HitReactionComponent *v2; // rsi
  UFG::HitRecord *v3; // rdi

  v1 = this->mHitRecord.mNext;
  v2 = this;
  if ( v1 )
  {
    do
    {
      v3 = v1->mNext;
      UFG::HitRecord::~HitRecord(v1);
      operator delete[](v1);
      --v2->mNumHits;
      v1 = v3;
    }
    while ( v3 );
    v2->mHitRecord.mNext = 0i64;
  }
  else
  {
    this->mHitRecord.mNext = 0i64;
  }
}

// File Line: 205
// RVA: 0x5440F0
void __fastcall UFG::HitReactionComponent::PropertiesLoad(UFG::HitReactionComponent *this, component_HitReaction *data_ptr)
{
  component_HitReaction *v2; // rbx
  UFG::HitReactionComponent *v3; // rdi
  const char *v4; // rdx
  __int64 v5; // rax
  const char *v6; // rbp
  __int64 v7; // rax
  char *v8; // rcx

  v2 = data_ptr;
  v3 = this;
  if ( !data_ptr->HitActFilename.mOffset || (v4 = (char *)data_ptr + data_ptr->HitActFilename.mOffset) == 0i64 || !*v4 )
    v4 = "Data\\Global\\Act\\HitTree.act";
  UFG::qSharedString::operator=(&this->mHitTreeFileName, v4);
  v5 = v2->HitReactionOpeningBranchFullPath.mOffset;
  if ( v5 )
  {
    v6 = (char *)&v2->HitReactionOpeningBranchFullPath + v5;
    if ( v6 && *v6 )
    {
      if ( v3->mHitReactionOpeningBranchFullPath.mPath.mCount >= 0 )
      {
        v7 = v3->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset;
        if ( v7 )
        {
          v8 = (char *)&v3->mHitReactionOpeningBranchFullPath.mPath.mData + v7;
          if ( v8 )
            operator delete[](v8);
        }
        v3->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset = 0i64;
        v3->mHitReactionOpeningBranchFullPath.mPath.mCount &= 0x80000000;
      }
      ActionPath::Append(&v3->mHitReactionOpeningBranchFullPath, v6);
      v3->mReceiverDamageMultiplierPct = v2->HitReceiverDamageMultiplierPct;
    }
    else
    {
      v3->mReceiverDamageMultiplierPct = v2->HitReceiverDamageMultiplierPct;
    }
  }
  else
  {
    v3->mReceiverDamageMultiplierPct = v2->HitReceiverDamageMultiplierPct;
  }
}

// File Line: 234
// RVA: 0x546440
UFG::SimComponent *__fastcall UFG::HitReactionComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qSymbol *v11; // r9
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx
  unsigned __int16 v14; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_HitReaction::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x220ui64, "HitReactionComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = (UFG::qSymbol *)v3->mpWritableProperties;
    if ( !v11 )
      v11 = (UFG::qSymbol *)v3->mpConstProperties;
    UFG::HitReactionComponent::HitReactionComponent(
      (UFG::HitReactionComponent *)v10,
      v3->m_NameUID,
      (component_HitReaction *)v7,
      v11 + 16);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 )
    v15 = 15;
  else
    v15 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 261
// RVA: 0x5363D0
void __fastcall UFG::HitReactionComponent::InitActionTree(UFG::HitReactionComponent *this)
{
  UFG::HitReactionComponent *v1; // rbx
  Expression::IMemberMap *v2; // rax
  char *v3; // rax
  ActionNode *v4; // rax
  ActionNode *v5; // rcx
  __int64 v6; // rax
  UFG::SimObject *v7; // rcx
  ActionNodeRoot *v8; // rdi
  UFG::SimComponent *v9; // rbx
  unsigned __int16 v10; // dx
  unsigned int v11; // edx
  unsigned int v12; // er8
  signed __int64 v13; // rbx

  v1 = this;
  v2 = ActionNode::Load(this->mHitTreeFileName.mText);
  v1->mHitTree = (ActionNode *)v2;
  if ( !v2 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
    UFG::qPrintf(
      "WARNING: HitReactionComponent::InitActionTree: Could Not Find Hit Tree: '%s' for SimObject: '%s'\n",
      v1->mHitTreeFileName.mText,
      v3);
  }
  if ( v1->mHitReactionOpeningBranchFullPath.mPath.mCount & 0x7FFFFFFF )
  {
    v4 = ActionNode::Find(&v1->mHitReactionOpeningBranchFullPath, 0i64);
    if ( v4 )
      v1->mHitTree = v4;
  }
  v5 = v1->mHitTree;
  if ( v5 )
  {
    v6 = ((__int64 (__cdecl *)(ActionNode *))v5->vfptr[1].GetResourceOwner)(v5);
    v7 = v1->m_pSimObject;
    v8 = (ActionNodeRoot *)v6;
    if ( !v7 )
    {
LABEL_8:
      v9 = 0i64;
      goto LABEL_24;
    }
    v10 = v7->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v9 = v7->m_Components.p[7].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v9 = v7->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v10 >> 12) & 1 )
        {
          v11 = (unsigned int)v7[1].vfptr;
          v12 = v7->m_Components.size;
          if ( v11 < v12 )
          {
            v13 = (signed __int64)&v7->m_Components.p[v11];
            while ( (*(_DWORD *)(v13 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
                 || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v13 + 8) & 0x1FFFFFF )
            {
              ++v11;
              v13 += 16i64;
              if ( v11 >= v12 )
              {
                v9 = 0i64;
                goto LABEL_24;
              }
            }
            v9 = *(UFG::SimComponent **)v13;
            goto LABEL_24;
          }
          goto LABEL_8;
        }
        v9 = UFG::SimObject::GetComponentOfType(v7, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v9 = v7->m_Components.p[7].m_pComponent;
    }
LABEL_24:
    if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v9[1], v8) )
      ActionNodeRoot::Init(v8, (ActionContext *)v9[2].m_BoundComponentHandles.mNode.mNext);
  }
}

// File Line: 295
// RVA: 0x53E110
void __fastcall UFG::HitReactionComponent::OnAttach(UFG::HitReactionComponent *this, UFG::SimObject *object)
{
  UFG::HitReactionComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v3; // rcx
  UFG::SimObject *v4; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  hkSeekableStreamReader *v9; // [rsp+30h] [rbp-18h]
  void (__fastcall *v10)(UFG::HitReactionComponent *, UFG::Event *); // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = &this->mActionTreeComponent;
  v4 = object;
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
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v3->mNext != v3) )
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
  v3->m_TypeUID = UFG::ActionTreeComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = Assembly::GetRCX(v2);
  v10 = UFG::HitReactionComponent::TargetSphereEventHandler;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v9,
    UFG::gBulletImpactDamageSphereEventChannel.mUID,
    UFG::gBulletImpactDamageSphereEventChannel.mName,
    0);
}

// File Line: 301
// RVA: 0x540710
void __fastcall UFG::HitReactionComponent::OnDetach(UFG::HitReactionComponent *this)
{
  UFG::HitReactionComponent *v1; // rbx
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v2; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  hkSeekableStreamReader *v7; // [rsp+20h] [rbp-18h]
  void (__fastcall *v8)(UFG::HitReactionComponent *, UFG::Event *); // [rsp+28h] [rbp-10h]

  v1 = this;
  v8 = UFG::HitReactionComponent::TargetSphereEventHandler;
  v7 = Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v7,
    UFG::gBulletImpactDamageSphereEventChannel.mUID);
  v2 = &v1->mActionTreeComponent;
  if ( v1->mActionTreeComponent.m_pSimComponent )
  {
    v3 = v2->mPrev;
    v4 = v1->mActionTreeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mActionTreeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->mActionTreeComponent.m_pSimObject = 0i64;
    v1->mActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mActionTreeComponent.mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( v1->mActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v1->mActionTreeComponent.mNext != &v1->mActionTreeComponent) )
  {
    v5 = v2->mPrev;
    v6 = v1->mActionTreeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v1->mActionTreeComponent.m_Changed = 1;
  v1->mHitTree = 0i64;
  UFG::HitReactionComponent::CleanUpHitRecords(v1);
}

// File Line: 309
// RVA: 0x549810
void __fastcall UFG::HitReactionComponent::Reset(UFG::HitReactionComponent *this)
{
  UFG::HitReactionComponent *v1; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::SimObject *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  __int64 *v7; // rcx
  __int64 **v8; // rax
  __int64 *v9; // rcx
  __int64 **v10; // rax
  __int64 *v11; // [rsp+30h] [rbp-30h]
  __int64 **v12; // [rsp+38h] [rbp-28h]
  __int128 v13; // [rsp+40h] [rbp-20h]
  int v14; // [rsp+50h] [rbp-10h]

  v1 = this;
  this->mStateVariables = (UFG::HitReactionComponent::StateVariables)1148846080i64;
  this->mHitRecordProcessing = 0;
  v11 = (__int64 *)&v11;
  v12 = &v11;
  v13 = 0ui64;
  v14 = 1000;
  this->mIncomingAttackInfo.mAttackPhaseEnum = 0;
  this->mIncomingAttackInfo.mAttackTypeID = 0;
  v2 = &this->mIncomingAttackInfo.mAttacker;
  v3 = (UFG::SimObject *)v13;
  if ( this->mIncomingAttackInfo.mAttacker.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = v3;
  if ( v3 )
  {
    v6 = v3->m_SafePointerList.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mPrev = v6;
    v2->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  *(_QWORD *)&v1->mIncomingAttackInfo.mAttackLocationLateralID = *((_QWORD *)&v13 + 1);
  v1->mIncomingAttackInfo.mTimeSinceUpdated = v14;
  if ( (_QWORD)v13 )
  {
    v7 = v11;
    v8 = v12;
    v11[1] = (__int64)v12;
    *v8 = v7;
    v11 = (__int64 *)&v11;
    v12 = &v11;
  }
  *(_QWORD *)&v13 = 0i64;
  v9 = v11;
  v10 = v12;
  v11[1] = (__int64)v12;
  *v10 = v9;
  v11 = (__int64 *)&v11;
  v12 = &v11;
  if ( v1->mNumHits > 1 )
    UFG::HitReactionComponent::CleanUpHitRecords(v1);
  UFG::HitRecord::Reset(&v1->mHitRecord);
  v1->mHitRecord.mHitRecordProcessed = 1;
  v1->mHitTree = 0i64;
}

// File Line: 330
// RVA: 0x55B840
void __fastcall UFG::HitReactionComponent::Update(UFG::HitReactionComponent *this, float delta_sec)
{
  UFG::HitReactionComponent *v2; // rbx
  char *v3; // rax
  UFG::SimObject *v4; // rcx
  UFG::TransformNodeComponent *v5; // rcx
  float v6; // xmm0_4
  UFG::UpdateInterfaceVtbl *v7; // rcx
  ActionNode *v8; // rax
  ActionNodePlayable *v9; // rsi
  int v10; // edx
  UEL::ParametersBase *v11; // rbp
  UFG::SimObject *v12; // r8
  unsigned __int16 v13; // cx
  UEL::ParametersBase *v14; // rax
  unsigned int v15; // ecx
  unsigned int v16; // er9
  UFG::SimComponentHolder *v17; // rdi
  char *v18; // rax
  ActionPath pathToPopulate; // [rsp+28h] [rbp-30h]

  v2 = this;
  if ( UFG::HitReactionComponent::msUpdating )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this[-1].mActionTreeComponent.m_pSimObject->m_Name);
    UFG::qPrintf("HitReactionComponent: skipping duplicate Update() for SimObject: %s\n", v3);
  }
  else
  {
    UFG::HitReactionComponent::msUpdating = 1;
    Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    v4 = v2[-1].mActionTreeComponent.m_pSimObject;
    if ( v4 )
    {
      v5 = v4->m_pTransformNodeComponent;
      if ( v5 )
        UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    }
    v6 = *(float *)&v2->m_TypeUID;
    if ( v6 < 3.4028235e38 )
      *(float *)&v2->m_TypeUID = v6 + delta_sec;
    if ( !LOBYTE(v2->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset) )
    {
      if ( !v2->vfptr )
        UFG::HitReactionComponent::InitActionTree((UFG::HitReactionComponent *)((char *)v2 - 64));
      v7 = v2->vfptr;
      if ( v7 )
      {
        v8 = (ActionNode *)(*((__int64 (__fastcall **)(UFG::UpdateInterfaceVtbl *, _QWORD))v7->Update + 25))(
                             v7,
                             *(_QWORD *)(*(_QWORD *)&v2->mHitRecord.mDistanceFromExplosionSquared + 184i64));
        v9 = (ActionNodePlayable *)v8;
        if ( v8 )
        {
          if ( UFG::HitReactionComponent::msSpewHitReactions )
          {
            pathToPopulate.mPath.mCount = 0;
            pathToPopulate.mPath.mData.mOffset = 0i64;
            ActionNode::GetNameFullPath(v8, &pathToPopulate);
            v10 = pathToPopulate.mPath.mCount;
            if ( pathToPopulate.mPath.mCount >= 0 )
            {
              if ( pathToPopulate.mPath.mData.mOffset
                && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                + pathToPopulate.mPath.mData.mOffset) )
              {
                operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                v10 = pathToPopulate.mPath.mCount;
              }
              pathToPopulate.mPath.mData.mOffset = 0i64;
              pathToPopulate.mPath.mCount = v10 & 0x80000000;
            }
          }
          v11 = UEL::gCurrentParameters;
          v12 = v2[-1].mActionTreeComponent.m_pSimObject;
          if ( v12 )
          {
            v13 = v12->m_Flags;
            if ( (v13 >> 14) & 1 )
            {
              v14 = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
            }
            else if ( (v13 & 0x8000u) == 0 )
            {
              if ( (v13 >> 13) & 1 )
              {
                v14 = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
              }
              else if ( (v13 >> 12) & 1 )
              {
                v15 = (unsigned int)v12[1].vfptr;
                v16 = v12->m_Components.size;
                if ( v15 >= v16 )
                {
LABEL_34:
                  v14 = 0i64;
                }
                else
                {
                  v17 = v12->m_Components.p;
                  while ( (v17[v15].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
                       || UFG::UELComponent::_TypeUID & ~v17[v15].m_TypeUID & 0x1FFFFFF )
                  {
                    if ( ++v15 >= v16 )
                      goto LABEL_34;
                  }
                  v14 = (UEL::ParametersBase *)v17[v15].m_pComponent;
                }
              }
              else
              {
                v14 = (UEL::ParametersBase *)UFG::SimObject::GetComponentOfType(
                                               v2[-1].mActionTreeComponent.m_pSimObject,
                                               UFG::UELComponent::_TypeUID);
              }
            }
            else
            {
              v14 = (UEL::ParametersBase *)v12->m_Components.p->m_pComponent;
            }
            if ( v14 )
              UEL::gCurrentParameters = v14 + 88;
          }
          ActionController::PlayTracks(
            (ActionController *)(*(_QWORD *)&v2->mHitRecord.mDistanceFromExplosionSquared + 0xC0i64),
            v9,
            0,
            0.0);
          LOBYTE(v2->m_Flags) = 1;
          ActionController::Update(
            (ActionController *)(*(_QWORD *)&v2->mHitRecord.mDistanceFromExplosionSquared + 192i64),
            0.0);
          LOBYTE(v2->m_Flags) = 0;
          UEL::gCurrentParameters = v11;
        }
        else
        {
          v18 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[-1].mActionTreeComponent.m_pSimObject->m_Name);
          UFG::qPrintf("HandleHitReaction: '%s' NO MATCH\n", v18);
        }
        LOBYTE(v2->mHitReactionOpeningBranchFullPath.mPath.mData.mOffset) = 1;
      }
    }
    *(float *)&v2->mIncomingAttackInfo.mAttacker.m_pPointer = delta_sec
                                                            + *(float *)&v2->mIncomingAttackInfo.mAttacker.m_pPointer;
    ++HIDWORD(v2->mIncomingAttackInfo.mAttacker.m_pPointer);
    if ( ++v2->mHitReactionOpeningBranchFullPath.mPath.mCount > 1 )
      LODWORD(v2->mPrev) = 0;
    UFG::HitReactionComponent::msUpdating = 0;
  }
}

// File Line: 525
// RVA: 0x521420
void __fastcall UFG::HitReactionComponent::AddToCurrentHitRecord(UFG::HitReactionComponent *this, UFG::HitRecord *hitrecord)
{
  UFG::HitRecord *v2; // rsi
  UFG::HitReactionComponent *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::HitRecord *v5; // rax
  UFG::HitRecord *v6; // rbx
  UFG::HitRecord *v7; // rax

  v2 = hitrecord;
  v3 = this;
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
  UFG::HitRecord::operator=(v6, v2);
  v7 = v3->mHitRecord.mNext;
  v3->mHitRecord.mNext = v6;
  v6->mNext = v7;
}

// File Line: 546
// RVA: 0x54D4E0
void __fastcall UFG::HitReactionComponent::SetHitRecord(UFG::HitReactionComponent *this, UFG::HitRecord *hitrecord)
{
  UFG::HitRecord *v2; // rdi
  UFG::HitReactionComponent *v3; // rbx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rdi
  unsigned int v7; // edx
  unsigned int v8; // er8
  signed __int64 v9; // rdi
  unsigned int v10; // edx
  unsigned int v11; // er8
  UFG::SimObject *v12; // rdx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // cl
  signed __int64 v15; // rbx
  __int64 v16; // rax

  v2 = hitrecord;
  v3 = this;
  if ( this->mNumHits > 1 )
    UFG::HitReactionComponent::CleanUpHitRecords(this);
  UFG::HitRecord::operator=(&v3->mHitRecord, v2);
  v4 = v3->m_pSimObject;
  v3->mNumHits = 1;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (v5 & 0x8000u) != 0 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
      goto LABEL_24;
    }
    if ( (v5 >> 13) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 < v8 )
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_14;
        }
LABEL_15:
        v6 = *(UFG::SimComponent **)v9;
        goto LABEL_24;
      }
    }
    else
    {
      if ( !((v5 >> 12) & 1) )
      {
        v6 = UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
        if ( v6 )
        {
          v12 = v3->mHitRecord.mAttacker.m_pPointer;
          if ( v12 )
          {
            v13 = *(_BYTE *)(*(_QWORD *)&v6[1].m_Flags + 10i64);
            if ( v13 )
              UFG::TargetingSimObject::SetTarget(
                (UFG::TargetingSimObject *)(*(_QWORD *)&v6[1].m_TypeUID + 56i64 * v13),
                v12);
          }
          else
          {
            v14 = *(_BYTE *)(*(_QWORD *)&v6[1].m_Flags + 10i64);
            if ( v14 )
            {
              v15 = 56i64 * v14;
              UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v15 + *(_QWORD *)&v6[1].m_TypeUID), 0i64);
              v16 = *(_QWORD *)&v6[1].m_TypeUID;
              if ( *(_BYTE *)(v15 + v16 + 49) )
                *(_BYTE *)(v15 + v16 + 49) = 0;
            }
          }
        }
        return;
      }
      v10 = (unsigned int)v4[1].vfptr;
      v11 = v4->m_Components.size;
      if ( v10 < v11 )
      {
        v9 = (signed __int64)&v4->m_Components.p[v10];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v10;
          v9 += 16i64;
          if ( v10 >= v11 )
          {
            v6 = 0i64;
            goto LABEL_24;
          }
        }
        goto LABEL_15;
      }
    }
LABEL_14:
    v6 = 0i64;
    goto LABEL_24;
  }
}

// File Line: 593
// RVA: 0x534420
void __fastcall UFG::HitReactionComponent::HandleHitReaction(UFG::HitReactionComponent *this, UFG::HitRecord *hitrecord)
{
  int v2; // er8
  char v3; // al

  if ( this->mHitRecord.mHitRecordProcessed == 1
    || ((v2 = hitrecord->mAttackTypeID, v2 != gAttackCollisionProjectile.m_EnumValue)
     || this->mHitRecord.mAttackTypeID != gAttackCollisionProjectile.m_EnumValue ? (v3 = 0) : (v3 = 1),
        JUMPOUT(v3, 0, UFG::HitReactionComponent::AddToCurrentHitRecord),
        v2 > this->mHitRecord.mAttackTypeID) )
  {
    UFG::HitReactionComponent::SetHitRecord(this, hitrecord);
  }
}

// File Line: 653
// RVA: 0x534470
void __fastcall UFG::HitReactionComponent::HandleIncomingAttack(UFG::HitReactionComponent *this, UFG::IncomingAttackInfo *incomingAttackInfo)
{
  UFG::SimObject *v2; // rax

  v2 = this->m_pSimObject;
  if ( !v2 || !((v2->m_Flags >> 10) & 1) )
    UFG::IncomingAttackInfo::operator=(&this->mIncomingAttackInfo, incomingAttackInfo);
}

// File Line: 663
// RVA: 0x5566D0
void __fastcall UFG::HitReactionComponent::TargetSphereEventHandler(UFG::HitReactionComponent *this, UFG::Event *e)
{
  UFG::HitReactionComponent *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::Event *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::PhysicsMoverInterface *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  int v10; // xmm1_4
  const char *v11; // ST28_8
  UFG::qNode<UFG::Event,UFG::Event> *v12; // rax
  int v13; // xmm0_4
  int v14; // xmm1_4
  int v15; // xmm0_4
  int v16; // xmm1_4
  int v17; // [rsp+30h] [rbp-28h]
  int v18; // [rsp+34h] [rbp-24h]
  int v19; // [rsp+38h] [rbp-20h]
  int v20; // [rsp+40h] [rbp-18h]
  int v21; // [rsp+44h] [rbp-14h]
  int v22; // [rsp+48h] [rbp-10h]

  v2 = this;
  v3 = this->m_pSimObject;
  v4 = e;
  if ( !v3 )
    goto LABEL_19;
  if ( (v3->m_Flags >> 10) & 1 )
    return;
  if ( !v3 )
    goto LABEL_19;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
    goto LABEL_19;
  if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
LABEL_19:
      if ( *(UFG::SimObject **)(v4[2].mUserData0 + 48) == v2->m_pSimObject )
      {
        v10 = HIDWORD(v4[2].mPrev);
        v11 = v4[2].m_NamePTR;
        v12 = v4[1].mNext;
        v17 = (int)v4[2].mPrev;
        v13 = (int)v4[2].mNext;
        v18 = v10;
        v14 = HIDWORD(v4[2].mNext);
        v19 = v13;
        v15 = v4[2].m_EventUID;
        v20 = v14;
        v16 = *(&v4[2].m_EventUID + 1);
        v21 = v15;
        v22 = v16;
        UFG::HitReactionComponent::ApplyBulletImpactImpulse(
          v2,
          (UFG::qVector3 *)&v20,
          (UFG::qVector3 *)&v17,
          (UFG::ProjectileInfo *)&v4[1].m_EventUID);
      }
      return;
    }
    if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v3[1].vfptr;
      v8 = v3->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_14:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v3->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_14;
        }
        v6 = *(UFG::PhysicsMoverInterface **)v9;
      }
    }
    else
    {
      v6 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(v3, UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    v6 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
  }
  if ( !v6 || !UFG::PhysicsMoverInterface::ShouldIgnoreBulletImpactDamageSphereEvent(v6, (UFG::SimObject *)v4[1].mNext) )
    goto LABEL_19;
}

// File Line: 690
// RVA: 0x5218A0
void __fastcall UFG::HitReactionComponent::ApplyBulletImpactImpulse(UFG::HitReactionComponent *this, UFG::qVector3 *vPoint, UFG::qVector3 *vBulletVelocity, UFG::ProjectileInfo *projectileInfo)
{
  UFG::ProjectileInfo *v4; // r14
  UFG::qVector3 *v5; // r12
  UFG::qVector3 *v6; // r13
  UFG::HitReactionComponent *v7; // rdi
  float v8; // xmm8_4
  __m128 v9; // xmm10
  float v10; // xmm9_4
  __m128 v11; // xmm2
  float v12; // xmm3_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  float v15; // xmm10_4
  UFG::HitRecord *v16; // rsi
  int v17; // ebx
  UFG::SimComponent *v18; // rax
  float v19; // xmm0_4
  UFG::SimObject *v20; // rcx
  unsigned __int16 v21; // dx
  unsigned int v22; // er8
  unsigned int v23; // er9
  UFG::SimComponentHolder *v24; // rbx
  signed __int64 v25; // rdx
  UFG::SimComponent *v26; // rax
  unsigned int v27; // er8
  unsigned int v28; // er9
  unsigned int v29; // er8
  unsigned int v30; // er9
  unsigned int v31; // er8
  unsigned int v32; // er9
  UFG::SimComponent *v33; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  signed int v35; // ebx
  bool v36; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  float v40; // xmm7_4
  __m128 v41; // xmm5
  float v42; // xmm6_4
  __m128 v43; // xmm2
  float v44; // xmm4_4
  unsigned int v45; // xmm3_4
  float v46; // xmm1_4
  UFG::SimComponent *v47; // rdx
  __int64 v48; // rcx
  _QWORD *v49; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v50; // rax
  bool v51; // cl
  UFG::HitRecord *v52; // rax
  UFG::HitRecord *v53; // rax
  UFG::HitRecord *v54; // rax
  UFG::HitRecord __that; // [rsp+20h] [rbp-B8h]
  UFG::SimObject *retaddr; // [rsp+1D8h] [rbp+100h]
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v57; // [rsp+1E0h] [rbp+108h]

  *(_QWORD *)&__that.mDistanceFromExplosionSquared = -2i64;
  v4 = projectileInfo;
  v5 = vBulletVelocity;
  v6 = vPoint;
  v7 = this;
  v8 = vBulletVelocity->y;
  v9 = (__m128)LODWORD(vBulletVelocity->x);
  v10 = vBulletVelocity->z;
  v11 = v9;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  v12 = 0.0;
  if ( v11.m128_f32[0] != 0.0 )
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v10 * v12;
  v14 = v8 * v12;
  v15 = v9.m128_f32[0] * v12;
  v16 = 0i64;
  v17 = 0;
  v18 = projectileInfo->m_pSOWPC.m_pPointer;
  if ( v18 )
  {
    v19 = *(float *)(*((_QWORD *)&v18[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v18[2].m_pSimObject))
                   + 92i64);
    v15 = v15 * v19;
    v14 = v14 * v19;
    v13 = v13 * v19;
    v20 = this->m_pSimObject;
    if ( !v20 )
    {
LABEL_38:
      v33 = v4->m_pSOWPC.m_pPointer;
      v34 = v33[2].m_BoundComponentHandles.mNode.mPrev;
      v35 = (signed int)(float)(*(float *)(*((_QWORD *)&v34->mNext + HIDWORD(v33[2].m_pSimObject)) + 140i64) * 100.0);
      if ( v4->m_bIsHardLocked )
        v35 = (signed int)(float)((float)v35
                                * *(float *)(*((_QWORD *)&v34->mNext + HIDWORD(v33[2].m_pSimObject)) + 132i64));
      v36 = UFG::IsAnyLocalPlayer(retaddr);
      v17 = (signed int)(float)((float)v35
                              * UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileDamage(
                                  (UFG::SimObjectWeaponPropertiesComponent *)v4->m_pSOWPC.m_pPointer,
                                  v36 == 0));
      goto LABEL_41;
    }
    v21 = v20->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      v22 = (unsigned int)v20[1].vfptr;
      v23 = v20->m_Components.size;
      if ( v22 < v23 )
      {
        v24 = v20->m_Components.p;
        while ( 1 )
        {
          v25 = v22;
          if ( (v24[v22].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && !(UFG::RigidBodyComponent::_TypeUID & ~v24[v22].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v22 >= v23 )
            goto LABEL_13;
        }
LABEL_12:
        v26 = v24[v25].m_pComponent;
        goto LABEL_36;
      }
    }
    else if ( (v21 & 0x8000u) == 0 )
    {
      if ( (v21 >> 13) & 1 )
      {
        v29 = (unsigned int)v20[1].vfptr;
        v30 = v20->m_Components.size;
        if ( v29 < v30 )
        {
          v24 = v20->m_Components.p;
          do
          {
            v25 = v29;
            if ( (v24[v29].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~v24[v29].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_12;
            }
          }
          while ( ++v29 < v30 );
        }
      }
      else
      {
        if ( !((v21 >> 12) & 1) )
        {
          v26 = UFG::SimObject::GetComponentOfType(v20, UFG::RigidBodyComponent::_TypeUID);
LABEL_36:
          if ( v26 )
          {
            v17 = (signed int)(float)(*(float *)(*((_QWORD *)&v4->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                 + HIDWORD(v4->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                               + 144i64)
                                    * 100.0);
            goto LABEL_41;
          }
          goto LABEL_38;
        }
        v31 = (unsigned int)v20[1].vfptr;
        v32 = v20->m_Components.size;
        if ( v31 < v32 )
        {
          v24 = v20->m_Components.p;
          do
          {
            v25 = v31;
            if ( (v24[v31].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
              && !(UFG::RigidBodyComponent::_TypeUID & ~v24[v31].m_TypeUID & 0x1FFFFFF) )
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
      v27 = (unsigned int)v20[1].vfptr;
      v28 = v20->m_Components.size;
      if ( v27 < v28 )
      {
        v24 = v20->m_Components.p;
        do
        {
          v25 = v27;
          if ( (v24[v27].m_TypeUID & 0xFE000000) == (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
            && !(UFG::RigidBodyComponent::_TypeUID & ~v24[v27].m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_12;
          }
        }
        while ( ++v27 < v28 );
      }
    }
LABEL_13:
    v26 = 0i64;
    goto LABEL_36;
  }
LABEL_41:
  if ( v4->m_bIsFullyAccurate )
    v17 = (signed int)(float)((float)v17
                            * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFullyAccurateDamageMultiplier);
  UFG::HitRecord::HitRecord(&__that);
  __that.mAttackTypeID = gAttackCollisionProjectile.m_EnumValue;
  __that.mDamage = v17;
  if ( __that.mAttacker.m_pPointer )
  {
    v37 = __that.mAttacker.mPrev;
    v38 = __that.mAttacker.mNext;
    __that.mAttacker.mPrev->mNext = __that.mAttacker.mNext;
    v38->mPrev = v37;
    __that.mAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
    __that.mAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
  }
  __that.mAttacker.m_pPointer = retaddr;
  if ( retaddr )
  {
    v39 = retaddr->m_SafePointerList.mNode.mPrev;
    v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
    __that.mAttacker.mPrev = v39;
    __that.mAttacker.mNext = &retaddr->m_SafePointerList.mNode;
    retaddr->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&__that.mAttacker.mPrev;
  }
  *(_QWORD *)&__that.mTimeSinceHit = 0i64;
  v40 = v5->y;
  v41 = (__m128)LODWORD(v5->x);
  v42 = v5->z;
  v43 = v41;
  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
  LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v43);
  v45 = (unsigned __int128)_mm_sqrt_ps(v43);
  __that.mProjectileInfo.m_pSOWPC.mPrev = v57;
  __that.mProjectileInfo.m_pSOWPC.mNext = 0i64;
  __that.mProjectileInfo.m_pSOWPC.m_pPointer = 0i64;
  __that.mProjectileInfo.m_pSubTargetingLocation = 0i64;
  v46 = v6->y;
  v43.m128_i32[0] = LODWORD(v6->z);
  *(float *)&__that.mProjectileInfo.m_bIsFullyAccurate = v6->x;
  *(float *)(&__that.mProjectileInfo.m_bIsHardLocked + 3) = v46;
  __that.mCollisionInfo.mPhysicsObjectPropertyHandleUID = __PAIR__(LODWORD(v15), v43.m128_u32[0]);
  __that.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = __PAIR__(LODWORD(v13), LODWORD(v14));
  __that.mCollisionInfo.mSurfacePropertyHandleUID = __PAIR__(LODWORD(v40), v41.m128_u32[0]);
  __that.mCollisionInfo.mAttackerSurfacePropertyHandleUID = __PAIR__(v45, LODWORD(v42));
  __that.mCollisionInfo.mHitLocation.x = v44;
  __that.mCollisionInfo.mHitLocation.y = FLOAT_N1_0;
  v47 = v4->m_pSOWPC.m_pPointer;
  if ( *(_QWORD *)&__that.mMeleeInfo.mHitNormal.z )
  {
    v48 = *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y;
    v49 = *(_QWORD **)&__that.mMeleeInfo.mHitNormal.x;
    *(_QWORD *)(*(_QWORD *)&__that.mMeleeInfo.mHitDirection.y + 8i64) = *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x;
    *v49 = v48;
    *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y = (char *)&__that + 88;
    *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x = (char *)&__that + 88;
  }
  *(_QWORD *)&__that.mMeleeInfo.mHitNormal.z = v47;
  if ( v47 )
  {
    v50 = v47->m_SafePointerList.mNode.mPrev;
    v50->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&__that.mMeleeInfo.mHitDirection.y;
    *(_QWORD *)&__that.mMeleeInfo.mHitDirection.y = v50;
    *(_QWORD *)&__that.mMeleeInfo.mHitNormal.x = (char *)v47 + 8;
    v47->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&__that.mMeleeInfo.mHitDirection.y;
  }
  *(_QWORD *)&__that.mMeleeInfo.mActionPath.mPath.mCount = v4->m_pSubTargetingLocation;
  LOWORD(__that.mMeleeInfo.mActionPath.mPath.mData.mOffset) = *(_WORD *)&v4->m_bIsFullyAccurate;
  if ( v7->mHitRecord.mHitRecordProcessed == 1 )
    goto LABEL_61;
  v51 = __that.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue
     && v7->mHitRecord.mAttackTypeID == gAttackCollisionProjectile.m_EnumValue;
  if ( !v51 )
  {
    if ( __that.mAttackTypeID <= v7->mHitRecord.mAttackTypeID )
      goto LABEL_62;
LABEL_61:
    UFG::HitReactionComponent::SetHitRecord(v7, &__that);
    goto LABEL_62;
  }
  ++v7->mNumHits;
  v52 = (UFG::HitRecord *)UFG::qMalloc(0x128ui64, UFG::gGlobalNewName, 0i64);
  retaddr = (UFG::SimObject *)v52;
  if ( v52 )
  {
    UFG::HitRecord::HitRecord(v52);
    v16 = v53;
  }
  UFG::HitRecord::operator=(v16, &__that);
  v54 = v7->mHitRecord.mNext;
  v7->mHitRecord.mNext = v16;
  v16->mNext = v54;
LABEL_62:
  UFG::HitRecord::~HitRecord(&__that);
}

// File Line: 733
// RVA: 0x549970
void __fastcall UFG::HitRecord::Reset(UFG::HitRecord *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // rdx
  UFG::HitRecord *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  signed __int64 v13; // rbx
  __int64 v14; // rcx
  _QWORD *v15; // rax

  v1 = &this->mAttacker;
  this->mTimeSinceHit = 1000.0;
  this->mFramesSinceHit = 1000;
  this->mEffectBone = -1;
  this->mDistanceFromExplosionSquared = -1.0;
  *(_QWORD *)&this->mAttackTypeID = 0i64;
  *(_DWORD *)&this->mHitRecordProcessed = 0;
  this->mExplosionInfo = 0i64;
  this->mNext = 0i64;
  v2 = this;
  if ( this->mAttacker.m_pPointer )
  {
    v3 = v1->mPrev;
    v4 = v1->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v2->mAttackerNetworkID = 0;
  v2->mEffectBone = 0;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v2->mEffectOffset.x = UFG::qVector3::msZero.x;
  v2->mEffectOffset.y = v5;
  v2->mEffectOffset.z = v6;
  v2->mCollisionInfo.mPhysicsObjectPropertyHandleUID = 0i64;
  v2->mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = 0i64;
  v2->mCollisionInfo.mSurfacePropertyHandleUID = 0i64;
  v2->mCollisionInfo.mAttackerSurfacePropertyHandleUID = 0i64;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v2->mCollisionInfo.mHitLocation.x = UFG::qVector3::msZero.x;
  v2->mCollisionInfo.mHitLocation.y = v7;
  v2->mCollisionInfo.mHitLocation.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v2->mCollisionInfo.mHitImpulse.x = UFG::qVector3::msZero.x;
  v2->mCollisionInfo.mHitImpulse.y = v9;
  v2->mCollisionInfo.mHitImpulse.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  v2->mCollisionInfo.mOtherVelocity.x = UFG::qVector3::msZero.x;
  v2->mCollisionInfo.mOtherVelocity.y = v11;
  v2->mCollisionInfo.mOtherVelocity.z = v12;
  *(_QWORD *)&v2->mCollisionInfo.mSpeed = 0i64;
  v2->mCollisionInfo.mEstimatedImpulseMagnitude = -1.0;
  UFG::MeleeInfo::Reset(&v2->mMeleeInfo);
  v13 = (signed __int64)&v2->mProjectileInfo;
  if ( *(_QWORD *)(v13 + 16) )
  {
    v14 = *(_QWORD *)v13;
    v15 = *(_QWORD **)(v13 + 8);
    *(_QWORD *)(v14 + 8) = v15;
    *v15 = v14;
    *(_QWORD *)v13 = v13;
    *(_QWORD *)(v13 + 8) = v13;
  }
  *(_QWORD *)(v13 + 16) = 0i64;
  *(_QWORD *)(v13 + 24) = 0i64;
  *(_WORD *)(v13 + 32) = 0;
}

// File Line: 761
// RVA: 0x517BF0
void __fastcall UFG::HitRecord::HitRecord(UFG::HitRecord *this)
{
  UFG::HitRecord *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rax
  UFG::MeleeInfo *v3; // rax
  ActionPath *v4; // rax
  UFG::ProjectileInfo *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  v2 = &this->mAttacker;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mAttacker.m_pPointer = 0i64;
  v3 = &this->mMeleeInfo;
  *(_QWORD *)&v3->mAttackLocationLateralID = 0i64;
  v3->mAttackFromBehind = 0;
  *(_QWORD *)&v3->mAttackMaterialUID = 0i64;
  *(_QWORD *)&v3->mAttackIntensityUID = 0i64;
  *(_QWORD *)&v3->mHitPosition.y = 0i64;
  *(_QWORD *)&v3->mHitDirection.x = 0i64;
  *(_QWORD *)&v3->mHitDirection.z = 0i64;
  *(_QWORD *)&v3->mHitNormal.y = 0i64;
  v4 = &this->mMeleeInfo.mActionPath;
  v4->mPath.mCount = 0;
  v4->mPath.mData.mOffset = 0i64;
  v5 = &this->mProjectileInfo;
  v5->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
  v5->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
  this->mProjectileInfo.m_pSOWPC.m_pPointer = 0i64;
  if ( this->mProjectileInfo.m_pSOWPC.m_pPointer )
  {
    v6 = v5->m_pSOWPC.mPrev;
    v7 = v5->m_pSOWPC.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
    v5->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
  }
  v5->m_pSOWPC.m_pPointer = 0i64;
  v5->m_pSubTargetingLocation = 0i64;
  *(_WORD *)&v5->m_bIsFullyAccurate = 0;
  UFG::HitRecord::Reset(v1);
}

