// File Line: 40
// RVA: 0x1480770
__int64 dynamic_initializer_for__PrintTrackLocationEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&PrintTrackLocationEnum, gPrintTrackLocationStringList, 3, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__PrintTrackLocationEnum__);
}

// File Line: 166
// RVA: 0x26D8A0
__int64 __fastcall DlgProc(HWND hWndDlg, unsigned int Msg, unsigned __int64 wParam, ActionTreeMessageDialog *lParam)
{
  int v4; // edx
  __int64 v5; // r8
  __int64 v6; // r8
  __int64 v7; // r8

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
    return 0i64;
  }
  else
  {
    ActionTreeMessageDialog::OnInitWin(lParam, hWndDlg);
    return 1i64;
  }
}

// File Line: 214
// RVA: 0x270030
void __fastcall ActionTreeMessageDialog::OnInitWin(ActionTreeMessageDialog *this, HWND hWndDlg)
{
  HWND DlgItem; // r14
  HWND v5; // rbp
  HWND v6; // rsi
  HWND v7; // rdi
  HWND v8; // rbx

  DlgItem = GetDlgItem(hWndDlg, -1);
  v5 = GetDlgItem(hWndDlg, 1000);
  v6 = GetDlgItem(hWndDlg, 1001);
  v7 = GetDlgItem(hWndDlg, 1002);
  v8 = GetDlgItem(hWndDlg, 1003);
  SetWindowTextA(hWndDlg, "ActionTree Message");
  SetWindowTextA(DlgItem, this->mMessageText.mData);
  SetWindowTextA(v5, this->mButton1Text.mData);
  SetWindowTextA(v6, this->mButton2Text.mData);
  SetWindowTextA(v7, this->mButton3Text.mData);
  SetWindowTextA(v8, this->mButton4Text.mData);
  SetTimer(hWndDlg, (UINT_PTR)this, 0x21u, (TIMERPROC)_);
  this->mhWndDlg = hWndDlg;
}

// File Line: 270
// RVA: 0x26B100
__int64 ActionTreeDebugMessageHandler(const char *msg, ...)
{
  HMODULE ModuleHandleA; // rax
  unsigned int v2; // ebx
  LPARAM dwInitParam; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qString v5; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qString v6; // [rsp+70h] [rbp-90h] BYREF
  UFG::qString v7; // [rsp+98h] [rbp-68h] BYREF
  UFG::qString v8; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qString v9; // [rsp+E8h] [rbp-18h] BYREF
  unsigned int v10; // [rsp+110h] [rbp+10h]
  char dest[2064]; // [rsp+120h] [rbp+20h] BYREF
  va_list va; // [rsp+948h] [rbp+848h] BYREF

  va_start(va, msg);
  if ( !msg )
    return 1i64;
  dest[0] = 0;
  UFG::qVSPrintf(dest, 2048, msg, va);
  UFG::qPrintf("%s", dest);
  UFG::qString::qString(&v5);
  UFG::qString::qString(&v6);
  UFG::qString::qString(&v7);
  UFG::qString::qString(&v8);
  UFG::qString::qString(&v9);
  v10 = -1;
  UFG::qString::Set(&v5, dest);
  UFG::qString::Set(&v6, "ClearBreakPoint");
  UFG::qString::Set(&v7, "ClearAllBreakPoints");
  UFG::qString::Set(&v8, "BreakInCode(CodersOnly)");
  UFG::qString::Set(&v9, "Skip");
  ModuleHandleA = GetModuleHandleA(0i64);
  v2 = DialogBoxIndirectParamA(ModuleHandleA, &dlg_4buttonWithText, 0i64, DlgProc, (LPARAM)&dwInitParam);
  KillTimer((HWND)dwInitParam, 0x3ECui64);
  v10 = v2;
  UFG::qString::~qString(&v9);
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&v7);
  UFG::qString::~qString(&v6);
  UFG::qString::~qString(&v5);
  return v2;
}

