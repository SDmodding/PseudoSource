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
  tagRECT rc; // [rsp+40h] [rbp-18h] BYREF
  unsigned int dwStyleEx; // [rsp+60h] [rbp+8h] BYREF
  unsigned int dwStyle; // [rsp+68h] [rbp+10h] BYREF

  Render::GetWindowRectAndStyle(&rc, &dwStyle, &dwStyleEx, rect->mW, rect->mH);
  SetWindowPos(ghWnd, 0i64, rc.left + rect->mX, rc.top + rect->mY, rc.right - rc.left, rc.bottom - rc.top, 0x4000u);
}

