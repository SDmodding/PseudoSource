// File Line: 40
// RVA: 0x1480770
__int64 dynamic_initializer_for__PrintTrackLocationEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&PrintTrackLocationEnum, gPrintTrackLocationStringList, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__PrintTrackLocationEnum__);
}

// File Line: 166
// RVA: 0x26D8A0
__int64 __fastcall DlgProc(HWND__ *hWndDlg, unsigned int Msg, unsigned __int64 wParam, __int64 lParam)
{
  unsigned int v4; // edx
  unsigned __int64 v5; // r8
  signed __int64 v6; // r8
  signed __int64 v7; // r8
  __int64 result; // rax

  v4 = Msg - 272;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v5 = wParam - 1000;
      if ( !v5 )
      {
        EndDialog(hWndDlg, 1i64);
        return 1i64;
      }
      v6 = v5 - 1;
      if ( !v6 )
      {
        EndDialog(hWndDlg, 2i64);
        return 1i64;
      }
      v7 = v6 - 1;
      if ( !v7 )
      {
        EndDialog(hWndDlg, 3i64);
        return 1i64;
      }
      if ( v7 == 1 )
      {
        EndDialog(hWndDlg, 4i64);
        return 1i64;
      }
    }
    result = 0i64;
  }
  else
  {
    ActionTreeMessageDialog::OnInitWin((ActionTreeMessageDialog *)lParam, hWndDlg);
    result = 1i64;
  }
  return result;
}

// File Line: 214
// RVA: 0x270030
void __fastcall ActionTreeMessageDialog::OnInitWin(ActionTreeMessageDialog *this, HWND__ *hWndDlg)
{
  HWND__ *v2; // r12
  ActionTreeMessageDialog *v3; // r15
  HWND v4; // r14
  HWND v5; // rbp
  HWND v6; // rsi
  HWND v7; // rdi
  HWND v8; // rbx

  v2 = hWndDlg;
  v3 = this;
  v4 = GetDlgItem(hWndDlg, -1);
  v5 = GetDlgItem(v2, 1000);
  v6 = GetDlgItem(v2, 1001);
  v7 = GetDlgItem(v2, 1002);
  v8 = GetDlgItem(v2, 1003);
  SetWindowTextA(v2, "ActionTree Message");
  SetWindowTextA(v4, v3->mMessageText.mData);
  SetWindowTextA(v5, v3->mButton1Text.mData);
  SetWindowTextA(v6, v3->mButton2Text.mData);
  SetWindowTextA(v7, v3->mButton3Text.mData);
  SetWindowTextA(v8, v3->mButton4Text.mData);
  SetTimer(v2, (UINT_PTR)v3, 0x21u, (TIMERPROC)_);
  v3->mhWndDlg = v2;
}

// File Line: 270
// RVA: 0x26B100
signed __int64 ActionTreeDebugMessageHandler(const char *msg, ...)
{
  HMODULE v1; // rax
  unsigned int v2; // ebx
  LPARAM dwInitParam; // [rsp+40h] [rbp-C0h]
  UFG::qString v5; // [rsp+48h] [rbp-B8h]
  UFG::qString v6; // [rsp+70h] [rbp-90h]
  UFG::qString v7; // [rsp+98h] [rbp-68h]
  UFG::qString v8; // [rsp+C0h] [rbp-40h]
  UFG::qString v9; // [rsp+E8h] [rbp-18h]
  unsigned int v10; // [rsp+110h] [rbp+10h]
  char dest; // [rsp+120h] [rbp+20h]
  va_list va; // [rsp+948h] [rbp+848h]

  va_start(va, msg);
  if ( !msg )
    return 1i64;
  dest = 0;
  UFG::qVSPrintf(&dest, 2048, msg, va);
  UFG::qPrintf("%s", &dest);
  UFG::qString::qString(&v5);
  UFG::qString::qString(&v6);
  UFG::qString::qString(&v7);
  UFG::qString::qString(&v8);
  UFG::qString::qString(&v9);
  v10 = -1;
  UFG::qString::Set(&v5, &dest);
  UFG::qString::Set(&v6, "ClearBreakPoint");
  UFG::qString::Set(&v7, "ClearAllBreakPoints");
  UFG::qString::Set(&v8, "BreakInCode(CodersOnly)");
  UFG::qString::Set(&v9, "Skip");
  v1 = GetModuleHandleA(0i64);
  v2 = DialogBoxIndirectParamA(v1, &dlg_4buttonWithText, 0i64, DlgProc, (LPARAM)&dwInitParam);
  KillTimer((HWND)dwInitParam, 0x3ECui64);
  v10 = v2;
  UFG::qString::~qString(&v9);
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&v7);
  UFG::qString::~qString(&v6);
  UFG::qString::~qString(&v5);
  return v2;
}

