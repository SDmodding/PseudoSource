// File Line: 15
// RVA: 0x1585B60
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::GamesliceNavigatorWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::GamesliceNavigatorWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::GamesliceNavigatorWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 25
// RVA: 0x69CA10
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GamesliceNavigatorWindow(UFG::Editor::GamesliceNavigatorWindow *this)
{
  UFG::Editor::GamesliceNavigatorWindow *v1; // rbx
  UFG::DUIIntArray *v2; // [rsp+48h] [rbp+10h]
  UFG::DUIIntArray *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::GamesliceNavigatorWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mScrollPos = 0i64;
  v2 = &v1->mTree_Selection;
  v2->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  v3 = &v1->mTree_ExpandedItems;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v1->mSortedContainerSlices.p = 0i64;
  *(_QWORD *)&v1->mSortedContainerSlices.size = 0i64;
  UFG::qString::Set(&v1->mTitle, "Gameslice Navigator");
  v1->mRect.mW = 300;
  v1->mRect.mH = 600;
  UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(v1);
}

// File Line: 34
// RVA: 0x69C940
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GamesliceNavigatorWindow(UFG::Editor::GamesliceNavigatorWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::GamesliceNavigatorWindow *v2; // rbx
  UFG::DUIIntArray *v3; // [rsp+50h] [rbp+18h]
  UFG::DUIIntArray *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GamesliceNavigatorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GamesliceNavigatorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mScrollPos = 0i64;
  v3 = &v2->mTree_Selection;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v4 = &v2->mTree_ExpandedItems;
  v4->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v4->mData.p = 0i64;
  *(_QWORD *)&v4->mData.size = 0i64;
  v2->mSortedContainerSlices.p = 0i64;
  *(_QWORD *)&v2->mSortedContainerSlices.size = 0i64;
  UFG::qString::Set(&v2->mTitle, "Gameslice Navigator");
  v2->mRect.mW = 300;
  v2->mRect.mH = 600;
  UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(v2);
}

// File Line: 41
// RVA: 0x69E1A0
void __fastcall UFG::Editor::GamesliceNavigatorWindow::UpdateUI(UFG::Editor::GamesliceNavigatorWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::Editor::GamesliceNavigatorWindow *v3; // rsi
  UFG::ProgressionTracker *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  unsigned __int64 name; // [rsp+40h] [rbp+18h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 1, 3, 3);
  UFG::DUIContext::BeginLayoutHorizontal(v2);
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Launch", 0x10u)
    && v3->mTree_Selection.vfptr->Count((UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr) == 1
    && (name = v3->mTree_Selection.vfptr->GetAt((UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr, 0), name > 0xC) )
  {
    v4 = UFG::ProgressionTracker::Instance();
    v5 = UFG::ProgressionTracker::Find(v4, (UFG::qSymbol *)&name, 0);
    UFG::Editor::GamesliceNavigatorWindow::LaunchGameSlice(v3, (UFG::GameSlice *)v5, v2);
  }
  else
  {
    UFG::DUIContext::Empty(v2);
    UFG::DUIContext::EndLayoutHorizontal(v2);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPos);
    UFG::DUIContext::BeginVerticalLayout(v2);
    UFG::DUIContext::BeginTreeView(
      v2,
      (UFG::IDUICollectionView *)&v3->mTree_Selection.vfptr,
      (UFG::IDUICollectionView *)&v3->mTree_ExpandedItems.vfptr,
      0);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 11, "Missions", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 5, "Events", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 6, "Favours", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 7, "Jobs", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 8, "Races", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 3, "Scenarios", v2);
    UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(v3, 4, "Sprinkles", v2);
    UFG::DUIContext::EndTreeView(v2);
    UFG::DUIContext::EndLayoutHorizontal(v2);
    UFG::DUIContext::EndScrollView(v2);
    UFG::DUIContext::EndLayoutHorizontal(v2);
  }
}

// File Line: 96
// RVA: 0x69D140
void __fastcall UFG::Editor::GamesliceNavigatorWindow::DisplayContainerGameSlices(UFG::Editor::GamesliceNavigatorWindow *this, int type, const char *typeName, UFG::DUIContext *dui)
{
  UFG::DUIContext *v4; // rsi
  int v5; // er15
  UFG::Editor::GamesliceNavigatorWindow *v6; // rbp
  unsigned int v7; // edi
  signed __int64 v8; // rbx
  char v9; // bl
  UFG::ProgressionTracker *v10; // rax
  UFG::qBaseTreeRB *v11; // r14
  UFG::ProgressionTracker *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-50h]
  unsigned __int64 id; // [rsp+50h] [rbp-28h]
  int index; // [rsp+58h] [rbp-20h]

  v4 = dui;
  v5 = type;
  v6 = this;
  if ( (unsigned __int8)UFG::DUIContext::TreeViewItem(dui, typeName, type, 1) )
  {
    UFG::DUIContext::BeginIndent(v4);
    v7 = 0;
    if ( v6->mSortedContainerSlices.size )
    {
      do
      {
        v8 = (signed __int64)&v6->mSortedContainerSlices.p[v7];
        UFG::qString::qString(&v13, (UFG::qString *)v8);
        id = *(_QWORD *)(v8 + 40);
        index = *(_DWORD *)(v8 + 48);
        if ( HIDWORD(id) == v5 )
        {
          v9 = UFG::DUIContext::TreeViewItem(v4, v13.mData, (unsigned int)id, 1);
          v10 = UFG::ProgressionTracker::Instance();
          v11 = UFG::ProgressionTracker::GetContainerSlice(v10, index);
          if ( v4->mDoubleClicked )
          {
            v12 = UFG::ProgressionTracker::Instance();
            UFG::ProgressionTracker::ForceSliceChange(v12, (UFG::GameSlice *)v11, 1);
            UFG::DUIManager::DestroyWindow(v4->mManager, (UFG::DUIWindow *)&v6->vfptr);
            UFG::qString::~qString(&v13);
            return;
          }
          if ( v9 )
          {
            UFG::DUIContext::BeginIndent(v4);
            UFG::Editor::GamesliceNavigatorWindow::DisplayChildGameSlices(v6, (UFG::GameSlice *)v11, v4);
            UFG::DUIContext::EndIndent(v4);
          }
        }
        UFG::qString::~qString(&v13);
        ++v7;
      }
      while ( v7 < v6->mSortedContainerSlices.size );
    }
    UFG::DUIContext::EndIndent(v4);
  }
}

// File Line: 134
// RVA: 0x69D090
void __fastcall UFG::Editor::GamesliceNavigatorWindow::DisplayChildGameSlices(UFG::Editor::GamesliceNavigatorWindow *this, UFG::GameSlice *pContainer, UFG::DUIContext *dui)
{
  UFG::Editor::GamesliceNavigatorWindow *v3; // r15
  UFG::DUIContext *v4; // rbp
  UFG::GameSlice *v5; // r14
  int v6; // ebx
  int v7; // edi
  UFG::GameSlice *v8; // rax
  UFG::GameSlice *v9; // rsi
  const char *v10; // rax
  UFG::ProgressionTracker *v11; // rax

  v3 = this;
  v4 = dui;
  v5 = pContainer;
  v6 = 0;
  v7 = UFG::GameSlice::GetNumChildren(pContainer);
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      v8 = UFG::GameSlice::GetChild(v5, v6);
      v9 = v8;
      v10 = UFG::UI::LocalizeText(v8->mTitle.mText);
      UFG::DUIContext::TreeViewItem(v4, v10, v9->mNode.mUID, 0);
      if ( v4->mDoubleClicked )
        break;
      if ( ++v6 >= v7 )
        return;
    }
    v11 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ForceSliceChange(v11, v9, 1);
    UFG::DUIManager::DestroyWindow(v4->mManager, (UFG::DUIWindow *)&v3->vfptr);
  }
}

// File Line: 152
// RVA: 0x69D800
void __fastcall UFG::Editor::GamesliceNavigatorWindow::LaunchGameSlice(UFG::Editor::GamesliceNavigatorWindow *this, UFG::GameSlice *pGameslice, UFG::DUIContext *dui)
{
  UFG::DUIContext *v3; // rsi
  UFG::GameSlice *v4; // rbx
  UFG::Editor::GamesliceNavigatorWindow *v5; // rdi
  UFG::ProgressionTracker *v6; // rax

  v3 = dui;
  v4 = pGameslice;
  v5 = this;
  v6 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ForceSliceChange(v6, v4, 1);
  UFG::DUIManager::DestroyWindow(v3->mManager, (UFG::DUIWindow *)&v5->vfptr);
}

// File Line: 159
// RVA: 0x69DCD0
bool __fastcall UFG::Editor::SortByName(UFG::qString *a, UFG::qString *b)
{
  return (signed int)UFG::qStringCompareInsensitive(a->mData, b->mData, -1) < 0;
}

// File Line: 164
// RVA: 0x69D410
void __fastcall UFG::Editor::GamesliceNavigatorWindow::GenerateGameSliceList(UFG::Editor::GamesliceNavigatorWindow *this)
{
  UFG::qArray<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,0> *v1; // rsi
  UFG::ProgressionTracker *v2; // rax
  int v3; // er14
  int i; // ebp
  UFG::ProgressionTracker *v5; // rax
  UFG::qBaseTreeRB *v6; // rdi
  const char *v7; // rbx
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  __int64 v10; // rdi
  unsigned int v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // edx
  signed __int64 v14; // rbx
  UFG::qString v15; // [rsp+30h] [rbp-A8h]
  unsigned int v16; // [rsp+58h] [rbp-80h]
  int v17; // [rsp+5Ch] [rbp-7Ch]
  int v18; // [rsp+60h] [rbp-78h]
  __int64 v19; // [rsp+68h] [rbp-70h]
  UFG::qString v20; // [rsp+70h] [rbp-68h]
  UFG::qString result; // [rsp+98h] [rbp-40h]

  v19 = -2i64;
  v1 = &this->mSortedContainerSlices;
  this->mSortedContainerSlices.size = 0;
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::ProgressionTracker::GetNumContainerSlices(v2);
  for ( i = 0; i < v3; ++i )
  {
    v5 = UFG::ProgressionTracker::Instance();
    v6 = UFG::ProgressionTracker::GetContainerSlice(v5, i);
    v7 = UFG::UI::LocalizeText((const char *)v6->mNULL.mChild[0]);
    UFG::qString::qString(&v15);
    v8 = UFG::qTrim(&result, v7, 30);
    v9 = UFG::qString::FormatEx(&v20, v8->mData);
    UFG::qString::Set(&v15, v9->mData, v9->mLength, 0i64, 0);
    UFG::qString::~qString(&v20);
    UFG::qString::~qString(&result);
    v16 = v6->mRoot.mUID;
    v17 = HIDWORD(v6[3].mNULL.mChild[1]);
    v18 = i;
    v10 = v1->size;
    v11 = v10 + 1;
    v12 = v1->capacity;
    if ( (signed int)v10 + 1 > v12 )
    {
      if ( v12 )
        v13 = 2 * v12;
      else
        v13 = 1;
      for ( ; v13 < v11; v13 *= 2 )
        ;
      if ( v13 - v11 > 0x10000 )
        v13 = v10 + 65537;
      UFG::qArray<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,0>::Reallocate(v1, v13, "qArray.Add");
    }
    v1->size = v11;
    v14 = (signed __int64)&v1->p[v10];
    UFG::qString::Set((UFG::qString *)v14, v15.mData, v15.mLength, 0i64, 0);
    *(_DWORD *)(v14 + 40) = v16;
    *(_DWORD *)(v14 + 44) = v17;
    *(_DWORD *)(v14 + 48) = v18;
    UFG::qString::~qString(&v15);
  }
  UFG::qQuickSortImpl<UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo,bool (*)(UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo const &,UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo const &)>(
    v1->p,
    &v1->p[(signed int)v1->size - 1],
    (bool (__fastcall *)(UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo *, UFG::Editor::GamesliceNavigatorWindow::GameSliceInfo *))UFG::Editor::SortByName);
}

