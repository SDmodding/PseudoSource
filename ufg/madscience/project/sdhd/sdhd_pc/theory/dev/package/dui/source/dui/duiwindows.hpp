// File Line: 74
// RVA: 0x192C70
void __fastcall UFG::DUIThemeEditorWindow::DUIThemeEditorWindow(UFG::DUIThemeEditorWindow *this, MemImageLoadFlag f)
{
  UFG::DUIThemeEditorWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIThemeEditorWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIThemeEditorWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::qString(&v2->mTextBoxString0);
  UFG::qString::qString(&v2->mTextBoxString1);
  UFG::qString::qString(&v2->mTextBoxString2);
  UFG::qString::qString(&v2->mTextBoxString3);
  UFG::qString::qString(&v2->mTextBoxWithSuggestionsString);
  UFG::qString::qString(&v2->mMessageBoxResponse);
  UFG::qString::Set(&v2->mTitle, "Theme Editor");
}

// File Line: 113
// RVA: 0x192820
void __fastcall UFG::DUILogWindow::DUILogWindow(UFG::DUILogWindow *this, MemImageLoadFlag f)
{
  UFG::DUILogWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  `eh vector constructor iterator'(v2->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::qString);
  v2->mNumLines = 0i64;
  v2->mScrollPos = 0i64;
  UFG::qString::Set(&v2->mTitle, "Log");
  UFG::qAddPrintHandler(UFG::DUILogWindow::PrintHandler, v2);
}

