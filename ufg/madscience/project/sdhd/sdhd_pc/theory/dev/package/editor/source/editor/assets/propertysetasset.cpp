// File Line: 24
// RVA: 0x146DA80
__int64 UFG::Editor::_dynamic_initializer_for__gPropertySetAssetFactory__()
{
  UFG::Editor::PropertySetAssetFactory::PropertySetAssetFactory(&UFG::Editor::gPropertySetAssetFactory);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gPropertySetAssetFactory__);
}

// File Line: 28
// RVA: 0x202440
void __fastcall UFG::Editor::PropertySetAssetFactory::PropertySetAssetFactory(
        UFG::Editor::PropertySetAssetFactory *this)
{
  unsigned __int64 v2; // rax
  UFG::AssetHive *v3; // rax

  v2 = UFG::qStringHash64("PropertySet", 0xFFFFFFFFFFFFFFFFui64);
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = v2;
  this->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::HiveAssetFactory::`vftable;
  UFG::qString::qString(&this->mTypeName, "PropertySet");
  v3 = UFG::AssetHive::Instance();
  UFG::qTree64Base::Add(&v3->mFactories.mTree, &this->mBaseNode);
  this->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::Editor::PropertySetAssetFactory::`vftable;
}

// File Line: 36
// RVA: 0x209800
void __fastcall UFG::Editor::PropertySetAssetFactory::EditAssets(
        UFG::Editor::PropertySetAssetFactory *this,
        UFG::qArray<UFG::HiveAsset *,0> *assets)
{
  UFG::DUIWindow *m_pPointer; // r15
  unsigned int i; // esi
  char *mData; // rbx
  __int64 size; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::Editor::DAGPath *v9; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  UFG::allocator::free_link *v15; // rax
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v17; // rbx
  UFG::Editor::SmartHandleObject *v18; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v21; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v22; // rax
  UFG::Editor::SelectionSet *SelectionSet; // rbx
  UFG::Event *v24; // rax
  UFG::Editor::DAGPathType::Enum *p_mPathType; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v26; // rcx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> result; // [rsp+20h] [rbp-E0h] BYREF
  UFG::Editor::DAGPath item; // [rsp+40h] [rbp-C0h] BYREF
  UFG::Editor::SelectionSet set; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v35; // [rsp+F0h] [rbp-10h]
  UFG::qString v36; // [rsp+F8h] [rbp-8h] BYREF

  v35 = -2i64;
  UFG::Editor::EditorWindowManager::CreateWindow(&result, "UFG::Editor::PropertyBrowserWindow");
  m_pPointer = result.m_pPointer;
  set.mPrev = &set;
  set.mNext = &set;
  UFG::qString::qString(&set.mName, "default");
  set.mDAGPaths.p = 0i64;
  *(_QWORD *)&set.mDAGPaths.size = 0i64;
  for ( i = 0; i < assets->size; ++i )
  {
    mData = UFG::qString::FormatEx(&v36, "archy:%s", assets->p[i]->mName.mData)->mData;
    item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mPtr = 0i64;
    item.mFnObject.mTypeId = -1998658210;
    item.mSystemName.mUID = -1;
    item.mElements.p = 0i64;
    *(_QWORD *)&item.mElements.size = 0i64;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
    item.mInterfaceName.mUID = -1;
    memset(&item.mSubElements, 0, 20);
    UFG::Editor::DAGPath::SetFromString(&item, mData);
    UFG::qString::~qString(&v36);
    if ( UFG::qArray<UFG::Editor::DAGPath,0>::Find(&set.mDAGPaths, &item) <= -1 )
    {
      size = set.mDAGPaths.size;
      v7 = set.mDAGPaths.size + 1;
      if ( set.mDAGPaths.size + 1 > set.mDAGPaths.capacity )
      {
        if ( set.mDAGPaths.capacity )
          v8 = 2 * set.mDAGPaths.capacity;
        else
          v8 = 1;
        for ( ; v8 < v7; v8 *= 2 )
          ;
        if ( v8 - v7 > 0x10000 )
          v8 = set.mDAGPaths.size + 65537;
        UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&set.mDAGPaths, v8, "qArray.Add");
      }
      set.mDAGPaths.size = v7;
      v9 = &set.mDAGPaths.p[size];
      if ( &item != v9 )
      {
        UFG::Editor::DAGPath::Clear(&set.mDAGPaths.p[size]);
        if ( v9->mPathType == Default )
        {
          mPtr = item.mFnObject.mPtr;
          if ( !v9->mFnObject.mPtr )
          {
            if ( item.mFnObject.mPtr )
            {
              v9->mFnObject.mTypeId = item.mFnObject.mPtr->mTypeId;
              v9->mFnObject.mPtr = mPtr;
              p_mNode = &mPtr->mSmartHandleList.mNode;
              mPrev = p_mNode->mPrev;
              mPrev->mNext = &v9->mFnObject;
              v9->mFnObject.mPrev = mPrev;
              v9->mFnObject.mNext = p_mNode;
              p_mNode->mPrev = &v9->mFnObject;
            }
          }
        }
        v9->mSystemName.mUID = item.mSystemName.mUID;
        UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, &v9->mElements);
        v9->mInterfaceName.mUID = item.mInterfaceName.mUID;
        UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, &v9->mSubElements);
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
      v14->mUserData0 = (unsigned __int64)&set;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v14);
    }
    if ( item.mSubElements.p )
    {
      p_mStringHash32 = &item.mSubElements.p[-1].mStringHash32;
      `eh vector destructor iterator(
        item.mSubElements.p,
        0x28ui64,
        item.mSubElements.p[-1].mStringHash32,
        (void (__fastcall *)(void *))UFG::qString::~qString);
      operator delete[](p_mStringHash32);
    }
    item.mSubElements.p = 0i64;
    *(_QWORD *)&item.mSubElements.size = 0i64;
    if ( item.mElements.p )
    {
      v17 = item.mElements.p - 1;
      `eh vector destructor iterator(
        item.mElements.p,
        4ui64,
        item.mElements.p[-1].mUID,
        (void (__fastcall *)(void *))_);
      operator delete[](v17);
    }
    item.mElements.p = 0i64;
    *(_QWORD *)&item.mElements.size = 0i64;
    v18 = item.mFnObject.mPtr;
    if ( item.mFnObject.mPtr )
    {
      v19 = item.mFnObject.mPrev;
      mNext = item.mFnObject.mNext;
      item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
      mNext->mPrev = v19;
      item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v18->mSmartHandleList.mNode.mNext == &v18->mSmartHandleList
        && v18 )
      {
        v18->vfptr->__vecDelDtor(v18, 1u);
      }
      item.mFnObject.mPtr = 0i64;
    }
    item.mFnObject.mPtr = 0i64;
    v21 = item.mFnObject.mPrev;
    v22 = item.mFnObject.mNext;
    item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
    v22->mPrev = v21;
    item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
  }
  SelectionSet = UFG::Editor::SelectionManager::GetCreateSelectionSet((const char *)m_pPointer[2].mDialogResult);
  SelectionSet->mDAGPaths.size = 0;
  v24 = (UFG::Event *)UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  if ( v24 )
  {
    v24->mPrev = &v24->UFG::qNode<UFG::Event,UFG::Event>;
    v24->mNext = &v24->UFG::qNode<UFG::Event,UFG::Event>;
    v24->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
    v24->m_EventUID = 609910773;
    v24->m_NamePTR = 0i64;
  }
  else
  {
    v24 = 0i64;
  }
  v24->mUserData0 = (unsigned __int64)SelectionSet;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v24);
  UFG::Editor::SelectionSet::Add(SelectionSet, &set);
  m_pPointer[1].UFG::qNode<UFG::DUIWindow,UFG::DUIManager>::mNext = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)SelectionSet;
  BYTE1(m_pPointer[2].mTitle.mPrev) = 1;
  LOBYTE(m_pPointer[2].mTitle.mMagic) = 1;
  if ( set.mDAGPaths.p )
  {
    p_mPathType = &set.mDAGPaths.p[-1].mPathType;
    `eh vector destructor iterator(
      set.mDAGPaths.p,
      0x58ui64,
      set.mDAGPaths.p[-1].mPathType,
      (void (__fastcall *)(void *))UFG::Editor::DAGPath::~DAGPath);
    operator delete[](p_mPathType);
  }
  set.mDAGPaths.p = 0i64;
  *(_QWORD *)&set.mDAGPaths.size = 0i64;
  UFG::qString::~qString(&set.mName);
  v26 = set.mPrev;
  v27 = set.mNext;
  set.mPrev->mNext = set.mNext;
  v27->mPrev = v26;
  set.mPrev = &set;
  set.mNext = &set;
  if ( result.m_pPointer )
  {
    v28 = result.mPrev;
    v29 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v29->mPrev = v28;
    result.mPrev = &result;
    result.mNext = &result;
  }
  v30 = result.mPrev;
  v31 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v31->mPrev = v30;
}

// File Line: 107
// RVA: 0x20D280
void __fastcall UFG::Editor::PropertySetAssetFactory::IndexAssets(
        UFG::Editor::PropertySetAssetFactory *this,
        UFG::AssetHive *hive)
{
  UFG::qBaseNodeRB *Head; // rsi
  UFG::qBaseNodeRB *mParent; // rax
  const char *v5; // rbx
  char *Last; // rax
  const char *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::HiveAsset *v9; // rax
  UFG::HiveAsset *v10; // rdi
  UFG::qString *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rdx
  UFG::qString *v14; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qString *v18; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qString *v20; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qString *v22; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v23; // rax
  UFG::qString *v24; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qString *v26; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  UFG::qSymbol result; // [rsp+80h] [rbp+18h] BYREF
  void *v30; // [rsp+88h] [rbp+20h]

  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142369440);
  if ( Head )
  {
    while ( 1 )
    {
      mParent = Head[3].mParent;
      v5 = mParent ? (char *)&Head[3] + (_QWORD)mParent : 0i64;
      UFG::qSymbol::create_from_string(&result, v5);
      Last = UFG::qStringFindLast(v5, "-");
      v7 = Last ? Last + 1 : v5;
      v8 = UFG::qMalloc(0x120ui64, UFG::gGlobalNewName, 0i64);
      v30 = v8;
      if ( v8 )
      {
        UFG::HiveAsset::HiveAsset((UFG::HiveAsset *)v8, result.mUID, v5, v7, "PropertySet", &customCaption);
        v10 = v9;
      }
      else
      {
        v10 = 0i64;
      }
      if ( UFG::qStringFindInsensitive(v5, "object-physical-character-") )
        break;
      if ( UFG::qStringFindInsensitive(v5, "object-physical-weapon-") )
      {
        v14 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v14;
        if ( v14 )
        {
          UFG::qString::qString(v14, "Weapons");
          v13 = v15;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "object-physical-vehicle-") )
      {
        v16 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v16;
        if ( v16 )
        {
          UFG::qString::qString(v16, "Vehicles");
          v13 = v17;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "object-physical-GameAsset-") )
      {
        v18 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v18;
        if ( v18 )
        {
          UFG::qString::qString(v18, "Game Assets");
          v13 = v19;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "object-logical-") )
      {
        v20 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v20;
        if ( v20 )
        {
          UFG::qString::qString(v20, "Logical Objects");
          v13 = v21;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "default-component-InterestPoint-") )
      {
        v22 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v22;
        if ( v22 )
        {
          UFG::qString::qString(v22, "InterestPoints");
          v13 = v23;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "default-component-") )
      {
        v24 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v24;
        if ( v24 )
        {
          UFG::qString::qString(v24, "Components");
          v13 = v25;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
      if ( UFG::qStringFindInsensitive(v5, "object-physical-Prefab-") )
      {
        v26 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
        v30 = v26;
        if ( v26 )
        {
          UFG::qString::qString(v26, "Prefabs");
          v13 = v27;
        }
        else
        {
          v13 = 0i64;
        }
        goto LABEL_43;
      }
LABEL_44:
      UFG::AssetHive::AddAsset(hive, v10);
      Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142369440, Head);
      if ( !Head )
        return;
    }
    v11 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v30 = v11;
    if ( v11 )
    {
      UFG::qString::qString(v11, "Characters");
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
LABEL_43:
    mPrev = v10->mTags.mNode.mPrev;
    mPrev->mNext = v13;
    v13->mPrev = mPrev;
    v13->mNext = &v10->mTags.mNode;
    v10->mTags.mNode.mPrev = v13;
    goto LABEL_44;
  }
}

