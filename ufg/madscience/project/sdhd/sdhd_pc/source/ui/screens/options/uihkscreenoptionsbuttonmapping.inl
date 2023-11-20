// File Line: 18
// RVA: 0x5EEFD0
void __fastcall UFG::KeyToKeyName(UFG::qString *keyName, char key)
{
  int v2; // ebx
  UFG::qString *v3; // rdi
  const char *v4; // rdx

  v2 = (unsigned __int8)key;
  v3 = keyName;
  UFG::qString::Set(keyName, &customWorldMapCaption);
  switch ( v2 )
  {
    case 1:
      v4 = "$BUTTON_REMAP_LBUTTON";
      goto LABEL_195;
    case 2:
      v4 = "$BUTTON_REMAP_RBUTTON";
      goto LABEL_195;
    case 3:
      v4 = "$BUTTON_REMAP_CANCEL";
      goto LABEL_195;
    case 4:
      v4 = "$BUTTON_REMAP_MBUTTON";
      goto LABEL_195;
    case 5:
      v4 = "$BUTTON_REMAP_XBUTTON1";
      goto LABEL_195;
    case 6:
      v4 = "$BUTTON_REMAP_XBUTTON2";
      goto LABEL_195;
    case 8:
      v4 = "$BUTTON_REMAP_BACK";
      goto LABEL_195;
    case 9:
      v4 = "$BUTTON_REMAP_TAB";
      goto LABEL_195;
    case 12:
      v4 = "$BUTTON_REMAP_CLEAR";
      goto LABEL_195;
    case 13:
      v4 = "$BUTTON_REMAP_RETURN";
      goto LABEL_195;
    case 16:
      v4 = "$BUTTON_REMAP_SHIFT";
      goto LABEL_195;
    case 17:
      v4 = "$BUTTON_REMAP_CONTROL";
      goto LABEL_195;
    case 18:
      v4 = "$BUTTON_REMAP_MENU";
      goto LABEL_195;
    case 19:
      v4 = "$BUTTON_REMAP_PAUSE";
      goto LABEL_195;
    case 20:
      v4 = "$BUTTON_REMAP_CAPITAL";
      goto LABEL_195;
    case 21:
      v4 = "$BUTTON_REMAP_KANA";
      goto LABEL_195;
    case 23:
      v4 = "$BUTTON_REMAP_JUNGA";
      goto LABEL_195;
    case 24:
      v4 = "$BUTTON_REMAP_FINAL";
      goto LABEL_195;
    case 25:
      v4 = "$BUTTON_REMAP_HANJA";
      goto LABEL_195;
    case 27:
      v4 = "$BUTTON_REMAP_ESCAPE";
      goto LABEL_195;
    case 28:
      v4 = "$BUTTON_REMAP_CONVERT";
      goto LABEL_195;
    case 29:
      v4 = "$BUTTON_REMAP_NONCONVERT";
      goto LABEL_195;
    case 30:
      v4 = "$BUTTON_REMAP_ACCEPT";
      goto LABEL_195;
    case 31:
      v4 = "$BUTTON_REMAP_MODECHANGE";
      goto LABEL_195;
    case 32:
      v4 = "$BUTTON_REMAP_SPACE";
      goto LABEL_195;
    case 33:
      v4 = "$BUTTON_REMAP_PRIOR";
      goto LABEL_195;
    case 34:
      v4 = "$BUTTON_REMAP_NEXT";
      goto LABEL_195;
    case 35:
      v4 = "$BUTTON_REMAP_END";
      goto LABEL_195;
    case 36:
      v4 = "$BUTTON_REMAP_HOME";
      goto LABEL_195;
    case 37:
      v4 = "$BUTTON_REMAP_LEFT";
      goto LABEL_195;
    case 38:
      v4 = "$BUTTON_REMAP_UP";
      goto LABEL_195;
    case 39:
      v4 = "$BUTTON_REMAP_RIGHT";
      goto LABEL_195;
    case 40:
      v4 = "$BUTTON_REMAP_DOWN";
      goto LABEL_195;
    case 41:
      v4 = "$BUTTON_REMAP_SELECT";
      goto LABEL_195;
    case 42:
      v4 = "$BUTTON_REMAP_PRINT";
      goto LABEL_195;
    case 43:
      v4 = "$BUTTON_REMAP_EXECUTE";
      goto LABEL_195;
    case 44:
      v4 = "$BUTTON_REMAP_SNAPSHOT";
      goto LABEL_195;
    case 45:
      v4 = "$BUTTON_REMAP_INSERT";
      goto LABEL_195;
    case 46:
      v4 = "$BUTTON_REMAP_DELETE";
      goto LABEL_195;
    case 47:
      v4 = "$BUTTON_REMAP_HELP";
      goto LABEL_195;
    case 48:
      v4 = "$BUTTON_REMAP_BUTTON_ZERO";
      goto LABEL_195;
    case 49:
      v4 = "$BUTTON_REMAP_BUTTON_ONE";
      goto LABEL_195;
    case 50:
      v4 = "$BUTTON_REMAP_BUTTON_TWO";
      goto LABEL_195;
    case 51:
      v4 = "$BUTTON_REMAP_BUTTON_THREE";
      goto LABEL_195;
    case 52:
      v4 = "$BUTTON_REMAP_BUTTON_FOUR";
      goto LABEL_195;
    case 53:
      v4 = "$BUTTON_REMAP_BUTTON_FIVE";
      goto LABEL_195;
    case 54:
      v4 = "$BUTTON_REMAP_BUTTON_SIX";
      goto LABEL_195;
    case 55:
      v4 = "$BUTTON_REMAP_BUTTON_SEVEN";
      goto LABEL_195;
    case 56:
      v4 = "$BUTTON_REMAP_BUTTON_EIGHT";
      goto LABEL_195;
    case 57:
      v4 = "$BUTTON_REMAP_BUTTON_NINE";
      goto LABEL_195;
    case 65:
      v4 = "$BUTTON_REMAP_BUTTON_A";
      goto LABEL_195;
    case 66:
      v4 = "$BUTTON_REMAP_BUTTON_B";
      goto LABEL_195;
    case 67:
      v4 = "$BUTTON_REMAP_BUTTON_C";
      goto LABEL_195;
    case 68:
      v4 = "$BUTTON_REMAP_BUTTON_D";
      goto LABEL_195;
    case 69:
      v4 = "$BUTTON_REMAP_BUTTON_E";
      goto LABEL_195;
    case 70:
      v4 = "$BUTTON_REMAP_BUTTON_F";
      goto LABEL_195;
    case 71:
      v4 = "$BUTTON_REMAP_BUTTON_G";
      goto LABEL_195;
    case 72:
      v4 = "$BUTTON_REMAP_BUTTON_H";
      goto LABEL_195;
    case 73:
      v4 = "$BUTTON_REMAP_BUTTON_I";
      goto LABEL_195;
    case 74:
      v4 = "$BUTTON_REMAP_BUTTON_J";
      goto LABEL_195;
    case 75:
      v4 = "$BUTTON_REMAP_BUTTON_K";
      goto LABEL_195;
    case 76:
      v4 = "$BUTTON_REMAP_BUTTON_L";
      goto LABEL_195;
    case 77:
      v4 = "$BUTTON_REMAP_BUTTON_M";
      goto LABEL_195;
    case 78:
      v4 = "$BUTTON_REMAP_BUTTON_N";
      goto LABEL_195;
    case 79:
      v4 = "$BUTTON_REMAP_BUTTON_O";
      goto LABEL_195;
    case 80:
      v4 = "$BUTTON_REMAP_BUTTON_P";
      goto LABEL_195;
    case 81:
      v4 = "$BUTTON_REMAP_BUTTON_Q";
      goto LABEL_195;
    case 82:
      v4 = "$BUTTON_REMAP_BUTTON_R";
      goto LABEL_195;
    case 83:
      v4 = "$BUTTON_REMAP_BUTTON_S";
      goto LABEL_195;
    case 84:
      v4 = "$BUTTON_REMAP_BUTTON_T";
      goto LABEL_195;
    case 85:
      v4 = "$BUTTON_REMAP_BUTTON_U";
      goto LABEL_195;
    case 86:
      v4 = "$BUTTON_REMAP_BUTTON_V";
      goto LABEL_195;
    case 87:
      v4 = "$BUTTON_REMAP_BUTTON_W";
      goto LABEL_195;
    case 88:
      v4 = "$BUTTON_REMAP_BUTTON_X";
      goto LABEL_195;
    case 89:
      v4 = "$BUTTON_REMAP_BUTTON_Y";
      goto LABEL_195;
    case 90:
      v4 = "$BUTTON_REMAP_BUTTON_Z";
      goto LABEL_195;
    case 91:
      v4 = "$BUTTON_REMAP_LWIN";
      goto LABEL_195;
    case 92:
      v4 = "$BUTTON_REMAP_RWIN";
      goto LABEL_195;
    case 93:
      v4 = "$BUTTON_REMAP_APPS";
      goto LABEL_195;
    case 94:
      v4 = "$BUTTON_REMAP_NUMPAD_RETURN";
      goto LABEL_195;
    case 96:
      v4 = "$BUTTON_REMAP_NUMPAD0";
      goto LABEL_195;
    case 97:
      v4 = "$BUTTON_REMAP_NUMPAD1";
      goto LABEL_195;
    case 98:
      v4 = "$BUTTON_REMAP_NUMPAD2";
      goto LABEL_195;
    case 99:
      v4 = "$BUTTON_REMAP_NUMPAD3";
      goto LABEL_195;
    case 100:
      v4 = "$BUTTON_REMAP_NUMPAD4";
      goto LABEL_195;
    case 101:
      v4 = "$BUTTON_REMAP_NUMPAD5";
      goto LABEL_195;
    case 102:
      v4 = "$BUTTON_REMAP_NUMPAD6";
      goto LABEL_195;
    case 103:
      v4 = "$BUTTON_REMAP_NUMPAD7";
      goto LABEL_195;
    case 104:
      v4 = "$BUTTON_REMAP_NUMPAD8";
      goto LABEL_195;
    case 105:
      v4 = "$BUTTON_REMAP_NUMPAD9";
      goto LABEL_195;
    case 106:
      v4 = "$BUTTON_REMAP_MULTIPLY";
      goto LABEL_195;
    case 107:
      v4 = "$BUTTON_REMAP_ADD";
      goto LABEL_195;
    case 108:
      v4 = "$BUTTON_REMAP_SEPERATOR";
      goto LABEL_195;
    case 109:
      v4 = "$BUTTON_REMAP_SUBTRACT";
      goto LABEL_195;
    case 110:
      v4 = "$BUTTON_REMAP_DECIMAL";
      goto LABEL_195;
    case 111:
      v4 = "$BUTTON_REMAP_DIVIDE";
      goto LABEL_195;
    case 112:
      v4 = "$BUTTON_REMAP_F1";
      goto LABEL_195;
    case 113:
      v4 = "$BUTTON_REMAP_F2";
      goto LABEL_195;
    case 114:
      v4 = "$BUTTON_REMAP_F3";
      goto LABEL_195;
    case 115:
      v4 = "$BUTTON_REMAP_F4";
      goto LABEL_195;
    case 116:
      v4 = "$BUTTON_REMAP_F5";
      goto LABEL_195;
    case 117:
      v4 = "$BUTTON_REMAP_F6";
      goto LABEL_195;
    case 118:
      v4 = "$BUTTON_REMAP_F7";
      goto LABEL_195;
    case 119:
      v4 = "$BUTTON_REMAP_F8";
      goto LABEL_195;
    case 120:
      v4 = "$BUTTON_REMAP_F9";
      goto LABEL_195;
    case 121:
      v4 = "$BUTTON_REMAP_F10";
      goto LABEL_195;
    case 122:
      v4 = "$BUTTON_REMAP_F11";
      goto LABEL_195;
    case 123:
      v4 = "$BUTTON_REMAP_F12";
      goto LABEL_195;
    case 124:
      v4 = "$BUTTON_REMAP_F13";
      goto LABEL_195;
    case 125:
      v4 = "$BUTTON_REMAP_F14";
      goto LABEL_195;
    case 126:
      v4 = "$BUTTON_REMAP_F15";
      goto LABEL_195;
    case 127:
      v4 = "$BUTTON_REMAP_F16";
      goto LABEL_195;
    case 128:
      v4 = "$BUTTON_REMAP_F17";
      goto LABEL_195;
    case 129:
      v4 = "$BUTTON_REMAP_F18";
      goto LABEL_195;
    case 130:
      v4 = "$BUTTON_REMAP_F19";
      goto LABEL_195;
    case 131:
      v4 = "$BUTTON_REMAP_F20";
      goto LABEL_195;
    case 132:
      v4 = "$BUTTON_REMAP_F21";
      goto LABEL_195;
    case 133:
      v4 = "$BUTTON_REMAP_F22";
      goto LABEL_195;
    case 134:
      v4 = "$BUTTON_REMAP_F23";
      goto LABEL_195;
    case 135:
      v4 = "$BUTTON_REMAP_F24";
      goto LABEL_195;
    case 144:
      v4 = "$BUTTON_REMAP_NUMLOCK";
      goto LABEL_195;
    case 145:
      v4 = "$BUTTON_REMAP_SCROLL";
      goto LABEL_195;
    case 146:
      v4 = "$BUTTON_REMAP_OEM_NEC_EQUAL";
      goto LABEL_195;
    case 147:
      v4 = "$BUTTON_REMAP_OEM_FJ_MASSHOU";
      goto LABEL_195;
    case 148:
      v4 = "$BUTTON_REMAP_OEM_FJ_TOUROKU";
      goto LABEL_195;
    case 149:
      v4 = "$BUTTON_REMAP_OEM_FJ_LOYA";
      goto LABEL_195;
    case 150:
      v4 = "$BUTTON_REMAP_OEM_FJ_ROYA";
      goto LABEL_195;
    case 154:
      v4 = "$BUTTON_REMAP_MBUTTON_SCROLL_DOWN";
      goto LABEL_195;
    case 155:
      v4 = "$BUTTON_REMAP_MBUTTON_SCROLL_UP";
      goto LABEL_195;
    case 160:
      v4 = "$BUTTON_REMAP_LSHIFT";
      goto LABEL_195;
    case 161:
      v4 = "$BUTTON_REMAP_RSHIFT";
      goto LABEL_195;
    case 162:
      v4 = "$BUTTON_REMAP_LCONTROL";
      goto LABEL_195;
    case 163:
      v4 = "$BUTTON_REMAP_RCONTROL";
      goto LABEL_195;
    case 164:
      v4 = "$BUTTON_REMAP_LMENU";
      goto LABEL_195;
    case 165:
      v4 = "$BUTTON_REMAP_RMENU";
      goto LABEL_195;
    case 166:
      v4 = "$BUTTON_REMAP_BROWSER_BACK";
      goto LABEL_195;
    case 167:
      v4 = "$BUTTON_REMAP_BROWSER_FORWARD";
      goto LABEL_195;
    case 168:
      v4 = "$BUTTON_REMAP_BROWSER_REFRESH";
      goto LABEL_195;
    case 169:
      v4 = "$BUTTON_REMAP_BROWSER_STOP";
      goto LABEL_195;
    case 170:
      v4 = "$BUTTON_REMAP_BROWSER_SEARCH";
      goto LABEL_195;
    case 171:
      v4 = "$BUTTON_REMAP_BROWSER_FAVORITES";
      goto LABEL_195;
    case 172:
      v4 = "$BUTTON_REMAP_BROWSER_HOME";
      goto LABEL_195;
    case 173:
      v4 = "$BUTTON_REMAP_VOLUME_MUTE";
      goto LABEL_195;
    case 174:
      v4 = "$BUTTON_REMAP_VOLUME_DOWN";
      goto LABEL_195;
    case 175:
      v4 = "$BUTTON_REMAP_VOULME_UP";
      goto LABEL_195;
    case 176:
      v4 = "$BUTTON_REMAP_MEDIA_NEXT_TRACK";
      goto LABEL_195;
    case 177:
      v4 = "$BUTTON_REMAP_MEDIA_PREV_TRACK";
      goto LABEL_195;
    case 178:
      v4 = "$BUTTON_REMAP_MEDIA_STOP";
      goto LABEL_195;
    case 179:
      v4 = "$BUTTON_REMAP_MEDIA_PLAY_PAUSE";
      goto LABEL_195;
    case 180:
      v4 = "$BUTTON_REMAP_LAUNCH_MAIL";
      goto LABEL_195;
    case 181:
      v4 = "$BUTTON_REMAP_LAUNCH_MEDIA_SELECT";
      goto LABEL_195;
    case 182:
      v4 = "$BUTTON_REMAP_LAUNCH_APP1";
      goto LABEL_195;
    case 183:
      v4 = "$BUTTON_REMAP_LAUNCH_APP2";
      goto LABEL_195;
    case 186:
      v4 = "$BUTTON_REMAP_OEM_1";
      goto LABEL_195;
    case 187:
      v4 = "$BUTTON_REMAP_OEM_PLUS";
      goto LABEL_195;
    case 188:
      v4 = "$BUTTON_REMAP_OEM_COMMA";
      goto LABEL_195;
    case 189:
      v4 = "$BUTTON_REMAP_OEM_MINUS";
      goto LABEL_195;
    case 190:
      v4 = "$BUTTON_REMAP_OEM_PERIOD";
      goto LABEL_195;
    case 191:
      v4 = "$BUTTON_REMAP_OEM_2";
      goto LABEL_195;
    case 192:
      v4 = "$BUTTON_REMAP_OEM_3";
      goto LABEL_195;
    case 219:
      v4 = "$BUTTON_REMAP_OEM_4";
      goto LABEL_195;
    case 220:
      v4 = "$BUTTON_REMAP_OEM_5";
      goto LABEL_195;
    case 221:
      v4 = "$BUTTON_REMAP_OEM_6";
      goto LABEL_195;
    case 222:
      v4 = "$BUTTON_REMAP_OEM_7";
      goto LABEL_195;
    case 223:
      v4 = "$BUTTON_REMAP_OEM_8";
      goto LABEL_195;
    case 225:
      v4 = "$BUTTON_REMAP_OEM_AX";
      goto LABEL_195;
    case 226:
      v4 = "$BUTTON_REMAP_OEM_102";
      goto LABEL_195;
    case 227:
      v4 = "$BUTTON_REMAP_OEM_ICO_HELP";
      goto LABEL_195;
    case 228:
      v4 = "$BUTTON_REMAP_OEM_ICO_00";
      goto LABEL_195;
    case 229:
      v4 = "$BUTTON_REMAP_OEM_PROCESSKEY";
      goto LABEL_195;
    case 230:
      v4 = "$BUTTON_REMAP_OEM_ICO_CLEAR";
      goto LABEL_195;
    case 233:
      v4 = "$BUTTON_REMAP_OEM_RESET";
      goto LABEL_195;
    case 234:
      v4 = "$BUTTON_REMAP_OEM_JUMP";
      goto LABEL_195;
    case 235:
      v4 = "$BUTTON_REMAP_OEM_PA1";
      goto LABEL_195;
    case 236:
      v4 = "$BUTTON_REMAP_OEM_PA2";
      goto LABEL_195;
    case 237:
      v4 = "$BUTTON_REMAP_OEM_PA3";
      goto LABEL_195;
    case 238:
      v4 = "$BUTTON_REMAP_OEM_WSCTRL";
      goto LABEL_195;
    case 239:
      v4 = "$BUTTON_REMAP_OEM_CUSEL";
      goto LABEL_195;
    case 240:
      v4 = "$BUTTON_REMAP_OEM_ATTN";
      goto LABEL_195;
    case 241:
      v4 = "$BUTTON_REMAP_OEM_FINNISH";
      goto LABEL_195;
    case 242:
      v4 = "$BUTTON_REMAP_OEM_COPY";
      goto LABEL_195;
    case 243:
      v4 = "$BUTTON_REMAP_OEM_AUTO";
      goto LABEL_195;
    case 244:
      v4 = "$BUTTON_REMAP_OEM_ENLW";
      goto LABEL_195;
    case 245:
      v4 = "$BUTTON_REMAP_OEM_BACKTAB";
      goto LABEL_195;
    case 246:
      v4 = "$BUTTON_REMAP_ATTN";
      goto LABEL_195;
    case 247:
      v4 = "$BUTTON_REMAP_CRSEL";
      goto LABEL_195;
    case 248:
      v4 = "$BUTTON_REMAP_EXCEL";
      goto LABEL_195;
    case 249:
      v4 = "$BUTTON_REMAP_EREOF";
      goto LABEL_195;
    case 250:
      v4 = "$BUTTON_REMAP_PLAY";
      goto LABEL_195;
    case 251:
      v4 = "$BUTTON_REMAP_ZOOM";
      goto LABEL_195;
    case 252:
      v4 = "$BUTTON_REMAP_NONAME";
      goto LABEL_195;
    case 253:
      v4 = "$BUTTON_REMAP_PA1";
      goto LABEL_195;
    case 254:
      v4 = "$BUTTON_REMAP_OEM_CLEAR";
LABEL_195:
      UFG::qString::Set(v3, v4);
      break;
    default:
      break;
  }
  UFG::qString::MakeUpper(v3);
}

// File Line: 610
// RVA: 0x5EFD00
const char *__fastcall UFG::KeyToTextureName(char key)
{
  const char *v1; // rdx
  const char *result; // rax

  v1 = &customWorldMapCaption;
  switch ( key )
  {
    case 1:
      result = "BUTTON_MOUSE_L";
      break;
    case 2:
      result = "BUTTON_MOUSE_R";
      break;
    case 4:
      result = "BUTTON_MOUSE_M";
      break;
    case 5:
      result = "BUTTON_MOUSE4";
      break;
    case 6:
      result = "BUTTON_MOUSE5";
      break;
    case 8:
      result = "BUTTON_BACKSPACE";
      break;
    case 9:
      result = "BUTTON_TAB";
      break;
    case 0xD:
      result = "BUTTON_ENTER";
      break;
    case 0x10:
      result = "BUTTON_SHIFT";
      break;
    case 0x11:
      result = "BUTTON_CTRL";
      break;
    case 0x12:
      result = "BUTTON_ALT";
      break;
    case 0x20:
      result = "BUTTON_SPACE";
      break;
    case 0x21:
      result = "BUTTON_PAGEUP";
      break;
    case 0x22:
      result = "BUTTON_PAGEDOWN";
      break;
    case 0x23:
      result = "BUTTON_END";
      break;
    case 0x24:
      result = "BUTTON_HOME";
      break;
    case 0x25:
      result = "BUTTON_ARROW_L";
      break;
    case 0x26:
      result = "BUTTON_ARROW_U";
      break;
    case 0x27:
      result = "BUTTON_ARROW_R";
      break;
    case 0x28:
      result = "BUTTON_ARROW_D";
      break;
    case 0x2D:
      result = "BUTTON_INSERT";
      break;
    case 0x2E:
      result = "BUTTON_DELETE";
      break;
    case 0x30:
      result = "BUTTON_ZERO";
      break;
    case 0x31:
      result = "BUTTON_ONE";
      break;
    case 0x32:
      result = "BUTTON_TWO";
      break;
    case 0x33:
      result = "BUTTON_THREE";
      break;
    case 0x34:
      result = "BUTTON_FOUR";
      break;
    case 0x35:
      result = "BUTTON_FIVE";
      break;
    case 0x36:
      result = "BUTTON_SIX";
      break;
    case 0x37:
      result = "BUTTON_SEVEN";
      break;
    case 0x38:
      result = "BUTTON_EIGHT";
      break;
    case 0x39:
      result = "BUTTON_NINE";
      break;
    case 0x41:
      result = "BUTTON_A";
      break;
    case 0x42:
      result = "BUTTON_B";
      break;
    case 0x43:
      result = "BUTTON_C";
      break;
    case 0x44:
      result = "BUTTON_D";
      break;
    case 0x45:
      result = "BUTTON_E";
      break;
    case 0x46:
      result = "BUTTON_F";
      break;
    case 0x47:
      result = "BUTTON_G";
      break;
    case 0x48:
      result = "BUTTON_H";
      break;
    case 0x49:
      result = "BUTTON_I";
      break;
    case 0x4A:
      result = "BUTTON_J";
      break;
    case 0x4B:
      result = "BUTTON_K";
      break;
    case 0x4C:
      result = "BUTTON_L";
      break;
    case 0x4D:
      result = "BUTTON_M";
      break;
    case 0x4E:
      result = "BUTTON_N";
      break;
    case 0x4F:
      result = "BUTTON_O";
      break;
    case 0x50:
      result = "BUTTON_P";
      break;
    case 0x51:
      result = "BUTTON_Q";
      break;
    case 0x52:
      result = "BUTTON_R";
      break;
    case 0x53:
      result = "BUTTON_S";
      break;
    case 0x54:
      result = "BUTTON_T";
      break;
    case 0x55:
      result = "BUTTON_U";
      break;
    case 0x56:
      result = "BUTTON_V";
      break;
    case 0x57:
      result = "BUTTON_W";
      break;
    case 0x58:
      result = "BUTTON_X";
      break;
    case 0x59:
      result = "BUTTON_Y";
      break;
    case 0x5A:
      result = "BUTTON_Z";
      break;
    case 0x5E:
      result = "BUTTON_NUMENTER";
      break;
    case 0x60:
      result = "BUTTON_NUMZERO";
      break;
    case 0x61:
      result = "BUTTON_NUMONE";
      break;
    case 0x62:
      result = "BUTTON_NUMTWO";
      break;
    case 0x63:
      result = "BUTTON_NUMTHREE";
      break;
    case 0x64:
      result = "BUTTON_NUMFOUR";
      break;
    case 0x65:
      result = "BUTTON_NUMFIVE";
      break;
    case 0x66:
      result = "BUTTON_NUMSIX";
      break;
    case 0x67:
      result = "BUTTON_NUMSEVEN";
      break;
    case 0x68:
      result = "BUTTON_NUMEIGHT";
      break;
    case 0x69:
      result = "BUTTON_NUMNINE";
      break;
    case 0x6A:
      result = "BUTTON_NUMSTAR";
      break;
    case 0x6B:
      result = "BUTTON_NUMPLUS";
      break;
    case 0x6D:
      result = "BUTTON_NUMDASH";
      break;
    case 0x6E:
      result = "BUTTON_NUMDEL";
      break;
    case 0x6F:
      result = "BUTTON_NUMSLASH";
      break;
    case 0x70:
      result = "BUTTON_F1";
      break;
    case 0x71:
      result = "BUTTON_F2";
      break;
    case 0x72:
      result = "BUTTON_F3";
      break;
    case 0x73:
      result = "BUTTON_F4";
      break;
    case 0x74:
      result = "BUTTON_F5";
      break;
    case 0x75:
      result = "BUTTON_F6";
      break;
    case 0x76:
      result = "BUTTON_F7";
      break;
    case 0x77:
      result = "BUTTON_F8";
      break;
    case 0x78:
      result = "BUTTON_F9";
      break;
    case 0x79:
      result = "BUTTON_F10";
      break;
    case 0x7A:
      result = "BUTTON_F11";
      break;
    case 0x7B:
      result = "BUTTON_F12";
      break;
    case 0x7C:
      result = "BUTTON_F13";
      break;
    case 0x7D:
      result = "BUTTON_F14";
      break;
    case 0x7E:
      result = "BUTTON_F15";
      break;
    case 0x7F:
      result = "BUTTON_F16";
      break;
    case 0x80:
      result = "BUTTON_F17";
      break;
    case 0x81:
      result = "BUTTON_F18";
      break;
    case 0x82:
      result = "BUTTON_F19";
      break;
    case 0x83:
      result = "BUTTON_F20";
      break;
    case 0x84:
      result = "BUTTON_F21";
      break;
    case 0x85:
      result = "BUTTON_F22";
      break;
    case 0x86:
      result = "BUTTON_F23";
      break;
    case 0x87:
      v1 = "BUTTON_F24";
      goto LABEL_118;
    case 0x90:
      result = "BUTTON_NUMLOCK";
      break;
    case 0xA0:
      result = "BUTTON_LSHIFT";
      break;
    case 0xA1:
      result = "BUTTON_RSHIFT";
      break;
    case 0xA2:
      result = "BUTTON_LCTRL";
      break;
    case 0xA3:
      result = "BUTTON_RCTRL";
      break;
    case 0xA4:
      result = "BUTTON_LALT";
      break;
    case 0xA5:
      result = "BUTTON_RALT";
      break;
    case 0xBA:
      result = "BUTTON_SEMICOLON";
      break;
    case 0xBB:
      result = "BUTTON_EQUALES";
      break;
    case 0xBC:
      result = "BUTTON_COMMA";
      break;
    case 0xBD:
      result = "BUTTON_DASH";
      break;
    case 0xBE:
      result = "BUTTON_PERIOD";
      break;
    case 0xBF:
      result = "BUTTON_SLASH";
      break;
    case 0xC0:
      result = "BUTTON_TILDE";
      break;
    case 0xDB:
      result = "BUTTON_LSB";
      break;
    case 0xDC:
      result = "BUTTON_BACKSLASH";
      break;
    case 0xDD:
      result = "BUTTON_RSB";
      break;
    case 0xDE:
      result = "BUTTON_APOSTROPHE";
      break;
    default:
LABEL_118:
      result = v1;
      break;
  }
  return result;
}

