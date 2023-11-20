// File Line: 132
// RVA: 0x15AE0A0
__int64 UFG::_dynamic_initializer_for__sRawInputState__()
{
  return atexit(UFG::_dynamic_atexit_destructor_for__sRawInputState__);
}

// File Line: 349
// RVA: 0xA3CC70
bool __fastcall UFG::InputState::IsPressed(UFG::InputState *this, int key)
{
  int v2; // eax
  unsigned int v3; // eax

  if ( key == 18 )
  {
    LOWORD(v3) = GetKeyState(18);
    v2 = (v3 >> 15) & 1;
  }
  else if ( key == 32 )
  {
    LOBYTE(v2) = gSpaceBarState != 0;
  }
  else
  {
    LOBYTE(v2) = this->mKeyState[key] < 0;
  }
  return v2;
}

// File Line: 392
// RVA: 0xA3D380
char __fastcall UFG::LocalMapVirtualKey(unsigned int wParam, unsigned int lParam)
{
  unsigned int v2; // ebx
  char result; // al
  char v4; // al
  unsigned int v5; // ebx
  unsigned int v6; // eax
  char v7; // al

  v2 = lParam & 0x1000000;
  if ( !(lParam & 0x1000000) && (unsigned int)BYTE2(lParam) - 71 <= 0xC )
    return keypad_codes[BYTE2(lParam) - 71];
  switch ( wParam )
  {
    case 0x10u:
      goto LABEL_23;
    case 0x11u:
      if ( v2 )
        return -93;
      v5 = GetAsyncKeyState(162);
      LOWORD(v6) = GetAsyncKeyState(165);
      v7 = (v6 >> 15) & 1;
      if ( (v5 >> 15) & 1 && v7 )
        result = -91;
      else
        result = -94;
      return result;
    case 0x12u:
      return (v2 != 0) - 92;
    case 0x5Du:
LABEL_23:
      LOBYTE(wParam) = MapVirtualKeyA(BYTE2(lParam), 3u);
      break;
  }
  if ( (_BYTE)wParam == 13 )
  {
    v4 = 13;
    if ( v2 )
      v4 = 94;
    LOBYTE(wParam) = v4;
  }
  return wParam;
}

// File Line: 471
// RVA: 0xA3EBF0
void __fastcall UFG::Update_Cursor_Clip_and_Hide(HWND__ *hWnd)
{
  HWND__ *v1; // rdi
  bool v2; // bl
  tagCURSORINFO pci; // [rsp+20h] [rbp-28h]
  tagPOINT Point; // [rsp+58h] [rbp+10h]

  v1 = hWnd;
  pci.cbSize = 24;
  GetCursorInfo(&pci);
  v2 = pci.flags == 0;
  if ( UFG::InputSystem::msApplicationHasFocus
    && UFG::InputSystem::msPCKeyboardSwapMode != 1
    && UFG::InputSystem::msShouldRestrictCursor )
  {
    Point = (tagPOINT)0x100000001i64;
    ClientToScreen(v1, &Point);
    GetClientRect(v1, &rcClip);
    *(tagPOINT *)&rcClip.left = Point;
    rcClip.right += Point.x - 2;
    rcClip.bottom += Point.y - 2;
    if ( !is_clipped )
    {
      ClipCursor(&rcClip);
      is_clipped = 1;
    }
    UFG::InputSystem::msCursorCurrentlyRestricted = 1;
  }
  else
  {
    if ( is_clipped )
    {
      ClipCursor(0i64);
      is_clipped = 0;
    }
    UFG::InputSystem::msCursorCurrentlyRestricted = 0;
  }
  if ( UFG::InputSystem::msShouldHideCursor )
  {
    if ( !v2 )
      ShowCursor(0);
    UFG::InputSystem::msCursorCurrentlyHidden = 1;
  }
  else
  {
    if ( v2 )
      ShowCursor(1);
    UFG::InputSystem::msCursorCurrentlyHidden = 0;
  }
  if ( hCursorOverride )
    SetCursor(hCursorOverride);
}

// File Line: 545
// RVA: 0xA3ACA0
void __fastcall UFG::AllowAccessibilityShortcutKeys(bool bAllowKeys)
{
  __int64 *v1; // r8
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax
  __int64 v4; // [rsp+20h] [rbp-28h]
  __int64 v5; // [rsp+28h] [rbp-20h]
  __int64 v6; // [rsp+30h] [rbp-18h]
  tagSTICKYKEYS pvParam; // [rsp+58h] [rbp+10h]
  tagTOGGLEKEYS v8; // [rsp+60h] [rbp+18h]

  if ( bAllowKeys )
  {
    SystemParametersInfoA(0x3Bu, 8u, &g_StartupStickyKeys, 0);
    SystemParametersInfoA(0x35u, 8u, &g_StartupToggleKeys, 0);
    v1 = (__int64 *)&g_StartupFilterKeys;
LABEL_9:
    SystemParametersInfoA(0x33u, 0x18u, v1, 0);
    return;
  }
  pvParam = g_StartupStickyKeys;
  v2 = *(unsigned __int64 *)&g_StartupStickyKeys >> 32;
  if ( !(g_StartupStickyKeys.dwFlags & 1) )
  {
    pvParam.dwFlags = v2 & 0xFFFFFFF3;
    SystemParametersInfoA(0x3Bu, 8u, &pvParam, 0);
  }
  v8 = g_StartupToggleKeys;
  v3 = *(unsigned __int64 *)&g_StartupToggleKeys >> 32;
  if ( !(g_StartupToggleKeys.dwFlags & 1) )
  {
    v8.dwFlags = v3 & 0xFFFFFFF3;
    SystemParametersInfoA(0x35u, 8u, &v8, 0);
  }
  v5 = *(_QWORD *)&g_StartupFilterKeys.iWaitMSec;
  v4 = *(_QWORD *)&g_StartupFilterKeys.cbSize;
  v6 = *(_QWORD *)&g_StartupFilterKeys.iRepeatMSec;
  if ( !(g_StartupFilterKeys.dwFlags & 1) )
  {
    v1 = &v4;
    HIDWORD(v4) = g_StartupFilterKeys.dwFlags & 0xFFFFFFF3;
    goto LABEL_9;
  }
}

// File Line: 622
// RVA: 0xA3AF60
void __fastcall UFG::DispatchUIMouseEvent(unsigned int uMsg, int mouse_x, int mouse_y)
{
  int v3; // edi
  int v4; // esi
  unsigned int v5; // ebp
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::allocator::free_link *v8; // rax

  v3 = mouse_y;
  v4 = mouse_x;
  v5 = uMsg;
  v6 = UFG::qMalloc(0x50ui64, "UIScreenMouseInput", 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::Event::`vftable;
    v7[4].mNext = (UFG::allocator::free_link *)"UIScreenMouseInput";
    LODWORD(v7[3].mNext) = UFG::qStringHash32("UIScreenMouseInput", 0xFFFFFFFF);
    v7->mNext = (UFG::allocator::free_link *)&UFG::UIMouseEvent::`vftable;
    v7[7].mNext = 0i64;
    v7[8].mNext = 0i64;
    LODWORD(v7[9].mNext) = 0;
  }
  else
  {
    v7 = 0i64;
  }
  LODWORD(v7[7].mNext) = v5;
  HIDWORD(v7[7].mNext) = v4;
  LODWORD(v7[8].mNext) = v3;
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v7);
}

// File Line: 631
// RVA: 0xA3BBC0
__int64 __fastcall UFG::InputPlat_MsgProc(HWND__ *hWnd, unsigned int uMsg, unsigned __int64 wParam, __int64 lParam, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15, __int64 a16, __int64 a17, __int64 a18, __int64 a19, __int64 a20, __int64 a21, __int64 a22, __int64 a23, __int64 a24, unsigned int a25, UFG::Event *a26, HRAWINPUT a27)
{
  unsigned __int64 v27; // r12
  unsigned int v28; // er15
  HWND__ *v29; // r13
  HRAWINPUT v30; // rcx
  int v31; // edi
  int v32; // er14
  __int64 v33; // rsi
  UFG::allocator::free_link *v34; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v35; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v36; // rax
  char v37; // cl
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v38; // rax
  __int16 v39; // bx
  __int16 v40; // di
  UFG::allocator::free_link *v41; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v42; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v43; // rax
  unsigned __int8 v44; // r15
  __int64 v45; // rcx
  signed int v46; // ecx
  UINT v47; // ebx
  UFG::allocator::free_link *v48; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v49; // rdx
  int v50; // ecx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v51; // rax
  UFG::allocator::free_link *v52; // rax
  UFG::Event *v53; // rbx
  UFG::allocator::free_link *v54; // rax
  UINT v56; // edi
  __int64 v57; // rax
  UINT v58; // ebx
  unsigned int v59; // eax
  UFG::allocator::free_link *v60; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v61; // rdx
  int v62; // ecx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v63; // rax
  UFG::allocator::free_link *v64; // rax
  UFG::Event *v65; // rbx
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::Event *v68; // rbx
  UFG::allocator::free_link *v69; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v70; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v71; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v72; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v73; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v74; // rax
  UFG::allocator::free_link *v75; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v76; // rcx
  UFG::allocator::free_link *v77; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v78; // rax
  UFG::allocator::free_link *v79; // rax
  __int64 v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v82; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v83; // rax
  int v84; // edi
  int v85; // er14
  UFG::allocator::free_link *v86; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v87; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v88; // rax
  UFG::allocator::free_link *v89; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v90; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v91; // rax
  UFG::allocator::free_link *v92; // rax
  UFG::allocator::free_link *v93; // rax
  UFG::allocator::free_link *v94; // rax
  UFG::allocator::free_link *v95; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v96; // rcx
  UFG::allocator::free_link *v97; // rax
  UFG::allocator::free_link *v98; // rax
  UFG::allocator::free_link *v99; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v100; // rax
  UFG::allocator::free_link *v101; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v102; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v103; // rax
  UFG::allocator::free_link *v104; // rax
  UFG::allocator::free_link *v105; // rax
  UFG::allocator::free_link *v106; // rax
  UFG::allocator::free_link *v107; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v108; // rcx
  __int16 v109; // r12
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v110; // rax
  UFG::allocator::free_link *v111; // rax
  __int64 v112; // rax
  tagWINDOWINFO pwi; // [rsp+138h] [rbp-190h]
  tagTRACKMOUSEEVENT EventTrack; // [rsp+178h] [rbp-150h]
  int v115; // [rsp+248h] [rbp-80h]
  __int64 v116; // [rsp+250h] [rbp-78h]
  BYTE v117; // [rsp+258h] [rbp-70h]

  v116 = -2i64;
  v27 = wParam;
  v28 = uMsg;
  v29 = hWnd;
  InstallKeyboardHook(1);
  v30 = a27;
  v31 = (unsigned __int16)a27;
  v32 = WORD1(a27);
  a27 = (HRAWINPUT)(v27 >> 16);
  v33 = 0i64;
  a25 = (WORD1(v27) != 1) + 5;
  if ( v28 <= 0x200 )
  {
    if ( v28 == 0x200 )
    {
      if ( !mouse_tracking_enabled )
      {
        mouse_tracking_enabled = 1;
        EventTrack.cbSize = 24;
        EventTrack.dwFlags = 2;
        EventTrack.hwndTrack = v29;
        v115 = -1;
        TrackMouseEvent(&EventTrack);
      }
      if ( sIgnore_next_mouse_move )
      {
        sIgnore_next_mouse_move = 0;
        pwi.cbSize = 60;
        GetWindowInfo(v29, &pwi);
        UFG::InputSystem::msMouseArea = (UFG::InputSystem::MouseArea)pwi.rcClient;
      }
      else
      {
        UFG::Update_Cursor_Clip_and_Hide(v29);
        if ( !UFG::InputSystem::msMouseInputRawAvailable
          || !UFG::InputSystem::msMouseInputRawDesired
          || !UFG::InputSystem::msRelativeMouseMode )
        {
          if ( (UFG::RawInputState *)UFG::sRawInputState.mInputMessages.mNode.mNext != &UFG::sRawInputState )
          {
            v70 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
            if ( LOBYTE(UFG::sRawInputState.mInputMessages.mNode.mPrev[1].mPrev) == 4 )
            {
              v71 = UFG::sRawInputState.mInputMessages.mNode.mPrev->mPrev;
              v72 = UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext;
              v71->mNext = v72;
              v72->mPrev = v71;
              v70->mPrev = v70;
              v70->mNext = v70;
              a27 = (HRAWINPUT)v70;
              v73 = v70->mPrev;
              v74 = v70->mNext;
              v73->mNext = v74;
              v74->mPrev = v73;
              v70->mPrev = v70;
              v70->mNext = v70;
              operator delete[](v70);
            }
          }
          if ( UFG::InputSystem::msApplicationHasFocus )
          {
            v75 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v76 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v75;
            a27 = (HRAWINPUT)v75;
            if ( v75 )
            {
              v75->mNext = v75;
              v75[1].mNext = v75;
              LOWORD(v75[2].mNext) = 4;
              WORD1(v75[2].mNext) = v31;
              WORD2(v75[2].mNext) = v32;
              HIWORD(v75[2].mNext) = 0;
              LODWORD(v75[3].mNext) = 0;
            }
            else
            {
              v76 = 0i64;
            }
          }
          else
          {
            v77 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v76 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v77;
            a27 = (HRAWINPUT)v77;
            if ( v77 )
            {
              v77->mNext = v77;
              v77[1].mNext = v77;
              LOWORD(v77[2].mNext) = 6;
              WORD1(v77[2].mNext) = v31;
              WORD2(v77[2].mNext) = v32;
              HIWORD(v77[2].mNext) = 0;
              LODWORD(v77[3].mNext) = 0;
            }
            else
            {
              v76 = 0i64;
            }
          }
          v78 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v76;
          v76->mPrev = v78;
          v76->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v76;
        }
        v79 = UFG::qMalloc(0x50ui64, "UIScreenMouseInput", 0i64);
        a27 = (HRAWINPUT)v79;
        if ( v79 )
        {
          UFG::UIMouseEvent::UIMouseEvent((UFG::UIMouseEvent *)v79, "UIScreenMouseInput");
          v33 = v80;
        }
        *(_DWORD *)(v33 + 56) = 512;
        *(_DWORD *)(v33 + 60) = v31;
        *(_DWORD *)(v33 + 64) = v32;
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v33);
        if ( UFG::InputSystem::msCursorCurrentlyRestricted && UFG::InputSystem::msRelativeMouseMode )
        {
          pwi.cbSize = 60;
          GetWindowInfo(v29, &pwi);
          UFG::InputSystem::msMouseArea = (UFG::InputSystem::MouseArea)pwi.rcClient;
          SetCursorPos(
            pwi.rcClient.left + (pwi.rcClient.right - pwi.rcClient.left) / 2,
            pwi.rcClient.top + (pwi.rcClient.bottom - pwi.rcClient.top) / 2);
          sIgnore_next_mouse_move = 1;
        }
      }
      if ( in_use_x != v31 || in_use_y != v32 )
      {
        in_use_x = v31;
        in_use_y = v32;
        bMouseIsInUse = 1;
      }
      else
      {
        bMouseIsInUse = 0;
      }
      return 0i64;
    }
    if ( v28 <= 0xFF )
    {
      if ( v28 == 0xFF )
      {
        if ( UFG::InputSystem::msMouseInputRawAvailable
          && UFG::InputSystem::msMouseInputRawDesired
          && UFG::InputSystem::msRelativeMouseMode )
        {
          a25 = 48;
          GetRawInputData(v30, 0x10000003u, lpb, &a25, 0x18u);
          if ( !*(_DWORD *)lpb )
          {
            v39 = dword_14249CE94;
            v40 = dword_14249CE98;
            v41 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v42 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v41;
            a27 = (HRAWINPUT)v41;
            if ( v41 )
            {
              v41->mNext = v41;
              v41[1].mNext = v41;
              LOWORD(v41[2].mNext) = 5;
              WORD1(v41[2].mNext) = v39;
              WORD2(v41[2].mNext) = v40;
              HIWORD(v41[2].mNext) = 0;
              LODWORD(v41[3].mNext) = 0;
            }
            else
            {
              v42 = 0i64;
            }
            v43 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
            UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v42;
            v42->mPrev = v43;
            v42->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
            UFG::sRawInputState.mInputMessages.mNode.mPrev = v42;
          }
        }
      }
      else if ( v28 == 6 )
      {
        v34 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
        v35 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v34;
        a27 = (HRAWINPUT)v34;
        if ( v27 )
        {
          if ( v34 )
          {
            v34->mNext = v34;
            v34[1].mNext = v34;
            LODWORD(v34[2].mNext) = 1;
            *(UFG::allocator::free_link **)((char *)&v34[2].mNext + 4) = 0i64;
          }
          else
          {
            v35 = 0i64;
          }
          v38 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v35;
          v35->mPrev = v38;
          v35->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v35;
          v37 = 1;
          g_Fullscreen = g_savedFullscreen;
        }
        else
        {
          if ( v34 )
          {
            v34->mNext = v34;
            v34[1].mNext = v34;
            LODWORD(v34[2].mNext) = 0;
            *(UFG::allocator::free_link **)((char *)&v34[2].mNext + 4) = 0i64;
          }
          else
          {
            v35 = 0i64;
          }
          v36 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v35;
          v35->mPrev = v36;
          v35->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v35;
          v37 = 0;
          g_savedFullscreen = g_Fullscreen;
        }
        UFG::InputSystem::msApplicationHasFocus = v37;
        UFG::AllowAccessibilityShortcutKeys(v37 == 0);
      }
      return 0i64;
    }
    switch ( v28 )
    {
      case 0x100u:
      case 0x104u:
        v44 = UFG::LocalMapVirtualKey(v27, (unsigned int)v30);
        v45 = 0i64;
        while ( v44 != *(_BYTE *)(v45 + 5403268024i64) )
        {
          if ( ++v45 >= 4 )
          {
            v46 = gSpaceBarState;
            if ( v27 == 32 )
              v46 = 1;
            gSpaceBarState = v46;
            GetKeyboardState(&v117);
            v47 = MapVirtualKeyA(v44, 0);
            UFG::qMemSet(&a27, 0, 8u);
            ToUnicode(v44, v47, &v117, (LPWSTR)&a27, 4, 0);
            v48 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v49 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v48;
            a26 = (UFG::Event *)v48;
            if ( v48 )
            {
              v50 = (unsigned __int16)a27;
              v48->mNext = v48;
              v48[1].mNext = v48;
              LOBYTE(v48[2].mNext) = 2;
              BYTE1(v48[2].mNext) = v44;
              *(_DWORD *)((char *)&v48[2].mNext + 2) = 0;
              HIWORD(v48[2].mNext) = 0;
              LODWORD(v48[3].mNext) = v50;
            }
            else
            {
              v49 = 0i64;
            }
            v51 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
            UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v49;
            v49->mPrev = v51;
            v49->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
            UFG::sRawInputState.mInputMessages.mNode.mPrev = v49;
            v52 = UFG::qMalloc(0x38ui64, "UIScreenTextInput", 0i64);
            v53 = (UFG::Event *)v52;
            a26 = (UFG::Event *)v52;
            if ( v52 )
            {
              v54 = v52 + 1;
              v54->mNext = v54;
              v54[1].mNext = v54;
              v53->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
              v53->m_NamePTR = "UIScreenTextInput";
              v53->m_EventUID = UFG::qStringHash32("UIScreenTextInput", 0xFFFFFFFF);
            }
            else
            {
              v53 = 0i64;
            }
            v53->mUserData0 = 256i64;
            v53->mUserData1 = v44;
            UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v53);
            return 1i64;
          }
        }
        return 1i64;
      case 0x101u:
      case 0x105u:
        v56 = (unsigned __int8)UFG::LocalMapVirtualKey(v27, (unsigned int)v30);
        v57 = 0i64;
        break;
      case 0x102u:
        v67 = UFG::qMalloc(0x38ui64, "UIScreenTextInput", 0i64);
        v68 = (UFG::Event *)v67;
        a27 = (HRAWINPUT)v67;
        if ( v67 )
        {
          v69 = v67 + 1;
          v69->mNext = v69;
          v69[1].mNext = v69;
          v68->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
          v68->m_NamePTR = "UIScreenTextInput";
          v68->m_EventUID = UFG::qStringHash32("UIScreenTextInput", 0xFFFFFFFF);
        }
        else
        {
          v68 = 0i64;
        }
        v68->mUserData0 = 258i64;
        v68->mUserData1 = v27;
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v68);
        return 0i64;
      case 0x106u:
        return 1i64;
      default:
        return 0i64;
    }
    while ( (_BYTE)v56 != *(_BYTE *)(v57 + 5403268024i64) )
    {
      if ( ++v57 >= 4 )
      {
        GetKeyboardState(&v117);
        v58 = MapVirtualKeyA(v56, 0);
        UFG::qMemSet(&a27, 0, 8u);
        ToUnicode(v56, v58, &v117, (LPWSTR)&a27, 4, 0);
        v59 = gSpaceBarState;
        if ( v27 == 32 )
          v59 = 0;
        gSpaceBarState = v59;
        v60 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
        v61 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v60;
        a26 = (UFG::Event *)v60;
        if ( v60 )
        {
          v62 = (unsigned __int16)a27;
          v60->mNext = v60;
          v60[1].mNext = v60;
          LOBYTE(v60[2].mNext) = 3;
          BYTE1(v60[2].mNext) = v56;
          *(_DWORD *)((char *)&v60[2].mNext + 2) = 0;
          HIWORD(v60[2].mNext) = 0;
          LODWORD(v60[3].mNext) = v62;
        }
        else
        {
          v61 = 0i64;
        }
        v63 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
        UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v61;
        v61->mPrev = v63;
        v61->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
        UFG::sRawInputState.mInputMessages.mNode.mPrev = v61;
        v64 = UFG::qMalloc(0x38ui64, "UIScreenTextInput", 0i64);
        v65 = (UFG::Event *)v64;
        a26 = (UFG::Event *)v64;
        if ( v64 )
        {
          v66 = v64 + 1;
          v66->mNext = v66;
          v66[1].mNext = v66;
          v65->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
          v65->m_NamePTR = "UIScreenTextInput";
          v65->m_EventUID = UFG::qStringHash32("UIScreenTextInput", 0xFFFFFFFF);
        }
        else
        {
          v65 = 0i64;
        }
        v65->mUserData0 = 257i64;
        v65->mUserData1 = v27;
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v65);
        return 1i64;
      }
    }
    return 1i64;
  }
  if ( v28 <= 0x312 )
  {
    if ( v28 != 786 )
    {
      switch ( v28 )
      {
        case 0x201u:
          v89 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v90 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v89;
          a27 = (HRAWINPUT)v89;
          if ( v89 )
          {
            v89->mNext = v89;
            v89[1].mNext = v89;
            LOWORD(v89[2].mNext) = 263;
            WORD1(v89[2].mNext) = v31;
            WORD2(v89[2].mNext) = v32;
            HIWORD(v89[2].mNext) = 0;
            LODWORD(v89[3].mNext) = 0;
          }
          else
          {
            v90 = 0i64;
          }
          goto LABEL_98;
        case 0x202u:
        case 0x205u:
        case 0x208u:
        case 0x20Cu:
          switch ( v28 )
          {
            case 0x202u:
              v99 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
              v96 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v99;
              a27 = (HRAWINPUT)v99;
              if ( v99 )
              {
                v99->mNext = v99;
                v99[1].mNext = v99;
                LOWORD(v99[2].mNext) = 264;
                WORD1(v99[2].mNext) = v31;
                WORD2(v99[2].mNext) = v32;
                HIWORD(v99[2].mNext) = 0;
                LODWORD(v99[3].mNext) = 0;
              }
              else
              {
                v96 = 0i64;
              }
              break;
            case 0x205u:
              v98 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
              v96 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v98;
              a27 = (HRAWINPUT)v98;
              if ( v98 )
              {
                v98->mNext = v98;
                v98[1].mNext = v98;
                LOWORD(v98[2].mNext) = 520;
                WORD1(v98[2].mNext) = v31;
                WORD2(v98[2].mNext) = v32;
                HIWORD(v98[2].mNext) = 0;
                LODWORD(v98[3].mNext) = 0;
              }
              else
              {
                v96 = 0i64;
              }
              break;
            case 0x208u:
              v97 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
              v96 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v97;
              a27 = (HRAWINPUT)v97;
              if ( v97 )
              {
                v97->mNext = v97;
                v97[1].mNext = v97;
                LOWORD(v97[2].mNext) = 1032;
                WORD1(v97[2].mNext) = v31;
                WORD2(v97[2].mNext) = v32;
                HIWORD(v97[2].mNext) = 0;
                LODWORD(v97[3].mNext) = 0;
              }
              else
              {
                v96 = 0i64;
              }
              break;
            case 0x20Cu:
              v95 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
              v96 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v95;
              a27 = (HRAWINPUT)v95;
              if ( v95 )
              {
                v95->mNext = v95;
                v95[1].mNext = v95;
                LOBYTE(v95[2].mNext) = 8;
                BYTE1(v95[2].mNext) = a25;
                WORD1(v95[2].mNext) = v31;
                WORD2(v95[2].mNext) = v32;
                HIWORD(v95[2].mNext) = 0;
                LODWORD(v95[3].mNext) = 0;
              }
              else
              {
                v96 = 0i64;
              }
              break;
            default:
              goto LABEL_131;
          }
          v100 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v96;
          v96->mPrev = v100;
          v96->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v96;
LABEL_131:
          UFG::DispatchUIMouseEvent(v28, v31, v32);
          if ( !(v27 & 0x13) )
            ReleaseCapture();
          break;
        case 0x203u:
          v105 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v102 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v105;
          a27 = (HRAWINPUT)v105;
          if ( v105 )
          {
            v105->mNext = v105;
            v105[1].mNext = v105;
            LOWORD(v105[2].mNext) = 265;
            WORD1(v105[2].mNext) = v31;
            WORD2(v105[2].mNext) = v32;
            HIWORD(v105[2].mNext) = 0;
            LODWORD(v105[3].mNext) = 0;
          }
          else
          {
            v102 = 0i64;
          }
          goto LABEL_136;
        case 0x204u:
          v92 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v90 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v92;
          a27 = (HRAWINPUT)v92;
          if ( v92 )
          {
            v92->mNext = v92;
            v92[1].mNext = v92;
            LOWORD(v92[2].mNext) = 519;
            WORD1(v92[2].mNext) = v31;
            WORD2(v92[2].mNext) = v32;
            HIWORD(v92[2].mNext) = 0;
            LODWORD(v92[3].mNext) = 0;
          }
          else
          {
            v90 = 0i64;
          }
          goto LABEL_98;
        case 0x206u:
          v101 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v102 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v101;
          a27 = (HRAWINPUT)v101;
          if ( v101 )
          {
            v101->mNext = v101;
            v101[1].mNext = v101;
            LOWORD(v101[2].mNext) = 521;
            WORD1(v101[2].mNext) = v31;
            WORD2(v101[2].mNext) = v32;
            HIWORD(v101[2].mNext) = 0;
            LODWORD(v101[3].mNext) = 0;
          }
          else
          {
            v102 = 0i64;
          }
          goto LABEL_136;
        case 0x207u:
          v93 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v90 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v93;
          a27 = (HRAWINPUT)v93;
          if ( v93 )
          {
            v93->mNext = v93;
            v93[1].mNext = v93;
            LOWORD(v93[2].mNext) = 1031;
            WORD1(v93[2].mNext) = v31;
            WORD2(v93[2].mNext) = v32;
            HIWORD(v93[2].mNext) = 0;
            LODWORD(v93[3].mNext) = 0;
          }
          else
          {
            v90 = 0i64;
          }
          goto LABEL_98;
        case 0x209u:
          v104 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v102 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v104;
          a27 = (HRAWINPUT)v104;
          if ( v104 )
          {
            v104->mNext = v104;
            v104[1].mNext = v104;
            LOWORD(v104[2].mNext) = 1033;
            WORD1(v104[2].mNext) = v31;
            WORD2(v104[2].mNext) = v32;
            HIWORD(v104[2].mNext) = 0;
            LODWORD(v104[3].mNext) = 0;
          }
          else
          {
            v102 = 0i64;
          }
          goto LABEL_136;
        case 0x20Au:
          v107 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v108 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v107;
          a26 = (UFG::Event *)v107;
          if ( v107 )
          {
            v107->mNext = v107;
            v107[1].mNext = v107;
            LOWORD(v107[2].mNext) = 10;
            WORD1(v107[2].mNext) = v31;
            WORD2(v107[2].mNext) = v32;
            v109 = (signed __int16)a27;
            HIWORD(v107[2].mNext) = (_WORD)a27;
            LODWORD(v107[3].mNext) = 0;
          }
          else
          {
            v108 = 0i64;
            v109 = (signed __int16)a27;
          }
          v110 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v108;
          v108->mPrev = v110;
          v108->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v108;
          v111 = UFG::qMalloc(0x50ui64, "UIScreenMouseInput", 0i64);
          a27 = (HRAWINPUT)v111;
          if ( v111 )
          {
            UFG::UIMouseEvent::UIMouseEvent((UFG::UIMouseEvent *)v111, "UIScreenMouseInput");
            v33 = v112;
          }
          *(_DWORD *)(v33 + 56) = v28;
          *(_DWORD *)(v33 + 60) = v31;
          *(_DWORD *)(v33 + 64) = v32;
          *(_DWORD *)(v33 + 68) = a25;
          *(_DWORD *)(v33 + 72) = v109;
          UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v33);
          UFG::sRawInputState.mMouseWheelDelta += v109 / 120;
          return 0i64;
        case 0x20Bu:
          v94 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v90 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v94;
          a27 = (HRAWINPUT)v94;
          if ( v94 )
          {
            v94->mNext = v94;
            v94[1].mNext = v94;
            LOBYTE(v94[2].mNext) = 7;
            BYTE1(v94[2].mNext) = a25;
            WORD1(v94[2].mNext) = v31;
            WORD2(v94[2].mNext) = v32;
            HIWORD(v94[2].mNext) = 0;
            LODWORD(v94[3].mNext) = 0;
          }
          else
          {
            v90 = 0i64;
          }
LABEL_98:
          v91 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v90;
          v90->mPrev = v91;
          v90->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v90;
          SetCapture(v29);
          UFG::DispatchUIMouseEvent(v28, v31, v32);
          return 1i64;
        case 0x20Du:
          v106 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v102 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v106;
          a27 = (HRAWINPUT)v106;
          if ( v106 )
          {
            v106->mNext = v106;
            v106[1].mNext = v106;
            LOBYTE(v106[2].mNext) = 9;
            BYTE1(v106[2].mNext) = a25;
            WORD1(v106[2].mNext) = v31;
            WORD2(v106[2].mNext) = v32;
            HIWORD(v106[2].mNext) = 0;
            LODWORD(v106[3].mNext) = 0;
          }
          else
          {
            v102 = 0i64;
          }
LABEL_136:
          v103 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v102;
          v102->mPrev = v103;
          v102->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v102;
          return 1i64;
        case 0x219u:
          bCheckForNewController = 1;
          return 0i64;
        case 0x2A3u:
          v81 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v82 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v81;
          a27 = (HRAWINPUT)v81;
          if ( v81 )
          {
            v81->mNext = v81;
            v81[1].mNext = v81;
            LOWORD(v81[2].mNext) = 4;
            WORD1(v81[2].mNext) = -1;
            WORD2(v81[2].mNext) = -1;
            HIWORD(v81[2].mNext) = 0;
            LODWORD(v81[3].mNext) = 0;
          }
          else
          {
            v82 = 0i64;
          }
          v83 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v82;
          v82->mPrev = v83;
          v82->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v82;
          mouse_tracking_enabled = 0;
          if ( UFG::gInputSystem )
          {
            pwi.cbSize = 60;
            GetWindowInfo(v29, &pwi);
            UFG::InputSystem::msMouseArea = (UFG::InputSystem::MouseArea)pwi.rcClient;
            v84 = (pwi.rcClient.right - pwi.rcClient.left) / 2;
            v85 = (pwi.rcClient.bottom - pwi.rcClient.top) / 2;
            v86 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v87 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v86;
            a27 = (HRAWINPUT)v86;
            if ( v86 )
            {
              v86->mNext = v86;
              v86[1].mNext = v86;
              LOWORD(v86[2].mNext) = 4;
              WORD1(v86[2].mNext) = v84;
              WORD2(v86[2].mNext) = v85;
              HIWORD(v86[2].mNext) = 0;
              LODWORD(v86[3].mNext) = 0;
            }
            else
            {
              v87 = 0i64;
            }
            v88 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
            UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v87;
            v87->mPrev = v88;
            v87->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
            UFG::sRawInputState.mInputMessages.mNode.mPrev = v87;
            if ( UFG::InputSystem::msCursorCurrentlyRestricted )
            {
              SetCursorPos(
                (UFG::InputSystem::msMouseArea.mRight - UFG::InputSystem::msMouseArea.mLeft) / 2
              + UFG::InputSystem::msMouseArea.mLeft,
                UFG::InputSystem::msMouseArea.mTop
              + (UFG::InputSystem::msMouseArea.mBottom - UFG::InputSystem::msMouseArea.mTop) / 2);
              sIgnore_next_mouse_move = 1;
            }
          }
          return 0i64;
        default:
          return 0i64;
      }
    }
    return 1i64;
  }
  return 0i64;
}

// File Line: 1040
// RVA: 0xA3E190
void __fastcall UFG::SignalFalse(UFG::InputActionData *iad, bool buttonDown, const float elapsed_time)
{
  float v3; // xmm2_4
  UFG::eSignalType v4; // eax

  v3 = elapsed_time + iad->mOffSeconds;
  v4 = iad->mSignalType;
  iad->mActionTrue = 0;
  iad->mOffSeconds = v3;
  switch ( v4 )
  {
    case 0:
    case 3:
    case 8:
    case 11:
      if ( buttonDown == 1 )
        iad->mDebouncer = 1;
      break;
    case 1:
    case 2:
    case 6:
    case 7:
    case 9:
    case 10:
      if ( !buttonDown )
        iad->mDebouncer = 0;
      break;
    default:
      return;
  }
}

// File Line: 1073
// RVA: 0xA3E210
void __fastcall UFG::SignalTrue(UFG::InputActionData *iad, const float elapsed_time)
{
  UFG::eSignalType v2; // eax
  float v3; // xmm1_4
  float v4; // xmm1_4

  v2 = iad->mSignalType;
  iad->mActionTrue = 1;
  iad->mOffSeconds = 0.0;
  switch ( v2 )
  {
    case 0:
      if ( iad->mDebouncer == 1 )
      {
        iad->mDebouncer = 0;
        iad->mOnSeconds = 0.0;
        iad->mAxisPositionX = 0.0;
      }
      else
      {
        v4 = elapsed_time + iad->mOnSeconds;
        iad->mAxisPositionX = 0.0;
        iad->mOnSeconds = v4;
      }
      break;
    case 1:
    case 6:
    case 9:
      if ( iad->mDebouncer )
      {
        v3 = elapsed_time + iad->mOnSeconds;
        iad->mAxisPositionX = 1.0;
        iad->mOnSeconds = v3;
      }
      else
      {
        iad->mDebouncer = 1;
        iad->mOnSeconds = 0.0;
        iad->mAxisPositionX = 1.0;
      }
      break;
    case 2:
    case 7:
    case 10:
      iad->mDebouncer = 1;
      iad->mAxisPositionX = 1.0;
      iad->mOnSeconds = 0.0;
      break;
    case 3:
    case 8:
    case 11:
      iad->mDebouncer = 0;
      iad->mAxisPositionX = 0.0;
      iad->mOnSeconds = 0.0;
      break;
    default:
      return;
  }
}

// File Line: 1131
// RVA: 0xA3AD90
void __fastcall UFG::BasicButtonStub(UFG::InputActionData *inputActionData, bool buttonDown, const float elapsed_time)
{
  bool v3; // al

  switch ( inputActionData->mSignalType )
  {
    case 0:
      v3 = buttonDown == 0;
      goto LABEL_4;
    case 1:
    case 6:
    case 9:
      v3 = buttonDown;
LABEL_4:
      if ( !v3 )
        goto LABEL_5;
      goto LABEL_11;
    case 2:
    case 7:
    case 0xA:
      if ( !buttonDown )
        goto LABEL_5;
      if ( !inputActionData->mDebouncer )
        goto LABEL_11;
      UFG::SignalFalse(inputActionData, buttonDown, elapsed_time);
      return;
    case 3:
    case 8:
    case 0xB:
      if ( buttonDown || inputActionData->mDebouncer != 1 )
        goto LABEL_5;
LABEL_11:
      UFG::SignalTrue(inputActionData, elapsed_time);
      break;
    default:
LABEL_5:
      UFG::SignalFalse(inputActionData, buttonDown, elapsed_time);
      break;
  }
}

// File Line: 1167
// RVA: 0xA3D280
void __fastcall UFG::Left_Stick_Click_Deadzone_Handler(UFG::Controller *controller, UFG::InputActionData *iad, const float elapsed_time, bool buttonDown)
{
  bool v4; // bl
  UFG::InputActionData *v5; // rdi
  signed __int16 *v6; // rax
  float v7; // xmm1_4
  bool v8; // dl

  v4 = buttonDown;
  v5 = iad;
  v6 = (signed __int16 *)_RTDynamicCast(
                           controller,
                           0,
                           &UFG::Controller `RTTI Type Descriptor,
                           &UFG::Gamepad `RTTI Type Descriptor,
                           0);
  v8 = 0;
  if ( (float)((float)((float)v6[1062] * 0.000030517578) * (float)((float)v6[1062] * 0.000030517578)) < 0.85000002 )
  {
    v7 = (float)v6[1063] * -0.000030517578;
    if ( (float)(v7 * v7) < 0.85000002 )
      v8 = 1;
  }
  switch ( v5->mSignalType )
  {
    case 1:
    case 6:
    case 9:
      if ( !v8 && v4 )
        v4 = v5->mActionTrue;
      break;
    case 2:
    case 7:
    case 0xA:
      if ( !v8 && v4 )
        v4 = 0;
      break;
    default:
      break;
  }
  UFG::BasicButtonStub(v5, v4, elapsed_time);
}

// File Line: 1214
// RVA: 0xA3D970
void __fastcall UFG::Remote_IAD_Func(UFG::RawPadData *remoteData, UFG::Controller *controller, UFG::InputActionData *inputActionData, const float elapsed_time)
{
  UFG::Controller *v4; // rsi
  __int64 v5; // rdx
  char v6; // di
  UFG::InputActionData *v7; // rbx
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  float v10; // xmm2_4
  float v11; // xmm6_4
  float v12; // xmm8_4
  __m128 v13; // xmm7
  __m128i v14; // xmm8
  __m128i v15; // xmm7
  float v16; // xmm8_4
  float v17; // eax
  float v18; // xmm0_4
  float v19; // xmm9_4
  float v20; // xmm7_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm11_4
  float v24; // xmm8_4
  float v25; // xmm8_4
  float v26; // eax
  float v27; // xmm0_4
  float v28; // xmm11_4
  float v29; // xmm8_4
  float v30; // xmm8_4
  float v31; // xmm9_4
  float v32; // xmm7_4
  float v33; // xmm8_4
  float v34; // eax
  float v35; // xmm0_4
  float v36; // xmm9_4
  float v37; // xmm7_4
  float v38; // xmm7_4
  float v39; // xmm0_4
  float v40; // xmm11_4
  float v41; // xmm8_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm8_4
  float v45; // eax
  float v46; // xmm0_4
  float v47; // xmm11_4
  float v48; // xmm8_4
  float v49; // xmm8_4
  float v50; // xmm7_4
  signed int v51; // eax
  float v52; // eax
  float v53; // eax
  float v54; // xmm8_4
  float v55; // xmm7_4
  bool v56; // zf

  v4 = controller;
  v5 = inputActionData->mButton;
  v6 = 0;
  v7 = inputActionData;
  if ( (unsigned int)v5 < 0x80 )
  {
    v8 = remoteData->mGetXIState_Gamepad_wButtons;
    v9 = UFG::XINPUT_BUTTON_MASKS[v5];
    if ( remoteData->mGetXIState_Gamepad_wButtons & 0xF3FF )
      v4->m_ControllerInUse = 1;
    v10 = elapsed_time;
    v6 = (v9 & v8) != 0;
    if ( inputActionData->mButton == 10 )
      UFG::Left_Stick_Click_Deadzone_Handler(v4, inputActionData, elapsed_time, v6);
    else
LABEL_87:
      UFG::BasicButtonStub(inputActionData, v6, v10);
LABEL_88:
    if ( v6 )
    {
      if ( v4 )
      {
        v4->m_fTimeSinceLastInput = 0.0;
        v4->m_ControllerInUse = 1;
      }
    }
    return;
  }
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0i64;
  if ( (_DWORD)v5 == 137 )
  {
    v14 = _mm_cvtsi32_si128(remoteData->mGetState_lX);
    v15 = _mm_cvtsi32_si128(remoteData->mGetState_lY);
  }
  else if ( (_DWORD)v5 == 138 )
  {
    v14 = _mm_cvtsi32_si128(remoteData->mGetState_lZ);
    v15 = _mm_cvtsi32_si128(remoteData->mGetState_lRz);
  }
  else
  {
    if ( (_DWORD)v5 != 139 )
    {
      if ( (_DWORD)v5 == 140 )
      {
        v12 = (float)remoteData->mGetXIState_Gamepad_sThumbLX * 0.030517576;
        v13 = (__m128)COERCE_UNSIGNED_INT((float)remoteData->mGetXIState_Gamepad_sThumbLY);
        v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
      }
      else if ( (_DWORD)v5 == 141 )
      {
        v12 = (float)remoteData->mGetXIState_Gamepad_sThumbRX * 0.030517576;
        v13 = (__m128)COERCE_UNSIGNED_INT((float)remoteData->mGetXIState_Gamepad_sThumbRY);
        v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
      }
      goto LABEL_17;
    }
    v14 = _mm_cvtsi32_si128(remoteData->mGetState_lRx);
    v15 = _mm_cvtsi32_si128(remoteData->mGetState_lRy);
  }
  LODWORD(v12) = (unsigned __int128)_mm_cvtepi32_ps(v14);
  v13 = _mm_cvtepi32_ps(v15);
LABEL_17:
  switch ( (_DWORD)v5 )
  {
    case 0x81:
      v56 = remoteData->mGetState_rgdwPOV0 == 27000;
      goto LABEL_86;
    case 0x82:
      v56 = remoteData->mGetState_rgdwPOV0 == 9000;
      goto LABEL_86;
    case 0x83:
      v56 = remoteData->mGetState_rgdwPOV0 == 0;
      goto LABEL_86;
    case 0x84:
      v56 = remoteData->mGetState_rgdwPOV0 == 18000;
LABEL_86:
      v10 = elapsed_time;
      v6 = v56;
      goto LABEL_87;
    case 0x85:
      v50 = (float)remoteData->mGetState_lZ * 0.001;
      goto LABEL_73;
    case 0x86:
      v50 = (float)remoteData->mGetState_lZ * -0.001;
      goto LABEL_73;
    case 0x87:
      v51 = (unsigned __int8)remoteData->mGetXIState_Gamepad_bLeftTrigger;
      goto LABEL_72;
    case 0x88:
      v51 = (unsigned __int8)remoteData->mGetXIState_Gamepad_bRightTrigger;
LABEL_72:
      v50 = (float)v51 * 0.0039215689;
LABEL_73:
      inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
      inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
      v52 = inputActionData->mAxisRawY[1];
      inputActionData->mAxisRawX[0] = v50;
      inputActionData->mAxisRawY[2] = v52;
      v53 = inputActionData->mAxisRawY[0];
      inputActionData->mAxisRawY[0] = 0.0;
      inputActionData->mAxisRawY[1] = v53;
      v54 = signal_dead_zones[inputActionData->mSignalType];
      if ( v50 <= v54 )
      {
        v50 = 0.0;
        v6 = 0;
      }
      else
      {
        v6 = 1;
      }
      UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
      if ( v50 < 0.0 )
      {
        if ( (float)(v54 + v50) <= 0.0 )
          v11 = v54 + v50;
      }
      else
      {
        v55 = v50 - v54;
        if ( v55 >= 0.0 )
          v11 = v55;
      }
      v7->mAxisPositionY = 0.0;
      v7->mAxisPositionX = v11 / (float)(1.0 - v54);
      goto LABEL_88;
    case 0x89:
      v33 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
      inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
      v34 = inputActionData->mAxisRawY[1];
      inputActionData->mAxisRawX[0] = v33;
      inputActionData->mAxisRawY[2] = v34;
      inputActionData->mAxisRawY[1] = inputActionData->mAxisRawY[0];
      LODWORD(inputActionData->mAxisRawY[0]) = v13.m128_i32[0];
      v35 = atan2f(v13.m128_f32[0], v33);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v33 * v33);
      v36 = v35;
      v37 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.30000001;
      if ( v37 < 0.0 )
        v37 = 0.0;
      v38 = v37 * 1.4285715;
      if ( v38 > 0.050000001 )
      {
        v39 = v35 - -1.5707964;
        if ( (float)(v36 - -1.5707964) >= 0.0 )
        {
          if ( v39 >= 0.19 )
          {
            if ( v39 < 0.38 )
              v36 = (float)((float)((float)(v39 - 0.19) * 5.2631578) * 0.38) - 1.5707964;
          }
          else
          {
            v36 = FLOAT_N1_5707964;
          }
        }
        else if ( v39 <= -0.19 )
        {
          if ( v39 > -0.38 )
            v36 = -1.5707964 - (float)((float)((float)(v39 + 0.19) * -5.2631578) * 0.38);
        }
        else
        {
          v36 = FLOAT_N1_5707964;
        }
      }
      v40 = cosf(v36) * v38;
      v41 = sinf(v36) * v38;
      if ( v40 != 0.0 || v41 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v7, v6, elapsed_time);
      v56 = v7->mSignalType == 5;
      v7->mAxisPositionX = v40;
      v7->mAxisPositionY = v41;
      if ( !v56 || v7->mButton - 138 > 1 )
        goto LABEL_88;
      v42 = v41;
      v43 = v40;
      goto LABEL_67;
    case 0x8A:
    case 0x8B:
      v44 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
      inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
      v45 = inputActionData->mAxisRawY[1];
      inputActionData->mAxisRawX[0] = v44;
      inputActionData->mAxisRawY[2] = v45;
      inputActionData->mAxisRawY[1] = inputActionData->mAxisRawY[0];
      LODWORD(inputActionData->mAxisRawY[0]) = v13.m128_i32[0];
      v46 = atan2f(v13.m128_f32[0], v44);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v44 * v44);
      v47 = v46;
      v48 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.30000001;
      if ( v48 < 0.0 )
        v48 = 0.0;
      v49 = v48 * 1.4285715;
      v31 = cosf(v46) * v49;
      v32 = sinf(v47) * v49;
      if ( v31 != 0.0 || v32 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v7, v6, elapsed_time);
      v56 = v7->mSignalType == 5;
      v7->mAxisPositionX = v31;
      v7->mAxisPositionY = v32;
      if ( !v56 || v7->mButton - 138 > 1 )
        goto LABEL_88;
      goto LABEL_66;
    case 0x8C:
      v16 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
      inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
      v17 = inputActionData->mAxisRawY[1];
      inputActionData->mAxisRawX[0] = v16;
      inputActionData->mAxisRawY[2] = v17;
      inputActionData->mAxisRawY[1] = inputActionData->mAxisRawY[0];
      LODWORD(inputActionData->mAxisRawY[0]) = v13.m128_i32[0];
      v18 = atan2f(v13.m128_f32[0], v16);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v16 * v16);
      v19 = v18;
      v20 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.33774078;
      if ( v20 < 0.0 )
        v20 = 0.0;
      v21 = v20 * 1.5099827;
      if ( v21 > 0.050000001 )
      {
        v22 = v18 - -1.5707964;
        if ( (float)(v19 - -1.5707964) >= 0.0 )
        {
          if ( v22 >= 0.19 )
          {
            if ( v22 < 0.38 )
              v19 = (float)((float)((float)(v22 - 0.19) * 5.2631578) * 0.38) - 1.5707964;
          }
          else
          {
            v19 = FLOAT_N1_5707964;
          }
        }
        else if ( v22 <= -0.19 )
        {
          if ( v22 > -0.38 )
            v19 = -1.5707964 - (float)((float)((float)(v22 + 0.19) * -5.2631578) * 0.38);
        }
        else
        {
          v19 = FLOAT_N1_5707964;
        }
      }
      v23 = cosf(v19) * v21;
      v24 = sinf(v19) * v21;
      if ( v23 != 0.0 || v24 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v7, v6, elapsed_time);
      v7->mAxisPositionX = v23;
      v7->mAxisPositionY = v24;
      goto LABEL_88;
    case 0x8D:
      v25 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
      inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
      v26 = inputActionData->mAxisRawY[1];
      inputActionData->mAxisRawX[0] = v25;
      inputActionData->mAxisRawY[2] = v26;
      inputActionData->mAxisRawY[1] = inputActionData->mAxisRawY[0];
      LODWORD(inputActionData->mAxisRawY[0]) = v13.m128_i32[0];
      v27 = atan2f(v13.m128_f32[0], v25);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v25 * v25);
      v28 = v27;
      v29 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.37388578;
      if ( v29 < 0.0 )
        v29 = 0.0;
      v30 = v29 * 1.5971527;
      v31 = cosf(v27) * v30;
      v32 = sinf(v28) * v30;
      if ( v31 != 0.0 || v32 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v7, v6, elapsed_time);
      v56 = v7->mSignalType == 5;
      v7->mAxisPositionX = v31;
      v7->mAxisPositionY = v32;
      if ( v56 )
      {
LABEL_66:
        v42 = v32;
        v43 = v31;
LABEL_67:
        UFG::Controller::UpdateRightThumbHistory(v4, v43, v42, elapsed_time);
        v7->mActionTrue = UFG::Controller::RightStick_HoldThenFlickAcross(v4) != 0;
      }
      goto LABEL_88;
    default:
      return;
  }
}

// File Line: 1557
// RVA: 0xA3B160
void __fastcall UFG::Gamepad_IAD_Func(UFG::Controller *controller, UFG::InputActionData *inputActionData, const float elapsed_time)
{
  UFG::InputActionData *v3; // rbx
  float v4; // xmm9_4
  UFG::Controller *v5; // rsi
  char v6; // di
  signed __int16 *v7; // rax
  __int64 v8; // rcx
  signed __int16 v9; // ax
  unsigned __int16 v10; // r9
  float v11; // xmm6_4
  float v12; // xmm8_4
  __m128 v13; // xmm7
  __m128i v14; // xmm8
  __m128i v15; // xmm7
  float v16; // xmm8_4
  float v17; // eax
  float v18; // xmm0_4
  float v19; // xmm10_4
  float v20; // xmm7_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm11_4
  float v24; // xmm8_4
  float v25; // xmm8_4
  float v26; // eax
  float v27; // xmm0_4
  float v28; // xmm11_4
  float v29; // xmm8_4
  float v30; // xmm8_4
  float v31; // xmm10_4
  float v32; // xmm7_4
  float v33; // xmm8_4
  float v34; // eax
  float v35; // xmm0_4
  float v36; // xmm10_4
  float v37; // xmm7_4
  float v38; // xmm7_4
  float v39; // xmm0_4
  float v40; // xmm11_4
  float v41; // xmm8_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm8_4
  float v45; // eax
  float v46; // xmm0_4
  float v47; // xmm11_4
  float v48; // xmm8_4
  float v49; // xmm8_4
  float v50; // xmm7_4
  signed int v51; // eax
  float v52; // eax
  float v53; // eax
  float v54; // xmm8_4
  float v55; // xmm7_4
  bool v56; // zf

  v3 = inputActionData;
  v4 = elapsed_time;
  v5 = controller;
  if ( controller->mIsRemote )
  {
    UFG::Remote_IAD_Func(
      (UFG::RawPadData *)&controller[1].mInputState.mKeyState[224],
      controller,
      inputActionData,
      elapsed_time);
    return;
  }
  v6 = 0;
  v7 = (signed __int16 *)_RTDynamicCast(
                           controller,
                           0,
                           &UFG::Controller `RTTI Type Descriptor,
                           &UFG::Gamepad `RTTI Type Descriptor,
                           0);
  v8 = v3->mButton;
  if ( (unsigned int)v8 < 0x80 )
  {
    if ( *((_DWORD *)v7 + 460) < 0 )
    {
      v6 = *((_BYTE *)v7 + v8 + 1892) != 0;
    }
    else
    {
      v9 = v7[1060];
      v10 = UFG::XINPUT_BUTTON_MASKS[v8];
      if ( v9 & 0xF3FF )
        v5->m_ControllerInUse = 1;
      v6 = (v10 & (unsigned __int16)v9) != 0;
      if ( v3->mButton == 10 )
      {
        UFG::Left_Stick_Click_Deadzone_Handler(v5, v3, elapsed_time, v6);
        goto LABEL_92;
      }
    }
LABEL_91:
    UFG::BasicButtonStub(v3, v6, elapsed_time);
LABEL_92:
    if ( v6 )
    {
      v5->m_fTimeSinceLastInput = 0.0;
      v5->m_ControllerInUse = 1;
    }
    return;
  }
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0i64;
  if ( (_DWORD)v8 == 137 )
  {
    v14 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 461));
    v15 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 462));
  }
  else if ( (_DWORD)v8 == 138 )
  {
    v14 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 463));
    v15 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 466));
  }
  else
  {
    if ( (_DWORD)v8 != 139 )
    {
      if ( (_DWORD)v8 == 140 )
      {
        v12 = (float)v7[1062] * 0.030517576;
        v13 = (__m128)COERCE_UNSIGNED_INT((float)v7[1063]);
        v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
      }
      else if ( (_DWORD)v8 == 141 )
      {
        v12 = (float)v7[1064] * 0.030517576;
        v13 = (__m128)COERCE_UNSIGNED_INT((float)v7[1065]);
        v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
      }
      goto LABEL_21;
    }
    v14 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 464));
    v15 = _mm_cvtsi32_si128(*((_DWORD *)v7 + 465));
  }
  LODWORD(v12) = (unsigned __int128)_mm_cvtepi32_ps(v14);
  v13 = _mm_cvtepi32_ps(v15);
LABEL_21:
  switch ( (_DWORD)v8 )
  {
    case 0x81:
      v56 = *((_DWORD *)v7 + 469) == 27000;
      goto LABEL_90;
    case 0x82:
      v56 = *((_DWORD *)v7 + 469) == 9000;
      goto LABEL_90;
    case 0x83:
      v56 = *((_DWORD *)v7 + 469) == 0;
      goto LABEL_90;
    case 0x84:
      v56 = *((_DWORD *)v7 + 469) == 18000;
LABEL_90:
      v6 = v56;
      goto LABEL_91;
    case 0x85:
      v50 = (float)*((signed int *)v7 + 463) * 0.001;
      goto LABEL_77;
    case 0x86:
      v50 = (float)*((signed int *)v7 + 463) * -0.001;
      goto LABEL_77;
    case 0x87:
      v51 = *((unsigned __int8 *)v7 + 2122);
      goto LABEL_76;
    case 0x88:
      v51 = *((unsigned __int8 *)v7 + 2123);
LABEL_76:
      v50 = (float)v51 * 0.0039215689;
LABEL_77:
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v52 = v3->mAxisRawY[1];
      v3->mAxisRawX[0] = v50;
      v3->mAxisRawY[2] = v52;
      v53 = v3->mAxisRawY[0];
      v3->mAxisRawY[0] = 0.0;
      v3->mAxisRawY[1] = v53;
      v54 = signal_dead_zones[v3->mSignalType];
      if ( v50 <= v54 )
      {
        v50 = 0.0;
        v6 = 0;
      }
      else
      {
        v6 = 1;
      }
      UFG::BasicButtonStub(v3, v6, elapsed_time);
      if ( v50 < 0.0 )
      {
        if ( (float)(v54 + v50) <= 0.0 )
          v11 = v54 + v50;
      }
      else
      {
        v55 = v50 - v54;
        if ( v55 >= 0.0 )
          v11 = v55;
      }
      v3->mAxisPositionY = 0.0;
      v3->mAxisPositionX = v11 / (float)(1.0 - v54);
      goto LABEL_92;
    case 0x89:
      v33 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v34 = v3->mAxisRawY[1];
      v3->mAxisRawX[0] = v33;
      v3->mAxisRawY[2] = v34;
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      LODWORD(v3->mAxisRawY[0]) = v13.m128_i32[0];
      v35 = atan2f(v13.m128_f32[0], v33);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v33 * v33);
      v36 = v35;
      v37 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.30000001;
      if ( v37 < 0.0 )
        v37 = 0.0;
      v38 = v37 * 1.4285715;
      if ( v38 > 0.050000001 )
      {
        v39 = v35 - -1.5707964;
        if ( (float)(v36 - -1.5707964) >= 0.0 )
        {
          if ( v39 >= 0.19 )
          {
            if ( v39 < 0.38 )
              v36 = (float)((float)((float)(v39 - 0.19) * 5.2631578) * 0.38) - 1.5707964;
          }
          else
          {
            v36 = FLOAT_N1_5707964;
          }
        }
        else if ( v39 <= -0.19 )
        {
          if ( v39 > -0.38 )
            v36 = -1.5707964 - (float)((float)((float)(v39 + 0.19) * -5.2631578) * 0.38);
        }
        else
        {
          v36 = FLOAT_N1_5707964;
        }
      }
      v40 = cosf(v36) * v38;
      v41 = sinf(v36) * v38;
      if ( v40 != 0.0 || v41 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v3, v6, elapsed_time);
      v56 = v3->mSignalType == 5;
      v3->mAxisPositionX = v40;
      v3->mAxisPositionY = v41;
      if ( !v56 || v3->mButton - 138 > 1 )
        goto LABEL_92;
      v42 = v41;
      v43 = v40;
      goto LABEL_71;
    case 0x8A:
    case 0x8B:
      v44 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v45 = v3->mAxisRawY[1];
      v3->mAxisRawX[0] = v44;
      v3->mAxisRawY[2] = v45;
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      LODWORD(v3->mAxisRawY[0]) = v13.m128_i32[0];
      v46 = atan2f(v13.m128_f32[0], v44);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v44 * v44);
      v47 = v46;
      v48 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.30000001;
      if ( v48 < 0.0 )
        v48 = 0.0;
      v49 = v48 * 1.4285715;
      v31 = cosf(v46) * v49;
      v32 = sinf(v47) * v49;
      if ( v31 != 0.0 || v32 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v3, v6, elapsed_time);
      v56 = v3->mSignalType == 5;
      v3->mAxisPositionX = v31;
      v3->mAxisPositionY = v32;
      if ( !v56 || v3->mButton - 138 > 1 )
        goto LABEL_92;
      goto LABEL_70;
    case 0x8C:
      v16 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v17 = v3->mAxisRawY[1];
      v3->mAxisRawX[0] = v16;
      v3->mAxisRawY[2] = v17;
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      LODWORD(v3->mAxisRawY[0]) = v13.m128_i32[0];
      v18 = atan2f(v13.m128_f32[0], v16);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v16 * v16);
      v19 = v18;
      v20 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.33774078;
      if ( v20 < 0.0 )
        v20 = 0.0;
      v21 = v20 * 1.5099827;
      if ( v21 > 0.050000001 )
      {
        v22 = v18 - -1.5707964;
        if ( (float)(v19 - -1.5707964) >= 0.0 )
        {
          if ( v22 >= 0.19 )
          {
            if ( v22 < 0.38 )
              v19 = (float)((float)((float)(v22 - 0.19) * 5.2631578) * 0.38) - 1.5707964;
          }
          else
          {
            v19 = FLOAT_N1_5707964;
          }
        }
        else if ( v22 <= -0.19 )
        {
          if ( v22 > -0.38 )
            v19 = -1.5707964 - (float)((float)((float)(v22 + 0.19) * -5.2631578) * 0.38);
        }
        else
        {
          v19 = FLOAT_N1_5707964;
        }
      }
      v23 = cosf(v19) * v21;
      v24 = sinf(v19) * v21;
      if ( v23 != 0.0 || v24 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v3, v6, elapsed_time);
      v3->mAxisPositionX = v23;
      v3->mAxisPositionY = v24;
      goto LABEL_92;
    case 0x8D:
      v25 = v12 * 0.001;
      v13.m128_f32[0] = v13.m128_f32[0] * 0.001;
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v26 = v3->mAxisRawY[1];
      v3->mAxisRawX[0] = v25;
      v3->mAxisRawY[2] = v26;
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      LODWORD(v3->mAxisRawY[0]) = v13.m128_i32[0];
      v27 = atan2f(v13.m128_f32[0], v25);
      v13.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v25 * v25);
      v28 = v27;
      v29 = COERCE_FLOAT(_mm_sqrt_ps(v13)) - 0.37388578;
      if ( v29 < 0.0 )
        v29 = 0.0;
      v30 = v29 * 1.5971527;
      v31 = cosf(v27) * v30;
      v32 = sinf(v28) * v30;
      if ( v31 != 0.0 || v32 != 0.0 )
        v6 = 1;
      UFG::BasicButtonStub(v3, v6, elapsed_time);
      v56 = v3->mSignalType == 5;
      v3->mAxisPositionX = v31;
      v3->mAxisPositionY = v32;
      if ( v56 )
      {
LABEL_70:
        v42 = v32;
        v43 = v31;
LABEL_71:
        UFG::Controller::UpdateRightThumbHistory(v5, v43, v42, v4);
        v3->mActionTrue = UFG::Controller::RightStick_HoldThenFlickAcross(v5) != 0;
      }
      goto LABEL_92;
    default:
      return;
  }
}

// File Line: 1920
// RVA: 0xA3D0C0
void __fastcall UFG::Keyboard_IAD_Func(UFG::Controller *controller, UFG::InputActionData *inputActionData, const float elapsed_time)
{
  __int64 v3; // rbx
  __int64 v4; // rsi
  __int64 v5; // rbp
  __int64 v6; // r14
  UFG::InputActionData *v7; // r15
  UFG::Controller *v8; // rdi
  unsigned __int8 v9; // al
  unsigned int v10; // eax
  unsigned __int8 v11; // al
  unsigned int v12; // eax
  int v13; // er13
  unsigned __int8 v14; // al
  unsigned int v15; // eax
  int v16; // er12
  unsigned __int8 v17; // al
  unsigned int v18; // eax
  int v19; // edx
  signed int v20; // eax
  bool v21; // bl
  int v22; // ebx
  BOOL v23; // ecx
  int v24; // ebx
  BOOL v25; // ecx
  int v26; // ebx
  int v27; // ebx
  int v28; // [rsp+60h] [rbp+8h]

  v3 = LOBYTE(inputActionData->mButton);
  v4 = BYTE1(inputActionData->mButton);
  v5 = BYTE2(inputActionData->mButton);
  v6 = HIBYTE(inputActionData->mButton);
  v7 = inputActionData;
  v8 = controller;
  if ( (_DWORD)v3 == 18 )
  {
    LOWORD(v10) = GetKeyState(18);
    v9 = (v10 >> 15) & 1;
  }
  else if ( (_DWORD)v3 == 32 )
  {
    v9 = gSpaceBarState != 0;
  }
  else
  {
    v9 = controller->mInputState.mKeyState[v3] < 0;
  }
  v28 = v9;
  if ( (_DWORD)v4 == 18 )
  {
    LOWORD(v12) = GetKeyState(18);
    v11 = (v12 >> 15) & 1;
  }
  else if ( (_DWORD)v4 == 32 )
  {
    v11 = gSpaceBarState != 0;
  }
  else
  {
    v11 = v8->mInputState.mKeyState[v4] < 0;
  }
  v13 = v11;
  if ( (_DWORD)v5 == 18 )
  {
    LOWORD(v15) = GetKeyState(18);
    v14 = (v15 >> 15) & 1;
  }
  else if ( (_DWORD)v5 == 32 )
  {
    v14 = gSpaceBarState != 0;
  }
  else
  {
    v14 = v8->mInputState.mKeyState[v5] < 0;
  }
  v16 = v14;
  if ( (_DWORD)v6 == 18 )
  {
    LOWORD(v18) = GetKeyState(18);
    v17 = (v18 >> 15) & 1;
  }
  else if ( (_DWORD)v6 == 32 )
  {
    v17 = gSpaceBarState != 0;
  }
  else
  {
    v17 = v8->mInputState.mKeyState[v6] < 0;
  }
  v19 = v17;
  v20 = 0;
  if ( (signed int)v3 <= 0 )
    v21 = 1;
  else
    v21 = v28 > 0;
  v22 = v21;
  if ( (signed int)v4 <= 0 )
    v23 = 1;
  else
    v23 = v13 > 0;
  v24 = v23 & v22;
  if ( (signed int)v5 <= 0 )
    v25 = 1;
  else
    v25 = v16 > 0;
  v26 = v25 & v24;
  if ( (signed int)v6 <= 0 )
    v20 = 1;
  else
    LOBYTE(v20) = v19 > 0;
  v27 = v20 & v26;
  UFG::BasicButtonStub(v7, v27 != 0, elapsed_time);
  if ( v27 || bMouseIsInUse )
  {
    v8->m_ControllerInUse = 1;
    bMouseIsInUse = 0;
  }
}

// File Line: 1955
// RVA: 0xA3E2E0
void __fastcall UFG::Two_Axis_Keyboard_IAD_Func(UFG::Controller *controller, UFG::InputActionData *inputActionData, const float elapsed_time)
{
  __int64 v3; // rax
  __int64 v4; // rsi
  __int64 v5; // r15
  __int64 v6; // r12
  UFG::InputActionData *v7; // rbx
  UFG::Controller *v8; // r14
  float v9; // xmm11_4
  char v10; // al
  unsigned int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  char v14; // al
  unsigned int v15; // eax
  __m128 v16; // xmm8
  float v17; // xmm9_4
  char v18; // al
  unsigned int v19; // eax
  char v20; // al
  unsigned int v21; // eax
  float v22; // xmm9_4
  __m128 v23; // xmm1
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // eax
  float v29; // eax
  signed __int64 v30; // [rsp+C0h] [rbp+40h]
  unsigned __int64 v31; // [rsp+C8h] [rbp+48h]
  unsigned __int64 v32; // [rsp+C8h] [rbp+48h]
  float v33; // [rsp+D8h] [rbp+58h]
  float v34; // [rsp+DCh] [rbp+5Ch]

  v3 = LOBYTE(inputActionData->mButton);
  v4 = BYTE1(inputActionData->mButton);
  v5 = BYTE2(inputActionData->mButton);
  v6 = HIBYTE(inputActionData->mButton);
  v7 = inputActionData;
  v8 = controller;
  v9 = elapsed_time;
  if ( (_DWORD)v3 == 18 )
  {
    LOWORD(v11) = GetKeyState(18);
    v10 = (v11 >> 15) & 1;
  }
  else if ( (_DWORD)v3 == 32 )
  {
    v10 = gSpaceBarState != 0;
  }
  else
  {
    v10 = controller->mInputState.mKeyState[v3] < 0;
  }
  v12 = UFG::qVector2::msZero.y;
  v13 = UFG::qVector2::msZero.x;
  if ( v10 )
    v30 = 3212836864i64;
  else
    v30 = (signed __int64)UFG::qVector2::msZero;
  if ( (_DWORD)v4 == 18 )
  {
    LOWORD(v15) = GetKeyState(18);
    v12 = UFG::qVector2::msZero.y;
    v13 = UFG::qVector2::msZero.x;
    v14 = (v15 >> 15) & 1;
  }
  else if ( (_DWORD)v4 == 32 )
  {
    v14 = gSpaceBarState != 0;
  }
  else
  {
    v14 = v8->mInputState.mKeyState[v4] < 0;
  }
  if ( v14 )
    v31 = 1065353216i64;
  else
    v31 = __PAIR__(LODWORD(v12), LODWORD(v13));
  v16 = (__m128)(unsigned int)v31;
  v17 = *((float *)&v31 + 1);
  if ( (_DWORD)v5 == 18 )
  {
    LOWORD(v19) = GetKeyState(18);
    v12 = UFG::qVector2::msZero.y;
    v13 = UFG::qVector2::msZero.x;
    v18 = (v19 >> 15) & 1;
  }
  else if ( (_DWORD)v5 == 32 )
  {
    v18 = gSpaceBarState != 0;
  }
  else
  {
    v18 = v8->mInputState.mKeyState[v5] < 0;
  }
  if ( v18 )
    v32 = 4575657221408423936i64;
  else
    v32 = __PAIR__(LODWORD(v12), LODWORD(v13));
  if ( (_DWORD)v6 == 18 )
  {
    LOWORD(v21) = GetKeyState(\x12);
    v12 = UFG::qVector2::msZero.y;
    v13 = UFG::qVector2::msZero.x;
    v20 = (v21 >> 15) & 1;
  }
  else if ( (_DWORD)v6 == 32 )
  {
    v20 = gSpaceBarState != 0;
  }
  else
  {
    v20 = v8->mInputState.mKeyState[v6] < 0;
  }
  if ( v20 )
  {
    v33 = 0.0;
    v34 = -1.0;
  }
  else
  {
    v33 = v13;
    v34 = v12;
  }
  v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] + *(float *)&v30) + *(float *)&v32) + v33;
  v22 = (float)((float)(v17 + *((float *)&v30 + 1)) + *((float *)&v32 + 1)) + v34;
  v23 = v16;
  v23.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v25 = v24;
  v26 = v24 * v22;
  v27 = v25 * v16.m128_f32[0];
  UFG::BasicButtonStub(v7, (float)((float)(v27 * v27) + (float)(v26 * v26)) > 0.0, v9);
  v7->mAxisRawX[2] = v7->mAxisRawX[1];
  v7->mAxisRawX[1] = v7->mAxisRawX[0];
  v28 = v7->mAxisRawY[1];
  v7->mAxisRawX[0] = v27;
  v7->mAxisRawY[2] = v28;
  v29 = v7->mAxisRawY[0];
  v7->mAxisRawY[0] = v26;
  v7->mAxisRawY[1] = v29;
  v7->mAxisPositionX = v27;
  v7->mAxisPositionY = v26;
}

// File Line: 1987
// RVA: 0xA3D460
void __fastcall UFG::Mouse_IAD_Func(UFG::Controller *controller, UFG::InputActionData *inputActionData, const float __formal)
{
  UFG::InputActionData *v3; // rbx
  UFG::InputState *v4; // rdi
  UFG::WayGraph *v5; // rdx
  UFG::WayGraph *v6; // rdx
  float v7; // xmm7_4
  bool v8; // al
  char v9; // si
  float v10; // xmm6_4
  UFG::WayGraph *v11; // rdx
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // er14
  int v15; // er15
  int v16; // ebp
  UFG::WayGraph *v17; // rdx
  int v18; // ecx
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm0_4

  v3 = inputActionData;
  v4 = &controller->mInputState;
  inputActionData->mData0i = (signed __int16)UFG::WayFinderClient::GetWayEdge(
                                               (UFG::WayFinderClient *)&controller->mInputState,
                                               (UFG::WayGraph *)inputActionData);
  v3->mData1i = (signed __int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)v4, v5);
  LOBYTE(v6) = v4->mKeyState[2] < 0;
  v3->mData2i = (v4->mKeyState[1] < 0) | 2
                                       * ((v4->mKeyState[4] < 0) | 2
                                                                 * ((unsigned __int8)v6 | 2
                                                                                        * ((v4->mKeyState[5] < 0) | 2 * (v4->mKeyState[6] < 0))));
  v7 = UFG::InputSystem::msMouseSensitivity;
  if ( _S1_33 & 1 )
  {
    v8 = relativeMode;
  }
  else
  {
    _S1_33 |= 1u;
    v8 = UFG::InputSystem::msRelativeMouseMode;
    relativeMode = UFG::InputSystem::msRelativeMouseMode;
  }
  v9 = 0;
  if ( v8 != UFG::InputSystem::msRelativeMouseMode )
  {
    v9 = 1;
    relativeMode = UFG::InputSystem::msRelativeMouseMode;
  }
  if ( UFG::InputSystem::msRelativeMouseMode )
  {
    if ( UFG::InputSystem::msMouseInputRawAvailable && UFG::InputSystem::msMouseInputRawDesired )
    {
      v10 = (float)(signed __int16)UFG::WayFinderClient::GetWayEdge((UFG::WayFinderClient *)v4, v6) * v7;
      v12 = (float)(signed __int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)v4, v11) * v7;
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v3->mAxisRawX[0] = v10;
      v3->mAxisRawY[2] = v3->mAxisRawY[1];
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      v3->mAxisRawY[0] = v12;
      v13 = 0.0;
      if ( v9 )
        v10 = 0.0;
      v3->mAxisPositionX = v10;
      if ( !v9 )
        v13 = v12;
      v3->mAxisPositionY = v13;
      *(_DWORD *)&v4->mPrevMouseX = 0;
      *(_DWORD *)&v4->mMouseX = 0;
    }
    else
    {
      v14 = (UFG::InputSystem::msMouseArea.mRight - UFG::InputSystem::msMouseArea.mLeft) / 2;
      v15 = (UFG::InputSystem::msMouseArea.mBottom - UFG::InputSystem::msMouseArea.mTop) / 2;
      v16 = (signed __int16)UFG::WayFinderClient::GetWayEdge(
                              (UFG::WayFinderClient *)v4,
                              (UFG::WayGraph *)(unsigned int)((UFG::InputSystem::msMouseArea.mBottom
                                                             - UFG::InputSystem::msMouseArea.mTop) >> 31));
      v18 = (signed __int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)v4, v17);
      v19 = 0.0;
      v20 = 0.0;
      v21 = 0.0;
      if ( v16 >= 0 )
      {
        v20 = (float)(v16 - v14) * v7;
        v21 = (float)(v18 - v15) * v7;
      }
      v3->mAxisRawX[2] = v3->mAxisRawX[1];
      v3->mAxisRawX[1] = v3->mAxisRawX[0];
      v3->mAxisRawX[0] = v20;
      v3->mAxisRawY[2] = v3->mAxisRawY[1];
      v3->mAxisRawY[1] = v3->mAxisRawY[0];
      v3->mAxisRawY[0] = v21;
      if ( v9 )
        v20 = 0.0;
      v3->mAxisPositionX = v20;
      if ( !v9 )
        v19 = v21;
      v3->mAxisPositionY = v19;
      v4->mPrevMouseX = v14;
      v4->mMouseX = v14;
      v4->mPrevMouseY = v15;
      v4->mMouseY = v15;
    }
  }
  else
  {
    v22 = (float)(signed __int16)UFG::InputState::GetMouseDeltaX(v4) * v7;
    v23 = (float)(signed __int16)UFG::InputState::GetMouseDeltaY(v4) * v7;
    v3->mAxisRawX[2] = v3->mAxisRawX[1];
    v3->mAxisRawX[1] = v3->mAxisRawX[0];
    v3->mAxisRawX[0] = v22;
    v3->mAxisRawY[2] = v3->mAxisRawY[1];
    v3->mAxisRawY[1] = v3->mAxisRawY[0];
    v3->mAxisRawY[0] = v23;
    v24 = 0.0;
    if ( v9 )
      v22 = 0.0;
    v3->mAxisPositionX = v22;
    if ( !v9 )
      v24 = v23;
    v3->mAxisPositionY = v24;
  }
  v3->mActionTrue = 1;
}

// File Line: 2087
// RVA: 0xA3D730
void __fastcall UFG::Mouse_Wheel_IAD_Func(UFG::Controller *controller, UFG::InputActionData *inputActionData, const float elapsed_time)
{
  UFG::InputState *v3; // rbx
  UFG::InputActionData *v4; // rdi
  UFG::WayGraph *v5; // rdx
  float v6; // xmm0_4
  float v7; // xmm6_4
  bool v8; // bl
  float v9; // eax

  v3 = &controller->mInputState;
  v4 = inputActionData;
  inputActionData->mData0i = (signed __int16)UFG::WayFinderClient::GetWayEdge(
                                               (UFG::WayFinderClient *)&controller->mInputState,
                                               (UFG::WayGraph *)inputActionData);
  v4->mData1i = (signed __int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)v3, v5);
  v4->mData2i = (v3->mKeyState[1] < 0) | 2
                                       * ((v3->mKeyState[4] < 0) | 2
                                                                 * ((v3->mKeyState[2] < 0) | 2
                                                                                           * ((v3->mKeyState[5] < 0) | 2 * (v3->mKeyState[6] < 0))));
  v6 = UFG::InputState::GetMouseWheelDelta(v3);
  v7 = v6;
  if ( v4->mButton == 156 )
  {
    v8 = v6 <= -1.0;
  }
  else
  {
    if ( v4->mButton != 157 )
      return;
    v8 = v6 >= 1.0;
  }
  UFG::BasicButtonStub(v4, v8, elapsed_time);
  if ( !v8 )
    v7 = 0.0;
  v4->mAxisRawX[2] = v4->mAxisRawX[1];
  v4->mAxisRawX[1] = v4->mAxisRawX[0];
  v9 = v4->mAxisRawY[1];
  v4->mAxisRawX[0] = v7;
  v4->mAxisRawY[2] = v9;
  v4->mAxisRawY[1] = v4->mAxisRawY[0];
  v4->mAxisRawY[0] = 0.0;
  v4->mAxisPositionY = 0.0;
  v4->mAxisPositionX = v7;
}

// File Line: 2149
// RVA: 0xA3CCC0
__int64 __fastcall UFG::IsXInputDevice(_GUID *pGuidProductFromDirectInput)
{
  _GUID *v1; // r15
  wchar_t *v2; // r14
  unsigned __int8 v3; // di
  HRESULT v4; // eax
  bool v5; // r12
  signed __int64 v6; // rsi
  wchar_t *v7; // r13
  wchar_t *v8; // r12
  unsigned int v9; // ebx
  __int64 *v10; // rdi
  const wchar_t *v11; // rax
  int v12; // eax
  int v13; // ecx
  const wchar_t *v14; // rax
  int v15; // eax
  unsigned __int16 v16; // cx
  __int64 *v17; // rbx
  int v19; // [rsp+50h] [rbp-B0h]
  LPVOID ppv; // [rsp+58h] [rbp-A8h]
  IUnknown *pProxy; // [rsp+60h] [rbp-A0h]
  __int64 v22; // [rsp+68h] [rbp-98h]
  __int16 v23; // [rsp+70h] [rbp-90h]
  wchar_t *wcs1; // [rsp+78h] [rbp-88h]
  __int64 v25; // [rsp+90h] [rbp-70h]
  char Dst; // [rsp+98h] [rbp-68h]
  bool v27; // [rsp+178h] [rbp+78h]
  int v28; // [rsp+180h] [rbp+80h]
  unsigned int v29; // [rsp+188h] [rbp+88h]

  v1 = pGuidProductFromDirectInput;
  ppv = 0i64;
  v22 = 0i64;
  v25 = 0i64;
  memset(&Dst, 0, 0x98ui64);
  pProxy = 0i64;
  v2 = 0i64;
  v29 = 0;
  v3 = 0;
  v4 = CoInitialize(0i64);
  v5 = v4 >= 0;
  v27 = v4 >= 0;
  v6 = 20i64;
  if ( CoCreateInstance(
         &GUID_4590f811_1d3a_11d0_891f_00aa004b2e24,
         0i64,
         1u,
         &GUID_dc12a687_737f_11cf_884d_00aa004b2e24,
         &ppv) >= 0 )
  {
    if ( ppv )
    {
      v7 = SysAllocString(L"\\\\.\\root\\cimv2");
      if ( v7 )
      {
        v8 = SysAllocString(L"Win32_PNPEntity");
        if ( v8 )
        {
          v2 = SysAllocString(L"DeviceID");
          if ( v2 )
          {
            if ( (*(signed int (__fastcall **)(LPVOID, wchar_t *, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, IUnknown **))(*(_QWORD *)ppv + 24i64))(
                   ppv,
                   v7,
                   0i64,
                   0i64,
                   0i64,
                   0,
                   0i64,
                   0i64,
                   &pProxy) >= 0 )
            {
              if ( pProxy )
              {
                CoSetProxyBlanket(pProxy, 0xAu, 0, 0i64, 3u, 3u, 0i64, 0);
                if ( ((signed int (__fastcall *)(IUnknown *, wchar_t *, _QWORD, _QWORD, __int64 *))pProxy->vfptr[6].QueryInterface)(
                       pProxy,
                       v8,
                       0i64,
                       0i64,
                       &v22) >= 0
                  && v22
                  && (*(signed int (__fastcall **)(__int64, signed __int64, signed __int64, __int64 *, unsigned int *))(*(_QWORD *)v22 + 32i64))(
                       v22,
                       10000i64,
                       20i64,
                       &v25,
                       &v29) >= 0 )
                {
                  while ( 1 )
                  {
                    if ( !v29 )
                    {
LABEL_31:
                      v3 = 0;
                      goto $LCleanup;
                    }
                    v9 = 0;
                    if ( v29 )
                      break;
LABEL_30:
                    if ( (*(signed int (__fastcall **)(__int64, signed __int64, signed __int64, __int64 *, unsigned int *))(*(_QWORD *)v22 + 32i64))(
                           v22,
                           10000i64,
                           20i64,
                           &v25,
                           &v29) < 0 )
                      goto LABEL_31;
                  }
                  while ( 1 )
                  {
                    v10 = &v25 + v9;
                    if ( (*(signed int (__fastcall **)(_QWORD, wchar_t *, _QWORD, __int16 *, _QWORD, _QWORD))(*(_QWORD *)*(&v25 + v9) + 32i64))(
                           *(&v25 + v9),
                           v2,
                           0i64,
                           &v23,
                           0i64,
                           0i64) >= 0
                      && v23 == 8
                      && wcs1
                      && wcsstr(wcs1, L"IG_") )
                    {
                      v19 = 0;
                      v28 = 0;
                      v11 = wcsstr(wcs1, L"VID_");
                      if ( v11 )
                      {
                        v12 = swscanf(v11, L"VID_%4X", &v28);
                        v13 = v28;
                        if ( v12 != 1 )
                          v13 = 0;
                        v28 = v13;
                      }
                      v14 = wcsstr(wcs1, L"PID_");
                      if ( v14 )
                      {
                        v15 = swscanf(v14, L"PID_%4X", &v19);
                        v16 = v19;
                        if ( v15 != 1 )
                          v16 = 0;
                      }
                      else
                      {
                        v16 = v19;
                      }
                      if ( ((unsigned __int16)v28 | (v16 << 16)) == v1->Data1 )
                        break;
                    }
                    if ( *v10 )
                    {
                      (*(void (**)(void))(*(_QWORD *)*v10 + 16i64))();
                      *v10 = 0i64;
                    }
                    if ( ++v9 >= v29 )
                      goto LABEL_30;
                  }
                  v3 = 1;
                }
              }
            }
          }
        }
$LCleanup:
        SysFreeString(v7);
        if ( v2 )
          SysFreeString(v2);
        if ( v8 )
          SysFreeString(v8);
        v5 = v27;
      }
    }
  }
  v17 = &v25;
  do
  {
    if ( *v17 )
    {
      (*(void (**)(void))(*(_QWORD *)*v17 + 16i64))();
      *v17 = 0i64;
    }
    ++v17;
    --v6;
  }
  while ( v6 );
  if ( v22 )
  {
    (*(void (**)(void))(*(_QWORD *)v22 + 16i64))();
    v22 = 0i64;
  }
  if ( ppv )
  {
    (*(void (**)(void))(*(_QWORD *)ppv + 16i64))();
    ppv = 0i64;
  }
  if ( pProxy )
  {
    ((void (*)(void))pProxy->vfptr->Release)();
    pProxy = 0i64;
  }
  if ( v5 )
    CoUninitialize();
  return v3;
}

// File Line: 2256
// RVA: 0xA3B9C0
void UFG::InputSystem::Init(void)
{
  HWND__ *v0; // rbx
  UFG::allocator::free_link *v1; // rax
  tagRAWINPUTDEVICE pRawInputDevices; // [rsp+28h] [rbp-20h]

  v0 = ghWnd;
  v1 = UFG::qMalloc(0x50ui64, "InputSystem", 0i64);
  if ( v1 )
    UFG::DxInputSystem::DxInputSystem((UFG::DxInputSystem *)v1, v0);
  UFG::gInputSystem = (UFG::InputSystem *)v1;
  *(_QWORD *)&pRawInputDevices.usUsagePage = 131073i64;
  pRawInputDevices.hwndTarget = ghWnd;
  UFG::InputSystem::msMouseInputRawAvailable = RegisterRawInputDevices(&pRawInputDevices, 1u, 0x10u) != 0;
  UFG::qMemSet(&UFG::sRawInputState, 0, 0x138u);
  UFG::sRawInputState.mInputMessages.mNode.mPrev = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
  UFG::sRawInputState.mInputMessages.mNode.mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
}

// File Line: 2277
// RVA: 0xA3AE20
void UFG::InputSystem::Close(void)
{
  if ( UFG::gInputSystem )
    UFG::gInputSystem->vfptr->__vecDelDtor(UFG::gInputSystem, 1u);
  UFG::gInputSystem = 0i64;
}

// File Line: 2284
// RVA: 0xA3D850
UFG::RawPadData *__fastcall UFG::DxController::ReadRawPadData(UFG::DxController *this)
{
  UFG::RawPadData *v1; // rbx
  _WORD *v2; // rax
  _WORD *v3; // rdx
  __int16 v4; // cx
  UFG::RawPadData *result; // rax

  v1 = &this->mRemoteData;
  v2 = _RTDynamicCast(this, 0, &UFG::DxController `RTTI Type Descriptor, &UFG::Gamepad `RTTI Type Descriptor, 0);
  v3 = v2;
  v1->mGetXIState_Gamepad_wButtons = v2[1060];
  v1->mGetState_lRx = *((_DWORD *)v2 + 464);
  v1->mGetState_lRy = *((_DWORD *)v2 + 465);
  v1->mGetState_lRz = *((_DWORD *)v2 + 466);
  v1->mGetState_lX = *((_DWORD *)v2 + 461);
  v1->mGetState_lY = *((_DWORD *)v2 + 462);
  v1->mGetState_lZ = *((_DWORD *)v2 + 463);
  v4 = v2[1062];
  result = v1;
  v1->mGetXIState_Gamepad_sThumbLX = v4;
  v1->mGetXIState_Gamepad_sThumbLY = v3[1063];
  v1->mGetXIState_Gamepad_sThumbRX = v3[1064];
  v1->mGetXIState_Gamepad_sThumbRY = v3[1065];
  v1->mGetXIState_Gamepad_bLeftTrigger = *((_BYTE *)v3 + 2122);
  v1->mGetXIState_Gamepad_bRightTrigger = *((_BYTE *)v3 + 2123);
  v1->mGetState_rgdwPOV0 = *((_DWORD *)v3 + 469);
  return result;
}

// File Line: 2312
// RVA: 0xA3E120
void __fastcall UFG::DxController::SetRawPadData(UFG::DxController *this, const void *prpd)
{
  unsigned int v2; // eax

  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_wButtons = *(_DWORD *)prpd;
  this->mRemoteData.mGetState_lRx = *((_DWORD *)prpd + 1);
  this->mRemoteData.mGetState_lRy = *((_DWORD *)prpd + 2);
  this->mRemoteData.mGetState_lRz = *((_DWORD *)prpd + 3);
  this->mRemoteData.mGetState_lX = *((_DWORD *)prpd + 4);
  this->mRemoteData.mGetState_lY = *((_DWORD *)prpd + 5);
  this->mRemoteData.mGetState_lZ = *((_DWORD *)prpd + 6);
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_sThumbLX = *((_DWORD *)prpd + 7);
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_sThumbRX = *((_DWORD *)prpd + 8);
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_bLeftTrigger = *((_DWORD *)prpd + 9);
  v2 = *((_DWORD *)prpd + 10);
  *(_WORD *)&this->mIsInitialized = 257;
  this->mRemoteData.mGetState_rgdwPOV0 = v2;
}

// File Line: 2333
// RVA: 0xA3AA80
void __fastcall UFG::DxController::~DxController(UFG::DxController *this)
{
  this->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  UFG::Controller::~Controller((UFG::Controller *)&this->vfptr);
}

// File Line: 2340
// RVA: 0xA3A8E0
void __fastcall UFG::Keyboard::Keyboard(UFG::Keyboard *this, int index, HWND__ *hWnd, void *di)
{
  void *v4; // rdi
  HWND__ *v5; // rsi
  int v6; // ebp
  UFG::Keyboard *v7; // r14
  signed int v8; // edi
  UFG::InputActionMap **v9; // rbx
  signed int v10; // edi
  UFG::MultiInputMap **v11; // rbx
  int v12; // eax

  v4 = di;
  v5 = hWnd;
  v6 = index;
  v7 = this;
  UFG::Controller::Controller((UFG::Controller *)&this->vfptr, index);
  v7->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  v7->mXinputUserIndex = -1;
  memset(&v7->mState, 0, 0x110ui64);
  *(_QWORD *)&v7->mXinputState.dwPacketNumber = 0i64;
  *(_QWORD *)&v7->mXinputState.Gamepad.sThumbLX = 0i64;
  v7->vfptr = (UFG::ControllerVtbl *)&UFG::Keyboard::`vftable;
  (*(void (__fastcall **)(void *, GUID *, IDirectInputDevice8A **, _QWORD, signed __int64))(*(_QWORD *)v4 + 24i64))(
    v4,
    &GUID_SysKeyboard,
    &v7->mDevice,
    0i64,
    -2i64);
  ((void (__fastcall *)(IDirectInputDevice8A *, _DIDATAFORMAT *))v7->mDevice->vfptr[3].Release)(
    v7->mDevice,
    &c_dfDIKeyboard);
  ((void (__fastcall *)(IDirectInputDevice8A *, HWND__ *, signed __int64))v7->mDevice->vfptr[4].AddRef)(
    v7->mDevice,
    v5,
    6i64);
  v8 = 0;
  v9 = UFG::gInitialKeyboardMaps;
  do
  {
    if ( !*v9 )
      break;
    UFG::Controller::AddInputActionMap((UFG::Controller *)&v7->vfptr, *v9, 0i64);
    ++v8;
    ++v9;
  }
  while ( v8 < 32 );
  v10 = 0;
  v11 = UFG::gInitialMultiMaps;
  do
  {
    if ( !*v11 )
      break;
    UFG::Controller::AddMultiInputMap((UFG::Controller *)&v7->vfptr, *v11);
    ++v10;
    ++v11;
  }
  while ( v10 < 32 );
  v7->m_IsKeyboardController = 1;
  if ( !v6 )
  {
    v12 = UFG::InputSystem::msPCKeyboardSwapMode;
    if ( UFG::InputSystem::msPCKeyboardSwapMode == 1 )
      v12 = 0;
    UFG::InputSystem::msPCKeyboardSwapMode = v12;
  }
}

// File Line: 2416
// RVA: 0xA3EBC0
void __fastcall UFG::Keyboard::Update(UFG::Keyboard *this, const float elapsedTime, const float simTime)
{
  int v3; // edx

  v3 = this->mControllerIndex;
  this->m_ControllerInUse = 0;
  UFG::gInputSystem->mKeyboardIndex = v3;
  memset(&this->mState, 0, 0x110ui64);
}

// File Line: 2433
// RVA: 0xA3A6F0
void __fastcall UFG::Gamepad::Gamepad(UFG::Gamepad *this, int index, HWND__ *hWnd, void *di, DIDEVICEINSTANCEA *did, const int xinput_user_index)
{
  void *v6; // r14
  HWND__ *v7; // rbp
  UFG::Gamepad *v8; // rbx
  IDirectInputDevice8A **v9; // rdi
  signed int v10; // esi
  const unsigned int *v11; // r14
  unsigned int v12; // ecx
  int v13; // ST2C_4
  int v14; // ST30_4
  int v15; // ST34_4
  signed int v16; // ebp
  UFG::InputActionMap **v17; // rdi
  UFG::MultiInputMap **v18; // rdi

  v6 = di;
  v7 = hWnd;
  v8 = this;
  UFG::Controller::Controller((UFG::Controller *)&this->vfptr, index);
  v8->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  v8->mXinputUserIndex = xinput_user_index;
  memset(&v8->mState, 0, 0x110ui64);
  *(_QWORD *)&v8->mXinputState.dwPacketNumber = 0i64;
  *(_QWORD *)&v8->mXinputState.Gamepad.sThumbLX = 0i64;
  v8->vfptr = (UFG::ControllerVtbl *)&UFG::Gamepad::`vftable;
  v9 = &v8->mDevice;
  v10 = 0;
  v8->mDevice = 0i64;
  *(_WORD *)&v8->mIsStatusOK = 0;
  if ( v8->mXinputUserIndex < 0 )
  {
    if ( (*(signed int (__fastcall **)(void *, _GUID *, IDirectInputDevice8A **, _QWORD, signed __int64))(*(_QWORD *)v6 + 24i64))(
           v6,
           &did->guidInstance,
           v9,
           0i64,
           -2i64) >= 0 )
    {
      v8->mDeviceInfo.dwSize = 580;
      ((void (*)(void))(*v9)->vfptr[5].QueryInterface)();
      if ( ((signed int (__fastcall *)(IDirectInputDevice8A *, _DIDATAFORMAT *))(*v9)->vfptr[3].Release)(
             *v9,
             &c_dfDIJoystick2) >= 0
        && ((signed int (__fastcall *)(IDirectInputDevice8A *, HWND__ *, signed __int64))(*v9)->vfptr[4].AddRef)(
             *v9,
             v7,
             9i64) >= 0
        && ((signed int (__fastcall *)(IDirectInputDevice8A *, int (__fastcall *)(DIDEVICEOBJECTINSTANCEA *, void *), UFG::Gamepad *, _QWORD))(*v9)->vfptr[1].AddRef)(
             *v9,
             UFG::Gamepad::EnumObjectsCallback,
             v8,
             0i64) >= 0 )
      {
        v8->mIsStatusOK = 1;
      }
    }
    v12 = v8->mDeviceInfo.guidProduct.Data1;
    v13 = *(_DWORD *)&v8->mDeviceInfo.guidProduct.Data2;
    v14 = *(_DWORD *)v8->mDeviceInfo.guidProduct.Data4;
    v15 = *(_DWORD *)&v8->mDeviceInfo.guidProduct.Data4[4];
    if ( v12 == 40371532 )
    {
      v11 = UFG::Generic_to_SixAxisRemap;
    }
    else if ( v12 != 42861662 && v12 != 119080030 && (v12 == -1038744467 || v12 == -1038547859) )
    {
      v11 = UFG::Generic_to_LogiTechRemap;
    }
    else
    {
      v11 = UFG::Generic_to_360_Remap;
    }
  }
  else
  {
    v8->mIsStatusOK = 1;
    v11 = UFG::Generic_to_XInput;
  }
  v16 = 0;
  v17 = UFG::gInitialGamepadMaps;
  do
  {
    if ( !*v17 )
      break;
    UFG::Controller::AddInputActionMap((UFG::Controller *)&v8->vfptr, *v17, v11);
    ++v16;
    ++v17;
  }
  while ( v16 < 32 );
  v18 = UFG::gInitialMultiMaps;
  do
  {
    if ( !*v18 )
      break;
    UFG::Controller::AddMultiInputMap((UFG::Controller *)&v8->vfptr, *v18);
    ++v10;
    ++v18;
  }
  while ( v10 < 32 );
  v8->m_IsKeyboardController = 0;
}

// File Line: 2553
// RVA: 0xA3EA80
void __fastcall UFG::Gamepad::Update(UFG::Gamepad *this, const float elapsedTime, const float simTime)
{
  UFG::Gamepad *v3; // rbx
  int v4; // ecx
  DWORD v5; // eax
  int i; // eax

  v3 = this;
  this->m_ControllerInUse = 0;
  v4 = this->mXinputUserIndex;
  if ( v4 < 0 )
  {
    if ( v3->mIsStatusOK )
    {
      if ( v3->mUnplugged )
        UFG::Gamepad::Reconnect(v3);
      if ( ((signed int (*)(void))v3->mDevice->vfptr[8].AddRef)() >= 0 )
        goto LABEL_19;
      for ( i = ((__int64 (*)(void))v3->mDevice->vfptr[2].AddRef)();
            i == -2147024866;
            i = ((__int64 (*)(void))v3->mDevice->vfptr[2].AddRef)() )
      {
        ;
      }
      if ( i != -2147024891 )
      {
LABEL_19:
        if ( v3->mDevice->vfptr[3].QueryInterface((IUnknown *)&v3->mDevice->vfptr, (_GUID *)272, (void **)&v3->mState) == -2147024866 )
        {
          UFG::qPrintf("DIERR_INPUTLOST %x\n", v3);
          v3->mUnplugged = 1;
          memset(&v3->mState, 0, 0x110ui64);
        }
      }
    }
  }
  else
  {
    if ( v3->mIsInitialized )
    {
      v5 = XInputGetState_0(v4, &v3->mXinputState);
      if ( !v5 )
      {
        v3->mUnplugged = 0;
        return;
      }
      if ( v5 != 1167 )
      {
        v3->mUnplugged = 1;
        return;
      }
    }
    v3->mUnplugged = 1;
    *(_QWORD *)&v3->mXinputState.dwPacketNumber = 0i64;
    *(_QWORD *)&v3->mXinputState.Gamepad.sThumbLX = 0i64;
  }
}

// File Line: 2680
// RVA: 0xA3D910
void __fastcall UFG::Gamepad::Reconnect(UFG::Gamepad *this)
{
  UFG::Gamepad *v1; // rbx
  int i; // eax

  v1 = this;
  for ( i = ((__int64 (*)(void))this->mDevice->vfptr[2].AddRef)();
        i == -2147024866;
        i = ((__int64 (*)(void))v1->mDevice->vfptr[2].AddRef)() )
  {
    ;
  }
  if ( i >= 0 )
  {
    UFG::qPrintf("JOYSTICK reacquired %x\n", v1);
    v1->mUnplugged = 0;
  }
}

// File Line: 2702
// RVA: 0xA3B020
signed __int64 __fastcall UFG::DxInputSystem::EnumJoysticksCallback(DIDEVICEINSTANCEA *pdidInstance, void *pContext)
{
  char *v2; // rsi
  DIDEVICEINSTANCEA *did; // rbp
  __int64 v4; // rdi
  int v5; // ebx
  signed __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax

  v2 = (char *)pContext;
  did = pdidInstance;
  if ( !UFG::IsXInputDevice(&pdidInstance->guidProduct) )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0i64;
    v7 = v2 + 8;
    while ( *v7 )
    {
      ++v5;
      ++v6;
      ++v7;
      if ( v6 >= 5 )
        return 0i64;
    }
    if ( v5 == -1 )
      return 0i64;
    v9 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
    if ( v9 )
    {
      UFG::Gamepad::Gamepad((UFG::Gamepad *)v9, v5, *((HWND__ **)v2 + 9), *((void **)v2 + 8), did, -1);
      v4 = v10;
    }
    if ( v4 )
      *(_QWORD *)&v2[8 * v5 + 8] = v4;
  }
  return 1i64;
}

// File Line: 2746
// RVA: 0xA3B0F0
_BOOL8 __fastcall UFG::Gamepad::EnumObjectsCallback(DIDEVICEOBJECTINSTANCEA *pdidoi, void *pContext)
{
  unsigned int v2; // eax
  __int64 v3; // rcx
  _BOOL8 result; // rax
  int v5; // [rsp+20h] [rbp-28h]
  int v6; // [rsp+24h] [rbp-24h]
  unsigned int v7; // [rsp+28h] [rbp-20h]
  int v8; // [rsp+2Ch] [rbp-1Ch]
  int v9; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+34h] [rbp-14h]

  v2 = pdidoi->dwType;
  result = 1;
  if ( v2 & 3 )
  {
    v3 = *((_QWORD *)pContext + 272);
    v5 = 24;
    v6 = 16;
    v8 = 2;
    v7 = v2;
    v9 = -1000;
    v10 = 1000;
    if ( (*(signed int (__fastcall **)(__int64, signed __int64, int *))(*(_QWORD *)v3 + 48i64))(v3, 4i64, &v5) < 0 )
      result = 0;
  }
  return result;
}

// File Line: 2770
// RVA: 0xA3AE50
signed __int64 __fastcall UFG::DxInputSystem::CreateNewGamePad(UFG::DxInputSystem *this, int index)
{
  __int64 v2; // rsi
  UFG::DxInputSystem *v3; // rbp
  __int64 v4; // r14
  UFG::Controller *v5; // rbx
  signed int v6; // er8
  UFG::Controller **v7; // rdx
  UFG::Controller *v8; // rax
  __int64 v9; // rcx
  int xinput_user_index; // edi
  int v11; // ecx
  __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Controller *v14; // rax
  __int64 v16; // [rsp+38h] [rbp-30h]
  __int64 v17; // [rsp+40h] [rbp-28h]

  v2 = index;
  v3 = this;
  v4 = index;
  if ( this->mControllers[v4] )
    return 0xFFFFFFFFi64;
  v16 = -1i64;
  v17 = -1i64;
  v5 = 0i64;
  v6 = 0;
  v7 = this->mControllers;
  do
  {
    v8 = *v7;
    if ( *v7 )
    {
      if ( !v8->m_IsKeyboardController )
      {
        v9 = SLODWORD(v8[1].vfptr);
        if ( (unsigned int)v9 <= 3 )
          *((_DWORD *)&v16 + v9) = v6;
      }
    }
    ++v6;
    ++v7;
  }
  while ( v6 < 4 );
  xinput_user_index = v2;
  if ( *((_DWORD *)&v16 + v2) != -1 )
  {
    xinput_user_index = -1;
    v11 = 0;
    v12 = 0i64;
    while ( *((_DWORD *)&v16 + v12) != -1 )
    {
      ++v11;
      if ( ++v12 >= 4 )
        goto LABEL_14;
    }
    xinput_user_index = v11;
  }
LABEL_14:
  v13 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
  if ( v13 )
  {
    UFG::Gamepad::Gamepad((UFG::Gamepad *)v13, v2, v3->hWnd, 0i64, 0i64, xinput_user_index);
    v5 = v14;
  }
  if ( v5 )
  {
    v3->mControllers[v4] = v5;
    v5->mIsInitialized = 1;
  }
  return (unsigned int)v2;
}

// File Line: 2823
// RVA: 0xA3BA70
__int64 __fastcall UFG::DxInputSystem::InitDirectInput(UFG::DxInputSystem *this)
{
  UFG::DxInputSystem *v1; // rbp
  HMODULE v2; // rax
  __int64 result; // rax
  DWORD xinput_user_index; // esi
  int v5; // edi
  __int64 v6; // rbx
  UFG::Controller **i; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::Controller *v9; // rax
  DIDEVICEINSTANCEA *did; // [rsp+20h] [rbp-48h]
  XINPUT_STATE pState; // [rsp+38h] [rbp-30h]

  v1 = this;
  v2 = GetModuleHandleA(0i64);
  result = DirectInput8Create_0(v2, 2048i64, &IID_IDirectInput8A, &v1->mDirectInput, 0i64);
  if ( (signed int)result >= 0 )
  {
    xinput_user_index = 0;
    do
    {
      *(_QWORD *)&pState.dwPacketNumber = 0i64;
      *(_QWORD *)&pState.Gamepad.sThumbLX = 0i64;
      if ( !XInputGetState_0(xinput_user_index, &pState) )
      {
        v5 = 0;
        v6 = 0i64;
        if ( xinput_user_index < 4 )
        {
          for ( i = v1->mControllers; *i; ++i )
          {
            ++v5;
            ++v6;
          }
          v8 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
          if ( v8 )
            UFG::Gamepad::Gamepad((UFG::Gamepad *)v8, v5, v1->hWnd, v1->mDirectInput, 0i64, xinput_user_index);
          else
            v9 = 0i64;
          if ( v9 )
          {
            v1->mControllers[v6] = v9;
            v9->mIsInitialized = 1;
          }
        }
      }
      ++xinput_user_index;
    }
    while ( xinput_user_index < 4 );
    if ( !gUsePCController
      || (LODWORD(did) = 1,
          result = ((__int64 (__fastcall *)(IDirectInput8A *, signed __int64, signed __int64 (__fastcall *)(DIDEVICEINSTANCEA *, void *), UFG::DxInputSystem *, DIDEVICEINSTANCEA *))v1->mDirectInput->vfptr[1].AddRef)(
                     v1->mDirectInput,
                     4i64,
                     UFG::DxInputSystem::EnumJoysticksCallback,
                     v1,
                     did),
          (signed int)result >= 0) )
    {
      result = 0i64;
    }
  }
  return result;
}

// File Line: 2916
// RVA: 0xA3A640
void __fastcall UFG::DxInputSystem::DxInputSystem(UFG::DxInputSystem *this, HWND__ *h)
{
  HWND__ *v2; // rbx
  UFG::DxInputSystem *v3; // rdi
  UFG::Controller *v4; // rsi
  int v5; // ebx
  UFG::allocator::free_link *v6; // rax
  UFG::Controller *v7; // rax

  v2 = h;
  v3 = this;
  UFG::InputSystem::InputSystem((UFG::InputSystem *)&this->vfptr);
  v3->vfptr = (UFG::InputSystemVtbl *)&UFG::DxInputSystem::`vftable;
  v3->hWnd = v2;
  UFG::DxInputSystem::InitDirectInput(v3);
  *(_WORD *)&v3->mbSentDisconnectMsg = 0;
  v4 = 0i64;
  v5 = 0;
  if ( v3->mControllers[0] )
    v5 = 4;
  UFG::InputSystem::msRelativeMouseMode = 0;
  v6 = UFG::qMalloc(0x888ui64, "Keyboard", 0i64);
  if ( v6 )
  {
    UFG::Keyboard::Keyboard((UFG::Keyboard *)v6, v5, v3->hWnd, v3->mDirectInput);
    v4 = v7;
  }
  v3->mControllers[v5] = v4;
}

// File Line: 2960
// RVA: 0xA3ED30
void __fastcall UFG::fake_xinput(UFG *this)
{
  unsigned __int16 v1; // r10
  float *v2; // r8
  unsigned __int16 *v3; // r9
  signed int v4; // edx

  v1 = 0;
  v2 = &UFG::testController.testInput[0].fDataX;
  v3 = UFG::XINPUT_BUTTON_MASKS;
  v4 = 0;
  do
  {
    if ( *((_BYTE *)v2 - 8) )
    {
      switch ( v4 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
        case 15:
        case 16:
        case 17:
          v1 |= *v3;
          break;
        case 5:
          UFG::sRawInputState.mXinputState.Gamepad.bLeftTrigger = (signed int)*v2;
          break;
        case 7:
          UFG::sRawInputState.mXinputState.Gamepad.bRightTrigger = (signed int)*v2;
          break;
        case 12:
          UFG::sRawInputState.mXinputState.Gamepad.sThumbLX = (signed int)*v2;
          UFG::sRawInputState.mXinputState.Gamepad.sThumbLY = (signed int)v2[1];
          break;
        case 13:
          UFG::sRawInputState.mXinputState.Gamepad.sThumbRX = (signed int)*v2;
          UFG::sRawInputState.mXinputState.Gamepad.sThumbRY = (signed int)v2[1];
          break;
        default:
          break;
      }
    }
    ++v4;
    ++v3;
    v2 += 4;
  }
  while ( v4 < 18 );
  UFG::sRawInputState.mXinputState.Gamepad.wButtons = v1;
}

// File Line: 3027
// RVA: 0xA3E5C0
void __fastcall UFG::DxInputSystem::Update(UFG::DxInputSystem *this, const float elapsedTime, const float simTime)
{
  UFG::DxInputSystem *v3; // rbp
  int v4; // er14
  int v5; // ebx
  signed int v6; // esi
  UFG::DxInputSystem **v7; // rdi
  UFG::InputSystemVtbl *v8; // rax
  signed int xinput_user_index; // edi
  int *v10; // rsi
  UFG::allocator::free_link *v11; // rax
  UFG::DxInputSystem *v12; // rax
  UFG::Controller **v13; // r15
  signed __int64 v14; // r12
  UFG::InputMessage *v15; // rbx
  UFG::Controller *v16; // rax
  UFG::allocator::free_link *v17; // rdi
  UFG::DxInputSystem *v18; // rsi
  UFG::InputState *v19; // rbx
  __int64 *v20; // rcx
  __int64 v21; // rdx
  _QWORD *v22; // rax
  __int64 v23; // rdx
  _QWORD *v24; // rax
  signed __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rdx
  UFG::allocator::free_link *v28; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v29; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v30; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v31; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v32; // rax
  UFG::Controller *v33; // rbx
  UFG::Controller *v34; // rcx
  bool v35; // r8
  bool v36; // dl
  int v37; // [rsp+30h] [rbp-E8h]
  int v38; // [rsp+34h] [rbp-E4h]
  int v39; // [rsp+38h] [rbp-E0h]
  int v40; // [rsp+3Ch] [rbp-DCh]
  XINPUT_STATE pState; // [rsp+40h] [rbp-D8h]
  __int64 v42; // [rsp+50h] [rbp-C8h]
  Render::RenderOutputParams outSettings; // [rsp+60h] [rbp-B8h]

  v42 = -2i64;
  v3 = this;
  v4 = 0;
  if ( !gFreezeInputs )
  {
    v5 = -1;
    v37 = -1;
    v38 = -1;
    v39 = -1;
    v40 = -1;
    v6 = 0;
    v7 = (UFG::DxInputSystem **)this->mControllers;
    do
    {
      this = *v7;
      if ( *v7 )
      {
        ((void (*)(void))this->vfptr[1].CreateNewGamePad)();
        if ( v6 == UFG::gActiveControllerNum && v3->mbCheckForControllerDisconnect )
        {
          v8 = (*v7)->vfptr;
          if ( v3->mbSentDisconnectMsg )
          {
            if ( ((unsigned __int8 (*)(void))v8[1].Update)() )
              v3->mbSentDisconnectMsg = 0;
          }
          else if ( !((unsigned __int8 (*)(void))v8[1].Update)() )
          {
            v3->mbSentDisconnectMsg = 1;
          }
        }
        if ( !LOBYTE((*v7)[22].hWnd) )
        {
          this = (UFG::DxInputSystem *)SLODWORD((*v7)[23].vfptr);
          if ( (signed int)this >= 0 )
            *(&v37 + (_QWORD)this) = 0;
        }
      }
      else if ( v5 < 0 )
      {
        v5 = v6;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < 5 );
    if ( bCheckForNewController )
    {
      if ( v5 >= 0 )
      {
        xinput_user_index = 0;
        v10 = &v37;
        while ( 1 )
        {
          if ( *v10 )
          {
            *(_QWORD *)&pState.dwPacketNumber = 0i64;
            *(_QWORD *)&pState.Gamepad.sThumbLX = 0i64;
            if ( !XInputGetState_0(xinput_user_index, &pState) )
              break;
          }
          ++xinput_user_index;
          ++v10;
          if ( xinput_user_index >= 4 )
            goto LABEL_29;
        }
        v11 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
        if ( v11 )
        {
          UFG::Gamepad::Gamepad((UFG::Gamepad *)v11, v5, v3->hWnd, v3->mDirectInput, 0i64, xinput_user_index);
          this = v12;
        }
        else
        {
          this = 0i64;
        }
        if ( this )
        {
          v3->mControllers[v5] = (UFG::Controller *)this;
          LOBYTE(this->mControllers[0]) = 1;
        }
      }
LABEL_29:
      bCheckForNewController = 0;
    }
  }
  v13 = v3->mControllers;
  v14 = 5i64;
  v15 = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
  do
  {
    v16 = *v13;
    if ( *v13 )
    {
      v17 = (UFG::allocator::free_link *)&v16->mInputMessages;
      v18 = (UFG::DxInputSystem *)&v16->mInputState;
      v19 = &v16->mPreviousInputState;
      v20 = (__int64 *)v16->mInputMessages.mNode.mNext;
      if ( v20 != (__int64 *)&v16->mInputMessages )
      {
        do
        {
          v21 = *v20;
          v22 = (_QWORD *)v20[1];
          *(_QWORD *)(v21 + 8) = v22;
          *v22 = v21;
          *v20 = (__int64)v20;
          v20[1] = (__int64)v20;
          v23 = *v20;
          v24 = (_QWORD *)v20[1];
          *(_QWORD *)(v23 + 8) = v24;
          *v24 = v23;
          *v20 = (__int64)v20;
          v20[1] = (__int64)v20;
          operator delete[](v20);
          v20 = (__int64 *)v17[1].mNext;
        }
        while ( v20 != (__int64 *)v17 );
      }
      this = v18;
      if ( ((unsigned __int8)v19 | (unsigned __int8)v18) & 0xF )
      {
        memmove(v19, v18, 0x118ui64);
      }
      else
      {
        v25 = 2i64;
        do
        {
          *(_OWORD *)&v19->mLastMouseXYTime = *(_OWORD *)&this->vfptr;
          *(_OWORD *)&v19->mPrevMouseY = *(_OWORD *)&this->mControllers[1];
          *(_OWORD *)&v19->mKeyState[12] = *(_OWORD *)&this->mControllers[3];
          *(_OWORD *)&v19->mKeyState[28] = *(_OWORD *)this->mIsAssigned;
          *(_OWORD *)&v19->mKeyState[44] = *(_OWORD *)&this->mDirectInput;
          *(_OWORD *)&v19->mKeyState[60] = *(_OWORD *)&this[1].vfptr;
          *(_OWORD *)&v19->mKeyState[76] = *(_OWORD *)&this[1].mControllers[1];
          v19 = (UFG::InputState *)((char *)v19 + 128);
          *(_OWORD *)&v19[-1].mKeyState[244] = *(_OWORD *)&this[1].mControllers[3];
          this = (UFG::DxInputSystem *)((char *)this + 128);
          --v25;
        }
        while ( v25 );
        *(_OWORD *)&v19->mLastMouseXYTime = *(_OWORD *)&this->vfptr;
        *(_QWORD *)&v19->mPrevMouseY = this->mControllers[1];
      }
      v15 = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
      if ( (UFG::RawInputState *)UFG::sRawInputState.mInputMessages.mNode.mNext != &UFG::sRawInputState )
      {
        do
        {
          if ( !gFreezeInputs )
            UFG::InputState::ProcessMessage((UFG::InputState *)v18, v15);
          v26 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v27 = v26;
          if ( v26 )
          {
            v26->mNext = v26;
            v26[1].mNext = v26;
            LOBYTE(v26[2].mNext) = v15->mMessageID;
            this = (UFG::DxInputSystem *)(unsigned __int8)v15->mVKey;
            BYTE1(v26[2].mNext) = (_BYTE)this;
            WORD1(v26[2].mNext) = v15->mMouseX;
            WORD2(v26[2].mNext) = v15->mMouseY;
            HIWORD(v26[2].mNext) = v15->mMouseWheelDelta;
            LODWORD(v26[3].mNext) = v15->mChar;
          }
          else
          {
            v27 = 0i64;
          }
          v28 = v17->mNext;
          v28[1].mNext = v27;
          v27->mNext = v28;
          v27[1].mNext = v17;
          v17->mNext = v27;
          v15 = (UFG::InputMessage *)v15->mNext;
        }
        while ( v15 != (UFG::InputMessage *)&UFG::sRawInputState );
        v15 = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
      }
    }
    ++v13;
    --v14;
  }
  while ( v14 );
  if ( v15 != (UFG::InputMessage *)&UFG::sRawInputState )
  {
    do
    {
      v29 = v15->mPrev;
      v30 = v15->mNext;
      v29->mNext = v30;
      v30->mPrev = v29;
      v15->mPrev = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&v15->mPrev;
      v15->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&v15->mPrev;
      v31 = v15->mPrev;
      v32 = v15->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      v15->mPrev = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&v15->mPrev;
      v15->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&v15->mPrev;
      operator delete[](v15);
      v15 = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
    }
    while ( (UFG::RawInputState *)UFG::sRawInputState.mInputMessages.mNode.mNext != &UFG::sRawInputState );
  }
  if ( UFG::testController.active )
  {
    v33 = v3->mControllers[0];
    if ( SLODWORD(v33[1].vfptr) >= 0 )
    {
      UFG::fake_xinput((UFG *)this);
      *(_XINPUT_STATE *)&v33[1].mInputState.mKeyState[208] = UFG::sRawInputState.mXinputState;
    }
  }
  UFG::InputSystem::InternalUpdate((UFG::InputSystem *)&v3->vfptr, elapsedTime, simTime);
  if ( !v3->mbCheckForControllerDisconnect )
    v3->mbCheckForControllerDisconnect = 1;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  LOBYTE(v4) = outSettings.mEnableFullscreen != 0;
  v34 = v3->mControllers[UFG::gActiveControllerNum];
  if ( v34 && v34->m_IsKeyboardController )
  {
    v35 = UFG::InputSystem::msShouldRestrictCursorKeyboard[v4];
    v36 = UFG::InputSystem::msShouldHideCursorKeyboard[v4];
  }
  else
  {
    v35 = UFG::InputSystem::msShouldRestrictCursorGamepad[v4];
    v36 = UFG::InputSystem::msShouldHideCursorGamepad[v4];
  }
  UFG::InputSystem::msShouldHideCursor = v36;
  UFG::InputSystem::msShouldRestrictCursor = v35;
  if ( v35 != UFG::InputSystem::msCursorCurrentlyRestricted || v36 != UFG::InputSystem::msCursorCurrentlyHidden )
    UFG::Update_Cursor_Clip_and_Hide(ghWnd);
}

