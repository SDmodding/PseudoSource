// File Line: 46
// RVA: 0x12BB730
size_t __cdecl strlen(const char *Str)
{
  const char *v1; // rax
  __int64 v2; // rcx
  __int64 v4; // rdx
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rdx
  unsigned int v8; // edx

  v1 = Str;
  v2 = -(__int64)Str;
  if ( ((unsigned __int8)v1 & 7) == 0 )
    goto main_loop_begin;
  do
  {
    if ( !*v1++ )
      return (size_t)&v1[v2 - 1];
  }
  while ( ((unsigned __int8)v1 & 7) != 0 );
  while ( 1 )
  {
    do
    {
main_loop_begin:
      v4 = *(_QWORD *)v1;
      v1 += 8;
    }
    while ( (((v4 + 0x7EFEFEFEFEFEFEFFi64) ^ ~v4) & 0x8101010101010100ui64) == 0 );
    v5 = *((_QWORD *)v1 - 1);
    if ( !(_BYTE)v5 )
      break;
    if ( !BYTE1(v5) )
      return (size_t)&v1[v2 - 7];
    v6 = v5 >> 16;
    if ( !(_BYTE)v6 )
      return (size_t)&v1[v2 - 6];
    if ( !BYTE1(v6) )
      return (size_t)&v1[v2 - 5];
    v7 = v6 >> 16;
    if ( !(_BYTE)v7 )
      return (size_t)&v1[v2 - 4];
    if ( !BYTE1(v7) )
      return (size_t)&v1[v2 - 3];
    v8 = WORD1(v7);
    if ( !(_BYTE)v8 )
      return (size_t)&v1[v2 - 2];
    if ( !BYTE1(v8) )
      return (size_t)&v1[v2 - 1];
  }
  return (size_t)&v1[v2 - 8];
}

