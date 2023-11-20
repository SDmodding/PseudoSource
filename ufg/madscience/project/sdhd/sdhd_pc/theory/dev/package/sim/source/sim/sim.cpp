// File Line: 21
// RVA: 0x1468850
__int64 UFG::_dynamic_initializer_for__gSim__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gSim.mSimObjects.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_14235C3E8);
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_14235C430);
  unk_14235C478 = &unk_14235C478;
  unk_14235C480 = &unk_14235C478;
  LocalPlayer = 0i64;
  unk_14235C498 = 0i64;
  unk_14235C490 = 0i64;
  return atexit(UFG::_dynamic_atexit_destructor_for__gSim__);
}

// File Line: 22
// RVA: 0x190BD0
UFG::ComponentIDDesc *__fastcall UFG::TransformNodeComponent::GetDesc(UFG::TransformNodeComponent *this)
{
  return &UFG::TransformNodeComponent::_TypeIDesc;
}

// File Line: 33
// RVA: 0x190320
UFG::SimObject *__fastcall UFG::Simulation::CreateSimObject(UFG::Simulation *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::Simulation *v3; // rsi
  UFG::allocator::free_link *v4; // rax
  UFG::qBaseNodeRB *v5; // rdi
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rbx

  v2 = name;
  v3 = this;
  v4 = UFG::qMemoryPool::Allocate(gSimulationMemoryPool, 0x80ui64, "SimObject", 0i64, 1u);
  v5 = 0i64;
  if ( v4 )
  {
    UFG::SimObject::SimObject((UFG::SimObject *)v4, v2);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
    v5 = &v7->mNode;
  UFG::qBaseTreeRB::Add(&v3->mSimObjects.mTree, v5);
  return v7;
}

// File Line: 41
// RVA: 0x1917A0
void __fastcall UFG::Simulation::TrackSimObject(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  if ( pSimObj )
    UFG::qBaseTreeRB::Add(&this->mSimObjects.mTree, &pSimObj->mNode);
  else
    UFG::qBaseTreeRB::Add(&this->mSimObjects.mTree, 0i64);
}

// File Line: 49
// RVA: 0x1917C0
char __fastcall UFG::Simulation::UntrackSimObject(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v4; // rsi
  UFG::qBaseNodeRB *v5; // rdx

  v2 = 0i64;
  v3 = pSimObj;
  v4 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)this;
  if ( pSimObj )
    v5 = &pSimObj->mNode;
  else
    v5 = 0i64;
  if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, v5) )
    return 0;
  if ( v3 )
    v2 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mNode;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v4, v2);
  return 1;
}

// File Line: 62
// RVA: 0x190760
void __fastcall UFG::Simulation::DestroySimObject(UFG::Simulation *this, UFG::SimObject *object)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rsi
  UFG::SimObject *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // edx
  UFG::Simulation *v6; // rbp
  UFG::SimObject **v7; // r8
  bool v8; // al
  UFG::qBaseNodeRB *v9; // rdx
  UFG::qBaseTreeVariableRB<unsigned __int64> *v10; // rcx
  __int64 v11; // rbp
  unsigned int v12; // edx
  unsigned int v13; // edi
  unsigned int v14; // edx
  UFG::qReflectInventoryBase **v15; // rax
  unsigned int v16; // er8
  __int64 v17; // rcx
  UFG::qReflectInventoryBase **v18; // rdx

  v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCurrentDestructingObjects;
  v3 = object;
  v4 = 0;
  v5 = this->m_aCurrentDestructingObjects.size;
  v6 = this;
  if ( !v5 )
    goto LABEL_7;
  v7 = this->m_aCurrentDestructingObjects.p;
  while ( v3 != *v7 )
  {
    ++v4;
    ++v7;
    if ( v4 >= v5 )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    if ( (_QWORD)v3->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64 && !UFG::Simulation::UntrackSimObject(this, v3) )
    {
      v8 = UFG::qBaseTreeRB::Contains(&v6->mSimObjectsToBeDeleted.mTree, &v3->mNode);
      v9 = &v3->mNode;
      if ( v8 )
      {
        v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v6->mSimObjectsToBeDeleted;
      }
      else
      {
        if ( !UFG::qBaseTreeRB::Contains(&v6->mSimObjectsToBeDeletedRecursively.mTree, v9) )
          goto LABEL_14;
        v9 = &v3->mNode;
        v10 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v6->mSimObjectsToBeDeletedRecursively;
      }
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v10, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
    }
LABEL_14:
    v11 = v2->size;
    v12 = v2->capacity;
    v13 = v11 + 1;
    if ( (signed int)v11 + 1 > v12 )
    {
      if ( v12 )
        v14 = 2 * v12;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 <= 2 )
        v14 = 2;
      if ( v14 - v13 > 0x10000 )
        v14 = v11 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v14, "qArray.Add");
    }
    v15 = v2->p;
    v2->size = v13;
    v15[v11] = (UFG::qReflectInventoryBase *)v3;
    v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimObject> *)&v3->vfptr, 1u);
    v16 = v2->size;
    v17 = 0i64;
    if ( v2->size )
    {
      v18 = v2->p;
      while ( v3 != (UFG::SimObject *)v18[v17] )
      {
        v17 = (unsigned int)(v17 + 1);
        if ( (unsigned int)v17 >= v16 )
          return;
      }
      if ( (signed int)v17 >= 0 )
      {
        v18[v17] = v18[v16 - 1];
        if ( v2->size > 1 )
          --v2->size;
        else
          v2->size = 0;
      }
    }
  }
}

// File Line: 155
// RVA: 0x190F10
void __fastcall UFG::Simulation::QueueSimObjectToBeDestroyed(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qBaseNodeRB *v2; // rdi
  UFG::SimObject *v3; // rbx
  unsigned int v4; // edx
  UFG::Simulation *v5; // rsi
  unsigned int v6; // eax
  UFG::SimObject **v7; // r8
  UFG::qBaseNodeRB *v8; // rdx

  v2 = 0i64;
  v3 = pSimObj;
  v4 = this->m_aCurrentDestructingObjects.size;
  v5 = this;
  v6 = 0;
  if ( !v4 )
    goto LABEL_7;
  v7 = this->m_aCurrentDestructingObjects.p;
  while ( v3 != *v7 )
  {
    ++v6;
    ++v7;
    if ( v6 >= v4 )
      goto LABEL_7;
  }
  if ( v6 == -1 )
  {
LABEL_7:
    UFG::Simulation::UntrackSimObject(this, v3);
    v8 = &v3->mNode;
    if ( !v3 )
      v8 = 0i64;
    if ( !UFG::qBaseTreeRB::Contains(&v5->mSimObjectsToBeDeleted.mTree, v8) )
    {
      if ( v3 )
        v2 = &v3->mNode;
      UFG::qBaseTreeRB::Add(&v5->mSimObjectsToBeDeleted.mTree, v2);
    }
  }
}

// File Line: 174
// RVA: 0x191030
void __fastcall UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qBaseNodeRB *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::Simulation *v4; // rsi
  UFG::qBaseNodeRB *v5; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v6; // rdx
  UFG::qBaseNodeRB *v7; // rdx

  v2 = 0i64;
  v3 = pSimObj;
  v4 = this;
  if ( pSimObj )
    v5 = &pSimObj->mNode;
  else
    v5 = 0i64;
  if ( UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, v5) )
  {
    v6 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mNode;
    if ( !v3 )
      v6 = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v4, v6);
    v7 = &v3->mNode;
    if ( !v3 )
      v7 = 0i64;
    if ( !UFG::qBaseTreeRB::Contains(&v4->mSimObjectsToBeDeleted.mTree, v7) )
    {
      if ( v3 )
        v2 = &v3->mNode;
      UFG::qBaseTreeRB::Add(&v4->mSimObjectsToBeDeleted.mTree, v2);
    }
  }
}

// File Line: 201
// RVA: 0x190FA0
void __fastcall UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qBaseNodeRB *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::Simulation *v4; // rsi
  UFG::qBaseNodeRB *v5; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v6; // rdx
  UFG::qBaseNodeRB *v7; // rdx

  v2 = 0i64;
  v3 = pSimObj;
  v4 = this;
  if ( pSimObj )
    v5 = &pSimObj->mNode;
  else
    v5 = 0i64;
  if ( UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, v5) )
  {
    v6 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mNode;
    if ( !v3 )
      v6 = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v4, v6);
  }
  v7 = &v3->mNode;
  if ( !v3 )
    v7 = 0i64;
  if ( !UFG::qBaseTreeRB::Contains(&v4->mSimObjectsToBeDeletedRecursively.mTree, v7) )
  {
    if ( v3 )
      v2 = &v3->mNode;
    UFG::qBaseTreeRB::Add(&v4->mSimObjectsToBeDeletedRecursively.mTree, v2);
  }
}

// File Line: 211
// RVA: 0x190720
void __fastcall UFG::Simulation::DestroySimComponent(UFG::Simulation *this, UFG::SimComponent *component)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rbx

  if ( component )
  {
    v2 = component->m_pSimObject;
    v3 = component;
    if ( v2 )
    {
      if ( (LOBYTE(v2->m_Flags) >> 1) & 1 )
        return;
      ((void (*)(void))v2->vfptr[2].__vecDelDtor)();
    }
    v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, 1u);
  }
}

// File Line: 230
// RVA: 0x1905D0
void __fastcall UFG::Simulation::DestroyAllSimObjects(UFG::Simulation *this)
{
  UFG::Simulation *v1; // rdi
  UFG::qBaseNodeRB *v2; // rax
  UFG::SimObject *v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx

  v1 = this;
  UFG::Simulation::DestroyQueuedSimObjects(this);
  if ( v1->mSimObjects.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qBaseTreeRB::GetTail(&v1->mSimObjects.mTree);
      if ( !v2 )
        break;
      v3 = (UFG::SimObject *)&v2[-2].mUID;
      if ( v2 == (UFG::qBaseNodeRB *)40 )
        goto LABEL_6;
      v4 = v2;
LABEL_7:
      if ( UFG::qBaseTreeRB::Contains(&v1->mSimObjects.mTree, v4) )
      {
        if ( v3 )
          v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mNode;
        else
          v5 = 0i64;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v1, v5);
      }
      UFG::Simulation::DestroySimObject(v1, v3);
      if ( !v1->mSimObjects.mTree.mCount )
        return;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
}

// File Line: 244
// RVA: 0x190650
void __fastcall UFG::Simulation::DestroyQueuedSimObjects(UFG::Simulation *this)
{
  UFG::Simulation *v1; // rdi
  UFG::qBaseNodeRB *v2; // rax
  UFG::SimObject *v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  UFG::qBaseNodeRB *v5; // rax
  UFG::SimObject *v6; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rdx

  v1 = this;
  if ( this->mSimObjectsToBeDeleted.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qBaseTreeRB::GetTail(&v1->mSimObjectsToBeDeleted.mTree);
      if ( !v2 )
        break;
      v3 = (UFG::SimObject *)&v2[0xFFFFFFFE].mUID;
      if ( v2 == (UFG::qBaseNodeRB *)0x28 )
        goto LABEL_6;
      v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mSimObjectsToBeDeleted,
        v4);
      UFG::Simulation::DestroySimObject(v1, v3);
      if ( !v1->mSimObjectsToBeDeleted.mTree.mCount )
        goto LABEL_8;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_8:
  if ( v1->mSimObjectsToBeDeletedRecursively.mTree.mCount )
  {
    while ( 1 )
    {
      v5 = UFG::qBaseTreeRB::GetTail(&v1->mSimObjectsToBeDeletedRecursively.mTree);
      if ( !v5 )
        break;
      v6 = (UFG::SimObject *)&v5[-2].mUID;
      if ( v5 == (UFG::qBaseNodeRB *)40 )
        goto LABEL_13;
      v7 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v5;
LABEL_14:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mSimObjectsToBeDeletedRecursively,
        v7);
      if ( v6 )
        UFG::Simulation::DestroySimObject(v1, v6);
      if ( !v1->mSimObjectsToBeDeletedRecursively.mTree.mCount )
        return;
    }
    v6 = 0i64;
LABEL_13:
    v7 = 0i64;
    goto LABEL_14;
  }
}

// File Line: 268
// RVA: 0x190A50
UFG::qSymbol *__fastcall UFG::Simulation::GenerateUniqueName(UFG::Simulation *this, UFG::qSymbol *result, const char *pRoot)
{
  UFG::qSymbol *v3; // rdi
  UFG::Simulation *v4; // rsi
  UFG::qSymbol *v5; // rax
  unsigned int v6; // ebx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol resulta; // [rsp+38h] [rbp+10h]

  v3 = result;
  v4 = this;
  UFG::qSymbol::create_from_string(result, pRoot);
  while ( 1 )
  {
    v5 = UFG::qSymbol::create_increment(&resulta, v3, 1);
    v6 = v5->mUID;
    v3->mUID = v5->mUID;
    if ( !v6 )
      break;
    v7 = UFG::qBaseTreeRB::Get(&v4->mSimObjects.mTree, v6);
    if ( !v7 || v7 == (UFG::qBaseTreeRB *)40 )
    {
      v8 = UFG::qBaseTreeRB::Get(&v4->mSimObjectsToBeDeleted.mTree, v6);
      if ( !v8 || v8 == (UFG::qBaseTreeRB *)40 )
        break;
    }
  }
  return v3;
}

// File Line: 280
// RVA: 0x1909D0
UFG::qSymbol *__fastcall UFG::Simulation::GenerateUniqueName(UFG::Simulation *this, UFG::qSymbol *result, UFG::qSymbol *root)
{
  unsigned __int128 v3; // di
  UFG::qSymbol *v4; // rax
  unsigned int v5; // ebx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qSymbol resulta; // [rsp+38h] [rbp+10h]

  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)result);
  result->mUID = root->mUID;
  while ( 1 )
  {
    v4 = UFG::qSymbol::create_increment(&resulta, (UFG::qSymbol *)v3, 1);
    v5 = v4->mUID;
    *(UFG::qSymbol *)v3 = (UFG::qSymbol)v4->mUID;
    if ( !v5 )
      break;
    v6 = UFG::qBaseTreeRB::Get(*((UFG::qBaseTreeRB **)&v3 + 1), v5);
    if ( !v6 || v6 == (UFG::qBaseTreeRB *)40 )
    {
      v7 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(*((_QWORD *)&v3 + 1) + 72i64), v5);
      if ( !v7 || v7 == (UFG::qBaseTreeRB *)40 )
        break;
    }
  }
  return (UFG::qSymbol *)v3;
}

// File Line: 307
// RVA: 0x190BF0
UFG::qBaseNodeRB *__fastcall UFG::Simulation::GetSimObject(UFG::Simulation *this, UFG::qSymbol *name)
{
  unsigned int v2; // ebx
  UFG::Simulation *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *result; // rax
  UFG::qBaseTreeRB *v6; // rax

  v2 = name->mUID;
  v3 = this;
  if ( !name->mUID
    || ((v4 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, v2)) == 0i64 || (result = &v4[-1].mNULL) == 0i64)
    && ((v6 = UFG::qBaseTreeRB::Get(&v3->mSimObjectsToBeDeleted.mTree, v2)) == 0i64 || (result = &v6[-1].mNULL) == 0i64) )
  {
    result = 0i64;
  }
  return result;
}

// File Line: 329
// RVA: 0x190C40
UFG::qBaseNodeRB *__fastcall UFG::Simulation::GetSimObject(UFG::Simulation *this, unsigned int name_uid)
{
  unsigned int v2; // ebx
  UFG::Simulation *v3; // rdi
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *result; // rax
  UFG::qBaseTreeRB *v6; // rax

  v2 = name_uid;
  v3 = this;
  if ( !name_uid
    || ((v4 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, name_uid)) == 0i64 || (result = &v4[-1].mNULL) == 0i64)
    && ((v6 = UFG::qBaseTreeRB::Get(&v3->mSimObjectsToBeDeleted.mTree, v2)) == 0i64 || (result = &v6[-1].mNULL) == 0i64) )
  {
    result = 0i64;
  }
  return result;
}

