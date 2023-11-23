// File Line: 16
// RVA: 0x146D2C0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::PrefabWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::PrefabWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory,
    "UFG::Editor::PrefabWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::PrefabWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::PrefabWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::PrefabWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 28
// RVA: 0x201F90
void __fastcall UFG::Editor::PrefabWindow::PrefabWindow(UFG::Editor::PrefabWindow *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+38h] [rbp-20h] BYREF

  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::PrefabWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mIgnoreSelectionChange = 0;
  UFG::Editor::DAGPath::DAGPath(&this->mPrefabPath);
  UFG::Editor::DAGPath::DAGPath(&this->mPrefabPathNext);
  this->mScrollPos = 0i64;
  this->mSelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedItems.mData.size = 0i64;
  this->mExpandedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mExpandedItems.mData.size = 0i64;
  UFG::qString::Set(&this->mTitle, "Prefab Inspector");
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PrefabWindow::OnSelectionChanged;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v2, 0x245A7FF5u, 0i64, 0);
}

// File Line: 42
// RVA: 0x201E80
void __fastcall UFG::Editor::PrefabWindow::PrefabWindow(UFG::Editor::PrefabWindow *this, MemImageLoadFlag f)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v3; // [rsp+38h] [rbp-20h] BYREF

  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mIgnoreSelectionChange = 0;
  UFG::Editor::DAGPath::DAGPath(&this->mPrefabPath);
  UFG::Editor::DAGPath::DAGPath(&this->mPrefabPathNext);
  this->mScrollPos = 0i64;
  this->mSelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedItems.mData.size = 0i64;
  this->mExpandedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mExpandedItems.mData.size = 0i64;
  UFG::qString::Set(&this->mTitle, "Prefab Inspector");
  v3.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PrefabWindow::OnSelectionChanged;
  v3.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v3, 0x245A7FF5u, 0i64, 0);
}

// File Line: 49
// RVA: 0x203650
void __fastcall UFG::Editor::PrefabWindow::~PrefabWindow(UFG::Editor::PrefabWindow *this)
{
  unsigned __int64 *p; // rcx
  unsigned __int64 *v3; // rcx
  fastdelegate::FastDelegate1<UFG::Event *,void> v4; // [rsp+28h] [rbp-20h] BYREF

  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::PrefabWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::PrefabWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v4.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::Editor::PrefabWindow::OnSelectionChanged;
  v4.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v4, 0x245A7FF5u);
  p = this->mExpandedItems.mData.p;
  if ( p )
    operator delete[](p);
  this->mExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mExpandedItems.mData.size = 0i64;
  v3 = this->mSelectedItems.mData.p;
  if ( v3 )
    operator delete[](v3);
  this->mSelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedItems.mData.size = 0i64;
  UFG::Editor::DAGPath::~DAGPath(&this->mPrefabPathNext);
  UFG::Editor::DAGPath::~DAGPath(&this->mPrefabPath);
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 55
// RVA: 0x20FA50
void __fastcall UFG::Editor::PrefabWindow::OnSelectionChanged(UFG::Editor::PrefabWindow *this, UFG::Event *__formal)
{
  char *MemImagePtr; // rbp
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mNext; // r14
  unsigned int v5; // esi
  __int64 v6; // rdi
  bool v7; // zf
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Editor::FnObject *v10; // rax
  unsigned int mTypeId; // ecx
  _QWORD *p_mPrev; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  __int64 v14; // rax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  UFG::Editor::FnModifier **v17; // rax
  UFG::Editor::FnModifier *v18; // rbx
  UFG::Editor::FnModifier *Modifier; // rax
  UFG::qPropertySet *v20; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol symbol; // [rsp+40h] [rbp+8h] BYREF

  if ( this->mIgnoreSelectionChange )
    return;
  MemImagePtr = 0i64;
  mNext = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v5 = 0;
  if ( !LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) )
    return;
  while ( 1 )
  {
    v6 = (__int64)mNext[4].mPrev + 88 * v5;
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
                mTypeId = v10->mTypeId;
                *(_QWORD *)(v6 + 16) = v10;
                *(_DWORD *)(v6 + 24) = mTypeId;
                p_mPrev = &v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                mPrev = v10->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                mPrev->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v6;
                *(_QWORD *)v6 = mPrev;
                *(_QWORD *)(v6 + 8) = p_mPrev;
                *p_mPrev = v6;
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
      Modifier = UFG::Editor::FnObject::GetModifier(*(UFG::Editor::FnObject **)(v6 + 16), &symbol);
      v18 = Modifier;
      if ( !Modifier || Modifier->mTypeID != 884077544 )
        goto LABEL_21;
    }
    if ( v18 )
      break;
LABEL_21:
    if ( ++v5 >= LODWORD(mNext[3].mNext) )
      return;
  }
  UFG::Editor::DAGPath::operator=(&this->mPrefabPath, (UFG::Editor::DAGPath *)v6);
  v20 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          (UFG::qPropertySet *)v18->mFnObject[1].vfptr,
          (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
          DEPTH_RECURSE);
  if ( v20 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v20);
  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)MemImagePtr);
  UFG::Editor::Core::OpenForEdit(PropertySet);
}

// File Line: 77
// RVA: 0x21ABA0
void __fastcall UFG::Editor::PrefabWindow::UpdateUI(UFG::Editor::PrefabWindow *this, UFG::DUIContext *dui)
{
  unsigned int v4; // r15d
  UFG::Editor::DAGPath *p_mPrefabPath; // r13
  UFG::Editor::FnPrefab *Interface; // rax
  UFG::Editor::FnPrefab *v7; // rbx
  UFG::qPropertySet *v8; // rax
  char *MemImagePtr; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v11; // rax
  char *v12; // rax
  UFG::qPropertySet *v13; // rax
  int mW; // ecx
  int v15; // ebx
  UFG::qString *v16; // rax
  UFG::qString *v17; // rbx
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  char *Last; // rax
  __int64 v21; // rdi
  unsigned int v22; // esi
  unsigned int v23; // r14d
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v24; // rax
  UFG::qArray<UFG::Editor::DAGPath,0> *p_mNext; // r12
  __int64 Hash; // r12
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
  unsigned int v44; // r14d
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v45; // rbx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v46; // rdi
  __int64 size; // rsi
  unsigned int v48; // ebx
  unsigned int capacity; // edx
  unsigned int v50; // edx
  __int64 v51; // rbx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *mPrev; // rcx
  __int64 *v53; // rcx
  __int64 v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::Event *v56; // rdx
  UFG::allocator::free_link *v57; // rax
  int v58; // ebx
  unsigned int v59; // edx
  UFG::qBaseTreeRB *v60; // rax
  UFG::Editor::FnObject *v61; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *p_mSmartHandleList; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v63; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v64; // rax
  unsigned int v65; // ecx
  unsigned int v66; // edx
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v67; // r8
  __int64 v68; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v69; // r8
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v70; // r8
  UFG::qPropertySet *v71; // rax
  char *v72; // rax
  UFG::qPropertySet *v73; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *i; // rbx
  unsigned int v75; // r8d
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
  UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> mapList; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qSymbol v97; // [rsp+40h] [rbp-C0h] BYREF
  UFG::Editor::FnPrefab *fnprefab; // [rsp+48h] [rbp-B8h]
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mNext; // [rsp+50h] [rbp-B0h]
  UFG::qString v100; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qString v101; // [rsp+88h] [rbp-78h] BYREF
  UFG::Editor::DAGPath *v102; // [rsp+B0h] [rbp-50h]
  UFG::qString dest; // [rsp+B8h] [rbp-48h] BYREF
  UFG::DUIRect result; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qString v105; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v106; // [rsp+118h] [rbp+18h]
  UFG::qString v107; // [rsp+120h] [rbp+20h] BYREF
  char name[1088]; // [rsp+150h] [rbp+50h] BYREF
  char v111; // [rsp+5B0h] [rbp+4B0h]
  UFG::qSymbol interfaceName; // [rsp+5B8h] [rbp+4B8h] BYREF

  v106 = -2i64;
  if ( dui->mInputState.mKeyIsDownAlt
    || dui->mInputState.mKeyIsDownControl
    || (v111 = 0, dui->mInputState.mKeyIsDownShift) )
  {
    v111 = 1;
  }
  mNext = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  UFG::DUIContext::SetLayoutRect(dui, &result);
  if ( UFG::DUIContext::IsMouseOver(dui, &result) && dui->mInputState.mMouseRBWentUp )
  {
    UFG::Editor::ShowContextMenu(dui);
    UFG::DUIInputState::ConsumeMouseButtonEvents(&dui->mInputState);
  }
  v4 = 0;
  if ( !this->mPrefabPathNext.mElements.size )
    goto LABEL_14;
  p_mPrefabPath = &this->mPrefabPath;
  v102 = &this->mPrefabPath;
  UFG::Editor::DAGPath::operator=(&this->mPrefabPath, &this->mPrefabPathNext);
  UFG::Editor::DAGPath::Clear(&this->mPrefabPathNext);
  fnprefab = (UFG::Editor::FnPrefab *)&interfaceName;
  interfaceName.mUID = this->mPrefabPath.mInterfaceName.mUID;
  Interface = (UFG::Editor::FnPrefab *)UFG::Editor::DAGPath::GetInterface(
                                         &this->mPrefabPath,
                                         0x34B1F3E8u,
                                         &interfaceName);
  v7 = Interface;
  fnprefab = Interface;
  if ( Interface )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           (UFG::qPropertySet *)Interface->mFnObject[1].vfptr,
           (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
           DEPTH_RECURSE);
    if ( v8 )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v8);
    else
      MemImagePtr = 0i64;
    PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)MemImagePtr);
    UFG::Editor::Core::OpenForEdit(PropertySet);
  }
  else
  {
LABEL_14:
    p_mPrefabPath = &this->mPrefabPath;
    v102 = &this->mPrefabPath;
    fnprefab = (UFG::Editor::FnPrefab *)&v97;
    v97.mUID = this->mPrefabPath.mInterfaceName.mUID;
    v7 = (UFG::Editor::FnPrefab *)UFG::Editor::DAGPath::GetInterface(&this->mPrefabPath, 0x34B1F3E8u, &v97);
    fnprefab = v7;
    if ( !v7 )
    {
      UFG::DUIContext::BeginGridLayout(dui, 1, 2, LayoutFlag_FillLastCell);
      UFG::DUIContext::Label(dui, "No Prefab Selected");
      UFG::DUIContext::Separator(dui);
      UFG::DUIContext::EndLayoutHorizontal(dui);
      UFG::Editor::DAGPath::Clear(&this->mPrefabPath);
      return;
    }
  }
  v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          (UFG::qPropertySet *)v7->mFnObject[1].vfptr,
          (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
          DEPTH_RECURSE);
  if ( v11 )
    v12 = UFG::qPropertySet::GetMemImagePtr(v11);
  else
    v12 = 0i64;
  v13 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v12);
  UFG::Editor::Core::OpenForEdit(v13);
  mapList.mNode.mPrev = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList;
  mapList.mNode.mNext = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)&mapList;
  UFG::Editor::PrefabWindow::PopulateHashMapChild(this, v7, &mapList);
  UFG::DUIContext::BeginGridLayout(dui, 1, 4, LayoutFlag_FillLastCell);
  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&v7->mFnObject->mDAGPath, &dest, 1);
  v100.mPrev = *(UFG::qNode<UFG::qString,UFG::qString> **)&dui->mLastRect.mX;
  mW = dui->mLastRect.mW;
  HIDWORD(v100.mNext) = dui->mLastRect.mH;
  v15 = (mW - 84) / 7;
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
  UFG::qSPrintf(name, 1024, "Prefab: %s", v105.mData);
  UFG::DUIContext::Label(dui, name);
  if ( UFG::DUIContext::Button(dui, "UP", 0x10u) )
  {
    Last = UFG::qStringFindLast(dest.mData, "|$Prefab");
    if ( Last )
    {
      *Last = 0;
      UFG::Editor::DAGPath::SetFromString(&this->mPrefabPathNext, dest.mData);
    }
  }
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  v101.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::DUIIntArray::`vftable;
  v21 = 0i64;
  *(_QWORD *)&v101.mMagic = 0i64;
  v22 = 0;
  v101.mNext = 0i64;
  v23 = 0;
  v24 = mNext;
  p_mNext = (UFG::qArray<UFG::Editor::DAGPath,0> *)&mNext[3].mNext;
  if ( LODWORD(mNext[3].mNext) )
  {
    do
    {
      Hash = (unsigned int)UFG::Editor::DAGPath::GetHash((UFG::Editor::DAGPath *)v24[4].mPrev + v4);
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
      *(_QWORD *)(*(_QWORD *)&v101.mMagic + 8i64 * v27) = Hash;
      ++v4;
      v24 = mNext;
      p_mNext = (UFG::qArray<UFG::Editor::DAGPath,0> *)&mNext[3].mNext;
    }
    while ( v4 < LODWORD(mNext[3].mNext) );
    p_mPrefabPath = v102;
  }
  v100.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::DUIIntArray::`vftable;
  *(_QWORD *)&v100.mMagic = 0i64;
  v100.mNext = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone(
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v101.mNext,
    (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v100.mNext);
  v37 = dui;
  UFG::DUIContext::BeginTreeView(
    dui,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v100,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mExpandedItems,
    1);
  UFG::Editor::PrefabWindow::DisplayChildLabels(this, fnprefab, dui);
  UFG::DUIContext::EndTreeView(dui);
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
    this->mIgnoreSelectionChange = 1;
    v39 = UFG::qArray<UFG::Editor::DAGPath,0>::Find(p_mNext, p_mPrefabPath);
    if ( v39 != -1 )
      UFG::qArray<UFG::Editor::DAGPath,0>::StableDelete(p_mNext, v39);
    if ( v111 )
    {
      v43 = mNext;
    }
    else
    {
      p_mNext->size = 0;
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
      v43 = mNext;
      v41->mUserData0 = (unsigned __int64)mNext;
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
        v46 = v45 + 1;
        if ( v45 == (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)-16i64 )
          goto LABEL_120;
        if ( (int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(p_mNext, (UFG::Editor::DAGPath *)&v45[1]) <= -1 )
        {
          size = p_mNext->size;
          v48 = size + 1;
          capacity = p_mNext->capacity;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v50 = 2 * capacity;
            else
              v50 = 1;
            for ( ; v50 < v48; v50 *= 2 )
              ;
            if ( v50 - v48 > 0x10000 )
              v50 = size + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(p_mNext, v50, "qArray.Add");
          }
          p_mNext->size = v48;
          v51 = (__int64)&p_mNext->p[size];
          if ( v46 != (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v51 )
          {
            UFG::Editor::DAGPath::Clear(&p_mNext->p[size]);
            if ( !*(_DWORD *)(v51 + 80) )
            {
              mPrev = v46[1].mPrev;
              if ( !*(_QWORD *)(v51 + 16) )
              {
                if ( mPrev )
                {
                  *(_DWORD *)(v51 + 24) = mPrev[3].mNext;
                  *(_QWORD *)(v51 + 16) = mPrev;
                  v53 = (__int64 *)&mPrev[2].mNext;
                  v54 = *v53;
                  *(_QWORD *)(v54 + 8) = v51;
                  *(_QWORD *)v51 = v54;
                  *(_QWORD *)(v51 + 8) = v53;
                  *v53 = v51;
                }
              }
            }
            *(_DWORD *)(v51 + 32) = v46[2].mPrev;
            UFG::qArray<UFG::qSymbol,0>::Clone(
              (UFG::qArray<UFG::qSymbol,0> *)&v46[2].mNext,
              (UFG::qArray<UFG::qSymbol,0> *)(v51 + 40));
            *(_DWORD *)(v51 + 56) = v46[3].mNext;
            UFG::qArray<UFG::qString,0>::Clone(
              (UFG::qArray<UFG::qString,0> *)&v46[4],
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
        v58 = (int)v46[3].mNext;
        if ( LODWORD(v46[5].mPrev) == 1 )
          goto LABEL_120;
        if ( !v46[1].mPrev )
        {
          v59 = (unsigned int)v46[2].mPrev;
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
                if ( !v46[1].mPrev )
                {
                  if ( v61 )
                  {
                    LODWORD(v46[1].mNext) = v61->mTypeId;
                    v46[1].mPrev = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v61;
                    p_mSmartHandleList = &v61->mSmartHandleList;
                    v63 = v61->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                    v63->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v46;
                    v46->mPrev = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v63;
                    v46->mNext = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)p_mSmartHandleList;
                    p_mSmartHandleList->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v46;
                  }
                }
              }
            }
          }
        }
        v64 = v46[1].mPrev;
        if ( !v64 )
          goto LABEL_120;
        v65 = 0;
        v66 = (unsigned int)v64[4].mPrev;
        if ( LODWORD(v46[3].mNext) == -1 )
        {
          if ( v66 )
          {
            v67 = v64[4].mNext;
            while ( 1 )
            {
              v68 = *((_QWORD *)&v67->mPrev + v65);
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
                    (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
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
            v69 = v64[4].mNext;
            while ( 1 )
            {
              v68 = *((_QWORD *)&v69->mPrev + v65);
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
          v70 = v64[4].mNext;
          while ( 1 )
          {
            v68 = *((_QWORD *)&v70->mPrev + v65);
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
          v37 = dui;
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
        v76 = UFG::qArray<UFG::Editor::DAGPath,0>::Find(p_mNext, (UFG::Editor::DAGPath *)&i[1]);
        if ( v76 != -1 )
          UFG::qArray<UFG::Editor::DAGPath,0>::StableDelete(p_mNext, v76);
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
    this->mIgnoreSelectionChange = 0;
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
}

// File Line: 257
// RVA: 0x208840
void __fastcall UFG::Editor::PrefabWindow::DisplayChildLabels(
        UFG::Editor::PrefabWindow *this,
        UFG::Editor::FnPrefab *fnprefab,
        UFG::DUIContext *dui)
{
  component_PrefabData *PrefabData; // rdi
  __int64 mOffset; // rax
  unsigned int v8; // esi
  unsigned int i; // ebx
  UFG::qPropertyList *v10; // rcx
  char *ValuePtr; // rax
  UFG::qPropertySet *v12; // rdx
  UFG::qString dest; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&fnprefab->mFnObject->mDAGPath, &dest, 1);
  UFG::qString::operator+=(&dest, "|$Prefab");
  PrefabData = UFG::Editor::FnPrefab::GetPrefabData(fnprefab);
  mOffset = PrefabData->Prefab_SceneObjects.mOffset;
  if ( PrefabData->Prefab_SceneObjects.mOffset )
    mOffset += (__int64)PrefabData;
  v8 = *(_DWORD *)(mOffset + 40);
  for ( i = 0; i < v8; ++i )
  {
    if ( PrefabData->Prefab_SceneObjects.mOffset )
      v10 = (UFG::qPropertyList *)((char *)PrefabData + PrefabData->Prefab_SceneObjects.mOffset);
    else
      v10 = 0i64;
    ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, i);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v12 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v12 = 0i64;
    UFG::Editor::PrefabWindow::DisplayChildLabelsRec(this, v12, &dest, dui);
  }
  UFG::qString::~qString(&dest);
}

// File Line: 272
// RVA: 0x208930
void __fastcall UFG::Editor::PrefabWindow::DisplayChildLabelsRec(
        UFG::Editor::PrefabWindow *this,
        UFG::qPropertySet *sceneObject,
        UFG::qString *parentPath,
        UFG::DUIContext *dui)
{
  char *v6; // rax
  UFG::qPropertyList *v7; // rdi
  UFG::qPropertyList *v8; // rax
  signed int mNumElements; // esi
  char *v10; // rax
  const char *v11; // rbx
  unsigned int Hash; // eax
  const char *v13; // rdx
  UFG::DUIContext *v14; // rbx
  char v15; // al
  UFG::Editor::DAGPath *p_mPrefabPathNext; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  signed int i; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v22; // rdx
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v24; // rbx
  UFG::Editor::SmartHandleObject *v25; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v26; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v28; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v29; // rax
  UFG::Editor::DAGPath v30; // [rsp+20h] [rbp-59h] BYREF
  __int64 v31; // [rsp+80h] [rbp+7h]
  UFG::qString result; // [rsp+88h] [rbp+Fh] BYREF
  UFG::qSymbolUC *p_mName; // [rsp+E8h] [rbp+6Fh]
  char v35; // [rsp+E8h] [rbp+6Fh]

  v31 = -2i64;
  p_mName = (UFG::qSymbolUC *)&sceneObject->mName;
  v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&sceneObject->mName);
  UFG::qString::FormatEx(&result, "%s|%s", parentPath->mData, v6);
  v30.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
  v30.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
  v30.mFnObject.mPtr = 0i64;
  v30.mFnObject.mTypeId = -1998658210;
  v30.mSystemName.mUID = -1;
  v30.mElements.p = 0i64;
  *(_QWORD *)&v30.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&v30.mElements, 4u, "qArray.Reallocate(Constructor)");
  v30.mInterfaceName.mUID = -1;
  memset(&v30.mSubElements, 0, 20);
  UFG::Editor::DAGPath::SetFromString(&v30, result.mData);
  if ( sceneObject )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           sceneObject,
           (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymSimObjChildren,
           DEPTH_RECURSE);
    v7 = v8;
    if ( v8 )
    {
      mNumElements = v8->mNumElements;
      goto LABEL_6;
    }
  }
  else
  {
    v7 = 0i64;
  }
  mNumElements = 0;
LABEL_6:
  v10 = UFG::qSymbol::as_cstr_dbg(p_mName);
  v11 = "Unknown";
  if ( v10 )
    v11 = v10;
  Hash = UFG::Editor::DAGPath::GetHash(&v30);
  v13 = v11;
  v14 = dui;
  v15 = UFG::DUIContext::TreeViewItem(dui, v13, Hash, mNumElements != 0);
  v35 = v15;
  if ( dui->mDoubleClicked )
  {
    p_mPrefabPathNext = &this->mPrefabPathNext;
    if ( &v30 != &this->mPrefabPathNext )
    {
      UFG::Editor::DAGPath::Clear(&this->mPrefabPathNext);
      if ( this->mPrefabPathNext.mPathType == Default && !this->mPrefabPathNext.mFnObject.mPtr )
      {
        mPtr = v30.mFnObject.mPtr;
        if ( v30.mFnObject.mPtr )
        {
          this->mPrefabPathNext.mFnObject.mTypeId = v30.mFnObject.mPtr->mTypeId;
          this->mPrefabPathNext.mFnObject.mPtr = mPtr;
          p_mNode = &mPtr->mSmartHandleList.mNode;
          mPrev = p_mNode->mPrev;
          mPrev->mNext = &p_mPrefabPathNext->mFnObject;
          p_mPrefabPathNext->mFnObject.mPrev = mPrev;
          this->mPrefabPathNext.mFnObject.mNext = p_mNode;
          p_mNode->mPrev = &p_mPrefabPathNext->mFnObject;
        }
      }
      this->mPrefabPathNext.mSystemName.mUID = v30.mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&v30.mElements, &this->mPrefabPathNext.mElements);
      this->mPrefabPathNext.mInterfaceName.mUID = v30.mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&v30.mSubElements, &this->mPrefabPathNext.mSubElements);
      v15 = v35;
    }
    v14 = dui;
  }
  if ( v7 && v15 )
  {
    UFG::DUIContext::BeginIndent(v14);
    for ( i = 0; i < mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v22 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v22 = 0i64;
      UFG::Editor::PrefabWindow::DisplayChildLabelsRec(this, v22, &result, dui);
    }
    UFG::DUIContext::EndIndent(dui);
  }
  if ( v30.mSubElements.p )
  {
    p_mStringHash32 = &v30.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      v30.mSubElements.p,
      0x28ui64,
      v30.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  v30.mSubElements.p = 0i64;
  *(_QWORD *)&v30.mSubElements.size = 0i64;
  if ( v30.mElements.p )
  {
    v24 = v30.mElements.p - 1;
    `eh vector destructor iterator(v30.mElements.p, 4ui64, v30.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v24);
  }
  v30.mElements.p = 0i64;
  *(_QWORD *)&v30.mElements.size = 0i64;
  v25 = v30.mFnObject.mPtr;
  if ( v30.mFnObject.mPtr )
  {
    v26 = v30.mFnObject.mPrev;
    mNext = v30.mFnObject.mNext;
    v30.mFnObject.mPrev->mNext = v30.mFnObject.mNext;
    mNext->mPrev = v26;
    v30.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
    v30.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v25->mSmartHandleList.mNode.mNext == &v25->mSmartHandleList
      && v25 )
    {
      v25->vfptr->__vecDelDtor(v25, 1u);
    }
    v30.mFnObject.mPtr = 0i64;
  }
  v30.mFnObject.mPtr = 0i64;
  v28 = v30.mFnObject.mPrev;
  v29 = v30.mFnObject.mNext;
  v30.mFnObject.mPrev->mNext = v30.mFnObject.mNext;
  v29->mPrev = v28;
  v30.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
  v30.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v30;
  UFG::qString::~qString(&result);
}

// File Line: 302
// RVA: 0x2101B0
void __fastcall UFG::Editor::PrefabWindow::PopulateHashMapChild(
        UFG::Editor::PrefabWindow *this,
        UFG::Editor::FnPrefab *fnPrefab,
        UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *mapList)
{
  UFG::qPropertySet *PrefabData; // rdi
  __int64 v7; // rax
  unsigned int v8; // esi
  unsigned int i; // ebx
  UFG::qPropertyList *v10; // rcx
  char *ValuePtr; // rax
  UFG::qPropertySet *v12; // rdx
  UFG::qString dest; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&dest);
  UFG::Editor::DAGPath::GetAsString(&fnPrefab->mFnObject->mDAGPath, &dest, 1);
  UFG::qString::operator+=(&dest, "|$Prefab");
  PrefabData = UFG::Editor::FnPrefab::GetPrefabData(fnPrefab);
  v7 = *(_QWORD *)&PrefabData->mFlags;
  if ( *(_QWORD *)&PrefabData->mFlags )
    v7 += (__int64)PrefabData;
  v8 = *(_DWORD *)(v7 + 40);
  for ( i = 0; i < v8; ++i )
  {
    if ( *(_QWORD *)&PrefabData->mFlags )
      v10 = (UFG::qPropertyList *)((char *)PrefabData + *(_QWORD *)&PrefabData->mFlags);
    else
      v10 = 0i64;
    ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, i);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v12 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v12 = 0i64;
    UFG::Editor::PrefabWindow::PopulateHashMapChildRec(this, v12, &dest, mapList);
  }
  UFG::qString::~qString(&dest);
}

// File Line: 315
// RVA: 0x2102A0
void __fastcall UFG::Editor::PrefabWindow::PopulateHashMapChildRec(
        UFG::Editor::PrefabWindow *this,
        UFG::qPropertySet *sceneObject,
        UFG::qString *parentPath,
        UFG::qList<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo,1,0> *hashMap)
{
  char *v6; // rax
  signed int v7; // ebx
  UFG::qPropertyList *v8; // rsi
  UFG::qPropertyList *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v11; // rdi
  UFG::allocator::free_link *v12; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *p_mSmartHandleList; // rcx
  UFG::allocator::free_link *mPrev; // rax
  UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *v16; // rax
  char *ValuePtr; // rax
  UFG::qPropertySet *v18; // rdx
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v20; // rbx
  UFG::Editor::SmartHandleObject *v21; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v22; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mNext; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v24; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v25; // rax
  UFG::Editor::DAGPath v26; // [rsp+20h] [rbp-69h] BYREF
  UFG::allocator::free_link *v27; // [rsp+80h] [rbp-9h]
  UFG::allocator::free_link *v28; // [rsp+88h] [rbp-1h]
  __int64 v29; // [rsp+90h] [rbp+7h]
  UFG::qString result; // [rsp+98h] [rbp+Fh] BYREF
  int mNumElements; // [rsp+F8h] [rbp+6Fh]

  v29 = -2i64;
  v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&sceneObject->mName);
  UFG::qString::FormatEx(&result, "%s|%s", parentPath->mData, v6);
  v26.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
  v26.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
  v7 = 0;
  v26.mFnObject.mPtr = 0i64;
  v26.mFnObject.mTypeId = -1998658210;
  v26.mSystemName.mUID = -1;
  v26.mElements.p = 0i64;
  *(_QWORD *)&v26.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&v26.mElements, 4u, "qArray.Reallocate(Constructor)");
  v26.mInterfaceName.mUID = -1;
  memset(&v26.mSubElements, 0, 20);
  UFG::Editor::DAGPath::SetFromString(&v26, result.mData);
  if ( sceneObject )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           sceneObject,
           (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymSimObjChildren,
           DEPTH_RECURSE);
    v8 = v9;
    if ( v9 )
    {
      mNumElements = v9->mNumElements;
      goto LABEL_6;
    }
  }
  else
  {
    v8 = 0i64;
  }
  mNumElements = 0;
LABEL_6:
  v10 = UFG::qMalloc(0x70ui64, UFG::gGlobalNewName, 0i64);
  v11 = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)v10;
  if ( v10 )
  {
    v10->mNext = v10;
    v10[1].mNext = v10;
    v12 = v10 + 2;
    v28 = v10 + 2;
    v27 = v10 + 2;
    v10[2].mNext = v10 + 2;
    v10[3].mNext = v10 + 2;
    v10[4].mNext = 0i64;
    LODWORD(v10[5].mNext) = -1998658210;
    LODWORD(v10[6].mNext) = -1;
    v10[8].mNext = 0i64;
    v10[7].mNext = 0i64;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(
      (UFG::qArray<UFG::qSymbol,0> *)&v10[7],
      4u,
      "qArray.Reallocate(Constructor)");
    LODWORD(v12[7].mNext) = -1;
    v12[9].mNext = 0i64;
    v12[8].mNext = 0i64;
    LODWORD(v12[10].mNext) = 0;
    if ( &v26 != (UFG::Editor::DAGPath *)v12 )
    {
      UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)v12);
      if ( !LODWORD(v12[10].mNext) )
      {
        mPtr = v26.mFnObject.mPtr;
        if ( !v12[2].mNext )
        {
          if ( v26.mFnObject.mPtr )
          {
            LODWORD(v12[3].mNext) = v26.mFnObject.mPtr->mTypeId;
            v12[2].mNext = (UFG::allocator::free_link *)mPtr;
            p_mSmartHandleList = &mPtr->mSmartHandleList;
            mPrev = (UFG::allocator::free_link *)p_mSmartHandleList->mNode.mPrev;
            mPrev[1].mNext = v12;
            v12->mNext = mPrev;
            v12[1].mNext = (UFG::allocator::free_link *)p_mSmartHandleList;
            p_mSmartHandleList->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v12;
          }
        }
      }
      LODWORD(v12[4].mNext) = v26.mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&v26.mElements, (UFG::qArray<UFG::qSymbol,0> *)&v12[5]);
      LODWORD(v12[7].mNext) = v26.mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&v26.mSubElements, (UFG::qArray<UFG::qString,0> *)&v12[8]);
    }
    v11[6].mNext = (UFG::qNode<UFG::Editor::PrefabWindow::HashDagInfo,UFG::Editor::PrefabWindow::HashDagInfo> *)(unsigned int)UFG::Editor::DAGPath::GetHash(&v26);
    v7 = 0;
  }
  else
  {
    v11 = 0i64;
  }
  v16 = hashMap->mNode.mPrev;
  v16->mNext = v11;
  v11->mPrev = v16;
  v11->mNext = &hashMap->mNode;
  hashMap->mNode.mPrev = v11;
  if ( mNumElements > 0 )
  {
    do
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v7);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v18 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v18 = 0i64;
      UFG::Editor::PrefabWindow::PopulateHashMapChildRec(this, v18, &result, hashMap);
      ++v7;
    }
    while ( v7 < mNumElements );
  }
  if ( v26.mSubElements.p )
  {
    p_mStringHash32 = &v26.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      v26.mSubElements.p,
      0x28ui64,
      v26.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  v26.mSubElements.p = 0i64;
  *(_QWORD *)&v26.mSubElements.size = 0i64;
  if ( v26.mElements.p )
  {
    v20 = v26.mElements.p - 1;
    `eh vector destructor iterator(v26.mElements.p, 4ui64, v26.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v20);
  }
  v26.mElements.p = 0i64;
  *(_QWORD *)&v26.mElements.size = 0i64;
  v21 = v26.mFnObject.mPtr;
  if ( v26.mFnObject.mPtr )
  {
    v22 = v26.mFnObject.mPrev;
    mNext = v26.mFnObject.mNext;
    v26.mFnObject.mPrev->mNext = v26.mFnObject.mNext;
    mNext->mPrev = v22;
    v26.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
    v26.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v21->mSmartHandleList.mNode.mNext == &v21->mSmartHandleList
      && v21 )
    {
      v21->vfptr->__vecDelDtor(v21, 1u);
    }
    v26.mFnObject.mPtr = 0i64;
  }
  v26.mFnObject.mPtr = 0i64;
  v24 = v26.mFnObject.mPrev;
  v25 = v26.mFnObject.mNext;
  v26.mFnObject.mPrev->mNext = v26.mFnObject.mNext;
  v25->mPrev = v24;
  v26.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
  v26.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26;
  UFG::qString::~qString(&result);
}

