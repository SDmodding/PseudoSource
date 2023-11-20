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
  if ( !(_S1_22 & 1) )
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
  unsigned int v2; // ebx
  UFG::SimComponent *v3; // rdi
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v4; // [rsp+50h] [rbp+18h]

  v2 = name_uid;
  v3 = this;
  UFG::qSafePointerNode<UFG::SimComponent>::qSafePointerNode<UFG::SimComponent>((UFG::qSafePointerNode<UFG::SimComponent> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimComponent::`vftable;
  v3->m_TypeUID = -1;
  v3->m_NameUID = v2;
  v3->m_Flags = 8;
  v3->m_SimObjIndex = -1;
  v3->m_pSimObject = 0i64;
  v4 = &v3->m_BoundComponentHandles;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 76
// RVA: 0x18F6A0
void __fastcall UFG::SimComponent::~SimComponent(UFG::SimComponent *this)
{
  UFG::SimComponent *v1; // rbx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v2; // r8
  UFG::SimComponent *v3; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v10; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimComponent::`vftable;
  v2 = &this->m_BoundComponentHandles;
  v3 = (UFG::SimComponent *)this->m_BoundComponentHandles.mNode.mNext;
  if ( v3 != (UFG::SimComponent *)&this->m_BoundComponentHandles )
  {
    do
    {
      v4 = v3->vfptr;
      v5 = v3->m_SafePointerList.mNode.mPrev;
      v4[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v5;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v4;
      v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v3;
      v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3;
      v3 = (UFG::SimComponent *)v2->mNode.mNext;
    }
    while ( v3 != (UFG::SimComponent *)v2 );
  }
  v6 = v2->mNode.mPrev;
  v7 = v2->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::qSafePointerNode<UFG::SimComponent>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  v10 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v8 = v1->m_SafePointerList.mNode.mPrev;
  v9 = v1->m_SafePointerList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
}

// File Line: 139
// RVA: 0x18F160
void __fastcall UFG::SimObjectModifier::SimObjectModifier(UFG::SimObjectModifier *this, UFG::SimObject *simObject, bool broadcastChange)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  this->mbOpen = 1;
  this->mbBroadcastChange = broadcastChange;
  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mptrSimObject.mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->mptrSimObject.m_pPointer = 0i64;
  if ( broadcastChange )
    ++simObject->m_ResolveRefCount;
  if ( this->mptrSimObject.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
  }
  v3[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)simObject;
  if ( simObject )
  {
    v6 = simObject->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    v3->mNext = &simObject->m_SafePointerList.mNode;
    simObject->m_SafePointerList.mNode.mPrev = v3;
  }
}

// File Line: 153
// RVA: 0x18FA70
void __fastcall UFG::SimObjectModifier::~SimObjectModifier(UFG::SimObjectModifier *this)
{
  UFG::SimObjectModifier *v1; // rbx
  UFG::SimObject *v2; // rcx
  bool v3; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  v1 = this;
  if ( this->mbBroadcastChange )
  {
    v2 = this->mptrSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_ResolveRefCount-- == 1;
      if ( v3 )
      {
        if ( v2->m_Flags & 1 )
          UFG::SimObject::NotifyComponentsOfChange(v2);
      }
    }
  }
  v4 = &v1->mptrSimObject;
  if ( v1->mptrSimObject.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mptrSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mptrSimObject.mPrev;
  }
  v1->mptrSimObject.m_pPointer = 0i64;
  v1->mbOpen = 0;
  if ( v1->mptrSimObject.m_pPointer )
  {
    v7 = v4->mPrev;
    v8 = v1->mptrSimObject.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mptrSimObject.mPrev;
  }
  v1->mptrSimObject.m_pPointer = 0i64;
  v9 = v4->mPrev;
  v10 = v1->mptrSimObject.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mptrSimObject.mPrev;
}

// File Line: 159
// RVA: 0x1902C0
void __fastcall UFG::SimObjectModifier::Close(UFG::SimObjectModifier *this)
{
  UFG::SimObjectModifier *v1; // rbx
  UFG::SimObject *v2; // rcx
  bool v3; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  if ( this->mbBroadcastChange )
  {
    v2 = this->mptrSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_ResolveRefCount-- == 1;
      if ( v3 )
      {
        if ( v2->m_Flags & 1 )
          UFG::SimObject::NotifyComponentsOfChange(v2);
      }
    }
  }
  v4 = &v1->mptrSimObject;
  if ( v1->mptrSimObject.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mptrSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mptrSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mptrSimObject.mPrev;
  }
  v1->mptrSimObject.m_pPointer = 0i64;
  v1->mbOpen = 0;
}

// File Line: 176
// RVA: 0x1902B0
void __fastcall UFG::SimObjectModifier::AttachComponent(UFG::SimObjectModifier *this, UFG::SimComponent *component, __int64 slotIndex)
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
  UFG::qSymbol *v2; // rbx
  UFG::SimObject *v3; // rdi
  unsigned int v4; // eax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v5; // [rsp+48h] [rbp+10h]

  v2 = name;
  v3 = this;
  v4 = name->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::qSafePointerNodeWithCallbacks<UFG::SimObject>((UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObject::`vftable;
  *(_QWORD *)&v3->m_Name.mUID = v2->mUID;
  v3->m_pSceneObj = 0i64;
  v3->m_pTransformNodeComponent = 0i64;
  v3->m_Components.p = 0i64;
  *(_QWORD *)&v3->m_Components.size = 0i64;
  v5 = &v3->m_UnboundComponentHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

// File Line: 223
// RVA: 0x18F750
void __fastcall UFG::SimObject::~SimObject(UFG::SimObject *this)
{
  UFG::SimObject *v1; // r14
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v2; // r15
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  char v10; // cl
  int v11; // eax
  __int64 v12; // rdi
  signed __int64 v13; // rsi
  UFG::SimComponent *v14; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  unsigned int i; // er10
  UFG::SimComponent *v23; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  unsigned int j; // ebx
  UFG::SimComponent *v28; // rcx
  unsigned __int16 v29; // ax
  unsigned int v30; // ebx
  UFG::qBaseTreeRB *k; // rax
  unsigned int v32; // edx
  __int64 v33; // rcx
  __int64 v34; // rdx
  signed __int64 v35; // rdx
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *l; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v42; // rax
  UFG::SimComponentHolder *v43; // rcx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)&UFG::SimObject::`vftable;
  this->m_Flags |= 2u;
  v2 = &this->m_UnboundComponentHandles;
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)this->m_UnboundComponentHandles.mNode.mNext != &this->m_UnboundComponentHandles )
  {
    while ( 1 )
    {
      v3 = v1->m_UnboundComponentHandles.mNode.mNext;
      if ( v3[1].mNext )
      {
        v4 = v3->mPrev;
        v5 = v3->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        v3[1].mNext = 0i64;
      }
      else
      {
        if ( !v3[2].mPrev )
          goto LABEL_9;
        v6 = v3->mPrev;
        if ( v3->mPrev == v3 && v3->mNext == v3 )
          goto LABEL_9;
        v7 = v3->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
      }
      v3[2].mPrev = 0i64;
      v3->mNext = v3;
      v3->mPrev = v3;
LABEL_9:
      LODWORD(v3[2].mNext) = 1;
      v8 = v3->mPrev;
      v9 = v3->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v3->mPrev = v3;
      v3->mNext = v3;
      if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v2->mNode.mNext == v2 )
        goto LABEL_10;
    }
  }
  do
  {
LABEL_10:
    v10 = 0;
    v11 = v1->m_Components.size - 1;
    v12 = v11;
    if ( v11 < 0 )
      break;
    v13 = v11;
    do
    {
      v14 = v1->m_Components.p[v13].m_pComponent;
      if ( v14 && !(v14->m_Flags & 0x10) )
      {
        ((void (__fastcall *)(UFG::SimComponent *))v14->vfptr[10].__vecDelDtor)(v14);
        v14->m_Flags |= 0x10u;
        v10 = 1;
      }
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  while ( v10 );
  for ( ;
        (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v2->mNode.mNext != v2;
        v15->mNext = v15 )
  {
    v15 = v1->m_UnboundComponentHandles.mNode.mNext;
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
  for ( i = 0; i < v1->m_Components.size; ++i )
  {
    v23 = v1->m_Components.p[i].m_pComponent;
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
  for ( j = 0; j < v1->m_Components.size; ++j )
  {
    v28 = v1->m_Components.p[j].m_pComponent;
    if ( v28 )
    {
      v28->m_Flags &= 0xFFEEu;
      if ( v28->m_Flags & 8 )
        v28->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v28->vfptr, 1u);
      v1->m_Components.p[j].m_pComponent = 0i64;
    }
  }
  v29 = v1->m_Flags;
  if ( v29 & 1 )
    v1->m_Flags = v29 & 0xFFFE;
  v30 = v1->mNode.mUID;
  for ( k = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14235C1A0);
        k;
        k = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14235C1A0, &k->mRoot) )
  {
    v32 = HIDWORD(k[1].mRoot.mChild[1]);
    if ( v30 >= v32 )
    {
      v33 = v30 - v32;
      if ( (unsigned int)v33 < LODWORD(k[1].mRoot.mChild[1]) )
      {
        v34 = *(_QWORD *)&k[1].mRoot.mUID;
        if ( v34 )
          v35 = (signed __int64)&k[1].mRoot.mUID + v34;
        else
          v35 = 0i64;
        *(_BYTE *)(v33 + v35) = 0;
        UFG::qSymbolRegistry::PurgeRef(v30);
        break;
      }
    }
  }
  for ( l = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v2->mNode.mNext;
        l != v2;
        l = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v2->mNode.mNext )
  {
    v37 = l->mNode.mPrev;
    v38 = l->mNode.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    l->mNode.mPrev = &l->mNode;
    l->mNode.mNext = &l->mNode;
    v39 = l->mNode.mPrev;
    v40 = l->mNode.mNext;
    v39->mNext = v40;
    v40->mPrev = v39;
    l->mNode.mPrev = &l->mNode;
    l->mNode.mNext = &l->mNode;
    operator delete[](l);
  }
  v41 = v2->mNode.mPrev;
  v42 = v2->mNode.mNext;
  v41->mNext = v42;
  v42->mPrev = v41;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v43 = v1->m_Components.p;
  if ( v43 )
    operator delete[](v43);
  v1->m_Components.p = 0i64;
  *(_QWORD *)&v1->m_Components.size = 0i64;
  UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::~qSafePointerNodeWithCallbacks<UFG::SimObject>((UFG::qSafePointerNodeWithCallbacks<UFG::SimObject> *)&v1->vfptr);
}

// File Line: 333
// RVA: 0x190060
void __fastcall UFG::SimObject::Attach(UFG::SimObject *this, UFG::SimComponent *component, unsigned int index)
{
  unsigned int v3; // ebp
  UFG::SimComponent *v4; // r14
  UFG::SimObject *v5; // rsi
  UFG::SimComponentHolder *v6; // rdi
  unsigned int v7; // ebx
  UFG::SimComponent *v8; // rdi
  __int64 v9; // rbx
  __int64 v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  signed __int64 v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *i; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v17; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rax
  unsigned __int16 v21; // ax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v22; // rax
  unsigned __int16 v23; // ax
  unsigned int v24; // ebx
  UFG::SimComponent *v25; // rcx
  unsigned __int16 v26; // ax

  if ( !component )
    return;
  v3 = component->m_TypeUID;
  component->m_pSimObject = this;
  v4 = component;
  v5 = this;
  if ( v3 == UFG::TransformNodeComponent::_TypeUID && !this->m_pTransformNodeComponent )
    this->m_pTransformNodeComponent = (UFG::TransformNodeComponent *)component;
  if ( index < this->m_Components.size )
  {
    v6 = &this->m_Components.p[index];
    if ( v6->m_pComponent )
    {
      v8 = v6->m_pComponent;
      v9 = ((__int64 (__fastcall *)(UFG::SimComponent *))component->vfptr[4].__vecDelDtor)(component);
      v10 = ((__int64 (__fastcall *)(UFG::SimComponent *))v8->vfptr[4].__vecDelDtor)(v8);
      UFG::qPrintf(
        "WARNING:already have a component of of the given type %s in this slot, add this component %s into dynamic slot a"
        "fter type table, this could be a construction error with competing components",
        v10,
        v9);
LABEL_9:
      index = (unsigned __int8)v5->m_ReservedComponentSlots;
      v7 = v5->m_Components.size;
      if ( index >= v7 )
        goto LABEL_15;
      while ( v5->m_Components.p[index].m_pComponent )
      {
        if ( ++index >= v7 )
          goto LABEL_15;
      }
      if ( index == -1 )
      {
LABEL_15:
        v11 = v5->m_Components.capacity;
        v12 = v7 + 1;
        if ( v12 > v11 )
        {
          if ( v11 )
            v13 = 2 * v11;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 - v12 > 0x10000 )
            v13 = v12 + 0x10000;
          UFG::qArray<UFG::SimComponentHolder,0>::Reallocate(&v5->m_Components, v13, "SimObject::m_Components");
        }
        v5->m_Components.size = v12;
        index = v12 - 1;
      }
      v14 = (signed __int64)&v5->m_Components.p[index];
      *(_QWORD *)v14 = v4;
      *(_DWORD *)(v14 + 8) = v3;
      goto LABEL_26;
    }
    v6->m_pComponent = component;
    v6->m_TypeUID = v3;
  }
  if ( index == -1 )
    goto LABEL_9;
LABEL_26:
  v4->m_SimObjIndex = index;
  for ( i = v5->m_UnboundComponentHandles.mNode.mNext;
        i != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v5->m_UnboundComponentHandles;
        i = i->mNext )
  {
    if ( (v3 & 0xFE000000) == ((_QWORD)i[1].mPrev & 0xFE000000) && !((_QWORD)i[1].mPrev & ~v3 & 0x1FFFFFF) )
    {
      v16 = i;
      v17 = &i->mNext;
      v18 = &i->mNext->mPrev;
      v19 = v16->mPrev;
      v19->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v18;
      *v18 = v19;
      v16->mPrev = v16;
      *v17 = v16;
      i = *v18;
      v16[1].mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v4;
      v20 = v4->m_BoundComponentHandles.mNode.mPrev;
      v20->mNext = v16;
      v16->mPrev = v20;
      *v17 = &v4->m_BoundComponentHandles.mNode;
      v4->m_BoundComponentHandles.mNode.mPrev = v16;
    }
  }
  v21 = v5->m_Flags;
  if ( !(v21 & 3) )
    v5->m_Flags = v21 | 1;
  if ( !(v5->m_Flags & 0x10) )
  {
    v22 = v4->vfptr;
    v4->m_Flags |= 1u;
    v22[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)v5);
    v23 = v5->m_Flags;
    if ( !(v23 & 0x10) )
    {
      v24 = 0;
      v5->m_Flags = v23 & 0xFFFE;
      if ( v5->m_Components.size )
      {
        do
        {
          v25 = v5->m_Components.p[v24].m_pComponent;
          if ( v25 )
          {
            v26 = v25->m_Flags;
            if ( !(v26 & 1) )
            {
              v25->m_pSimObject = v5;
              v25->m_Flags = v26 | 1;
              v25->vfptr[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v25->vfptr, (unsigned int)v5);
            }
          }
          ++v24;
        }
        while ( v24 < v5->m_Components.size );
      }
    }
  }
}

// File Line: 438
// RVA: 0x1908E0
void __fastcall UFG::SimObject::Detach(UFG::SimObject *this, UFG::SimComponent *component)
{
  char **v2; // r10
  UFG::SimComponent *v3; // rbx
  UFG::SimObject *v4; // rdi
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v5; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  unsigned __int16 v10; // ax
  unsigned int v11; // eax
  signed __int64 v12; // rcx

  v2 = (char **)&component->m_BoundComponentHandles;
  v3 = component;
  v4 = this;
  if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)component->m_BoundComponentHandles.mNode.mNext != &component->m_BoundComponentHandles )
  {
    v5 = &this->m_UnboundComponentHandles;
    do
    {
      v6 = v3->m_BoundComponentHandles.mNode.mNext;
      v7 = v6->mNext;
      v8 = v6->mPrev;
      v8->mNext = v7;
      v7->mPrev = v8;
      v6->mPrev = v6;
      v6->mNext = v6;
      v6[1].mNext = 0i64;
      v9 = v5->mNode.mPrev;
      v9->mNext = v6;
      v6->mPrev = v9;
      v6->mNext = &v5->mNode;
      v5->mNode.mPrev = v6;
    }
    while ( v2[1] != (char *)v2 );
  }
  v10 = this->m_Flags;
  if ( !(v10 & 3) )
    this->m_Flags = v10 | 1;
  ((void (__fastcall *)(UFG::SimComponent *))v3->vfptr[10].__vecDelDtor)(v3);
  v3->m_pSimObject = 0i64;
  v3->m_Flags &= 0xFFFEu;
  v11 = v3->m_SimObjIndex;
  v3->m_SimObjIndex = -1;
  v12 = v11;
  v4->m_Components.p[v12].m_pComponent = 0i64;
  v4->m_Components.p[v12].m_TypeUID = 0;
  if ( v3->m_TypeUID == UFG::TransformNodeComponent::_TypeUID
    && (UFG::SimComponent *)v4->m_pTransformNodeComponent == v3 )
  {
    v4->m_pTransformNodeComponent = 0i64;
  }
}

// File Line: 490
// RVA: 0x190D80
void __fastcall UFG::SimObject::NotifyComponentsOfChange(UFG::SimObject *this)
{
  unsigned __int16 v1; // ax
  UFG::SimObject *v2; // rdi
  unsigned int v3; // ebx
  UFG::SimComponent *v4; // rcx
  unsigned __int16 v5; // ax

  v1 = this->m_Flags;
  v2 = this;
  if ( !(v1 & 0x10) )
  {
    v3 = 0;
    this->m_Flags = v1 & 0xFFFE;
    if ( this->m_Components.size )
    {
      do
      {
        v4 = v2->m_Components.p[v3].m_pComponent;
        if ( v4 )
        {
          v5 = v4->m_Flags;
          if ( !(v5 & 1) )
          {
            v4->m_pSimObject = v2;
            v4->m_Flags = v5 | 1;
            v4->vfptr[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)v2);
          }
        }
        ++v3;
      }
      while ( v3 < v2->m_Components.size );
    }
  }
}

// File Line: 580
// RVA: 0x1916D0
__int64 __fastcall UFG::SimObject::Suspend(UFG::SimObject *this)
{
  unsigned int v1; // ebx
  UFG::SimObject *v2; // rdi
  UFG::SimComponent *v3; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_Components.size )
  {
    do
    {
      v3 = v2->m_Components.p[v1].m_pComponent;
      if ( v3 )
        ((void (*)(void))v3->vfptr[8].__vecDelDtor)();
      ++v1;
    }
    while ( v1 < v2->m_Components.size );
  }
  return 0i64;
}

// File Line: 597
// RVA: 0x1911F0
__int64 __fastcall UFG::SimObject::Restore(UFG::SimObject *this)
{
  unsigned int v1; // ebx
  UFG::SimObject *v2; // rdi
  UFG::SimComponent *v3; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_Components.size )
  {
    do
    {
      v3 = v2->m_Components.p[v1].m_pComponent;
      if ( v3 && (LOBYTE(v3->m_Flags) >> 1) & 1 )
        ((void (*)(void))v3->vfptr[9].__vecDelDtor)();
      ++v1;
    }
    while ( v1 < v2->m_Components.size );
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
  UFG::SimObject *v3; // r8

  v3 = this->m_pSimObject;
  this->m_TypeUID = type;
  if ( v3 )
    v3->m_Components.p[this->m_SimObjIndex].m_TypeUID = type;
}

// File Line: 684
// RVA: 0x190CF0
bool __fastcall UFG::SimComponent::IsType(UFG::SimComponent *this, unsigned int type)
{
  return !((type ^ this->m_TypeUID) & 0xFE000000) && !(type & ~this->m_TypeUID & 0x1FFFFFF);
}

// File Line: 690
// RVA: 0x190B30
UFG::TransformNodeComponent *__fastcall UFG::SimObject::GetComponentOfType(UFG::SimObject *this, unsigned int type_uid, unsigned int name_uid, UFG::SimComponent *prev_component)
{
  unsigned int v4; // ebx
  unsigned int v5; // er11
  unsigned int v7; // edx
  UFG::SimComponentHolder *v8; // rcx

  v4 = this->m_Components.size;
  v5 = type_uid;
  if ( !v4 )
    return 0i64;
  if ( type_uid == UFG::TransformNodeComponent::_TypeUID && !name_uid )
    return this->m_pTransformNodeComponent;
  v7 = 0;
  if ( prev_component )
    v7 = prev_component->m_SimObjIndex + 1;
  if ( v7 >= v4 )
    return 0i64;
  v8 = &this->m_Components.p[v7];
  while ( !v8->m_pComponent
       || (v5 ^ v8->m_TypeUID) & 0xFE000000
       || v5 & ~v8->m_TypeUID & 0x1FFFFFF
       || name_uid && v8->m_pComponent->m_NameUID != name_uid )
  {
    ++v7;
    ++v8;
    if ( v7 >= v4 )
      return 0i64;
  }
  return (UFG::TransformNodeComponent *)v8->m_pComponent;
}

// File Line: 758
// RVA: 0x190AD0
UFG::SimComponent *__fastcall UFG::SimObject::GetComponentOfType(UFG::SimObject *this, unsigned int type_uid)
{
  unsigned int v2; // er9
  unsigned int v3; // er11
  unsigned int v4; // er8
  unsigned int v5; // er10
  UFG::SimComponentHolder *v6; // rdx
  unsigned int v7; // er10

  v2 = this->m_Components.size;
  v3 = type_uid;
  if ( !v2 )
    return 0i64;
  v4 = 0;
  if ( !v2 )
    return 0i64;
  v5 = type_uid;
  v6 = this->m_Components.p;
  v7 = v5 & 0xFE000000;
  while ( (v6->m_TypeUID & 0xFE000000) != v7 || v3 & ~v6->m_TypeUID & 0x1FFFFFF )
  {
    ++v4;
    ++v6;
    if ( v4 >= v2 )
      return 0i64;
  }
  return v6->m_pComponent;
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
  this->m_Flags &= 0xFFEFu;
  JUMPOUT(this->m_Flags & 1, 0, UFG::SimObject::NotifyComponentsOfChange);
}

