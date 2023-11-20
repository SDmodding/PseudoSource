// File Line: 78
// RVA: 0x12BB7F0
char *__cdecl strcat(char *Dest, const char *Source)
{
  unsigned __int64 v2; // rax
  signed __int64 v3; // r10
  unsigned __int64 v4; // rax

  for ( ; (unsigned __int8)Dest & 7; ++Dest )
    JUMPOUT(*Dest, 0, &__entry_from_strcat_in_strcpy);
  while ( 1 )
  {
    do
    {
      v2 = *(_QWORD *)Dest;
      v3 = (*(_QWORD *)Dest + 9151031864016699135i64) ^ ~*(_QWORD *)Dest;
      Dest += 8;
    }
    while ( !(v3 & 0x8101010101010100ui64) );
    JUMPOUT(v2, 0, &__entry_from_strcat_in_strcpy);
    JUMPOUT(BYTE1(v2), 0, &__entry_from_strcat_in_strcpy);
    v4 = v2 >> 16;
    JUMPOUT(v4, 0, &__entry_from_strcat_in_strcpy);
    JUMPOUT(BYTE1(v4), 0, &__entry_from_strcat_in_strcpy);
    v4 >>= 16;
    JUMPOUT(v4, 0, &__entry_from_strcat_in_strcpy);
    JUMPOUT(BYTE1(v4), 0, &__entry_from_strcat_in_strcpy);
    LODWORD(v4) = (unsigned int)v4 >> 16;
    JUMPOUT(v4, 0, &__entry_from_strcat_in_strcpy);
    JUMPOUT(BYTE1(v4), 0, &__entry_from_strcat_in_strcpy);
  }
}

// File Line: 139
// RVA: 0x12BB890
char *__cdecl strcpy(char *Dest, const char *Source)
{
  char *v2; // r11
  signed __int64 v3; // rcx
  char v4; // al
  char *result; // rax
  unsigned __int64 v6; // rax
  const char *v7; // rdx
  signed __int64 v8; // rdx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // rdx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rdx
  signed __int64 v14; // rdx
  unsigned int v15; // eax
  signed __int64 v16; // rdx

  v2 = Dest;
  v3 = Dest - Source;
  if ( (unsigned __int8)Source & 7 )
  {
    while ( 1 )
    {
      v4 = *Source;
      Source[v3] = *Source;
      if ( !v4 )
        break;
      if ( !((unsigned __int8)++Source & 7) )
        goto LABEL_7;
    }
    result = v2;
  }
  else
  {
    while ( 1 )
    {
LABEL_7:
      while ( 1 )
      {
        v6 = *(_QWORD *)Source;
        if ( ((*(_QWORD *)Source + 9151031864016699135i64) ^ ~*(_QWORD *)Source) & 0x8101010101010100ui64 )
          break;
        *(_QWORD *)&Source[v3] = v6;
        Source += 8;
      }
      Source[v3] = v6;
      if ( !(_BYTE)v6 )
        break;
      v7 = Source + 1;
      v7[v3] = BYTE1(v6);
      if ( !BYTE1(v6) )
        break;
      v8 = (signed __int64)(v7 + 1);
      v9 = v6 >> 16;
      *(_BYTE *)(v3 + v8) = v9;
      if ( !(_BYTE)v9 )
        break;
      v10 = v8 + 1;
      *(_BYTE *)(v3 + v10) = BYTE1(v9);
      if ( !BYTE1(v9) )
        break;
      v11 = v10 + 1;
      v12 = v9 >> 16;
      *(_BYTE *)(v3 + v11) = v12;
      if ( !(_BYTE)v12 )
        break;
      v13 = v11 + 1;
      *(_BYTE *)(v3 + v13) = BYTE1(v12);
      if ( !BYTE1(v12) )
        break;
      v14 = v13 + 1;
      v15 = (unsigned int)v12 >> 16;
      *(_BYTE *)(v3 + v14) = v15;
      if ( !(_BYTE)v15 )
        break;
      v16 = v14 + 1;
      *(_BYTE *)(v3 + v16) = BYTE1(v15);
      if ( !BYTE1(v15) )
        break;
      Source = (const char *)(v16 + 1);
    }
    result = v2;
  }
  return result;
}

// File Line: 148
// RVA: 0x12BB893
__entry_from_strcat_in_strcpy

