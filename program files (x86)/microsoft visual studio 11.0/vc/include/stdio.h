// File Line: 309
// RVA: 0xEEC0A8
int sprintf_s<20>(char (*_Dest)[20], const char *_Format, ...)
{
  va_list va; // [rsp+40h] [rbp+18h] BYREF

  va_start(va, _Format);
  return vsprintf_s((char *)_Dest, 0x14ui64, _Format, va);
}

