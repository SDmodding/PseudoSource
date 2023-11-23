// File Line: 77
// RVA: 0x12BBF60
char *__fastcall bsearch(
        const void *key,
        char *base,
        unsigned __int64 num,
        unsigned __int64 width,
        int (__fastcall *compare)(const void *, const void *))
{
  unsigned __int64 v6; // rsi
  char *v7; // rbx
  char *v9; // rdi
  unsigned __int64 v11; // rbp
  bool v12; // zf
  char *v13; // r14
  int v14; // eax

  v6 = num;
  v7 = base;
  v9 = &base[width * (num - 1)];
  if ( !base && num || !width || !compare )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  if ( base > v9 )
    return 0i64;
  while ( 1 )
  {
    v11 = v6 >> 1;
    if ( !(v6 >> 1) )
      break;
    v12 = (v6 & 1) == 0;
    v6 = v11 - 1;
    if ( !v12 )
      v6 = v11;
    v13 = &v7[width * v6];
    v14 = compare(key, v13);
    if ( !v14 )
      return &v7[width * v6];
    if ( v14 >= 0 )
    {
      v7 = &v13[width];
      v6 = v11;
    }
    else
    {
      v9 = &v13[-width];
    }
    if ( v7 > v9 )
      return 0i64;
  }
  if ( !v6 )
    return 0i64;
  if ( compare(key, v7) )
    return 0i64;
  return v7;
}

