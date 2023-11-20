// File Line: 41
// RVA: 0x94B240
void __fastcall Scaleform::Log::~Log(Scaleform::Log *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Log::`vftable';
  if ( this == Scaleform::SF_GlobalLog )
    Scaleform::SF_GlobalLog = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 56
// RVA: 0x998C80
void Scaleform::Log::LogMessageById(Scaleform::GFx::LogState *this, __int64 messageType, const char *pfmt, ...)
{
  int v3; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+58h] [rbp+20h]

  va_start(va, pfmt);
  v3 = *(_DWORD *)messageType;
  ((void (__fastcall *)(Scaleform::GFx::LogState *, int *, const char *, __int64 *, _QWORD))this->vfptr[1].__vecDelDtor)(
    this,
    &v3,
    pfmt,
    (__int64 *)va,
    *(_QWORD *)&v3);
}

// File Line: 116
// RVA: 0x984D60
Scaleform::Log *__fastcall Scaleform::Log::GetGlobalLog()
{
  return Scaleform::SF_GlobalLog;
}

// File Line: 125
// RVA: 0x982C60
Scaleform::Log *__fastcall Scaleform::Log::GetDefaultLog()
{
  if ( !(_S1_31 & 1) )
  {
    _S1_31 |= 1u;
    defaultLog.RefCount = 1;
    defaultLog.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Log::`vftable';
    atexit(Scaleform::Log::GetDefaultLog_::_2_::_dynamic_atexit_destructor_for__defaultLog__);
  }
  return &defaultLog;
}

