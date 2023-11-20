// File Line: 32
// RVA: 0x210630
__int64 __fastcall UFG::Editor::Terminal::PrintHandlerBridge(void *userData, const char *text)
{
  if ( userData && text )
    JUMPOUT(*((_BYTE *)userData + 348) & 2, 0, UFG::Editor::Terminal::TextOutA);
  return 0i64;
}

// File Line: 64
// RVA: 0x202B70
void __fastcall UFG::Editor::Terminal::Terminal(UFG::Editor::Terminal *this, MemImageLoadFlag f)
{
  UFG::Editor::Terminal *v2; // rdi

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qSafePointerNode<UFG::Editor::Terminal>::qSafePointerNode<UFG::Editor::Terminal>((UFG::qSafePointerNode<UFG::Editor::Terminal> *)&v2->vfptr);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable;
  v2->mScrollPos = 0i64;
  `eh vector constructor iterator(
    v2->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  *(_QWORD *)&v2->mEOL = 0i64;
  UFG::Editor::Terminal::Initialize(v2);
}

