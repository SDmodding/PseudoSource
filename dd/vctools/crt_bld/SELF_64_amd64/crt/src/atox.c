// File Line: 55
// RVA: 0x12DCFFC
int __fastcall wtol(const wchar_t *nptr)
{
  return wcstol(nptr, 0i64, 10);
}

// File Line: 99
// RVA: 0x12B12C8
int __fastcall atol(const char *nptr)
{
  return strtol(nptr, 0i64, 10);
}

