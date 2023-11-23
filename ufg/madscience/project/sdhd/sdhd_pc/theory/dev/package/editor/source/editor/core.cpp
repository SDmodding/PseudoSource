// File Line: 121
// RVA: 0x2012E0
void __fastcall UFG::Editor::Core::DAGCacheNode::DAGCacheNode(
        UFG::Editor::Core::DAGCacheNode *this,
        UFG::Editor::DAGPath *path,
        unsigned int uid)
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
  unsigned int v4; // eax
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qSymbol *p_mName; // r14
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v10; // rax
  UFG::Editor::SmartHandleObject *v11; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v12; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rax
  UFG::qOffset64<UFG::qPropertyCollection *> *p_mOwner; // rbx
  UFG::qOffset64<UFG::qPropertyCollection *> *v15; // rbx
  UFG::qSymbol *LayerContainingObject; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qBaseNodeRB *v19; // rax

  UFG::Editor::DAGPath::Clear(path);
  v4 = propSet->mFlags >> 28;
  switch ( v4 )
  {
    case 1u:
      path->mSystemName.mUID = UFG::Editor::DAGTypeArchetype::TYPE_SYMBOL.mUID;
      UFG::qArray<UFG::qSymbol,0>::Insert(&path->mElements, 0, &propSet->mName, "qArray.Insert");
      mPtr = path->mFnObject.mPtr;
      if ( mPtr )
      {
        mPrev = path->mFnObject.mPrev;
        mNext = path->mFnObject.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        path->mFnObject.mPrev = &path->mFnObject;
        path->mFnObject.mNext = &path->mFnObject;
        if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
          mPtr->vfptr->__vecDelDtor(mPtr, 1u);
        path->mFnObject.mPtr = 0i64;
      }
      path->mFnObject.mPtr = 0i64;
      break;
    case 2u:
      if ( (_S19_0 & 1) == 0 )
      {
        _S19_0 |= 1u;
        UFG::qBaseTreeRB::qBaseTreeRB(&cache.mTree);
        atexit(UFG::Editor::Core::GetDAGPath_::_9_::_dynamic_atexit_destructor_for__cache__);
      }
      p_mName = &propSet->mName;
      mUID = propSet->mName.mUID;
      if ( mUID && (v10 = UFG::qBaseTreeRB::Get(&cache.mTree, mUID)) != 0i64 )
      {
        UFG::Editor::DAGPath::operator=(path, (UFG::Editor::DAGPath *)&v10->mNULL);
      }
      else
      {
        path->mSystemName.mUID = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
        while ( 1 )
        {
          UFG::qArray<UFG::qSymbol,0>::Insert(&path->mElements, 0, &propSet->mName, "qArray.Insert");
          v11 = path->mFnObject.mPtr;
          if ( v11 )
          {
            v12 = path->mFnObject.mPrev;
            v13 = path->mFnObject.mNext;
            v12->mNext = v13;
            v13->mPrev = v12;
            path->mFnObject.mPrev = &path->mFnObject;
            path->mFnObject.mNext = &path->mFnObject;
            if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v11->mSmartHandleList.mNode.mNext == &v11->mSmartHandleList )
              v11->vfptr->__vecDelDtor(v11, 1u);
            path->mFnObject.mPtr = 0i64;
          }
          path->mFnObject.mPtr = 0i64;
          p_mOwner = &propSet->mOwner;
          if ( !p_mOwner->mOffset )
            break;
          propSet = (UFG::qPropertySet *)((char *)p_mOwner + p_mOwner->mOffset);
          if ( !propSet )
            break;
          while ( (propSet->mFlags & 2) == 0 )
          {
            v15 = &propSet->mOwner;
            if ( v15->mOffset )
            {
              propSet = (UFG::qPropertySet *)((char *)v15 + v15->mOffset);
              if ( propSet )
                continue;
            }
            goto LABEL_23;
          }
        }
LABEL_23:
        LayerContainingObject = (UFG::qSymbol *)UFG::Scene::FindLayerContainingObject(
                                                  &UFG::Scene::msDefault,
                                                  p_mName,
                                                  0i64);
        if ( !LayerContainingObject )
        {
          UFG::Editor::DAGPath::Clear(path);
          return 0;
        }
        UFG::Editor::DAGPath::InsertStart(path, LayerContainingObject + 6);
        UFG::Editor::DAGPath::GetFnObject(path);
        v18 = UFG::qMalloc(0x78ui64, UFG::gGlobalNewName, 0i64);
        if ( v18 )
          UFG::Editor::Core::DAGCacheNode::DAGCacheNode((UFG::Editor::Core::DAGCacheNode *)v18, path, p_mName->mUID);
        else
          v19 = 0i64;
        UFG::qBaseTreeRB::Add(&cache.mTree, v19);
      }
      break;
    case 3u:
      path->mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
      UFG::Editor::DAGPath::InsertEnd(path, &propSet->mName);
      break;
  }
  return path->mElements.size != 0;
}

// File Line: 180
// RVA: 0x20B8F0
bool __fastcall UFG::Editor::Core::GetDAGPath(UFG::Editor::DAGPath *path, UFG::SceneLayer *layer)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  UFG::Editor::DAGPath::Clear(path);
  if ( !layer )
    return 0;
  path->mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
  UFG::qArray<UFG::qSymbol,0>::Add(&path->mElements, (UFG::qSymbol *)&layer->mNode.mUID, "qArray.Add");
  mPtr = path->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = path->mFnObject.mNext;
    mPrev = path->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    path->mFnObject.mPrev = &path->mFnObject;
    path->mFnObject.mNext = &path->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
    path->mFnObject.mPtr = 0i64;
  }
  path->mFnObject.mPtr = 0i64;
  return path->mElements.size != 0;
}

// File Line: 191
// RVA: 0x20B990
bool __fastcall UFG::Editor::Core::GetDAGPath(UFG::Editor::DAGPath *path, UFG::SimObject *simObj)
{
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rdx

  UFG::Editor::DAGPath::Clear(path);
  if ( !simObj )
    return 0;
  path->mSystemName.mUID = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  UFG::qArray<UFG::qSymbol,0>::Add(&path->mElements, &simObj->m_Name, "qArray.Add");
  mPtr = path->mFnObject.mPtr;
  if ( mPtr )
  {
    mNext = path->mFnObject.mNext;
    mPrev = path->mFnObject.mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    path->mFnObject.mPrev = &path->mFnObject;
    path->mFnObject.mNext = &path->mFnObject;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList )
      mPtr->vfptr->__vecDelDtor(mPtr, 1u);
    path->mFnObject.mPtr = 0i64;
  }
  path->mFnObject.mPtr = 0i64;
  return path->mElements.size != 0;
}

// File Line: 211
// RVA: 0x20FEB0
UFG::qPropertySet *__fastcall UFG::Editor::Core::OpenForEdit(UFG::qPropertySet *propSet)
{
  UFG::Editor::FnObject *mPtr; // rcx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax
  UFG::Editor::FnObject *v5; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  unsigned int v8; // eax
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::FnObject *v10; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  int v13; // edx
  unsigned int size; // r8d
  UFG::Editor::FnModifier *Modifier; // rax
  __int64 mOffset; // rax
  UFG::qPropertySet *v17; // rax
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v19; // rbx
  UFG::qPropertyPath v21; // [rsp+20h] [rbp-21h] BYREF
  UFG::Editor::DAGPath path; // [rsp+38h] [rbp-9h] BYREF
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> **symbol; // [rsp+B0h] [rbp+6Fh] BYREF

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
  memset(&path.mSubElements, 0, 20);
  if ( UFG::Editor::Core::GetDAGPath(&path, propSet) )
  {
    mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( path.mPathType == Half )
      goto LABEL_12;
    if ( !path.mFnObject.mPtr )
    {
      mUID = path.mSystemName.mUID;
      if ( !path.mSystemName.mUID )
        goto LABEL_13;
      v4 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
      if ( !v4 || v4 == (UFG::qBaseTreeRB *)8 )
      {
LABEL_10:
        mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
        if ( path.mFnObject.mPtr )
          goto LABEL_11;
LABEL_12:
        mUID = path.mSystemName.mUID;
LABEL_13:
        v8 = path.mInterfaceName.mUID;
        LODWORD(symbol) = path.mInterfaceName.mUID;
        if ( path.mPathType == Half )
          goto LABEL_32;
        if ( mPtr )
        {
LABEL_23:
          if ( v8 == -1 )
          {
            v13 = 0;
            size = mPtr->mFnModifiers.size;
            if ( size )
            {
              while ( 1 )
              {
                Modifier = mPtr->mFnModifiers.p[v13];
                if ( Modifier->mTypeID == -1570916174 )
                  break;
                if ( ++v13 >= size )
                  goto LABEL_27;
              }
            }
            else
            {
LABEL_27:
              Modifier = 0i64;
            }
LABEL_30:
            if ( Modifier )
            {
              propSet = (UFG::qPropertySet *)Modifier[1].vfptr->__vecDelDtor;
              goto LABEL_41;
            }
            goto LABEL_32;
          }
          Modifier = UFG::Editor::FnObject::GetModifier(mPtr, (UFG::qSymbol *)&symbol);
          if ( Modifier && Modifier->mTypeID == -1570916174 )
            goto LABEL_30;
LABEL_32:
          propSet = 0i64;
          goto LABEL_41;
        }
        if ( !mUID )
          goto LABEL_32;
        v9 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, mUID);
        if ( v9 && v9 != (UFG::qBaseTreeRB *)8 )
        {
          v10 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v9[-1].mCount, &path);
          mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
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
          p_mNode = &v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
          mPrev = v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
          mPrev->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
          path.mFnObject.mPrev = mPrev;
          path.mFnObject.mNext = p_mNode;
          p_mNode->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        }
        mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
        if ( !path.mFnObject.mPtr )
          goto LABEL_32;
        goto LABEL_22;
      }
      v5 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v4[-1].mCount, &path);
      mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
      if ( !path.mFnObject.mPtr )
      {
        if ( !v5 )
          goto LABEL_12;
        path.mFnObject.mTypeId = v5->mTypeId;
        path.mFnObject.mPtr = v5;
        v6 = &v5->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
        v7 = v5->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
        v7->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        path.mFnObject.mPrev = v7;
        path.mFnObject.mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        goto LABEL_10;
      }
    }
LABEL_11:
    ((void (__fastcall *)(UFG::Editor::FnObject *))mPtr->vfptr[4].__vecDelDtor)(mPtr);
    mPtr = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    goto LABEL_12;
  }
  UFG::qPropertyPath::qPropertyPath(&v21);
  UFG::PropertySetManager::GetPath(&v21, propSet, (UFG::qArray<unsigned long,0> *)&UFG::gNullQSymbol);
  if ( v21.mPath.size > 1 )
  {
    while ( 1 )
    {
      mOffset = propSet->mOwner.mOffset;
      if ( !mOffset || !(UFG::qOffset64<UFG::qPropertyCollection *> *)((char *)&propSet->mOwner + mOffset) )
        break;
      propSet = (UFG::qPropertySet *)((char *)propSet + mOffset + 8);
    }
    v17 = UFG::Editor::Core::OpenForEdit(propSet);
    propSet = UFG::PropertySetManager::GetPtrFromPath(&v21, v17);
  }
  if ( v21.mPath.p )
    operator delete[](v21.mPath.p);
  v21.mPath.p = 0i64;
  *(_QWORD *)&v21.mPath.size = 0i64;
LABEL_41:
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
  if ( path.mElements.p )
  {
    v19 = path.mElements.p - 1;
    `eh vector destructor iterator(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v19);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
  return propSet;
}

// File Line: 239
// RVA: 0x20FC20
UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *__fastcall UFG::Editor::Core::OpenForEdit(
        UFG::SceneLayer *layer)
{
  UFG::Editor::SmartHandleObject *mPtr; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::Editor::SmartHandleObject *v5; // rcx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::Editor::FnObject *v8; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v10; // rax
  UFG::qBaseTreeRB *v11; // rax
  UFG::Editor::FnObject *v12; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v14; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rdi
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v17; // rbx
  UFG::Editor::DAGPath path; // [rsp+28h] [rbp-9h] BYREF

  path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mNext;
  path.mFnObject.mPtr = 0i64;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  memset(&path.mSubElements, 0, 20);
  UFG::Editor::DAGPath::Clear(&path);
  if ( layer )
  {
    path.mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
    UFG::qArray<UFG::qSymbol,0>::Add(&path.mElements, (UFG::qSymbol *)&layer->mNode.mUID, "qArray.Add");
    mPtr = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
    {
      mPrev = path.mFnObject.mPrev;
      mNext = path.mFnObject.mNext;
      path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
      mNext->mPrev = mPrev;
      path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList
        && mPtr )
      {
        mPtr->vfptr->__vecDelDtor(mPtr, 1u);
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
  if ( path.mPathType == Half )
    goto LABEL_29;
  if ( v5 )
    goto LABEL_18;
  mUID = path.mSystemName.mUID;
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
    ((void (__fastcall *)(UFG::Editor::SmartHandleObject *))v5->vfptr[4].__vecDelDtor)(v5);
    v5 = path.mFnObject.mPtr;
    goto LABEL_19;
  }
  if ( v8 )
  {
    path.mFnObject.mTypeId = v8->mTypeId;
    path.mFnObject.mPtr = v8;
    p_mNode = &v8->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
    v10 = v8->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mPrev = v10;
    path.mFnObject.mNext = p_mNode;
    p_mNode->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    goto LABEL_17;
  }
LABEL_19:
  mUID = path.mSystemName.mUID;
LABEL_20:
  if ( path.mPathType == Half )
  {
LABEL_29:
    v5 = 0i64;
    goto LABEL_30;
  }
  if ( !v5 && mUID )
  {
    v11 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, mUID);
    if ( !v11 || v11 == (UFG::qBaseTreeRB *)8 )
      goto LABEL_28;
    v12 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v11[-1].mCount, &path);
    v5 = path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr && v12 )
    {
      path.mFnObject.mTypeId = v12->mTypeId;
      path.mFnObject.mPtr = v12;
      v13 = &v12->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
      v14 = v12->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mPrev = v14;
      path.mFnObject.mNext = v13;
      v13->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_28:
      v5 = path.mFnObject.mPtr;
    }
  }
LABEL_30:
  v15 = v5[2].mSmartHandleList.mNode.mPrev;
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
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF

  if ( !path->mElements.size
    || UFG::Editor::DAGPath::GetSystemName(path, &result)->mUID != UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
  {
    return 0i64;
  }
  else
  {
    return UFG::Simulation::GetSimObject(&UFG::gSim, path->mElements.p);
  }
}

// File Line: 314
// RVA: 0x208300
void __fastcall UFG::Editor::Core::DeleteSelection(UFG::Editor::SelectionSet *selectionSet)
{
  unsigned int i; // edi
  UFG::Editor::DAGPath *v3; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::Editor::FnObject *v6; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::Editor::SmartHandleObject *v10; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v11; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  UFG::allocator::free_link *v15; // rax

  for ( i = 0; i < selectionSet->mDAGPaths.size; ++i )
  {
    v3 = &selectionSet->mDAGPaths.p[i];
    if ( v3->mPathType != Half )
    {
      if ( !v3->mFnObject.mPtr )
      {
        mUID = v3->mSystemName.mUID;
        if ( mUID )
        {
          v5 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, mUID);
          if ( v5 )
          {
            if ( v5 != (UFG::qBaseTreeRB *)8 )
            {
              v6 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v5[-1].mCount, v3);
              if ( !v3->mFnObject.mPtr )
              {
                if ( v6 )
                {
                  v3->mFnObject.mTypeId = v6->mTypeId;
                  v3->mFnObject.mPtr = v6;
                  p_mNode = &v6->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
                  mPrev = v6->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                  mPrev->mNext = &v3->mFnObject;
                  v3->mFnObject.mPrev = mPrev;
                  v3->mFnObject.mNext = p_mNode;
                  p_mNode->mPrev = &v3->mFnObject;
                }
              }
            }
          }
        }
      }
      mPtr = v3->mFnObject.mPtr;
      if ( mPtr )
      {
        ((void (__fastcall *)(UFG::Editor::SmartHandleObject *))mPtr->vfptr[3].__vecDelDtor)(mPtr);
        v10 = v3->mFnObject.mPtr;
        if ( v10 )
        {
          v11 = v3->mFnObject.mPrev;
          mNext = v3->mFnObject.mNext;
          v11->mNext = mNext;
          mNext->mPrev = v11;
          v3->mFnObject.mPrev = &v3->mFnObject;
          v3->mFnObject.mNext = &v3->mFnObject;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v10->mSmartHandleList.mNode.mNext == &v10->mSmartHandleList )
            v10->vfptr->__vecDelDtor(v10, 1u);
          v3->mFnObject.mPtr = 0i64;
        }
        v3->mFnObject.mPtr = 0i64;
      }
    }
  }
  selectionSet->mDAGPaths.size = 0;
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
  v14->mUserData0 = (unsigned __int64)selectionSet;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
}

