// File Line: 284
// RVA: 0x8173D0
unsigned __int64 Scaleform::SFsprintf(char *dest, unsigned __int64 destsize, const char *format, ...)
{
  unsigned __int64 result; // rax
  va_list va; // [rsp+68h] [rbp+20h] BYREF

  va_start(va, format);
  LODWORD(result) = vsnprintf_s(dest, destsize, 0xFFFFFFFFFFFFFFFFui64, format, va);
  if ( (_DWORD)result != -1 )
    return (int)result;
  dest[destsize - 1] = 0;
  return destsize - 1;
}

// File Line: 395
// RVA: 0x9046D0
__int64 __fastcall Scaleform::SFiswalnum(wchar_t charCode)
{
  unsigned __int64 v1; // rax
  int v2; // r8d
  int v4; // edx
  int v5; // ecx

  v1 = (unsigned __int64)charCode >> 8;
  v2 = Scaleform::UnicodeAlnumBits[v1];
  if ( !Scaleform::UnicodeAlnumBits[v1] )
    return 0i64;
  if ( v2 == 1 )
    return 1i64;
  v4 = charCode & 0xF;
  v5 = Scaleform::UnicodeAlnumBits[v2 + ((charCode >> 4) & 0xF)];
  return _bittest(&v5, v4);
}

// File Line: 398
// RVA: 0x817380
__int64 __fastcall Scaleform::SFiswspace(wchar_t charCode)
{
  unsigned __int64 v1; // rax
  int v2; // r8d
  int v4; // edx
  int v5; // ecx

  v1 = (unsigned __int64)charCode >> 8;
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0i64;
  if ( v2 == 1 )
    return 1i64;
  v4 = charCode & 0xF;
  v5 = Scaleform::UnicodeSpaceBits[v2 + ((charCode >> 4) & 0xF)];
  return _bittest(&v5, v4);
}

