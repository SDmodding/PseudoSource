// File Line: 52
// RVA: 0x12DC088
int __fastcall mbsnbicmp_l(const char *s1, const char *s2, unsigned __int64 n, localeinfo_struct *plocinfo)
{
  const char *v4; // rsi
  const char *v5; // rdi
  unsigned __int64 v6; // rbx
  int result; // eax
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 v10; // rdx
  __int16 v11; // ax
  __int16 v12; // ax
  __int64 v13; // [rsp+20h] [rbp-28h]
  __int64 v14; // [rsp+28h] [rbp-20h]
  __int64 v15; // [rsp+30h] [rbp-18h]
  char v16; // [rsp+38h] [rbp-10h]

  v4 = s1;
  v5 = s2;
  v6 = n;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v13, plocinfo);
  if ( !v6 )
  {
LABEL_37:
    result = 0;
    goto LABEL_39;
  }
  if ( !*(_DWORD *)(v14 + 8) )
  {
    result = strnicmp(v4, v5, v6);
    goto LABEL_39;
  }
  if ( !v4 || !v5 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0x7FFFFFFF;
    goto LABEL_39;
  }
  while ( 1 )
  {
    v8 = *(unsigned __int8 *)v4;
    --v6;
    ++v4;
    if ( !(*(_BYTE *)(v8 + v14 + 25) & 4) )
    {
      if ( *(_BYTE *)((unsigned __int16)v8 + v14 + 25) & 0x10 )
        LOWORD(v8) = *(unsigned __int8 *)((unsigned __int16)v8 + v14 + 281);
      goto LABEL_21;
    }
    if ( v6 )
    {
      if ( *v4 )
      {
        v11 = *(unsigned __int8 *)v4++;
        LOWORD(v8) = v11 | ((_WORD)v8 << 8);
        if ( (unsigned __int16)v8 < *(_WORD *)(v14 + 12) || (unsigned __int16)v8 > *(_WORD *)(v14 + 14) )
        {
          if ( (unsigned __int16)v8 >= *(_WORD *)(v14 + 18) && (unsigned __int16)v8 <= *(_WORD *)(v14 + 20) )
            LOWORD(v8) = *(_WORD *)(v14 + 22) + v8;
        }
        else
        {
          LOWORD(v8) = *(_WORD *)(v14 + 16) + v8;
        }
      }
      else
      {
        LOWORD(v8) = 0;
      }
LABEL_21:
      v10 = *(unsigned __int8 *)v5++;
      if ( *(_BYTE *)(v10 + v14 + 25) & 4 )
      {
        if ( v6 )
        {
          --v6;
          if ( *v5 )
          {
            v12 = *(unsigned __int8 *)v5++;
            LOWORD(v10) = v12 | ((_WORD)v10 << 8);
            if ( (unsigned __int16)v10 < *(_WORD *)(v14 + 12) || (unsigned __int16)v10 > *(_WORD *)(v14 + 14) )
            {
              if ( (unsigned __int16)v10 >= *(_WORD *)(v14 + 18) && (unsigned __int16)v10 <= *(_WORD *)(v14 + 20) )
                LOWORD(v10) = *(_WORD *)(v14 + 22) + v10;
            }
            else
            {
              LOWORD(v10) = *(_WORD *)(v14 + 16) + v10;
            }
          }
          else
          {
            LOWORD(v10) = 0;
          }
        }
        else
        {
          LOWORD(v10) = 0;
        }
      }
      else if ( *(_BYTE *)((unsigned __int16)v10 + v14 + 25) & 0x10 )
      {
        LOWORD(v10) = *(unsigned __int8 *)((unsigned __int16)v10 + v14 + 281);
      }
      goto $test_0;
    }
    v9 = *(unsigned __int8 *)v5;
    LOWORD(v8) = 0;
    if ( *(_BYTE *)(v9 + v14 + 25) & 4 )
      goto LABEL_37;
    LOWORD(v10) = *(unsigned __int8 *)v5;
$test_0:
    if ( (_WORD)v10 != (_WORD)v8 )
      break;
    if ( !(_WORD)v8 || !v6 )
      goto LABEL_37;
  }
  result = (unsigned __int16)v10 < (unsigned __int16)v8 ? 1 : -1;
LABEL_39:
  if ( v16 )
    *(_DWORD *)(v15 + 200) &= 0xFFFFFFFD;
  return result;
}

// File Line: 134
// RVA: 0x12DC080
int __fastcall mbsnbicmp(const char *s1, const char *s2, unsigned __int64 n)
{
  return mbsnbicmp_l(s1, s2, n, 0i64);
}

