// File Line: 184
// RVA: 0x8E9410
void Scaleform::Log::LogMessage(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *v2; // rax
  int v3; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, fmt);
  v2 = this->vfptr;
  v3 = 4096;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v2[1].__vecDelDtor)(
    this,
    &v3,
    fmt,
    (__int64 *)va,
    *(_QWORD *)&v3);
}

// File Line: 190
// RVA: 0x7023C0
void Scaleform::Log::LogError(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *v2; // rax
  int v3; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, fmt);
  v2 = this->vfptr;
  v3 = 200704;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v2[1].__vecDelDtor)(
    this,
    &v3,
    fmt,
    (__int64 *)va,
    *(_QWORD *)&v3);
}

// File Line: 196
// RVA: 0x7FA410
void Scaleform::Log::LogWarning(Scaleform::Log *this, const char *fmt, ...)
{
  Scaleform::RefCountImplCoreVtbl *v2; // rax
  int v3; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, fmt);
  v2 = this->vfptr;
  v3 = 135168;
  ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v2[1].__vecDelDtor)(
    this,
    &v3,
    fmt,
    (__int64 *)va,
    *(_QWORD *)&v3);
}

