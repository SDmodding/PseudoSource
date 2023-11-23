// File Line: 21
// RVA: 0x1468850
__int64 UFG::_dynamic_initializer_for__gSim__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gSim.mSimObjects.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_14235C3E8);
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_14235C430);
  qword_14235C478 = (__int64)&qword_14235C478;
  qword_14235C480 = (__int64)&qword_14235C478;
  LocalPlayer = 0i64;
  unk_14235C498 = 0i64;
  unk_14235C490 = 0i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSim__);
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
  UFG::allocator::free_link *v4; // rax
  UFG::qNodeRB<UFG::SimObject> *v5; // rdi
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rbx

  v4 = UFG::qMemoryPool::Allocate(gSimulationMemoryPool, 0x80ui64, "SimObject", 0i64, 1u);
  v5 = 0i64;
  if ( v4 )
  {
    UFG::SimObject::SimObject((UFG::SimObject *)v4, name);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
    v5 = &v7->UFG::qNodeRB<UFG::SimObject>;
  UFG::qBaseTreeRB::Add(&this->mSimObjects.mTree, &v5->mNode);
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
  UFG::qNodeRB<UFG::SimObject> *v2; // rdi
  UFG::qNodeRB<UFG::SimObject> *v5; // rdx

  v2 = 0i64;
  if ( pSimObj )
    v5 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
  else
    v5 = 0i64;
  if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, &v5->mNode) )
    return 0;
  if ( pSimObj )
    v2 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
  return 1;
}

// File Line: 62
// RVA: 0x190760
void __fastcall UFG::Simulation::DestroySimObject(UFG::Simulation *this, UFG::SimObject *object)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_aCurrentDestructingObjects; // rsi
  unsigned int v4; // eax
  unsigned int size; // edx
  UFG::SimObject **p; // r8
  bool v8; // al
  UFG::qNodeRB<UFG::SimObject> *v9; // rdx
  UFG::qBaseTreeVariableRB<unsigned __int64> *p_mSimObjectsToBeDeleted; // rcx
  __int64 v11; // rbp
  unsigned int capacity; // edx
  unsigned int v13; // edi
  unsigned int v14; // edx
  UFG::qReflectInventoryBase **v15; // rax
  unsigned int v16; // r8d
  __int64 v17; // rcx
  UFG::qReflectInventoryBase **v18; // rdx

  p_m_aCurrentDestructingObjects = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aCurrentDestructingObjects;
  v4 = 0;
  size = this->m_aCurrentDestructingObjects.size;
  if ( !size )
    goto LABEL_7;
  p = this->m_aCurrentDestructingObjects.p;
  while ( object != *p )
  {
    ++v4;
    ++p;
    if ( v4 >= size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    if ( ((unsigned __int64)object->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64) != 0
      && !UFG::Simulation::UntrackSimObject(this, object) )
    {
      v8 = UFG::qBaseTreeRB::Contains(&this->mSimObjectsToBeDeleted.mTree, &object->mNode);
      v9 = &object->UFG::qNodeRB<UFG::SimObject>;
      if ( v8 )
      {
        p_mSimObjectsToBeDeleted = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mSimObjectsToBeDeleted;
      }
      else
      {
        if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjectsToBeDeletedRecursively.mTree, &v9->mNode) )
          goto LABEL_14;
        v9 = &object->UFG::qNodeRB<UFG::SimObject>;
        p_mSimObjectsToBeDeleted = (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mSimObjectsToBeDeletedRecursively;
      }
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        p_mSimObjectsToBeDeleted,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
    }
LABEL_14:
    v11 = p_m_aCurrentDestructingObjects->size;
    capacity = p_m_aCurrentDestructingObjects->capacity;
    v13 = v11 + 1;
    if ( (int)v11 + 1 > capacity )
    {
      if ( capacity )
        v14 = 2 * capacity;
      else
        v14 = 1;
      for ( ; v14 < v13; v14 *= 2 )
        ;
      if ( v14 <= 2 )
        v14 = 2;
      if ( v14 - v13 > 0x10000 )
        v14 = v11 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_aCurrentDestructingObjects, v14, "qArray.Add");
    }
    v15 = p_m_aCurrentDestructingObjects->p;
    p_m_aCurrentDestructingObjects->size = v13;
    v15[v11] = (UFG::qReflectInventoryBase *)object;
    object->vfptr->__vecDelDtor(object, 1i64);
    v16 = p_m_aCurrentDestructingObjects->size;
    v17 = 0i64;
    if ( p_m_aCurrentDestructingObjects->size )
    {
      v18 = p_m_aCurrentDestructingObjects->p;
      while ( object != (UFG::SimObject *)v18[v17] )
      {
        v17 = (unsigned int)(v17 + 1);
        if ( (unsigned int)v17 >= v16 )
          return;
      }
      if ( (int)v17 >= 0 )
      {
        v18[v17] = v18[v16 - 1];
        if ( p_m_aCurrentDestructingObjects->size > 1 )
          --p_m_aCurrentDestructingObjects->size;
        else
          p_m_aCurrentDestructingObjects->size = 0;
      }
    }
  }
}

// File Line: 155
// RVA: 0x190F10
void __fastcall UFG::Simulation::QueueSimObjectToBeDestroyed(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qNodeRB<UFG::SimObject> *v2; // rdi
  unsigned int size; // edx
  unsigned int v6; // eax
  UFG::SimObject **p; // r8
  UFG::qNodeRB<UFG::SimObject> *v8; // rdx

  v2 = 0i64;
  size = this->m_aCurrentDestructingObjects.size;
  v6 = 0;
  if ( !size )
    goto LABEL_7;
  p = this->m_aCurrentDestructingObjects.p;
  while ( pSimObj != *p )
  {
    ++v6;
    ++p;
    if ( v6 >= size )
      goto LABEL_7;
  }
  if ( v6 == -1 )
  {
LABEL_7:
    UFG::Simulation::UntrackSimObject(this, pSimObj);
    v8 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
    if ( !pSimObj )
      v8 = 0i64;
    if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjectsToBeDeleted.mTree, &v8->mNode) )
    {
      if ( pSimObj )
        v2 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
      UFG::qBaseTreeRB::Add(&this->mSimObjectsToBeDeleted.mTree, &v2->mNode);
    }
  }
}

// File Line: 174
// RVA: 0x191030
void __fastcall UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qNodeRB<UFG::SimObject> *v2; // rdi
  UFG::qNodeRB<UFG::SimObject> *v5; // rdx
  UFG::qNodeRB<UFG::SimObject> *v6; // rdx
  UFG::qNodeRB<UFG::SimObject> *v7; // rdx

  v2 = 0i64;
  if ( pSimObj )
    v5 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
  else
    v5 = 0i64;
  if ( UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, &v5->mNode) )
  {
    v6 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
    if ( !pSimObj )
      v6 = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
    v7 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
    if ( !pSimObj )
      v7 = 0i64;
    if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjectsToBeDeleted.mTree, &v7->mNode) )
    {
      if ( pSimObj )
        v2 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
      UFG::qBaseTreeRB::Add(&this->mSimObjectsToBeDeleted.mTree, &v2->mNode);
    }
  }
}

// File Line: 201
// RVA: 0x190FA0
void __fastcall UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(UFG::Simulation *this, UFG::SimObject *pSimObj)
{
  UFG::qNodeRB<UFG::SimObject> *v2; // rdi
  UFG::qNodeRB<UFG::SimObject> *v5; // rdx
  UFG::qNodeRB<UFG::SimObject> *v6; // rdx
  UFG::qNodeRB<UFG::SimObject> *v7; // rdx

  v2 = 0i64;
  if ( pSimObj )
    v5 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
  else
    v5 = 0i64;
  if ( UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, &v5->mNode) )
  {
    v6 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
    if ( !pSimObj )
      v6 = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v6);
  }
  v7 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
  if ( !pSimObj )
    v7 = 0i64;
  if ( !UFG::qBaseTreeRB::Contains(&this->mSimObjectsToBeDeletedRecursively.mTree, &v7->mNode) )
  {
    if ( pSimObj )
      v2 = &pSimObj->UFG::qNodeRB<UFG::SimObject>;
    UFG::qBaseTreeRB::Add(&this->mSimObjectsToBeDeletedRecursively.mTree, &v2->mNode);
  }
}

// File Line: 211
// RVA: 0x190720
void __fastcall UFG::Simulation::DestroySimComponent(UFG::Simulation *this, UFG::SimComponent *component)
{
  UFG::SimObject *m_pSimObject; // rcx

  if ( component )
  {
    m_pSimObject = component->m_pSimObject;
    if ( m_pSimObject )
    {
      if ( (m_pSimObject->m_Flags & 2) != 0 )
        return;
      ((void (__fastcall *)(UFG::SimObject *))m_pSimObject->vfptr[2].__vecDelDtor)(m_pSimObject);
    }
    component->vfptr->__vecDelDtor(component, 1i64);
  }
}

// File Line: 230
// RVA: 0x1905D0
void __fastcall UFG::Simulation::DestroyAllSimObjects(UFG::Simulation *this)
{
  UFG::qBaseNodeRB *Tail; // rax
  UFG::SimObject *p_mUID; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx

  UFG::Simulation::DestroyQueuedSimObjects(this);
  if ( this->mSimObjects.mTree.mCount )
  {
    while ( 1 )
    {
      Tail = UFG::qBaseTreeRB::GetTail(&this->mSimObjects.mTree);
      if ( !Tail )
        break;
      p_mUID = (UFG::SimObject *)&Tail[-2].mUID;
      if ( Tail == (UFG::qBaseNodeRB *)40 )
        goto LABEL_6;
      v4 = Tail;
LABEL_7:
      if ( UFG::qBaseTreeRB::Contains(&this->mSimObjects.mTree, v4) )
      {
        if ( p_mUID )
          v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&p_mUID->UFG::qNodeRB<UFG::SimObject>;
        else
          v5 = 0i64;
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, v5);
      }
      UFG::Simulation::DestroySimObject(this, p_mUID);
      if ( !this->mSimObjects.mTree.mCount )
        return;
    }
    p_mUID = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
}

// File Line: 244
// RVA: 0x190650
void __fastcall UFG::Simulation::DestroyQueuedSimObjects(UFG::Simulation *this)
{
  UFG::qBaseNodeRB *Tail; // rax
  UFG::SimObject *p_mUID; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  UFG::qBaseNodeRB *v5; // rax
  UFG::SimObject *v6; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rdx

  if ( this->mSimObjectsToBeDeleted.mTree.mCount )
  {
    while ( 1 )
    {
      Tail = UFG::qBaseTreeRB::GetTail(&this->mSimObjectsToBeDeleted.mTree);
      if ( !Tail )
        break;
      p_mUID = (UFG::SimObject *)&Tail[0xFFFFFFFE].mUID;
      if ( Tail == (UFG::qBaseNodeRB *)0x28 )
        goto LABEL_6;
      v4 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)Tail;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mSimObjectsToBeDeleted,
        v4);
      UFG::Simulation::DestroySimObject(this, p_mUID);
      if ( !this->mSimObjectsToBeDeleted.mTree.mCount )
        goto LABEL_8;
    }
    p_mUID = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_8:
  if ( this->mSimObjectsToBeDeletedRecursively.mTree.mCount )
  {
    while ( 1 )
    {
      v5 = UFG::qBaseTreeRB::GetTail(&this->mSimObjectsToBeDeletedRecursively.mTree);
      if ( !v5 )
        break;
      v6 = (UFG::SimObject *)&v5[-2].mUID;
      if ( v5 == (UFG::qBaseNodeRB *)40 )
        goto LABEL_13;
      v7 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v5;
LABEL_14:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mSimObjectsToBeDeletedRecursively,
        v7);
      if ( v6 )
        UFG::Simulation::DestroySimObject(this, v6);
      if ( !this->mSimObjectsToBeDeletedRecursively.mTree.mCount )
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
UFG::qSymbol *__fastcall UFG::Simulation::GenerateUniqueName(
        UFG::Simulation *this,
        UFG::qSymbol *result,
        const char *pRoot)
{
  UFG::qWiseSymbol *increment; // rax
  unsigned int mUID; // ebx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol resulta; // [rsp+38h] [rbp+10h] BYREF

  UFG::qSymbol::create_from_string(result, pRoot);
  while ( 1 )
  {
    increment = UFG::qSymbol::create_increment((UFG::qWiseSymbol *)&resulta, result, 1);
    mUID = increment->mUID;
    result->mUID = increment->mUID;
    if ( !mUID )
      break;
    v7 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, mUID);
    if ( !v7 || v7 == (UFG::qBaseTreeRB *)40 )
    {
      v8 = UFG::qBaseTreeRB::Get(&this->mSimObjectsToBeDeleted.mTree, mUID);
      if ( !v8 || v8 == (UFG::qBaseTreeRB *)40 )
        break;
    }
  }
  return result;
}

// File Line: 280
// RVA: 0x1909D0
UFG::qSymbol *__fastcall UFG::Simulation::GenerateUniqueName(
        UFG::Simulation *this,
        UFG::qSymbol *result,
        UFG::qSymbol *root)
{
  UFG::qWiseSymbol *increment; // rax
  unsigned int mUID; // ebx
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol resulta; // [rsp+38h] [rbp+10h] BYREF

  result->mUID = root->mUID;
  while ( 1 )
  {
    increment = UFG::qSymbol::create_increment((UFG::qWiseSymbol *)&resulta, result, 1);
    mUID = increment->mUID;
    result->mUID = increment->mUID;
    if ( !mUID )
      break;
    v7 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, mUID);
    if ( !v7 || v7 == (UFG::qBaseTreeRB *)40 )
    {
      v8 = UFG::qBaseTreeRB::Get(&this->mSimObjectsToBeDeleted.mTree, mUID);
      if ( !v8 || v8 == (UFG::qBaseTreeRB *)40 )
        break;
    }
  }
  return result;
}

// File Line: 307
// RVA: 0x190BF0
UFG::qBaseNodeRB *__fastcall UFG::Simulation::GetSimObject(UFG::Simulation *this, UFG::qSymbol *name)
{
  unsigned int mUID; // ebx
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *result; // rax
  UFG::qBaseTreeRB *v6; // rax

  mUID = name->mUID;
  if ( !name->mUID )
    return 0i64;
  v4 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, mUID);
  if ( !v4 || (result = &v4[-1].mNULL) == 0i64 )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mSimObjectsToBeDeleted.mTree, mUID);
    if ( !v6 )
      return 0i64;
    result = &v6[-1].mNULL;
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 329
// RVA: 0x190C40
UFG::qBaseNodeRB *__fastcall UFG::Simulation::GetSimObject(UFG::Simulation *this, unsigned int name_uid)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *result; // rax
  UFG::qBaseTreeRB *v6; // rax

  if ( !name_uid )
    return 0i64;
  v4 = UFG::qBaseTreeRB::Get(&this->mSimObjects.mTree, name_uid);
  if ( !v4 || (result = &v4[-1].mNULL) == 0i64 )
  {
    v6 = UFG::qBaseTreeRB::Get(&this->mSimObjectsToBeDeleted.mTree, name_uid);
    if ( !v6 )
      return 0i64;
    result = &v6[-1].mNULL;
    if ( !result )
      return 0i64;
  }
  return result;
}

