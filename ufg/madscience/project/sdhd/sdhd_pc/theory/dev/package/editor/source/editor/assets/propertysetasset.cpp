// File Line: 24
// RVA: 0x146DA80
__int64 UFG::Editor::_dynamic_initializer_for__gPropertySetAssetFactory__()
{
  UFG::Editor::PropertySetAssetFactory::PropertySetAssetFactory(&UFG::Editor::gPropertySetAssetFactory);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gPropertySetAssetFactory__);
}

// File Line: 28
// RVA: 0x202440
void __fastcall UFG::Editor::PropertySetAssetFactory::PropertySetAssetFactory(UFG::Editor::PropertySetAssetFactory *this)
{
  UFG::Editor::PropertySetAssetFactory *v1; // rdi
  unsigned __int64 v2; // rax
  UFG::qTreeNode64<UFG::HiveAssetFactory,UFG::HiveAssetFactory> *v3; // rbx
  UFG::AssetHive *v4; // rax

  v1 = this;
  v2 = UFG::qStringHash64("PropertySet", 0xFFFFFFFFFFFFFFFFui64);
  v3 = (UFG::qTreeNode64<UFG::HiveAssetFactory,UFG::HiveAssetFactory> *)&v1->mBaseNode;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v2;
  v1->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::HiveAssetFactory::`vftable';
  UFG::qString::qString(&v1->mTypeName, "PropertySet");
  v4 = UFG::AssetHive::Instance();
  UFG::qTree64Base::Add(&v4->mFactories.mTree, &v1->mBaseNode);
  v1->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::Editor::PropertySetAssetFactory::`vftable';
}

// File Line: 36
// RVA: 0x209800
void __fastcall UFG::Editor::PropertySetAssetFactory::EditAssets(UFG::Editor::PropertySetAssetFactory *this, UFG::qArray<UFG::HiveAsset *,0> *assets)
{
  UFG::qArray<UFG::HiveAsset *,0> *v2; // r14
  UFG::DUIWindow *v3; // r15
  unsigned int i; // esi
  char *v5; // rbx
  __int64 v6; // rdi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::Editor::DAGPath *v9; // rbx
  UFG::Editor::SmartHandleObject *v10; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v11; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rdx
  UFG::allocator::free_link *v15; // rax
  unsigned int *v16; // rbx
  UFG::qSymbol *v17; // rbx
  UFG::Editor::SmartHandleObject *v18; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v20; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v21; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v22; // rax
  UFG::Editor::SelectionSet *v23; // rax
  UFG::Editor::SelectionSet *v24; // rbx
  UFG::Event *v25; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v26; // rcx
  UFG::Editor::DAGPathType::Enum *v27; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v28; // rcx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> result; // [rsp+20h] [rbp-E0h]
  UFG::Editor::DAGPath item; // [rsp+40h] [rbp-C0h]
  UFG::Editor::SelectionSet set; // [rsp+A0h] [rbp-60h]
  __int64 v37; // [rsp+F0h] [rbp-10h]
  UFG::qString v38; // [rsp+F8h] [rbp-8h]

  v37 = -2i64;
  v2 = assets;
  UFG::Editor::EditorWindowManager::CreateWindow(&result, "UFG::Editor::PropertyBrowserWindow");
  v3 = result.m_pPointer;
  set.mPrev = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&set;
  set.mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&set;
  UFG::qString::qString(&set.mName, "default");
  set.mDAGPaths.p = 0i64;
  *(_QWORD *)&set.mDAGPaths.size = 0i64;
  for ( i = 0; i < v2->size; ++i )
  {
    v5 = UFG::qString::FormatEx(&v38, "archy:%s", v2->p[i]->mName.mData)->mData;
    item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mPtr = 0i64;
    item.mFnObject.mTypeId = -1998658210;
    item.mSystemName.mUID = -1;
    item.mElements.p = 0i64;
    *(_QWORD *)&item.mElements.size = 0i64;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
    item.mInterfaceName.mUID = -1;
    item.mSubElements.p = 0i64;
    *(_QWORD *)&item.mSubElements.size = 0i64;
    item.mPathType = 0;
    UFG::Editor::DAGPath::SetFromString(&item, v5);
    UFG::qString::~qString(&v38);
    if ( UFG::qArray<UFG::Editor::DAGPath,0>::Find(&set.mDAGPaths, &item) <= -1 )
    {
      v6 = set.mDAGPaths.size;
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
      v9 = &set.mDAGPaths.p[v6];
      if ( &item != v9 )
      {
        UFG::Editor::DAGPath::Clear(&set.mDAGPaths.p[v6]);
        if ( v9->mPathType == Default )
        {
          v10 = item.mFnObject.mPtr;
          if ( !v9->mFnObject.mPtr )
          {
            if ( item.mFnObject.mPtr )
            {
              v9->mFnObject.mTypeId = item.mFnObject.mPtr->mTypeId;
              v9->mFnObject.mPtr = v10;
              v11 = &v10->mSmartHandleList.mNode;
              v12 = v11->mPrev;
              v12->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v9->mFnObject.mPrev;
              v9->mFnObject.mPrev = v12;
              v9->mFnObject.mNext = v11;
              v11->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v9->mFnObject.mPrev;
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
        v14->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
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
      v16 = &item.mSubElements.p[-1].mStringHash32;
      `eh vector destructor iterator'(
        item.mSubElements.p,
        0x28ui64,
        item.mSubElements.p[-1].mStringHash32,
        (void (__fastcall *)(void *))UFG::qString::~qString);
      operator delete[](v16);
    }
    item.mSubElements.p = 0i64;
    *(_QWORD *)&item.mSubElements.size = 0i64;
    if ( item.mElements.p )
    {
      v17 = item.mElements.p - 1;
      `eh vector destructor iterator'(
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
      v20 = item.mFnObject.mNext;
      item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
      v20->mPrev = v19;
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
  v23 = UFG::Editor::SelectionManager::GetCreateSelectionSet((const char *)v3[2].mDialogResult);
  v24 = v23;
  v23->mDAGPaths.size = 0;
  v25 = (UFG::Event *)UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  if ( v25 )
  {
    v26 = (UFG::qNode<UFG::Event,UFG::Event> *)&v25->mPrev;
    v26->mPrev = v26;
    v26->mNext = v26;
    v25->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
    v25->m_EventUID = 609910773;
    v25->m_NamePTR = 0i64;
  }
  else
  {
    v25 = 0i64;
  }
  v25->mUserData0 = (unsigned __int64)v24;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v25);
  UFG::Editor::SelectionSet::Add(v24, &set);
  v3[1].mNext = (UFG::qNode<UFG::DUIWindow,UFG::DUIManager> *)v24;
  BYTE1(v3[2].mTitle.mPrev) = 1;
  LOBYTE(v3[2].mTitle.mMagic) = 1;
  if ( set.mDAGPaths.p )
  {
    v27 = &set.mDAGPaths.p[-1].mPathType;
    `eh vector destructor iterator'(
      set.mDAGPaths.p,
      0x58ui64,
      set.mDAGPaths.p[-1].mPathType,
      (void (__fastcall *)(void *))UFG::Editor::DAGPath::~DAGPath);
    operator delete[](v27);
  }
  set.mDAGPaths.p = 0i64;
  *(_QWORD *)&set.mDAGPaths.size = 0i64;
  UFG::qString::~qString(&set.mName);
  v28 = set.mPrev;
  v29 = set.mNext;
  set.mPrev->mNext = set.mNext;
  v29->mPrev = v28;
  set.mPrev = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&set;
  set.mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&set;
  if ( result.m_pPointer )
  {
    v30 = result.mPrev;
    v31 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v31->mPrev = v30;
    result.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&result;
    result.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&result;
  }
  v32 = result.mPrev;
  v33 = result.mNext;
  result.mPrev->mNext = result.mNext;
  v33->mPrev = v32;
}

// File Line: 107
// RVA: 0x20D280
void __fastcall UFG::Editor::PropertySetAssetFactory::IndexAssets(UFG::Editor::PropertySetAssetFactory *this, UFG::AssetHive *hive)
{
  UFG::AssetHive *v2; // rbp
  UFG::qBaseNodeRB *v3; // rsi
  UFG::qBaseNodeRB *v4; // rax
  const char *v5; // rbx
  char *v6; // rax
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
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qSymbol result; // [rsp+80h] [rbp+18h]
  void *v30; // [rsp+88h] [rbp+20h]

  v2 = hive;
  v3 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142369440);
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = v3[3].mParent;
      v5 = (const char *)(v4 ? (UFG::qBaseNodeRB *)((char *)&v3[3] + (_QWORD)v4) : 0i64);
      UFG::qSymbol::create_from_string(&result, v5);
      v6 = UFG::qStringFindLast(v5, "-");
      v7 = v6 ? v6 + 1 : v5;
      v8 = UFG::qMalloc(0x120ui64, UFG::gGlobalNewName, 0i64);
      v30 = v8;
      if ( v8 )
      {
        UFG::HiveAsset::HiveAsset((UFG::HiveAsset *)v8, result.mUID, v5, v7, "PropertySet", &customWorldMapCaption);
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
        goto LABEL_50;
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
        goto LABEL_50;
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
        goto LABEL_50;
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
        goto LABEL_50;
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
        goto LABEL_50;
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
        goto LABEL_50;
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
        goto LABEL_50;
      }
LABEL_51:
      UFG::AssetHive::AddAsset(v2, v10);
      v3 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142369440, v3);
      if ( !v3 )
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
LABEL_50:
    v28 = v10->mTags.mNode.mPrev;
    v28->mNext = v13;
    v13->mPrev = v28;
    v13->mNext = &v10->mTags.mNode;
    v10->mTags.mNode.mPrev = v13;
    goto LABEL_51;
  }
}

