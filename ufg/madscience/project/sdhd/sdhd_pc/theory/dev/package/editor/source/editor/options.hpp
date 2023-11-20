// File Line: 183
// RVA: 0x2033A0
void __fastcall UFG::Editor::GizmoVisiblity::~GizmoVisiblity(UFG::Editor::GizmoVisiblity *this)
{
  UFG::Editor::GizmoVisiblity *v1; // rbx
  UFG::qReflectString *v2; // rdi

  v1 = this;
  v2 = &this->mFilter;
  if ( !(this->mFilter.mText.mData.mFlags & 2) )
    operator delete[](v2->mText.mData.mItems);
  v2->mText.mData.mItems = 0i64;
  *(_QWORD *)&v2->mText.mData.mNumItems = 0i64;
  if ( !(v1->mName.mText.mData.mFlags & 2) )
    operator delete[](v1->mName.mText.mData.mItems);
  v1->mName.mText.mData.mItems = 0i64;
  *(_QWORD *)&v1->mName.mText.mData.mNumItems = 0i64;
}

// File Line: 355
// RVA: 0x203430
void __fastcall UFG::Editor::Options::~Options(UFG::Editor::Options *this)
{
  UFG::qList<UFG::Editor::OptionsView,UFG::Editor::OptionsView,1,0> *v1; // rbx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v2; // rax
  UFG::Editor::Options *i; // rdi
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v4; // rdx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v5; // rcx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v6; // rax
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v7; // rcx
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *v8; // rax

  v1 = &this->mViews;
  v2 = this->mViews.mNode.mNext - 5;
  for ( i = this - 3; v2 != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)i; v2 = v1->mNode.mNext - 5 )
  {
    v4 = v2 + 5;
    v5 = v2[5].mPrev;
    v6 = v2[5].mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
    if ( v4 != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)80 )
      ((void (__fastcall *)(UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> **, signed __int64))v4[-5].mPrev->mPrev)(
        &v4[-5].mPrev,
        1i64);
  }
  UFG::qList<UFG::Editor::OptionsView,UFG::Editor::OptionsView,1,0>::DeleteNodes(v1);
  v7 = v1->mNode.mPrev;
  v8 = v1->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 376
// RVA: 0x201D00
void __fastcall UFG::Editor::OptionsWindow::OptionsWindow(UFG::Editor::OptionsWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::OptionsWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OptionsWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OptionsWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mScrollPosition = 0i64;
  UFG::qString::Set(&v2->mTitle, "Options");
}

