// File Line: 84
// RVA: 0x12D5DA8
signed __int64 __fastcall putwch_nolock(wchar_t ch)
{
  HANDLE v1; // rcx
  signed __int64 result; // rax
  wchar_t Buffer; // [rsp+40h] [rbp+8h]
  unsigned int NumberOfCharsWritten; // [rsp+48h] [rbp+10h]

  Buffer = ch;
  v1 = confh;
  if ( confh == (HANDLE)-2i64 )
  {
    _initconout();
    v1 = confh;
  }
  if ( v1 != (HANDLE)-1i64 && WriteConsoleW(v1, &Buffer, 1u, &NumberOfCharsWritten, 0i64) )
    result = Buffer;
  else
    result = 0xFFFFi64;
  return result;
}

