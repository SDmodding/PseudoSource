// File Line: 29
// RVA: 0x2019D0
void __fastcall UFG::Editor::InfoPanel::InfoPanel(UFG::Editor::InfoPanel *this, MemImageLoadFlag f)
{
  UFG::Editor::InfoPanel *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::InfoPanel::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::InfoPanel::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mScrollPosition = 0i64;
  UFG::qString::Set(&v2->mTitle, "Info");
}

