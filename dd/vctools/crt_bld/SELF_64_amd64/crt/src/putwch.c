// File Line: 84
// RVA: 0x12D5DA8
__int64 __fastcall putwch_nolock(wchar_t ch)
{
  HANDLE v1; // rcx
  unsigned __int16 Buffer; // [rsp+40h] [rbp+8h] BYREF
  unsigned int NumberOfCharsWritten; // [rsp+48h] [rbp+10h] BYREF

  Buffer = ch;
  v1 = confh;
  if ( confh == (HANDLE)-2i64 )
  {
    _initconout();
    v1 = confh;
  }
  if ( v1 == (HANDLE)-1i64 || !WriteConsoleW(v1, &Buffer, 1u, &NumberOfCharsWritten, 0i64) )
    return 0xFFFFi64;
  else
    return Buffer;
}

