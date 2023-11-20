// File Line: 289
// RVA: 0x182B70
__int64 __fastcall UFG::qDataHash32(const void *data, unsigned __int64 num_bytes, unsigned int prev_hash)
{
  unsigned __int64 v3; // r10
  char *v4; // r9
  unsigned int v5; // edx
  char v6; // al

  v3 = num_bytes;
  v4 = (char *)data;
  if ( data )
  {
    v5 = 0;
    if ( v3 )
    {
      do
      {
        v6 = *v4;
        ++v5;
        ++v4;
        prev_hash = (prev_hash << 8) ^ sCrcTable32[(unsigned __int8)(v6 ^ HIBYTE(prev_hash))];
      }
      while ( v5 < v3 );
    }
  }
  return prev_hash;
}

// File Line: 306
// RVA: 0x182BC0
unsigned __int64 __fastcall UFG::qDataHash64(const void *data, unsigned __int64 num_bytes, unsigned __int64 prev_hash)
{
  unsigned __int64 v3; // r10
  char *v4; // r9
  unsigned int v5; // edx
  char v6; // al

  v3 = num_bytes;
  v4 = (char *)data;
  if ( data )
  {
    v5 = 0;
    if ( v3 )
    {
      do
      {
        v6 = *v4;
        ++v5;
        ++v4;
        prev_hash = (prev_hash >> 8) ^ sCrcTable64[(unsigned __int8)(prev_hash ^ v6)];
      }
      while ( v5 < v3 );
    }
  }
  return prev_hash;
}

// File Line: 325
// RVA: 0x18B680
__int64 __fastcall UFG::qStringHash32(const char *str, unsigned int prevHash)
{
  const char *v2; // r8
  char v3; // al

  v2 = str;
  if ( str )
  {
    v3 = *str;
    if ( *str )
    {
      do
      {
        ++v2;
        prevHash = (prevHash << 8) ^ sCrcTable32[(unsigned __int8)(v3 ^ HIBYTE(prevHash))];
        v3 = *v2;
      }
      while ( *v2 );
    }
  }
  return prevHash;
}

// File Line: 341
// RVA: 0x18B6D0
unsigned __int64 __fastcall UFG::qStringHash64(const char *data, unsigned __int64 prev_hash)
{
  const char *v2; // r8
  char v3; // al

  v2 = data;
  if ( data )
  {
    v3 = *data;
    if ( *data )
    {
      do
      {
        ++v2;
        prev_hash = (prev_hash >> 8) ^ sCrcTable64[(unsigned __int8)(prev_hash ^ v3)];
        v3 = *v2;
      }
      while ( *v2 );
    }
  }
  return prev_hash;
}

// File Line: 361
// RVA: 0x18B720
__int64 __fastcall UFG::qStringHashUpper32(const char *str, unsigned int prevHash)
{
  unsigned int v2; // er8
  const char *v3; // r9
  char v4; // al
  unsigned int v5; // ecx
  unsigned int v6; // er8

  v2 = prevHash;
  v3 = str;
  if ( str )
  {
    v4 = *str;
    if ( *str )
    {
      do
      {
        if ( v4 <= 0x7A && v4 >= 0x61 )
          v4 -= 0x20;
        ++v3;
        v5 = v2 << 8;
        v6 = sCrcTable32[(unsigned __int8)(v4 ^ HIBYTE(v2))];
        v4 = *v3;
        v2 = v5 ^ v6;
      }
      while ( *v3 );
    }
  }
  return v2;
}

// File Line: 378
// RVA: 0x18B780
unsigned __int64 __fastcall UFG::qStringHashUpper64(const char *data, unsigned __int64 prev_hash)
{
  unsigned __int64 v2; // r8
  const char *v3; // r9
  char v4; // al
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r8

  v2 = prev_hash;
  v3 = data;
  if ( data )
  {
    v4 = *data;
    if ( *data )
    {
      do
      {
        if ( v4 <= 122 && v4 >= 97 )
          v4 -= 32;
        ++v3;
        v5 = v2;
        v6 = sCrcTable64[(unsigned __int8)(v2 ^ v4)];
        v4 = *v3;
        v2 = (v5 >> 8) ^ v6;
      }
      while ( *v3 );
    }
  }
  return v2;
}

