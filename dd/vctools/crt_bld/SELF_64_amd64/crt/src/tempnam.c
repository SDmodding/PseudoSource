// File Line: 92
// RVA: 0x12BE410
char *__fastcall tempnam(char *dir, char *pfx)
{
  unsigned int v4; // r12d
  int v6; // eax
  unsigned __int64 v7; // r14
  char *v8; // rax
  char *v9; // rbx
  const char *v10; // r15
  char *v11; // rdi
  int v12; // r15d
  int v13; // esi
  unsigned int v14; // ecx
  char *pBuffer; // [rsp+60h] [rbp+18h] BYREF

  v4 = 0;
  pBuffer = 0i64;
  if ( !mtinitlocknum(2) )
    return 0i64;
  dupenv_s(&pBuffer, 0i64, "TMP");
  if ( v6 == 22 )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( v6 || !pBuffer || access_s(pBuffer, 0) )
  {
    if ( !dir || access_s(dir, 0) )
    {
      dir = "\\";
      if ( access_s("\\", 0) )
        dir = ".";
    }
  }
  else
  {
    dir = pBuffer;
  }
  if ( pfx )
    v4 = strlen(pfx);
  v7 = v4 + (unsigned int)strlen(dir) + 12;
  v8 = (char *)calloc(v7, 1ui64);
  v9 = v8;
  if ( v8 )
  {
    *v8 = 0;
    if ( (unsigned int)strcat_s(v8, (unsigned int)v7, dir) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    v10 = &dir[strlen(dir) - 1];
    if ( *v10 == 92 )
    {
      if ( v10 != mbsrchr(dir, 0x5Cu) && (unsigned int)strcat_s(v9, (unsigned int)v7, "\\") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
    }
    else if ( *v10 != 47 && (unsigned int)strcat_s(v9, v7, "\\") )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    if ( pfx && (unsigned int)strcat_s(v9, v7, pfx) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    v11 = &v9[strlen(v9)];
    lock(2);
    v12 = tempoff;
    if ( old_pfxlen < v4 )
      v12 = 1;
    tempoff = v12;
    old_pfxlen = v4;
    v13 = *errno();
    while ( 1 )
    {
      v14 = tempoff + 1;
      tempoff = v14;
      if ( v14 - v12 > 0x7FFFFFFF )
        break;
      if ( ultoa_s(v14, v11, (unsigned __int64)&v9[v7 - (_QWORD)v11], 0xAu) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        break;
      }
      *errno() = 0;
      if ( access_s(v9, 0) && *errno() != 13 )
      {
        *errno() = v13;
        goto $done1;
      }
    }
    *errno() = v13;
    free(v9);
    v9 = 0i64;
$done1:
    unlock(2);
  }
  free(pBuffer);
  free(0i64);
  return v9;
}

// File Line: 218
// RVA: 0x1451E8A
_tempnam$fin$0

