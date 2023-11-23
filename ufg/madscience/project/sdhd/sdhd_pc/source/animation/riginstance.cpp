// File Line: 56
// RVA: 0x14BD040
__int64 UFG::_dynamic_initializer_for__gRigInstanceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gRigInstanceInventory,
    "RigInstanceInventory",
    0x9A00456E,
    0x5C66C6BDu,
    0,
    0);
  UFG::gRigInstanceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::RigInstanceInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gRigInstanceInventory__);
}

// File Line: 77
// RVA: 0x3A0A40
void __fastcall UFG::RigInstanceInventory::Add(
        UFG::RigInstanceInventory *this,
        UFG::RigInstanceResource *resource_data)
{
  if ( resource_data )
    UFG::RigInstanceResource::RigInstanceResource(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 89
// RVA: 0x3B4BE0
char __fastcall UFG::UpdateRigs(unsigned int maxPerFrame)
{
  int v2; // esi
  UFG::qBaseNodeRB *Head; // rdi
  __int64 v4; // rbx
  __int64 v5; // rcx

  v2 = 0;
  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423CE990);
  if ( !Head )
    return 1;
  while ( 1 )
  {
    v4 = 0i64;
    if ( Head[2].mUID )
      break;
LABEL_7:
    Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423CE990, Head);
    if ( !Head )
      return 1;
  }
  while ( 1 )
  {
    v5 = (__int64)&Head[3].mParent[3 * v4];
    if ( !*(_QWORD *)(*(_QWORD *)(v5 + 72) + 16i64) && (*(_BYTE *)(v5 + 80) & 1) == 0 )
    {
      UFG::InstantiateRigInstance((UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v5);
      if ( ++v2 == maxPerFrame )
        return 0;
    }
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= Head[2].mUID )
      goto LABEL_7;
  }
}

// File Line: 115
// RVA: 0x3AAF00
void __fastcall UFG::InstantiateRigInstance(
        UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *instance)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rdi
  UFG::SimObject *v4; // rax
  UFG::SimObjectGame *v5; // r9
  UFG::SafePointerHolder *mNext; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qString v13; // [rsp+38h] [rbp-30h] BYREF
  UFG::qSymbol name; // [rsp+70h] [rbp+8h] BYREF

  v2 = (UFG::qSymbol *)UFG::qResourceInventory::Get(&UFG::gRigInventory, HIDWORD(instance[4].mPrev));
  if ( v2 )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(v2 + 22);
    if ( PropertySet )
    {
      name.mUID = (unsigned int)instance[4].mPrev;
      while ( UFG::Simulation::GetSimObject(&UFG::gSim, &name) )
      {
        UFG::qString::qString(&v13, "RigInstance-%d", (unsigned int)++count_0);
        UFG::qSymbol::set_from_cstr(&name, v13.mData);
        UFG::qString::~qString(&v13);
      }
      v4 = UFG::SpawnInfoInterface::SpawnObject(&name, PropertySet, (UFG::qMatrix44 *)instance, Count, 0i64, 0i64);
      v5 = (UFG::SimObjectGame *)v4;
      if ( v4 )
      {
        mNext = (UFG::SafePointerHolder *)instance[4].mNext;
        if ( mNext->mSimObject.m_pPointer )
        {
          mPrev = mNext->mSimObject.mPrev;
          v8 = mNext->mSimObject.mNext;
          mPrev->mNext = v8;
          v8->mPrev = mPrev;
          mNext->mSimObject.mPrev = &mNext->mSimObject;
          mNext->mSimObject.mNext = &mNext->mSimObject;
        }
        mNext->mSimObject.m_pPointer = v4;
        p_mNode = &v4->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v10 = v4->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v10->mNext = &mNext->mSimObject;
        mNext->mSimObject.mPrev = v10;
        mNext->mSimObject.mNext = p_mNode;
        p_mNode->mPrev = &mNext->mSimObject;
        m_Flags = v5->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v5->m_Components.p[9].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = v5->m_Components.p[8].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = v5->m_Components.p[9].m_pComponent;
        }
        if ( m_pComponent )
          m_pComponent[2].m_SafePointerList.mNode.mNext = instance;
      }
    }
  }
}

// File Line: 167
// RVA: 0x3ADF50
void __fastcall UFG::RigInstanceInventory::Remove(
        UFG::RigInstanceInventory *this,
        UFG::RigInstanceResource *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::RigInstanceResource::~RigInstanceResource(resource_data);
}

// File Line: 186
// RVA: 0x39FBE0
void __fastcall UFG::RigInstance::~RigInstance(UFG::RigInstance *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SafePointerHolder *mSimObjectHolder; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mSimObjectHolder->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
    }
    if ( m_pComponent )
      m_pComponent[2].m_SafePointerList.mNode.mNext = 0i64;
    UFG::Simulation::DestroySimObject(&UFG::gSim, this->mSimObjectHolder->mSimObject.m_pPointer);
  }
  mSimObjectHolder = this->mSimObjectHolder;
  if ( mSimObjectHolder )
  {
    if ( mSimObjectHolder->mSimObject.m_pPointer )
    {
      mPrev = mSimObjectHolder->mSimObject.mPrev;
      mNext = mSimObjectHolder->mSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mSimObjectHolder->mSimObject.mPrev = &mSimObjectHolder->mSimObject;
      mSimObjectHolder->mSimObject.mNext = &mSimObjectHolder->mSimObject;
    }
    mSimObjectHolder->mSimObject.m_pPointer = 0i64;
    v8 = mSimObjectHolder->mSimObject.mPrev;
    v9 = mSimObjectHolder->mSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    mSimObjectHolder->mSimObject.mPrev = &mSimObjectHolder->mSimObject;
    mSimObjectHolder->mSimObject.mNext = &mSimObjectHolder->mSimObject;
    operator delete[](mSimObjectHolder);
  }
  this->mSimObjectHolder = 0i64;
}

// File Line: 205
// RVA: 0x39E4F0
void __fastcall UFG::RigInstanceResource::RigInstanceResource(UFG::RigInstanceResource *this)
{
  unsigned int i; // ebx
  UFG::RigInstance *v3; // rdi
  UFG::allocator::free_link *v4; // rax

  UFG::qResourceData::qResourceData(this);
  this->mInstance = (UFG::RigInstance *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  for ( i = 0; i < this->mNumInstances; ++i )
  {
    v3 = &this->mInstance[i];
    if ( v3 )
    {
      v4 = UFG::qMalloc(0x18ui64, "SafePointerHolder", 0i64);
      if ( v4 )
      {
        v4->mNext = v4;
        v4[1].mNext = v4;
        v4[2].mNext = 0i64;
      }
      else
      {
        v4 = 0i64;
      }
      v3->mSimObjectHolder = (UFG::SafePointerHolder *)v4;
    }
  }
}

// File Line: 219
// RVA: 0x39FCF0
void __fastcall UFG::RigInstanceResource::~RigInstanceResource(UFG::RigInstanceResource *this)
{
  __int64 i; // rbx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  for ( i = 0i64; (unsigned int)i < this->mNumInstances; i = (unsigned int)(i + 1) )
    UFG::RigInstance::~RigInstance(&this->mInstance[i]);
  p_mResourceHandles = &this->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        j != (UFG::qResourceHandle *)p_mResourceHandles;
        j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v7 = p_mResourceHandles->mNode.mPrev;
  v8 = p_mResourceHandles->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

// File Line: 231
// RVA: 0x3AE170
void __fastcall UFG::ResetRigInstances(UFG *this)
{
  UFG::qBaseNodeRB *i; // rdi
  unsigned int j; // ebx
  UFG::qBaseNodeRB *k; // rdi
  unsigned int m; // ebx
  __int64 v5; // rsi
  UFG::qBaseNodeRB *v6; // rbp
  UFG::allocator::free_link *v7; // rax

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423CE990);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423CE990, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
      UFG::RigInstance::~RigInstance((UFG::RigInstance *)&i[3].mParent[3 * j]);
  }
  for ( k = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423CE990);
        k;
        k = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423CE990, k) )
  {
    for ( m = 0; m < k[2].mUID; ++m )
    {
      v5 = 3i64 * m;
      LODWORD(k[3].mParent[v5 + 2].mChild[1]) = 0;
      v6 = &k[3].mParent[v5];
      if ( v6 )
      {
        v7 = UFG::qMalloc(0x18ui64, "SafePointerHolder", 0i64);
        if ( v7 )
        {
          v7->mNext = v7;
          v7[1].mNext = v7;
          v7[2].mNext = 0i64;
        }
        else
        {
          v7 = 0i64;
        }
        v6[2].mChild[0] = (UFG::qBaseNodeRB *)v7;
      }
      UFG::InstantiateRigInstance((UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&k[3].mParent[v5]);
    }
  }
}

