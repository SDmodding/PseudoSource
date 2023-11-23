// File Line: 23
// RVA: 0x201AD0
void __fastcall UFG::Editor::MenuBar::MenuBar(UFG::Editor::MenuBar *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mSceneLayer.mFilter_Text);
  this->mSceneLayer.mFilteredList.p = 0i64;
  *(_QWORD *)&this->mSceneLayer.mFilteredList.size = 0i64;
  this->mSceneLayer.mLayer_SelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSceneLayer.mLayer_SelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSceneLayer.mLayer_SelectedItems.mData.size = 0i64;
  this->mSceneLayer.mLayer_ScrollPos = 0i64;
  this->mSceneLayer.mMetrics = 0i64;
  this->mSceneLayer.mSortIndex = 1;
  this->mSceneLayer.mOldSortIndex = -1;
  this->mMinSize = (UFG::DUIPoint)0x32000000C8i64;
  UFG::qString::Set(&this->mTitle, "EDITOR");
}

