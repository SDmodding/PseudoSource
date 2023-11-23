// File Line: 74
// RVA: 0x192C70
void __fastcall UFG::DUIThemeEditorWindow::DUIThemeEditorWindow(UFG::DUIThemeEditorWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mTextBoxString0);
  UFG::qString::qString(&this->mTextBoxString1);
  UFG::qString::qString(&this->mTextBoxString2);
  UFG::qString::qString(&this->mTextBoxString3);
  UFG::qString::qString(&this->mTextBoxWithSuggestionsString);
  UFG::qString::qString(&this->mMessageBoxResponse);
  UFG::qString::Set(&this->mTitle, "Theme Editor");
}

// File Line: 113
// RVA: 0x192820
void __fastcall UFG::DUILogWindow::DUILogWindow(UFG::DUILogWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  `eh vector constructor iterator(this->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::qString);
  this->mNumLines = 0i64;
  this->mScrollPos = 0i64;
  UFG::qString::Set(&this->mTitle, "Log");
  UFG::qAddPrintHandler((UFG::allocator::free_link *)UFG::DUILogWindow::PrintHandler, (UFG::allocator::free_link *)this);
}

