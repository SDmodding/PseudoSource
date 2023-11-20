// File Line: 284
// RVA: 0x8173D0
signed __int64 Scaleform::SFsprintf(char *dest, unsigned __int64 destsize, const char *format, ...)
{
  unsigned __int64 v3; // rbx
  char *v4; // rdi
  signed __int64 result; // rax
  va_list va; // [rsp+68h] [rbp+20h]

  va_start(va, format);
  v3 = destsize;
  v4 = dest;
  LODWORD(result) = vsnprintf_s(dest, destsize, 0xFFFFFFFFFFFFFFFFui64, format, va);
  if ( (_DWORD)result != -1 )
    return (signed int)result;
  v4[v3 - 1] = 0;
  return v3 - 1;
}

// File Line: 395
// RVA: 0x9046D0
signed __int64 __fastcall Scaleform::SFiswalnum(wchar_t charCode)
{
  unsigned __int64 v1; // rax
  int v2; // er8
  int v4; // edx
  int v5; // ecx

  v1 = (unsigned __int64)charCode >> 8;
  v2 = Scaleform::UnicodeAlnumBits[v1];
  if ( !Scaleform::UnicodeAlnumBits[v1] )
    return 0i64;
  if ( v2 == 1 )
    return 1i64;
  v4 = charCode & 0xF;
  v5 = Scaleform::UnicodeAlnumBits[v2 + (((unsigned int)charCode >> 4) & 0xF)];
  return _bittest(&v5, v4);
}

// File Line: 398
// RVA: 0x817380
signed __int64 __fastcall Scaleform::SFiswspace(wchar_t charCode)
{
  unsigned __int64 v1; // rax
  int v2; // er8
  int v4; // edx
  int v5; // ecx

  v1 = (unsigned __int64)charCode >> 8;
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0i64;
  if ( v2 == 1 )
    return 1i64;
  v4 = charCode & 0xF;
  v5 = Scaleform::UnicodeSpaceBits[v2 + (((unsigned int)charCode >> 4) & 0xF)];
  return _bittest(&v5, v4);
}

