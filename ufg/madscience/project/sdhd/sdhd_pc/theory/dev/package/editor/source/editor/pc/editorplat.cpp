// File Line: 53
// RVA: 0xA3EE20
void __fastcall UFG::Editor::SetCursorMode(UFG::Editor::CursorMode mode)
{
  hCursorOverride = UFG::Editor::hCursors[mode];
}

// File Line: 85
// RVA: 0xA3EE40
void __fastcall UFG::Editor::Utility::SetMainWindowClientRect(UFG::DUIRect *rect)
{
  UFG::DUIRect *v1; // rbx
  tagRECT rc; // [rsp+40h] [rbp-18h]
  unsigned int dwStyleEx; // [rsp+60h] [rbp+8h]
  unsigned int dwStyle; // [rsp+68h] [rbp+10h]

  v1 = rect;
  Render::GetWindowRectAndStyle(&rc, &dwStyle, &dwStyleEx, rect->mW, rect->mH);
  SetWindowPos(ghWnd, 0i64, rc.left + v1->mX, rc.top + v1->mY, rc.right - rc.left, rc.bottom - rc.top, 0x4000u);
}

