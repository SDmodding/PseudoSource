// File Line: 132
// RVA: 0x15AE0A0
__int64 UFG::_dynamic_initializer_for__sRawInputState__()
{
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sRawInputState__);
}

// File Line: 349
// RVA: 0xA3CC70
_BOOL8 __fastcall UFG::InputState::IsPressed(UFG::InputState *this, int key)
{
  unsigned int v3; // eax

  if ( key == 18 )
  {
    LOWORD(v3) = GetKeyState(18);
    return (v3 >> 15) & 1;
  }
  else if ( key == 32 )
  {
    return gSpaceBarState != 0;
  }
  else
  {
    return this->mKeyState[key] < 0;
  }
}

// File Line: 392
// RVA: 0xA3D380
char __fastcall UFG::LocalMapVirtualKey(unsigned int wParam, unsigned int lParam)
{
  unsigned int v2; // ebx
  char v4; // al
  SHORT AsyncKeyState; // bx
  bool v6; // al

  v2 = lParam & 0x1000000;
  if ( (lParam & 0x1000000) == 0 && (unsigned int)BYTE2(lParam) - 71 <= 0xC )
    return keypad_codes[BYTE2(lParam) - 71];
  switch ( wParam )
  {
    case 0x10u:
      goto LABEL_8;
    case 0x11u:
      if ( v2 )
        return -93;
      AsyncKeyState = GetAsyncKeyState(162);
      v6 = (GetAsyncKeyState(165) & 0x8000) != 0;
      if ( (AsyncKeyState & 0x8000) != 0 && v6 )
        return -91;
      else
        return -94;
    case 0x12u:
      return (v2 != 0) - 92;
    case 0x5Du:
LABEL_8:
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
void __fastcall UFG::Update_Cursor_Clip_and_Hide(HWND hWnd)
{
  bool v2; // bl
  tagCURSORINFO pci; // [rsp+20h] [rbp-28h] BYREF
  tagPOINT Point; // [rsp+58h] [rbp+10h] BYREF

  pci.cbSize = 24;
  GetCursorInfo(&pci);
  v2 = pci.flags == 0;
  if ( UFG::InputSystem::msApplicationHasFocus
    && UFG::InputSystem::msPCKeyboardSwapMode != 1
    && UFG::InputSystem::msShouldRestrictCursor )
  {
    Point.x = 1;
    Point.y = 1;
    ClientToScreen(hWnd, &Point);
    GetClientRect(hWnd, &rcClip);
    rcClip.left = Point.x;
    rcClip.top = Point.y;
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
  tagFILTERKEYS *v1; // r8
  tagFILTERKEYS v2; // [rsp+20h] [rbp-28h] BYREF
  tagSTICKYKEYS pvParam; // [rsp+58h] [rbp+10h] BYREF
  tagTOGGLEKEYS v4; // [rsp+60h] [rbp+18h] BYREF

  if ( bAllowKeys )
  {
    SystemParametersInfoA(0x3Bu, 8u, &g_StartupStickyKeys, 0);
    SystemParametersInfoA(0x35u, 8u, &g_StartupToggleKeys, 0);
    v1 = &g_StartupFilterKeys;
LABEL_9:
    SystemParametersInfoA(0x33u, 0x18u, v1, 0);
    return;
  }
  pvParam = g_StartupStickyKeys;
  if ( (g_StartupStickyKeys.dwFlags & 1) == 0 )
  {
    pvParam.dwFlags = g_StartupStickyKeys.dwFlags & 0xFFFFFFF3;
    SystemParametersInfoA(0x3Bu, 8u, &pvParam, 0);
  }
  v4 = g_StartupToggleKeys;
  if ( (g_StartupToggleKeys.dwFlags & 1) == 0 )
  {
    v4.dwFlags = g_StartupToggleKeys.dwFlags & 0xFFFFFFF3;
    SystemParametersInfoA(0x35u, 8u, &v4, 0);
  }
  v2 = g_StartupFilterKeys;
  if ( (g_StartupFilterKeys.dwFlags & 1) == 0 )
  {
    v1 = &v2;
    v2.dwFlags = g_StartupFilterKeys.dwFlags & 0xFFFFFFF3;
    goto LABEL_9;
  }
}

// File Line: 622
// RVA: 0xA3AF60
void __fastcall UFG::DispatchUIMouseEvent(unsigned int uMsg, int mouse_x, int mouse_y)
{
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::allocator::free_link *v8; // rax

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
  LODWORD(v7[7].mNext) = uMsg;
  HIDWORD(v7[7].mNext) = mouse_x;
  LODWORD(v7[8].mNext) = mouse_y;
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v7);
}

// File Line: 631
// RVA: 0xA3BBC0
__int64 __fastcall UFG::InputPlat_MsgProc(
        HWND__ *hWnd,
        unsigned int uMsg,
        unsigned __int64 wParam,
        __int64 lParam,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        unsigned int a25,
        UFG::allocator::free_link *a26,
        HRAWINPUT a27)
{
  HRAWINPUT v30; // rcx
  int v31; // edi
  int v32; // r14d
  __int64 v33; // rsi
  UFG::allocator::free_link *v34; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v35; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v36; // rax
  bool v37; // cl
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v38; // rax
  __int16 v39; // bx
  __int16 v40; // di
  UFG::allocator::free_link *v41; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v42; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v43; // rax
  unsigned __int8 v44; // r15
  __int64 v45; // rcx
  int v46; // ecx
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
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *mPrev; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v71; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *mNext; // rax
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
  int v85; // r14d
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
  tagWINDOWINFO pwi; // [rsp+138h] [rbp-190h] BYREF
  tagTRACKMOUSEEVENT EventTrack; // [rsp+178h] [rbp-150h] BYREF
  int v115; // [rsp+248h] [rbp-80h]
  __int64 v116; // [rsp+250h] [rbp-78h]
  BYTE v117[8]; // [rsp+258h] [rbp-70h] BYREF

  v116 = -2i64;
  InstallKeyboardHook(1);
  v30 = a27;
  v31 = (unsigned __int16)a27;
  v32 = WORD1(a27);
  a27 = (HRAWINPUT)(wParam >> 16);
  v33 = 0i64;
  a25 = (WORD1(wParam) != 1) + 5;
  if ( uMsg <= 0x200 )
  {
    if ( uMsg == 0x200 )
    {
      if ( !mouse_tracking_enabled )
      {
        mouse_tracking_enabled = 1;
        EventTrack.cbSize = 24;
        EventTrack.dwFlags = 2;
        EventTrack.hwndTrack = hWnd;
        v115 = -1;
        TrackMouseEvent(&EventTrack);
      }
      if ( sIgnore_next_mouse_move )
      {
        sIgnore_next_mouse_move = 0;
        pwi.cbSize = 60;
        GetWindowInfo(hWnd, &pwi);
        UFG::InputSystem::msMouseArea = (UFG::InputSystem::MouseArea)pwi.rcClient;
      }
      else
      {
        UFG::Update_Cursor_Clip_and_Hide(hWnd);
        if ( !UFG::InputSystem::msMouseInputRawAvailable
          || !UFG::InputSystem::msMouseInputRawDesired
          || !UFG::InputSystem::msRelativeMouseMode )
        {
          if ( (UFG::RawInputState *)UFG::sRawInputState.mInputMessages.mNode.mNext != &UFG::sRawInputState )
          {
            mPrev = UFG::sRawInputState.mInputMessages.mNode.mPrev;
            if ( LOBYTE(UFG::sRawInputState.mInputMessages.mNode.mPrev[1].mPrev) == 4 )
            {
              v71 = UFG::sRawInputState.mInputMessages.mNode.mPrev->mPrev;
              mNext = UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext;
              v71->mNext = mNext;
              mNext->mPrev = v71;
              mPrev->mPrev = mPrev;
              mPrev->mNext = mPrev;
              a27 = (HRAWINPUT)mPrev;
              v73 = mPrev->mPrev;
              v74 = mPrev->mNext;
              v73->mNext = v74;
              v74->mPrev = v73;
              mPrev->mPrev = mPrev;
              mPrev->mNext = mPrev;
              operator delete[](mPrev);
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
          GetWindowInfo(hWnd, &pwi);
          UFG::InputSystem::msMouseArea = (UFG::InputSystem::MouseArea)pwi.rcClient;
          SetCursorPos(
            pwi.rcClient.left + (pwi.rcClient.right - pwi.rcClient.left) / 2,
            pwi.rcClient.top + (pwi.rcClient.bottom - pwi.rcClient.top) / 2);
          sIgnore_next_mouse_move = 1;
        }
      }
      if ( in_use_x == v31 && in_use_y == v32 )
      {
        bMouseIsInUse = 0;
      }
      else
      {
        in_use_x = v31;
        in_use_y = v32;
        bMouseIsInUse = 1;
      }
      return 0i64;
    }
    if ( uMsg <= 0xFF )
    {
      if ( uMsg == 0xFF )
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
      else if ( uMsg == 6 )
      {
        v34 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
        v35 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v34;
        a27 = (HRAWINPUT)v34;
        if ( wParam )
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
        UFG::AllowAccessibilityShortcutKeys(!v37);
      }
      return 0i64;
    }
    switch ( uMsg )
    {
      case 0x100u:
      case 0x104u:
        v44 = UFG::LocalMapVirtualKey(wParam, (unsigned int)v30);
        v45 = 0i64;
        while ( v44 != aKeysToIgnore[v45] )
        {
          if ( ++v45 >= 4 )
          {
            v46 = gSpaceBarState;
            if ( wParam == 32 )
              v46 = 1;
            gSpaceBarState = v46;
            GetKeyboardState(v117);
            v47 = MapVirtualKeyA(v44, 0);
            UFG::qMemSet(&a27, 0, 8u);
            ToUnicode(v44, v47, v117, (LPWSTR)&a27, 4, 0);
            v48 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
            v49 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v48;
            a26 = v48;
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
            a26 = v52;
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
        v56 = (unsigned __int8)UFG::LocalMapVirtualKey(wParam, (unsigned int)v30);
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
        v68->mUserData1 = wParam;
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v68);
        return 0i64;
      case 0x106u:
        return 1i64;
      default:
        return 0i64;
    }
    while ( (_BYTE)v56 != aKeysToIgnore[v57] )
    {
      if ( ++v57 >= 4 )
      {
        GetKeyboardState(v117);
        v58 = MapVirtualKeyA(v56, 0);
        UFG::qMemSet(&a27, 0, 8u);
        ToUnicode(v56, v58, v117, (LPWSTR)&a27, 4, 0);
        v59 = gSpaceBarState;
        if ( wParam == 32 )
          v59 = 0;
        gSpaceBarState = v59;
        v60 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
        v61 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v60;
        a26 = v60;
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
        a26 = v64;
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
        v65->mUserData1 = wParam;
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v65);
        return 1i64;
      }
    }
    return 1i64;
  }
  if ( uMsg <= 0x312 )
  {
    if ( uMsg != 786 )
    {
      switch ( uMsg )
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
          goto LABEL_97;
        case 0x202u:
        case 0x205u:
        case 0x208u:
        case 0x20Cu:
          switch ( uMsg )
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
              goto LABEL_124;
          }
          v100 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v96;
          v96->mPrev = v100;
          v96->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v96;
LABEL_124:
          UFG::DispatchUIMouseEvent(uMsg, v31, v32);
          if ( (wParam & 0x13) == 0 )
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
          goto LABEL_129;
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
          goto LABEL_97;
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
          goto LABEL_129;
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
          goto LABEL_97;
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
          goto LABEL_129;
        case 0x20Au:
          v107 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v108 = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)v107;
          a26 = v107;
          if ( v107 )
          {
            v107->mNext = v107;
            v107[1].mNext = v107;
            LOWORD(v107[2].mNext) = 10;
            WORD1(v107[2].mNext) = v31;
            WORD2(v107[2].mNext) = v32;
            v109 = (__int16)a27;
            HIWORD(v107[2].mNext) = (_WORD)a27;
            LODWORD(v107[3].mNext) = 0;
          }
          else
          {
            v108 = 0i64;
            v109 = (__int16)a27;
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
          *(_DWORD *)(v33 + 56) = uMsg;
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
LABEL_97:
          v91 = UFG::sRawInputState.mInputMessages.mNode.mPrev;
          UFG::sRawInputState.mInputMessages.mNode.mPrev->mNext = v90;
          v90->mPrev = v91;
          v90->mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
          UFG::sRawInputState.mInputMessages.mNode.mPrev = v90;
          SetCapture(hWnd);
          UFG::DispatchUIMouseEvent(uMsg, v31, v32);
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
LABEL_129:
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
            GetWindowInfo(hWnd, &pwi);
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
  UFG::eSignalType mSignalType; // eax

  v3 = elapsed_time + iad->mOffSeconds;
  mSignalType = iad->mSignalType;
  iad->mActionTrue = 0;
  iad->mOffSeconds = v3;
  switch ( mSignalType )
  {
    case OFF:
    case FALLING_EDGE:
    case FALLING_45:
    case FALLING_90:
      if ( buttonDown )
        iad->mDebouncer = 1;
      break;
    case ON:
    case RISING_EDGE:
    case ON_50:
    case RISING_50:
    case ON_95:
    case RISING_95:
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
  UFG::eSignalType mSignalType; // eax
  float v3; // xmm1_4
  float v4; // xmm1_4

  mSignalType = iad->mSignalType;
  iad->mActionTrue = 1;
  iad->mOffSeconds = 0.0;
  switch ( mSignalType )
  {
    case OFF:
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
    case ON:
    case ON_50:
    case ON_95:
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
    case RISING_EDGE:
    case RISING_50:
    case RISING_95:
      iad->mDebouncer = 1;
      iad->mAxisPositionX = 1.0;
      iad->mOnSeconds = 0.0;
      break;
    case FALLING_EDGE:
    case FALLING_45:
    case FALLING_90:
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
void __fastcall UFG::BasicButtonStub(UFG::InputActionData *inputActionData, bool buttonDown, float elapsed_time)
{
  bool v3; // al

  switch ( inputActionData->mSignalType )
  {
    case OFF:
      v3 = !buttonDown;
      goto LABEL_4;
    case ON:
    case ON_50:
    case ON_95:
      v3 = buttonDown;
LABEL_4:
      if ( !v3 )
        goto LABEL_5;
      goto LABEL_11;
    case RISING_EDGE:
    case RISING_50:
    case RISING_95:
      if ( !buttonDown || inputActionData->mDebouncer )
        goto LABEL_5;
      goto LABEL_11;
    case FALLING_EDGE:
    case FALLING_45:
    case FALLING_90:
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
void __fastcall UFG::Left_Stick_Click_Deadzone_Handler(
        UFG::Controller *controller,
        UFG::InputActionData *iad,
        float elapsed_time,
        bool buttonDown)
{
  __int16 *v6; // rax
  float v7; // xmm1_4
  bool v8; // dl

  v6 = (__int16 *)_RTDynamicCast(
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
  switch ( iad->mSignalType )
  {
    case ON:
    case ON_50:
    case ON_95:
      if ( !v8 && buttonDown )
        buttonDown = iad->mActionTrue;
      break;
    case RISING_EDGE:
    case RISING_50:
    case RISING_95:
      if ( !v8 && buttonDown )
        buttonDown = 0;
      break;
    default:
      break;
  }
  UFG::BasicButtonStub(iad, buttonDown, elapsed_time);
}

// File Line: 1214
// RVA: 0xA3D970
void __fastcall UFG::Remote_IAD_Func(
        UFG::RawPadData *remoteData,
        UFG::Controller *controller,
        UFG::InputActionData *inputActionData,
        float elapsed_time)
{
  __int64 mButton; // rdx
  bool v6; // di
  unsigned __int16 mGetXIState_Gamepad_wButtons; // ax
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
  int mGetXIState_Gamepad_bLeftTrigger; // eax
  float v52; // eax
  float v53; // eax
  float v54; // xmm8_4
  float v55; // xmm7_4
  bool v56; // zf

  mButton = inputActionData->mButton;
  v6 = 0;
  if ( (unsigned int)mButton >= 0x80 )
  {
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0i64;
    if ( (_DWORD)mButton == 137 )
    {
      v14 = _mm_cvtsi32_si128(remoteData->mGetState_lX);
      v15 = _mm_cvtsi32_si128(remoteData->mGetState_lY);
    }
    else if ( (_DWORD)mButton == 138 )
    {
      v14 = _mm_cvtsi32_si128(remoteData->mGetState_lZ);
      v15 = _mm_cvtsi32_si128(remoteData->mGetState_lRz);
    }
    else
    {
      if ( (_DWORD)mButton != 139 )
      {
        if ( (_DWORD)mButton == 140 )
        {
          v12 = (float)remoteData->mGetXIState_Gamepad_sThumbLX * 0.030517576;
          v13 = (__m128)COERCE_UNSIGNED_INT((float)remoteData->mGetXIState_Gamepad_sThumbLY);
          v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
        }
        else if ( (_DWORD)mButton == 141 )
        {
          v12 = (float)remoteData->mGetXIState_Gamepad_sThumbRX * 0.030517576;
          v13 = (__m128)COERCE_UNSIGNED_INT((float)remoteData->mGetXIState_Gamepad_sThumbRY);
          v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
        }
LABEL_17:
        switch ( (int)mButton )
        {
          case 129:
            v56 = remoteData->mGetState_rgdwPOV0 == 27000;
            goto LABEL_86;
          case 130:
            v56 = remoteData->mGetState_rgdwPOV0 == 9000;
            goto LABEL_86;
          case 131:
            v56 = remoteData->mGetState_rgdwPOV0 == 0;
            goto LABEL_86;
          case 132:
            v56 = remoteData->mGetState_rgdwPOV0 == 18000;
LABEL_86:
            v10 = elapsed_time;
            v6 = v56;
            goto LABEL_87;
          case 133:
            v50 = (float)remoteData->mGetState_lZ * 0.001;
            goto LABEL_73;
          case 134:
            v50 = (float)remoteData->mGetState_lZ * -0.001;
            goto LABEL_73;
          case 135:
            mGetXIState_Gamepad_bLeftTrigger = (unsigned __int8)remoteData->mGetXIState_Gamepad_bLeftTrigger;
            goto LABEL_72;
          case 136:
            mGetXIState_Gamepad_bLeftTrigger = (unsigned __int8)remoteData->mGetXIState_Gamepad_bRightTrigger;
LABEL_72:
            v50 = (float)mGetXIState_Gamepad_bLeftTrigger * 0.0039215689;
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
            inputActionData->mAxisPositionY = 0.0;
            inputActionData->mAxisPositionX = v11 / (float)(1.0 - v54);
            goto LABEL_88;
          case 137:
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
            v37 = _mm_sqrt_ps(v13).m128_f32[0] - 0.30000001;
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
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v40;
            inputActionData->mAxisPositionY = v41;
            if ( !v56 || inputActionData->mButton - 138 > 1 )
              goto LABEL_88;
            v42 = v41;
            v43 = v40;
            goto LABEL_67;
          case 138:
          case 139:
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
            v48 = _mm_sqrt_ps(v13).m128_f32[0] - 0.30000001;
            if ( v48 < 0.0 )
              v48 = 0.0;
            v49 = v48 * 1.4285715;
            v31 = cosf(v46) * v49;
            v32 = sinf(v47) * v49;
            if ( v31 != 0.0 || v32 != 0.0 )
              v6 = 1;
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v31;
            inputActionData->mAxisPositionY = v32;
            if ( !v56 || inputActionData->mButton - 138 > 1 )
              goto LABEL_88;
            goto LABEL_66;
          case 140:
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
            v20 = _mm_sqrt_ps(v13).m128_f32[0] - 0.33774078;
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
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            inputActionData->mAxisPositionX = v23;
            inputActionData->mAxisPositionY = v24;
            goto LABEL_88;
          case 141:
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
            v29 = _mm_sqrt_ps(v13).m128_f32[0] - 0.37388578;
            if ( v29 < 0.0 )
              v29 = 0.0;
            v30 = v29 * 1.5971527;
            v31 = cosf(v27) * v30;
            v32 = sinf(v28) * v30;
            if ( v31 != 0.0 || v32 != 0.0 )
              v6 = 1;
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v31;
            inputActionData->mAxisPositionY = v32;
            if ( !v56 )
              goto LABEL_88;
LABEL_66:
            v42 = v32;
            v43 = v31;
LABEL_67:
            UFG::Controller::UpdateRightThumbHistory(controller, v43, v42, elapsed_time);
            inputActionData->mActionTrue = UFG::Controller::RightStick_HoldThenFlickAcross(controller) != 0;
            goto LABEL_88;
          default:
            return;
        }
      }
      v14 = _mm_cvtsi32_si128(remoteData->mGetState_lRx);
      v15 = _mm_cvtsi32_si128(remoteData->mGetState_lRy);
    }
    LODWORD(v12) = _mm_cvtepi32_ps(v14).m128_u32[0];
    v13 = _mm_cvtepi32_ps(v15);
    goto LABEL_17;
  }
  mGetXIState_Gamepad_wButtons = remoteData->mGetXIState_Gamepad_wButtons;
  v9 = UFG::XINPUT_BUTTON_MASKS[mButton];
  if ( (remoteData->mGetXIState_Gamepad_wButtons & 0xF3FF) != 0 )
    controller->m_ControllerInUse = 1;
  v10 = elapsed_time;
  v6 = (v9 & mGetXIState_Gamepad_wButtons) != 0;
  if ( inputActionData->mButton == 10 )
    UFG::Left_Stick_Click_Deadzone_Handler(controller, inputActionData, elapsed_time, v6);
  else
LABEL_87:
    UFG::BasicButtonStub(inputActionData, v6, v10);
LABEL_88:
  if ( v6 )
  {
    if ( controller )
    {
      controller->m_fTimeSinceLastInput = 0.0;
      controller->m_ControllerInUse = 1;
    }
  }
}

// File Line: 1557
// RVA: 0xA3B160
void __fastcall UFG::Gamepad_IAD_Func(
        UFG::Controller *controller,
        UFG::InputActionData *inputActionData,
        float elapsed_time)
{
  bool v6; // di
  _DWORD *v7; // rax
  __int64 mButton; // rcx
  unsigned __int16 v9; // ax
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
  int v51; // eax
  float v52; // eax
  float v53; // eax
  float v54; // xmm8_4
  float v55; // xmm7_4
  bool v56; // zf

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
  v7 = _RTDynamicCast(controller, 0, &UFG::Controller `RTTI Type Descriptor, &UFG::Gamepad `RTTI Type Descriptor, 0);
  mButton = inputActionData->mButton;
  if ( (unsigned int)mButton >= 0x80 )
  {
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0i64;
    if ( (_DWORD)mButton == 137 )
    {
      v14 = _mm_cvtsi32_si128(v7[461]);
      v15 = _mm_cvtsi32_si128(v7[462]);
    }
    else if ( (_DWORD)mButton == 138 )
    {
      v14 = _mm_cvtsi32_si128(v7[463]);
      v15 = _mm_cvtsi32_si128(v7[466]);
    }
    else
    {
      if ( (_DWORD)mButton != 139 )
      {
        if ( (_DWORD)mButton == 140 )
        {
          v12 = (float)*((__int16 *)v7 + 1062) * 0.030517576;
          v13 = (__m128)COERCE_UNSIGNED_INT((float)*((__int16 *)v7 + 1063));
          v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
        }
        else if ( (_DWORD)mButton == 141 )
        {
          v12 = (float)*((__int16 *)v7 + 1064) * 0.030517576;
          v13 = (__m128)COERCE_UNSIGNED_INT((float)*((__int16 *)v7 + 1065));
          v13.m128_f32[0] = v13.m128_f32[0] * -0.030517576;
        }
LABEL_21:
        switch ( (int)mButton )
        {
          case 129:
            v56 = v7[469] == 27000;
            goto LABEL_90;
          case 130:
            v56 = v7[469] == 9000;
            goto LABEL_90;
          case 131:
            v56 = v7[469] == 0;
            goto LABEL_90;
          case 132:
            v56 = v7[469] == 18000;
LABEL_90:
            v6 = v56;
            goto LABEL_91;
          case 133:
            v50 = (float)(int)v7[463] * 0.001;
            goto LABEL_77;
          case 134:
            v50 = (float)(int)v7[463] * -0.001;
            goto LABEL_77;
          case 135:
            v51 = *((unsigned __int8 *)v7 + 2122);
            goto LABEL_76;
          case 136:
            v51 = *((unsigned __int8 *)v7 + 2123);
LABEL_76:
            v50 = (float)v51 * 0.0039215689;
LABEL_77:
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
            inputActionData->mAxisPositionY = 0.0;
            inputActionData->mAxisPositionX = v11 / (float)(1.0 - v54);
            goto LABEL_92;
          case 137:
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
            v37 = _mm_sqrt_ps(v13).m128_f32[0] - 0.30000001;
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
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v40;
            inputActionData->mAxisPositionY = v41;
            if ( !v56 || inputActionData->mButton - 138 > 1 )
              goto LABEL_92;
            v42 = v41;
            v43 = v40;
            goto LABEL_71;
          case 138:
          case 139:
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
            v48 = _mm_sqrt_ps(v13).m128_f32[0] - 0.30000001;
            if ( v48 < 0.0 )
              v48 = 0.0;
            v49 = v48 * 1.4285715;
            v31 = cosf(v46) * v49;
            v32 = sinf(v47) * v49;
            if ( v31 != 0.0 || v32 != 0.0 )
              v6 = 1;
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v31;
            inputActionData->mAxisPositionY = v32;
            if ( !v56 || inputActionData->mButton - 138 > 1 )
              goto LABEL_92;
            goto LABEL_70;
          case 140:
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
            v20 = _mm_sqrt_ps(v13).m128_f32[0] - 0.33774078;
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
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            inputActionData->mAxisPositionX = v23;
            inputActionData->mAxisPositionY = v24;
            goto LABEL_92;
          case 141:
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
            v29 = _mm_sqrt_ps(v13).m128_f32[0] - 0.37388578;
            if ( v29 < 0.0 )
              v29 = 0.0;
            v30 = v29 * 1.5971527;
            v31 = cosf(v27) * v30;
            v32 = sinf(v28) * v30;
            if ( v31 != 0.0 || v32 != 0.0 )
              v6 = 1;
            UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
            v56 = inputActionData->mSignalType == HOLD_THEN_FLICK;
            inputActionData->mAxisPositionX = v31;
            inputActionData->mAxisPositionY = v32;
            if ( !v56 )
              goto LABEL_92;
LABEL_70:
            v42 = v32;
            v43 = v31;
LABEL_71:
            UFG::Controller::UpdateRightThumbHistory(controller, v43, v42, elapsed_time);
            inputActionData->mActionTrue = UFG::Controller::RightStick_HoldThenFlickAcross(controller) != 0;
            goto LABEL_92;
          default:
            return;
        }
      }
      v14 = _mm_cvtsi32_si128(v7[464]);
      v15 = _mm_cvtsi32_si128(v7[465]);
    }
    LODWORD(v12) = _mm_cvtepi32_ps(v14).m128_u32[0];
    v13 = _mm_cvtepi32_ps(v15);
    goto LABEL_21;
  }
  if ( (int)v7[460] < 0 )
  {
    v6 = *((_BYTE *)v7 + mButton + 1892) != 0;
  }
  else
  {
    v9 = *((_WORD *)v7 + 1060);
    v10 = UFG::XINPUT_BUTTON_MASKS[mButton];
    if ( (v9 & 0xF3FF) != 0 )
      controller->m_ControllerInUse = 1;
    v6 = (v10 & v9) != 0;
    if ( inputActionData->mButton == 10 )
    {
      UFG::Left_Stick_Click_Deadzone_Handler(controller, inputActionData, elapsed_time, v6);
      goto LABEL_92;
    }
  }
LABEL_91:
  UFG::BasicButtonStub(inputActionData, v6, elapsed_time);
LABEL_92:
  if ( v6 )
  {
    controller->m_fTimeSinceLastInput = 0.0;
    controller->m_ControllerInUse = 1;
  }
}

// File Line: 1920
// RVA: 0xA3D0C0
void __fastcall UFG::Keyboard_IAD_Func(
        UFG::Controller *controller,
        UFG::InputActionData *inputActionData,
        float elapsed_time)
{
  __int64 mButton_low; // rbx
  __int64 v4; // rsi
  __int64 v5; // rbp
  __int64 mButton_high; // r14
  bool v9; // al
  bool v10; // al
  int v11; // r13d
  bool v12; // al
  int v13; // r12d
  bool v14; // al
  int v15; // edx
  int v16; // eax
  bool v17; // bl
  int v18; // ebx
  BOOL v19; // ecx
  int v20; // ebx
  BOOL v21; // ecx
  int v22; // ebx
  int v23; // ebx
  int v24; // [rsp+60h] [rbp+8h]

  mButton_low = LOBYTE(inputActionData->mButton);
  v4 = BYTE1(inputActionData->mButton);
  v5 = BYTE2(inputActionData->mButton);
  mButton_high = HIBYTE(inputActionData->mButton);
  if ( (_DWORD)mButton_low == 18 )
  {
    v9 = (GetKeyState(18) & 0x8000) != 0;
  }
  else if ( (_DWORD)mButton_low == 32 )
  {
    v9 = gSpaceBarState != 0;
  }
  else
  {
    v9 = controller->mInputState.mKeyState[mButton_low] < 0;
  }
  v24 = v9;
  if ( (_DWORD)v4 == 18 )
  {
    v10 = (GetKeyState(18) & 0x8000) != 0;
  }
  else if ( (_DWORD)v4 == 32 )
  {
    v10 = gSpaceBarState != 0;
  }
  else
  {
    v10 = controller->mInputState.mKeyState[v4] < 0;
  }
  v11 = v10;
  if ( (_DWORD)v5 == 18 )
  {
    v12 = (GetKeyState(18) & 0x8000) != 0;
  }
  else if ( (_DWORD)v5 == 32 )
  {
    v12 = gSpaceBarState != 0;
  }
  else
  {
    v12 = controller->mInputState.mKeyState[v5] < 0;
  }
  v13 = v12;
  if ( (_DWORD)mButton_high == 18 )
  {
    v14 = (GetKeyState(18) & 0x8000) != 0;
  }
  else if ( (_DWORD)mButton_high == 32 )
  {
    v14 = gSpaceBarState != 0;
  }
  else
  {
    v14 = controller->mInputState.mKeyState[mButton_high] < 0;
  }
  v15 = v14;
  v16 = 0;
  v17 = (int)mButton_low <= 0 || v24 > 0;
  v18 = v17;
  v19 = (int)v4 <= 0 || v11 > 0;
  v20 = v19 & v18;
  v21 = (int)v5 <= 0 || v13 > 0;
  v22 = v21 & v20;
  if ( (int)mButton_high <= 0 )
    v16 = 1;
  else
    LOBYTE(v16) = v15 > 0;
  v23 = v16 & v22;
  UFG::BasicButtonStub(inputActionData, v23 != 0, elapsed_time);
  if ( v23 || bMouseIsInUse )
  {
    controller->m_ControllerInUse = 1;
    bMouseIsInUse = 0;
  }
}

// File Line: 1955
// RVA: 0xA3E2E0
void __fastcall UFG::Two_Axis_Keyboard_IAD_Func(
        UFG::Controller *controller,
        UFG::InputActionData *inputActionData,
        float elapsed_time)
{
  __int64 mButton_low; // rax
  __int64 v4; // rsi
  __int64 v5; // r15
  __int64 mButton_high; // r12
  bool v10; // al
  float y; // xmm1_4
  float x; // xmm2_4
  bool v13; // al
  SHORT KeyState; // ax
  __m128 v15; // xmm8
  float v16; // xmm9_4
  bool v17; // al
  SHORT v18; // ax
  bool v19; // al
  SHORT v20; // ax
  float v21; // xmm9_4
  __m128 v22; // xmm1
  float v23; // xmm7_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // eax
  float v28; // eax
  UFG::qVector2 v29; // [rsp+C0h] [rbp+40h]
  unsigned __int64 v30; // [rsp+C8h] [rbp+48h]
  unsigned __int64 v31; // [rsp+C8h] [rbp+48h]
  float v32; // [rsp+D8h] [rbp+58h]
  float v33; // [rsp+DCh] [rbp+5Ch]

  mButton_low = LOBYTE(inputActionData->mButton);
  v4 = BYTE1(inputActionData->mButton);
  v5 = BYTE2(inputActionData->mButton);
  mButton_high = HIBYTE(inputActionData->mButton);
  if ( (_DWORD)mButton_low == 18 )
  {
    v10 = (GetKeyState(18) & 0x8000) != 0;
  }
  else if ( (_DWORD)mButton_low == 32 )
  {
    v10 = gSpaceBarState != 0;
  }
  else
  {
    v10 = controller->mInputState.mKeyState[mButton_low] < 0;
  }
  y = UFG::qVector2::msZero.y;
  x = UFG::qVector2::msZero.x;
  if ( v10 )
    v29 = (UFG::qVector2)3212836864i64;
  else
    v29 = UFG::qVector2::msZero;
  if ( (_DWORD)v4 == 18 )
  {
    KeyState = GetKeyState(18);
    y = UFG::qVector2::msZero.y;
    x = UFG::qVector2::msZero.x;
    v13 = (KeyState & 0x8000) != 0;
  }
  else if ( (_DWORD)v4 == 32 )
  {
    v13 = gSpaceBarState != 0;
  }
  else
  {
    v13 = controller->mInputState.mKeyState[v4] < 0;
  }
  if ( v13 )
    v30 = 1065353216i64;
  else
    v30 = __PAIR64__(LODWORD(y), LODWORD(x));
  v15 = (__m128)(unsigned int)v30;
  v16 = *((float *)&v30 + 1);
  if ( (_DWORD)v5 == 18 )
  {
    v18 = GetKeyState(18);
    y = UFG::qVector2::msZero.y;
    x = UFG::qVector2::msZero.x;
    v17 = (v18 & 0x8000) != 0;
  }
  else if ( (_DWORD)v5 == 32 )
  {
    v17 = gSpaceBarState != 0;
  }
  else
  {
    v17 = controller->mInputState.mKeyState[v5] < 0;
  }
  if ( v17 )
    v31 = 0x3F80000000000000i64;
  else
    v31 = __PAIR64__(LODWORD(y), LODWORD(x));
  if ( (_DWORD)mButton_high == 18 )
  {
    v20 = GetKeyState(\x12);
    y = UFG::qVector2::msZero.y;
    x = UFG::qVector2::msZero.x;
    v19 = (v20 & 0x8000) != 0;
  }
  else if ( (_DWORD)mButton_high == 32 )
  {
    v19 = gSpaceBarState != 0;
  }
  else
  {
    v19 = controller->mInputState.mKeyState[mButton_high] < 0;
  }
  if ( v19 )
  {
    v32 = 0.0;
    v33 = -1.0;
  }
  else
  {
    v32 = x;
    v33 = y;
  }
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] + v29.x) + *(float *)&v31) + v32;
  v21 = (float)((float)(v16 + v29.y) + *((float *)&v31 + 1)) + v33;
  v22 = v15;
  v22.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v21 * v21);
  if ( v22.m128_f32[0] == 0.0 )
    v23 = 0.0;
  else
    v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
  v24 = v23;
  v25 = v23 * v21;
  v26 = v24 * v15.m128_f32[0];
  UFG::BasicButtonStub(inputActionData, (float)((float)(v26 * v26) + (float)(v25 * v25)) > 0.0, elapsed_time);
  inputActionData->mAxisRawX[2] = inputActionData->mAxisRawX[1];
  inputActionData->mAxisRawX[1] = inputActionData->mAxisRawX[0];
  v27 = inputActionData->mAxisRawY[1];
  inputActionData->mAxisRawX[0] = v26;
  inputActionData->mAxisRawY[2] = v27;
  v28 = inputActionData->mAxisRawY[0];
  inputActionData->mAxisRawY[0] = v25;
  inputActionData->mAxisRawY[1] = v28;
  inputActionData->mAxisPositionX = v26;
  inputActionData->mAxisPositionY = v25;
}

// File Line: 1987
// RVA: 0xA3D460
void __fastcall UFG::Mouse_IAD_Func(UFG::Controller *controller, UFG::WayGraph *inputActionData, const float __formal)
{
  UFG::InputState *p_mInputState; // rdi
  UFG::WayGraph *v5; // rdx
  UFG::WayGraph *v6; // rdx
  float v7; // xmm7_4
  bool v8; // al
  char v9; // si
  float v10; // xmm6_4
  UFG::WayGraph *v11; // rdx
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // r14d
  int v15; // r15d
  int WayEdge; // ebp
  UFG::WayGraph *v17; // rdx
  int WayNode; // ecx
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm0_4

  p_mInputState = &controller->mInputState;
  HIDWORD(inputActionData[2].vfptr) = (__int16)UFG::WayFinderClient::GetWayEdge(
                                                 (UFG::WayFinderClient *)&controller->mInputState,
                                                 inputActionData);
  LODWORD(inputActionData[3].vfptr) = (__int16)UFG::WayFinderClient::GetWayNode(
                                                 (UFG::WayFinderClient *)p_mInputState,
                                                 v5);
  LOBYTE(v6) = p_mInputState->mKeyState[2] < 0;
  HIDWORD(inputActionData[3].vfptr) = (p_mInputState->mKeyState[1] < 0) | (2
                                                                         * ((p_mInputState->mKeyState[4] < 0) | (2 * ((unsigned __int8)v6 | (2 * ((p_mInputState->mKeyState[5] < 0) | (2 * (p_mInputState->mKeyState[6] < 0))))))));
  v7 = UFG::InputSystem::msMouseSensitivity;
  if ( (_S1_33 & 1) != 0 )
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
      v10 = (float)(__int16)UFG::WayFinderClient::GetWayEdge((UFG::WayFinderClient *)p_mInputState, v6) * v7;
      v12 = (float)(__int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)p_mInputState, v11) * v7;
      LODWORD(inputActionData[6].vfptr) = HIDWORD(inputActionData[5].vfptr);
      HIDWORD(inputActionData[5].vfptr) = inputActionData[5].vfptr;
      *(float *)&inputActionData[5].vfptr = v10;
      HIDWORD(inputActionData[7].vfptr) = inputActionData[7].vfptr;
      LODWORD(inputActionData[7].vfptr) = HIDWORD(inputActionData[6].vfptr);
      *((float *)&inputActionData[6].vfptr + 1) = v12;
      v13 = 0.0;
      if ( v9 )
        v10 = 0.0;
      *(float *)&inputActionData[4].vfptr = v10;
      if ( !v9 )
        v13 = v12;
      *((float *)&inputActionData[4].vfptr + 1) = v13;
      *(_DWORD *)&p_mInputState->mPrevMouseX = 0;
      *(_DWORD *)&p_mInputState->mMouseX = 0;
    }
    else
    {
      v14 = (UFG::InputSystem::msMouseArea.mRight - UFG::InputSystem::msMouseArea.mLeft) / 2;
      v15 = (UFG::InputSystem::msMouseArea.mBottom - UFG::InputSystem::msMouseArea.mTop) / 2;
      WayEdge = (__int16)UFG::WayFinderClient::GetWayEdge(
                           (UFG::WayFinderClient *)p_mInputState,
                           (UFG::WayGraph *)(unsigned int)((UFG::InputSystem::msMouseArea.mBottom
                                                          - UFG::InputSystem::msMouseArea.mTop) >> 31));
      WayNode = (__int16)UFG::WayFinderClient::GetWayNode((UFG::WayFinderClient *)p_mInputState, v17);
      v19 = 0.0;
      v20 = 0.0;
      v21 = 0.0;
      if ( WayEdge >= 0 )
      {
        v20 = (float)(WayEdge - v14) * v7;
        v21 = (float)(WayNode - v15) * v7;
      }
      LODWORD(inputActionData[6].vfptr) = HIDWORD(inputActionData[5].vfptr);
      HIDWORD(inputActionData[5].vfptr) = inputActionData[5].vfptr;
      *(float *)&inputActionData[5].vfptr = v20;
      HIDWORD(inputActionData[7].vfptr) = inputActionData[7].vfptr;
      LODWORD(inputActionData[7].vfptr) = HIDWORD(inputActionData[6].vfptr);
      *((float *)&inputActionData[6].vfptr + 1) = v21;
      if ( v9 )
        v20 = 0.0;
      *(float *)&inputActionData[4].vfptr = v20;
      if ( !v9 )
        v19 = v21;
      *((float *)&inputActionData[4].vfptr + 1) = v19;
      p_mInputState->mPrevMouseX = v14;
      p_mInputState->mMouseX = v14;
      p_mInputState->mPrevMouseY = v15;
      p_mInputState->mMouseY = v15;
    }
  }
  else
  {
    v22 = (float)(__int16)UFG::InputState::GetMouseDeltaX(p_mInputState) * v7;
    v23 = (float)(__int16)UFG::InputState::GetMouseDeltaY(p_mInputState) * v7;
    LODWORD(inputActionData[6].vfptr) = HIDWORD(inputActionData[5].vfptr);
    HIDWORD(inputActionData[5].vfptr) = inputActionData[5].vfptr;
    *(float *)&inputActionData[5].vfptr = v22;
    HIDWORD(inputActionData[7].vfptr) = inputActionData[7].vfptr;
    LODWORD(inputActionData[7].vfptr) = HIDWORD(inputActionData[6].vfptr);
    *((float *)&inputActionData[6].vfptr + 1) = v23;
    v24 = 0.0;
    if ( v9 )
      v22 = 0.0;
    *(float *)&inputActionData[4].vfptr = v22;
    if ( !v9 )
      v24 = v23;
    *((float *)&inputActionData[4].vfptr + 1) = v24;
  }
  BYTE4(inputActionData[9].vfptr) = 1;
}

// File Line: 2087
// RVA: 0xA3D730
void __fastcall UFG::Mouse_Wheel_IAD_Func(
        UFG::Controller *controller,
        UFG::WayGraph *inputActionData,
        float elapsed_time)
{
  UFG::InputState *p_mInputState; // rbx
  UFG::WayGraph *v5; // rdx
  float MouseWheelDelta; // xmm0_4
  float v7; // xmm6_4
  bool v8; // bl
  float v9; // eax

  p_mInputState = &controller->mInputState;
  HIDWORD(inputActionData[2].vfptr) = (__int16)UFG::WayFinderClient::GetWayEdge(
                                                 (UFG::WayFinderClient *)&controller->mInputState,
                                                 inputActionData);
  LODWORD(inputActionData[3].vfptr) = (__int16)UFG::WayFinderClient::GetWayNode(
                                                 (UFG::WayFinderClient *)p_mInputState,
                                                 v5);
  HIDWORD(inputActionData[3].vfptr) = (p_mInputState->mKeyState[1] < 0) | (2
                                                                         * ((p_mInputState->mKeyState[4] < 0) | (2 * ((p_mInputState->mKeyState[2] < 0) | (2 * ((p_mInputState->mKeyState[5] < 0) | (2 * (p_mInputState->mKeyState[6] < 0))))))));
  MouseWheelDelta = UFG::InputState::GetMouseWheelDelta(p_mInputState);
  v7 = MouseWheelDelta;
  if ( LODWORD(inputActionData->vfptr) == 156 )
  {
    v8 = MouseWheelDelta <= -1.0;
  }
  else
  {
    if ( LODWORD(inputActionData->vfptr) != 157 )
      return;
    v8 = MouseWheelDelta >= 1.0;
  }
  UFG::BasicButtonStub((UFG::InputActionData *)inputActionData, v8, elapsed_time);
  if ( !v8 )
    v7 = 0.0;
  LODWORD(inputActionData[6].vfptr) = HIDWORD(inputActionData[5].vfptr);
  HIDWORD(inputActionData[5].vfptr) = inputActionData[5].vfptr;
  v9 = *(float *)&inputActionData[7].vfptr;
  *(float *)&inputActionData[5].vfptr = v7;
  *((float *)&inputActionData[7].vfptr + 1) = v9;
  LODWORD(inputActionData[7].vfptr) = HIDWORD(inputActionData[6].vfptr);
  HIDWORD(inputActionData[6].vfptr) = 0;
  HIDWORD(inputActionData[4].vfptr) = 0;
  *(float *)&inputActionData[4].vfptr = v7;
}

// File Line: 2149
// RVA: 0xA3CCC0
__int64 __fastcall UFG::IsXInputDevice(_GUID *pGuidProductFromDirectInput)
{
  wchar_t *v2; // r14
  unsigned __int8 v3; // di
  bool v4; // r12
  __int64 v5; // rsi
  wchar_t *v6; // r13
  wchar_t *v7; // r12
  int v8; // ebx
  __int64 *v9; // rdi
  const wchar_t *v10; // rax
  int v11; // eax
  int v12; // ecx
  const wchar_t *v13; // rax
  int v14; // eax
  unsigned __int16 v15; // cx
  __int64 *v16; // rbx
  int v18; // [rsp+50h] [rbp-B0h] BYREF
  LPVOID ppv; // [rsp+58h] [rbp-A8h] BYREF
  IUnknown *pProxy; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v21; // [rsp+68h] [rbp-98h] BYREF
  __int16 v22; // [rsp+70h] [rbp-90h] BYREF
  wchar_t *wcs1; // [rsp+78h] [rbp-88h]
  __int64 v24[26]; // [rsp+90h] [rbp-70h] BYREF
  bool v25; // [rsp+178h] [rbp+78h]
  int v26; // [rsp+180h] [rbp+80h] BYREF
  unsigned int v27; // [rsp+188h] [rbp+88h] BYREF

  ppv = 0i64;
  v21 = 0i64;
  memset(v24, 0, 160);
  pProxy = 0i64;
  v2 = 0i64;
  v27 = 0;
  v3 = 0;
  v4 = CoInitialize(0i64) >= 0;
  v25 = v4;
  v5 = 20i64;
  if ( CoCreateInstance(
         &GUID_4590f811_1d3a_11d0_891f_00aa004b2e24,
         0i64,
         1u,
         &GUID_dc12a687_737f_11cf_884d_00aa004b2e24,
         &ppv) >= 0 )
  {
    if ( ppv )
    {
      v6 = SysAllocString(L"\\\\.\\root\\cimv2");
      if ( v6 )
      {
        v7 = SysAllocString(L"Win32_PNPEntity");
        if ( v7 )
        {
          v2 = SysAllocString(L"DeviceID");
          if ( v2 )
          {
            if ( (*(int (__fastcall **)(LPVOID, wchar_t *, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, IUnknown **))(*(_QWORD *)ppv + 24i64))(
                   ppv,
                   v6,
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
                if ( ((int (__fastcall *)(IUnknown *, wchar_t *, _QWORD, _QWORD, __int64 *))pProxy->vfptr[6].QueryInterface)(
                       pProxy,
                       v7,
                       0i64,
                       0i64,
                       &v21) >= 0
                  && v21
                  && (*(int (__fastcall **)(__int64, __int64, __int64, __int64 *, unsigned int *))(*(_QWORD *)v21 + 32i64))(
                       v21,
                       10000i64,
                       20i64,
                       v24,
                       &v27) >= 0 )
                {
                  while ( 1 )
                  {
                    if ( !v27 )
                    {
LABEL_31:
                      v3 = 0;
                      goto $LCleanup;
                    }
                    v8 = 0;
                    if ( v27 )
                      break;
LABEL_30:
                    if ( (*(int (__fastcall **)(__int64, __int64, __int64, __int64 *, unsigned int *))(*(_QWORD *)v21 + 32i64))(
                           v21,
                           10000i64,
                           20i64,
                           v24,
                           &v27) < 0 )
                      goto LABEL_31;
                  }
                  while ( 1 )
                  {
                    v9 = &v24[v8];
                    if ( (*(int (__fastcall **)(__int64, wchar_t *, _QWORD, __int16 *, _QWORD, _QWORD))(*(_QWORD *)*v9 + 32i64))(
                           *v9,
                           v2,
                           0i64,
                           &v22,
                           0i64,
                           0i64) >= 0
                      && v22 == 8
                      && wcs1
                      && wcsstr(wcs1, L"IG_") )
                    {
                      v18 = 0;
                      v26 = 0;
                      v10 = wcsstr(wcs1, L"VID_");
                      if ( v10 )
                      {
                        v11 = swscanf(v10, L"VID_%4X", &v26);
                        v12 = v26;
                        if ( v11 != 1 )
                          v12 = 0;
                        v26 = v12;
                      }
                      v13 = wcsstr(wcs1, L"PID_");
                      if ( v13 )
                      {
                        v14 = swscanf(v13, L"PID_%4X", &v18);
                        v15 = v18;
                        if ( v14 != 1 )
                          v15 = 0;
                      }
                      else
                      {
                        v15 = v18;
                      }
                      if ( ((unsigned __int16)v26 | (v15 << 16)) == pGuidProductFromDirectInput->Data1 )
                        break;
                    }
                    if ( *v9 )
                    {
                      (*(void (__fastcall **)(__int64))(*(_QWORD *)*v9 + 16i64))(*v9);
                      *v9 = 0i64;
                    }
                    if ( ++v8 >= v27 )
                      goto LABEL_30;
                  }
                  v3 = 1;
                }
              }
            }
          }
        }
$LCleanup:
        SysFreeString(v6);
        if ( v2 )
          SysFreeString(v2);
        if ( v7 )
          SysFreeString(v7);
        v4 = v25;
      }
    }
  }
  v16 = v24;
  do
  {
    if ( *v16 )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)*v16 + 16i64))(*v16);
      *v16 = 0i64;
    }
    ++v16;
    --v5;
  }
  while ( v5 );
  if ( v21 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v21 + 16i64))(v21);
    v21 = 0i64;
  }
  if ( ppv )
  {
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16i64))(ppv);
    ppv = 0i64;
  }
  if ( pProxy )
  {
    pProxy->vfptr->Release(pProxy);
    pProxy = 0i64;
  }
  if ( v4 )
    CoUninitialize();
  return v3;
}

// File Line: 2256
// RVA: 0xA3B9C0
void UFG::InputSystem::Init(void)
{
  HWND__ *v0; // rbx
  UFG::allocator::free_link *v1; // rax
  tagRAWINPUTDEVICE pRawInputDevices; // [rsp+28h] [rbp-20h] BYREF

  v0 = ghWnd;
  v1 = UFG::qMalloc(0x50ui64, "InputSystem", 0i64);
  if ( v1 )
    UFG::DxInputSystem::DxInputSystem((UFG::DxInputSystem *)v1, v0);
  UFG::gInputSystem = (UFG::InputSystem *)v1;
  *(_QWORD *)&pRawInputDevices.usUsagePage = 131073i64;
  pRawInputDevices.hwndTarget = ghWnd;
  UFG::InputSystem::msMouseInputRawAvailable = RegisterRawInputDevices(&pRawInputDevices, 1u, 0x10u);
  UFG::qMemSet(&UFG::sRawInputState, 0, 0x138u);
  UFG::sRawInputState.mInputMessages.mNode.mPrev = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
  UFG::sRawInputState.mInputMessages.mNode.mNext = (UFG::qNode<UFG::InputMessage,UFG::InputMessage> *)&UFG::sRawInputState;
}

// File Line: 2277
// RVA: 0xA3AE20
void UFG::InputSystem::Close(void)
{
  if ( UFG::gInputSystem )
    UFG::gInputSystem->vfptr->__vecDelDtor(UFG::gInputSystem, 1i64);
  UFG::gInputSystem = 0i64;
}

// File Line: 2284
// RVA: 0xA3D850
UFG::RawPadData *__fastcall UFG::DxController::ReadRawPadData(UFG::DxController *this)
{
  UFG::RawPadData *p_mRemoteData; // rbx
  void *v2; // rdx
  UFG::RawPadData *result; // rax

  p_mRemoteData = &this->mRemoteData;
  v2 = _RTDynamicCast(this, 0, &UFG::DxController `RTTI Type Descriptor, &UFG::Gamepad `RTTI Type Descriptor, 0);
  p_mRemoteData->mGetXIState_Gamepad_wButtons = *((_WORD *)v2 + 1060);
  p_mRemoteData->mGetState_lRx = *((_DWORD *)v2 + 464);
  p_mRemoteData->mGetState_lRy = *((_DWORD *)v2 + 465);
  p_mRemoteData->mGetState_lRz = *((_DWORD *)v2 + 466);
  p_mRemoteData->mGetState_lX = *((_DWORD *)v2 + 461);
  p_mRemoteData->mGetState_lY = *((_DWORD *)v2 + 462);
  p_mRemoteData->mGetState_lZ = *((_DWORD *)v2 + 463);
  result = p_mRemoteData;
  p_mRemoteData->mGetXIState_Gamepad_sThumbLX = *((_WORD *)v2 + 1062);
  p_mRemoteData->mGetXIState_Gamepad_sThumbLY = *((_WORD *)v2 + 1063);
  p_mRemoteData->mGetXIState_Gamepad_sThumbRX = *((_WORD *)v2 + 1064);
  p_mRemoteData->mGetXIState_Gamepad_sThumbRY = *((_WORD *)v2 + 1065);
  p_mRemoteData->mGetXIState_Gamepad_bLeftTrigger = *((_BYTE *)v2 + 2122);
  p_mRemoteData->mGetXIState_Gamepad_bRightTrigger = *((_BYTE *)v2 + 2123);
  p_mRemoteData->mGetState_rgdwPOV0 = *((_DWORD *)v2 + 469);
  return result;
}

// File Line: 2312
// RVA: 0xA3E120
void __fastcall UFG::DxController::SetRawPadData(UFG::DxController *this, _DWORD *prpd)
{
  unsigned int v2; // eax

  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_wButtons = *prpd;
  this->mRemoteData.mGetState_lRx = prpd[1];
  this->mRemoteData.mGetState_lRy = prpd[2];
  this->mRemoteData.mGetState_lRz = prpd[3];
  this->mRemoteData.mGetState_lX = prpd[4];
  this->mRemoteData.mGetState_lY = prpd[5];
  this->mRemoteData.mGetState_lZ = prpd[6];
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_sThumbLX = prpd[7];
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_sThumbRX = prpd[8];
  *(_DWORD *)&this->mRemoteData.mGetXIState_Gamepad_bLeftTrigger = prpd[9];
  v2 = prpd[10];
  *(_WORD *)&this->mIsInitialized = 257;
  this->mRemoteData.mGetState_rgdwPOV0 = v2;
}

// File Line: 2333
// RVA: 0xA3AA80
void __fastcall UFG::DxController::~DxController(UFG::DxController *this)
{
  this->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  UFG::Controller::~Controller(this);
}

// File Line: 2340
// RVA: 0xA3A8E0
void __fastcall UFG::Keyboard::Keyboard(UFG::Keyboard *this, unsigned int index, HWND__ *hWnd, void *di)
{
  int v8; // edi
  UFG::InputActionMap **v9; // rbx
  int v10; // edi
  UFG::MultiInputMap **v11; // rbx
  int v12; // eax

  UFG::Controller::Controller(this, index);
  this->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  this->mXinputUserIndex = -1;
  memset(&this->mState, 0, sizeof(this->mState));
  *(_QWORD *)&this->mXinputState.dwPacketNumber = 0i64;
  *(_QWORD *)&this->mXinputState.Gamepad.sThumbLX = 0i64;
  this->vfptr = (UFG::ControllerVtbl *)&UFG::Keyboard::`vftable;
  (*(void (__fastcall **)(void *, GUID *, IDirectInputDevice8A **, _QWORD, __int64))(*(_QWORD *)di + 24i64))(
    di,
    &GUID_SysKeyboard,
    &this->mDevice,
    0i64,
    -2i64);
  ((void (__fastcall *)(IDirectInputDevice8A *, _DIDATAFORMAT *))this->mDevice->vfptr[3].Release)(
    this->mDevice,
    &c_dfDIKeyboard);
  ((void (__fastcall *)(IDirectInputDevice8A *, HWND__ *, __int64))this->mDevice->vfptr[4].AddRef)(
    this->mDevice,
    hWnd,
    6i64);
  v8 = 0;
  v9 = UFG::gInitialKeyboardMaps;
  do
  {
    if ( !*v9 )
      break;
    UFG::Controller::AddInputActionMap(this, *v9, 0i64);
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
    UFG::Controller::AddMultiInputMap(this, *v11);
    ++v10;
    ++v11;
  }
  while ( v10 < 32 );
  this->m_IsKeyboardController = 1;
  if ( !index )
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
  int mControllerIndex; // edx

  mControllerIndex = this->mControllerIndex;
  this->m_ControllerInUse = 0;
  UFG::gInputSystem->mKeyboardIndex = mControllerIndex;
  memset(&this->mState, 0, sizeof(this->mState));
}

// File Line: 2433
// RVA: 0xA3A6F0
void __fastcall UFG::Gamepad::Gamepad(
        UFG::Gamepad *this,
        unsigned int index,
        HWND__ *hWnd,
        void *di,
        DIDEVICEINSTANCEA *did,
        int xinput_user_index)
{
  IDirectInputDevice8A **p_mDevice; // rdi
  int v10; // esi
  const unsigned int *v11; // r14
  unsigned int Data1; // ecx
  int v13; // ebp
  UFG::InputActionMap **v14; // rdi
  UFG::MultiInputMap **v15; // rdi

  UFG::Controller::Controller(this, index);
  this->vfptr = (UFG::ControllerVtbl *)&UFG::DxController::`vftable;
  this->mXinputUserIndex = xinput_user_index;
  memset(&this->mState, 0, sizeof(this->mState));
  *(_QWORD *)&this->mXinputState.dwPacketNumber = 0i64;
  *(_QWORD *)&this->mXinputState.Gamepad.sThumbLX = 0i64;
  this->vfptr = (UFG::ControllerVtbl *)&UFG::Gamepad::`vftable;
  p_mDevice = &this->mDevice;
  v10 = 0;
  this->mDevice = 0i64;
  *(_WORD *)&this->mIsStatusOK = 0;
  if ( this->mXinputUserIndex < 0 )
  {
    if ( (*(int (__fastcall **)(void *, _GUID *, IDirectInputDevice8A **, _QWORD, __int64))(*(_QWORD *)di + 24i64))(
           di,
           &did->guidInstance,
           p_mDevice,
           0i64,
           -2i64) >= 0 )
    {
      this->mDeviceInfo.dwSize = 580;
      ((void (__fastcall *)(IDirectInputDevice8A *))(*p_mDevice)->vfptr[5].QueryInterface)(*p_mDevice);
      if ( ((int (__fastcall *)(IDirectInputDevice8A *, _DIDATAFORMAT *))(*p_mDevice)->vfptr[3].Release)(
             *p_mDevice,
             &c_dfDIJoystick2) >= 0
        && ((int (__fastcall *)(IDirectInputDevice8A *, HWND__ *, __int64))(*p_mDevice)->vfptr[4].AddRef)(
             *p_mDevice,
             hWnd,
             9i64) >= 0
        && ((int (__fastcall *)(IDirectInputDevice8A *, int (__fastcall *)(DIDEVICEOBJECTINSTANCEA *, void *), UFG::Gamepad *, _QWORD))(*p_mDevice)->vfptr[1].AddRef)(
             *p_mDevice,
             UFG::Gamepad::EnumObjectsCallback,
             this,
             0i64) >= 0 )
      {
        this->mIsStatusOK = 1;
      }
    }
    Data1 = this->mDeviceInfo.guidProduct.Data1;
    if ( Data1 == 40371532 )
    {
      v11 = UFG::Generic_to_SixAxisRemap;
    }
    else if ( Data1 != 42861662 && Data1 != 119080030 && (Data1 == -1038744467 || Data1 == -1038547859) )
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
    this->mIsStatusOK = 1;
    v11 = UFG::Generic_to_XInput;
  }
  v13 = 0;
  v14 = UFG::gInitialGamepadMaps;
  do
  {
    if ( !*v14 )
      break;
    UFG::Controller::AddInputActionMap(this, *v14, v11);
    ++v13;
    ++v14;
  }
  while ( v13 < 32 );
  v15 = UFG::gInitialMultiMaps;
  do
  {
    if ( !*v15 )
      break;
    UFG::Controller::AddMultiInputMap(this, *v15);
    ++v10;
    ++v15;
  }
  while ( v10 < 32 );
  this->m_IsKeyboardController = 0;
}

// File Line: 2553
// RVA: 0xA3EA80
void __fastcall UFG::Gamepad::Update(UFG::Gamepad *this, const float elapsedTime, const float simTime)
{
  int mXinputUserIndex; // ecx
  DWORD State_0; // eax
  unsigned int i; // eax

  this->m_ControllerInUse = 0;
  mXinputUserIndex = this->mXinputUserIndex;
  if ( mXinputUserIndex < 0 )
  {
    if ( this->mIsStatusOK )
    {
      if ( this->mUnplugged )
        UFG::Gamepad::Reconnect(this);
      if ( (this->mDevice->vfptr[8].AddRef(this->mDevice) & 0x80000000) == 0 )
        goto LABEL_15;
      for ( i = this->mDevice->vfptr[2].AddRef(this->mDevice);
            i == -2147024866;
            i = this->mDevice->vfptr[2].AddRef(this->mDevice) )
      {
        ;
      }
      if ( i != -2147024891 )
      {
LABEL_15:
        if ( this->mDevice->vfptr[3].QueryInterface(this->mDevice, (_GUID *)272, (void **)&this->mState) == -2147024866 )
        {
          UFG::qPrintf("DIERR_INPUTLOST %x\n", this);
          this->mUnplugged = 1;
          memset(&this->mState, 0, sizeof(this->mState));
        }
      }
    }
  }
  else
  {
    if ( this->mIsInitialized )
    {
      State_0 = XInputGetState_0(mXinputUserIndex, &this->mXinputState);
      if ( !State_0 )
      {
        this->mUnplugged = 0;
        return;
      }
      if ( State_0 != 1167 )
      {
        this->mUnplugged = 1;
        return;
      }
    }
    this->mUnplugged = 1;
    *(_QWORD *)&this->mXinputState.dwPacketNumber = 0i64;
    *(_QWORD *)&this->mXinputState.Gamepad.sThumbLX = 0i64;
  }
}

// File Line: 2680
// RVA: 0xA3D910
void __fastcall UFG::Gamepad::Reconnect(UFG::Gamepad *this)
{
  int i; // eax

  for ( i = this->mDevice->vfptr[2].AddRef(this->mDevice);
        i == -2147024866;
        i = this->mDevice->vfptr[2].AddRef(this->mDevice) )
  {
    ;
  }
  if ( i >= 0 )
  {
    UFG::qPrintf("JOYSTICK reacquired %x\n", this);
    this->mUnplugged = 0;
  }
}

// File Line: 2702
// RVA: 0xA3B020
__int64 __fastcall UFG::DxInputSystem::EnumJoysticksCallback(DIDEVICEINSTANCEA *pdidInstance, char *pContext)
{
  __int64 v4; // rdi
  unsigned int v5; // ebx
  __int64 v6; // rcx
  _QWORD *i; // rax
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax

  if ( !UFG::IsXInputDevice(&pdidInstance->guidProduct) )
  {
    v4 = 0i64;
    v5 = 0;
    v6 = 0i64;
    for ( i = pContext + 8; *i; ++i )
    {
      ++v5;
      if ( ++v6 >= 5 )
        return 0i64;
    }
    if ( v5 == -1 )
      return 0i64;
    v9 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
    if ( v9 )
    {
      UFG::Gamepad::Gamepad(
        (UFG::Gamepad *)v9,
        v5,
        *((HWND__ **)pContext + 9),
        *((void **)pContext + 8),
        pdidInstance,
        -1);
      v4 = v10;
    }
    if ( v4 )
      *(_QWORD *)&pContext[8 * v5 + 8] = v4;
  }
  return 1i64;
}

// File Line: 2746
// RVA: 0xA3B0F0
_BOOL8 __fastcall UFG::Gamepad::EnumObjectsCallback(DIDEVICEOBJECTINSTANCEA *pdidoi, _QWORD *pContext)
{
  unsigned int dwType; // eax
  __int64 v3; // rcx
  _BOOL8 result; // rax
  int v5[10]; // [rsp+20h] [rbp-28h] BYREF

  dwType = pdidoi->dwType;
  result = 1;
  if ( (dwType & 3) != 0 )
  {
    v3 = pContext[272];
    v5[0] = 24;
    v5[1] = 16;
    v5[3] = 2;
    v5[2] = dwType;
    v5[4] = -1000;
    v5[5] = 1000;
    if ( (*(int (__fastcall **)(__int64, __int64, int *))(*(_QWORD *)v3 + 48i64))(v3, 4i64, v5) < 0 )
      return 0;
  }
  return result;
}

// File Line: 2770
// RVA: 0xA3AE50
signed __int64 __fastcall UFG::DxInputSystem::CreateNewGamePad(UFG::DxInputSystem *this, int index)
{
  __int64 v2; // rsi
  __int64 v4; // r14
  UFG::Controller *v5; // rbx
  int v6; // r8d
  UFG::Controller **mControllers; // rdx
  UFG::Controller *v8; // rax
  __int64 vfptr_low; // rcx
  int xinput_user_index; // edi
  int v11; // ecx
  __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::Controller *v14; // rax
  __int64 v16[6]; // [rsp+38h] [rbp-30h]

  v2 = index;
  v4 = index;
  if ( this->mControllers[v4] )
    return 0xFFFFFFFFi64;
  v16[0] = -1i64;
  v16[1] = -1i64;
  v5 = 0i64;
  v6 = 0;
  mControllers = this->mControllers;
  do
  {
    v8 = *mControllers;
    if ( *mControllers )
    {
      if ( !v8->m_IsKeyboardController )
      {
        vfptr_low = SLODWORD(v8[1].vfptr);
        if ( (unsigned int)vfptr_low <= 3 )
          *((_DWORD *)v16 + vfptr_low) = v6;
      }
    }
    ++v6;
    ++mControllers;
  }
  while ( v6 < 4 );
  xinput_user_index = v2;
  if ( *((_DWORD *)v16 + v2) != -1 )
  {
    xinput_user_index = -1;
    v11 = 0;
    v12 = 0i64;
    while ( *((_DWORD *)v16 + v12) != -1 )
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
    UFG::Gamepad::Gamepad((UFG::Gamepad *)v13, v2, this->hWnd, 0i64, 0i64, xinput_user_index);
    v5 = v14;
  }
  if ( v5 )
  {
    this->mControllers[v4] = v5;
    v5->mIsInitialized = 1;
  }
  return (unsigned int)v2;
}

// File Line: 2823
// RVA: 0xA3BA70
__int64 __fastcall UFG::DxInputSystem::InitDirectInput(UFG::DxInputSystem *this)
{
  HMODULE ModuleHandleA; // rax
  __int64 result; // rax
  DWORD xinput_user_index; // esi
  unsigned int v5; // edi
  __int64 v6; // rbx
  UFG::Controller **i; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::Controller *v9; // rax
  XINPUT_STATE pState; // [rsp+38h] [rbp-30h] BYREF

  ModuleHandleA = GetModuleHandleA(0i64);
  result = DirectInput8Create_0(ModuleHandleA, 2048i64, &IID_IDirectInput8A, &this->mDirectInput, 0i64);
  if ( (int)result >= 0 )
  {
    for ( xinput_user_index = 0; xinput_user_index < 4; ++xinput_user_index )
    {
      *(_QWORD *)&pState.dwPacketNumber = 0i64;
      *(_QWORD *)&pState.Gamepad.sThumbLX = 0i64;
      if ( !XInputGetState_0(xinput_user_index, &pState) )
      {
        v5 = 0;
        v6 = 0i64;
        for ( i = this->mControllers; *i; ++i )
        {
          ++v5;
          ++v6;
        }
        v8 = UFG::qMalloc(0xAD0ui64, "Gamepad", 0i64);
        if ( v8 )
          UFG::Gamepad::Gamepad((UFG::Gamepad *)v8, v5, this->hWnd, this->mDirectInput, 0i64, xinput_user_index);
        else
          v9 = 0i64;
        if ( v9 )
        {
          this->mControllers[v6] = v9;
          v9->mIsInitialized = 1;
        }
      }
    }
    if ( !gUsePCController )
      return 0i64;
    result = ((__int64 (__fastcall *)(IDirectInput8A *, __int64, __int64 (__fastcall *)(DIDEVICEINSTANCEA *, char *), UFG::DxInputSystem *, int))this->mDirectInput->vfptr[1].AddRef)(
               this->mDirectInput,
               4i64,
               UFG::DxInputSystem::EnumJoysticksCallback,
               this,
               1);
    if ( (int)result >= 0 )
      return 0i64;
  }
  return result;
}

// File Line: 2916
// RVA: 0xA3A640
void __fastcall UFG::DxInputSystem::DxInputSystem(UFG::DxInputSystem *this, HWND__ *h)
{
  UFG::Controller *v4; // rsi
  int v5; // ebx
  UFG::allocator::free_link *v6; // rax
  UFG::Controller *v7; // rax

  UFG::InputSystem::InputSystem(this);
  this->vfptr = (UFG::InputSystemVtbl *)&UFG::DxInputSystem::`vftable;
  this->hWnd = h;
  UFG::DxInputSystem::InitDirectInput(this);
  *(_WORD *)&this->mbSentDisconnectMsg = 0;
  v4 = 0i64;
  v5 = 0;
  if ( this->mControllers[0] )
    v5 = 4;
  UFG::InputSystem::msRelativeMouseMode = 0;
  v6 = UFG::qMalloc(0x888ui64, "Keyboard", 0i64);
  if ( v6 )
  {
    UFG::Keyboard::Keyboard((UFG::Keyboard *)v6, v5, this->hWnd, this->mDirectInput);
    v4 = v7;
  }
  this->mControllers[v5] = v4;
}

// File Line: 2960
// RVA: 0xA3ED30
void __fastcall UFG::fake_xinput(UFG *this)
{
  unsigned __int16 v1; // r10
  float *p_fDataX; // r8
  unsigned __int16 *v3; // r9
  int i; // edx

  v1 = 0;
  p_fDataX = &UFG::testController.testInput[0].fDataX;
  v3 = UFG::XINPUT_BUTTON_MASKS;
  for ( i = 0; i < 18; ++i )
  {
    if ( *((_BYTE *)p_fDataX - 8) )
    {
      switch ( i )
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
          UFG::sRawInputState.mXinputState.Gamepad.bLeftTrigger = (int)*p_fDataX;
          break;
        case 7:
          UFG::sRawInputState.mXinputState.Gamepad.bRightTrigger = (int)*p_fDataX;
          break;
        case 12:
          UFG::sRawInputState.mXinputState.Gamepad.sThumbLX = (int)*p_fDataX;
          UFG::sRawInputState.mXinputState.Gamepad.sThumbLY = (int)p_fDataX[1];
          break;
        case 13:
          UFG::sRawInputState.mXinputState.Gamepad.sThumbRX = (int)*p_fDataX;
          UFG::sRawInputState.mXinputState.Gamepad.sThumbRY = (int)p_fDataX[1];
          break;
        default:
          break;
      }
    }
    ++v3;
    p_fDataX += 4;
  }
  UFG::sRawInputState.mXinputState.Gamepad.wButtons = v1;
}

// File Line: 3027
// RVA: 0xA3E5C0
void __fastcall UFG::DxInputSystem::Update(UFG::DxInputSystem *this, float elapsedTime, float simTime)
{
  UFG::DxInputSystem *v3; // rbp
  int v4; // r14d
  signed int v5; // ebx
  int v6; // esi
  UFG::Controller **mControllers; // rdi
  UFG::ControllerVtbl *vfptr; // rax
  int xinput_user_index; // edi
  int *v10; // rsi
  UFG::allocator::free_link *v11; // rax
  UFG::DxInputSystem *v12; // rax
  UFG::Controller **v13; // r15
  __int64 v14; // r12
  UFG::InputMessage *mNext; // rbx
  UFG::Controller *v16; // rax
  UFG::allocator::free_link *p_mInputMessages; // rdi
  UFG::DxInputSystem *p_mInputState; // rsi
  UFG::DxInputSystem *p_mPreviousInputState; // rbx
  __int64 *v20; // rcx
  __int64 v21; // rdx
  _QWORD *v22; // rax
  __int64 v23; // rdx
  _QWORD *v24; // rax
  __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rdx
  UFG::allocator::free_link *v28; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *mPrev; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v30; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v31; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v32; // rax
  UFG::Controller *v33; // rbx
  UFG::Controller *v34; // rcx
  bool v35; // r8
  bool v36; // dl
  int v37[4]; // [rsp+30h] [rbp-E8h] BYREF
  XINPUT_STATE pState; // [rsp+40h] [rbp-D8h] BYREF
  __int64 v39; // [rsp+50h] [rbp-C8h]
  Render::RenderOutputParams outSettings; // [rsp+60h] [rbp-B8h] BYREF

  v39 = -2i64;
  v3 = this;
  v4 = 0;
  if ( !gFreezeInputs )
  {
    v5 = -1;
    v37[0] = -1;
    v37[1] = -1;
    v37[2] = -1;
    v37[3] = -1;
    v6 = 0;
    mControllers = this->mControllers;
    do
    {
      this = (UFG::DxInputSystem *)*mControllers;
      if ( *mControllers )
      {
        ((void (__fastcall *)(UFG::DxInputSystem *))this->vfptr[1].CreateNewGamePad)(this);
        if ( v6 == UFG::gActiveControllerNum && v3->mbCheckForControllerDisconnect )
        {
          vfptr = (*mControllers)->vfptr;
          if ( v3->mbSentDisconnectMsg )
          {
            if ( ((unsigned __int8 (*)(void))vfptr->IsConnected)() )
              v3->mbSentDisconnectMsg = 0;
          }
          else if ( !((unsigned __int8 (*)(void))vfptr->IsConnected)() )
          {
            v3->mbSentDisconnectMsg = 1;
          }
        }
        if ( !(*mControllers)->m_IsKeyboardController )
        {
          this = (UFG::DxInputSystem *)SLODWORD((*mControllers)[1].vfptr);
          if ( (int)this >= 0 )
            v37[(_QWORD)this] = 0;
        }
      }
      else if ( v5 < 0 )
      {
        v5 = v6;
      }
      ++v6;
      ++mControllers;
    }
    while ( v6 < 5 );
    if ( bCheckForNewController )
    {
      if ( v5 >= 0 )
      {
        xinput_user_index = 0;
        v10 = v37;
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
  mNext = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
  do
  {
    v16 = *v13;
    if ( *v13 )
    {
      p_mInputMessages = (UFG::allocator::free_link *)&v16->mInputMessages;
      p_mInputState = (UFG::DxInputSystem *)&v16->mInputState;
      p_mPreviousInputState = (UFG::DxInputSystem *)&v16->mPreviousInputState;
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
          v20 = (__int64 *)p_mInputMessages[1].mNext;
        }
        while ( v20 != (__int64 *)p_mInputMessages );
      }
      this = p_mInputState;
      if ( (((unsigned __int8)p_mPreviousInputState | (unsigned __int8)p_mInputState) & 0xF) != 0 )
      {
        memmove(p_mPreviousInputState, p_mInputState, 0x118ui64);
      }
      else
      {
        v25 = 2i64;
        do
        {
          *p_mPreviousInputState = *this;
          *(_OWORD *)&p_mPreviousInputState[1].vfptr = *(_OWORD *)&this[1].vfptr;
          *(_OWORD *)&p_mPreviousInputState[1].mControllers[1] = *(_OWORD *)&this[1].mControllers[1];
          p_mPreviousInputState = (UFG::DxInputSystem *)((char *)p_mPreviousInputState + 128);
          *(_OWORD *)&p_mPreviousInputState[-1].mDirectInput = *(_OWORD *)&this[1].mControllers[3];
          this = (UFG::DxInputSystem *)((char *)this + 128);
          --v25;
        }
        while ( v25 );
        *(_OWORD *)&p_mPreviousInputState->vfptr = *(_OWORD *)&this->vfptr;
        p_mPreviousInputState->mControllers[1] = this->mControllers[1];
      }
      mNext = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
      if ( (UFG::RawInputState *)UFG::sRawInputState.mInputMessages.mNode.mNext != &UFG::sRawInputState )
      {
        do
        {
          if ( !gFreezeInputs )
            UFG::InputState::ProcessMessage((UFG::InputState *)p_mInputState, mNext);
          v26 = UFG::qMalloc(0x20ui64, "InputMessage", 0i64);
          v27 = v26;
          if ( v26 )
          {
            v26->mNext = v26;
            v26[1].mNext = v26;
            LOBYTE(v26[2].mNext) = mNext->mMessageID;
            this = (UFG::DxInputSystem *)(unsigned __int8)mNext->mVKey;
            BYTE1(v26[2].mNext) = (_BYTE)this;
            WORD1(v26[2].mNext) = mNext->mMouseX;
            WORD2(v26[2].mNext) = mNext->mMouseY;
            HIWORD(v26[2].mNext) = mNext->mMouseWheelDelta;
            LODWORD(v26[3].mNext) = mNext->mChar;
          }
          else
          {
            v27 = 0i64;
          }
          v28 = p_mInputMessages->mNext;
          v28[1].mNext = v27;
          v27->mNext = v28;
          v27[1].mNext = p_mInputMessages;
          p_mInputMessages->mNext = v27;
          mNext = (UFG::InputMessage *)mNext->mNext;
        }
        while ( mNext != (UFG::InputMessage *)&UFG::sRawInputState );
        mNext = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
      }
    }
    ++v13;
    --v14;
  }
  while ( v14 );
  if ( mNext != (UFG::InputMessage *)&UFG::sRawInputState )
  {
    do
    {
      mPrev = mNext->mPrev;
      v30 = mNext->mNext;
      mPrev->mNext = v30;
      v30->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v31 = mNext->mPrev;
      v32 = mNext->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      mNext = (UFG::InputMessage *)UFG::sRawInputState.mInputMessages.mNode.mNext;
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
  UFG::InputSystem::InternalUpdate(v3, elapsedTime, simTime);
  if ( !v3->mbCheckForControllerDisconnect )
    v3->mbCheckForControllerDisconnect = 1;
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  LOBYTE(v4) = outSettings.mEnableFullscreen;
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

