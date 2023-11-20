// File Line: 16
// RVA: 0x12B34E0
char *__cdecl strncpy(char *Dest, const char *Source, size_t Count)
{
  char *v3; // r11
  signed __int64 v4; // rcx
  bool v5; // zf
  char *result; // rax
  unsigned __int64 v7; // rax
  bool v8; // cf
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned int v11; // eax
  char *v12; // rcx
  size_t i; // r8
  unsigned __int64 v14; // r8

  v3 = Dest;
  if ( !Count )
    return v3;
  v4 = Dest - Source;
  if ( (unsigned __int8)Source & 7 )
  {
    while ( 1 )
    {
      v5 = *Source == 0;
      Source[v4] = *Source;
      if ( v5 )
        break;
      ++Source;
      if ( !--Count )
        return v3;
      if ( !((unsigned __int8)Source & 7) )
        goto LABEL_9;
    }
filler:
    v12 = (char *)&Source[v4];
    if ( Count >= 0x10 )
    {
      while ( (unsigned __int8)v12 & 7 )
      {
        *++v12 = 0;
        --Count;
      }
      v8 = Count < 0x20;
      for ( i = Count - 32; !v8; i -= 32i64 )
      {
        *(_QWORD *)v12 = 0i64;
        *((_QWORD *)v12 + 1) = 0i64;
        *((_QWORD *)v12 + 2) = 0i64;
        *((_QWORD *)v12 + 3) = 0i64;
        v12 += 32;
        v8 = i < 0x20;
      }
      v14 = i + 32;
      while ( 1 )
      {
        v8 = v14 < 8;
        v14 -= 8i64;
        if ( v8 )
          break;
        *(_QWORD *)v12 = 0i64;
        v12 += 8;
      }
      Count = v14 + 8;
    }
    while ( 1 )
    {
      v8 = Count-- < 1;
      if ( v8 )
        break;
      *v12++ = 0;
    }
    result = v3;
  }
  else
  {
    do
    {
LABEL_9:
      while ( 1 )
      {
        v7 = *(_QWORD *)Source;
        v8 = Count < 8;
        Count -= 8i64;
        if ( v8 || Count == 0 || ((v7 + 9151031864016699135i64) ^ ~v7) & 0x8101010101010100ui64 )
          break;
        *(_QWORD *)&Source[v4] = v7;
        Source += 8;
      }
      Count += 8i64;
      if ( !Count )
        break;
      Source[v4] = v7;
      if ( !(_BYTE)v7 )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      Source[v4] = BYTE1(v7);
      if ( !BYTE1(v7) )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      v9 = v7 >> 16;
      Source[v4] = v9;
      if ( !(_BYTE)v9 )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      Source[v4] = BYTE1(v9);
      if ( !BYTE1(v9) )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      v10 = v9 >> 16;
      Source[v4] = v10;
      if ( !(_BYTE)v10 )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      Source[v4] = BYTE1(v10);
      if ( !BYTE1(v10) )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      v11 = (unsigned int)v10 >> 16;
      Source[v4] = v11;
      if ( !(_BYTE)v11 )
        goto filler;
      ++Source;
      if ( !--Count )
        break;
      Source[v4] = BYTE1(v11);
      if ( !BYTE1(v11) )
        goto filler;
      ++Source;
      --Count;
    }
    while ( Count );
    result = v3;
  }
  return result;
}

