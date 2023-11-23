// File Line: 15
// RVA: 0x1585B60
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::GamesliceNavigatorWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::GamesliceNavigatorWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::GamesliceNavigatorWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 25
// RVA: 0x69CA10
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GamesliceNavigatorWindow(
        UFG::Editor::GamesliceNavigatorWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::GamesliceNavigatorWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPos = 0i64;
  this->mTree_Selection.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mTree_Selection.mData.p = 0i64;
  *(_QWORD *)&this->mTree_Selection.mData.size = 0i64;
  this->mTree_ExpandedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mTree_ExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mTree_ExpandedItems.mData.size = 0i64;
  this->mSortedContainerSlices.p = 0i64;
  *(_QWORD *)&this->mSortedContainerSlices.size = 0i64;
  UFG::qString::Set(&this->mTitle, "Gameslice Navigator");
  this->mRect.mW = 300;
  this->mRect.mH = 600;
  UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(this);
}

// File Line: 34
// RVA: 0x69C940
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GamesliceNavigatorWindow(
        UFG::Editor::GamesliceNavigatorWindow *this,
        MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPos = 0i64;
  this->mTree_Selection.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mTree_Selection.mData.p = 0i64;
  *(_QWORD *)&this->mTree_Selection.mData.size = 0i64;
  this->mTree_ExpandedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mTree_ExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mTree_ExpandedItems.mData.size = 0i64;
  this->mSortedContainerSlices.p = 0i64;
  *(_QWORD *)&this->mSortedContainerSlices.size = 0i64;
  UFG::qString::Set(&this->mTitle, "Gameslice Navigator");
  this->mRect.mW = 300;
  this->mRect.mH = 600;
  UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(this);
}

// File Line: 41
// RVA: 0x69E1A0
void __fastcall UFG::Editor::GamesliceNavigatorWindow::UpdateUI(
        UFG::Editor::GamesliceNavigatorWindow *this,
        UFG::DUIContext *dui)
{
  UFG::ProgressionTracker *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  unsigned __int64 name; // [rsp+40h] [rbp+18h] BYREF

  UFG::DUIContext::BeginGridLayout(dui, 1, 3, LayoutFlag_FillLastCell);
  UFG::DUIContext::BeginLayoutHorizontal(dui);
  if ( UFG::DUIContext::Button(dui, "Launch", 0x10u)
    && this->mTree_Selection.vfptr->Count(&this->mTree_Selection) == 1
    && (name = this->mTree_Selection.vfptr->GetAt(&this->mTree_Selection, 0), name > 0xC) )
  {
    v4 = UFG::ProgressionTracker::Instance();
    v5 = UFG::ProgressionTracker::Find(v4, (UFG::qSymbol *)&name, 0);
    UFG::Editor::GamesliceNavigatorWindow::LaunchGameSlice(this, (UFG::GameSlice *)v5, dui);
  }
  else
  {
    UFG::DUIContext::Empty(dui);
    UFG::DUIContext::EndLayoutHorizontal(dui);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
    UFG::DUIContext::BeginVerticalLayout(dui);
    UFG::DUIContext::BeginTreeView(
      dui,
      (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mTree_Selection,
      (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mTree_ExpandedItems,
      0);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 11, "Missions", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 5, "Events", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 6, "Favours", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 7, "Jobs", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 8, "Races", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 3, "Scenarios", dui);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(this, 4, "Sprinkles", dui);
    UFG::DUIContext::EndTreeView(dui);
    UFG::DUIContext::EndLayoutHorizontal(dui);
    UFG::DUIContext::EndScrollView(dui);
    UFG::DUIContext::EndLayoutHorizontal(dui);
  }
}

// File Line: 96
// RVA: 0x69D140
void __fastcall UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(
        UFG::Editor::GamesliceNavigatorWindow *this,
        int type,
        const char *typeName,
        UFG::DUIContext *dui)
{
  unsigned int i; // edi
  UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo *v8; // rbx
  char v9; // bl
  UFG::ProgressionTracker *v10; // rax
  UFG::qBaseTreeRB *ContainerSlice; // r14
  UFG::ProgressionTracker *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-50h] BYREF
  unsigned __int64 id; // [rsp+50h] [rbp-28h]
  int index; // [rsp+58h] [rbp-20h]

  if ( (unsigned __int8)UFG::DUIContext::TreeViewItem(dui, typeName, type, 1) )
  {
    UFG::DUIContext::BeginIndent(dui);
    for ( i = 0; i < this->mSortedContainerSlices.size; ++i )
    {
      v8 = &this->mSortedContainerSlices.p[i];
      UFG::qString::qString(&v13, &v8->title);
      id = *(_QWORD *)&v8->uid;
      index = v8->index;
      if ( HIDWORD(id) == type )
      {
        v9 = UFG::DUIContext::TreeViewItem(dui, v13.mData, (unsigned int)id, 1);
        v10 = UFG::ProgressionTracker::Instance();
        ContainerSlice = UFG::ProgressionTracker::GetContainerSlice(v10, index);
        if ( dui->mDoubleClicked )
        {
          v12 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::ForceSliceChange(v12, (UFG::GameSlice *)ContainerSlice, 1);
          UFG::DUIManager::DestroyWindow(dui->mManager, this);
          UFG::qString::~qString(&v13);
          return;
        }
        if ( v9 )
        {
          UFG::DUIContext::BeginIndent(dui);
          UFG::Editor::GamesliceNavigatorWindow::DisplayChildGameSlices(this, (UFG::GameSlice *)ContainerSlice, dui);
          UFG::DUIContext::EndIndent(dui);
        }
      }
      UFG::qString::~qString(&v13);
    }
    UFG::DUIContext::EndIndent(dui);
  }
}

// File Line: 134
// RVA: 0x69D090
void __fastcall UFG::Editor::GamesliceNavigatorWindow::DisplayChildGameSlices(
        UFG::Editor::GamesliceNavigatorWindow *this,
        UFG::GameSlice *pContainer,
        UFG::DUIContext *dui)
{
  int v6; // ebx
  int NumChildren; // edi
  UFG::GameSlice *Child; // rsi
  const char *v9; // rax
  UFG::ProgressionTracker *v10; // rax

  v6 = 0;
  NumChildren = UFG::GameSlice::GetNumChildren(pContainer);
  if ( NumChildren > 0 )
  {
    while ( 1 )
    {
      Child = UFG::GameSlice::GetChild(pContainer, v6);
      v9 = UFG::UI::LocalizeText(Child->mTitle.mText);
      UFG::DUIContext::TreeViewItem(dui, v9, Child->mNode.mUID, 0);
      if ( dui->mDoubleClicked )
        break;
      if ( ++v6 >= NumChildren )
        return;
    }
    v10 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ForceSliceChange(v10, Child, 1);
    UFG::DUIManager::DestroyWindow(dui->mManager, this);
  }
}

// File Line: 152
// RVA: 0x69D800
void __fastcall UFG::Editor::GamesliceNavigatorWindow::LaunchGameSlice(
        UFG::Editor::GamesliceNavigatorWindow *this,
        UFG::GameSlice *pGameslice,
        UFG::DUIContext *dui)
{
  UFG::ProgressionTracker *v6; // rax

  v6 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ForceSliceChange(v6, pGameslice, 1);
  UFG::DUIManager::DestroyWindow(dui->mManager, this);
}

// File Line: 159
// RVA: 0x69DCD0
bool __fastcall UFG::Editor::SortByName(UFG::qString *a, UFG::qString *b)
{
  return (int)UFG::qStringCompareInsensitive(a->mData, b->mData, -1) < 0;
}

// File Line: 164
// RVA: 0x69D410
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(
        UFG::Editor::GamesliceNavigatorWindow *this)
{
  UFG::qArray<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,0> *p_mSortedContainerSlices; // rsi
  UFG::ProgressionTracker *v2; // rax
  int NumContainerSlices; // r14d
  int i; // ebp
  UFG::ProgressionTracker *v5; // rax
  UFG::qBaseTreeRB *ContainerSlice; // rdi
  const char *v7; // rbx
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  __int64 size; // rdi
  unsigned int v11; // ebx
  unsigned int capacity; // edx
  unsigned int v13; // edx
  __int64 v14; // rbx
  UFG::qString v15; // [rsp+30h] [rbp-A8h] BYREF
  unsigned int mUID; // [rsp+58h] [rbp-80h]
  int v17; // [rsp+5Ch] [rbp-7Ch]
  int v18; // [rsp+60h] [rbp-78h]
  __int64 v19; // [rsp+68h] [rbp-70h]
  UFG::qString v20; // [rsp+70h] [rbp-68h] BYREF
  UFG::qString result; // [rsp+98h] [rbp-40h] BYREF

  v19 = -2i64;
  p_mSortedContainerSlices = &this->mSortedContainerSlices;
  this->mSortedContainerSlices.size = 0;
  v2 = UFG::ProgressionTracker::Instance();
  NumContainerSlices = UFG::ProgressionTracker::GetNumContainerSlices(v2);
  for ( i = 0; i < NumContainerSlices; ++i )
  {
    v5 = UFG::ProgressionTracker::Instance();
    ContainerSlice = UFG::ProgressionTracker::GetContainerSlice(v5, i);
    v7 = UFG::UI::LocalizeText((const char *)ContainerSlice->mNULL.mChild[0]);
    UFG::qString::qString(&v15);
    v8 = UFG::qTrim(&result, v7, 30);
    v9 = UFG::qString::FormatEx(&v20, v8->mData);
    UFG::qString::Set(&v15, v9->mData, v9->mLength, 0i64, 0);
    UFG::qString::~qString(&v20);
    UFG::qString::~qString(&result);
    mUID = ContainerSlice->mRoot.mUID;
    v17 = HIDWORD(ContainerSlice[3].mNULL.mChild[1]);
    v18 = i;
    size = p_mSortedContainerSlices->size;
    v11 = size + 1;
    capacity = p_mSortedContainerSlices->capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v13 = 2 * capacity;
      else
        v13 = 1;
      for ( ; v13 < v11; v13 *= 2 )
        ;
      if ( v13 - v11 > 0x10000 )
        v13 = size + 65537;
      UFG::qArray<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,0>::Reallocate(
        p_mSortedContainerSlices,
        v13,
        "qArray.Add");
    }
    p_mSortedContainerSlices->size = v11;
    v14 = (__int64)&p_mSortedContainerSlices->p[size];
    UFG::qString::Set((UFG::qString *)v14, v15.mData, v15.mLength, 0i64, 0);
    *(_DWORD *)(v14 + 40) = mUID;
    *(_DWORD *)(v14 + 44) = v17;
    *(_DWORD *)(v14 + 48) = v18;
    UFG::qString::~qString(&v15);
  }
  UFG::qQuickSortImpl<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,bool (*)(UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo const &,UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo const &)>(
    p_mSortedContainerSlices->p,
    &p_mSortedContainerSlices->p[(int)p_mSortedContainerSlices->size - 1],
    (bool (__fastcall *)(UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo *, UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo *))UFG::Editor::SortByName);
}

