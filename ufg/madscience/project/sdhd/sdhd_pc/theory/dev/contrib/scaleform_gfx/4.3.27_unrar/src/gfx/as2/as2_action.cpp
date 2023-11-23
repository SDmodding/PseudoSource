// File Line: 134
// RVA: 0x6C6CE0
void __fastcall Scaleform::GFx::AS2::ActionLogger::ActionLogger(
        Scaleform::GFx::AS2::ActionLogger *this,
        Scaleform::GFx::DisplayObject *ptarget,
        const char *suffixStr)
{
  Scaleform::GFx::MovieImpl *MovieImpl; // rax
  Scaleform::GFx::MovieImpl *v6; // rdi
  __int64 v7; // rax
  const char *LogSuffix; // rsi
  const char *v9; // rax
  signed __int64 v10; // rsi
  int v11; // ecx
  int v12; // edx
  unsigned int Flags; // eax
  unsigned int v14; // eax
  __int64 v15; // rax
  const char *v16; // rdx
  char v17; // cl

  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::AS2::ActionLogger::`vftable;
  MovieImpl = Scaleform::GFx::DisplayObjectBase::FindMovieImpl(ptarget);
  v6 = MovieImpl;
  this->VerboseAction = (MovieImpl->Flags & 4) != 0;
  this->VerboseActionErrors = (MovieImpl->Flags & 0x40) == 0;
  this->LogSuffix = suffixStr;
  if ( suffixStr )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))MovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(MovieImpl);
    LogSuffix = this->LogSuffix;
    v9 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 96i64))(v7);
    v10 = LogSuffix - v9;
    do
    {
      v11 = (unsigned __int8)v9[v10];
      v12 = *(unsigned __int8 *)v9 - v11;
      if ( v12 )
        break;
      ++v9;
    }
    while ( v11 );
    Flags = v6->Flags;
    if ( v12 )
      v14 = Flags >> 4;
    else
      v14 = Flags >> 3;
    this->UseSuffix = v14 & 1;
  }
  else
  {
    this->UseSuffix = 0;
  }
  this->pLog = Scaleform::GFx::MovieImpl::GetCachedLog(v6);
  if ( this->UseSuffix && (v6->Flags & 0x20) == 0 )
  {
    v15 = -1i64;
    do
      ++v15;
    while ( suffixStr[v15] );
    if ( v15 > 0 )
    {
      v16 = this->LogSuffix;
      while ( 1 )
      {
        v17 = v16[v15];
        if ( v17 == 47 || v17 == 92 )
          break;
        if ( --v15 <= 0 )
          return;
      }
      this->LogSuffix = &v16[v15 + 1];
    }
  }
}

// File Line: 193
// RVA: 0x7024C0
void Scaleform::GFx::AS2::ActionLogger::LogScriptError(Scaleform::GFx::AS2::ActionLogger *this, char *pfmt, ...)
{
  Scaleform::Log *pLog; // rcx
  unsigned __int64 v4; // rax
  char *v5; // r8
  int v6; // [rsp+20h] [rbp-558h] BYREF
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-550h] BYREF
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-540h] BYREF
  __int64 v9; // [rsp+50h] [rbp-528h]
  char v10[256]; // [rsp+60h] [rbp-518h] BYREF
  Scaleform::MsgFormat v11; // [rsp+160h] [rbp-418h] BYREF
  va_list va; // [rsp+590h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v9 = -2i64;
  pLog = this->pLog;
  if ( pLog )
  {
    if ( this->UseSuffix )
    {
      v4 = -1i64;
      do
        ++v4;
      while ( pfmt[v4] );
      if ( pfmt[v4 - 1] == 10 )
        --v4;
      r.Type = tDataPtr;
      r.SinkData.pStr = (Scaleform::String *)v10;
      r.SinkData.DataPtr.Size = 256i64;
      v.pStr = pfmt;
      v.Size = v4;
      Scaleform::MsgFormat::MsgFormat(&v11, &r);
      Scaleform::MsgFormat::Parse(&v11, "{0} : {1}\n");
      Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v11, &v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v11, &this->LogSuffix);
      Scaleform::MsgFormat::FinishFormatD(&v11);
      Scaleform::MsgFormat::~MsgFormat(&v11);
      pLog = this->pLog;
      v5 = v10;
    }
    else
    {
      v5 = pfmt;
    }
    v6 = 212992;
    ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
      pLog,
      &v6,
      v5,
      (__int64 *)va);
  }
}

// File Line: 200
// RVA: 0x702920
void Scaleform::GFx::AS2::ActionLogger::LogScriptWarning(Scaleform::GFx::AS2::ActionLogger *this, char *pfmt, ...)
{
  Scaleform::Log *pLog; // rcx
  unsigned __int64 v4; // rax
  char *v5; // r8
  int v6; // [rsp+20h] [rbp-558h] BYREF
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-550h] BYREF
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-540h] BYREF
  __int64 v9; // [rsp+50h] [rbp-528h]
  char v10[256]; // [rsp+60h] [rbp-518h] BYREF
  Scaleform::MsgFormat v11; // [rsp+160h] [rbp-418h] BYREF
  va_list va; // [rsp+590h] [rbp+18h] BYREF

  va_start(va, pfmt);
  v9 = -2i64;
  pLog = this->pLog;
  if ( pLog )
  {
    if ( this->UseSuffix )
    {
      v4 = -1i64;
      do
        ++v4;
      while ( pfmt[v4] );
      if ( pfmt[v4 - 1] == 10 )
        --v4;
      r.Type = tDataPtr;
      r.SinkData.pStr = (Scaleform::String *)v10;
      r.SinkData.DataPtr.Size = 256i64;
      v.pStr = pfmt;
      v.Size = v4;
      Scaleform::MsgFormat::MsgFormat(&v11, &r);
      Scaleform::MsgFormat::Parse(&v11, "{0} : {1}\n");
      Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v11, &v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v11, &this->LogSuffix);
      Scaleform::MsgFormat::FinishFormatD(&v11);
      Scaleform::MsgFormat::~MsgFormat(&v11);
      pLog = this->pLog;
      v5 = v10;
    }
    else
    {
      v5 = pfmt;
    }
    v6 = 147456;
    ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
      pLog,
      &v6,
      v5,
      (__int64 *)va);
  }
}

// File Line: 239
// RVA: 0x6ECCA0
__int64 __fastcall Scaleform::GFx::AS2::GAS_Invoke(
        Scaleform::GFx::AS2::Value *method,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        int nargs,
        int firstArgBottomIndex,
        const char *pmethodName)
{
  char v10; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  unsigned __int8 v15; // bl
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int v18; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-58h] BYREF
  __int64 v23[3]; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v25; // [rsp+60h] [rbp-20h]
  char v26; // [rsp+68h] [rbp-18h]
  Scaleform::GFx::AS2::Environment *v27; // [rsp+70h] [rbp-10h]
  int v28; // [rsp+78h] [rbp-8h]
  int v29; // [rsp+7Ch] [rbp-4h]

  Scaleform::GFx::AS2::Value::ToFunction(method, &result, penv);
  if ( presult )
  {
    Scaleform::GFx::AS2::Value::DropRefs(presult);
    presult->T.Type = 0;
  }
  if ( result.Function )
  {
    v23[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
    v23[1] = (__int64)presult;
    v23[2] = (__int64)pthis;
    v26 = 0;
    v24 = 0i64;
    v25 = 0i64;
    v27 = penv;
    v28 = nargs;
    v29 = firstArgBottomIndex;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64 *, Scaleform::GFx::AS2::LocalFrame *, const char *, __int64))result.Function->vfptr[3].Finalize_GC)(
      result.Function,
      v23,
      result.pLocalFrame,
      pmethodName,
      -2i64);
    v23[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
    v10 = v26;
    if ( (v26 & 2) == 0 )
    {
      v11 = v24;
      if ( v24 )
      {
        RefCount = v24->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v24->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          v10 = v26;
        }
      }
    }
    v24 = 0i64;
    if ( (v10 & 1) == 0 )
    {
      v13 = v25;
      if ( v25 )
      {
        v14 = v25->RefCount;
        if ( (v14 & 0x3FFFFFF) != 0 )
        {
          v25->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
        }
      }
    }
    v25 = 0i64;
    v23[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
  Flags = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    Function = result.Function;
    if ( result.Function )
    {
      v18 = result.Function->RefCount;
      if ( (v18 & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v20 = result.pLocalFrame->RefCount;
      if ( (v20 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  return v15;
}

// File Line: 309
// RVA: 0x6ED500
char __fastcall Scaleform::GFx::AS2::GAS_InvokeParsed(
        const char *pmethodName,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASString *String; // rax
  bool v8; // r14
  Scaleform::GFx::ASStringNode *v9; // rcx
  char v11; // bl
  char *v12; // rcx
  __int64 v13; // rax
  char Type; // al
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // rcx
  int v18; // eax
  Scaleform::GFx::AS2::Value v20; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value presulta; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value method; // [rsp+88h] [rbp-1h] BYREF
  Scaleform::GFx::InteractiveObject *ppnewTarget; // [rsp+E0h] [rbp+57h] BYREF

  v20.V.pStringNode = (Scaleform::GFx::ASStringNode *)-2i64;
  if ( !pmethodName || !*pmethodName )
    return 0;
  ppnewTarget = 0i64;
  method.T.Type = 0;
  presulta.V.BooleanValue = 0;
  String = Scaleform::GFx::AS2::Environment::CreateString(penv, (Scaleform::GFx::ASString *)&v20, pmethodName);
  v8 = !Scaleform::GFx::AS2::Environment::GetVariable(
          penv,
          String,
          &method,
          0i64,
          &ppnewTarget,
          (Scaleform::GFx::AS2::Value *)&presulta.NV.8,
          0);
  v9 = *(Scaleform::GFx::ASStringNode **)&v20.T.Type;
  if ( (*(_DWORD *)(*(_QWORD *)&v20.T.Type + 24i64))-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v8 )
  {
    v11 = 0;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)(&v20.NV + 1), penv);
    if ( v20.V.FunctionValue.pLocalFrame )
    {
      if ( (unsigned __int8)(presulta.V.BooleanValue - 6) <= 1u )
      {
        pthis = Scaleform::GFx::AS2::Value::ToObjectInterface((Scaleform::GFx::AS2::Value *)&presulta.NV.8, penv);
      }
      else if ( ppnewTarget )
      {
        v12 = (char *)ppnewTarget + 4 * (unsigned __int8)ppnewTarget->AvmObjOffset;
        v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
        if ( v13 )
          pthis = (Scaleform::GFx::AS2::ObjectInterface *)(v13 + 8);
        else
          pthis = 0i64;
      }
      v11 = Scaleform::GFx::AS2::GAS_InvokeParsed(&method, presult, pthis, penv);
    }
    else
    {
      v11 = 0;
    }
    Type = presulta.T.Type;
    if ( (presulta.T.Type & 2) == 0 )
    {
      pLocalFrame = v20.V.FunctionValue.pLocalFrame;
      if ( v20.V.FunctionValue.pLocalFrame )
      {
        RefCount = v20.V.FunctionValue.pLocalFrame->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v20.V.FunctionValue.pLocalFrame->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          Type = presulta.T.Type;
        }
      }
    }
    v20.V.FunctionValue.pLocalFrame = 0i64;
    if ( (Type & 1) == 0 )
    {
      v17 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)*((_QWORD *)&v20.NV + 3);
      if ( *((_QWORD *)&v20.NV + 3) )
      {
        v18 = *(_DWORD *)(*((_QWORD *)&v20.NV + 3) + 24i64);
        if ( (v18 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*((_QWORD *)&v20.NV + 3) + 24i64) = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
    }
    *((_QWORD *)&v20.NV + 3) = 0i64;
  }
  if ( presulta.V.BooleanValue >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&presulta.NV.8);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  return v11;
}

// File Line: 358
// RVA: 0x6ED000
__int64 __fastcall Scaleform::GFx::AS2::GAS_InvokeParsed(
        Scaleform::GFx::AS2::Value *method,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v4; // r13
  int v5; // edi
  const char *v6; // r15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  int v8; // edx
  char v9; // cl
  char *v10; // rdi
  const char **v11; // r14
  __int64 v12; // rsi
  char *v13; // r12
  char v14; // al
  __int64 pCurrent; // rcx
  int v16; // eax
  char Type; // si
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value *v19; // rax
  bool v20; // si
  Scaleform::GFx::AS2::Value *v21; // rax
  __int64 v22; // xmm6_8
  __int64 v23; // rax
  char v24; // al
  __int64 v25; // xmm6_8
  __int64 v26; // rax
  Scaleform::GFx::ASString *v27; // rsi
  __int64 v28; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  char v31; // al
  Scaleform::GFx::ASString *v32; // rsi
  __int64 v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rax
  char i; // al
  unsigned int v37; // r14d
  unsigned int v38; // r15d
  __int64 v39; // r13
  Scaleform::GFx::AS2::Value *v40; // r12
  unsigned __int64 Size; // r9
  __int64 v42; // r8
  Scaleform::GFx::AS2::Value *v43; // rsi
  unsigned __int8 j; // si
  Scaleform::GFx::AS2::Value *v45; // rcx
  Scaleform::GFx::ASString result; // [rsp+0h] [rbp-61h] BYREF
  Scaleform::GFx::ASString v48; // [rsp+8h] [rbp-59h] BYREF
  __int64 v49; // [rsp+10h] [rbp-51h]
  Scaleform::GFx::AS2::Value *v50; // [rsp+18h] [rbp-49h]
  int nargs[2]; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value *methoda; // [rsp+B0h] [rbp+4Fh]
  Scaleform::GFx::AS2::Value *presulta; // [rsp+B8h] [rbp+57h]
  Scaleform::GFx::AS2::ObjectInterface *pthisa; // [rsp+C0h] [rbp+5Fh]
  Scaleform::GFx::AS2::Environment *v56; // [rsp+C8h] [rbp+67h]
  const char *v57; // [rsp+D0h] [rbp+6Fh]
  __int64 v58; // [rsp+D8h] [rbp+77h]
  char *vars0; // [rsp+E0h] [rbp+7Fh]

  v49 = -2i64;
  v4 = penv;
  v5 = 0;
  v6 = v57;
  if ( v57 )
  {
    p_Stack = &penv->Stack;
    v8 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    LODWORD(v57) = v8;
    v9 = *v6;
    v10 = (char *)(v6 + 1);
    if ( *v6 )
    {
      v11 = (const char **)(v58 - 8);
      v12 = 0x100100000200i64;
      v13 = vars0;
      while ( 1 )
      {
        if ( v9 == 37 )
        {
          v14 = *v10++;
          switch ( v14 )
          {
            case d:
              ++v11;
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              pCurrent = (__int64)p_Stack->pCurrent;
              v50 = (Scaleform::GFx::AS2::Value *)pCurrent;
              *(_QWORD *)nargs = pCurrent;
              if ( pCurrent )
              {
                v16 = *(_DWORD *)v11;
                *(_BYTE *)pCurrent = 4;
                *(_DWORD *)(pCurrent + 8) = v16;
              }
              break;
            case u:
              Type = 0;
              v.T.Type = 0;
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v18 = p_Stack->pCurrent;
              *(_QWORD *)nargs = v18;
              v50 = v18;
              if ( v18 )
              {
                Scaleform::GFx::AS2::Value::Value(v18, &v);
                Type = v.T.Type;
              }
              if ( (unsigned __int8)Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v);
LABEL_62:
              v12 = 0x100100000200i64;
              break;
            case n:
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v19 = p_Stack->pCurrent;
              *(_QWORD *)nargs = v19;
              v50 = v19;
              if ( v19 )
                v19->T.Type = 1;
              break;
            case b:
              v20 = *(_DWORD *)++v11 != 0;
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v21 = p_Stack->pCurrent;
              *(_QWORD *)nargs = v21;
              v50 = v21;
              if ( v21 )
              {
                v21->T.Type = 2;
                v21->V.BooleanValue = v20;
              }
              goto LABEL_62;
            case f:
              v22 = (__int64)*++v11;
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v23 = (__int64)p_Stack->pCurrent;
              *(_QWORD *)nargs = v23;
              v50 = (Scaleform::GFx::AS2::Value *)v23;
              if ( v23 )
              {
                *(_BYTE *)v23 = 3;
                *(_QWORD *)(v23 + 8) = v22;
              }
              break;
            case h:
              v24 = *v10++;
              if ( v24 == 102 )
              {
                v25 = (__int64)*++v11;
                if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
                v26 = (__int64)p_Stack->pCurrent;
                *(_QWORD *)nargs = v26;
                v50 = (Scaleform::GFx::AS2::Value *)v26;
                if ( v26 )
                {
                  *(_BYTE *)v26 = 3;
                  *(_QWORD *)(v26 + 8) = v25;
                }
              }
              else
              {
                nargs[0] = v24;
                Scaleform::GFx::AS2::Environment::LogScriptError(
                  v4,
                  "InvokeParsed(%s,%s) - invalid format %%h%c",
                  v13,
                  v6,
                  *(_QWORD *)nargs);
              }
              break;
            case s:
              v27 = Scaleform::GFx::AS2::Environment::CreateString(v4, &result, *++v11);
              if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v28 = (__int64)p_Stack->pCurrent;
              *(_QWORD *)nargs = v28;
              v50 = (Scaleform::GFx::AS2::Value *)v28;
              if ( v28 )
              {
                *(_BYTE *)v28 = 5;
                pNode = v27->pNode;
                *(Scaleform::GFx::ASString *)(v28 + 8) = (Scaleform::GFx::ASString)v27->pNode;
                ++pNode->RefCount;
              }
              v30 = result.pNode;
LABEL_60:
              if ( v30->RefCount-- == 1 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v30);
              goto LABEL_62;
            case l:
              v31 = *v10++;
              if ( v31 == 115 )
              {
                v32 = Scaleform::GFx::AS2::Environment::CreateString(v4, &v48, (const wchar_t *)*++v11);
                if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
                v33 = (__int64)p_Stack->pCurrent;
                *(_QWORD *)nargs = v33;
                v50 = (Scaleform::GFx::AS2::Value *)v33;
                if ( v33 )
                {
                  *(_BYTE *)v33 = 5;
                  v34 = v32->pNode;
                  *(Scaleform::GFx::ASString *)(v33 + 8) = (Scaleform::GFx::ASString)v32->pNode;
                  ++v34->RefCount;
                }
                v30 = v48.pNode;
                goto LABEL_60;
              }
              nargs[0] = v31;
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v4,
                "InvokeParsed(%s,%s) - invalid format %%l%c",
                v13,
                v6,
                *(_QWORD *)nargs);
              break;
            default:
              nargs[0] = v14;
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v4,
                "InvokeParsed(%s,%s) - invalid format %%%c",
                v13,
                v6,
                *(_QWORD *)nargs);
              break;
          }
        }
        else
        {
          nargs[0] = v9;
          Scaleform::GFx::AS2::Environment::LogScriptError(
            v4,
            "InvokeParsed(%s,%s) - invalid char %c",
            v13,
            v6,
            *(_QWORD *)nargs);
        }
        for ( i = *v10; *v10; i = *++v10 )
        {
          if ( (unsigned __int8)i > 0x2Cu )
            break;
          if ( !_bittest64(&v12, i) )
            break;
        }
        v9 = *v10++;
        if ( !v9 )
        {
          v8 = (int)v57;
          break;
        }
      }
    }
    v5 = 32 * p_Stack->Pages.Data.Size + p_Stack->pCurrent - p_Stack->pPageStart - v8 - 32;
    if ( v5 >> 1 > 0 )
    {
      v37 = v8 + 1;
      v38 = 32 * p_Stack->Pages.Data.Size + p_Stack->pCurrent - p_Stack->pPageStart - 32;
      v39 = (unsigned int)(v5 >> 1);
      do
      {
        v40 = 0i64;
        Size = p_Stack->Pages.Data.Size;
        v42 = p_Stack->pCurrent - p_Stack->pPageStart;
        if ( v38 <= (int)v42 + 32 * ((int)Size - 1) )
          v40 = &p_Stack->Pages.Data.Data[v38 >> 5]->Values[v38 & 0x1F];
        v43 = 0i64;
        if ( v37 <= (int)v42 + 32 * ((int)Size - 1) )
          v43 = &p_Stack->Pages.Data.Data[v37 >> 5]->Values[v37 & 0x1F];
        Scaleform::GFx::AS2::Value::Value(&v, v43);
        Scaleform::GFx::AS2::Value::operator=(v43, v40);
        Scaleform::GFx::AS2::Value::operator=(v40, &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        ++v37;
        --v38;
        --v39;
      }
      while ( v39 );
      v4 = v56;
    }
  }
  for ( j = Scaleform::GFx::AS2::GAS_Invoke(
              methoda,
              presulta,
              pthisa,
              v4,
              v5,
              32 * LODWORD(v4->Stack.Pages.Data.Size) - 32 + (unsigned int)(v4->Stack.pCurrent - v4->Stack.pPageStart),
              vars0); v5; --v5 )
  {
    v45 = v4->Stack.pCurrent;
    if ( v45->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v45);
    if ( --v4->Stack.pCurrent < v4->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
  }
  return j;
}

// File Line: 489
// RVA: 0x6ECE30
char __fastcall Scaleform::GFx::AS2::GAS_Invoke(
        const char *pmethodName,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASString *v8; // rax
  bool v9; // r14
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v12; // bl
  char *v13; // rcx
  __int64 v14; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::InteractiveObject **ppnewTarget; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::FunctionRef powner; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+40h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value presulta; // [rsp+60h] [rbp-1h] BYREF
  Scaleform::GFx::InteractiveObject *v26; // [rsp+B8h] [rbp+57h] BYREF
  void *retaddr; // [rsp+D8h] [rbp+77h]
  int v28; // [rsp+E0h] [rbp+7Fh]

  ppnewTarget = (Scaleform::GFx::InteractiveObject **)-2i64;
  if ( !pmethodName || !*pmethodName )
    return 0;
  v26 = 0i64;
  presulta.T.Type = 0;
  v24.T.Type = 0;
  v8 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, pmethodName);
  v9 = !Scaleform::GFx::AS2::Environment::GetVariable(penv, v8, &presulta, 0i64, &v26, &v24, 0);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v9 )
  {
    v12 = 0;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToFunction(&presulta, &powner, penv);
    if ( powner.Function )
    {
      if ( (unsigned __int8)(v24.T.Type - 6) <= 1u )
      {
        pthis = Scaleform::GFx::AS2::Value::ToObjectInterface(&v24, penv);
      }
      else if ( v26 )
      {
        v13 = (char *)v26 + 4 * (unsigned __int8)v26->AvmObjOffset;
        v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
        if ( v14 )
          pthis = (Scaleform::GFx::AS2::ObjectInterface *)(v14 + 8);
        else
          pthis = 0i64;
      }
      v12 = Scaleform::GFx::AS2::GAS_Invoke(&presulta, presult, pthis, penv, (int)retaddr, v28, pmethodName);
    }
    else
    {
      v12 = 0;
    }
    Flags = powner.Flags;
    if ( (powner.Flags & 2) == 0 )
    {
      Function = powner.Function;
      if ( powner.Function )
      {
        RefCount = powner.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          powner.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = powner.Flags;
        }
      }
    }
    powner.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = powner.pLocalFrame;
      if ( powner.pLocalFrame )
      {
        v19 = powner.pLocalFrame->RefCount;
        if ( (v19 & 0x3FFFFFF) != 0 )
        {
          powner.pLocalFrame->RefCount = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    powner.pLocalFrame = 0i64;
  }
  if ( v24.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v24);
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v12;
}

// File Line: 540
// RVA: 0x6B4B50
void __fastcall Scaleform::GFx::AS2::GAS_GlobalTrace(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  unsigned int v10; // r9d
  Scaleform::GFx::AS2::Environment *v11; // r8
  unsigned __int64 Size; // rdi
  char *i; // rax
  const char *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS2::Value method; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS2::Value presult; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v18; // [rsp+80h] [rbp-80h]
  char _Dst[2016]; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::ASString v20; // [rsp+880h] [rbp+780h] BYREF
  Scaleform::GFx::ASString result; // [rsp+888h] [rbp+788h] BYREF

  v18 = -2i64;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v4 = 0i64;
  v5 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, Env);
  v7 = v6;
  if ( v6 )
  {
    method.T.Type = 0;
    if ( v6->vfptr->GetMemberRaw(
           v6,
           &fn->Env->StringContext,
           (Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25],
           &method)
      && (method.T.Type == 8 || method.T.Type == 11) )
    {
      presult.T.Type = 0;
      Scaleform::GFx::AS2::GAS_Invoke(
        &method,
        &presult,
        v7,
        fn->Env,
        0,
        32 * fn->Env->Stack.Pages.Data.Size - 31 + fn->Env->Stack.pCurrent - fn->Env->Stack.pPageStart,
        0i64);
      Scaleform::GFx::AS2::Value::ToString(&presult, &result, fn->Env, -1);
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(fn, "%s\n", result.pNode->pData);
      pNode = result.pNode;
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( presult.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&presult);
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
      return;
    }
    if ( method.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&method);
  }
  v10 = fn->FirstArgBottomIndex;
  v11 = fn->Env;
  if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
            + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
    v4 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v4, &v20, v11, -1);
  Size = v20.pNode->Size;
  if ( v20.pNode->Size >= 0x7D0 )
    Size = 1999i64;
  strncpy_s(_Dst, 0x7D0ui64, v20.pNode->pData, Size);
  _Dst[Size] = 0;
  for ( i = _Dst; *i; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  v14 = "%s\n";
  if ( v20.pNode->Size >= 0x7D0 )
    v14 = "%s ...<truncated>\n";
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(fn, v14, _Dst);
  v15 = v20.pNode;
  v9 = v20.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 584
// RVA: 0x6B5450
void __fastcall Scaleform::GFx::AS2::GAS_GlobalParseInt(Scaleform::GFx::AS2::FnCall *fn)
{
  int v2; // esi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASStringNode *pNode; // rax
  unsigned int v7; // ebx
  unsigned int v8; // r10d
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  long double v11; // xmm6_8
  Scaleform::GFx::AS2::Value *v12; // rbx
  char v13; // dl
  __int64 v14; // rdx
  char *v15; // rbx
  int v16; // ebp
  long double v17; // xmm0_8
  Scaleform::GFx::AS2::Value *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  char *endptr; // [rsp+68h] [rbp+10h] BYREF

  if ( fn->NArgs >= 1 )
  {
    v2 = 10;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    pNode = result.pNode;
    v7 = 0;
    if ( fn->NArgs < 2 )
    {
      if ( result.pNode->Size > 1 && *result.pNode->pData == 48 )
      {
        v7 = 1;
        v2 = 8;
        v13 = *((_BYTE *)result.pNode->pData + 1);
        if ( v13 == 120 || v13 == 88 )
        {
          v2 = 16;
          v7 = 2;
        }
      }
    }
    else
    {
      v8 = fn->FirstArgBottomIndex - 1;
      v9 = fn->Env;
      v10 = 0i64;
      if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
               + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
        v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
      v2 = Scaleform::GFx::AS2::Value::ToInt32(v10, v9);
      if ( (unsigned int)(v2 - 2) > 0x22 )
      {
        v11 = Scaleform::GFx::NumberUtil::NaN();
        v12 = fn->Result;
        if ( v12->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v12->T.Type = 3;
        v12->NV.NumberValue = v11;
LABEL_23:
        v19 = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        return;
      }
      pNode = result.pNode;
    }
    v14 = v7;
    v15 = (char *)&pNode->pData[v7];
    endptr = 0i64;
    v16 = strtol(&pNode->pData[v14], &endptr, v2);
    if ( v15 != endptr || v2 == 8 )
    {
      v18 = fn->Result;
      if ( v18->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
      v18->T.Type = 4;
      v18->NV.Int32Value = v16;
    }
    else
    {
      v17 = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v17);
    }
    goto LABEL_23;
  }
}

// File Line: 645
// RVA: 0x6B7640
void __fastcall Scaleform::GFx::AS2::GAS_GlobalParseFloat(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  char *pData; // rbx
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char *tailptr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
    pData = (char *)result.pNode->pData;
    tailptr = 0i64;
    v6 = Scaleform::SFstrtod(result.pNode->pData, &tailptr);
    if ( pData == tailptr )
      v6 = Scaleform::GFx::NumberUtil::NaN();
    v7 = fn->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 658
// RVA: 0x6B7720
void __fastcall Scaleform::GFx::AS2::GAS_GlobalIfFrameLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  void *Target; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  int v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // rbx

  if ( fn->NArgs >= 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 0;
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 2 )
        return;
      Target = fn->ThisPtr;
    }
    else
    {
      Target = fn->Env->Target;
    }
    if ( Target )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      v7 = 0i64;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToInt32(v7, Env);
      if ( v8 < (*(int (__fastcall **)(void *))(*(_QWORD *)Target + 888i64))(Target) )
      {
        v9 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v9);
        v9->T.Type = 2;
        v9->V.BooleanValue = 1;
      }
    }
  }
}

// File Line: 682
// RVA: 0x6B7C40
void __fastcall Scaleform::GFx::AS2::GAS_GlobalIsNaN(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  char v5; // di
  Scaleform::GFx::AS2::Value *v6; // r9
  long double v7; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v5 = 0;
    v6 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToNumber(v6, Env);
    if ( (*(_QWORD *)&v7 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&v7 & 0xFFFFFFFFFFFFFi64) != 0 )
      v5 = 1;
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v5;
    Result->T.Type = 2;
  }
  else
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->V.BooleanValue = 1;
    v2->T.Type = 2;
  }
}

// File Line: 691
// RVA: 0x6B7E10
void __fastcall Scaleform::GFx::AS2::GAS_GlobalIsFinite(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v5; // r9
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v5 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
    if ( ((*(_QWORD *)&v6 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&v6 & 0xFFFFFFFFFFFFFi64) == 0)
      && v6 != -INFINITY
      && v6 != INFINITY )
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->V.BooleanValue = 1;
      Result->T.Type = 2;
      return;
    }
    v2 = fn->Result;
  }
  else
  {
    v2 = fn->Result;
  }
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->V.BooleanValue = 0;
  v2->T.Type = 2;
}

// File Line: 711
// RVA: 0x6B8060
void __fastcall Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  int SWFVersion; // r14d
  unsigned int FirstArgBottomIndex; // r10d
  __int64 v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // r15
  unsigned int v8; // r8d
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rbx
  char Type; // al
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *v14; // rax
  Scaleform::GFx::AS2::ArrayObject *v15; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  unsigned int v19; // r9d
  Scaleform::GFx::AS2::Environment *v20; // rdx
  Scaleform::GFx::AS2::Value *v21; // r10
  Scaleform::GFx::AS2::Object *v22; // rax
  __int64 v23; // r14
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // rcx
  unsigned int v29; // r9d
  Scaleform::GFx::AS2::Environment *v30; // rdx
  Scaleform::GFx::AS2::Value *v31; // r10
  int v32; // eax
  char v33; // si
  unsigned int v34; // r9d
  Scaleform::GFx::AS2::Environment *v35; // rdx
  Scaleform::GFx::AS2::Value *v36; // r10
  char v37; // si
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  __int64 RootIndex; // r12
  Scaleform::GFx::AS2::Value *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // rcx
  unsigned int v42; // eax
  Scaleform::GFx::AS2::Value v43; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> v44; // [rsp+B0h] [rbp+48h] BYREF
  __int64 v45; // [rsp+B8h] [rbp+50h]
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+58h] BYREF
  Scaleform::GFx::ASString v47; // [rsp+C8h] [rbp+60h] BYREF

  Env = fn->Env;
  SWFVersion = (unsigned __int8)Env->StringContext.SWFVersion;
  LODWORD(v44.pObject) = SWFVersion;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  v5 = 0i64;
  v6 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v7 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObjectInterface(v6, Env);
  if ( v7 )
  {
    v8 = fn->FirstArgBottomIndex - 1;
    v9 = fn->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    pObject = 0i64;
    v45 = 0i64;
    Type = v10->T.Type;
    if ( v10->T.Type == 5 )
    {
      v13 = Scaleform::GFx::AS2::Value::ToString(v10, &result, fn->Env, -1);
      v14 = Scaleform::GFx::AS2::StringProto::StringSplit(&v44, fn->Env, v13, ",", 0x3FFFFFFF);
      if ( v14->pObject )
        v14->pObject->RefCount = (v14->pObject->RefCount + 1) & 0x8FFFFFFF;
      pObject = v14->pObject;
      v45 = (__int64)v14->pObject;
      v15 = v44.pObject;
      if ( v44.pObject )
      {
        RefCount = v44.pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v44.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
        }
      }
      pNode = result.pNode;
      v18 = result.pNode->RefCount-- == 1;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_31;
    }
    if ( Type == 6 )
    {
      v19 = fn->FirstArgBottomIndex - 1;
      v20 = fn->Env;
      v21 = 0i64;
      if ( v19 <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v20->Stack.pCurrent - v20->Stack.pPageStart) )
        v21 = &v20->Stack.Pages.Data.Data[v19 >> 5]->Values[v19 & 0x1F];
      v22 = Scaleform::GFx::AS2::Value::ToObject(v21, v20);
      v23 = (__int64)v22;
      if ( !v22 )
        goto LABEL_30;
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v22->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v22->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        *(_DWORD *)(v23 + 24) = (*(_DWORD *)(v23 + 24) + 1) & 0x8FFFFFFF;
        pObject = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v23;
        v45 = v23;
LABEL_30:
        SWFVersion = (int)v44.pObject;
LABEL_31:
        v29 = fn->FirstArgBottomIndex - 2;
        v30 = fn->Env;
        v31 = 0i64;
        if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v30->Stack.pCurrent - v30->Stack.pPageStart) )
          v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
        v32 = Scaleform::GFx::AS2::Value::ToInt32(v31, v30);
        LOBYTE(v32) = v32 & 7;
        LODWORD(v44.pObject) = v32;
        if ( fn->NArgs == 3 )
        {
          v33 = 0;
          if ( SWFVersion == 5 )
            v33 = -1;
        }
        else
        {
          v34 = fn->FirstArgBottomIndex - 3;
          v35 = fn->Env;
          v36 = 0i64;
          if ( v34 <= 32 * ((unsigned int)v35->Stack.Pages.Data.Size - 1)
                    + (unsigned int)(v35->Stack.pCurrent - v35->Stack.pPageStart) )
            v36 = &v35->Stack.Pages.Data.Data[v34 >> 5]->Values[v34 & 0x1F];
          v33 = Scaleform::GFx::AS2::Value::ToUInt32(v36, v35);
          LOBYTE(v32) = v44.pObject;
        }
        v37 = v33 & 7;
        p_StringContext = &fn->Env->StringContext;
        if ( pObject )
        {
          RootIndex = (int)pObject[3].RootIndex;
          if ( RootIndex > 0 )
          {
            do
            {
              v40 = (Scaleform::GFx::AS2::Value *)(&pObject[3].pRCC->$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v5];
              if ( v40 )
              {
                Scaleform::GFx::AS2::Value::ToString(v40, &result, fn->Env, -1);
                v43.T = 0;
                if ( (*((unsigned __int8 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v7->pData
                      + 5))(
                       v7,
                       p_StringContext,
                       &result,
                       &v43) )
                {
                  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))v7->pData
                   + 7))(
                    v7,
                    p_StringContext,
                    &result,
                    (unsigned __int8)(LOBYTE(v44.pObject) | v43.T.PropFlags & ~v37));
                }
                if ( v43.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v43);
                v41 = result.pNode;
                v18 = result.pNode->RefCount-- == 1;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v41);
              }
              ++v5;
            }
            while ( v5 < RootIndex );
          }
        }
        else
        {
          *(_QWORD *)&v43.T.Type = `Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags::`27::MemberVisitor::`vftable;
          v43.V.pStringNode = v7;
          v43.V.FunctionValue.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)p_StringContext;
          v43.V.FunctionValue.Flags = v32;
          *((_BYTE *)&v43.NV + 25) = v37;
          (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *, __int64, _QWORD))v7->pData
           + 8))(
            v7,
            p_StringContext,
            &v43,
            12i64,
            0i64);
          *(_QWORD *)&v43.T.Type = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
        }
        goto LABEL_51;
      }
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)(v23 + 32) + 16i64))(v23 + 32) == 8 )
      {
        v24 = Scaleform::GFx::AS2::Value::ToString(v10, &v47, fn->Env, -1);
        v25 = Scaleform::GFx::AS2::StringProto::StringSplit(
                (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&result,
                fn->Env,
                v24,
                ",",
                0x3FFFFFFF);
        if ( v25->pObject )
          v25->pObject->RefCount = (v25->pObject->RefCount + 1) & 0x8FFFFFFF;
        pObject = v25->pObject;
        v45 = (__int64)v25->pObject;
        v26 = result.pNode;
        if ( result.pNode )
        {
          v27 = result.pNode->RefCount;
          if ( (v27 & 0x3FFFFFF) != 0 )
          {
            result.pNode->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v26);
          }
        }
        v28 = v47.pNode;
        v18 = v47.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
        goto LABEL_30;
      }
    }
    else if ( Type == 1 )
    {
      goto LABEL_31;
    }
LABEL_51:
    if ( pObject )
    {
      v42 = pObject->RefCount;
      if ( (v42 & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 778
// RVA: 0x723970
void __fastcall Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags_::_27_::MemberVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *__formal,
        char flags,
        char a4)
{
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::Value *, _QWORD))name[1].pNode->pData
   + 7))(
    name[1].pNode,
    name[2].pNode,
    __formal,
    (unsigned __int8)(LOBYTE(name[3].pNode) | a4 & ~BYTE1(name[3].pNode)));
}

// File Line: 810
// RVA: 0x6ECBF0
void __fastcall Scaleform::GFx::AS2::GAS_ASnativeMouseButtonStates(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::Environment *v6; // rcx
  Scaleform::GFx::AS2::Value *Result; // rdi
  unsigned int v8; // esi
  unsigned int CurButtonsState; // ebx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
    v6 = fn->Env;
    Result = fn->Result;
    v8 = v5;
    CurButtonsState = v6->Target->pASRoot->pMovieImpl->mMouseState[0].CurButtonsState;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = (v8 & CurButtonsState) == v8;
  }
}

// File Line: 821
// RVA: 0x6BB390
void __fastcall Scaleform::GFx::AS2::GAS_GlobalASnative(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v5; // r9
  unsigned int v6; // ebx
  unsigned int v7; // r10d
  Scaleform::GFx::AS2::Environment *v8; // r11
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // eax
  __int64 v11; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v12; // rax
  Scaleform::GFx::AS2::FunctionObject *v13; // rax
  Scaleform::GFx::AS2::FunctionObject *v14; // rbx
  unsigned int RefCount; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::FunctionRefBase func; // [rsp+28h] [rbp-20h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs >= 2 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToUInt32(v5, Env);
    v7 = fn->FirstArgBottomIndex - 1;
    v8 = fn->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v8->Stack.pCurrent - v8->Stack.pPageStart) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, fn->Env);
    if ( v6 == 800 && v10 == 2 )
    {
      v12 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                      v11,
                                                      104i64);
      if ( v12 )
      {
        Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
          v12,
          &fn->Env->StringContext,
          Scaleform::GFx::AS2::GAS_ASnativeMouseButtonStates);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      func.Flags = 0;
      func.Function = v14;
      if ( v14 )
        v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
      func.pLocalFrame = 0i64;
      Scaleform::GFx::AS2::Value::SetAsFunction(fn->Result, &func);
      if ( v14 )
      {
        RefCount = v14->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v14->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
        }
      }
      func.Function = 0i64;
      func.pLocalFrame = 0i64;
      if ( v14 )
      {
        v16 = v14->RefCount;
        if ( (v16 & 0x3FFFFFF) != 0 )
        {
          v14->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
        }
      }
    }
  }
}

// File Line: 837
// RVA: 0x6A6A00
void __fastcall Scaleform::GFx::AS2::GAS_GlobalEscape(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::String pescapedStr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v14; // [rsp+60h] [rbp+18h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    Scaleform::String::String(&pescapedStr);
    Scaleform::GFx::ASUtils::Escape(result.pNode->pData, result.pNode->Size, &pescapedStr);
    v6 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &v14, &pescapedStr);
    v7 = fn->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    pNode = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++pNode->RefCount;
    v9 = v14.pNode;
    v10 = v14.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v11 = result.pNode;
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
}

// File Line: 848
// RVA: 0x6A6B20
void __fastcall Scaleform::GFx::AS2::GAS_GlobalUnescape(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v14; // [rsp+60h] [rbp+18h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    Scaleform::String::String(&punescapedStr);
    Scaleform::GFx::ASUtils::Unescape(result.pNode->pData, result.pNode->Size, &punescapedStr);
    v6 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &v14, &punescapedStr);
    v7 = fn->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    pNode = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++pNode->RefCount;
    v9 = v14.pNode;
    v10 = v14.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v11 = result.pNode;
    v10 = result.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
}

// File Line: 861
// RVA: 0x6A6C40
void __fastcall Scaleform::GFx::AS2::GAS_GlobalEscapeSpecialHTML(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  const char *pData; // rdi
  unsigned int Length; // eax
  Scaleform::GFx::ASString *v8; // r14
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::String pescapedStr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v16; // [rsp+60h] [rbp+18h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    Scaleform::String::String(&pescapedStr);
    pData = result.pNode->pData;
    Length = Scaleform::GFx::ASConstString::GetLength(&result);
    Scaleform::String::EscapeSpecialHTML(pData, Length, &pescapedStr);
    v8 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &v16, &pescapedStr);
    v9 = fn->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v9->T.Type = 5;
    pNode = v8->pNode;
    v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++pNode->RefCount;
    v11 = v16.pNode;
    v12 = v16.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = result.pNode;
    v12 = result.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 873
// RVA: 0x6A6D70
void __fastcall Scaleform::GFx::AS2::GAS_GlobalUnescapeSpecialHTML(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  const char *pData; // rdi
  unsigned int Length; // eax
  Scaleform::GFx::ASString *v8; // r14
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v16; // [rsp+60h] [rbp+18h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v5 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, Env, -1);
    Scaleform::String::String(&punescapedStr);
    pData = result.pNode->pData;
    Length = Scaleform::GFx::ASConstString::GetLength(&result);
    Scaleform::String::UnescapeSpecialHTML(pData, Length, &punescapedStr);
    v8 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &v16, &punescapedStr);
    v9 = fn->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v9->T.Type = 5;
    pNode = v8->pNode;
    v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++pNode->RefCount;
    v11 = v16.pNode;
    v12 = v16.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = result.pNode;
    v12 = result.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 1083
// RVA: 0x6D9250
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::GlobalContext::AddPackage(
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pparent,
        Scaleform::GFx::AS2::Object *objProto,
        const char *packageName)
{
  Scaleform::GFx::AS2::Object *v5; // rdi
  __int64 v6; // r14
  const char *v7; // r12
  char *v8; // rax
  char *v9; // rsi
  unsigned __int64 v10; // rbx
  __int64 v11; // rcx
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::AS2::Value *v16; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v20; // eax
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value v23; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+68h] [rbp-98h]
  __int64 v25; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS2::Object *v26; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS2::Value v27; // [rsp+80h] [rbp-80h] BYREF
  char Dst[200]; // [rsp+A0h] [rbp-60h] BYREF
  char v30; // [rsp+1F8h] [rbp+F8h] BYREF
  Scaleform::GFx::AS2::Object *proto; // [rsp+200h] [rbp+100h]
  Scaleform::GFx::ASString result; // [rsp+208h] [rbp+108h] BYREF

  proto = objProto;
  v25 = -2i64;
  v5 = pparent;
  v6 = -1i64;
  do
    ++v6;
  while ( packageName[v6] );
  v7 = packageName;
  if ( pparent )
    pparent->RefCount = (pparent->RefCount + 1) & 0x8FFFFFFF;
  if ( packageName )
  {
    do
    {
      v8 = strchr(v7, 46);
      v9 = v8;
      if ( v8 )
      {
        v10 = v8 - v7 + 1;
        v9 = v8 + 1;
      }
      else
      {
        v10 = (unsigned __int64)&packageName[v6 + 1 - (_QWORD)v7];
      }
      if ( v10 > 0x100 )
        v10 = 256i64;
      memmove(Dst, v7, v10 - 1);
      *((_BYTE *)&v27.NV + v10 + 31) = 0;
      v7 = v9;
      v23.T.Type = 0;
      Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &result, Dst);
      if ( v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
             &v5->Scaleform::GFx::AS2::ObjectInterface,
             psc,
             &result,
             &v23) )
      {
        v12 = Scaleform::GFx::AS2::Value::ToObject(&v23, 0i64);
        v13 = (Scaleform::GFx::ASStringNode *)v12;
        if ( v12 )
          v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
      }
      else
      {
        pHeap = psc->pContext->pHeap;
        v14 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v11, 96i64);
        v26 = v14;
        if ( v14 )
        {
          Scaleform::GFx::AS2::Object::Object(v14, psc, proto);
          v13 = v15;
        }
        else
        {
          v13 = 0i64;
        }
        Scaleform::GFx::AS2::Value::Value(&v27, v13);
        v30 = 0;
        v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
          &v5->Scaleform::GFx::AS2::ObjectInterface,
          psc,
          &result,
          v16,
          (Scaleform::GFx::AS2::PropFlags *)&v30);
        if ( v27.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v27);
      }
      if ( v13 )
        v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
      v5 = (Scaleform::GFx::AS2::Object *)v13;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v13 )
      {
        v20 = v13->RefCount;
        if ( (v20 & 0x3FFFFFF) != 0 )
        {
          v13->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v13);
        }
      }
      if ( v23.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v23);
    }
    while ( v9 );
  }
  if ( v5 )
  {
    v21 = v5->RefCount;
    if ( (v21 & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = v21 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  return v5;
}

// File Line: 1132
// RVA: 0x6C8900
void __fastcall Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // rdx

  pMovieRoot = pgc->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pGC = pgc;
}

// File Line: 1138
// RVA: 0x6F38F0
bool __fastcall Scaleform::GFx::AS2::GASGlobalObject::GetMemberRaw(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  char Type; // cl
  bool v6; // bl

  if ( name->pNode != (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[22].vfptr )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
  Type = this->ResolveHandler.pLocalFrame->Caller.T.Type;
  if ( Type )
  {
    v6 = Type == 1;
    Scaleform::GFx::AS2::Value::DropRefs(val);
    val->V.BooleanValue = v6;
    val->T.Type = 2;
    return 1;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 0;
    return 0;
  }
}

// File Line: 1153
// RVA: 0x717610
bool __fastcall Scaleform::GFx::AS2::GASGlobalObject::SetMember(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::AS2::GlobalContext *pLocalFrame; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // bl
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::GFx::MovieImpl *v21; // rbx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-58h] BYREF
  __int64 v23; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS2::Value vala; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::GFx::ASString v25; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+A0h] [rbp+18h] BYREF

  v23 = -2i64;
  pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[22].vfptr )
  {
    this->ResolveHandler.pLocalFrame->Caller.T.Type = !Scaleform::GFx::AS2::Value::ToBool(val, penv) + 1;
    pLocalFrame = (Scaleform::GFx::AS2::GlobalContext *)this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame->GFxExtensions.Value == 1 )
    {
      v12 = Scaleform::GFx::AS2::GlobalContext::CreateConstString(pLocalFrame, &result, "4.3.27");
      vala.T.Type = 5;
      vala.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v12->pNode;
      ++vala.V.pStringNode->RefCount;
      v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v26, "gfxVersion");
      LOBYTE(v25.pNode) = 0;
      ((void (__fastcall *)(Scaleform::GFx::AS2::GASGlobalObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].Finalize_GC)(
        this,
        &penv->StringContext,
        v13,
        &vala,
        &v25);
      v14 = v26.pNode;
      v15 = v26.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( vala.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&vala);
      v16 = result.pNode;
    }
    else
    {
      v17 = Scaleform::GFx::AS2::GlobalContext::CreateConstString(pLocalFrame, &v25, "gfxVersion");
      this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[2].ExecuteForEachChild_GC(
        this,
        (Scaleform::GFx::AS2::RefCountCollector<323> *)&penv->StringContext,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v17);
      v16 = v25.pNode;
    }
    v15 = v16->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    vala.T.Type = 10;
    v18 = Scaleform::GFx::AS2::Object::SetMember(this, penv, name, &vala, flags);
    if ( vala.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&vala);
    return v18;
  }
  else
  {
    if ( this->ResolveHandler.pLocalFrame->Caller.T.Type == 1 )
    {
      if ( pNode == *(Scaleform::GFx::ASStringNode **)&pObject[22].RefCount )
      {
        pMovieImpl = penv->Target->pASRoot->pMovieImpl;
        if ( pMovieImpl )
        {
          if ( Scaleform::GFx::AS2::Value::ToBool(val, penv) )
            pMovieImpl->Flags |= 0x800u;
          else
            pMovieImpl->Flags &= ~0x800u;
        }
      }
      else if ( pNode == (Scaleform::GFx::ASStringNode *)pObject[22].pMovieImpl )
      {
        v21 = penv->Target->pASRoot->pMovieImpl;
        if ( v21 )
        {
          if ( Scaleform::GFx::AS2::Value::ToBool(val, penv) )
            v21->Flags |= 0x2000u;
          else
            v21->Flags &= ~0x2000u;
        }
      }
    }
    return Scaleform::GFx::AS2::Object::SetMemberRaw(this, &penv->StringContext, name, val, flags);
  }
}

// File Line: 1224
// RVA: 0x6C90F0
void __fastcall Scaleform::GFx::AS2::GlobalContext::GlobalContext(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::MovieImpl *proot)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::AS2::GlobalContext,323>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable;
  this->Prototypes.mHash.pTable = 0i64;
  this->RegisteredClasses.mHash.pTable = 0i64;
  this->BuiltinClassesRegistry.mHash.pTable = 0i64;
  this->pGlobal.pObject = 0i64;
  this->GFxExtensions.Value = 0;
  this->StandardMemberMap.mHash.pTable = 0i64;
  Scaleform::GFx::AS2::GlobalContext::Init(this, proot);
}

// File Line: 1229
// RVA: 0x6FBBB0
void __fastcall Scaleform::GFx::AS2::GlobalContext::Init(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::MovieImpl *v2; // r13
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::GFx::AS2::GASGlobalObject *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::FunctionObject *v11; // r12
  Scaleform::GFx::AS2::Object *Prototype; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // r15
  Scaleform::GFx::AS2::Object *v17; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rsi
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::AS2::Object *v23; // rsi
  __int64 v24; // rsi
  unsigned __int64 v25; // r9
  __int64 v26; // rcx
  unsigned __int64 v27; // r9
  __int64 v28; // rcx
  Scaleform::GFx::AS2::Object *v29; // rax
  Scaleform::GFx::AS2::Object *v30; // r14
  Scaleform::GFx::AS2::Object *v31; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::MovieImpl *v34; // rax
  Scaleform::GFx::AS2::FunctionObject *v35; // rax
  Scaleform::GFx::AS2::FunctionObject *v36; // rbx
  Scaleform::GFx::AS2::Object *v37; // rax
  Scaleform::GFx::AS2::Object *v38; // r13
  Scaleform::GFx::AS2::Object *v39; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v40; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v41; // rcx
  unsigned int v42; // eax
  unsigned __int64 v43; // r9
  __int64 v44; // rcx
  Scaleform::GFx::MovieImpl *v45; // rax
  __int64 v46; // rdx
  unsigned __int64 v47; // rax
  Scaleform::GFx::AS2::Object *v48; // rax
  Scaleform::GFx::AS2::ObjectInterface *v49; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v50; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v51; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v52; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v53; // rcx
  Scaleform::GFx::AS2::Object *v54; // rax
  Scaleform::GFx::AS2::Object *v55; // rax
  Scaleform::GFx::AS2::Object *v56; // rax
  Scaleform::GFx::AS2::Object *v57; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v58; // rcx
  unsigned int v59; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v60; // rcx
  unsigned int v61; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v62; // rcx
  unsigned int v63; // eax
  unsigned int v64; // eax
  unsigned int v65; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v66; // rcx
  unsigned int v67; // eax
  Scaleform::GFx::AS2::Object *v68; // rcx
  unsigned int v69; // eax
  unsigned int v70; // eax
  unsigned int v71; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS2::Value key; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v74; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v75; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value v76; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v77; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v78; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v80; // [rsp+B8h] [rbp-48h] BYREF
  void **v81; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v82; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS2::ASStringContext *p_psc; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS2::FunctionRef v84; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v85; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS2::Value v86; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::GFx::MovieImpl *proota; // [rsp+188h] [rbp+88h] BYREF
  Scaleform::GFx::AS2::GASGlobalObject *flags; // [rsp+190h] [rbp+90h] BYREF
  Scaleform::GFx::AS2::Object *proto; // [rsp+198h] [rbp+98h] BYREF

  proota = proot;
  v85 = -2i64;
  v2 = proot;
  this->pMovieRoot = proot;
  pHeap = proot->pHeap;
  this->pHeap = pHeap;
  psc.pContext = this;
  psc.SWFVersion = 8;
  if ( !this->pGlobal.pObject )
  {
    v5 = (Scaleform::GFx::AS2::GASGlobalObject *)pHeap->vfptr->Alloc(pHeap, 104ui64, 0i64);
    flags = v5;
    if ( v5 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v5, this);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    pObject = this->pGlobal.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    this->pGlobal.pObject = v7;
  }
  v10 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                         this->pHeap,
                                         104i64);
  v11 = (Scaleform::GFx::AS2::FunctionObject *)v10;
  v74 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS2::Object::Object(v10, &psc);
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v11[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ObjectProto::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v11->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v76.T.Type = 10;
      v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v11->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v76,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v76.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v76);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    v13 = v11->pProto.pObject;
    if ( v13 )
    {
      v14 = v13->RefCount;
      if ( (v14 & 0x3FFFFFF) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v11->pProto.pObject = Prototype;
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &v11->Scaleform::GFx::AS2::ObjectInterface,
      &psc,
      Scaleform::GFx::AS2::ObjectCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v11 = 0i64;
  }
  constructor.Flags = 0;
  constructor.Function = v11;
  constructor.pLocalFrame = 0i64;
  v15 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                         this->pHeap,
                                         104i64);
  v16 = v15;
  v74 = v15;
  if ( v15 )
  {
    Scaleform::GFx::AS2::Object::Object(v15, &psc);
    v16->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v16->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v16->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v16->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v16[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::FunctionProto::GlobalCtor;
    v17 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v16->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v76.T.Type = 10;
      v16->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v16->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v76,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v76.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v76);
    }
    if ( v17 )
      v17->RefCount = (v17->RefCount + 1) & 0x8FFFFFFF;
    v18 = v16->pProto.pObject;
    if ( v18 )
    {
      v19 = v18->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        v18->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
    v16->pProto.pObject = v17;
    v16->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v16->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v16 = 0i64;
  }
  *((_BYTE *)&v76.NV + 16) = 0;
  *(_OWORD *)&v76.T.Type = (unsigned __int64)v16;
  v20 = (Scaleform::GFx::AS2::Object *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  v21 = v20;
  v74 = v20;
  if ( v20 )
  {
    Scaleform::GFx::AS2::Object::Object(v20, &psc);
    flags = (Scaleform::GFx::AS2::GASGlobalObject *)&v21[1];
    v21[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v21[1].RefCount) = 0;
    v21[1].pRCC = 0i64;
    v21[1].pPrev = 0i64;
    LOBYTE(v21[1].Members.mHash.pTable) = 0;
    v21[1].Scaleform::GFx::AS2::ObjectInterface::vfptr = 0i64;
    v21[1].pProto.pObject = 0i64;
    v21[1].ResolveHandler.Function = 0i64;
    v21->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v21->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v21[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v21[1],
      v21,
      &psc,
      &constructor);
    v21->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v21->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v21[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v21[1],
      v21,
      &psc,
      GAS_ObjectFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v21 = 0i64;
  }
  proto = v21;
  v22 = (Scaleform::GFx::AS2::Object *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  v23 = v22;
  v74 = v22;
  if ( v22 )
  {
    Scaleform::GFx::AS2::Object::Object(v22, &psc, proto);
    flags = (Scaleform::GFx::AS2::GASGlobalObject *)&v23[1];
    v23[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v23[1].RefCount) = 0;
    v23[1].pRCC = 0i64;
    v23[1].pPrev = 0i64;
    LOBYTE(v23[1].Members.mHash.pTable) = 0;
    v23[1].Scaleform::GFx::AS2::ObjectInterface::vfptr = 0i64;
    v23[1].pProto.pObject = 0i64;
    v23[1].ResolveHandler.Function = 0i64;
    v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v23->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v23[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v23[1],
      v23,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)&v76);
    v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v23->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v23[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v23[1],
      v23,
      &psc,
      GAS_FunctionObjectTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v23 = 0i64;
  }
  v75 = v23;
  v11->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &v11->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    v23);
  v16->Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &v16->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::AS2::Object *)v75);
  LODWORD(flags) = 1;
  *(_QWORD *)&key.T.Type = &flags;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)&proto;
  v24 = 5381i64;
  v25 = 5381i64;
  v26 = 4i64;
  do
  {
    --v26;
    v25 = *((unsigned __int8 *)&flags + v26) + 65599 * v25;
  }
  while ( v26 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    &this->Prototypes.mHash,
    &this->Prototypes,
    (Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *)&key,
    v25);
  LODWORD(flags) = 7;
  *(_QWORD *)&key.T.Type = &flags;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v75;
  v27 = 5381i64;
  v28 = 4i64;
  do
  {
    --v28;
    v27 = *((unsigned __int8 *)&flags + v28) + 65599 * v27;
  }
  while ( v28 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    &this->Prototypes.mHash,
    &this->Prototypes,
    (Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *)&key,
    v27);
  v29 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                         this->pHeap,
                                         104i64);
  v30 = v29;
  v74 = v29;
  if ( v29 )
  {
    Scaleform::GFx::AS2::Object::Object(v29, &psc);
    v30->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v30->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v30->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v30->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v30[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::MovieClipCtorFunction::GlobalCtor;
    v31 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v30->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v80.T.Type = 10;
      v30->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v30->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v80,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v80.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v80);
    }
    if ( v31 )
      v31->RefCount = (v31->RefCount + 1) & 0x8FFFFFFF;
    v32 = v30->pProto.pObject;
    if ( v32 )
    {
      v33 = v32->RefCount;
      if ( (v33 & 0x3FFFFFF) != 0 )
      {
        v32->RefCount = v33 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
      }
    }
    v30->pProto.pObject = v31;
    v30->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v30->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v2 = proota;
  }
  else
  {
    v30 = 0i64;
  }
  *((_BYTE *)&v80.NV + 16) = 0;
  *(_OWORD *)&v80.T.Type = (unsigned __int64)v30;
  v34 = (Scaleform::GFx::MovieImpl *)this->pHeap->vfptr->Alloc(this->pHeap, 312i64, 0i64);
  proota = v34;
  if ( v34 )
  {
    Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction((Scaleform::GFx::AS2::KeyCtorFunction *)v34, &psc, v2);
    v36 = v35;
  }
  else
  {
    v36 = 0i64;
  }
  v74 = v36;
  v84.Flags = 0;
  v84.Function = v36;
  v84.pLocalFrame = 0i64;
  v37 = (Scaleform::GFx::AS2::Object *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  v38 = v37;
  *(_QWORD *)&key.T.Type = v37;
  if ( v37 )
  {
    v39 = proto;
    Scaleform::GFx::AS2::Object::Object(v37, &psc);
    v38->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::KeyObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v40 = &v38->Scaleform::GFx::AS2::ObjectInterface;
    v38->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::KeyObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    if ( !v38->pProto.pObject )
    {
      LOBYTE(proota) = 3;
      v86.T.Type = 10;
      v40->vfptr->SetMemberRaw(
        &v38->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v86,
        (Scaleform::GFx::AS2::PropFlags *)&proota);
      if ( v86.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v86);
      v40 = &v38->Scaleform::GFx::AS2::ObjectInterface;
    }
    if ( v39 )
      v39->RefCount = (v39->RefCount + 1) & 0x8FFFFFFF;
    v41 = v40->pProto.pObject;
    if ( v41 )
    {
      v42 = v41->RefCount;
      if ( (v42 & 0x3FFFFFF) != 0 )
      {
        v41->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v41);
        v40 = &v38->Scaleform::GFx::AS2::ObjectInterface;
      }
    }
    v40->pProto.pObject = v39;
    flags = (Scaleform::GFx::AS2::GASGlobalObject *)&v38[1];
    v38[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    LOBYTE(v38[1].RefCount) = 0;
    v38[1].pRCC = 0i64;
    v38[1].pPrev = 0i64;
    LOBYTE(v38[1].Members.mHash.pTable) = 0;
    v38[1].Scaleform::GFx::AS2::ObjectInterface::vfptr = 0i64;
    v38[1].pProto.pObject = 0i64;
    v38[1].ResolveHandler.Function = 0i64;
    v38->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v40->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v38[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init((Scaleform::GFx::AS2::GASPrototypeBase *)&v38[1], v38, &psc, &v84);
    v38->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v38->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v38[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v38[1],
      v38,
      &psc,
      GAS_KeyFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
    v36 = (Scaleform::GFx::AS2::FunctionObject *)v74;
  }
  else
  {
    v38 = 0i64;
  }
  v77 = v38;
  LODWORD(proota) = 26;
  *(_QWORD *)&key.T.Type = &proota;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v77;
  v43 = 5381i64;
  v44 = 4i64;
  do
  {
    --v44;
    v43 = *((unsigned __int8 *)&proota + v44) + 65599 * v43;
  }
  while ( v44 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    &this->Prototypes.mHash,
    &this->Prototypes,
    (Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *)&key,
    v43);
  v45 = (Scaleform::GFx::MovieImpl *)this->pHeap->vfptr->Alloc(this->pHeap, 176i64, 0i64);
  proota = v45;
  if ( v45 )
    Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(
      (Scaleform::GFx::AS2::MovieClipProto *)v45,
      &psc,
      proto,
      (Scaleform::GFx::AS2::FunctionRef *)&v80);
  v78 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v45;
  LODWORD(proota) = 6;
  *(_QWORD *)&key.T.Type = &proota;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v78;
  v46 = 4i64;
  do
  {
    --v46;
    v47 = 65599 * v24 + *((unsigned __int8 *)&proota + v46);
    v24 = v47;
  }
  while ( v46 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    &this->Prototypes.mHash,
    &this->Prototypes,
    (Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *)&key,
    v47);
  v48 = this->pGlobal.pObject;
  v49 = &v48->Scaleform::GFx::AS2::ObjectInterface;
  if ( !v48 )
    v49 = 0i64;
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    v49,
    &psc,
    Scaleform::GFx::AS2::GFxAction_Global_StaticFunctions,
    0);
  v50 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  key.T.Type = 8;
  key.V.FunctionValue.Flags = 0;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)v11;
  v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
  key.V.FunctionValue.pLocalFrame = 0i64;
  LOBYTE(proota) = 0;
  v50->vfptr->SetMemberRaw(
    v50,
    &psc,
    (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[8],
    &key,
    (Scaleform::GFx::AS2::PropFlags *)&proota);
  if ( key.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&key);
  v51 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  key.T.Type = 8;
  key.V.FunctionValue.Flags = 0;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)v16;
  v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
  key.V.FunctionValue.pLocalFrame = 0i64;
  LOBYTE(proota) = 0;
  v51->vfptr->SetMemberRaw(
    v51,
    &psc,
    (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[9].RefCount,
    &key,
    (Scaleform::GFx::AS2::PropFlags *)&proota);
  if ( key.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&key);
  v52 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  key.T.Type = 8;
  key.V.FunctionValue.Flags = 0;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)v30;
  if ( v30 )
    v30->RefCount = (v30->RefCount + 1) & 0x8FFFFFFF;
  key.V.FunctionValue.pLocalFrame = 0i64;
  LOBYTE(proota) = 0;
  v52->vfptr->SetMemberRaw(
    v52,
    &psc,
    (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[9],
    &key,
    (Scaleform::GFx::AS2::PropFlags *)&proota);
  if ( key.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&key);
  v53 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  key.T.Type = 8;
  key.V.FunctionValue.Flags = 0;
  key.V.pStringNode = (Scaleform::GFx::ASStringNode *)v36;
  if ( v36 )
    v36->RefCount = (v36->RefCount + 1) & 0x8FFFFFFF;
  key.V.FunctionValue.pLocalFrame = 0i64;
  LOBYTE(proota) = 0;
  v53->vfptr->SetMemberRaw(
    v53,
    &psc,
    (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[13],
    &key,
    (Scaleform::GFx::AS2::PropFlags *)&proota);
  if ( key.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&key);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<25,Scaleform::GFx::AS2::MathCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<2,Scaleform::GFx::AS2::ArrayCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<4,Scaleform::GFx::AS2::NumberCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<3,Scaleform::GFx::AS2::StringCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<5,Scaleform::GFx::AS2::BooleanCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<9,Scaleform::GFx::AS2::ButtonCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<29,Scaleform::GFx::AS2::MovieClipLoaderCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<31,Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<18,Scaleform::GFx::AS2::StageCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<19,Scaleform::GFx::AS2::AsBroadcasterCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<27,Scaleform::GFx::AS2::MouseCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<10,Scaleform::GFx::AS2::TextFieldCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<32,Scaleform::GFx::AS2::TextFormatCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  v54 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, this->pGlobal.pObject, proto, "flash.geom");
  this->FlashGeomPackage = v54;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<14,Scaleform::GFx::AS2::PointCtorFunction>(
    this,
    &psc,
    v54);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<15,Scaleform::GFx::AS2::RectangleCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<16,Scaleform::GFx::AS2::ColorTransformCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  v55 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, this->pGlobal.pObject, proto, "flash.external");
  this->FlashExternalPackage = v55;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<28,Scaleform::GFx::AS2::ExternalInterfaceCtorFunction>(
    this,
    &psc,
    v55);
  v56 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, this->pGlobal.pObject, proto, "flash.display");
  this->FlashDisplayPackage = v56;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<30,Scaleform::GFx::AS2::BitmapDataCtorFunction>(
    this,
    &psc,
    v56);
  this->FlashFiltersPackage = Scaleform::GFx::AS2::GlobalContext::AddPackage(
                                &psc,
                                this->pGlobal.pObject,
                                proto,
                                "flash.filters");
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StandardMemberMap);
  Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(this);
  v57 = this->pGlobal.pObject;
  v81 = (void **)&`Scaleform::GFx::AS2::GlobalContext::Init::`4::MemberVisitor::`vftable;
  if ( v57 )
    v57->RefCount = (v57->RefCount + 1) & 0x8FFFFFFF;
  v82 = v57;
  p_psc = &psc;
  this->pGlobal.pObject->vfptr->VisitMembers(
    &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v81,
    4u,
    0i64);
  v58 = v82;
  if ( v82 )
  {
    v59 = v82->RefCount;
    if ( (v59 & 0x3FFFFFF) != 0 )
    {
      v82->RefCount = v59 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v58);
    }
  }
  v81 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
  v60 = v78;
  if ( v78 )
  {
    v61 = v78->RefCount;
    if ( (v61 & 0x3FFFFFF) != 0 )
    {
      v78->RefCount = v61 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v60);
    }
  }
  v62 = v77;
  if ( v77 )
  {
    v63 = v77->RefCount;
    if ( (v63 & 0x3FFFFFF) != 0 )
    {
      v77->RefCount = v63 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v62);
    }
  }
  if ( v36 )
  {
    v64 = v36->RefCount;
    if ( (v64 & 0x3FFFFFF) != 0 )
    {
      v36->RefCount = v64 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
    }
  }
  v84.Function = 0i64;
  v84.pLocalFrame = 0i64;
  if ( v30 )
  {
    v65 = v30->RefCount;
    if ( (v65 & 0x3FFFFFF) != 0 )
    {
      v30->RefCount = v65 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
    }
  }
  *(_OWORD *)&v80.T.Type = 0ui64;
  v66 = v75;
  if ( v75 )
  {
    v67 = v75->RefCount;
    if ( (v67 & 0x3FFFFFF) != 0 )
    {
      v75->RefCount = v67 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v66);
    }
  }
  v68 = proto;
  if ( proto )
  {
    v69 = proto->RefCount;
    if ( (v69 & 0x3FFFFFF) != 0 )
    {
      proto->RefCount = v69 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v68);
    }
  }
  v70 = v16->RefCount;
  if ( (v70 & 0x3FFFFFF) != 0 )
  {
    v16->RefCount = v70 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
  }
  *(_OWORD *)&v76.T.Type = 0ui64;
  v71 = v11->RefCount;
  if ( (v71 & 0x3FFFFFF) != 0 )
  {
    v11->RefCount = v71 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
  }
}

// File Line: 1398
// RVA: 0x7237B0
void __fastcall Scaleform::GFx::AS2::GlobalContext::Init_::_4_::MemberVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        char flags,
        __int64 a4)
{
  LOBYTE(a4) = a4 | 1;
  (*(void (__fastcall **)(unsigned int *, Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::Value *, __int64))(*(_QWORD *)&name[1].pNode->Size + 56i64))(
    &name[1].pNode->Size,
    name[2].pNode,
    val,
    a4);
}

// File Line: 1414
// RVA: 0x6D18A0
void __fastcall Scaleform::GFx::AS2::GlobalContext::~GlobalContext(Scaleform::GFx::AS2::GlobalContext *this)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StandardMemberMap);
  pObject = this->pGlobal.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&this->BuiltinClassesRegistry.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->RegisteredClasses.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>(&this->Prototypes.mHash);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

// File Line: 1425
// RVA: 0x708770
void __fastcall Scaleform::GFx::AS2::GlobalContext::PreClean(
        Scaleform::GFx::AS2::GlobalContext *this,
        bool preserveBuiltinProps)
{
  Scaleform::GFx::AS2::GASGlobalObject *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rsi
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Object *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-19h] BYREF
  __int64 v16; // [rsp+38h] [rbp-11h]
  Scaleform::GFx::AS2::GASGlobalObject *v17; // [rsp+40h] [rbp-9h]
  Scaleform::GFx::AS2::ASStringContext v18; // [rsp+48h] [rbp-1h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp+Fh] BYREF
  char v20; // [rsp+B8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString v21; // [rsp+C0h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+C8h] [rbp+7Fh] BYREF

  v16 = -2i64;
  if ( preserveBuiltinProps )
  {
    v3 = (Scaleform::GFx::AS2::GASGlobalObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                   this->pHeap,
                                                   104i64);
    v17 = v3;
    if ( v3 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v3, this);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    v18.pContext = this;
    v18.SWFVersion = 8;
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &result, "gfxPlayer");
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &v22, "gfxLanguage");
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &v21, "gfxArg");
    v19.T.Type = 0;
    this->pGlobal.pObject->vfptr->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &result,
      &v19);
    v20 = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &result,
      &v19,
      (Scaleform::GFx::AS2::PropFlags *)&v20);
    this->pGlobal.pObject->vfptr->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &v22,
      &v19);
    v20 = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &v22,
      &v19,
      (Scaleform::GFx::AS2::PropFlags *)&v20);
    this->pGlobal.pObject->vfptr->GetMemberRaw(
      &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &v21,
      &v19);
    v20 = 0;
    v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v5->Scaleform::GFx::AS2::ObjectInterface,
      &v18,
      &v21,
      &v19,
      (Scaleform::GFx::AS2::PropFlags *)&v20);
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    pObject = this->pGlobal.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    this->pGlobal.pObject = v5;
    if ( v19.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    pNode = v21.pNode;
    v9 = v21.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v10 = v22.pNode;
    v9 = v22.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v11 = result.pNode;
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = v5->RefCount;
    if ( (v12 & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  else
  {
    v13 = this->pGlobal.pObject;
    if ( v13 )
    {
      v14 = v13->RefCount;
      if ( (v14 & 0x3FFFFFF) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    this->pGlobal.pObject = 0i64;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->RegisteredClasses.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&this->BuiltinClassesRegistry.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>(&this->Prototypes.mHash);
  this->pMovieRoot = 0i64;
}

// File Line: 1452
// RVA: 0x711F40
Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *__fastcall Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString *functionName)
{
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *result; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *p_ResolvedFunc; // rsi
  __int64 v6; // rax
  bool v7; // bp
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  __int64 v10; // rcx
  char v11; // al
  char v12; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+30h] [rbp-68h]
  char v23; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // [rsp+40h] [rbp-58h]
  __int64 v25; // [rsp+48h] [rbp-50h]
  bool v26; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::ASString className; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::GFx::ASString *p_className; // [rsp+B8h] [rbp+20h]

  className.pNode = (Scaleform::GFx::ASStringNode *)&pNode;
  pNode = functionName->pNode;
  ++pNode->RefCount;
  result = Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(this, (Scaleform::GFx::ASString)&pNode);
  if ( result )
  {
    p_ResolvedFunc = &result->ResolvedFunc;
    if ( !result->ResolvedFunc.pObject )
    {
      v6 = result->RegistrarFunc(&v21, this);
      v7 = 0;
      v26 = 0;
      v8 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v6;
      v24 = v8;
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      v9 = 0i64;
      v25 = 0i64;
      v10 = *(_QWORD *)(v6 + 8);
      if ( v10 )
      {
        v11 = *(_BYTE *)(v6 + 16) & 1;
        v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10;
        v25 = v10;
        v7 = v11 != 0;
        v26 = v11 != 0;
        if ( !v11 )
          *(_DWORD *)(v10 + 24) = (*(_DWORD *)(v10 + 24) + 1) & 0x8FFFFFFF;
      }
      v12 = v23;
      if ( (v23 & 2) == 0 )
      {
        v13 = v21;
        if ( v21 )
        {
          RefCount = v21->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v21->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
            v12 = v23;
          }
        }
      }
      v21 = 0i64;
      if ( (v12 & 1) == 0 )
      {
        v15 = v22;
        if ( v22 )
        {
          v16 = v22->RefCount;
          if ( (v16 & 0x3FFFFFF) != 0 )
          {
            v22->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
          }
        }
      }
      v22 = 0i64;
      p_className = &className;
      className.pNode = functionName->pNode;
      ++className.pNode->RefCount;
      p_ResolvedFunc = &Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(
                          this,
                          (Scaleform::GFx::ASString)&className)->ResolvedFunc;
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      pObject = p_ResolvedFunc->pObject;
      if ( p_ResolvedFunc->pObject )
      {
        v18 = pObject->RefCount;
        if ( (v18 & 0x3FFFFFF) != 0 )
        {
          pObject->RefCount = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      p_ResolvedFunc->pObject = (Scaleform::GFx::AS2::FunctionObject *)v8;
      if ( (v7 & 2) == 0 )
      {
        if ( v8 )
        {
          v19 = v8->RefCount;
          if ( (v19 & 0x3FFFFFF) != 0 )
          {
            v8->RefCount = v19 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          }
        }
      }
      v24 = 0i64;
      if ( !v7 && v9 )
      {
        v20 = v9->RefCount;
        if ( (v20 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      v25 = 0i64;
    }
    return (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)p_ResolvedFunc->pObject;
  }
  return result;
}

// File Line: 1475
// RVA: 0x6F4F50
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::GlobalContext::GetPrototype(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASBuiltinType type)
{
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> >::TableType *pTable; // rsi
  __int64 v3; // r15
  __int64 v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // r9
  __int64 v8; // r8
  __int64 v9; // rax
  __int64 v10; // rax
  signed __int64 v11; // rax
  unsigned __int64 *v12; // rax
  char *v13; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> >::TableType *v14; // rsi
  __int64 v15; // rax
  __int64 v16; // rax
  signed __int64 v17; // rax
  unsigned __int64 *v18; // rax
  __int64 v20; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS2::ASBuiltinType key; // [rsp+48h] [rbp+10h] BYREF

  key = type;
  pTable = this->Prototypes.mHash.pTable;
  v3 = type;
  v5 = 5381i64;
  v6 = 4i64;
  if ( pTable )
  {
    v7 = 5381i64;
    v8 = 4i64;
    do
    {
      v9 = *((unsigned __int8 *)&v20 + v8-- + 7);
      v10 = 65599 * v7 + v9;
      v7 = v10;
    }
    while ( v8 );
    v11 = Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexCore<enum Scaleform::GFx::AS2::ASBuiltinType>(
            &this->Prototypes.mHash,
            &key,
            v10 & pTable->SizeMask);
    if ( v11 >= 0 )
    {
      v12 = &pTable[1].SizeMask + 3 * v11;
      if ( v12 )
      {
        v13 = (char *)(v12 + 1);
        if ( v13 )
          return *(Scaleform::GFx::AS2::Object **)v13;
      }
    }
  }
  Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
    this,
    (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion + v3);
  v14 = this->Prototypes.mHash.pTable;
  if ( !v14 )
    return 0i64;
  do
  {
    v15 = *((unsigned __int8 *)&v20 + v6-- + 7);
    v16 = 65599 * v5 + v15;
    v5 = v16;
  }
  while ( v6 );
  v17 = Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexCore<enum Scaleform::GFx::AS2::ASBuiltinType>(
          &this->Prototypes.mHash,
          &key,
          v16 & v14->SizeMask);
  if ( v17 >= 0 && (v18 = &v14[1].SizeMask + 3 * v17) != 0i64 && (v13 = (char *)(v18 + 1)) != 0i64 )
    return *(Scaleform::GFx::AS2::Object **)v13;
  else
    return 0i64;
}

// File Line: 1486
// RVA: 0x6EE510
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ASBuiltinType type)
{
  __int64 v3; // rdi
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rsi
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  Scaleform::GFx::AS2::Value v16; // [rsp+28h] [rbp-40h] BYREF

  v3 = type;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this, type);
  v7 = Prototype;
  if ( Prototype )
    Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, __int64))this->pGlobal.pObject->vfptr->GetMemberRaw)(
         &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &penv->StringContext,
         &this->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion + 8 * v3,
         &v16,
         -2i64) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v16, penv);
    v9 = v8;
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    if ( v8
      && v8->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
           &v8->Scaleform::GFx::AS2::ObjectInterface,
           &penv->StringContext,
           (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v16) )
    {
      v10 = Scaleform::GFx::AS2::Value::ToObject(&v16, penv);
      v11 = v10;
      if ( v10 )
        v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
      if ( v7 )
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
      v7 = v11;
    }
    if ( v9 )
    {
      v13 = v9->RefCount;
      if ( (v13 & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  if ( v7 )
  {
    v14 = v7->RefCount;
    if ( (v14 & 0x3FFFFFF) != 0 )
    {
      v7->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  return (Scaleform::GFx::AS2::Object *)v7;
}

// File Line: 1502
// RVA: 0x6EE760
Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *__fastcall Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString className)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::GlobalContext::ClassRegEntry> *p_BuiltinClassesRegistry; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v4; // rdi
  signed __int64 v5; // rax
  __int64 p_SizeMask; // rdi
  __int64 v7; // rdi
  Scaleform::GFx::ASStringNode *pData; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx

  p_BuiltinClassesRegistry = &this->BuiltinClassesRegistry;
  v4.pTable = p_BuiltinClassesRegistry->mHash.pTable;
  if ( p_BuiltinClassesRegistry->mHash.pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &p_BuiltinClassesRegistry->mHash,
               (Scaleform::GFx::ASString *)className.pNode,
               *((unsigned int *)className.pNode->pData + 7) & v4.pTable->SizeMask),
        v5 >= 0)
    && (p_SizeMask = (__int64)&v4.pTable[2 * v5 + 1].SizeMask) != 0
    && (v7 = p_SizeMask + 8) != 0 )
  {
    pData = (Scaleform::GFx::ASStringNode *)className.pNode->pData;
    v9 = (*((_DWORD *)className.pNode->pData + 6))-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pData);
    return (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)v7;
  }
  else
  {
    v11 = (Scaleform::GFx::ASStringNode *)className.pNode->pData;
    v9 = (*((_DWORD *)className.pNode->pData + 6))-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    return 0i64;
  }
}

// File Line: 1512
// RVA: 0x6EAA40
// bad sp value at call has been detected, the output may be wrong!
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::GlobalContext::FindClassName(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *iobj)
{
  int v8; // edi
  bool v9; // cc
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v10; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // rcx
  Scaleform::GFx::AS2::FunctionObject *v12; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rdx
  Scaleform::GFx::AS2::LocalFrame *v14; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v15; // rcx
  Scaleform::GFx::AS2::FunctionObject *Function; // r12
  __int64 pLocalFrame; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v18; // rcx
  Scaleform::GFx::ASString *v19; // r15
  Scaleform::GFx::AS2::Value *p_Finalize_GC; // rsi
  bool v21; // si
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *v23; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *v25; // rcx
  unsigned int v26; // eax
  char v27; // al
  Scaleform::GFx::AS2::FunctionObject *v28; // rcx
  unsigned int v29; // edx
  Scaleform::GFx::AS2::LocalFrame *v30; // rcx
  unsigned int v31; // eax
  void (__fastcall *Finalize_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *); // rcx
  $3B3220B7F8C7709B379812E5C933B251 *v33; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASString *v35; // rbx
  Scaleform::GFx::ASString *v37; // rbx
  char v38; // al
  Scaleform::GFx::AS2::FunctionObject *v39; // rcx
  unsigned int v40; // edx
  Scaleform::GFx::AS2::LocalFrame *v41; // rcx
  unsigned int v42; // eax
  Scaleform::GFx::ASStringNode *vfptr; // rax
  Scaleform::GFx::AS2::FunctionRef v44; // [rsp+10h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::FunctionRef resulta; // [rsp+30h] [rbp-19h] BYREF
  Scaleform::GFx::AS2::Value v46; // [rsp+48h] [rbp-1h] BYREF
  char v47[31]; // [rsp+99h] [rbp+50h]
  Scaleform::GFx::ASString *v48; // [rsp+B8h] [rbp+6Fh]

  v8 = 0;
  if ( !iobj )
  {
LABEL_75:
    vfptr = (Scaleform::GFx::ASStringNode *)this->pMovieRoot->pASMovieRoot.pObject[17].vfptr;
    result->pNode = vfptr;
    ++vfptr->RefCount;
    return result;
  }
  v9 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&iobj->vfptr->gap8[8])(iobj) - 2 <= 3;
  v10 = iobj->vfptr;
  if ( v9 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->gap8[8])(iobj) - 2 > 3 )
      p_pProto = 0i64;
    else
      p_pProto = &iobj[-1].pProto;
    v12 = (Scaleform::GFx::AS2::FunctionObject *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))p_pProto->pObject[2].pRCC)(p_pProto);
  }
  else
  {
    v12 = (Scaleform::GFx::AS2::FunctionObject *)&iobj[-2];
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->gap8[8])(iobj) - 6 > 0x26 )
      v12 = 0i64;
  }
  pTable = this->pGlobal.pObject->Members.mHash.pTable;
  if ( pTable )
  {
    v14 = 0i64;
    v15 = pTable + 1;
    do
    {
      if ( v15->EntryCount != -2i64 )
        break;
      v14 = (Scaleform::GFx::AS2::LocalFrame *)((char *)v14 + 1);
      v15 += 3;
    }
    while ( (unsigned __int64)v14 <= pTable->SizeMask );
    v44.Function = (Scaleform::GFx::AS2::FunctionObject *)&this->pGlobal.pObject->Members;
    v44.pLocalFrame = v14;
  }
  else
  {
    v44.Function = 0i64;
    v44.pLocalFrame = 0i64;
  }
  Function = v44.Function;
  pLocalFrame = (__int64)v44.pLocalFrame;
  while ( 1 )
  {
    if ( !Function
      || (v18 = Function->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr) == 0i64
      || pLocalFrame > (__int64)v18->Finalize_GC )
    {
      result = v48;
      this = *(Scaleform::GFx::AS2::GlobalContext **)&v47[23];
      goto LABEL_75;
    }
    v19 = (Scaleform::GFx::ASString *)&v18[2 * pLocalFrame];
    p_Finalize_GC = (Scaleform::GFx::AS2::Value *)&v18[2 * pLocalFrame + 1].Finalize_GC;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v12->Scaleform::GFx::AS2::ObjectInterface) == 23 )
    {
      v21 = 0;
      if ( p_Finalize_GC->T.Type == 8 || p_Finalize_GC->T.Type == 11 )
      {
        v8 |= 1u;
        if ( Scaleform::GFx::AS2::Value::ToFunction(p_Finalize_GC, &resulta, penv)->Function == v12 )
          v21 = 1;
      }
      if ( (v8 & 1) != 0 )
      {
        v8 &= ~1u;
        Flags = resulta.Flags;
        if ( (resulta.Flags & 2) == 0 )
        {
          v23 = resulta.Function;
          if ( resulta.Function )
          {
            RefCount = resulta.Function->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              resulta.Function->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
              Flags = resulta.Flags;
            }
          }
        }
        resulta.Function = 0i64;
        if ( (Flags & 1) == 0 )
        {
          v25 = resulta.pLocalFrame;
          if ( resulta.pLocalFrame )
          {
            v26 = resulta.pLocalFrame->RefCount;
            if ( (v26 & 0x3FFFFFF) != 0 )
            {
              resulta.pLocalFrame->RefCount = v26 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
            }
          }
        }
        resulta.pLocalFrame = 0i64;
      }
      if ( v21 )
      {
LABEL_61:
        pNode = v19[3].pNode;
        v35 = v48;
        v48->pNode = pNode;
        ++pNode->RefCount;
        return v35;
      }
      goto LABEL_55;
    }
    if ( p_Finalize_GC->T.Type == 6 && Scaleform::GFx::AS2::Value::ToObject(p_Finalize_GC, penv) == v12 )
      goto LABEL_61;
    if ( p_Finalize_GC->T.Type == 8 || p_Finalize_GC->T.Type == 11 )
      break;
LABEL_55:
    Finalize_GC = Function->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr->Finalize_GC;
    if ( pLocalFrame <= (__int64)Finalize_GC && ++pLocalFrame <= (unsigned __int64)Finalize_GC )
    {
      v33 = &Function->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[2 * pLocalFrame].16;
      do
      {
        if ( v33->~RefCountBaseGC<323> != (void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *))-2i64 )
          break;
        ++pLocalFrame;
        v33 += 6;
      }
      while ( pLocalFrame <= (unsigned __int64)Finalize_GC );
    }
  }
  Scaleform::GFx::AS2::Value::ToFunction(p_Finalize_GC, &v44, penv);
  v46.T.Type = 0;
  if ( !v44.Function->vfptr->GetMemberRaw(
          &v44.Function->Scaleform::GFx::AS2::ObjectInterface,
          &penv->StringContext,
          (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v47[23] + 40i64) + 24i64) + 928i64),
          &v46)
    || v46.T.Type != 6
    || Scaleform::GFx::AS2::Value::ToObject(&v46, penv) != v12 )
  {
    if ( v46.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v46);
    v27 = v44.Flags;
    if ( (v44.Flags & 2) == 0 )
    {
      v28 = v44.Function;
      if ( v44.Function )
      {
        v29 = v44.Function->RefCount;
        if ( (v29 & 0x3FFFFFF) != 0 )
        {
          v44.Function->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
          v27 = v44.Flags;
        }
      }
    }
    v44.Function = 0i64;
    if ( (v27 & 1) == 0 )
    {
      v30 = v44.pLocalFrame;
      if ( v44.pLocalFrame )
      {
        v31 = v44.pLocalFrame->RefCount;
        if ( (v31 & 0x3FFFFFF) != 0 )
        {
          v44.pLocalFrame->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
        }
      }
    }
    v44.pLocalFrame = 0i64;
    goto LABEL_55;
  }
  v37 = v48;
  Scaleform::GFx::ASString::operator+(v19 + 3, v48, ".prototype");
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v38 = v44.Flags;
  if ( (v44.Flags & 2) == 0 )
  {
    v39 = v44.Function;
    if ( v44.Function )
    {
      v40 = v44.Function->RefCount;
      if ( (v40 & 0x3FFFFFF) != 0 )
      {
        v44.Function->RefCount = v40 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v39);
        v38 = v44.Flags;
      }
    }
  }
  v44.Function = 0i64;
  if ( (v38 & 1) == 0 )
  {
    v41 = v44.pLocalFrame;
    if ( v44.pLocalFrame )
    {
      v42 = v44.pLocalFrame->RefCount;
      if ( (v42 & 0x3FFFFFF) != 0 )
      {
        v44.pLocalFrame->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v41);
      }
    }
  }
  v44.pLocalFrame = 0i64;
  return v37;
}

// File Line: 1566
// RVA: 0x722BA0
char __fastcall Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *className)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::FunctionRef> *p_RegisteredClasses; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v6; // rsi
  __int64 v7; // rax
  unsigned __int64 *v8; // rax
  Scaleform::GFx::AS2::FunctionRef *CaseInsensitive; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+30h] [rbp+8h] BYREF

  p_RegisteredClasses = &this->RegisteredClasses;
  if ( psc->SWFVersion <= 6u )
  {
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        &this->RegisteredClasses,
                        className);
  }
  else
  {
    v6.pTable = p_RegisteredClasses->mHash.pTable;
    if ( !p_RegisteredClasses->mHash.pTable )
      return 0;
    v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           &this->RegisteredClasses.mHash,
           className,
           v6.pTable->SizeMask & className->pNode->HashFlags);
    if ( v7 < 0 )
      return 0;
    v8 = &v6.pTable[1].SizeMask + 5 * v7;
    if ( !v8 )
      return 0;
    CaseInsensitive = (Scaleform::GFx::AS2::FunctionRef *)(v8 + 1);
  }
  if ( !CaseInsensitive )
    return 0;
  if ( psc->SWFVersion <= 6u )
  {
    pNode = className->pNode;
    key.pStr = className;
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString::NoCaseKey>(
      &p_RegisteredClasses->mHash,
      &key);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
      &p_RegisteredClasses->mHash,
      className);
  }
  return 1;
}

// File Line: 1612
// RVA: 0x6D7DD0
void __fastcall Scaleform::GFx::AS2::NameFunction::AddConstMembers(
        Scaleform::GFx::AS2::ObjectInterface *pobj,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::NameFunction *pfunctions,
        char flags)
{
  Scaleform::MemoryHeap *pHeap; // r14
  Scaleform::GFx::AS2::Object *i; // r13
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rbx
  void (__fastcall *Function)(Scaleform::GFx::AS2::FnCall *); // rdi
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v17; // [rsp+60h] [rbp-58h] BYREF
  char v18; // [rsp+C8h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+18h] BYREF

  pHeap = psc->pContext->pHeap;
  for ( i = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
        pfunctions->Name;
        ++pfunctions )
  {
    v18 = flags;
    v10 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                           pHeap,
                                           104i64);
    v11 = v10;
    if ( v10 )
    {
      Function = pfunctions->Function;
      Scaleform::GFx::AS2::Object::Object(v10, psc);
      v11->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
      v11->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
      v11->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
      v11->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
      v11[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Function;
      Scaleform::GFx::AS2::Object::Set__proto__(
        (Scaleform::GFx::AS2::Object *)&v11->Scaleform::GFx::AS2::ObjectInterface,
        psc,
        i);
    }
    else
    {
      v11 = 0i64;
    }
    v17.T.Type = 8;
    v17.V.FunctionValue.Flags = 0;
    v17.V.pStringNode = (Scaleform::GFx::ASStringNode *)v11;
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
    v17.V.FunctionValue.pLocalFrame = 0i64;
    v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, pfunctions->Name);
    pobj->vfptr->SetMemberRaw(pobj, psc, v13, &v17, (Scaleform::GFx::AS2::PropFlags *)&v18);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
}

// File Line: 1646
// RVA: 0x6D2A60
void __fastcall Scaleform::GFx::AS2::WithStackEntry::~WithStackEntry(Scaleform::GFx::AS2::WithStackEntry *this)
{
  signed int BlockEndPc; // eax
  Scaleform::RefCountNTSImpl *pObject; // rcx
  int RefCount; // eax

  BlockEndPc = this->BlockEndPc;
  pObject = (Scaleform::RefCountNTSImpl *)this->pObject;
  if ( BlockEndPc >= 0 )
  {
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else if ( pObject )
  {
    RefCount = pObject[1].RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject[1].RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pObject);
    }
  }
}

// File Line: 1663
// RVA: 0x6F45F0
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(
        Scaleform::GFx::AS2::WithStackEntry *this)
{
  char *v2; // rcx
  __int64 v3; // rax

  if ( (this->BlockEndPc & 0x80000000) == 0 )
  {
    if ( this->pObject )
    {
      v2 = (char *)this->pObject + 4 * BYTE5(this->pObject[1].pNext);
      v3 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v2 + 8i64))(v2);
      if ( v3 )
        return (Scaleform::GFx::AS2::ObjectInterface *)(v3 + 8);
    }
  }
  else if ( this->pObject )
  {
    return &this->pObject->Scaleform::GFx::AS2::ObjectInterface;
  }
  return 0i64;
}

// File Line: 1670
// RVA: 0x6E00D0
Scaleform::GFx::AS2::ActionBufferData *__fastcall Scaleform::GFx::AS2::ActionBufferData::CreateNew()
{
  Scaleform::GFx::AS2::ActionBufferData *result; // rax

  result = (Scaleform::GFx::AS2::ActionBufferData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      40i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,263>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::ActionBufferData,263>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::ActionBufferData::`vftable;
  result->pBuffer = 0i64;
  *(_QWORD *)&result->BufferLen = 0i64;
  result->SWFFileOffset = 0;
  return result;
}

// File Line: 1680
// RVA: 0x70B620
void __fastcall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::Stream *in,
        unsigned int actionLength)
{
  char *v5; // rax
  unsigned int BufferLen; // r8d
  char *pBuffer; // rsi
  __int64 v8; // rdi
  char v9; // bl
  unsigned int v10; // edx
  Scaleform::GFx::AS2::Disasm v11; // [rsp+20h] [rbp-18h] BYREF

  this->BufferLen = actionLength;
  v5 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 this,
                 actionLength,
                 0i64);
  BufferLen = this->BufferLen;
  this->pBuffer = v5;
  Scaleform::GFx::Stream::ReadToBuffer(in, v5, BufferLen);
  if ( Scaleform::GFx::Stream::IsVerboseParseAction(in) )
  {
    pBuffer = this->pBuffer;
    v8 = 0i64;
    do
    {
      v9 = pBuffer[v8];
      v10 = v8++;
      if ( v9 < 0 )
        v8 += (unsigned __int16)((unsigned __int8)pBuffer[v8] | ((unsigned __int8)pBuffer[v8 + 1] << 8)) + 2i64;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, "%4d\t", v10);
      v11.pLog = (Scaleform::Log *)Scaleform::GFx::Stream::GetLog((Expression::IMemberMap *)in);
      v11.MsgId.Id = 20483;
      Scaleform::GFx::AS2::Disasm::LogF(&v11, "<disasm is disabled>\n");
    }
    while ( v9 );
  }
}

// File Line: 1736
// RVA: 0x70B590
void __fastcall Scaleform::GFx::AS2::ActionBufferData::Read(
        Scaleform::GFx::AS2::ActionBufferData *this,
        Scaleform::GFx::StreamContext *psc,
        unsigned int eventLength)
{
  size_t v3; // rbp
  char *v6; // rax
  bool v7; // zf

  v3 = eventLength;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  psc->CurBitIndex = 0;
  v6 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 this,
                 eventLength,
                 0i64);
  this->pBuffer = v6;
  memmove(v6, &psc->pData[psc->CurByteIndex], v3);
  this->BufferLen = v3;
  v7 = psc->CurBitIndex == 0;
  psc->CurBitIndex = 0;
  if ( !v7 )
    ++psc->CurByteIndex;
  psc->CurByteIndex += v3;
}

// File Line: 1758
// RVA: 0x6C6C30
void __fastcall Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::Resource *pbufferData)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  Scaleform::GFx::ASStringNode *v7; // rax

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::AS2::ActionBuffer,323>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::ActionBuffer::`vftable;
  if ( pbufferData )
    Scaleform::Render::RenderBuffer::AddRef(pbufferData);
  this->pBufferData.pObject = (Scaleform::GFx::AS2::ActionBufferData *)pbufferData;
  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  this->Dictionary.Data.Data = 0i64;
  this->Dictionary.Data.Size = 0i64;
  this->Dictionary.Data.Policy.Capacity = 0i64;
  v7 = *(Scaleform::GFx::ASStringNode **)&pObject[7].AVMVersion;
  this->Dictionary.Data.DefaultValue.pNode = v7;
  ++v7->RefCount;
  this->DeclDictProcessedAt = -1;
}

// File Line: 1786
// RVA: 0x709530
void __fastcall Scaleform::GFx::AS2::ActionBuffer::ProcessDeclDict(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        int startPc,
        unsigned int stopPc,
        Scaleform::GFx::AS2::ActionLogger *log)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rdi
  unsigned int v9; // ebp
  char *pBuffer; // rdi
  int DeclDictProcessedAt; // eax
  Scaleform::GFx::AS2::ActionLogger *v12; // rbx
  unsigned int v13; // r15d
  unsigned int v14; // ebx
  _QWORD *p_Data; // r12
  __int64 v16; // r14
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *pNode; // r12
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS2::ActionLogger *v22; // rbx
  __int64 v23; // rbx
  __int64 v24; // rsi
  Scaleform::GFx::ASStringNode *v25; // r15
  Scaleform::GFx::ASString *v26; // rax
  const char *pData; // r14
  Scaleform::GFx::ASStringNode *v28; // rdi
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rcx
  __int64 v31; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-50h] BYREF
  __int64 v33; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::ASString v34; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::ASStringContext *v35; // [rsp+98h] [rbp+10h]

  v35 = psc;
  v33 = -2i64;
  pObject = this->pBufferData.pObject;
  v9 = 0;
  if ( !pObject->BufferLen || (pBuffer = pObject->pBuffer, !*pBuffer) )
    pBuffer = 0i64;
  DeclDictProcessedAt = this->DeclDictProcessedAt;
  if ( DeclDictProcessedAt != startPc )
  {
    if ( DeclDictProcessedAt == -1 )
    {
      this->DeclDictProcessedAt = startPc;
      v13 = (unsigned __int8)pBuffer[startPc + 3] | ((unsigned __int8)pBuffer[startPc + 4] << 8);
      v14 = startPc + 2;
      p_Data = &this->Dictionary.Data.Data;
      v34.pNode = (Scaleform::GFx::ASStringNode *)&this->Dictionary;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Dictionary.Data,
        v13);
      v16 = 0i64;
      if ( v13 )
      {
        while ( 1 )
        {
          v17 = Scaleform::GFx::AS2::ASStringContext::CreateString(v35, &result, &pBuffer[v14 + 3]);
          v31 = *p_Data + 8 * v16;
          pNode = v17->pNode;
          ++v17->pNode->RefCount;
          v19 = *(Scaleform::GFx::ASStringNode **)v31;
          v20 = (*(_DWORD *)(*(_QWORD *)v31 + 24i64))-- == 1;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          *(_QWORD *)v31 = pNode;
          v21 = result.pNode;
          v20 = result.pNode->RefCount-- == 1;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          if ( pBuffer[v14 + 3] )
            break;
LABEL_16:
          ++v14;
          ++v9;
          ++v16;
          if ( v9 >= v13 )
            return;
          p_Data = v34.pNode;
        }
        while ( v14 < stopPc )
        {
          if ( !pBuffer[++v14 + 3] )
            goto LABEL_16;
        }
        v22 = log;
        if ( log->vfptr->IsVerboseActionErrors(log) )
          Scaleform::GFx::AS2::ActionLogger::LogScriptError(v22, "Action buffer dict length exceeded");
        if ( v9 < v13 )
        {
          v23 = 8 * v16;
          v24 = v13 - v9;
          v25 = v34.pNode;
          do
          {
            v26 = Scaleform::GFx::AS2::ASStringContext::CreateString(v35, &v34, "<invalid>");
            pData = v25->pData;
            v28 = v26->pNode;
            ++v26->pNode->RefCount;
            v29 = *(Scaleform::GFx::ASStringNode **)&pData[v23];
            v20 = v29->RefCount-- == 1;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v29);
            *(_QWORD *)&pData[v23] = v28;
            v30 = v34.pNode;
            v20 = v34.pNode->RefCount-- == 1;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            v23 += 8i64;
            --v24;
          }
          while ( v24 );
        }
      }
    }
    else
    {
      v12 = log;
      if ( log->vfptr->IsVerboseActionErrors(log) )
        Scaleform::GFx::AS2::ActionLogger::LogScriptError(
          v12,
          "ProcessDeclDict(%d, %d) - DeclDict was already processed at %d",
          (unsigned int)startPc,
          stopPc,
          this->DeclDictProcessedAt);
    }
  }
}

// File Line: 1851
// RVA: 0x711D90
_BOOL8 __fastcall Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::GFx::AS2::Value *frameValue,
        Scaleform::GFx::InteractiveObject **pptarget,
        unsigned int *pframeNumber)
{
  Scaleform::GFx::InteractiveObject *Target; // rdi
  bool v8; // bp
  int Length; // esi
  __int64 v10; // r9
  signed int v11; // ebx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  long double v20; // xmm0_8
  _BOOL8 v21; // rax
  Scaleform::GFx::ASString v22; // [rsp+20h] [rbp-38h] BYREF
  __int64 v23; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString path; // [rsp+70h] [rbp+18h] BYREF

  v23 = -2i64;
  Target = env->Target;
  v8 = 0;
  if ( frameValue->T.Type != 5 )
  {
    if ( (unsigned __int8)(frameValue->T.Type - 3) > 1u )
      return 0i64;
    v20 = Scaleform::GFx::AS2::Value::ToNumber(frameValue, env);
    *pframeNumber = (int)(v20 - 1.0);
    v8 = 1;
    goto LABEL_25;
  }
  Scaleform::GFx::AS2::Value::ToString(frameValue, &result, env, -1);
  Length = Scaleform::GFx::ASConstString::GetLength(&result);
  v11 = 0;
  if ( Length <= 0 )
    goto LABEL_17;
  while ( Scaleform::GFx::ASConstString::GetCharAt(&result, v11) != 58 )
  {
LABEL_9:
    if ( ++v11 >= Length )
      goto LABEL_17;
  }
  Scaleform::GFx::ASString::Substring(&result, &path, 0, v11);
  Target = Scaleform::GFx::AS2::Environment::FindTarget(env, &path, 0);
  if ( !Target )
  {
LABEL_7:
    pNode = path.pNode;
    v13 = path.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_9;
  }
  if ( v11 >= Length )
  {
    Target = 0i64;
    goto LABEL_7;
  }
  v14 = Scaleform::GFx::ASString::Substring(&result, &v22, v11 + 1, Length + 1);
  v15 = v14->pNode;
  ++v14->pNode->RefCount;
  v16 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  result.pNode = v15;
  v17 = v22.pNode;
  v13 = v22.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = path.pNode;
  v13 = path.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
LABEL_17:
  if ( Target )
  {
    LOBYTE(v10) = 1;
    v8 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[108].__vecDelDtor)(
           Target,
           result.pNode->pData,
           pframeNumber,
           v10) != 0;
  }
  v19 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( !v8 )
    return 0i64;
LABEL_25:
  v21 = v8;
  if ( pptarget )
    *pptarget = Target;
  return v21;
}

// File Line: 1976
// RVA: 0x6CDA70
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::WithStackHolder(
        Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pinit)
{
  Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v6; // rbx

  this->pHeap = pheap;
  if ( pinit )
  {
    v5 = (Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(pheap, 24i64);
    v6 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)v5;
    if ( v5 )
    {
      v5->Data = 0i64;
      v5->Size = 0i64;
      v5->Policy.Capacity = 0i64;
      Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::Append(
        v5,
        pinit->Data.Data,
        pinit->Data.Size);
    }
    else
    {
      v6 = 0i64;
    }
    this->pWithStackArray = v6;
  }
  else
  {
    this->pWithStackArray = 0i64;
  }
}

// File Line: 1980
// RVA: 0x6D2AA0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::~WithStackHolder(
        Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // rbx

  pWithStackArray = this->pWithStackArray;
  if ( pWithStackArray )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray);
  }
}

// File Line: 1989
// RVA: 0x70ABB0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::PushBack(
        Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this,
        Scaleform::GFx::AS2::WithStackEntry *entry)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // rax

  if ( !this->pWithStackArray )
  {
    v4 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 24i64);
    if ( v4 )
    {
      v4->Data.Data = 0i64;
      v4->Data.Size = 0i64;
      v4->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    this->pWithStackArray = v4;
  }
  Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->pWithStackArray->Data,
    entry);
}

// File Line: 2031
// RVA: 0x6D1430
void __fastcall Scaleform::GFx::AS2::ExecutionContext::~ExecutionContext(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // rbx

  this->pEnv->pASLogger = this->pPrevLog;
  this->LogF.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable;
  pWithStackArray = this->WithStack.pWithStackArray;
  if ( pWithStackArray )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWithStackArray);
  }
}

// File Line: 2051
// RVA: 0x71C4D0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::SetTargetOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::InteractiveObject *pOriginalTarget; // rdi
  char Type; // r14
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS2::Environment *pEnv; // rax
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::CharacterHandle *pCharHandle; // rcx
  Scaleform::GFx::DisplayObject *v10; // rax
  bool v11; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS2::Environment *v15; // rbx
  Scaleform::GFx::InteractiveObject *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+30h] [rbp-1h] BYREF
  Scaleform::GFx::AS2::Value presult; // [rsp+50h] [rbp+1Fh] BYREF
  Scaleform::GFx::InteractiveObject *v21; // [rsp+98h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+6Fh] BYREF

  pOriginalTarget = 0i64;
  v21 = 0i64;
  Scaleform::GFx::AS2::Value::Value(&v19, this->pEnv->Stack.pCurrent);
  Type = v19.T.Type;
  if ( v19.T.Type == 5 )
  {
LABEL_14:
    v11 = Scaleform::GFx::AS2::Value::ToString(&v19, &result, this->pEnv, -1)->pNode->Size == 0;
    pNode = result.pNode;
    v6 = result.pNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v11 )
    {
      pOriginalTarget = this->pOriginalTarget;
      v21 = pOriginalTarget;
    }
    else
    {
      presult.T.Type = 0;
      v13 = Scaleform::GFx::AS2::Value::ToString(this->pEnv->Stack.pCurrent, &result, this->pEnv, -1);
      *(_DWORD *)&v19.T.Type = 0;
      Scaleform::GFx::AS2::Environment::GetVariable(this->pEnv, v13, &presult, this->WithStack.pWithStackArray);
      v14 = result.pNode;
      v6 = result.pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( presult.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&presult);
      pOriginalTarget = v21;
    }
    goto LABEL_23;
  }
  if ( v19.T.Type != 7 )
  {
    v4 = Scaleform::GFx::AS2::Value::ToStringVersioned(&v19, &result, this->pEnv, (unsigned __int8)this->Version);
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    Type = 5;
    v19.T.Type = 5;
    v19.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v4->pNode;
    ++v19.V.pStringNode->RefCount;
    v5 = result.pNode;
    v6 = result.pNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    goto LABEL_14;
  }
  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent->T.Type == 7 )
  {
    if ( pEnv )
    {
      pCharHandle = pCurrent->V.pCharHandle;
      if ( pCharHandle )
      {
        v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pCharHandle, pEnv->Target->pASRoot->pMovieImpl);
        if ( v10 )
        {
          if ( SLOBYTE(v10->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
            pOriginalTarget = (Scaleform::GFx::InteractiveObject *)v10;
        }
      }
    }
  }
  v21 = pOriginalTarget;
LABEL_23:
  v15 = this->pEnv;
  if ( pOriginalTarget )
  {
    v15->Target = pOriginalTarget;
    *((_BYTE *)v15 + 382) &= ~2u;
    v16 = pOriginalTarget;
  }
  else
  {
    v16 = this->pOriginalTarget;
    v15->Target = v16;
    *((_BYTE *)v15 + 382) |= 2u;
  }
  v15->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v16);
  v17 = this->pEnv;
  v18 = this->pEnv->Stack.pCurrent;
  if ( v18->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v18);
  if ( --v17->Stack.pCurrent < v17->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v17->Stack);
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
}

// File Line: 2122
// RVA: 0x720880
void __fastcall Scaleform::GFx::AS2::ExecutionContext::StartDragOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // rdx
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  Scaleform::GFx::AS2::Value *pPrevPageTop; // rcx
  bool v6; // bp
  Scaleform::GFx::InteractiveObject *TargetByValue; // rax
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // rcx
  unsigned int v10; // r8d
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r9
  unsigned int v13; // ecx
  long double v14; // xmm0_8
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // rcx
  float v17; // xmm1_4
  unsigned int v18; // r8d
  long double v19; // xmm0_8
  Scaleform::GFx::AS2::Environment *v20; // rdx
  Scaleform::GFx::AS2::Value *v21; // rcx
  float v22; // xmm1_4
  unsigned int v23; // r8d
  long double v24; // xmm0_8
  Scaleform::GFx::AS2::Environment *v25; // rdx
  float v26; // xmm1_4
  unsigned int v27; // ecx
  long double v28; // xmm0_8
  Scaleform::GFx::AS2::Environment *v29; // rbx
  int v30; // edi
  float v31; // xmm1_4
  Scaleform::GFx::AS2::Value *v32; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+20h] [rbp-48h] BYREF

  pEnv = this->pEnv;
  v2 = 0i64;
  memset(&st, 0, 18);
  memset(&st.BoundLT, 0, 24);
  st.MouseIndex = -1;
  pCurrent = pEnv->Stack.pCurrent;
  pPrevPageTop = pCurrent - 1;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  v6 = Scaleform::GFx::AS2::Value::ToBool(pPrevPageTop, pEnv);
  TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(this->pEnv, this->pEnv->Stack.pCurrent);
  v8 = this->pEnv;
  v9 = 0i64;
  st.pCharacter = TargetByValue;
  v10 = 32 * (LODWORD(v8->Stack.Pages.Data.Size) - 1) + v8->Stack.pCurrent - v8->Stack.pPageStart;
  if ( v10 >= 2 )
    v9 = &v8->Stack.Pages.Data.Data[(unsigned __int64)(v10 - 2) >> 5]->Values[((_BYTE)v10 - 2) & 0x1F];
  st.Bound = Scaleform::GFx::AS2::Value::ToBool(v9, v8);
  if ( st.Bound )
  {
    v11 = this->pEnv;
    v12 = 0i64;
    v13 = 32 * (LODWORD(v11->Stack.Pages.Data.Size) - 1) + v11->Stack.pCurrent - v11->Stack.pPageStart;
    if ( v13 >= 6 )
      v12 = &v11->Stack.Pages.Data.Data[(unsigned __int64)(v13 - 6) >> 5]->Values[((_BYTE)v13 - 6) & 0x1F];
    v14 = Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
    v15 = this->pEnv;
    v16 = 0i64;
    v17 = v14;
    st.BoundLT.x = v17 * 20.0;
    v18 = 32 * (LODWORD(v15->Stack.Pages.Data.Size) - 1) + v15->Stack.pCurrent - v15->Stack.pPageStart;
    if ( v18 >= 5 )
      v16 = &v15->Stack.Pages.Data.Data[(unsigned __int64)(v18 - 5) >> 5]->Values[((_BYTE)v18 - 5) & 0x1F];
    v19 = Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
    v20 = this->pEnv;
    v21 = 0i64;
    v22 = v19;
    st.BoundLT.y = v22 * 20.0;
    v23 = 32 * (LODWORD(v20->Stack.Pages.Data.Size) - 1) + v20->Stack.pCurrent - v20->Stack.pPageStart;
    if ( v23 >= 4 )
      v21 = &v20->Stack.Pages.Data.Data[(unsigned __int64)(v23 - 4) >> 5]->Values[((_BYTE)v23 - 4) & 0x1F];
    v24 = Scaleform::GFx::AS2::Value::ToNumber(v21, v20);
    v25 = this->pEnv;
    v26 = v24;
    st.BoundRB.x = v26 * 20.0;
    v27 = 32 * (LODWORD(v25->Stack.Pages.Data.Size) - 1) + v25->Stack.pCurrent - v25->Stack.pPageStart;
    if ( v27 >= 3 )
      v2 = &v25->Stack.Pages.Data.Data[(unsigned __int64)(v27 - 3) >> 5]->Values[((_BYTE)v27 - 3) & 0x1F];
    v28 = Scaleform::GFx::AS2::Value::ToNumber(v2, v25);
    v29 = this->pEnv;
    v30 = 4;
    v31 = v28;
    st.BoundRB.y = v31 * 20.0;
    do
    {
      v32 = v29->Stack.pCurrent;
      if ( v32->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v32);
      if ( --v29->Stack.pCurrent < v29->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v29->Stack);
      --v30;
    }
    while ( v30 );
  }
  if ( st.pCharacter )
  {
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, v6, 0);
    pMovieImpl = this->pEnv->Target->pASRoot->pMovieImpl;
    if ( pMovieImpl )
      Scaleform::GFx::MovieImpl::SetDragState(pMovieImpl, &st);
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&this->pEnv->Stack);
}

// File Line: 2165
// RVA: 0x6DC320
void __fastcall Scaleform::GFx::AS2::ExecutionContext::CastObjectOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rbx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rax
  _BOOL8 v6; // r9
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // rbx
  Scaleform::GFx::AS2::Value *v13; // rcx
  int v14; // edi
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v20; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-28h] BYREF

  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = this->pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  v.T.Type = 1;
  if ( pPrevPageTop->T.Type == 8 || pPrevPageTop->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(pPrevPageTop, &result, this->pEnv);
    if ( result.Function )
    {
      v4 = Scaleform::GFx::AS2::Value::ToObjectInterface(pCurrent, this->pEnv);
      if ( v4 )
      {
        v20.T.Type = 0;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, __int64))result.Function->vfptr->GetMemberRaw)(
               &result.Function->Scaleform::GFx::AS2::ObjectInterface,
               &this->pEnv->StringContext,
               &this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
               &v20,
               -2i64) )
        {
          v5 = Scaleform::GFx::AS2::Value::ToObject(&v20, this->pEnv);
          LOBYTE(v6) = 1;
          if ( v4->vfptr->InstanceOf(v4, this->pEnv, v5, v6) )
            Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, v4);
        }
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
      }
    }
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      Function = result.Function;
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v11 = result.pLocalFrame->RefCount;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  pEnv = this->pEnv;
  v13 = this->pEnv->Stack.pCurrent;
  if ( &v13[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v13->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v13);
    v16 = --pEnv->Stack.pCurrent;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    --pEnv->Stack.pCurrent;
  }
  else
  {
    v14 = 2;
    do
    {
      v15 = pEnv->Stack.pCurrent;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      if ( --pEnv->Stack.pCurrent < pEnv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&pEnv->Stack);
      --v14;
    }
    while ( v14 );
  }
  v17 = this->pEnv;
  if ( ++v17->Stack.pCurrent >= v17->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v17->Stack);
  v18 = v17->Stack.pCurrent;
  if ( v18 )
    Scaleform::GFx::AS2::Value::Value(v18, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}

// File Line: 2213
// RVA: 0x6FB7A0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::ImplementsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // rdx
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // rcx
  int v5; // esi
  Scaleform::GFx::AS2::Environment *v6; // rbx
  Scaleform::GFx::AS2::Value *v7; // rcx
  int v8; // edi
  Scaleform::GFx::AS2::Value *v9; // rcx
  Scaleform::GFx::AS2::Value *v10; // rcx
  char Type; // di
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::ObjectInterface *v13; // rdi
  unsigned int i; // ebx
  Scaleform::GFx::AS2::Environment *v15; // r8
  Scaleform::GFx::AS2::Value *v16; // r9
  unsigned int v17; // edx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v22; // eax
  char v23; // al
  Scaleform::GFx::AS2::FunctionObject *v24; // rcx
  unsigned int v25; // edx
  Scaleform::GFx::AS2::LocalFrame *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Environment *j; // rbx
  Scaleform::GFx::AS2::Value *v29; // rcx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+8h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::FunctionRef v31; // [rsp+20h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value v32; // [rsp+38h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value v33; // [rsp+58h] [rbp+17h] BYREF
  __int64 v34; // [rsp+78h] [rbp+37h]

  v34 = -2i64;
  Scaleform::GFx::AS2::Value::Value(&v33, this->pEnv->Stack.pCurrent);
  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(pPrevPageTop, pEnv);
  v6 = this->pEnv;
  v7 = this->pEnv->Stack.pCurrent;
  if ( &v7[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v10 = --v6->Stack.pCurrent;
    if ( v10->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v10);
    --v6->Stack.pCurrent;
  }
  else
  {
    v8 = 2;
    do
    {
      v9 = v6->Stack.pCurrent;
      if ( v9->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v9);
      if ( --v6->Stack.pCurrent < v6->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
      --v8;
    }
    while ( v8 );
  }
  Type = v33.T.Type;
  if ( v33.T.Type == 8 || v33.T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v33, &result, this->pEnv);
    if ( result.Function )
    {
      v32.T.Type = 0;
      if ( result.Function->vfptr->GetMemberRaw(
             &result.Function->Scaleform::GFx::AS2::ObjectInterface,
             &this->pEnv->StringContext,
             (Scaleform::GFx::ASString *)&this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
             &v32) )
      {
        v12 = Scaleform::GFx::AS2::Value::ToObject(&v32, this->pEnv);
        if ( v12 )
        {
          v13 = &v12->Scaleform::GFx::AS2::ObjectInterface;
          v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->AddInterface(
            &v12->Scaleform::GFx::AS2::ObjectInterface,
            &this->pEnv->StringContext,
            v5,
            0i64);
          for ( i = 0; (int)i < v5; ++i )
          {
            v15 = this->pEnv;
            v16 = 0i64;
            v17 = 32 * (this->pEnv->Stack.Pages.Data.Size - 1)
                + this->pEnv->Stack.pCurrent
                - this->pEnv->Stack.pPageStart;
            if ( i <= v17 )
              v16 = &v15->Stack.Pages.Data.Data[(v17 - i) >> 5]->Values[(v17 - i) & 0x1F];
            if ( v16->T.Type == 8 || v16->T.Type == 11 )
            {
              Scaleform::GFx::AS2::Value::ToFunction(v16, &v31, v15);
              if ( v31.Function )
                ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, _QWORD))v13->vfptr->AddInterface)(
                  v13,
                  &this->pEnv->StringContext,
                  i);
              Flags = v31.Flags;
              if ( (v31.Flags & 2) == 0 )
              {
                Function = v31.Function;
                if ( v31.Function )
                {
                  RefCount = v31.Function->RefCount;
                  if ( (RefCount & 0x3FFFFFF) != 0 )
                  {
                    v31.Function->RefCount = RefCount - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                    Flags = v31.Flags;
                  }
                }
              }
              v31.Function = 0i64;
              if ( (Flags & 1) == 0 )
              {
                pLocalFrame = v31.pLocalFrame;
                if ( v31.pLocalFrame )
                {
                  v22 = v31.pLocalFrame->RefCount;
                  if ( (v22 & 0x3FFFFFF) != 0 )
                  {
                    v31.pLocalFrame->RefCount = v22 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
                  }
                }
              }
              v31.pLocalFrame = 0i64;
            }
          }
        }
      }
      if ( v32.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v32);
    }
    v23 = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      v24 = result.Function;
      if ( result.Function )
      {
        v25 = result.Function->RefCount;
        if ( (v25 & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = v25 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          v23 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (v23 & 1) == 0 )
    {
      v26 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v27 = result.pLocalFrame->RefCount;
        if ( (v27 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
        }
      }
    }
    result.pLocalFrame = 0i64;
    Type = v33.T.Type;
  }
  for ( j = this->pEnv; v5; --v5 )
  {
    v29 = j->Stack.pCurrent;
    if ( v29->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v29);
    if ( --j->Stack.pCurrent < j->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&j->Stack);
  }
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
}

// File Line: 2267
// RVA: 0x6E2E60
void __fastcall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        int actionId)
{
  Scaleform::GFx::AS2::Environment *pEnv; // rbx
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  char Type; // r14
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rcx
  char *v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::AS2::ObjectInterface *v14; // rbx
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Environment *v16; // rdx
  Scaleform::GFx::DisplayObject *v17; // rax
  Scaleform::GFx::DisplayObject *v18; // rcx
  char *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v23; // zf
  Scaleform::GFx::AS2::Environment *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+40h] [rbp-49h] BYREF
  __int64 v27[3]; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+78h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+98h] [rbp+Fh] BYREF
  __int64 v30; // [rsp+B8h] [rbp+2Fh]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [rsp+100h] [rbp+77h]

  v30 = -2i64;
  Scaleform::GFx::AS2::Value::Value(&v28, this->pEnv->Stack.pCurrent);
  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
  if ( --pEnv->Stack.pCurrent < pEnv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&pEnv->Stack);
  v.T.Type = 0;
  Scaleform::GFx::AS2::Value::DropRefs(&v);
  Type = 1;
  v.T.Type = 1;
  v7 = this->pEnv;
  if ( ++v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v8 = (Scaleform::GFx::ASStringNode *)v7->Stack.pCurrent;
  result.pNode = v8;
  v32 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v8, &v);
    Type = v.T.Type;
  }
  if ( actionId != 85 )
  {
    Scaleform::GFx::AS2::Value::ToString(&v28, &result, this->pEnv, -1);
    presult.T.Type = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(
           this->pEnv,
           &result,
           &presult,
           this->WithStack.pWithStackArray,
           0i64,
           0i64,
           0) )
    {
      v16 = this->pEnv;
      if ( presult.T.Type == 7 )
      {
        if ( v16 )
        {
          if ( presult.V.pStringNode )
          {
            v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                    presult.V.pCharHandle,
                    v16->Target->pASRoot->pMovieImpl);
            if ( v17 )
            {
              v18 = 0i64;
              if ( SLOBYTE(v17->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
                v18 = v17;
              if ( v18 )
              {
                v19 = (char *)v18 + 4 * (unsigned __int8)v18->AvmObjOffset;
                v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v19 + 8i64))(v19);
                if ( v20 )
                {
                  v14 = (Scaleform::GFx::AS2::ObjectInterface *)(v20 + 8);
                  goto LABEL_35;
                }
              }
            }
          }
        }
      }
      else
      {
        v21 = Scaleform::GFx::AS2::Value::ToObject(&presult, v16);
        if ( v21 )
        {
          v14 = &v21->Scaleform::GFx::AS2::ObjectInterface;
LABEL_35:
          if ( v14 )
          {
            if ( presult.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&presult);
            pNode = result.pNode;
            v23 = result.pNode->RefCount-- == 1;
            if ( v23 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_40:
            v24 = this->pEnv;
            v27[0] = (__int64)`Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode::`15::EnumerateOpVisitor::`vftable;
            v27[1] = (__int64)v24;
            v27[2] = (__int64)&this->LogF;
            v14->vfptr->VisitMembers(
              v14,
              &this->pEnv->StringContext,
              (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)v27,
              11u,
              0i64);
            v27[0] = (__int64)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
            goto LABEL_45;
          }
        }
      }
    }
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    v25 = result.pNode;
    v23 = result.pNode->RefCount-- == 1;
    if ( v23 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    goto LABEL_45;
  }
  v9 = this->pEnv;
  if ( v28.T.Type != 7 )
  {
    v15 = Scaleform::GFx::AS2::Value::ToObject(&v28, v9);
    if ( !v15 )
      goto LABEL_45;
    v14 = &v15->Scaleform::GFx::AS2::ObjectInterface;
LABEL_21:
    if ( !v14 )
      goto LABEL_45;
    goto LABEL_40;
  }
  if ( v9 )
  {
    if ( v28.V.pStringNode )
    {
      v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v28.V.pCharHandle, v9->Target->pASRoot->pMovieImpl);
      if ( v10 )
      {
        v11 = 0i64;
        if ( SLOBYTE(v10->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
          v11 = v10;
        if ( v11 )
        {
          v12 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset;
          v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
          if ( v13 )
          {
            v14 = (Scaleform::GFx::AS2::ObjectInterface *)(v13 + 8);
            goto LABEL_21;
          }
        }
      }
    }
  }
LABEL_45:
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v28.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v28);
}

// File Line: 2313
// RVA: 0x723610
void __fastcall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode_::_15_::EnumerateOpVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *__formal,
        char flags)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringManager *pManager; // r8
  __int64 v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx

  pNode = name[1].pNode;
  pNode->pManager = (Scaleform::GFx::ASStringManager *)((char *)pNode->pManager + 32);
  if ( pNode->pManager >= (Scaleform::GFx::ASStringManager *)*(_QWORD *)&pNode->RefCount )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&pNode->pManager);
  pManager = pNode->pManager;
  if ( pManager )
  {
    LOBYTE(pManager->vfptr) = 5;
    v7 = *(_QWORD *)&__formal->T.Type;
    *(_QWORD *)&pManager->RefCount = *(_QWORD *)&__formal->T.Type;
    ++*(_DWORD *)(v7 + 24);
  }
  v8 = name[2].pNode;
  if ( v8 )
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
      (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *)v8,
      "---enumerate - Push: %s\n",
      **(const char ***)&__formal->T.Type);
}

// File Line: 2330
// RVA: 0x6E8DD0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::ExtendsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rdx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // rdx
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rbx
  Scaleform::GFx::AS2::ObjectProto *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rsi
  unsigned int RefCount; // eax
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // rbx
  Scaleform::GFx::AS2::Value *v13; // rcx
  int v14; // edi
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int v19; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v21; // eax
  char v22; // al
  Scaleform::GFx::AS2::FunctionObject *v23; // rcx
  unsigned int v24; // edx
  Scaleform::GFx::AS2::LocalFrame *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::FunctionRef v28; // [rsp+38h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::Value v29; // [rsp+50h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v30; // [rsp+70h] [rbp-19h] BYREF
  __int64 v31; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS2::Value v32; // [rsp+98h] [rbp+Fh] BYREF

  v31 = -2i64;
  Scaleform::GFx::AS2::Value::Value(&v32, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = this->pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  Scaleform::GFx::AS2::Value::Value(&v30, pPrevPageTop);
  Scaleform::GFx::AS2::Value::ToFunction(&v32, &result, this->pEnv);
  Scaleform::GFx::AS2::Value::ToFunction(&v30, &v28, this->pEnv);
  if ( result.Function && v28.Function )
  {
    v29.T.Type = 0;
    if ( result.Function->vfptr->GetMemberRaw(
           &result.Function->Scaleform::GFx::AS2::ObjectInterface,
           &this->pEnv->StringContext,
           (Scaleform::GFx::ASString *)&this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v29)
      && v29.T.Type == 6 )
    {
      v4 = Scaleform::GFx::AS2::Value::ToObject(&v29, this->pEnv);
      v6 = v4;
      if ( v4 )
        v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
      v7 = (Scaleform::GFx::AS2::ObjectProto *)this->pEnv->StringContext.pContext->pHeap->vfptr->Alloc(v5, 160i64, 0i64);
      if ( v7 )
      {
        Scaleform::GFx::AS2::ObjectProto::ObjectProto(v7, &this->pEnv->StringContext, v6);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      Scaleform::GFx::AS2::FunctionObject::SetPrototype(v28.Function, &this->pEnv->StringContext, v9);
      Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        &v9->Scaleform::GFx::AS2::ObjectInterface,
        &this->pEnv->StringContext,
        &result);
      if ( v9 )
      {
        RefCount = v9->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      if ( v6 )
      {
        v11 = v6->RefCount;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          v6->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
    if ( v29.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v29);
  }
  pEnv = this->pEnv;
  v13 = this->pEnv->Stack.pCurrent;
  if ( &v13[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v13->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v13);
    v16 = --pEnv->Stack.pCurrent;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    --pEnv->Stack.pCurrent;
  }
  else
  {
    v14 = 2;
    do
    {
      v15 = pEnv->Stack.pCurrent;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      if ( --pEnv->Stack.pCurrent < pEnv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&pEnv->Stack);
      --v14;
    }
    while ( v14 );
  }
  Flags = v28.Flags;
  if ( (v28.Flags & 2) == 0 )
  {
    Function = v28.Function;
    if ( v28.Function )
    {
      v19 = v28.Function->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        v28.Function->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = v28.Flags;
      }
    }
  }
  v28.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = v28.pLocalFrame;
    if ( v28.pLocalFrame )
    {
      v21 = v28.pLocalFrame->RefCount;
      if ( (v21 & 0x3FFFFFF) != 0 )
      {
        v28.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  v28.pLocalFrame = 0i64;
  v22 = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    v23 = result.Function;
    if ( result.Function )
    {
      v24 = result.Function->RefCount;
      if ( (v24 & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = v24 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
        v22 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( (v22 & 1) == 0 )
  {
    v25 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v26 = result.pLocalFrame->RefCount;
      if ( (v26 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v26 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
      }
    }
  }
  result.pLocalFrame = 0i64;
  if ( v30.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v30);
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
}

// File Line: 2385
// RVA: 0x6FDAF0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::InstanceOfOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // r8
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // rbx
  bool v5; // bp
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  _BOOL8 v8; // r9
  char Flags; // dl
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // rbx
  Scaleform::GFx::AS2::Value *v15; // rcx
  int v16; // edi
  Scaleform::GFx::AS2::Value *v17; // rcx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Environment *v19; // rbx
  Scaleform::GFx::AS2::Value *v20; // rax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+40h] [rbp-38h] BYREF

  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  pPrevPageTop = pCurrent - 1;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  v5 = 0;
  if ( pCurrent->T.Type == 8 || pCurrent->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(pCurrent, &result, pEnv);
    if ( result.Function )
    {
      v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(pPrevPageTop, this->pEnv);
      if ( v6 )
      {
        v22.T.Type = 0;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, __int64))result.Function->vfptr->GetMemberRaw)(
               &result.Function->Scaleform::GFx::AS2::ObjectInterface,
               &this->pEnv->StringContext,
               &this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
               &v22,
               -2i64) )
        {
          v7 = Scaleform::GFx::AS2::Value::ToObject(&v22, this->pEnv);
          LOBYTE(v8) = 1;
          v5 = v6->vfptr->InstanceOf(v6, this->pEnv, v7, v8);
        }
        if ( v22.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v22);
      }
    }
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      Function = result.Function;
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v13 = result.pLocalFrame->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  v14 = this->pEnv;
  v15 = this->pEnv->Stack.pCurrent;
  if ( &v15[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    v18 = --v14->Stack.pCurrent;
    if ( v18->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v18);
    --v14->Stack.pCurrent;
  }
  else
  {
    v16 = 2;
    do
    {
      v17 = v14->Stack.pCurrent;
      if ( v17->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v17);
      if ( --v14->Stack.pCurrent < v14->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v14->Stack);
      --v16;
    }
    while ( v16 );
  }
  v19 = this->pEnv;
  if ( ++v19->Stack.pCurrent >= v19->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v19->Stack);
  v20 = v19->Stack.pCurrent;
  if ( v20 )
  {
    v20->T.Type = 2;
    v20->V.BooleanValue = v5;
  }
}->Stack);
  v20 = v19->Stack.pCurrent;
  if ( v20 )
  

// File Line: 2427
// RVA: 0x724370
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WaitForFrameOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::AS2::ActionBuffer *pActions,
        int actionId)
{
  int v3; // ebx
  Scaleform::GFx::AS2::Environment *pEnv; // rdx
  Scaleform::GFx::InteractiveObject *Target; // rsi
  char v8; // r15
  const char *v9; // rdx
  unsigned int v10; // ebp
  bool v11; // al
  Scaleform::GFx::AS2::Environment *v12; // r14
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int BufferLen; // r10d
  __int64 v17; // rax
  const char *pBuffer; // r9
  __int64 v19; // rcx
  unsigned int pframeNumber; // [rsp+70h] [rbp+18h] BYREF

  v3 = 0;
  pEnv = this->pEnv;
  pframeNumber = 0;
  Target = 0i64;
  if ( (*((_BYTE *)pEnv + 382) & 2) == 0 && (pEnv->Target->Flags & 0x400) != 0 )
    Target = pEnv->Target;
  if ( actionId == 138 )
  {
    v8 = 1;
    v9 = &this->pBuffer[this->PC];
    pframeNumber = *(unsigned __int16 *)(v9 + 3);
    v10 = *((unsigned __int8 *)v9 + 5);
  }
  else
  {
    v11 = Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(
            pActions,
            pEnv,
            pEnv->Stack.pCurrent,
            0i64,
            &pframeNumber);
    v12 = this->pEnv;
    v10 = (unsigned __int8)this->pBuffer[this->PC + 3];
    v8 = v11;
    pCurrent = this->pEnv->Stack.pCurrent;
    if ( pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
    if ( --v12->Stack.pCurrent < v12->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
  }
  if ( Target && v8 )
  {
    v14 = ((__int64 (__fastcall *)(Scaleform::RefCountNTSImplCoreVtbl **))Target[1].pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::$CFA0FEAB6C317A8124CFA738756F89CC::vfptr[10].__vecDelDtor)(&Target[1].pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::$CFA0FEAB6C317A8124CFA738756F89CC::vfptr);
    if ( v14 && pframeNumber >= v14 )
      pframeNumber = v14 - 1;
    v15 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[111].__vecDelDtor)(Target);
    if ( pframeNumber >= v15 )
    {
      BufferLen = pActions->pBufferData.pObject->BufferLen;
      LODWORD(v17) = this->NextPC;
      if ( v10 )
      {
        while ( (unsigned int)v17 < BufferLen )
        {
          pBuffer = this->pBuffer;
          v19 = (unsigned int)v17;
          v17 = (unsigned int)(v17 + 1);
          if ( pBuffer[v19] < 0 )
            LODWORD(v17) = ((unsigned __int8)pBuffer[v17] | ((unsigned __int8)pBuffer[(unsigned int)(v17 + 1)] << 8))
                         + v17
                         + 2;
          if ( ++v3 >= v10 )
            goto LABEL_21;
        }
      }
      else
      {
LABEL_21:
        if ( (unsigned int)v17 < BufferLen )
          this->NextPC = v17;
      }
    }
  }
}

// File Line: 2493
// RVA: 0x6EC180
void __fastcall Scaleform::GFx::AS2::ExecutionContext::Function1OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::AS2::ActionBuffer *pActions)
{
  Scaleform::GFx::AS2::AsFunctionObject *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r14
  int v7; // ebx
  unsigned int v8; // r12d
  int v9; // edx
  unsigned int v10; // r12d
  _QWORD *v11; // rdi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r15
  __int64 v14; // rcx
  __int64 i; // rbx
  __int64 v16; // rax
  __int64 v17; // r15
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  int v22; // edx
  Scaleform::GFx::AS2::LocalFrame *v23; // r15
  Scaleform::GFx::AS2::LocalFrame *Size; // rcx
  Scaleform::GFx::InteractiveObject *Target; // rcx
  __int64 v26; // rax
  char *v27; // rcx
  __int64 v28; // r12
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Environment *pEnv; // rbx
  Scaleform::GFx::AS2::Object *v31; // rax
  Scaleform::GFx::AS2::Environment *v32; // rbx
  __int64 v33; // rax
  Scaleform::GFx::AS2::Environment *v34; // rbx
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  int v36; // eax
  int v37; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v39; // rcx
  int v40; // eax
  Scaleform::GFx::AS2::Value v; // [rsp+48h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+68h] [rbp-31h] BYREF
  __int64 v43; // [rsp+80h] [rbp-19h]
  __int64 v44; // [rsp+88h] [rbp-11h]
  __int64 v45; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS2::Value v46; // [rsp+98h] [rbp-1h] BYREF
  Scaleform::GFx::ASString v47; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h] BYREF
  __int64 v49; // [rsp+118h] [rbp+7Fh]

  v44 = -2i64;
  v47.pNode = (Scaleform::GFx::ASStringNode *)this->pEnv->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::AS2::AsFunctionObject *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::ExecutionContext *, __int64, _QWORD))v47.pNode->pData
                                                 + 10))(
                                                  this,
                                                  200i64,
                                                  0i64);
  v49 = (__int64)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      v4,
      this->pEnv,
      pActions,
      this->NextPC,
      0,
      this->WithStack.pWithStackArray,
      Exec_Function);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v45 = v6;
  v7 = this->PC + 3;
  Scaleform::GFx::AS2::Environment::CreateString(this->pEnv, &result, &this->pBuffer[v7]);
  v8 = v7 + result.pNode->Size + 1;
  v9 = *(unsigned __int16 *)&this->pBuffer[v8];
  v10 = v8 + 2;
  if ( v9 > 0 )
  {
    v11 = (_QWORD *)(v6 + 152);
    v49 = (unsigned int)v9;
    do
    {
      Scaleform::GFx::AS2::Environment::CreateString(this->pEnv, &v47, &this->pBuffer[v10]);
      v12 = *(_QWORD *)(v6 + 160) + 1i64;
      v13 = *(_QWORD *)(v6 + 160);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v6 + 152),
        (const void *)(v6 + 152),
        v12);
      if ( v12 > v13 )
      {
        v14 = *v11 + 16 * v13;
        v43 = v14;
        for ( i = v12 - v13; i; --i )
        {
          if ( v14 )
          {
            *(_DWORD *)v14 = *(_DWORD *)(v6 + 176);
            v16 = *(_QWORD *)(v6 + 184);
            *(_QWORD *)(v14 + 8) = v16;
            ++*(_DWORD *)(v16 + 24);
          }
          v14 += 16i64;
          v43 = v14;
        }
      }
      v17 = *v11 + 16i64 * *(_QWORD *)(v6 + 160);
      *(_DWORD *)(v17 - 16) = 0;
      pNode = v47.pNode;
      ++v47.pNode->RefCount;
      v19 = *(Scaleform::GFx::ASStringNode **)(v17 - 8);
      v20 = v19->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      *(_QWORD *)(v17 - 8) = pNode;
      v10 += pNode->Size + 1;
      v21 = v47.pNode;
      v20 = v47.pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      --v49;
    }
    while ( v49 );
  }
  v22 = *(unsigned __int16 *)&this->pBuffer[v10];
  *(_DWORD *)(v6 + 148) = v22;
  this->NextPC += v22;
  constructor.Flags = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  v23 = 0i64;
  constructor.pLocalFrame = 0i64;
  Size = (Scaleform::GFx::AS2::LocalFrame *)this->pEnv->LocalFrames.Data.Size;
  if ( Size )
  {
    Size = this->pEnv->LocalFrames.Data.Data[(_QWORD)Size - 1].pObject;
    if ( Size )
    {
      v23 = Size;
      constructor.pLocalFrame = Size;
      constructor.Flags = 0;
      Size->RefCount = (Size->RefCount + 1) & 0x8FFFFFFF;
    }
  }
  v.T.Type = 8;
  v.V.FunctionValue.Flags = 0;
  v.V.pStringNode = (Scaleform::GFx::ASStringNode *)v6;
  *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  v.V.FunctionValue.pLocalFrame = 0i64;
  if ( v23 )
  {
    v.V.FunctionValue.pLocalFrame = v23;
    v.V.FunctionValue.Flags &= ~1u;
    if ( (v.V.FunctionValue.Flags & 1) == 0 )
      v23->RefCount = (v23->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( result.pNode->Size )
  {
    Target = this->pEnv->Target;
    if ( Target )
    {
      v27 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
      v26 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v27 + 8i64))(v27);
    }
    else
    {
      v26 = 0i64;
    }
    LOBYTE(v47.pNode) = 0;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString *))(*(_QWORD *)(v26 + 8) + 80i64))(
      v26 + 8,
      &this->pEnv->StringContext,
      &result,
      &v,
      &v47);
  }
  v47.pNode = (Scaleform::GFx::ASStringNode *)this->pEnv->StringContext.pContext->pHeap;
  v28 = (*((__int64 (__fastcall **)(Scaleform::GFx::AS2::LocalFrame *, __int64, _QWORD))v47.pNode->pData + 10))(
          Size,
          160i64,
          0i64);
  v49 = v28;
  if ( v28 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    pEnv = this->pEnv;
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v28, &this->pEnv->StringContext, Prototype);
    *(_QWORD *)(v28 + 96) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v28 + 120) = 0;
    *(_QWORD *)(v28 + 104) = 0i64;
    *(_QWORD *)(v28 + 112) = 0i64;
    *(_BYTE *)(v28 + 144) = 0;
    *(_QWORD *)(v28 + 128) = 0i64;
    *(_QWORD *)(v28 + 136) = 0i64;
    *(_QWORD *)(v28 + 152) = 0i64;
    *(_QWORD *)v28 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v28 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v28 + 96) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v28 + 96),
      (Scaleform::GFx::AS2::Object *)v28,
      &pEnv->StringContext,
      &constructor);
    *(_QWORD *)v28 = &Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v28 + 32) = &Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v28 + 96) = &Scaleform::GFx::AS2::FunctionProto::`vftable;
  }
  else
  {
    v28 = 0i64;
  }
  v49 = v28;
  v31 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(
    (Scaleform::GFx::AS2::FunctionObject *)v6,
    &this->pEnv->StringContext,
    v31);
  v32 = this->pEnv;
  Scaleform::GFx::AS2::Value::Value(&v46, (Scaleform::GFx::ASStringNode *)v28);
  LOBYTE(v47.pNode) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, volatile int *, __int64, Scaleform::GFx::ASString *))(*(_QWORD *)(v6 + 32) + 80i64))(
    v6 + 32,
    &v32->StringContext,
    &v32->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v33,
    &v47);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  if ( !result.pNode->Size )
  {
    v34 = this->pEnv;
    if ( ++v34->Stack.pCurrent >= v34->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v34->Stack);
    pCurrent = (Scaleform::GFx::ASStringNode *)v34->Stack.pCurrent;
    v47.pNode = pCurrent;
    if ( pCurrent )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, &v);
  }
  if ( v28 )
  {
    v36 = *(_DWORD *)(v28 + 24);
    if ( (v36 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v28 + 24) = v36 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v28);
    }
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v37 = *(_DWORD *)(v6 + 24);
  if ( (v37 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v6 + 24) = v37 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
  }
  constructor.Function = 0i64;
  if ( v23 )
  {
    RefCount = v23->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v23->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
    }
  }
  constructor.pLocalFrame = 0i64;
  v39 = result.pNode;
  v20 = result.pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = *(_DWORD *)(v6 + 24);
  if ( (v40 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v6 + 24) = v40 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
  }
}

// File Line: 2573
// RVA: 0x6EC6A0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::Function2OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::AS2::ActionBuffer *pActions)
{
  Scaleform::GFx::ASStringNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r15
  int v7; // ebx
  unsigned int v8; // esi
  const char *pBuffer; // rcx
  int v10; // r8d
  __int16 v11; // dx
  unsigned int v12; // esi
  _QWORD *v13; // rdi
  const char *v14; // rcx
  unsigned int v15; // esi
  const char *v16; // r8
  __int64 v17; // rax
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r14
  __int64 v20; // rcx
  __int64 i; // rbx
  __int64 v22; // rax
  __int64 v23; // r14
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::ASStringNode *v27; // rcx
  int v28; // edx
  Scaleform::GFx::AS2::LocalFrame *v29; // rdi
  Scaleform::GFx::AS2::LocalFrame *Size; // rcx
  Scaleform::GFx::InteractiveObject *Target; // rcx
  __int64 v32; // rax
  char *v33; // rcx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  __int64 v35; // rsi
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *v37; // rax
  __int64 v38; // rax
  Scaleform::GFx::AS2::Environment *pEnv; // rbx
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  int v41; // eax
  int v42; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v44; // rcx
  int v45; // eax
  __int64 v46; // [rsp+40h] [rbp-59h]
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+70h] [rbp-29h] BYREF
  __int64 v49; // [rsp+88h] [rbp-11h]
  __int64 v50; // [rsp+90h] [rbp-9h]
  __int64 v51; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS2::Value v52; // [rsp+A0h] [rbp+7h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v55; // [rsp+118h] [rbp+7Fh] BYREF

  v51 = -2i64;
  pHeap = this->pEnv->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::ASStringNode *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 200ui64, 0i64);
  v55.pNode = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      (Scaleform::GFx::AS2::AsFunctionObject *)v4,
      this->pEnv,
      pActions,
      this->NextPC,
      0,
      this->WithStack.pWithStackArray,
      Exec_Function2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v50 = v6;
  v7 = this->PC + 3;
  Scaleform::GFx::AS2::Environment::CreateString(this->pEnv, &result, &this->pBuffer[v7]);
  v8 = v7 + result.pNode->Size + 1;
  pBuffer = this->pBuffer;
  v10 = *(unsigned __int16 *)&pBuffer[v8];
  v8 += 2;
  LOBYTE(pBuffer) = pBuffer[v8++];
  *(_BYTE *)(v6 + 195) = (_BYTE)pBuffer;
  v11 = *(_WORD *)&this->pBuffer[v8];
  v12 = v8 + 2;
  *(_WORD *)(v6 + 192) = v11;
  if ( v10 > 0 )
  {
    v13 = (_QWORD *)(v6 + 152);
    v46 = (unsigned int)v10;
    do
    {
      v14 = this->pBuffer;
      LODWORD(pHeap) = (unsigned __int8)v14[v12];
      v15 = v12 + 1;
      v16 = &v14[v15];
      v17 = -1i64;
      do
        ++v17;
      while ( v16[v17] );
      Scaleform::GFx::AS2::Environment::CreateString(this->pEnv, &v55, v16, (unsigned int)v17);
      v18 = *(_QWORD *)(v6 + 160) + 1i64;
      v19 = *(_QWORD *)(v6 + 160);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v6 + 152),
        (const void *)(v6 + 152),
        v18);
      if ( v18 > v19 )
      {
        v20 = *v13 + 16 * v19;
        v49 = v20;
        for ( i = v18 - v19; i; --i )
        {
          if ( v20 )
          {
            *(_DWORD *)v20 = *(_DWORD *)(v6 + 176);
            v22 = *(_QWORD *)(v6 + 184);
            *(_QWORD *)(v20 + 8) = v22;
            ++*(_DWORD *)(v22 + 24);
          }
          v20 += 16i64;
          v49 = v20;
        }
      }
      v23 = *v13 + 16i64 * *(_QWORD *)(v6 + 160);
      *(_DWORD *)(v23 - 16) = (_DWORD)pHeap;
      pNode = v55.pNode;
      ++v55.pNode->RefCount;
      v25 = *(Scaleform::GFx::ASStringNode **)(v23 - 8);
      v26 = v25->RefCount-- == 1;
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      *(_QWORD *)(v23 - 8) = pNode;
      v12 = pNode->Size + 1 + v15;
      v27 = v55.pNode;
      v26 = v55.pNode->RefCount-- == 1;
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      --v46;
    }
    while ( v46 );
  }
  v28 = *(unsigned __int16 *)&this->pBuffer[v12];
  *(_DWORD *)(v6 + 148) = v28;
  this->NextPC += v28;
  constructor.Flags = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  v29 = 0i64;
  constructor.pLocalFrame = 0i64;
  Size = (Scaleform::GFx::AS2::LocalFrame *)this->pEnv->LocalFrames.Data.Size;
  if ( Size )
  {
    Size = this->pEnv->LocalFrames.Data.Data[(_QWORD)Size - 1].pObject;
    if ( Size )
    {
      v29 = Size;
      constructor.pLocalFrame = Size;
      constructor.Flags = 0;
      Size->RefCount = (Size->RefCount + 1) & 0x8FFFFFFF;
    }
  }
  v.T.Type = 8;
  v.V.FunctionValue.Flags = 0;
  v.V.pStringNode = (Scaleform::GFx::ASStringNode *)v6;
  *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  v.V.FunctionValue.pLocalFrame = 0i64;
  if ( v29 )
  {
    v.V.FunctionValue.pLocalFrame = v29;
    v.V.FunctionValue.Flags &= ~1u;
    if ( (v.V.FunctionValue.Flags & 1) == 0 )
      v29->RefCount = (v29->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( result.pNode->Size )
  {
    Target = this->pEnv->Target;
    if ( Target )
    {
      v33 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
      v32 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v33 + 8i64))(v33);
    }
    else
    {
      v32 = 0i64;
    }
    LOBYTE(pHeap) = 0;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)(v32 + 8) + 80i64))(
      v32 + 8,
      &this->pEnv->StringContext,
      &result,
      &v,
      &pHeap);
  }
  p_StringContext = &this->pEnv->StringContext;
  pHeap = p_StringContext->pContext->pHeap;
  v35 = (__int64)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)Size, 160ui64, 0i64);
  v55.pNode = (Scaleform::GFx::ASStringNode *)v35;
  if ( v35 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v35, p_StringContext, Prototype);
    *(_QWORD *)(v35 + 96) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v35 + 120) = 0;
    *(_QWORD *)(v35 + 104) = 0i64;
    *(_QWORD *)(v35 + 112) = 0i64;
    *(_BYTE *)(v35 + 144) = 0;
    *(_QWORD *)(v35 + 128) = 0i64;
    *(_QWORD *)(v35 + 136) = 0i64;
    *(_QWORD *)(v35 + 152) = 0i64;
    *(_QWORD *)v35 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v35 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v35 + 96) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v35 + 96),
      (Scaleform::GFx::AS2::Object *)v35,
      p_StringContext,
      &constructor);
    *(_QWORD *)v35 = &Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v35 + 32) = &Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v35 + 96) = &Scaleform::GFx::AS2::FunctionProto::`vftable;
  }
  else
  {
    v35 = 0i64;
  }
  v55.pNode = (Scaleform::GFx::ASStringNode *)v35;
  v37 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor((Scaleform::GFx::AS2::FunctionObject *)v6, p_StringContext, v37);
  Scaleform::GFx::AS2::Value::Value(&v52, (Scaleform::GFx::ASStringNode *)v35);
  LOBYTE(pHeap) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, volatile int *, __int64, Scaleform::MemoryHeap **))(*(_QWORD *)(v6 + 32) + 80i64))(
    v6 + 32,
    p_StringContext,
    &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v38,
    &pHeap);
  if ( v52.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v52);
  if ( !result.pNode->Size )
  {
    pEnv = this->pEnv;
    if ( ++pEnv->Stack.pCurrent >= pEnv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&pEnv->Stack);
    pCurrent = pEnv->Stack.pCurrent;
    pHeap = (Scaleform::MemoryHeap *)pCurrent;
    if ( pCurrent )
      Scaleform::GFx::AS2::Value::Value(pCurrent, &v);
  }
  if ( v35 )
  {
    v41 = *(_DWORD *)(v35 + 24);
    if ( (v41 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v35 + 24) = v41 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v35);
    }
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v42 = *(_DWORD *)(v6 + 24);
  if ( (v42 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v6 + 24) = v42 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
  }
  constructor.Function = 0i64;
  if ( v29 )
  {
    RefCount = v29->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v29->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
    }
  }
  constructor.pLocalFrame = 0i64;
  v44 = result.pNode;
  v26 = result.pNode->RefCount-- == 1;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  v45 = *(_DWORD *)(v6 + 24);
  if ( (v45 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v6 + 24) = v45 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
  }
}

// File Line: 2720
// RVA: 0x6E3290
Scaleform::GFx::AS2::ActionBuffer::Execute

// File Line: 5287
// RVA: 0x6DD1B0
void __fastcall Scaleform::GFx::AS2::Environment::CheckTryBlocks(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int pc,
        int *plocalTryBlockCount)
{
  int v3; // ebx
  unsigned __int64 i; // rax
  Scaleform::GFx::AS2::Environment::TryDescr *Data; // rcx
  __int64 v9; // rax
  unsigned int TryBeginPC; // r9d

  v3 = *plocalTryBlockCount;
  if ( *plocalTryBlockCount > 0 )
  {
    for ( i = this->TryBlocks.Data.Size; i; --v3 )
    {
      if ( v3 < 0 )
        break;
      Data = this->TryBlocks.Data.Data;
      v9 = i;
      TryBeginPC = Data[v9 - 1].TryBeginPC;
      if ( pc >= TryBeginPC
        && pc < TryBeginPC
              + (*((unsigned __int8 *)Data[v9 - 1].pTryBlock + 1) | (*((unsigned __int8 *)Data[v9 - 1].pTryBlock + 2) << 8)) )
      {
        break;
      }
      --*plocalTryBlockCount;
      Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->TryBlocks.Data,
        this->TryBlocks.Data.Size - 1);
      i = this->TryBlocks.Data.Size;
    }
  }
}

// File Line: 5316
// RVA: 0x6DC8B0
__int64 __fastcall Scaleform::GFx::AS2::Environment::CheckExceptions(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ActionBuffer *pactBuf,
        unsigned int nextPc,
        int *plocalTryBlockCount,
        Scaleform::GFx::AS2::Value *retval,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  int *v7; // rbx
  Scaleform::GFx::AS2::ActionBuffer *v8; // rsi
  Scaleform::GFx::AS2::Value *p_ThrowingValue; // rax
  char v11; // r12
  int v12; // r13d
  unsigned __int64 Size; // r8
  Scaleform::GFx::AS2::Environment::TryDescr *Data; // rax
  const char *pTryBlock; // r14
  __int64 v16; // r15
  unsigned int v17; // esi
  int i; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  unsigned __int64 v20; // r15
  unsigned __int64 v21; // r8
  unsigned __int64 v22; // rcx
  Scaleform::GFx::AS2::Value *GlobalRegister; // rcx
  Scaleform::GFx::AS2::Value *v24; // r12
  Scaleform::GFx::AS2::LocalFrame *TopLocalFrame; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // rbx
  Scaleform::GFx::AS2::LocalFrame *NewLocalFrame; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *CatchName; // rbp
  unsigned __int64 v32; // rax
  Scaleform::GFx::AS2::Value *Local; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v36; // eax
  unsigned int v37; // eax
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType v38; // ebp
  __int64 v39; // r8
  unsigned __int64 v40; // rcx
  Scaleform::GFx::AS2::Value *v41; // rcx
  unsigned __int64 v42; // rbp
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v43; // rcx
  unsigned __int64 j; // rbx
  int v45; // r8d
  Scaleform::GFx::AS2::Environment::TryDescr v47; // [rsp+48h] [rbp-A0h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp-90h] BYREF
  Scaleform::GFx::AS2::LocalFrame *v49; // [rsp+60h] [rbp-88h]
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v50; // [rsp+68h] [rbp-80h]
  __int64 v51; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::LocalFrame *v52; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-68h] BYREF
  int v54; // [rsp+F0h] [rbp+8h]

  v51 = -2i64;
  v7 = plocalTryBlockCount;
  v8 = pactBuf;
  p_ThrowingValue = &this->ThrowingValue;
LABEL_3:
  while ( 1 )
  {
    v11 = 0;
    if ( p_ThrowingValue->T.Type == 10 )
      return nextPc;
    v12 = *v7;
    if ( *v7 <= 0 )
      return v8->pBufferData.pObject->BufferLen;
    do
    {
      if ( v11 )
      {
        p_ThrowingValue = &this->ThrowingValue;
        goto LABEL_3;
      }
      Size = this->TryBlocks.Data.Size;
      Data = this->TryBlocks.Data.Data;
      pTryBlock = Data[Size - 1].pTryBlock;
      v47.pTryBlock = pTryBlock;
      v16 = *(_QWORD *)&Data[Size - 1].TryBeginPC;
      v54 = v16;
      *(_QWORD *)&v47.TryBeginPC = v16;
      Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->TryBlocks.Data,
        Size - 1);
      --*v7;
      v17 = 32 * (this->Stack.Pages.Data.Size - 1) + this->Stack.pCurrent - this->Stack.pPageStart;
      if ( v17 > v47.TopStackIndex )
      {
        for ( i = v17 - v47.TopStackIndex; i; --i )
        {
          pCurrent = this->Stack.pCurrent;
          if ( pCurrent->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
          if ( --this->Stack.pCurrent < this->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&this->Stack);
        }
      }
      if ( (*pTryBlock & 1) == 0 )
        goto LABEL_58;
      LODWORD(v20) = 0;
      if ( (*pTryBlock & 4) != 0 )
      {
        v21 = *((unsigned __int8 *)pTryBlock + 7);
        v22 = this->LocalRegister.Data.Size;
        if ( v21 < v22 )
        {
          GlobalRegister = &this->LocalRegister.Data.Data[v22 - v21 - 1];
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            this,
            "Invalid local register %d, stack only has %d entries",
            v21,
            (unsigned int)v22);
          GlobalRegister = this->GlobalRegister;
        }
        v24 = &this->ThrowingValue;
        Scaleform::GFx::AS2::Value::operator=(GlobalRegister, &this->ThrowingValue);
      }
      else
      {
        v20 = this->LocalFrames.Data.Size;
        TopLocalFrame = Scaleform::GFx::AS2::Environment::GetTopLocalFrame(this, 0);
        v26 = TopLocalFrame;
        if ( TopLocalFrame )
          TopLocalFrame->RefCount = (TopLocalFrame->RefCount + 1) & 0x8FFFFFFF;
        v49 = TopLocalFrame;
        NewLocalFrame = Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(this);
        v28 = NewLocalFrame;
        if ( NewLocalFrame )
          NewLocalFrame->RefCount = (NewLocalFrame->RefCount + 1) & 0x8FFFFFFF;
        v52 = NewLocalFrame;
        if ( v26 )
          v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
        pObject = NewLocalFrame->PrevFrame.pObject;
        if ( pObject )
        {
          RefCount = pObject->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
          }
        }
        v28[1].pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v26;
        CatchName = Scaleform::GFx::AS2::Environment::TryDescr::GetCatchName(&v47, &result, this);
        v32 = this->LocalFrames.Data.Size;
        if ( v32 && this->LocalFrames.Data.Data[v32 - 1].pObject )
        {
          Local = Scaleform::GFx::AS2::Environment::FindLocal(this, CatchName);
          v24 = &this->ThrowingValue;
          if ( Local )
            Scaleform::GFx::AS2::Value::operator=(Local, &this->ThrowingValue);
          else
            Scaleform::GFx::AS2::Environment::AddLocal(this, CatchName, &this->ThrowingValue);
        }
        else
        {
          v24 = &this->ThrowingValue;
        }
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v36 = v28->RefCount;
        if ( (v36 & 0x3FFFFFF) != 0 )
        {
          v28->RefCount = v36 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
        }
        if ( v26 )
        {
          v37 = v26->RefCount;
          if ( (v37 & 0x3FFFFFF) != 0 )
          {
            v26->RefCount = v37 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
          }
        }
      }
      Scaleform::GFx::AS2::Value::DropRefs(v24);
      this->ThrowingValue.T.Type = 10;
      *((_BYTE *)this + 382) &= ~1u;
      v38 = execType;
      v8 = pactBuf;
      Scaleform::GFx::AS2::ActionBuffer::Execute(
        pactBuf,
        this,
        v54 + *(unsigned __int16 *)(pTryBlock + 1),
        *(unsigned __int16 *)(pTryBlock + 3),
        retval,
        pwithStack,
        execType);
      nextPc = *(unsigned __int16 *)(pTryBlock + 5)
             + v54
             + *(unsigned __int16 *)(pTryBlock + 3)
             + *(unsigned __int16 *)(pTryBlock + 1);
      v11 = 1;
      if ( (*pTryBlock & 4) == 0 )
      {
        v42 = this->LocalFrames.Data.Size;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames,
          &this->LocalFrames,
          (unsigned int)v20);
        if ( (unsigned int)v20 > v42 )
        {
          v43 = &this->LocalFrames.Data.Data[v42];
          for ( j = (unsigned int)v20 - v42; j; --j )
          {
            v50 = v43;
            if ( v43 )
              v43->pObject = 0i64;
            ++v43;
          }
        }
        LODWORD(v16) = v54;
LABEL_58:
        v38 = execType;
        v8 = pactBuf;
        goto LABEL_59;
      }
      v.T.Type = 0;
      if ( (*pTryBlock & 1) != 0 && (*pTryBlock & 4) != 0 )
        v39 = *((unsigned __int8 *)pTryBlock + 7);
      else
        v39 = 0xFFFFFFFFi64;
      v40 = this->LocalRegister.Data.Size;
      if ( (unsigned int)v39 < v40 )
      {
        v41 = &this->LocalRegister.Data.Data[v40 - (unsigned int)v39 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          this,
          "Invalid local register %d, stack only has %d entries",
          v39,
          (unsigned int)v40);
        v41 = this->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::operator=(v41, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      LODWORD(v16) = v54;
LABEL_59:
      if ( (*pTryBlock & 2) != 0 )
      {
        v45 = v16 + *(unsigned __int16 *)(pTryBlock + 3) + *(unsigned __int16 *)(pTryBlock + 1);
        *((_BYTE *)this + 382) |= 1u;
        Scaleform::GFx::AS2::ActionBuffer::Execute(
          v8,
          this,
          v45,
          *(unsigned __int16 *)(pTryBlock + 5),
          retval,
          pwithStack,
          v38);
        *((_BYTE *)this + 382) &= ~1u;
      }
      --v12;
      v7 = plocalTryBlockCount;
    }
    while ( v12 > 0 );
    p_ThrowingValue = &this->ThrowingValue;
    if ( !v11 )
      return v8->pBufferData.pObject->BufferLen;
  }
}

// File Line: 5436
// RVA: 0x6F1CA0
__int64 __fastcall Scaleform::GFx::AS2::Environment::GetMember(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ObjectInterface *pthisObj,
        Scaleform::GFx::ASString *memberName,
        Scaleform::GFx::AS2::Value *pdestVal)
{
  unsigned __int8 v8; // bl
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  int v12; // edx
  char v13; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  unsigned int v17; // eax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v22; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+10h] [rbp-29h] BYREF
  __int64 v25[3]; // [rsp+28h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // [rsp+40h] [rbp+7h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // [rsp+48h] [rbp+Fh]
  char v28; // [rsp+50h] [rbp+17h]
  Scaleform::GFx::AS2::Environment *v29; // [rsp+58h] [rbp+1Fh]
  int v30; // [rsp+60h] [rbp+27h]
  int v31; // [rsp+64h] [rbp+2Bh]
  Scaleform::GFx::AS2::Value *v32; // [rsp+A8h] [rbp+6Fh]

  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))pthisObj->vfptr->GetMember)(
         pthisObj,
         this);
  if ( v8 && pdestVal->T.Type == 9 )
  {
    Scaleform::GFx::AS2::Value::GetPropertyValue(pdestVal, this, pthisObj, pdestVal);
  }
  else if ( pdestVal->T.Type == 12 )
  {
    Scaleform::GFx::AS2::Value::ToResolveHandler(pdestVal, &result);
    if ( result.Function )
    {
      p_Stack = &this->Stack;
      if ( ++this->Stack.pCurrent >= this->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
      pCurrent = p_Stack->pCurrent;
      v32 = pCurrent;
      if ( pCurrent )
      {
        pCurrent->T.Type = 5;
        pNode = memberName->pNode;
        pCurrent->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)memberName->pNode;
        ++pNode->RefCount;
      }
      Scaleform::GFx::AS2::Value::DropRefs(pdestVal);
      pdestVal->T.Type = 0;
      v12 = this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32;
      v25[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
      v25[1] = (__int64)pdestVal;
      v25[2] = (__int64)pthisObj;
      v28 = 0;
      v26 = 0i64;
      v27 = 0i64;
      v29 = this;
      v30 = 1;
      v31 = v12;
      ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64 *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))result.Function->vfptr[3].Finalize_GC)(
        result.Function,
        v25,
        result.pLocalFrame,
        0i64);
      v25[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
      v13 = v28;
      if ( (v28 & 2) == 0 )
      {
        v14 = v26;
        if ( v26 )
        {
          RefCount = v26->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v26->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
            v13 = v28;
          }
        }
      }
      v26 = 0i64;
      if ( (v13 & 1) == 0 )
      {
        v16 = v27;
        if ( v27 )
        {
          v17 = v27->RefCount;
          if ( (v17 & 0x3FFFFFF) != 0 )
          {
            v27->RefCount = v17 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          }
        }
      }
      v27 = 0i64;
      v25[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      --p_Stack->pCurrent;
      if ( this->Stack.pCurrent < this->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&this->Stack);
      v8 = 1;
    }
    else
    {
      v8 = 0;
    }
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      Function = result.Function;
      if ( result.Function )
      {
        v20 = result.Function->RefCount;
        if ( (v20 & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v22 = result.pLocalFrame->RefCount;
        if ( (v22 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v22 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  return v8;
}

// File Line: 5470
// RVA: 0x71C4A0
void __fastcall Scaleform::GFx::AS2::Environment::SetTarget(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  *((_BYTE *)this + 382) &= ~2u;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(ptarget);
}

// File Line: 5476
// RVA: 0x714BF0
void __fastcall Scaleform::GFx::AS2::Environment::SetInvalidTarget(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  *((_BYTE *)this + 382) |= 2u;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(ptarget);
}

// File Line: 5491
// RVA: 0x7025D0
void Scaleform::GFx::AS2::Environment::LogScriptError(Scaleform::GFx::AS2::Environment *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::ActionLogger *pASLogger; // rbx
  Scaleform::Log *pLog; // rcx
  unsigned __int64 v5; // rax
  __int64 v6; // rax
  int v7; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v10; // [rsp+50h] [rbp-B0h]
  char v11[256]; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::MsgFormat v12; // [rsp+160h] [rbp+60h] BYREF
  va_list va; // [rsp+5A0h] [rbp+4A0h] BYREF

  va_start(va, pfmt);
  v10 = -2i64;
  pASLogger = this->pASLogger;
  if ( pASLogger )
  {
    pLog = pASLogger->pLog;
    if ( pLog )
    {
      if ( pASLogger->UseSuffix )
      {
        v5 = -1i64;
        do
          ++v5;
        while ( pfmt[v5] );
        if ( pfmt[v5 - 1] == 10 )
          --v5;
        r.Type = tDataPtr;
        r.SinkData.pStr = (Scaleform::String *)v11;
        r.SinkData.DataPtr.Size = 256i64;
        v.pStr = pfmt;
        v.Size = v5;
        Scaleform::MsgFormat::MsgFormat(&v12, &r);
        Scaleform::MsgFormat::Parse(&v12, "{0} : {1}\n");
        Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v12, &v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v12, &pASLogger->LogSuffix);
        Scaleform::MsgFormat::FinishFormatD(&v12);
        Scaleform::MsgFormat::~MsgFormat(&v12);
        v7 = 212992;
        ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *))pASLogger->pLog->vfptr[1].__vecDelDtor)(
          pASLogger->pLog,
          &v7,
          v11,
          (__int64 *)va);
      }
      else
      {
        v7 = 212992;
        ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
          pLog,
          &v7,
          pfmt,
          (__int64 *)va);
      }
    }
  }
  else if ( ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Target->vfptr[76].__vecDelDtor)(this->Target) )
  {
    v6 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Target->vfptr[76].__vecDelDtor)(this->Target);
    v7 = 212992;
    (*(void (__fastcall **)(__int64, int *, const char *, __int64 *))(*(_QWORD *)v6 + 8i64))(
      v6,
      &v7,
      pfmt,
      (__int64 *)va);
  }
}

// File Line: 5501
// RVA: 0x702A30
void Scaleform::GFx::AS2::Environment::LogScriptWarning(Scaleform::GFx::AS2::Environment *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::ActionLogger *pASLogger; // rbx
  Scaleform::Log *pLog; // rcx
  unsigned __int64 v5; // rax
  __int64 v6; // rax
  int v7; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v10; // [rsp+50h] [rbp-B0h]
  char v11[256]; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::MsgFormat v12; // [rsp+160h] [rbp+60h] BYREF
  va_list va; // [rsp+5A0h] [rbp+4A0h] BYREF

  va_start(va, pfmt);
  v10 = -2i64;
  pASLogger = this->pASLogger;
  if ( pASLogger )
  {
    pLog = pASLogger->pLog;
    if ( pLog )
    {
      if ( pASLogger->UseSuffix )
      {
        v5 = -1i64;
        do
          ++v5;
        while ( pfmt[v5] );
        if ( pfmt[v5 - 1] == 10 )
          --v5;
        r.Type = tDataPtr;
        r.SinkData.pStr = (Scaleform::String *)v11;
        r.SinkData.DataPtr.Size = 256i64;
        v.pStr = pfmt;
        v.Size = v5;
        Scaleform::MsgFormat::MsgFormat(&v12, &r);
        Scaleform::MsgFormat::Parse(&v12, "{0} : {1}\n");
        Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v12, &v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v12, &pASLogger->LogSuffix);
        Scaleform::MsgFormat::FinishFormatD(&v12);
        Scaleform::MsgFormat::~MsgFormat(&v12);
        v7 = 147456;
        ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *))pASLogger->pLog->vfptr[1].__vecDelDtor)(
          pASLogger->pLog,
          &v7,
          v11,
          (__int64 *)va);
      }
      else
      {
        v7 = 147456;
        ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
          pLog,
          &v7,
          pfmt,
          (__int64 *)va);
      }
    }
  }
  else if ( ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Target->vfptr[76].__vecDelDtor)(this->Target) )
  {
    v6 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Target->vfptr[76].__vecDelDtor)(this->Target);
    v7 = 147456;
    (*(void (__fastcall **)(__int64, int *, const char *, __int64 *))(*(_QWORD *)v6 + 8i64))(
      v6,
      &v7,
      pfmt,
      (__int64 *)va);
  }
}

// File Line: 5531
// RVA: 0x7010B0
_BOOL8 __fastcall Scaleform::GFx::AS2::Environment::IsVerboseActionErrors(Scaleform::GFx::AS2::Environment *this)
{
  return (this->Target->pASRoot->pMovieImpl->Flags & 0x40) == 0;
}

// File Line: 5559
// RVA: 0x6EA100
bool __fastcall Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::GFx::ASString *VarName; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rax
  const char *pData; // rsi
  unsigned int ExcludeFlags; // r9d
  Scaleform::GFx::InteractiveObject **ppNewTarget; // r8
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStack; // rdx
  Scaleform::GFx::AS2::Value *pResult; // rcx
  bool Variable; // di
  Scaleform::GFx::AS2::Value *pOwner; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+48h] [rbp-40h] BYREF

  VarName = params->VarName;
  pNode = params->VarName->pNode;
  if ( (pNode->HashFlags & 0x2000000) != 0 )
    return Scaleform::GFx::AS2::Environment::GetVariableRaw(this, params);
  if ( (pNode->HashFlags & 0x4000000) == 0 )
  {
    pData = pNode->pData;
    if ( !strchr(pNode->pData, 58) && !strchr(pData, 47) && !strchr(pData, 46) )
    {
      VarName->pNode->HashFlags |= 0x6000000u;
      return Scaleform::GFx::AS2::Environment::GetVariableRaw(this, params);
    }
    VarName->pNode->HashFlags |= 0x4000000u;
  }
  v.T.Type = 0;
  ExcludeFlags = params->ExcludeFlags;
  ppNewTarget = params->ppNewTarget;
  pWithStack = params->pWithStack;
  pResult = params->pResult;
  paramsa.VarName = params->VarName;
  paramsa.pResult = pResult;
  paramsa.pWithStack = pWithStack;
  paramsa.ppNewTarget = ppNewTarget;
  paramsa.pOwner = &v;
  paramsa.ExcludeFlags = ExcludeFlags;
  Variable = Scaleform::GFx::AS2::Environment::FindVariable(this, &paramsa, 0, 0i64);
  if ( !v.T.Type || v.T.Type == 10 )
  {
    if ( (params->ExcludeFlags & 4) == 0 )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        this,
        " GetVariable failed: cant resolve the path \"%s\"",
        params->VarName->pNode->pData);
    Variable = 0;
  }
  else
  {
    pOwner = params->pOwner;
    if ( pOwner )
      Scaleform::GFx::AS2::Value::operator=(pOwner, &v);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return Variable;
}

// File Line: 5596
// RVA: 0x6F73A0
bool __fastcall Scaleform::GFx::AS2::Environment::GetVariable(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  bool result; // al
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::ObjectInterface *v9; // r8
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::InteractiveObject *v11; // rcx
  char *v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::AS2::Value *p_params; // rcx
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::DisplayObject *v16; // rax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v18; // rcx
  __int64 v19; // rax
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::ASStringNode *v21; // rax
  int v22; // edx
  char v23; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Value *v28; // rcx
  char v29; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // rcx
  int v31; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS2::Value v34; // [rsp+28h] [rbp-71h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+48h] [rbp-51h] BYREF
  __int64 v36[3]; // [rsp+78h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v37; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v38; // [rsp+98h] [rbp-1h]
  char v39; // [rsp+A0h] [rbp+7h]
  Scaleform::GFx::AS2::Environment *v40; // [rsp+A8h] [rbp+Fh]
  int v41; // [rsp+B0h] [rbp+17h]
  int v42; // [rsp+B4h] [rbp+1Bh]
  __int64 v43; // [rsp+B8h] [rbp+1Fh]
  Scaleform::GFx::ASStringNode **vars0; // [rsp+F0h] [rbp+57h]
  Scaleform::GFx::AS2::Value *retaddr; // [rsp+F8h] [rbp+5Fh]
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStacka; // [rsp+100h] [rbp+67h]
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStackb; // [rsp+100h] [rbp+67h]
  bool v48; // [rsp+118h] [rbp+7Fh]

  v43 = -2i64;
  params.VarName = varname;
  params.pResult = presult;
  params.pWithStack = pwithStack;
  params.ppNewTarget = (Scaleform::GFx::InteractiveObject **)varname;
  params.pOwner = presult;
  params.ExcludeFlags = (unsigned int)pwithStack;
  result = Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, &params);
  v48 = result;
  if ( !result || presult->T.Type != 9 )
  {
    if ( presult->T.Type != 12 )
      return result;
    LOBYTE(params.VarName) = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(
           this,
           (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20],
           (Scaleform::GFx::AS2::Value *)&params,
           pwithStacka,
           0i64,
           0i64,
           0) )
    {
      v15 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&params, this);
      if ( v15 )
      {
        pwithStackb = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)&v15->Scaleform::GFx::AS2::ObjectInterface;
        if ( v15 != (Scaleform::GFx::AS2::Object *)-32i64 )
          goto LABEL_33;
      }
      if ( LOBYTE(params.VarName) != 7 )
        goto LABEL_32;
      if ( !params.pResult )
        goto LABEL_32;
      v16 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
              (Scaleform::GFx::CharacterHandle *)params.pResult,
              this->Target->pASRoot->pMovieImpl);
      if ( !v16 )
        goto LABEL_32;
      Target = 0i64;
      if ( SLOBYTE(v16->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
        Target = (Scaleform::GFx::InteractiveObject *)v16;
    }
    else
    {
      Target = this->Target;
    }
    if ( Target )
    {
      v18 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
      v19 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v18 + 8i64))(v18);
      if ( v19 )
      {
        pwithStackb = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)(v19 + 8);
LABEL_33:
        Scaleform::GFx::AS2::Value::ToResolveHandler(presult, (Scaleform::GFx::AS2::FunctionRef *)&v34);
        if ( ++this->Stack.pCurrent >= this->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
        pCurrent = this->Stack.pCurrent;
        if ( pCurrent )
        {
          pCurrent->T.Type = 5;
          v21 = *vars0;
          pCurrent->V.pStringNode = *vars0;
          ++v21->RefCount;
        }
        Scaleform::GFx::AS2::Value::DropRefs(retaddr);
        retaddr->T.Type = 0;
        v22 = this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32;
        v36[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
        v36[1] = (__int64)retaddr;
        v36[2] = (__int64)pwithStackb;
        v39 = 0;
        v37 = 0i64;
        v38 = 0i64;
        v40 = this;
        v41 = 1;
        v42 = v22;
        (*(void (__fastcall **)(_QWORD, __int64 *, Scaleform::GFx::ASStringNode *, _QWORD))(**(_QWORD **)&v34.T.Type
                                                                                          + 80i64))(
          *(_QWORD *)&v34.T.Type,
          v36,
          v34.V.pStringNode,
          0i64);
        v36[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
        v23 = v39;
        if ( (v39 & 2) == 0 )
        {
          v24 = v37;
          if ( v37 )
          {
            RefCount = v37->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v37->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
              v23 = v39;
            }
          }
        }
        v37 = 0i64;
        if ( (v23 & 1) == 0 )
        {
          v26 = v38;
          if ( v38 )
          {
            v27 = v38->RefCount;
            if ( (v27 & 0x3FFFFFF) != 0 )
            {
              v38->RefCount = v27 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
            }
          }
        }
        v38 = 0i64;
        v36[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
        v28 = this->Stack.pCurrent;
        if ( v28->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v28);
        if ( --this->Stack.pCurrent < this->Stack.pPageStart )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&this->Stack);
        v29 = *((_BYTE *)&v34.NV + 16);
        if ( (*(_BYTE *)(&v34.NV + 1) & 2) == 0 )
        {
          v30 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v34.T.Type;
          if ( *(_QWORD *)&v34.T.Type )
          {
            v31 = *(_DWORD *)(*(_QWORD *)&v34.T.Type + 24i64);
            if ( (v31 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(*(_QWORD *)&v34.T.Type + 24i64) = v31 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
              v29 = *((_BYTE *)&v34.NV + 16);
            }
          }
        }
        *(_QWORD *)&v34.T.Type = 0i64;
        if ( (v29 & 1) == 0 )
        {
          pStringNode = v34.V.pStringNode;
          if ( v34.V.pStringNode )
          {
            v33 = v34.V.pStringNode->RefCount;
            if ( (v33 & 0x3FFFFFF) != 0 )
            {
              v34.V.pStringNode->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        v34.V.pStringNode = 0i64;
        if ( LOBYTE(params.VarName) < 5u )
          return v48;
        p_params = (Scaleform::GFx::AS2::Value *)&params;
        goto LABEL_59;
      }
    }
LABEL_32:
    pwithStackb = 0i64;
    goto LABEL_33;
  }
  v34.T.Type = 0;
  params.VarName = (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
  params.pResult = &v34;
  params.pWithStack = pwithStack;
  memset(&params.ppNewTarget, 0, 20);
  if ( Scaleform::GFx::AS2::Environment::GetVariableRaw(this, &params) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v34, this);
    if ( v8 )
    {
      v9 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      if ( v8 != (Scaleform::GFx::AS2::Object *)-32i64 )
        goto LABEL_16;
    }
    if ( v34.T.Type != 7 )
      goto LABEL_15;
    if ( !v34.V.pStringNode )
      goto LABEL_15;
    v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v34.V.pCharHandle, this->Target->pASRoot->pMovieImpl);
    if ( !v10 )
      goto LABEL_15;
    v11 = 0i64;
    if ( SLOBYTE(v10->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      v11 = (Scaleform::GFx::InteractiveObject *)v10;
  }
  else
  {
    v11 = this->Target;
  }
  if ( !v11
    || (v12 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset,
        v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12),
        v9 = (Scaleform::GFx::AS2::ObjectInterface *)(v13 + 8),
        !v13) )
  {
LABEL_15:
    v9 = 0i64;
  }
LABEL_16:
  Scaleform::GFx::AS2::Value::GetPropertyValue(presult, this, v9, presult);
  if ( v34.T.Type >= 5u )
  {
    p_params = &v34;
LABEL_59:
    Scaleform::GFx::AS2::Value::DropRefs(p_params);
  }
  return v48;
}

// File Line: 5649
// RVA: 0x6FFF60
char __fastcall Scaleform::GFx::AS2::Environment::IsAvailable(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  Scaleform::GFx::InteractiveObject *Target; // rax
  char v9; // bl
  char *v10; // rcx
  __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // rbx
  __int64 v14; // rdi
  Scaleform::GFx::AS2::WithStackEntry *Data; // rcx
  Scaleform::GFx::AS2::Object *v16; // rcx
  __int64 v17; // rcx
  Scaleform::GFx::AS2::Object *pObject; // rdx
  char *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::InteractiveObject *v21; // rcx
  char *v22; // rcx
  __int64 v23; // rax
  Scaleform::GFx::ASStringNode **v24; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::AS2::GlobalContext *pContext; // r9
  Scaleform::GFx::ASStringNode *pLower; // r8
  const char *pData; // rcx
  int v29; // eax
  Scaleform::GFx::AS2::Object *v30; // rcx
  Scaleform::GFx::ASStringNode *v31; // rcx
  bool v32; // zf
  Scaleform::GFx::ASStringNode *v33; // rcx
  char *ptail[2]; // [rsp+20h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v35; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::ASString pvar; // [rsp+B8h] [rbp+38h] BYREF
  Scaleform::GFx::ASString ppath; // [rsp+C8h] [rbp+48h] BYREF

  ptail[1] = (char *)-2i64;
  if ( !varname->pNode->Size )
    return 0;
  p_StringContext = &this->StringContext;
  ppath.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++ppath.pNode->RefCount;
  pvar.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++pvar.pNode->RefCount;
  v35.T.Type = 0;
  params.VarName = varname;
  params.pResult = &v35;
  params.pWithStack = pwithStack;
  params.ppNewTarget = 0i64;
  params.pOwner = 0i64;
  params.ExcludeFlags = 4;
  if ( Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, &params) )
    goto LABEL_40;
  if ( Scaleform::GFx::AS2::Environment::ParsePath(p_StringContext, varname, &ppath, &pvar) )
  {
    Target = Scaleform::GFx::AS2::Environment::FindTarget(this, &ppath, 4);
    if ( Target )
    {
      v10 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
      v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 8i64))(v10);
      v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v11 + 8) + 88i64))(
             v11 + 8,
             p_StringContext,
             &pvar,
             &v35);
    }
    else
    {
      v9 = 0;
    }
    goto LABEL_41;
  }
  if ( pwithStack )
  {
    v12 = pwithStack->Data.Size - 1;
    v13 = v12;
    if ( v12 >= 0 )
    {
      v14 = v12;
      do
      {
        Data = pwithStack->Data.Data;
        if ( (pwithStack->Data.Data[v14].BlockEndPc & 0x80000000) == 0 )
        {
          pObject = Data[v14].pObject;
          if ( !pObject )
            goto LABEL_19;
          v19 = (char *)pObject + 4 * BYTE5(pObject[1].pNext);
          v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v19 + 8i64))(v19);
          if ( !v20 )
            goto LABEL_19;
          v17 = v20 + 8;
        }
        else
        {
          v16 = Data[v14].pObject;
          if ( !v16 )
            goto LABEL_19;
          v17 = (__int64)&v16->Scaleform::GFx::AS2::ObjectInterface;
        }
        if ( v17
          && (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v17 + 88i64))(
               v17,
               p_StringContext,
               varname,
               &v35) )
        {
          goto LABEL_40;
        }
LABEL_19:
        --v14;
      }
      while ( --v13 >= 0 );
    }
  }
  if ( Scaleform::GFx::AS2::Environment::FindLocal(this, varname) )
    goto LABEL_40;
  v21 = this->Target;
  if ( v21 )
  {
    v22 = (char *)v21 + 4 * (unsigned __int8)v21->AvmObjOffset;
    v23 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v22 + 8i64))(v22);
    if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v23 + 8) + 88i64))(
           v23 + 8,
           p_StringContext,
           varname,
           &v35) )
    {
      goto LABEL_40;
    }
  }
  if ( this->StringContext.SWFVersion <= 6u )
  {
    if ( !varname->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(varname->pNode);
    pContext = p_StringContext->pContext;
    pNode = varname->pNode;
    pLower = varname->pNode->pLower;
    if ( (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[20].vfptr[2].__vecDelDtor == pLower
      || *(Scaleform::GFx::ASStringNode **)&pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport.pObject->SType == pLower
      || (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl->vfptr == pLower )
    {
      goto LABEL_40;
    }
  }
  else
  {
    v24 = (Scaleform::GFx::ASStringNode **)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject;
    pNode = varname->pNode;
    if ( v24[100] == varname->pNode || v24[103] == pNode || v24[102] == pNode )
    {
LABEL_40:
      v9 = 1;
      goto LABEL_41;
    }
  }
  pData = pNode->pData;
  if ( *pNode->pData == 95 )
  {
    ptail[0] = 0i64;
    v29 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
            pData,
            (const char **)ptail,
            this->StringContext.SWFVersion > 6u);
    if ( v29 != -1
      && !*ptail[0]
      && Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
           (Scaleform::GFx::AS2::MovieRoot *)this->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
           v29) )
    {
      goto LABEL_40;
    }
  }
  v30 = p_StringContext->pContext->pGlobal.pObject;
  if ( v30 )
  {
    if ( v30->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
           &v30->Scaleform::GFx::AS2::ObjectInterface,
           p_StringContext,
           varname,
           &v35) )
    {
      goto LABEL_40;
    }
  }
  v9 = 0;
LABEL_41:
  if ( v35.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v35);
  v31 = pvar.pNode;
  v32 = pvar.pNode->RefCount-- == 1;
  if ( v32 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  v33 = ppath.pNode;
  v32 = ppath.pNode->RefCount-- == 1;
  if ( v32 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  return v9;
}

// File Line: 5731
// RVA: 0x6F8070
bool __fastcall Scaleform::GFx::AS2::Environment::GetVariableRaw(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStack; // rax
  int v5; // ecx
  __int64 v6; // r14
  __int64 v7; // r15
  Scaleform::GFx::AS2::WithStackEntry *Data; // rcx
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rdx
  char *v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::InteractiveObject *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Value *pResult; // rbx
  Scaleform::GFx::AS2::Value *Local; // rax
  char SWFVersion; // al
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r13
  __int64 v21; // rcx
  unsigned __int64 Size; // r14
  Scaleform::GFx::AS2::LocalFrame *v23; // r14
  Scaleform::GFx::AS2::ArrayObject *v24; // rax
  Scaleform::GFx::AS2::ArrayObject *v25; // rax
  Scaleform::GFx::AS2::ArrayObject *v26; // r15
  int i; // ebx
  unsigned int v28; // edx
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::AS2::Value *v30; // r8
  Scaleform::GFx::AS2::Value *v31; // rax
  unsigned int RefCount; // eax
  char v33; // al
  unsigned __int64 v34; // rcx
  Scaleform::GFx::AS2::LocalFrame *v35; // r14
  Scaleform::GFx::AS2::ObjectInterface *SuperThis; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v37; // r14
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v38; // rcx
  Scaleform::MemoryHeap *v39; // rcx
  Scaleform::GFx::AS2::SuperObject *v40; // r15
  Scaleform::GFx::AS2::Object *pRCC; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v42; // rax
  Scaleform::GFx::AS2::Object *v43; // rax
  Scaleform::GFx::AS2::Object *v44; // rbx
  char v45; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // rcx
  int v47; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int v49; // eax
  unsigned int v50; // eax
  unsigned int v51; // eax
  Scaleform::GFx::ASMovieRootBase *v52; // r14
  Scaleform::GFx::ASString *VarName; // rbx
  bool v54; // zf
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v56; // rcx
  __int64 v57; // rax
  Scaleform::GFx::InteractiveObject *v58; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rax
  Scaleform::GFx::AS2::Object *v60; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-59h] BYREF
  Scaleform::GFx::AS2::Value v62; // [rsp+50h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+70h] [rbp-19h] BYREF
  __int64 v64; // [rsp+A0h] [rbp+17h]
  Scaleform::GFx::AS2::SuperObject *v65; // [rsp+A8h] [rbp+1Fh]
  void *result; // [rsp+F8h] [rbp+6Fh] BYREF
  Scaleform::GFx::AS2::ArrayObject *v67; // [rsp+100h] [rbp+77h]
  Scaleform::MemoryHeap *pHeap; // [rsp+108h] [rbp+7Fh]

  v64 = -2i64;
  if ( !params->pResult )
    return 0;
  if ( params->pOwner )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(params->pOwner, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  pWithStack = params->pWithStack;
  if ( pWithStack )
  {
    v5 = pWithStack->Data.Size - 1;
    v6 = v5;
    if ( v5 >= 0 )
    {
      v7 = v5;
      while ( 1 )
      {
        Data = params->pWithStack->Data.Data;
        if ( (Data[v7].BlockEndPc & 0x80000000) == 0 )
        {
          pObject = Data[v7].pObject;
          if ( !pObject )
            return 0;
          v12 = (char *)pObject + 4 * BYTE5(pObject[1].pNext);
          v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
          if ( !v13 )
            return 0;
          v10 = (Scaleform::GFx::AS2::ObjectInterface *)(v13 + 8);
        }
        else
        {
          v9 = Data[v7].pObject;
          if ( !v9 )
            return 0;
          v10 = &v9->Scaleform::GFx::AS2::ObjectInterface;
        }
        if ( !v10 )
          return 0;
        if ( v10->vfptr->GetMember(v10, this, params->VarName, params->pResult) )
          break;
        --v7;
        if ( --v6 < 0 )
          goto LABEL_23;
      }
      if ( params->pOwner )
      {
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->vfptr->gap8[8])(v10) - 2 > 3 )
        {
          v15 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(v10);
          Scaleform::GFx::AS2::Value::SetAsObject(params->pOwner, v15);
        }
        else
        {
          v14 = Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v10);
          Scaleform::GFx::AS2::Value::SetAsCharacter(params->pOwner, v14);
        }
      }
      return 1;
    }
  }
LABEL_23:
  if ( (params->ExcludeFlags & 1) == 0 )
  {
    pResult = params->pResult;
    Local = Scaleform::GFx::AS2::Environment::FindLocal(this, params->VarName);
    if ( Local )
    {
      if ( pResult )
        Scaleform::GFx::AS2::Value::operator=(pResult, Local);
      return 1;
    }
    SWFVersion = this->StringContext.SWFVersion;
    if ( (unsigned __int8)SWFVersion >= 5u )
    {
      p_StringContext = &this->StringContext;
      if ( Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
             (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl,
             params->VarName,
             (unsigned __int8)SWFVersion > 6u) )
      {
        Size = this->LocalFrames.Data.Size;
        if ( Size )
        {
          v23 = this->LocalFrames.Data.Data[Size - 1].pObject;
          if ( v23 )
          {
            result = p_StringContext->pContext->pHeap;
            v24 = (Scaleform::GFx::AS2::ArrayObject *)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)result + 80i64))(
                                                        v21,
                                                        144i64,
                                                        0i64);
            v67 = v24;
            if ( v24 )
            {
              Scaleform::GFx::AS2::ArrayObject::ArrayObject(v24, this);
              v26 = v25;
            }
            else
            {
              v26 = 0i64;
            }
            v67 = v26;
            Scaleform::GFx::AS2::ArrayObject::Resize(v26, v23->NArgs);
            for ( i = 0; i < v23->NArgs; ++i )
            {
              v28 = v23->FirstArgBottomIndex - i;
              Env = v23->Env;
              v30 = 0i64;
              if ( v28 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                        + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
                v30 = &Env->Stack.Pages.Data.Data[v28 >> 5]->Values[v28 & 0x1F];
              Scaleform::GFx::AS2::ArrayObject::SetElement(v26, i, v30);
            }
            Scaleform::GFx::AS2::Value::Value(&v62, (Scaleform::GFx::ASStringNode *)v26);
            Scaleform::GFx::AS2::Environment::AddLocal(
              this,
              (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl,
              v31);
            if ( v62.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v62);
            LOBYTE(result) = 7;
            v26->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
              &v26->Scaleform::GFx::AS2::ObjectInterface,
              &this->StringContext,
              (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[21].pASSupport,
              &v23->Callee,
              (Scaleform::GFx::AS2::PropFlags *)&result);
            LOBYTE(result) = 7;
            v26->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
              &v26->Scaleform::GFx::AS2::ObjectInterface,
              &this->StringContext,
              (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[21].AVMVersion,
              &v23->Caller,
              (Scaleform::GFx::AS2::PropFlags *)&result);
            Scaleform::GFx::AS2::Value::SetAsObject(params->pResult, v26);
            RefCount = v26->RefCount;
            if ( (RefCount & 0x3FFFFFF) == 0 )
              return 1;
            v26->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
            return 1;
          }
        }
      }
      else
      {
        v33 = this->StringContext.SWFVersion;
        if ( (unsigned __int8)v33 >= 6u
          && Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
               (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[20].RefCount,
               params->VarName,
               (unsigned __int8)v33 > 6u) )
        {
          v34 = this->LocalFrames.Data.Size;
          if ( v34 )
          {
            v35 = this->LocalFrames.Data.Data[v34 - 1].pObject;
            if ( v35 )
            {
              SuperThis = v35->SuperThis;
              if ( SuperThis )
              {
                result = 0i64;
                v37 = SuperThis->pProto.pObject;
                if ( v37 )
                  v37->RefCount = (v37->RefCount + 1) & 0x8FFFFFFF;
                v67 = (Scaleform::GFx::AS2::ArrayObject *)v37;
                if ( v37 )
                {
                  v62.T.Type = 0;
                  v38 = params->pWithStack;
                  paramsa.VarName = (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[20];
                  paramsa.pResult = &v62;
                  paramsa.pWithStack = v38;
                  memset(&paramsa.ppNewTarget, 0, 20);
                  Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, &paramsa);
                  ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ASStringContext *))v37[1].vfptr[4].~RefCountBaseGC<323>)(
                    &v37[1],
                    &v,
                    &this->StringContext);
                  pHeap = p_StringContext->pContext->pHeap;
                  v40 = (Scaleform::GFx::AS2::SuperObject *)pHeap->vfptr->Alloc(v39, 144ui64, 0i64);
                  v65 = v40;
                  if ( v40 )
                  {
                    pRCC = (Scaleform::GFx::AS2::Object *)v37[1].pRCC;
                    v42 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v62, this);
                    Scaleform::GFx::AS2::SuperObject::SuperObject(
                      v40,
                      pRCC,
                      v42,
                      (Scaleform::GFx::AS2::FunctionRef *)&v);
                    v44 = v43;
                  }
                  else
                  {
                    v44 = 0i64;
                  }
                  result = v44;
                  Scaleform::GFx::AS2::Value::SetAsObject(params->pResult, v44);
                  Scaleform::GFx::AS2::Environment::SetLocal(
                    this,
                    (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[20].RefCount,
                    params->pResult);
                  v45 = *((_BYTE *)&v.NV + 16);
                  if ( (*(_BYTE *)(&v.NV + 1) & 2) == 0 )
                  {
                    v46 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
                    if ( *(_QWORD *)&v.T.Type )
                    {
                      v47 = *(_DWORD *)(*(_QWORD *)&v.T.Type + 24i64);
                      if ( (v47 & 0x3FFFFFF) != 0 )
                      {
                        *(_DWORD *)(*(_QWORD *)&v.T.Type + 24i64) = v47 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
                        v45 = *((_BYTE *)&v.NV + 16);
                      }
                    }
                  }
                  *(_QWORD *)&v.T.Type = 0i64;
                  if ( (v45 & 1) == 0 )
                  {
                    pStringNode = v.V.pStringNode;
                    if ( v.V.pStringNode )
                    {
                      v49 = v.V.pStringNode->RefCount;
                      if ( (v49 & 0x3FFFFFF) != 0 )
                      {
                        v.V.pStringNode->RefCount = v49 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
                      }
                    }
                  }
                  v.V.pStringNode = 0i64;
                  if ( v62.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v62);
                  v50 = v37->RefCount;
                  if ( (v50 & 0x3FFFFFF) != 0 )
                  {
                    v37->RefCount = v50 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v37);
                  }
                  if ( !v44 )
                    return 1;
                  v51 = v44->RefCount;
                  if ( (v51 & 0x3FFFFFF) == 0 )
                    return 1;
                  v44->RefCount = v51 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v44);
                  return 1;
                }
              }
            }
          }
        }
      }
    }
    v52 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    VarName = params->VarName;
    if ( this->StringContext.SWFVersion <= 6u )
    {
      if ( !VarName->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(VarName->pNode);
      v54 = v52[20].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))VarName->pNode->pLower;
    }
    else
    {
      v54 = v52[20].vfptr == (Scaleform::RefCountImplCoreVtbl *)VarName->pNode;
    }
    if ( v54 )
    {
      Scaleform::GFx::AS2::Value::SetAsCharacter(params->pResult, this->Target);
      return 1;
    }
  }
  Target = this->Target;
  if ( !Target )
    return 0;
  v56 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
  v57 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v56 + 8i64))(v56);
  if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v57 + 8) + 88i64))(
         v57 + 8,
         &this->StringContext,
         params->VarName,
         params->pResult) )
  {
    if ( !params->pOwner )
      return 1;
    v58 = this->Target;
    v.T.Type = 7;
    if ( v58 )
    {
      CharacterHandle = (Scaleform::GFx::ASStringNode *)v58->pNameHandle.pObject;
      if ( !CharacterHandle )
        CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v58);
      v.V.pStringNode = CharacterHandle;
      if ( CharacterHandle )
        ++LODWORD(CharacterHandle->pData);
    }
    else
    {
      v.V.pStringNode = 0i64;
    }
    Scaleform::GFx::AS2::Value::operator=(params->pOwner, &v);
    if ( v.T.Type < 5u )
      return 1;
    Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 1;
  }
  v60 = this->StringContext.pContext->pGlobal.pObject;
  if ( (params->ExcludeFlags & 2) == 0 )
  {
    if ( Scaleform::GFx::ASConstString::GetLength(params->VarName) )
    {
      if ( *params->VarName->pNode->pData == 95 )
      {
        Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(this, (Scaleform::GFx::Bool3W *)&result, params);
        if ( (_BYTE)result )
          return (_BYTE)result == 1;
      }
    }
  }
  if ( !v60
    || !v60->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
          &v60->Scaleform::GFx::AS2::ObjectInterface,
          this,
          params->VarName,
          params->pResult) )
  {
    if ( (params->ExcludeFlags & 4) == 0 )
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
        this,
        "GetVariableRaw(\"%s\") failed, returning UNDEFINED.\n",
        params->VarName->pNode->pData);
    return 0;
  }
  if ( !params->pOwner )
    return 1;
  Scaleform::GFx::AS2::Value::Value(&v62, (Scaleform::GFx::ASStringNode *)v60);
  Scaleform::GFx::AS2::Value::operator=(params->pOwner, &v62);
  if ( v62.T.Type < 5u )
    return 1;
  Scaleform::GFx::AS2::Value::DropRefs(&v62);
  return 1;
}

// File Line: 5884
// RVA: 0x6DD030
Scaleform::GFx::Bool3W *__fastcall Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::Bool3W *result,
        Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // rdx
  Scaleform::GFx::ASMovieRootBase *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // r8
  Scaleform::GFx::Sprite *LevelMovie; // rax
  Scaleform::GFx::ASString *VarName; // r14
  Scaleform::GFx::ASMovieRootBase *pObject; // rbp
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v13; // r14
  Scaleform::GFx::ASMovieRootBase *v14; // rbp
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // r8
  int v18; // eax
  char *ptail; // [rsp+40h] [rbp+8h] BYREF

  if ( this->StringContext.SWFVersion <= 6u )
  {
    VarName = params->VarName;
    pObject = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    pNode = params->VarName->pNode;
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    if ( *(Scaleform::GFx::ASStringNode **)&pObject[20].pASSupport.pObject->SType == VarName->pNode->pLower )
      goto LABEL_3;
    v13 = params->VarName;
    v14 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v15 = params->VarName->pNode;
    if ( !v15->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15);
    if ( v14[20].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)v13->pNode->pLower )
    {
      pContext = this->StringContext.pContext;
      goto LABEL_6;
    }
LABEL_14:
    v16 = params->VarName->pNode;
    v17 = this->StringContext.SWFVersion > 6u;
    ptail = 0i64;
    v18 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v16->pData, (const char **)&ptail, v17);
    if ( v18 == -1 || *ptail )
    {
      result->Value = 0;
      return result;
    }
    LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
                   (Scaleform::GFx::AS2::MovieRoot *)this->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
                   v18);
    if ( !LevelMovie )
    {
      result->Value = 2;
      return result;
    }
    goto LABEL_4;
  }
  pContext = this->StringContext.pContext;
  v7 = pContext->pMovieRoot->pASMovieRoot.pObject;
  v8 = params->VarName->pNode;
  if ( (Scaleform::GFx::ASStringNode *)v7[20].pASSupport.pObject != v8 )
  {
    if ( (Scaleform::GFx::ASStringNode *)v7[20].pMovieImpl == v8 )
    {
LABEL_6:
      Scaleform::GFx::AS2::Value::SetAsObject(params->pResult, pContext->pGlobal.pObject);
      result->Value = 1;
      return result;
    }
    goto LABEL_14;
  }
LABEL_3:
  LevelMovie = (Scaleform::GFx::Sprite *)this->Target->vfptr[68].__vecDelDtor(this->Target, 0i64);
LABEL_4:
  Scaleform::GFx::AS2::Value::SetAsCharacter(params->pResult, LevelMovie);
  result->Value = 1;
  return result;
}

// File Line: 5936
// RVA: 0x6EB1C0
char __fastcall Scaleform::GFx::AS2::Environment::FindOwnerOfMember(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  int v9; // eax
  __int64 v10; // rdi
  __int64 v11; // rsi
  Scaleform::GFx::AS2::WithStackEntry *Data; // rcx
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::InteractiveObject **v14; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rdx
  char *v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::InteractiveObject *v21; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rbx
  Scaleform::GFx::AS2::Object *v23; // rbx

  if ( !presult )
    return 0;
  if ( pwithStack )
  {
    v9 = LODWORD(pwithStack->Data.Size) - 1;
    v10 = v9;
    if ( v9 >= 0 )
    {
      v11 = v9;
      do
      {
        Data = pwithStack->Data.Data;
        if ( (pwithStack->Data.Data[v11].BlockEndPc & 0x80000000) == 0 )
        {
          pObject = Data[v11].pObject;
          if ( !pObject )
            goto LABEL_14;
          v16 = (char *)pObject + 4 * BYTE5(pObject[1].pNext);
          v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 8i64))(v16);
          if ( !v17 )
            goto LABEL_14;
          v14 = (Scaleform::GFx::InteractiveObject **)(v17 + 8);
        }
        else
        {
          v13 = Data[v11].pObject;
          if ( !v13 )
            goto LABEL_14;
          v14 = (Scaleform::GFx::InteractiveObject **)&v13->Scaleform::GFx::AS2::ObjectInterface;
        }
        if ( v14
          && ((unsigned __int64 (__fastcall *)(Scaleform::GFx::InteractiveObject **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*v14)->pRenNode.pObject)(
               v14,
               &this->StringContext,
               varname,
               0i64) )
        {
          if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject **))(*v14)->pWeakProxy)(v14) - 2 > 3 )
          {
            Scaleform::GFx::AS2::Value::SetAsObject(presult, (Scaleform::GFx::AS2::Object *)(v14 - 4));
            return 1;
          }
          else
          {
            if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject **))(*v14)->pWeakProxy)(v14) - 2 > 3 )
              Scaleform::GFx::AS2::Value::SetAsCharacter(presult, 0i64);
            else
              Scaleform::GFx::AS2::Value::SetAsCharacter(presult, v14[2]);
            return 1;
          }
        }
LABEL_14:
        --v11;
        --v10;
      }
      while ( v10 >= 0 );
    }
  }
  Target = this->Target;
  if ( !Target )
    return 0;
  v19 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
  v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v19 + 8i64))(v19);
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)(v20 + 8) + 72i64))(
          v20 + 8,
          &this->StringContext,
          varname,
          0i64) )
  {
    v23 = this->StringContext.pContext->pGlobal.pObject;
    if ( v23
      && v23->Scaleform::GFx::AS2::ObjectInterface::vfptr->HasMember(
           &v23->Scaleform::GFx::AS2::ObjectInterface,
           &this->StringContext,
           varname,
           0) )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(presult, v23);
      return 1;
    }
    return 0;
  }
  v21 = this->Target;
  if ( v21 )
  {
    CharacterHandle = (Scaleform::GFx::ASStringNode *)v21->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v21);
  }
  else
  {
    CharacterHandle = 0i64;
  }
  if ( presult->T.Type != 7 || presult->V.pStringNode != CharacterHandle )
  {
    Scaleform::GFx::AS2::Value::DropRefs(presult);
    presult->T.Type = 7;
    presult->V.pStringNode = CharacterHandle;
    if ( CharacterHandle )
      ++LODWORD(CharacterHandle->pData);
  }
  return 1;
}

// File Line: 5986
// RVA: 0x71D1F0
char __fastcall Scaleform::GFx::AS2::Environment::SetVariable(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        bool doDisplayErrors)
{
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  const char *pData; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS2::Value v17; // [rsp+38h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+58h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+78h] [rbp-9h] BYREF
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+5Fh] BYREF
  Scaleform::GFx::ASString varName; // [rsp+E8h] [rbp+67h] BYREF

  if ( (this->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v18, val);
    Scaleform::GFx::AS2::Value::ToDebugString(v9, &result, this);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
      this,
      "-------------- %s = %s\n",
      varname->pNode->pData,
      result.pNode->pData);
    pNode = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( (varname->pNode->HashFlags & 0x2000000) != 0 )
    goto LABEL_32;
  if ( (varname->pNode->HashFlags & 0x4000000) == 0 )
  {
    pData = varname->pNode->pData;
    if ( !strchr(pData, 58) && !strchr(pData, 47) && !strchr(pData, 46) )
    {
      varname->pNode->HashFlags |= 0x6000000u;
LABEL_32:
      Scaleform::GFx::AS2::Environment::SetVariableRaw(this, varname, val, pwithStack);
      return 1;
    }
    varname->pNode->HashFlags |= 0x4000000u;
  }
  v17.T.Type = 0;
  varName.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++varName.pNode->RefCount;
  v18.T.Type = 0;
  params.VarName = varname;
  params.pResult = &v18;
  params.pWithStack = pwithStack;
  params.ppNewTarget = 0i64;
  params.pOwner = &v17;
  params.ExcludeFlags = 0;
  Scaleform::GFx::AS2::Environment::FindVariable(this, &params, 0, &varName);
  if ( !v17.T.Type || v17.T.Type == 10 )
  {
    if ( doDisplayErrors && this->vfptr->IsVerboseActionErrors(this) )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        this,
        "SetVariable failed: cant resolve the path \"%s\"",
        varname->pNode->pData);
  }
  else
  {
    v13 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v17, this);
    if ( v13 )
    {
      LOBYTE(result.pNode) = 0;
      v13->vfptr->SetMember(v13, this, &varName, val, (Scaleform::GFx::AS2::PropFlags *)&result);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
      v14 = varName.pNode;
      v11 = varName.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
      return 1;
    }
  }
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  v15 = varName.pNode;
  v11 = varName.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  return 0;
}

// File Line: 6030
// RVA: 0x71DEE0
void __fastcall Scaleform::GFx::AS2::Environment::SetVariableRaw(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  __int64 v8; // rbp
  int v9; // r10d
  __int64 v10; // rdi
  __int64 v11; // rsi
  Scaleform::GFx::AS2::WithStackEntry *Data; // rcx
  Scaleform::GFx::AS2::Object *v13; // rbx
  __int64 v14; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rdx
  char *v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::AS2::Value *Local; // rax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v20; // rcx
  Scaleform::GFx::AS2::Value v21; // [rsp+38h] [rbp-50h] BYREF
  char v22; // [rsp+A8h] [rbp+20h] BYREF

  v8 = 0i64;
  if ( !pwithStack || (v9 = pwithStack->Data.Size - 1, v10 = v9, v9 < 0) )
  {
LABEL_18:
    Local = Scaleform::GFx::AS2::Environment::FindLocal(this, varname);
    if ( Local )
    {
      Scaleform::GFx::AS2::Value::operator=(Local, val);
    }
    else
    {
      Target = this->Target;
      if ( Target )
      {
        v20 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
        v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v20 + 8i64))(v20);
      }
      v22 = 0;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)(v8 + 8) + 24i64))(
        v8 + 8,
        this,
        varname,
        val,
        &v22);
    }
    return;
  }
  v11 = v9;
  while ( 1 )
  {
    Data = pwithStack->Data.Data;
    if ( (pwithStack->Data.Data[v11].BlockEndPc & 0x80000000) == 0 )
    {
      pObject = Data[v11].pObject;
      if ( !pObject
        || (v16 = (char *)pObject + 4 * BYTE5(pObject[1].pNext),
            v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 8i64))(v16),
            v14 = v17 + 8,
            !v17) )
      {
LABEL_9:
        v14 = 0i64;
      }
    }
    else
    {
      v13 = Data[v11].pObject;
      if ( !v13 )
        goto LABEL_9;
      v14 = (__int64)&v13->Scaleform::GFx::AS2::ObjectInterface;
    }
    v21.T.Type = 0;
    if ( v14 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v14 + 32i64))(
             v14,
             this,
             varname,
             &v21) )
      {
        break;
      }
    }
    if ( v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    --v11;
    if ( --v10 < 0 )
      goto LABEL_18;
  }
  v22 = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v14 + 24i64))(
    v14,
    this,
    varname,
    val,
    &v22);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
}

// File Line: 6063
// RVA: 0x714E90
void __fastcall Scaleform::GFx::AS2::Environment::SetLocal(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *val)
{
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS2::Value *Local; // rax

  Size = this->LocalFrames.Data.Size;
  if ( Size && this->LocalFrames.Data.Data[Size - 1].pObject )
  {
    Local = Scaleform::GFx::AS2::Environment::FindLocal(this, varname);
    if ( Local )
      Scaleform::GFx::AS2::Value::operator=(Local, val);
    else
      Scaleform::GFx::AS2::Environment::AddLocal(this, varname, val);
  }
}

// File Line: 6093
// RVA: 0x6D9060
void __fastcall Scaleform::GFx::AS2::Environment::AddLocal(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v3; // rbx
  Scaleform::GFx::AS2::LocalFrame *pObject; // r9
  Scaleform::GFx::AS2::LocalFrame *v5; // rbx
  unsigned int RefCount; // eax

  v3 = &this->LocalFrames.Data.Data[this->LocalFrames.Data.Size];
  pObject = v3[-1].pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v5 = v3[-1].pObject;
  if ( v5 )
    Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
      &v5->Variables,
      varname,
      val,
      this->StringContext.SWFVersion > 6u);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 6110
// RVA: 0x6E1B70
void __fastcall Scaleform::GFx::AS2::Environment::DeclareLocal(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname)
{
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h] BYREF

  Size = this->LocalFrames.Data.Size;
  if ( Size
    && this->LocalFrames.Data.Data[Size - 1].pObject
    && !Scaleform::GFx::AS2::Environment::FindLocal(this, varname) )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::AddLocal(this, varname, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
}

// File Line: 6141
// RVA: 0x7021A0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::LocalRegisterPtr(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int reg)
{
  unsigned __int64 Size; // rax

  Size = this->LocalRegister.Data.Size;
  if ( reg < Size )
    return &this->LocalRegister.Data.Data[Size - reg - 1];
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
    this,
    "Invalid local register %d, stack only has %d entries",
    reg,
    (unsigned int)Size);
  return this->GlobalRegister;
}

// File Line: 6159
// RVA: 0x6EAE50
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::FindLocal(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *varname)
{
  unsigned __int64 Size; // rax
  Scaleform::GFx::AS2::Value *CaseInsensitive; // rsi
  Scaleform::GFx::AS2::LocalFrame *pObject; // rbx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *p_Variables; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > v8; // rsi
  __int64 v9; // rax
  __int64 p_SizeMask; // rsi
  int SWFVersion; // esi
  Scaleform::GFx::ASMovieRootBase *v12; // r14
  bool v13; // zf
  Scaleform::GFx::ASMovieRootBase *v14; // rsi
  bool v15; // zf
  Scaleform::GFx::AS2::LocalFrame *v16; // rcx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int RefCount; // ecx

  Size = this->LocalFrames.Data.Size;
  if ( !Size )
    return 0i64;
  CaseInsensitive = 0i64;
  pObject = this->LocalFrames.Data.Data[Size - 1].pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  if ( !pObject )
  {
LABEL_34:
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    return CaseInsensitive;
  }
  do
  {
    p_Variables = &pObject->Variables;
    if ( this->StringContext.SWFVersion <= 6u )
    {
      CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                          p_Variables,
                          varname);
    }
    else
    {
      v8.mHash.pTable = p_Variables->mHash.pTable;
      if ( !p_Variables->mHash.pTable )
        goto LABEL_12;
      v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             &p_Variables->mHash,
             varname,
             varname->pNode->HashFlags & v8.mHash.pTable->SizeMask);
      if ( v9 < 0 )
        goto LABEL_12;
      p_SizeMask = (__int64)&v8.mHash.pTable[3 * v9 + 1].SizeMask;
      if ( !p_SizeMask )
        goto LABEL_12;
      CaseInsensitive = (Scaleform::GFx::AS2::Value *)(p_SizeMask + 8);
    }
    if ( CaseInsensitive )
      goto LABEL_34;
LABEL_12:
    SWFVersion = (unsigned __int8)this->StringContext.SWFVersion;
    if ( (unsigned int)SWFVersion >= 5 )
    {
      v12 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( (unsigned __int8)SWFVersion <= 6u )
      {
        if ( !varname->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(varname->pNode);
        v13 = v12[21].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)varname->pNode->pLower;
      }
      else
      {
        v13 = v12[21].pMovieImpl == (Scaleform::GFx::MovieImpl *)varname->pNode;
      }
      if ( v13 )
        break;
    }
    if ( SWFVersion >= 6 )
    {
      v14 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( this->StringContext.SWFVersion <= 6u )
      {
        if ( !varname->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(varname->pNode);
        v15 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v14[20].RefCount + 16i64) == varname->pNode->pLower;
      }
      else
      {
        v15 = *(Scaleform::GFx::ASStringNode **)&v14[20].RefCount == varname->pNode;
      }
      if ( v15 )
        break;
    }
    v16 = pObject->PrevFrame.pObject;
    if ( v16 )
      v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
    v17 = pObject->RefCount;
    if ( (v17 & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    pObject = pObject->PrevFrame.pObject;
  }
  while ( pObject );
  if ( pObject )
  {
    v18 = pObject->RefCount;
    if ( (v18 & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = v18 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  return 0i64;
}

// File Line: 6187
// RVA: 0x6F6A40
Scaleform::GFx::AS2::LocalFrame *__fastcall Scaleform::GFx::AS2::Environment::GetTopLocalFrame(
        Scaleform::GFx::AS2::Environment *this,
        int off)
{
  __int64 v2; // r8

  v2 = this->LocalFrames.Data.Size - off;
  if ( v2 )
    return this->LocalFrames.Data.Data[v2 - 1].pObject;
  else
    return 0i64;
}

// File Line: 6196
// RVA: 0x6E0160
Scaleform::GFx::AS2::LocalFrame *__fastcall Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(
        Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::AS2::LocalFrame *v2; // rdi
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v4; // rcx
  Scaleform::GFx::AS2::RefCountCollector<323> *v5; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v6; // rdx
  unsigned int RefCount; // ecx

  v2 = (Scaleform::GFx::AS2::LocalFrame *)this->StringContext.pContext->pHeap->vfptr->Alloc(this, 136i64, 0i64);
  if ( v2 )
  {
    Target = this->Target;
    if ( Target )
    {
      v4 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
      v5 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 8i64))(v4)
                                                                                               + 24)
                                                                                   + 32i64)
                                                                       + 56i64)
                                                           + 32i64);
    }
    else
    {
      v5 = 0i64;
    }
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
    v2->pRCC = v5;
    v2->RefCount = 1;
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::LocalFrame>::`vftable;
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LocalFrame::`vftable;
    v2->Variables.mHash.pTable = 0i64;
    v2->PrevFrame.pObject = 0i64;
    v2->SuperThis = 0i64;
    v2->Env = 0i64;
    *(_QWORD *)&v2->NArgs = 0i64;
    v2->Callee.T.Type = 0;
    v2->Caller.T.Type = 0;
  }
  else
  {
    v2 = 0i64;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames,
    &this->LocalFrames,
    this->LocalFrames.Data.Size + 1);
  v6 = &this->LocalFrames.Data.Data[this->LocalFrames.Data.Size - 1];
  if ( v6 )
  {
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    v6->pObject = v2;
  }
  if ( v2 )
  {
    RefCount = v2->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
  return v2;
}

// File Line: 6219
// RVA: 0x707CC0
bool __fastcall Scaleform::GFx::AS2::Environment::ParsePath(
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *varPath,
        Scaleform::GFx::ASString *ppath,
        Scaleform::GFx::ASString *pvar)
{
  int v8; // ebx
  const char *pData; // rdi
  char *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  char *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v19; // sf
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v8 = -1;
  pData = varPath->pNode->pData;
  v10 = strchr(pData, 58);
  if ( !v10 )
  {
    v10 = strrchr(pData, 46);
    if ( !v10 )
    {
      v16 = strrchr(pData, 47);
      if ( !v16 )
        return (char)v16;
      goto LABEL_9;
    }
  }
  v8 = (_DWORD)v10 - (_DWORD)pData;
  if ( (int)v10 - (int)pData < 0 )
  {
LABEL_9:
    v17 = *(Scaleform::GFx::ASStringNode **)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v17->RefCount;
    pNode = pvar->pNode;
    v14 = pvar->pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pvar->pNode = v17;
    goto LABEL_12;
  }
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &result, &varPath->pNode->pData[v8 + 1]);
  v12 = v11->pNode;
  ++v11->pNode->RefCount;
  v13 = pvar->pNode;
  v14 = pvar->pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  pvar->pNode = v12;
  v15 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_12:
  v19 = v8 < 0;
  if ( v8 > 0 )
  {
    if ( varPath->pNode->pData[v8 - 1] == 47 )
      --v8;
    v19 = v8 < 0;
  }
  if ( v19 )
  {
    v24 = varPath->pNode;
    ++varPath->pNode->RefCount;
    v25 = ppath->pNode;
    v14 = ppath->pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    ppath->pNode = v24;
  }
  else
  {
    v20 = Scaleform::GFx::AS2::ASStringContext::CreateString(psc, &result, varPath->pNode->pData, v8);
    v21 = v20->pNode;
    ++v20->pNode->RefCount;
    v22 = ppath->pNode;
    v14 = ppath->pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    ppath->pNode = v21;
    v23 = result.pNode;
    v14 = result.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  }
  LOBYTE(v16) = 1;
  return (char)v16;
}

// File Line: 6266
// RVA: 0x700B50
char __fastcall Scaleform::GFx::AS2::Environment::IsPath(Scaleform::GFx::ASString *varPath)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  const char *pData; // rdi

  pNode = varPath->pNode;
  if ( (varPath->pNode->HashFlags & 0x4000000) != 0 )
    return 1;
  pData = pNode->pData;
  if ( strchr(pNode->pData, 58) || strchr(pData, 47) || strchr(pData, 46) )
  {
    varPath->pNode->HashFlags |= 0x4000000u;
    return 1;
  }
  else
  {
    varPath->pNode->HashFlags |= 0x6000000u;
    return 0;
  }
}

// File Line: 6295
// RVA: 0x6EB650
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Environment::FindTargetByValue(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObject *v5; // rdx
  char v6; // cl
  Scaleform::GFx::InteractiveObject *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::InteractiveObject *Target; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h] BYREF

  if ( val->T.Type == 7 )
  {
    if ( this )
    {
      pStringNode = val->V.pStringNode;
      if ( pStringNode )
      {
        v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)pStringNode,
               this->Target->pASRoot->pMovieImpl);
        v5 = v4;
        if ( v4 )
        {
          v6 = LOBYTE(v4->Scaleform::GFx::DisplayObjectBase::Flags) >> 7;
          v7 = 0i64;
          if ( (v6 & 1) != 0 )
            return (Scaleform::GFx::InteractiveObject *)v5;
          return v7;
        }
      }
    }
    return 0i64;
  }
  if ( val->T.Type != 5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(this, "Invalid movie clip path; neither string nor object");
    return 0i64;
  }
  v8 = Scaleform::GFx::AS2::Value::ToString(val, &result, this, -1);
  Target = Scaleform::GFx::AS2::Environment::FindTarget(this, v8, 0);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return Target;
}

// File Line: 6340
// RVA: 0x703210
bool __fastcall Scaleform::GFx::AS2::Environment::NeedTermination(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::InteractiveObject *Target; // rax
  bool result; // al

  result = (execType == Exec_Unknown || execType == Exec_Event)
        && ((Target = this->Target,
             (Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0)
         || Target->Depth < -1)
        || (this->Target->Flags & 0x10) != 0;
  return result;
}

// File Line: 6406
// RVA: 0x703250
char __fastcall Scaleform::GFx::AS2::StringTokenizer::NextToken(Scaleform::GFx::AS2::StringTokenizer *this, char *sep)
{
  const char *Str; // rdi
  const char *v6; // r9
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  Str = this->Str;
  if ( this->Str >= this->EndStr )
    return 0;
  do
  {
    if ( strchr(this->Delimiters, *this->Str) )
      break;
    ++this->Str;
  }
  while ( this->Str < this->EndStr );
  *sep = *this->Str;
  v6 = this->Str;
  if ( Str == this->Str || v6 > this->EndStr )
  {
    v11 = Scaleform::GFx::ASStringManager::CreateEmptyString(this->Token.pNode->pManager, &result);
    pNode = v11->pNode;
    ++v11->pNode->RefCount;
    v13 = this->Token.pNode;
    v10 = v13->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    this->Token.pNode = pNode;
  }
  else
  {
    v7 = Scaleform::GFx::ASStringManager::CreateString(this->Token.pNode->pManager, &result, Str, v6 - Str);
    v8 = v7->pNode;
    ++v7->pNode->RefCount;
    v9 = this->Token.pNode;
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    this->Token.pNode = v8;
  }
  v14 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  ++this->Str;
  return 1;
}

// File Line: 6447
// RVA: 0x6EB710
char __fastcall Scaleform::GFx::AS2::Environment::FindVariable(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Environment::GetVarParams *params,
        bool onlyTargets,
        Scaleform::GFx::ASString *varName)
{
  Scaleform::GFx::AS2::Value *pResult; // rcx
  char Type; // bl
  char v9; // r13
  Scaleform::GFx::ASStringNode *pNode; // rax
  const char *pData; // rsi
  __int64 Size; // r15
  Scaleform::GFx::AS2::Value *pOwner; // rdi
  Scaleform::GFx::InteractiveObject **ppNewTarget; // rax
  Scaleform::GFx::InteractiveObject *v15; // r14
  Scaleform::GFx::DisplayObject *v16; // rax
  Scaleform::GFx::ASStringNode *pObject; // rdi
  const char *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // rcx
  const char *Str; // rax
  const char *v21; // rsi
  char v22; // r15
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rsi
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rsi
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rsi
  Scaleform::GFx::ASStringNode *v31; // rcx
  char VariableRaw; // r15
  Scaleform::GFx::ASMovieRootBase *v33; // rsi
  Scaleform::GFx::ASStringNode *v34; // rdx
  bool v35; // zf
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v36; // rax
  unsigned __int64 v37; // rcx
  Scaleform::GFx::AS2::ObjectInterface *ObjectInterface; // rsi
  Scaleform::GFx::InteractiveObject *vfptr; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rsi
  Scaleform::GFx::AS2::Value *v41; // rax
  Scaleform::GFx::AS2::Object *v42; // rax
  Scaleform::GFx::AS2::ObjectInterface *v43; // rcx
  Scaleform::GFx::DisplayObject *v44; // rax
  Scaleform::GFx::DisplayObject *v45; // rcx
  char *v46; // rcx
  __int64 v47; // rax
  Scaleform::GFx::DisplayObject *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rsi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStack; // rax
  Scaleform::GFx::DisplayObject *v51; // rax
  Scaleform::GFx::DisplayObject *v52; // rcx
  char *v53; // rcx
  __int64 v54; // rax
  Scaleform::GFx::AS2::Value *v55; // rcx
  Scaleform::GFx::DisplayObject *v56; // rax
  Scaleform::GFx::DisplayObject *v57; // rcx
  char *v58; // rcx
  __int64 v59; // rax
  Scaleform::GFx::AS2::ObjectInterface *v60; // rcx
  Scaleform::GFx::AS2::Object *v61; // rax
  Scaleform::GFx::DisplayObject *v62; // rax
  Scaleform::GFx::InteractiveObject *v63; // rcx
  Scaleform::GFx::AS2::Value *v64; // rdi
  Scaleform::GFx::InteractiveObject **v65; // rax
  Scaleform::GFx::ASStringNode *v66; // rdi
  Scaleform::GFx::ASStringNode *v67; // rcx
  Scaleform::GFx::DisplayObject *v68; // rax
  Scaleform::GFx::AS2::Value *v69; // rdi
  char v70; // di
  Scaleform::GFx::AS2::Value *v71; // rcx
  Scaleform::GFx::ASStringNode *v72; // rcx
  char sep; // [rsp+20h] [rbp-E0h] BYREF
  char v74; // [rsp+21h] [rbp-DFh]
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::GFx::AS2::StringTokenizer pstr; // [rsp+48h] [rbp-B8h] BYREF
  const char *v77; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::Value v78; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::ASString v80; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::FnCall v81; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v82; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+100h] [rbp+0h] BYREF
  __int64 v84; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS2::Value v85; // [rsp+138h] [rbp+38h] BYREF

  v84 = -2i64;
  if ( !params->VarName->pNode->Size )
  {
    pResult = params->pResult;
    if ( pResult )
      Scaleform::GFx::AS2::Value::SetAsCharacter(pResult, this->Target);
    return 1;
  }
  Type = 0;
  v.T.Type = 0;
  v9 = 0;
  pNode = params->VarName->pNode;
  pData = pNode->pData;
  Size = pNode->Size;
  pOwner = params->pOwner;
  if ( pOwner )
  {
    Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
    pOwner->T.Type = 0;
  }
  ppNewTarget = params->ppNewTarget;
  v15 = 0i64;
  if ( ppNewTarget )
    *ppNewTarget = 0i64;
  if ( *pData == 47 )
  {
    v16 = (Scaleform::GFx::DisplayObject *)this->Target->vfptr[68].__vecDelDtor(this->Target, 0i64);
    if ( v16 )
    {
      pObject = (Scaleform::GFx::ASStringNode *)v16->pNameHandle.pObject;
      if ( !pObject )
        pObject = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
    }
    else
    {
      pObject = 0i64;
    }
    Scaleform::GFx::AS2::Value::DropRefs(&v);
    Type = 7;
    v.T.Type = 7;
    v.V.pStringNode = pObject;
    if ( pObject )
      ++LODWORD(pObject->pData);
    v9 = 1;
    ++pData;
    --Size;
    v18 = onlySlashesDelim;
    v77 = onlySlashesDelim;
    v19 = params->pOwner;
    if ( !v19 )
      goto LABEL_22;
    Scaleform::GFx::AS2::Value::operator=(v19, &v);
    Type = v.T.Type;
    v18 = v77;
  }
  else
  {
    v18 = ":./";
    if ( *pData == 46 )
      v18 = onlySlashesDelim;
    v77 = v18;
  }
  pObject = v.V.pStringNode;
LABEL_22:
  pstr.Str = pData;
  pstr.EndStr = &pData[Size];
  pstr.Delimiters = v18;
  pstr.Token.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++pstr.Token.pNode->RefCount;
  sep = 1;
  Str = pstr.Str;
  while ( Str < pstr.EndStr )
  {
    v21 = Str;
    do
    {
      v35 = strchr(pstr.Delimiters, *Str) == 0i64;
      Str = pstr.Str;
      if ( !v35 )
        break;
      Str = pstr.Str + 1;
      pstr.Str = Str;
    }
    while ( Str < pstr.EndStr );
    v22 = *Str;
    v74 = *Str;
    if ( v21 == Str || Str > pstr.EndStr )
    {
      v27 = Scaleform::GFx::ASStringManager::CreateEmptyString(pstr.Token.pNode->pManager, &v80);
      v28 = v27->pNode;
      ++v27->pNode->RefCount;
      v29 = pstr.Token.pNode;
      v35 = pstr.Token.pNode->RefCount-- == 1;
      if ( v35 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      pstr.Token.pNode = v28;
      v26 = v80.pNode;
    }
    else
    {
      v23 = Scaleform::GFx::ASStringManager::CreateString(pstr.Token.pNode->pManager, &result, v21, Str - v21);
      v24 = v23->pNode;
      ++v23->pNode->RefCount;
      v25 = pstr.Token.pNode;
      v35 = pstr.Token.pNode->RefCount-- == 1;
      if ( v35 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      pstr.Token.pNode = v24;
      v26 = result.pNode;
    }
    v35 = v26->RefCount-- == 1;
    if ( v35 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    Str = ++pstr.Str;
    v30 = pstr.Token.pNode;
    if ( pstr.Token.pNode->Size )
    {
      if ( varName )
      {
        ++pstr.Token.pNode->RefCount;
        v31 = varName->pNode;
        v35 = varName->pNode->RefCount-- == 1;
        if ( v35 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v31);
        varName->pNode = v30;
      }
      v78.T.Type = 0;
      VariableRaw = 0;
      if ( Type == 7 )
      {
        if ( !v9 )
          goto LABEL_53;
      }
      else
      {
        if ( v9 )
          goto LABEL_70;
        v33 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
        v34 = pstr.Token.pNode;
        if ( *(Scaleform::GFx::ASStringNode **)&v33[17].AVMVersion != pstr.Token.pNode )
        {
          if ( this->StringContext.SWFVersion <= 6u )
          {
            if ( !pstr.Token.pNode->pLower )
            {
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pstr.Token.pNode);
              v34 = pstr.Token.pNode;
            }
            v35 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v33[20].AVMVersion + 16i64) == v34->pLower;
          }
          else
          {
            v35 = *(Scaleform::GFx::ASStringNode **)&v33[20].AVMVersion == pstr.Token.pNode;
          }
          if ( !v35 )
          {
            pWithStack = params->pWithStack;
            paramsa.VarName = &pstr.Token;
            paramsa.pResult = &v78;
            paramsa.pWithStack = pWithStack;
            memset(&paramsa.ppNewTarget, 0, 20);
            VariableRaw = Scaleform::GFx::AS2::Environment::GetVariableRaw(this, &paramsa);
            goto LABEL_105;
          }
        }
LABEL_53:
        v36 = params->pWithStack;
        if ( v36 )
        {
          v37 = v36->Data.Size;
          if ( v37 )
          {
            ObjectInterface = Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(&v36->Data.Data[v37 - 1]);
            if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ObjectInterface->vfptr->gap8[8])(ObjectInterface)
               - 2 <= 3 )
            {
              if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ObjectInterface->vfptr->gap8[8])(ObjectInterface)
                 - 2 <= 3 )
              {
                vfptr = (Scaleform::GFx::InteractiveObject *)ObjectInterface[1].vfptr;
                goto LABEL_61;
              }
              goto LABEL_64;
            }
          }
        }
        if ( !Type || Type == 10 )
        {
          vfptr = this->Target;
LABEL_61:
          if ( vfptr )
          {
            CharacterHandle = (Scaleform::GFx::ASStringNode *)vfptr->pNameHandle.pObject;
            if ( !CharacterHandle )
              CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(vfptr);
          }
          else
          {
LABEL_64:
            CharacterHandle = 0i64;
          }
          if ( Type != 7 || pObject != CharacterHandle )
          {
            Scaleform::GFx::AS2::Value::DropRefs(&v);
            Type = 7;
            v.T.Type = 7;
            v.V.pStringNode = CharacterHandle;
            pObject = CharacterHandle;
            if ( CharacterHandle )
              ++LODWORD(CharacterHandle->pData);
          }
        }
        if ( Type != 7 )
        {
LABEL_70:
          if ( (unsigned __int8)(Type - 2) <= 3u )
          {
            v41 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(this, &v85, &v);
            Scaleform::GFx::AS2::Value::operator=(&v, v41);
            if ( v85.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v85);
            Type = v.T.Type;
            pObject = v.V.pStringNode;
          }
          switch ( Type )
          {
            case 6:
LABEL_78:
              v42 = Scaleform::GFx::AS2::Value::ToObject(&v, this);
              if ( !v42 )
                goto LABEL_105;
              v43 = &v42->Scaleform::GFx::AS2::ObjectInterface;
              break;
            case 7:
LABEL_95:
              if ( !pObject )
                goto LABEL_105;
              v51 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                      (Scaleform::GFx::CharacterHandle *)pObject,
                      this->Target->pASRoot->pMovieImpl);
              if ( !v51 )
                goto LABEL_105;
              v52 = 0i64;
              if ( SLOBYTE(v51->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
                v52 = v51;
              if ( !v52 )
                goto LABEL_105;
              v53 = (char *)v52 + 4 * (unsigned __int8)v52->AvmObjOffset;
              v54 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v53 + 8i64))(v53);
              if ( !v54 )
                goto LABEL_105;
              v43 = (Scaleform::GFx::AS2::ObjectInterface *)(v54 + 8);
              break;
            case 8:
            case 11:
              goto LABEL_78;
            default:
LABEL_104:
              Scaleform::GFx::AS2::Value::DropRefs(&v78);
              VariableRaw = 0;
              v78.T.Type = 0;
LABEL_105:
              v55 = params->pOwner;
              if ( v55 )
              {
                Scaleform::GFx::AS2::Value::operator=(v55, &v);
                pObject = v.V.pStringNode;
                Type = v.T.Type;
              }
              if ( onlyTargets && v78.T.Type != 7 || !VariableRaw )
              {
                Scaleform::GFx::AS2::Value::DropRefs(&v);
                Type = 0;
                v.T.Type = 0;
                v9 = 0;
                if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&pstr, &sep) )
                {
                  v64 = params->pOwner;
                  if ( v64 )
                  {
                    Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
                    v64->T.Type = 0;
                  }
                  v65 = params->ppNewTarget;
                  if ( v65 )
                    *v65 = 0i64;
                  if ( varName )
                  {
                    v66 = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
                    ++v66->RefCount;
                    v67 = varName->pNode;
                    v35 = varName->pNode->RefCount-- == 1;
                    if ( v35 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v67);
                    varName->pNode = v66;
                  }
                }
                if ( v78.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v78);
                pObject = v.V.pStringNode;
                goto LABEL_160;
              }
              if ( v78.T.Type == 9 )
              {
                if ( Type == 7 )
                {
                  if ( pObject )
                  {
                    v56 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                            (Scaleform::GFx::CharacterHandle *)pObject,
                            this->Target->pASRoot->pMovieImpl);
                    if ( v56 )
                    {
                      v57 = 0i64;
                      if ( SLOBYTE(v56->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
                        v57 = v56;
                      if ( v57 )
                      {
                        v58 = (char *)v57 + 4 * (unsigned __int8)v57->AvmObjOffset;
                        v59 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v58 + 8i64))(v58);
                        if ( v59 )
                        {
                          v60 = (Scaleform::GFx::AS2::ObjectInterface *)(v59 + 8);
                          goto LABEL_121;
                        }
                      }
                    }
                  }
LABEL_120:
                  v60 = 0i64;
                }
                else
                {
                  v61 = Scaleform::GFx::AS2::Value::ToObject(&v, this);
                  v60 = &v61->Scaleform::GFx::AS2::ObjectInterface;
                  if ( !v61 )
                    goto LABEL_120;
                }
LABEL_121:
                if ( v78.T.Type == 9 )
                {
                  if ( *(_QWORD *)&v78.V.pStringNode->Size )
                  {
                    v82.T.Type = 0;
                    v81.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
                    v81.Result = &v82;
                    v81.ThisPtr = v60;
                    memset(&v81.ThisFunctionRef, 0, 17);
                    v81.Env = this;
                    *(_QWORD *)&v81.NArgs = 0i64;
                    (*(void (__fastcall **)(_QWORD, Scaleform::GFx::AS2::FnCall *, const char *, _QWORD))(**(_QWORD **)&v78.V.pStringNode->Size + 80i64))(
                      *(_QWORD *)&v78.V.pStringNode->Size,
                      &v81,
                      v78.V.pStringNode[1].pData,
                      0i64);
                    Scaleform::GFx::AS2::FnCall::~FnCall(&v81);
                    Scaleform::GFx::AS2::Value::operator=(&v, &v82);
                    if ( v82.T.Type >= 5u )
                      Scaleform::GFx::AS2::Value::DropRefs(&v82);
LABEL_128:
                    pObject = v.V.pStringNode;
                    Type = v.T.Type;
                  }
                  else if ( this->vfptr->IsVerboseActionErrors(this) )
                  {
                    Scaleform::GFx::AS2::Environment::LogScriptError(this, "Getter method is null.");
                  }
                }
                v9 = VariableRaw;
                if ( v78.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v78);
                v22 = v74;
                Str = pstr.Str;
                goto LABEL_132;
              }
              Scaleform::GFx::AS2::Value::operator=(&v, &v78);
              goto LABEL_128;
          }
          if ( v43 )
          {
            VariableRaw = v43->vfptr->GetMember(v43, this, &pstr.Token, &v78);
            if ( !VariableRaw )
              goto LABEL_104;
          }
          goto LABEL_105;
        }
      }
      if ( pObject )
      {
        v44 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                (Scaleform::GFx::CharacterHandle *)pObject,
                this->Target->pASRoot->pMovieImpl);
        if ( v44 )
        {
          v45 = 0i64;
          if ( SLOBYTE(v44->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
            v45 = v44;
          if ( v45 )
          {
            v46 = (char *)v45 + 4 * (unsigned __int8)v45->AvmObjOffset;
            v47 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v46 + 8i64))(v46);
            v48 = (Scaleform::GFx::DisplayObject *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)v47 + 208i64))(
                                                     v47,
                                                     &pstr.Token,
                                                     (unsigned __int8)sep);
            if ( v48 )
            {
              v49 = (Scaleform::GFx::ASStringNode *)v48->pNameHandle.pObject;
              if ( !v49 )
                v49 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v48);
              if ( v78.T.Type != 7 || v78.V.pStringNode != v49 )
              {
                Scaleform::GFx::AS2::Value::DropRefs(&v78);
                v78.T.Type = 7;
                v78.V.pStringNode = v49;
                if ( v49 )
                  ++LODWORD(v49->pData);
              }
              VariableRaw = 1;
              goto LABEL_105;
            }
          }
        }
      }
      goto LABEL_95;
    }
LABEL_132:
    if ( v77 == onlySlashesDelim )
    {
      if ( v22 == 58 )
      {
        pstr.Delimiters = ":./";
        v77 = ":./";
LABEL_135:
        if ( params->ppNewTarget && Type == 7 )
        {
          if ( pObject
            && (v62 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                        (Scaleform::GFx::CharacterHandle *)pObject,
                        this->Target->pASRoot->pMovieImpl)) != 0i64 )
          {
            v63 = 0i64;
            if ( SLOBYTE(v62->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
              v63 = (Scaleform::GFx::InteractiveObject *)v62;
          }
          else
          {
            v63 = 0i64;
          }
          *params->ppNewTarget = v63;
          Str = pstr.Str;
        }
        goto LABEL_147;
      }
    }
    else if ( v22 == 46 )
    {
      goto LABEL_135;
    }
    if ( v22 == 47 )
    {
      pstr.Delimiters = onlySlashesDelim;
      v77 = onlySlashesDelim;
    }
LABEL_147:
    sep = 0;
  }
LABEL_160:
  if ( params->ppNewTarget && Type == 7 )
  {
    if ( pObject )
    {
      v68 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
              (Scaleform::GFx::CharacterHandle *)pObject,
              this->Target->pASRoot->pMovieImpl);
      if ( v68 )
      {
        if ( SLOBYTE(v68->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
          v15 = (Scaleform::GFx::InteractiveObject *)v68;
      }
    }
    *params->ppNewTarget = v15;
  }
  v69 = params->pOwner;
  if ( v69 && (unsigned __int8)(v69->T.Type - 6) > 1u && v69->T.Type != 8 && v69->T.Type != 11 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
    v69->T.Type = 0;
  }
  if ( v9 )
  {
    v71 = params->pResult;
    if ( v71 )
    {
      Scaleform::GFx::AS2::Value::operator=(v71, &v);
      Type = v.T.Type;
    }
    v70 = 1;
  }
  else
  {
    v70 = 0;
  }
  v72 = pstr.Token.pNode;
  v35 = pstr.Token.pNode->RefCount-- == 1;
  if ( v35 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v72);
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v70;
}

// File Line: 6643
// RVA: 0x6EB3C0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Environment::FindTarget(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *path,
        char excludeFlags)
{
  Scaleform::GFx::InteractiveObject *Target; // rsi
  const char *pData; // rdi
  unsigned __int8 i; // r15
  const char *j; // rbx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rdi
  Scaleform::GFx::ASStringNode *v19; // rcx
  __int64 v20; // rax
  char *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString v23; // [rsp+20h] [rbp-48h] BYREF
  __int64 v24; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v25; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h] BYREF

  v24 = -2i64;
  if ( path->pNode->Size )
  {
    Target = this->Target;
    pData = path->pNode->pData;
    v25 = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v25->RefCount;
    if ( *pData == 47 )
    {
      Target = (Scaleform::GFx::InteractiveObject *)Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                                      Target,
                                                      0);
      ++pData;
    }
    for ( i = 1; ; i = 0 )
    {
      for ( j = pData; *j; ++j )
      {
        if ( *j == 46 )
        {
          if ( j[1] != 46 )
            goto LABEL_16;
          ++j;
        }
        else if ( *j == 47 )
        {
          goto LABEL_16;
        }
      }
      j = 0i64;
LABEL_16:
      if ( j == pData )
        break;
      if ( j )
      {
        v12 = Scaleform::GFx::AS2::Environment::CreateString(this, &result, pData, j - pData);
        pNode = v12->pNode;
        ++v12->pNode->RefCount;
        v14 = v25;
        v15 = v25->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        v25 = pNode;
        v16 = result.pNode;
      }
      else
      {
        v17 = Scaleform::GFx::AS2::Environment::CreateString(this, &v23, pData);
        v18 = v17->pNode;
        ++v17->pNode->RefCount;
        v19 = v25;
        v15 = v25->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        v25 = v18;
        v16 = v23.pNode;
      }
      v15 = v16->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( v25->Size )
      {
        if ( Target )
        {
          v21 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
          v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v21 + 8i64))(v21);
        }
        else
        {
          v20 = 0i64;
        }
        Target = (Scaleform::GFx::InteractiveObject *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASStringNode **, _QWORD))(*(_QWORD *)v20 + 208i64))(
                                                        v20,
                                                        &v25,
                                                        i);
      }
      if ( !Target || !j )
        goto LABEL_36;
      pData = j + 1;
    }
    if ( (excludeFlags & 4) == 0 )
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(this, "Invalid path %s", path->pNode->pData);
LABEL_36:
    v22 = v25;
    v15 = v25->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    return Target;
  }
  else if ( (*((_BYTE *)this + 382) & 2) != 0 )
  {
    return 0i64;
  }
  else
  {
    return this->Target;
  }
}  else if ( (*((_BYTE

// File Line: 6698
// RVA: 0x707420
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::FunctionRef *constructor,
        int nargs,
        int argsTopOff)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  Scaleform::GFx::ASStringNode *v6; // r13
  int v7; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  bool v9; // r15
  char v10; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  int v12; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // rdx
  char Type; // si
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Object *v18; // rax
  Scaleform::GFx::AS2::Object *v19; // rdi
  Scaleform::GFx::AS2::Value *v20; // rcx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *v23; // rdx
  char v24; // r12
  Scaleform::GFx::AS2::RefCountBaseGC<323> *Function; // r15
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  char v27; // al
  bool v28; // bl
  char v29; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // rcx
  int v31; // edx
  Scaleform::GFx::ASStringNode *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS2::FunctionRef *v34; // rax
  char v35; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v36; // rcx
  int v37; // edx
  Scaleform::GFx::ASStringNode *v38; // rcx
  unsigned int v39; // eax
  __int64 v40; // rax
  Scaleform::GFx::AS2::ObjectInterface *v41; // rsi
  __int64 v42; // rdi
  Scaleform::GFx::AS2::Object *v43; // rax
  Scaleform::GFx::AS2::FunctionRef *v44; // rdi
  bool BooleanValue; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // rcx
  int v47; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v48; // rcx
  int v49; // eax
  Scaleform::GFx::AS2::ObjectInterface *v50; // r9
  Scaleform::GFx::ASStringNode *v51; // rcx
  bool v52; // zf
  Scaleform::GFx::ASStringNode *v53; // rcx
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ecx
  int v58; // [rsp+20h] [rbp-A8h]
  unsigned int v59; // [rsp+20h] [rbp-A8h]
  Scaleform::GFx::AS2::Value result; // [rsp+30h] [rbp-98h] BYREF
  Scaleform::GFx::AS2::Value v61; // [rsp+50h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v62; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v63; // [rsp+90h] [rbp-38h] BYREF
  __int64 v64; // [rsp+B0h] [rbp-18h]
  Scaleform::GFx::AS2::Value v65; // [rsp+B8h] [rbp-10h] BYREF
  char v66; // [rsp+D8h] [rbp+10h]
  Scaleform::GFx::AS2::FunctionRef *ctorFunc; // [rsp+140h] [rbp+78h]
  unsigned int v68; // [rsp+148h] [rbp+80h]
  unsigned int v69; // [rsp+150h] [rbp+88h]

  v64 = -2i64;
  v4 = constructor;
  v6 = 0i64;
  v7 = 0;
  v58 = 0;
  v66 = 0;
  if ( argsTopOff < 0 )
    v69 = 32 * this->Stack.Pages.Data.Size - 32 + this->Stack.pCurrent - this->Stack.pPageStart;
  v8 = 0i64;
  *((_QWORD *)&v61.NV + 3) = 0i64;
  v9 = 0;
  if ( nargs == 1 )
  {
    v7 = 1;
    v58 = 1;
    if ( constructor->Function == Scaleform::GFx::AS2::Environment::GetConstructor(
                                    this,
                                    (Scaleform::GFx::AS2::FunctionRef *)&result,
                                    ASBuiltin_Object)->Function )
      v9 = 1;
  }
  if ( (v7 & 1) != 0 )
  {
    v7 &= ~1u;
    v58 = v7;
    v10 = *((_BYTE *)&result.NV + 16);
    if ( (*(_BYTE *)(&result.NV + 1) & 2) == 0 )
    {
      v11 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
      if ( *(_QWORD *)&result.T.Type )
      {
        v12 = *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64);
        if ( (v12 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64) = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          v10 = *((_BYTE *)&result.NV + 16);
        }
      }
    }
    *(_QWORD *)&result.T.Type = 0i64;
    if ( (v10 & 1) == 0 )
    {
      pStringNode = result.V.pStringNode;
      if ( result.V.pStringNode )
      {
        RefCount = result.V.pStringNode->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.V.pStringNode->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
    result.V.pStringNode = 0i64;
  }
  if ( v9 )
  {
    pCurrent = this->Stack.pCurrent;
    Type = 0;
    v61.T.Type = 0;
    if ( (unsigned __int8)(pCurrent->T.Type - 2) <= 3u )
    {
      v17 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(this, &result, 0);
      Scaleform::GFx::AS2::Value::operator=(&v61, v17);
      if ( result.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&result);
    }
    else
    {
      if ( (unsigned __int8)(pCurrent->T.Type - 6) > 1u )
      {
LABEL_29:
        if ( (unsigned __int8)Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v61);
        v4 = ctorFunc;
        goto LABEL_32;
      }
      Scaleform::GFx::AS2::Value::operator=(&v61, pCurrent);
    }
    Type = v61.T.Type;
    if ( v61.T.Type && v61.T.Type != 10 )
    {
      v18 = Scaleform::GFx::AS2::Value::ToObject(&v61, this);
      v19 = v18;
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      if ( (unsigned __int8)Type >= 5u )
      {
        v20 = &v61;
LABEL_95:
        Scaleform::GFx::AS2::Value::DropRefs(v20);
        goto LABEL_96;
      }
      goto LABEL_96;
    }
    goto LABEL_29;
  }
LABEL_32:
  v62.T.Type = 0;
  p_StringContext = &this->StringContext;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, int))v4->Function->vfptr->GetMemberRaw)(
          &v4->Function->Scaleform::GFx::AS2::ObjectInterface,
          &this->StringContext,
          &this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
          &v62,
          v58) )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Value::SetAsObject(&v62, Prototype);
  }
  v23 = Scaleform::GFx::AS2::Value::ToObject(&v62, this);
  v24 = 0;
  *((_BYTE *)&result.NV + 16) = 0;
  Function = v4->Function;
  *(_QWORD *)&result.T.Type = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  result.V.pStringNode = 0i64;
  pLocalFrame = v4->pLocalFrame;
  if ( pLocalFrame )
  {
    v27 = v4->Flags & 1;
    v6 = (Scaleform::GFx::ASStringNode *)v4->pLocalFrame;
    result.V.pStringNode = v6;
    v24 = v27 != 0;
    *((_BYTE *)&result.NV + 16) = v27 != 0;
    if ( !v27 )
      pLocalFrame->RefCount = (pLocalFrame->RefCount + 1) & 0x8FFFFFFF;
  }
  v63.T.Type = 0;
  if ( v23
    && v23->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
         &v23->Scaleform::GFx::AS2::ObjectInterface,
         &this->StringContext,
         (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
         &v63) )
  {
    v28 = 0;
    if ( v63.T.Type == 8 || v63.T.Type == 11 )
    {
      v7 |= 2u;
      v59 = v7;
      if ( Scaleform::GFx::AS2::Value::ToFunction(&v63, (Scaleform::GFx::AS2::FunctionRef *)&v61, this)->Function )
        v28 = 1;
    }
    if ( (v7 & 2) != 0 )
    {
      v59 = v7 & 0xFFFFFFFD;
      v29 = *((_BYTE *)&v61.NV + 16);
      if ( (*(_BYTE *)(&v61.NV + 1) & 2) == 0 )
      {
        v30 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v61.T.Type;
        if ( *(_QWORD *)&v61.T.Type )
        {
          v31 = *(_DWORD *)(*(_QWORD *)&v61.T.Type + 24i64);
          if ( (v31 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_QWORD *)&v61.T.Type + 24i64) = v31 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
            v29 = *((_BYTE *)&v61.NV + 16);
          }
        }
      }
      *(_QWORD *)&v61.T.Type = 0i64;
      if ( (v29 & 1) == 0 )
      {
        v32 = v61.V.pStringNode;
        if ( v61.V.pStringNode )
        {
          v33 = v61.V.pStringNode->RefCount;
          if ( (v33 & 0x3FFFFFF) != 0 )
          {
            v61.V.pStringNode->RefCount = v33 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v32);
          }
        }
      }
      v61.V.pStringNode = 0i64;
    }
    if ( v28 )
    {
      v34 = Scaleform::GFx::AS2::Value::ToFunction(&v63, (Scaleform::GFx::AS2::FunctionRef *)&v61, this);
      Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&result, v34);
      v35 = *((_BYTE *)&v61.NV + 16);
      if ( (*(_BYTE *)(&v61.NV + 1) & 2) == 0 )
      {
        v36 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v61.T.Type;
        if ( *(_QWORD *)&v61.T.Type )
        {
          v37 = *(_DWORD *)(*(_QWORD *)&v61.T.Type + 24i64);
          if ( (v37 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_QWORD *)&v61.T.Type + 24i64) = v37 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
            v35 = *((_BYTE *)&v61.NV + 16);
          }
        }
      }
      *(_QWORD *)&v61.T.Type = 0i64;
      if ( (v35 & 1) == 0 )
      {
        v38 = v61.V.pStringNode;
        if ( v61.V.pStringNode )
        {
          v39 = v61.V.pStringNode->RefCount;
          if ( (v39 & 0x3FFFFFF) != 0 )
          {
            v61.V.pStringNode->RefCount = v39 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v38);
          }
        }
      }
      v61.V.pStringNode = 0i64;
      v24 = *((_BYTE *)&result.NV + 16);
      v6 = result.V.pStringNode;
      Function = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
    }
  }
  v40 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *))Function->vfptr[5].ExecuteForEachChild_GC)(
          Function,
          this);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v40;
  *((_QWORD *)&v61.NV + 3) = v40;
  if ( v40 )
  {
    v41 = (Scaleform::GFx::AS2::ObjectInterface *)(v40 + 32);
    v42 = *(_QWORD *)(v40 + 32);
    v43 = Scaleform::GFx::AS2::Value::ToObject(&v62, this);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(v42 + 104))(
      v41,
      &this->StringContext,
      v43);
    v44 = ctorFunc;
    Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(v41, &this->StringContext, ctorFunc);
    v65.T.Type = 0;
    v61.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v65;
    *((_OWORD *)&v61.NV + 1) = (unsigned __int64)v41;
    v62.V.BooleanValue = 0;
    *(_QWORD *)&v62.T.Type = 0i64;
    *((_QWORD *)&result.NV + 3) = this;
    *(_QWORD *)&v61.T.Type = __PAIR64__(v69, v68);
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::LocalFrame *, _QWORD, unsigned int))v44->Function->vfptr[3].Finalize_GC)(
      v44->Function,
      &v61,
      v44->pLocalFrame,
      0i64,
      v59);
    *(_QWORD *)&v61.T.Type = &Scaleform::GFx::AS2::FnCall::`vftable;
    BooleanValue = v62.V.BooleanValue;
    if ( (v62.V.BooleanValue & 2) == 0 )
    {
      v46 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)*((_QWORD *)&v61.NV + 3);
      if ( *((_QWORD *)&v61.NV + 3) )
      {
        v47 = *(_DWORD *)(*((_QWORD *)&v61.NV + 3) + 24i64);
        if ( (v47 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*((_QWORD *)&v61.NV + 3) + 24i64) = v47 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
          BooleanValue = v62.V.BooleanValue;
        }
      }
    }
    *((_QWORD *)&v61.NV + 3) = 0i64;
    if ( !BooleanValue )
    {
      v48 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v62.T.Type;
      if ( *(_QWORD *)&v62.T.Type )
      {
        v49 = *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64);
        if ( (v49 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64) = v49 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
        }
      }
    }
    *(_QWORD *)&v62.T.Type = 0i64;
    *(_QWORD *)&v61.T.Type = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    v19 = (Scaleform::GFx::AS2::Object *)v8;
    if ( v65.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v65);
  }
  else
  {
    v50 = &v4->Function->Scaleform::GFx::AS2::ObjectInterface;
    if ( !v4->Function )
      v50 = 0i64;
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      this->StringContext.pContext,
      (Scaleform::GFx::ASString *)&v61.NV + 2,
      this,
      v50);
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      this->StringContext.pContext,
      (Scaleform::GFx::ASString *)&v61.NV.8,
      this,
      (Scaleform::GFx::AS2::ObjectInterface *)&Function[1]);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      this,
      "%s::CreateNewObject returned NULL during creation of %s class instance.",
      v61.V.pStringNode->pData,
      v61.V.FunctionValue.pLocalFrame->vfptr);
    v51 = v61.V.pStringNode;
    v52 = v61.V.pStringNode->RefCount-- == 1;
    if ( v52 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v51);
    v53 = (Scaleform::GFx::ASStringNode *)v61.V.FunctionValue.pLocalFrame;
    v52 = v61.V.FunctionValue.pLocalFrame->RefCount-- == 1;
    if ( v52 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v53);
    v19 = 0i64;
  }
  if ( v63.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v63);
  if ( (v24 & 2) == 0 )
  {
    v54 = Function->RefCount;
    if ( (v54 & 0x3FFFFFF) != 0 )
    {
      Function->RefCount = v54 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
  }
  *(_QWORD *)&result.T.Type = 0i64;
  if ( (v24 & 1) == 0 )
  {
    if ( v6 )
    {
      v55 = v6->RefCount;
      if ( (v55 & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = v55 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
      }
    }
  }
  result.V.pStringNode = 0i64;
  if ( v62.T.Type >= 5u )
  {
    v20 = &v62;
    goto LABEL_95;
  }
LABEL_96:
  if ( v8 )
  {
    v56 = v8->RefCount;
    if ( (v56 & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = v56 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v19;
}

// File Line: 6798
// RVA: 0x707A90
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Object *ppackageObj,
        Scaleform::GFx::ASString *className,
        int nargs,
        int argsTopOff)
{
  Scaleform::GFx::AS2::FunctionRef *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rbx
  char Flags; // dl
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+40h] [rbp-28h] BYREF

  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))ppackageObj->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember)(
         &ppackageObj->Scaleform::GFx::AS2::ObjectInterface,
         this,
         className,
         &v16,
         -2i64)
    && (v16.T.Type == 8 || v16.T.Type == 11) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToFunction(&v16, &result, this);
    v8 = Scaleform::GFx::AS2::Environment::OperatorNew(this, v7, nargs, argsTopOff);
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      Function = result.Function;
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v13 = result.pLocalFrame->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  return v8;
}

// File Line: 6814
// RVA: 0x6EEE30
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Environment::GetConstructor(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASBuiltinType className)
{
  Scaleform::GFx::AS2::Value v6; // [rsp+30h] [rbp-28h] BYREF

  v6.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, _DWORD, __int64))this->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw)(
         &this->StringContext.pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &this->StringContext,
         &this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion + 8 * className,
         &v6,
         0,
         -2i64)
    && (v6.T.Type == 8 || v6.T.Type == 11) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v6, result, this);
  }
  else
  {
    result->Flags = 0;
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
  }
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  return result;
}

// File Line: 6827
// RVA: 0x708B10
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *result,
        unsigned int index)
{
  Scaleform::GFx::AS2::Value *v5; // r9
  unsigned __int64 Size; // r8
  signed __int64 v7; // r10
  unsigned int v8; // edx
  int Type; // eax
  int v10; // r9d
  Scaleform::GFx::ASStringNode *v11; // rdi
  unsigned int RefCount; // eax

  v5 = 0i64;
  Size = this->Stack.Pages.Data.Size;
  v7 = this->Stack.pCurrent - this->Stack.pPageStart;
  v8 = v7 + 32 * (Size - 1);
  if ( index <= v8 )
    v5 = &this->Stack.Pages.Data.Data[(v8 - index) >> 5]->Values[(v8 - index) & 0x1F];
  Type = (unsigned __int8)v5->T.Type;
  if ( Type == 2 )
  {
    v10 = 5;
  }
  else if ( Type == 5 )
  {
    v10 = 3;
  }
  else
  {
    if ( (unsigned __int8)(Type - 3) > 1u )
    {
      result->T.Type = 0;
      return result;
    }
    v10 = 4;
  }
  v11 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                          this,
                                          this->StringContext.pContext->pGlobal.pObject,
                                          (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
                                        + v10,
                                          1,
                                          v7 + 32 * Size - 32 - index);
  Scaleform::GFx::AS2::Value::Value(result, v11);
  if ( v11 )
  {
    RefCount = v11->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v11->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11);
    }
  }
  return result;
}

// File Line: 6851
// RVA: 0x7089B0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Value *v)
{
  int Type; // eax
  int v7; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::ASStringNode *v10; // rsi
  Scaleform::GFx::AS2::Value *v11; // rcx
  unsigned int RefCount; // eax

  Type = (unsigned __int8)v->T.Type;
  if ( Type == 2 )
  {
    v7 = 5;
  }
  else if ( Type == 5 )
  {
    v7 = 3;
  }
  else
  {
    if ( (unsigned __int8)(Type - 3) > 1u )
    {
      result->T.Type = 0;
      return result;
    }
    v7 = 4;
  }
  if ( ++this->Stack.pCurrent >= this->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
  pCurrent = this->Stack.pCurrent;
  if ( pCurrent )
    Scaleform::GFx::AS2::Value::Value(pCurrent, v);
  v10 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                          this,
                                          this->StringContext.pContext->pGlobal.pObject,
                                          (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
                                        + v7,
                                          1,
                                          this->Stack.pCurrent
                                        - this->Stack.pPageStart
                                        + 32 * this->Stack.Pages.Data.Size
                                        - 32);
  v11 = this->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  if ( --this->Stack.pCurrent < this->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&this->Stack);
  Scaleform::GFx::AS2::Value::Value(result, v10);
  if ( v10 )
  {
    RefCount = v10->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  return result;
}

// File Line: 6923
// RVA: 0x6C0790
void __fastcall Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::LocalFrame *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *p_Variables; // r8
  unsigned __int64 v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rcx
  signed __int64 v9; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v10; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  char EntryCount; // al
  unsigned __int64 v13; // rdx
  int v14; // eax
  unsigned int v15; // eax
  unsigned __int64 v16; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v17; // rax
  Scaleform::GFx::AS2::LocalFrame *pObject; // rdx
  unsigned int v19; // eax
  unsigned int v20; // eax
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *v21; // [rsp+20h] [rbp-18h]

  p_Variables = &this->Variables;
  v4 = 0i64;
  pTable = this->Variables.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v4;
      v8 += 3;
    }
    while ( v4 <= SizeMask );
    v21 = p_Variables;
  }
  else
  {
    v21 = 0i64;
  }
  v9 = v4;
  while ( v21 )
  {
    v10 = v21->mHash.pTable;
    if ( !v21->mHash.pTable || v9 > (signed __int64)v10->SizeMask )
      break;
    v11 = &v10[3 * v9];
    EntryCount = v11[2].EntryCount;
    if ( EntryCount == 8 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v11[2].SizeMask,
        prcc);
      goto LABEL_20;
    }
    if ( EntryCount != 6 || (v13 = v11[2].SizeMask) == 0 )
    {
      if ( EntryCount != 9 )
        goto LABEL_20;
      v13 = v11[2].SizeMask;
    }
    v14 = ++*(_DWORD *)(v13 + 24);
    if ( (v14 & 0x70000000) != 0 )
    {
      v15 = v14 & 0x8FFFFFFF;
      *(_DWORD *)(v13 + 24) = v15;
      if ( (v15 & 0x8000000) != 0 )
      {
        *(_QWORD *)(*(_QWORD *)(v13 + 16) + 8i64) = *(_QWORD *)(v13 + 8);
        *(_QWORD *)(*(_QWORD *)(v13 + 8) + 16i64) = *(_QWORD *)(v13 + 16);
        *(_QWORD *)(v13 + 16) = *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0;
        *(_QWORD *)(v13 + 8) = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = v13;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v13;
      }
    }
LABEL_20:
    v16 = v21->mHash.pTable->SizeMask;
    if ( v9 <= (__int64)v16 && ++v9 <= v16 )
    {
      v17 = &v21->mHash.pTable[3 * v9 + 1];
      do
      {
        if ( v17->EntryCount != -2i64 )
          break;
        ++v9;
        v17 += 3;
      }
      while ( v9 <= v16 );
    }
  }
  pObject = this->PrevFrame.pObject;
  if ( pObject )
  {
    v19 = ++pObject->RefCount;
    if ( (v19 & 0x70000000) != 0 )
    {
      v20 = v19 & 0x8FFFFFFF;
      pObject->RefCount = v20;
      if ( (v20 & 0x8000000) != 0 )
      {
        pObject->pPrev->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::LocalFrame>::Scaleform::GFx::AS2::RefCountBaseGC<323>::pRCC = pObject->pRCC;
        *(_QWORD *)pObject->pRCC->Roots.gap0 = pObject->pPrev;
        pObject->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        pObject->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
      }
    }
  }
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Callee,
    prcc);
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Caller,
    prcc);
}

// File Line: 6939
// RVA: 0x6E89A0
void __fastcall Scaleform::GFx::AS2::LocalFrame::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::LocalFrame *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  int v3; // r8d

  if ( operation )
  {
    v3 = operation - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}

// File Line: 6944
// RVA: 0x6E9C30
void __fastcall Scaleform::GFx::AS2::LocalFrame::Finalize_GC(Scaleform::GFx::AS2::LocalFrame *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&this->Variables.mHash);
}

