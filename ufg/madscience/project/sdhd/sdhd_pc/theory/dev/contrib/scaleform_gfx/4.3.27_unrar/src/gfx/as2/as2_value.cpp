// File Line: 40
// RVA: 0x720FB0
bool __fastcall Scaleform::GFx::AS2::StringToNumber(long double *result, const char *str)
{
  long double *v2; // r14
  const char *v3; // rdi
  signed __int64 v4; // rbx
  int v5; // ecx
  double v6; // xmm0_8
  const char *v7; // rsi
  signed int v8; // ebp
  char *v9; // rax
  char *endptr; // [rsp+48h] [rbp+10h]

  v2 = result;
  v3 = str;
  endptr = 0i64;
  v4 = -1i64;
  do
    ++v4;
  while ( str[v4] );
  if ( *str != 48 )
    goto LABEL_24;
  v5 = str[1];
  if ( (unsigned int)(v5 - 65) <= 0x19 )
    v5 += 32;
  if ( v5 != 120 )
  {
LABEL_24:
    if ( strcspn(str, ".Ee") != v4 )
    {
      v6 = Scaleform::SFstrtod(v3, &endptr);
      goto LABEL_18;
    }
    v7 = v3;
    v8 = 1;
    if ( *v3 == 45 )
    {
      v8 = -1;
    }
    else if ( *v3 != 43 )
    {
LABEL_14:
      if ( *v7 != 48 || strspn(v7, "01234567") != v4 )
        v6 = Scaleform::SFstrtod(v7, &endptr) * (double)v8;
      else
        v6 = (double)(signed int)(v8 * strtoul(v7, &endptr, 8));
      goto LABEL_18;
    }
    --v4;
    v7 = v3 + 1;
    goto LABEL_14;
  }
  v6 = (double)(signed int)strtoul(str, &endptr, 0);
LABEL_18:
  v9 = endptr;
  *v2 = v6;
  return v9 != v3 && !*v9;
}

// File Line: 126
// RVA: 0x6CD530
void __usercall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this@<rcx>, Scaleform::GFx::AS2::Value *v@<rdx>, __int64 a3@<rdi>)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  __int64 v7; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v8; // rcx
  Scaleform::GFx::AS2::FunctionObject *v9; // r8
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  char v11; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  unsigned int v13; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rdx
  Scaleform::GFx::AS2::LocalFrame *v20; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+30h] [rbp-18h]
  char v23; // [rsp+38h] [rbp-10h]
  __int64 v24; // [rsp+40h] [rbp-8h]

  v24 = a3;
  v3 = v;
  v4 = this;
  this->T.Type = v->T.Type;
  switch ( v->T.Type )
  {
    case 2:
      this->V.BooleanValue = v->V.BooleanValue;
      break;
    case 3:
      this->V.pStringNode = v->V.pStringNode;
      break;
    case 4:
      this->NV.Int32Value = v->NV.Int32Value;
      break;
    case 5:
    case 0xB:
      v5 = v->V.pStringNode;
      this->V.pStringNode = v5;
      ++v5->RefCount;
      break;
    case 6:
      v6 = v->V.pStringNode;
      if ( v6 )
      {
        if ( (*(unsigned int (__cdecl **)(unsigned int *))(*(_QWORD *)&v6->Size + 16i64))(&v6->Size) != 23 )
        {
          v16 = v3->V.pStringNode;
          goto LABEL_30;
        }
        v4->T.Type = 8;
        v7 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&v3->V.pStringNode->Size + 96i64))(
               &v3->V.pStringNode->Size,
               &v21);
        v8 = (Scaleform::GFx::AS2::FunctionRefBase *)&v4->NV.8;
        v8->Flags = 0;
        v9 = *(Scaleform::GFx::AS2::FunctionObject **)v7;
        v8->Function = *(Scaleform::GFx::AS2::FunctionObject **)v7;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
        v4->V.FunctionValue.pLocalFrame = 0i64;
        v10 = *(Scaleform::GFx::AS2::LocalFrame **)(v7 + 8);
        if ( v10 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v8, v10, *(_BYTE *)(v7 + 16) & 1);
        v11 = v23;
        if ( !(v23 & 2) )
        {
          v12 = v21;
          if ( v21 )
          {
            v13 = v21->RefCount;
            if ( v13 & 0x3FFFFFF )
            {
              v21->RefCount = v13 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
              v11 = v23;
            }
          }
        }
        v21 = 0i64;
        if ( !(v11 & 1) )
        {
          v14 = v22;
          if ( v22 )
          {
            v15 = v22->RefCount;
            if ( v15 & 0x3FFFFFF )
            {
              v22->RefCount = v15 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
            }
          }
        }
        v22 = 0i64;
      }
      else
      {
        v4->V.pStringNode = 0i64;
      }
      break;
    case 7:
      v17 = v->V.pStringNode;
      this->V.pStringNode = v17;
      if ( v17 )
        ++LODWORD(v17->pData);
      break;
    case 8:
    case 0xC:
      v18 = (Scaleform::GFx::AS2::FunctionRefBase *)&this->NV.8;
      v18->Flags = 0;
      v19 = v->V.pStringNode;
      v18->Function = (Scaleform::GFx::AS2::FunctionObject *)v19;
      if ( v19 )
        v19->RefCount = (v19->RefCount + 1) & 0x8FFFFFFF;
      v4->V.FunctionValue.pLocalFrame = 0i64;
      v20 = v3->V.FunctionValue.pLocalFrame;
      if ( v20 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v18, v20, v3->V.FunctionValue.Flags & 1);
      break;
    case 9:
      v16 = v->V.pStringNode;
LABEL_30:
      v4->V.pStringNode = v16;
      v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}

// File Line: 191
// RVA: 0x6D3710
void __usercall Scaleform::GFx::AS2::Value::operator=(Scaleform::GFx::AS2::Value *this@<rcx>, Scaleform::GFx::AS2::Value *v@<rdx>, __int64 a3@<rdi>)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  __int64 v7; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v8; // rcx
  Scaleform::GFx::AS2::FunctionObject *v9; // r8
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  char v11; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  unsigned int v13; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v17; // rcx
  Scaleform::GFx::AS2::FunctionObject *v18; // rdx
  Scaleform::GFx::AS2::LocalFrame *v19; // rdx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+30h] [rbp-18h]
  char v23; // [rsp+38h] [rbp-10h]
  __int64 v24; // [rsp+40h] [rbp-8h]

  v24 = a3;
  v3 = v;
  v4 = this;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  v4->T.Type = v3->T.Type;
  switch ( v3->T.Type )
  {
    case 2:
      v4->V.BooleanValue = v3->V.BooleanValue;
      break;
    case 3:
      v4->V.pStringNode = v3->V.pStringNode;
      break;
    case 4:
      v4->NV.Int32Value = v3->NV.Int32Value;
      break;
    case 5:
    case 0xB:
      v5 = v3->V.pStringNode;
      v4->V.pStringNode = v5;
      ++v5->RefCount;
      break;
    case 6:
      v6 = v3->V.pStringNode;
      if ( v6 )
      {
        if ( (*(unsigned int (__fastcall **)(unsigned int *, signed __int64))(*(_QWORD *)&v6->Size + 16i64))(
               &v6->Size,
               5368709120i64) != 23 )
          goto $LN1_32;
        v4->T.Type = 8;
        v7 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&v3->V.pStringNode->Size + 96i64))(
               &v3->V.pStringNode->Size,
               &v21);
        v8 = (Scaleform::GFx::AS2::FunctionRefBase *)&v4->NV.8;
        v8->Flags = 0;
        v9 = *(Scaleform::GFx::AS2::FunctionObject **)v7;
        v8->Function = *(Scaleform::GFx::AS2::FunctionObject **)v7;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
        v4->V.FunctionValue.pLocalFrame = 0i64;
        v10 = *(Scaleform::GFx::AS2::LocalFrame **)(v7 + 8);
        if ( v10 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v8, v10, *(_BYTE *)(v7 + 16) & 1);
        v11 = v23;
        if ( !(v23 & 2) )
        {
          v12 = v21;
          if ( v21 )
          {
            v13 = v21->RefCount;
            if ( v13 & 0x3FFFFFF )
            {
              v21->RefCount = v13 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
              v11 = v23;
            }
          }
        }
        v21 = 0i64;
        if ( !(v11 & 1) )
        {
          v14 = v22;
          if ( v22 )
          {
            v15 = v22->RefCount;
            if ( v15 & 0x3FFFFFF )
            {
              v22->RefCount = v15 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
            }
          }
        }
        v22 = 0i64;
      }
      else
      {
        v4->V.pStringNode = 0i64;
      }
      break;
    case 7:
      v16 = v3->V.pStringNode;
      v4->V.pStringNode = v16;
      if ( v16 )
        ++LODWORD(v16->pData);
      break;
    case 8:
    case 0xC:
      v17 = (Scaleform::GFx::AS2::FunctionRefBase *)&v4->NV.8;
      v17->Flags = 0;
      v18 = v3->V.FunctionValue.Function;
      v17->Function = v18;
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      v4->V.FunctionValue.pLocalFrame = 0i64;
      v19 = v3->V.FunctionValue.pLocalFrame;
      if ( v19 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v17, v19, v3->V.FunctionValue.Flags & 1);
      break;
    case 9:
$LN1_32:
      v20 = v3->V.pStringNode;
      v4->V.pStringNode = v20;
      v20->RefCount = (v20->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}

// File Line: 262
// RVA: 0x6CD7A0
void __fastcall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::Object *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // r8
  Scaleform::GFx::AS2::LocalFrame *v7; // rdx
  char v8; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // [rsp+30h] [rbp-18h]
  char v15; // [rsp+38h] [rbp-10h]

  v2 = pobj;
  v3 = this;
  if ( pobj
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&pobj->vfptr->gap8[8])(&pobj->vfptr) == 23 )
  {
    v3->T.Type = 8;
    v4 = (__int64)v2->vfptr->ToFunction(
                    (Scaleform::GFx::AS2::ObjectInterface *)&v2->vfptr,
                    (Scaleform::GFx::AS2::FunctionRef *)&v13);
    v5 = (Scaleform::GFx::AS2::FunctionRefBase *)&v3->NV.8;
    v5->Flags = 0;
    v6 = *(Scaleform::GFx::AS2::FunctionObject **)v4;
    v5->Function = *(Scaleform::GFx::AS2::FunctionObject **)v4;
    if ( v6 )
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
    v3->V.FunctionValue.pLocalFrame = 0i64;
    v7 = *(Scaleform::GFx::AS2::LocalFrame **)(v4 + 8);
    if ( v7 )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v5, v7, *(_BYTE *)(v4 + 16) & 1);
    v8 = v15;
    if ( !(v15 & 2) )
    {
      v9 = v13;
      if ( v13 )
      {
        v10 = v13->RefCount;
        if ( v10 & 0x3FFFFFF )
        {
          v13->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          v8 = v15;
        }
      }
    }
    v13 = 0i64;
    if ( !(v8 & 1) )
    {
      v11 = v14;
      if ( v14 )
      {
        v12 = v14->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          v14->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
    }
    v14 = 0i64;
  }
  else
  {
    v3->T.Type = 6;
    v3->V.pStringNode = (Scaleform::GFx::ASStringNode *)v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 294
// RVA: 0x6CD740
void __fastcall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::FunctionRef *func)
{
  Scaleform::GFx::AS2::FunctionRefBase *v2; // rcx
  Scaleform::GFx::AS2::FunctionObject *v3; // r8

  this->T.Type = 8;
  v2 = (Scaleform::GFx::AS2::FunctionRefBase *)&this->NV.8;
  v2->Flags = 0;
  v3 = func->Function;
  v2->Function = func->Function;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  v2->pLocalFrame = 0i64;
  if ( func->pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v2, func->pLocalFrame, func->Flags & 1);
}

// File Line: 309
// RVA: 0x6D2890
void __fastcall Scaleform::GFx::AS2::Value::~Value(Scaleform::GFx::AS2::Value *this)
{
  JUMPOUT(this->T.Type, 5, Scaleform::GFx::AS2::Value::DropRefs);
}

// File Line: 317
// RVA: 0x6BF120
void __fastcall Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  char v2; // al
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // r8
  Scaleform::GFx::ASStringNode *v4; // rdx

  v2 = this->T.Type;
  v3 = prcc;
  if ( this->T.Type == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
      (Scaleform::GFx::AS2::FunctionRefBase *)&this->NV.8,
      prcc);
    return;
  }
  if ( v2 != 6 || (v4 = this->V.pStringNode) == 0i64 )
  {
    if ( v2 != 9 )
      return;
    v4 = this->V.pStringNode;
  }
  if ( !((--v4->RefCount >> 27) & 1) )
  {
    v4->pLower = *(Scaleform::GFx::ASStringNode **)v3->pLastPtr->pRCC->Roots.gap0;
    v4->pManager = (Scaleform::GFx::ASStringManager *)v3->pLastPtr->pRCC;
    *(_QWORD *)v3->pLastPtr->pRCC->Roots.gap0 = v4;
    v3->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4;
    v3->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v4;
    v4->RefCount |= 0x8000000u;
  }
}

// File Line: 339
// RVA: 0x7221F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToStringImpl(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv, int precision, bool debug)
{
  Scaleform::GFx::AS2::Environment *v5; // rdi
  Scaleform::GFx::ASString *v6; // rbx
  Scaleform::GFx::AS2::Value *v7; // rsi
  Scaleform::GFx::AS2::ASStringContext *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // r10
  Scaleform::GFx::ASStringNode *v10; // rdi
  int v11; // er9
  const char *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  const char *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl **v19; // rax
  __int64 v20; // r15
  unsigned __int16 v21; // cx
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  char v24; // al
  Scaleform::GFx::AS2::FunctionObject *v25; // rcx
  unsigned int v26; // edx
  Scaleform::GFx::AS2::LocalFrame *v27; // rcx
  unsigned int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // rcx
  const char *v30; // rax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASString *v33; // rdx
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS2::FunctionRef v40; // [rsp+28h] [rbp-A9h]
  Scaleform::GFx::ASString v41; // [rsp+40h] [rbp-91h]
  Scaleform::GFx::ASString v42; // [rsp+48h] [rbp-89h]
  Scaleform::GFx::ASString v43; // [rsp+50h] [rbp-81h]
  Scaleform::GFx::ASString v44; // [rsp+58h] [rbp-79h]
  char destStr[8]; // [rsp+60h] [rbp-71h]
  Scaleform::GFx::AS2::Value *v46; // [rsp+68h] [rbp-69h]
  __int64 v47; // [rsp+70h] [rbp-61h]
  __int64 v48; // [rsp+78h] [rbp-59h]
  __int64 v49; // [rsp+80h] [rbp-51h]
  char v50; // [rsp+88h] [rbp-49h]
  Scaleform::GFx::AS2::Environment *v51; // [rsp+90h] [rbp-41h]
  __int64 v52; // [rsp+98h] [rbp-39h]
  Scaleform::GFx::AS2::Value v53; // [rsp+A0h] [rbp-31h]
  Scaleform::GFx::AS2::Value v54; // [rsp+C0h] [rbp-11h]
  __int64 v55; // [rsp+E0h] [rbp+Fh]
  Scaleform::GFx::ASString resulta; // [rsp+130h] [rbp+5Fh]
  Scaleform::GFx::ASString *v57; // [rsp+138h] [rbp+67h]
  Scaleform::GFx::ASString v58; // [rsp+140h] [rbp+6Fh]

  v57 = result;
  v55 = -2i64;
  v5 = penv;
  v6 = result;
  v7 = this;
  v8 = &penv->StringContext;
  v9 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  result->pNode = v9;
  ++v9->RefCount;
  switch ( this->T.Type )
  {
    case 0:
    case 0xA:
      v10 = (Scaleform::GFx::ASStringNode *)v8->pContext->pMovieRoot->pASMovieRoot.pObject[18].vfptr;
      goto LABEL_51;
    case 1:
      Scaleform::GFx::ASString::operator=(
        result,
        (Scaleform::GFx::ASString *)&v8->pContext->pMovieRoot->pASMovieRoot.pObject[18].RefCount);
      return v6;
    case 2:
      Scaleform::GFx::ASString::operator=(
        result,
        (Scaleform::GFx::ASString *)&(&v8->pContext->pMovieRoot->pASMovieRoot.pObject->vfptr)[93i64
                                                                                            - (this->V.BooleanValue != 0)]);
      return v6;
    case 3:
      if ( precision >= 0 )
        v11 = -precision;
      else
        v11 = 10;
      v12 = Scaleform::GFx::NumberUtil::ToString(this->NV.NumberValue, destStr, 0x40ui64, v11);
      v13 = Scaleform::GFx::AS2::Environment::CreateString(v5, &resulta, v12);
      Scaleform::GFx::ASString::operator=(v6, v13);
      v14 = resulta.pNode;
      v15 = resulta.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      return v6;
    case 4:
      v16 = Scaleform::GFx::NumberUtil::IntToString(this->NV.Int32Value, destStr, 0x40ui64);
      v17 = Scaleform::GFx::AS2::Environment::CreateString(v5, &v58, v16);
      Scaleform::GFx::ASString::operator=(v6, v17);
      v18 = v58.pNode;
      v15 = v58.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      return v6;
    case 5:
      v10 = this->V.pStringNode;
      goto LABEL_51;
    case 6:
    case 7:
      v54.T.Type = 0;
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
      v20 = (__int64)v19;
      if ( !debug
        && v19
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, signed int))(*v19)->GetMemberRaw)(
             v19,
             v8,
             &v8->pContext->pMovieRoot->pASMovieRoot.pObject[25],
             &v54,
             1) )
      {
        v21 = v5->FuncCallNestingLevel;
        v5->FuncCallNestingLevel = v21 + 1;
        if ( v21 >= 0xFFu )
        {
          Scaleform::GFx::ASString::operator=(
            v6,
            (Scaleform::GFx::ASString *)&v8->pContext->pMovieRoot->pASMovieRoot.pObject[24].pASSupport);
        }
        else
        {
          v53.T.Type = 0;
          Scaleform::GFx::AS2::Value::ToFunction(&v54, &v40, v5);
          if ( v40.Function )
          {
            *(_QWORD *)destStr = &Scaleform::GFx::AS2::FnCall::`vftable';
            v46 = &v53;
            v47 = v20;
            v50 = 0;
            v48 = 0i64;
            v49 = 0i64;
            v51 = v5;
            v52 = 0i64;
            ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, char *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))v40.Function->vfptr[3].Finalize_GC)(
              v40.Function,
              destStr,
              v40.pLocalFrame,
              0i64);
            Scaleform::GFx::AS2::FnCall::~FnCall((Scaleform::GFx::AS2::FnCall *)destStr);
          }
          v22 = Scaleform::GFx::AS2::Value::ToString(&v53, &v44, v5, -1);
          Scaleform::GFx::ASString::operator=(v6, v22);
          v23 = v44.pNode;
          v15 = v44.pNode->RefCount == 1;
          --v23->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          v24 = v40.Flags;
          if ( !(v40.Flags & 2) )
          {
            v25 = v40.Function;
            if ( v40.Function )
            {
              v26 = v40.Function->RefCount;
              if ( v26 & 0x3FFFFFF )
              {
                v40.Function->RefCount = v26 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
                v24 = v40.Flags;
              }
            }
          }
          v40.Function = 0i64;
          if ( !(v24 & 1) )
          {
            v27 = v40.pLocalFrame;
            if ( v40.pLocalFrame )
            {
              v28 = v40.pLocalFrame->RefCount;
              if ( v28 & 0x3FFFFFF )
              {
                v40.pLocalFrame->RefCount = v28 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v27->vfptr);
              }
            }
          }
          v40.pLocalFrame = 0i64;
          if ( v53.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v53);
        }
        --v5->FuncCallNestingLevel;
      }
      else if ( v7->T.Type == 6
             && (v29 = v7->V.pStringNode) != 0i64
             && (v30 = (const char *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::Environment *))(*(_QWORD *)&v29->Size + 8i64))(
                                       &v29->Size,
                                       v5)) != 0i64 )
      {
        v31 = Scaleform::GFx::AS2::Environment::CreateString(v5, &v42, v30);
        Scaleform::GFx::ASString::operator=(v6, v31);
        v32 = v42.pNode;
        v15 = v42.pNode->RefCount == 1;
        --v32->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      }
      else
      {
        if ( v7->T.Type == 7 && v7->V.pStringNode )
          v33 = Scaleform::GFx::AS2::Value::GetCharacterNamePath(v7, v5);
        else
          v33 = (Scaleform::GFx::ASString *)&v8->pContext->pMovieRoot->pASMovieRoot.pObject[24].AVMVersion;
        Scaleform::GFx::ASString::operator=(v6, v33);
      }
      if ( v54.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v54);
      return v6;
    case 8:
    case 0xB:
      v10 = (Scaleform::GFx::ASStringNode *)v8->pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl;
      goto LABEL_51;
    case 9:
      v34 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v43, "[property]");
      Scaleform::GFx::ASString::operator=(v6, v34);
      v35 = v43.pNode;
      v15 = v43.pNode->RefCount == 1;
      --v35->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      break;
    case 0xC:
      v36 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v41, "[resolveHandler]");
      Scaleform::GFx::ASString::operator=(v6, v36);
      v37 = v41.pNode;
      v15 = v41.pNode->RefCount == 1;
      --v37->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      break;
    default:
      v10 = *(Scaleform::GFx::ASStringNode **)&v8->pContext->pMovieRoot->pASMovieRoot.pObject[17].RefCount;
LABEL_51:
      ++v10->RefCount;
      v38 = result->pNode;
      v15 = result->pNode->RefCount == 1;
      --v38->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      v6->pNode = v10;
      break;
  }
  return v6;
}

// File Line: 488
// RVA: 0x7214A0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToDebugString(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, 1);
  return v3;
}

// File Line: 495
// RVA: 0x7226B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToStringVersioned(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv, unsigned int version)
{
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASMovieRootBase *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx

  v4 = result;
  if ( this->T.Type && this->T.Type != 10 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, 0);
    v5 = v4;
  }
  else
  {
    v6 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( version - 1 > 5 )
      v7 = (Scaleform::GFx::ASStringNode *)v6[18].vfptr;
    else
      v7 = *(Scaleform::GFx::ASStringNode **)&v6[7].AVMVersion;
    result->pNode = v7;
    ++v7->RefCount;
    v5 = result;
  }
  return v5;
}

// File Line: 515
// RVA: 0x721750
long double __fastcall Scaleform::GFx::AS2::Value::ToNumber(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  char v4; // al
  bool v6; // cf
  bool v7; // zf
  Scaleform::GFx::AS2::ObjectInterface *v8; // rax
  Scaleform::GFx::AS2::ObjectInterface *v9; // rsi
  unsigned __int16 v10; // cx
  double v11; // xmm0_8
  double v12; // xmm6_8
  char v13; // al
  Scaleform::GFx::AS2::FunctionObject *v14; // rcx
  unsigned int v15; // edx
  Scaleform::GFx::AS2::LocalFrame *v16; // rcx
  unsigned int v17; // eax
  const char *v18; // rax
  unsigned int v19; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+18h] [rbp-69h]
  Scaleform::GFx::AS2::Value v21; // [rsp+30h] [rbp-51h]
  Scaleform::GFx::AS2::FnCall v22; // [rsp+58h] [rbp-29h]
  Scaleform::GFx::AS2::Value v23; // [rsp+98h] [rbp+17h]
  __int64 v24; // [rsp+B8h] [rbp+37h]
  double retaddr; // [rsp+E8h] [rbp+67h]

  v24 = -2i64;
  v2 = penv;
  v3 = this;
  v4 = this->T.Type;
  if ( this->T.Type == 3 )
    return this->NV.NumberValue;
  switch ( v4 )
  {
    case 4:
      return (double)this->NV.Int32Value;
    case 5:
      if ( Scaleform::GFx::AS2::StringToNumber(&retaddr, this->V.pStringNode->pData) )
        return retaddr;
      return Scaleform::GFx::NumberUtil::NaN();
    case 1:
      v6 = penv->StringContext.SWFVersion < 6u;
      v7 = penv->StringContext.SWFVersion == 6;
      goto LABEL_49;
    case 2:
      if ( this->V.BooleanValue )
        return DOUBLE_1_0;
      return 0.0;
    case 7:
      return Scaleform::GFx::NumberUtil::NaN();
  }
  if ( (v4 != 6 || !this->V.pStringNode) && v4 != 8 )
  {
    if ( v4 && v4 != 10 )
      return 0.0;
    v19 = (unsigned __int8)penv->StringContext.SWFVersion - 1;
    v6 = v19 < 5;
    v7 = v19 == 5;
LABEL_49:
    if ( !v6 && !v7 )
      return Scaleform::GFx::NumberUtil::NaN();
    return 0.0;
  }
  v23.T.Type = 0;
  v8 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
  v9 = v8;
  if ( v2
    && v8->vfptr->GetMemberRaw(
         v8,
         &v2->StringContext,
         (Scaleform::GFx::ASString *)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].RefCount,
         &v23) )
  {
    v10 = v2->FuncCallNestingLevel;
    v2->FuncCallNestingLevel = v10 + 1;
    if ( v10 >= 0xFFu )
    {
      v12 = Scaleform::GFx::NumberUtil::NaN();
    }
    else
    {
      v21.T.Type = 0;
      Scaleform::GFx::AS2::Value::ToFunction(&v23, &result, v2);
      if ( result.Function )
      {
        v22.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
        v22.Result = &v21;
        v22.ThisPtr = v9;
        v22.ThisFunctionRef.Flags = 0;
        v22.ThisFunctionRef.Function = 0i64;
        v22.ThisFunctionRef.pLocalFrame = 0i64;
        v22.Env = v2;
        *(_QWORD *)&v22.NArgs = 0i64;
        ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))result.Function->vfptr[3].Finalize_GC)(
          result.Function,
          &v22,
          result.pLocalFrame,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v22);
      }
      if ( (unsigned __int8)(v21.T.Type - 1) > 4u )
        v11 = Scaleform::GFx::NumberUtil::NaN();
      else
        v11 = Scaleform::GFx::AS2::Value::ToNumber(&v21, v2);
      v12 = v11;
      v13 = result.Flags;
      if ( !(result.Flags & 2) )
      {
        v14 = result.Function;
        if ( result.Function )
        {
          v15 = result.Function->RefCount;
          if ( v15 & 0x3FFFFFF )
          {
            result.Function->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
            v13 = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( !(v13 & 1) )
      {
        v16 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v17 = result.pLocalFrame->RefCount;
          if ( v17 & 0x3FFFFFF )
          {
            result.pLocalFrame->RefCount = v17 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
          }
        }
      }
      result.pLocalFrame = 0i64;
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
    }
    --v2->FuncCallNestingLevel;
  }
  else if ( v3->T.Type == 7 )
  {
    v12 = Scaleform::GFx::NumberUtil::NaN();
  }
  else
  {
    v18 = (const char *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))v9->vfptr->gap8)(
                          v9,
                          v2);
    if ( v18 )
      v12 = atof(v18);
    else
      v12 = 0.0;
  }
  if ( v23.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v23);
  return v12;
}

// File Line: 634
// RVA: 0x721610
__int64 __usercall Scaleform::GFx::AS2::Value::ToInt32@<rax>(Scaleform::GFx::AS2::Value *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, __m128d a3@<xmm0>)
{
  __int64 result; // rax
  double v4; // xmm6_8
  __m128d v5; // xmm0
  __int64 v6; // rcx

  if ( this->T.Type == 4 )
    return this->NV.UInt32Value;
  a3.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v4 = a3.m128d_f64[0];
  if ( (*(_QWORD *)&a3.m128d_f64[0] & 0x7FF0000000000000i64) == 9218868437227405312i64 || a3.m128d_f64[0] == 0.0 )
    return 0i64;
  if ( a3.m128d_f64[0] >= -2147483648.0 && a3.m128d_f64[0] <= 2147483647.0 )
    return (unsigned int)(signed int)a3.m128d_f64[0];
  v5 = _mm_and_pd(a3, (__m128d)_xmm);
  v6 = (unsigned int)(signed int)v5.m128d_f64[0];
  if ( v6 != 0x8000000000000000i64 && (double)(signed int)v6 != v5.m128d_f64[0] )
    v5.m128d_f64[0] = (double)(signed int)(v6 - (_mm_movemask_pd(_mm_unpckl_pd(v5, v5)) & 1));
  result = (unsigned int)(signed int)fmod(v5.m128d_f64[0], 4294967296.0);
  if ( v4 < 0.0 )
    result = (unsigned int)-(signed int)result;
  return result;
}

// File Line: 663
// RVA: 0x722740
__int64 __usercall Scaleform::GFx::AS2::Value::ToUInt32@<rax>(Scaleform::GFx::AS2::Value *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, __m128d a3@<xmm0>)
{
  __int64 result; // rax
  double v4; // xmm6_8
  __m128d v5; // xmm0
  __int64 v6; // rcx

  if ( this->T.Type == 4 )
    return this->NV.UInt32Value;
  a3.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v4 = a3.m128d_f64[0];
  if ( (*(_QWORD *)&a3.m128d_f64[0] & 0x7FF0000000000000i64) == 9218868437227405312i64 || a3.m128d_f64[0] == 0.0 )
    return 0i64;
  if ( a3.m128d_f64[0] >= 0.0 && a3.m128d_f64[0] <= 4294967295.0 )
    return (unsigned int)(signed int)a3.m128d_f64[0];
  v5 = _mm_and_pd(a3, (__m128d)_xmm);
  v6 = (unsigned int)(signed int)v5.m128d_f64[0];
  if ( v6 != 0x8000000000000000i64 && (double)(signed int)v6 != v5.m128d_f64[0] )
    v5.m128d_f64[0] = (double)(signed int)(v6 - (_mm_movemask_pd(_mm_unpckl_pd(v5, v5)) & 1));
  result = (unsigned int)(signed int)fmod(v5.m128d_f64[0], 4294967296.0);
  if ( v4 < 0.0 )
    result = (unsigned int)-(signed int)result;
  return result;
}

// File Line: 688
// RVA: 0x7212C0
char __fastcall Scaleform::GFx::AS2::Value::ToBool(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  char v2; // al
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::GFx::ASStringNode *v4; // rdx
  char v5; // al
  double v6; // xmm6_8
  Scaleform::GFx::ASStringNode *v7; // rax
  long double result; // [rsp+40h] [rbp+8h]

  v2 = this->T.Type;
  v3 = penv;
  if ( this->T.Type == 5 )
  {
    v4 = this->V.pStringNode;
    if ( !v4->Size )
      return 0;
    if ( v3->StringContext.SWFVersion > 6u )
    {
      v5 = 1;
    }
    else
    {
      if ( !Scaleform::GFx::AS2::StringToNumber(&result, v4->pData) )
        return 0;
      v6 = result;
      if ( Scaleform::GFx::NumberUtil::IsNaN(result) )
        v5 = 0;
      else
        v5 = v6 != 0.0;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 3:
        v7 = this->V.pStringNode;
        if ( ((unsigned __int64)v7 & 0x7FF0000000000000i64) == 9218868437227405312i64
          && (unsigned __int64)v7 & 0xFFFFFFFFFFFFFi64 )
        {
          return 0;
        }
        v5 = this->NV.NumberValue != 0.0;
        break;
      case 4:
        return this->NV.Int32Value != 0;
      case 2:
        return this->V.BooleanValue;
      case 6:
        return this->V.pStringNode != 0i64;
      case 7:
        return Scaleform::GFx::AS2::Value::ToCharacter(this, penv) != 0i64;
      case 8:
        return this->V.pStringNode != 0i64;
      default:
        v5 = v2 == 11;
        break;
    }
  }
  return v5;
}

// File Line: 771
// RVA: 0x721A10
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Value::ToObject(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rbx
  int v4; // ecx
  __int64 v5; // rdi
  char v6; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  int v8; // edx
  Scaleform::GFx::ASStringNode *v9; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::Object *result; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  int v13; // edx
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::InteractiveObject *v16; // rcx
  signed __int64 v17; // rcx
  __int64 v18; // rax
  Scaleform::GFx::AS2::Object *v19; // rbx
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h]

  v2 = penv;
  v3 = this;
  v4 = (unsigned __int8)this->T.Type;
  if ( v4 == 6 )
    return v3->V.pObjectValue;
  if ( v4 == 8 )
  {
    result = v3->V.pObjectValue;
    if ( result )
      return result;
    return 0i64;
  }
  if ( v4 != 9 )
  {
    if ( v4 == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(v3, (Scaleform::GFx::AS2::FunctionRef *)&value, penv);
      v5 = *(_QWORD *)&value.T.Type;
      v6 = *((_BYTE *)&value.NV + 16);
      if ( *(_QWORD *)&value.T.Type )
      {
        if ( !(*((char *)&value.NV + 16) & 2) )
        {
          v7 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
          if ( *(_QWORD *)&value.T.Type )
          {
            v8 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
            if ( v8 & 0x3FFFFFF )
            {
              *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v8 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
              v6 = *((_BYTE *)&value.NV + 16);
            }
          }
        }
        *(_QWORD *)&value.T.Type = 0i64;
        if ( !(v6 & 1) )
        {
          v9 = value.V.pStringNode;
          if ( value.V.pStringNode )
          {
            v10 = value.V.pStringNode->RefCount;
            if ( v10 & 0x3FFFFFF )
            {
              value.V.pStringNode->RefCount = v10 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
            }
          }
        }
        value.V.pStringNode = 0i64;
        return (Scaleform::GFx::AS2::Object *)v5;
      }
      if ( !(*((char *)&value.NV + 16) & 2) )
      {
        v12 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
        if ( *(_QWORD *)&value.T.Type )
        {
          v13 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
          if ( v13 & 0x3FFFFFF )
          {
            *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
            v6 = *((_BYTE *)&value.NV + 16);
          }
        }
      }
      *(_QWORD *)&value.T.Type = 0i64;
      if ( !(v6 & 1) )
      {
        v14 = value.V.pStringNode;
        if ( value.V.pStringNode )
        {
          v15 = value.V.pStringNode->RefCount;
          if ( v15 & 0x3FFFFFF )
          {
            value.V.pStringNode->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
          }
        }
      }
      value.V.pStringNode = 0i64;
    }
    return 0i64;
  }
  v16 = penv->Target;
  if ( !v16 )
    return 0i64;
  v17 = (signed __int64)v16 + 4 * (unsigned __int8)v16->AvmObjOffset;
  v18 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v17 + 8i64))(v17);
  if ( !v18 )
    return 0i64;
  value.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Value::GetPropertyValue(v3, v2, (Scaleform::GFx::AS2::ObjectInterface *)(v18 + 8), &value) )
  {
    if ( value.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    return 0i64;
  }
  v19 = Scaleform::GFx::AS2::Value::ToObject(&value, v2);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  return v19;
}lue::ToObject(&valu

// File Line: 824
// RVA: 0x721440
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Value::ToCharacter(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *v2; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::GFx::InteractiveObject *v4; // rdx
  char v5; // cl
  Scaleform::GFx::InteractiveObject *result; // rax

  if ( this->T.Type != 7 )
    return 0i64;
  if ( !penv )
    return 0i64;
  v2 = this->V.pStringNode;
  if ( !v2 )
    return 0i64;
  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)v2,
         penv->Target->pASRoot->pMovieImpl);
  v4 = (Scaleform::GFx::InteractiveObject *)v3;
  if ( !v3 )
    return 0i64;
  v5 = LOBYTE(v3->Flags) >> 7;
  result = 0i64;
  if ( v5 & 1 )
    result = v4;
  return result;
}

// File Line: 837
// RVA: 0x721BD0
Scaleform::GFx::AS2::ObjectInterfaceVtbl **__fastcall Scaleform::GFx::AS2::Value::ToObjectInterface(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *v2; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::GFx::DisplayObject *v4; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS2::Object *v7; // rax

  if ( this->T.Type == 7 )
  {
    if ( penv )
    {
      v2 = this->V.pStringNode;
      if ( v2 )
      {
        v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)v2,
               penv->Target->pASRoot->pMovieImpl);
        if ( v3 )
        {
          v4 = 0i64;
          if ( SLOBYTE(v3->Flags) < 0 )
            v4 = v3;
          if ( v4 )
          {
            v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr
                                                                             + 4 * (unsigned __int8)v4->AvmObjOffset))[1].__vecDelDtor)();
            if ( v5 )
              return (Scaleform::GFx::AS2::ObjectInterfaceVtbl **)(v5 + 8);
          }
        }
      }
    }
  }
  else
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(this, penv);
    if ( v7 )
      return &v7->vfptr;
  }
  return 0i64;
}

// File Line: 848
// RVA: 0x721570
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ToFunction(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // rbx
  Scaleform::GFx::ASStringNode *v5; // rdx
  Scaleform::GFx::AS2::LocalFrame *v6; // rdx

  v3 = result;
  if ( this->T.Type == 8 )
  {
    result->Flags = 0;
    v5 = this->V.pStringNode;
    v3->Function = (Scaleform::GFx::AS2::FunctionObject *)v5;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    v3->pLocalFrame = 0i64;
    v6 = this->V.FunctionValue.pLocalFrame;
    if ( v6 )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v3->Function,
        v6,
        this->V.FunctionValue.Flags & 1);
  }
  else
  {
    if ( this->T.Type != 11 )
    {
      result->Flags = 0;
      result->Function = 0i64;
      result->pLocalFrame = 0i64;
      return result;
    }
    Scaleform::GFx::AS2::Value::ResolveFunctionName(this, result, penv);
  }
  return v3;
}

// File Line: 861
// RVA: 0x722040
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ToResolveHandler(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::FunctionRef *result)
{
  Scaleform::GFx::AS2::FunctionRef *v2; // rbx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // rdx
  Scaleform::GFx::AS2::LocalFrame *v5; // rdx
  Scaleform::GFx::AS2::FunctionRef *v6; // rax

  v2 = result;
  v3 = this->T.Type == 12;
  result->Flags = 0;
  if ( v3 )
  {
    v4 = this->V.pStringNode;
    v2->Function = (Scaleform::GFx::AS2::FunctionObject *)v4;
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
    v2->pLocalFrame = 0i64;
    v5 = this->V.FunctionValue.pLocalFrame;
    if ( v5 )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v2->Function,
        v5,
        this->V.FunctionValue.Flags & 1);
    v6 = v2;
  }
  else
  {
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
    v6 = result;
  }
  return v6;
}

// File Line: 869
// RVA: 0x6DF5D0
void __fastcall Scaleform::GFx::AS2::Value::ConvertToNumber(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *pEnv)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  double v3; // xmm0_8

  v2 = this;
  v3 = Scaleform::GFx::AS2::Value::ToNumber(this, pEnv);
  if ( v2->T.Type < 5u )
  {
    v2->NV.NumberValue = v3;
    v2->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->T.Type = 3;
    v2->NV.NumberValue = v3;
  }
}

// File Line: 886
// RVA: 0x6DF620
void __fastcall Scaleform::GFx::AS2::Value::ConvertToStringVersioned(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *pEnv, unsigned int version)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v3 = this;
  Scaleform::GFx::AS2::Value::ToStringVersioned(this, &result, pEnv, version);
  Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->T.Type = 5;
  v4 = result.pNode;
  v3->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++v4->RefCount;
  v5 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 896
// RVA: 0x713130
void __fastcall Scaleform::GFx::AS2::Value::SetAsObject(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Object *obj)
{
  Scaleform::GFx::AS2::Object *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::FunctionRefBase *v4; // rax
  char v5; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // [rsp+30h] [rbp-18h]
  char v12; // [rsp+38h] [rbp-10h]

  v2 = obj;
  v3 = this;
  if ( obj
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&obj->vfptr->gap8[8])(&obj->vfptr) == 23 )
  {
    v4 = (Scaleform::GFx::AS2::FunctionRefBase *)v2->vfptr->ToFunction(
                                                   (Scaleform::GFx::AS2::ObjectInterface *)&v2->vfptr,
                                                   (Scaleform::GFx::AS2::FunctionRef *)&v10);
    Scaleform::GFx::AS2::Value::SetAsFunction(v3, v4);
    v5 = v12;
    if ( !(v12 & 2) )
    {
      v6 = v10;
      if ( v10 )
      {
        v7 = v10->RefCount;
        if ( v7 & 0x3FFFFFF )
        {
          v10->RefCount = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          v5 = v12;
        }
      }
    }
    v10 = 0i64;
    if ( !(v5 & 1) )
    {
      v8 = v11;
      if ( v11 )
      {
        v9 = v11->RefCount;
        if ( v9 & 0x3FFFFFF )
        {
          v11->RefCount = v9 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
    v11 = 0i64;
  }
  else if ( v3->T.Type != 6 || v3->V.pObjectValue != v2 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(v3);
    v3->T.Type = 6;
    v3->V.pStringNode = (Scaleform::GFx::ASStringNode *)v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 912
// RVA: 0x713080
void __fastcall Scaleform::GFx::AS2::Value::SetAsCharacterHandle(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::CharacterHandle *pchar)
{
  Scaleform::GFx::CharacterHandle *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rdi

  v2 = pchar;
  v3 = this;
  if ( this->T.Type != 7 || this->V.pCharHandle != pchar )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    v3->T.Type = 7;
    v3->V.pStringNode = (Scaleform::GFx::ASStringNode *)v2;
    if ( v2 )
      ++v2->RefCount;
  }
}

// File Line: 924
// RVA: 0x713020
void __fastcall Scaleform::GFx::AS2::Value::SetAsCharacter(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::InteractiveObject *pchar)
{
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::CharacterHandle *v3; // rbx

  v2 = this;
  if ( pchar )
  {
    v3 = pchar->pNameHandle.pObject;
    if ( !v3 )
      v3 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&pchar->vfptr);
  }
  else
  {
    v3 = 0i64;
  }
  if ( v2->T.Type != 7 || v2->V.pCharHandle != v3 )
  {
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->T.Type = 7;
    v2->V.pStringNode = (Scaleform::GFx::ASStringNode *)v3;
    if ( v3 )
      ++v3->RefCount;
  }
}

// File Line: 934
// RVA: 0x713220
void __fastcall Scaleform::GFx::AS2::Value::SetAsObjectInterface(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  unsigned int v4; // eax
  bool v5; // cf
  bool v6; // zf
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v7; // rax
  Scaleform::GFx::DisplayObject *v8; // rcx
  Scaleform::GFx::CharacterHandle *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rbx

  v2 = this;
  v3 = pobj;
  v4 = (unsigned __int64)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&pobj->vfptr->gap8[8])(pobj)
     - 2;
  v5 = v4 < 3;
  v6 = v4 == 3;
  v7 = v3->vfptr;
  if ( v5 || v6 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->gap8[8])(v3) - 2 <= 3
      && (v8 = (Scaleform::GFx::DisplayObject *)v3[1].vfptr) != 0i64 )
    {
      v9 = v8->pNameHandle.pObject;
      if ( !v9 )
        v9 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v8);
    }
    else
    {
      v9 = 0i64;
    }
    if ( v2->T.Type != 7 || v2->V.pCharHandle != v9 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v2);
      v2->T.Type = 7;
      v2->V.pStringNode = (Scaleform::GFx::ASStringNode *)v9;
      if ( v9 )
        ++v9->RefCount;
    }
  }
  else
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->gap8[8])(v3) - 6 > 0x26 )
      v10 = 0i64;
    else
      v10 = (Scaleform::GFx::AS2::Object *)&v3[-2];
    Scaleform::GFx::AS2::Value::SetAsObject(v2, v10);
  }
}

// File Line: 944
// RVA: 0x7130C0
void __fastcall Scaleform::GFx::AS2::Value::SetAsFunction(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::FunctionRefBase *func)
{
  Scaleform::GFx::AS2::FunctionRefBase *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::FunctionRefBase *v4; // rcx
  Scaleform::GFx::AS2::FunctionObject *v5; // rdx
  Scaleform::GFx::AS2::LocalFrame *v6; // rdx

  v2 = func;
  v3 = this;
  if ( this->T.Type != 8 || this->V.pStringNode != (Scaleform::GFx::ASStringNode *)func->Function )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    v3->T.Type = 8;
    v4 = (Scaleform::GFx::AS2::FunctionRefBase *)&v3->NV.8;
    v4->Flags = 0;
    v5 = v2->Function;
    v4->Function = v2->Function;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    v3->V.FunctionValue.pLocalFrame = 0i64;
    v6 = v2->pLocalFrame;
    if ( v6 )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v4, v6, v2->Flags & 1);
  }
}

// File Line: 962
// RVA: 0x6D7950
void __fastcall Scaleform::GFx::AS2::Value::Add(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  char v8; // bl
  double v9; // xmm6_8
  double v10; // xmm6_8
  unsigned int v11; // ebx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rbx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rsi
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS2::Value v22; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-19h]
  Scaleform::GFx::ASString v24; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS2::Value v25; // [rsp+48h] [rbp-9h]
  Scaleform::GFx::AS2::Value result; // [rsp+68h] [rbp+17h]
  __int64 v27; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::ASString v28; // [rsp+D0h] [rbp+7Fh]

  v27 = -2i64;
  v3 = v;
  v4 = penv;
  v5 = this;
  v25.T.Type = 0;
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, 0);
  Scaleform::GFx::AS2::Value::operator=(&v22, v6, (__int64)v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v7 = Scaleform::GFx::AS2::Value::ToPrimitive(v3, &result, v4, 0);
  Scaleform::GFx::AS2::Value::operator=(&v25, v7, (__int64)v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v8 = v22.T.Type;
  if ( v22.T.Type == 5 || v25.T.Type == 5 )
  {
    v11 = (unsigned __int8)v4->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v22, &v28, v4, v11);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v28.pNode;
    ++v22.V.pStringNode->RefCount;
    v12 = v28.pNode;
    v13 = v28.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v14 = Scaleform::GFx::AS2::Value::ToStringVersioned(&v25, &v24, v4, v11);
    v15 = Scaleform::GFx::AS2::Value::ToString(&v22, &v23, v4, -1);
    Scaleform::GFx::ASString::operator+(v15, &v28, v14);
    v16 = v23.pNode;
    v13 = v23.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v8 = 5;
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v28.pNode;
    ++v22.V.pStringNode->RefCount;
    v17 = v28.pNode;
    v13 = v28.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    v18 = v24.pNode;
    v13 = v24.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    v19 = Scaleform::GFx::AS2::Value::ToString(&v22, &v28, v4, -1);
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 5;
    v20 = v19->pNode;
    v5->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v19->pNode;
    ++v20->RefCount;
    v21 = v28.pNode;
    v13 = v28.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  }
  else
  {
    v9 = Scaleform::GFx::AS2::Value::ToNumber(&v25, v4);
    v10 = v9 + Scaleform::GFx::AS2::Value::ToNumber(&v22, v4);
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 3;
    v5->NV.NumberValue = v10;
  }
  if ( v25.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v25);
  if ( (unsigned __int8)v8 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
}

// File Line: 983
// RVA: 0x6D7B70
void __fastcall Scaleform::GFx::AS2::Value::Add(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, int v2)
{
  signed int v3; // er14
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rax
  char v7; // bl
  unsigned int v8; // ebx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rbx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rsi
  Scaleform::GFx::ASStringNode *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  double v19; // xmm6_8
  Scaleform::GFx::ASString v20; // [rsp+8h] [rbp-29h]
  Scaleform::GFx::ASString v21; // [rsp+10h] [rbp-21h]
  Scaleform::GFx::AS2::Value v22; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS2::Value result; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::ASString v24; // [rsp+B0h] [rbp+7Fh]

  v3 = v2;
  v4 = penv;
  v5 = this;
  v22.T.Type = 0;
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, 0);
  Scaleform::GFx::AS2::Value::operator=(&v22, v6, (__int64)v5);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v7 = v22.T.Type;
  if ( v22.T.Type == 5 )
  {
    v8 = (unsigned __int8)v4->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v22, &v24, v4, v8);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v24.pNode;
    ++v22.V.pStringNode->RefCount;
    v9 = v24.pNode;
    v10 = v24.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    result.T.Type = 4;
    result.NV.Int32Value = v3;
    v11 = Scaleform::GFx::AS2::Value::ToStringVersioned(&result, &v21, v4, v8);
    v12 = Scaleform::GFx::AS2::Value::ToString(&v22, &v20, v4, -1);
    Scaleform::GFx::ASString::operator+(v12, &v24, v11);
    v13 = v20.pNode;
    v10 = v20.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v7 = 5;
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v24.pNode;
    ++v22.V.pStringNode->RefCount;
    v14 = v24.pNode;
    v10 = v24.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = v21.pNode;
    v10 = v21.pNode->RefCount == 1;
    --v15->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v16 = Scaleform::GFx::AS2::Value::ToString(&v22, &v24, v4, -1);
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 5;
    v17 = v16->pNode;
    v5->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v16->pNode;
    ++v17->RefCount;
    v18 = v24.pNode;
    v10 = v24.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    v19 = Scaleform::GFx::AS2::Value::ToNumber(&v22, v4) + (double)v3;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    v5->T.Type = 3;
    v5->NV.NumberValue = v19;
  }
  if ( (unsigned __int8)v7 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
}

// File Line: 1003
// RVA: 0x721100
void __fastcall Scaleform::GFx::AS2::Value::Sub(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rsi
  double v6; // xmm6_8
  double v7; // xmm7_8

  v3 = v;
  v4 = penv;
  v5 = this;
  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v3, v4);
  if ( v5->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v5);
  v5->NV.NumberValue = v6 - v7;
  v5->T.Type = 3;
}

// File Line: 1010
// RVA: 0x721170
void __fastcall Scaleform::GFx::AS2::Value::Sub(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, int v2)
{
  int v3; // edi
  Scaleform::GFx::AS2::Value *v4; // rbx
  double v5; // xmm6_8

  v3 = v2;
  v4 = this;
  v5 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  if ( v4->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->T.Type = 3;
  v4->NV.NumberValue = v5 - (double)v3;
}

// File Line: 1016
// RVA: 0x703160
void __fastcall Scaleform::GFx::AS2::Value::Mul(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rsi
  double v6; // xmm7_8
  double v7; // xmm6_8

  v3 = v;
  v4 = penv;
  v5 = this;
  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v3, v4);
  if ( v5->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v5);
  v5->T.Type = 3;
  v5->NV.NumberValue = v7 * v6;
}

// File Line: 1024
// RVA: 0x700440
char __fastcall Scaleform::GFx::AS2::Value::IsEqual(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rsi
  char v6; // r9
  bool v7; // al
  unsigned __int8 v8; // r8
  bool v9; // cl
  bool v10; // bl
  signed int v12; // ecx
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  signed int v17; // ecx
  long double v18; // xmm0_8
  double v19; // xmm7_8
  bool v20; // bl
  __int128 v21; // xmm6
  signed int v22; // ecx
  bool v23; // zf
  Scaleform::GFx::ASStringNode *v24; // rax
  Scaleform::GFx::ASString *v25; // rbx
  Scaleform::GFx::AS2::Value result; // [rsp+8h] [rbp-69h]
  Scaleform::GFx::AS2::Value v27; // [rsp+28h] [rbp-49h]
  Scaleform::GFx::AS2::Value va; // [rsp+48h] [rbp-29h]
  Scaleform::GFx::AS2::Value v29; // [rsp+68h] [rbp-9h]
  __int64 v30; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::ASString v31; // [rsp+D8h] [rbp+67h]
  Scaleform::GFx::ASStringNode *retaddr; // [rsp+E8h] [rbp+77h]

  v30 = -2i64;
  v3 = v;
  v4 = penv;
  v5 = this;
  v6 = this->T.Type;
  v7 = this->T.Type <= 1u || v6 == 10;
  v8 = v->T.Type;
  v9 = v8 <= 1u || v8 == 10;
  if ( v7 || v9 )
    return v7 == v9;
  switch ( v6 )
  {
    case 2:
      v29.T.Type = 3;
      v29.V.pStringNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(v5, penv));
      v10 = Scaleform::GFx::AS2::Value::IsEqual(&v29, v4, v3);
      if ( v29.T.Type < 5u )
        return v10;
      v13 = &v29;
      goto LABEL_26;
    case 3:
      if ( v8 != 2 && v8 <= 0xBu )
      {
        v17 = 2368;
        if ( _bittest(&v17, v8) )
        {
          Scaleform::GFx::AS2::Value::ToPrimitive(v3, &result, penv, 0);
          if ( (unsigned __int8)(result.T.Type - 1) > 4u )
            v10 = 0;
          else
            v10 = Scaleform::GFx::AS2::Value::IsEqual(v5, v4, &result);
          goto LABEL_24;
        }
      }
      v18 = Scaleform::GFx::AS2::Value::ToNumber(v3, penv);
      v19 = v5->NV.NumberValue;
      v20 = Scaleform::GFx::NumberUtil::IsNaN(v5->NV.NumberValue);
      if ( v20 && Scaleform::GFx::NumberUtil::IsNaN(v18) )
        return 1;
      if ( !v20 && !Scaleform::GFx::NumberUtil::IsNaN(v18) )
        return v19 == v18;
      return 0;
    case 4:
      if ( v8 == 3 )
      {
        result.T.Type = 0;
        v21 = COERCE_UNSIGNED_INT64((double)v5->NV.Int32Value);
        v10 = Scaleform::GFx::AS2::Value::IsEqual(&result, penv, v3);
        goto LABEL_24;
      }
      if ( v8 == 2 )
        return v5->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v3, penv);
      if ( v8 > 0xBu )
        return v5->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v3, penv);
      v22 = 2368;
      if ( !_bittest(&v22, v8) )
        return v5->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v3, penv);
      Scaleform::GFx::AS2::Value::ToPrimitive(v3, &result, penv, 0);
      if ( (unsigned __int8)(result.T.Type - 1) > 4u )
        v10 = 0;
      else
        v10 = Scaleform::GFx::AS2::Value::IsEqual(v5, v4, &result);
      goto LABEL_24;
    case 5:
      if ( (unsigned __int8)(v8 - 3) <= 1u )
      {
        v27.T.Type = 3;
        v27.V.pStringNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(v5, penv));
        v10 = Scaleform::GFx::AS2::Value::IsEqual(&v27, v4, v3);
        if ( v27.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v27);
        return v10;
      }
      if ( v8 == 2 )
      {
        va.T.Type = 3;
        va.V.pStringNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(v3, penv));
        v10 = Scaleform::GFx::AS2::Value::IsEqual(v5, v4, &va);
        if ( va.T.Type < 5u )
          return v10;
        Scaleform::GFx::AS2::Value::DropRefs(&va);
        return v10;
      }
      if ( v8 <= 0xBu )
      {
        v12 = 2368;
        if ( _bittest(&v12, v8) )
        {
          Scaleform::GFx::AS2::Value::ToPrimitive(v3, &result, penv, 0);
          if ( (unsigned __int8)(result.T.Type - 1) > 4u )
            v10 = 0;
          else
            v10 = Scaleform::GFx::AS2::Value::IsEqual(v5, v4, &result);
          goto LABEL_24;
        }
      }
      v14 = Scaleform::GFx::AS2::Value::ToString(v3, &v31, penv, -1);
      v15 = v5->V.pStringNode;
      retaddr = v15;
      ++v15->RefCount;
      v10 = v15 == v14->pNode;
      v23 = v15->RefCount-- == 1;
      if ( v23 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v16 = v31.pNode;
      v23 = v31.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v23 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        return v10;
      }
      return v10;
    case 6:
    case 8:
      if ( (unsigned __int8)(v8 - 2) <= 3u )
      {
        Scaleform::GFx::AS2::Value::ToPrimitive(v5, &result, penv, 0);
        if ( (unsigned __int8)(result.T.Type - 1) > 4u )
          v10 = 0;
        else
          v10 = Scaleform::GFx::AS2::Value::IsEqual(&result, v4, v3);
LABEL_24:
        if ( result.T.Type < 5u )
          return v10;
        v13 = &result;
LABEL_26:
        Scaleform::GFx::AS2::Value::DropRefs(v13);
        return v10;
      }
      if ( (v6 != 6 || v8 != 6) && (v6 != 8 || v8 != 8) )
        return 0;
      v23 = v5->V.pStringNode == v3->V.pStringNode;
      break;
    case 7:
      if ( v8 != 7 )
        return 0;
      v24 = v5->V.pStringNode;
      if ( !v24 || !v3->V.pStringNode )
        return v24 == v3->V.pStringNode;
      v25 = Scaleform::GFx::AS2::Value::GetCharacterNamePath(v3, penv);
      return Scaleform::GFx::AS2::Value::GetCharacterNamePath(v5, v4)->pNode == v25->pNode;
    default:
      return v6 == v8;
  }
  return v23;
}

// File Line: 1150
// RVA: 0x6DEA50
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Value::Compare(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v4; // r14
  Scaleform::GFx::AS2::Environment *v5; // rsi
  Scaleform::GFx::AS2::Value *v6; // rdi
  int v7; // ebx
  bool v8; // al
  Scaleform::GFx::ASString *v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  bool v11; // al
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::ASString *v16; // rax
  bool v17; // al
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  double v20; // xmm0_8
  long double v21; // xmm6_8
  long double v22; // xmm7_8
  bool v23; // al
  Scaleform::GFx::ASString v25; // [rsp+10h] [rbp-39h]
  Scaleform::GFx::ASString v26; // [rsp+18h] [rbp-31h]
  __int64 v27; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::AS2::Value v28; // [rsp+28h] [rbp-21h]
  Scaleform::GFx::AS2::Value resulta; // [rsp+48h] [rbp-1h]

  v27 = -2i64;
  v4 = v;
  v5 = penv;
  v6 = result;
  v7 = (signed int)result;
  if ( (_DWORD)result )
  {
    Scaleform::GFx::AS2::Value::ToPrimitive(this, &resulta, penv, 0);
    Scaleform::GFx::AS2::Value::ToPrimitive(v4, &v28, v5, 0);
    if ( resulta.T.Type != 5 || v28.T.Type != 5 )
    {
      if ( (v5->StringContext.SWFVersion <= 6u
         || resulta.T.Type && resulta.T.Type != 10 && v28.T.Type && v28.T.Type != 10)
        && ((v20 = Scaleform::GFx::AS2::Value::ToNumber(&resulta, v5), v7 >= 0) ? (v22 = v20,
                                                                                   v21 = Scaleform::GFx::AS2::Value::ToNumber(
                                                                                           &v28,
                                                                                           v5)) : (v21 = v20,
                                                                                                   v22 = Scaleform::GFx::AS2::Value::ToNumber(&v28, v5)),
            (v26.pNode = *(Scaleform::GFx::ASStringNode **)&v21,
             (*(_QWORD *)&v21 & 0x7FF0000000000000i64) != 9218868437227405312i64)
         || !(*(_QWORD *)&v21 & 0xFFFFFFFFFFFFFi64)) )
      {
        v26.pNode = *(Scaleform::GFx::ASStringNode **)&v22;
        if ( (*(_QWORD *)&v22 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v22 & 0xFFFFFFFFFFFFFi64 )
        {
          v6->T.Type = 0;
        }
        else
        {
          if ( v21 == v22 )
          {
            v23 = 0;
          }
          else if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v21) && Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v22) )
          {
            v23 = 0;
          }
          else if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v22) && Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v21) )
          {
            v23 = 0;
          }
          else
          {
            v26.pNode = *(Scaleform::GFx::ASStringNode **)&v21;
            if ( v21 == 1.797693134862316e308/*+Inf*/ )
            {
              v23 = 0;
            }
            else
            {
              v26.pNode = *(Scaleform::GFx::ASStringNode **)&v22;
              if ( v22 == 1.797693134862316e308/*+Inf*/ )
              {
                v23 = 1;
              }
              else
              {
                v26.pNode = *(Scaleform::GFx::ASStringNode **)&v22;
                if ( v22 == -1.797693134862316e308/*-Inf*/ )
                {
                  v23 = 0;
                }
                else
                {
                  v26.pNode = *(Scaleform::GFx::ASStringNode **)&v21;
                  if ( v21 == -1.797693134862316e308/*-Inf*/ )
                    v23 = 1;
                  else
                    v23 = v22 > v21;
                }
              }
            }
          }
          v6->T.Type = 2;
          v6->V.BooleanValue = v23;
        }
      }
      else
      {
        v6->T.Type = 0;
      }
    }
    else if ( v7 >= 0 )
    {
      v15 = Scaleform::GFx::AS2::Value::ToString(&v28, &v25, v5, -1);
      v16 = Scaleform::GFx::AS2::Value::ToString(&resulta, &v26, v5, -1);
      if ( v16->pNode == v15->pNode )
        v17 = 0;
      else
        v17 = Scaleform::GFx::ASString::operator<(v16, v15) == 0;
      v6->T.Type = 2;
      v6->V.BooleanValue = v17;
      v18 = v26.pNode;
      v13 = v26.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v19 = v25.pNode;
      v13 = v25.pNode->RefCount == 1;
      --v19->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    }
    else
    {
      v9 = Scaleform::GFx::AS2::Value::ToString(&v28, &v26, v5, -1);
      v10 = Scaleform::GFx::AS2::Value::ToString(&resulta, &v25, v5, -1);
      v11 = Scaleform::GFx::ASString::operator<(v10, v9);
      v6->T.Type = 2;
      v6->V.BooleanValue = v11;
      v12 = v25.pNode;
      v13 = v25.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v14 = v26.pNode;
      v13 = v26.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
    if ( resulta.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&resulta);
  }
  else
  {
    v8 = Scaleform::GFx::AS2::Value::IsEqual(this, penv, v);
    v6->T.Type = 2;
    v6->V.BooleanValue = v8;
  }
  return v6;
}

// File Line: 1206
// RVA: 0x720B30
void __fastcall Scaleform::GFx::AS2::Value::StringConcat(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString v10; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+20h]

  v3 = str;
  v4 = this;
  v5 = Scaleform::GFx::AS2::Value::ToString(this, &result, penv, -1);
  Scaleform::GFx::ASString::operator+(v5, &v10, v3);
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->T.Type = 5;
  v8 = v10.pNode;
  v4->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10.pNode;
  ++v8->RefCount;
  v9 = v10.pNode;
  v7 = v10.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 1263
// RVA: 0x6E2CE0
void __fastcall Scaleform::GFx::AS2::Value::DropRefs(Scaleform::GFx::AS2::Value *this)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax

  v1 = this;
  switch ( this->T.Type )
  {
    case 5:
    case 0xB:
      v2 = this->V.pStringNode;
      v3 = v2->RefCount-- == 1;
      if ( v3 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v2);
      break;
    case 6:
    case 9:
      v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->V.pStringNode;
      if ( v9 )
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
        goto LABEL_19;
      }
      break;
    case 7:
      v8 = this->V.pStringNode;
      if ( v8 )
      {
        if ( --LODWORD(v8->pData) > 0 )
        {
LABEL_19:
          v1->V.pStringNode = 0i64;
        }
        else
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)v8);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
          v1->V.pStringNode = 0i64;
        }
      }
      break;
    case 8:
    case 0xC:
      v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->V.pStringNode;
      if ( v4 )
      {
        if ( !(v1->V.FunctionValue.Flags & 2) )
        {
          v5 = v4->RefCount;
          if ( v5 & 0x3FFFFFF )
          {
            v4->RefCount = v5 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
        v3 = (v1->V.FunctionValue.Flags & 1) == 0;
        v1->V.pStringNode = 0i64;
        if ( v3 )
        {
          v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->V.FunctionValue.pLocalFrame->vfptr;
          if ( v6 )
          {
            v7 = v6->RefCount;
            if ( v7 & 0x3FFFFFF )
            {
              v6->RefCount = v7 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
            }
          }
        }
        v1->V.FunctionValue.pLocalFrame = 0i64;
      }
      break;
    default:
      return;
  }
}

// File Line: 1311
// RVA: 0x721C60
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Value::ToPrimitive(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Value *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value::Hint __formal)
{
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rsi
  char v7; // cl
  Scaleform::GFx::AS2::FunctionObject *v8; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v9; // rcx
  char v10; // al
  Scaleform::GFx::AS2::FunctionObject *v11; // rcx
  unsigned int v12; // edx
  Scaleform::GFx::AS2::LocalFrame *v13; // rcx
  unsigned int v14; // eax
  char v15; // al
  Scaleform::GFx::AS2::FunctionObject *v16; // rcx
  unsigned int v17; // edx
  Scaleform::GFx::AS2::LocalFrame *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS2::ObjectInterfaceVtbl **v20; // rax
  Scaleform::GFx::AS2::ObjectInterface *v21; // r14
  unsigned __int16 v22; // cx
  char v23; // al
  Scaleform::GFx::AS2::FunctionObject *v24; // rcx
  unsigned int v25; // edx
  Scaleform::GFx::AS2::LocalFrame *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Value *v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  const char *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  bool v32; // zf
  Scaleform::GFx::AS2::FunctionRef resulta; // [rsp+28h] [rbp-81h]
  Scaleform::GFx::AS2::Value v35; // [rsp+48h] [rbp-61h]
  Scaleform::GFx::AS2::FnCall v36; // [rsp+70h] [rbp-39h]
  Scaleform::GFx::AS2::Value v; // [rsp+B0h] [rbp+7h]
  __int64 v38; // [rsp+D0h] [rbp+27h]
  Scaleform::GFx::ASString v39; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::AS2::Value *v40; // [rsp+118h] [rbp+6Fh]

  v40 = result;
  v38 = -2i64;
  v4 = penv;
  v5 = result;
  v6 = this;
  v7 = this->T.Type;
  if ( (unsigned __int8)(v7 - 6) > 2u )
  {
    if ( v7 == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(v6, &resulta, penv);
      v8 = resulta.Function;
      if ( resulta.Function )
      {
        v5->T.Type = 8;
        v9 = (Scaleform::GFx::AS2::FunctionRefBase *)&v5->NV.8;
        v9->Flags = 0;
        v9->Function = v8;
        ++v8->RefCount;
        v8->RefCount &= 0x8FFFFFFF;
        v9->pLocalFrame = 0i64;
        if ( resulta.pLocalFrame )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v9, resulta.pLocalFrame, resulta.Flags & 1);
        v10 = resulta.Flags;
        if ( !(resulta.Flags & 2) )
        {
          v11 = resulta.Function;
          if ( resulta.Function )
          {
            v12 = resulta.Function->RefCount;
            if ( v12 & 0x3FFFFFF )
            {
              resulta.Function->RefCount = v12 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
              v10 = resulta.Flags;
            }
          }
        }
        resulta.Function = 0i64;
        if ( !(v10 & 1) )
        {
          v13 = resulta.pLocalFrame;
          if ( resulta.pLocalFrame )
          {
            v14 = resulta.pLocalFrame->RefCount;
            if ( v14 & 0x3FFFFFF )
            {
              resulta.pLocalFrame->RefCount = v14 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
            }
          }
        }
        resulta.pLocalFrame = 0i64;
        return v5;
      }
      v15 = resulta.Flags;
      if ( !(resulta.Flags & 2) )
      {
        v16 = resulta.Function;
        if ( resulta.Function )
        {
          v17 = resulta.Function->RefCount;
          if ( v17 & 0x3FFFFFF )
          {
            resulta.Function->RefCount = v17 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
            v15 = resulta.Flags;
          }
        }
      }
      resulta.Function = 0i64;
      if ( !(v15 & 1) )
      {
        v18 = resulta.pLocalFrame;
        if ( resulta.pLocalFrame )
        {
          v19 = resulta.pLocalFrame->RefCount;
          if ( v19 & 0x3FFFFFF )
          {
            resulta.pLocalFrame->RefCount = v19 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v18->vfptr);
          }
        }
      }
      resulta.pLocalFrame = 0i64;
    }
    Scaleform::GFx::AS2::Value::Value(v5, v6, (__int64)v5);
    return v5;
  }
  v35.T.Type = 0;
  v20 = Scaleform::GFx::AS2::Value::ToObjectInterface(v6, penv);
  v21 = (Scaleform::GFx::AS2::ObjectInterface *)v20;
  if ( v4
    && v20
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, _DWORD))(*v20)->GetMemberRaw)(
         v20,
         &v4->StringContext,
         &v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].RefCount,
         &v35,
         0) )
  {
    v.T.Type = 0;
    v22 = v4->FuncCallNestingLevel;
    v4->FuncCallNestingLevel = v22 + 1;
    if ( v22 < 0xFFu )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v35, &resulta, v4);
      if ( resulta.Function )
      {
        v36.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
        v36.Result = &v;
        v36.ThisPtr = v21;
        v36.ThisFunctionRef.Flags = 0;
        v36.ThisFunctionRef.Function = 0i64;
        v36.ThisFunctionRef.pLocalFrame = 0i64;
        v36.Env = v4;
        *(_QWORD *)&v36.NArgs = 0i64;
        ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))resulta.Function->vfptr[3].Finalize_GC)(
          resulta.Function,
          &v36,
          resulta.pLocalFrame,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v36);
      }
      v23 = resulta.Flags;
      if ( !(resulta.Flags & 2) )
      {
        v24 = resulta.Function;
        if ( resulta.Function )
        {
          v25 = resulta.Function->RefCount;
          if ( v25 & 0x3FFFFFF )
          {
            resulta.Function->RefCount = v25 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v24->vfptr);
            v23 = resulta.Flags;
          }
        }
      }
      resulta.Function = 0i64;
      if ( !(v23 & 1) )
      {
        v26 = resulta.pLocalFrame;
        if ( resulta.pLocalFrame )
        {
          v27 = resulta.pLocalFrame->RefCount;
          if ( v27 & 0x3FFFFFF )
          {
            resulta.pLocalFrame->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v26->vfptr);
          }
        }
      }
      resulta.pLocalFrame = 0i64;
    }
    --v4->FuncCallNestingLevel;
    Scaleform::GFx::AS2::Value::Value(v5, &v, (__int64)v5);
    if ( v.T.Type < 5u )
      goto LABEL_55;
    v28 = &v;
  }
  else
  {
    LOBYTE(resulta.Function) = 0;
    if ( v6->T.Type == 7 && v6->V.pStringNode )
    {
      LOBYTE(resulta.Function) = 5;
      resulta.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::AS2::Value::GetCharacterNamePath(v6, v4)->pNode;
      ++resulta.pLocalFrame->RefCount;
    }
    else
    {
      if ( v6->T.Type == 6
        && (v29 = v6->V.pStringNode) != 0i64
        && (v30 = (const char *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::Environment *))(*(_QWORD *)&v29->Size + 8i64))(
                                  &v29->Size,
                                  v4)) != 0i64 )
      {
        LOBYTE(resulta.Function) = 5;
        resulta.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::AS2::Environment::CreateString(
                                                                   v4,
                                                                   &v39,
                                                                   v30)->pNode;
        ++resulta.pLocalFrame->RefCount;
      }
      else
      {
        LOBYTE(resulta.Function) = 5;
        resulta.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::AS2::Value::ToString(v6, &v39, v4, -1)->pNode;
        ++resulta.pLocalFrame->RefCount;
      }
      v31 = v39.pNode;
      v32 = v39.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v32 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    }
    Scaleform::GFx::AS2::Value::Value(v5, (Scaleform::GFx::AS2::Value *)&resulta, (__int64)v5);
    if ( LOBYTE(resulta.Function) < 5u )
      goto LABEL_55;
    v28 = (Scaleform::GFx::AS2::Value *)&resulta;
  }
  Scaleform::GFx::AS2::Value::DropRefs(v28);
LABEL_55:
  if ( v35.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v35);
  return v5;
}

// File Line: 1385
// RVA: 0x6F4E50
char __fastcall Scaleform::GFx::AS2::Value::GetPropertyValue(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Value *value)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-70h]
  Scaleform::GFx::AS2::FnCall v8; // [rsp+48h] [rbp-50h]

  v4 = value;
  v5 = penv;
  if ( this->T.Type != 9 || !penv )
    return 0;
  if ( !*(_QWORD *)&this->V.pStringNode->Size )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *))penv->vfptr->IsVerboseActionErrors)(
           penv,
           penv,
           pthis) )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(v5, "Getter method is null.");
    }
    return 0;
  }
  v.T.Type = 0;
  v8.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  v8.Result = &v;
  v8.ThisPtr = pthis;
  v8.ThisFunctionRef.Flags = 0;
  v8.ThisFunctionRef.Function = 0i64;
  v8.ThisFunctionRef.pLocalFrame = 0i64;
  v8.Env = penv;
  *(_QWORD *)&v8.NArgs = 0i64;
  (*(void (__fastcall **)(_QWORD, Scaleform::GFx::AS2::FnCall *, const char *, _QWORD, signed __int64))(**(_QWORD **)&this->V.pStringNode->Size + 80i64))(
    *(_QWORD *)&this->V.pStringNode->Size,
    &v8,
    this->V.pStringNode[1].pData,
    0i64,
    -2i64);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v8);
  Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v4);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 1405
// RVA: 0x71AE70
void __fastcall Scaleform::GFx::AS2::Value::SetPropertyValue(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rsi
  Scaleform::GFx::AS2::Value *v8; // rcx
  int v9; // edx
  Scaleform::GFx::AS2::Value *v10; // rcx
  Scaleform::GFx::AS2::Value *v11; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::AS2::Value v12; // [rsp+30h] [rbp-78h]
  Scaleform::GFx::AS2::FnCall v13; // [rsp+50h] [rbp-58h]

  v4 = val;
  v5 = pthis;
  v6 = penv;
  v7 = this;
  if ( this->T.Type == 9 && penv )
  {
    if ( this->V.pStringNode[1].pLower )
    {
      v12.T.Type = 0;
      ++penv->Stack.pCurrent;
      if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v8 = v6->Stack.pCurrent;
      v11 = v6->Stack.pCurrent;
      if ( v8 )
        Scaleform::GFx::AS2::Value::Value(v8, v4, (__int64)v6);
      v9 = ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5)
         + 32 * v6->Stack.Pages.Data.Size
         - 32;
      v13.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      v13.Result = &v12;
      v13.ThisPtr = v5;
      v13.ThisFunctionRef.Flags = 0;
      v13.ThisFunctionRef.Function = 0i64;
      v13.ThisFunctionRef.pLocalFrame = 0i64;
      v13.Env = v6;
      v13.NArgs = 1;
      v13.FirstArgBottomIndex = v9;
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::FnCall *, _QWORD, _QWORD, signed __int64, Scaleform::GFx::AS2::Value *))v7->V.pStringNode[1].pLower->pData
       + 10))(
        v7->V.pStringNode[1].pLower,
        &v13,
        *(_QWORD *)&v7->V.pStringNode[1].RefCount,
        0i64,
        -2i64,
        v11);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v13);
      v10 = v6->Stack.pCurrent;
      if ( v10->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v10);
      --v6->Stack.pCurrent;
      if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
      if ( v12.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v12);
    }
    else if ( penv->vfptr->IsVerboseActionErrors((Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)penv) )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(v6, "Setter method is null.");
    }
  }
}

// File Line: 1425
// RVA: 0x6EEDC0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::GetCharacterNamePath(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rcx
  Scaleform::GFx::AS2::Environment *v4; // rdi
  Scaleform::GFx::ASString *result; // rax

  v2 = this;
  v3 = this->V.pStringNode;
  v4 = penv;
  if ( v3
    && Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)v3,
         penv->Target->pASRoot->pMovieImpl) )
  {
    result = (Scaleform::GFx::ASString *)&v2->V.pStringNode->RefCount;
  }
  else
  {
    result = (Scaleform::GFx::ASString *)&v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  }
  return result;
}

// File Line: 1434
// RVA: 0x712120
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ResolveFunctionName(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::AS2::FunctionRef *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rdi
  bool v8; // zf
  Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *v9; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rdx
  int v11; // eax
  Scaleform::GFx::AS2::FunctionRef *v12; // rax
  Scaleform::GFx::ASString functionName; // [rsp+80h] [rbp+18h]

  v3 = penv;
  v4 = result;
  v5 = this;
  if ( penv && this->T.Type == 11 )
  {
    v6 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    functionName.pNode = v6;
    ++v6->RefCount;
    v7 = v5->V.pStringNode;
    ++v7->RefCount;
    v8 = v6->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    functionName.pNode = v7;
    v9 = Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(v3->StringContext.pContext, &functionName);
    v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
    if ( v9 )
      LODWORD(v9[1].ResolvedFunc.pObject) = (LODWORD(v9[1].ResolvedFunc.pObject) + 1) & 0x8FFFFFFF;
    v4->Flags = 0;
    v4->Function = (Scaleform::GFx::AS2::FunctionObject *)v9;
    if ( v9 )
      LODWORD(v9[1].ResolvedFunc.pObject) = (LODWORD(v9[1].ResolvedFunc.pObject) + 1) & 0x8FFFFFFF;
    v4->pLocalFrame = 0i64;
    if ( v9 )
    {
      v11 = (int)v9[1].ResolvedFunc.pObject;
      if ( v11 & 0x3FFFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    v12 = v4;
  }
  else
  {
    result->Flags = 0;
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
    v12 = result;
  }
  return v12;
}

// File Line: 1447
// RVA: 0x6E2560
void __fastcall Scaleform::GFx::AS2::Value::Div(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rsi
  double v6; // xmm6_8
  double v7; // xmm0_8
  double v8; // xmm6_8

  v3 = v;
  v4 = penv;
  v5 = this;
  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v3, v4);
  if ( (*(_QWORD *)&v6 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v6 & 0xFFFFFFFFFFFFFi64
    || (*(_QWORD *)&v7 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v7 & 0xFFFFFFFFFFFFFi64 )
  {
    v8 = Scaleform::GFx::NumberUtil::NaN();
  }
  else if ( v7 == 0.0 )
  {
    if ( v6 == 0.0 )
    {
      v8 = Scaleform::GFx::NumberUtil::NaN();
    }
    else if ( v6 < 0.0 )
    {
      v8 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
    }
    else
    {
      v8 = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
    }
  }
  else
  {
    v8 = v6 / v7;
  }
  if ( v5->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v5);
  v5->NV.NumberValue = v8;
  v5->T.Type = 3;
}

// File Line: 1473
// RVA: 0x6CD8D0
void __fastcall Scaleform::GFx::AS2::ValueGuard::ValueGuard(Scaleform::GFx::AS2::ValueGuard *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::ValueGuard *v4; // rbx
  Scaleform::GFx::CharacterHandle *v5; // rcx
  Scaleform::GFx::DisplayObject *v6; // rax
  Scaleform::GFx::InteractiveObject *v7; // rcx

  v3 = val;
  v4 = this;
  this->pEnv = penv;
  Scaleform::GFx::AS2::Value::Value(&this->mValue, val, (__int64)val);
  if ( v3->T.Type == 7 )
  {
    if ( v4->pEnv
      && (v5 = v3->V.pCharHandle) != 0i64
      && (v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v5, v4->pEnv->Target->pASRoot->pMovieImpl)) != 0i64 )
    {
      v7 = 0i64;
      if ( SLOBYTE(v6->Flags) < 0 )
        v7 = (Scaleform::GFx::InteractiveObject *)v6;
    }
    else
    {
      v7 = 0i64;
    }
    v4->pChar = v7;
    if ( v7 )
      ++v7->RefCount;
  }
  else
  {
    v4->pChar = 0i64;
  }
}

// File Line: 1486
// RVA: 0x6D28A0
void __fastcall Scaleform::GFx::AS2::ValueGuard::~ValueGuard(Scaleform::GFx::AS2::ValueGuard *this)
{
  Scaleform::GFx::AS2::ValueGuard *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v1 = this;
  v2 = this->pChar;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
  if ( v1->mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v1->mValue);
}

// File Line: 1510
// RVA: 0x6DA880
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::FnCall::Arg(Scaleform::GFx::AS2::FnCall *this, int n)
{
  Scaleform::GFx::AS2::Environment *v2; // r8
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Value *result; // rax

  v2 = this->Env;
  v3 = this->FirstArgBottomIndex - n;
  if ( v3 > 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
          + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
    result = 0i64;
  else
    result = &v2->Stack.Pages.Data.Data[(unsigned __int64)v3 >> 5]->Values[v3 & 0x1F];
  return result;
}

// File Line: 1527
// RVA: 0x7010E0
__int64 __fastcall Scaleform::GFx::AS2::FnCall::IsVerboseActionErrors(Scaleform::GFx::AS2::FnCall *this)
{
  return ((__int64 (*)(void))this->Env->vfptr->IsVerboseActionErrors)();
}

