// File Line: 152
// RVA: 0xBB5B20
signed __int64 __fastcall hkaProcessFlyingColors(hkBool *flyingColors)
{
  hkBool *v1; // r14
  int v2; // er9
  int v3; // ebx
  int v4; // eax
  const char *v5; // rcx
  char v6; // dl
  char v7; // al
  char v8; // dl
  int v9; // eax
  char *i; // rcx
  char v11; // dl
  const char *v12; // rax
  signed __int64 result; // rax
  _BYTE *v14; // rax
  _BYTE *v15; // r8
  __int64 v16; // rsi
  __int64 v17; // rdi
  int v18; // edx
  int v19; // ecx

  flyingColors->m_bool = 0;
  v1 = flyingColors;
  if ( HK_ANIMATION_KEYCODE[0] != 48 )
    goto LABEL_37;
  v2 = -1;
  v3 = -1;
  v4 = 2;
  v5 = "ba5602f-0x209c7f74:2015-06-04.Animation.SquareEnix_UnitedFrontGames_SleepingDogsHD_PS4-XboxOne";
  do
  {
    v6 = *v5;
    v3 = v4 + 16 * v3;
    if ( (unsigned __int8)(*v5 - 48) > 9u )
    {
      if ( (unsigned __int8)(v6 - 65) > 5u )
      {
        if ( (unsigned __int8)(v6 - 97) > 5u )
          v4 = -1;
        else
          v4 = v6 - 87;
      }
      else
      {
        v4 = v6 - 55;
      }
    }
    else
    {
      v4 = v6 - 48;
    }
    ++v5;
  }
  while ( v4 >= 0 );
  v7 = *(v5 - 1);
  if ( v7 != 58 && (v7 != 45 || *v5 != 48 || v5[1] != 120) )
    goto LABEL_37;
  v8 = v5[2];
  if ( (unsigned __int8)(v8 - 48) > 9u )
  {
    if ( (unsigned __int8)(v8 - 65) > 5u )
    {
      if ( (unsigned __int8)(v8 - 97) > 5u )
        v9 = -1;
      else
        v9 = v8 - 87;
    }
    else
    {
      v9 = v8 - 55;
    }
  }
  else
  {
    v9 = v8 - 48;
  }
  for ( i = (char *)(v5 + 3); v9 >= 0; ++i )
  {
    v11 = *i;
    v2 = v9 + 16 * v2;
    if ( (unsigned __int8)(*i - 48) > 9u )
    {
      if ( (unsigned __int8)(v11 - 65) > 5u )
      {
        if ( (unsigned __int8)(v11 - 97) > 5u )
          v9 = -1;
        else
          v9 = v11 - 87;
      }
      else
      {
        v9 = v11 - 55;
      }
    }
    else
    {
      v9 = v11 - 48;
    }
  }
  if ( !v3 || !v2 )
    goto LABEL_37;
  v12 = HK_ANIMATION_KEYCODE;
  while ( *v12 && *v12 != 46 )
  {
    if ( !++v12 )
      goto LABEL_37;
  }
  if ( !v12 )
    goto LABEL_37;
  v14 = v12 + 1;
  if ( !v14 )
    goto LABEL_37;
  while ( *v14 && *v14 != 46 )
  {
    if ( !++v14 )
      goto LABEL_37;
  }
  if ( !v14 )
    goto LABEL_37;
  v15 = v14 + 1;
  if ( v3 >= 0 )
  {
    v18 = 0;
    if ( *v15 )
    {
      do
      {
        v19 = (char)(v15++)[1];
        v18 = v19 + 23 * v18;
      }
      while ( (_BYTE)v19 );
    }
    if ( v2 == ((v18 ^ 0x2BF010C9) & 0x7FFFFFFF) )
      goto LABEL_55;
LABEL_37:
    hkErrorMessage(
      "Product:hka Key Code is invalid or is for a different product version.\n"
      "Please contact Havok.com\n"
      "No simulation possible.");
    return 1i64;
  }
  v16 = (v3 ^ 0x2BF010C9) & 0x7FFFFFFF;
  v17 = hkGetSystemTime() >> 8;
  if ( v17 < 5177250 )
    hkErrorMessage(
      "Product:hka Key Code has expired or is for a different product version.\n"
      "Please contact Havok.com for an extension.\n"
      "No simulation possible.");
  if ( v16 < v17 )
  {
    hkErrorMessage(
      "Product:hka Key Code has expired or is for a different product version.\n"
      "Please contact Havok.com for an extension.\n"
      "No simulation possible.");
    return 2i64;
  }
  if ( (unsigned __int64)(v16 - v17 - 1) <= 0xD2D )
  {
    v1->m_bool = 1;
    return 3i64;
  }
LABEL_55:
  result = 0i64;
  v1->m_bool = 1;
  return result;
}

// File Line: 321
// RVA: 0xBB5E00
void hkaCheckKeycode()
{
  ;
}

