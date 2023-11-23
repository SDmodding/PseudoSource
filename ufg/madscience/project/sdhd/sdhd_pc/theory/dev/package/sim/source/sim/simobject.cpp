// File Line: 28
// RVA: 0x14688E0
UFG::qMemoryPool *UFG::_dynamic_initializer_for__gSimulationMemoryPool__()
{
  UFG::qMemoryPool *result; // rax

  result = UFG::gMainMemoryPool;
  gSimulationMemoryPool = UFG::gMainMemoryPool;
  return result;
}

// File Line: 31
// RVA: 0x190C90
UFG::qMemoryPool *__fastcall UFG::GetSimulationMemoryPool()
{
  return gSimulationMemoryPool;
}

// File Line: 36
// RVA: 0x1914A0
void __fastcall UFG::SetSimulationMemoryPool(UFG::qMemoryPool *sim_memory_pool)
{
  gSimulationMemoryPool = sim_memory_pool;
}

// File Line: 47
// RVA: 0x191670
UFG::ComponentIDDesc *__fastcall UFG::Simulation_GetNewBaseDesc(UFG::ComponentIDDesc *result)
{
  if ( (_S1_22 & 1) == 0 )
  {
    _S1_22 |= 1u;
    word_14235C4B0 = 0;
    qword_14235C4B4 = 0i64;
  }
  ++HIDWORD(qword_14235C4B4);
  result->mBaseTypeIndex = WORD2(qword_14235C4B4);
  *(_QWORD *)&result->mChildBitMask = 1i64;
  return result;
}

// File Line: 71
// RVA: 0x18F060
void __fastcall UFG::SimComponent::SimComponent(UFG::SimComponent *this, unsigned int name_uid)
{
  UFG::qSafePointerNode<UFG::SimComponent>::qSafePointerNode<UFG::SimComponent>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimComponent::`vftable;
  this->m_TypeUID = -1;
  this->m_NameUID = name_uid;
  this->m_Flags = 8;
  this->m_SimObjIndex = -1;
  this->m_pSimObject = 0i64;
  this->m_BoundComponentHandles.mNode.mPrev = &this->m_BoundComponentHandles.mNode;
  this->m_BoundComponentHandles.mNode.mNext = &this->m_BoundComponentHandles.mNode;
}

// File Line: 76
// RVA: 0x18F6A0
void __fastcall UFG::SimComponent::~SimComponent(UFG::SimComponent *this)
{
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r8
  UFG::SimComponent *mNext; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimComponent::`vftable;
  p_m_BoundComponentHandles = &this->m_BoundComponentHandles;
  mNext = (UFG::SimComponent *)this->m_BoundComponentHandles.mNode.mNext;
  if ( mNext != (UFG::SimComponent *)&this->m_BoundComponentHandles )
  {
    do
    {
      vfptr = mNext->vfptr;
      mPrev = mNext->m_SafePointerList.mNode.mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)vfptr;
      mNext->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)mNext;
      mNext->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)mNext;
      mNext = (UFG::SimComponent *)p_m_BoundComponentHandles->mNode.mNext;
    }
    while ( mNext != (UFG::SimComponent *)p_m_BoundComponentHandles );
  }
  v6 = p_m_BoundComponentHandles->mNode.mPrev;
  v7 = p_m_BoundComponentHandles->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_BoundComponentHandles->mNode.mPrev = &p_m_BoundComponentHandles->mNode;
  p_m_BoundComponentHandles->mNode.mNext = &p_m_BoundComponentHandles->mNode;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::qSafePointerNode<UFG::SimComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v8 = this->m_SafePointerList.mNode.mPrev;
  v9 = this->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 139
// RVA: 0x18F160
void __fastcall UFG::SimObjectModifier::SimObjectModifier(
        UFG::SimObjectModifier *this,
        UFG::SimObject *simObject,
        bool broadcastChange)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mptrSimObject; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  this->mbOpen = 1;
  this->mbBroadcastChange = broadcastChange;
  p_mptrSimObject = &this->mptrSimObject;
  this->mptrSimObject.mPrev = &this->mptrSimObject;
  this->mptrSimObject.mNext = &this->mptrSimObject;
  this->mptrSimObject.m_pPointer = 0i64;
  if ( broadcastChange )
    ++simObject->m_ResolveRefCount;
  if ( this->mptrSimObject.m_pPointer )
  {
    mPrev = p_mptrSimObject->mPrev;
    mNext = p_mptrSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mptrSimObject->mPrev = p_mptrSimObject;
    p_mptrSimObject->mNext = p_mptrSimObject;
  }
  p_mptrSimObject->m_pPointer = simObject;
  if ( simObject )
  {
    v6 = simObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = p_mptrSimObject;
    p_mptrSimObject->mPrev = v6;
    p_mptrSimObject->mNext = &simObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    simObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mptrSimObject;
  }
}

// File Line: 153
// RVA: 0x18FA70
void __fastcall UFG::SimObjectModifier::~SimObjectModifier(UFG::SimObjectModifier *this)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mptrSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  if ( this->mbBroadcastChange )
  {
    m_pPointer = this->mptrSimObject.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->m_ResolveRefCount-- == 1 && (m_pPointer->m_Flags & 1) != 0 )
        UFG::SimObject::NotifyComponentsOfChange(m_pPointer);
    }
  }
  p_mptrSimObject = &this->mptrSimObject;
  if ( this->mptrSimObject.m_pPointer )
  {
    mPrev = p_mptrSimObject->mPrev;
    mNext = this->mptrSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mptrSimObject->mPrev = p_mptrSimObject;
    this->mptrSimObject.mNext = &this->mptrSimObject;
  }
  this->mptrSimObject.m_pPointer = 0i64;
  this->mbOpen = 0;
  if ( this->mptrSimObject.m_pPointer )
  {
    v7 = p_mptrSimObject->mPrev;
    v8 = this->mptrSimObject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mptrSimObject->mPrev = p_mptrSimObject;
    this->mptrSimObject.mNext = &this->mptrSimObject;
  }
  this->mptrSimObject.m_pPointer = 0i64;
  v9 = p_mptrSimObject->mPrev;
  v10 = this->mptrSimObject.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mptrSimObject->mPrev = p_mptrSimObject;
  this->mptrSimObject.mNext = &this->mptrSimObject;
}

// File Line: 159
// RVA: 0x1902C0
void __fastcall UFG::SimObjectModifier::Close(UFG::SimObjectModifier *this)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mptrSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mbBroadcastChange )
  {
    m_pPointer = this->mptrSimObject.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->m_ResolveRefCount-- == 1 && (m_pPointer->m_Flags & 1) != 0 )
        UFG::SimObject::NotifyComponentsOfChange(m_pPointer);
    }
  }
  p_mptrSimObject = &this->mptrSimObject;
  if ( this->mptrSimObject.m_pPointer )
  {
    mPrev = p_mptrSimObject->mPrev;
    mNext = this->mptrSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mptrSimObject->mPrev = p_mptrSimObject;
    this->mptrSimObject.mNext = &this->mptrSimObject;
  }
  this->mptrSimObject.m_pPointer = 0i64;
  this->mbOpen = 0;
}

// File Line: 176
// RVA: 0x1902B0
void __fastcall UFG::SimObjectModifier::AttachComponent(
        UFG::SimObjectModifier *this,
        UFG::SimComponent *component,
        __int64 slotIndex)
{
  ((void (__fastcall *)(UFG::SimObject *, UFG::SimComponent *, __int64))this->mptrSimObject.m_pPointer->vfptr[1].__vecDelDtor)(
    this->mptrSimObject.m_pPointer,
    component,
    slotIndex);
}

// File Line: 211
// RVA: 0x18F0D0
void __fastcall UFG::SimObject::SimObject(UFG::SimObject *this, UFG::qSymbol *name)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::qSafePointerNodeWithCallbacks<UFG::SimObject>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObject::`vftable;
  *(_QWORD *)&this->m_Name.mUID = name->mUID;
  this->m_pSceneObj = 0i64;
  this->m_pTransformNodeComponent = 0i64;
  this->m_Components.p = 0i64;
  *(_QWORD *)&this->m_Components.size = 0i64;
  this->m_UnboundComponentHandles.mNode.mPrev = &this->m_UnboundComponentHandles.mNode;
  this->m_UnboundComponentHandles.mNode.mNext = &this->m_UnboundComponentHandles.mNode;
}

// File Line: 223
// RVA: 0x18F750
void __fastcall UFG::SimObject::~SimObject(UFG::SimObject *this)
{
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *p_m_UnboundComponentHandles; // r15
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  char v10; // cl
  signed int v11; // eax
  __int64 v12; // rdi
  __int64 v13; // rsi
  UFG::SimComponent *m_pComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  unsigned int i; // r10d
  UFG::SimComponent *v23; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  unsigned int j; // ebx
  UFG::SimComponent *v28; // rcx
  unsigned __int16 m_Flags; // ax
  unsigned int mUID; // ebx
  UFG::qBaseTreeRB *k; // rax
  unsigned int v32; // edx
  __int64 v33; // rcx
  __int64 v34; // rdx
  char *v35; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *m; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v42; // rax
  UFG::SimComponentHolder *p; // rcx

  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObject::`vftable;
  this->m_Flags |= 2u;
  p_m_UnboundComponentHandles = &this->m_UnboundComponentHandles;
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)this->m_UnboundComponentHandles.mNode.mNext != &this->m_UnboundComponentHandles )
  {
    while ( 1 )
    {
      mNext = this->m_UnboundComponentHandles.mNode.mNext;
      if ( mNext[1].mNext )
      {
        mPrev = mNext->mPrev;
        v5 = mNext->mNext;
        mPrev->mNext = v5;
        v5->mPrev = mPrev;
        mNext[1].mNext = 0i64;
      }
      else
      {
        if ( !mNext[2].mPrev )
          goto LABEL_9;
        v6 = mNext->mPrev;
        if ( mNext->mPrev == mNext && mNext->mNext == mNext )
          goto LABEL_9;
        v7 = mNext->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
      }
      mNext[2].mPrev = 0i64;
      mNext->mNext = mNext;
      mNext->mPrev = mNext;
LABEL_9:
      LODWORD(mNext[2].mNext) = 1;
      v8 = mNext->mPrev;
      v9 = mNext->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)p_m_UnboundComponentHandles->mNode.mNext == p_m_UnboundComponentHandles )
        goto LABEL_10;
    }
  }
  do
  {
LABEL_10:
    v10 = 0;
    v11 = this->m_Components.size - 1;
    v12 = v11;
    if ( v11 < 0 )
      break;
    v13 = v11;
    do
    {
      m_pComponent = this->m_Components.p[v13].m_pComponent;
      if ( m_pComponent && (m_pComponent->m_Flags & 0x10) == 0 )
      {
        ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[10].__vecDelDtor)(m_pComponent);
        m_pComponent->m_Flags |= 0x10u;
        v10 = 1;
      }
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  while ( v10 );
  for ( ;
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)p_m_UnboundComponentHandles->mNode.mNext != p_m_UnboundComponentHandles;
        v15->mNext = v15 )
  {
    v15 = this->m_UnboundComponentHandles.mNode.mNext;
    if ( v15[1].mNext )
    {
      v16 = v15->mPrev;
      v17 = v15->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15[1].mNext = 0i64;
    }
    else
    {
      if ( !v15[2].mPrev )
        goto LABEL_25;
      v18 = v15->mPrev;
      if ( v15->mPrev == v15 && v15->mNext == v15 )
        goto LABEL_25;
      v19 = v15->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
    }
    v15[2].mPrev = 0i64;
    v15->mNext = v15;
    v15->mPrev = v15;
LABEL_25:
    LODWORD(v15[2].mNext) = 1;
    v20 = v15->mPrev;
    v21 = v15->mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v15->mPrev = v15;
  }
  for ( i = 0; i < this->m_Components.size; ++i )
  {
    v23 = this->m_Components.p[i].m_pComponent;
    if ( v23 )
    {
      for ( v23->m_pSimObject = 0i64;
            (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v23->m_BoundComponentHandles.mNode.mNext != &v23->m_BoundComponentHandles;
            v24[2].mPrev = 0i64 )
      {
        v24 = v23->m_BoundComponentHandles.mNode.mNext;
        v25 = v24->mPrev;
        v26 = v24->mNext;
        v25->mNext = v26;
        v26->mPrev = v25;
        v24->mPrev = v24;
        v24->mNext = v24;
        v24[1].mNext = 0i64;
      }
    }
  }
  for ( j = 0; j < this->m_Components.size; ++j )
  {
    v28 = this->m_Components.p[j].m_pComponent;
    if ( v28 )
    {
      v28->m_Flags &= 0xFFEEu;
      if ( (v28->m_Flags & 8) != 0 )
        v28->vfptr->__vecDelDtor(v28, 1u);
      this->m_Components.p[j].m_pComponent = 0i64;
    }
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 1) != 0 )
    this->m_Flags = m_Flags & 0xFFFE;
  mUID = this->mNode.mUID;
  for ( k = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14235C1A0);
        k;
        k = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14235C1A0, &k->mRoot) )
  {
    v32 = HIDWORD(k[1].mRoot.mChild[1]);
    if ( mUID >= v32 )
    {
      v33 = mUID - v32;
      if ( (unsigned int)v33 < LODWORD(k[1].mRoot.mChild[1]) )
      {
        v34 = *(_QWORD *)&k[1].mRoot.mUID;
        if ( v34 )
          v35 = (char *)&k[1].mRoot.mChild[2] + v34;
        else
          v35 = 0i64;
        v35[v33] = 0;
        UFG::qSymbolRegistry::PurgeRef(mUID);
        break;
      }
    }
  }
  for ( m = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)p_m_UnboundComponentHandles->mNode.mNext;
        m != p_m_UnboundComponentHandles;
        m = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)p_m_UnboundComponentHandles->mNode.mNext )
  {
    v37 = m->mNode.mPrev;
    v38 = m->mNode.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    m->mNode.mPrev = &m->mNode;
    m->mNode.mNext = &m->mNode;
    v39 = m->mNode.mPrev;
    v40 = m->mNode.mNext;
    v39->mNext = v40;
    v40->mPrev = v39;
    m->mNode.mPrev = &m->mNode;
    m->mNode.mNext = &m->mNode;
    operator delete[](m);
  }
  v41 = p_m_UnboundComponentHandles->mNode.mPrev;
  v42 = p_m_UnboundComponentHandles->mNode.mNext;
  v41->mNext = v42;
  v42->mPrev = v41;
  p_m_UnboundComponentHandles->mNode.mPrev = &p_m_UnboundComponentHandles->mNode;
  p_m_UnboundComponentHandles->mNode.mNext = &p_m_UnboundComponentHandles->mNode;
  p = this->m_Components.p;
  if ( p )
    operator delete[](p);
  this->m_Components.p = 0i64;
  *(_QWORD *)&this->m_Components.size = 0i64;
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::~qSafePointerNodeWithCallbacks<UFG::SimObject>(this);
}

// File Line: 333
// RVA: 0x190060
void __fastcall UFG::SimObject::Attach(
        UFG::SimObject *this,
        UFG::TransformNodeComponent *component,
        unsigned int index)
{
  unsigned int m_TypeUID; // ebp
  UFG::SimComponentHolder *v6; // rdi
  unsigned int size; // ebx
  UFG::SimComponent *m_pComponent; // rdi
  const char *v9; // rbx
  const char *v10; // rax
  unsigned int capacity; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  UFG::SimComponentHolder *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *i; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // r9
  _QWORD *p_mNext; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  unsigned __int16 m_Flags; // ax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  unsigned __int16 v23; // ax
  unsigned int v24; // ebx
  UFG::SimComponent *v25; // rcx
  unsigned __int16 v26; // ax

  if ( !component )
    return;
  m_TypeUID = component->m_TypeUID;
  component->m_pSimObject = this;
  if ( m_TypeUID == UFG::TransformNodeComponent::_TypeUID && !this->m_pTransformNodeComponent )
    this->m_pTransformNodeComponent = component;
  if ( index < this->m_Components.size )
  {
    v6 = &this->m_Components.p[index];
    if ( v6->m_pComponent )
    {
      m_pComponent = v6->m_pComponent;
      v9 = (const char *)((__int64 (__fastcall *)(UFG::TransformNodeComponent *))component->vfptr[4].__vecDelDtor)(component);
      v10 = (const char *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[4].__vecDelDtor)(m_pComponent);
      UFG::qPrintf(
        "WARNING:already have a component of of the given type %s in this slot, add this component %s into dynamic slot a"
        "fter type table, this could be a construction error with competing components",
        v10,
        v9);
LABEL_9:
      index = (unsigned __int8)this->m_ReservedComponentSlots;
      size = this->m_Components.size;
      if ( index >= size )
        goto LABEL_15;
      while ( this->m_Components.p[index].m_pComponent )
      {
        if ( ++index >= size )
          goto LABEL_15;
      }
      if ( index == -1 )
      {
LABEL_15:
        capacity = this->m_Components.capacity;
        v12 = size + 1;
        if ( v12 > capacity )
        {
          if ( capacity )
            v13 = 2 * capacity;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 - v12 > 0x10000 )
            v13 = v12 + 0x10000;
          UFG::qArray<UFG::SimComponentHolder,0>::Reallocate(&this->m_Components, v13, "SimObject::m_Components");
        }
        this->m_Components.size = v12;
        index = v12 - 1;
      }
      v14 = &this->m_Components.p[index];
      v14->m_pComponent = component;
      v14->m_TypeUID = m_TypeUID;
      goto LABEL_26;
    }
    v6->m_pComponent = component;
    v6->m_TypeUID = m_TypeUID;
  }
  if ( index == -1 )
    goto LABEL_9;
LABEL_26:
  component->m_SimObjIndex = index;
  for ( i = this->m_UnboundComponentHandles.mNode.mNext;
        i != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->m_UnboundComponentHandles;
        i = i->mNext )
  {
    if ( (m_TypeUID & 0xFE000000) == ((__int64)i[1].mPrev & 0xFE000000)
      && ((__int64)i[1].mPrev & ~m_TypeUID & 0x1FFFFFF) == 0 )
    {
      v16 = i;
      p_mNext = &i->mNext;
      mNext = i->mNext;
      mPrev = v16->mPrev;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v16->mPrev = v16;
      *p_mNext = v16;
      i = mNext->mPrev;
      v16[1].mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)component;
      v20 = component->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev;
      v20->mNext = v16;
      v16->mPrev = v20;
      *p_mNext = &component->m_BoundComponentHandles;
      component->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev = v16;
    }
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 3) == 0 )
    this->m_Flags = m_Flags | 1;
  if ( (this->m_Flags & 0x10) == 0 )
  {
    vfptr = component->vfptr;
    component->m_Flags |= 1u;
    vfptr[6].__vecDelDtor(component, (unsigned int)this);
    v23 = this->m_Flags;
    if ( (v23 & 0x10) == 0 )
    {
      v24 = 0;
      for ( this->m_Flags = v23 & 0xFFFE; v24 < this->m_Components.size; ++v24 )
      {
        v25 = this->m_Components.p[v24].m_pComponent;
        if ( v25 )
        {
          v26 = v25->m_Flags;
          if ( (v26 & 1) == 0 )
          {
            v25->m_pSimObject = this;
            v25->m_Flags = v26 | 1;
            v25->vfptr[6].__vecDelDtor(v25, (unsigned int)this);
          }
        }
      }
    }
  }
}

// File Line: 438
// RVA: 0x1908E0
void __fastcall UFG::SimObject::Detach(UFG::SimObject *this, UFG::TransformNodeComponent *component)
{
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // r10
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *p_m_UnboundComponentHandles; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  unsigned __int16 m_Flags; // ax
  unsigned int m_SimObjIndex; // eax
  __int64 v12; // rcx

  p_m_BoundComponentHandles = &component->m_BoundComponentHandles;
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)component->m_BoundComponentHandles.mNode.mNext != &component->m_BoundComponentHandles )
  {
    p_m_UnboundComponentHandles = &this->m_UnboundComponentHandles;
    do
    {
      mNext = component->m_BoundComponentHandles.mNode.mNext;
      v7 = mNext->mNext;
      mPrev = mNext->mPrev;
      mPrev->mNext = v7;
      v7->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      mNext[1].mNext = 0i64;
      v9 = p_m_UnboundComponentHandles->mNode.mPrev;
      v9->mNext = mNext;
      mNext->mPrev = v9;
      mNext->mNext = &p_m_UnboundComponentHandles->mNode;
      p_m_UnboundComponentHandles->mNode.mPrev = mNext;
    }
    while ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)p_m_BoundComponentHandles->mNode.mNext != p_m_BoundComponentHandles );
  }
  m_Flags = this->m_Flags;
  if ( (m_Flags & 3) == 0 )
    this->m_Flags = m_Flags | 1;
  ((void (__fastcall *)(UFG::TransformNodeComponent *))component->vfptr[10].__vecDelDtor)(component);
  component->m_pSimObject = 0i64;
  component->m_Flags &= ~1u;
  m_SimObjIndex = component->m_SimObjIndex;
  component->m_SimObjIndex = -1;
  v12 = m_SimObjIndex;
  this->m_Components.p[v12].m_pComponent = 0i64;
  this->m_Components.p[v12].m_TypeUID = 0;
  if ( component->m_TypeUID == UFG::TransformNodeComponent::_TypeUID && this->m_pTransformNodeComponent == component )
    this->m_pTransformNodeComponent = 0i64;
}

// File Line: 490
// RVA: 0x190D80
void __fastcall UFG::SimObject::NotifyComponentsOfChange(UFG::SimObject *this)
{
  unsigned __int16 m_Flags; // ax
  unsigned int v3; // ebx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned __int16 v5; // ax

  m_Flags = this->m_Flags;
  if ( (m_Flags & 0x10) == 0 )
  {
    v3 = 0;
    for ( this->m_Flags = m_Flags & 0xFFFE; v3 < this->m_Components.size; ++v3 )
    {
      m_pComponent = this->m_Components.p[v3].m_pComponent;
      if ( m_pComponent )
      {
        v5 = m_pComponent->m_Flags;
        if ( (v5 & 1) == 0 )
        {
          m_pComponent->m_pSimObject = this;
          m_pComponent->m_Flags = v5 | 1;
          m_pComponent->vfptr[6].__vecDelDtor(m_pComponent, (unsigned int)this);
        }
      }
    }
  }
}

// File Line: 580
// RVA: 0x1916D0
__int64 __fastcall UFG::SimObject::Suspend(UFG::SimObject *this)
{
  unsigned int i; // ebx
  UFG::SimComponent *m_pComponent; // rcx

  for ( i = 0; i < this->m_Components.size; ++i )
  {
    m_pComponent = this->m_Components.p[i].m_pComponent;
    if ( m_pComponent )
      ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[8].__vecDelDtor)(m_pComponent);
  }
  return 0i64;
}

// File Line: 597
// RVA: 0x1911F0
__int64 __fastcall UFG::SimObject::Restore(UFG::SimObject *this)
{
  unsigned int i; // ebx
  UFG::SimComponent *m_pComponent; // rcx

  for ( i = 0; i < this->m_Components.size; ++i )
  {
    m_pComponent = this->m_Components.p[i].m_pComponent;
    if ( m_pComponent && (m_pComponent->m_Flags & 2) != 0 )
      ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[9].__vecDelDtor)(m_pComponent);
  }
  return 0i64;
}

// File Line: 616
// RVA: 0x1905C0
void __fastcall UFG::SimObject::Destroy(UFG::SimObject *this)
{
  UFG::Simulation::DestroySimObject(&UFG::gSim, this);
}

// File Line: 669
// RVA: 0x190040
void __fastcall UFG::SimComponent::AddType(UFG::SimComponent *this, unsigned int type, const char *debugName)
{
  UFG::SimObject *m_pSimObject; // r8

  m_pSimObject = this->m_pSimObject;
  this->m_TypeUID = type;
  if ( m_pSimObject )
    m_pSimObject->m_Components.p[this->m_SimObjIndex].m_TypeUID = type;
}

// File Line: 684
// RVA: 0x190CF0
bool __fastcall UFG::SimComponent::IsType(UFG::SimComponent *this, unsigned int type)
{
  return ((type ^ this->m_TypeUID) & 0xFE000000) == 0 && (type & ~this->m_TypeUID & 0x1FFFFFF) == 0;
}

// File Line: 690
// RVA: 0x190B30
UFG::TransformNodeComponent *__fastcall UFG::SimObject::GetComponentOfType(
        UFG::SimObject *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::SimComponent *prev_component)
{
  unsigned int size; // ebx
  unsigned int v7; // edx
  UFG::SimComponentHolder *i; // rcx

  size = this->m_Components.size;
  if ( !size )
    return 0i64;
  if ( type_uid == UFG::TransformNodeComponent::_TypeUID && !name_uid )
    return this->m_pTransformNodeComponent;
  v7 = 0;
  if ( prev_component )
    v7 = prev_component->m_SimObjIndex + 1;
  if ( v7 >= size )
    return 0i64;
  for ( i = &this->m_Components.p[v7];
        !i->m_pComponent
     || ((type_uid ^ i->m_TypeUID) & 0xFE000000) != 0
     || (type_uid & ~i->m_TypeUID & 0x1FFFFFF) != 0
     || name_uid && i->m_pComponent->m_NameUID != name_uid;
        ++i )
  {
    if ( ++v7 >= size )
      return 0i64;
  }
  return (UFG::TransformNodeComponent *)i->m_pComponent;
}

// File Line: 758
// RVA: 0x190AD0
UFG::SimComponent *__fastcall UFG::SimObject::GetComponentOfType(UFG::SimObject *this, unsigned int type_uid)
{
  unsigned int size; // r9d
  unsigned int v4; // r8d
  UFG::SimComponentHolder *p; // rdx
  unsigned int v7; // r10d

  size = this->m_Components.size;
  if ( !size )
    return 0i64;
  v4 = 0;
  p = this->m_Components.p;
  v7 = type_uid & 0xFE000000;
  while ( (p->m_TypeUID & 0xFE000000) != v7 || (type_uid & ~p->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++v4;
    ++p;
    if ( v4 >= size )
      return 0i64;
  }
  return p->m_pComponent;
}

// File Line: 779
// RVA: 0x1916C0
void __fastcall UFG::SimObject::StartDeferringAttachment(UFG::SimObject *this)
{
  this->m_Flags |= 0x10u;
}

// File Line: 784
// RVA: 0x1909B0
void __fastcall UFG::SimObject::EndDeferringAttachment(UFG::SimObject *this)
{
  this->m_Flags &= ~0x10u;
  if ( (this->m_Flags & 1) != 0 )
    UFG::SimObject::NotifyComponentsOfChange(this);
}

