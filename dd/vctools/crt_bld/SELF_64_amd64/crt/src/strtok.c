// File Line: 67
// RVA: 0x12C3398
char *__fastcall strtok(char *string, const char *control)
{
  _tiddata *v4; // rax
  __int64 v5; // rcx
  bool v6; // cf
  unsigned int v7; // r9d
  char *v8; // r9
  char v10[32]; // [rsp+20h] [rbp-38h]

  v4 = getptd();
  v5 = 0i64;
  v6 = 1;
  do
  {
    if ( !v6 )
    {
      _report_rangecheckfailure();
      __debugbreak();
    }
    v10[v5++] = 0;
    v6 = (unsigned __int64)v5 < 0x20;
  }
  while ( v5 < 32 );
  do
  {
    v7 = *(unsigned __int8 *)control++;
    v10[(unsigned __int64)v7 >> 3] |= 1 << (v7 & 7);
  }
  while ( (_BYTE)v7 );
  if ( !string )
    string = v4->_token;
  while ( ((unsigned __int8)(1 << (*string & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*string >> 3]) != 0
       && *string )
    ++string;
  v8 = string;
  while ( *string )
  {
    if ( ((unsigned __int8)(1 << (*string & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*string >> 3]) != 0 )
    {
      *string++ = 0;
      break;
    }
    ++string;
  }
  v4->_token = string;
  if ( v8 == string )
    return 0i64;
  return v8;
}

