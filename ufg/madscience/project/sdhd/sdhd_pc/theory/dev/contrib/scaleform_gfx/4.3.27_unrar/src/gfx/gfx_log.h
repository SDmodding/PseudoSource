// File Line: 88
// RVA: 0x8A22A0
void __fastcall Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::~LogBase<Scaleform::GFx::LoaderImpl>(
        Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl> *this)
{
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::`vftable;
}

// File Line: 223
// RVA: 0x89A4B0
void __fastcall Scaleform::GFx::LogState::LogState(Scaleform::GFx::LogState *this, Scaleform::GFx::Resource *log)
{
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_Scale9;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LogState::`vftable{for `Scaleform::GFx::State};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)&Scaleform::GFx::LogState::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LogState>};
  if ( log )
    Scaleform::Render::RenderBuffer::AddRef(log);
  this->pLog.pObject = (Scaleform::Log *)log;
}

// File Line: 238
// RVA: 0x702360
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this,
        const char *pfmt,
        ...)
{
  __int64 *v2; // rax
  __int64 v3; // r10
  int v4[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v2 = (__int64 *)(*((__int64 (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *))this[28].vfptr->__vecDelDtor
                   + 76))(this[28].vfptr);
  if ( v2 )
  {
    v3 = *v2;
    v4[0] = 200704;
    (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *))(v3 + 8))(v2, v4, pfmt, (__int64 *)va);
  }
}

// File Line: 239
// RVA: 0x7FA3B0
void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *vfptr; // rcx
  Scaleform::Log *GlobalLog; // rax
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *, unsigned int); // rax
  int v5[6]; // [rsp+20h] [rbp-18h] BYREF
  const char *v6; // [rsp+48h] [rbp+10h]
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v6 = pfmt;
  if ( this )
    this -= 3;
  vfptr = this[4].vfptr;
  if ( !vfptr )
  {
    GlobalLog = Scaleform::Log::GetGlobalLog();
    pfmt = v6;
    vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *)GlobalLog;
  }
  vecDelDtor = vfptr->__vecDelDtor;
  v5[0] = 135168;
  (*((void (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::LogState>Vtbl *, int *, const char *, __int64 *))vecDelDtor
   + 1))(
    vfptr,
    v5,
    pfmt,
    (__int64 *)va);
}

// File Line: 242
// RVA: 0x702440
void Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v3; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *v4; // rbx
  __int64 *v5; // rax
  __int64 v6; // r10
  int v7[10]; // [rsp+20h] [rbp-28h] BYREF
  va_list va; // [rsp+60h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v3 = 0i64;
  if ( this )
    v4 = this - 3;
  else
    v4 = 0i64;
  if ( v4 != (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)-24i64 )
    v3 = v4;
  if ( v3[3].vfptr->IsVerboseActionErrors(v3 + 3) )
  {
    v5 = (__int64 *)((__int64 (__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *))v4->vfptr[38].__vecDelDtor)(v4);
    if ( v5 )
    {
      v6 = *v5;
      v7[0] = 212992;
      (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *))(v6 + 8))(v5, v7, pfmt, (__int64 *)va);
    }
  }
}

// File Line: 243
// RVA: 0x7028A0
void Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v3; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v4; // rbx
  Scaleform::Log *vfptr; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  int v7[10]; // [rsp+20h] [rbp-28h] BYREF
  va_list va; // [rsp+60h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v3 = 0i64;
  if ( this )
    v4 = this - 3;
  else
    v4 = 0i64;
  if ( v4 != (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)-24i64 )
    v3 = v4;
  if ( v3[3].vfptr->IsVerboseActionErrors(v3 + 3) )
  {
    vfptr = (Scaleform::Log *)v4[4].vfptr;
    if ( !vfptr )
      vfptr = Scaleform::Log::GetGlobalLog();
    v6 = vfptr->vfptr;
    v7[0] = 147456;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))v6[1].__vecDelDtor)(
      vfptr,
      v7,
      pfmt,
      (__int64 *)va);
  }
}

// File Line: 244
// RVA: 0x702750
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *this,
        const char *pfmt,
        ...)
{
  __int64 *v2; // rax
  __int64 v3; // r10
  int v4[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v2 = (__int64 *)(*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *, unsigned int)))(*(_QWORD *)this[6].vfptr[14].__vecDelDtor + 608i64))(this[6].vfptr[14].__vecDelDtor);
  if ( v2 )
  {
    v3 = *v2;
    v4[0] = 0x4000;
    (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *))(v3 + 8))(v2, v4, pfmt, (__int64 *)va);
  }
}

// File Line: 246
// RVA: 0x8E94B0
void __fastcall Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *this,
        const char *pfmt)
{
  ;
}

// File Line: 250
// RVA: 0x702290
void Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *this,
        const char *pfmt,
        ...)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *vfptr; // rcx
  __int64 *v3; // rax
  __int64 v4; // r10
  int v5[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, pfmt);
  vfptr = this[28].vfptr;
  if ( (*(_DWORD *)(*((_QWORD *)vfptr[2].__vecDelDtor + 2) + 21200i64) & 4) != 0 )
  {
    v3 = (__int64 *)(*((__int64 (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *))vfptr->__vecDelDtor
                     + 76))(vfptr);
    if ( v3 )
    {
      v4 = *v3;
      v5[0] = 24576;
      (*(void (__fastcall **)(__int64 *, int *, const char *, __int64 *))(v4 + 8))(v3, v5, pfmt, (__int64 *)va);
    }
  }
}

