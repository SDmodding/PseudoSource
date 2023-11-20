// File Line: 56
// RVA: 0x14BD040
__int64 UFG::_dynamic_initializer_for__gRigInstanceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gRigInstanceInventory.vfptr,
    "RigInstanceInventory",
    0x9A00456E,
    0x5C66C6BDu,
    0,
    0);
  UFG::gRigInstanceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::RigInstanceInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gRigInstanceInventory__);
}

// File Line: 77
// RVA: 0x3A0A40
void __fastcall UFG::RigInstanceInventory::Add(UFG::RigInstanceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::RigInstanceInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::RigInstanceResource::RigInstanceResource((UFG::RigInstanceResource *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 89
// RVA: 0x3B4BE0
char __fastcall UFG::UpdateRigs(unsigned int maxPerFrame)
{
  unsigned int v1; // ebp
  int v2; // esi
  UFG::qBaseNodeRB *v3; // rdi
  __int64 v4; // rbx
  signed __int64 v5; // rcx

  v1 = maxPerFrame;
  v2 = 0;
  v3 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423CE990);
  if ( !v3 )
    return 1;
  while ( 1 )
  {
    v4 = 0i64;
    if ( v3[2].mUID )
      break;
LABEL_7:
    v3 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423CE990, v3);
    if ( !v3 )
      return 1;
  }
  while ( 1 )
  {
    v5 = (signed __int64)&v3[3].mParent[3 * v4];
    if ( !*(_QWORD *)(*(_QWORD *)(v5 + 72) + 16i64) && !(*(_BYTE *)(v5 + 80) & 1) )
    {
      UFG::InstantiateRigInstance((UFG::RigInstance *)v5);
      if ( ++v2 == v1 )
        return 0;
    }
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= v3[2].mUID )
      goto LABEL_7;
  }
}

// File Line: 115
// RVA: 0x3AAF00
void __fastcall UFG::InstantiateRigInstance(UFG::RigInstance *instance)
{
  UFG::RigInstance *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rdi
  UFG::SimObject *v4; // rax
  UFG::SimObjectGame *v5; // r9
  UFG::SafePointerHolder *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  UFG::qString v13; // [rsp+38h] [rbp-30h]
  UFG::qSymbol name; // [rsp+70h] [rbp+8h]

  v1 = instance;
  v2 = (UFG::qSymbol *)UFG::qResourceInventory::Get(
                         (UFG::qResourceInventory *)&UFG::gRigInventory.vfptr,
                         instance->mRigGuid);
  if ( v2 )
  {
    v3 = UFG::PropertySetManager::FindPropertySet(v2 + 22);
    if ( v3 )
    {
      name.mUID = v1->mInstanceName.mUID;
      while ( UFG::Simulation::GetSimObject(&UFG::gSim, &name) )
      {
        ++count_0;
        UFG::qString::qString(&v13, "RigInstance-%d");
        UFG::qSymbol::set_from_cstr(&name, v13.mData);
        UFG::qString::~qString(&v13);
      }
      v4 = UFG::SpawnInfoInterface::SpawnObject(&name, v3, &v1->mTransform, Count, 0i64, 0i64);
      v5 = (UFG::SimObjectGame *)v4;
      if ( v4 )
      {
        v6 = v1->mSimObjectHolder;
        if ( v6->mSimObject.m_pPointer )
        {
          v7 = v6->mSimObject.mPrev;
          v8 = v6->mSimObject.mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v6->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mSimObject.mPrev;
          v6->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mSimObject.mPrev;
        }
        v6->mSimObject.m_pPointer = v4;
        v9 = &v4->m_SafePointerList;
        v10 = v4->m_SafePointerList.mNode.mPrev;
        v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mSimObject.mPrev;
        v6->mSimObject.mPrev = v10;
        v6->mSimObject.mNext = &v9->mNode;
        v9->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mSimObject.mPrev;
        v11 = v5->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = v5->m_Components.p[9].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = v5->m_Components.p[8].m_pComponent;
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            v12 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v5->vfptr,
                    UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v12 = v5->m_Components.p[9].m_pComponent;
        }
        if ( v12 )
          v12[2].m_SafePointerList.mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v1;
      }
    }
  }
}

// File Line: 167
// RVA: 0x3ADF50
void __fastcall UFG::RigInstanceInventory::Remove(UFG::RigInstanceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::RigInstanceResource *v2; // rbx

  v2 = (UFG::RigInstanceResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::RigInstanceResource::~RigInstanceResource(v2);
}

// File Line: 186
// RVA: 0x39FBE0
void __fastcall UFG::RigInstance::~RigInstance(UFG::RigInstance *this)
{
  UFG::RigInstance *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::SafePointerHolder *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mSimObjectHolder->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[9].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p[8].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p[9].m_pComponent;
    }
    if ( v4 )
      v4[2].m_SafePointerList.mNode.mNext = 0i64;
    UFG::Simulation::DestroySimObject(&UFG::gSim, v1->mSimObjectHolder->mSimObject.m_pPointer);
  }
  v5 = v1->mSimObjectHolder;
  if ( v5 )
  {
    if ( v5->mSimObject.m_pPointer )
    {
      v6 = v5->mSimObject.mPrev;
      v7 = v5->mSimObject.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
      v5->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    }
    v5->mSimObject.m_pPointer = 0i64;
    v8 = v5->mSimObject.mPrev;
    v9 = v5->mSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v5->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    v5->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mSimObject.mPrev;
    operator delete[](v5);
  }
  v1->mSimObjectHolder = 0i64;
}

// File Line: 205
// RVA: 0x39E4F0
void __fastcall UFG::RigInstanceResource::RigInstanceResource(UFG::RigInstanceResource *this)
{
  UFG::RigInstanceResource *v1; // rsi
  unsigned int v2; // ebx
  signed __int64 v3; // rdi
  UFG::allocator::free_link *v4; // rax

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v1->mInstance = (UFG::RigInstance *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  v2 = 0;
  if ( v1->mNumInstances )
  {
    do
    {
      v3 = (signed __int64)&v1->mInstance[v2];
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
        *(_QWORD *)(v3 + 72) = v4;
      }
      ++v2;
    }
    while ( v2 < v1->mNumInstances );
  }
}

// File Line: 219
// RVA: 0x39FCF0
void __fastcall UFG::RigInstanceResource::~RigInstanceResource(UFG::RigInstanceResource *this)
{
  UFG::RigInstanceResource *v1; // rdi
  __int64 v2; // rbx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v3; // rdi
  UFG::qResourceHandle *i; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  v1 = this;
  v2 = 0i64;
  if ( this->mNumInstances )
  {
    do
    {
      UFG::RigInstance::~RigInstance(&v1->mInstance[v2]);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumInstances );
  }
  v3 = &v1->mResourceHandles;
  for ( i = (UFG::qResourceHandle *)v3->mNode.mNext;
        i != (UFG::qResourceHandle *)v3;
        i = (UFG::qResourceHandle *)v3->mNode.mNext )
  {
    v5 = i->mPrev;
    v6 = i->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    i->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    UFG::qResourceHandle::~qResourceHandle(i);
    operator delete[](i);
  }
  v7 = v3->mNode.mPrev;
  v8 = v3->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
}

// File Line: 231
// RVA: 0x3AE170
void __fastcall UFG::ResetRigInstances(UFG *this)
{
  UFG::qBaseNodeRB *i; // rdi
  unsigned int j; // ebx
  UFG::qBaseNodeRB *k; // rdi
  unsigned int l; // ebx
  signed __int64 v5; // rsi
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
    for ( l = 0; l < k[2].mUID; ++l )
    {
      v5 = 3i64 * l;
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
      UFG::InstantiateRigInstance((UFG::RigInstance *)&k[3].mParent[v5]);
    }
  }
}

