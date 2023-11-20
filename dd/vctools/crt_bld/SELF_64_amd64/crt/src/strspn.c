// File Line: 111
// RVA: 0x12B114C
unsigned __int64 __fastcall strcspn(const char *string, const char *control)
{
  int v2; // er9
  const char *v3; // r10
  const char *v4; // r11
  signed __int64 v5; // rax
  bool v6; // cf
  unsigned __int8 i; // al
  char v9[32]; // [rsp+20h] [rbp-38h]

  v2 = 0;
  v3 = control;
  v4 = string;
  v5 = 0i64;
  v6 = 1;
  do
  {
    if ( !v6 )
    {
      _report_rangecheckfailure(string);
      __debugbreak();
      JUMPOUT(*(_QWORD *)strpbrk);
    }
    v9[v5++] = 0;
    v6 = (unsigned __int64)v5 < 0x20;
  }
  while ( v5 < 32 );
  for ( i = *control; i; i = *v3 )
  {
    v9[(unsigned __int64)i >> 3] |= 1 << (i & 7);
    ++v3;
  }
  v9[0] |= 1u;
  while ( !((unsigned __int8)(1 << (*v4 & 7)) & (unsigned __int8)v9[(unsigned __int64)*(unsigned __int8 *)v4 >> 3]) )
  {
    ++v2;
    ++v4;
  }
  return v2;
}

