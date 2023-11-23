// File Line: 23
// RVA: 0x146C7A0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::AssetBrowser_UFG::DUIWindow_::sFactoryOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::AssetBrowser", 0xFFFFFFFFFFFFFFFFui64);
  UFG::FactoryOperation::FactoryOperation(
    &UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::sFactoryOp,
    v0,
    UFG::OnCreateClass<UFG::Editor::AssetBrowser>,
    (void (__fastcall *)(char *))UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>);
}

// File Line: 28
// RVA: 0x146D720
__int64 dynamic_initializer_for__UFG::Editor::AssetBrowser::sSelectedAssets__()
{
  UFG::Editor::AssetBrowser::sSelectedAssets.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Editor::AssetBrowser::sSelectedAssets__);
}

// File Line: 37
// RVA: 0x201090
void __fastcall UFG::Editor::AssetBrowser::AssetBrowser(UFG::Editor::AssetBrowser *this)
{
  unsigned int v2; // ebx

  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::AssetBrowser", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mTypesFilterScrollPos = 0i64;
  this->mTagFilterScrollPos = 0i64;
  this->mSelectedTypes.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedTypes.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTypes.mData.size = 0i64;
  this->mSelectedTags.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedTags.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTags.mData.size = 0i64;
  *(_QWORD *)&this->mSearchText.mText.mData.mNumItems = 0i64;
  this->mSearchText.mText.mData.mItems = 0i64;
  v2 = UFG::qStringLength(&customCaption) + 1;
  UFG::qReflectArray<char>::Resize(&this->mSearchText.mText, v2, "qReflectString::Set()");
  UFG::qMemCopy(this->mSearchText.mText.mData.mItems, &customCaption, v2);
  this->mRefreshFiltered = 1;
  this->mFilteredAssets.p = 0i64;
  *(_QWORD *)&this->mFilteredAssets.size = 0i64;
  this->mAssetListScrollPos = 0i64;
  this->mMetrics = 0i64;
  UFG::qString::Set(&this->mTitle, "Asset Browser");
  this->mRect.mW = 400;
  this->mRect.mH = 600;
  *(_QWORD *)this->mAssetGridWidths = 0x100000001i64;
  this->mHorizontalSplitHeights[0] = 1;
  this->mHorizontalSplitHeights[1] = 2;
  *(_QWORD *)this->mHorizontalSplitWidths = 0x100000001i64;
  this->mAssetGridWidths[0] = this->mRect.mW - 60;
  this->mAssetGridWidths[1] = 30;
  this->mHorizontalSplitHeights[0] = (int)(float)((float)this->mRect.mH * 0.34999999);
  this->mHorizontalSplitHeights[1] = (int)(float)((float)this->mRect.mH * 0.64999998);
}

// File Line: 63
// RVA: 0x213850
bool __fastcall UFG::Editor::SortAssetsByName(unsigned __int64 *a, unsigned __int64 *b)
{
  UFG::AssetHive *v4; // rax
  UFG::qTree64Base *v5; // rbx
  UFG::AssetHive *v6; // rax
  UFG::qTree64Base *v7; // rax

  v4 = UFG::AssetHive::Instance();
  v5 = UFG::qTree64Base::Get(&v4->mAssets.mTree, *a);
  v6 = UFG::AssetHive::Instance();
  v7 = UFG::qTree64Base::Get(&v6->mAssets.mTree, *b);
  return (int)UFG::qStringCompare((const char *)v5[2].mHead.mChildren[1], (const char *)v7[2].mHead.mChildren[1], -1) < 0;
}

// File Line: 70
// RVA: 0x2138B0
bool __fastcall UFG::Editor::SortAssetsByType(unsigned __int64 *a, unsigned __int64 *b)
{
  UFG::AssetHive *v4; // rax
  UFG::qTree64Base *v5; // rbx
  UFG::AssetHive *v6; // rax
  UFG::qTree64Base *v7; // rax

  v4 = UFG::AssetHive::Instance();
  v5 = UFG::qTree64Base::Get(&v4->mAssets.mTree, *a);
  v6 = UFG::AssetHive::Instance();
  v7 = UFG::qTree64Base::Get(&v6->mAssets.mTree, *b);
  return (int)UFG::qStringCompare((const char *)v5[3].mCount, (const char *)v7[3].mCount, -1) < 0;
}

// File Line: 84
// RVA: 0x217A30
void __fastcall UFG::Editor::AssetBrowser::UpdateUI(UFG::Editor::AssetBrowser *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r15
  UFG::AssetHive *v4; // rax
  UFG::qReflectString *p_mSearchText; // r12
  char *mData; // rdi
  unsigned int v7; // ebx
  UFG::DUIIntArray *p_mSelectedTypes; // r13
  UFG::AssetHive *v9; // rax
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rdi
  UFG::AssetHive *v12; // rax
  UFG::qTree64Base *Next; // rax
  UFG::DUIIntArray *p_mSelectedTags; // rsi
  UFG::AssetHive *v15; // rax
  UFG::qTree64Base *v16; // rbx
  UFG::AssetHive *v17; // rax
  UFG::AssetHive *v18; // rax
  UFG::qTree64Base *v19; // rbx
  unsigned int mNumItems; // ecx
  BOOL v21; // eax
  char *mItems; // r8
  const char *v23; // rcx
  char v24; // al
  bool v25; // zf
  unsigned __int64 v26; // rdi
  unsigned int v27; // ebx
  bool v28; // r12
  unsigned int v29; // r15d
  __int64 v30; // rbx
  __int64 v31; // rdi
  __int64 v32; // rsi
  __int64 v33; // rbx
  unsigned __int64 v34; // r12
  __int64 size; // r15
  unsigned int v36; // edi
  unsigned int capacity; // ebx
  unsigned int v38; // ebx
  unsigned __int64 v39; // rax
  UFG::allocator::free_link *v40; // rax
  unsigned __int64 *v41; // rsi
  __int64 i; // r9
  UFG::AssetHive *v43; // rax
  int v44; // ebx
  bool (__fastcall *v45)(unsigned __int64 *, unsigned __int64 *); // r8
  unsigned int j; // edi
  unsigned __int64 v47; // rbx
  UFG::AssetHive *v48; // rax
  UFG::qTree64Base *v49; // rsi
  bool v50; // al
  unsigned __int64 v51; // rax
  UFG::HiveAsset **v52; // rbx
  UFG::AssetHive *v53; // rax
  UFG::qString *v54; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mNext; // rdi
  UFG::allocator::free_link *v56; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mPrev; // rax
  UFG::allocator::free_link *v58; // rax
  UFG::Event *v59; // rdx
  UFG::allocator::free_link *v60; // rax
  unsigned int k; // r15d
  unsigned __int64 v62; // rbx
  UFG::qSymbol *v63; // rsi
  unsigned int v64; // ebx
  unsigned int v65; // edx
  __int64 v66; // rdx
  __int64 v67; // r8
  UFG::Editor::SmartHandleObject *mPtr; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v69; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v70; // rax
  __int64 mNext_low; // rsi
  unsigned int v72; // ebx
  unsigned int mNext_high; // edx
  unsigned int v74; // edx
  __int64 v75; // rbx
  UFG::Editor::SmartHandleObject *v76; // rcx
  __int64 *p_mSmartHandleList; // rcx
  __int64 v78; // rax
  UFG::allocator::free_link *v79; // rax
  UFG::Event *v80; // rdx
  UFG::allocator::free_link *v81; // rax
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v83; // rbx
  UFG::Editor::SmartHandleObject *v84; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v85; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v86; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v87; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v88; // rax
  bool v89; // [rsp+50h] [rbp-B0h]
  UFG::qArray<UFG::HiveAsset *,0> cur_node; // [rsp+58h] [rbp-A8h] BYREF
  UFG::Editor::DAGPath item; // [rsp+70h] [rbp-90h] BYREF
  UFG::qString current_value; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v93; // [rsp+F8h] [rbp-8h]
  UFG::qSymbol result; // [rsp+150h] [rbp+50h] BYREF
  UFG::DUIContext *out_is_selected; // [rsp+158h] [rbp+58h] BYREF
  UFG::Editor::DAGPath *p_item; // [rsp+160h] [rbp+60h]
  char v97; // [rsp+168h] [rbp+68h]

  out_is_selected = dui;
  v93 = -2i64;
  v2 = dui;
  if ( !UFG::AssetHive::Instance()->mAssets.mTree.mCount )
  {
    v4 = UFG::AssetHive::Instance();
    UFG::AssetHive::IndexAssets(v4);
  }
  this->mMainStatusStripHeights[0] = this->mClientRect.mH - v2->mTheme.mRowHeight;
  this->mMainStatusStripHeights[1] = v2->mTheme.mRowHeight;
  LOBYTE(p_item) = 0;
  v97 = 0;
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 0i64, this->mMainStatusStripHeights, LayoutFlag_FillLastCol);
  UFG::DUIContext::BeginGridLayout(
    v2,
    1,
    2,
    0i64,
    this->mHorizontalSplitHeights,
    LayoutFlag_GridSplitting|LayoutFlag_DistributeCells);
  UFG::DUIContext::BeginGridLayout(v2, 1, 3, LayoutFlag_FillLastCell);
  UFG::DUIContext::Header(v2, "Filters", 0i64, 0i64);
  p_mSearchText = &this->mSearchText;
  if ( this->mSearchText.mText.mData.mNumItems )
    UFG::qString::qString(&current_value, p_mSearchText->mText.mData.mItems);
  else
    UFG::qString::qString(&current_value, &customCaption);
  if ( (unsigned __int8)UFG::DUIContext::TextBox(v2, &current_value, "Search...", 1, 0i64, -1) )
  {
    mData = current_value.mData;
    v7 = UFG::qStringLength(current_value.mData) + 1;
    UFG::qReflectArray<char>::Resize(&this->mSearchText.mText, v7, "qReflectString::Set()");
    UFG::qMemCopy(p_mSearchText->mText.mData.mItems, mData, v7);
    this->mRefreshFiltered = 1;
  }
  UFG::DUIContext::BeginGridLayout(
    v2,
    2,
    1,
    this->mHorizontalSplitWidths,
    0i64,
    LayoutFlag_GridSplitting|LayoutFlag_DistributeCells);
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, LayoutFlag_FillLastCell);
  UFG::DUIContext::Header(v2, "Types", 0i64, 0i64);
  p_mSelectedTypes = &this->mSelectedTypes;
  UFG::DUIContext::BeginListView(
    v2,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mSelectedTypes,
    &this->mTypesFilterScrollPos,
    1);
  v9 = UFG::AssetHive::Instance();
  Head = UFG::qTree64Base::GetHead(&v9->mFactories.mTree);
  p_mCount = &Head[-1].mCount;
  if ( !Head )
    p_mCount = 0i64;
  UFG::AssetHive::Instance();
  while ( p_mCount )
  {
    this->mRefreshFiltered |= UFG::DUIContext::ListViewItem(v2, (char *)p_mCount[10], p_mCount[1], 0i64);
    v12 = UFG::AssetHive::Instance();
    Next = UFG::qTree64Base::GetNext(&v12->mFactories.mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
    p_mCount = &Next[-1].mCount;
    if ( !Next )
      p_mCount = 0i64;
    UFG::AssetHive::Instance();
  }
  UFG::DUIContext::EndListView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, LayoutFlag_FillLastCell);
  UFG::DUIContext::Header(v2, "Tags", 0i64, 0i64);
  p_mSelectedTags = &this->mSelectedTags;
  UFG::DUIContext::BeginListView(
    v2,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mSelectedTags,
    &this->mTagFilterScrollPos,
    1);
  v15 = UFG::AssetHive::Instance();
  v16 = UFG::qTree64Base::GetHead(&v15->mTags.mTree);
  UFG::AssetHive::Instance();
  while ( v16 )
  {
    this->mRefreshFiltered |= UFG::DUIContext::ListViewItem(
                                v2,
                                (char *)v16[1].mHead.mChildren[0],
                                v16->mHead.mUID,
                                0i64);
    v17 = UFG::AssetHive::Instance();
    v16 = UFG::qTree64Base::GetNext(&v17->mTags.mTree, &v16->mHead);
    UFG::AssetHive::Instance();
  }
  UFG::DUIContext::EndListView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::qString::~qString(&current_value);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( this->mRefreshFiltered )
  {
    LOBYTE(p_item) = 1;
    UFG::Editor::AssetBrowser::sSelectedAssets.mData.size = 0;
    this->mFilteredAssets.size = 0;
    v18 = UFG::AssetHive::Instance();
    v19 = UFG::qTree64Base::GetHead(&v18->mAssets.mTree);
    *(_QWORD *)&cur_node.size = v19;
    UFG::AssetHive::Instance();
    if ( v19 )
    {
      do
      {
        mNumItems = p_mSearchText->mText.mData.mNumItems;
        v21 = !mNumItems || mNumItems == 1 && !*p_mSearchText->mText.mData.mItems;
        LOBYTE(result.mUID) = v21;
        if ( mNumItems && (mNumItems != 1 || *p_mSearchText->mText.mData.mItems) )
        {
          mItems = p_mSearchText->mText.mData.mItems;
          if ( p_mSearchText->mText.mData.mItems && (v23 = p_mSearchText->mText.mData.mItems, (v24 = *mItems) != 0) )
          {
            while ( v24 != 42 && v24 != 63 )
            {
              v24 = *++v23;
              if ( !*v23 )
                goto LABEL_33;
            }
            v25 = (unsigned int)UFG::qWildcardMatchInsensitive(mItems, (char *)v19[2].mHead.mChildren[1]) == 0;
          }
          else
          {
LABEL_33:
            v25 = UFG::qStringFindInsensitive((const char *)v19[2].mHead.mChildren[1], mItems) == 0i64;
          }
          LOBYTE(result.mUID) = !v25;
        }
        v89 = p_mSelectedTypes->vfptr->Count(&this->mSelectedTypes) == 0;
        v26 = UFG::qStringHash64((const char *)v19[3].mCount, 0xFFFFFFFFFFFFFFFFui64);
        v27 = 0;
        if ( p_mSelectedTypes->vfptr->Count(&this->mSelectedTypes) )
        {
          while ( p_mSelectedTypes->vfptr->GetAt(&this->mSelectedTypes, v27) != v26 )
          {
            if ( ++v27 >= p_mSelectedTypes->vfptr->Count(&this->mSelectedTypes) )
              goto LABEL_40;
          }
          v89 = 1;
        }
LABEL_40:
        v28 = p_mSelectedTags->vfptr->Count(p_mSelectedTags) == 0;
        v29 = 0;
        if ( p_mSelectedTags->vfptr->Count(p_mSelectedTags) )
        {
          v30 = *(_QWORD *)&cur_node.size;
          v31 = *(_QWORD *)&cur_node.size + 272i64;
          while ( 1 )
          {
            v32 = p_mSelectedTags->vfptr->GetAt(p_mSelectedTags, v29);
            v33 = *(_QWORD *)(v30 + 280);
            if ( v33 != v31 )
              break;
LABEL_45:
            ++v29;
            p_mSelectedTags = &this->mSelectedTags;
            if ( v29 >= this->mSelectedTags.vfptr->Count(&this->mSelectedTags) )
              goto LABEL_48;
            v30 = *(_QWORD *)&cur_node.size;
          }
          while ( v32 != UFG::qStringHash64(*(const char **)(v33 + 24), 0xFFFFFFFFFFFFFFFFui64) )
          {
            v33 = *(_QWORD *)(v33 + 8);
            if ( v33 == v31 )
              goto LABEL_45;
          }
          v28 = 1;
        }
LABEL_48:
        if ( ((v89 && v28) & result.mUID) != 0 )
        {
          v34 = *(_QWORD *)(*(_QWORD *)&cur_node.size + 96i64);
          size = this->mFilteredAssets.size;
          v36 = size + 1;
          capacity = this->mFilteredAssets.capacity;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v38 = 2 * capacity;
            else
              v38 = 1;
            for ( ; v38 < v36; v38 *= 2 )
              ;
            if ( v38 <= 2 )
              v38 = 2;
            if ( v38 - v36 > 0x10000 )
              v38 = size + 65537;
            if ( v38 != (_DWORD)size )
            {
              v39 = 8i64 * v38;
              if ( !is_mul_ok(v38, 8ui64) )
                v39 = -1i64;
              v40 = UFG::qMalloc(v39, "qArray.Add", 0i64);
              v41 = (unsigned __int64 *)v40;
              if ( this->mFilteredAssets.p )
              {
                for ( i = 0i64; (unsigned int)i < this->mFilteredAssets.size; i = (unsigned int)(i + 1) )
                  v40[i] = (UFG::allocator::free_link)this->mFilteredAssets.p[i];
                operator delete[](this->mFilteredAssets.p);
              }
              this->mFilteredAssets.p = v41;
              this->mFilteredAssets.capacity = v38;
            }
          }
          this->mFilteredAssets.size = v36;
          this->mFilteredAssets.p[size] = v34;
        }
        v43 = UFG::AssetHive::Instance();
        v19 = UFG::qTree64Base::GetNext(&v43->mAssets.mTree, *(UFG::qTree64Base::BaseNode **)&cur_node.size);
        *(_QWORD *)&cur_node.size = v19;
        UFG::AssetHive::Instance();
        p_mSelectedTags = &this->mSelectedTags;
        p_mSearchText = &this->mSearchText;
      }
      while ( v19 );
      v2 = out_is_selected;
    }
    this->mRefreshFiltered = 0;
  }
  v44 = sort_col;
  UFG::DUIContext::BeginDataGrid(
    v2,
    2,
    headings_0,
    this->mAssetGridWidths,
    (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&UFG::Editor::AssetBrowser::sSelectedAssets,
    &this->mAssetListScrollPos,
    &sort_col,
    1,
    this->mFilteredAssets.size,
    &this->mMetrics);
  LOBYTE(p_item) = (v44 != sort_col) | (unsigned __int8)p_item;
  if ( (_BYTE)p_item )
  {
    if ( sort_col )
    {
      if ( sort_col != 1 )
        goto LABEL_77;
      v45 = UFG::Editor::SortAssetsByType;
    }
    else
    {
      v45 = UFG::Editor::SortAssetsByName;
    }
    UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
      (UFG::qPropertySet **)this->mFilteredAssets.p,
      (UFG::qPropertySet **)&this->mFilteredAssets.p[(int)this->mFilteredAssets.size - 1],
      (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))v45);
  }
LABEL_77:
  for ( j = this->mMetrics.mStart; j < this->mMetrics.mEnd; ++j )
  {
    v47 = this->mFilteredAssets.p[j];
    v48 = UFG::AssetHive::Instance();
    v49 = UFG::qTree64Base::Get(&v48->mAssets.mTree, v47);
    LOBYTE(out_is_selected) = 0;
    v50 = UFG::DUIContext::BeginDataGridItem(v2, (unsigned __int64)v49, (bool *)&out_is_selected, 0i64);
    v97 |= v50;
    if ( v2->mDoubleClicked )
    {
      cur_node.p = 0i64;
      *(_QWORD *)&cur_node.size = 0i64;
      v51 = 16i64;
      if ( !is_mul_ok(2ui64, 8ui64) )
        v51 = -1i64;
      v52 = (UFG::HiveAsset **)UFG::qMalloc(v51, "qArray.Add", 0i64);
      cur_node.p = v52;
      *(_QWORD *)&cur_node.size = 0x200000001i64;
      *v52 = (UFG::HiveAsset *)v49;
      v53 = UFG::AssetHive::Instance();
      UFG::AssetHive::EditAssets(v53, &cur_node);
      operator delete[](v52);
      cur_node.p = 0i64;
      *(_QWORD *)&cur_node.size = 0i64;
    }
    UFG::DUIContext::Label(v2, (const char *)v49[2].mHead.mChildren[1]);
    UFG::DUIContext::Label(v2, (const char *)v49[3].mCount);
    UFG::DUIContext::EndDataGridItem(v2);
  }
  UFG::DUIContext::EndDataGrid(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  v54 = UFG::qString::FormatEx(&current_value, "%d Items", this->mFilteredAssets.size);
  UFG::DUIContext::Header(v2, v54->mData, 0i64, 0i64);
  UFG::qString::~qString(&current_value);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( v97 )
  {
    mNext = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
    if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
    {
LABEL_87:
      v56 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v56;
      out_is_selected = (UFG::DUIContext *)v56;
      if ( v56 )
      {
        v56->mNext = v56;
        v56[1].mNext = v56;
        UFG::qString::qString((UFG::qString *)&v56[2], "LastSelection");
        mNext[4].mPrev = 0i64;
        mNext[3].mNext = 0i64;
      }
      else
      {
        mNext = 0i64;
      }
      mPrev = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mNext->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = mNext;
    }
    else
    {
      while ( (unsigned int)UFG::qStringCompare("LastSelection", (const char *)mNext[2].mNext, -1) )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
          goto LABEL_87;
      }
    }
    LODWORD(mNext[3].mNext) = 0;
    v58 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v59 = (UFG::Event *)v58;
    out_is_selected = (UFG::DUIContext *)v58;
    if ( v58 )
    {
      v60 = v58 + 1;
      v60->mNext = v60;
      v60[1].mNext = v60;
      v59->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
      v59->m_EventUID = 609910773;
      v59->m_NamePTR = 0i64;
    }
    else
    {
      v59 = 0i64;
    }
    v59->mUserData0 = (unsigned __int64)mNext;
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v59);
    for ( k = 0; k < UFG::Editor::AssetBrowser::sSelectedAssets.mData.size; ++k )
    {
      v62 = UFG::Editor::AssetBrowser::sSelectedAssets.mData.p[k];
      if ( !(unsigned int)UFG::qStringCompare(*(const char **)(v62 + 216), "PropertySet", -1) )
      {
        p_item = &item;
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
        item.mSystemName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&out_is_selected, "archy")->mUID;
        v63 = UFG::qSymbol::create_from_string(&result, *(const char **)(v62 + 136));
        v64 = item.mElements.size + 1;
        if ( item.mElements.size + 1 > item.mElements.capacity )
        {
          if ( item.mElements.capacity )
            v65 = 2 * item.mElements.capacity;
          else
            v65 = 1;
          for ( ; v65 < v64; v65 *= 2 )
            ;
          if ( v65 <= 4 )
            v65 = 4;
          if ( v65 - v64 > 0x10000 )
            v65 = item.mElements.size + 65537;
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, v65, "qArray.Insert");
        }
        item.mElements.size = v64;
        v66 = v64 - 1;
        if ( v64 != 1 )
        {
          v67 = v66;
          do
          {
            LODWORD(v66) = v66 - 1;
            item.mElements.p[v67--].mUID = item.mElements.p[(unsigned int)v66].mUID;
          }
          while ( (_DWORD)v66 );
        }
        item.mElements.p->mUID = v63->mUID;
        mPtr = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v69 = item.mFnObject.mPrev;
          v70 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v70->mPrev = v69;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)mPtr->mSmartHandleList.mNode.mNext == &mPtr->mSmartHandleList
            && mPtr )
          {
            mPtr->vfptr->__vecDelDtor(mPtr, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        if ( (int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(
                    (UFG::qArray<UFG::Editor::DAGPath,0> *)&mNext[3].mNext,
                    &item) <= -1 )
        {
          mNext_low = LODWORD(mNext[3].mNext);
          v72 = mNext_low + 1;
          mNext_high = HIDWORD(mNext[3].mNext);
          if ( (int)mNext_low + 1 > mNext_high )
          {
            if ( mNext_high )
              v74 = 2 * mNext_high;
            else
              v74 = 1;
            for ( ; v74 < v72; v74 *= 2 )
              ;
            if ( v74 - v72 > 0x10000 )
              v74 = mNext_low + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(
              (UFG::qArray<UFG::Editor::DAGPath,0> *)&mNext[3].mNext,
              v74,
              "qArray.Add");
          }
          LODWORD(mNext[3].mNext) = v72;
          v75 = (__int64)mNext[4].mPrev + 88 * mNext_low;
          if ( &item != (UFG::Editor::DAGPath *)v75 )
          {
            UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)mNext[4].mPrev + mNext_low);
            if ( !*(_DWORD *)(v75 + 80) )
            {
              v76 = item.mFnObject.mPtr;
              if ( !*(_QWORD *)(v75 + 16) )
              {
                if ( item.mFnObject.mPtr )
                {
                  *(_DWORD *)(v75 + 24) = item.mFnObject.mPtr->mTypeId;
                  *(_QWORD *)(v75 + 16) = v76;
                  p_mSmartHandleList = (__int64 *)&v76->mSmartHandleList;
                  v78 = *p_mSmartHandleList;
                  *(_QWORD *)(v78 + 8) = v75;
                  *(_QWORD *)v75 = v78;
                  *(_QWORD *)(v75 + 8) = p_mSmartHandleList;
                  *p_mSmartHandleList = v75;
                }
              }
            }
            *(_DWORD *)(v75 + 32) = item.mSystemName.mUID;
            UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v75 + 40));
            *(_DWORD *)(v75 + 56) = item.mInterfaceName.mUID;
            UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, (UFG::qArray<UFG::qString,0> *)(v75 + 64));
          }
          v79 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
          v80 = (UFG::Event *)v79;
          p_item = (UFG::Editor::DAGPath *)v79;
          if ( v79 )
          {
            v81 = v79 + 1;
            v81->mNext = v81;
            v81[1].mNext = v81;
            v80->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
            v80->m_EventUID = 609910773;
            v80->m_NamePTR = 0i64;
          }
          else
          {
            v80 = 0i64;
          }
          v80->mUserData0 = (unsigned __int64)mNext;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v80);
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
          v83 = item.mElements.p - 1;
          `eh vector destructor iterator(
            item.mElements.p,
            4ui64,
            item.mElements.p[-1].mUID,
            (void (__fastcall *)(void *))_);
          operator delete[](v83);
        }
        item.mElements.p = 0i64;
        *(_QWORD *)&item.mElements.size = 0i64;
        p_item = &item;
        v84 = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v85 = item.mFnObject.mPrev;
          v86 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v86->mPrev = v85;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v84->mSmartHandleList.mNode.mNext == &v84->mSmartHandleList )
          {
            if ( v84 )
              v84->vfptr->__vecDelDtor(v84, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        v87 = item.mFnObject.mPrev;
        v88 = item.mFnObject.mNext;
        item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
        v88->mPrev = v87;
        item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      }
    }
  }
}:qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      }
    }
  }
}

