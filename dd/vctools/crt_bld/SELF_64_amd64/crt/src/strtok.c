// File Line: 67
// RVA: 0x12C3398
char *__fastcall strtok(char *string, const char *control)
{
  const char *v2; // rdi
  char *v3; // rbx
  _tiddata *v4; // rax
  signed __int64 v5; // rcx
  bool v6; // cf
  unsigned int v7; // er9
  char *v8; // r9
  char v10[32]; // [rsp+20h] [rbp-38h]

  v2 = control;
  v3 = string;
  v4 = getptd();
  v5 = 0i64;
  v6 = 1;
  do
  {
    if ( !v6 )
    {
      _report_rangecheckfailure();
      __debugbreak();
      JUMPOUT(*(_QWORD *)_wdtoxmode);
    }
    v10[v5++] = 0;
    v6 = (unsigned __int64)v5 < 0x20;
  }
  while ( v5 < 32 );
  do
  {
    v7 = *(unsigned __int8 *)v2++;
    v10[(unsigned __int64)v7 >> 3] |= 1 << (v7 & 7);
  }
  while ( (_BYTE)v7 );
  if ( !v3 )
    v3 = v4->_token;
  while ( (unsigned __int8)(1 << (*v3 & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*v3 >> 3] && *v3 )
    ++v3;
  v8 = v3;
  while ( *v3 )
  {
    if ( (unsigned __int8)(1 << (*v3 & 7)) & (unsigned __int8)v10[(unsigned __int64)(unsigned __int8)*v3 >> 3] )
    {
      *v3++ = 0;
      break;
    }
    ++v3;
  }
  v4->_token = v3;
  if ( v8 == v3 )
    v8 = 0i64;
  return v8;
}

