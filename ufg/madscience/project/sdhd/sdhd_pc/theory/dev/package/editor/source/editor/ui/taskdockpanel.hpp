// File Line: 23
// RVA: 0x201AD0
void __fastcall UFG::Editor::MenuBar::MenuBar(UFG::Editor::MenuBar *this, MemImageLoadFlag f)
{
  UFG::Editor::MenuBar *v2; // rdi
  UFG::DUIIntArray *v3; // [rsp+58h] [rbp+20h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v2->mSceneLayer.mFilter_Text);
  v2->mSceneLayer.mFilteredList.p = 0i64;
  *(_QWORD *)&v2->mSceneLayer.mFilteredList.size = 0i64;
  v3 = &v2->mSceneLayer.mLayer_SelectedItems;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v2->mSceneLayer.mLayer_ScrollPos = 0i64;
  v2->mSceneLayer.mMetrics = 0i64;
  v2->mSceneLayer.mSortIndex = 1;
  v2->mSceneLayer.mOldSortIndex = -1;
  v2->mMinSize = (UFG::DUIPoint)214748365000i64;
  UFG::qString::Set(&v2->mTitle, "EDITOR");
}

