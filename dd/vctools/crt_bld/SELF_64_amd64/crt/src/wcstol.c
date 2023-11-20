// File Line: 81
// RVA: 0x12DD3C8
__int64 __fastcall wcstoxl(const wchar_t *nptr, const wchar_t **endptr, int ibase, int flags)
{
  int v4; // ebp
  unsigned int v5; // er14
  const wchar_t **v6; // r15
  unsigned __int16 v8; // si
  unsigned int v9; // edi
  const wchar_t *v10; // rbx
  unsigned int v11; // er13
  unsigned int v12; // eax
  int v13; // eax
  signed __int64 v14; // rbx
  const wchar_t *v15; // [rsp+60h] [rbp+8h]

  v15 = nptr;
  v4 = flags;
  v5 = ibase;
  v6 = endptr;
  if ( endptr )
    *endptr = nptr;
  if ( !nptr || ibase && (unsigned int)(ibase - 2) > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v8 = *nptr;
  v9 = 0;
  v10 = nptr + 1;
  while ( (unsigned int)iswctype(v8, 8u) )
  {
    v8 = *v10;
    ++v10;
  }
  if ( v8 == 45 )
  {
    v4 |= 2u;
  }
  else if ( v8 != 43 )
  {
    goto LABEL_14;
  }
  v8 = *v10;
  ++v10;
LABEL_14:
  if ( v5 )
    goto LABEL_20;
  if ( !wchartodigit(v8) )
  {
    if ( (*v10 - 88) & 0xFFDF )
    {
      v5 = 8;
      goto LABEL_24;
    }
    v5 = 16;
LABEL_20:
    if ( v5 == 16 && !wchartodigit(v8) && !((*v10 - 88) & 0xFFDF) )
    {
      v8 = v10[1];
      v10 += 2;
    }
    goto LABEL_24;
  }
  v5 = 10;
LABEL_24:
  v11 = 0xFFFFFFFF / v5;
  while ( 1 )
  {
    v12 = wchartodigit(v8);
    if ( v12 != -1 )
      goto LABEL_31;
    if ( (unsigned __int16)(v8 - 65) > 0x19u && (unsigned __int16)(v8 - 97) > 0x19u )
      break;
    v13 = v8;
    if ( (unsigned __int16)(v8 - 97) <= 0x19u )
      v13 = v8 - 32;
    v12 = v13 - 55;
LABEL_31:
    if ( v12 >= v5 )
      break;
    v4 |= 8u;
    if ( v9 < v11 || v9 == v11 && v12 <= 0xFFFFFFFF % v5 )
    {
      v9 = v12 + v5 * v9;
    }
    else
    {
      v4 |= 4u;
      if ( !v6 )
        break;
    }
    v8 = *v10;
    ++v10;
  }
  v14 = (signed __int64)(v10 - 1);
  if ( v4 & 8 )
  {
    if ( v4 & 4 || !(v4 & 1) && (v4 & 2 && v9 > 0x80000000 || !(v4 & 2) && v9 > 0x7FFFFFFF) )
    {
      *errno() = 34;
      if ( v4 & 1 )
        v9 = -1;
      else
        v9 = ((v4 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( v6 )
      v14 = (signed __int64)v15;
    v9 = 0;
  }
  if ( v6 )
    *v6 = (const wchar_t *)v14;
  if ( v4 & 2 )
    v9 = -v9;
  return v9;
}

// File Line: 214
// RVA: 0x12DD5B0
__int64 __fastcall wcstol(const wchar_t *nptr, wchar_t **endptr, int ibase)
{
  return wcstoxl(nptr, (const wchar_t **)endptr, ibase, 0);
}

