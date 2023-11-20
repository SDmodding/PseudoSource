// File Line: 37
// RVA: 0x200FB0
void __fastcall UFG::Editor::AssetBrowser::AssetBrowser(UFG::Editor::AssetBrowser *this, MemImageLoadFlag f)
{
  UFG::Editor::AssetBrowser *v2; // rbx
  UFG::DUIIntArray *v3; // [rsp+50h] [rbp+18h]
  UFG::DUIIntArray *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mTagFilterScrollPos = 0i64;
  v3 = &v2->mSelectedTypes;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable';
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v4 = &v2->mSelectedTags;
  v4->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable';
  v4->mData.p = 0i64;
  *(_QWORD *)&v4->mData.size = 0i64;
  v2->mSearchText.mText.mData.mFlags = 2;
  v2->mRefreshFiltered = 1;
  v2->mFilteredAssets.p = 0i64;
  *(_QWORD *)&v2->mFilteredAssets.size = 0i64;
  v2->mAssetListScrollPos = 0i64;
  v2->mMetrics = 0i64;
  UFG::qString::Set(&v2->mTitle, "Asset Browser");
}

// File Line: 41
// RVA: 0x2031A0
void __fastcall UFG::Editor::AssetBrowser::~AssetBrowser(UFG::Editor::AssetBrowser *this)
{
  UFG::Editor::AssetBrowser *v1; // rbx
  unsigned __int64 *v2; // rcx
  void **v3; // rdi
  unsigned __int64 *v4; // rcx
  unsigned __int64 *v5; // rcx

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2 = this->mFilteredAssets.p;
  if ( v2 )
    operator delete[](v2);
  v1->mFilteredAssets.p = 0i64;
  *(_QWORD *)&v1->mFilteredAssets.size = 0i64;
  v3 = (void **)&v1->mSearchText.mText.mData.mItems;
  if ( !(v1->mSearchText.mText.mData.mFlags & 2) )
    operator delete[](*v3);
  *v3 = 0i64;
  *(_QWORD *)&v1->mSearchText.mText.mData.mNumItems = 0i64;
  v4 = v1->mSelectedTags.mData.p;
  if ( v4 )
    operator delete[](v4);
  v1->mSelectedTags.mData.p = 0i64;
  *(_QWORD *)&v1->mSelectedTags.mData.size = 0i64;
  v5 = v1->mSelectedTypes.mData.p;
  if ( v5 )
    operator delete[](v5);
  v1->mSelectedTypes.mData.p = 0i64;
  *(_QWORD *)&v1->mSelectedTypes.mData.size = 0i64;
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

