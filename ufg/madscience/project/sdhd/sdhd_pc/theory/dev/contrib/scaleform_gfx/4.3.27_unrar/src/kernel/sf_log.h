// File Line: 184
// RVA: 0x8E9410
void Scaleform::Log::LogMessage(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v3[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, fmt);
  vfptr = this->vfptr;
  v3[0] = 4096;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))vfptr[1].__vecDelDtor)(
    this,
    v3,
    fmt,
    (__int64 *)va);
}

// File Line: 190
// RVA: 0x7023C0
void Scaleform::Log::LogError(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v3[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, fmt);
  vfptr = this->vfptr;
  v3[0] = 200704;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))vfptr[1].__vecDelDtor)(
    this,
    v3,
    fmt,
    (__int64 *)va);
}

// File Line: 196
// RVA: 0x7FA410
void Scaleform::Log::LogWarning(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v3[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, fmt);
  vfptr = this->vfptr;
  v3[0] = 135168;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))vfptr[1].__vecDelDtor)(
    this,
    v3,
    fmt,
    (__int64 *)va);
}

