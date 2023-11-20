// File Line: 56
// RVA: 0x12BB230
char *__cdecl strncat(char *Dest, const char *Source, size_t Count)
{
  char *v3; // r11
  unsigned __int64 v4; // rax
  signed __int64 v5; // r10
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  signed __int64 v9; // rcx
  char v10; // al
  unsigned __int64 v12; // rax
  bool v13; // cf
  size_t v14; // r8
  signed __int64 v15; // r8
  signed __int64 v16; // r8
  unsigned __int64 v17; // rax
  signed __int64 v18; // r8
  signed __int64 v19; // r8
  unsigned __int64 v20; // rax
  signed __int64 v21; // r8
  signed __int64 v22; // r8
  unsigned int v23; // eax
  signed __int64 v24; // r8

  v3 = Dest;
  if ( !Count )
    return v3;
  if ( (unsigned __int8)Dest & 7 )
  {
    while ( *Dest )
    {
      if ( !((unsigned __int8)++Dest & 7) )
        goto strncat_loop_begin;
    }
  }
  else
  {
    while ( 1 )
    {
      do
      {
strncat_loop_begin:
        v4 = *(_QWORD *)Dest;
        v5 = (*(_QWORD *)Dest + 9151031864016699135i64) ^ ~*(_QWORD *)Dest;
        Dest += 8;
      }
      while ( !(v5 & 0x8101010101010100ui64) );
      Dest -= 8;
      if ( !(_BYTE)v4 )
        break;
      ++Dest;
      if ( !BYTE1(v4) )
        break;
      ++Dest;
      v6 = v4 >> 16;
      if ( !(_BYTE)v6 )
        break;
      ++Dest;
      if ( !BYTE1(v6) )
        break;
      ++Dest;
      v7 = v6 >> 16;
      if ( !(_BYTE)v7 )
        break;
      ++Dest;
      if ( !BYTE1(v7) )
        break;
      ++Dest;
      v8 = (unsigned int)v7 >> 16;
      if ( !(_BYTE)v8 )
        break;
      ++Dest;
      if ( !BYTE1(v8) )
        break;
      ++Dest;
    }
  }
  v9 = Dest - Source;
  if ( (unsigned __int8)Source & 7 )
  {
    while ( 1 )
    {
      v10 = *Source;
      Source[v9] = *Source;
      if ( !v10 )
        return v3;
      ++Source;
      if ( !--Count )
      {
        Source[v9] = 0;
        return v3;
      }
      if ( !((unsigned __int8)Source & 7) )
        goto LABEL_23;
    }
  }
  do
  {
LABEL_23:
    while ( 1 )
    {
      v12 = *(_QWORD *)Source;
      v13 = Count < 8;
      Count -= 8i64;
      if ( v13 || ((v12 + 9151031864016699135i64) ^ ~v12) & 0x8101010101010100ui64 )
        break;
      *(_QWORD *)&Source[v9] = v12;
      Source += 8;
    }
    v14 = Count + 8;
    if ( !v14 )
      break;
    Source[v9] = v12;
    if ( !(_BYTE)v12 )
      return v3;
    ++Source;
    v15 = v14 - 1;
    if ( !v15 )
      break;
    Source[v9] = BYTE1(v12);
    if ( !BYTE1(v12) )
      return v3;
    ++Source;
    v16 = v15 - 1;
    if ( !v16 )
      break;
    v17 = v12 >> 16;
    Source[v9] = v17;
    if ( !(_BYTE)v17 )
      return v3;
    ++Source;
    v18 = v16 - 1;
    if ( !v18 )
      break;
    Source[v9] = BYTE1(v17);
    if ( !BYTE1(v17) )
      return v3;
    ++Source;
    v19 = v18 - 1;
    if ( !v19 )
      break;
    v20 = v17 >> 16;
    Source[v9] = v20;
    if ( !(_BYTE)v20 )
      return v3;
    ++Source;
    v21 = v19 - 1;
    if ( !v21 )
      break;
    Source[v9] = BYTE1(v20);
    if ( !BYTE1(v20) )
      return v3;
    ++Source;
    v22 = v21 - 1;
    if ( !v22 )
      break;
    v23 = (unsigned int)v20 >> 16;
    Source[v9] = v23;
    if ( !(_BYTE)v23 )
      return v3;
    ++Source;
    v24 = v22 - 1;
    if ( !v24 )
      break;
    Source[v9] = BYTE1(v23);
    if ( !BYTE1(v23) )
      return v3;
    ++Source;
    Count = v24 - 1;
  }
  while ( Count );
  Source[v9] = 0;
  return v3;
}

