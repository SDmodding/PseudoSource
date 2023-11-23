// File Line: 32
// RVA: 0x146A9B0
float *UFG::_dynamic_initializer_for__testController__()
{
  int v0; // ecx
  float *result; // rax

  v0 = 21;
  result = &UFG::testController.testInput[0].fDataY;
  do
  {
    --v0;
    *((_BYTE *)result - 12) = 0;
    *(_QWORD *)(result - 1) = 0i64;
    result += 4;
  }
  while ( v0 >= 0 );
  return result;
}

// File Line: 84
// RVA: 0x146A930
__int64 UFG::_dynamic_initializer_for__gMoveThatMatchedRefMove__()
{
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mR, 0, 0x100u);
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mTheta, 0, 0x100u);
  UFG::qMemSet(UFG::gMoveThatMatchedRefMove.mOctantHistory, -1, 0x40u);
  *(_QWORD *)&UFG::gMoveThatMatchedRefMove.mIndex = 0i64;
  *(_QWORD *)&UFG::gMoveThatMatchedRefMove.mEndTrim = 0i64;
  UFG::gMoveThatMatchedRefMove.mLocked = 0;
  UFG::gMoveThatMatchedRefMove.mOctantIndex = 0;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gMoveThatMatchedRefMove__);
}

// File Line: 100
// RVA: 0x1B7D90
const char *__fastcall UFG::MapInputVKeyToString(unsigned __int8 key)
{
  __int64 v2[256]; // [rsp+0h] [rbp-100h]

  v2[0] = (__int64)"0x00";
  v2[1] = (__int64)"LBUTTON";
  v2[2] = (__int64)"RBUTTON";
  v2[3] = (__int64)"CANCEL";
  v2[4] = (__int64)"MBUTTON";
  v2[5] = (__int64)"XBUTTON1";
  v2[6] = (__int64)"XBUTTON2";
  v2[7] = (__int64)"0x07";
  v2[8] = (__int64)"BACK";
  v2[9] = (__int64)"TAB";
  v2[10] = (__int64)"0x0a";
  v2[11] = (__int64)"0x0b";
  v2[12] = (__int64)"CLEAR";
  v2[13] = (__int64)"RETURN";
  v2[14] = (__int64)"0x0e";
  v2[15] = (__int64)"0x0f";
  v2[16] = (__int64)"SHIFT";
  v2[17] = (__int64)"CTRL";
  v2[18] = (__int64)"ALT";
  v2[19] = (__int64)"PAUSE";
  v2[20] = (__int64)"CAPITAL";
  v2[21] = (__int64)"KANA";
  v2[22] = (__int64)"0x16";
  v2[23] = (__int64)"JUNJA";
  v2[24] = (__int64)"FINAL";
  v2[25] = (__int64)"KANJI";
  v2[26] = (__int64)"0x1a";
  v2[27] = (__int64)"ESCAPE";
  v2[28] = (__int64)"CONVERT";
  v2[29] = (__int64)"NONCONVERT";
  v2[30] = (__int64)"ACCEPT";
  v2[31] = (__int64)"MODECHANGE";
  v2[32] = (__int64)"SPACE";
  v2[33] = (__int64)"PAGE UP";
  v2[34] = (__int64)"PAGE DOWN";
  v2[35] = (__int64)"END";
  v2[36] = (__int64)"HOME";
  v2[37] = (__int64)"LEFT";
  v2[38] = (__int64)"UP";
  v2[39] = (__int64)"RIGHT";
  v2[40] = (__int64)"DOWN";
  v2[41] = (__int64)"SELECT";
  v2[42] = (__int64)"PRINT";
  v2[43] = (__int64)"EXECUTE";
  v2[44] = (__int64)"SNAPSHOT";
  v2[45] = (__int64)"INSERT";
  v2[46] = (__int64)"DELETE";
  v2[47] = (__int64)"HELP";
  v2[48] = (__int64)"0";
  v2[49] = (__int64)"1";
  v2[50] = (__int64)"2";
  v2[51] = (__int64)"3";
  v2[52] = (__int64)"4";
  v2[53] = (__int64)"5";
  v2[54] = (__int64)"6";
  v2[55] = (__int64)"7";
  v2[56] = (__int64)"8";
  v2[57] = (__int64)"9";
  v2[58] = (__int64)"0x3a";
  v2[59] = (__int64)"0x3b";
  v2[60] = (__int64)"0x3c";
  v2[61] = (__int64)"0x3d";
  v2[62] = (__int64)"0x3e";
  v2[63] = (__int64)"0x3f";
  v2[64] = (__int64)"0x40";
  v2[65] = (__int64)"A";
  v2[66] = (__int64)"B";
  v2[67] = (__int64)"C";
  v2[68] = (__int64)"D";
  v2[69] = (__int64)"E";
  v2[70] = (__int64)"F";
  v2[71] = (__int64)"G";
  v2[72] = (__int64)"H";
  v2[73] = (__int64)"I";
  v2[74] = (__int64)"J";
  v2[75] = (__int64)"K";
  v2[76] = (__int64)"L";
  v2[77] = (__int64)"M";
  v2[78] = (__int64)"N";
  v2[79] = (__int64)"O";
  v2[80] = (__int64)"P";
  v2[81] = (__int64)"Q";
  v2[82] = (__int64)"R";
  v2[83] = (__int64)"S";
  v2[84] = (__int64)"T";
  v2[85] = (__int64)"U";
  v2[86] = (__int64)"V";
  v2[87] = (__int64)"W";
  v2[88] = (__int64)"X";
  v2[89] = (__int64)"Y";
  v2[90] = (__int64)"Z";
  v2[91] = (__int64)"LWIN";
  v2[92] = (__int64)"RWIN";
  v2[93] = (__int64)"APPS";
  v2[94] = (__int64)"0x5e";
  v2[95] = (__int64)"SLEEP";
  v2[96] = (__int64)"NUMPAD0";
  v2[97] = (__int64)"NUMPAD1";
  v2[98] = (__int64)"NUMPAD2";
  v2[99] = (__int64)"NUMPAD3";
  v2[100] = (__int64)"NUMPAD4";
  v2[101] = (__int64)"NUMPAD5";
  v2[102] = (__int64)"NUMPAD6";
  v2[103] = (__int64)"NUMPAD7";
  v2[104] = (__int64)"NUMPAD8";
  v2[105] = (__int64)"NUMPAD9";
  v2[106] = (__int64)"MULTIPLY";
  v2[107] = (__int64)"ADD";
  v2[108] = (__int64)"SEPARATOR";
  v2[109] = (__int64)"SUBTRACT";
  v2[110] = (__int64)"DECIMAL";
  v2[111] = (__int64)"DIVIDE";
  v2[112] = (__int64)"F1";
  v2[113] = (__int64)"F2";
  v2[114] = (__int64)"F3";
  v2[115] = (__int64)"F4";
  v2[116] = (__int64)"F5";
  v2[117] = (__int64)"F6";
  v2[118] = (__int64)"F7";
  v2[119] = (__int64)"F8";
  v2[120] = (__int64)"F9";
  v2[121] = (__int64)"F10";
  v2[122] = (__int64)"F11";
  v2[123] = (__int64)"F12";
  v2[124] = (__int64)"F13";
  v2[125] = (__int64)"F14";
  v2[126] = (__int64)"F15";
  v2[127] = (__int64)"F16";
  v2[128] = (__int64)"F17";
  v2[129] = (__int64)"F18";
  v2[130] = (__int64)"F19";
  v2[131] = (__int64)"F20";
  v2[132] = (__int64)"F21";
  v2[133] = (__int64)"F22";
  v2[134] = (__int64)"F23";
  v2[135] = (__int64)"F24";
  v2[136] = (__int64)"0x88";
  v2[137] = (__int64)"0x89";
  v2[138] = (__int64)"0x8a";
  v2[139] = (__int64)"0x8b";
  v2[140] = (__int64)"0x8c";
  v2[141] = (__int64)"0x8d";
  v2[142] = (__int64)"0x8e";
  v2[143] = (__int64)"0x8f";
  v2[144] = (__int64)"NUMLOCK";
  v2[145] = (__int64)"SCROLL";
  v2[146] = (__int64)"OEM_NEC_EQUAL";
  v2[147] = (__int64)"OEM_FJ_MASSHOU";
  v2[148] = (__int64)"OEM_FJ_TOUROKU";
  v2[149] = (__int64)"OEM_FJ_LOYA";
  v2[150] = (__int64)"OEM_FJ_ROYA";
  v2[151] = (__int64)"0x97";
  v2[152] = (__int64)"0x98";
  v2[153] = (__int64)"0x99";
  v2[154] = (__int64)"0x9a";
  v2[155] = (__int64)"0x9b";
  v2[156] = (__int64)"0x9c";
  v2[157] = (__int64)"0x9d";
  v2[158] = (__int64)"0x9e";
  v2[159] = (__int64)"0x9f";
  v2[160] = (__int64)"LSHIFT";
  v2[161] = (__int64)"RSHIFT";
  v2[162] = (__int64)"LCONTROL";
  v2[163] = (__int64)"RCONTROL";
  v2[164] = (__int64)"LMENU";
  v2[165] = (__int64)"RMENU";
  v2[166] = (__int64)"BROWSER_BACK";
  v2[167] = (__int64)"BROWSER_FORWARD";
  v2[168] = (__int64)"BROWSER_REFRESH";
  v2[169] = (__int64)"BROWSER_STOP";
  v2[170] = (__int64)"BROWSER_SEARCH";
  v2[171] = (__int64)"BROWSER_FAVORITES";
  v2[172] = (__int64)"BROWSER_HOME";
  v2[173] = (__int64)"VOLUME_MUTE";
  v2[174] = (__int64)"VOLUME_DOWN";
  v2[175] = (__int64)"VOLUME_UP";
  v2[176] = (__int64)"MEDIA_NEXT_TRACK";
  v2[177] = (__int64)"MEDIA_PREV_TRACK";
  v2[178] = (__int64)"MEDIA_STOP";
  v2[179] = (__int64)"MEDIA_PLAY_PAUSE";
  v2[180] = (__int64)"LAUNCH_MAIL";
  v2[181] = (__int64)"LAUNCH_MEDIA_SELECT";
  v2[182] = (__int64)"LAUNCH_APP1";
  v2[183] = (__int64)"LAUNCH_APP2";
  v2[184] = (__int64)"0xb8";
  v2[185] = (__int64)"0xb9";
  v2[186] = (__int64)"SEMI_COLON";
  v2[187] = (__int64)"PLUS";
  v2[188] = (__int64)"COMMA";
  v2[189] = (__int64)"MINUS";
  v2[190] = (__int64)"PERIOD";
  v2[191] = (__int64)"QUESTION_MARK";
  v2[192] = (__int64)"TILDE";
  v2[193] = (__int64)"0xc1";
  v2[194] = (__int64)"0xc2";
  v2[195] = (__int64)"0xc3";
  v2[196] = (__int64)"0xc4";
  v2[197] = (__int64)"0xc5";
  v2[198] = (__int64)"0xc6";
  v2[199] = (__int64)"0xc7";
  v2[200] = (__int64)"0xc8";
  v2[201] = (__int64)"0xc9";
  v2[202] = (__int64)"0xca";
  v2[203] = (__int64)"0xcb";
  v2[204] = (__int64)"0xcc";
  v2[205] = (__int64)"0xcd";
  v2[206] = (__int64)"0xce";
  v2[207] = (__int64)"0xcf";
  v2[208] = (__int64)"0xd0";
  v2[209] = (__int64)"0xd1";
  v2[210] = (__int64)"0xd2";
  v2[211] = (__int64)"0xd3";
  v2[212] = (__int64)"0xd4";
  v2[213] = (__int64)"0xd5";
  v2[214] = (__int64)"0xd6";
  v2[215] = (__int64)"0xd7";
  v2[216] = (__int64)"0xd8";
  v2[217] = (__int64)"0xd9";
  v2[218] = (__int64)"0xda";
  v2[219] = (__int64)"OEM_4";
  v2[220] = (__int64)"OEM_5";
  v2[221] = (__int64)"OEM_6";
  v2[222] = (__int64)"OEM_7";
  v2[223] = (__int64)"OEM_8";
  v2[224] = (__int64)"0xe0";
  v2[225] = (__int64)"OEM_AX";
  v2[226] = (__int64)"OEM_102";
  v2[227] = (__int64)"ICO_HELP";
  v2[228] = (__int64)"ICO_00";
  v2[229] = (__int64)"PROCESSKEY";
  v2[230] = (__int64)"ICO_CLEAR";
  v2[231] = (__int64)"0xe7";
  v2[232] = (__int64)"0xe8";
  v2[233] = (__int64)"OEM_RESET";
  v2[234] = (__int64)"OEM_JUMP";
  v2[235] = (__int64)"OEM_PA1";
  v2[236] = (__int64)"OEM_PA2";
  v2[237] = (__int64)"OEM_PA3";
  v2[238] = (__int64)"OEM_WSCTRL";
  v2[239] = (__int64)"OEM_CUSEL";
  v2[240] = (__int64)"OEM_ATTN";
  v2[241] = (__int64)"OEM_FINISH";
  v2[242] = (__int64)"OEM_COPY";
  v2[243] = (__int64)"OEM_AUTO";
  v2[244] = (__int64)"OEM_ENLW";
  v2[245] = (__int64)"OEM_BACKTAB";
  v2[246] = (__int64)"ATTN";
  v2[247] = (__int64)"CRSEL";
  v2[248] = (__int64)"EXSEL";
  v2[249] = (__int64)"EREOF";
  v2[250] = (__int64)"PLAY";
  v2[251] = (__int64)"ZOOM";
  v2[252] = (__int64)"NONAME";
  v2[253] = (__int64)"PA1";
  v2[254] = (__int64)"OEM_CLEAR";
  v2[255] = (__int64)"0xff";
  return (const char *)v2[key];
}

// File Line: 650
// RVA: 0x1B7420
void __fastcall UFG::InputState::Clear(UFG::InputState *this)
{
  char *mKeyState; // rcx

  mKeyState = this->mKeyState;
  *(_QWORD *)(mKeyState - 20) = 0i64;
  *((_WORD *)mKeyState - 6) = -1;
  *((_WORD *)mKeyState - 5) = -1;
  *((_WORD *)mKeyState - 4) = 0;
  *((_WORD *)mKeyState - 3) = -1;
  *((_WORD *)mKeyState - 2) = -1;
  *((_WORD *)mKeyState - 1) = 0;
  UFG::qMemSet(mKeyState, 0, 256u);
}

// File Line: 665
// RVA: 0x1B79F0
__int64 __fastcall UFG::InputState::GetModiferKeys(UFG::InputState *this)
{
  int v2; // esi
  int v3; // edi
  bool v4; // zf
  int v5; // eax
  int v6; // edi
  int v7; // edi

  v2 = 0;
  if ( UFG::InputState::IsPressed(this, 160) || (v3 = 0, UFG::InputState::IsPressed(this, 161)) )
    v3 = 1;
  if ( UFG::InputState::IsPressed(this, 162) || (v4 = !UFG::InputState::IsPressed(this, 163), v5 = 0, !v4) )
    v5 = 2;
  v6 = v5 | v3;
  if ( UFG::InputState::IsPressed(this, 164) || UFG::InputState::IsPressed(this, 165) )
    v2 = 4;
  v7 = v2 | (UFG::InputState::IsPressed(this, 91) ? 8 : 0) | v6;
  return v7 | (UFG::InputState::IsPressed(this, 93) ? 0x10 : 0);
}

// File Line: 678
// RVA: 0x1B7AC0
__int64 __fastcall UFG::InputState::GetMouseButtons(UFG::InputState *this)
{
  BOOL IsPressed; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi

  IsPressed = UFG::InputState::IsPressed(this, 1);
  v3 = (UFG::InputState::IsPressed(this, 2) ? 2 : 0) | IsPressed;
  v4 = (UFG::InputState::IsPressed(this, 4) ? 4 : 0) | v3;
  v5 = (UFG::InputState::IsPressed(this, 8) ? 8 : 0) | v4;
  return v5 | (UFG::InputState::IsPressed(this, 16) ? 0x10 : 0);
}

// File Line: 700
// RVA: 0x1B7BB0
__int64 __fastcall UFG::InputState::GetRepeatCount(UFG::InputState *this, int key)
{
  return this->mKeyState[key] & 0x7F;
}

// File Line: 712
// RVA: 0x1B7D80
bool __fastcall UFG::InputState::IsMouseVisible(UFG::InputState *this)
{
  return this->mMouseX != -1;
}

// File Line: 717
// RVA: 0x1B7B90
__int64 __fastcall UFG::WayFinderClient::GetWayEdge(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  return this->m_CurrWayEdge;
}

// File Line: 722
// RVA: 0x1B7BA0
__int64 __fastcall UFG::WayFinderClient::GetWayNode(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  return this->m_CurrWayNode;
}

// File Line: 733
// RVA: 0x1B7B50
__int64 __fastcall UFG::InputState::GetMouseDeltaX(UFG::InputState *this)
{
  return (unsigned int)(this->mMouseX - this->mPrevMouseX);
}

// File Line: 738
// RVA: 0x1B7B60
__int64 __fastcall UFG::InputState::GetMouseDeltaY(UFG::InputState *this)
{
  return (unsigned int)(this->mMouseY - this->mPrevMouseY);
}

// File Line: 743
// RVA: 0x1B7B70
float __fastcall UFG::InputState::GetMouseWheelDelta(UFG::InputState *this)
{
  return (float)(this->mMouseWheel - this->mPrevMouseWheel) * 0.0083333338;
}

// File Line: 748
// RVA: 0x1B8BC0
void __fastcall UFG::InputState::ProcessMessage(UFG::InputState *this, UFG::InputMessage *msg)
{
  __int64 mVKey; // rdi
  int mMouseX; // ebp
  __int16 mMouseY; // r14
  __int16 mMouseWheelDelta; // dx
  int v8; // ecx
  _FILETIME SystemTime; // rax
  __int16 mMouseWheel; // ax
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // cl

  if ( !msg )
    return;
  if ( !this->mLastMouseXYTime )
    this->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
  mVKey = (unsigned __int8)msg->mVKey;
  mMouseX = msg->mMouseX;
  mMouseY = msg->mMouseY;
  mMouseWheelDelta = msg->mMouseWheelDelta;
  switch ( msg->mMessageID )
  {
    case 0:
    case 1:
      UFG::InputState::Clear(this);
      goto LABEL_23;
    case 2:
      if ( UFG::InputState::IsPressed(this, (unsigned __int8)msg->mVKey) )
      {
        v8 = ((this->mKeyState[(int)mVKey] & 0x7F) + 1) % 127;
        if ( v8 <= 1 )
        {
          this->mKeyState[(int)mVKey] = -127;
          goto LABEL_23;
        }
      }
      else
      {
        LOBYTE(v8) = 0;
      }
      this->mKeyState[(int)mVKey] = v8 | 0x80;
LABEL_23:
      v11 = this->mKeyState[161];
      if ( (unsigned int)this->mKeyState[160] > v11 )
        v11 = this->mKeyState[160];
      this->mKeyState[16] = v11;
      v12 = this->mKeyState[163];
      if ( (unsigned int)this->mKeyState[162] > v12 )
        v12 = this->mKeyState[162];
      this->mKeyState[17] = v12;
      v13 = this->mKeyState[165];
      if ( (unsigned int)this->mKeyState[164] > v13 )
        v13 = this->mKeyState[164];
      this->mKeyState[18] = v13;
      return;
    case 3:
    case 8:
      this->mKeyState[(unsigned __int8)msg->mVKey] = 0;
      goto LABEL_23;
    case 4:
      if ( mMouseX >= 0 || UFG::InputSystem::msCursorCurrentlyRestricted )
      {
        SystemTime = UFG::qGetSystemTime();
        if ( UFG::qGetSystemTimeDifference(this->mLastMouseXYTime, *(_QWORD *)&SystemTime) >= 0.5 )
        {
          this->mPrevMouseX = mMouseX;
          this->mPrevMouseY = mMouseY;
        }
        else
        {
          this->mPrevMouseX = this->mMouseX;
          this->mPrevMouseY = this->mMouseY;
        }
        this->mMouseX = mMouseX;
        this->mMouseY = mMouseY;
        this->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
      }
      else
      {
        this->mPrevMouseX = this->mMouseX;
        this->mPrevMouseY = this->mMouseY;
      }
      goto LABEL_23;
    case 5:
      this->mMouseX += msg->mMouseX;
      this->mMouseY += mMouseY;
      *(_DWORD *)&this->mPrevMouseX = 0;
      this->mLastMouseXYTime = (unsigned __int64)UFG::qGetSystemTime();
      goto LABEL_23;
    case 7:
      this->mKeyState[(unsigned __int8)msg->mVKey] = 0x80;
      goto LABEL_23;
    case 9:
      this->mKeyState[mVKey] = 0x80;
      goto LABEL_23;
    case 0xA:
      mMouseWheel = this->mMouseWheel;
      this->mPrevMouseWheel = mMouseWheel;
      this->mMouseWheel = mMouseWheelDelta + mMouseWheel;
      goto LABEL_23;
    default:
      goto LABEL_23;
  }
}

// File Line: 889
// RVA: 0x1B79D0
float __fastcall UFG::InputActionData::GetAxisVelX(UFG::InputActionData *this)
{
  return this->mAxisRawX[0] - this->mAxisRawX[1];
}

// File Line: 902
// RVA: 0x1B79E0
float __fastcall UFG::InputActionData::GetAxisVelY(UFG::InputActionData *this)
{
  return this->mAxisRawY[0] - this->mAxisRawY[1];
}

// File Line: 967
// RVA: 0x1B6A90
void __fastcall UFG::InputSystem::InputSystem(UFG::InputSystem *this)
{
  UFG::JoyMoveWatcher *v2; // rax

  this->vfptr = (UFG::InputSystemVtbl *)&UFG::InputSystem::`vftable;
  *(_WORD *)&this->mbSentDisconnectMsg = 0;
  this->mKeyboardIndex = -1;
  v2 = (UFG::JoyMoveWatcher *)UFG::qMalloc(0x10ui64, "JoyMoveWatcher", 0i64);
  if ( v2 )
  {
    v2->mListOfMoves.mNode.mPrev = &v2->mListOfMoves.mNode;
    v2->mListOfMoves.mNode.mNext = &v2->mListOfMoves.mNode;
  }
  UFG::gJoyMoveWatcher = v2;
  UFG::qMemSet(this->mControllers, 0, 0x28u);
  UFG::gInputSystem = this;
  *(_DWORD *)this->mIsAssigned = 0;
  this->mIsAssigned[4] = 0;
}

// File Line: 983
// RVA: 0x1B6E00
void __fastcall UFG::InputSystem::~InputSystem(UFG::InputSystem *this)
{
  UFG::Controller *v1; // rcx

  this->vfptr = (UFG::InputSystemVtbl *)&UFG::InputSystem::`vftable;
  v1 = this->mControllers[0];
  if ( v1 )
    ((void (__fastcall *)(UFG::Controller *, __int64))v1->vfptr->~Controller)(v1, 1i64);
}

// File Line: 988
// RVA: 0x1B9050
void __fastcall UFG::InputSystem::SetShouldRestrictCursor(
        bool b_gamepad_window,
        bool b_keyboard_window,
        char b_gamepad_fullscreen,
        char b_keyboard_fullscreen)
{
  UFG::InputSystem::msShouldRestrictCursorGamepad[0] = b_gamepad_window;
  byte_14235FB85 = b_gamepad_fullscreen;
  UFG::InputSystem::msShouldRestrictCursorKeyboard[0] = b_keyboard_window;
  byte_14235FB89 = b_keyboard_fullscreen;
}

// File Line: 997
// RVA: 0x1B9030
void __fastcall UFG::InputSystem::SetShouldHideCursor(
        bool b_gamepad_window,
        bool b_keyboard_window,
        char b_gamepad_fullscreen,
        char b_keyboard_fullscreen)
{
  UFG::InputSystem::msShouldHideCursorGamepad[0] = b_gamepad_window;
  byte_14235FB8D = b_gamepad_fullscreen;
  UFG::InputSystem::msShouldHideCursorKeyboard[0] = b_keyboard_window;
  byte_14235FB91 = b_keyboard_fullscreen;
}

// File Line: 1005
// RVA: 0x1B8DD0
void UFG::InputSystem::PushRestrictAndHideSettings(void)
{
  int v0; // edx
  __int64 v1; // rcx
  __int64 v2; // rcx
  __int64 v3; // rcx

  v0 = UFG::InputSystem::msSavedRestrictAndHideStackIndex;
  UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex] = UFG::InputSystem::msShouldRestrictCursorGamepad[0];
  v1 = ++v0;
  ++v0;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v1] = byte_14235FB85;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v0++] = UFG::InputSystem::msShouldRestrictCursorKeyboard[0];
  v2 = v0++;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v2] = byte_14235FB89;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v0++] = UFG::InputSystem::msShouldHideCursorGamepad[0];
  v3 = v0++;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v3] = byte_14235FB8D;
  UFG::InputSystem::msSavedRestrictAndHideSettings[v0++] = UFG::InputSystem::msShouldHideCursorKeyboard[0];
  UFG::InputSystem::msSavedRestrictAndHideSettings[v0] = byte_14235FB91;
  UFG::InputSystem::msSavedRestrictAndHideStackIndex = v0 + 1;
}

// File Line: 1019
// RVA: 0x1B8B30
void UFG::InputSystem::PopRestrictAndHideSettings(void)
{
  bool v0; // al

  byte_14235FB91 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 1];
  UFG::InputSystem::msShouldHideCursorKeyboard[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 2];
  byte_14235FB8D = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 3];
  UFG::InputSystem::msShouldHideCursorGamepad[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 4];
  byte_14235FB89 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex
                                                                  - 5];
  UFG::InputSystem::msShouldRestrictCursorKeyboard[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 6];
  v0 = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex - 7];
  UFG::InputSystem::msSavedRestrictAndHideStackIndex -= 8;
  byte_14235FB85 = v0;
  UFG::InputSystem::msShouldRestrictCursorGamepad[0] = UFG::InputSystem::msSavedRestrictAndHideSettings[UFG::InputSystem::msSavedRestrictAndHideStackIndex];
}

// File Line: 1036
// RVA: 0x1B7BC0
void __fastcall UFG::InputSystem::InternalUpdate(UFG::InputSystem *this, float elapsedTime, float simTime)
{
  UFG::Controller **mControllers; // r12
  __int64 v4; // r13
  UFG::Controller *v5; // rbx
  UFG::Controller *v6; // rbp
  __int64 v7; // r14
  UFG::InputActionMap **mInputActionMaps; // r15
  UFG::InputActionMap *v9; // rsi
  __int64 i; // rbx
  UFG::InputActionData *v11; // rdi
  void (__fastcall *mInputFunc)(UFG::Controller *, UFG::InputActionData *, float); // rax
  __int64 v13; // rsi
  UFG::MultiInputMap **mMultiInputMaps; // r14
  UFG::MultiInputMap *v15; // rdi
  int j; // ebx

  ++UFG::InputSystem::mServiceTickCounter;
  mControllers = this->mControllers;
  v4 = 5i64;
  do
  {
    v5 = *mControllers;
    if ( *mControllers && (v5->vfptr->IsConnected(*mControllers) || v5->mIsInitialized) )
    {
      v6 = *mControllers;
      v7 = 0i64;
      mInputActionMaps = (*mControllers)->mInputActionMaps;
      do
      {
        v9 = *mInputActionMaps;
        if ( *mInputActionMaps && (simTime > 0.0 || v9->mUpdateWhenSimPaused) && v6->mInputActionMapEnable[v7] )
        {
          for ( i = 0i64; (unsigned int)i < v9->mNumEntries; i = (unsigned int)(i + 1) )
          {
            v11 = v9->mActionMapInfoArray[i].pActionDef->mDataPerController[v6->mControllerIndex];
            if ( v11 )
            {
              if ( v11->mServicedFlag != UFG::InputSystem::mServiceTickCounter )
              {
                mInputFunc = v11->mInputFunc;
                if ( v9->mActionMapInfoArray[i].mInputFunc == mInputFunc )
                {
                  ((void (__fastcall *)(UFG::Controller *, UFG::InputActionData *))mInputFunc)(v6, v11);
                  v11->mServicedFlag = UFG::InputSystem::mServiceTickCounter;
                }
              }
            }
          }
        }
        ++v7;
        ++mInputActionMaps;
      }
      while ( v7 < 32 );
      v13 = 0i64;
      mMultiInputMaps = v6->mMultiInputMaps;
      do
      {
        v15 = *mMultiInputMaps;
        if ( *mMultiInputMaps )
        {
          if ( v6->mMultiInputMapEnable[v13] )
          {
            for ( j = 0; j < v15->mNumEntries; ++j )
              UFG::Controller::UpdateCompoundAction(v6, &v15->mCompoundDefinitions[j], elapsedTime);
          }
        }
        ++v13;
        ++mMultiInputMaps;
      }
      while ( v13 < 32 );
      v6->m_fTimeSinceLastInput = elapsedTime + v6->m_fTimeSinceLastInput;
      v6->mInputState.mPrevMouseWheel = v6->mInputState.mMouseWheel;
    }
    ++mControllers;
    --v4;
  }
  while ( v4 );
}

// File Line: 1071
// RVA: 0x1B6EB0
UFG::Controller *__fastcall UFG::InputSystem::AcquireController(UFG::InputSystem *this, int index)
{
  int v2; // r8d
  UFG::Controller **mControllers; // rdx
  __int64 v4; // rax

  if ( index == -1 )
  {
    v2 = 0;
    mControllers = this->mControllers;
    v4 = 0i64;
    while ( !*mControllers || this->mIsAssigned[v4] )
    {
      ++v4;
      ++v2;
      ++mControllers;
      if ( v4 >= 5 )
        return 0i64;
    }
    this->mIsAssigned[v2] = 1;
    return this->mControllers[v2];
  }
  else if ( index < 5 && this->mControllers[index] )
  {
    this->mIsAssigned[index] = 1;
    return this->mControllers[index];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1101
// RVA: 0x1B8E70
void __fastcall UFG::InputSystem::ReleaseController(UFG::InputSystem *this, UFG::Controller *c)
{
  int v2; // r9d
  UFG::Controller **mControllers; // rax
  __int64 v4; // r8

  v2 = 0;
  mControllers = this->mControllers;
  v4 = 0i64;
  while ( c != *mControllers )
  {
    ++v4;
    ++v2;
    ++mControllers;
    if ( v4 >= 5 )
      return;
  }
  this->mIsAssigned[v2] = 0;
}

// File Line: 1131
// RVA: 0x1B6930
void __fastcall UFG::Controller::Controller(UFG::Controller *this, unsigned int index)
{
  char v3; // cl
  bool *mMultiInputMapEnable; // rax
  UFG::MultiInputMap **mMultiInputMaps; // rcx
  __int64 v6; // rdx

  this->vfptr = (UFG::ControllerVtbl *)&UFG::Controller::`vftable;
  *(_WORD *)&this->mIsInitialized = 0;
  this->mControllerIndex = index;
  this->mInputMessages.mNode.mPrev = &this->mInputMessages.mNode;
  this->mInputMessages.mNode.mNext = &this->mInputMessages.mNode;
  this->mRemappableActions.mNode.mPrev = &this->mRemappableActions.mNode;
  this->mRemappableActions.mNode.mNext = &this->mRemappableActions.mNode;
  this->mInputState.mLastMouseXYTime = 0i64;
  this->mInputState.mMouseX = -1;
  this->mInputState.mMouseY = -1;
  this->mInputState.mMouseWheel = 0;
  this->mInputState.mPrevMouseX = -1;
  this->mInputState.mPrevMouseY = -1;
  this->mInputState.mPrevMouseWheel = 0;
  UFG::qMemSet(this->mInputState.mKeyState, 0, 0x100u);
  this->mPreviousInputState.mLastMouseXYTime = 0i64;
  this->mPreviousInputState.mMouseX = -1;
  this->mPreviousInputState.mMouseY = -1;
  this->mPreviousInputState.mMouseWheel = 0;
  this->mPreviousInputState.mPrevMouseX = -1;
  this->mPreviousInputState.mPrevMouseY = -1;
  this->mPreviousInputState.mPrevMouseWheel = 0;
  UFG::qMemSet(this->mPreviousInputState.mKeyState, 0, 0x100u);
  UFG::JoyInputHistory::JoyInputHistory(&this->mJoyInputHistory);
  this->mRightThumbServiceTick = 0;
  this->m_fTimeSinceLastInput = 0.0;
  this->m_pRemapArray = 0i64;
  *(_QWORD *)&this->m_ActiveMapSet = 0i64;
  *(_WORD *)&this->m_IsKeyboardController = 0;
  v3 = regTweaks;
  if ( !regTweaks )
    v3 = 1;
  regTweaks = v3;
  mMultiInputMapEnable = this->mMultiInputMapEnable;
  mMultiInputMaps = this->mMultiInputMaps;
  v6 = 32i64;
  do
  {
    *(mMultiInputMaps - 32) = 0i64;
    *mMultiInputMaps = 0i64;
    *(mMultiInputMapEnable - 32) = 0;
    *mMultiInputMapEnable = 0;
    ++mMultiInputMaps;
    ++mMultiInputMapEnable;
    --v6;
  }
  while ( v6 );
}

// File Line: 1160
// RVA: 0x1B6BA0
void __fastcall UFG::Controller::~Controller(UFG::Controller *this)
{
  bool *mMultiInputMapEnable; // r12
  UFG::InputActionMap **mInputActionMaps; // rbp
  __int64 v4; // r13
  UFG::InputActionMap *v5; // rdi
  unsigned int i; // ebx
  UFG::InputActionDef *pActionDef; // rsi
  UFG::InputActionData *v8; // rcx
  UFG::InputActionMap *v9; // rsi
  signed int v10; // ebx
  __int64 v11; // rdi
  __int64 v12; // r15
  void *v13; // rcx
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *p_mRemappableActions; // rbx
  UFG::Controller *mNext; // rcx
  UFG::ControllerVtbl *vfptr; // rdx
  UFG::ControllerVtbl **v17; // rax
  UFG::ControllerVtbl *v18; // rdx
  UFG::ControllerVtbl **v19; // rax
  UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *mPrev; // rcx
  UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *v21; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *j; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v23; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v24; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v25; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v26; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v27; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v28; // rax
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *p_mInputMessages; // r14
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *k; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v31; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v32; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v33; // rdx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v34; // rax
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v35; // rcx
  UFG::qNode<UFG::InputMessage,UFG::InputMessage> *v36; // rax

  this->vfptr = (UFG::ControllerVtbl *)&UFG::Controller::`vftable;
  mMultiInputMapEnable = this->mMultiInputMapEnable;
  mInputActionMaps = this->mInputActionMaps;
  v4 = 32i64;
  do
  {
    v5 = *mInputActionMaps;
    if ( *mInputActionMaps )
    {
      for ( i = 0; i < v5->mNumEntries; ++i )
      {
        pActionDef = v5->mActionMapInfoArray[i].pActionDef;
        v8 = pActionDef->mDataPerController[this->mControllerIndex];
        if ( v8 )
        {
          operator delete[](v8);
          pActionDef->mDataPerController[this->mControllerIndex] = 0i64;
        }
      }
      *mInputActionMaps = 0i64;
    }
    v9 = mInputActionMaps[32];
    if ( v9 )
    {
      v10 = 0;
      if ( (int)v9->mNumEntries > 0 )
      {
        v11 = 0i64;
        do
        {
          v12 = *(__int64 *)((char *)&v9->mActionMapInfoArray->pActionDef + v11);
          v13 = *(void **)(v12 + 8i64 * this->mControllerIndex);
          if ( v13 )
          {
            operator delete[](v13);
            *(_QWORD *)(v12 + 8i64 * this->mControllerIndex) = 0i64;
          }
          ++v10;
          v11 += 304i64;
        }
        while ( v10 < (signed int)v9->mNumEntries );
      }
    }
    *(mMultiInputMapEnable - 32) = 0;
    *mMultiInputMapEnable = 0;
    ++mInputActionMaps;
    ++mMultiInputMapEnable;
    --v4;
  }
  while ( v4 );
  p_mRemappableActions = &this->mRemappableActions;
  mNext = (UFG::Controller *)this->mRemappableActions.mNode.mNext;
  if ( mNext != (UFG::Controller *)&this->mRemappableActions )
  {
    do
    {
      vfptr = mNext->vfptr;
      v17 = *(UFG::ControllerVtbl ***)&mNext->mIsInitialized;
      vfptr->ReadRawPadData = (void *(__fastcall *)(UFG::Controller *))v17;
      *v17 = vfptr;
      mNext->vfptr = (UFG::ControllerVtbl *)mNext;
      *(_QWORD *)&mNext->mIsInitialized = mNext;
      v18 = mNext->vfptr;
      v19 = *(UFG::ControllerVtbl ***)&mNext->mIsInitialized;
      v18->ReadRawPadData = (void *(__fastcall *)(UFG::Controller *))v19;
      *v19 = v18;
      mNext->vfptr = (UFG::ControllerVtbl *)mNext;
      *(_QWORD *)&mNext->mIsInitialized = mNext;
      operator delete[](mNext);
      mNext = (UFG::Controller *)this->mRemappableActions.mNode.mNext;
    }
    while ( mNext != (UFG::Controller *)p_mRemappableActions );
  }
  mPrev = this->mJoyInputHistory.mPrev;
  v21 = this->mJoyInputHistory.mNext;
  mPrev->mNext = v21;
  v21->mPrev = mPrev;
  this->mJoyInputHistory.mPrev = &this->mJoyInputHistory;
  this->mJoyInputHistory.mNext = &this->mJoyInputHistory;
  for ( j = this->mRemappableActions.mNode.mNext;
        j != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions;
        j = this->mRemappableActions.mNode.mNext )
  {
    v23 = j->mPrev;
    v24 = j->mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    j->mPrev = j;
    j->mNext = j;
    v25 = j->mPrev;
    v26 = j->mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    j->mPrev = j;
    j->mNext = j;
    operator delete[](j);
  }
  v27 = p_mRemappableActions->mNode.mPrev;
  v28 = this->mRemappableActions.mNode.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  p_mRemappableActions->mNode.mPrev = &p_mRemappableActions->mNode;
  this->mRemappableActions.mNode.mNext = &this->mRemappableActions.mNode;
  p_mInputMessages = &this->mInputMessages;
  for ( k = (UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *)p_mInputMessages->mNode.mNext;
        k != p_mInputMessages;
        k = (UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0> *)p_mInputMessages->mNode.mNext )
  {
    v31 = k->mNode.mPrev;
    v32 = k->mNode.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    k->mNode.mPrev = &k->mNode;
    k->mNode.mNext = &k->mNode;
    v33 = k->mNode.mPrev;
    v34 = k->mNode.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    k->mNode.mPrev = &k->mNode;
    k->mNode.mNext = &k->mNode;
    operator delete[](k);
  }
  v35 = p_mInputMessages->mNode.mPrev;
  v36 = p_mInputMessages->mNode.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  p_mInputMessages->mNode.mPrev = &p_mInputMessages->mNode;
  p_mInputMessages->mNode.mNext = &p_mInputMessages->mNode;
}

// File Line: 1218
// RVA: 0x1B76C0
void __fastcall UFG::Controller::DeleteMapDataStructures(UFG::Controller *this)
{
  UFG::MultiInputMap **mMultiInputMaps; // r15
  __int64 v3; // r12
  __int64 v4; // rdi
  unsigned int i; // ebx
  __int64 v6; // rsi
  void *v7; // rcx
  UFG::MultiInputMap *v8; // rsi
  int v9; // ebx
  __int64 v10; // rdi
  UFG::InputActionDef *mActionDefName; // r14
  UFG::InputActionData *v12; // rcx

  mMultiInputMaps = this->mMultiInputMaps;
  v3 = 32i64;
  do
  {
    v4 = (__int64)*(mMultiInputMaps - 32);
    if ( v4 )
    {
      for ( i = 0; i < *(_DWORD *)(v4 + 8); ++i )
      {
        v6 = *(_QWORD *)(*(_QWORD *)v4 + 24i64 * i);
        v7 = *(void **)(v6 + 8i64 * this->mControllerIndex);
        if ( v7 )
        {
          operator delete[](v7);
          *(_QWORD *)(v6 + 8i64 * this->mControllerIndex) = 0i64;
        }
      }
    }
    v8 = *mMultiInputMaps;
    if ( *mMultiInputMaps )
    {
      v9 = 0;
      if ( v8->mNumEntries > 0 )
      {
        v10 = 0i64;
        do
        {
          mActionDefName = v8->mCompoundDefinitions[v10].mActionDefName;
          v12 = mActionDefName->mDataPerController[this->mControllerIndex];
          if ( v12 )
          {
            operator delete[](v12);
            mActionDefName->mDataPerController[this->mControllerIndex] = 0i64;
          }
          ++v9;
          ++v10;
        }
        while ( v9 < v8->mNumEntries );
      }
    }
    ++mMultiInputMaps;
    --v3;
  }
  while ( v3 );
}

// File Line: 1300
// RVA: 0x1B6F10
void __fastcall UFG::Controller::AddActionToRemappableList(
        UFG::Controller *this,
        UFG::allocator::free_link *actionDef,
        unsigned int id,
        UFG::allocator::free_link *actionDef_2,
        UFG::allocator::free_link *actionDef_3)
{
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rax
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *p_mRemappableActions; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rdx
  UFG::InputActionData *v13; // rcx
  unsigned int mButton; // eax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v15; // rax

  mNext = this->mRemappableActions.mNode.mNext;
  p_mRemappableActions = &this->mRemappableActions;
  if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions )
  {
LABEL_4:
    v11 = UFG::qMalloc(0x38ui64, "ActionRemapInfo", 0i64);
    v12 = v11;
    if ( v11 )
    {
      v11->mNext = v11;
      v11[1].mNext = v11;
      v11[2].mNext = actionDef;
      v11[3].mNext = actionDef_2;
      v11[4].mNext = actionDef_3;
      LODWORD(v11[5].mNext) = id;
      *(UFG::allocator::free_link **)((char *)&v11[5].mNext + 4) = (UFG::allocator::free_link *)-1i64;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = (UFG::InputActionData *)actionDef[this->mControllerIndex].mNext;
    mButton = v13->mButton;
    LODWORD(v12[6].mNext) = v13->mButton;
    HIDWORD(v12[5].mNext) = mButton;
    v15 = p_mRemappableActions->mNode.mNext;
    p_mRemappableActions->mNode.mNext = (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v12;
    v12->mNext = (UFG::allocator::free_link *)p_mRemappableActions;
    v12[1].mNext = (UFG::allocator::free_link *)v15;
    v15->mPrev = (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v12;
  }
  else
  {
    while ( (UFG::allocator::free_link *)mNext[1].mPrev != actionDef )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions )
        goto LABEL_4;
    }
  }
}

// File Line: 1341
// RVA: 0x1B73C0
void __fastcall UFG::Controller::ApplyRemapList(UFG::Controller *this)
{
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mPrev; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v4; // rdx

  for ( i = this->mRemappableActions.mNode.mNext;
        i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions;
        i = i->mNext )
  {
    mPrev = i[1].mPrev;
    if ( mPrev )
      **((_DWORD **)&mPrev->mPrev + this->mControllerIndex) = i[3].mPrev;
    mNext = i[1].mNext;
    if ( mNext )
      **((_DWORD **)&mNext->mPrev + this->mControllerIndex) = i[3].mPrev;
    v4 = i[2].mPrev;
    if ( v4 )
      **((_DWORD **)&v4->mPrev + this->mControllerIndex) = i[3].mPrev;
  }
}

// File Line: 1358
// RVA: 0x1B8EA0
void __fastcall UFG::Controller::ResetRemapList(UFG::Controller *this)
{
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rax
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mPrev; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rdx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v4; // rdx

  for ( i = this->mRemappableActions.mNode.mNext;
        i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&this->mRemappableActions;
        i = i->mNext )
  {
    mPrev = i[1].mPrev;
    if ( mPrev )
      **((_DWORD **)&mPrev->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    mNext = i[1].mNext;
    if ( mNext )
      **((_DWORD **)&mNext->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    v4 = i[2].mPrev;
    if ( v4 )
      **((_DWORD **)&v4->mPrev + this->mControllerIndex) = HIDWORD(i[2].mNext);
    LODWORD(i[3].mPrev) = HIDWORD(i[2].mNext);
  }
}

// File Line: 1374
// RVA: 0x1B74B0
void __fastcall UFG::Controller::CreateSingleMapStructure(UFG::Controller *this, int index)
{
  UFG::InputActionMap *v3; // r15
  unsigned int i; // ebx
  UFG::InputActionMapInfo *mActionMapInfoArray; // rsi
  UFG::InputActionDef *pActionDef; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  __int64 mButtonDef; // rax
  const unsigned int *m_pRemapArray; // rdx

  v3 = this->mInputActionMaps[index];
  for ( i = 0; i < v3->mNumEntries; ++i )
  {
    mActionMapInfoArray = v3->mActionMapInfoArray;
    pActionDef = v3->mActionMapInfoArray[i].pActionDef;
    if ( !pActionDef->mDataPerController[this->mControllerIndex] )
    {
      v7 = UFG::qMalloc(0x50ui64, "InputActionData", 0i64);
      v8 = v7;
      if ( v7 )
      {
        v7[2].mNext = 0i64;
        *(UFG::allocator::free_link **)((char *)&v7[8].mNext + 4) = 0i64;
        BYTE4(v7[9].mNext) = 0;
        v7[3].mNext = 0i64;
        v7[4].mNext = 0i64;
        *(UFG::allocator::free_link **)((char *)&v7[5].mNext + 4) = 0i64;
        LODWORD(v7[5].mNext) = 0;
        v7[7].mNext = 0i64;
        HIDWORD(v7[6].mNext) = 0;
        LODWORD(v7[8].mNext) = 0;
      }
      else
      {
        v8 = 0i64;
      }
      pActionDef->mDataPerController[this->mControllerIndex] = (UFG::InputActionData *)v8;
      mButtonDef = mActionMapInfoArray[i].mButtonDef;
      m_pRemapArray = this->m_pRemapArray;
      if ( m_pRemapArray
        && (unsigned int)mButtonDef < 0x12
        && (void (__fastcall *)(UFG::Controller *, UFG::InputActionData *, const float))mActionMapInfoArray[i].mInputFunc != UFG::Keyboard_IAD_Func )
      {
        LODWORD(mButtonDef) = m_pRemapArray[mButtonDef];
      }
      LODWORD(v8->mNext) = mButtonDef;
      v8[1].mNext = (UFG::allocator::free_link *)mActionMapInfoArray[i].mInputFunc;
      HIDWORD(v8->mNext) = mActionMapInfoArray[i].mSignalType;
    }
  }
}

// File Line: 1427
// RVA: 0x1B7450
void __fastcall UFG::Controller::CreateMapDataStructures(UFG::Controller *this)
{
  int v2; // ebx
  UFG::MultiInputMap **mMultiInputMaps; // rdi

  v2 = 0;
  mMultiInputMaps = this->mMultiInputMaps;
  do
  {
    if ( *(mMultiInputMaps - 32) )
      UFG::Controller::CreateSingleMapStructure(this, v2);
    if ( *mMultiInputMaps )
      UFG::Controller::CreateSingleMultiMapStruct(this, v2);
    ++v2;
    ++mMultiInputMaps;
  }
  while ( v2 < 32 );
}

// File Line: 1444
// RVA: 0x1B7110
void __fastcall UFG::Controller::AddInputActionMap(
        UFG::Controller *this,
        UFG::InputActionMap *actionMap,
        const unsigned int *pRemapArray)
{
  int v4; // eax
  int v5; // r8d
  UFG::InputActionMap **i; // r9
  UFG::InputActionMap *v7; // r15
  unsigned int j; // ebx
  UFG::InputActionMapInfo *mActionMapInfoArray; // rsi
  UFG::InputActionDef *pActionDef; // r14
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rcx
  __int64 mButtonDef; // rax
  const unsigned int *m_pRemapArray; // rdx

  if ( !this->m_pRemapArray )
    this->m_pRemapArray = pRemapArray;
  v4 = -1;
  v5 = 0;
  for ( i = this->mInputActionMaps; actionMap != *i; ++i )
  {
    if ( !*i && v4 == -1 )
      v4 = v5;
    if ( ++v5 >= 32 )
    {
      this->mInputActionMaps[v4] = actionMap;
      this->mInputActionMapEnable[v4] = 1;
      v7 = this->mInputActionMaps[v4];
      for ( j = 0; j < v7->mNumEntries; ++j )
      {
        mActionMapInfoArray = v7->mActionMapInfoArray;
        pActionDef = v7->mActionMapInfoArray[j].pActionDef;
        if ( !pActionDef->mDataPerController[this->mControllerIndex] )
        {
          v11 = UFG::qMalloc(0x50ui64, "InputActionData", 0i64);
          v12 = v11;
          if ( v11 )
          {
            v11[2].mNext = 0i64;
            *(UFG::allocator::free_link **)((char *)&v11[8].mNext + 4) = 0i64;
            BYTE4(v11[9].mNext) = 0;
            v11[3].mNext = 0i64;
            v11[4].mNext = 0i64;
            *(UFG::allocator::free_link **)((char *)&v11[5].mNext + 4) = 0i64;
            LODWORD(v11[5].mNext) = 0;
            v11[7].mNext = 0i64;
            HIDWORD(v11[6].mNext) = 0;
            LODWORD(v11[8].mNext) = 0;
          }
          else
          {
            v12 = 0i64;
          }
          pActionDef->mDataPerController[this->mControllerIndex] = (UFG::InputActionData *)v12;
          mButtonDef = mActionMapInfoArray[j].mButtonDef;
          m_pRemapArray = this->m_pRemapArray;
          if ( m_pRemapArray
            && (unsigned int)mButtonDef < 0x12
            && (void (__fastcall *)(UFG::Controller *, UFG::InputActionData *, const float))mActionMapInfoArray[j].mInputFunc != UFG::Keyboard_IAD_Func )
          {
            LODWORD(mButtonDef) = m_pRemapArray[mButtonDef];
          }
          LODWORD(v12->mNext) = mButtonDef;
          v12[1].mNext = (UFG::allocator::free_link *)mActionMapInfoArray[j].mInputFunc;
          HIDWORD(v12->mNext) = mActionMapInfoArray[j].mSignalType;
        }
      }
      return;
    }
  }
}

// File Line: 1475
// RVA: 0x1B7990
signed __int64 __fastcall UFG::Controller::EnableInputActionMap(UFG::Controller *this, UFG::InputActionMap *actionMap)
{
  int v2; // r9d
  UFG::InputActionMap **mInputActionMaps; // rax
  __int64 v4; // r8

  v2 = 0;
  mInputActionMaps = this->mInputActionMaps;
  v4 = 0i64;
  while ( actionMap != *mInputActionMaps )
  {
    ++v4;
    ++v2;
    ++mInputActionMaps;
    if ( v4 >= 32 )
      return 1i64;
  }
  this->mInputActionMapEnable[v2] = 1;
  return 0i64;
}

// File Line: 1521
// RVA: 0x1B78F0
signed __int64 __fastcall UFG::Controller::DisableInputActionMap(UFG::Controller *this, UFG::InputActionMap *actionMap)
{
  int v3; // r8d
  __int64 v4; // rdx
  UFG::InputActionMap **i; // rax
  __int64 v7; // rax
  unsigned int v8; // r8d
  UFG::InputActionData *v9; // rdx

  v3 = 0;
  v4 = 0i64;
  for ( i = this->mInputActionMaps; actionMap != *i || !actionMap; ++i )
  {
    ++v4;
    ++v3;
    if ( v4 >= 32 )
      return 1i64;
  }
  v7 = v3;
  v8 = 0;
  for ( this->mInputActionMapEnable[v7] = 0; v8 < actionMap->mNumEntries; ++v8 )
  {
    v9 = actionMap->mActionMapInfoArray[v8].pActionDef->mDataPerController[this->mControllerIndex];
    if ( v9 )
    {
      v9->mActionTrue = 0;
      *(_QWORD *)&v9->mData0i = 0i64;
      *(_QWORD *)&v9->mData2i = 0i64;
      *(_QWORD *)&v9->mAxisPositionY = 0i64;
      *(_QWORD *)&v9->mAxisRawX[1] = 0i64;
      *(_QWORD *)&v9->mAxisRawY[1] = 0i64;
      v9->mAxisRawY[0] = 0.0;
      *(_QWORD *)&v9->mOnSeconds = 0i64;
    }
  }
  return 0i64;
}

// File Line: 1588
// RVA: 0x1B77B0
void __fastcall UFG::Controller::DisableAllMaps(UFG::Controller *this)
{
  UFG::InputActionMap **mInputActionMaps; // rbx
  __int64 i; // r10
  UFG::InputActionMap *v4; // r9
  signed int v5; // edx
  __int64 v6; // r8
  UFG::InputActionDef *pActionDef; // rcx
  UFG::InputActionData *v8; // rcx
  __int64 v9; // r10
  UFG::MultiInputMap **mMultiInputMaps; // rbx
  UFG::MultiInputMap *v11; // r9
  int v12; // edx
  __int64 v13; // r8
  UFG::InputActionDef *mActionDefName; // rcx
  UFG::InputActionData *v15; // rcx

  mInputActionMaps = this->mInputActionMaps;
  for ( i = 0i64; i < 32; ++i )
  {
    v4 = *mInputActionMaps;
    this->mInputActionMapEnable[i] = 0;
    if ( v4 )
    {
      v5 = 0;
      if ( (int)v4->mNumEntries > 0 )
      {
        v6 = 0i64;
        do
        {
          pActionDef = v4->mActionMapInfoArray[v6].pActionDef;
          if ( pActionDef )
          {
            v8 = pActionDef->mDataPerController[this->mControllerIndex];
            if ( v8 )
            {
              v8->mActionTrue = 0;
              *(_QWORD *)&v8->mData0i = 0i64;
              *(_QWORD *)&v8->mData2i = 0i64;
              *(_QWORD *)&v8->mAxisPositionY = 0i64;
              *(_QWORD *)&v8->mAxisRawX[1] = 0i64;
              *(_QWORD *)&v8->mAxisRawY[1] = 0i64;
              v8->mAxisRawY[0] = 0.0;
              *(_QWORD *)&v8->mOnSeconds = 0i64;
            }
          }
          ++v5;
          ++v6;
        }
        while ( v5 < (signed int)v4->mNumEntries );
      }
    }
    ++mInputActionMaps;
  }
  v9 = 0i64;
  mMultiInputMaps = this->mMultiInputMaps;
  do
  {
    v11 = *mMultiInputMaps;
    this->mMultiInputMapEnable[v9] = 0;
    if ( v11 )
    {
      v12 = 0;
      if ( v11->mNumEntries > 0 )
      {
        v13 = 0i64;
        do
        {
          mActionDefName = v11->mCompoundDefinitions[v13].mActionDefName;
          if ( mActionDefName )
          {
            v15 = mActionDefName->mDataPerController[this->mControllerIndex];
            if ( v15 )
            {
              v15->mActionTrue = 0;
              *(_QWORD *)&v15->mData0i = 0i64;
              *(_QWORD *)&v15->mData2i = 0i64;
              *(_QWORD *)&v15->mAxisPositionY = 0i64;
              *(_QWORD *)&v15->mAxisRawX[1] = 0i64;
              *(_QWORD *)&v15->mAxisRawY[1] = 0i64;
              v15->mAxisRawY[0] = 0.0;
              *(_QWORD *)&v15->mOnSeconds = 0i64;
              v15[1].mButton = 0;
              v15[1].mInputFunc = 0i64;
              v15->mDebouncer = 1;
            }
          }
          ++v12;
          ++v13;
        }
        while ( v12 < v11->mNumEntries );
      }
    }
    ++v9;
    ++mMultiInputMaps;
  }
  while ( v9 < 32 );
}

// File Line: 1628
// RVA: 0x1B75D0
void __fastcall UFG::Controller::CreateSingleMultiMapStruct(UFG::Controller *this, int index)
{
  UFG::MultiInputMap *v3; // rsi
  int v4; // ebx
  __int64 v5; // rdi
  UFG::InputActionDef *mActionDefName; // r14
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx

  v3 = this->mMultiInputMaps[index];
  v4 = 0;
  if ( v3->mNumEntries > 0 )
  {
    v5 = 0i64;
    do
    {
      mActionDefName = v3->mCompoundDefinitions[v5].mActionDefName;
      if ( !mActionDefName->mDataPerController[this->mControllerIndex] )
      {
        v7 = UFG::qMalloc(0x60ui64, "MultiInputActionData", 0i64);
        v8 = v7;
        if ( v7 )
        {
          v7[2].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[8].mNext + 4) = 0i64;
          BYTE4(v7[9].mNext) = 0;
          v7[3].mNext = 0i64;
          v7[4].mNext = 0i64;
          *(UFG::allocator::free_link **)((char *)&v7[5].mNext + 4) = 0i64;
          LODWORD(v7[5].mNext) = 0;
          v7[7].mNext = 0i64;
          HIDWORD(v7[6].mNext) = 0;
          LODWORD(v7[8].mNext) = 0;
          LODWORD(v7[10].mNext) = 0;
          v7[11].mNext = 0i64;
          BYTE4(v7[10].mNext) = 0;
        }
        else
        {
          v8 = 0i64;
        }
        mActionDefName->mDataPerController[this->mControllerIndex] = (UFG::InputActionData *)v8;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->mNumEntries );
  }
}

// File Line: 1653
// RVA: 0x1B7290
void __fastcall UFG::Controller::AddMultiInputMap(UFG::Controller *this, UFG::MultiInputMap *multiMap)
{
  int v3; // eax
  int v4; // r8d
  UFG::MultiInputMap **i; // r9
  UFG::MultiInputMap *v6; // r14
  int v7; // ebx
  __int64 v8; // rdi
  UFG::InputActionDef *mActionDefName; // r15
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rcx

  v3 = -1;
  v4 = 0;
  for ( i = this->mMultiInputMaps; multiMap != *i; ++i )
  {
    if ( !*i && v3 == -1 )
      v3 = v4;
    if ( ++v4 >= 32 )
    {
      this->mMultiInputMaps[v3] = multiMap;
      this->mMultiInputMapEnable[v3] = 1;
      v6 = this->mMultiInputMaps[v3];
      v7 = 0;
      if ( v6->mNumEntries > 0 )
      {
        v8 = 0i64;
        do
        {
          mActionDefName = v6->mCompoundDefinitions[v8].mActionDefName;
          if ( !mActionDefName->mDataPerController[this->mControllerIndex] )
          {
            v10 = UFG::qMalloc(0x60ui64, "MultiInputActionData", 0i64);
            v11 = v10;
            if ( v10 )
            {
              v10[2].mNext = 0i64;
              *(UFG::allocator::free_link **)((char *)&v10[8].mNext + 4) = 0i64;
              BYTE4(v10[9].mNext) = 0;
              v10[3].mNext = 0i64;
              v10[4].mNext = 0i64;
              *(UFG::allocator::free_link **)((char *)&v10[5].mNext + 4) = 0i64;
              LODWORD(v10[5].mNext) = 0;
              v10[7].mNext = 0i64;
              HIDWORD(v10[6].mNext) = 0;
              LODWORD(v10[8].mNext) = 0;
              LODWORD(v10[10].mNext) = 0;
              v10[11].mNext = 0i64;
              BYTE4(v10[10].mNext) = 0;
            }
            else
            {
              v11 = 0i64;
            }
            mActionDefName->mDataPerController[this->mControllerIndex] = (UFG::InputActionData *)v11;
          }
          ++v7;
          ++v8;
        }
        while ( v7 < v6->mNumEntries );
      }
      return;
    }
  }
}

// File Line: 1758
// RVA: 0x1B9070
void __fastcall UFG::Controller::UpdateCompoundAction(
        UFG::Controller *this,
        UFG::CompoundAction *ca,
        float elapsedTime)
{
  UFG::InputActionData *v3; // r9
  float v4; // xmm3_4
  __int64 mButton; // rbp
  float v6; // xmm3_4
  float mEndTime; // xmm0_4
  UFG::InputActionDef *v8; // r11
  float mOnSeconds; // xmm2_4
  int v10; // r10d
  UFG::InputActionData *v11; // rax
  UFG::InputActionDef *v12; // r11
  UFG::InputActionData *v13; // rax
  float v14; // xmm0_4
  UFG::InputActionDef *v15; // r11
  UFG::InputActionData *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  float mMaxHoldTime; // xmm0_4

  v3 = ca->mActionDefName->mDataPerController[this->mControllerIndex];
  v4 = 0.0;
  mButton = (int)v3[1].mButton;
  if ( v3->mActionTrue )
    v3->mActionTrue = 0;
  if ( (_DWORD)mButton )
  {
    v6 = elapsedTime + *(float *)&v3[1].mInputFunc;
    *(float *)&v3[1].mInputFunc = v6;
    v4 = v6 - *((float *)&v3[1].mInputFunc + 1);
    mEndTime = ca->mActionNodes[mButton].mEndTime;
    if ( v4 > mEndTime && mEndTime >= 0.0 )
    {
      v3->mActionTrue = 0;
LABEL_55:
      *(_QWORD *)&v3->mData0i = 0i64;
      *(_QWORD *)&v3->mData2i = 0i64;
      *(_QWORD *)&v3->mAxisPositionY = 0i64;
      *(_QWORD *)&v3->mAxisRawX[1] = 0i64;
      *(_QWORD *)&v3->mAxisRawY[1] = 0i64;
      v3->mAxisRawY[0] = 0.0;
      v3->mDebouncer = 1;
      v3[1].mInputFunc = 0i64;
      v3[1].mButton = 0;
      *(_QWORD *)&v3->mOnSeconds = 0i64;
      return;
    }
  }
  v8 = ca->mActionNodes[mButton].mActions[0];
  mOnSeconds = FLOAT_999_0;
  v10 = 0;
  if ( v8 )
  {
    v11 = v8->mDataPerController[this->mControllerIndex];
    if ( v11 )
    {
      if ( v11->mActionTrue )
        v10 = 1;
      if ( v11->mOnSeconds < 999.0 )
        mOnSeconds = v11->mOnSeconds;
    }
    else
    {
      mOnSeconds = 0.0;
    }
  }
  v12 = ca->mActionNodes[mButton].mActions[1];
  if ( v12 )
  {
    v13 = v12->mDataPerController[this->mControllerIndex];
    if ( v13 )
    {
      if ( v13->mActionTrue )
        ++v10;
      v14 = v13->mOnSeconds;
    }
    else
    {
      v14 = 0.0;
    }
    if ( v14 < mOnSeconds )
    {
      if ( v13 )
        mOnSeconds = v13->mOnSeconds;
      else
        mOnSeconds = 0.0;
    }
  }
  v15 = ca->mActionNodes[mButton].mActions[2];
  if ( v15 )
  {
    v16 = v15->mDataPerController[this->mControllerIndex];
    if ( v16 )
    {
      if ( v16->mActionTrue )
        ++v10;
      v17 = v16->mOnSeconds;
    }
    else
    {
      v17 = 0.0;
    }
    if ( v17 < mOnSeconds )
    {
      if ( v16 )
        mOnSeconds = v16->mOnSeconds;
      else
        mOnSeconds = 0.0;
    }
  }
  if ( v3->mDebouncer && ca->mShouldDebounce || v10 < ca->mActionNodes[mButton].mNumActionsCombined )
  {
    if ( v10 )
      return;
    if ( !(_DWORD)mButton )
    {
      v3->mDebouncer = 0;
      return;
    }
    if ( ca->mActionNodes[mButton].mMinHoldTime < 0.0 && ca->mActionNodes[mButton].mMaxHoldTime < 0.0 )
    {
      v3->mActionTrue = 0;
      goto LABEL_55;
    }
  }
  else if ( v4 >= ca->mActionNodes[mButton].mStartTime )
  {
    v18 = ca->mActionNodes[mButton].mEndTime;
    if ( (v4 <= v18 || v18 < 0.0) && mOnSeconds >= ca->mActionNodes[mButton].mMinHoldTime )
    {
      mMaxHoldTime = ca->mActionNodes[mButton].mMaxHoldTime;
      if ( mMaxHoldTime >= mOnSeconds || mMaxHoldTime < 0.0 )
      {
        v3[1].mButton = mButton + 1;
        if ( (_DWORD)mButton + 1 == ca->mNumNodes )
        {
          if ( ca->mActionNodes[mButton].mMinHoldTime >= 0.0 || ca->mActionNodes[mButton].mMaxHoldTime >= 0.0 )
          {
            v3->mActionTrue = 0;
            *(_QWORD *)&v3->mData0i = 0i64;
            *(_QWORD *)&v3->mData2i = 0i64;
            *(_QWORD *)&v3->mAxisPositionY = 0i64;
            *(_QWORD *)&v3->mAxisRawX[1] = 0i64;
            *(_QWORD *)&v3->mAxisRawY[1] = 0i64;
            v3->mAxisRawY[0] = 0.0;
            *(_QWORD *)&v3->mOnSeconds = 0i64;
            v3[1].mButton = 0;
            v3[1].mInputFunc = 0i64;
            v3->mDebouncer = 1;
            v3->mActionTrue = 1;
          }
          else
          {
            v3->mActionTrue = 1;
            v3[1].mButton = mButton;
          }
        }
        else
        {
          HIDWORD(v3[1].mInputFunc) = v3[1].mInputFunc;
        }
      }
    }
  }
}

// File Line: 1883
// RVA: 0x1B9300
void __fastcall UFG::Controller::UpdateRightThumbHistory(UFG::Controller *this, float x, float y, float elapsedTime)
{
  if ( this->mRightThumbServiceTick != UFG::InputSystem::mServiceTickCounter )
  {
    this->mRightThumbServiceTick = UFG::InputSystem::mServiceTickCounter;
    UFG::JoyInputHistory::AddAxisInfo(&this->mJoyInputHistory, x, y, elapsedTime);
  }
}

// File Line: 1901
// RVA: 0x1B8F10
char __fastcall UFG::Controller::RightStick_HoldThenFlickAcross(UFG::Controller *this)
{
  char v2; // dl
  __int64 mOctantIndex; // rcx
  int mOctant; // r9d
  int v6; // eax
  int v7; // ecx
  __int64 v8; // rdx
  float v9; // xmm0_4
  int v10; // r11d
  int i; // r9d
  int v12; // eax
  int v13; // ecx

  v2 = tweaksAdded;
  if ( !tweaksAdded )
    v2 = 1;
  tweaksAdded = v2;
  if ( this->mRightThumbServiceTick != UFG::InputSystem::mServiceTickCounter )
    return 0;
  mOctantIndex = this->mJoyInputHistory.mOctantIndex;
  mOctant = this->mJoyInputHistory.mOctantHistory[mOctantIndex].mOctant;
  if ( UFG::gFlickDuration >= this->mJoyInputHistory.mOctantHistory[mOctantIndex].mDuration )
  {
    v6 = mOctantIndex - 1;
    v7 = 7;
    if ( v6 >= 0 )
      v7 = v6;
    v8 = v7;
    if ( this->mJoyInputHistory.mOctantHistory[v7].mOctant == -1
      && UFG::gFlickDuration > this->mJoyInputHistory.mOctantHistory[v7].mDuration )
    {
      ++count;
      v9 = 0.0;
      v10 = ((_BYTE)mOctant - 8) & 0xF;
      for ( i = 0; i < 4; ++i )
      {
        if ( --v8 < 0 )
          v8 = 7i64;
        v12 = v10 - this->mJoyInputHistory.mOctantHistory[v8].mOctant;
        v13 = v12;
        if ( v12 < 0 )
          v13 = this->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
        if ( v13 > 8 )
        {
          if ( v12 < 0 )
            v12 = this->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
          v12 = 16 - v12;
        }
        else if ( v12 < 0 )
        {
          v12 = this->mJoyInputHistory.mOctantHistory[v8].mOctant - v10;
        }
        if ( v12 > UFG::gAllowedSectionDelt )
          break;
        v9 = v9 + this->mJoyInputHistory.mOctantHistory[v8].mDuration;
        if ( v9 >= UFG::gHoldDuration )
          return 1;
      }
    }
  }
  return 0;
}

// File Line: 2000
// RVA: 0x1B6FD0
void __fastcall UFG::JoyInputHistory::AddAxisInfo(UFG::JoyInputHistory *this, float x, float y, float elapsedTime)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  int mIndex; // eax
  int mValidHistorySize; // eax
  int v9; // ecx
  __int64 mOctantIndex; // rdx
  int v11; // eax

  if ( !this->mLocked )
  {
    v5 = atan2f(y, x);
    if ( fsqrt((float)(x * x) + (float)(y * y)) <= 0.85000002 )
      v6 = 0.0;
    else
      v6 = *(float *)&FLOAT_1_0;
    this->mTheta[this->mIndex] = v5;
    this->mR[this->mIndex++] = v6;
    mIndex = this->mIndex;
    if ( mIndex >= 64 )
      mIndex = 0;
    this->mIndex = mIndex;
    mValidHistorySize = this->mValidHistorySize;
    if ( mValidHistorySize < 64 )
      this->mValidHistorySize = mValidHistorySize + 1;
    v9 = -1;
    if ( v6 != 0.0 )
    {
      if ( v5 < 0.0 )
        v5 = v5 + 6.2831855;
      v9 = (int)(float)((float)(v5 + 0.19634955) * 2.546479) & 0xF;
    }
    mOctantIndex = this->mOctantIndex;
    if ( v9 == this->mOctantHistory[mOctantIndex].mOctant )
    {
      this->mOctantHistory[mOctantIndex].mDuration = elapsedTime + this->mOctantHistory[mOctantIndex].mDuration;
    }
    else
    {
      v11 = mOctantIndex + 1;
      if ( (_DWORD)mOctantIndex == 7 )
        v11 = 0;
      this->mOctantIndex = v11;
      this->mOctantHistory[v11].mDuration = elapsedTime;
      this->mOctantHistory[this->mOctantIndex].mOctant = v9;
    }
  }
}

