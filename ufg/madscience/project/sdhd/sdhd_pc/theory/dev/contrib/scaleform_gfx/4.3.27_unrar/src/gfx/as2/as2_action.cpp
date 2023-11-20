// File Line: 134
// RVA: 0x6C6CE0
void __fastcall Scaleform::GFx::AS2::ActionLogger::ActionLogger(Scaleform::GFx::AS2::ActionLogger *this, Scaleform::GFx::DisplayObject *ptarget, const char *suffixStr)
{
  const char *v3; // rbp
  Scaleform::GFx::AS2::ActionLogger *v4; // rbx
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::GFx::MovieImpl *v6; // rdi
  __int64 v7; // rax
  const char *v8; // rsi
  const char *v9; // rax
  signed __int64 v10; // rsi
  int v11; // ecx
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  signed __int64 v15; // rax
  const char *v16; // rdx
  char v17; // cl

  v3 = suffixStr;
  v4 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::AS2::ActionLogger::`vftable';
  v5 = Scaleform::GFx::DisplayObjectBase::FindMovieImpl((Scaleform::GFx::DisplayObjectBase *)&ptarget->vfptr);
  v6 = v5;
  v4->VerboseAction = (v5->Flags >> 2) & 1;
  v4->VerboseActionErrors = ~(unsigned __int8)(v5->Flags >> 6) & 1;
  v4->LogSuffix = v3;
  if ( v3 )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v5->vfptr[1].__vecDelDtor)(v5);
    v8 = v4->LogSuffix;
    v9 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 96i64))(v7);
    v10 = v8 - v9;
    do
    {
      v11 = (unsigned __int8)v9[v10];
      v12 = *(unsigned __int8 *)v9 - v11;
      if ( *(unsigned __int8 *)v9 != v11 )
        break;
      ++v9;
    }
    while ( v11 );
    v13 = v6->Flags;
    if ( v12 )
      v14 = v13 >> 4;
    else
      v14 = v13 >> 3;
    v4->UseSuffix = v14 & 1;
  }
  else
  {
    v4->UseSuffix = 0;
  }
  v4->pLog = Scaleform::GFx::MovieImpl::GetCachedLog(v6);
  if ( v4->UseSuffix )
  {
    if ( !((v6->Flags >> 5) & 1) )
    {
      v15 = -1i64;
      do
        ++v15;
      while ( v3[v15] );
      if ( v15 > 0 )
      {
        v16 = v4->LogSuffix;
        while ( 1 )
        {
          v17 = v16[v15];
          if ( v17 == 47 || v17 == 92 )
            break;
          if ( --v15 <= 0 )
            return;
        }
        v4->LogSuffix = &v16[v15 + 1];
      }
    }
  }
}

// File Line: 193
// RVA: 0x7024C0
void Scaleform::GFx::AS2::ActionLogger::LogScriptError(Scaleform::GFx::AS2::ActionLogger *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::ActionLogger *v2; // rbx
  Scaleform::Log *v3; // rcx
  unsigned __int64 v4; // rax
  const char *v5; // r8
  int v6; // [rsp+20h] [rbp-558h]
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-550h]
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-540h]
  __int64 v9; // [rsp+50h] [rbp-528h]
  char v10; // [rsp+60h] [rbp-518h]
  Scaleform::MsgFormat v11; // [rsp+160h] [rbp-418h]
  va_list va; // [rsp+590h] [rbp+18h]

  va_start(va, pfmt);
  v9 = -2i64;
  v2 = this;
  v3 = this->pLog;
  if ( v3 )
  {
    if ( v2->UseSuffix )
    {
      v4 = -1i64;
      do
        ++v4;
      while ( pfmt[v4] );
      if ( pfmt[v4 - 1] == 10 )
        --v4;
      r.Type = 2;
      r.SinkData.pStr = (Scaleform::String *)&v10;
      r.SinkData.DataPtr.Size = 256i64;
      v.pStr = pfmt;
      v.Size = v4;
      Scaleform::MsgFormat::MsgFormat(&v11, &r);
      Scaleform::MsgFormat::Parse(&v11, "{0} : {1}\n");
      Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v11, &v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v11, &v2->LogSuffix);
      Scaleform::MsgFormat::FinishFormatD(&v11);
      Scaleform::MsgFormat::~MsgFormat(&v11);
      v3 = v2->pLog;
      v5 = &v10;
    }
    else
    {
      v5 = pfmt;
    }
    v6 = 212992;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD, const char *, unsigned __int64))v3->vfptr[1].__vecDelDtor)(
      v3,
      &v6,
      v5,
      (__int64 *)va,
      *(_QWORD *)&v6,
      v.pStr,
      v.Size);
  }
}

// File Line: 200
// RVA: 0x702920
void Scaleform::GFx::AS2::ActionLogger::LogScriptWarning(Scaleform::GFx::AS2::ActionLogger *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::ActionLogger *v2; // rbx
  Scaleform::Log *v3; // rcx
  unsigned __int64 v4; // rax
  const char *v5; // r8
  int v6; // [rsp+20h] [rbp-558h]
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-550h]
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-540h]
  __int64 v9; // [rsp+50h] [rbp-528h]
  char v10; // [rsp+60h] [rbp-518h]
  Scaleform::MsgFormat v11; // [rsp+160h] [rbp-418h]
  va_list va; // [rsp+590h] [rbp+18h]

  va_start(va, pfmt);
  v9 = -2i64;
  v2 = this;
  v3 = this->pLog;
  if ( v3 )
  {
    if ( v2->UseSuffix )
    {
      v4 = -1i64;
      do
        ++v4;
      while ( pfmt[v4] );
      if ( pfmt[v4 - 1] == 10 )
        --v4;
      r.Type = 2;
      r.SinkData.pStr = (Scaleform::String *)&v10;
      r.SinkData.DataPtr.Size = 256i64;
      v.pStr = pfmt;
      v.Size = v4;
      Scaleform::MsgFormat::MsgFormat(&v11, &r);
      Scaleform::MsgFormat::Parse(&v11, "{0} : {1}\n");
      Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v11, &v);
      Scaleform::MsgFormat::FormatD1<char const *>(&v11, &v2->LogSuffix);
      Scaleform::MsgFormat::FinishFormatD(&v11);
      Scaleform::MsgFormat::~MsgFormat(&v11);
      v3 = v2->pLog;
      v5 = &v10;
    }
    else
    {
      v5 = pfmt;
    }
    v6 = 147456;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD, const char *, unsigned __int64))v3->vfptr[1].__vecDelDtor)(
      v3,
      &v6,
      v5,
      (__int64 *)va,
      *(_QWORD *)&v6,
      v.pStr,
      v.Size);
  }
}

// File Line: 239
// RVA: 0x6ECCA0
__int64 __fastcall Scaleform::GFx::AS2::GAS_Invoke(Scaleform::GFx::AS2::Value *method, Scaleform::GFx::AS2::Value *presult, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Environment *penv, int nargs, int firstArgBottomIndex, const char *pmethodName)
{
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v8; // rsi
  Scaleform::GFx::AS2::Value *v9; // rbx
  char v10; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  unsigned __int8 v15; // bl
  char v16; // al
  Scaleform::GFx::AS2::FunctionObject *v17; // rcx
  unsigned int v18; // edx
  Scaleform::GFx::AS2::LocalFrame *v19; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-58h]
  void **v23; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::AS2::Value *v24; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::ObjectInterface *v25; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // [rsp+60h] [rbp-20h]
  char v28; // [rsp+68h] [rbp-18h]
  Scaleform::GFx::AS2::Environment *v29; // [rsp+70h] [rbp-10h]
  int v30; // [rsp+78h] [rbp-8h]
  int v31; // [rsp+7Ch] [rbp-4h]

  v7 = penv;
  v8 = pthis;
  v9 = presult;
  Scaleform::GFx::AS2::Value::ToFunction(method, &result, penv);
  if ( v9 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->T.Type = 0;
  }
  if ( result.Function )
  {
    v23 = &Scaleform::GFx::AS2::FnCall::`vftable';
    v24 = v9;
    v25 = v8;
    v28 = 0;
    v26 = 0i64;
    v27 = 0i64;
    v29 = v7;
    v30 = nargs;
    v31 = firstArgBottomIndex;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, const char *, signed __int64))result.Function->vfptr[3].Finalize_GC)(
      result.Function,
      &v23,
      result.pLocalFrame,
      pmethodName,
      -2i64);
    v23 = &Scaleform::GFx::AS2::FnCall::`vftable';
    v10 = v28;
    if ( !(v28 & 2) )
    {
      v11 = v26;
      if ( v26 )
      {
        v12 = v26->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          v26->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          v10 = v28;
        }
      }
    }
    v26 = 0i64;
    if ( !(v10 & 1) )
    {
      v13 = v27;
      if ( v27 )
      {
        v14 = v27->RefCount;
        if ( v14 & 0x3FFFFFF )
        {
          v27->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
        }
      }
    }
    v27 = 0i64;
    v23 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
  v16 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v17 = result.Function;
    if ( result.Function )
    {
      v18 = result.Function->RefCount;
      if ( v18 & 0x3FFFFFF )
      {
        result.Function->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
        v16 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v16 & 1) )
  {
    v19 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v20 = result.pLocalFrame->RefCount;
      if ( v20 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
      }
    }
  }
  return v15;
}

// File Line: 309
// RVA: 0x6ED500
char __fastcall Scaleform::GFx::AS2::GAS_InvokeParsed(const char *pmethodName, Scaleform::GFx::AS2::Value *presult, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // r15
  const char *v7; // rsi
  Scaleform::GFx::ASString *v8; // rax
  bool v9; // r14
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  char v12; // bl
  char *v13; // rcx
  __int64 v14; // rax
  char v15; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  int v17; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  int v19; // eax
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-49h]
  Scaleform::GFx::InteractiveObject **ppnewTarget; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::Value *powner; // [rsp+28h] [rbp-39h]
  unsigned int excludeFlags[2]; // [rsp+30h] [rbp-31h]
  char v25; // [rsp+38h] [rbp-29h]
  Scaleform::GFx::AS2::Value v26; // [rsp+40h] [rbp-21h]
  Scaleform::GFx::AS2::Value presulta; // [rsp+60h] [rbp-1h]
  Scaleform::GFx::InteractiveObject *v28; // [rsp+B8h] [rbp+57h]
  Scaleform::GFx::InteractiveObject **retaddr; // [rsp+D8h] [rbp+77h]
  Scaleform::GFx::AS2::Value *v30; // [rsp+E0h] [rbp+7Fh]

  ppnewTarget = (Scaleform::GFx::InteractiveObject **)-2i64;
  v4 = penv;
  v5 = pthis;
  v6 = presult;
  v7 = pmethodName;
  if ( !pmethodName || !*pmethodName )
    return 0;
  v28 = 0i64;
  presulta.T.Type = 0;
  v26.T.Type = 0;
  v8 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, pmethodName);
  v9 = Scaleform::GFx::AS2::Environment::GetVariable(v4, v8, &presulta, 0i64, &v28, &v26, 0) == 0;
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v9 )
  {
    v12 = 0;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToFunction(&presulta, (Scaleform::GFx::AS2::FunctionRef *)&powner, v4);
    if ( powner )
    {
      if ( (unsigned __int8)(v26.T.Type - 6) <= 1u )
      {
        v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v26, v4);
      }
      else if ( v28 )
      {
        v13 = (char *)v28 + 4 * (unsigned __int8)v28->AvmObjOffset;
        v14 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
        if ( v14 )
          v5 = (Scaleform::GFx::AS2::ObjectInterface *)(v14 + 8);
        else
          v5 = 0i64;
      }
      *(_QWORD *)excludeFlags = v7;
      powner = v30;
      ppnewTarget = retaddr;
      v12 = Scaleform::GFx::AS2::GAS_InvokeParsed(&presulta, v6, v5, v4);
    }
    else
    {
      v12 = 0;
    }
    v15 = v25;
    if ( !(v25 & 2) )
    {
      v16 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)powner;
      if ( powner )
      {
        v17 = *((_DWORD *)&powner->NV + 6);
        if ( v17 & 0x3FFFFFF )
        {
          *((_DWORD *)&powner->NV + 6) = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          v15 = v25;
        }
      }
    }
    powner = 0i64;
    if ( !(v15 & 1) )
    {
      v18 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)excludeFlags;
      if ( *(_QWORD *)excludeFlags )
      {
        v19 = *(_DWORD *)(*(_QWORD *)excludeFlags + 24i64);
        if ( v19 & 0x3FFFFFF )
        {
          *(_DWORD *)(*(_QWORD *)excludeFlags + 24i64) = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
        }
      }
    }
    *(_QWORD *)excludeFlags = 0i64;
  }
  if ( v26.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v26);
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v12;
}

// File Line: 358
// RVA: 0x6ED000
__int64 __fastcall Scaleform::GFx::AS2::GAS_InvokeParsed(Scaleform::GFx::AS2::Value *method, Scaleform::GFx::AS2::Value *presult, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v4; // r13
  __int64 v5; // rdi
  char *v6; // r15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v7; // rbx
  __int64 v8; // rax
  int v9; // edx
  char v10; // cl
  char *v11; // rdi
  const char **v12; // r14
  signed __int64 v13; // rsi
  char *v14; // r12
  char v15; // al
  __int64 v16; // rcx
  int v17; // eax
  char v18; // si
  Scaleform::GFx::AS2::Value *v19; // rcx
  Scaleform::GFx::AS2::Value *v20; // rax
  bool v21; // si
  Scaleform::GFx::AS2::Value *v22; // rax
  const char *v23; // xmm6_8
  __int64 v24; // rax
  char v25; // al
  const char *v26; // xmm6_8
  __int64 v27; // rax
  Scaleform::GFx::ASString *v28; // rsi
  __int64 v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  char v32; // al
  Scaleform::GFx::ASString *v33; // rsi
  __int64 v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rax
  bool v36; // zf
  unsigned __int8 i; // al
  signed int v38; // eax
  unsigned int v39; // er14
  unsigned int v40; // er15
  __int64 v41; // r13
  Scaleform::GFx::AS2::Value *v42; // r12
  unsigned __int64 v43; // r9
  __int64 v44; // r8
  Scaleform::GFx::AS2::Value *v45; // rsi
  unsigned __int8 j; // si
  Scaleform::GFx::AS2::Value *v47; // rcx
  Scaleform::GFx::ASString result; // [rsp+0h] [rbp-61h]
  Scaleform::GFx::ASString v50; // [rsp+8h] [rbp-59h]
  __int64 v51; // [rsp+10h] [rbp-51h]
  Scaleform::GFx::AS2::Value *v52; // [rsp+18h] [rbp-49h]
  int nargs[2]; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-39h]
  Scaleform::GFx::AS2::Value *methoda; // [rsp+B0h] [rbp+4Fh]
  Scaleform::GFx::AS2::Value *presulta; // [rsp+B8h] [rbp+57h]
  Scaleform::GFx::AS2::ObjectInterface *pthisa; // [rsp+C0h] [rbp+5Fh]
  Scaleform::GFx::AS2::Environment *v58; // [rsp+C8h] [rbp+67h]
  char *v59; // [rsp+D0h] [rbp+6Fh]
  __int64 v60; // [rsp+D8h] [rbp+77h]
  char *vars0; // [rsp+E0h] [rbp+7Fh]

  v51 = -2i64;
  v4 = penv;
  LODWORD(v5) = 0;
  v6 = v59;
  if ( v59 )
  {
    v7 = &penv->Stack;
    v8 = (_QWORD)((char *)penv->Stack.pCurrent - (char *)penv->Stack.pPageStart) >> 5;
    v9 = v8 + 32 * penv->Stack.Pages.Data.Size - 32;
    LODWORD(v59) = v8 + 32 * penv->Stack.Pages.Data.Size - 32;
    v10 = *v6;
    v11 = v6 + 1;
    if ( *v6 )
    {
      v12 = (const char **)(v60 - 8);
      v13 = 17596481012224i64;
      v14 = vars0;
      while ( 1 )
      {
        if ( v10 == 37 )
        {
          v15 = *v11++;
          switch ( v15 )
          {
            case 100:
              ++v12;
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v16 = (__int64)v7->pCurrent;
              v52 = (Scaleform::GFx::AS2::Value *)v16;
              *(_QWORD *)nargs = v16;
              if ( v16 )
              {
                v17 = *(_DWORD *)v12;
                *(_BYTE *)v16 = 4;
                *(_DWORD *)(v16 + 8) = v17;
              }
              break;
            case 117:
              v18 = 0;
              v.T.Type = 0;
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v19 = v7->pCurrent;
              *(_QWORD *)nargs = v19;
              v52 = v19;
              if ( v19 )
              {
                Scaleform::GFx::AS2::Value::Value(v19, &v, (__int64)v11);
                v18 = v.T.Type;
              }
              if ( (unsigned __int8)v18 >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v);
LABEL_62:
              v13 = 17596481012224i64;
              break;
            case 110:
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v20 = v7->pCurrent;
              *(_QWORD *)nargs = v20;
              v52 = v20;
              if ( v20 )
                v20->T.Type = 1;
              break;
            case 98:
              ++v12;
              v21 = *(_DWORD *)v12 != 0;
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v22 = v7->pCurrent;
              *(_QWORD *)nargs = v22;
              v52 = v22;
              if ( v22 )
              {
                v22->T.Type = 2;
                v22->V.BooleanValue = v21;
              }
              goto LABEL_62;
            case 102:
              ++v12;
              v23 = *v12;
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v24 = (__int64)v7->pCurrent;
              *(_QWORD *)nargs = v24;
              v52 = (Scaleform::GFx::AS2::Value *)v24;
              if ( v24 )
              {
                *(_BYTE *)v24 = 3;
                *(_QWORD *)(v24 + 8) = v23;
              }
              break;
            case 104:
              v25 = *v11++;
              if ( v25 == 102 )
              {
                ++v12;
                v26 = *v12;
                ++v7->pCurrent;
                if ( v7->pCurrent >= v7->pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
                v27 = (__int64)v7->pCurrent;
                *(_QWORD *)nargs = v27;
                v52 = (Scaleform::GFx::AS2::Value *)v27;
                if ( v27 )
                {
                  *(_BYTE *)v27 = 3;
                  *(_QWORD *)(v27 + 8) = v26;
                }
              }
              else
              {
                nargs[0] = v25;
                Scaleform::GFx::AS2::Environment::LogScriptError(
                  v4,
                  "InvokeParsed('%s','%s') - invalid format '%%h%c'",
                  v14,
                  v6,
                  *(_QWORD *)nargs);
              }
              break;
            case 115:
              ++v12;
              v28 = Scaleform::GFx::AS2::Environment::CreateString(v4, &result, *v12);
              ++v7->pCurrent;
              if ( v7->pCurrent >= v7->pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
              v29 = (__int64)v7->pCurrent;
              *(_QWORD *)nargs = v29;
              v52 = (Scaleform::GFx::AS2::Value *)v29;
              if ( v29 )
              {
                *(_BYTE *)v29 = 5;
                v30 = v28->pNode;
                *(Scaleform::GFx::ASString *)(v29 + 8) = (Scaleform::GFx::ASString)v28->pNode;
                ++v30->RefCount;
              }
              v31 = result.pNode;
LABEL_60:
              v36 = v31->RefCount-- == 1;
              if ( v36 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v31);
              goto LABEL_62;
            case 108:
              v32 = *v11++;
              if ( v32 == 115 )
              {
                ++v12;
                v33 = Scaleform::GFx::AS2::Environment::CreateString(v4, &v50, (const wchar_t *)*v12);
                ++v7->pCurrent;
                if ( v7->pCurrent >= v7->pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v7);
                v34 = (__int64)v7->pCurrent;
                *(_QWORD *)nargs = v34;
                v52 = (Scaleform::GFx::AS2::Value *)v34;
                if ( v34 )
                {
                  *(_BYTE *)v34 = 5;
                  v35 = v33->pNode;
                  *(Scaleform::GFx::ASString *)(v34 + 8) = (Scaleform::GFx::ASString)v33->pNode;
                  ++v35->RefCount;
                }
                v31 = v50.pNode;
                goto LABEL_60;
              }
              nargs[0] = v32;
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v4,
                "InvokeParsed('%s','%s') - invalid format '%%l%c'",
                v14,
                v6,
                *(_QWORD *)nargs);
              break;
            default:
              nargs[0] = v15;
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v4,
                "InvokeParsed('%s','%s') - invalid format '%%%c'",
                v14,
                v6,
                *(_QWORD *)nargs);
              break;
          }
        }
        else
        {
          nargs[0] = v10;
          Scaleform::GFx::AS2::Environment::LogScriptError(
            v4,
            "InvokeParsed('%s','%s') - invalid char '%c'",
            v14,
            v6,
            *(_QWORD *)nargs);
        }
        for ( i = *v11; *v11; i = *++v11 )
        {
          if ( i > 0x2Cu )
            break;
          if ( !_bittest64(&v13, (char)i) )
            break;
        }
        v10 = *v11++;
        if ( !v10 )
        {
          v9 = (signed int)v59;
          break;
        }
      }
    }
    v5 = 32 * (unsigned int)v7->Pages.Data.Size
       + (unsigned int)((_QWORD)((char *)v7->pCurrent - (char *)v7->pPageStart) >> 5)
       - v9
       - 32;
    v38 = (signed int)(32 * v7->Pages.Data.Size
                     + ((_QWORD)((char *)v7->pCurrent - (char *)v7->pPageStart) >> 5)
                     - v9
                     - 32) >> 1;
    if ( v38 > 0 )
    {
      v39 = v9 + 1;
      v40 = 32 * v7->Pages.Data.Size + ((_QWORD)((char *)v7->pCurrent - (char *)v7->pPageStart) >> 5) - 32;
      v41 = (unsigned int)v38;
      do
      {
        v42 = 0i64;
        v43 = v7->Pages.Data.Size;
        v44 = (_QWORD)((char *)v7->pCurrent - (char *)v7->pPageStart) >> 5;
        if ( v40 <= (signed int)v44 + 32 * ((signed int)v43 - 1) )
          v42 = &v7->Pages.Data.Data[v40 >> 5]->Values[v40 & 0x1F];
        v45 = 0i64;
        if ( v39 <= (signed int)v44 + 32 * ((signed int)v43 - 1) )
          v45 = &v7->Pages.Data.Data[v39 >> 5]->Values[v39 & 0x1F];
        Scaleform::GFx::AS2::Value::Value(&v, v45, v5);
        Scaleform::GFx::AS2::Value::operator=(v45, v42, v5);
        Scaleform::GFx::AS2::Value::operator=(v42, &v, v5);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        ++v39;
        --v40;
        --v41;
      }
      while ( v41 );
      v4 = v58;
    }
  }
  for ( j = Scaleform::GFx::AS2::GAS_Invoke(
              methoda,
              presulta,
              pthisa,
              v4,
              v5,
              32 * LODWORD(v4->Stack.Pages.Data.Size)
            - 32
            + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5),
              vars0); (_DWORD)v5; LODWORD(v5) = v5 - 1 )
  {
    v47 = v4->Stack.pCurrent;
    if ( v47->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v47);
    --v4->Stack.pCurrent;
    if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
  }
  return j;
}

// File Line: 489
// RVA: 0x6ECE30
char __fastcall Scaleform::GFx::AS2::GAS_Invoke(const char *pmethodName, Scaleform::GFx::AS2::Value *presult, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // r15
  const char *v7; // rsi
  Scaleform::GFx::ASString *v8; // rax
  bool v9; // r14
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  char v12; // bl
  char *v13; // rcx
  __int64 v14; // rax
  char v15; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  int v17; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  int v19; // eax
  Scaleform::GFx::ASString result; // [rsp+18h] [rbp-49h]
  Scaleform::GFx::InteractiveObject **ppnewTarget; // [rsp+20h] [rbp-41h]
  Scaleform::GFx::AS2::Value *powner; // [rsp+28h] [rbp-39h]
  unsigned int excludeFlags[2]; // [rsp+30h] [rbp-31h]
  char v25; // [rsp+38h] [rbp-29h]
  Scaleform::GFx::AS2::Value v26; // [rsp+40h] [rbp-21h]
  Scaleform::GFx::AS2::Value presulta; // [rsp+60h] [rbp-1h]
  Scaleform::GFx::InteractiveObject *v28; // [rsp+B8h] [rbp+57h]
  void *retaddr; // [rsp+D8h] [rbp+77h]
  int v30; // [rsp+E0h] [rbp+7Fh]

  ppnewTarget = (Scaleform::GFx::InteractiveObject **)-2i64;
  v4 = penv;
  v5 = pthis;
  v6 = presult;
  v7 = pmethodName;
  if ( !pmethodName || !*pmethodName )
    return 0;
  v28 = 0i64;
  presulta.T.Type = 0;
  v26.T.Type = 0;
  v8 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, pmethodName);
  v9 = Scaleform::GFx::AS2::Environment::GetVariable(v4, v8, &presulta, 0i64, &v28, &v26, 0) == 0;
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v9 )
  {
    v12 = 0;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToFunction(&presulta, (Scaleform::GFx::AS2::FunctionRef *)&powner, v4);
    if ( powner )
    {
      if ( (unsigned __int8)(v26.T.Type - 6) <= 1u )
      {
        v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v26, v4);
      }
      else if ( v28 )
      {
        v13 = (char *)v28 + 4 * (unsigned __int8)v28->AvmObjOffset;
        v14 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
        if ( v14 )
          v5 = (Scaleform::GFx::AS2::ObjectInterface *)(v14 + 8);
        else
          v5 = 0i64;
      }
      v12 = Scaleform::GFx::AS2::GAS_Invoke(&presulta, v6, v5, v4, (int)retaddr, v30, v7);
    }
    else
    {
      v12 = 0;
    }
    v15 = v25;
    if ( !(v25 & 2) )
    {
      v16 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)powner;
      if ( powner )
      {
        v17 = *((_DWORD *)&powner->NV + 6);
        if ( v17 & 0x3FFFFFF )
        {
          *((_DWORD *)&powner->NV + 6) = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          v15 = v25;
        }
      }
    }
    powner = 0i64;
    if ( !(v15 & 1) )
    {
      v18 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)excludeFlags;
      if ( *(_QWORD *)excludeFlags )
      {
        v19 = *(_DWORD *)(*(_QWORD *)excludeFlags + 24i64);
        if ( v19 & 0x3FFFFFF )
        {
          *(_DWORD *)(*(_QWORD *)excludeFlags + 24i64) = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
        }
      }
    }
    *(_QWORD *)excludeFlags = 0i64;
  }
  if ( v26.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v26);
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v12;
}

// File Line: 540
// RVA: 0x6B4B50
void __fastcall Scaleform::GFx::AS2::GAS_GlobalTrace(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er10
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  unsigned int v10; // er9
  Scaleform::GFx::AS2::Environment *v11; // r8
  unsigned __int64 v12; // rdi
  char *i; // rax
  const char *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS2::Value method; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS2::Value presult; // [rsp+60h] [rbp-A0h]
  __int64 v18; // [rsp+80h] [rbp-80h]
  char _Dst[2016]; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::ASString v20; // [rsp+880h] [rbp+780h]
  Scaleform::GFx::ASString result; // [rsp+888h] [rbp+788h]

  v18 = -2i64;
  v1 = fn;
  v2 = fn->FirstArgBottomIndex;
  v3 = fn->Env;
  v4 = 0i64;
  v5 = 0i64;
  if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v5 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, v3);
  v7 = v6;
  if ( v6 )
  {
    method.T.Type = 0;
    if ( v6->vfptr->GetMemberRaw(
           v6,
           &v1->Env->StringContext,
           (Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25],
           &method)
      && (method.T.Type == 8 || method.T.Type == 11) )
    {
      presult.T.Type = 0;
      Scaleform::GFx::AS2::GAS_Invoke(
        &method,
        &presult,
        v7,
        v1->Env,
        0,
        32 * v1->Env->Stack.Pages.Data.Size
      - 31
      + ((_QWORD)((char *)v1->Env->Stack.pCurrent - (char *)v1->Env->Stack.pPageStart) >> 5),
        0i64);
      Scaleform::GFx::AS2::Value::ToString(&presult, &result, v1->Env, -1);
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *)&v1->vfptr,
        "%s\n",
        result.pNode->pData);
      v8 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v8->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      if ( presult.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&presult);
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
      return;
    }
    if ( method.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&method);
  }
  v10 = v1->FirstArgBottomIndex;
  v11 = v1->Env;
  if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
            + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
    v4 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v4, &v20, v11, -1);
  v12 = v20.pNode->Size;
  if ( v20.pNode->Size >= 0x7D0 )
    v12 = 1999i64;
  strncpy_s(_Dst, 0x7D0ui64, v20.pNode->pData, v12);
  _Dst[v12] = 0;
  for ( i = _Dst; *i; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  v14 = "%s\n";
  if ( v20.pNode->Size >= 0x7D0 )
    v14 = "%s ...<truncated>\n";
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptMessage(
    (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *)&v1->vfptr,
    v14,
    _Dst);
  v15 = v20.pNode;
  v9 = v20.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 584
// RVA: 0x6B5450
void __fastcall Scaleform::GFx::AS2::GAS_GlobalParseInt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  int v2; // esi
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASStringNode *v6; // rax
  unsigned int v7; // ebx
  unsigned int v8; // er10
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
  bool v20; // zf
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  char *endptr; // [rsp+68h] [rbp+10h]

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = 10;
    v3 = fn->FirstArgBottomIndex;
    v4 = fn->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    v6 = result.pNode;
    v7 = 0;
    if ( v1->NArgs < 2 )
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
      v8 = v1->FirstArgBottomIndex - 1;
      v9 = v1->Env;
      v10 = 0i64;
      if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
        v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
      v2 = Scaleform::GFx::AS2::Value::ToInt32(v10, v9);
      if ( (unsigned int)(v2 - 2) > 0x22 )
      {
        v11 = Scaleform::GFx::NumberUtil::NaN();
        v12 = v1->Result;
        if ( v12->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v12->T.Type = 3;
        v12->NV.NumberValue = v11;
LABEL_23:
        v19 = result.pNode;
        v20 = result.pNode->RefCount == 1;
        --v19->RefCount;
        if ( v20 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        return;
      }
      v6 = result.pNode;
    }
    v14 = v7;
    v15 = (char *)&v6->pData[v7];
    endptr = 0i64;
    v16 = strtol(&v6->pData[v14], &endptr, v2);
    if ( v15 != endptr || v2 == 8 )
    {
      v18 = v1->Result;
      if ( v18->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
      v18->T.Type = 4;
      v18->NV.Int32Value = v16;
    }
    else
    {
      v17 = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v17);
    }
    goto LABEL_23;
  }
}

// File Line: 645
// RVA: 0x6B7640
void __fastcall Scaleform::GFx::AS2::GAS_GlobalParseFloat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  char *v5; // rbx
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char *tailptr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
    v5 = (char *)result.pNode->pData;
    tailptr = 0i64;
    v6 = Scaleform::SFstrtod(result.pNode->pData, &tailptr);
    if ( v5 == tailptr )
      v6 = Scaleform::GFx::NumberUtil::NaN();
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 658
// RVA: 0x6B7720
void __fastcall Scaleform::GFx::AS2::GAS_GlobalIfFrameLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  void *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  int v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v2->T.Type = 2;
    v2->V.BooleanValue = 0;
    v3 = v1->ThisPtr;
    if ( v3 )
    {
      if ( (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() != 2 )
        return;
      v4 = v1->ThisPtr;
    }
    else
    {
      v4 = v1->Env->Target;
    }
    if ( v4 )
    {
      v5 = v1->Env;
      v6 = (unsigned int)v1->FirstArgBottomIndex;
      v7 = 0i64;
      if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
        v7 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToInt32(v7, v5);
      if ( v8 < (*(signed int (__fastcall **)(void *))(*(_QWORD *)v4 + 888i64))(v4) )
      {
        v9 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rdx
  unsigned __int64 v4; // r8
  char v5; // di
  Scaleform::GFx::AS2::Value *v6; // r9
  long double v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v3 = fn->Env;
    v4 = (unsigned int)fn->FirstArgBottomIndex;
    v5 = 0;
    v6 = 0i64;
    if ( (unsigned int)v4 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v6 = &v3->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToNumber(v6, v3);
    if ( (*(_QWORD *)&v7 & 0x7FF0000000000000i64) == 9218868437227405312i64 )
    {
      if ( *(_QWORD *)&v7 & 0xFFFFFFFFFFFFFi64 )
        v5 = 1;
    }
    v8 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->V.BooleanValue = v5;
    v8->T.Type = 2;
  }
  else
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v2->V.BooleanValue = 1;
    v2->T.Type = 2;
  }
}

// File Line: 691
// RVA: 0x6B7E10
void __fastcall Scaleform::GFx::AS2::GAS_GlobalIsFinite(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rdx
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r9
  double v6; // xmm0_8
  double v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v3 = fn->Env;
    v4 = (unsigned int)fn->FirstArgBottomIndex;
    v5 = 0i64;
    if ( (unsigned int)v4 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v3);
    v7 = v6;
    if ( ((*(_QWORD *)&v6 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v7 & 0xFFFFFFFFFFFFFi64))
      && v6 != -1.797693134862316e308/*-Inf*/
      && v6 != 1.797693134862316e308/*+Inf*/ )
    {
      v8 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v8);
      v8->V.BooleanValue = 1;
      v8->T.Type = 2;
      return;
    }
    v2 = v1->Result;
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
  Scaleform::GFx::AS2::FnCall *v1; // r13
  Scaleform::GFx::AS2::Environment *v2; // r9
  int v3; // er14
  unsigned int v4; // er10
  __int64 v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // r15
  unsigned int v8; // er8
  Scaleform::GFx::AS2::Environment *v9; // r9
  Scaleform::GFx::AS2::Value *v10; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rbx
  char v12; // al
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *v14; // rax
  Scaleform::GFx::AS2::ArrayObject *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  unsigned int v19; // er9
  Scaleform::GFx::AS2::Environment *v20; // rdx
  Scaleform::GFx::AS2::Value *v21; // r10
  Scaleform::GFx::AS2::Object *v22; // rax
  __int64 v23; // r14
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // rcx
  unsigned int v29; // er9
  Scaleform::GFx::AS2::Environment *v30; // rdx
  Scaleform::GFx::AS2::Value *v31; // r10
  int v32; // eax
  char v33; // si
  unsigned int v34; // er9
  Scaleform::GFx::AS2::Environment *v35; // rdx
  Scaleform::GFx::AS2::Value *v36; // r10
  char v37; // si
  Scaleform::GFx::AS2::LocalFrame *v38; // r14
  __int64 v39; // r12
  Scaleform::GFx::AS2::Value *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // rcx
  unsigned int v42; // eax
  Scaleform::GFx::AS2::Value v43; // [rsp+38h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> v44; // [rsp+B0h] [rbp+48h]
  __int64 v45; // [rsp+B8h] [rbp+50h]
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+58h]
  Scaleform::GFx::ASString v47; // [rsp+C8h] [rbp+60h]

  v1 = fn;
  v2 = fn->Env;
  v3 = (unsigned __int8)v2->StringContext.SWFVersion;
  LODWORD(v44.pObject) = (unsigned __int8)v2->StringContext.SWFVersion;
  v4 = fn->FirstArgBottomIndex;
  v5 = 0i64;
  v6 = 0i64;
  if ( v4 <= 32 * ((unsigned int)v2->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
    v6 = &v2->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
  v7 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObjectInterface(v6, v2);
  if ( v7 )
  {
    v8 = v1->FirstArgBottomIndex - 1;
    v9 = v1->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v11 = 0i64;
    v45 = 0i64;
    v12 = v10->T.Type;
    if ( v10->T.Type == 5 )
    {
      v13 = Scaleform::GFx::AS2::Value::ToString(v10, &result, v1->Env, -1);
      v14 = Scaleform::GFx::AS2::StringProto::StringSplit(&v44, v1->Env, v13, ",", 0x3FFFFFFF);
      if ( v14->pObject )
        v14->pObject->RefCount = (v14->pObject->RefCount + 1) & 0x8FFFFFFF;
      v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->pObject->vfptr;
      v45 = (__int64)v14->pObject;
      v15 = v44.pObject;
      if ( v44.pObject )
      {
        v16 = v44.pObject->RefCount;
        if ( v16 & 0x3FFFFFF )
        {
          v44.pObject->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
        }
      }
      v17 = result.pNode;
      v18 = result.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      goto LABEL_31;
    }
    if ( v12 == 6 )
    {
      v19 = v1->FirstArgBottomIndex - 1;
      v20 = v1->Env;
      v21 = 0i64;
      if ( v19 <= 32 * ((unsigned int)v20->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v20->Stack.pCurrent - (char *)v20->Stack.pPageStart) >> 5) )
        v21 = &v20->Stack.Pages.Data.Data[v19 >> 5]->Values[v19 & 0x1F];
      v22 = Scaleform::GFx::AS2::Value::ToObject(v21, v20);
      v23 = (__int64)v22;
      if ( !v22 )
        goto LABEL_30;
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v22->vfptr->gap8[8])(&v22->vfptr) == 7 )
      {
        *(_DWORD *)(v23 + 24) = (*(_DWORD *)(v23 + 24) + 1) & 0x8FFFFFFF;
        v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v23;
        v45 = v23;
LABEL_30:
        v3 = (int)v44.pObject;
LABEL_31:
        v29 = v1->FirstArgBottomIndex - 2;
        v30 = v1->Env;
        v31 = 0i64;
        if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v30->Stack.pCurrent - (char *)v30->Stack.pPageStart) >> 5) )
          v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
        v32 = Scaleform::GFx::AS2::Value::ToInt32(v31, v30);
        LOBYTE(v32) = v32 & 7;
        LODWORD(v44.pObject) = v32;
        if ( v1->NArgs == 3 )
        {
          v33 = 0;
          if ( v3 == 5 )
            v33 = -1;
        }
        else
        {
          v34 = v1->FirstArgBottomIndex - 3;
          v35 = v1->Env;
          v36 = 0i64;
          if ( v34 <= 32 * ((unsigned int)v35->Stack.Pages.Data.Size - 1)
                    + (unsigned int)((_QWORD)((char *)v35->Stack.pCurrent - (char *)v35->Stack.pPageStart) >> 5) )
            v36 = &v35->Stack.Pages.Data.Data[v34 >> 5]->Values[v34 & 0x1F];
          v33 = Scaleform::GFx::AS2::Value::ToUInt32(v36, v35);
          LOBYTE(v32) = v44.pObject;
        }
        v37 = v33 & 7;
        v38 = (Scaleform::GFx::AS2::LocalFrame *)&v1->Env->StringContext;
        if ( v11 )
        {
          v39 = (signed int)v11[3].RootIndex;
          if ( v39 > 0 )
          {
            do
            {
              v40 = (Scaleform::GFx::AS2::Value *)(&v11[3].pRCC->vfptr)[v5];
              if ( v40 )
              {
                Scaleform::GFx::AS2::Value::ToString(v40, &result, v1->Env, -1);
                v43.T = 0;
                if ( (*((unsigned __int8 (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::LocalFrame *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v7->pData
                      + 5))(
                       v7,
                       v38,
                       &result,
                       &v43) )
                {
                  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::LocalFrame *, Scaleform::GFx::ASString *, _QWORD))v7->pData
                   + 7))(
                    v7,
                    v38,
                    &result,
                    (unsigned __int8)(LOBYTE(v44.pObject) | v43.T.PropFlags & ~v37));
                }
                if ( v43.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v43);
                v41 = result.pNode;
                v18 = result.pNode->RefCount == 1;
                --v41->RefCount;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v41);
              }
              ++v5;
            }
            while ( v5 < v39 );
          }
        }
        else
        {
          *(_QWORD *)&v43.T.Type = `Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags'::`27'::MemberVisitor::`vftable';
          v43.V.pStringNode = v7;
          v43.V.FunctionValue.pLocalFrame = v38;
          v43.V.FunctionValue.Flags = v32;
          *((_BYTE *)&v43.NV + 25) = v37;
          (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::LocalFrame *, Scaleform::GFx::AS2::Value *, signed __int64, _QWORD))v7->pData
           + 8))(
            v7,
            v38,
            &v43,
            12i64,
            0i64);
          *(_QWORD *)&v43.T.Type = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
        }
        goto LABEL_51;
      }
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)(v23 + 32) + 16i64))(v23 + 32) == 8 )
      {
        v24 = Scaleform::GFx::AS2::Value::ToString(v10, &v47, v1->Env, -1);
        v25 = Scaleform::GFx::AS2::StringProto::StringSplit(
                (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&result,
                v1->Env,
                v24,
                ",",
                0x3FFFFFFF);
        if ( v25->pObject )
          v25->pObject->RefCount = (v25->pObject->RefCount + 1) & 0x8FFFFFFF;
        v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->pObject->vfptr;
        v45 = (__int64)v25->pObject;
        v26 = result.pNode;
        if ( result.pNode )
        {
          v27 = result.pNode->RefCount;
          if ( v27 & 0x3FFFFFF )
          {
            result.pNode->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v26);
          }
        }
        v28 = v47.pNode;
        v18 = v47.pNode->RefCount == 1;
        --v28->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
        goto LABEL_30;
      }
    }
    else if ( v12 == 1 )
    {
      goto LABEL_31;
    }
LABEL_51:
    if ( v11 )
    {
      v42 = v11->RefCount;
      if ( v42 & 0x3FFFFFF )
      {
        v11->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
}

// File Line: 778
// RVA: 0x723970
void __fastcall Scaleform::GFx::AS2::GAS_GlobalASSetPropFlags_::_27_::MemberVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *__formal, char flags, char a4)
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
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::Environment *v6; // rcx
  Scaleform::GFx::AS2::Value *v7; // rdi
  unsigned int v8; // esi
  unsigned int v9; // ebx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v4 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, v2);
    v6 = v1->Env;
    v7 = v1->Result;
    v8 = v5;
    v9 = v6->Target->pASRoot->pMovieImpl->mMouseState[0].CurButtonsState;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 2;
    v7->V.BooleanValue = (v8 & v9) == v8;
  }
}

// File Line: 821
// RVA: 0x6BB390
void __fastcall Scaleform::GFx::AS2::GAS_GlobalASnative(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er10
  Scaleform::GFx::AS2::Environment *v4; // rdx
  Scaleform::GFx::AS2::Value *v5; // r9
  unsigned int v6; // ebx
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // r11
  Scaleform::GFx::AS2::Value *v9; // r9
  unsigned int v10; // eax
  __int64 v11; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v12; // rax
  Scaleform::GFx::AS2::FunctionObject *v13; // rax
  Scaleform::GFx::AS2::FunctionObject *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::FunctionRefBase func; // [rsp+28h] [rbp-20h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs >= 2 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v4);
    v7 = v1->FirstArgBottomIndex - 1;
    v8 = v1->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v1->Env);
    if ( v6 == 800 && v10 == 2 )
    {
      v12 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                      v11,
                                                      104i64);
      if ( v12 )
      {
        Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
          v12,
          &v1->Env->StringContext,
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
      Scaleform::GFx::AS2::Value::SetAsFunction(v1->Result, &func);
      if ( v14 )
      {
        v15 = v14->RefCount;
        if ( v15 & 0x3FFFFFF )
        {
          v14->RefCount = v15 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
        }
      }
      func.Function = 0i64;
      func.pLocalFrame = 0i64;
      if ( v14 )
      {
        v16 = v14->RefCount;
        if ( v16 & 0x3FFFFFF )
        {
          v14->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
        }
      }
    }
  }
}

// File Line: 837
// RVA: 0x6A6A00
void __fastcall Scaleform::GFx::AS2::GAS_GlobalEscape(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::String pescapedStr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString v14; // [rsp+60h] [rbp+18h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs == 1 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    Scaleform::String::String(&pescapedStr);
    Scaleform::GFx::ASUtils::Escape(result.pNode->pData, result.pNode->Size, &pescapedStr);
    v6 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v14, &pescapedStr);
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    v8 = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++v8->RefCount;
    v9 = v14.pNode;
    v10 = v14.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v11 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
}

// File Line: 848
// RVA: 0x6A6B20
void __fastcall Scaleform::GFx::AS2::GAS_GlobalUnescape(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString v14; // [rsp+60h] [rbp+18h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs == 1 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    Scaleform::String::String(&punescapedStr);
    Scaleform::GFx::ASUtils::Unescape(result.pNode->pData, result.pNode->Size, &punescapedStr);
    v6 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v14, &punescapedStr);
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    v8 = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++v8->RefCount;
    v9 = v14.pNode;
    v10 = v14.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v11 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
}

// File Line: 861
// RVA: 0x6A6C40
void __fastcall Scaleform::GFx::AS2::GAS_GlobalEscapeSpecialHTML(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  const char *v6; // rdi
  unsigned int v7; // eax
  Scaleform::GFx::ASString *v8; // r14
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::String pescapedStr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString v16; // [rsp+60h] [rbp+18h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs == 1 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    Scaleform::String::String(&pescapedStr);
    v6 = result.pNode->pData;
    v7 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
    Scaleform::String::EscapeSpecialHTML(v6, v7, &pescapedStr);
    v8 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v16, &pescapedStr);
    v9 = v1->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v9->T.Type = 5;
    v10 = v8->pNode;
    v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++v10->RefCount;
    v11 = v16.pNode;
    v12 = v16.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 873
// RVA: 0x6A6D70
void __fastcall Scaleform::GFx::AS2::GAS_GlobalUnescapeSpecialHTML(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r8
  Scaleform::GFx::AS2::Value *v5; // r10
  const char *v6; // rdi
  unsigned int v7; // eax
  Scaleform::GFx::ASString *v8; // r14
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString v16; // [rsp+60h] [rbp+18h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs == 1 )
  {
    v3 = v1->FirstArgBottomIndex;
    v4 = v1->Env;
    v5 = 0i64;
    if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
      v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v5, &result, v4, -1);
    Scaleform::String::String(&punescapedStr);
    v6 = result.pNode->pData;
    v7 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
    Scaleform::String::UnescapeSpecialHTML(v6, v7, &punescapedStr);
    v8 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v16, &punescapedStr);
    v9 = v1->Result;
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v9->T.Type = 5;
    v10 = v8->pNode;
    v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
    ++v10->RefCount;
    v11 = v16.pNode;
    v12 = v16.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 1083
// RVA: 0x6D9250
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::GlobalContext::AddPackage(Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pparent, Scaleform::GFx::AS2::Object *objProto, const char *const packageName)
{
  const char *v4; // r13
  Scaleform::GFx::AS2::Object *v5; // rdi
  signed __int64 v6; // r14
  const char *v7; // r12
  char *v8; // rax
  signed __int64 v9; // rsi
  unsigned __int64 v10; // rbx
  __int64 v11; // rcx
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Value *v16; // rax
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  unsigned int v20; // eax
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value v23; // [rsp+48h] [rbp-B8h]
  Scaleform::MemoryHeap *v24; // [rsp+68h] [rbp-98h]
  __int64 v25; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS2::Object *v26; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS2::Value v27; // [rsp+80h] [rbp-80h]
  char Dst; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS2::ASStringContext *psca; // [rsp+1F0h] [rbp+F0h]
  char v30; // [rsp+1F8h] [rbp+F8h]
  Scaleform::GFx::AS2::Object *proto; // [rsp+200h] [rbp+100h]
  Scaleform::GFx::ASString result; // [rsp+208h] [rbp+108h]

  proto = objProto;
  psca = psc;
  v25 = -2i64;
  v4 = packageName;
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
      v9 = (signed __int64)v8;
      if ( v8 )
      {
        v10 = v8 - v7 + 1;
        v9 = (signed __int64)(v8 + 1);
      }
      else
      {
        v10 = (unsigned __int64)&v4[v6 + 1 - (_QWORD)v7];
      }
      if ( v10 > 0x100 )
        v10 = 256i64;
      memmove(&Dst, v7, v10 - 1);
      *((_BYTE *)&v27.NV + v10 + 31) = 0;
      v7 = (const char *)v9;
      v23.T.Type = 0;
      Scaleform::GFx::AS2::ASStringContext::CreateString(psca, &result, &Dst);
      if ( v5->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr, psca, &result, &v23) )
      {
        v12 = Scaleform::GFx::AS2::Value::ToObject(&v23, 0i64);
        v13 = v12;
        if ( v12 )
          v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
      }
      else
      {
        v24 = psca->pContext->pHeap;
        v14 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(__int64, signed __int64))v24->vfptr->Alloc)(
                                               v11,
                                               96i64);
        v26 = v14;
        if ( v14 )
        {
          Scaleform::GFx::AS2::Object::Object(v14, psca, proto);
          v13 = v15;
        }
        else
        {
          v13 = 0i64;
        }
        Scaleform::GFx::AS2::Value::Value(&v27, v13);
        v30 = 0;
        v5->vfptr->SetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
          psca,
          &result,
          v16,
          (Scaleform::GFx::AS2::PropFlags *)&v30);
        if ( v27.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v27);
      }
      if ( v13 )
        v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
      v17 = v5->RefCount;
      if ( v17 & 0x3FFFFFF )
      {
        v5->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
      }
      v5 = v13;
      v18 = result.pNode;
      v19 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      if ( v13 )
      {
        v20 = v13->RefCount;
        if ( v20 & 0x3FFFFFF )
        {
          v13->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
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
    if ( v21 & 0x3FFFFFF )
    {
      v5->RefCount = v21 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
  return v5;
}

// File Line: 1132
// RVA: 0x6C8900
void __fastcall Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(Scaleform::GFx::AS2::GASGlobalObject *this, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rdi
  Scaleform::GFx::AS2::GASGlobalObject *v3; // rbx
  Scaleform::GFx::MovieImpl *v4; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v5; // rdx

  v2 = pgc;
  v3 = this;
  v4 = pgc->pMovieRoot;
  if ( v4 )
    v5 = (Scaleform::GFx::AS2::ASRefCountCollector *)v4->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v5 = 0i64;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, v5);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->pGC = v2;
}

// File Line: 1138
// RVA: 0x6F38F0
bool __fastcall Scaleform::GFx::AS2::GASGlobalObject::GetMemberRaw(Scaleform::GFx::AS2::GASGlobalObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  char v5; // cl
  bool v6; // bl
  bool result; // al

  v4 = val;
  if ( name->pNode != (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[22].vfptr )
    return Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&this->vfptr, psc, name, val);
  v5 = this->ResolveHandler.pLocalFrame->Caller.T.Type;
  if ( v5 )
  {
    v6 = v5 == 1;
    Scaleform::GFx::AS2::Value::DropRefs(val);
    v4->V.BooleanValue = v6;
    v4->T.Type = 2;
    result = 1;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(val);
    v4->T.Type = 0;
    result = 0;
  }
  return result;
}

// File Line: 1153
// RVA: 0x717610
bool __fastcall Scaleform::GFx::AS2::GASGlobalObject::SetMember(Scaleform::GFx::AS2::GASGlobalObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // rbp
  Scaleform::GFx::ASString *v6; // r15
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::AS2::GASGlobalObject *v8; // rsi
  Scaleform::GFx::ASMovieRootBase *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rdx
  Scaleform::GFx::AS2::GlobalContext *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // bl
  bool v19; // al
  Scaleform::GFx::MovieImpl *v20; // rbx
  Scaleform::GFx::MovieImpl *v21; // rbx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-58h]
  __int64 v23; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS2::Value vala; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::ASString v25; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::ASString v26; // [rsp+A0h] [rbp+18h]

  v23 = -2i64;
  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  v9 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  v10 = name->pNode;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)v9[22].vfptr )
  {
    v8->ResolveHandler.pLocalFrame->Caller.T.Type = (Scaleform::GFx::AS2::Value::ToBool(val, v7) == 0) + 1;
    v11 = (Scaleform::GFx::AS2::GlobalContext *)v8->ResolveHandler.pLocalFrame;
    if ( v11->GFxExtensions.Value == 1 )
    {
      v12 = Scaleform::GFx::AS2::GlobalContext::CreateConstString(v11, &result, "4.3.27");
      vala.T.Type = 5;
      vala.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v12->pNode;
      ++vala.V.pStringNode->RefCount;
      v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v7->StringContext, &v26, "gfxVersion");
      LOBYTE(v25.pNode) = 0;
      ((void (__fastcall *)(Scaleform::GFx::AS2::GASGlobalObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString *))v8->vfptr[3].Finalize_GC)(
        v8,
        &v7->StringContext,
        v13,
        &vala,
        &v25);
      v14 = v26.pNode;
      v15 = v26.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( vala.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&vala);
      v16 = result.pNode;
    }
    else
    {
      v17 = Scaleform::GFx::AS2::GlobalContext::CreateConstString(v11, &v25, "gfxVersion");
      v8->vfptr[2].ExecuteForEachChild_GC(
        (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr,
        (Scaleform::GFx::AS2::RefCountCollector<323> *)&v7->StringContext,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v17);
      v16 = v25.pNode;
    }
    v15 = v16->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    vala.T.Type = 10;
    v18 = Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, &vala, flags);
    if ( vala.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&vala);
    v19 = v18;
  }
  else
  {
    if ( v8->ResolveHandler.pLocalFrame->Caller.T.Type == 1 )
    {
      if ( v10 == *(Scaleform::GFx::ASStringNode **)&v9[22].RefCount )
      {
        v20 = v7->Target->pASRoot->pMovieImpl;
        if ( v20 )
        {
          if ( Scaleform::GFx::AS2::Value::ToBool(val, v7) )
            v20->Flags |= 0x800u;
          else
            v20->Flags &= 0xFFFFF7FF;
        }
      }
      else if ( v10 == (Scaleform::GFx::ASStringNode *)v9[22].pMovieImpl )
      {
        v21 = v7->Target->pASRoot->pMovieImpl;
        if ( v21 )
        {
          if ( Scaleform::GFx::AS2::Value::ToBool(val, v7) )
            v21->Flags |= 0x2000u;
          else
            v21->Flags &= 0xFFFFDFFF;
        }
      }
    }
    v19 = Scaleform::GFx::AS2::Object::SetMemberRaw(
            (Scaleform::GFx::AS2::Object *)&v8->vfptr,
            &v7->StringContext,
            v6,
            v5,
            flags);
  }
  return v19;
}

// File Line: 1224
// RVA: 0x6C90F0
void __fastcall Scaleform::GFx::AS2::GlobalContext::GlobalContext(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::MovieImpl *proot)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::AS2::GlobalContext,323>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable';
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
void __fastcall Scaleform::GFx::AS2::GlobalContext::Init(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::MovieImpl *v2; // r13
  Scaleform::GFx::AS2::GlobalContext *v3; // rdi
  Scaleform::MemoryHeap *v4; // rcx
  Scaleform::GFx::AS2::GASGlobalObject *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::FunctionObject *v11; // r12
  Scaleform::GFx::AS2::Object *v12; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // r15
  Scaleform::GFx::AS2::Object *v17; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rsi
  signed __int64 v22; // rbx
  Scaleform::GFx::AS2::Object *v23; // rax
  Scaleform::GFx::AS2::Object *v24; // rsi
  signed __int64 v25; // rbx
  signed __int64 v26; // rsi
  unsigned __int64 v27; // r9
  signed __int64 v28; // rcx
  unsigned __int64 v29; // r9
  signed __int64 v30; // rcx
  Scaleform::GFx::AS2::Object *v31; // rax
  Scaleform::GFx::AS2::Object *v32; // r14
  Scaleform::GFx::AS2::Object *v33; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::MovieImpl *v36; // rax
  Scaleform::GFx::AS2::FunctionObject *v37; // rax
  Scaleform::GFx::AS2::FunctionObject *v38; // rbx
  Scaleform::GFx::AS2::ASBuiltinType *v39; // rax
  Scaleform::GFx::AS2::ASBuiltinType *v40; // r13
  Scaleform::GFx::AS2::Object *v41; // rbx
  _QWORD *v42; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v43; // rcx
  unsigned int v44; // eax
  signed __int64 v45; // rbx
  unsigned __int64 v46; // r9
  signed __int64 v47; // rcx
  Scaleform::GFx::MovieImpl *v48; // rax
  signed __int64 v49; // rdx
  unsigned __int64 v50; // rax
  Scaleform::GFx::AS2::Object *v51; // rax
  Scaleform::GFx::AS2::ObjectInterface *v52; // rcx
  signed __int64 v53; // rcx
  signed __int64 v54; // rcx
  signed __int64 v55; // rcx
  signed __int64 v56; // rcx
  Scaleform::GFx::AS2::Object *v57; // rax
  Scaleform::GFx::AS2::Object *v58; // rax
  Scaleform::GFx::AS2::Object *v59; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v60; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v61; // rcx
  unsigned int v62; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v63; // rcx
  unsigned int v64; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v65; // rcx
  unsigned int v66; // eax
  unsigned int v67; // eax
  unsigned int v68; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v69; // rcx
  unsigned int v70; // eax
  Scaleform::GFx::AS2::Object *v71; // rcx
  unsigned int v72; // eax
  unsigned int v73; // eax
  unsigned int v74; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+30h] [rbp-D0h]
  Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef key; // [rsp+40h] [rbp-C0h]
  __int64 v77; // [rsp+50h] [rbp-B0h]
  char v78; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v79; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v80; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::Value v81; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v82; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v83; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS2::Value v85; // [rsp+B8h] [rbp-48h]
  void **v86; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v87; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS2::ASStringContext *v88; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS2::FunctionRef v89; // [rsp+F0h] [rbp-10h]
  __int64 v90; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS2::Value v91; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::MovieImpl *proota; // [rsp+188h] [rbp+88h]
  __int64 flags; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::AS2::Object *proto; // [rsp+198h] [rbp+98h]

  proota = proot;
  v90 = -2i64;
  v2 = proot;
  v3 = this;
  this->pMovieRoot = proot;
  v4 = proot->pHeap;
  v3->pHeap = v4;
  psc.pContext = v3;
  psc.SWFVersion = 8;
  if ( !v3->pGlobal.pObject )
  {
    v5 = (Scaleform::GFx::AS2::GASGlobalObject *)v4->vfptr->Alloc(v4, 104ui64, 0i64);
    flags = (__int64)v5;
    if ( v5 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v5, v3);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->pGlobal.pObject->vfptr;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v3->pGlobal.pObject = v7;
  }
  v10 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                                         v3->pHeap,
                                         104i64);
  v11 = (Scaleform::GFx::AS2::FunctionObject *)v10;
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr;
  if ( v10 )
  {
    Scaleform::GFx::AS2::Object::Object(v10, &psc);
    v11->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v11->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v11->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v11->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v11[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::ObjectProto::GlobalCtor;
    v12 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v11->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v81.T.Type = 10;
      v11->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v11->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v81,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v81.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v81);
    }
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
    v13 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->pProto.pObject->vfptr;
    if ( v13 )
    {
      v14 = v13->RefCount;
      if ( v14 & 0x3FFFFFF )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
    v11->pProto.pObject = v12;
    v11->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v11->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v11->vfptr,
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
  v15 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                                         v3->pHeap,
                                         104i64);
  v16 = v15;
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr;
  if ( v15 )
  {
    Scaleform::GFx::AS2::Object::Object(v15, &psc);
    v16->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v16->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v16->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v16->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v16[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::FunctionProto::GlobalCtor;
    v17 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v16->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v81.T.Type = 10;
      v16->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v16->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v81,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v81.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v81);
    }
    if ( v17 )
      v17->RefCount = (v17->RefCount + 1) & 0x8FFFFFFF;
    v18 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->pProto.pObject->vfptr;
    if ( v18 )
    {
      v19 = v18->RefCount;
      if ( v19 & 0x3FFFFFF )
      {
        v18->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
    v16->pProto.pObject = v17;
    v16->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v16->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v16 = 0i64;
  }
  *((_BYTE *)&v81.NV + 16) = 0;
  *(_OWORD *)&v81.T.Type = (unsigned __int64)v16;
  v20 = (Scaleform::GFx::AS2::Object *)v3->pHeap->vfptr->Alloc(v3->pHeap, 160ui64, 0i64);
  v21 = v20;
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr;
  if ( v20 )
  {
    Scaleform::GFx::AS2::Object::Object(v20, &psc);
    v22 = (signed __int64)&v21[1];
    flags = v22;
    *(_QWORD *)v22 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v22 + 24) = 0;
    *(_QWORD *)(v22 + 8) = 0i64;
    *(_QWORD *)(v22 + 16) = 0i64;
    LOBYTE(v21[1].Members.mHash.pTable) = 0;
    v21[1].vfptr = 0i64;
    v21[1].pProto.pObject = 0i64;
    v21[1].ResolveHandler.Function = 0i64;
    v21->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v21->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v22 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v21[1],
      v21,
      &psc,
      &constructor);
    v21->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v21->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v22 = &Scaleform::GFx::AS2::ObjectProto::`vftable';
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
  v23 = (Scaleform::GFx::AS2::Object *)v3->pHeap->vfptr->Alloc(v3->pHeap, 160ui64, 0i64);
  v24 = v23;
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr;
  if ( v23 )
  {
    Scaleform::GFx::AS2::Object::Object(v23, &psc, proto);
    v25 = (signed __int64)&v24[1];
    flags = v25;
    *(_QWORD *)v25 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v25 + 24) = 0;
    *(_QWORD *)(v25 + 8) = 0i64;
    *(_QWORD *)(v25 + 16) = 0i64;
    LOBYTE(v24[1].Members.mHash.pTable) = 0;
    v24[1].vfptr = 0i64;
    v24[1].pProto.pObject = 0i64;
    v24[1].ResolveHandler.Function = 0i64;
    v24->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v24->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v25 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v24[1],
      v24,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)&v81);
    v24->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v24->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v25 = &Scaleform::GFx::AS2::FunctionProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v24[1],
      v24,
      &psc,
      GAS_FunctionObjectTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v24 = 0i64;
  }
  v80 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v24->vfptr;
  v11->vfptr->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)&v11->vfptr, &psc, v24);
  v16->vfptr->Set__proto__(
    (Scaleform::GFx::AS2::ObjectInterface *)&v16->vfptr,
    &psc,
    (Scaleform::GFx::AS2::Object *)v80);
  LODWORD(flags) = 1;
  key.pFirst = (Scaleform::GFx::AS2::ASBuiltinType *)&flags;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&proto;
  v26 = 5381i64;
  v27 = 5381i64;
  v28 = 4i64;
  do
    v27 = *((unsigned __int8 *)&flags + --v28) + 65599 * v27;
  while ( v28 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v3->Prototypes.mHash.pTable,
    &v3->Prototypes,
    &key,
    v27);
  LODWORD(flags) = 7;
  key.pFirst = (Scaleform::GFx::AS2::ASBuiltinType *)&flags;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&v80;
  v29 = 5381i64;
  v30 = 4i64;
  do
    v29 = *((unsigned __int8 *)&flags + --v30) + 65599 * v29;
  while ( v30 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v3->Prototypes.mHash.pTable,
    &v3->Prototypes,
    &key,
    v29);
  v31 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                                         v3->pHeap,
                                         104i64);
  v32 = v31;
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v31->vfptr;
  if ( v31 )
  {
    Scaleform::GFx::AS2::Object::Object(v31, &psc);
    v32->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v32->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v32->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v32->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v32[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::MovieClipCtorFunction::GlobalCtor;
    v33 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v32->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v85.T.Type = 10;
      v32->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v32->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v85,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v85.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v85);
    }
    if ( v33 )
      v33->RefCount = (v33->RefCount + 1) & 0x8FFFFFFF;
    v34 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->pProto.pObject->vfptr;
    if ( v34 )
    {
      v35 = v34->RefCount;
      if ( v35 & 0x3FFFFFF )
      {
        v34->RefCount = v35 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
      }
    }
    v32->pProto.pObject = v33;
    v32->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v32->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v2 = proota;
  }
  else
  {
    v32 = 0i64;
  }
  *((_BYTE *)&v85.NV + 16) = 0;
  *(_OWORD *)&v85.T.Type = (unsigned __int64)v32;
  v36 = (Scaleform::GFx::MovieImpl *)v3->pHeap->vfptr->Alloc(v3->pHeap, 312ui64, 0i64);
  proota = v36;
  if ( v36 )
  {
    Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction((Scaleform::GFx::AS2::KeyCtorFunction *)v36, &psc, v2);
    v38 = v37;
  }
  else
  {
    v38 = 0i64;
  }
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v38->vfptr;
  v89.Flags = 0;
  v89.Function = v38;
  v89.pLocalFrame = 0i64;
  v39 = (Scaleform::GFx::AS2::ASBuiltinType *)v3->pHeap->vfptr->Alloc(v3->pHeap, 160ui64, 0i64);
  v40 = v39;
  key.pFirst = v39;
  if ( v39 )
  {
    v41 = proto;
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v39, &psc);
    *(_QWORD *)v40 = &Scaleform::GFx::AS2::KeyObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v42 = v40 + 8;
    *((_QWORD *)v40 + 4) = &Scaleform::GFx::AS2::KeyObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    if ( !*((_QWORD *)v40 + 5) )
    {
      LOBYTE(proota) = 3;
      v91.T.Type = 10;
      (*(void (__fastcall **)(Scaleform::GFx::AS2::ASBuiltinType *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::MovieImpl **))(*v42 + 80i64))(
        v40 + 8,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v91,
        &proota);
      if ( v91.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v91);
      v42 = v40 + 8;
    }
    if ( v41 )
      v41->RefCount = (v41->RefCount + 1) & 0x8FFFFFFF;
    v43 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v42[1];
    if ( v43 )
    {
      v44 = v43->RefCount;
      if ( v44 & 0x3FFFFFF )
      {
        v43->RefCount = v44 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v43);
        v42 = v40 + 8;
      }
    }
    v42[1] = v41;
    v45 = (signed __int64)(v40 + 24);
    flags = v45;
    *(_QWORD *)v45 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v45 + 24) = 0;
    *(_QWORD *)(v45 + 8) = 0i64;
    *(_QWORD *)(v45 + 16) = 0i64;
    *((_BYTE *)v40 + 144) = 0;
    *((_QWORD *)v40 + 16) = 0i64;
    *((_QWORD *)v40 + 17) = 0i64;
    *((_QWORD *)v40 + 19) = 0i64;
    *(_QWORD *)v40 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *v42 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v45 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v40 + 24),
      (Scaleform::GFx::AS2::Object *)v40,
      &psc,
      &v89);
    *(_QWORD *)v40 = &Scaleform::GFx::AS2::KeyProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *((_QWORD *)v40 + 4) = &Scaleform::GFx::AS2::KeyProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v45 = &Scaleform::GFx::AS2::KeyProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v40 + 24),
      (Scaleform::GFx::AS2::Object *)v40,
      &psc,
      GAS_KeyFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
    v38 = (Scaleform::GFx::AS2::FunctionObject *)v79;
  }
  else
  {
    v40 = 0i64;
  }
  v82 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v40;
  LODWORD(proota) = 26;
  key.pFirst = (Scaleform::GFx::AS2::ASBuiltinType *)&proota;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&v82;
  v46 = 5381i64;
  v47 = 4i64;
  do
    v46 = *((unsigned __int8 *)&proota + --v47) + 65599 * v46;
  while ( v47 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v3->Prototypes.mHash.pTable,
    &v3->Prototypes,
    &key,
    v46);
  v48 = (Scaleform::GFx::MovieImpl *)v3->pHeap->vfptr->Alloc(v3->pHeap, 176ui64, 0i64);
  proota = v48;
  if ( v48 )
    Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(
      (Scaleform::GFx::AS2::MovieClipProto *)v48,
      &psc,
      proto,
      (Scaleform::GFx::AS2::FunctionRef *)&v85);
  v83 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v48;
  LODWORD(proota) = 6;
  key.pFirst = (Scaleform::GFx::AS2::ASBuiltinType *)&proota;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&v83;
  v49 = 4i64;
  do
  {
    v50 = 65599 * v26 + *((unsigned __int8 *)&proota + --v49);
    v26 = 65599 * v26 + *((unsigned __int8 *)&proota + v49);
  }
  while ( v49 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v3->Prototypes.mHash.pTable,
    &v3->Prototypes,
    &key,
    v50);
  v51 = v3->pGlobal.pObject;
  v52 = (Scaleform::GFx::AS2::ObjectInterface *)&v51->vfptr;
  if ( !v51 )
    v52 = 0i64;
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    v52,
    &psc,
    Scaleform::GFx::AS2::GFxAction_Global_StaticFunctions,
    0);
  v53 = (signed __int64)&v3->pGlobal.pObject->vfptr;
  LOBYTE(key.pFirst) = 8;
  v78 = 0;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v11;
  v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
  v77 = 0i64;
  LOBYTE(proota) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *, Scaleform::GFx::MovieImpl **))(*(_QWORD *)v53 + 80i64))(
    v53,
    &psc,
    v3->pMovieRoot->pASMovieRoot.pObject + 8,
    &key,
    &proota);
  if ( LOBYTE(key.pFirst) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&key);
  v54 = (signed __int64)&v3->pGlobal.pObject->vfptr;
  LOBYTE(key.pFirst) = 8;
  v78 = 0;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v16;
  v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
  v77 = 0i64;
  LOBYTE(proota) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *, Scaleform::GFx::MovieImpl **))(*(_QWORD *)v54 + 80i64))(
    v54,
    &psc,
    &v3->pMovieRoot->pASMovieRoot.pObject[9].RefCount,
    &key,
    &proota);
  if ( LOBYTE(key.pFirst) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&key);
  v55 = (signed __int64)&v3->pGlobal.pObject->vfptr;
  LOBYTE(key.pFirst) = 8;
  v78 = 0;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v32;
  if ( v32 )
    v32->RefCount = (v32->RefCount + 1) & 0x8FFFFFFF;
  v77 = 0i64;
  LOBYTE(proota) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *, Scaleform::GFx::MovieImpl **))(*(_QWORD *)v55 + 80i64))(
    v55,
    &psc,
    v3->pMovieRoot->pASMovieRoot.pObject + 9,
    &key,
    &proota);
  if ( LOBYTE(key.pFirst) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&key);
  v56 = (signed __int64)&v3->pGlobal.pObject->vfptr;
  LOBYTE(key.pFirst) = 8;
  v78 = 0;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v38;
  if ( v38 )
    v38->RefCount = (v38->RefCount + 1) & 0x8FFFFFFF;
  v77 = 0i64;
  LOBYTE(proota) = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef *, Scaleform::GFx::MovieImpl **))(*(_QWORD *)v56 + 80i64))(
    v56,
    &psc,
    v3->pMovieRoot->pASMovieRoot.pObject + 13,
    &key,
    &proota);
  if ( LOBYTE(key.pFirst) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&key);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<25,Scaleform::GFx::AS2::MathCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<2,Scaleform::GFx::AS2::ArrayCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<4,Scaleform::GFx::AS2::NumberCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<3,Scaleform::GFx::AS2::StringCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<5,Scaleform::GFx::AS2::BooleanCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<9,Scaleform::GFx::AS2::ButtonCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<29,Scaleform::GFx::AS2::MovieClipLoaderCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<31,Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<18,Scaleform::GFx::AS2::StageCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<19,Scaleform::GFx::AS2::AsBroadcasterCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<27,Scaleform::GFx::AS2::MouseCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<10,Scaleform::GFx::AS2::TextFieldCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<32,Scaleform::GFx::AS2::TextFormatCtorFunction>(
    v3,
    &psc,
    v3->pGlobal.pObject);
  v57 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, v3->pGlobal.pObject, proto, "flash.geom");
  v3->FlashGeomPackage = v57;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<14,Scaleform::GFx::AS2::PointCtorFunction>(v3, &psc, v57);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<15,Scaleform::GFx::AS2::RectangleCtorFunction>(
    v3,
    &psc,
    v3->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<16,Scaleform::GFx::AS2::ColorTransformCtorFunction>(
    v3,
    &psc,
    v3->FlashGeomPackage);
  v58 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, v3->pGlobal.pObject, proto, "flash.external");
  v3->FlashExternalPackage = v58;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<28,Scaleform::GFx::AS2::ExternalInterfaceCtorFunction>(
    v3,
    &psc,
    v58);
  v59 = Scaleform::GFx::AS2::GlobalContext::AddPackage(&psc, v3->pGlobal.pObject, proto, "flash.display");
  v3->FlashDisplayPackage = v59;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<30,Scaleform::GFx::AS2::BitmapDataCtorFunction>(
    v3,
    &psc,
    v59);
  v3->FlashFiltersPackage = Scaleform::GFx::AS2::GlobalContext::AddPackage(
                              &psc,
                              v3->pGlobal.pObject,
                              proto,
                              "flash.filters");
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v3->StandardMemberMap);
  Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(v3);
  v60 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->pGlobal.pObject->vfptr;
  v86 = (void **)&`Scaleform::GFx::AS2::GlobalContext::Init'::`4'::MemberVisitor::`vftable';
  if ( v60 )
    v60->RefCount = (v60->RefCount + 1) & 0x8FFFFFFF;
  v87 = v60;
  v88 = &psc;
  v3->pGlobal.pObject->vfptr->VisitMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->pGlobal.pObject->vfptr,
    &psc,
    (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v86,
    4u,
    0i64);
  v61 = v87;
  if ( v87 )
  {
    v62 = v87->RefCount;
    if ( v62 & 0x3FFFFFF )
    {
      v87->RefCount = v62 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v61);
    }
  }
  v86 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
  v63 = v83;
  if ( v83 )
  {
    v64 = v83->RefCount;
    if ( v64 & 0x3FFFFFF )
    {
      v83->RefCount = v64 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v63);
    }
  }
  v65 = v82;
  if ( v82 )
  {
    v66 = v82->RefCount;
    if ( v66 & 0x3FFFFFF )
    {
      v82->RefCount = v66 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v65);
    }
  }
  if ( v38 )
  {
    v67 = v38->RefCount;
    if ( v67 & 0x3FFFFFF )
    {
      v38->RefCount = v67 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v38->vfptr);
    }
  }
  v89.Function = 0i64;
  v89.pLocalFrame = 0i64;
  if ( v32 )
  {
    v68 = v32->RefCount;
    if ( v68 & 0x3FFFFFF )
    {
      v32->RefCount = v68 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
    }
  }
  *(_OWORD *)&v85.T.Type = 0ui64;
  v69 = v80;
  if ( v80 )
  {
    v70 = v80->RefCount;
    if ( v70 & 0x3FFFFFF )
    {
      v80->RefCount = v70 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v69);
    }
  }
  v71 = proto;
  if ( proto )
  {
    v72 = proto->RefCount;
    if ( v72 & 0x3FFFFFF )
    {
      proto->RefCount = v72 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v71->vfptr);
    }
  }
  v73 = v16->RefCount;
  if ( v73 & 0x3FFFFFF )
  {
    v16->RefCount = v73 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
  }
  *(_OWORD *)&v81.T.Type = 0ui64;
  v74 = v11->RefCount;
  if ( v74 & 0x3FFFFFF )
  {
    v11->RefCount = v74 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
  }
}

// File Line: 1398
// RVA: 0x7237B0
void __fastcall Scaleform::GFx::AS2::GlobalContext::Init_::_4_::MemberVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, char flags, __int64 a4)
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
  Scaleform::GFx::AS2::GlobalContext *v1; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable';
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StandardMemberMap);
  v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->pGlobal.pObject->vfptr;
  if ( v2 )
  {
    v3 = v2->RefCount;
    if ( v3 & 0x3FFFFFF )
    {
      v2->RefCount = v3 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->BuiltinClassesRegistry.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->RegisteredClasses.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v1->Prototypes.mHash.pTable);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->vfptr);
}

// File Line: 1425
// RVA: 0x708770
void __fastcall Scaleform::GFx::AS2::GlobalContext::PreClean(Scaleform::GFx::AS2::GlobalContext *this, bool preserveBuiltinProps)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rdi
  Scaleform::GFx::AS2::GASGlobalObject *v3; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Object *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-19h]
  __int64 v16; // [rsp+38h] [rbp-11h]
  Scaleform::GFx::AS2::GASGlobalObject *v17; // [rsp+40h] [rbp-9h]
  Scaleform::GFx::AS2::ASStringContext v18; // [rsp+48h] [rbp-1h]
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp+Fh]
  char v20; // [rsp+B8h] [rbp+6Fh]
  Scaleform::GFx::ASString v21; // [rsp+C0h] [rbp+77h]
  Scaleform::GFx::ASString v22; // [rsp+C8h] [rbp+7Fh]

  v16 = -2i64;
  v2 = this;
  if ( preserveBuiltinProps )
  {
    v3 = (Scaleform::GFx::AS2::GASGlobalObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                                   this->pHeap,
                                                   104i64);
    v17 = v3;
    if ( v3 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v3, v2);
      v5 = v4;
    }
    else
    {
      v5 = 0i64;
    }
    v18.pContext = v2;
    v18.SWFVersion = 8;
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &result, "gfxPlayer");
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &v22, "gfxLanguage");
    Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v18, &v21, "gfxArg");
    v19.T.Type = 0;
    v2->pGlobal.pObject->vfptr->GetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v2->pGlobal.pObject->vfptr,
      &v18,
      &result,
      &v19);
    v20 = 0;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))v5[1].vfptr[3].Finalize_GC)(
      &v5[1],
      &v18,
      &result,
      &v19,
      &v20);
    v2->pGlobal.pObject->vfptr->GetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v2->pGlobal.pObject->vfptr,
      &v18,
      &v22,
      &v19);
    v20 = 0;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))v5[1].vfptr[3].Finalize_GC)(
      &v5[1],
      &v18,
      &v22,
      &v19,
      &v20);
    v2->pGlobal.pObject->vfptr->GetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v2->pGlobal.pObject->vfptr,
      &v18,
      &v21,
      &v19);
    v20 = 0;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))v5[1].vfptr[3].Finalize_GC)(
      &v5[1],
      &v18,
      &v21,
      &v19,
      &v20);
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pGlobal.pObject->vfptr;
    if ( v6 )
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    v2->pGlobal.pObject = (Scaleform::GFx::AS2::Object *)v5;
    if ( v19.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    v8 = v21.pNode;
    v9 = v21.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v10 = v22.pNode;
    v9 = v22.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v11 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = v5->RefCount;
    if ( v12 & 0x3FFFFFF )
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
      if ( v14 & 0x3FFFFFF )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
      }
    }
    v2->pGlobal.pObject = 0i64;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->RegisteredClasses.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->BuiltinClassesRegistry.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v2->Prototypes.mHash.pTable);
  v2->pMovieRoot = 0i64;
}

// File Line: 1452
// RVA: 0x711F40
Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *__fastcall Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::ASString *functionName)
{
  Scaleform::GFx::ASString *v2; // r15
  Scaleform::GFx::AS2::GlobalContext *v3; // r14
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *result; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v5; // rsi
  __int64 v6; // rax
  bool v7; // bp
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  __int64 v10; // rcx
  char v11; // al
  char v12; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // rcx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+28h] [rbp-70h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+30h] [rbp-68h]
  char v23; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // [rsp+40h] [rbp-58h]
  __int64 v25; // [rsp+48h] [rbp-50h]
  bool v26; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::ASString className; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+B0h] [rbp+18h]
  Scaleform::GFx::ASString *v29; // [rsp+B8h] [rbp+20h]

  v2 = functionName;
  v3 = this;
  className.pNode = (Scaleform::GFx::ASStringNode *)&v28;
  v28 = functionName->pNode;
  ++v28->RefCount;
  result = Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(this, (Scaleform::GFx::ASString)&v28);
  if ( result )
  {
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result->ResolvedFunc;
    if ( !result->ResolvedFunc.pObject )
    {
      v6 = result->RegistrarFunc(&v21, v3);
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
      if ( !(v23 & 2) )
      {
        v13 = v21;
        if ( v21 )
        {
          v14 = v21->RefCount;
          if ( v14 & 0x3FFFFFF )
          {
            v21->RefCount = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
            v12 = v23;
          }
        }
      }
      v21 = 0i64;
      if ( !(v12 & 1) )
      {
        v15 = v22;
        if ( v22 )
        {
          v16 = v22->RefCount;
          if ( v16 & 0x3FFFFFF )
          {
            v22->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
          }
        }
      }
      v22 = 0i64;
      v29 = &className;
      className.pNode = v2->pNode;
      ++className.pNode->RefCount;
      v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)&Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(
                                                           v3,
                                                           (Scaleform::GFx::ASString)&className)->ResolvedFunc;
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      v17 = *v5;
      if ( *v5 )
      {
        v18 = v17->RefCount;
        if ( v18 & 0x3FFFFFF )
        {
          v17->RefCount = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
      *v5 = v8;
      if ( !(v7 & 2) )
      {
        if ( v8 )
        {
          v19 = v8->RefCount;
          if ( v19 & 0x3FFFFFF )
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
        if ( v20 & 0x3FFFFFF )
        {
          v9->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      v25 = 0i64;
    }
    result = (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)*v5;
  }
  return result;
}

// File Line: 1475
// RVA: 0x6F4F50
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::GlobalContext::GetPrototype(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::AS2::ASBuiltinType type)
{
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> >::TableType *v2; // rsi
  __int64 v3; // r15
  Scaleform::GFx::AS2::GlobalContext *v4; // rbp
  signed __int64 v5; // rbx
  signed __int64 v6; // rdi
  signed __int64 v7; // r9
  signed __int64 v8; // r8
  __int64 v9; // rax
  signed __int64 v10; // rax
  signed __int64 v11; // rax
  signed __int64 v12; // rax
  Scaleform::GFx::AS2::Object **v13; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> >::TableType *v14; // rsi
  __int64 v15; // rax
  signed __int64 v16; // rax
  signed __int64 v17; // rax
  signed __int64 v18; // rax
  Scaleform::GFx::AS2::Object *result; // rax
  __int64 v20; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS2::ASBuiltinType key; // [rsp+48h] [rbp+10h]

  key = type;
  v2 = this->Prototypes.mHash.pTable;
  v3 = type;
  v4 = this;
  v5 = 5381i64;
  v6 = 4i64;
  if ( v2 )
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
    v11 = Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexCore<enum  Scaleform::GFx::AS2::ASBuiltinType>(
            (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&this->Prototypes.mHash.pTable,
            &key,
            v10 & v2->SizeMask);
    if ( v11 >= 0 )
    {
      v12 = (signed __int64)v2 + 8 * (3 * v11 + 3);
      if ( v12 )
      {
        v13 = (Scaleform::GFx::AS2::Object **)(v12 + 8);
        if ( v13 )
          goto LABEL_16;
      }
    }
  }
  Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
    v4,
    (Scaleform::GFx::ASString *)&(&v4->pMovieRoot->pASMovieRoot.pObject->vfptr)[v3 + 39]);
  v14 = v4->Prototypes.mHash.pTable;
  if ( !v14 )
    goto LABEL_17;
  do
  {
    v15 = *((unsigned __int8 *)&v20 + v6-- + 7);
    v16 = 65599 * v5 + v15;
    v5 = v16;
  }
  while ( v6 );
  v17 = Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexCore<enum  Scaleform::GFx::AS2::ASBuiltinType>(
          (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v4->Prototypes.mHash.pTable,
          &key,
          v16 & v14->SizeMask);
  if ( v17 >= 0
    && (v18 = (signed __int64)v14 + 8 * (3 * v17 + 3)) != 0
    && (v13 = (Scaleform::GFx::AS2::Object **)(v18 + 8)) != 0i64 )
  {
LABEL_16:
    result = *v13;
  }
  else
  {
LABEL_17:
    result = 0i64;
  }
  return result;
}

// File Line: 1486
// RVA: 0x6EE510
Scaleform::GFx::AS2::RefCountBaseGC<323> *__fastcall Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ASBuiltinType type)
{
  __int64 v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::GlobalContext *v5; // rbp
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rsi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  Scaleform::GFx::AS2::Value v16; // [rsp+28h] [rbp-40h]

  v3 = type;
  v4 = penv;
  v5 = this;
  v6 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this, type);
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, signed __int64))v5->pGlobal.pObject->vfptr->GetMemberRaw)(
         &v5->pGlobal.pObject->vfptr,
         &v4->StringContext,
         (char *)v5->pMovieRoot->pASMovieRoot.pObject + 8 * (v3 + 39),
         &v16,
         -2i64) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v16, v4);
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr;
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    if ( v8
      && v8->vfptr->GetMemberRaw(
           (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr,
           &v4->StringContext,
           (Scaleform::GFx::ASString *)&v5->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v16) )
    {
      v10 = Scaleform::GFx::AS2::Value::ToObject(&v16, v4);
      v11 = v10;
      if ( v10 )
        v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
      if ( v7 )
      {
        v12 = v7->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          v7->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
      v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr;
    }
    if ( v9 )
    {
      v13 = v9->RefCount;
      if ( v13 & 0x3FFFFFF )
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
    if ( v14 & 0x3FFFFFF )
    {
      v7->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  return v7;
}

// File Line: 1502
// RVA: 0x6EE760
Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *__fastcall Scaleform::GFx::AS2::GlobalContext::GetBuiltinClassRegistrar(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::ASString className)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v4; // rdi
  signed __int64 v5; // rax
  signed __int64 v6; // rdi
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *result; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx

  v2 = className.pNode;
  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->BuiltinClassesRegistry.mHash.pTable;
  v4.pTable = v3->pTable;
  if ( v3->pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               v3,
               (Scaleform::GFx::ASString *)className.pNode,
               *((unsigned int *)className.pNode->pData + 7) & v4.pTable->SizeMask),
        v5 >= 0)
    && (v6 = (signed __int64)&v4.pTable[2 * v5 + 1].SizeMask) != 0
    && (v7 = (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)(v6 + 8)) != 0i64 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)v2->pData;
    v9 = *((_DWORD *)v2->pData + 6) == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    result = v7;
  }
  else
  {
    v11 = (Scaleform::GFx::ASStringNode *)v2->pData;
    v9 = *((_DWORD *)v2->pData + 6) == 1;
    --v11->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    result = 0i64;
  }
  return result;
}

// File Line: 1512
// RVA: 0x6EAA40
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::GlobalContext::FindClassName(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *iobj)
{
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // r13
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::GlobalContext *v7; // r15
  int v8; // edi
  unsigned int v9; // eax
  bool v10; // cf
  bool v11; // zf
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v12; // rax
  signed __int64 v13; // rcx
  Scaleform::GFx::AS2::FunctionObject *v14; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v15; // rdx
  Scaleform::GFx::AS2::LocalFrame *v16; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v17; // rcx
  Scaleform::GFx::AS2::FunctionObject *v18; // r12
  signed __int64 v19; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v20; // rcx
  Scaleform::GFx::ASString *v21; // r15
  Scaleform::GFx::AS2::Value *v22; // rsi
  bool v23; // si
  char v24; // al
  Scaleform::GFx::AS2::FunctionObject *v25; // rcx
  unsigned int v26; // edx
  Scaleform::GFx::AS2::LocalFrame *v27; // rcx
  unsigned int v28; // eax
  char v29; // al
  Scaleform::GFx::AS2::FunctionObject *v30; // rcx
  unsigned int v31; // edx
  Scaleform::GFx::AS2::LocalFrame *v32; // rcx
  unsigned int v33; // eax
  void (__fastcall *v34)(Scaleform::GFx::AS2::RefCountBaseGC<323> *); // rcx
  $3B3220B7F8C7709B379812E5C933B251 *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rax
  Scaleform::GFx::ASString *v37; // rbx
  Scaleform::GFx::ASStringNode *v39; // rax
  Scaleform::GFx::ASString *v40; // rbx
  Scaleform::GFx::ASString *v41; // rbx
  char v42; // al
  Scaleform::GFx::AS2::FunctionObject *v43; // rcx
  unsigned int v44; // edx
  Scaleform::GFx::AS2::LocalFrame *v45; // rcx
  unsigned int v46; // eax
  Scaleform::GFx::ASStringNode *v47; // rax
  Scaleform::GFx::AS2::FunctionRef v48; // [rsp+10h] [rbp-39h]
  Scaleform::GFx::AS2::FunctionRef resulta; // [rsp+30h] [rbp-19h]
  Scaleform::GFx::AS2::Value v50; // [rsp+48h] [rbp-1h]
  char v51[31]; // [rsp+99h] [rbp+50h]
  Scaleform::GFx::ASString *v52; // [rsp+B8h] [rbp+6Fh]

  v4 = iobj;
  v5 = penv;
  v6 = result;
  v7 = this;
  v8 = 0;
  if ( !iobj )
  {
LABEL_75:
    v47 = (Scaleform::GFx::ASStringNode *)v7->pMovieRoot->pASMovieRoot.pObject[17].vfptr;
    v6->pNode = v47;
    ++v47->RefCount;
    return v6;
  }
  v9 = (unsigned __int64)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&iobj->vfptr->gap8[8])(iobj)
     - 2;
  v10 = v9 < 3;
  v11 = v9 == 3;
  v12 = v4->vfptr;
  if ( v10 || v11 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->gap8[8])(v4) - 2 > 3 )
      v13 = 0i64;
    else
      v13 = (signed __int64)&v4[-1].pProto;
    v14 = (Scaleform::GFx::AS2::FunctionObject *)(*(__int64 (**)(void))(*(_QWORD *)v13 + 200i64))();
  }
  else
  {
    v14 = (Scaleform::GFx::AS2::FunctionObject *)&v4[-2];
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->gap8[8])(v4) - 6 > 0x26 )
      v14 = 0i64;
  }
  v15 = v7->pGlobal.pObject->Members.mHash.pTable;
  if ( v15 )
  {
    v16 = 0i64;
    v17 = v15 + 1;
    do
    {
      if ( v17->EntryCount != -2i64 )
        break;
      v16 = (Scaleform::GFx::AS2::LocalFrame *)((char *)v16 + 1);
      v17 += 3;
    }
    while ( (unsigned __int64)v16 <= v15->SizeMask );
    v48.Function = (Scaleform::GFx::AS2::FunctionObject *)&v7->pGlobal.pObject->Members;
    v48.pLocalFrame = v16;
  }
  else
  {
    v48.Function = 0i64;
    v48.pLocalFrame = 0i64;
  }
  _mm_store_si128((__m128i *)&v48, *(__m128i *)&v48.Function);
  v18 = v48.Function;
  v19 = (signed __int64)v48.pLocalFrame;
  while ( 1 )
  {
    if ( !v18 || (v20 = v18->vfptr) == 0i64 || v19 > (_QWORD)v20->Finalize_GC )
    {
      v6 = v52;
      v7 = *(Scaleform::GFx::AS2::GlobalContext **)&v51[23];
      goto LABEL_75;
    }
    v21 = (Scaleform::GFx::ASString *)&v20[2 * v19];
    v22 = (Scaleform::GFx::AS2::Value *)&v20[2 * v19 + 1].Finalize_GC;
    if ( (*(unsigned int (**)(void))&v14->vfptr->gap8[8])() == 23 )
    {
      v23 = 0;
      if ( v22->T.Type == 8 || v22->T.Type == 11 )
      {
        v8 |= 1u;
        if ( Scaleform::GFx::AS2::Value::ToFunction(v22, &resulta, v5)->Function == v14 )
          v23 = 1;
      }
      if ( v8 & 1 )
      {
        v8 &= 0xFFFFFFFE;
        v24 = resulta.Flags;
        if ( !(resulta.Flags & 2) )
        {
          v25 = resulta.Function;
          if ( resulta.Function )
          {
            v26 = resulta.Function->RefCount;
            if ( v26 & 0x3FFFFFF )
            {
              resulta.Function->RefCount = v26 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
              v24 = resulta.Flags;
            }
          }
        }
        resulta.Function = 0i64;
        if ( !(v24 & 1) )
        {
          v27 = resulta.pLocalFrame;
          if ( resulta.pLocalFrame )
          {
            v28 = resulta.pLocalFrame->RefCount;
            if ( v28 & 0x3FFFFFF )
            {
              resulta.pLocalFrame->RefCount = v28 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v27->vfptr);
            }
          }
        }
        resulta.pLocalFrame = 0i64;
      }
      if ( v23 )
      {
        v36 = v21[3].pNode;
        v37 = v52;
        v52->pNode = v36;
        ++v36->RefCount;
        return v37;
      }
      goto LABEL_55;
    }
    if ( v22->T.Type == 6 && Scaleform::GFx::AS2::Value::ToObject(v22, v5) == (Scaleform::GFx::AS2::Object *)v14 )
    {
      v39 = v21[3].pNode;
      v40 = v52;
      v52->pNode = v39;
      ++v39->RefCount;
      return v40;
    }
    if ( v22->T.Type == 8 || v22->T.Type == 11 )
      break;
LABEL_55:
    v34 = v18->vfptr->Finalize_GC;
    if ( v19 <= (signed __int64)v34 && ++v19 <= (unsigned __int64)v34 )
    {
      v35 = &v18->vfptr[2 * v19].16;
      do
      {
        if ( v35->~RefCountBaseGC<323> != (void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *))-2i64 )
          break;
        ++v19;
        v35 += 6;
      }
      while ( v19 <= (unsigned __int64)v34 );
    }
  }
  Scaleform::GFx::AS2::Value::ToFunction(v22, &v48, v5);
  v50.T.Type = 0;
  if ( !v48.Function->vfptr->GetMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v48.Function->vfptr,
          &v5->StringContext,
          (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v51[23] + 40i64) + 24i64) + 928i64),
          &v50)
    || v50.T.Type != 6
    || Scaleform::GFx::AS2::Value::ToObject(&v50, v5) != (Scaleform::GFx::AS2::Object *)v14 )
  {
    if ( v50.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v50);
    v29 = v48.Flags;
    if ( !(v48.Flags & 2) )
    {
      v30 = v48.Function;
      if ( v48.Function )
      {
        v31 = v48.Function->RefCount;
        if ( v31 & 0x3FFFFFF )
        {
          v48.Function->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v30->vfptr);
          v29 = v48.Flags;
        }
      }
    }
    v48.Function = 0i64;
    if ( !(v29 & 1) )
    {
      v32 = v48.pLocalFrame;
      if ( v48.pLocalFrame )
      {
        v33 = v48.pLocalFrame->RefCount;
        if ( v33 & 0x3FFFFFF )
        {
          v48.pLocalFrame->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
        }
      }
    }
    v48.pLocalFrame = 0i64;
    goto LABEL_55;
  }
  v41 = v52;
  Scaleform::GFx::ASString::operator+(v21 + 3, v52, ".prototype");
  if ( v50.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v50);
  v42 = v48.Flags;
  if ( !(v48.Flags & 2) )
  {
    v43 = v48.Function;
    if ( v48.Function )
    {
      v44 = v48.Function->RefCount;
      if ( v44 & 0x3FFFFFF )
      {
        v48.Function->RefCount = v44 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v43->vfptr);
        v42 = v48.Flags;
      }
    }
  }
  v48.Function = 0i64;
  if ( !(v42 & 1) )
  {
    v45 = v48.pLocalFrame;
    if ( v48.pLocalFrame )
    {
      v46 = v48.pLocalFrame->RefCount;
      if ( v46 & 0x3FFFFFF )
      {
        v48.pLocalFrame->RefCount = v46 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v45->vfptr);
      }
    }
  }
  v48.pLocalFrame = 0i64;
  return v41;
}

// File Line: 1566
// RVA: 0x722BA0
char __fastcall Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *className)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v5; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v6; // rsi
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  Scaleform::GFx::AS2::FunctionRef *v9; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+30h] [rbp+8h]

  v3 = className;
  v4 = psc;
  v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->RegisteredClasses.mHash.pTable;
  if ( psc->SWFVersion <= 6u )
  {
    v9 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
           (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->RegisteredClasses.mHash,
           className);
  }
  else
  {
    v6.pTable = v5->pTable;
    if ( !v5->pTable )
      return 0;
    v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->RegisteredClasses.mHash.pTable,
           className,
           v6.pTable->SizeMask & className->pNode->HashFlags);
    if ( v7 < 0 )
      return 0;
    v8 = (signed __int64)v6.pTable + 8 * (5 * v7 + 3);
    if ( !v8 )
      return 0;
    v9 = (Scaleform::GFx::AS2::FunctionRef *)(v8 + 8);
  }
  if ( !v9 )
    return 0;
  if ( v4->SWFVersion <= 6u )
  {
    v11 = v3->pNode;
    key.pStr = v3;
    if ( !v11->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v11);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString::NoCaseKey>(
      v5,
      &key);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
      v5,
      v3);
  }
  return 1;
}

// File Line: 1612
// RVA: 0x6D7DD0
void __fastcall Scaleform::GFx::AS2::NameFunction::AddConstMembers(Scaleform::GFx::AS2::ObjectInterface *pobj, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::NameFunction *pfunctions, char flags)
{
  char v4; // bp
  Scaleform::GFx::AS2::NameFunction *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::ObjectInterface *v7; // r12
  Scaleform::MemoryHeap *v8; // r14
  Scaleform::GFx::AS2::Object *i; // r13
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rbx
  void (__fastcall *v12)(Scaleform::GFx::AS2::FnCall *); // rdi
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value v17; // [rsp+60h] [rbp-58h]
  char v18; // [rsp+C8h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+18h]

  v4 = flags;
  v5 = pfunctions;
  v6 = psc;
  v7 = pobj;
  v8 = psc->pContext->pHeap;
  for ( i = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function); v5->Name; ++v5 )
  {
    v18 = v4;
    v10 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v8->vfptr->Alloc)(
                                           v8,
                                           104i64);
    v11 = v10;
    if ( v10 )
    {
      v12 = v5->Function;
      Scaleform::GFx::AS2::Object::Object(v10, v6);
      v11->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
      v11->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
      v11->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
      v11->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
      v11[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)v12;
      Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)((char *)v11 + 32), v6, i);
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
    v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, v5->Name);
    v7->vfptr->SetMemberRaw(v7, v6, v13, &v17, (Scaleform::GFx::AS2::PropFlags *)&v18);
    v14 = result.pNode;
    v15 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
    if ( v11 )
    {
      v16 = v11->RefCount;
      if ( v16 & 0x3FFFFFF )
      {
        v11->RefCount = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
      }
    }
  }
}

// File Line: 1646
// RVA: 0x6D2A60
void __fastcall Scaleform::GFx::AS2::WithStackEntry::~WithStackEntry(Scaleform::GFx::AS2::WithStackEntry *this)
{
  signed int v1; // eax
  Scaleform::GFx::AS2::Object *v2; // rcx
  unsigned int v3; // eax

  v1 = this->BlockEndPc;
  v2 = this->pObject;
  if ( v1 >= 0 )
  {
    JUMPOUT(v2, 0i64, Scaleform::RefCountNTSImpl::Release);
  }
  else if ( v2 )
  {
    v3 = v2->RefCount;
    if ( v3 & 0x3FFFFFF )
    {
      v2->RefCount = v3 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
    }
  }
}

// File Line: 1663
// RVA: 0x6F45F0
Scaleform::GFx::AS2::ObjectInterfaceVtbl **__fastcall Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(Scaleform::GFx::AS2::WithStackEntry *this)
{
  __int64 v2; // rax

  if ( (this->BlockEndPc & 0x80000000) == 0 )
  {
    if ( this->pObject )
    {
      v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)((char *)&this->pObject->vfptr
                                                                                              + 4
                                                                                              * BYTE5(this->pObject[1].pNext)))->Finalize_GC)((char *)this->pObject + 4 * BYTE5(this->pObject[1].pNext));
      if ( v2 )
        return (Scaleform::GFx::AS2::ObjectInterfaceVtbl **)(v2 + 8);
    }
  }
  else if ( this->pObject )
  {
    return &this->pObject->vfptr;
  }
  return 0i64;
}

// File Line: 1670
// RVA: 0x6E00D0
Scaleform::GFx::AS2::ActionBufferData *__fastcall Scaleform::GFx::AS2::ActionBufferData::CreateNew()
{
  Scaleform::GFx::AS2::ActionBufferData *result; // rax

  result = (Scaleform::GFx::AS2::ActionBufferData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      40i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,263>::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::ActionBufferData,263>::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::ActionBufferData::`vftable';
  result->pBuffer = 0i64;
  *(_QWORD *)&result->BufferLen = 0i64;
  result->SWFFileOffset = 0;
  return result;
}

// File Line: 1680
// RVA: 0x70B620
void __fastcall Scaleform::GFx::AS2::ActionBufferData::Read(Scaleform::GFx::AS2::ActionBufferData *this, Scaleform::GFx::Stream *in, unsigned int actionLength)
{
  Scaleform::GFx::AS2::ActionBufferData *v3; // rsi
  Scaleform::GFx::Stream *v4; // rbp
  char *v5; // rax
  unsigned int v6; // er8
  char *v7; // rsi
  __int64 v8; // rdi
  char v9; // bl
  unsigned int v10; // edx
  Scaleform::GFx::AS2::Disasm v11; // [rsp+20h] [rbp-18h]

  this->BufferLen = actionLength;
  v3 = this;
  v4 = in;
  v5 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 this,
                 actionLength,
                 0i64);
  v6 = v3->BufferLen;
  v3->pBuffer = v5;
  Scaleform::GFx::Stream::ReadToBuffer(v4, v5, v6);
  if ( Scaleform::GFx::Stream::IsVerboseParseAction(v4) )
  {
    v7 = v3->pBuffer;
    v8 = 0i64;
    do
    {
      v9 = v7[v8];
      v10 = v8++;
      if ( v9 < 0 )
        v8 += (unsigned __int16)((unsigned __int8)v7[v8] | (unsigned __int16)((unsigned __int8)v7[v8 + 1] << 8)) + 2i64;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v4->vfptr,
        "%4d\t",
        v10);
      v11.pLog = (Scaleform::Log *)Scaleform::GFx::Stream::GetLog((Expression::IMemberMap *)v4);
      v11.MsgId.Id = 20483;
      Scaleform::GFx::AS2::Disasm::LogF(&v11, "<disasm is disabled>\n");
    }
    while ( v9 );
  }
}

// File Line: 1736
// RVA: 0x70B590
void __fastcall Scaleform::GFx::AS2::ActionBufferData::Read(Scaleform::GFx::AS2::ActionBufferData *this, Scaleform::GFx::StreamContext *psc, unsigned int eventLength)
{
  size_t v3; // rbp
  Scaleform::GFx::StreamContext *v4; // rbx
  Scaleform::GFx::AS2::ActionBufferData *v5; // rsi
  char *v6; // rax
  bool v7; // zf

  v3 = eventLength;
  v4 = psc;
  v5 = this;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  psc->CurBitIndex = 0;
  v6 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 this,
                 eventLength,
                 0i64);
  v5->pBuffer = v6;
  memmove(v6, &v4->pData[v4->CurByteIndex], v3);
  v5->BufferLen = v3;
  v7 = v4->CurBitIndex == 0;
  v4->CurBitIndex = 0;
  if ( !v7 )
    ++v4->CurByteIndex;
  v4->CurByteIndex += v3;
}

// File Line: 1758
// RVA: 0x6C6C30
void __fastcall Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(Scaleform::GFx::AS2::ActionBuffer *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ActionBufferData *pbufferData)
{
  Scaleform::GFx::AS2::ActionBufferData *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::ActionBuffer *v5; // rbx
  Scaleform::GFx::ASMovieRootBase *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rax
  signed __int64 v8; // [rsp+58h] [rbp+10h]

  v3 = pbufferData;
  v4 = psc;
  v5 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::AS2::ActionBuffer,323>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::ActionBuffer::`vftable';
  if ( pbufferData )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pbufferData);
  v5->pBufferData.pObject = v3;
  v6 = v4->pContext->pMovieRoot->pASMovieRoot.pObject;
  v8 = (signed __int64)&v5->Dictionary;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v7 = *(Scaleform::GFx::ASStringNode **)&v6[7].AVMVersion;
  v5->Dictionary.Data.DefaultValue.pNode = v7;
  ++v7->RefCount;
  v5->DeclDictProcessedAt = -1;
}

// File Line: 1786
// RVA: 0x709530
void __fastcall Scaleform::GFx::AS2::ActionBuffer::ProcessDeclDict(Scaleform::GFx::AS2::ActionBuffer *this, Scaleform::GFx::AS2::ASStringContext *psc, unsigned int startPc, unsigned int stopPc, Scaleform::GFx::AS2::ActionLogger *log)
{
  unsigned int v5; // esi
  unsigned int v6; // er13
  Scaleform::GFx::AS2::ActionBuffer *v7; // r14
  Scaleform::GFx::AS2::ActionBufferData *v8; // rdi
  unsigned int v9; // ebp
  char *v10; // rdi
  int v11; // eax
  Scaleform::GFx::AS2::ActionLogger *v12; // rbx
  unsigned int v13; // er15
  unsigned int v14; // ebx
  Scaleform::GFx::ASStringNode *v15; // r12
  __int64 v16; // r14
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode **v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // r12
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS2::ActionLogger *v23; // rbx
  signed __int64 v24; // rbx
  __int64 v25; // rsi
  Scaleform::GFx::ASStringNode *v26; // r15
  Scaleform::GFx::ASString *v27; // rax
  const char *v28; // r14
  Scaleform::GFx::ASStringNode *v29; // rdi
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::ASStringNode *v31; // rcx
  _QWORD v32[2]; // [rsp+20h] [rbp-68h]
  char *v33; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-50h]
  __int64 v35; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::ASString v36; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::AS2::ASStringContext *v37; // [rsp+98h] [rbp+10h]

  v37 = psc;
  v35 = -2i64;
  v5 = stopPc;
  v6 = startPc;
  v7 = this;
  v8 = this->pBufferData.pObject;
  v9 = 0;
  if ( v8->BufferLen < 1 || (v10 = v8->pBuffer, !*v10) )
    v10 = 0i64;
  v11 = this->DeclDictProcessedAt;
  if ( v11 != startPc )
  {
    if ( v11 == -1 )
    {
      this->DeclDictProcessedAt = startPc;
      v13 = (unsigned __int8)v10[startPc + 3] | ((unsigned __int8)v10[startPc + 4] << 8);
      v14 = startPc + 2;
      v15 = (Scaleform::GFx::ASStringNode *)&this->Dictionary;
      v36.pNode = (Scaleform::GFx::ASStringNode *)&this->Dictionary;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Dictionary.Data,
        v13);
      v16 = 0i64;
      if ( v13 )
      {
        while ( 1 )
        {
          v17 = Scaleform::GFx::AS2::ASStringContext::CreateString(v37, &result, &v10[v14 + 3]);
          v33 = (char *)&v15->pData[8 * v16];
          v18 = (Scaleform::GFx::ASStringNode **)&v15->pData[8 * v16];
          v19 = v17->pNode;
          ++v19->RefCount;
          v20 = *v18;
          v21 = v20->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v20);
          *(_QWORD *)v33 = v19;
          v22 = result.pNode;
          v21 = result.pNode->RefCount == 1;
          --v22->RefCount;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          if ( v10[v14 + 3] )
            break;
LABEL_16:
          ++v14;
          ++v9;
          ++v16;
          if ( v9 >= v13 )
            return;
          v15 = v36.pNode;
        }
        while ( v14 < v5 )
        {
          if ( !v10[++v14 + 3] )
            goto LABEL_16;
        }
        v23 = log;
        if ( log->vfptr->IsVerboseActionErrors((Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *)log) )
          Scaleform::GFx::AS2::ActionLogger::LogScriptError(v23, "Action buffer dict length exceeded");
        if ( v9 < v13 )
        {
          v24 = 8 * v16;
          v25 = v13 - v9;
          v26 = v36.pNode;
          do
          {
            v27 = Scaleform::GFx::AS2::ASStringContext::CreateString(v37, &v36, "<invalid>");
            v28 = v26->pData;
            v29 = v27->pNode;
            ++v29->RefCount;
            v30 = *(Scaleform::GFx::ASStringNode **)&v28[v24];
            v21 = v30->RefCount-- == 1;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            *(_QWORD *)&v28[v24] = v29;
            v31 = v36.pNode;
            v21 = v36.pNode->RefCount == 1;
            --v31->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
            v24 += 8i64;
            --v25;
          }
          while ( v25 );
        }
      }
    }
    else
    {
      v12 = log;
      if ( log->vfptr->IsVerboseActionErrors((Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *)log) )
      {
        LODWORD(v32[0]) = v7->DeclDictProcessedAt;
        Scaleform::GFx::AS2::ActionLogger::LogScriptError(
          v12,
          "ProcessDeclDict(%d, %d) - DeclDict was already processed at %d",
          v6,
          v5,
          v32[0]);
      }
    }
  }
}

// File Line: 1851
// RVA: 0x711D90
__int64 __fastcall Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(Scaleform::GFx::AS2::ActionBuffer *this, Scaleform::GFx::AS2::Environment *env, Scaleform::GFx::AS2::Value *frameValue, Scaleform::GFx::InteractiveObject **pptarget, unsigned int *pframeNumber)
{
  Scaleform::GFx::InteractiveObject **v5; // r15
  Scaleform::GFx::AS2::Environment *v6; // r14
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned __int8 v8; // bp
  signed int v9; // esi
  __int64 v10; // r9
  signed int v11; // ebx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  long double v19; // xmm0_8
  __int64 v20; // rax
  Scaleform::GFx::ASString v21; // [rsp+20h] [rbp-38h]
  __int64 v22; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString path; // [rsp+70h] [rbp+18h]

  v22 = -2i64;
  v5 = pptarget;
  v6 = env;
  v7 = env->Target;
  v8 = 0;
  if ( frameValue->T.Type != 5 )
  {
    if ( (unsigned __int8)(frameValue->T.Type - 3) > 1u )
      return 0i64;
    v19 = Scaleform::GFx::AS2::Value::ToNumber(frameValue, env);
    *pframeNumber = (signed int)(v19 - 1.0);
    v8 = 1;
    goto LABEL_26;
  }
  Scaleform::GFx::AS2::Value::ToString(frameValue, &result, env, -1);
  v9 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
  v11 = 0;
  if ( v9 <= 0 )
    goto LABEL_17;
  while ( Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&result.pNode, v11) != 58 )
  {
LABEL_9:
    if ( ++v11 >= v9 )
      goto LABEL_17;
  }
  Scaleform::GFx::ASString::Substring(&result, &path, 0, v11);
  v7 = Scaleform::GFx::AS2::Environment::FindTarget(v6, &path, 0);
  if ( !v7 )
  {
LABEL_7:
    v12 = path.pNode;
    v13 = path.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    goto LABEL_9;
  }
  if ( v11 >= v9 )
  {
    v7 = 0i64;
    goto LABEL_7;
  }
  v14 = Scaleform::GFx::ASString::Substring(&result, &v21, v11 + 1, v9 + 1)->pNode;
  ++v14->RefCount;
  v15 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  result.pNode = v14;
  v16 = v21.pNode;
  v13 = v21.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = path.pNode;
  v13 = path.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
LABEL_17:
  if ( v7 )
  {
    LOBYTE(v10) = 1;
    v8 = 0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, const char *, unsigned int *, __int64))v7->vfptr[108].__vecDelDtor)(
           v7,
           result.pNode->pData,
           pframeNumber,
           v10) )
    {
      v8 = 1;
    }
  }
  v18 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( !v8 )
    return 0i64;
LABEL_26:
  v20 = v8;
  if ( v5 )
    *v5 = v7;
  return v20;
}

// File Line: 1976
// RVA: 0x6CDA70
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::WithStackHolder(Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this, Scaleform::MemoryHeap *pheap, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pinit)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v3; // rsi
  Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *v4; // rdi
  Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v6; // rbx

  v3 = pinit;
  v4 = this;
  this->pHeap = pheap;
  if ( pinit )
  {
    v5 = (Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pheap->vfptr->Alloc)(pheap, 24i64);
    v6 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)v5;
    if ( v5 )
    {
      v5->Data = 0i64;
      v5->Size = 0i64;
      v5->Policy.Capacity = 0i64;
      Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::Append(
        v5,
        v3->Data.Data,
        v3->Data.Size);
    }
    else
    {
      v6 = 0i64;
    }
    v4->pWithStackArray = v6;
  }
  else
  {
    this->pWithStackArray = 0i64;
  }
}

// File Line: 1980
// RVA: 0x6D2AA0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::~WithStackHolder(Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v1; // rbx

  v1 = this->pWithStackArray;
  if ( v1 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

// File Line: 1989
// RVA: 0x70ABB0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::PushBack(Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *this, Scaleform::GFx::AS2::WithStackEntry *entry)
{
  Scaleform::GFx::AS2::WithStackEntry *v2; // rdi
  Scaleform::GFx::AS2::ExecutionContext::WithStackHolder *v3; // rbx
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // rax

  v2 = entry;
  v3 = this;
  if ( !this->pWithStackArray )
  {
    v4 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 24i64);
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
    v3->pWithStackArray = v4;
  }
  Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &v3->pWithStackArray->Data,
    v2);
}

// File Line: 2031
// RVA: 0x6D1430
void __fastcall Scaleform::GFx::AS2::ExecutionContext::~ExecutionContext(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v1; // rbx

  this->pEnv->pASLogger = this->pPrevLog;
  this->LogF.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  v1 = this->WithStack.pWithStackArray;
  if ( v1 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

// File Line: 2051
// RVA: 0x71C4D0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::SetTargetOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::ExecutionContext *v1; // rsi
  Scaleform::GFx::InteractiveObject *v2; // rdi
  char v3; // r14
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS2::Environment *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rcx
  Scaleform::GFx::CharacterHandle *v9; // rcx
  Scaleform::GFx::DisplayObject *v10; // rax
  bool v11; // bl
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS2::Environment *v15; // rbx
  Scaleform::GFx::DisplayObjectBase *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+30h] [rbp-1h]
  Scaleform::GFx::AS2::Value presult; // [rsp+50h] [rbp+1Fh]
  Scaleform::GFx::InteractiveObject *v21; // [rsp+98h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+6Fh]

  v1 = this;
  v2 = 0i64;
  v21 = 0i64;
  Scaleform::GFx::AS2::Value::Value(&v19, this->pEnv->Stack.pCurrent, 0i64);
  v3 = v19.T.Type;
  if ( v19.T.Type == 5 )
  {
LABEL_14:
    v11 = Scaleform::GFx::AS2::Value::ToString(&v19, &result, v1->pEnv, -1)->pNode->Size == 0;
    v12 = result.pNode;
    v6 = result.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( v11 )
    {
      v2 = v1->pOriginalTarget;
      v21 = v1->pOriginalTarget;
    }
    else
    {
      presult.T.Type = 0;
      v13 = Scaleform::GFx::AS2::Value::ToString(v1->pEnv->Stack.pCurrent, &result, v1->pEnv, -1);
      *(_DWORD *)&v19.T.Type = 0;
      Scaleform::GFx::AS2::Environment::GetVariable(v1->pEnv, v13, &presult, v1->WithStack.pWithStackArray);
      v14 = result.pNode;
      v6 = result.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( presult.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&presult);
      v2 = v21;
    }
    goto LABEL_23;
  }
  if ( v19.T.Type != 7 )
  {
    v4 = Scaleform::GFx::AS2::Value::ToStringVersioned(&v19, &result, v1->pEnv, (unsigned __int8)v1->Version);
    if ( (unsigned __int8)v3 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    v3 = 5;
    v19.T.Type = 5;
    v19.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v4->pNode;
    ++v19.V.pStringNode->RefCount;
    v5 = result.pNode;
    v6 = result.pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    goto LABEL_14;
  }
  v7 = v1->pEnv;
  v8 = v1->pEnv->Stack.pCurrent;
  if ( v8->T.Type == 7 )
  {
    if ( v7 )
    {
      v9 = v8->V.pCharHandle;
      if ( v9 )
      {
        v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v9, v7->Target->pASRoot->pMovieImpl);
        if ( v10 )
        {
          if ( SLOBYTE(v10->Flags) < 0 )
            v2 = (Scaleform::GFx::InteractiveObject *)v10;
        }
      }
    }
  }
  v21 = v2;
LABEL_23:
  v15 = v1->pEnv;
  if ( v2 )
  {
    v15->Target = v2;
    *((_BYTE *)v15 + 382) &= 0xFDu;
    v16 = (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr;
  }
  else
  {
    v16 = (Scaleform::GFx::DisplayObjectBase *)&v1->pOriginalTarget->vfptr;
    v15->Target = (Scaleform::GFx::InteractiveObject *)v16;
    *((_BYTE *)v15 + 382) |= 2u;
  }
  v15->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(v16);
  v17 = v1->pEnv;
  v18 = v1->pEnv->Stack.pCurrent;
  if ( v18->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v18);
  --v17->Stack.pCurrent;
  if ( v17->Stack.pCurrent < v17->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v17->Stack);
  if ( (unsigned __int8)v3 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
}

// File Line: 2122
// RVA: 0x720880
void __fastcall Scaleform::GFx::AS2::ExecutionContext::StartDragOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *v1; // rdx
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rax
  Scaleform::GFx::AS2::ExecutionContext *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rcx
  bool v6; // bp
  Scaleform::GFx::InteractiveObject *v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // rcx
  unsigned int v10; // er8
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // r9
  unsigned int v13; // ecx
  long double v14; // xmm0_8
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::AS2::Value *v16; // rcx
  float v17; // xmm1_4
  unsigned int v18; // er8
  long double v19; // xmm0_8
  Scaleform::GFx::AS2::Environment *v20; // rdx
  Scaleform::GFx::AS2::Value *v21; // rcx
  float v22; // xmm1_4
  unsigned int v23; // er8
  long double v24; // xmm0_8
  Scaleform::GFx::AS2::Environment *v25; // rdx
  float v26; // xmm1_4
  unsigned int v27; // ecx
  long double v28; // xmm0_8
  Scaleform::GFx::AS2::Environment *v29; // rbx
  signed int v30; // edi
  float v31; // xmm1_4
  Scaleform::GFx::AS2::Value *v32; // rcx
  Scaleform::GFx::MovieImpl *v33; // rcx
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+20h] [rbp-48h]

  v1 = this->pEnv;
  v2 = 0i64;
  st.pCharacter = 0i64;
  st.pTopmostEntity = 0i64;
  *(_WORD *)&st.LockCenter = 0;
  st.BoundLT = 0i64;
  st.BoundRB = 0i64;
  st.CenterDelta = 0i64;
  st.MouseIndex = -1;
  v3 = v1->Stack.pCurrent;
  v4 = this;
  v5 = v3 - 1;
  if ( v3 <= v1->Stack.pPageStart )
    v5 = v1->Stack.pPrevPageTop;
  v6 = Scaleform::GFx::AS2::Value::ToBool(v5, v1);
  v7 = Scaleform::GFx::AS2::Environment::FindTargetByValue(v4->pEnv, v4->pEnv->Stack.pCurrent);
  v8 = v4->pEnv;
  v9 = 0i64;
  st.pCharacter = v7;
  v10 = 32 * (LODWORD(v8->Stack.Pages.Data.Size) - 1)
      + ((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5);
  if ( v10 >= 2 )
    v9 = &v8->Stack.Pages.Data.Data[(unsigned __int64)(v10 - 2) >> 5]->Values[((_BYTE)v10 - 2) & 0x1F];
  st.Bound = Scaleform::GFx::AS2::Value::ToBool(v9, v8);
  if ( st.Bound )
  {
    v11 = v4->pEnv;
    v12 = 0i64;
    v13 = 32 * (LODWORD(v11->Stack.Pages.Data.Size) - 1)
        + ((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5);
    if ( v13 >= 6 )
      v12 = &v11->Stack.Pages.Data.Data[(unsigned __int64)(v13 - 6) >> 5]->Values[((_BYTE)v13 - 6) & 0x1F];
    v14 = Scaleform::GFx::AS2::Value::ToNumber(v12, v11);
    v15 = v4->pEnv;
    v16 = 0i64;
    v17 = v14;
    st.BoundLT.x = v17 * 20.0;
    v18 = 32 * (LODWORD(v15->Stack.Pages.Data.Size) - 1)
        + ((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5);
    if ( v18 >= 5 )
      v16 = &v15->Stack.Pages.Data.Data[(unsigned __int64)(v18 - 5) >> 5]->Values[((_BYTE)v18 - 5) & 0x1F];
    v19 = Scaleform::GFx::AS2::Value::ToNumber(v16, v15);
    v20 = v4->pEnv;
    v21 = 0i64;
    v22 = v19;
    st.BoundLT.y = v22 * 20.0;
    v23 = 32 * (LODWORD(v20->Stack.Pages.Data.Size) - 1)
        + ((_QWORD)((char *)v20->Stack.pCurrent - (char *)v20->Stack.pPageStart) >> 5);
    if ( v23 >= 4 )
      v21 = &v20->Stack.Pages.Data.Data[(unsigned __int64)(v23 - 4) >> 5]->Values[((_BYTE)v23 - 4) & 0x1F];
    v24 = Scaleform::GFx::AS2::Value::ToNumber(v21, v20);
    v25 = v4->pEnv;
    v26 = v24;
    st.BoundRB.x = v26 * 20.0;
    v27 = 32 * (LODWORD(v25->Stack.Pages.Data.Size) - 1)
        + ((_QWORD)((char *)v25->Stack.pCurrent - (char *)v25->Stack.pPageStart) >> 5);
    if ( v27 >= 3 )
      v2 = &v25->Stack.Pages.Data.Data[(unsigned __int64)(v27 - 3) >> 5]->Values[((_BYTE)v27 - 3) & 0x1F];
    v28 = Scaleform::GFx::AS2::Value::ToNumber(v2, v25);
    v29 = v4->pEnv;
    v30 = 4;
    v31 = v28;
    st.BoundRB.y = v31 * 20.0;
    do
    {
      v32 = v29->Stack.pCurrent;
      if ( v32->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v32);
      --v29->Stack.pCurrent;
      if ( v29->Stack.pCurrent < v29->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v29->Stack);
      --v30;
    }
    while ( v30 );
  }
  if ( st.pCharacter )
  {
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, v6, 0);
    v33 = v4->pEnv->Target->pASRoot->pMovieImpl;
    if ( v33 )
      Scaleform::GFx::MovieImpl::SetDragState(v33, &st);
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&v4->pEnv->Stack);
}

// File Line: 2165
// RVA: 0x6DC320
void __usercall Scaleform::GFx::AS2::ExecutionContext::CastObjectOpCode(Scaleform::GFx::AS2::ExecutionContext *this@<rcx>, __int64 a2@<rdi>)
{
  Scaleform::GFx::AS2::ExecutionContext *v2; // rsi
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Object *v6; // rax
  _BOOL8 v7; // r9
  char v8; // al
  Scaleform::GFx::AS2::FunctionObject *v9; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::LocalFrame *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::AS2::Value v20; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-28h]

  v2 = this;
  v3 = this->pEnv->Stack.pCurrent;
  if ( v3 <= this->pEnv->Stack.pPageStart )
    v4 = this->pEnv->Stack.pPrevPageTop;
  else
    v4 = v3 - 1;
  v.T.Type = 1;
  if ( v4->T.Type == 8 || v4->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(v4, &result, v2->pEnv);
    if ( result.Function )
    {
      v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v3, v2->pEnv);
      if ( v5 )
      {
        v20.T.Type = 0;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, signed __int64))result.Function->vfptr->GetMemberRaw)(
               &result.Function->vfptr,
               &v2->pEnv->StringContext,
               &v2->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
               &v20,
               -2i64) )
        {
          v6 = Scaleform::GFx::AS2::Value::ToObject(&v20, v2->pEnv);
          LOBYTE(v7) = 1;
          if ( v5->vfptr->InstanceOf(v5, v2->pEnv, v6, v7) )
            Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, v5);
        }
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
      }
    }
    v8 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v9 = result.Function;
      if ( result.Function )
      {
        v10 = result.Function->RefCount;
        if ( v10 & 0x3FFFFFF )
        {
          result.Function->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
          v8 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v8 & 1) )
    {
      v11 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v12 = result.pLocalFrame->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  v13 = v2->pEnv;
  v14 = v2->pEnv->Stack.pCurrent;
  if ( &v14[-2] >= v2->pEnv->Stack.pPageStart )
  {
    if ( v14->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v14);
    --v13->Stack.pCurrent;
    v16 = v13->Stack.pCurrent;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    --v13->Stack.pCurrent;
  }
  else
  {
    LODWORD(a2) = 2;
    do
    {
      v15 = v13->Stack.pCurrent;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      --v13->Stack.pCurrent;
      if ( v13->Stack.pCurrent < v13->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
      a2 = (unsigned int)(a2 - 1);
    }
    while ( (_DWORD)a2 );
  }
  v17 = v2->pEnv;
  ++v17->Stack.pCurrent;
  if ( v17->Stack.pCurrent >= v17->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v17->Stack);
  v18 = v17->Stack.pCurrent;
  if ( v18 )
    Scaleform::GFx::AS2::Value::Value(v18, &v, a2);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
}

// File Line: 2213
// RVA: 0x6FB7A0
void __usercall Scaleform::GFx::AS2::ExecutionContext::ImplementsOpCode(Scaleform::GFx::AS2::ExecutionContext *this@<rcx>, __int64 a2@<rdi>)
{
  Scaleform::GFx::AS2::ExecutionContext *v2; // r14
  Scaleform::GFx::AS2::Environment *v3; // rdx
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rcx
  int v6; // esi
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::AS2::Value *v8; // rcx
  signed int v9; // edi
  Scaleform::GFx::AS2::Value *v10; // rcx
  Scaleform::GFx::AS2::Value *v11; // rcx
  char v12; // di
  Scaleform::GFx::AS2::Object *v13; // rax
  signed __int64 v14; // rdi
  unsigned int v15; // ebx
  Scaleform::GFx::AS2::Environment *v16; // r8
  Scaleform::GFx::AS2::Value *v17; // r9
  unsigned int v18; // edx
  char v19; // al
  Scaleform::GFx::AS2::FunctionObject *v20; // rcx
  unsigned int v21; // edx
  Scaleform::GFx::AS2::LocalFrame *v22; // rcx
  unsigned int v23; // eax
  char v24; // al
  Scaleform::GFx::AS2::FunctionObject *v25; // rcx
  unsigned int v26; // edx
  Scaleform::GFx::AS2::LocalFrame *v27; // rcx
  unsigned int v28; // eax
  Scaleform::GFx::AS2::Environment *i; // rbx
  Scaleform::GFx::AS2::Value *v30; // rcx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+8h] [rbp-39h]
  Scaleform::GFx::AS2::FunctionRef v32; // [rsp+20h] [rbp-21h]
  Scaleform::GFx::AS2::Value v33; // [rsp+38h] [rbp-9h]
  Scaleform::GFx::AS2::Value v34; // [rsp+58h] [rbp+17h]
  __int64 v35; // [rsp+78h] [rbp+37h]

  v35 = -2i64;
  v2 = this;
  Scaleform::GFx::AS2::Value::Value(&v34, this->pEnv->Stack.pCurrent, a2);
  v3 = v2->pEnv;
  v4 = v2->pEnv->Stack.pCurrent;
  if ( v4 <= v2->pEnv->Stack.pPageStart )
    v5 = v3->Stack.pPrevPageTop;
  else
    v5 = v4 - 1;
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, v3);
  v7 = v2->pEnv;
  v8 = v2->pEnv->Stack.pCurrent;
  if ( &v8[-2] >= v2->pEnv->Stack.pPageStart )
  {
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    --v7->Stack.pCurrent;
    v11 = v7->Stack.pCurrent;
    if ( v11->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v11);
    --v7->Stack.pCurrent;
  }
  else
  {
    v9 = 2;
    do
    {
      v10 = v7->Stack.pCurrent;
      if ( v10->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v10);
      --v7->Stack.pCurrent;
      if ( v7->Stack.pCurrent < v7->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v7->Stack);
      --v9;
    }
    while ( v9 );
  }
  v12 = v34.T.Type;
  if ( v34.T.Type == 8 || v34.T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v34, &result, v2->pEnv);
    if ( result.Function )
    {
      v33.T.Type = 0;
      if ( result.Function->vfptr->GetMemberRaw(
             (Scaleform::GFx::AS2::ObjectInterface *)&result.Function->vfptr,
             &v2->pEnv->StringContext,
             (Scaleform::GFx::ASString *)&v2->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
             &v33) )
      {
        v13 = Scaleform::GFx::AS2::Value::ToObject(&v33, v2->pEnv);
        if ( v13 )
        {
          v14 = (signed __int64)&v13->vfptr;
          v13->vfptr->AddInterface(
            (Scaleform::GFx::AS2::ObjectInterface *)&v13->vfptr,
            &v2->pEnv->StringContext,
            v6,
            0i64);
          v15 = 0;
          if ( v6 > 0 )
          {
            do
            {
              v16 = v2->pEnv;
              v17 = 0i64;
              v18 = 32 * (v2->pEnv->Stack.Pages.Data.Size - 1)
                  + ((_QWORD)((char *)v2->pEnv->Stack.pCurrent - (char *)v2->pEnv->Stack.pPageStart) >> 5);
              if ( v15 <= v18 )
                v17 = &v16->Stack.Pages.Data.Data[(v18 - v15) >> 5]->Values[(v18 - v15) & 0x1F];
              if ( v17->T.Type == 8 || v17->T.Type == 11 )
              {
                Scaleform::GFx::AS2::Value::ToFunction(v17, &v32, v16);
                if ( v32.Function )
                  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, _QWORD))(*(_QWORD *)v14 + 136i64))(
                    v14,
                    &v2->pEnv->StringContext,
                    v15);
                v19 = v32.Flags;
                if ( !(v32.Flags & 2) )
                {
                  v20 = v32.Function;
                  if ( v32.Function )
                  {
                    v21 = v32.Function->RefCount;
                    if ( v21 & 0x3FFFFFF )
                    {
                      v32.Function->RefCount = v21 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
                      v19 = v32.Flags;
                    }
                  }
                }
                v32.Function = 0i64;
                if ( !(v19 & 1) )
                {
                  v22 = v32.pLocalFrame;
                  if ( v32.pLocalFrame )
                  {
                    v23 = v32.pLocalFrame->RefCount;
                    if ( v23 & 0x3FFFFFF )
                    {
                      v32.pLocalFrame->RefCount = v23 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v22->vfptr);
                    }
                  }
                }
                v32.pLocalFrame = 0i64;
              }
              ++v15;
            }
            while ( (signed int)v15 < v6 );
          }
        }
      }
      if ( v33.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v33);
    }
    v24 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v25 = result.Function;
      if ( result.Function )
      {
        v26 = result.Function->RefCount;
        if ( v26 & 0x3FFFFFF )
        {
          result.Function->RefCount = v26 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
          v24 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v24 & 1) )
    {
      v27 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v28 = result.pLocalFrame->RefCount;
        if ( v28 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v28 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v27->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
    v12 = v34.T.Type;
  }
  for ( i = v2->pEnv; v6; --v6 )
  {
    v30 = i->Stack.pCurrent;
    if ( v30->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v30);
    --i->Stack.pCurrent;
    if ( i->Stack.pCurrent < i->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&i->Stack);
  }
  if ( (unsigned __int8)v12 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v34);
}

// File Line: 2267
// RVA: 0x6E2E60
void __fastcall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode(Scaleform::GFx::AS2::ExecutionContext *this, int actionId)
{
  int v2; // esi
  Scaleform::GFx::AS2::ExecutionContext *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  char v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rcx
  __int64 v12; // rax
  signed __int64 v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Environment *v15; // rdx
  Scaleform::GFx::DisplayObject *v16; // rax
  Scaleform::GFx::DisplayObject *v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::AS2::Object *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::AS2::Environment *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+40h] [rbp-49h]
  void **v25; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::Environment *v26; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::AS2::ActionLogger *v27; // [rsp+70h] [rbp-19h]
  Scaleform::GFx::AS2::Value v28; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::AS2::Value v; // [rsp+98h] [rbp+Fh]
  __int64 v30; // [rsp+B8h] [rbp+2Fh]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASStringNode *v32; // [rsp+100h] [rbp+77h]

  v30 = -2i64;
  v2 = actionId;
  v3 = this;
  Scaleform::GFx::AS2::Value::Value(&v28, this->pEnv->Stack.pCurrent, (__int64)this);
  v4 = v3->pEnv;
  v5 = v3->pEnv->Stack.pCurrent;
  if ( v5->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v5);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
  v.T.Type = 0;
  Scaleform::GFx::AS2::Value::DropRefs(&v);
  v6 = 1;
  v.T.Type = 1;
  v7 = v3->pEnv;
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v8 = (Scaleform::GFx::ASStringNode *)v7->Stack.pCurrent;
  result.pNode = v8;
  v32 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v8, &v, (__int64)v3);
    v6 = v.T.Type;
  }
  if ( v2 != 85 )
  {
    Scaleform::GFx::AS2::Value::ToString(&v28, &result, v3->pEnv, -1);
    presult.T.Type = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(
           v3->pEnv,
           &result,
           &presult,
           v3->WithStack.pWithStackArray,
           0i64,
           0i64,
           0) )
    {
      v15 = v3->pEnv;
      if ( presult.T.Type == 7 )
      {
        if ( v15 )
        {
          if ( presult.V.pStringNode )
          {
            v16 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                    presult.V.pCharHandle,
                    v15->Target->pASRoot->pMovieImpl);
            if ( v16 )
            {
              v17 = 0i64;
              if ( SLOBYTE(v16->Flags) < 0 )
                v17 = v16;
              if ( v17 )
              {
                v18 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v17->vfptr
                                                                                  + 4
                                                                                  * (unsigned __int8)v17->AvmObjOffset))[1].__vecDelDtor)();
                if ( v18 )
                {
                  v13 = v18 + 8;
                  goto LABEL_35;
                }
              }
            }
          }
        }
      }
      else
      {
        v19 = Scaleform::GFx::AS2::Value::ToObject(&presult, v15);
        if ( v19 )
        {
          v13 = (signed __int64)&v19->vfptr;
LABEL_35:
          if ( v13 )
          {
            if ( presult.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&presult);
            v20 = result.pNode;
            v21 = result.pNode->RefCount == 1;
            --v20->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_40:
            v22 = v3->pEnv;
            v25 = (void **)`Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode'::`15'::EnumerateOpVisitor::`vftable';
            v26 = v22;
            v27 = &v3->LogF;
            (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, void ***, signed __int64, _QWORD))(*(_QWORD *)v13 + 64i64))(
              v13,
              &v3->pEnv->StringContext,
              &v25,
              11i64,
              0i64);
            v25 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
            goto LABEL_45;
          }
          goto LABEL_41;
        }
      }
    }
LABEL_41:
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    v23 = result.pNode;
    v21 = result.pNode->RefCount == 1;
    --v23->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    goto LABEL_45;
  }
  v9 = v3->pEnv;
  if ( v28.T.Type != 7 )
  {
    v14 = Scaleform::GFx::AS2::Value::ToObject(&v28, v9);
    if ( !v14 )
      goto LABEL_45;
    v13 = (signed __int64)&v14->vfptr;
LABEL_21:
    if ( !v13 )
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
        if ( SLOBYTE(v10->Flags) < 0 )
          v11 = v10;
        if ( v11 )
        {
          v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                            + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
          if ( v12 )
          {
            v13 = v12 + 8;
            goto LABEL_21;
          }
        }
      }
    }
  }
LABEL_45:
  if ( (unsigned __int8)v6 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v28.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v28);
}

// File Line: 2313
// RVA: 0x723610
void __fastcall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode_::_15_::EnumerateOpVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *__formal, char flags)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rbx
  Scaleform::GFx::ASStringManager *v6; // r8
  _QWORD *v7; // rax
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *v8; // rcx

  v3 = __formal;
  v4 = name;
  v5 = name[1].pNode;
  v5->pManager = (Scaleform::GFx::ASStringManager *)((char *)v5->pManager + 32);
  if ( v5->pManager >= (Scaleform::GFx::ASStringManager *)*(_QWORD *)&v5->RefCount )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&v5->pManager);
  v6 = v5->pManager;
  if ( v6 )
  {
    LOBYTE(v6->vfptr) = 5;
    v7 = *(_QWORD **)&v3->T.Type;
    *(_QWORD *)&v6->RefCount = *(_QWORD *)&v3->T.Type;
    ++*((_DWORD *)v7 + 6);
  }
  v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *)v4[2].pNode;
  if ( v8 )
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
      v8,
      "---enumerate - Push: %s\n",
      **(_QWORD **)&v3->T.Type);
}

// File Line: 2330
// RVA: 0x6E8DD0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::ExtendsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::ExecutionContext *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rdx
  Scaleform::GFx::AS2::Value *v3; // rdx
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::Object *v6; // rbx
  Scaleform::GFx::AS2::ObjectProto *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rsi
  unsigned int v10; // eax
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // rbx
  Scaleform::GFx::AS2::Value *v13; // rcx
  signed int v14; // edi
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rcx
  char v17; // al
  Scaleform::GFx::AS2::FunctionObject *v18; // rcx
  unsigned int v19; // edx
  Scaleform::GFx::AS2::LocalFrame *v20; // rcx
  unsigned int v21; // eax
  char v22; // al
  Scaleform::GFx::AS2::FunctionObject *v23; // rcx
  unsigned int v24; // edx
  Scaleform::GFx::AS2::LocalFrame *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::AS2::FunctionRef v28; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::Value v29; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Value v30; // [rsp+70h] [rbp-19h]
  __int64 v31; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS2::Value v32; // [rsp+98h] [rbp+Fh]

  v31 = -2i64;
  v1 = this;
  Scaleform::GFx::AS2::Value::Value(&v32, this->pEnv->Stack.pCurrent, (__int64)this);
  v2 = v1->pEnv->Stack.pCurrent;
  if ( v2 <= v1->pEnv->Stack.pPageStart )
    v3 = v1->pEnv->Stack.pPrevPageTop;
  else
    v3 = v2 - 1;
  Scaleform::GFx::AS2::Value::Value(&v30, v3, (__int64)v1);
  Scaleform::GFx::AS2::Value::ToFunction(&v32, &result, v1->pEnv);
  Scaleform::GFx::AS2::Value::ToFunction(&v30, &v28, v1->pEnv);
  if ( result.Function && v28.Function )
  {
    v29.T.Type = 0;
    if ( result.Function->vfptr->GetMemberRaw(
           (Scaleform::GFx::AS2::ObjectInterface *)&result.Function->vfptr,
           &v1->pEnv->StringContext,
           (Scaleform::GFx::ASString *)&v1->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v29)
      && v29.T.Type == 6 )
    {
      v4 = Scaleform::GFx::AS2::Value::ToObject(&v29, v1->pEnv);
      v6 = v4;
      if ( v4 )
        v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
      v7 = (Scaleform::GFx::AS2::ObjectProto *)v1->pEnv->StringContext.pContext->pHeap->vfptr->Alloc(v5, 160ui64, 0i64);
      if ( v7 )
      {
        Scaleform::GFx::AS2::ObjectProto::ObjectProto(v7, &v1->pEnv->StringContext, v6);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      Scaleform::GFx::AS2::FunctionObject::SetPrototype(v28.Function, &v1->pEnv->StringContext, v9);
      Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
        &v1->pEnv->StringContext,
        &result);
      if ( v9 )
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
        }
      }
      if ( v6 )
      {
        v11 = v6->RefCount;
        if ( v11 & 0x3FFFFFF )
        {
          v6->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
        }
      }
    }
    if ( v29.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v29);
  }
  v12 = v1->pEnv;
  v13 = v1->pEnv->Stack.pCurrent;
  if ( &v13[-2] >= v1->pEnv->Stack.pPageStart )
  {
    if ( v13->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v13);
    --v12->Stack.pCurrent;
    v16 = v12->Stack.pCurrent;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    --v12->Stack.pCurrent;
  }
  else
  {
    v14 = 2;
    do
    {
      v15 = v12->Stack.pCurrent;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      --v12->Stack.pCurrent;
      if ( v12->Stack.pCurrent < v12->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
      --v14;
    }
    while ( v14 );
  }
  v17 = v28.Flags;
  if ( !(v28.Flags & 2) )
  {
    v18 = v28.Function;
    if ( v28.Function )
    {
      v19 = v28.Function->RefCount;
      if ( v19 & 0x3FFFFFF )
      {
        v28.Function->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v18->vfptr);
        v17 = v28.Flags;
      }
    }
  }
  v28.Function = 0i64;
  if ( !(v17 & 1) )
  {
    v20 = v28.pLocalFrame;
    if ( v28.pLocalFrame )
    {
      v21 = v28.pLocalFrame->RefCount;
      if ( v21 & 0x3FFFFFF )
      {
        v28.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
      }
    }
  }
  v28.pLocalFrame = 0i64;
  v22 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v23 = result.Function;
    if ( result.Function )
    {
      v24 = result.Function->RefCount;
      if ( v24 & 0x3FFFFFF )
      {
        result.Function->RefCount = v24 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr);
        v22 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v22 & 1) )
  {
    v25 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v26 = result.pLocalFrame->RefCount;
      if ( v26 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v26 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
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
  Scaleform::GFx::AS2::ExecutionContext *v1; // rsi
  Scaleform::GFx::AS2::Environment *v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rcx
  Scaleform::GFx::AS2::Value *v4; // rbx
  bool v5; // bp
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  _BOOL8 v8; // r9
  char v9; // dl
  Scaleform::GFx::AS2::FunctionObject *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::LocalFrame *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // rbx
  Scaleform::GFx::AS2::Value *v15; // rcx
  signed int v16; // edi
  Scaleform::GFx::AS2::Value *v17; // rcx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Environment *v19; // rbx
  Scaleform::GFx::AS2::Value *v20; // rax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS2::Value v22; // [rsp+40h] [rbp-38h]

  v1 = this;
  v2 = this->pEnv;
  v3 = this->pEnv->Stack.pCurrent;
  v4 = v3 - 1;
  if ( v3 <= v2->Stack.pPageStart )
    v4 = v2->Stack.pPrevPageTop;
  v5 = 0;
  if ( v3->T.Type == 8 || v3->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(v3, &result, v2);
    if ( result.Function )
    {
      v6 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v1->pEnv);
      if ( v6 )
      {
        v22.T.Type = 0;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, signed __int64))result.Function->vfptr->GetMemberRaw)(
               &result.Function->vfptr,
               &v1->pEnv->StringContext,
               &v1->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
               &v22,
               -2i64) )
        {
          v7 = Scaleform::GFx::AS2::Value::ToObject(&v22, v1->pEnv);
          LOBYTE(v8) = 1;
          v5 = v6->vfptr->InstanceOf(v6, v1->pEnv, v7, v8);
        }
        if ( v22.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v22);
      }
    }
    v9 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v10 = result.Function;
      if ( result.Function )
      {
        v11 = result.Function->RefCount;
        if ( v11 & 0x3FFFFFF )
        {
          result.Function->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
          v9 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v9 & 1) )
    {
      v12 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v13 = result.pLocalFrame->RefCount;
        if ( v13 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  v14 = v1->pEnv;
  v15 = v1->pEnv->Stack.pCurrent;
  if ( &v15[-2] >= v1->pEnv->Stack.pPageStart )
  {
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    --v14->Stack.pCurrent;
    v18 = v14->Stack.pCurrent;
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
      --v14->Stack.pCurrent;
      if ( v14->Stack.pCurrent < v14->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v14->Stack);
      --v16;
    }
    while ( v16 );
  }
  v19 = v1->pEnv;
  ++v19->Stack.pCurrent;
  if ( v19->Stack.pCurrent >= v19->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v19->Stack);
  v20 = v19->Stack.pCurrent;
  if ( v20 )
  {
    v20->T.Type = 2;
    v20->V.BooleanValue = v5;
  }
}(&v19->Stack);
  v20 = v19->Stack.pCurr

// File Line: 2427
// RVA: 0x724370
void __fastcall Scaleform::GFx::AS2::ExecutionContext::WaitForFrameOpCode(Scaleform::GFx::AS2::ExecutionContext *this, Scaleform::GFx::AS2::ActionBuffer *pActions, int actionId)
{
  int v3; // ebx
  Scaleform::GFx::AS2::ActionBuffer *v4; // r13
  Scaleform::GFx::AS2::Environment *v5; // rdx
  Scaleform::GFx::AS2::ExecutionContext *v6; // rdi
  Scaleform::GFx::InteractiveObject *v7; // rsi
  char v8; // r15
  const char *v9; // rdx
  unsigned int v10; // ebp
  char v11; // al
  Scaleform::GFx::AS2::Environment *v12; // r14
  Scaleform::GFx::AS2::Value *v13; // rcx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // er10
  __int64 v17; // rax
  const char *v18; // r9
  __int64 v19; // rcx
  unsigned int pframeNumber; // [rsp+70h] [rbp+18h]

  v3 = 0;
  v4 = pActions;
  v5 = this->pEnv;
  pframeNumber = 0;
  v6 = this;
  v7 = 0i64;
  if ( !(*((_BYTE *)v5 + 382) & 2) && (v5->Target->Flags >> 10) & 1 )
    v7 = v5->Target;
  if ( actionId == 138 )
  {
    v8 = 1;
    v9 = &this->pBuffer[this->PC];
    pframeNumber = *(unsigned __int16 *)(v9 + 3);
    v10 = *((unsigned __int8 *)v9 + 5);
  }
  else
  {
    v11 = Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(v4, v5, v5->Stack.pCurrent, 0i64, &pframeNumber);
    v12 = v6->pEnv;
    v10 = (unsigned __int8)v6->pBuffer[v6->PC + 3];
    v8 = v11;
    v13 = v6->pEnv->Stack.pCurrent;
    if ( v13->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v13);
    --v12->Stack.pCurrent;
    if ( v12->Stack.pCurrent < v12->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
  }
  if ( v7 && v8 )
  {
    v14 = ((__int64 (*)(void))v7[1].pParent->vfptr[10].__vecDelDtor)();
    if ( v14 && pframeNumber >= v14 )
      pframeNumber = v14 - 1;
    v15 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v7->vfptr[111].__vecDelDtor)(v7);
    if ( pframeNumber >= v15 )
    {
      v16 = v4->pBufferData.pObject->BufferLen;
      LODWORD(v17) = v6->NextPC;
      if ( v10 )
      {
        while ( (unsigned int)v17 < v16 )
        {
          v18 = v6->pBuffer;
          v19 = (unsigned int)v17;
          v17 = (unsigned int)(v17 + 1);
          if ( v18[v19] < 0 )
            LODWORD(v17) = ((unsigned __int8)v18[v17] | ((unsigned __int8)v18[(unsigned int)(v17 + 1)] << 8)) + v17 + 2;
          if ( ++v3 >= v10 )
            goto LABEL_21;
        }
      }
      else
      {
LABEL_21:
        if ( (unsigned int)v17 < v16 )
          v6->NextPC = v17;
      }
    }
  }
}

// File Line: 2493
// RVA: 0x6EC180
void __usercall Scaleform::GFx::AS2::ExecutionContext::Function1OpCode(Scaleform::GFx::AS2::ExecutionContext *this@<rcx>, Scaleform::GFx::AS2::ActionBuffer *pActions@<rdx>, __int64 a3@<rdi>)
{
  Scaleform::GFx::AS2::ActionBuffer *v3; // rbx
  Scaleform::GFx::AS2::ExecutionContext *v4; // rsi
  Scaleform::GFx::AS2::AsFunctionObject *v5; // rax
  __int64 v6; // rax
  __int64 v7; // r14
  int v8; // ebx
  signed int v9; // er12
  unsigned int v10; // edx
  int v11; // er12
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r15
  signed __int64 v14; // rcx
  unsigned __int64 i; // rbx
  __int64 v16; // rax
  signed __int64 v17; // r15
  Scaleform::GFx::ASStringNode *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  int v22; // edx
  Scaleform::GFx::AS2::LocalFrame *v23; // r15
  Scaleform::GFx::AS2::LocalFrame *v24; // rcx
  Scaleform::GFx::InteractiveObject *v25; // rcx
  __int64 v26; // rax
  __int64 v27; // r12
  Scaleform::GFx::AS2::Object *v28; // rax
  Scaleform::GFx::AS2::Environment *v29; // rbx
  Scaleform::GFx::AS2::Object *v30; // rax
  Scaleform::GFx::AS2::Environment *v31; // rbx
  __int64 v32; // rax
  Scaleform::GFx::AS2::Environment *v33; // rbx
  Scaleform::GFx::ASStringNode *v34; // rcx
  int v35; // eax
  int v36; // eax
  unsigned int v37; // eax
  Scaleform::GFx::ASStringNode *v38; // rcx
  int v39; // eax
  Scaleform::GFx::AS2::Value v; // [rsp+48h] [rbp-51h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+68h] [rbp-31h]
  __int64 v42; // [rsp+80h] [rbp-19h]
  __int64 v43; // [rsp+88h] [rbp-11h]
  __int64 v44; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS2::Value v45; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::ASString v46; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h]
  __int64 v48; // [rsp+118h] [rbp+7Fh]

  v43 = -2i64;
  v3 = pActions;
  v4 = this;
  v46.pNode = (Scaleform::GFx::ASStringNode *)this->pEnv->StringContext.pContext->pHeap;
  v5 = (Scaleform::GFx::AS2::AsFunctionObject *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::ExecutionContext *, signed __int64, _QWORD))v46.pNode->pData
                                                 + 10))(
                                                  this,
                                                  200i64,
                                                  0i64);
  v48 = (__int64)v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      v5,
      v4->pEnv,
      v3,
      v4->NextPC,
      0,
      v4->WithStack.pWithStackArray,
      Exec_Function);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v44 = v7;
  v8 = v4->PC + 3;
  Scaleform::GFx::AS2::Environment::CreateString(v4->pEnv, &result, &v4->pBuffer[v8]);
  v9 = v8 + result.pNode->Size + 1;
  v10 = *(unsigned __int16 *)&v4->pBuffer[v9];
  v11 = v9 + 2;
  if ( (signed int)v10 > 0 )
  {
    a3 = v7 + 152;
    v48 = v10;
    do
    {
      Scaleform::GFx::AS2::Environment::CreateString(v4->pEnv, &v46, &v4->pBuffer[v11]);
      v12 = *(_QWORD *)(v7 + 160) + 1i64;
      v13 = *(_QWORD *)(v7 + 160);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v7 + 152),
        (const void *)(v7 + 152),
        v12);
      if ( v12 > v13 )
      {
        v14 = *(_QWORD *)a3 + 16 * v13;
        v42 = *(_QWORD *)a3 + 16 * v13;
        for ( i = v12 - v13; i; --i )
        {
          if ( v14 )
          {
            *(_DWORD *)v14 = *(_DWORD *)(v7 + 176);
            v16 = *(_QWORD *)(v7 + 184);
            *(_QWORD *)(v14 + 8) = v16;
            ++*(_DWORD *)(v16 + 24);
          }
          v14 += 16i64;
          v42 = v14;
        }
      }
      v17 = *(_QWORD *)a3 + 16i64 * *(_QWORD *)(v7 + 160);
      *(_DWORD *)(v17 - 16) = 0;
      v18 = v46.pNode;
      ++v18->RefCount;
      v19 = *(Scaleform::GFx::ASStringNode **)(v17 - 8);
      v20 = v19->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      *(_QWORD *)(v17 - 8) = v18;
      v11 += v18->Size + 1;
      v21 = v46.pNode;
      v20 = v46.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      --v48;
    }
    while ( v48 );
  }
  v22 = *(unsigned __int16 *)&v4->pBuffer[v11];
  *(_DWORD *)(v7 + 148) = v22;
  v4->NextPC += v22;
  constructor.Flags = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v7;
  *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  v23 = 0i64;
  constructor.pLocalFrame = 0i64;
  v24 = (Scaleform::GFx::AS2::LocalFrame *)v4->pEnv->LocalFrames.Data.Size;
  if ( v24 )
  {
    v24 = v4->pEnv->LocalFrames.Data.Data[(_QWORD)v24 - 1].pObject;
    if ( v24 )
    {
      v23 = v24;
      constructor.pLocalFrame = v24;
      constructor.Flags = 0;
      v24->RefCount = (v24->RefCount + 1) & 0x8FFFFFFF;
    }
  }
  v.T.Type = 8;
  v.V.FunctionValue.Flags = 0;
  v.V.pStringNode = (Scaleform::GFx::ASStringNode *)v7;
  *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  v.V.FunctionValue.pLocalFrame = 0i64;
  if ( v23 )
  {
    v.V.FunctionValue.pLocalFrame = v23;
    v.V.FunctionValue.Flags &= 0xFEu;
    if ( !(v.V.FunctionValue.Flags & 1) )
      v23->RefCount = (v23->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( result.pNode->Size )
  {
    v25 = v4->pEnv->Target;
    if ( v25 )
      v26 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v25->vfptr
                                                                        + 4 * (unsigned __int8)v25->AvmObjOffset))[1].__vecDelDtor)();
    else
      v26 = 0i64;
    LOBYTE(v46.pNode) = 0;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString *))(*(_QWORD *)(v26 + 8) + 80i64))(
      v26 + 8,
      &v4->pEnv->StringContext,
      &result,
      &v,
      &v46);
  }
  v46.pNode = (Scaleform::GFx::ASStringNode *)v4->pEnv->StringContext.pContext->pHeap;
  v27 = (*((__int64 (__fastcall **)(Scaleform::GFx::AS2::LocalFrame *, signed __int64, _QWORD))v46.pNode->pData + 10))(
          v24,
          160i64,
          0i64);
  v48 = v27;
  if ( v27 )
  {
    v28 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->pEnv->StringContext.pContext, ASBuiltin_Object);
    v29 = v4->pEnv;
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v27, &v4->pEnv->StringContext, v28);
    a3 = v27 + 96;
    *(_QWORD *)a3 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(a3 + 24) = 0;
    *(_QWORD *)(a3 + 8) = 0i64;
    *(_QWORD *)(a3 + 16) = 0i64;
    *(_BYTE *)(v27 + 144) = 0;
    *(_QWORD *)(v27 + 128) = 0i64;
    *(_QWORD *)(v27 + 136) = 0i64;
    *(_QWORD *)(v27 + 152) = 0i64;
    *(_QWORD *)v27 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v27 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)a3 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v27 + 96),
      (Scaleform::GFx::AS2::Object *)v27,
      &v29->StringContext,
      &constructor);
    *(_QWORD *)v27 = &Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v27 + 32) = &Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)a3 = &Scaleform::GFx::AS2::FunctionProto::`vftable';
  }
  else
  {
    v27 = 0i64;
  }
  v48 = v27;
  v30 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->pEnv->StringContext.pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(
    (Scaleform::GFx::AS2::FunctionObject *)v7,
    &v4->pEnv->StringContext,
    v30);
  v31 = v4->pEnv;
  Scaleform::GFx::AS2::Value::Value(&v45, (Scaleform::GFx::AS2::Object *)v27);
  LOBYTE(v46.pNode) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, volatile int *, __int64, Scaleform::GFx::ASString *))(*(_QWORD *)(v7 + 32) + 80i64))(
    v7 + 32,
    &v31->StringContext,
    &v31->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v32,
    &v46);
  if ( v45.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v45);
  if ( !result.pNode->Size )
  {
    v33 = v4->pEnv;
    ++v33->Stack.pCurrent;
    if ( v33->Stack.pCurrent >= v33->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v33->Stack);
    v34 = (Scaleform::GFx::ASStringNode *)v33->Stack.pCurrent;
    v46.pNode = v34;
    if ( v34 )
      Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v34, &v, a3);
  }
  if ( v27 )
  {
    v35 = *(_DWORD *)(v27 + 24);
    if ( v35 & 0x3FFFFFF )
    {
      *(_DWORD *)(v27 + 24) = v35 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v27);
    }
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v36 = *(_DWORD *)(v7 + 24);
  if ( v36 & 0x3FFFFFF )
  {
    *(_DWORD *)(v7 + 24) = v36 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
  }
  constructor.Function = 0i64;
  if ( v23 )
  {
    v37 = v23->RefCount;
    if ( v37 & 0x3FFFFFF )
    {
      v23->RefCount = v37 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr);
    }
  }
  constructor.pLocalFrame = 0i64;
  v38 = result.pNode;
  v20 = result.pNode->RefCount == 1;
  --v38->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  v39 = *(_DWORD *)(v7 + 24);
  if ( v39 & 0x3FFFFFF )
  {
    *(_DWORD *)(v7 + 24) = v39 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
  }
}

// File Line: 2573
// RVA: 0x6EC6A0
void __fastcall Scaleform::GFx::AS2::ExecutionContext::Function2OpCode(Scaleform::GFx::AS2::ExecutionContext *this, Scaleform::GFx::AS2::ActionBuffer *pActions)
{
  Scaleform::GFx::AS2::ActionBuffer *v2; // rbx
  Scaleform::GFx::AS2::ExecutionContext *v3; // r12
  Scaleform::GFx::ASStringNode *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r15
  int v7; // ebx
  signed int v8; // esi
  const char *v9; // rcx
  unsigned int v10; // er8
  __int16 v11; // dx
  int v12; // esi
  _QWORD *v13; // rdi
  const char *v14; // rcx
  int v15; // esi
  const char *v16; // r8
  signed __int64 v17; // rax
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r14
  signed __int64 v20; // rcx
  unsigned __int64 i; // rbx
  __int64 v22; // rax
  signed __int64 v23; // r14
  Scaleform::GFx::ASStringNode *v24; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::ASStringNode *v27; // rcx
  int v28; // edx
  Scaleform::GFx::AS2::LocalFrame *v29; // rdi
  Scaleform::GFx::AS2::LocalFrame *v30; // rcx
  Scaleform::GFx::InteractiveObject *v31; // rcx
  __int64 v32; // rax
  Scaleform::GFx::AS2::ASStringContext *v33; // r14
  __int64 v34; // rsi
  Scaleform::GFx::AS2::Object *v35; // rax
  signed __int64 v36; // ST48_8
  Scaleform::GFx::AS2::Object *v37; // rax
  __int64 v38; // rax
  Scaleform::GFx::AS2::Environment *v39; // rbx
  Scaleform::GFx::AS2::Value *v40; // rcx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  Scaleform::GFx::ASStringNode *v44; // rcx
  int v45; // eax
  __int64 v46; // [rsp+40h] [rbp-59h]
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-49h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [rsp+70h] [rbp-29h]
  __int64 v49; // [rsp+88h] [rbp-11h]
  __int64 v50; // [rsp+90h] [rbp-9h]
  __int64 v51; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS2::Value v52; // [rsp+A0h] [rbp+7h]
  Scaleform::MemoryHeap *v53; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::ASString v55; // [rsp+118h] [rbp+7Fh]

  v51 = -2i64;
  v2 = pActions;
  v3 = this;
  v53 = this->pEnv->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::ASStringNode *)v53->vfptr->Alloc((Scaleform::MemoryHeap *)this, 200ui64, 0i64);
  v55.pNode = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      (Scaleform::GFx::AS2::AsFunctionObject *)v4,
      v3->pEnv,
      v2,
      v3->NextPC,
      0,
      v3->WithStack.pWithStackArray,
      Exec_Function2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v50 = v6;
  v7 = v3->PC + 3;
  Scaleform::GFx::AS2::Environment::CreateString(v3->pEnv, &result, &v3->pBuffer[v7]);
  v8 = v7 + result.pNode->Size + 1;
  v9 = v3->pBuffer;
  v10 = *(unsigned __int16 *)&v9[v8];
  v8 += 2;
  LOBYTE(v9) = v9[v8++];
  *(_BYTE *)(v6 + 195) = (_BYTE)v9;
  v11 = *(_WORD *)&v3->pBuffer[v8];
  v12 = v8 + 2;
  *(_WORD *)(v6 + 192) = v11;
  if ( (signed int)v10 > 0 )
  {
    v13 = (_QWORD *)(v6 + 152);
    v46 = v10;
    do
    {
      v14 = v3->pBuffer;
      LODWORD(v53) = (unsigned __int8)v14[v12];
      v15 = v12 + 1;
      v16 = &v14[v15];
      v17 = -1i64;
      do
        ++v17;
      while ( v16[v17] );
      Scaleform::GFx::AS2::Environment::CreateString(v3->pEnv, &v55, v16, (unsigned int)v17);
      v18 = *(_QWORD *)(v6 + 160) + 1i64;
      v19 = *(_QWORD *)(v6 + 160);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v6 + 152),
        (const void *)(v6 + 152),
        v18);
      if ( v18 > v19 )
      {
        v20 = *v13 + 16 * v19;
        v49 = *v13 + 16 * v19;
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
      *(_DWORD *)(v23 - 16) = (_DWORD)v53;
      v24 = v55.pNode;
      ++v24->RefCount;
      v25 = *(Scaleform::GFx::ASStringNode **)(v23 - 8);
      v26 = v25->RefCount-- == 1;
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      *(_QWORD *)(v23 - 8) = v24;
      v12 = v24->Size + 1 + v15;
      v27 = v55.pNode;
      v26 = v55.pNode->RefCount == 1;
      --v27->RefCount;
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      --v46;
    }
    while ( v46 );
  }
  v28 = *(unsigned __int16 *)&v3->pBuffer[v12];
  *(_DWORD *)(v6 + 148) = v28;
  v3->NextPC += v28;
  constructor.Flags = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  v29 = 0i64;
  constructor.pLocalFrame = 0i64;
  v30 = (Scaleform::GFx::AS2::LocalFrame *)v3->pEnv->LocalFrames.Data.Size;
  if ( v30 )
  {
    v30 = v3->pEnv->LocalFrames.Data.Data[(_QWORD)v30 - 1].pObject;
    if ( v30 )
    {
      v29 = v30;
      constructor.pLocalFrame = v30;
      constructor.Flags = 0;
      v30->RefCount = (v30->RefCount + 1) & 0x8FFFFFFF;
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
    v.V.FunctionValue.Flags &= 0xFEu;
    if ( !(v.V.FunctionValue.Flags & 1) )
      v29->RefCount = (v29->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( result.pNode->Size )
  {
    v31 = v3->pEnv->Target;
    if ( v31 )
      v32 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v31->vfptr
                                                                        + 4 * (unsigned __int8)v31->AvmObjOffset))[1].__vecDelDtor)();
    else
      v32 = 0i64;
    LOBYTE(v53) = 0;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))(*(_QWORD *)(v32 + 8) + 80i64))(
      v32 + 8,
      &v3->pEnv->StringContext,
      &result,
      &v,
      &v53);
  }
  v33 = &v3->pEnv->StringContext;
  v53 = v33->pContext->pHeap;
  v34 = (__int64)v53->vfptr->Alloc((Scaleform::MemoryHeap *)v30, 160ui64, 0i64);
  v55.pNode = (Scaleform::GFx::ASStringNode *)v34;
  if ( v34 )
  {
    v35 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v3->pEnv->StringContext.pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v34, v33, v35);
    v36 = v34 + 96;
    *(_QWORD *)v36 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v36 + 24) = 0;
    *(_QWORD *)(v36 + 8) = 0i64;
    *(_QWORD *)(v36 + 16) = 0i64;
    *(_BYTE *)(v34 + 144) = 0;
    *(_QWORD *)(v34 + 128) = 0i64;
    *(_QWORD *)(v34 + 136) = 0i64;
    *(_QWORD *)(v34 + 152) = 0i64;
    *(_QWORD *)v34 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v34 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v36 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v34 + 96),
      (Scaleform::GFx::AS2::Object *)v34,
      v33,
      &constructor);
    *(_QWORD *)v34 = &Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v34 + 32) = &Scaleform::GFx::AS2::FunctionProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v36 = &Scaleform::GFx::AS2::FunctionProto::`vftable';
  }
  else
  {
    v34 = 0i64;
  }
  v55.pNode = (Scaleform::GFx::ASStringNode *)v34;
  v37 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v3->pEnv->StringContext.pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor((Scaleform::GFx::AS2::FunctionObject *)v6, v33, v37);
  Scaleform::GFx::AS2::Value::Value(&v52, (Scaleform::GFx::AS2::Object *)v34);
  LOBYTE(v53) = 0;
  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, volatile int *, __int64, Scaleform::MemoryHeap **))(*(_QWORD *)(v6 + 32) + 80i64))(
    v6 + 32,
    v33,
    &v33->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v38,
    &v53);
  if ( v52.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v52);
  if ( !result.pNode->Size )
  {
    v39 = v3->pEnv;
    ++v39->Stack.pCurrent;
    if ( v39->Stack.pCurrent >= v39->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v39->Stack);
    v40 = v39->Stack.pCurrent;
    v53 = (Scaleform::MemoryHeap *)v40;
    if ( v40 )
      Scaleform::GFx::AS2::Value::Value(v40, &v, (__int64)v29);
  }
  if ( v34 )
  {
    v41 = *(_DWORD *)(v34 + 24);
    if ( v41 & 0x3FFFFFF )
    {
      *(_DWORD *)(v34 + 24) = v41 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v34);
    }
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v42 = *(_DWORD *)(v6 + 24);
  if ( v42 & 0x3FFFFFF )
  {
    *(_DWORD *)(v6 + 24) = v42 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
  }
  constructor.Function = 0i64;
  if ( v29 )
  {
    v43 = v29->RefCount;
    if ( v43 & 0x3FFFFFF )
    {
      v29->RefCount = v43 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v29->vfptr);
    }
  }
  constructor.pLocalFrame = 0i64;
  v44 = result.pNode;
  v26 = result.pNode->RefCount == 1;
  --v44->RefCount;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  v45 = *(_DWORD *)(v6 + 24);
  if ( v45 & 0x3FFFFFF )
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
void __fastcall Scaleform::GFx::AS2::Environment::CheckTryBlocks(Scaleform::GFx::AS2::Environment *this, int pc, int *plocalTryBlockCount)
{
  int v3; // ebx
  int *v4; // rsi
  unsigned int v5; // ebp
  Scaleform::GFx::AS2::Environment *v6; // rdi
  unsigned __int64 i; // rax
  Scaleform::GFx::AS2::Environment::TryDescr *v8; // rcx
  signed __int64 v9; // rax
  unsigned int v10; // er9

  v3 = *plocalTryBlockCount;
  v4 = plocalTryBlockCount;
  v5 = pc;
  v6 = this;
  if ( *plocalTryBlockCount > 0 )
  {
    for ( i = this->TryBlocks.Data.Size; i; --v3 )
    {
      if ( v3 < 0 )
        break;
      v8 = v6->TryBlocks.Data.Data;
      v9 = i;
      v10 = *((_DWORD *)&v8[v9] - 2);
      if ( v5 >= v10
        && v5 < v10
              + (*((unsigned __int8 *)v8[v9 - 1].pTryBlock + 1) | (*((unsigned __int8 *)v8[v9 - 1].pTryBlock + 2) << 8)) )
      {
        break;
      }
      --*v4;
      Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v6->TryBlocks.Data,
        v6->TryBlocks.Data.Size - 1);
      i = v6->TryBlocks.Data.Size;
    }
  }
}

// File Line: 5316
// RVA: 0x6DC8B0
__int64 __fastcall Scaleform::GFx::AS2::Environment::CheckExceptions(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::ActionBuffer *pactBuf, int nextPc, int *plocalTryBlockCount, Scaleform::GFx::AS2::Value *retval, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack, Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  int *v7; // rbx
  Scaleform::GFx::AS2::ActionBuffer *v8; // rsi
  Scaleform::GFx::AS2::Environment *v9; // rdi
  Scaleform::GFx::AS2::Value *v10; // rax
  char v11; // r12
  int v12; // er13
  unsigned __int64 v13; // r8
  signed __int64 v14; // rdx
  Scaleform::GFx::AS2::Environment::TryDescr *v15; // rax
  const char *v16; // r14
  __int64 v17; // r15
  unsigned int v18; // esi
  unsigned int i; // esi
  Scaleform::GFx::AS2::Value *v20; // rcx
  unsigned __int64 v21; // r15
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rcx
  Scaleform::GFx::AS2::Value *v24; // rcx
  Scaleform::GFx::AS2::Value *v25; // r12
  Scaleform::GFx::AS2::LocalFrame *v26; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // rbx
  Scaleform::GFx::AS2::LocalFrame *v28; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASString *v32; // rbp
  unsigned __int64 v33; // rax
  Scaleform::GFx::AS2::Value *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  bool v36; // zf
  unsigned int v37; // eax
  unsigned int v38; // eax
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType v39; // ebp
  signed __int64 v40; // r8
  unsigned __int64 v41; // rcx
  Scaleform::GFx::AS2::Value *v42; // rcx
  unsigned __int64 v43; // rbp
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v44; // rcx
  unsigned __int64 v45; // rbx
  int v46; // er8
  Scaleform::GFx::AS2::Environment::TryDescr v48; // [rsp+48h] [rbp-A0h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp-90h]
  Scaleform::GFx::AS2::LocalFrame *v50; // [rsp+60h] [rbp-88h]
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v51; // [rsp+68h] [rbp-80h]
  __int64 v52; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS2::LocalFrame *v53; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-68h]
  __int64 v55; // [rsp+F0h] [rbp+8h]
  Scaleform::GFx::AS2::ActionBuffer *v56; // [rsp+F8h] [rbp+10h]
  unsigned int v57; // [rsp+100h] [rbp+18h]
  int *v58; // [rsp+108h] [rbp+20h]

  v58 = plocalTryBlockCount;
  v57 = nextPc;
  v56 = pactBuf;
  v52 = -2i64;
  v7 = plocalTryBlockCount;
  v8 = pactBuf;
  v9 = this;
  v10 = &this->ThrowingValue;
LABEL_3:
  while ( 1 )
  {
    v11 = 0;
    if ( v10->T.Type == 10 )
      return v57;
    v12 = *v7;
    if ( *v7 <= 0 )
      return v8->pBufferData.pObject->BufferLen;
    do
    {
      if ( v11 )
      {
        v10 = &v9->ThrowingValue;
        goto LABEL_3;
      }
      v13 = v9->TryBlocks.Data.Size;
      v14 = v9->TryBlocks.Data.Size;
      v15 = v9->TryBlocks.Data.Data;
      v16 = v15[v9->TryBlocks.Data.Size - 1].pTryBlock;
      v48.pTryBlock = v15[v9->TryBlocks.Data.Size - 1].pTryBlock;
      v17 = *((_QWORD *)&v15[v14] - 1);
      v55 = *((_QWORD *)&v15[v14] - 1);
      *(_QWORD *)&v48.TryBeginPC = *((_QWORD *)&v15[v14] - 1);
      Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v9->TryBlocks.Data,
        v13 - 1);
      --*v7;
      v18 = 32 * (v9->Stack.Pages.Data.Size - 1)
          + ((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5);
      if ( v18 > v48.TopStackIndex )
      {
        for ( i = v18 - v48.TopStackIndex; i; --i )
        {
          v20 = v9->Stack.pCurrent;
          if ( v20->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v20);
          --v9->Stack.pCurrent;
          if ( v9->Stack.pCurrent < v9->Stack.pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v9->Stack);
        }
      }
      if ( !(*v16 & 1) )
        goto LABEL_58;
      LODWORD(v21) = 0;
      if ( *v16 & 4 )
      {
        v22 = *((unsigned __int8 *)v16 + 7);
        v23 = v9->LocalRegister.Data.Size;
        if ( v22 < v23 )
        {
          v24 = &v9->LocalRegister.Data.Data[v23 - v22 - 1];
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v9->vfptr,
            "Invalid local register %d, stack only has %d entries",
            v22,
            (unsigned int)v23);
          v24 = v9->GlobalRegister;
        }
        v25 = &v9->ThrowingValue;
        Scaleform::GFx::AS2::Value::operator=(v24, &v9->ThrowingValue, (__int64)v9);
      }
      else
      {
        v21 = v9->LocalFrames.Data.Size;
        v26 = Scaleform::GFx::AS2::Environment::GetTopLocalFrame(v9, 0);
        v27 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v26->vfptr;
        if ( v26 )
          v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
        v50 = v26;
        v28 = Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(v9);
        v29 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v28->vfptr;
        if ( v28 )
          v28->RefCount = (v28->RefCount + 1) & 0x8FFFFFFF;
        v53 = v28;
        if ( v27 )
          v27->RefCount = (v27->RefCount + 1) & 0x8FFFFFFF;
        v30 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v28->PrevFrame.pObject->vfptr;
        if ( v30 )
        {
          v31 = v30->RefCount;
          if ( v31 & 0x3FFFFFF )
          {
            v30->RefCount = v31 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
          }
        }
        v29[1].pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v27;
        v32 = Scaleform::GFx::AS2::Environment::TryDescr::GetCatchName(&v48, &result, v9);
        v33 = v9->LocalFrames.Data.Size;
        if ( v33 && v9->LocalFrames.Data.Data[v33 - 1].pObject )
        {
          v34 = Scaleform::GFx::AS2::Environment::FindLocal(v9, v32);
          v25 = &v9->ThrowingValue;
          if ( v34 )
            Scaleform::GFx::AS2::Value::operator=(v34, &v9->ThrowingValue, (__int64)v9);
          else
            Scaleform::GFx::AS2::Environment::AddLocal(v9, v32, &v9->ThrowingValue);
        }
        else
        {
          v25 = &v9->ThrowingValue;
        }
        v35 = result.pNode;
        v36 = result.pNode->RefCount == 1;
        --v35->RefCount;
        if ( v36 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        v37 = v29->RefCount;
        if ( v37 & 0x3FFFFFF )
        {
          v29->RefCount = v37 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
        }
        if ( v27 )
        {
          v38 = v27->RefCount;
          if ( v38 & 0x3FFFFFF )
          {
            v27->RefCount = v38 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
          }
        }
      }
      Scaleform::GFx::AS2::Value::DropRefs(v25);
      v9->ThrowingValue.T.Type = 10;
      *((_BYTE *)v9 + 382) &= 0xFEu;
      v39 = execType;
      v8 = v56;
      Scaleform::GFx::AS2::ActionBuffer::Execute(
        v56,
        v9,
        v55 + *(unsigned __int16 *)(v16 + 1),
        *(unsigned __int16 *)(v16 + 3),
        retval,
        pwithStack,
        execType);
      v57 = *(unsigned __int16 *)(v16 + 5) + v55 + *(unsigned __int16 *)(v16 + 3) + *(unsigned __int16 *)(v16 + 1);
      v11 = 1;
      if ( !(*v16 & 4) )
      {
        v43 = v9->LocalFrames.Data.Size;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v9->LocalFrames,
          &v9->LocalFrames,
          (unsigned int)v21);
        if ( (unsigned int)v21 > v43 )
        {
          v44 = &v9->LocalFrames.Data.Data[v43];
          v45 = (unsigned int)v21 - v43;
          if ( (unsigned int)v21 != v43 )
          {
            do
            {
              v51 = v44;
              if ( v44 )
                v44->pObject = 0i64;
              ++v44;
              --v45;
            }
            while ( v45 );
          }
        }
        LODWORD(v17) = v55;
LABEL_58:
        v39 = execType;
        v8 = v56;
        goto LABEL_59;
      }
      v.T.Type = 0;
      if ( *v16 & 1 && *v16 & 4 )
        v40 = *((unsigned __int8 *)v16 + 7);
      else
        v40 = 0xFFFFFFFFi64;
      v41 = v9->LocalRegister.Data.Size;
      if ( (unsigned int)v40 < v41 )
      {
        v42 = &v9->LocalRegister.Data.Data[v41 - (unsigned int)v40 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v9->vfptr,
          "Invalid local register %d, stack only has %d entries",
          v40,
          (unsigned int)v41);
        v42 = v9->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::operator=(v42, &v, (__int64)v9);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      LODWORD(v17) = v55;
LABEL_59:
      if ( *v16 & 2 )
      {
        v46 = v17 + *(unsigned __int16 *)(v16 + 3) + *(unsigned __int16 *)(v16 + 1);
        *((_BYTE *)v9 + 382) |= 1u;
        Scaleform::GFx::AS2::ActionBuffer::Execute(v8, v9, v46, *(unsigned __int16 *)(v16 + 5), retval, pwithStack, v39);
        *((_BYTE *)v9 + 382) &= 0xFEu;
      }
      --v12;
      v7 = v58;
    }
    while ( v12 > 0 );
    v10 = &v9->ThrowingValue;
    if ( !v11 )
      return v8->pBufferData.pObject->BufferLen;
  }
}

// File Line: 5436
// RVA: 0x6F1CA0
__int64 __fastcall Scaleform::GFx::AS2::Environment::GetMember(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::ObjectInterface *pthisObj, Scaleform::GFx::ASString *memberName, Scaleform::GFx::AS2::Value *pdestVal)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASString *v5; // r15
  Scaleform::GFx::AS2::ObjectInterface *v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // rsi
  unsigned __int8 v8; // bl
  Scaleform::GFx::AS2::Value **v9; // rbx
  __int64 v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rax
  int v12; // edx
  char v13; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  unsigned int v17; // eax
  char v18; // al
  Scaleform::GFx::AS2::FunctionObject *v19; // rcx
  unsigned int v20; // edx
  Scaleform::GFx::AS2::LocalFrame *v21; // rcx
  unsigned int v22; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+10h] [rbp-29h]
  void **v25; // [rsp+28h] [rbp-11h]
  Scaleform::GFx::AS2::Value *v26; // [rsp+30h] [rbp-9h]
  Scaleform::GFx::AS2::ObjectInterface *v27; // [rsp+38h] [rbp-1h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // [rsp+40h] [rbp+7h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // [rsp+48h] [rbp+Fh]
  char v30; // [rsp+50h] [rbp+17h]
  Scaleform::GFx::AS2::Environment *v31; // [rsp+58h] [rbp+1Fh]
  _DWORD v32[14]; // [rsp+60h] [rbp+27h]
  __int64 v33; // [rsp+A8h] [rbp+6Fh]

  v4 = pdestVal;
  v5 = memberName;
  v6 = pthisObj;
  v7 = this;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))pthisObj->vfptr->GetMember)(
         pthisObj,
         this);
  if ( v8 && v4->T.Type == 9 )
  {
    Scaleform::GFx::AS2::Value::GetPropertyValue(v4, v7, v6, v4);
  }
  else if ( v4->T.Type == 12 )
  {
    Scaleform::GFx::AS2::Value::ToResolveHandler(v4, &result);
    if ( result.Function )
    {
      v9 = &v7->Stack.pCurrent;
      ++*v9;
      if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
      v10 = (__int64)*v9;
      v33 = v10;
      if ( v10 )
      {
        *(_BYTE *)v10 = 5;
        v11 = v5->pNode;
        *(Scaleform::GFx::ASString *)(v10 + 8) = (Scaleform::GFx::ASString)v5->pNode;
        ++v11->RefCount;
      }
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 0;
      v12 = ((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5)
          + 32 * v7->Stack.Pages.Data.Size
          - 32;
      v25 = &Scaleform::GFx::AS2::FnCall::`vftable';
      v26 = v4;
      v27 = v6;
      v30 = 0;
      v28 = 0i64;
      v29 = 0i64;
      v31 = v7;
      v32[0] = 1;
      v32[1] = v12;
      ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD, void **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ObjectInterface *))result.Function->vfptr[3].Finalize_GC)(
        result.Function,
        &v25,
        result.pLocalFrame,
        0i64,
        &Scaleform::GFx::AS2::FnCall::`vftable',
        v4,
        v6);
      v25 = &Scaleform::GFx::AS2::FnCall::`vftable';
      v13 = v30;
      if ( !(v30 & 2) )
      {
        v14 = v28;
        if ( v28 )
        {
          v15 = v28->RefCount;
          if ( v15 & 0x3FFFFFF )
          {
            v28->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
            v13 = v30;
          }
        }
      }
      v28 = 0i64;
      if ( !(v13 & 1) )
      {
        v16 = v29;
        if ( v29 )
        {
          v17 = v29->RefCount;
          if ( v17 & 0x3FFFFFF )
          {
            v29->RefCount = v17 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
          }
        }
      }
      v29 = 0i64;
      v25 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
      if ( (*v9)->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(*v9);
      --*v9;
      if ( v7->Stack.pCurrent < v7->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v7->Stack);
      v8 = 1;
    }
    else
    {
      v8 = 0;
    }
    v18 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v19 = result.Function;
      if ( result.Function )
      {
        v20 = result.Function->RefCount;
        if ( v20 & 0x3FFFFFF )
        {
          result.Function->RefCount = v20 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
          v18 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v18 & 1) )
    {
      v21 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v22 = result.pLocalFrame->RefCount;
        if ( v22 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v22 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v21->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  return v8;
}

// File Line: 5470
// RVA: 0x71C4A0
void __fastcall Scaleform::GFx::AS2::Environment::SetTarget(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::InteractiveObject *ptarget)
{
  *((_BYTE *)this + 382) &= 0xFDu;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&ptarget->vfptr);
}

// File Line: 5476
// RVA: 0x714BF0
void __fastcall Scaleform::GFx::AS2::Environment::SetInvalidTarget(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::InteractiveObject *ptarget)
{
  *((_BYTE *)this + 382) |= 2u;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&ptarget->vfptr);
}

// File Line: 5491
// RVA: 0x7025D0
void Scaleform::GFx::AS2::Environment::LogScriptError(Scaleform::GFx::AS2::Environment *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::Environment *v2; // rdi
  Scaleform::GFx::AS2::ActionLogger *v3; // rbx
  Scaleform::Log *v4; // rcx
  unsigned __int64 v5; // rax
  __int64 v6; // rax
  int v7; // [rsp+20h] [rbp-E0h]
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-D8h]
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-C8h]
  __int64 v10; // [rsp+50h] [rbp-B0h]
  char v11; // [rsp+60h] [rbp-A0h]
  Scaleform::MsgFormat v12; // [rsp+160h] [rbp+60h]
  const char *v13; // [rsp+598h] [rbp+498h]
  va_list va; // [rsp+5A0h] [rbp+4A0h]

  va_start(va, pfmt);
  v13 = pfmt;
  v10 = -2i64;
  v2 = this;
  v3 = this->pASLogger;
  if ( v3 )
  {
    v4 = v3->pLog;
    if ( v4 )
    {
      if ( v3->UseSuffix )
      {
        v5 = -1i64;
        do
          ++v5;
        while ( pfmt[v5] );
        if ( pfmt[v5 - 1] == 10 )
          --v5;
        r.Type = 2;
        r.SinkData.pStr = (Scaleform::String *)&v11;
        r.SinkData.DataPtr.Size = 256i64;
        v.pStr = pfmt;
        v.Size = v5;
        Scaleform::MsgFormat::MsgFormat(&v12, &r);
        Scaleform::MsgFormat::Parse(&v12, "{0} : {1}\n");
        Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v12, &v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v12, &v3->LogSuffix);
        Scaleform::MsgFormat::FinishFormatD(&v12);
        Scaleform::MsgFormat::~MsgFormat(&v12);
        v7 = 212992;
        ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *, _QWORD, const char *, unsigned __int64))v3->pLog->vfptr[1].__vecDelDtor)(
          v3->pLog,
          &v7,
          &v11,
          (__int64 *)va,
          *(_QWORD *)&v7,
          v.pStr,
          v.Size);
      }
      else
      {
        v7 = 212992;
        ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v4->vfptr[1].__vecDelDtor)(
          v4,
          &v7,
          pfmt,
          (__int64 *)va,
          *(_QWORD *)&v7);
      }
    }
  }
  else if ( ((__int64 (*)(void))this->Target->vfptr[76].__vecDelDtor)() )
  {
    v6 = ((__int64 (*)(void))v2->Target->vfptr[76].__vecDelDtor)();
    v7 = 212992;
    (*(void (__fastcall **)(__int64, int *, const char *, __int64 *, _QWORD))(*(_QWORD *)v6 + 8i64))(
      v6,
      &v7,
      v13,
      (__int64 *)va,
      *(_QWORD *)&v7);
  }
}

// File Line: 5501
// RVA: 0x702A30
void Scaleform::GFx::AS2::Environment::LogScriptWarning(Scaleform::GFx::AS2::Environment *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::Environment *v2; // rdi
  Scaleform::GFx::AS2::ActionLogger *v3; // rbx
  Scaleform::Log *v4; // rcx
  unsigned __int64 v5; // rax
  __int64 v6; // rax
  int v7; // [rsp+20h] [rbp-E0h]
  Scaleform::StringDataPtr v; // [rsp+28h] [rbp-D8h]
  Scaleform::MsgFormat::Sink r; // [rsp+38h] [rbp-C8h]
  __int64 v10; // [rsp+50h] [rbp-B0h]
  char v11; // [rsp+60h] [rbp-A0h]
  Scaleform::MsgFormat v12; // [rsp+160h] [rbp+60h]
  const char *v13; // [rsp+598h] [rbp+498h]
  va_list va; // [rsp+5A0h] [rbp+4A0h]

  va_start(va, pfmt);
  v13 = pfmt;
  v10 = -2i64;
  v2 = this;
  v3 = this->pASLogger;
  if ( v3 )
  {
    v4 = v3->pLog;
    if ( v4 )
    {
      if ( v3->UseSuffix )
      {
        v5 = -1i64;
        do
          ++v5;
        while ( pfmt[v5] );
        if ( pfmt[v5 - 1] == 10 )
          --v5;
        r.Type = 2;
        r.SinkData.pStr = (Scaleform::String *)&v11;
        r.SinkData.DataPtr.Size = 256i64;
        v.pStr = pfmt;
        v.Size = v5;
        Scaleform::MsgFormat::MsgFormat(&v12, &r);
        Scaleform::MsgFormat::Parse(&v12, "{0} : {1}\n");
        Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v12, &v);
        Scaleform::MsgFormat::FormatD1<char const *>(&v12, &v3->LogSuffix);
        Scaleform::MsgFormat::FinishFormatD(&v12);
        Scaleform::MsgFormat::~MsgFormat(&v12);
        v7 = 147456;
        ((void (__fastcall *)(Scaleform::Log *, int *, char *, __int64 *, _QWORD, const char *, unsigned __int64))v3->pLog->vfptr[1].__vecDelDtor)(
          v3->pLog,
          &v7,
          &v11,
          (__int64 *)va,
          *(_QWORD *)&v7,
          v.pStr,
          v.Size);
      }
      else
      {
        v7 = 147456;
        ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v4->vfptr[1].__vecDelDtor)(
          v4,
          &v7,
          pfmt,
          (__int64 *)va,
          *(_QWORD *)&v7);
      }
    }
  }
  else if ( ((__int64 (*)(void))this->Target->vfptr[76].__vecDelDtor)() )
  {
    v6 = ((__int64 (*)(void))v2->Target->vfptr[76].__vecDelDtor)();
    v7 = 147456;
    (*(void (__fastcall **)(__int64, int *, const char *, __int64 *, _QWORD))(*(_QWORD *)v6 + 8i64))(
      v6,
      &v7,
      v13,
      (__int64 *)va,
      *(_QWORD *)&v7);
  }
}

// File Line: 5531
// RVA: 0x7010B0
__int64 __fastcall Scaleform::GFx::AS2::Environment::IsVerboseActionErrors(Scaleform::GFx::AS2::Environment *this)
{
  return ~(unsigned __int8)(this->Target->pASRoot->pMovieImpl->Flags >> 6) & 1;
}

// File Line: 5559
// RVA: 0x6EA100
bool __fastcall Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::GFx::AS2::Environment::GetVarParams *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rbp
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rax
  const char *v6; // rsi
  unsigned int v7; // er9
  Scaleform::GFx::InteractiveObject **v8; // r8
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // rcx
  __int64 v11; // rdi
  Scaleform::GFx::AS2::Value *v12; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+48h] [rbp-40h]

  v2 = params;
  v3 = this;
  v4 = params->VarName;
  v5 = params->VarName->pNode;
  if ( (v5->HashFlags >> 25) & 1 )
    return Scaleform::GFx::AS2::Environment::GetVariableRaw(v3, v2);
  if ( !(v5->HashFlags & 0x4000000) )
  {
    v6 = v5->pData;
    if ( !strchr(v5->pData, 58) && !strchr(v6, 47) && !strchr(v6, 46) )
    {
      v4->pNode->HashFlags |= 0x6000000u;
      return Scaleform::GFx::AS2::Environment::GetVariableRaw(v3, v2);
    }
    v4->pNode->HashFlags |= 0x4000000u;
  }
  v.T.Type = 0;
  v7 = v2->ExcludeFlags;
  v8 = v2->ppNewTarget;
  v9 = v2->pWithStack;
  v10 = v2->pResult;
  paramsa.VarName = v2->VarName;
  paramsa.pResult = v10;
  paramsa.pWithStack = v9;
  paramsa.ppNewTarget = v8;
  paramsa.pOwner = &v;
  paramsa.ExcludeFlags = v7;
  v11 = Scaleform::GFx::AS2::Environment::FindVariable(v3, &paramsa, 0, 0i64);
  if ( v.T.Type && v.T.Type != 10 )
  {
    v12 = v2->pOwner;
    if ( v12 )
      Scaleform::GFx::AS2::Value::operator=(v12, &v, v11);
  }
  else
  {
    if ( !(v2->ExcludeFlags & 4) )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v3,
        " GetVariable failed: can't resolve the path \"%s\"",
        v2->VarName->pNode->pData);
    LOBYTE(v11) = 0;
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v11;
}

// File Line: 5596
// RVA: 0x6F73A0
bool __fastcall Scaleform::GFx::AS2::Environment::GetVariable(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::GFx::AS2::Value *presult, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::Environment *v6; // rsi
  bool result; // al
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::ObjectInterface *v9; // r8
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::InteractiveObject *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::DisplayObject *v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rax
  int v20; // edx
  char v21; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::AS2::Value *v26; // rcx
  char v27; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // rcx
  int v29; // edx
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS2::Value v32; // [rsp+28h] [rbp-71h]
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+48h] [rbp-51h]
  void **v34; // [rsp+78h] [rbp-21h]
  Scaleform::GFx::AS2::Value *v35; // [rsp+80h] [rbp-19h]
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v36; // [rsp+88h] [rbp-11h]
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
  v4 = pwithStack;
  v5 = presult;
  v6 = this;
  params.VarName = varname;
  params.pResult = presult;
  params.pWithStack = pwithStack;
  params.ppNewTarget = (Scaleform::GFx::InteractiveObject **)varname;
  params.pOwner = presult;
  params.ExcludeFlags = (unsigned int)pwithStack;
  result = Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, &params);
  v48 = result;
  if ( !result || v5->T.Type != 9 )
  {
    if ( v5->T.Type != 12 )
      return result;
    LOBYTE(params.VarName) = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariable(
           v6,
           (Scaleform::GFx::ASString *)&v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20],
           (Scaleform::GFx::AS2::Value *)&params,
           pwithStacka,
           0i64,
           0i64,
           0) )
    {
      v14 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&params, v6);
      if ( v14 )
      {
        pwithStackb = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)&v14->vfptr;
        if ( v14 != (Scaleform::GFx::AS2::Object *)-32i64 )
          goto LABEL_33;
      }
      if ( LOBYTE(params.VarName) != 7 )
        goto LABEL_32;
      if ( !params.pResult )
        goto LABEL_32;
      v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
              (Scaleform::GFx::CharacterHandle *)params.pResult,
              v6->Target->pASRoot->pMovieImpl);
      if ( !v15 )
        goto LABEL_32;
      v16 = 0i64;
      if ( SLOBYTE(v15->Flags) < 0 )
        v16 = (Scaleform::GFx::InteractiveObject *)v15;
    }
    else
    {
      v16 = v6->Target;
    }
    if ( v16 )
    {
      v17 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v16->vfptr
                                                                        + 4 * (unsigned __int8)v16->AvmObjOffset))[1].__vecDelDtor)();
      if ( v17 )
      {
        pwithStackb = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)(v17 + 8);
LABEL_33:
        Scaleform::GFx::AS2::Value::ToResolveHandler(v5, (Scaleform::GFx::AS2::FunctionRef *)&v32);
        ++v6->Stack.pCurrent;
        if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
        v18 = v6->Stack.pCurrent;
        if ( v18 )
        {
          v18->T.Type = 5;
          v19 = *vars0;
          v18->V.pStringNode = *vars0;
          ++v19->RefCount;
        }
        Scaleform::GFx::AS2::Value::DropRefs(retaddr);
        retaddr->T.Type = 0;
        v20 = ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5)
            + 32 * v6->Stack.Pages.Data.Size
            - 32;
        v34 = &Scaleform::GFx::AS2::FnCall::`vftable';
        v35 = retaddr;
        v36 = pwithStackb;
        v39 = 0;
        v37 = 0i64;
        v38 = 0i64;
        v40 = v6;
        v41 = 1;
        v42 = v20;
        (*(void (__fastcall **)(_QWORD, void ***, Scaleform::GFx::ASStringNode *, _QWORD))(**(_QWORD **)&v32.T.Type
                                                                                         + 80i64))(
          *(_QWORD *)&v32.T.Type,
          &v34,
          v32.V.pStringNode,
          0i64);
        v34 = &Scaleform::GFx::AS2::FnCall::`vftable';
        v21 = v39;
        if ( !(v39 & 2) )
        {
          v22 = v37;
          if ( v37 )
          {
            v23 = v37->RefCount;
            if ( v23 & 0x3FFFFFF )
            {
              v37->RefCount = v23 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
              v21 = v39;
            }
          }
        }
        v37 = 0i64;
        if ( !(v21 & 1) )
        {
          v24 = v38;
          if ( v38 )
          {
            v25 = v38->RefCount;
            if ( v25 & 0x3FFFFFF )
            {
              v38->RefCount = v25 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
            }
          }
        }
        v38 = 0i64;
        v34 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
        v26 = v6->Stack.pCurrent;
        if ( v26->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v26);
        --v6->Stack.pCurrent;
        if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
        v27 = *((_BYTE *)&v32.NV + 16);
        if ( !(*((char *)&v32.NV + 16) & 2) )
        {
          v28 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v32.T.Type;
          if ( *(_QWORD *)&v32.T.Type )
          {
            v29 = *(_DWORD *)(*(_QWORD *)&v32.T.Type + 24i64);
            if ( v29 & 0x3FFFFFF )
            {
              *(_DWORD *)(*(_QWORD *)&v32.T.Type + 24i64) = v29 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
              v27 = *((_BYTE *)&v32.NV + 16);
            }
          }
        }
        *(_QWORD *)&v32.T.Type = 0i64;
        if ( !(v27 & 1) )
        {
          v30 = v32.V.pStringNode;
          if ( v32.V.pStringNode )
          {
            v31 = v32.V.pStringNode->RefCount;
            if ( v31 & 0x3FFFFFF )
            {
              v32.V.pStringNode->RefCount = v31 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v30);
            }
          }
        }
        v32.V.pStringNode = 0i64;
        if ( LOBYTE(params.VarName) < 5u )
          return v48;
        v13 = (Scaleform::GFx::AS2::Value *)&params;
        goto LABEL_59;
      }
    }
LABEL_32:
    pwithStackb = 0i64;
    goto LABEL_33;
  }
  v32.T.Type = 0;
  params.VarName = (Scaleform::GFx::ASString *)&v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
  params.pResult = &v32;
  params.pWithStack = v4;
  params.ppNewTarget = 0i64;
  params.pOwner = 0i64;
  params.ExcludeFlags = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariableRaw(v6, &params) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v32, v6);
    if ( v8 )
    {
      v9 = (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr;
      if ( v8 != (Scaleform::GFx::AS2::Object *)-32i64 )
        goto LABEL_16;
    }
    if ( v32.T.Type != 7 )
      goto LABEL_15;
    if ( !v32.V.pStringNode )
      goto LABEL_15;
    v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v32.V.pCharHandle, v6->Target->pASRoot->pMovieImpl);
    if ( !v10 )
      goto LABEL_15;
    v11 = 0i64;
    if ( SLOBYTE(v10->Flags) < 0 )
      v11 = (Scaleform::GFx::InteractiveObject *)v10;
  }
  else
  {
    v11 = v6->Target;
  }
  if ( !v11
    || (v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                          + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)(),
        v9 = (Scaleform::GFx::AS2::ObjectInterface *)(v12 + 8),
        !v12) )
  {
LABEL_15:
    v9 = 0i64;
  }
LABEL_16:
  Scaleform::GFx::AS2::Value::GetPropertyValue(v5, v6, v9, v5);
  if ( v32.T.Type >= 5u )
  {
    v13 = &v32;
LABEL_59:
    Scaleform::GFx::AS2::Value::DropRefs(v13);
  }
  return v48;
}

// File Line: 5649
// RVA: 0x6FFF60
char __fastcall Scaleform::GFx::AS2::Environment::IsAvailable(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v3; // r15
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // r13
  Scaleform::GFx::AS2::ASStringContext *v7; // r14
  Scaleform::GFx::InteractiveObject *v8; // rax
  char v9; // bl
  __int64 v10; // rax
  int v11; // ecx
  __int64 v12; // rbx
  signed __int64 v13; // rdi
  Scaleform::GFx::AS2::WithStackEntry *v14; // rcx
  Scaleform::GFx::AS2::Object *v15; // rcx
  signed __int64 v16; // rcx
  Scaleform::GFx::AS2::Object *v17; // rdx
  __int64 v18; // rax
  Scaleform::GFx::InteractiveObject *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::ASMovieRootBase *v21; // rcx
  const char **v22; // rdx
  Scaleform::GFx::AS2::GlobalContext *v23; // r9
  void *(__fastcall *v24)(Scaleform::RefCountImplCore *, unsigned int); // r8
  const char *v25; // rcx
  int v26; // eax
  Scaleform::GFx::AS2::Object *v27; // rcx
  Scaleform::GFx::ASStringNode *v28; // rcx
  bool v29; // zf
  Scaleform::GFx::ASStringNode *v30; // rcx
  char *ptail; // [rsp+20h] [rbp-60h]
  __int64 v32; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS2::Value v33; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::ASString pvar; // [rsp+B8h] [rbp+38h]
  Scaleform::GFx::ASString ppath; // [rsp+C8h] [rbp+48h]

  v32 = -2i64;
  v3 = pwithStack;
  v4 = varname;
  v5 = this;
  if ( !varname->pNode->Size )
    return 0;
  v7 = &this->StringContext;
  ppath.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++ppath.pNode->RefCount;
  pvar.pNode = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++pvar.pNode->RefCount;
  v33.T.Type = 0;
  params.VarName = varname;
  params.pResult = &v33;
  params.pWithStack = pwithStack;
  params.ppNewTarget = 0i64;
  params.pOwner = 0i64;
  params.ExcludeFlags = 4;
  if ( Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, &params) )
    goto LABEL_40;
  if ( Scaleform::GFx::AS2::Environment::ParsePath(v7, v4, &ppath, &pvar) )
  {
    v8 = Scaleform::GFx::AS2::Environment::FindTarget(v5, &ppath, 4u);
    if ( v8 )
    {
      v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->vfptr
                                                                        + 4 * (unsigned __int8)v8->AvmObjOffset))[1].__vecDelDtor)();
      v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v10 + 8) + 88i64))(
             v10 + 8,
             v7,
             &pvar,
             &v33);
    }
    else
    {
      v9 = 0;
    }
    goto LABEL_41;
  }
  if ( v3 )
  {
    v11 = v3->Data.Size - 1;
    v12 = v11;
    if ( v11 >= 0 )
    {
      v13 = v11;
      do
      {
        v14 = v3->Data.Data;
        if ( (v3->Data.Data[v13].BlockEndPc & 0x80000000) == 0 )
        {
          v17 = v14[v13].pObject;
          if ( !v17 )
            goto LABEL_19;
          v18 = ((__int64 (*)(void))(*(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)((char *)&v17->vfptr
                                                                                      + 4 * BYTE5(v17[1].pNext)))->Finalize_GC)();
          if ( !v18 )
            goto LABEL_19;
          v16 = v18 + 8;
        }
        else
        {
          v15 = v14[v13].pObject;
          if ( !v15 )
            goto LABEL_19;
          v16 = (signed __int64)&v15->vfptr;
        }
        if ( v16
          && (*(unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v16 + 88i64))(
               v16,
               v7,
               v4,
               &v33) )
        {
          goto LABEL_40;
        }
LABEL_19:
        --v13;
      }
      while ( --v12 >= 0 );
    }
  }
  if ( Scaleform::GFx::AS2::Environment::FindLocal(v5, v4) )
    goto LABEL_40;
  v19 = v5->Target;
  if ( v19 )
  {
    v20 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v19->vfptr
                                                                      + 4 * (unsigned __int8)v19->AvmObjOffset))[1].__vecDelDtor)();
    if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v20 + 8) + 88i64))(
           v20 + 8,
           v7,
           v4,
           &v33) )
    {
      goto LABEL_40;
    }
  }
  if ( v5->StringContext.SWFVersion <= 6u )
  {
    if ( !v4->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
    v23 = v7->pContext;
    v22 = &v4->pNode->pData;
    v24 = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v4->pNode->pLower;
    if ( v7->pContext->pMovieRoot->pASMovieRoot.pObject[20].vfptr[2].__vecDelDtor == v24
      || *(void *(__fastcall **)(Scaleform::RefCountImplCore *, unsigned int))&v23->pMovieRoot->pASMovieRoot.pObject[20].pASSupport.pObject->SType == v24
      || (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v23->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl->vfptr == v24 )
    {
      goto LABEL_40;
    }
  }
  else
  {
    v21 = v7->pContext->pMovieRoot->pASMovieRoot.pObject;
    v22 = &v4->pNode->pData;
    if ( v21[20].vfptr == (Scaleform::RefCountImplCoreVtbl *)v4->pNode
      || (const char **)v21[20].pASSupport.pObject == v22
      || (const char **)v21[20].pMovieImpl == v22 )
    {
LABEL_40:
      v9 = 1;
      goto LABEL_41;
    }
  }
  v25 = *v22;
  if ( **v22 == 95 )
  {
    ptail = 0i64;
    v26 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v25, (const char **)&ptail, v5->StringContext.SWFVersion > 6u);
    if ( v26 != -1
      && !*ptail
      && Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
           (Scaleform::GFx::AS2::MovieRoot *)v5->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
           v26) )
    {
      goto LABEL_40;
    }
  }
  v27 = v7->pContext->pGlobal.pObject;
  if ( v27 )
  {
    if ( v27->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v27->vfptr, v7, v4, &v33) )
      goto LABEL_40;
  }
  v9 = 0;
LABEL_41:
  if ( v33.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
  v28 = pvar.pNode;
  v29 = pvar.pNode->RefCount == 1;
  --v28->RefCount;
  if ( v29 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  v30 = ppath.pNode;
  v29 = ppath.pNode->RefCount == 1;
  --v30->RefCount;
  if ( v29 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  return v9;
}

// File Line: 5731
// RVA: 0x6F8070
bool __fastcall Scaleform::GFx::AS2::Environment::GetVariableRaw(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::GFx::AS2::Environment::GetVarParams *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // rax
  int v5; // ecx
  __int64 v6; // r14
  signed __int64 v7; // r15
  Scaleform::GFx::AS2::WithStackEntry *v8; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v9; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rdx
  __int64 v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rax
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Value *v16; // rbx
  Scaleform::GFx::AS2::Value *v17; // rax
  char v18; // al
  signed __int64 v19; // r13
  __int64 v20; // rcx
  unsigned __int64 v21; // r14
  Scaleform::GFx::AS2::LocalFrame *v22; // r14
  Scaleform::GFx::AS2::ArrayObject *v23; // rax
  Scaleform::GFx::AS2::ArrayObject *v24; // rax
  Scaleform::GFx::AS2::ArrayObject *v25; // r15
  int i; // ebx
  unsigned int v27; // edx
  Scaleform::GFx::AS2::Environment *v28; // r9
  Scaleform::GFx::AS2::Value *v29; // r8
  Scaleform::GFx::AS2::Value *v30; // rax
  unsigned int v31; // eax
  char v32; // al
  unsigned __int64 v33; // rcx
  Scaleform::GFx::AS2::LocalFrame *v34; // r14
  Scaleform::GFx::AS2::ObjectInterface *v35; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v36; // r14
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v37; // rcx
  __int64 v38; // rcx
  Scaleform::GFx::AS2::SuperObject *v39; // r15
  Scaleform::GFx::AS2::Object *v40; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v41; // rax
  Scaleform::GFx::AS2::Object *v42; // rax
  Scaleform::GFx::AS2::Object *v43; // rbx
  char v44; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v45; // rcx
  int v46; // edx
  Scaleform::GFx::ASStringNode *v47; // rcx
  unsigned int v48; // eax
  unsigned int v49; // eax
  unsigned int v50; // eax
  Scaleform::GFx::ASMovieRootBase *v51; // r14
  Scaleform::GFx::ASString *v52; // rbx
  bool v53; // zf
  Scaleform::GFx::InteractiveObject *v54; // rcx
  __int64 v55; // rax
  Scaleform::GFx::DisplayObject *v56; // rcx
  Scaleform::GFx::ASStringNode *v57; // rax
  Scaleform::GFx::AS2::Object *v58; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS2::Value v60; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+70h] [rbp-19h]
  __int64 v62; // [rsp+A0h] [rbp+17h]
  Scaleform::GFx::AS2::SuperObject *v63; // [rsp+A8h] [rbp+1Fh]
  Scaleform::GFx::AS2::Object *result; // [rsp+F8h] [rbp+6Fh]
  Scaleform::GFx::AS2::ArrayObject *v65; // [rsp+100h] [rbp+77h]
  __int64 v66; // [rsp+108h] [rbp+7Fh]

  v62 = -2i64;
  v2 = params;
  v3 = this;
  if ( !params->pResult )
    return 0;
  if ( params->pOwner )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(params->pOwner, &v, (__int64)params);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  v4 = v2->pWithStack;
  if ( v4 )
  {
    v5 = v4->Data.Size - 1;
    v6 = v5;
    if ( v5 >= 0 )
    {
      v7 = v5;
      while ( 1 )
      {
        v8 = v2->pWithStack->Data.Data;
        if ( (v8[v7].BlockEndPc & 0x80000000) == 0 )
        {
          v11 = v8[v7].pObject;
          if ( !v11 )
            return 0;
          v12 = ((__int64 (*)(void))(*(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)((char *)&v11->vfptr
                                                                                      + 4 * BYTE5(v11[1].pNext)))->Finalize_GC)();
          if ( !v12 )
            return 0;
          v10 = (Scaleform::GFx::AS2::ObjectInterface *)(v12 + 8);
        }
        else
        {
          v9 = (Scaleform::GFx::AS2::ObjectInterface *)v8[v7].pObject;
          if ( !v9 )
            return 0;
          v10 = v9 + 2;
        }
        if ( !v10 )
          return 0;
        if ( v10->vfptr->GetMember(v10, v3, v2->VarName, v2->pResult) )
          break;
        --v7;
        if ( --v6 < 0 )
          goto LABEL_23;
      }
      if ( v2->pOwner )
      {
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->vfptr->gap8[8])(v10) - 2 > 3 )
        {
          v14 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(v10);
          Scaleform::GFx::AS2::Value::SetAsObject(v2->pOwner, v14);
        }
        else
        {
          v13 = Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v10);
          Scaleform::GFx::AS2::Value::SetAsCharacter(v2->pOwner, v13);
        }
      }
      return 1;
    }
  }
LABEL_23:
  if ( !(v2->ExcludeFlags & 1) )
  {
    v16 = v2->pResult;
    v17 = Scaleform::GFx::AS2::Environment::FindLocal(v3, v2->VarName);
    if ( v17 )
    {
      if ( v16 )
      {
        Scaleform::GFx::AS2::Value::operator=(v16, v17, (__int64)v2);
        return 1;
      }
      if ( v17 )
        return 1;
    }
    v18 = v3->StringContext.SWFVersion;
    if ( (unsigned __int8)v18 >= 5u )
    {
      v19 = (signed __int64)&v3->StringContext;
      if ( Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
             (Scaleform::GFx::ASString *)&v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl,
             v2->VarName,
             (unsigned __int8)v18 > 6u) )
      {
        v21 = v3->LocalFrames.Data.Size;
        if ( v21 )
        {
          v22 = v3->LocalFrames.Data.Data[v21 - 1].pObject;
          if ( v22 )
          {
            result = *(Scaleform::GFx::AS2::Object **)(*(_QWORD *)v19 + 48i64);
            v23 = (Scaleform::GFx::AS2::ArrayObject *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result->vfptr[3].Finalize_GC)(
                                                        v20,
                                                        144i64,
                                                        0i64);
            v65 = v23;
            if ( v23 )
            {
              Scaleform::GFx::AS2::ArrayObject::ArrayObject(v23, v3);
              v25 = v24;
            }
            else
            {
              v25 = 0i64;
            }
            v65 = v25;
            Scaleform::GFx::AS2::ArrayObject::Resize(v25, v22->NArgs);
            for ( i = 0; i < v22->NArgs; ++i )
            {
              v27 = v22->FirstArgBottomIndex - i;
              v28 = v22->Env;
              v29 = 0i64;
              if ( v27 <= 32 * ((unsigned int)v28->Stack.Pages.Data.Size - 1)
                        + (unsigned int)((_QWORD)((char *)v28->Stack.pCurrent - (char *)v28->Stack.pPageStart) >> 5) )
                v29 = &v28->Stack.Pages.Data.Data[v27 >> 5]->Values[v27 & 0x1F];
              Scaleform::GFx::AS2::ArrayObject::SetElement(v25, i, v29);
            }
            Scaleform::GFx::AS2::Value::Value(&v60, (Scaleform::GFx::AS2::Object *)&v25->vfptr);
            Scaleform::GFx::AS2::Environment::AddLocal(
              v3,
              (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64) + 856i64),
              v30);
            if ( v60.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v60);
            LOBYTE(result) = 7;
            v25->vfptr->SetMemberRaw(
              (Scaleform::GFx::AS2::ObjectInterface *)&v25->vfptr,
              &v3->StringContext,
              (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64) + 864i64),
              &v22->Callee,
              (Scaleform::GFx::AS2::PropFlags *)&result);
            LOBYTE(result) = 7;
            v25->vfptr->SetMemberRaw(
              (Scaleform::GFx::AS2::ObjectInterface *)&v25->vfptr,
              &v3->StringContext,
              (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64) + 872i64),
              &v22->Caller,
              (Scaleform::GFx::AS2::PropFlags *)&result);
            Scaleform::GFx::AS2::Value::SetAsObject(v2->pResult, (Scaleform::GFx::AS2::Object *)&v25->vfptr);
            v31 = v25->RefCount;
            if ( !(v31 & 0x3FFFFFF) )
              return 1;
            v25->RefCount = v31 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
            return 1;
          }
        }
      }
      else
      {
        v32 = v3->StringContext.SWFVersion;
        if ( (unsigned __int8)v32 >= 6u
          && Scaleform::GFx::ASString::CompareBuiltIn_CaseCheck(
               (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64) + 808i64),
               v2->VarName,
               (unsigned __int8)v32 > 6u) )
        {
          v33 = v3->LocalFrames.Data.Size;
          if ( v33 )
          {
            v34 = v3->LocalFrames.Data.Data[v33 - 1].pObject;
            if ( v34 )
            {
              v35 = v34->SuperThis;
              if ( v35 )
              {
                result = 0i64;
                v36 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v35->pProto.pObject->vfptr;
                if ( v36 )
                  v36->RefCount = (v36->RefCount + 1) & 0x8FFFFFFF;
                v65 = (Scaleform::GFx::AS2::ArrayObject *)v36;
                if ( v36 )
                {
                  v60.T.Type = 0;
                  v37 = v2->pWithStack;
                  paramsa.VarName = (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64)
                                                               + 800i64);
                  paramsa.pResult = &v60;
                  paramsa.pWithStack = v37;
                  paramsa.ppNewTarget = 0i64;
                  paramsa.pOwner = 0i64;
                  paramsa.ExcludeFlags = 0;
                  Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(v3, &paramsa);
                  ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ASStringContext *))v36[1].vfptr[4].~RefCountBaseGC<323>)(
                    &v36[1],
                    &v,
                    &v3->StringContext);
                  v66 = *(_QWORD *)(*(_QWORD *)v19 + 48i64);
                  v39 = (Scaleform::GFx::AS2::SuperObject *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v66 + 80i64))(
                                                              v38,
                                                              144i64,
                                                              0i64);
                  v63 = v39;
                  if ( v39 )
                  {
                    v40 = (Scaleform::GFx::AS2::Object *)v36[1].pRCC;
                    v41 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v60, v3);
                    Scaleform::GFx::AS2::SuperObject::SuperObject(v39, v40, v41, (Scaleform::GFx::AS2::FunctionRef *)&v);
                    v43 = v42;
                  }
                  else
                  {
                    v43 = 0i64;
                  }
                  result = v43;
                  Scaleform::GFx::AS2::Value::SetAsObject(v2->pResult, v43);
                  Scaleform::GFx::AS2::Environment::SetLocal(
                    v3,
                    (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v19 + 40i64) + 24i64) + 808i64),
                    v2->pResult);
                  v44 = *((_BYTE *)&v.NV + 16);
                  if ( !(*((char *)&v.NV + 16) & 2) )
                  {
                    v45 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v.T.Type;
                    if ( *(_QWORD *)&v.T.Type )
                    {
                      v46 = *(_DWORD *)(*(_QWORD *)&v.T.Type + 24i64);
                      if ( v46 & 0x3FFFFFF )
                      {
                        *(_DWORD *)(*(_QWORD *)&v.T.Type + 24i64) = v46 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v45);
                        v44 = *((_BYTE *)&v.NV + 16);
                      }
                    }
                  }
                  *(_QWORD *)&v.T.Type = 0i64;
                  if ( !(v44 & 1) )
                  {
                    v47 = v.V.pStringNode;
                    if ( v.V.pStringNode )
                    {
                      v48 = v.V.pStringNode->RefCount;
                      if ( v48 & 0x3FFFFFF )
                      {
                        v.V.pStringNode->RefCount = v48 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v47);
                      }
                    }
                  }
                  v.V.pStringNode = 0i64;
                  if ( v60.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v60);
                  v49 = v36->RefCount;
                  if ( v49 & 0x3FFFFFF )
                  {
                    v36->RefCount = v49 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
                  }
                  if ( !v43 )
                    return 1;
                  v50 = v43->RefCount;
                  if ( !(v50 & 0x3FFFFFF) )
                    return 1;
                  v43->RefCount = v50 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v43->vfptr);
                  return 1;
                }
              }
            }
          }
        }
      }
    }
    v51 = v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v52 = v2->VarName;
    if ( v3->StringContext.SWFVersion <= 6u )
    {
      if ( !v52->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v52->pNode);
      v53 = v51[20].vfptr[2].__vecDelDtor == (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v52->pNode->pLower;
    }
    else
    {
      v53 = v51[20].vfptr == (Scaleform::RefCountImplCoreVtbl *)v52->pNode;
    }
    if ( v53 )
    {
      Scaleform::GFx::AS2::Value::SetAsCharacter(v2->pResult, v3->Target);
      return 1;
    }
  }
  v54 = v3->Target;
  if ( !v54 )
    return 0;
  v55 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v54->vfptr
                                                                    + 4 * (unsigned __int8)v54->AvmObjOffset))[1].__vecDelDtor)();
  if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v55 + 8) + 88i64))(
         v55 + 8,
         &v3->StringContext,
         v2->VarName,
         v2->pResult) )
  {
    if ( !v2->pOwner )
      return 1;
    v56 = (Scaleform::GFx::DisplayObject *)&v3->Target->vfptr;
    v.T.Type = 7;
    if ( v56 )
    {
      v57 = (Scaleform::GFx::ASStringNode *)v56->pNameHandle.pObject;
      if ( !v57 )
        v57 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v56);
      v.V.pStringNode = v57;
      if ( v57 )
        ++LODWORD(v57->pData);
    }
    else
    {
      v.V.pStringNode = 0i64;
    }
    Scaleform::GFx::AS2::Value::operator=(v2->pOwner, &v, (__int64)v2);
    if ( v.T.Type < 5u )
      return 1;
    Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 1;
  }
  v58 = v3->StringContext.pContext->pGlobal.pObject;
  if ( !(v2->ExcludeFlags & 2) )
  {
    if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v2->VarName->pNode) )
    {
      if ( *v2->VarName->pNode->pData == 95 )
      {
        Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(v3, (Scaleform::GFx::Bool3W *)&result, v2);
        if ( (_BYTE)result )
          return (_BYTE)result == 1;
      }
    }
  }
  if ( !v58 || !v58->vfptr->GetMember((Scaleform::GFx::AS2::ObjectInterface *)&v58->vfptr, v3, v2->VarName, v2->pResult) )
  {
    if ( !(v2->ExcludeFlags & 4) )
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v3->vfptr,
        "GetVariableRaw(\"%s\") failed, returning UNDEFINED.\n",
        v2->VarName->pNode->pData);
    return 0;
  }
  if ( !v2->pOwner )
    return 1;
  Scaleform::GFx::AS2::Value::Value(&v60, v58);
  Scaleform::GFx::AS2::Value::operator=(v2->pOwner, &v60, (__int64)v2);
  if ( v60.T.Type < 5u )
    return 1;
  Scaleform::GFx::AS2::Value::DropRefs(&v60);
  return 1;
}

// File Line: 5884
// RVA: 0x6DD030
Scaleform::GFx::Bool3W *__fastcall Scaleform::GFx::AS2::Environment::CheckGlobalAndLevels(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::Bool3W *result, Scaleform::GFx::AS2::Environment::GetVarParams *params)
{
  Scaleform::GFx::ASStringNode ***v3; // rdi
  Scaleform::GFx::Bool3W *v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // rsi
  Scaleform::GFx::AS2::GlobalContext *v6; // rdx
  Scaleform::GFx::ASMovieRootBase *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // r8
  Scaleform::GFx::Sprite *v9; // rax
  Scaleform::GFx::ASString *v10; // r14
  Scaleform::GFx::ASMovieRootBase *v11; // rbp
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode **v13; // r14
  Scaleform::GFx::ASMovieRootBase *v14; // rbp
  Scaleform::GFx::ASStringNode *v15; // rcx
  const char **v16; // rcx
  bool v17; // r8
  int v18; // eax
  char *ptail; // [rsp+40h] [rbp+8h]

  v3 = (Scaleform::GFx::ASStringNode ***)params;
  v4 = result;
  v5 = this;
  if ( this->StringContext.SWFVersion <= 6u )
  {
    v10 = params->VarName;
    v11 = this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v12 = params->VarName->pNode;
    if ( !v12->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v12);
    if ( *(Scaleform::GFx::ASStringNode **)&v11[20].pASSupport.pObject->SType == v10->pNode->pLower )
      goto LABEL_3;
    v13 = *v3;
    v14 = v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v15 = **v3;
    if ( !v15->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15);
    if ( v14[20].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)(*v13)->pLower )
    {
      v6 = v5->StringContext.pContext;
      goto LABEL_6;
    }
LABEL_14:
    v16 = (const char **)**v3;
    v17 = v5->StringContext.SWFVersion > 6u;
    ptail = 0i64;
    v18 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(*v16, (const char **)&ptail, v17);
    if ( v18 == -1 || *ptail )
    {
      v4->Value = 0;
      return v4;
    }
    v9 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
           (Scaleform::GFx::AS2::MovieRoot *)v5->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
           v18);
    if ( !v9 )
    {
      v4->Value = 2;
      return v4;
    }
    goto LABEL_4;
  }
  v6 = this->StringContext.pContext;
  v7 = v6->pMovieRoot->pASMovieRoot.pObject;
  v8 = params->VarName->pNode;
  if ( (Scaleform::GFx::ASStringNode *)v7[20].pASSupport.pObject != v8 )
  {
    if ( (Scaleform::GFx::ASStringNode *)v7[20].pMovieImpl == v8 )
    {
LABEL_6:
      Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)v3[1], v6->pGlobal.pObject);
      v4->Value = 1;
      return v4;
    }
    goto LABEL_14;
  }
LABEL_3:
  v9 = (Scaleform::GFx::Sprite *)v5->Target->vfptr[68].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v5->Target, 0);
LABEL_4:
  Scaleform::GFx::AS2::Value::SetAsCharacter(
    (Scaleform::GFx::AS2::Value *)v3[1],
    (Scaleform::GFx::InteractiveObject *)&v9->vfptr);
  v4->Value = 1;
  return v4;
}

// File Line: 5936
// RVA: 0x6EB1C0
bool __fastcall Scaleform::GFx::AS2::Environment::FindOwnerOfMember(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::GFx::AS2::Value *presult, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // r14
  Scaleform::GFx::ASString *v6; // r12
  Scaleform::GFx::AS2::Environment *v7; // rbp
  bool result; // al
  int v9; // eax
  __int64 v10; // rdi
  signed __int64 v11; // rsi
  Scaleform::GFx::AS2::WithStackEntry *v12; // rcx
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::InteractiveObject **v14; // rbx
  Scaleform::GFx::AS2::Object *v15; // rdx
  __int64 v16; // rax
  Scaleform::GFx::InteractiveObject *v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::DisplayObject *v19; // rcx
  Scaleform::GFx::CharacterHandle *v20; // rbx
  Scaleform::GFx::AS2::Object *v21; // rbx

  v4 = pwithStack;
  v5 = presult;
  v6 = varname;
  v7 = this;
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
        v12 = v4->Data.Data;
        if ( (v4->Data.Data[v11].BlockEndPc & 0x80000000) == 0 )
        {
          v15 = v12[v11].pObject;
          if ( !v15 )
            goto LABEL_14;
          v16 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)((char *)&v15->vfptr + 4 * BYTE5(v15[1].pNext)))->Finalize_GC)((signed __int64)v15 + 4 * BYTE5(v15[1].pNext));
          if ( !v16 )
            goto LABEL_14;
          v14 = (Scaleform::GFx::InteractiveObject **)(v16 + 8);
        }
        else
        {
          v13 = v12[v11].pObject;
          if ( !v13 )
            goto LABEL_14;
          v14 = (Scaleform::GFx::InteractiveObject **)&v13->vfptr;
        }
        if ( v14
          && ((unsigned __int64 (__fastcall *)(Scaleform::GFx::InteractiveObject **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*v14)->pRenNode.pObject)(
               v14,
               &v7->StringContext,
               v6,
               0i64) )
        {
          if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject **))(*v14)->pWeakProxy)(v14) - 2 > 3 )
          {
            Scaleform::GFx::AS2::Value::SetAsObject(v5, (Scaleform::GFx::AS2::Object *)(v14 - 4));
            result = 1;
          }
          else
          {
            if ( ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject **))(*v14)->pWeakProxy)(v14) - 2 > 3 )
              Scaleform::GFx::AS2::Value::SetAsCharacter(v5, 0i64);
            else
              Scaleform::GFx::AS2::Value::SetAsCharacter(v5, v14[2]);
            result = 1;
          }
          return result;
        }
LABEL_14:
        --v11;
        --v10;
      }
      while ( v10 >= 0 );
    }
  }
  v17 = v7->Target;
  if ( !v17 )
    return 0;
  v18 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v17->vfptr
                                                                    + 4 * (unsigned __int8)v17->AvmObjOffset))[1].__vecDelDtor)();
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)(v18 + 8) + 72i64))(
          v18 + 8,
          &v7->StringContext,
          v6,
          0i64) )
  {
    v21 = v7->StringContext.pContext->pGlobal.pObject;
    if ( v21 && v21->vfptr->HasMember((Scaleform::GFx::AS2::ObjectInterface *)&v21->vfptr, &v7->StringContext, v6, 0) )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(v5, v21);
      return 1;
    }
    return 0;
  }
  v19 = (Scaleform::GFx::DisplayObject *)&v7->Target->vfptr;
  if ( v19 )
  {
    v20 = v19->pNameHandle.pObject;
    if ( !v20 )
      v20 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v19);
  }
  else
  {
    v20 = 0i64;
  }
  if ( v5->T.Type != 7 || v5->V.pCharHandle != v20 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 7;
    v5->V.pStringNode = (Scaleform::GFx::ASStringNode *)v20;
    if ( v20 )
      ++v20->RefCount;
  }
  return 1;
}

// File Line: 5986
// RVA: 0x71D1F0
char __fastcall Scaleform::GFx::AS2::Environment::SetVariable(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::GFx::AS2::Value *val, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack, bool doDisplayErrors)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v5; // r15
  Scaleform::GFx::AS2::Value *v6; // r14
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS2::Environment *v8; // rbx
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned int v12; // ecx
  const char *v13; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::Value v18; // [rsp+38h] [rbp-49h]
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp-29h]
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [rsp+78h] [rbp-9h]
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+5Fh]
  Scaleform::GFx::ASString varName; // [rsp+E8h] [rbp+67h]

  v5 = pwithStack;
  v6 = val;
  v7 = varname;
  v8 = this;
  if ( (this->Target->pASRoot->pMovieImpl->Flags >> 2) & 1 )
  {
    Scaleform::GFx::AS2::Value::Value(&v19, val, (__int64)varname);
    Scaleform::GFx::AS2::Value::ToDebugString(v9, &result, v8);
    if ( v19.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
      (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v8->vfptr,
      "-------------- %s = %s\n",
      v7->pNode->pData,
      result.pNode->pData);
    v10 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( (v7->pNode->HashFlags >> 25) & 1 )
    goto LABEL_32;
  v12 = v7->pNode->HashFlags;
  if ( !_bittest((const signed int *)&v12, 0x1Au) )
  {
    v13 = v7->pNode->pData;
    if ( !strchr(v13, 58) && !strchr(v13, 47) && !strchr(v13, 46) )
    {
      v7->pNode->HashFlags |= 0x6000000u;
LABEL_32:
      Scaleform::GFx::AS2::Environment::SetVariableRaw(v8, v7, v6, v5);
      return 1;
    }
    v7->pNode->HashFlags |= 0x4000000u;
  }
  v18.T.Type = 0;
  varName.pNode = *(Scaleform::GFx::ASStringNode **)&v8->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++varName.pNode->RefCount;
  v19.T.Type = 0;
  params.VarName = v7;
  params.pResult = &v19;
  params.pWithStack = v5;
  params.ppNewTarget = 0i64;
  params.pOwner = &v18;
  params.ExcludeFlags = 0;
  Scaleform::GFx::AS2::Environment::FindVariable(v8, &params, 0, &varName);
  if ( v18.T.Type && v18.T.Type != 10 )
  {
    v14 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v18, v8);
    if ( v14 )
    {
      LOBYTE(result.pNode) = 0;
      v14->vfptr->SetMember(v14, v8, &varName, v6, (Scaleform::GFx::AS2::PropFlags *)&result);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
      v15 = varName.pNode;
      v11 = varName.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
      return 1;
    }
  }
  else if ( doDisplayErrors
         && v8->vfptr->IsVerboseActionErrors((Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v8->vfptr) )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v8,
      "SetVariable failed: can't resolve the path \"%s\"",
      v7->pNode->pData);
  }
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v16 = varName.pNode;
  v11 = varName.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  return 0;
}

// File Line: 6030
// RVA: 0x71DEE0
void __usercall Scaleform::GFx::AS2::Environment::SetVariableRaw(Scaleform::GFx::AS2::Environment *this@<rcx>, Scaleform::GFx::ASString *varname@<rdx>, Scaleform::GFx::AS2::Value *val@<r8>, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack@<r9>, __int64 a5@<rdi>)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v5; // r15
  Scaleform::GFx::AS2::Value *v6; // r13
  Scaleform::GFx::ASString *v7; // r12
  Scaleform::GFx::AS2::Environment *v8; // r14
  __int64 v9; // rbp
  int v10; // er10
  signed __int64 v11; // rsi
  Scaleform::GFx::AS2::WithStackEntry *v12; // rcx
  Scaleform::GFx::AS2::Object *v13; // rbx
  signed __int64 v14; // rbx
  Scaleform::GFx::AS2::Object *v15; // rdx
  __int64 v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::InteractiveObject *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+38h] [rbp-50h]
  char v20; // [rsp+A8h] [rbp+20h]

  v5 = pwithStack;
  v6 = val;
  v7 = varname;
  v8 = this;
  v9 = 0i64;
  if ( !pwithStack || (v10 = pwithStack->Data.Size - 1, a5 = v10, v10 < 0) )
  {
LABEL_18:
    v17 = Scaleform::GFx::AS2::Environment::FindLocal(v8, v7);
    if ( v17 )
    {
      Scaleform::GFx::AS2::Value::operator=(v17, v6, a5);
    }
    else
    {
      v18 = v8->Target;
      if ( v18 )
        v9 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v18->vfptr
                                                                         + 4 * (unsigned __int8)v18->AvmObjOffset))[1].__vecDelDtor)();
      v20 = 0;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)(v9 + 8) + 24i64))(
        v9 + 8,
        v8,
        v7,
        v6,
        &v20);
    }
    return;
  }
  v11 = v10;
  while ( 1 )
  {
    v12 = v5->Data.Data;
    if ( (v5->Data.Data[v11].BlockEndPc & 0x80000000) == 0 )
    {
      v15 = v12[v11].pObject;
      if ( !v15
        || (v16 = ((__int64 (*)(void))(*(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)((char *)&v15->vfptr
                                                                                        + 4 * BYTE5(v15[1].pNext)))->Finalize_GC)(),
            v14 = v16 + 8,
            !v16) )
      {
LABEL_9:
        v14 = 0i64;
        goto LABEL_10;
      }
    }
    else
    {
      v13 = v12[v11].pObject;
      if ( !v13 )
        goto LABEL_9;
      v14 = (signed __int64)&v13->vfptr;
    }
LABEL_10:
    v19.T.Type = 0;
    if ( v14 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v14 + 32i64))(
             v14,
             v8,
             v7,
             &v19) )
      {
        break;
      }
    }
    if ( v19.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    --v11;
    if ( --a5 < 0 )
      goto LABEL_18;
  }
  v20 = 0;
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v14 + 24i64))(
    v14,
    v8,
    v7,
    v6,
    &v20);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
}

// File Line: 6063
// RVA: 0x714E90
void __fastcall Scaleform::GFx::AS2::Environment::SetLocal(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Environment *v3; // rbx
  unsigned __int64 v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // rax

  v3 = this;
  v4 = this->LocalFrames.Data.Size;
  v5 = val;
  v6 = varname;
  if ( v4 && v3->LocalFrames.Data.Data[v4 - 1].pObject )
  {
    v7 = Scaleform::GFx::AS2::Environment::FindLocal(v3, varname);
    if ( v7 )
      Scaleform::GFx::AS2::Value::operator=(v7, v5, (__int64)v5);
    else
      Scaleform::GFx::AS2::Environment::AddLocal(v3, v6, v5);
  }
}

// File Line: 6093
// RVA: 0x6D9060
void __fastcall Scaleform::GFx::AS2::Environment::AddLocal(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v3; // rbx
  Scaleform::GFx::AS2::LocalFrame *v4; // r9
  Scaleform::GFx::AS2::LocalFrame *v5; // rbx
  unsigned int v6; // eax

  v3 = &this->LocalFrames.Data.Data[this->LocalFrames.Data.Size];
  v4 = v3[-1].pObject;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
  v5 = v3[-1].pObject;
  if ( v5 )
    Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
      (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&v5->Variables.mHash,
      varname,
      val,
      this->StringContext.SWFVersion > 6u);
  if ( v5 )
  {
    v6 = v5->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v5->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 6110
// RVA: 0x6E1B70
void __fastcall Scaleform::GFx::AS2::Environment::DeclareLocal(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rbx
  unsigned __int64 v4; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h]

  v2 = varname;
  v3 = this;
  v4 = this->LocalFrames.Data.Size;
  if ( v4 && v3->LocalFrames.Data.Data[v4 - 1].pObject && !Scaleform::GFx::AS2::Environment::FindLocal(v3, varname) )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::AddLocal(v3, v2, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
}

// File Line: 6141
// RVA: 0x7021A0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::LocalRegisterPtr(Scaleform::GFx::AS2::Environment *this, unsigned int reg)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  unsigned __int64 v3; // rax

  v2 = this;
  v3 = this->LocalRegister.Data.Size;
  if ( reg < v3 )
    return &this->LocalRegister.Data.Data[v3 - reg - 1];
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
    (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    "Invalid local register %d, stack only has %d entries",
    reg,
    (unsigned int)v3);
  return v2->GlobalRegister;
}

// File Line: 6159
// RVA: 0x6EAE50
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::FindLocal(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *varname)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rbp
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::AS2::LocalFrame *v6; // rbx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v7; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > v8; // rsi
  signed __int64 v9; // rax
  signed __int64 v10; // rsi
  signed int v11; // esi
  Scaleform::GFx::ASMovieRootBase *v12; // r14
  bool v13; // zf
  Scaleform::GFx::ASMovieRootBase *v14; // rsi
  bool v15; // zf
  Scaleform::GFx::AS2::LocalFrame *v16; // rcx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ecx

  v2 = varname;
  v3 = this;
  v4 = this->LocalFrames.Data.Size;
  if ( !v4 )
    return 0i64;
  v5 = 0i64;
  if ( v4 )
  {
    v6 = this->LocalFrames.Data.Data[v4 - 1].pObject;
    if ( v6 )
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !v6 )
  {
LABEL_36:
    if ( v6 )
    {
      v19 = v6->RefCount;
      if ( v19 & 0x3FFFFFF )
      {
        v6->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
      }
    }
    return v5;
  }
  do
  {
    v7 = (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&v6->Variables.mHash;
    if ( v3->StringContext.SWFVersion <= 6u )
    {
      v5 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
             v7,
             v2);
    }
    else
    {
      v8.mHash.pTable = v7->mHash.pTable;
      if ( !v7->mHash.pTable )
        goto LABEL_14;
      v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v7->mHash.pTable,
             v2,
             v2->pNode->HashFlags & v8.mHash.pTable->SizeMask);
      if ( v9 < 0 )
        goto LABEL_14;
      v10 = (signed __int64)&v8.mHash.pTable[3 * v9 + 1].SizeMask;
      if ( !v10 )
        goto LABEL_14;
      v5 = (Scaleform::GFx::AS2::Value *)(v10 + 8);
    }
    if ( v5 )
      goto LABEL_36;
LABEL_14:
    v11 = (unsigned __int8)v3->StringContext.SWFVersion;
    if ( v11 >= 5 )
    {
      v12 = v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( (unsigned __int8)v11 <= 6u )
      {
        if ( !v2->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v2->pNode);
        v13 = v12[21].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)v2->pNode->pLower;
      }
      else
      {
        v13 = v12[21].pMovieImpl == (Scaleform::GFx::MovieImpl *)v2->pNode;
      }
      if ( v13 )
        break;
    }
    if ( v11 >= 6 )
    {
      v14 = v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( v3->StringContext.SWFVersion <= 6u )
      {
        if ( !v2->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v2->pNode);
        v15 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v14[20].RefCount + 16i64) == v2->pNode->pLower;
      }
      else
      {
        v15 = *(Scaleform::GFx::ASStringNode **)&v14[20].RefCount == v2->pNode;
      }
      if ( v15 )
        break;
    }
    v16 = v6->PrevFrame.pObject;
    if ( v16 )
      v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
    v17 = v6->RefCount;
    if ( v17 & 0x3FFFFFF )
    {
      v6->RefCount = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
    v6 = v6->PrevFrame.pObject;
  }
  while ( v6 );
  if ( v6 )
  {
    v18 = v6->RefCount;
    if ( v18 & 0x3FFFFFF )
    {
      v6->RefCount = v18 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return 0i64;
}

// File Line: 6187
// RVA: 0x6F6A40
Scaleform::GFx::AS2::LocalFrame *__fastcall Scaleform::GFx::AS2::Environment::GetTopLocalFrame(Scaleform::GFx::AS2::Environment *this, int off)
{
  Scaleform::GFx::AS2::LocalFrame *result; // rax

  if ( this->LocalFrames.Data.Size == off )
    result = 0i64;
  else
    result = this->LocalFrames.Data.Data[this->LocalFrames.Data.Size - off - 1].pObject;
  return result;
}

// File Line: 6196
// RVA: 0x6E0160
Scaleform::GFx::AS2::RefCountBaseGC<323> *__fastcall Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v1; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rdi
  unsigned __int64 v3; // rcx
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v5; // rdx
  unsigned int v6; // ecx

  v1 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)this;
  v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->StringContext.pContext->pHeap->vfptr->Alloc(
                                                     (Scaleform::MemoryHeap *)this,
                                                     136ui64,
                                                     0i64);
  if ( v2 )
  {
    v3 = v1[9].Size;
    if ( v3 )
      v4 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((*(__int64 (**)(void))(*(_QWORD *)(v3 + 4i64 * *(unsigned __int8 *)(v3 + 109)) + 8i64))()
                                                                                               + 24)
                                                                                   + 32i64)
                                                                       + 56i64)
                                                           + 32i64);
    else
      v4 = 0i64;
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
    v2->pRCC = v4;
    v2->RefCount = 1;
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::LocalFrame>::`vftable';
    v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LocalFrame::`vftable';
    v2[1].vfptr = 0i64;
    v2[1].pRCC = 0i64;
    v2[1].pPrev = 0i64;
    *(_QWORD *)&v2[1].RefCount = 0i64;
    v2[2].vfptr = 0i64;
    LOBYTE(v2[2].pRCC) = 0;
    LOBYTE(v2[3].pRCC) = 0;
  }
  else
  {
    v2 = 0i64;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v1 + 16,
    &v1[16],
    v1[16].Size + 1);
  v5 = &v1[16].Data[v1[16].Size - 1];
  if ( v5 )
  {
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    v5->pObject = (Scaleform::GFx::AS2::Object *)v2;
  }
  if ( v2 )
  {
    v6 = v2->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v2->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
  return v2;
}

// File Line: 6219
// RVA: 0x707CC0
bool __fastcall Scaleform::GFx::AS2::Environment::ParsePath(Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *varPath, Scaleform::GFx::ASString *ppath, Scaleform::GFx::ASString *pvar)
{
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::ASString *v5; // rsi
  const char ***v6; // r15
  Scaleform::GFx::AS2::ASStringContext *v7; // rbp
  signed int v8; // ebx
  const char *v9; // rdi
  char *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  char *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // sf
  Scaleform::GFx::ASStringNode *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  const char **v22; // rbx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v4 = pvar;
  v5 = ppath;
  v6 = (const char ***)varPath;
  v7 = psc;
  v8 = -1;
  v9 = varPath->pNode->pData;
  v10 = strchr(v9, 58);
  if ( !v10 )
  {
    v10 = strrchr(v9, 46);
    if ( !v10 )
    {
      v15 = strrchr(v9, 47);
      if ( !v15 )
        return (char)v15;
      goto LABEL_9;
    }
  }
  v8 = (_DWORD)v10 - (_DWORD)v9;
  if ( (signed int)v10 - (signed int)v9 < 0 )
  {
LABEL_9:
    v16 = *(Scaleform::GFx::ASStringNode **)&v7->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v16->RefCount;
    v17 = v4->pNode;
    v13 = v4->pNode->RefCount == 1;
    --v17->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    v4->pNode = v16;
    goto LABEL_12;
  }
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateString(v7, &result, &(**v6)[v8 + 1])->pNode;
  ++v11->RefCount;
  v12 = v4->pNode;
  v13 = v4->pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v4->pNode = v11;
  v14 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_12:
  v18 = v8 < 0;
  if ( v8 > 0 )
  {
    if ( (**v6)[v8 - 1] == 47 )
      --v8;
    v18 = v8 < 0;
  }
  if ( v18 )
  {
    v22 = *v6;
    ++*((_DWORD *)v22 + 6);
    v23 = v5->pNode;
    v13 = v5->pNode->RefCount == 1;
    --v23->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    v5->pNode = (Scaleform::GFx::ASStringNode *)v22;
  }
  else
  {
    v19 = Scaleform::GFx::AS2::ASStringContext::CreateString(v7, &result, **v6, v8)->pNode;
    ++v19->RefCount;
    v20 = v5->pNode;
    v13 = v5->pNode->RefCount == 1;
    --v20->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    v5->pNode = v19;
    v21 = result.pNode;
    v13 = result.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  }
  LOBYTE(v15) = 1;
  return (char)v15;
}

// File Line: 6266
// RVA: 0x700B50
bool __fastcall Scaleform::GFx::AS2::Environment::IsPath(Scaleform::GFx::ASString *varPath)
{
  Scaleform::GFx::ASStringNode *v1; // rax
  Scaleform::GFx::ASString *v2; // rbx
  bool result; // al
  const char *v4; // rdi

  v1 = varPath->pNode;
  v2 = varPath;
  if ( varPath->pNode->HashFlags & 0x4000000 )
    return 1;
  v4 = v1->pData;
  if ( strchr(v1->pData, 58) || strchr(v4, 47) || strchr(v4, 46) )
  {
    v2->pNode->HashFlags |= 0x4000000u;
    result = 1;
  }
  else
  {
    v2->pNode->HashFlags |= 0x6000000u;
    result = 0;
  }
  return result;
}

// File Line: 6295
// RVA: 0x6EB650
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Environment::FindTargetByValue(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rcx
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::InteractiveObject *v5; // rdx
  char v6; // cl
  Scaleform::GFx::InteractiveObject *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::InteractiveObject *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASString result; // [rsp+48h] [rbp+10h]

  v2 = this;
  if ( val->T.Type == 7 )
  {
    if ( this )
    {
      v3 = val->V.pStringNode;
      if ( v3 )
      {
        v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)v3,
               v2->Target->pASRoot->pMovieImpl);
        v5 = (Scaleform::GFx::InteractiveObject *)v4;
        if ( v4 )
        {
          v6 = LOBYTE(v4->Flags) >> 7;
          v7 = 0i64;
          if ( v6 & 1 )
            v7 = v5;
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
  v9 = Scaleform::GFx::AS2::Environment::FindTarget(v2, v8, 0);
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  return v9;
}

// File Line: 6340
// RVA: 0x703210
char __fastcall Scaleform::GFx::AS2::Environment::NeedTermination(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::InteractiveObject *v2; // rax
  char result; // al

  if ( (execType == Exec_Unknown || execType == 3) && ((v2 = this->Target, v2->Flags & 0x1000) || v2->Depth < -1) )
    result = 1;
  else
    result = (LOBYTE(this->Target->Flags) >> 4) & 1;
  return result;
}

// File Line: 6406
// RVA: 0x703250
char __fastcall Scaleform::GFx::AS2::StringTokenizer::NextToken(Scaleform::GFx::AS2::StringTokenizer *this, char *sep)
{
  char *v2; // rsi
  Scaleform::GFx::AS2::StringTokenizer *v3; // rbx
  const char *v4; // rdi
  const char *v6; // r9
  Scaleform::GFx::ASStringNode *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rdi
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = sep;
  v3 = this;
  v4 = this->Str;
  if ( this->Str >= this->EndStr )
    return 0;
  do
  {
    if ( strchr(v3->Delimiters, *v3->Str) )
      break;
    ++v3->Str;
  }
  while ( v3->Str < v3->EndStr );
  *v2 = *v3->Str;
  v6 = v3->Str;
  if ( v4 == v3->Str || v6 > v3->EndStr )
  {
    v10 = Scaleform::GFx::ASStringManager::CreateEmptyString(v3->Token.pNode->pManager, &result)->pNode;
    ++v10->RefCount;
    v11 = v3->Token.pNode;
    v9 = v11->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v3->Token.pNode = v10;
  }
  else
  {
    v7 = Scaleform::GFx::ASStringManager::CreateString(v3->Token.pNode->pManager, &result, v4, v6 - v4)->pNode;
    ++v7->RefCount;
    v8 = v3->Token.pNode;
    v9 = v8->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v3->Token.pNode = v7;
  }
  v12 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  ++v3->Str;
  return 1;
}

// File Line: 6447
// RVA: 0x6EB710
char __fastcall Scaleform::GFx::AS2::Environment::FindVariable(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Environment::GetVarParams *params, bool onlyTargets, Scaleform::GFx::ASString *varName)
{
  Scaleform::GFx::AS2::Environment::GetVarParams *v4; // r14
  Scaleform::GFx::AS2::Environment *v5; // r12
  Scaleform::GFx::AS2::Value *v6; // rcx
  char v8; // bl
  char v9; // r13
  Scaleform::GFx::ASStringNode *v10; // rax
  char *v11; // rsi
  __int64 v12; // r15
  Scaleform::GFx::AS2::Value *v13; // rdi
  Scaleform::GFx::InteractiveObject **v14; // rax
  Scaleform::GFx::InteractiveObject *v15; // r14
  Scaleform::GFx::DisplayObject *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rdi
  char *v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // rcx
  char *v20; // rax
  const char *v21; // rsi
  char v22; // r15
  Scaleform::GFx::ASStringNode *v23; // rsi
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rsi
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASStringNode *v28; // rsi
  Scaleform::GFx::ASStringNode *v29; // rcx
  char v30; // r15
  Scaleform::GFx::ASMovieRootBase *v31; // rsi
  Scaleform::GFx::ASStringNode *v32; // rdx
  bool v33; // zf
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v34; // rax
  unsigned __int64 v35; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v36; // rsi
  Scaleform::GFx::DisplayObject *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rsi
  Scaleform::GFx::AS2::Value *v39; // rax
  Scaleform::GFx::AS2::Object *v40; // rax
  signed __int64 v41; // rcx
  Scaleform::GFx::DisplayObject *v42; // rax
  Scaleform::GFx::DisplayObject *v43; // rcx
  __int64 v44; // rax
  Scaleform::GFx::DisplayObject *v45; // rax
  Scaleform::GFx::ASStringNode *v46; // rsi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v47; // rax
  Scaleform::GFx::DisplayObject *v48; // rax
  Scaleform::GFx::DisplayObject *v49; // rcx
  __int64 v50; // rax
  Scaleform::GFx::AS2::Value *v51; // rcx
  Scaleform::GFx::DisplayObject *v52; // rax
  Scaleform::GFx::DisplayObject *v53; // rcx
  __int64 v54; // rax
  Scaleform::GFx::AS2::ObjectInterface *v55; // rcx
  Scaleform::GFx::AS2::Object *v56; // rax
  Scaleform::GFx::DisplayObject *v57; // rax
  Scaleform::GFx::InteractiveObject *v58; // rcx
  Scaleform::GFx::AS2::Value *v59; // rdi
  Scaleform::GFx::InteractiveObject **v60; // rax
  Scaleform::GFx::ASStringNode *v61; // rdi
  Scaleform::GFx::ASStringNode *v62; // rcx
  Scaleform::GFx::DisplayObject *v63; // rax
  Scaleform::GFx::AS2::Value *v64; // rdi
  char v65; // di
  Scaleform::GFx::AS2::Value *v66; // rcx
  Scaleform::GFx::ASStringNode *v67; // rcx
  char sep; // [rsp+20h] [rbp-E0h]
  char v69; // [rsp+21h] [rbp-DFh]
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-D8h]
  char *pstr; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v72; // [rsp+50h] [rbp-B0h]
  char *string; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::ASStringNode *v74; // [rsp+60h] [rbp-A0h]
  const char *v75; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::Value v76; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::ASString v78; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS2::FnCall v79; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS2::Value v80; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS2::Environment::GetVarParams paramsa; // [rsp+100h] [rbp+0h]
  __int64 v82; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS2::Value v83; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::AS2::Environment::GetVarParams *v84; // [rsp+1A8h] [rbp+A8h]
  bool v85; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::ASString *v86; // [rsp+1B8h] [rbp+B8h]

  v86 = varName;
  v85 = onlyTargets;
  v84 = params;
  v82 = -2i64;
  v4 = params;
  v5 = this;
  if ( !params->VarName->pNode->Size )
  {
    v6 = params->pResult;
    if ( v6 )
      Scaleform::GFx::AS2::Value::SetAsCharacter(v6, v5->Target);
    return 1;
  }
  v8 = 0;
  v.T.Type = 0;
  v9 = 0;
  v10 = params->VarName->pNode;
  v11 = (char *)v10->pData;
  v12 = v10->Size;
  v13 = params->pOwner;
  if ( v13 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
    v13->T.Type = 0;
  }
  v14 = v4->ppNewTarget;
  v15 = 0i64;
  if ( v14 )
    *v14 = 0i64;
  if ( *v11 == 47 )
  {
    v16 = (Scaleform::GFx::DisplayObject *)v5->Target->vfptr[68].__vecDelDtor(
                                             (Scaleform::RefCountNTSImplCore *)v5->Target,
                                             0);
    if ( v16 )
    {
      v17 = (Scaleform::GFx::ASStringNode *)v16->pNameHandle.pObject;
      if ( !v17 )
        v17 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
    }
    else
    {
      v17 = 0i64;
    }
    Scaleform::GFx::AS2::Value::DropRefs(&v);
    v8 = 7;
    v.T.Type = 7;
    v.V.pStringNode = v17;
    if ( v17 )
      ++LODWORD(v17->pData);
    v9 = 1;
    ++v11;
    --v12;
    v18 = (char *)onlySlashesDelim;
    v75 = onlySlashesDelim;
    v19 = v84->pOwner;
    if ( !v19 )
      goto LABEL_22;
    Scaleform::GFx::AS2::Value::operator=(v19, &v, (__int64)v17);
    v8 = v.T.Type;
    v18 = (char *)v75;
  }
  else
  {
    v18 = ":./";
    if ( *v11 == 46 )
      v18 = (char *)onlySlashesDelim;
    v75 = v18;
  }
  v17 = v.V.pStringNode;
LABEL_22:
  pstr = v11;
  v72 = (unsigned __int64)&v11[v12];
  string = v18;
  v74 = *(Scaleform::GFx::ASStringNode **)&v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++v74->RefCount;
  sep = 1;
  v20 = pstr;
  while ( (unsigned __int64)v20 < v72 )
  {
    v21 = v20;
    do
    {
      v33 = strchr(string, *v20) == 0i64;
      v20 = pstr;
      if ( !v33 )
        break;
      v20 = pstr + 1;
      pstr = v20;
    }
    while ( (unsigned __int64)v20 < v72 );
    v22 = *v20;
    v69 = *v20;
    if ( v21 == v20 || (unsigned __int64)v20 > v72 )
    {
      v26 = Scaleform::GFx::ASStringManager::CreateEmptyString(v74->pManager, &v78)->pNode;
      ++v26->RefCount;
      v27 = v74;
      v33 = v74->RefCount == 1;
      --v27->RefCount;
      if ( v33 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      v74 = v26;
      v25 = v78.pNode;
    }
    else
    {
      v23 = Scaleform::GFx::ASStringManager::CreateString(v74->pManager, &result, v21, v20 - v21)->pNode;
      ++v23->RefCount;
      v24 = v74;
      v33 = v74->RefCount == 1;
      --v24->RefCount;
      if ( v33 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v74 = v23;
      v25 = result.pNode;
    }
    v33 = v25->RefCount-- == 1;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    v20 = pstr++ + 1;
    v28 = v74;
    if ( v74->Size )
    {
      if ( v86 )
      {
        ++v74->RefCount;
        v29 = v86->pNode;
        v33 = v86->pNode->RefCount == 1;
        --v29->RefCount;
        if ( v33 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        v86->pNode = v28;
      }
      v76.T.Type = 0;
      v30 = 0;
      if ( v8 != 7 )
      {
        if ( v9 )
          goto LABEL_70;
        v31 = v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
        v32 = v74;
        if ( *(Scaleform::GFx::ASStringNode **)&v31[17].AVMVersion == v74 )
          goto LABEL_53;
        if ( v5->StringContext.SWFVersion <= 6u )
        {
          if ( !v74->pLower )
          {
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v74);
            v32 = v74;
          }
          v33 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v31[20].AVMVersion + 16i64) == v32->pLower;
        }
        else
        {
          v33 = *(_QWORD *)&v31[20].AVMVersion == (_QWORD)v74;
        }
        if ( v33 )
        {
LABEL_53:
          v34 = v84->pWithStack;
          if ( v34 )
          {
            v35 = v34->Data.Size;
            if ( v35 )
            {
              v36 = Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(&v34->Data.Data[v35 - 1]);
              if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v36->vfptr->gap8[8])(v36)
                 - 2 <= 3 )
              {
                if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v36->vfptr->gap8[8])(v36)
                   - 2 <= 3 )
                {
                  v37 = (Scaleform::GFx::DisplayObject *)v36[1].vfptr;
                  goto LABEL_61;
                }
                goto LABEL_64;
              }
            }
          }
          if ( !v8 || v8 == 10 )
          {
            v37 = (Scaleform::GFx::DisplayObject *)&v5->Target->vfptr;
LABEL_61:
            if ( v37 )
            {
              v38 = (Scaleform::GFx::ASStringNode *)v37->pNameHandle.pObject;
              if ( !v38 )
                v38 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v37);
            }
            else
            {
LABEL_64:
              v38 = 0i64;
            }
            if ( v8 != 7 || v17 != v38 )
            {
              Scaleform::GFx::AS2::Value::DropRefs(&v);
              v8 = 7;
              v.T.Type = 7;
              v.V.pStringNode = v38;
              v17 = v38;
              if ( v38 )
                ++LODWORD(v38->pData);
            }
          }
          v9 = 1;
          if ( v8 != 7 )
          {
LABEL_70:
            if ( (unsigned __int8)(v8 - 2) <= 3u )
            {
              v39 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(v5, &v83, &v);
              Scaleform::GFx::AS2::Value::operator=(&v, v39, (__int64)v17);
              if ( v83.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v83);
              v8 = v.T.Type;
              v17 = v.V.pStringNode;
            }
            switch ( v8 )
            {
              case 6:
LABEL_78:
                if ( v8 == 7 )
                  goto LABEL_96;
                v40 = Scaleform::GFx::AS2::Value::ToObject(&v, v5);
                if ( !v40 )
                  goto LABEL_106;
                v41 = (signed __int64)&v40->vfptr;
                break;
              case 7:
LABEL_96:
                if ( !v17 )
                  goto LABEL_106;
                v48 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                        (Scaleform::GFx::CharacterHandle *)v17,
                        v5->Target->pASRoot->pMovieImpl);
                if ( !v48 )
                  goto LABEL_106;
                v49 = 0i64;
                if ( SLOBYTE(v48->Flags) < 0 )
                  v49 = v48;
                if ( !v49 )
                  goto LABEL_106;
                v50 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v49->vfptr
                                                                                  + 4
                                                                                  * (unsigned __int8)v49->AvmObjOffset))[1].__vecDelDtor)();
                if ( !v50 )
                  goto LABEL_106;
                v41 = v50 + 8;
                break;
              case 8:
              case 11:
                goto LABEL_78;
              default:
LABEL_105:
                Scaleform::GFx::AS2::Value::DropRefs(&v76);
                v30 = 0;
                v76.T.Type = 0;
LABEL_106:
                v51 = v84->pOwner;
                if ( v51 )
                {
                  Scaleform::GFx::AS2::Value::operator=(v51, &v, (__int64)v17);
                  v17 = v.V.pStringNode;
                  v8 = v.T.Type;
                }
                if ( v85 && v76.T.Type != 7 || !v30 )
                {
                  Scaleform::GFx::AS2::Value::DropRefs(&v);
                  v8 = 0;
                  v.T.Type = 0;
                  v9 = 0;
                  if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(
                         (Scaleform::GFx::AS2::StringTokenizer *)&pstr,
                         &sep) )
                  {
                    v59 = v84->pOwner;
                    if ( v59 )
                    {
                      Scaleform::GFx::AS2::Value::DropRefs(v84->pOwner);
                      v59->T.Type = 0;
                    }
                    v60 = v84->ppNewTarget;
                    if ( v60 )
                      *v60 = 0i64;
                    if ( v86 )
                    {
                      v61 = *(Scaleform::GFx::ASStringNode **)&v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
                      ++v61->RefCount;
                      v62 = v86->pNode;
                      v33 = v86->pNode->RefCount == 1;
                      --v62->RefCount;
                      if ( v33 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v62);
                      v86->pNode = v61;
                    }
                  }
                  if ( v76.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v76);
                  v17 = v.V.pStringNode;
                  goto LABEL_161;
                }
                if ( v76.T.Type == 9 )
                {
                  if ( v8 == 7 )
                  {
                    if ( v17 )
                    {
                      v52 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                              (Scaleform::GFx::CharacterHandle *)v17,
                              v5->Target->pASRoot->pMovieImpl);
                      if ( v52 )
                      {
                        v53 = 0i64;
                        if ( SLOBYTE(v52->Flags) < 0 )
                          v53 = v52;
                        if ( v53 )
                        {
                          v54 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v53->vfptr
                                                                                            + 4
                                                                                            * (unsigned __int8)v53->AvmObjOffset))[1].__vecDelDtor)();
                          if ( v54 )
                          {
                            v55 = (Scaleform::GFx::AS2::ObjectInterface *)(v54 + 8);
                            goto LABEL_122;
                          }
                        }
                      }
                    }
LABEL_121:
                    v55 = 0i64;
                  }
                  else
                  {
                    v56 = Scaleform::GFx::AS2::Value::ToObject(&v, v5);
                    v55 = (Scaleform::GFx::AS2::ObjectInterface *)&v56->vfptr;
                    if ( !v56 )
                      goto LABEL_121;
                  }
LABEL_122:
                  if ( v76.T.Type == 9 )
                  {
                    if ( *(_QWORD *)&v76.V.pStringNode->Size )
                    {
                      v80.T.Type = 0;
                      v79.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
                      v79.Result = &v80;
                      v79.ThisPtr = v55;
                      v79.ThisFunctionRef.Flags = 0;
                      v79.ThisFunctionRef.Function = 0i64;
                      v79.ThisFunctionRef.pLocalFrame = 0i64;
                      v79.Env = v5;
                      *(_QWORD *)&v79.NArgs = 0i64;
                      (*(void (__fastcall **)(_QWORD, Scaleform::GFx::AS2::FnCall *, const char *, _QWORD))(**(_QWORD **)&v76.V.pStringNode->Size + 80i64))(
                        *(_QWORD *)&v76.V.pStringNode->Size,
                        &v79,
                        v76.V.pStringNode[1].pData,
                        0i64);
                      Scaleform::GFx::AS2::FnCall::~FnCall(&v79);
                      Scaleform::GFx::AS2::Value::operator=(&v, &v80, (__int64)v17);
                      if ( v80.T.Type >= 5u )
                        Scaleform::GFx::AS2::Value::DropRefs(&v80);
LABEL_129:
                      v17 = v.V.pStringNode;
                      v8 = v.T.Type;
                    }
                    else if ( v5->vfptr->IsVerboseActionErrors((Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v5->vfptr) )
                    {
                      Scaleform::GFx::AS2::Environment::LogScriptError(v5, "Getter method is null.");
                    }
                  }
                  v9 = v30;
                  if ( v76.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v76);
                  v22 = v69;
                  v20 = pstr;
                  goto LABEL_133;
                }
                Scaleform::GFx::AS2::Value::operator=(&v, &v76, (__int64)v17);
                goto LABEL_129;
            }
            if ( v41 )
            {
              v30 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v41 + 32i64))(
                      v41,
                      v5,
                      &v74,
                      &v76);
              if ( !v30 )
                goto LABEL_105;
            }
            goto LABEL_106;
          }
LABEL_81:
          if ( v17 )
          {
            v42 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                    (Scaleform::GFx::CharacterHandle *)v17,
                    v5->Target->pASRoot->pMovieImpl);
            if ( v42 )
            {
              v43 = 0i64;
              if ( SLOBYTE(v42->Flags) < 0 )
                v43 = v42;
              if ( v43 )
              {
                v44 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v43->vfptr
                                                                                  + 4
                                                                                  * (unsigned __int8)v43->AvmObjOffset))[1].__vecDelDtor)();
                v45 = (Scaleform::GFx::DisplayObject *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASStringNode **, _QWORD))(*(_QWORD *)v44 + 208i64))(
                                                         v44,
                                                         &v74,
                                                         (unsigned __int8)sep);
                if ( v45 )
                {
                  v46 = (Scaleform::GFx::ASStringNode *)v45->pNameHandle.pObject;
                  if ( !v46 )
                    v46 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v45);
                  if ( v76.T.Type != 7 || v76.V.pStringNode != v46 )
                  {
                    Scaleform::GFx::AS2::Value::DropRefs(&v76);
                    v76.T.Type = 7;
                    v76.V.pStringNode = v46;
                    if ( v46 )
                      ++LODWORD(v46->pData);
                  }
                  v30 = 1;
                  goto LABEL_106;
                }
              }
            }
          }
          if ( v9 )
            goto LABEL_96;
        }
        v47 = v84->pWithStack;
        paramsa.VarName = (Scaleform::GFx::ASString *)&v74;
        paramsa.pResult = &v76;
        paramsa.pWithStack = v47;
        paramsa.ppNewTarget = 0i64;
        paramsa.pOwner = 0i64;
        paramsa.ExcludeFlags = 0;
        v30 = Scaleform::GFx::AS2::Environment::GetVariableRaw(v5, &paramsa);
        goto LABEL_106;
      }
      if ( !v9 )
        goto LABEL_53;
      goto LABEL_81;
    }
LABEL_133:
    if ( v75 == onlySlashesDelim )
    {
      if ( v22 == 58 )
      {
        string = ":./";
        v75 = ":./";
LABEL_136:
        if ( v84->ppNewTarget && v8 == 7 )
        {
          if ( v17
            && (v57 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                        (Scaleform::GFx::CharacterHandle *)v17,
                        v5->Target->pASRoot->pMovieImpl)) != 0i64 )
          {
            v58 = 0i64;
            if ( SLOBYTE(v57->Flags) < 0 )
              v58 = (Scaleform::GFx::InteractiveObject *)v57;
          }
          else
          {
            v58 = 0i64;
          }
          *v84->ppNewTarget = v58;
          v20 = pstr;
        }
        goto LABEL_148;
      }
    }
    else if ( v22 == 46 )
    {
      goto LABEL_136;
    }
    if ( v22 == 47 )
    {
      string = (char *)onlySlashesDelim;
      v75 = onlySlashesDelim;
    }
LABEL_148:
    sep = 0;
  }
LABEL_161:
  if ( v84->ppNewTarget && v8 == 7 )
  {
    if ( v17 )
    {
      v63 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
              (Scaleform::GFx::CharacterHandle *)v17,
              v5->Target->pASRoot->pMovieImpl);
      if ( v63 )
      {
        if ( SLOBYTE(v63->Flags) < 0 )
          v15 = (Scaleform::GFx::InteractiveObject *)v63;
      }
    }
    *v84->ppNewTarget = v15;
  }
  v64 = v84->pOwner;
  if ( v64 && (unsigned __int8)(v64->T.Type - 6) > 1u && v64->T.Type != 8 && v64->T.Type != 11 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(v84->pOwner);
    v64->T.Type = 0;
  }
  if ( v9 )
  {
    v66 = v84->pResult;
    if ( v66 )
    {
      Scaleform::GFx::AS2::Value::operator=(v66, &v, (__int64)v64);
      v8 = v.T.Type;
    }
    v65 = 1;
  }
  else
  {
    v65 = 0;
  }
  v67 = v74;
  v33 = v74->RefCount == 1;
  --v67->RefCount;
  if ( v33 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  if ( (unsigned __int8)v8 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v65;
}

// File Line: 6643
// RVA: 0x6EB3C0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Environment::FindTarget(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *path, unsigned int excludeFlags)
{
  char v3; // r13
  Scaleform::GFx::ASString *v4; // r12
  Scaleform::GFx::AS2::Environment *v5; // r14
  Scaleform::GFx::InteractiveObject *v6; // rbp
  Scaleform::GFx::InteractiveObject *v7; // rax
  Scaleform::GFx::InteractiveObject *v8; // rsi
  const char *v9; // rdi
  unsigned __int8 i; // r15
  const char *j; // rbx
  Scaleform::GFx::ASStringNode *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::GFx::ASStringNode *v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString v20; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v22; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h]

  v21 = -2i64;
  v3 = excludeFlags;
  v4 = path;
  v5 = this;
  if ( path->pNode->Size )
  {
    v8 = this->Target;
    v9 = path->pNode->pData;
    v22 = *(Scaleform::GFx::ASStringNode **)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v22->RefCount;
    if ( *v9 == 47 )
    {
      v8 = (Scaleform::GFx::InteractiveObject *)v8->vfptr[68].__vecDelDtor(
                                                  (Scaleform::RefCountNTSImplCore *)&v8->vfptr,
                                                  0);
      ++v9;
    }
    for ( i = 1; ; i = 0 )
    {
      for ( j = v9; *j; ++j )
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
      if ( j == v9 )
        break;
      if ( j )
      {
        v12 = Scaleform::GFx::AS2::Environment::CreateString(v5, &result, v9, j - v9)->pNode;
        ++v12->RefCount;
        v13 = v22;
        v14 = v22->RefCount == 1;
        --v13->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        v22 = v12;
        v15 = result.pNode;
      }
      else
      {
        v16 = Scaleform::GFx::AS2::Environment::CreateString(v5, &v20, v9)->pNode;
        ++v16->RefCount;
        v17 = v22;
        v14 = v22->RefCount == 1;
        --v17->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        v22 = v16;
        v15 = v20.pNode;
      }
      v14 = v15->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( v22->Size )
      {
        if ( v8 )
          v18 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->vfptr
                                                                            + 4 * (unsigned __int8)v8->AvmObjOffset))[1].__vecDelDtor)();
        else
          v18 = 0i64;
        v8 = (Scaleform::GFx::InteractiveObject *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::ASStringNode **, _QWORD))(*(_QWORD *)v18 + 208i64))(
                                                    v18,
                                                    &v22,
                                                    i);
      }
      if ( !v8 || !j )
        goto LABEL_36;
      v9 = j + 1;
    }
    if ( !(v3 & 4) )
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v5->vfptr,
        "Invalid path '%s'",
        v4->pNode->pData);
LABEL_36:
    v19 = v22;
    v14 = v22->RefCount == 1;
    --v19->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v7 = v8;
  }
  else
  {
    if ( *((_BYTE *)this + 382) & 2 )
      v6 = 0i64;
    else
      v6 = this->Target;
    v7 = v6;
  }
  return v7;
}

// File Line: 6698
// RVA: 0x707420
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Environment::OperatorNew(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::FunctionRef *constructor, int nargs, int argsTopOff)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // r14
  Scaleform::GFx::AS2::LocalFrame *v6; // r13
  __int64 v7; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  bool v9; // r15
  char v10; // al
  Scaleform::GFx::AS2::FunctionObject *v11; // rcx
  unsigned int v12; // edx
  Scaleform::GFx::AS2::LocalFrame *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Value *v15; // rdx
  char v16; // si
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Object *v18; // rax
  Scaleform::GFx::AS2::Object *v19; // rdi
  Scaleform::GFx::AS2::Value *v20; // rcx
  Scaleform::GFx::AS2::GlobalContext **v21; // rbx
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::AS2::Object *v23; // rdx
  char v24; // r12
  Scaleform::GFx::AS2::FunctionObject *v25; // r15
  Scaleform::GFx::AS2::LocalFrame *v26; // rcx
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
  bool v45; // dl
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
  signed int v58; // [rsp+20h] [rbp-A8h]
  __int64 v59[2]; // [rsp+20h] [rbp-A8h]
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-98h]
  Scaleform::GFx::AS2::Environment *v61; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::AS2::Value v62; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::AS2::Value v63; // [rsp+70h] [rbp-58h]
  Scaleform::GFx::AS2::Value v64; // [rsp+90h] [rbp-38h]
  __int64 v65; // [rsp+B0h] [rbp-18h]
  Scaleform::GFx::AS2::Value v66; // [rsp+B8h] [rbp-10h]
  char v67; // [rsp+D8h] [rbp+10h]
  Scaleform::GFx::AS2::FunctionRef *ctorFunc; // [rsp+140h] [rbp+78h]
  unsigned int v69; // [rsp+148h] [rbp+80h]
  unsigned int v70; // [rsp+150h] [rbp+88h]

  v65 = -2i64;
  v4 = constructor;
  v5 = this;
  v6 = 0i64;
  v7 = 0i64;
  v58 = 0;
  v67 = 0;
  if ( argsTopOff < 0 )
    v70 = 32 * this->Stack.Pages.Data.Size
        - 32
        + ((_QWORD)((char *)this->Stack.pCurrent - (char *)this->Stack.pPageStart) >> 5);
  v8 = 0i64;
  *((_QWORD *)&v62.NV + 3) = 0i64;
  v9 = 0;
  if ( nargs == 1 )
  {
    v7 = 1i64;
    v58 = 1;
    if ( constructor->Function == Scaleform::GFx::AS2::Environment::GetConstructor(this, &result, ASBuiltin_Object)->Function )
      v9 = 1;
  }
  if ( v7 & 1 )
  {
    v7 = (unsigned int)v7 & 0xFFFFFFFE;
    v58 = v7;
    v10 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v11 = result.Function;
      if ( result.Function )
      {
        v12 = result.Function->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          result.Function->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
          v10 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v10 & 1) )
    {
      v13 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v14 = result.pLocalFrame->RefCount;
        if ( v14 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  if ( v9 )
  {
    v15 = v5->Stack.pCurrent;
    v16 = 0;
    v62.T.Type = 0;
    if ( (unsigned __int8)(v15->T.Type - 2) <= 3u )
    {
      v17 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(v5, (Scaleform::GFx::AS2::Value *)&result, 0);
      Scaleform::GFx::AS2::Value::operator=(&v62, v17, v7);
      if ( LOBYTE(result.Function) >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&result);
    }
    else
    {
      if ( (unsigned __int8)(v15->T.Type - 6) > 1u )
      {
LABEL_29:
        if ( (unsigned __int8)v16 >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v62);
        v4 = ctorFunc;
        goto LABEL_32;
      }
      Scaleform::GFx::AS2::Value::operator=(&v62, v15, v7);
    }
    v16 = v62.T.Type;
    if ( v62.T.Type && v62.T.Type != 10 )
    {
      v18 = Scaleform::GFx::AS2::Value::ToObject(&v62, v5);
      v19 = v18;
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      if ( (unsigned __int8)v16 >= 5u )
      {
        v20 = &v62;
LABEL_95:
        Scaleform::GFx::AS2::Value::DropRefs(v20);
        goto LABEL_96;
      }
      goto LABEL_96;
    }
    goto LABEL_29;
  }
LABEL_32:
  v63.T.Type = 0;
  v21 = &v5->StringContext.pContext;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, signed int))v4->Function->vfptr->GetMemberRaw)(
          &v4->Function->vfptr,
          &v5->StringContext,
          &v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
          &v63,
          v58) )
  {
    v22 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(*v21, ASBuiltin_Object);
    Scaleform::GFx::AS2::Value::SetAsObject(&v63, v22);
  }
  v23 = Scaleform::GFx::AS2::Value::ToObject(&v63, v5);
  v24 = 0;
  result.Flags = 0;
  v25 = v4->Function;
  result.Function = v25;
  if ( v25 )
    v25->RefCount = (v25->RefCount + 1) & 0x8FFFFFFF;
  result.pLocalFrame = 0i64;
  v26 = v4->pLocalFrame;
  if ( v26 )
  {
    v27 = v4->Flags & 1;
    v6 = v4->pLocalFrame;
    result.pLocalFrame = v4->pLocalFrame;
    v24 = v27 != 0;
    result.Flags = v27 != 0;
    if ( !v27 )
      v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
  }
  v64.T.Type = 0;
  if ( v23
    && v23->vfptr->GetMemberRaw(
         (Scaleform::GFx::AS2::ObjectInterface *)&v23->vfptr,
         &v5->StringContext,
         (Scaleform::GFx::ASString *)&(*v21)->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
         &v64) )
  {
    v28 = 0;
    if ( v64.T.Type == 8 || v64.T.Type == 11 )
    {
      LODWORD(v7) = v7 | 2;
      LODWORD(v59[0]) = v7;
      if ( Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v62, v5)->Function )
        v28 = 1;
    }
    if ( v7 & 2 )
    {
      LODWORD(v59[0]) = v7 & 0xFFFFFFFD;
      v29 = *((_BYTE *)&v62.NV + 16);
      if ( !(*((char *)&v62.NV + 16) & 2) )
      {
        v30 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v62.T.Type;
        if ( *(_QWORD *)&v62.T.Type )
        {
          v31 = *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64);
          if ( v31 & 0x3FFFFFF )
          {
            *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64) = v31 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
            v29 = *((_BYTE *)&v62.NV + 16);
          }
        }
      }
      *(_QWORD *)&v62.T.Type = 0i64;
      if ( !(v29 & 1) )
      {
        v32 = v62.V.pStringNode;
        if ( v62.V.pStringNode )
        {
          v33 = v62.V.pStringNode->RefCount;
          if ( v33 & 0x3FFFFFF )
          {
            v62.V.pStringNode->RefCount = v33 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v32);
          }
        }
      }
      v62.V.pStringNode = 0i64;
    }
    if ( v28 )
    {
      v34 = Scaleform::GFx::AS2::Value::ToFunction(&v64, (Scaleform::GFx::AS2::FunctionRef *)&v62, v5);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&result.Function,
        (Scaleform::GFx::AS2::FunctionRefBase *)&v34->Function);
      v35 = *((_BYTE *)&v62.NV + 16);
      if ( !(*((char *)&v62.NV + 16) & 2) )
      {
        v36 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v62.T.Type;
        if ( *(_QWORD *)&v62.T.Type )
        {
          v37 = *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64);
          if ( v37 & 0x3FFFFFF )
          {
            *(_DWORD *)(*(_QWORD *)&v62.T.Type + 24i64) = v37 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
            v35 = *((_BYTE *)&v62.NV + 16);
          }
        }
      }
      *(_QWORD *)&v62.T.Type = 0i64;
      if ( !(v35 & 1) )
      {
        v38 = v62.V.pStringNode;
        if ( v62.V.pStringNode )
        {
          v39 = v62.V.pStringNode->RefCount;
          if ( v39 & 0x3FFFFFF )
          {
            v62.V.pStringNode->RefCount = v39 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v38);
          }
        }
      }
      v62.V.pStringNode = 0i64;
      v24 = result.Flags;
      v6 = result.pLocalFrame;
      v25 = result.Function;
    }
  }
  v40 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::Environment *))v25->vfptr[5].ExecuteForEachChild_GC)(
          v25,
          v5);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v40;
  *((_QWORD *)&v62.NV + 3) = v40;
  if ( v40 )
  {
    v41 = (Scaleform::GFx::AS2::ObjectInterface *)(v40 + 32);
    v42 = *(_QWORD *)(v40 + 32);
    v43 = Scaleform::GFx::AS2::Value::ToObject(&v63, v5);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(v42 + 104))(
      v41,
      &v5->StringContext,
      v43);
    v44 = ctorFunc;
    Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(v41, &v5->StringContext, ctorFunc);
    v66.T.Type = 0;
    v62.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v66;
    *((_OWORD *)&v62.NV + 1) = (unsigned __int64)v41;
    v63.V.BooleanValue = 0;
    *(_QWORD *)&v63.T.Type = 0i64;
    v61 = v5;
    *(_QWORD *)&v62.T.Type = __PAIR__(v70, v69);
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::LocalFrame *, _QWORD, __int64))v44->Function->vfptr[3].Finalize_GC)(
      v44->Function,
      &v62,
      v44->pLocalFrame,
      0i64,
      v59[0]);
    *(_QWORD *)&v62.T.Type = &Scaleform::GFx::AS2::FnCall::`vftable';
    v45 = v63.V.BooleanValue;
    if ( !(v63.V.BooleanValue & 2) )
    {
      v46 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)*((_QWORD *)&v62.NV + 3);
      if ( *((_QWORD *)&v62.NV + 3) )
      {
        v47 = *(_DWORD *)(*((_QWORD *)&v62.NV + 3) + 24i64);
        if ( v47 & 0x3FFFFFF )
        {
          *(_DWORD *)(*((_QWORD *)&v62.NV + 3) + 24i64) = v47 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
          v45 = v63.V.BooleanValue;
        }
      }
    }
    *((_QWORD *)&v62.NV + 3) = 0i64;
    if ( !v45 )
    {
      v48 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v63.T.Type;
      if ( *(_QWORD *)&v63.T.Type )
      {
        v49 = *(_DWORD *)(*(_QWORD *)&v63.T.Type + 24i64);
        if ( v49 & 0x3FFFFFF )
        {
          *(_DWORD *)(*(_QWORD *)&v63.T.Type + 24i64) = v49 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
        }
      }
    }
    *(_QWORD *)&v63.T.Type = 0i64;
    *(_QWORD *)&v62.T.Type = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
    v19 = (Scaleform::GFx::AS2::Object *)v8;
    if ( v66.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v66);
  }
  else
  {
    v50 = (Scaleform::GFx::AS2::ObjectInterface *)&v4->Function->vfptr;
    if ( !v4->Function )
      v50 = 0i64;
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      v5->StringContext.pContext,
      (Scaleform::GFx::ASString *)&v62.NV + 2,
      v5,
      v50);
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      v5->StringContext.pContext,
      (Scaleform::GFx::ASString *)&v62.NV.8,
      v5,
      (Scaleform::GFx::AS2::ObjectInterface *)&v25->vfptr);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v5,
      "%s::CreateNewObject returned NULL during creation of %s class instance.",
      v62.V.pStringNode->pData,
      v62.V.FunctionValue.pLocalFrame->vfptr,
      v59[0]);
    v51 = v62.V.pStringNode;
    v52 = v62.V.pStringNode->RefCount == 1;
    --v51->RefCount;
    if ( v52 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v51);
    v53 = (Scaleform::GFx::ASStringNode *)v62.V.FunctionValue.pLocalFrame;
    v52 = v62.V.FunctionValue.pLocalFrame->RefCount == 1;
    --v53->RefCount;
    if ( v52 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v53);
    v19 = 0i64;
  }
  if ( v64.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v64);
  if ( !(v24 & 2) )
  {
    v54 = v25->RefCount;
    if ( v54 & 0x3FFFFFF )
    {
      v25->RefCount = v54 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
    }
  }
  result.Function = 0i64;
  if ( !(v24 & 1) )
  {
    if ( v6 )
    {
      v55 = v6->RefCount;
      if ( v55 & 0x3FFFFFF )
      {
        v6->RefCount = v55 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
      }
    }
  }
  result.pLocalFrame = 0i64;
  if ( v63.T.Type >= 5u )
  {
    v20 = &v63;
    goto LABEL_95;
  }
LABEL_96:
  if ( v8 )
  {
    v56 = v8->RefCount;
    if ( v56 & 0x3FFFFFF )
    {
      v8->RefCount = v56 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v19;
}

// File Line: 6798
// RVA: 0x707A90
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Environment::OperatorNew(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Object *ppackageObj, Scaleform::GFx::ASString *className, int nargs, int argsTopOff)
{
  int v5; // edi
  Scaleform::GFx::AS2::Environment *v6; // rbx
  Scaleform::GFx::AS2::FunctionRef *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rbx
  char v9; // dl
  Scaleform::GFx::AS2::FunctionObject *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::LocalFrame *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::Value v16; // [rsp+40h] [rbp-28h]

  v5 = nargs;
  v6 = this;
  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))ppackageObj->vfptr->GetMember)(
         &ppackageObj->vfptr,
         this,
         className,
         &v16,
         -2i64)
    && (v16.T.Type == 8 || v16.T.Type == 11) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToFunction(&v16, &result, v6);
    v8 = Scaleform::GFx::AS2::Environment::OperatorNew(v6, v7, v5, argsTopOff);
    v9 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v10 = result.Function;
      if ( result.Function )
      {
        v11 = result.Function->RefCount;
        if ( v11 & 0x3FFFFFF )
        {
          result.Function->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
          v9 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v9 & 1) )
    {
      v12 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v13 = result.pLocalFrame->RefCount;
        if ( v13 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
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
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Environment::GetConstructor(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::ASBuiltinType className)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rdi
  int v5; // ST20_4
  Scaleform::GFx::AS2::Value v7; // [rsp+30h] [rbp-28h]

  v3 = result;
  v4 = this;
  v5 = 0;
  v7.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, int, signed __int64))this->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw)(
         &this->StringContext.pContext->pGlobal.pObject->vfptr,
         &this->StringContext,
         &this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion + 8 * className,
         &v7,
         v5,
         -2i64)
    && (v7.T.Type == 8 || v7.T.Type == 11) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&v7, v3, v4);
  }
  else
  {
    v3->Flags = 0;
    v3->Function = 0i64;
    v3->pLocalFrame = 0i64;
  }
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
  return v3;
}

// File Line: 6827
// RVA: 0x708B10
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Value *result, int index)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // r9
  unsigned __int64 v6; // r8
  __int64 v7; // r10
  unsigned int v8; // edx
  int v9; // eax
  signed int v10; // er9
  Scaleform::GFx::AS2::Object *v11; // rdi
  unsigned int v12; // eax

  v3 = index;
  v4 = result;
  v5 = 0i64;
  v6 = this->Stack.Pages.Data.Size;
  v7 = (_QWORD)((char *)this->Stack.pCurrent - (char *)this->Stack.pPageStart) >> 5;
  v8 = v7 + 32 * (v6 - 1);
  if ( v3 <= v8 )
    v5 = &this->Stack.Pages.Data.Data[(v8 - v3) >> 5]->Values[(v8 - v3) & 0x1F];
  v9 = (unsigned __int8)v5->T.Type;
  if ( v9 == 2 )
  {
    v10 = 5;
  }
  else if ( v9 == 5 )
  {
    v10 = 3;
  }
  else
  {
    if ( (unsigned __int8)(v9 - 3) > 1u )
    {
      v4->T.Type = 0;
      return v4;
    }
    v10 = 4;
  }
  v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
          this,
          this->StringContext.pContext->pGlobal.pObject,
          (Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
        + v10,
          1,
          v7 + 32 * v6 - 32 - v3);
  Scaleform::GFx::AS2::Value::Value(v4, v11);
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
    }
  }
  return v4;
}

// File Line: 6851
// RVA: 0x7089B0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rbp
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // r14
  int v6; // eax
  signed int v7; // esi
  Scaleform::GFx::AS2::Value *v9; // rcx
  Scaleform::GFx::AS2::Object *v10; // rsi
  Scaleform::GFx::AS2::Value *v11; // rcx
  unsigned int v12; // eax

  v3 = v;
  v4 = result;
  v5 = this;
  v6 = (unsigned __int8)v->T.Type;
  if ( v6 == 2 )
  {
    v7 = 5;
  }
  else if ( v6 == 5 )
  {
    v7 = 3;
  }
  else
  {
    if ( (unsigned __int8)(v6 - 3) > 1u )
    {
      result->T.Type = 0;
      return result;
    }
    v7 = 4;
  }
  ++this->Stack.pCurrent;
  if ( this->Stack.pCurrent >= this->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
  v9 = v5->Stack.pCurrent;
  if ( v9 )
    Scaleform::GFx::AS2::Value::Value(v9, v3, (__int64)v4);
  v10 = Scaleform::GFx::AS2::Environment::OperatorNew(
          v5,
          v5->StringContext.pContext->pGlobal.pObject,
          (Scaleform::GFx::ASString *)&v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion + v7,
          1,
          ((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5)
        + 32 * v5->Stack.Pages.Data.Size
        - 32);
  v11 = v5->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  --v5->Stack.pCurrent;
  if ( v5->Stack.pCurrent < v5->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v5->Stack);
  Scaleform::GFx::AS2::Value::Value(v4, v10);
  if ( v10 )
  {
    v12 = v10->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v10->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
  return v4;
}

// File Line: 6923
// RVA: 0x6C0790
void __fastcall Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(Scaleform::GFx::AS2::LocalFrame *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *v2; // r8
  Scaleform::GFx::AS2::LocalFrame *v3; // rbp
  unsigned __int64 v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v5; // rcx
  Scaleform::GFx::AS2::RefCountCollector<323> *v6; // rdi
  unsigned __int64 v7; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rcx
  __int64 v9; // rbx
  __int64 v10; // rsi
  __int64 v11; // rcx
  signed __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rdx
  int v15; // eax
  unsigned int v16; // eax
  unsigned __int64 v17; // rcx
  _QWORD *v18; // rax
  Scaleform::GFx::AS2::LocalFrame *v19; // rdx
  unsigned int v20; // eax
  unsigned int v21; // eax
  __m128i v22; // [rsp+20h] [rbp-18h]

  v2 = &this->Variables;
  v3 = this;
  v4 = 0i64;
  v5 = this->Variables.mHash.pTable;
  v6 = prcc;
  if ( v5 )
  {
    v7 = v5->SizeMask;
    v8 = v5 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v4;
      v8 += 3;
    }
    while ( v4 <= v7 );
    v22.m128i_i64[0] = (__int64)v2;
  }
  else
  {
    v22.m128i_i64[0] = 0i64;
  }
  v22.m128i_i64[1] = v4;
  _mm_store_si128(&v22, v22);
  v9 = v22.m128i_i64[1];
  v10 = v22.m128i_i64[0];
  while ( v10 )
  {
    v11 = *(_QWORD *)v10;
    if ( !*(_QWORD *)v10 || v9 > *(_QWORD *)(v11 + 8) )
      break;
    v12 = 48 * v9 + v11;
    v13 = *(_BYTE *)(v12 + 32);
    if ( v13 == 8 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)(v12 + 40),
        v6);
      goto LABEL_20;
    }
    if ( v13 != 6 || (v14 = *(_QWORD *)(v12 + 40)) == 0 )
    {
      if ( v13 != 9 )
        goto LABEL_20;
      v14 = *(_QWORD *)(v12 + 40);
    }
    v15 = ++*(_DWORD *)(v14 + 24);
    if ( v15 & 0x70000000 )
    {
      v16 = v15 & 0x8FFFFFFF;
      *(_DWORD *)(v14 + 24) = v16;
      if ( (v16 >> 27) & 1 )
      {
        *(_QWORD *)(*(_QWORD *)(v14 + 16) + 8i64) = *(_QWORD *)(v14 + 8);
        *(_QWORD *)(*(_QWORD *)(v14 + 8) + 16i64) = *(_QWORD *)(v14 + 16);
        *(_QWORD *)(v14 + 16) = *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0;
        *(_QWORD *)(v14 + 8) = v6->pLastPtr->pRCC;
        *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0 = v14;
        v6->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v14;
      }
    }
LABEL_20:
    v17 = *(_QWORD *)(*(_QWORD *)v10 + 8i64);
    if ( v9 <= (signed __int64)v17 && ++v9 <= v17 )
    {
      v18 = (_QWORD *)(*(_QWORD *)v10 + 48 * v9 + 16);
      do
      {
        if ( *v18 != -2i64 )
          break;
        ++v9;
        v18 += 6;
      }
      while ( v9 <= v17 );
    }
  }
  v19 = v3->PrevFrame.pObject;
  if ( v19 )
  {
    v20 = ++v19->RefCount;
    if ( v20 & 0x70000000 )
    {
      v21 = v20 & 0x8FFFFFFF;
      v19->RefCount = v21;
      if ( (v21 >> 27) & 1 )
      {
        v19->pPrev->pRCC = v19->pRCC;
        *(_QWORD *)v19->pRCC->Roots.gap0 = v19->pPrev;
        v19->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v6->pLastPtr->pRCC->Roots.gap0;
        v19->pRCC = v6->pLastPtr->pRCC;
        *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0 = v19;
        v6->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v19;
      }
    }
  }
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &v3->Callee,
    v6);
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &v3->Caller,
    v6);
}

// File Line: 6939
// RVA: 0x6E89A0
void __fastcall Scaleform::GFx::AS2::LocalFrame::ExecuteForEachChild_GC(Scaleform::GFx::AS2::LocalFrame *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

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
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Variables.mHash.pTable);
}

