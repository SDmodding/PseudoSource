// File Line: 31
// RVA: 0x201620
void __fastcall UFG::Editor::EditorDialog::EditorDialog(UFG::Editor::EditorDialog *this, const char *windowName)
{
  const char *v2; // rbx
  UFG::Editor::EditorDialog *v3; // rdi

  v2 = windowName;
  v3 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v3->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v3->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3->mBaseNode.mUID = -1i64;
  v3->mTypeUID = UFG::qStringHash64("UFG::Editor::EditorDialog", 0xFFFFFFFFFFFFFFFFui64);
  v3->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::EditorDialog::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v3->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::EditorDialog::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3->mbHidden = 1;
  UFG::qString::Set(&v3->mTitle, v2);
  v3->mRect.mH = 120;
  v3->mRect.mW = 300;
}

// File Line: 48
// RVA: 0x2016D0
void __fastcall UFG::Editor::EditorDialog::EditorDialog(UFG::Editor::EditorDialog *this, MemImageLoadFlag flag)
{
  UFG::Editor::EditorDialog *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, flag);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::EditorDialog::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::EditorDialog::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mbHidden = 1;
  v2->mRect.mH = 120;
  v2->mRect.mW = 300;
}

