// File Line: 13
// RVA: 0x12BC3DC
char *__fastcall strtok_s(char *_String, const char *_Control, char **_Context)
{
  const char *v3; // rbx
  char *v4; // r10
  __int64 v6; // rax
  bool v7; // cf
  unsigned int v8; // r9d
  char *v9; // r9
  char v10[32]; // [rsp+20h] [rbp-38h]

  v3 = _Control;
  v4 = _String;
  if ( _Context && _Control && (_String || *_Context) )
  {
    v6 = 0i64;
    v7 = 1;
    do
    {
      if ( !v7 )
      {
        _report_rangecheckfailure();
        JUMPOUT(0x1412BC4F6i64);
      }
      v10[v6++] = 0;
      v7 = (unsigned __int64)v6 < 0x20;
    }
    while ( v6 < 32 );
    do
    {
      v8 = *(unsigned __int8 *)v3++;
      v10[(unsigned __int64)v8 >> 3] |= 1 << (v8 & 7);
    }
    while ( (_BYTE)v8 );
    if ( !_String )
      v4 = *_Context;
    while ( ((unsigned __int8)(1 << (*v4 & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*v4 >> 3]) != 0
         && *v4 )
      ++v4;
    v9 = v4;
    while ( *v4 )
    {
      if ( ((unsigned __int8)(1 << (*v4 & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*v4 >> 3]) != 0 )
      {
        *v4++ = 0;
        break;
      }
      ++v4;
    }
    *_Context = v4;
    if ( v9 == v4 )
      return 0i64;
    return v9;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
}

