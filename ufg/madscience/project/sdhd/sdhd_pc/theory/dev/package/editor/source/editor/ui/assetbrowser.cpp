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
  return atexit(dynamic_atexit_destructor_for__UFG::Editor::AssetBrowser::sSelectedAssets__);
}

// File Line: 37
// RVA: 0x201090
void __fastcall UFG::Editor::AssetBrowser::AssetBrowser(UFG::Editor::AssetBrowser *this)
{
  UFG::Editor::AssetBrowser *v1; // rsi
  unsigned int v2; // ebx
  UFG::DUIIntArray *v3; // [rsp+58h] [rbp+10h]
  UFG::DUIIntArray *v4; // [rsp+58h] [rbp+10h]
  UFG::qReflectString *v5; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::AssetBrowser", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mTypesFilterScrollPos = 0i64;
  v1->mTagFilterScrollPos = 0i64;
  v3 = &v1->mSelectedTypes;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v4 = &v1->mSelectedTags;
  v4->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v4->mData.p = 0i64;
  *(_QWORD *)&v4->mData.size = 0i64;
  v5 = &v1->mSearchText;
  *(_QWORD *)&v5->mText.mData.mNumItems = 0i64;
  v5->mText.mData.mItems = 0i64;
  v2 = (unsigned __int64)UFG::qStringLength(&customWorldMapCaption) + 1;
  UFG::qReflectArray<char>::Resize(&v1->mSearchText.mText, v2, "qReflectString::Set()");
  UFG::qMemCopy(v1->mSearchText.mText.mData.mItems, &customWorldMapCaption, v2);
  v1->mRefreshFiltered = 1;
  v1->mFilteredAssets.p = 0i64;
  *(_QWORD *)&v1->mFilteredAssets.size = 0i64;
  v1->mAssetListScrollPos = 0i64;
  v1->mMetrics = 0i64;
  UFG::qString::Set(&v1->mTitle, "Asset Browser");
  v1->mRect.mW = 400;
  v1->mRect.mH = 600;
  *(_QWORD *)v1->mAssetGridWidths = 4294967297i64;
  v1->mHorizontalSplitHeights[0] = 1;
  v1->mHorizontalSplitHeights[1] = 2;
  *(_QWORD *)v1->mHorizontalSplitWidths = 4294967297i64;
  v1->mAssetGridWidths[0] = v1->mRect.mW - 60;
  v1->mAssetGridWidths[1] = 30;
  v1->mHorizontalSplitHeights[0] = (signed int)(float)((float)v1->mRect.mH * 0.34999999);
  v1->mHorizontalSplitHeights[1] = (signed int)(float)((float)v1->mRect.mH * 0.64999998);
}

// File Line: 63
// RVA: 0x213850
bool __fastcall UFG::Editor::SortAssetsByName(const unsigned __int64 *a, const unsigned __int64 *b)
{
  unsigned __int64 *v2; // rdi
  unsigned __int64 *v3; // rbx
  UFG::AssetHive *v4; // rax
  UFG::qTree64Base *v5; // rbx
  UFG::AssetHive *v6; // rax
  UFG::qTree64Base *v7; // rax

  v2 = (unsigned __int64 *)b;
  v3 = (unsigned __int64 *)a;
  v4 = UFG::AssetHive::Instance();
  v5 = UFG::qTree64Base::Get(&v4->mAssets.mTree, *v3);
  v6 = UFG::AssetHive::Instance();
  v7 = UFG::qTree64Base::Get(&v6->mAssets.mTree, *v2);
  return (signed int)UFG::qStringCompare(
                       (const char *)v5[2].mHead.mChildren[1],
                       (const char *)v7[2].mHead.mChildren[1],
                       -1) < 0;
}

// File Line: 70
// RVA: 0x2138B0
bool __fastcall UFG::Editor::SortAssetsByType(const unsigned __int64 *a, const unsigned __int64 *b)
{
  unsigned __int64 *v2; // rdi
  unsigned __int64 *v3; // rbx
  UFG::AssetHive *v4; // rax
  UFG::qTree64Base *v5; // rbx
  UFG::AssetHive *v6; // rax
  UFG::qTree64Base *v7; // rax

  v2 = (unsigned __int64 *)b;
  v3 = (unsigned __int64 *)a;
  v4 = UFG::AssetHive::Instance();
  v5 = UFG::qTree64Base::Get(&v4->mAssets.mTree, *v3);
  v6 = UFG::AssetHive::Instance();
  v7 = UFG::qTree64Base::Get(&v6->mAssets.mTree, *v2);
  return (signed int)UFG::qStringCompare((const char *)v5[3].mCount, (const char *)v7[3].mCount, -1) < 0;
}

// File Line: 84
// RVA: 0x217A30
void __fastcall UFG::Editor::AssetBrowser::UpdateUI(UFG::Editor::AssetBrowser *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r15
  UFG::Editor::AssetBrowser *v3; // r14
  UFG::AssetHive *v4; // rax
  signed __int64 v5; // r12
  const char *v6; // rdx
  char *v7; // rdi
  unsigned int v8; // ebx
  signed __int64 v9; // r13
  UFG::AssetHive *v10; // rax
  UFG::qTree64Base *v11; // rax
  signed __int64 v12; // rdi
  UFG::AssetHive *v13; // rax
  UFG::qTree64Base *v14; // rax
  signed __int64 v15; // rsi
  UFG::AssetHive *v16; // rax
  UFG::qTree64Base *v17; // rbx
  UFG::AssetHive *v18; // rax
  UFG::AssetHive *v19; // rax
  UFG::qTree64Base *v20; // rbx
  int v21; // ecx
  BOOL v22; // eax
  const char *v23; // r8
  const char *v24; // rcx
  char v25; // al
  bool v26; // zf
  unsigned __int64 v27; // rdi
  unsigned int v28; // ebx
  bool v29; // r12
  unsigned int v30; // er15
  UFG::qTree64Base::BaseNode *v31; // rbx
  UFG::qTree64Base::BaseNode **v32; // rdi
  __int64 v33; // rsi
  UFG::qTree64Base::BaseNode *v34; // rbx
  unsigned __int64 v35; // r12
  __int64 v36; // r15
  unsigned int v37; // edi
  unsigned int v38; // ebx
  unsigned int v39; // ebx
  unsigned __int64 v40; // rax
  UFG::allocator::free_link *v41; // rax
  unsigned __int64 *v42; // rsi
  __int64 v43; // r9
  UFG::AssetHive *v44; // rax
  int v45; // ebx
  bool (__fastcall *v46)(UFG::qPropertySet *const *, UFG::qPropertySet *const *); // r8
  unsigned int i; // edi
  unsigned __int64 v48; // rbx
  UFG::AssetHive *v49; // rax
  UFG::qTree64Base *v50; // rax
  UFG::qTree64Base *v51; // rsi
  bool v52; // al
  unsigned __int64 v53; // rax
  UFG::allocator::free_link *v54; // rbx
  UFG::AssetHive *v55; // rax
  UFG::qString *v56; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v57; // rdi
  UFG::allocator::free_link *v58; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::Event *v61; // rdx
  UFG::allocator::free_link *v62; // rax
  unsigned int j; // er15
  unsigned __int64 v64; // rbx
  UFG::qSymbol *v65; // rsi
  unsigned int v66; // ebx
  unsigned int v67; // edx
  __int64 v68; // rdx
  __int64 v69; // r8
  UFG::Editor::SmartHandleObject *v70; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v71; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v72; // rax
  __int64 v73; // rsi
  unsigned int v74; // ebx
  unsigned int v75; // edx
  unsigned int v76; // edx
  signed __int64 v77; // rbx
  UFG::Editor::SmartHandleObject *v78; // rcx
  __int64 *v79; // rcx
  __int64 v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::Event *v82; // rdx
  UFG::allocator::free_link *v83; // rax
  unsigned int *v84; // rbx
  UFG::qSymbol *v85; // rbx
  UFG::Editor::SmartHandleObject *v86; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v87; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v88; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v89; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v90; // rax
  bool v91; // [rsp+50h] [rbp-B0h]
  UFG::qTree64Base::BaseNode *cur_node; // [rsp+58h] [rbp-A8h]
  UFG::allocator::free_link *v93; // [rsp+60h] [rbp-A0h]
  UFG::Editor::DAGPath item; // [rsp+70h] [rbp-90h]
  UFG::qString current_value; // [rsp+D0h] [rbp-30h]
  __int64 v96; // [rsp+F8h] [rbp-8h]
  UFG::qSymbol result; // [rsp+150h] [rbp+50h]
  UFG::DUIContext *out_is_selected; // [rsp+158h] [rbp+58h]
  UFG::Editor::DAGPath *v99; // [rsp+160h] [rbp+60h]
  char v100; // [rsp+168h] [rbp+68h]

  out_is_selected = dui;
  v96 = -2i64;
  v2 = dui;
  v3 = this;
  if ( !UFG::AssetHive::Instance()->mAssets.mTree.mCount )
  {
    v4 = UFG::AssetHive::Instance();
    UFG::AssetHive::IndexAssets(v4);
  }
  v3->mMainStatusStripHeights[0] = v3->mClientRect.mH - v2->mTheme.mRowHeight;
  v3->mMainStatusStripHeights[1] = v2->mTheme.mRowHeight;
  LOBYTE(v99) = 0;
  v100 = 0;
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 0i64, v3->mMainStatusStripHeights, 1);
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 0i64, v3->mHorizontalSplitHeights, 12);
  UFG::DUIContext::BeginGridLayout(v2, 1, 3, 3);
  UFG::DUIContext::Header(v2, "Filters", 0i64, 0i64);
  v5 = (signed __int64)&v3->mSearchText;
  if ( v3->mSearchText.mText.mData.mNumItems )
    v6 = *(const char **)v5;
  else
    v6 = &customWorldMapCaption;
  UFG::qString::qString(&current_value, v6);
  if ( (unsigned __int8)UFG::DUIContext::TextBox(v2, &current_value, "Search...", 1, 0i64, 0xFFFFFFFF) )
  {
    v7 = current_value.mData;
    v8 = (unsigned __int64)UFG::qStringLength(current_value.mData) + 1;
    UFG::qReflectArray<char>::Resize(&v3->mSearchText.mText, v8, "qReflectString::Set()");
    UFG::qMemCopy(*(void **)v5, v7, v8);
    v3->mRefreshFiltered = 1;
  }
  UFG::DUIContext::BeginGridLayout(v2, 2, 1, v3->mHorizontalSplitWidths, 0i64, 12);
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 3);
  UFG::DUIContext::Header(v2, "Types", 0i64, 0i64);
  v9 = (signed __int64)&v3->mSelectedTypes;
  UFG::DUIContext::BeginListView(
    v2,
    (UFG::IDUICollectionView *)&v3->mSelectedTypes.vfptr,
    &v3->mTypesFilterScrollPos,
    1);
  v10 = UFG::AssetHive::Instance();
  v11 = UFG::qTree64Base::GetHead(&v10->mFactories.mTree);
  v12 = (signed __int64)&v11[-1].mCount;
  if ( !v11 )
    v12 = 0i64;
  UFG::AssetHive::Instance();
  while ( v12 )
  {
    v3->mRefreshFiltered |= UFG::DUIContext::ListViewItem(v2, *(const char **)(v12 + 80), *(_QWORD *)(v12 + 8), 0i64);
    v13 = UFG::AssetHive::Instance();
    v14 = UFG::qTree64Base::GetNext(&v13->mFactories.mTree, (UFG::qTree64Base::BaseNode *)(v12 + 8));
    v12 = (signed __int64)&v14[-1].mCount;
    if ( !v14 )
      v12 = 0i64;
    UFG::AssetHive::Instance();
  }
  UFG::DUIContext::EndListView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::BeginGridLayout(v2, 1, 2, 3);
  UFG::DUIContext::Header(v2, "Tags", 0i64, 0i64);
  v15 = (signed __int64)&v3->mSelectedTags;
  UFG::DUIContext::BeginListView(v2, (UFG::IDUICollectionView *)&v3->mSelectedTags.vfptr, &v3->mTagFilterScrollPos, 1);
  v16 = UFG::AssetHive::Instance();
  v17 = UFG::qTree64Base::GetHead(&v16->mTags.mTree);
  UFG::AssetHive::Instance();
  while ( v17 )
  {
    v3->mRefreshFiltered |= UFG::DUIContext::ListViewItem(
                              v2,
                              (const char *)v17[1].mHead.mChildren[0],
                              v17->mHead.mUID,
                              0i64);
    v18 = UFG::AssetHive::Instance();
    v17 = UFG::qTree64Base::GetNext(&v18->mTags.mTree, &v17->mHead);
    UFG::AssetHive::Instance();
  }
  UFG::DUIContext::EndListView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::qString::~qString(&current_value);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( v3->mRefreshFiltered )
  {
    LOBYTE(v99) = 1;
    UFG::Editor::AssetBrowser::sSelectedAssets.mData.size = 0;
    v3->mFilteredAssets.size = 0;
    v19 = UFG::AssetHive::Instance();
    v20 = UFG::qTree64Base::GetHead(&v19->mAssets.mTree);
    cur_node = &v20->mHead;
    UFG::AssetHive::Instance();
    if ( v20 )
    {
      do
      {
        v21 = *(_DWORD *)(v5 + 8);
        v22 = !v21 || v21 == 1 && !**(_BYTE **)v5;
        LOBYTE(result.mUID) = v22 != 0;
        if ( v21 && (v21 != 1 || **(_BYTE **)v5) )
        {
          if ( v21 )
            v23 = *(const char **)v5;
          else
            v23 = &customWorldMapCaption;
          if ( v23 && (v24 = v23, (v25 = *v23) != 0) )
          {
            while ( v25 != 42 && v25 != 63 )
            {
              v25 = *++v24;
              if ( !*v24 )
                goto LABEL_36;
            }
            v26 = (unsigned int)UFG::qWildcardMatchInsensitive(v23, (const char *)v20[2].mHead.mChildren[1]) == 0;
          }
          else
          {
LABEL_36:
            v26 = UFG::qStringFindInsensitive((const char *)v20[2].mHead.mChildren[1], v23) == 0i64;
          }
          LOBYTE(result.mUID) = !v26;
        }
        v91 = (*(unsigned int (__fastcall **)(UFG::DUIIntArray *))(*(_QWORD *)v9 + 48i64))(&v3->mSelectedTypes) == 0;
        v27 = UFG::qStringHash64((const char *)v20[3].mCount, 0xFFFFFFFFFFFFFFFFui64);
        v28 = 0;
        if ( (*(unsigned int (__fastcall **)(UFG::DUIIntArray *))(*(_QWORD *)v9 + 48i64))(&v3->mSelectedTypes) )
        {
          while ( (*(__int64 (__fastcall **)(UFG::DUIIntArray *, _QWORD))(*(_QWORD *)v9 + 24i64))(
                    &v3->mSelectedTypes,
                    v28) != v27 )
          {
            if ( ++v28 >= (*(unsigned int (__fastcall **)(UFG::DUIIntArray *))(*(_QWORD *)v9 + 48i64))(&v3->mSelectedTypes) )
              goto LABEL_43;
          }
          v91 = 1;
        }
LABEL_43:
        v29 = (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v15 + 48i64))(v15) == 0;
        v30 = 0;
        if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v15 + 48i64))(v15) )
        {
          v31 = cur_node;
          v32 = cur_node[5].mNeighbours;
          while ( 1 )
          {
            v33 = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v15 + 24i64))(v15, v30);
            v34 = v31[5].mNeighbours[1];
            if ( v34 != (UFG::qTree64Base::BaseNode *)v32 )
              break;
LABEL_48:
            ++v30;
            v15 = (signed __int64)&v3->mSelectedTags;
            if ( v30 >= v3->mSelectedTags.vfptr->Count((UFG::IDUICollectionView *)&v3->mSelectedTags.vfptr) )
              goto LABEL_51;
            v31 = cur_node;
          }
          while ( v33 != UFG::qStringHash64((const char *)v34->mChildren[1], 0xFFFFFFFFFFFFFFFFui64) )
          {
            v34 = v34->mParent;
            if ( v34 == (UFG::qTree64Base::BaseNode *)v32 )
              goto LABEL_48;
          }
          v29 = 1;
        }
LABEL_51:
        if ( (v91 && v29) & result.mUID )
        {
          v35 = cur_node[2].mUID;
          v36 = v3->mFilteredAssets.size;
          v37 = v36 + 1;
          v38 = v3->mFilteredAssets.capacity;
          if ( (signed int)v36 + 1 > v38 )
          {
            if ( v38 )
              v39 = 2 * v38;
            else
              v39 = 1;
            for ( ; v39 < v37; v39 *= 2 )
              ;
            if ( v39 <= 2 )
              v39 = 2;
            if ( v39 - v37 > 0x10000 )
              v39 = v36 + 65537;
            if ( v39 != (_DWORD)v36 )
            {
              v40 = 8i64 * v39;
              if ( !is_mul_ok(v39, 8ui64) )
                v40 = -1i64;
              v41 = UFG::qMalloc(v40, "qArray.Add", 0i64);
              v42 = (unsigned __int64 *)v41;
              if ( v3->mFilteredAssets.p )
              {
                v43 = 0i64;
                if ( v3->mFilteredAssets.size )
                {
                  do
                  {
                    v41[v43] = (UFG::allocator::free_link)v3->mFilteredAssets.p[v43];
                    v43 = (unsigned int)(v43 + 1);
                  }
                  while ( (unsigned int)v43 < v3->mFilteredAssets.size );
                }
                operator delete[](v3->mFilteredAssets.p);
              }
              v3->mFilteredAssets.p = v42;
              v3->mFilteredAssets.capacity = v39;
            }
          }
          v3->mFilteredAssets.size = v37;
          v3->mFilteredAssets.p[v36] = v35;
        }
        v44 = UFG::AssetHive::Instance();
        v20 = UFG::qTree64Base::GetNext(&v44->mAssets.mTree, cur_node);
        cur_node = &v20->mHead;
        UFG::AssetHive::Instance();
        v15 = (signed __int64)&v3->mSelectedTags;
        v5 = (signed __int64)&v3->mSearchText;
      }
      while ( v20 );
      v2 = out_is_selected;
    }
    v3->mRefreshFiltered = 0;
  }
  v45 = sort_col;
  UFG::DUIContext::BeginDataGrid(
    v2,
    2,
    headings_0,
    v3->mAssetGridWidths,
    (UFG::IDUICollectionView *)&UFG::Editor::AssetBrowser::sSelectedAssets.vfptr,
    &v3->mAssetListScrollPos,
    &sort_col,
    1,
    v3->mFilteredAssets.size,
    &v3->mMetrics);
  LOBYTE(v99) = (v45 != sort_col) | (unsigned __int8)v99;
  if ( (_BYTE)v99 )
  {
    if ( sort_col )
    {
      if ( sort_col != 1 )
        goto LABEL_80;
      v46 = (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::Editor::SortAssetsByType;
    }
    else
    {
      v46 = (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::Editor::SortAssetsByName;
    }
    UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
      (UFG::qPropertySet **)v3->mFilteredAssets.p,
      (UFG::qPropertySet **)&v3->mFilteredAssets.p[(signed int)v3->mFilteredAssets.size - 1i64],
      v46);
  }
LABEL_80:
  for ( i = v3->mMetrics.mStart; i < v3->mMetrics.mEnd; ++i )
  {
    v48 = v3->mFilteredAssets.p[i];
    v49 = UFG::AssetHive::Instance();
    v50 = UFG::qTree64Base::Get(&v49->mAssets.mTree, v48);
    v51 = v50;
    LOBYTE(out_is_selected) = 0;
    v52 = UFG::DUIContext::BeginDataGridItem(v2, (unsigned __int64)v50, (bool *)&out_is_selected, 0i64);
    v100 |= v52;
    if ( v2->mDoubleClicked )
    {
      v93 = 0i64;
      cur_node = 0i64;
      v53 = 16i64;
      if ( !is_mul_ok(2ui64, 8ui64) )
        v53 = -1i64;
      v54 = UFG::qMalloc(v53, "qArray.Add", 0i64);
      v93 = v54;
      cur_node = (UFG::qTree64Base::BaseNode *)8589934593i64;
      v54->mNext = (UFG::allocator::free_link *)v51;
      v55 = UFG::AssetHive::Instance();
      UFG::AssetHive::EditAssets(v55, (UFG::qArray<UFG::HiveAsset *,0> *)&cur_node);
      operator delete[](v54);
      v93 = 0i64;
      cur_node = 0i64;
    }
    UFG::DUIContext::Label(v2, (const char *)v51[2].mHead.mChildren[1]);
    UFG::DUIContext::Label(v2, (const char *)v51[3].mCount);
    UFG::DUIContext::EndDataGridItem(v2);
  }
  UFG::DUIContext::EndDataGrid(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  v56 = UFG::qString::FormatEx(&current_value, "%d Items", v3->mFilteredAssets.size);
  UFG::DUIContext::Header(v2, v56->mData, 0i64, 0i64);
  UFG::qString::~qString(&current_value);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( v100 )
  {
    v57 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
    if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
    {
LABEL_90:
      v58 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      v57 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v58;
      out_is_selected = (UFG::DUIContext *)v58;
      if ( v58 )
      {
        v58->mNext = v58;
        v58[1].mNext = v58;
        UFG::qString::qString((UFG::qString *)&v58[2], "LastSelection");
        v57[4].mPrev = 0i64;
        v57[3].mNext = 0i64;
      }
      else
      {
        v57 = 0i64;
      }
      v59 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v57;
      v57->mPrev = v59;
      v57->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
      UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v57;
    }
    else
    {
      while ( (unsigned int)UFG::qStringCompare("LastSelection", (const char *)v57[2].mNext, -1) )
      {
        v57 = v57->mNext;
        if ( v57 == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
          goto LABEL_90;
      }
    }
    LODWORD(v57[3].mNext) = 0;
    v60 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v61 = (UFG::Event *)v60;
    out_is_selected = (UFG::DUIContext *)v60;
    if ( v60 )
    {
      v62 = v60 + 1;
      v62->mNext = v62;
      v62[1].mNext = v62;
      v61->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
      v61->m_EventUID = 609910773;
      v61->m_NamePTR = 0i64;
    }
    else
    {
      v61 = 0i64;
    }
    v61->mUserData0 = (unsigned __int64)v57;
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v61);
    for ( j = 0; j < UFG::Editor::AssetBrowser::sSelectedAssets.mData.size; ++j )
    {
      v64 = UFG::Editor::AssetBrowser::sSelectedAssets.mData.p[j];
      if ( !(unsigned int)UFG::qStringCompare(*(const char **)(v64 + 216), "PropertySet", -1) )
      {
        v99 = &item;
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
        item.mSystemName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&out_is_selected, "archy")->mUID;
        v65 = UFG::qSymbol::create_from_string(&result, *(const char **)(v64 + 136));
        v66 = item.mElements.size + 1;
        if ( item.mElements.size + 1 > item.mElements.capacity )
        {
          if ( item.mElements.capacity )
            v67 = 2 * item.mElements.capacity;
          else
            v67 = 1;
          for ( ; v67 < v66; v67 *= 2 )
            ;
          if ( v67 <= 4 )
            v67 = 4;
          if ( v67 - v66 > 0x10000 )
            v67 = item.mElements.size + 65537;
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, v67, "qArray.Insert");
        }
        item.mElements.size = v66;
        v68 = v66 - 1;
        if ( v66 != 1 )
        {
          v69 = v68;
          do
          {
            LODWORD(v68) = v68 - 1;
            item.mElements.p[v69].mUID = item.mElements.p[(unsigned int)v68].mUID;
            --v69;
          }
          while ( (_DWORD)v68 );
        }
        item.mElements.p->mUID = v65->mUID;
        v70 = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v71 = item.mFnObject.mPrev;
          v72 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v72->mPrev = v71;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v70->mSmartHandleList.mNode.mNext == &v70->mSmartHandleList
            && v70 )
          {
            v70->vfptr->__vecDelDtor(v70, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(
                           (UFG::qArray<UFG::Editor::DAGPath,0> *)&v57[3].mNext,
                           &item) <= -1 )
        {
          v73 = LODWORD(v57[3].mNext);
          v74 = v73 + 1;
          v75 = HIDWORD(v57[3].mNext);
          if ( (signed int)v73 + 1 > v75 )
          {
            if ( v75 )
              v76 = 2 * v75;
            else
              v76 = 1;
            for ( ; v76 < v74; v76 *= 2 )
              ;
            if ( v76 - v74 > 0x10000 )
              v76 = v73 + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(
              (UFG::qArray<UFG::Editor::DAGPath,0> *)&v57[3].mNext,
              v76,
              "qArray.Add");
          }
          LODWORD(v57[3].mNext) = v74;
          v77 = (signed __int64)v57[4].mPrev + 88 * v73;
          if ( &item != (UFG::Editor::DAGPath *)v77 )
          {
            UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)v57[4].mPrev + v73);
            if ( !*(_DWORD *)(v77 + 80) )
            {
              v78 = item.mFnObject.mPtr;
              if ( !*(_QWORD *)(v77 + 16) )
              {
                if ( item.mFnObject.mPtr )
                {
                  *(_DWORD *)(v77 + 24) = item.mFnObject.mPtr->mTypeId;
                  *(_QWORD *)(v77 + 16) = v78;
                  v79 = (__int64 *)&v78->mSmartHandleList;
                  v80 = *v79;
                  *(_QWORD *)(v80 + 8) = v77;
                  *(_QWORD *)v77 = v80;
                  *(_QWORD *)(v77 + 8) = v79;
                  *v79 = v77;
                }
              }
            }
            *(_DWORD *)(v77 + 32) = item.mSystemName.mUID;
            UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v77 + 40));
            *(_DWORD *)(v77 + 56) = item.mInterfaceName.mUID;
            UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, (UFG::qArray<UFG::qString,0> *)(v77 + 64));
          }
          v81 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
          v82 = (UFG::Event *)v81;
          v99 = (UFG::Editor::DAGPath *)v81;
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
          v82->mUserData0 = (unsigned __int64)v57;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v82);
        }
        if ( item.mSubElements.p )
        {
          v84 = &item.mSubElements.p[-1].mStringHash32;
          `eh vector destructor iterator(
            item.mSubElements.p,
            0x28ui64,
            item.mSubElements.p[-1].mStringHash32,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v84);
        }
        item.mSubElements.p = 0i64;
        *(_QWORD *)&item.mSubElements.size = 0i64;
        if ( item.mElements.p )
        {
          v85 = item.mElements.p - 1;
          `eh vector destructor iterator(
            item.mElements.p,
            4ui64,
            item.mElements.p[-1].mUID,
            (void (__fastcall *)(void *))_);
          operator delete[](v85);
        }
        item.mElements.p = 0i64;
        *(_QWORD *)&item.mElements.size = 0i64;
        v99 = &item;
        v86 = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v87 = item.mFnObject.mPrev;
          v88 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v88->mPrev = v87;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v86->mSmartHandleList.mNode.mNext == &v86->mSmartHandleList )
          {
            if ( v86 )
              v86->vfptr->__vecDelDtor(v86, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        v89 = item.mFnObject.mPrev;
        v90 = item.mFnObject.mNext;
        item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
        v90->mPrev = v89;
        item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      }
    }
  }
}FG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
      }
    }
  }
}

