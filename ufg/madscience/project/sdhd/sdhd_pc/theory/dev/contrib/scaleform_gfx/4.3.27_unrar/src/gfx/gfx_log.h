// File Line: 88
// RVA: 0x8A22A0
void __fastcall Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::~LogBase<Scaleform::GFx::LoaderImpl>(Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl> *this)
{
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
}

// File Line: 223
// RVA: 0x89A4B0
void __fastcall Scaleform::GFx::LogState::LogState(Scaleform::GFx::LogState *this, Scaleform::Log *log)
{
  Scaleform::Log *v2; // rdi
  Scaleform::GFx::LogState *v3; // rbx

  v2 = log;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 2;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LogState::`vftable{for `Scaleform::GFx::State};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)&Scaleform::GFx::LogState::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LogState>};
  if ( log )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)log);
  v3->pLog.pObject = v2;
}

// File Line: 238
// RVA: 0x702360
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this, const char *pfmt, ...)
{
  __int64 *v2; // rax
  __int64 v3; // r10
  int v4; // [rsp+20h] [rbp-18h]
  const char *v5; // [rsp+48h] [rbp+10h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, pfmt);
  v5 = pfmt;
  v2 = (__int64 *)(*((__int64 (**)(void))this[28].vfptr->__vecDelDtor + 76))();
  if ( v2 )
  {
    v3 = *v2;
    v4 = 200704;
    (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *, _QWORD))(v3 + 8))(
      v2,
      &v4,
      v5,
      (__int64 *)va,
      *(_QWORD *)&v4);
  }
}

// File Line: 239
// RVA: 0x7FA3B0
void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this, const char *pfmt, ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *v2; // rcx
  Scaleform::Log *v3; // rax
  void *(__fastcall *v4)(Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *, unsigned int); // rax
  int v5; // [rsp+20h] [rbp-18h]
  const char *v6; // [rsp+48h] [rbp+10h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, pfmt);
  v6 = pfmt;
  if ( this )
    this -= 3;
  v2 = this[4].vfptr;
  if ( !v2 )
  {
    v3 = Scaleform::Log::GetGlobalLog();
    pfmt = v6;
    v2 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)v3;
  }
  v4 = v2->__vecDelDtor;
  v5 = 135168;
  (*((void (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *, int *, const char *, __int64 *, _QWORD))v4
   + 1))(
    v2,
    &v5,
    pfmt,
    (__int64 *)va,
    *(_QWORD *)&v5);
}

// File Line: 242
// RVA: 0x702440
void Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *this, const char *pfmt, ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v2; // rbx
  signed __int64 v3; // rcx
  signed __int64 v4; // rbx
  __int64 *v5; // rax
  __int64 v6; // r10
  int v7; // [rsp+20h] [rbp-28h]
  const char *v8; // [rsp+58h] [rbp+10h]
  va_list va; // [rsp+60h] [rbp+18h]

  va_start(va, pfmt);
  v8 = pfmt;
  v2 = this;
  v3 = 0i64;
  if ( v2 )
    v4 = (signed __int64)&v2[-3];
  else
    v4 = 0i64;
  if ( v4 != -24 )
    v3 = v4;
  if ( (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)(v3 + 24) + 8i64))(v3 + 24) )
  {
    v5 = (__int64 *)(*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v4 + 608i64))(v4);
    if ( v5 )
    {
      v6 = *v5;
      v7 = 212992;
      (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *, _QWORD))(v6 + 8))(
        v5,
        &v7,
        v8,
        (__int64 *)va,
        *(_QWORD *)&v7);
    }
  }
}

// File Line: 243
// RVA: 0x7028A0
void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this, const char *pfmt, ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v2; // rbx
  signed __int64 v3; // rcx
  signed __int64 v4; // rbx
  Scaleform::Log *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  int v7; // [rsp+20h] [rbp-28h]
  const char *v8; // [rsp+58h] [rbp+10h]
  va_list va; // [rsp+60h] [rbp+18h]

  va_start(va, pfmt);
  v8 = pfmt;
  v2 = this;
  v3 = 0i64;
  if ( v2 )
    v4 = (signed __int64)&v2[-3];
  else
    v4 = 0i64;
  if ( v4 != -24 )
    v3 = v4;
  if ( (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)(v3 + 24) + 8i64))(v3 + 24) )
  {
    v5 = *(Scaleform::Log **)(v4 + 32);
    if ( !v5 )
      v5 = Scaleform::Log::GetGlobalLog();
    v6 = v5->vfptr;
    v7 = 147456;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v6[1].__vecDelDtor)(
      v5,
      &v7,
      v8,
      (__int64 *)va,
      *(_QWORD *)&v7);
  }
}

// File Line: 244
// RVA: 0x702750
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *this, const char *pfmt, ...)
{
  __int64 *v2; // rax
  __int64 v3; // r10
  int v4; // [rsp+20h] [rbp-18h]
  const char *v5; // [rsp+48h] [rbp+10h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, pfmt);
  v5 = pfmt;
  v2 = (__int64 *)(*(__int64 (**)(void))(*(_QWORD *)this[6].vfptr[14].__vecDelDtor + 608i64))();
  if ( v2 )
  {
    v3 = *v2;
    v4 = 0x4000;
    (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *, _QWORD))(v3 + 8))(
      v2,
      &v4,
      v5,
      (__int64 *)va,
      *(_QWORD *)&v4);
  }
}

// File Line: 246
// RVA: 0x8E94B0
void __fastcall Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this, const char *pfmt)
{
  ;
}

// File Line: 250
// RVA: 0x702290
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this, const char *pfmt, ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *v2; // rcx
  __int64 *v3; // rax
  __int64 v4; // r10
  int v5; // [rsp+20h] [rbp-18h]
  const char *v6; // [rsp+48h] [rbp+10h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, pfmt);
  v6 = pfmt;
  v2 = this[28].vfptr;
  if ( (*(_DWORD *)(*((_QWORD *)v2[2].__vecDelDtor + 2) + 21200i64) >> 2) & 1 )
  {
    v3 = (__int64 *)(*((__int64 (**)(void))v2->__vecDelDtor + 76))();
    if ( v3 )
    {
      v4 = *v3;
      v5 = 24576;
      (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *, _QWORD))(v4 + 8))(
        v3,
        &v5,
        v6,
        (__int64 *)va,
        *(_QWORD *)&v5);
    }
  }
}

