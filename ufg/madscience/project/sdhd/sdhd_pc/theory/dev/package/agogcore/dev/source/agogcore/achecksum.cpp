// File Line: 147
// RVA: 0x225150
__int64 __fastcall AChecksum::generate_crc32_cstr(const char *cstr_p, unsigned int length, unsigned int prev_crc)
{
  unsigned int v3; // er9
  const char *v4; // r8
  signed __int64 v5; // rax
  const char *v6; // rdx
  char v7; // al

  v3 = prev_crc;
  v4 = cstr_p;
  if ( length == -1 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( cstr_p[v5] );
  }
  else
  {
    LODWORD(v5) = length;
  }
  v6 = &cstr_p[(unsigned int)v5];
  if ( cstr_p < v6 )
  {
    do
    {
      v7 = *v4++;
      v3 = (v3 << 8) ^ g_table_crc32[(unsigned __int8)(v7 ^ HIBYTE(v3))];
    }
    while ( v4 < v6 );
  }
  return v3;
}

// File Line: 206
// RVA: 0x2251B0
__int64 __fastcall AChecksum::generate_crc32_cstr_upper(const char *cstr_p, unsigned int length, unsigned int prev_crc)
{
  unsigned int v3; // er9
  const char *v4; // r8
  signed __int64 v5; // rax
  const char *v6; // rdx
  __int64 v7; // rax

  v3 = prev_crc;
  v4 = cstr_p;
  if ( length == -1 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( cstr_p[v5] );
  }
  else
  {
    LODWORD(v5) = length;
  }
  v6 = &cstr_p[(unsigned int)v5];
  if ( cstr_p < v6 )
  {
    do
    {
      v7 = *(unsigned __int8 *)v4++;
      v3 = (v3 << 8) ^ g_table_crc32[(unsigned __int8)(HIBYTE(v3) ^ *(_BYTE *)(v7 + 5392592992i64))];
    }
    while ( v4 < v6 );
  }
  return v3;
}

