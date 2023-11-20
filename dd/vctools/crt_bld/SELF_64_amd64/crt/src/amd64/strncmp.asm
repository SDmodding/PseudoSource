// File Line: 55
// RVA: 0x12B1900
int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  signed __int64 v3; // rdx
  unsigned __int8 v4; // al
  __int64 v5; // rax
  bool v6; // cf
  signed __int64 v7; // rax

  v3 = Str2 - Str1;
  if ( MaxCount )
  {
    if ( (unsigned __int8)Str1 & 7 )
      goto comp_head_loop_begin;
LABEL_7:
    while ( (((_WORD)Str1 + (_WORD)v3) & 0xFFFu) <= 0xFF8 )
    {
      v5 = *(_QWORD *)Str1;
      if ( *(_QWORD *)Str1 != *(_QWORD *)&Str1[v3] )
        break;
      Str1 += 8;
      v6 = MaxCount < 8;
      MaxCount -= 8i64;
      if ( v6 || MaxCount == 0 || (v5 - 72340172838076673i64) & ~v5 & 0x8080808080808080ui64 )
        goto return_equal;
    }
comp_head_loop_begin:
    while ( 1 )
    {
      v4 = *Str1;
      if ( *Str1 != Str1[v3] )
        break;
      ++Str1;
      if ( !--MaxCount || !v4 )
        goto return_equal;
      if ( !((unsigned __int8)Str1 & 7) )
        goto LABEL_7;
    }
    v7 = -(signed __int64)(v4 < Str1[v3]) | 1;
  }
  else
  {
return_equal:
    LODWORD(v7) = 0;
  }
  return v7;
}

