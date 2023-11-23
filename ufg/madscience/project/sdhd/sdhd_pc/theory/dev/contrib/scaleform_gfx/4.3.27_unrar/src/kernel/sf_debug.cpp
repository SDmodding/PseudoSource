// File Line: 24
// RVA: 0x998C30
void Scaleform::LogDebugMessage(int *id, const char *fmt, ...)
{
  int v2[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, fmt);
  if ( Scaleform::SF_GlobalLog )
  {
    v2[0] = *id;
    ((void (__fastcall *)(Scaleform::Log *volatile, int *, const char *, __int64 *))Scaleform::SF_GlobalLog->vfptr[1].__vecDelDtor)(
      Scaleform::SF_GlobalLog,
      v2,
      fmt,
      (__int64 *)va);
  }
}

