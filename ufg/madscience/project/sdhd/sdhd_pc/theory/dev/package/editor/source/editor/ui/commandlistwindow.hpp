// File Line: 19
// RVA: 0x2014C0
void __fastcall UFG::Editor::DUICommandListWindow::DUICommandListWindow(UFG::Editor::DUICommandListWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::DUICommandListWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::DUICommandListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::DUICommandListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mScrollPos = 0i64;
  UFG::qString::Set(&v2->mTitle, "Command List");
}

