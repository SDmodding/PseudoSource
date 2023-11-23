// File Line: 222
// RVA: 0x13094A0
void __fastcall hkGetMsvcClassName(const char *type, char *typeOut)
{
  const char *i; // rbx
  const char *v5; // rbx

  for ( i = &type[(int)hkString::strLen(type) - 1]; i >= type; --i )
  {
    if ( *i == 58 )
      break;
  }
  v5 = i - 1;
  hkString::strNcpy(typeOut, type, (_DWORD)v5 - (_DWORD)type);
  typeOut[v5 - type] = 0;
}

// File Line: 269
// RVA: 0x1309490
// attributes: thunk
void __fastcall hkCurrentFunctionUtil::getClassName(const char *methodText, char *className)
{
  hkGetMsvcClassName(methodText, className);
}

