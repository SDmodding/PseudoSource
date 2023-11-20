// File Line: 16
// RVA: 0x146D2C0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::PrefabWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::PrefabWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::PrefabWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::PrefabWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::PrefabWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::PrefabWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 28
// RVA: 0x201F90
void __fastcall UFG::Editor::PrefabWindow::PrefabWindow(UFG::Editor::PrefabWindow *this)
{
  UFG::Editor::PrefabWindow *v1; // rbx
  hkSeekableStreamReader *v2; // [rsp+38h] [rbp-20h]
  void (__fastcall *v3)(UFG::Editor::PrefabWindow *, UFG::Event *); // [rsp+40h] [rbp-18h]
  UFG::DUIIntArray *v4; // [rsp+68h] [rbp+10h]
  UFG::DUIIntArray *v5; // [rsp+68h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::PrefabWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mIgnoreSelectionChange = 0;
  UFG::Editor::DAGPath::DAGPath(&v1->mPrefabPath);
  UFG::Editor::DAGPath::DAGPath(&v1->mPrefabPathNext);
  v1->mScrollPos = 0i64;
  v4 = &v1->mSelectedItems;
  v4->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v4->mData.p = 0i64;
  *(_QWORD *)&v4->mData.size = 0i64;
  v5 = &v1->mExpandedItems;
  v5->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v5->mData.p = 0i64;
  *(_QWORD *)&v5->mData.size = 0i64;
  UFG::qString::Set(&v1->mTitle, "Prefab Inspector");
  v3 = UFG::Editor::PrefabWindow::OnSelectionChanged;
  v2 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v2,
    0x245A7FF5u,
    0i64,
    0);
}

// File Line: 42
// RVA: 0x201E80
void __fastcall UFG::Editor::PrefabWindow::PrefabWindow(UFG::Editor::PrefabWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::PrefabWindow *v2; // rbx
  hkSeekableStreamReader *v3; // [rsp+38h] [rbp-20h]
  void (__fastcall *v4)(UFG::Editor::PrefabWindow *, UFG::Event *); // [rsp+40h] [rbp-18h]
  UFG::DUIIntArray *v5; // [rsp+70h] [rbp+18h]
  UFG::DUIIntArray *v6; // [rsp+70h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mIgnoreSelectionChange = 0;
  UFG::Editor::DAGPath::DAGPath(&v2->mPrefabPath);
  UFG::Editor::DAGPath::DAGPath(&v2->mPrefabPathNext);
  v2->mScrollPos = 0i64;
  v5 = &v2->mSelectedItems;
  v5->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v5->mData.p = 0i64;
  *(_QWORD *)&v5->mData.size = 0i64;
  v6 = &v2->mExpandedItems;
  v6->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v6->mData.p = 0i64;
  *(_QWORD *)&v6->mData.size = 0i64;
  UFG::qString::Set(&v2->mTitle, "Prefab Inspector");
  v4 = UFG::Editor::PrefabWindow::OnSelectionChanged;
  v3 = Assembly::GetRCX(v2);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v3,
    0x245A7FF5u,
    0i64,
    0);
}

// File Line: 49
// RVA: 0x203650
void __fastcall UFG::Editor::PrefabWindow::~PrefabWindow(UFG::Editor::PrefabWindow *this)
{
  UFG::Editor::PrefabWindow *v1; // rdi
  unsigned __int64 *v2; // rcx
  unsigned __int64 *v3; // rcx
  hkSeekableStreamReader *v4; // [rsp+28h] [rbp-20h]
  void (__fastcall *v5)(UFG::Editor::PrefabWindow *, UFG::Event *); // [rsp+30h] [rbp-18h]

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v5 = UFG::Editor::PrefabWindow::OnSelectionChanged;
  v4 = Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v4,
    0x245A7FF5u);
  v2 = v1->mExpandedItems.mData.p;
  if ( v2 )
    operator delete[](v2);
  v1->mExpandedItems.mData.p = 0i64;
  *(_QWORD *)&v1->mExpandedItems.mData.size = 0i64;
  v3 = v1->mSelectedItems.mData.p;
  if ( v3 )
    operator delete[](v3);
  v1->mSelectedItems.mData.p = 0i64;
  *(_QWORD *)&v1->mSelectedItems.mData.size = 0i64;
  UFG::Editor::DAGPath::~DAGPath(&v1->mPrefabPathNext);
  UFG::Editor::DAGPath::~DAGPath(&v1->mPrefabPath);
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 55
// RVA: 0x20FA50
void __fastcall UFG::Editor::PrefabWindow::OnSelectionChanged(UFG::Editor::PrefabWindow *this, UFG::Event *__formal)
{
  UFG::Editor::PrefabWindow *v2; // r15
  char *v3; // rbp
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v4; // r14
  unsigned int v5; // esi
  signed __int64 v6; // rdi
  bool v7; // zf
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::SmartHandleObject *v10; // rax
  unsigned int v11; // ecx
  _QWORD *v12; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rax
  __int64 v14; // rax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  UFG::Editor::FnModifier **v17; // rax
  UFG::Editor::FnModifier *v18; // rbx
  UFG::Editor::FnModifier *v19; // rax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *v21; // rax
  UFG::qSymbol symbol; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( this->mIgnoreSelectionChange )
    return;
  v3 = 0i64;
  v4 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v5 = 0;
  if ( !LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) )
    return;
  while ( 1 )
  {
    v6 = (signed __int64)v4[4].mPrev + 88 * v5;
    v7 = *(_DWORD *)(v6 + 80) == 1;
    symbol.mUID = *(_DWORD *)(v6 + 56);
    if ( v7 )
      goto LABEL_21;
    if ( !*(_QWORD *)(v6 + 16) )
    {
      v8 = *(_DWORD *)(v6 + 32);
      if ( v8 )
      {
        v9 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v8);
        if ( v9 )
        {
          if ( v9 != (UFG::qBaseTreeRB *)8 )
          {
            v10 = UFG::Editor::DAGType::AquireFnObject(
                    (UFG::Editor::DAGType *)&v9[-1].mCount,
                    (UFG::Editor::DAGPath *)v6);
            if ( !*(_QWORD *)(v6 + 16) )
            {
              if ( v10 )
              {
                v11 = v10->mTypeId;
                *(_QWORD *)(v6 + 16) = v10;
                *(_DWORD *)(v6 + 24) = v11;
                v12 = &v10->mSmartHandleList.mNode.mPrev;
                v13 = v10->mSmartHandleList.mNode.mPrev;
                v13->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v6;
                *(_QWORD *)v6 = v13;
                *(_QWORD *)(v6 + 8) = v12;
                *v12 = v6;
              }
            }
          }
        }
      }
    }
    v14 = *(_QWORD *)(v6 + 16);
    if ( !v14 )
      goto LABEL_21;
    if ( *(_DWORD *)(v6 + 56) == -1 )
    {
      v15 = *(_DWORD *)(v14 + 64);
      v16 = 0;
      if ( v15 )
      {
        v17 = *(UFG::Editor::FnModifier ***)(v14 + 72);
        while ( 1 )
        {
          v18 = *v17;
          if ( (*v17)->mTypeID == 884077544 )
            break;
          ++v16;
          ++v17;
          if ( v16 >= v15 )
            goto LABEL_17;
        }
      }
      else
      {
LABEL_17:
        v18 = 0i64;
      }
    }
    else
    {
      v19 = UFG::Editor::FnObject::GetModifier(*(UFG::Editor::FnObject **)(v6 + 16), &symbol);
      v18 = v19;
      if ( !v19 || v19->mTypeID != 884077544 )
        goto LABEL_21;
    }
    if ( v18 )
      break;
LABEL_21:
    if ( ++v5 >= LODWORD(v4[3].mNext) )
      return;
  }
  UFG::Editor::DAGPath::operator=(&v2->mPrefabPath, (UFG::Editor::DAGPath *)v6);
  v20 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          (UFG::qPropertySet *)v18->mFnObject[1].vfptr,
          (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( v20 )
    v3 = UFG::qPropertySet::GetMemImagePtr(v20);
  v21 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v3);
  UFG::Editor::Core::OpenForEdit(v21);
}

// File Line: 77
// RVA: 0x21ABA0
void __fastcall UFG::Editor::PrefabWindow::UpdateUI(UFG::Editor::PrefabWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::Editor::PrefabWindow *v3; // rsi
  unsigned int v4; // er15
  UFG::Editor::DAGPath *v5; // r13
  UFG::Editor::FnPrefab *v6; // rax
  UFG::Editor::FnPrefab *v7; // rbx
  UFG::qPropertySet *v8; // rax
  char *v9; // rax
  UFG::qPropertySet *v10; // rax
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  UFG::qPropertySet *v13; // rax
  int v14; // ecx
  int v15; // ebx
  UFG::qString *v16; // rax
  UFG::qString *v17; // rbx
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  char *v20; // rax
  __int64 v21; // rdi
  unsigned int v22; // esi
  unsigned int v23; // er14
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v24; // rax
  UFG::qArray<UFG::Editor::DAGPath,0> *v25; // r12
  __int64 v26; // r12
  unsigned int v27; // ecx
  unsigned int v28; // edi
  unsigned int v29; // ebx
  unsigned __int64 v30; // rax
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // r14
  void *v33; // rcx
  UFG::allocator::free_link *v34; // rdx
  __int64 v35; // r9
  __int64 v36; // r8
  UFG::DUIContext *v37; // r15
  unsigned int v38; // edx
  unsigned int v39; // eax
  UFG::allocator::free_link *v40; // rax
  UFG::Event *v41; // rdx
  UFG::allocator::free_link *v42; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v43; // r13
  unsigned int v44; // er14
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v45; // rbx
  signed __int64 v46; // rdi
  __int64 v47; // rsi
  unsigned int v48; // ebx
  unsigned int v49; // edx
  unsigned int v50; // edx
  signed __int64 v51; // rbx
  __int64 v52; // rcx
  signed __int64 *v53; // rcx
  signed __int64 v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::Event *v56; // rdx
  UFG::allocator::free_link *v57; // rax
  int v58; // ebx
  unsigned int v59; // edx
  UFG::qBaseTreeRB *v60; // rax
  UFG::Editor::SmartHandleObject *v61; // rax
  _QWORD *v62; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v63; // rax
  __int64 v64; // rax
  unsigned int v65; // ecx
  unsigned int v66; // edx
  __int64 v67; // r8
  __int64 v68; // rax
  __int64 v69; // r8
  __int64 v70; // r8
  UFG::qPropertySet *v71; // rax
  char *v72; // rax
  UFG::qPropertySet *v73; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *i; // rbx
  unsigned int v75; // er8
  unsigned int v76; // eax
  UFG::Editor::SelectionSet *v77; // rdi
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v78; // rbx
  UFG::allocator::free_link *v79; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::Event *v82; // rdx
  UFG::allocator::free_link *v83; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *j; // rbx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v85; // rcx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v86; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v87; // rdx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v88; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *k; // rbx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v90; // rcx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v91; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v92; // rdx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v93; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v94; // rcx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v95; // rax
  UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> mapList; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol v97; // [rsp+40h] [rbp-C0h]
  UFG::Editor::FnPrefab *fnprefab; // [rsp+48h] [rbp-B8h]
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v99; // [rsp+50h] [rbp-B0h]
  UFG::qString v100; // [rsp+58h] [rbp-A8h]
  UFG::qString v101; // [rsp+88h] [rbp-78h]
  UFG::Editor::DAGPath *v102; // [rsp+B0h] [rbp-50h]
  UFG::qString dest; // [rsp+B8h] [rbp-48h]
  UFG::DUIRect result; // [rsp+E0h] [rbp-20h]
  UFG::qString v105; // [rsp+F0h] [rbp-10h]
  __int64 v106; // [rsp+118h] [rbp+18h]
  UFG::qString v107; // [rsp+120h] [rbp+20h]
  char name; // [rsp+150h] [rbp+50h]
  UFG::Editor::PrefabWindow *v109; // [rsp+5A0h] [rbp+4A0h]
  UFG::DUIContext *duia; // [rsp+5A8h] [rbp+4A8h]
  char v111; // [rsp+5B0h] [rbp+4B0h]
  UFG::qSymbol interfaceName; // [rsp+5B8h] [rbp+4B8h]

  duia = dui;
  v109 = this;
  v106 = -2i64;
  v2 = dui;
  v3 = this;
  if ( dui->mInputState.mKeyIsDownAlt
    || dui->mInputState.mKeyIsDownControl
    || (v111 = 0, dui->mInputState.mKeyIsDownShift) )
  {
    v111 = 1;
  }
  v99 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  UFG::DUIContext::SetLayoutRect(v2, &result);
  if ( UFG::DUIContext::IsMouseOver(v2, &result) && v2->mInputState.mMouseRBWentUp )
  {
    UFG::Editor::ShowContextMenu(v2);
    UFG::DUIInputState::ConsumeMouseButtonEvents(&v2->mInputState);
  }
  v4 = 0;
  if ( !v3->mPrefabPathNext.mElements.size )
    goto LABEL_151;
  v5 = &v3->mPrefabPath;
  v102 = &v3->mPrefabPath;
  UFG::Editor::DAGPath::operator=(&v3->mPrefabPath, &v3->mPrefabPathNext);
  UFG::Editor::DAGPath::Clear(&v3->mPrefabPathNext);
  fnprefab = (UFG::Editor::FnPrefab *)&interfaceName;
  interfaceName.mUID = v3->mPrefabPath.mInterfaceName.mUID;
  v6 = (UFG::Editor::FnPrefab *)UFG::Editor::DAGPath::GetInterface(
                                  &v3->mPrefabPath,
                                  0x34B1F3E8u,
                                  (__int64)&interfaceName);
  v7 = v6;
  fnprefab = v6;
  if ( v6 )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           (UFG::qPropertySet *)v6->mFnObject[1].vfptr,
           (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v8 )
      v9 = UFG::qPropertySet::GetMemImagePtr(v8);
    else
      v9 = 0i64;
    v10 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v9);
    UFG::Editor::Core::OpenForEdit(v10);
  }
  else
  {
LABEL_151:
    v5 = &v3->mPrefabPath;
    v102 = &v3->mPrefabPath;
    fnprefab = (UFG::Editor::FnPrefab *)&v97;
    v97.mUID = v3->mPrefabPath.mInterfaceName.mUID;
    v7 = (UFG::Editor::FnPrefab *)UFG::Editor::DAGPath::GetInterface(&v3->mPrefabPath, 0x34B1F3E8u, (__int64)&v97);
    fnprefab = v7;
    if ( !v7 )
    {
      UFG::DUIContext::BeginGridLayout(v2, 1, 2, 3);
      UFG::DUIContext::Label(v2, "No Prefab Selected");
      UFG::DUIContext::Separator(v2);
      UFG::DUIContext::EndLayoutHorizontal(v2);
      UFG::Editor::DAGPath::Clear(&v3->mPrefabPath);
      return;
    }
  }
  v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          (UFG::qPropertySet *)v7->mFnObject[1].vfptr,
          (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( v11 )
    v12 = UFG::qPropertySet::GetMemImagePtr(v11);
  else
    v12 = 0i64;
  v13 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v12);
  UFG::Editor::Core::OpenForEdit(v13);
  mapList.mNode.mPrev = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList;
  mapList.mNode.mNext = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList;
  UFG::Editor::PrefabWindow::PopulateHashMapChild(v3, v7, &mapList);
  UFG::DUIContext::BeginGridLayout(v2, 1, 4, 3);
  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&v7->mFnObject->mDAGPath, &dest, 1);
  v100.mPrev = *(UFG::qNode<UFG::qString,UFG::qString> **)&v2->mLastRect.mX;
  v14 = v2->mLastRect.mW;
  HIDWORD(v100.mNext) = v2->mLastRect.mH;
  v15 = (v14 - 84) / 7;
  if ( v15 < 8 )
    v15 = 8;
  UFG::qString::qString(&v105);
  if ( dest.mLength > v15 )
  {
    UFG::qString::qString(&v107, &dest.mData[dest.mLength - v15]);
    v17 = v16;
    UFG::qString::qString(&v100, "...");
    v19 = UFG::operator+(&v101, v18, v17);
    UFG::qString::Set(&v105, v19->mData, v19->mLength, 0i64, 0);
    UFG::qString::~qString(&v101);
    UFG::qString::~qString(&v100);
    UFG::qString::~qString(&v107);
  }
  else
  {
    UFG::qString::Set(&v105, dest.mData, dest.mLength, 0i64, 0);
  }
  UFG::qSPrintf(&name, 1024, "Prefab: %s", v105.mData);
  UFG::DUIContext::Label(v2, &name);
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "UP", 0x10u) )
  {
    v20 = UFG::qStringFindLast(dest.mData, "|$Prefab");
    if ( v20 )
    {
      *v20 = 0;
      UFG::Editor::DAGPath::SetFromString(&v3->mPrefabPathNext, dest.mData);
    }
  }
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPos);
  v101.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::DUIIntArray::`vftable;
  v21 = 0i64;
  *(_QWORD *)&v101.mMagic = 0i64;
  v22 = 0;
  v101.mNext = 0i64;
  v23 = 0;
  v24 = v99;
  v25 = (UFG::qArray<UFG::Editor::DAGPath,0> *)&v99[3].mNext;
  if ( LODWORD(v99[3].mNext) )
  {
    do
    {
      v26 = (unsigned int)UFG::Editor::DAGPath::GetHash((UFG::Editor::DAGPath *)v24[4].mPrev + v4);
      v27 = v22;
      v28 = v22 + 1;
      if ( v22 + 1 > v23 )
      {
        v29 = 1;
        if ( v23 )
          v29 = 2 * v23;
        for ( ; v29 < v28; v29 *= 2 )
          ;
        if ( v29 <= 2 )
          v29 = 2;
        if ( v29 - v28 > 0x10000 )
          v29 = v22 + 65537;
        if ( v29 != v22 )
        {
          v30 = 8i64 * v29;
          if ( !is_mul_ok(v29, 8ui64) )
            v30 = -1i64;
          v31 = UFG::qMalloc(v30, "qArray.Add", 0i64);
          v32 = v31;
          v33 = *(void **)&v101.mMagic;
          if ( *(_QWORD *)&v101.mMagic )
          {
            if ( v22 )
            {
              v34 = v31;
              v35 = *(_QWORD *)&v101.mMagic - (_QWORD)v31;
              v36 = v22;
              do
              {
                v34->mNext = *(UFG::allocator::free_link **)((char *)v34 + v35);
                ++v34;
                --v36;
              }
              while ( v36 );
            }
            operator delete[](v33);
          }
          *(_QWORD *)&v101.mMagic = v32;
          v23 = v29;
          HIDWORD(v101.mNext) = v29;
          v27 = v22;
        }
      }
      ++v22;
      LODWORD(v101.mNext) = v28;
      v21 = *(_QWORD *)&v101.mMagic;
      *(_QWORD *)(*(_QWORD *)&v101.mMagic + 8i64 * v27) = v26;
      ++v4;
      v24 = v99;
      v25 = (UFG::qArray<UFG::Editor::DAGPath,0> *)&v99[3].mNext;
    }
    while ( v4 < LODWORD(v99[3].mNext) );
    v5 = v102;
  }
  v100.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::DUIIntArray::`vftable;
  *(_QWORD *)&v100.mMagic = 0i64;
  v100.mNext = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone(
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v101.mNext,
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v100.mNext);
  v37 = duia;
  UFG::DUIContext::BeginTreeView(
    duia,
    (UFG::IDUICollectionView *)&v100,
    (UFG::IDUICollectionView *)&v109->mExpandedItems.vfptr,
    1);
  UFG::Editor::PrefabWindow::DisplayChildLabels(v109, fnprefab, duia);
  UFG::DUIContext::EndTreeView(duia);
  if ( v22 != LODWORD(v100.mNext) )
    goto LABEL_53;
  v38 = 0;
  if ( LODWORD(v100.mNext) )
  {
    while ( *(_QWORD *)(v21 + 8i64 * v38) == *(_QWORD *)(*(_QWORD *)&v100.mMagic + 8i64 * v38) )
    {
      if ( ++v38 >= LODWORD(v100.mNext) )
        goto LABEL_140;
    }
LABEL_53:
    v109->mIgnoreSelectionChange = 1;
    v39 = UFG::qArray<UFG::Editor::DAGPath,0>::Find(v25, v5);
    if ( v39 != -1 )
      UFG::qArray<UFG::Editor::DAGPath,0>::StableDelete(v25, v39);
    if ( v111 )
    {
      v43 = v99;
    }
    else
    {
      v25->size = 0;
      v40 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
      v41 = (UFG::Event *)v40;
      if ( v40 )
      {
        v42 = v40 + 1;
        v42->mNext = v42;
        v42[1].mNext = v42;
        v41->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v41->m_EventUID = 609910773;
        v41->m_NamePTR = 0i64;
      }
      else
      {
        v41 = 0i64;
      }
      v43 = v99;
      v41->mUserData0 = (unsigned __int64)v99;
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v41);
    }
    v44 = 0;
    if ( LODWORD(v100.mNext) )
    {
      while ( 1 )
      {
        v45 = mapList.mNode.mNext;
        if ( (UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *)mapList.mNode.mNext == &mapList )
          goto LABEL_120;
        while ( v45[6].mNext != *(UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> **)(*(_QWORD *)&v100.mMagic + 8i64 * v44) )
        {
          v45 = v45->mNext;
          if ( v45 == (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList )
            goto LABEL_120;
        }
        v46 = (signed __int64)&v45[1];
        if ( v45 == (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)-16i64 )
          goto LABEL_120;
        if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(v25, (UFG::Editor::DAGPath *)&v45[1]) <= -1 )
        {
          v47 = v25->size;
          v48 = v47 + 1;
          v49 = v25->capacity;
          if ( (signed int)v47 + 1 > v49 )
          {
            if ( v49 )
              v50 = 2 * v49;
            else
              v50 = 1;
            for ( ; v50 < v48; v50 *= 2 )
              ;
            if ( v50 - v48 > 0x10000 )
              v50 = v47 + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(v25, v50, "qArray.Add");
          }
          v25->size = v48;
          v51 = (signed __int64)&v25->p[v47];
          if ( v46 != v51 )
          {
            UFG::Editor::DAGPath::Clear(&v25->p[v47]);
            if ( !*(_DWORD *)(v51 + 80) )
            {
              v52 = *(_QWORD *)(v46 + 16);
              if ( !*(_QWORD *)(v51 + 16) )
              {
                if ( v52 )
                {
                  *(_DWORD *)(v51 + 24) = *(_DWORD *)(v52 + 56);
                  *(_QWORD *)(v51 + 16) = v52;
                  v53 = (signed __int64 *)(v52 + 40);
                  v54 = *v53;
                  *(_QWORD *)(v54 + 8) = v51;
                  *(_QWORD *)v51 = v54;
                  *(_QWORD *)(v51 + 8) = v53;
                  *v53 = v51;
                }
              }
            }
            *(_DWORD *)(v51 + 32) = *(_DWORD *)(v46 + 32);
            UFG::qArray<UFG::qSymbol,0>::Clone(
              (UFG::qArray<UFG::qSymbol,0> *)(v46 + 40),
              (UFG::qArray<UFG::qSymbol,0> *)(v51 + 40));
            *(_DWORD *)(v51 + 56) = *(_DWORD *)(v46 + 56);
            UFG::qArray<UFG::qString,0>::Clone(
              (UFG::qArray<UFG::qString,0> *)(v46 + 64),
              (UFG::qArray<UFG::qString,0> *)(v51 + 64));
          }
          v55 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
          v56 = (UFG::Event *)v55;
          if ( v55 )
          {
            v57 = v55 + 1;
            v57->mNext = v57;
            v57[1].mNext = v57;
            v56->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
            v56->m_EventUID = 609910773;
            v56->m_NamePTR = 0i64;
          }
          else
          {
            v56 = 0i64;
          }
          v56->mUserData0 = (unsigned __int64)v43;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v56);
        }
        v58 = *(_DWORD *)(v46 + 56);
        if ( *(_DWORD *)(v46 + 80) == 1 )
          goto LABEL_120;
        if ( !*(_QWORD *)(v46 + 16) )
        {
          v59 = *(_DWORD *)(v46 + 32);
          if ( v59 )
          {
            v60 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v59);
            if ( v60 )
            {
              if ( v60 != (UFG::qBaseTreeRB *)8 )
              {
                v61 = UFG::Editor::DAGType::AquireFnObject(
                        (UFG::Editor::DAGType *)&v60[-1].mCount,
                        (UFG::Editor::DAGPath *)v46);
                if ( !*(_QWORD *)(v46 + 16) )
                {
                  if ( v61 )
                  {
                    *(_DWORD *)(v46 + 24) = v61->mTypeId;
                    *(_QWORD *)(v46 + 16) = v61;
                    v62 = &v61->mSmartHandleList.mNode.mPrev;
                    v63 = v61->mSmartHandleList.mNode.mPrev;
                    v63->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v46;
                    *(_QWORD *)v46 = v63;
                    *(_QWORD *)(v46 + 8) = v62;
                    *v62 = v46;
                  }
                }
              }
            }
          }
        }
        v64 = *(_QWORD *)(v46 + 16);
        if ( !v64 )
          goto LABEL_120;
        v65 = 0;
        v66 = *(_DWORD *)(v64 + 64);
        if ( *(_DWORD *)(v46 + 56) == -1 )
        {
          if ( v66 )
          {
            v67 = *(_QWORD *)(v64 + 72);
            while ( 1 )
            {
              v68 = *(_QWORD *)(v67 + 8i64 * v65);
              if ( *(_DWORD *)(v68 + 8) == 884077544 )
                break;
              if ( ++v65 >= v66 )
                goto LABEL_101;
            }
          }
          else
          {
LABEL_101:
            v68 = 0i64;
          }
LABEL_115:
          if ( v68 )
          {
            v71 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                    *(UFG::qPropertySet **)(*(_QWORD *)(v68 + 16) + 168i64),
                    (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
                    DEPTH_RECURSE);
            if ( v71 )
              v72 = UFG::qPropertySet::GetMemImagePtr(v71);
            else
              v72 = 0i64;
            v73 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v72);
            UFG::Editor::Core::OpenForEdit(v73);
          }
          goto LABEL_120;
        }
        if ( v58 == -1 )
        {
          if ( v66 )
          {
            v69 = *(_QWORD *)(v64 + 72);
            while ( 1 )
            {
              v68 = *(_QWORD *)(v69 + 8i64 * v65);
              if ( *(_DWORD *)(v68 + 8) == 1864359155 )
                break;
              if ( ++v65 >= v66 )
                goto LABEL_107;
            }
          }
          else
          {
LABEL_107:
            v68 = 0i64;
          }
        }
        else
        {
          if ( !v66 )
            goto LABEL_120;
          v70 = *(_QWORD *)(v64 + 72);
          while ( 1 )
          {
            v68 = *(_QWORD *)(v70 + 8i64 * v65);
            if ( *(_DWORD *)(v68 + 12) == v58 )
              break;
            if ( ++v65 >= v66 )
              goto LABEL_120;
          }
        }
        if ( v68 && *(_DWORD *)(v68 + 8) == 884077544 )
          goto LABEL_115;
LABEL_120:
        if ( ++v44 >= LODWORD(v100.mNext) )
        {
          v37 = duia;
          break;
        }
      }
    }
    for ( i = mapList.mNode.mNext;
          i != (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList;
          i = i->mNext )
    {
      v75 = 0;
      if ( LODWORD(v100.mNext) )
      {
        while ( i[6].mNext != *(UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> **)(*(_QWORD *)&v100.mMagic + 8i64 * v75) )
        {
          if ( ++v75 >= LODWORD(v100.mNext) )
            goto LABEL_126;
        }
      }
      else
      {
LABEL_126:
        v76 = UFG::qArray<UFG::Editor::DAGPath,0>::Find(v25, (UFG::Editor::DAGPath *)&i[1]);
        if ( v76 != -1 )
          UFG::qArray<UFG::Editor::DAGPath,0>::StableDelete(v25, v76);
      }
    }
    v77 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
    v78 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
    if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
    {
LABEL_132:
      v79 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      v78 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v79;
      if ( v79 )
      {
        v79->mNext = v79;
        v79[1].mNext = v79;
        UFG::qString::qString((UFG::qString *)&v79[2], "LastSelection");
        v78[4].mPrev = 0i64;
        v78[3].mNext = 0i64;
      }
      else
      {
        v78 = 0i64;
      }
      v80 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v78;
      v78->mPrev = v80;
      v78->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v78;
    }
    else
    {
      while ( (unsigned int)UFG::qStringCompare("LastSelection", (const char *)v78[2].mNext, -1) )
      {
        v78 = v78->mNext;
        if ( v78 == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
          goto LABEL_132;
      }
    }
    LODWORD(v78[3].mNext) = 0;
    v81 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v82 = (UFG::Event *)v81;
    if ( v81 )
    {
      v83 = v81 + 1;
      v83->mNext = v83;
      v83[1].mNext = v83;
      v82->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
      v82->m_EventUID = 609910773;
      v82->m_NamePTR = 0i64;
    }
    else
    {
      v82 = 0i64;
    }
    v82->mUserData0 = (unsigned __int64)v78;
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v82);
    UFG::Editor::SelectionSet::Add((UFG::Editor::SelectionSet *)v78, v77);
    v109->mIgnoreSelectionChange = 0;
  }
LABEL_140:
  if ( *(_QWORD *)&v100.mMagic )
    operator delete[](*(void **)&v100.mMagic);
  *(_QWORD *)&v100.mMagic = 0i64;
  v100.mNext = 0i64;
  if ( *(_QWORD *)&v101.mMagic )
    operator delete[](*(void **)&v101.mMagic);
  *(_QWORD *)&v101.mMagic = 0i64;
  v101.mNext = 0i64;
  for ( j = mapList.mNode.mNext;
        (UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *)mapList.mNode.mNext != &mapList;
        j = mapList.mNode.mNext )
  {
    v85 = j->mPrev;
    v86 = j->mNext;
    v85->mNext = v86;
    v86->mPrev = v85;
    j->mPrev = j;
    j->mNext = j;
    UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)&j[1]);
    v87 = j->mPrev;
    v88 = j->mNext;
    v87->mNext = v88;
    v88->mPrev = v87;
    j->mPrev = j;
    j->mNext = j;
    operator delete[](j);
  }
  UFG::DUIContext::EndScrollView(v37);
  UFG::DUIContext::EndLayoutHorizontal(v37);
  UFG::qString::~qString(&v105);
  UFG::qString::~qString(&dest);
  for ( k = mapList.mNode.mNext;
        (UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *)mapList.mNode.mNext != &mapList;
        k = mapList.mNode.mNext )
  {
    v90 = k->mPrev;
    v91 = k->mNext;
    v90->mNext = v91;
    v91->mPrev = v90;
    k->mPrev = k;
    k->mNext = k;
    UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)&k[1]);
    v92 = k->mPrev;
    v93 = k->mNext;
    v92->mNext = v93;
    v93->mPrev = v92;
    k->mPrev = k;
    k->mNext = k;
    operator delete[](k);
  }
  v94 = mapList.mNode.mPrev;
  v95 = mapList.mNode.mNext;
  mapList.mNode.mPrev->mNext = mapList.mNode.mNext;
  v95->mPrev = v94;
}apList.mNode.mNext;
        (UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *)mapList.mNode.mNext != &mapList;
        k = mapList.mNode.mNext )
  {
    v90 = k->mPrev;
    v91 = k->mNext;
    v90->mNext = v91;
    v91->mPrev = v90;
    k->mPrev = k;
    k->mNext = k;
    UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)&k[1]);
    v92 = k->mPrev;
    v93 = k->mNext;
    v92->mNext = v93;
    v93->mPrev = v92;
    k->mPrev = k;
    k->mNext = k;
    operator delete[](k);

// File Line: 257
// RVA: 0x208840
void __fastcall UFG::Editor::PrefabWindow::DisplayChildLabels(UFG::Editor::PrefabWindow *this, UFG::Editor::FnPrefab *fnprefab, UFG::DUIContext *dui)
{
  UFG::DUIContext *v3; // rbp
  UFG::Editor::FnPrefab *v4; // rbx
  UFG::Editor::PrefabWindow *v5; // r14
  component_PrefabData *v6; // rax
  component_PrefabData *v7; // rdi
  __int64 v8; // rax
  unsigned int v9; // esi
  unsigned int v10; // ebx
  UFG::qPropertyList *v11; // rcx
  char *v12; // rax
  UFG::qPropertySet *v13; // rdx
  UFG::qString dest; // [rsp+28h] [rbp-30h]

  v3 = dui;
  v4 = fnprefab;
  v5 = this;
  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&v4->mFnObject->mDAGPath, &dest, 1);
  UFG::qString::operator+=(&dest, "|$Prefab");
  v6 = UFG::Editor::FnPrefab::GetPrefabData(v4);
  v7 = v6;
  v8 = v6->Prefab_SceneObjects.mOffset;
  if ( v8 )
    v8 += (__int64)v7;
  v9 = *(_DWORD *)(v8 + 40);
  v10 = 0;
  if ( v9 )
  {
    do
    {
      if ( v7->Prefab_SceneObjects.mOffset )
        v11 = (UFG::qPropertyList *)((char *)v7 + v7->Prefab_SceneObjects.mOffset);
      else
        v11 = 0i64;
      v12 = UFG::qPropertyList::GetValuePtr(v11, 0x1Au, v10);
      if ( v12 && *(_QWORD *)v12 )
        v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      UFG::Editor::PrefabWindow::DisplayChildLabelsRec(v5, v13, &dest, v3);
      ++v10;
    }
    while ( v10 < v9 );
  }
  UFG::qString::~qString(&dest);
}

// File Line: 272
// RVA: 0x208930
void __fastcall UFG::Editor::PrefabWindow::DisplayChildLabelsRec(UFG::Editor::PrefabWindow *this, UFG::qPropertySet *sceneObject, UFG::qString *parentPath, UFG::DUIContext *dui)
{
  UFG::qString *v4; // rbx
  UFG::qPropertySet *v5; // rdi
  char *v6; // rax
  UFG::qPropertyList *v7; // rdi
  UFG::qPropertyList *v8; // rax
  signed int v9; // esi
  char *v10; // rax
  const char *v11; // rbx
  unsigned int v12; // eax
  const char *v13; // rdx
  UFG::DUIContext *v14; // rbx
  char v15; // al
  UFG::Editor::DAGPath *v16; // rbx
  UFG::Editor::SmartHandleObject *v17; // rcx
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v18; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rax
  signed int i; // ebx
  char *v21; // rax
  UFG::qPropertySet *v22; // rdx
  unsigned int *v23; // rbx
  UFG::qSymbol *v24; // rbx
  UFG::Editor::SmartHandleObject *v25; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v26; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v27; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v33; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v34; // rax
  UFG::Editor::DAGPath v35; // [rsp+20h] [rbp-59h]
  __int64 v36; // [rsp+80h] [rbp+7h]
  UFG::qString result; // [rsp+88h] [rbp+Fh]
  UFG::Editor::PrefabWindow *v38; // [rsp+E0h] [rbp+67h]
  UFG::qSymbolUC *v39; // [rsp+E8h] [rbp+6Fh]
  char v40; // [rsp+E8h] [rbp+6Fh]
  UFG::DUIContext *duia; // [rsp+F8h] [rbp+7Fh]

  duia = dui;
  v38 = this;
  v36 = -2i64;
  v4 = parentPath;
  v5 = sceneObject;
  v39 = (UFG::qSymbolUC *)&sceneObject->mName;
  v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&sceneObject->mName);
  UFG::qString::FormatEx(&result, "%s|%s", v4->mData, v6);
  v35.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
  v35.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
  v35.mFnObject.mPtr = 0i64;
  v35.mFnObject.mTypeId = -1998658210;
  v35.mSystemName.mUID = -1;
  v35.mElements.p = 0i64;
  *(_QWORD *)&v35.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&v35.mElements, 4u, "qArray.Reallocate(Constructor)");
  v35.mInterfaceName.mUID = -1;
  v35.mSubElements.p = 0i64;
  *(_QWORD *)&v35.mSubElements.size = 0i64;
  v35.mPathType = 0;
  UFG::Editor::DAGPath::SetFromString(&v35, result.mData);
  if ( v5 )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v5,
           (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID,
           DEPTH_RECURSE);
    v7 = v8;
    if ( v8 )
    {
      v9 = v8->mNumElements;
      goto LABEL_6;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v9 = 0;
LABEL_6:
  v10 = UFG::qSymbol::as_cstr_dbg(v39);
  v11 = "Unknown";
  if ( v10 )
    v11 = v10;
  v12 = UFG::Editor::DAGPath::GetHash(&v35);
  v13 = v11;
  v14 = duia;
  v15 = UFG::DUIContext::TreeViewItem(duia, v13, v12, v9 != 0);
  v40 = v15;
  if ( duia->mDoubleClicked )
  {
    v16 = &v38->mPrefabPathNext;
    if ( &v35 != &v38->mPrefabPathNext )
    {
      UFG::Editor::DAGPath::Clear(&v38->mPrefabPathNext);
      if ( v38->mPrefabPathNext.mPathType == Default && !v38->mPrefabPathNext.mFnObject.mPtr )
      {
        v17 = v35.mFnObject.mPtr;
        if ( v35.mFnObject.mPtr )
        {
          v38->mPrefabPathNext.mFnObject.mTypeId = v35.mFnObject.mPtr->mTypeId;
          v38->mPrefabPathNext.mFnObject.mPtr = v17;
          v18 = &v17->mSmartHandleList;
          v19 = v18->mNode.mPrev;
          v19->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v16->mFnObject.mPrev;
          v16->mFnObject.mPrev = v19;
          v38->mPrefabPathNext.mFnObject.mNext = &v18->mNode;
          v18->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v16->mFnObject.mPrev;
        }
      }
      v38->mPrefabPathNext.mSystemName.mUID = v35.mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&v35.mElements, &v38->mPrefabPathNext.mElements);
      v38->mPrefabPathNext.mInterfaceName.mUID = v35.mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&v35.mSubElements, &v38->mPrefabPathNext.mSubElements);
      v15 = v40;
    }
    v14 = duia;
  }
  if ( v7 && v15 )
  {
    UFG::DUIContext::BeginIndent(v14);
    for ( i = 0; i < v9; ++i )
    {
      v21 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, i);
      if ( v21 && *(_QWORD *)v21 )
        v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
      else
        v22 = 0i64;
      UFG::Editor::PrefabWindow::DisplayChildLabelsRec(v38, v22, &result, duia);
    }
    UFG::DUIContext::EndIndent(duia);
  }
  if ( v35.mSubElements.p )
  {
    v23 = &v35.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      v35.mSubElements.p,
      0x28ui64,
      v35.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v23);
  }
  v35.mSubElements.p = 0i64;
  *(_QWORD *)&v35.mSubElements.size = 0i64;
  if ( v35.mElements.p )
  {
    v24 = v35.mElements.p - 1;
    `eh vector destructor iterator(v35.mElements.p, 4ui64, v35.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v24);
  }
  v35.mElements.p = 0i64;
  *(_QWORD *)&v35.mElements.size = 0i64;
  v25 = v35.mFnObject.mPtr;
  if ( v35.mFnObject.mPtr )
  {
    v26 = v35.mFnObject.mPrev;
    v27 = v35.mFnObject.mNext;
    v35.mFnObject.mPrev->mNext = v35.mFnObject.mNext;
    v27->mPrev = v26;
    v35.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
    v35.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v25->mSmartHandleList.mNode.mNext == &v25->mSmartHandleList
      && v25 )
    {
      v25->vfptr->__vecDelDtor(v25, 1u);
    }
    v35.mFnObject.mPtr = 0i64;
  }
  v35.mFnObject.mPtr = 0i64;
  v35.mFnObject.mPtr = 0i64;
  v33 = v35.mFnObject.mPrev;
  v34 = v35.mFnObject.mNext;
  v35.mFnObject.mPrev->mNext = v35.mFnObject.mNext;
  v34->mPrev = v33;
  v35.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
  v35.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v35;
  UFG::qString::~qString(&result);
}

// File Line: 302
// RVA: 0x2101B0
void __fastcall UFG::Editor::PrefabWindow::PopulateHashMapChild(UFG::Editor::PrefabWindow *this, UFG::Editor::FnPrefab *fnPrefab, UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *mapList)
{
  UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *v3; // rbp
  UFG::Editor::FnPrefab *v4; // rbx
  UFG::Editor::PrefabWindow *v5; // r14
  UFG::qPropertySet *v6; // rax
  UFG::qPropertySet *v7; // rdi
  __int64 v8; // rax
  unsigned int v9; // esi
  unsigned int v10; // ebx
  UFG::qPropertyList *v11; // rcx
  char *v12; // rax
  UFG::qPropertySet *v13; // rdx
  UFG::qString dest; // [rsp+28h] [rbp-30h]

  v3 = mapList;
  v4 = fnPrefab;
  v5 = this;
  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&v4->mFnObject->mDAGPath, &dest, 1);
  UFG::qString::operator+=(&dest, "|$Prefab");
  v6 = UFG::Editor::FnPrefab::GetPrefabData(v4);
  v7 = v6;
  v8 = *(_QWORD *)&v6->mFlags;
  if ( v8 )
    v8 += (__int64)v7;
  v9 = *(_DWORD *)(v8 + 40);
  v10 = 0;
  if ( v9 )
  {
    do
    {
      if ( *(_QWORD *)&v7->mFlags )
        v11 = (UFG::qPropertyList *)((char *)v7 + *(_QWORD *)&v7->mFlags);
      else
        v11 = 0i64;
      v12 = UFG::qPropertyList::GetValuePtr(v11, 0x1Au, v10);
      if ( v12 && *(_QWORD *)v12 )
        v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
      else
        v13 = 0i64;
      UFG::Editor::PrefabWindow::PopulateHashMapChildRec(v5, v13, &dest, v3);
      ++v10;
    }
    while ( v10 < v9 );
  }
  UFG::qString::~qString(&dest);
}

// File Line: 315
// RVA: 0x2102A0
void __fastcall UFG::Editor::PrefabWindow::PopulateHashMapChildRec(UFG::Editor::PrefabWindow *this, UFG::qPropertySet *sceneObject, UFG::qString *parentPath, UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *hashMap)
{
  UFG::qString *v4; // rbx
  UFG::qPropertySet *v5; // rdi
  char *v6; // rax
  signed int v7; // ebx
  UFG::qPropertyList *v8; // rsi
  UFG::qPropertyList *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  signed __int64 v12; // rbx
  UFG::Editor::SmartHandleObject *v13; // rcx
  __int64 *v14; // rcx
  __int64 v15; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v16; // rax
  char *v17; // rax
  UFG::qPropertySet *v18; // rdx
  unsigned int *v19; // rbx
  UFG::qSymbol *v20; // rbx
  UFG::Editor::SmartHandleObject *v21; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v22; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v23; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v29; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v30; // rax
  UFG::Editor::DAGPath v31; // [rsp+20h] [rbp-69h]
  UFG::allocator::free_link *v32; // [rsp+80h] [rbp-9h]
  __int64 v33; // [rsp+88h] [rbp-1h]
  __int64 v34; // [rsp+90h] [rbp+7h]
  UFG::qString result; // [rsp+98h] [rbp+Fh]
  UFG::Editor::PrefabWindow *v36; // [rsp+F0h] [rbp+67h]
  signed int v37; // [rsp+F8h] [rbp+6Fh]
  UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *hashMapa; // [rsp+108h] [rbp+7Fh]

  hashMapa = hashMap;
  v36 = this;
  v34 = -2i64;
  v4 = parentPath;
  v5 = sceneObject;
  v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&sceneObject->mName);
  UFG::qString::FormatEx(&result, "%s|%s", v4->mData, v6);
  v31.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
  v31.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
  v7 = 0;
  v31.mFnObject.mPtr = 0i64;
  v31.mFnObject.mTypeId = -1998658210;
  v31.mSystemName.mUID = -1;
  v31.mElements.p = 0i64;
  *(_QWORD *)&v31.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&v31.mElements, 4u, "qArray.Reallocate(Constructor)");
  v31.mInterfaceName.mUID = -1;
  v31.mSubElements.p = 0i64;
  *(_QWORD *)&v31.mSubElements.size = 0i64;
  v31.mPathType = 0;
  UFG::Editor::DAGPath::SetFromString(&v31, result.mData);
  if ( v5 )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v5,
           (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID,
           DEPTH_RECURSE);
    v8 = v9;
    if ( v9 )
    {
      v37 = v9->mNumElements;
      goto LABEL_6;
    }
  }
  else
  {
    v8 = 0i64;
  }
  v37 = 0;
LABEL_6:
  v10 = UFG::qMalloc(0x70ui64, UFG::gGlobalNewName, 0i64);
  v11 = v10;
  if ( v10 )
  {
    v10->mNext = v10;
    v10[1].mNext = v10;
    v12 = (signed __int64)&v10[2];
    v33 = v12;
    v32 = v10 + 2;
    *(_QWORD *)v12 = v12;
    *(_QWORD *)(v12 + 8) = v12;
    v10[4].mNext = 0i64;
    LODWORD(v10[5].mNext) = -1998658210;
    LODWORD(v10[6].mNext) = -1;
    v10[8].mNext = 0i64;
    v10[7].mNext = 0i64;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(
      (UFG::qArray<UFG::qSymbol,0> *)&v10[7],
      4u,
      "qArray.Reallocate(Constructor)");
    *(_DWORD *)(v12 + 56) = -1;
    *(_QWORD *)(v12 + 72) = 0i64;
    *(_QWORD *)(v12 + 64) = 0i64;
    *(_DWORD *)(v12 + 80) = 0;
    if ( &v31 != (UFG::Editor::DAGPath *)v12 )
    {
      UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)v12);
      if ( !*(_DWORD *)(v12 + 80) )
      {
        v13 = v31.mFnObject.mPtr;
        if ( !*(_QWORD *)(v12 + 16) )
        {
          if ( v31.mFnObject.mPtr )
          {
            *(_DWORD *)(v12 + 24) = v31.mFnObject.mPtr->mTypeId;
            *(_QWORD *)(v12 + 16) = v13;
            v14 = (__int64 *)&v13->mSmartHandleList;
            v15 = *v14;
            *(_QWORD *)(v15 + 8) = v12;
            *(_QWORD *)v12 = v15;
            *(_QWORD *)(v12 + 8) = v14;
            *v14 = v12;
          }
        }
      }
      *(_DWORD *)(v12 + 32) = v31.mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&v31.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v12 + 40));
      *(_DWORD *)(v12 + 56) = v31.mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&v31.mSubElements, (UFG::qArray<UFG::qString,0> *)(v12 + 64));
    }
    v11[13].mNext = (UFG::allocator::free_link *)(unsigned int)UFG::Editor::DAGPath::GetHash(&v31);
    v7 = 0;
  }
  else
  {
    v11 = 0i64;
  }
  v16 = hashMapa->mNode.mPrev;
  v16->mNext = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v11;
  v11->mNext = (UFG::allocator::free_link *)v16;
  v11[1].mNext = (UFG::allocator::free_link *)hashMapa;
  hashMapa->mNode.mPrev = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v11;
  if ( v37 > 0 )
  {
    do
    {
      v17 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v7);
      if ( v17 && *(_QWORD *)v17 )
        v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
      else
        v18 = 0i64;
      UFG::Editor::PrefabWindow::PopulateHashMapChildRec(v36, v18, &result, hashMapa);
      ++v7;
    }
    while ( v7 < v37 );
  }
  if ( v31.mSubElements.p )
  {
    v19 = &v31.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      v31.mSubElements.p,
      0x28ui64,
      v31.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v19);
  }
  v31.mSubElements.p = 0i64;
  *(_QWORD *)&v31.mSubElements.size = 0i64;
  if ( v31.mElements.p )
  {
    v20 = v31.mElements.p - 1;
    `eh vector destructor iterator(v31.mElements.p, 4ui64, v31.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v20);
  }
  v31.mElements.p = 0i64;
  *(_QWORD *)&v31.mElements.size = 0i64;
  v21 = v31.mFnObject.mPtr;
  if ( v31.mFnObject.mPtr )
  {
    v22 = v31.mFnObject.mPrev;
    v23 = v31.mFnObject.mNext;
    v31.mFnObject.mPrev->mNext = v31.mFnObject.mNext;
    v23->mPrev = v22;
    v31.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
    v31.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v21->mSmartHandleList.mNode.mNext == &v21->mSmartHandleList
      && v21 )
    {
      v21->vfptr->__vecDelDtor(v21, 1u);
    }
    v31.mFnObject.mPtr = 0i64;
  }
  v31.mFnObject.mPtr = 0i64;
  v31.mFnObject.mPtr = 0i64;
  v29 = v31.mFnObject.mPrev;
  v30 = v31.mFnObject.mNext;
  v31.mFnObject.mPrev->mNext = v31.mFnObject.mNext;
  v30->mPrev = v29;
  v31.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
  v31.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v31;
  UFG::qString::~qString(&result);
}

