// File Line: 37
// RVA: 0x12D1B5C
__int64 __fastcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *v1; // rax
  int v2; // ecx

  v1 = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && v1->NumberParameters == 4 )
  {
    v2 = v1->ExceptionInformation[0];
    if ( (unsigned int)(v2 - 429065504) <= 2 || v2 == 26820608 )
      terminate();
  }
  return 0i64;
}

// File Line: 56
// RVA: 0x12D1B94
__int64 __fastcall _CxxSetUnhandledExceptionFilter()
{
  _crtSetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)__CxxUnhandledExceptionFilter);
  return 0i64;
}

