// File Line: 183
// RVA: 0x2033A0
void __fastcall UFG::Editor::GizmoVisiblity::~GizmoVisiblity(UFG::Editor::GizmoVisiblity *this)
{
  UFG::qReflectString *p_mFilter; // rdi

  p_mFilter = &this->mFilter;
  if ( (this->mFilter.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mFilter->mText.mData.mItems);
  p_mFilter->mText.mData.mItems = 0i64;
  *(_QWORD *)&p_mFilter->mText.mData.mNumItems = 0i64;
  if ( (this->mName.mText.mData.mFlags & 2) == 0 )
    operator delete[](this->mName.mText.mData.mItems);
  this->mName.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mName.mText.mData.mNumItems = 0i64;
}

// File Line: 355
// RVA: 0x203430
void __fastcall UFG::Editor::Options::~Options(UFG::Editor::Options *this)
{
  UFG::qList<UFG::Editor::OptionsView,UFG::Editor::OptionsView,1,0> *p_mViews; // rbx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v2; // rax
  UFG::Editor::Options *i; // rdi
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v4; // rdx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *mPrev; // rcx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *mNext; // rax
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v7; // rcx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v8; // rax

  p_mViews = &this->mViews;
  v2 = this->mViews.mNode.mNext - 5;
  for ( i = this - 3;
        v2 != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)i;
        v2 = p_mViews->mNode.mNext - 5 )
  {
    v4 = v2 + 5;
    mPrev = v2[5].mPrev;
    mNext = v2[5].mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mPrev = v4;
    v4->mNext = v4;
    if ( v4 != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)80 )
      ((void (__fastcall *)(UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> **, __int64))v4[-5].mPrev->mPrev)(
        &v4[-5].mPrev,
        1i64);
  }
  UFG::qList<UFG::Editor::OptionsView,UFG::Editor::OptionsView,1,0>::DeleteNodes(p_mViews);
  v7 = p_mViews->mNode.mPrev;
  v8 = p_mViews->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mViews->mNode.mPrev = &p_mViews->mNode;
  p_mViews->mNode.mNext = &p_mViews->mNode;
}

// File Line: 376
// RVA: 0x201D00
void __fastcall UFG::Editor::OptionsWindow::OptionsWindow(UFG::Editor::OptionsWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPosition = 0i64;
  UFG::qString::Set(&this->mTitle, "Options");
}

