// File Line: 37
// RVA: 0x200FB0
void __fastcall UFG::Editor::AssetBrowser::AssetBrowser(UFG::Editor::AssetBrowser *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mTagFilterScrollPos = 0i64;
  this->mSelectedTypes.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedTypes.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTypes.mData.size = 0i64;
  this->mSelectedTags.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSelectedTags.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTags.mData.size = 0i64;
  this->mSearchText.mText.mData.mFlags = 2;
  this->mRefreshFiltered = 1;
  this->mFilteredAssets.p = 0i64;
  *(_QWORD *)&this->mFilteredAssets.size = 0i64;
  this->mAssetListScrollPos = 0i64;
  this->mMetrics = 0i64;
  UFG::qString::Set(&this->mTitle, "Asset Browser");
}

// File Line: 41
// RVA: 0x2031A0
void __fastcall UFG::Editor::AssetBrowser::~AssetBrowser(UFG::Editor::AssetBrowser *this)
{
  unsigned __int64 *p; // rcx
  UFG::qReflectString *p_mSearchText; // rdi
  unsigned __int64 *v4; // rcx
  unsigned __int64 *v5; // rcx

  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AssetBrowser,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AssetBrowser::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  p = this->mFilteredAssets.p;
  if ( p )
    operator delete[](p);
  this->mFilteredAssets.p = 0i64;
  *(_QWORD *)&this->mFilteredAssets.size = 0i64;
  p_mSearchText = &this->mSearchText;
  if ( (this->mSearchText.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mSearchText->mText.mData.mItems);
  p_mSearchText->mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mSearchText.mText.mData.mNumItems = 0i64;
  v4 = this->mSelectedTags.mData.p;
  if ( v4 )
    operator delete[](v4);
  this->mSelectedTags.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTags.mData.size = 0i64;
  v5 = this->mSelectedTypes.mData.p;
  if ( v5 )
    operator delete[](v5);
  this->mSelectedTypes.mData.p = 0i64;
  *(_QWORD *)&this->mSelectedTypes.mData.size = 0i64;
  UFG::DUIWindow::~DUIWindow(this);
}

