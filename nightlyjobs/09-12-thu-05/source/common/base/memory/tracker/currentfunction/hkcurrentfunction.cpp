// File Line: 222
// RVA: 0x13094A0
void __fastcall hkGetMsvcClassName(const char *type, char *typeOut)
{
  char *v2; // rsi
  const char *v3; // rdi
  const char *i; // rbx
  signed __int64 v5; // rbx

  v2 = typeOut;
  v3 = type;
  for ( i = &type[(signed int)hkString::strLen(type) - 1]; i >= v3; --i )
  {
    if ( *i == 58 )
      break;
  }
  v5 = (signed __int64)(i - 1);
  hkString::strNcpy(v2, v3, v5 - (_DWORD)v3);
  v2[v5 - (_QWORD)v3] = 0;
}

// File Line: 269
// RVA: 0x1309490
void __fastcall hkCurrentFunctionUtil::getClassName(const char *methodText, char *className)
{
  hkGetMsvcClassName(methodText, className);
}

