// File Line: 32
// RVA: 0x210630
int __fastcall UFG::Editor::Terminal::PrintHandlerBridge(UFG::Editor::Terminal *userData, const char *text)
{
  if ( userData && text && (userData->mChannel & 2) != 0 )
    return UFG::Editor::Terminal::TextOutA(userData, text);
  else
    return 0;
}

// File Line: 64
// RVA: 0x202B70
void __fastcall UFG::Editor::Terminal::Terminal(UFG::Editor::Terminal *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qSafePointerNode<UFG::Editor::Terminal>::qSafePointerNode<UFG::Editor::Terminal>(&this->UFG::qSafePointerNode<UFG::Editor::Terminal>);
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qSafePointerNode<UFG::Editor::Terminal>::vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable;
  this->mScrollPos = 0i64;
  `eh vector constructor iterator(
    this->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  *(_QWORD *)&this->mEOL = 0i64;
  UFG::Editor::Terminal::Initialize(this);
}

