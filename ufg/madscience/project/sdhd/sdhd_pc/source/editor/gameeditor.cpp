// File Line: 255
// RVA: 0x69D000
void __fastcall UFG::GameEditor::Deactivate(UFG::GameEditor *this)
{
  UFG::Editor *v1; // rcx

  if ( (unsigned __int8)UFG::Editor::IsActive() )
    UFG::Editor::Deactivate(v1);
}

// File Line: 264
// RVA: 0x69D7C0
_BOOL8 __fastcall UFG::GameEditor::IsActive()
{
  return UFG::Editor::IsActive();
}

// File Line: 269
// RVA: 0x69D5D0
UFG::qNode<UFG::Editor::View,UFG::Editor::View> **__fastcall UFG::GameEditor::GetActiveView()
{
  return UFG::Editor::GetActiveView();
}

