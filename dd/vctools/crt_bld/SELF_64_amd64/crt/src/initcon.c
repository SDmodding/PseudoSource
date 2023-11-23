// File Line: 53
// RVA: 0x12DCCB0
HANDLE _initconout()
{
  HANDLE result; // rax

  result = CreateFileW(L"CONOUT$", 0x40000000u, 3u, 0i64, 3u, 0, 0i64);
  confh = result;
  return result;
}

// File Line: 83
// RVA: 0x12DCC90
int _termconout()
{
  int result; // eax

  result = (_DWORD)confh + 2;
  if ( (unsigned __int64)confh + 2 > 1 )
    return CloseHandle(confh);
  return result;
}

