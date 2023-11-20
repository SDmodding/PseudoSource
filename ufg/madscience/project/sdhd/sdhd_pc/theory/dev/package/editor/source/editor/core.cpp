// File Line: 121
// RVA: 0x2012E0
void __fastcall UFG::Editor::Core::DAGCacheNode::DAGCacheNode(UFG::Editor::Core::DAGCacheNode *this, UFG::Editor::DAGPath *path, unsigned int uid)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  UFG::Editor::DAGPath::DAGPath(&this->mPath, path);
}

// File Line: 126
// RVA: 0x20BA30
bool __fastcall UFG::Editor::Core::GetDAGPath(UFG::Editor::DAGPath *path, UFG::qPropertySet *propSet)
{
  UFG::qPropertySet *v2; // rbx
  UFG::Editor::DAGPath *v3; // rdi
  unsigned int v4; // eax
  UFG::Editor::SmartHandleObject *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  UFG::qSymbol *v8; // r14
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  UFG::Editor::SmartHandleObject *v11; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v12; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rax
  UFG::qOffset64<UFG::qPropertyCollection *> *v14; // rbx
  UFG::qOffset64<UFG::qPropertyCollection *> *v15; // rbx
  UFG::qSymbol *v16; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qBaseNodeRB *v19; // rax

  v2 = propSet;
  v3 = path;
  UFG::Editor::DAGPath::Clear(path);
  v4 = v2->mFlags >> 28;
  switch ( v4 )
  {
    case 1u:
      v3->mSystemName.mUID = UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID;
      UFG::qArray<UFG::qSymbol,0>::Insert(&v3->mElements, 0, &v2->mName, "qArray.Insert");
      v5 = v3->mFnObject.mPtr;
      if ( v5 )
      {
        v6 = v3->mFnObject.mPrev;
        v7 = v3->mFnObject.mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v3->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
        v3->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
        if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v5->mSmartHandleList.mNode.mNext == &v5->mSmartHandleList )
        {
          if ( v5 )
            v5->vfptr->__vecDelDtor(v5, 1u);
        }
        v3->mFnObject.mPtr = 0i64;
      }
      v3->mFnObject.mPtr = 0i64;
      break;
    case 2u:
      if ( !(_S19_0 & 1) )
      {
        _S19_0 |= 1u;
        UFG::qBaseTreeRB::qBaseTreeRB(&cache.mTree);
        atexit(UFG::Editor::Core::GetDAGPath_::_9_::_dynamic_atexit_destructor_for__cache__);
      }
      v8 = &v2->mName;
      v9 = v2->mName.mUID;
      if ( v9 && (v10 = UFG::qBaseTreeRB::Get(&cache.mTree, v9)) != 0i64 )
      {
        UFG::Editor::DAGPath::operator=(v3, (UFG::Editor::DAGPath *)&v10->mNULL);
      }
      else
      {
        v3->mSystemName.mUID = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
        while ( 1 )
        {
          UFG::qArray<UFG::qSymbol,0>::Insert(&v3->mElements, 0, &v2->mName, "qArray.Insert");
          v11 = v3->mFnObject.mPtr;
          if ( v11 )
          {
            v12 = v3->mFnObject.mPrev;
            v13 = v3->mFnObject.mNext;
            v12->mNext = v13;
            v13->mPrev = v12;
            v3->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
            v3->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
            if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v11->mSmartHandleList.mNode.mNext == &v11->mSmartHandleList
              && v11 )
            {
              v11->vfptr->__vecDelDtor(v11, 1u);
            }
            v3->mFnObject.mPtr = 0i64;
          }
          v3->mFnObject.mPtr = 0i64;
          v14 = &v2->mOwner;
          if ( !v14->mOffset )
            break;
          v2 = (UFG::qPropertySet *)((char *)v14 + v14->mOffset);
          if ( !v2 )
            break;
          while ( !((v2->mFlags >> 1) & 1) )
          {
            v15 = &v2->mOwner;
            if ( v15->mOffset )
            {
              v2 = (UFG::qPropertySet *)((char *)v15 + v15->mOffset);
              if ( v2 )
                continue;
            }
            goto LABEL_25;
          }
        }
LABEL_25:
        v16 = (UFG::qSymbol *)UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, v8, 0i64);
        if ( !v16 )
        {
          UFG::Editor::DAGPath::Clear(v3);
          return 0;
        }
        UFG::Editor::DAGPath::InsertStart(v3, v16 + 6);
        UFG::Editor::DAGPath::GetFnObject(v3);
        v18 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
        if ( v18 )
          UFG::Editor::Core::DAGCacheNode::DAGCacheNode((UFG::Editor::Core::DAGCacheNode *)v18, v3, v8->mUID);
        else
          v19 = 0i64;
        UFG::qBaseTreeRB::Add(&cache.mTree, v19);
      }
      break;
    case 3u:
      v3->mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
      UFG::Editor::DAGPath::InsertEnd(v3, &v2->mName);
      break;
  }
  return v3->mElements.size != 0;
}

// File Line: 180
// RVA: 0x20B8F0
bool __fastcall UFG::Editor::Core::GetDAGPath(UFG::Editor::DAGPath *path, UFG::SceneLayer *layer)
{
  UFG::SceneLayer *v2; // rdi
  UFG::Editor::DAGPath *v3; // rbx
  UFG::Editor::SmartHandleObject *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rdx

  v2 = layer;
  v3 = path;
  UFG::Editor::DAGPath::Clear(path);
  if ( !v2 )
    return 0;
  v3->mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
  UFG::qArray<UFG::qSymbol,0>::Add(&v3->mElements, (UFG::qSymbol *)&v2->mNode.mUID, "qArray.Add");
  v5 = v3->mFnObject.mPtr;
  if ( v5 )
  {
    v6 = v3->mFnObject.mNext;
    v7 = v3->mFnObject.mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    v3->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
    v3->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v5->mSmartHandleList.mNode.mNext == &v5->mSmartHandleList )
    {
      if ( v5 )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
    v3->mFnObject.mPtr = 0i64;
  }
  v3->mFnObject.mPtr = 0i64;
  return v3->mElements.size != 0;
}

// File Line: 191
// RVA: 0x20B990
bool __fastcall UFG::Editor::Core::GetDAGPath(UFG::Editor::DAGPath *path, UFG::SimObject *simObj)
{
  UFG::SimObject *v2; // rdi
  UFG::Editor::DAGPath *v3; // rbx
  UFG::Editor::SmartHandleObject *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rdx

  v2 = simObj;
  v3 = path;
  UFG::Editor::DAGPath::Clear(path);
  if ( !v2 )
    return 0;
  v3->mSystemName.mUID = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  UFG::qArray<UFG::qSymbol,0>::Add(&v3->mElements, &v2->m_Name, "qArray.Add");
  v5 = v3->mFnObject.mPtr;
  if ( v5 )
  {
    v6 = v3->mFnObject.mNext;
    v7 = v3->mFnObject.mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    v3->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
    v3->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v3->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v5->mSmartHandleList.mNode.mNext == &v5->mSmartHandleList )
    {
      if ( v5 )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
    v3->mFnObject.mPtr = 0i64;
  }
  v3->mFnObject.mPtr = 0i64;
  return v3->mElements.size != 0;
}

// File Line: 211
// RVA: 0x20FEB0
UFG::qPropertySet *__fastcall UFG::Editor::Core::OpenForEdit(UFG::qPropertySet *propSet)
{
  UFG::qPropertySet *v1; // rdi
  UFG::Editor::FnObject *v2; // rcx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::Editor::SmartHandleObject *v5; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  unsigned int v8; // eax
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::SmartHandleObject *v10; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v11; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v12; // rax
  int v13; // edx
  unsigned int v14; // er8
  UFG::Editor::FnModifier *v15; // rax
  __int64 v16; // rax
  UFG::qPropertySet *v17; // rax
  unsigned int *v18; // rbx
  UFG::qSymbol *v19; // rbx
  UFG::qPropertyPath v21; // [rsp+20h] [rbp-21h]
  UFG::Editor::DAGPath path; // [rsp+38h] [rbp-9h]
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> **symbol; // [rsp+B0h] [rbp+6Fh]

  v1 = propSet;
  symbol = &path.mFnObject.mNext;
  path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mPtr = 0i64;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  path.mPathType = 0;
  if ( UFG::Editor::Core::GetDAGPath(&path, v1) == 1 )
  {
    v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( path.mPathType == 1 )
      goto LABEL_12;
    if ( !path.mFnObject.mPtr )
    {
      v3 = path.mSystemName.mUID;
      if ( !path.mSystemName.mUID )
        goto LABEL_13;
      v4 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
      if ( !v4 || v4 == (UFG::qBaseTreeRB *)8 )
      {
LABEL_10:
        v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
        if ( path.mFnObject.mPtr )
          goto LABEL_11;
LABEL_12:
        v3 = path.mSystemName.mUID;
LABEL_13:
        v8 = path.mInterfaceName.mUID;
        LODWORD(symbol) = path.mInterfaceName.mUID;
        if ( path.mPathType == 1 )
          goto LABEL_32;
        if ( v2 )
        {
LABEL_23:
          if ( v8 == -1 )
          {
            v13 = 0;
            v14 = v2->mFnModifiers.size;
            if ( v14 )
            {
              while ( 1 )
              {
                v15 = v2->mFnModifiers.p[v13];
                if ( v15->mTypeID == -1570916174 )
                  break;
                if ( ++v13 >= v14 )
                  goto LABEL_27;
              }
            }
            else
            {
LABEL_27:
              v15 = 0i64;
            }
LABEL_30:
            if ( v15 )
            {
              v1 = (UFG::qPropertySet *)v15[1].vfptr->__vecDelDtor;
              goto LABEL_41;
            }
            goto LABEL_32;
          }
          v15 = UFG::Editor::FnObject::GetModifier(v2, (UFG::qSymbol *)&symbol);
          if ( v15 && v15->mTypeID == -1570916174 )
            goto LABEL_30;
LABEL_32:
          v1 = 0i64;
          goto LABEL_41;
        }
        if ( !v3 )
          goto LABEL_32;
        v9 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v3);
        if ( v9 && v9 != (UFG::qBaseTreeRB *)8 )
        {
          v10 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v9[-1].mCount, &path);
          v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
          if ( path.mFnObject.mPtr )
          {
LABEL_22:
            v8 = path.mInterfaceName.mUID;
            goto LABEL_23;
          }
          if ( !v10 )
            goto LABEL_32;
          path.mFnObject.mTypeId = v10->mTypeId;
          path.mFnObject.mPtr = v10;
          v11 = &v10->mSmartHandleList.mNode;
          v12 = v10->mSmartHandleList.mNode.mPrev;
          v12->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
          path.mFnObject.mPrev = v12;
          path.mFnObject.mNext = v11;
          v11->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        }
        v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
        if ( !path.mFnObject.mPtr )
          goto LABEL_32;
        goto LABEL_22;
      }
      v5 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v4[-1].mCount, &path);
      v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
      if ( !path.mFnObject.mPtr )
      {
        if ( !v5 )
          goto LABEL_12;
        path.mFnObject.mTypeId = v5->mTypeId;
        path.mFnObject.mPtr = v5;
        v6 = &v5->mSmartHandleList.mNode;
        v7 = v5->mSmartHandleList.mNode.mPrev;
        v7->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        path.mFnObject.mPrev = v7;
        path.mFnObject.mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        goto LABEL_10;
      }
    }
LABEL_11:
    ((void (*)(void))v2->vfptr[4].__vecDelDtor)();
    v2 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    goto LABEL_12;
  }
  UFG::qPropertyPath::qPropertyPath(&v21);
  UFG::PropertySetManager::GetPath(&v21, v1, &UFG::gNullQSymbol);
  if ( v21.mPath.size > 1 )
  {
    while ( 1 )
    {
      v16 = v1->mOwner.mOffset;
      if ( !v16 || !(UFG::qOffset64<UFG::qPropertyCollection *> *)((char *)&v1->mOwner + v16) )
        break;
      v1 = (UFG::qPropertySet *)((char *)v1 + v16 + 8);
    }
    v17 = UFG::Editor::Core::OpenForEdit(v1);
    v1 = UFG::PropertySetManager::GetPtrFromPath(&v21, v17);
  }
  if ( v21.mPath.p )
    operator delete[](v21.mPath.p);
  v21.mPath.p = 0i64;
  *(_QWORD *)&v21.mPath.size = 0i64;
LABEL_41:
  if ( path.mSubElements.p )
  {
    v18 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v18);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v19 = path.mElements.p - 1;
    `eh vector destructor iterator(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v19);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
  return v1;
}

// File Line: 239
// RVA: 0x20FC20
UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *__fastcall UFG::Editor::Core::OpenForEdit(UFG::SceneLayer *layer)
{
  UFG::SceneLayer *v1; // rbx
  UFG::Editor::SmartHandleObject *v2; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v3; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rax
  UFG::Editor::SmartHandleObject *v5; // rcx
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::Editor::SmartHandleObject *v8; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v9; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v10; // rax
  UFG::qBaseTreeRB *v11; // rax
  UFG::Editor::SmartHandleObject *v12; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v14; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rdi
  unsigned int *v16; // rbx
  UFG::qSymbol *v17; // rbx
  UFG::Editor::DAGPath path; // [rsp+28h] [rbp-9h]
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> **retaddr; // [rsp+98h] [rbp+67h]

  v1 = layer;
  retaddr = &path.mFnObject.mNext;
  path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mPtr = 0i64;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  path.mPathType = 0;
  UFG::Editor::DAGPath::Clear(&path);
  if ( v1 )
  {
    path.mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
    UFG::qArray<UFG::qSymbol,0>::Add(&path.mElements, (UFG::qSymbol *)&v1->mNode.mUID, "qArray.Add");
    v2 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
    {
      v3 = path.mFnObject.mPrev;
      v4 = path.mFnObject.mNext;
      path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
      v4->mPrev = v3;
      path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v2->mSmartHandleList.mNode.mNext == &v2->mSmartHandleList
        && v2 )
      {
        v2->vfptr->__vecDelDtor(v2, 1u);
      }
      path.mFnObject.mPtr = 0i64;
    }
    v5 = 0i64;
    path.mFnObject.mPtr = 0i64;
  }
  else
  {
    v5 = path.mFnObject.mPtr;
  }
  if ( path.mPathType == 1 )
    goto LABEL_29;
  if ( v5 )
    goto LABEL_18;
  v6 = path.mSystemName.mUID;
  if ( !path.mSystemName.mUID )
    goto LABEL_20;
  v7 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
  if ( !v7 || v7 == (UFG::qBaseTreeRB *)8 )
  {
LABEL_17:
    v5 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
      goto LABEL_18;
    goto LABEL_19;
  }
  v8 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v7[-1].mCount, &path);
  v5 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
LABEL_18:
    ((void (*)(void))v5->vfptr[4].__vecDelDtor)();
    v5 = path.mFnObject.mPtr;
    goto LABEL_19;
  }
  if ( v8 )
  {
    path.mFnObject.mTypeId = v8->mTypeId;
    path.mFnObject.mPtr = v8;
    v9 = &v8->mSmartHandleList.mNode;
    v10 = v8->mSmartHandleList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mPrev = v10;
    path.mFnObject.mNext = v9;
    v9->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    goto LABEL_17;
  }
LABEL_19:
  v6 = path.mSystemName.mUID;
LABEL_20:
  if ( path.mPathType == 1 )
  {
LABEL_29:
    v5 = 0i64;
    goto LABEL_30;
  }
  if ( !v5 && v6 )
  {
    v11 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v6);
    if ( !v11 || v11 == (UFG::qBaseTreeRB *)8 )
      goto LABEL_28;
    v12 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v11[-1].mCount, &path);
    v5 = path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr && v12 )
    {
      path.mFnObject.mTypeId = v12->mTypeId;
      path.mFnObject.mPtr = v12;
      v13 = &v12->mSmartHandleList.mNode;
      v14 = v12->mSmartHandleList.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mPrev = v14;
      path.mFnObject.mNext = v13;
      v13->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_28:
      v5 = path.mFnObject.mPtr;
      goto LABEL_30;
    }
  }
LABEL_30:
  v15 = v5[2].mSmartHandleList.mNode.mPrev;
  if ( path.mSubElements.p )
  {
    v16 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v16);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v17 = path.mElements.p - 1;
    `eh vector destructor iterator(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v17);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
  return v15;
}

// File Line: 286
// RVA: 0x205810
UFG::qBaseNodeRB *__fastcall UFG::Editor::Core::CastToSimObject(UFG::Editor::DAGPath *path)
{
  UFG::Editor::DAGPath *v1; // rdi
  bool v2; // al
  UFG::qBaseNodeRB *v3; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v1 = path;
  v2 = !path->mElements.size
    || UFG::Editor::DAGPath::GetSystemName(path, &result)->mUID != UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  if ( v2 )
    v3 = 0i64;
  else
    v3 = UFG::Simulation::GetSimObject(&UFG::gSim, v1->mElements.p);
  return v3;
}

// File Line: 314
// RVA: 0x208300
void __fastcall UFG::Editor::Core::DeleteSelection(UFG::Editor::SelectionSet *selectionSet)
{
  UFG::Editor::SelectionSet *v1; // rsi
  unsigned int v2; // edi
  signed __int64 v3; // rbx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::Editor::SmartHandleObject *v6; // rax
  _QWORD *v7; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rdx
  _QWORD *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  UFG::allocator::free_link *v15; // rax

  v1 = selectionSet;
  v2 = 0;
  if ( selectionSet->mDAGPaths.size )
  {
    do
    {
      v3 = (signed __int64)&v1->mDAGPaths.p[v2];
      if ( *(_DWORD *)(v3 + 80) != 1 )
      {
        if ( !*(_QWORD *)(v3 + 16) )
        {
          v4 = *(_DWORD *)(v3 + 32);
          if ( v4 )
          {
            v5 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v4);
            if ( v5 )
            {
              if ( v5 != (UFG::qBaseTreeRB *)8 )
              {
                v6 = UFG::Editor::DAGType::AquireFnObject(
                       (UFG::Editor::DAGType *)&v5[-1].mCount,
                       (UFG::Editor::DAGPath *)v3);
                if ( !*(_QWORD *)(v3 + 16) )
                {
                  if ( v6 )
                  {
                    *(_DWORD *)(v3 + 24) = v6->mTypeId;
                    *(_QWORD *)(v3 + 16) = v6;
                    v7 = &v6->mSmartHandleList.mNode.mPrev;
                    v8 = v6->mSmartHandleList.mNode.mPrev;
                    v8->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v3;
                    *(_QWORD *)v3 = v8;
                    *(_QWORD *)(v3 + 8) = v7;
                    *v7 = v3;
                  }
                }
              }
            }
          }
        }
        v9 = *(_QWORD *)(v3 + 16);
        if ( v9 )
        {
          (*(void (__cdecl **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
          v10 = *(_QWORD *)(v3 + 16);
          if ( v10 )
          {
            v11 = *(_QWORD *)v3;
            v12 = *(_QWORD **)(v3 + 8);
            *(_QWORD *)(v11 + 8) = v12;
            *v12 = v11;
            *(_QWORD *)v3 = v3;
            *(_QWORD *)(v3 + 8) = v3;
            if ( *(_QWORD *)(v10 + 48) == v10 + 40 && v10 )
              (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
            *(_QWORD *)(v3 + 16) = 0i64;
          }
          *(_QWORD *)(v3 + 16) = 0i64;
        }
      }
      ++v2;
    }
    while ( v2 < v1->mDAGPaths.size );
  }
  v1->mDAGPaths.size = 0;
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
  v14->mUserData0 = (unsigned __int64)v1;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
}

