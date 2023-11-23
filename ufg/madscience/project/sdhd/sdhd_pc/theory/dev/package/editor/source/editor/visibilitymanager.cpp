// File Line: 35
// RVA: 0x146E670
__int64 UFG::Editor::VisibilityManager::_dynamic_initializer_for__mHiddenObjects__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::Editor::VisibilityManager::mHiddenObjects.mTree);
  return atexit((int (__fastcall *)())UFG::Editor::VisibilityManager::_dynamic_atexit_destructor_for__mHiddenObjects__);
}

// File Line: 39
// RVA: 0x146E760
__int64 UFG::Editor::VisibilityManager::_dynamic_initializer_for__mStoredHiddenObjects__()
{
  UFG::qString::qString(&stru_142040B50, "default");
  stru_142040B78.p = 0i64;
  *(_QWORD *)&stru_142040B78.size = 0i64;
  return atexit((int (__fastcall *)())UFG::Editor::VisibilityManager::_dynamic_atexit_destructor_for__mStoredHiddenObjects__);
}

// File Line: 72
// RVA: 0x2074F0
void __fastcall UFG::Editor::VisibilityManager::Deactivate(UFG::Editor::VisibilityManager *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::Event *v2; // rdx
  UFG::allocator::free_link *v3; // rax
  UFG::Editor::VisibilityManager *v4; // rcx
  UFG::qBaseTreeRB *i; // rbp
  __int64 size; // rsi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::Editor::DAGPath *v9; // rbx
  UFG::Editor::SmartHandleObject *v10; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  UFG::allocator::free_link *v15; // rax

  stru_142040B78.size = 0;
  v1 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  v2 = (UFG::Event *)v1;
  if ( v1 )
  {
    v3 = v1 + 1;
    v3->mNext = v3;
    v3[1].mNext = v3;
    v2->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v2->m_EventUID = 609910773;
    v2->m_NamePTR = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  v2->mUserData0 = (unsigned __int64)&UFG::Editor::VisibilityManager::mStoredHiddenObjects;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v2);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::Editor::VisibilityManager::mHiddenObjects);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::Editor::VisibilityManager::mHiddenObjects.mTree, &i->mRoot) )
  {
    if ( UFG::qArray<UFG::Editor::DAGPath,0>::Find(&stru_142040B78, (UFG::Editor::DAGPath *)&i->mNULL) <= -1 )
    {
      size = stru_142040B78.size;
      v7 = stru_142040B78.size + 1;
      if ( stru_142040B78.size + 1 > stru_142040B78.capacity )
      {
        if ( stru_142040B78.capacity )
          v8 = 2 * stru_142040B78.capacity;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 - v7 > 0x10000 )
          v8 = stru_142040B78.size + 65537;
        UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&stru_142040B78, v8, "qArray.Add");
      }
      stru_142040B78.size = v7;
      v9 = &stru_142040B78.p[size];
      if ( &i->mNULL != (UFG::qBaseNodeRB *)v9 )
      {
        UFG::Editor::DAGPath::Clear(&stru_142040B78.p[size]);
        if ( v9->mPathType == Default )
        {
          v10 = (UFG::Editor::SmartHandleObject *)i->mNULL.mChild[1];
          if ( !v9->mFnObject.mPtr )
          {
            if ( v10 )
            {
              v9->mFnObject.mTypeId = v10->mTypeId;
              v9->mFnObject.mPtr = v10;
              p_mNode = &v10->mSmartHandleList.mNode;
              mPrev = p_mNode->mPrev;
              mPrev->mNext = &v9->mFnObject;
              v9->mFnObject.mPrev = mPrev;
              v9->mFnObject.mNext = p_mNode;
              p_mNode->mPrev = &v9->mFnObject;
            }
          }
        }
        v9->mSystemName.mUID = i->mCount;
        UFG::qArray<UFG::qSymbol,0>::Clone((UFG::qArray<UFG::qSymbol,0> *)&i[1], &v9->mElements);
        v9->mInterfaceName.mUID = (unsigned int)i[1].mRoot.mChild[1];
        UFG::qArray<UFG::qString,0>::Clone((UFG::qArray<UFG::qString,0> *)&i[1].mRoot.mUID, &v9->mSubElements);
      }
      v13 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
      v14 = (UFG::Event *)v13;
      if ( v13 )
      {
        v15 = v13 + 1;
        v15->mNext = v15;
        v15[1].mNext = v15;
        v14->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v14->m_EventUID = 609910773;
        v14->m_NamePTR = 0i64;
      }
      else
      {
        v14 = 0i64;
      }
      v14->mUserData0 = (unsigned __int64)&UFG::Editor::VisibilityManager::mStoredHiddenObjects;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
    }
  }
  UFG::Editor::VisibilityManager::UnhideAll(v4);
}

// File Line: 136
// RVA: 0x213CF0
void __fastcall UFG::Editor::VisibilityManager::Unhide(UFG::Editor::DAGPath *p)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  unsigned int *p_mStringHash32; // rbx
  unsigned int Hash; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::Editor::DAGPath *v8; // rbx
  UFG::qSymbol *SystemName; // rax
  unsigned int mUID; // ebx
  UFG::Editor::DAGPathType::Enum mPathType; // ecx
  UFG::Editor::SmartHandleObject *v12; // rax
  UFG::qBaseTreeRB *v13; // rax
  UFG::Editor::FnObject *v14; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimObject *v17; // rbx
  UFG::qSymbol *v18; // rax
  unsigned int v19; // ebx
  bool v20; // al
  UFG::SimObject *v21; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v23; // rsi
  unsigned int v24; // edi
  UFG::qSymbol *v25; // rbx
  UFG::Editor::SmartHandleObject *v26; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v27; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  unsigned int *v29; // rbx
  UFG::qSymbol *v30; // rbx
  unsigned int *v31; // rbx
  UFG::qSymbol *v32; // rbx
  UFG::Editor::SmartHandleObject *v33; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v34; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v35; // rax
  UFG::Editor::DAGPath path; // [rsp+30h] [rbp-89h] BYREF
  UFG::Editor::DAGPath pa; // [rsp+90h] [rbp-29h] BYREF
  __int64 v38; // [rsp+F0h] [rbp+37h]
  UFG::Editor::DAGPath *result; // [rsp+120h] [rbp+67h] BYREF
  UFG::Editor::DAGPath *p_pa; // [rsp+128h] [rbp+6Fh]

  v38 = -2i64;
  result = &path;
  path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
  path.mFnObject.mPtr = 0i64;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  memset(&path.mSubElements, 0, 20);
  if ( p != &path )
  {
    UFG::Editor::DAGPath::Clear(&path);
    if ( path.mPathType == Default )
    {
      mPtr = p->mFnObject.mPtr;
      if ( !path.mFnObject.mPtr )
      {
        if ( mPtr )
        {
          path.mFnObject.mTypeId = mPtr->mTypeId;
          path.mFnObject.mPtr = mPtr;
          p_mNode = &mPtr->mSmartHandleList.mNode;
          mPrev = p_mNode->mPrev;
          mPrev->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
          path.mFnObject.mPrev = mPrev;
          path.mFnObject.mNext = p_mNode;
          p_mNode->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        }
      }
    }
    path.mSystemName.mUID = p->mSystemName.mUID;
    UFG::qArray<UFG::qSymbol,0>::Clone(&p->mElements, &path.mElements);
    path.mInterfaceName.mUID = p->mInterfaceName.mUID;
    UFG::qArray<UFG::qString,0>::Clone(&p->mSubElements, &path.mSubElements);
  }
  if ( path.mSubElements.p )
  {
    p_mStringHash32 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  Hash = UFG::Editor::DAGPath::GetHash(&path);
  if ( Hash )
  {
    v7 = UFG::qBaseTreeRB::Get(&UFG::Editor::VisibilityManager::mHiddenObjects.mTree, Hash);
    v8 = (UFG::Editor::DAGPath *)v7;
    if ( v7 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::Editor::VisibilityManager::mHiddenObjects,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v7);
      result = v8;
      UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)&v8->mSystemName);
      operator delete[](v8);
      --UFG::Editor::VisibilityManager::mNumHidden;
    }
  }
  SystemName = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  mUID = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
  if ( SystemName->mUID == UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID )
  {
    if ( !path.mElements.size )
      goto LABEL_59;
    if ( UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != mUID )
    {
      if ( UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
      {
        v17 = 0i64;
        goto LABEL_32;
      }
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, path.mElements.p);
LABEL_31:
      v17 = (UFG::SimObject *)SimObject;
LABEL_32:
      if ( v17 )
      {
        p_pa = &pa;
        pa.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
        pa.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
        pa.mFnObject.mPtr = 0i64;
        pa.mFnObject.mTypeId = -1998658210;
        pa.mSystemName.mUID = -1;
        pa.mElements.p = 0i64;
        *(_QWORD *)&pa.mElements.size = 0i64;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&pa.mElements, 4u, "qArray.Reallocate(Constructor)");
        pa.mInterfaceName.mUID = -1;
        memset(&pa.mSubElements, 0, 20);
        if ( UFG::Editor::Core::GetDAGPath(&pa, v17) )
          UFG::Editor::VisibilityManager::Unhide(&pa);
        UFG::Editor::DAGPath::~DAGPath(&pa);
      }
      goto LABEL_59;
    }
    mPathType = path.mPathType;
    if ( path.mPathType == Half )
      goto LABEL_59;
    v12 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
    {
LABEL_25:
      if ( mPathType == Half )
        v12 = 0i64;
      SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (unsigned int)v12[2].mSmartHandleList.mNode.mNext);
      goto LABEL_31;
    }
    if ( !path.mSystemName.mUID )
      goto LABEL_59;
    v13 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
    if ( v13 && v13 != (UFG::qBaseTreeRB *)8 )
    {
      v14 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v13[-1].mCount, &path);
      v12 = path.mFnObject.mPtr;
      if ( path.mFnObject.mPtr )
      {
LABEL_24:
        mPathType = path.mPathType;
        goto LABEL_25;
      }
      if ( !v14 )
        goto LABEL_59;
      path.mFnObject.mTypeId = v14->mTypeId;
      path.mFnObject.mPtr = v14;
      v15 = v14->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mPrev = v15;
      path.mFnObject.mNext = &v14->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
      v14->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    }
    v12 = path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr )
      goto LABEL_59;
    goto LABEL_24;
  }
  v18 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  v19 = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  if ( v18->mUID == UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
  {
    v20 = !path.mElements.size || UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != v19;
    v21 = v20 ? 0i64 : (UFG::SimObject *)UFG::Simulation::GetSimObject(&UFG::gSim, path.mElements.p);
    UFG::SimObject::Restore(v21);
    ComponentOfType = UFG::SimObject::GetComponentOfType(v21, UFG::PrefabComponent::_TypeUID);
    v23 = ComponentOfType;
    if ( ComponentOfType )
    {
      v24 = 0;
      if ( ComponentOfType[1].m_TypeUID )
      {
        result = &pa;
        do
        {
          v25 = *(UFG::qSymbol **)(*(_QWORD *)(*(_QWORD *)&v23[1].m_Flags + 8i64 * v24) + 40i64);
          pa.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
          pa.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
          pa.mFnObject.mPtr = 0i64;
          pa.mFnObject.mTypeId = -1998658210;
          pa.mSystemName.mUID = -1;
          pa.mElements.p = 0i64;
          *(_QWORD *)&pa.mElements.size = 0i64;
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&pa.mElements, 4u, "qArray.Reallocate(Constructor)");
          pa.mInterfaceName.mUID = -1;
          memset(&pa.mSubElements, 0, 20);
          UFG::Editor::DAGPath::Clear(&pa);
          if ( v25 )
          {
            pa.mSystemName.mUID = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
            UFG::qArray<UFG::qSymbol,0>::Add(&pa.mElements, v25 + 18, "qArray.Add");
            v26 = pa.mFnObject.mPtr;
            if ( pa.mFnObject.mPtr )
            {
              v27 = pa.mFnObject.mPrev;
              mNext = pa.mFnObject.mNext;
              pa.mFnObject.mPrev->mNext = pa.mFnObject.mNext;
              mNext->mPrev = v27;
              pa.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
              pa.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&pa;
              if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v26->mSmartHandleList.mNode.mNext == &v26->mSmartHandleList
                && v26 )
              {
                v26->vfptr->__vecDelDtor(v26, 1u);
              }
              pa.mFnObject.mPtr = 0i64;
            }
            pa.mFnObject.mPtr = 0i64;
          }
          UFG::Editor::VisibilityManager::Unhide(&pa);
          if ( pa.mSubElements.p )
          {
            v29 = &pa.mSubElements.p[-1].mStringHash32;
            `eh vector destructor iterator(
              pa.mSubElements.p,
              0x28ui64,
              pa.mSubElements.p[-1].mStringHash32,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            operator delete[](v29);
          }
          pa.mSubElements.p = 0i64;
          *(_QWORD *)&pa.mSubElements.size = 0i64;
          if ( pa.mElements.p )
          {
            v30 = pa.mElements.p - 1;
            `eh vector destructor iterator(
              pa.mElements.p,
              4ui64,
              pa.mElements.p[-1].mUID,
              (void (__fastcall *)(void *))_);
            operator delete[](v30);
          }
          pa.mElements.p = 0i64;
          *(_QWORD *)&pa.mElements.size = 0i64;
          UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&pa.mFnObject);
          ++v24;
        }
        while ( v24 < v23[1].m_TypeUID );
      }
    }
  }
LABEL_59:
  if ( path.mSubElements.p )
  {
    v31 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v31);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v32 = path.mElements.p - 1;
    `eh vector destructor iterator(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v32);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  result = &path;
  v33 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
    v34 = path.mFnObject.mPrev;
    v35 = path.mFnObject.mNext;
    path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
    v35->mPrev = v34;
    path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v33->mSmartHandleList.mNode.mNext == &v33->mSmartHandleList
      && v33 )
    {
      v33->vfptr->__vecDelDtor(v33, 1u);
    }
    path.mFnObject.mPtr = 0i64;
  }
  path.mFnObject.mPtr = 0i64;
  UFG::Editor::SmartHandle::~SmartHandle(&path.mFnObject);
}

// File Line: 190
// RVA: 0x214350
void __fastcall UFG::Editor::VisibilityManager::UnhideAll(UFG::Editor::VisibilityManager *this)
{
  UFG::qBaseTreeRB *i; // r14
  __int64 size; // rsi
  unsigned int v3; // ebx
  unsigned int v4; // edx
  UFG::Editor::DAGPath *v5; // rbx
  UFG::Editor::SmartHandleObject *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::Event *v10; // rdx
  UFG::allocator::free_link *v11; // rax
  unsigned int j; // ebx
  UFG::Editor::DAGPathType::Enum *p_mPathType; // rbx
  __int64 *v14; // rcx
  __int64 **v15; // rax
  __int64 *v16; // [rsp+30h] [rbp-50h] BYREF
  __int64 **v17; // [rsp+38h] [rbp-48h]
  UFG::qString v18; // [rsp+40h] [rbp-40h] BYREF
  UFG::qArray<UFG::Editor::DAGPath,0> v19; // [rsp+68h] [rbp-18h] BYREF

  v16 = (__int64 *)&v16;
  v17 = &v16;
  UFG::qString::qString(&v18, "default");
  v19.p = 0i64;
  *(_QWORD *)&v19.size = 0i64;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::Editor::VisibilityManager::mHiddenObjects);
        i;
        i = UFG::qBaseTreeRB::GetNext(&UFG::Editor::VisibilityManager::mHiddenObjects.mTree, &i->mRoot) )
  {
    if ( (int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&v19, (UFG::Editor::DAGPath *)&i->mNULL) <= -1 )
    {
      size = v19.size;
      v3 = v19.size + 1;
      if ( v19.size + 1 > v19.capacity )
      {
        if ( v19.capacity )
          v4 = 2 * v19.capacity;
        else
          v4 = 1;
        for ( ; v4 < v3; v4 *= 2 )
          ;
        if ( v4 - v3 > 0x10000 )
          v4 = v19.size + 65537;
        UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&v19, v4, "qArray.Add");
      }
      v19.size = v3;
      v5 = &v19.p[size];
      if ( &i->mNULL != (UFG::qBaseNodeRB *)v5 )
      {
        UFG::Editor::DAGPath::Clear(&v19.p[size]);
        if ( v5->mPathType == Default )
        {
          v6 = (UFG::Editor::SmartHandleObject *)i->mNULL.mChild[1];
          if ( !v5->mFnObject.mPtr )
          {
            if ( v6 )
            {
              v5->mFnObject.mTypeId = v6->mTypeId;
              v5->mFnObject.mPtr = v6;
              p_mNode = &v6->mSmartHandleList.mNode;
              mPrev = p_mNode->mPrev;
              mPrev->mNext = &v5->mFnObject;
              v5->mFnObject.mPrev = mPrev;
              v5->mFnObject.mNext = p_mNode;
              p_mNode->mPrev = &v5->mFnObject;
            }
          }
        }
        v5->mSystemName.mUID = i->mCount;
        UFG::qArray<UFG::qSymbol,0>::Clone((UFG::qArray<UFG::qSymbol,0> *)&i[1], &v5->mElements);
        v5->mInterfaceName.mUID = (unsigned int)i[1].mRoot.mChild[1];
        UFG::qArray<UFG::qString,0>::Clone((UFG::qArray<UFG::qString,0> *)&i[1].mRoot.mUID, &v5->mSubElements);
      }
      v9 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
      v10 = (UFG::Event *)v9;
      if ( v9 )
      {
        v11 = v9 + 1;
        v11->mNext = v11;
        v11[1].mNext = v11;
        v10->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v10->m_EventUID = 609910773;
        v10->m_NamePTR = 0i64;
      }
      else
      {
        v10 = 0i64;
      }
      v10->mUserData0 = (unsigned __int64)&v16;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v10);
    }
  }
  for ( j = 0; j < v19.size; ++j )
    UFG::Editor::VisibilityManager::Unhide(&v19.p[j]);
  if ( v19.p )
  {
    p_mPathType = &v19.p[-1].mPathType;
    `eh vector destructor iterator(
      v19.p,
      0x58ui64,
      v19.p[-1].mPathType,
      (void (__fastcall *)(void *))UFG::Editor::DAGPath::~DAGPath);
    operator delete[](p_mPathType);
  }
  v19.p = 0i64;
  *(_QWORD *)&v19.size = 0i64;
  UFG::qString::~qString(&v18);
  v14 = v16;
  v15 = v17;
  v16[1] = (__int64)v17;
  *v15 = v14;
}

