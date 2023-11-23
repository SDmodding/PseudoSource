// File Line: 147
// RVA: 0x225150
__int64 __fastcall AChecksum::generate_crc32_cstr(const char *cstr_p, unsigned int length, unsigned int prev_crc)
{
  const char *v4; // r8
  __int64 v5; // rax
  const char *v6; // rdx
  char v7; // al

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
      prev_crc = (prev_crc << 8) ^ g_table_crc32[(unsigned __int8)(v7 ^ HIBYTE(prev_crc))];
    }
    while ( v4 < v6 );
  }
  return prev_crc;
}

// File Line: 206
// RVA: 0x2251B0
__int64 __fastcall AChecksum::generate_crc32_cstr_upper(const char *cstr_p, unsigned int length, unsigned int prev_crc)
{
  const char *v4; // r8
  __int64 v5; // rax
  const char *v6; // rdx
  __int64 v7; // rax

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
      prev_crc = (prev_crc << 8) ^ g_table_crc32[(unsigned __int8)(HIBYTE(prev_crc) ^ AString::c_char2uppper[v7])];
    }
    while ( v4 < v6 );
  }
  return prev_crc;
}

