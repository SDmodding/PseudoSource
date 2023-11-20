// File Line: 70
// RVA: 0x12B20E0
int __cdecl strcmp(const char *Str1, const char *Str2)
{
  signed __int64 v2; // rdx
  unsigned __int8 v3; // al
  __int64 v4; // rax
  signed __int64 v5; // rax

  v2 = Str2 - Str1;
  if ( (unsigned __int8)Str1 & 7 )
  {
comp_head_loop_begin_0:
    while ( 1 )
    {
      v3 = *Str1;
      if ( *Str1 != Str1[v2] )
        break;
      ++Str1;
      if ( !v3 )
        goto return_equal_0;
      if ( !((unsigned __int8)Str1 & 7) )
        goto LABEL_5;
    }
    v5 = -(signed __int64)(v3 < Str1[v2]) | 1;
  }
  else
  {
    do
    {
LABEL_5:
      if ( (((_WORD)Str1 + (_WORD)v2) & 0xFFFu) > 0xFF8 )
        goto comp_head_loop_begin_0;
      v4 = *(_QWORD *)Str1;
      if ( *(_QWORD *)Str1 != *(_QWORD *)&Str1[v2] )
        goto comp_head_loop_begin_0;
      Str1 += 8;
    }
    while ( !((v4 - 72340172838076673i64) & ~v4 & 0x8080808080808080ui64) );
return_equal_0:
    LODWORD(v5) = 0;
  }
  return v5;
}

