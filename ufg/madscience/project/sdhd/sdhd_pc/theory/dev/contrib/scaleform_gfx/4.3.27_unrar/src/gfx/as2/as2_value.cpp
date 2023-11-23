// File Line: 40
// RVA: 0x720FB0
bool __fastcall Scaleform::GFx::AS2::StringToNumber(long double *result, char *str)
{
  __int64 v4; // rbx
  int v5; // ecx
  double v6; // xmm0_8
  const char *v7; // rsi
  int v8; // ebp
  char *v9; // rax
  char *endptr; // [rsp+48h] [rbp+10h] BYREF

  endptr = 0i64;
  v4 = -1i64;
  do
    ++v4;
  while ( str[v4] );
  if ( *str != 48 )
    goto LABEL_8;
  v5 = str[1];
  if ( (unsigned int)(v5 - 65) <= 0x19 )
    v5 += 32;
  if ( v5 != 120 )
  {
LABEL_8:
    if ( strcspn(str, ".Ee") != v4 )
    {
      v6 = Scaleform::SFstrtod(str, &endptr);
      goto LABEL_18;
    }
    v7 = str;
    v8 = 1;
    if ( *str == 45 )
    {
      v8 = -1;
    }
    else if ( *str != 43 )
    {
LABEL_14:
      if ( *v7 == 48 && strspn(v7, "01234567") == v4 )
        v6 = (double)(int)(v8 * strtoul(v7, &endptr, 8));
      else
        v6 = Scaleform::SFstrtod(v7, &endptr) * (double)v8;
      goto LABEL_18;
    }
    --v4;
    v7 = str + 1;
    goto LABEL_14;
  }
  v6 = (double)(int)strtoul(str, &endptr, 0);
LABEL_18:
  v9 = endptr;
  *result = v6;
  return v9 != str && !*v9;
}

// File Line: 126
// RVA: 0x6CD530
void __fastcall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Value *v)
{
  __int64 v2; // rdi
  Scaleform::GFx::ASStringNode *pStringNode; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  __int64 v7; // rax
  Scaleform::GFx::ASStringNode *v8; // r8
  Scaleform::GFx::AS2::LocalFrame *v9; // rdx
  char v10; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rax
  $05405293094FBBD0121C32E32235DD0F *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+30h] [rbp-18h]
  char v22; // [rsp+38h] [rbp-10h]
  __int64 v23; // [rsp+40h] [rbp-8h]

  v23 = v2;
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
      pStringNode = v->V.pStringNode;
      this->V.pStringNode = pStringNode;
      ++pStringNode->RefCount;
      break;
    case 6:
      v6 = v->V.pStringNode;
      if ( v6 )
      {
        if ( (*(unsigned int (__fastcall **)(unsigned int *))(*(_QWORD *)&v6->Size + 16i64))(&v6->Size) != 23 )
        {
          v15 = v->V.pStringNode;
          goto LABEL_30;
        }
        this->T.Type = 8;
        v7 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&v->V.pStringNode->Size + 96i64))(
               &v->V.pStringNode->Size,
               &v20);
        this->V.FunctionValue.Flags = 0;
        v8 = *(Scaleform::GFx::ASStringNode **)v7;
        this->V.pStringNode = *(Scaleform::GFx::ASStringNode **)v7;
        if ( v8 )
          v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
        this->V.FunctionValue.pLocalFrame = 0i64;
        v9 = *(Scaleform::GFx::AS2::LocalFrame **)(v7 + 8);
        if ( v9 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, v9, *(_BYTE *)(v7 + 16) & 1);
        v10 = v22;
        if ( (v22 & 2) == 0 )
        {
          v11 = v20;
          if ( v20 )
          {
            RefCount = v20->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v20->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
              v10 = v22;
            }
          }
        }
        v20 = 0i64;
        if ( (v10 & 1) == 0 )
        {
          v13 = v21;
          if ( v21 )
          {
            v14 = v21->RefCount;
            if ( (v14 & 0x3FFFFFF) != 0 )
            {
              v21->RefCount = v14 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
            }
          }
        }
        v21 = 0i64;
      }
      else
      {
        this->V.pStringNode = 0i64;
      }
      break;
    case 7:
      v16 = v->V.pStringNode;
      this->V.pStringNode = v16;
      if ( v16 )
        ++LODWORD(v16->pData);
      break;
    case 8:
    case 0xC:
      v17 = &this->V.8;
      this->V.FunctionValue.Flags = 0;
      v18 = v->V.pStringNode;
      this->V.pStringNode = v18;
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      this->V.FunctionValue.pLocalFrame = 0i64;
      pLocalFrame = v->V.FunctionValue.pLocalFrame;
      if ( pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          (Scaleform::GFx::AS2::FunctionRefBase *)v17,
          pLocalFrame,
          v->V.FunctionValue.Flags & 1);
      break;
    case 9:
      v15 = v->V.pStringNode;
LABEL_30:
      this->V.pStringNode = v15;
      v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}

// File Line: 191
// RVA: 0x6D3710
void __fastcall Scaleform::GFx::AS2::Value::operator=(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Value *v)
{
  __int64 v2; // rdi
  Scaleform::GFx::ASStringNode *pStringNode; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  __int64 v7; // rax
  Scaleform::GFx::ASStringNode *v8; // r8
  Scaleform::GFx::AS2::LocalFrame *v9; // rdx
  char v10; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // [rsp+30h] [rbp-18h]
  char v21; // [rsp+38h] [rbp-10h]
  __int64 v22; // [rsp+40h] [rbp-8h]

  v22 = v2;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
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
      pStringNode = v->V.pStringNode;
      this->V.pStringNode = pStringNode;
      ++pStringNode->RefCount;
      break;
    case 6:
      v6 = v->V.pStringNode;
      if ( v6 )
      {
        if ( (*(unsigned int (__fastcall **)(unsigned int *, unsigned __int64))(*(_QWORD *)&v6->Size + 16i64))(
               &v6->Size,
               0x140000000ui64) != 23 )
          goto $LN1_32;
        this->T.Type = 8;
        v7 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&v->V.pStringNode->Size + 96i64))(
               &v->V.pStringNode->Size,
               &v19);
        this->V.FunctionValue.Flags = 0;
        v8 = *(Scaleform::GFx::ASStringNode **)v7;
        this->V.pStringNode = *(Scaleform::GFx::ASStringNode **)v7;
        if ( v8 )
          v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
        this->V.FunctionValue.pLocalFrame = 0i64;
        v9 = *(Scaleform::GFx::AS2::LocalFrame **)(v7 + 8);
        if ( v9 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, v9, *(_BYTE *)(v7 + 16) & 1);
        v10 = v21;
        if ( (v21 & 2) == 0 )
        {
          v11 = v19;
          if ( v19 )
          {
            RefCount = v19->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v19->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
              v10 = v21;
            }
          }
        }
        v19 = 0i64;
        if ( (v10 & 1) == 0 )
        {
          v13 = v20;
          if ( v20 )
          {
            v14 = v20->RefCount;
            if ( (v14 & 0x3FFFFFF) != 0 )
            {
              v20->RefCount = v14 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
            }
          }
        }
        v20 = 0i64;
      }
      else
      {
        this->V.pStringNode = 0i64;
      }
      break;
    case 7:
      v15 = v->V.pStringNode;
      this->V.pStringNode = v15;
      if ( v15 )
        ++LODWORD(v15->pData);
      break;
    case 8:
    case 0xC:
      this->V.FunctionValue.Flags = 0;
      v16 = v->V.pStringNode;
      this->V.pStringNode = v16;
      if ( v16 )
        v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
      this->V.FunctionValue.pLocalFrame = 0i64;
      pLocalFrame = v->V.FunctionValue.pLocalFrame;
      if ( pLocalFrame )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
          &this->V.FunctionValue,
          pLocalFrame,
          v->V.FunctionValue.Flags & 1);
      break;
    case 9:
$LN1_32:
      v18 = v->V.pStringNode;
      this->V.pStringNode = v18;
      v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      break;
    default:
      return;
  }
}

// File Line: 262
// RVA: 0x6CD7A0
void __fastcall Scaleform::GFx::AS2::Value::Value(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASStringNode *pobj)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rax
  Scaleform::GFx::ASStringNode *Function; // r8
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  char v7; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // [rsp+30h] [rbp-18h]
  char v14; // [rsp+38h] [rbp-10h]

  if ( pobj && (*(unsigned int (__fastcall **)(unsigned int *))(*(_QWORD *)&pobj->Size + 16i64))(&pobj->Size) == 23 )
  {
    this->T.Type = 8;
    v4 = (Scaleform::GFx::AS2::FunctionRef *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&pobj->Size + 96i64))(
                                               &pobj->Size,
                                               &v12);
    this->V.FunctionValue.Flags = 0;
    Function = (Scaleform::GFx::ASStringNode *)v4->Function;
    this->V.pStringNode = (Scaleform::GFx::ASStringNode *)v4->Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    this->V.FunctionValue.pLocalFrame = 0i64;
    pLocalFrame = v4->pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, pLocalFrame, v4->Flags & 1);
    v7 = v14;
    if ( (v14 & 2) == 0 )
    {
      v8 = v12;
      if ( v12 )
      {
        RefCount = v12->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v12->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
          v7 = v14;
        }
      }
    }
    v12 = 0i64;
    if ( (v7 & 1) == 0 )
    {
      v10 = v13;
      if ( v13 )
      {
        v11 = v13->RefCount;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          v13->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
        }
      }
    }
    v13 = 0i64;
  }
  else
  {
    this->T.Type = 6;
    this->V.pStringNode = pobj;
    if ( pobj )
      pobj->RefCount = (pobj->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 294
// RVA: 0x6CD740
void __fastcall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *func)
{
  $05405293094FBBD0121C32E32235DD0F *v2; // rcx
  Scaleform::GFx::AS2::FunctionObject *Function; // r8

  this->T.Type = 8;
  v2 = &this->V.8;
  v2->FunctionValue.Flags = 0;
  Function = func->Function;
  v2->pStringNode = (Scaleform::GFx::ASStringNode *)func->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  v2->FunctionValue.pLocalFrame = 0i64;
  if ( func->pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)v2,
      func->pLocalFrame,
      func->Flags & 1);
}

// File Line: 309
// RVA: 0x6D2890
void __fastcall Scaleform::GFx::AS2::Value::~Value(Scaleform::GFx::AS2::Value *this)
{
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
}

// File Line: 317
// RVA: 0x6BF120
void __fastcall Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  char Type; // al
  Scaleform::GFx::ASStringNode *pStringNode; // rdx

  Type = this->T.Type;
  if ( this->T.Type == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
      &this->V.FunctionValue,
      prcc);
    return;
  }
  if ( Type != 6 || (pStringNode = this->V.pStringNode) == 0i64 )
  {
    if ( Type != 9 )
      return;
    pStringNode = this->V.pStringNode;
  }
  if ( (--pStringNode->RefCount & 0x8000000) == 0 )
  {
    pStringNode->pLower = *(Scaleform::GFx::ASStringNode **)prcc->pLastPtr->pRCC->Roots.gap0;
    pStringNode->pManager = (Scaleform::GFx::ASStringManager *)prcc->pLastPtr->pRCC;
    *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = pStringNode;
    prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pStringNode;
    prcc->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode;
    pStringNode->RefCount |= 0x8000000u;
  }
}

// File Line: 339
// RVA: 0x7221F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToStringImpl(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        int precision,
        bool debug)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  Scaleform::GFx::ASStringNode *v9; // r10
  Scaleform::GFx::ASStringNode *vfptr; // rdi
  int v11; // r9d
  const char *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  const char *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::AS2::ObjectInterface *v18; // rax
  Scaleform::GFx::AS2::ObjectInterface *v19; // r15
  unsigned __int16 FuncCallNestingLevel; // cx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  const char *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *CharacterNamePath; // rdx
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASString *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::AS2::FunctionRef v39; // [rsp+28h] [rbp-A9h] BYREF
  Scaleform::GFx::ASString v40; // [rsp+40h] [rbp-91h] BYREF
  Scaleform::GFx::ASString v41; // [rsp+48h] [rbp-89h] BYREF
  Scaleform::GFx::ASString v42; // [rsp+50h] [rbp-81h] BYREF
  Scaleform::GFx::ASString v43; // [rsp+58h] [rbp-79h] BYREF
  Scaleform::GFx::AS2::FnCall destStr; // [rsp+60h] [rbp-71h] BYREF
  Scaleform::GFx::AS2::Value v45; // [rsp+A0h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v46; // [rsp+C0h] [rbp-11h] BYREF
  __int64 v47; // [rsp+E0h] [rbp+Fh]
  Scaleform::GFx::ASString resulta; // [rsp+130h] [rbp+5Fh] BYREF
  Scaleform::GFx::ASString *v49; // [rsp+138h] [rbp+67h]
  Scaleform::GFx::ASString v50; // [rsp+140h] [rbp+6Fh] BYREF

  v49 = result;
  v47 = -2i64;
  p_StringContext = &penv->StringContext;
  v9 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  result->pNode = v9;
  ++v9->RefCount;
  switch ( this->T.Type )
  {
    case 0:
    case 0xA:
      vfptr = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[18].vfptr;
      goto LABEL_51;
    case 1:
      Scaleform::GFx::ASString::operator=(
        result,
        (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[18].RefCount);
      return result;
    case 2:
      Scaleform::GFx::ASString::operator=(
        result,
        (Scaleform::GFx::ASString *)&(&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject->vfptr)[93i64 - this->V.BooleanValue]);
      return result;
    case 3:
      if ( precision >= 0 )
        v11 = -precision;
      else
        v11 = 10;
      v12 = Scaleform::GFx::NumberUtil::ToString(this->NV.NumberValue, (char *)&destStr, 0x40ui64, v11);
      v13 = Scaleform::GFx::AS2::Environment::CreateString(penv, &resulta, v12);
      Scaleform::GFx::ASString::operator=(result, v13);
      pNode = resulta.pNode;
      v15 = resulta.pNode->RefCount-- == 1;
      if ( v15 )
        goto LABEL_7;
      return result;
    case 4:
      v16 = Scaleform::GFx::NumberUtil::IntToString(this->NV.Int32Value, (char *)&destStr, 0x40ui64);
      v17 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v50, v16);
      Scaleform::GFx::ASString::operator=(result, v17);
      pNode = v50.pNode;
      v15 = v50.pNode->RefCount-- == 1;
      if ( v15 )
LABEL_7:
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return result;
    case 5:
      vfptr = this->V.pStringNode;
      goto LABEL_51;
    case 6:
    case 7:
      v46.T.Type = 0;
      v18 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
      v19 = v18;
      if ( !debug
        && v18
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, int))v18->vfptr->GetMemberRaw)(
             v18,
             p_StringContext,
             &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[25],
             &v46,
             1) )
      {
        FuncCallNestingLevel = penv->FuncCallNestingLevel;
        penv->FuncCallNestingLevel = FuncCallNestingLevel + 1;
        if ( FuncCallNestingLevel >= 0xFFu )
        {
          Scaleform::GFx::ASString::operator=(
            result,
            (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24].pASSupport);
        }
        else
        {
          v45.T.Type = 0;
          Scaleform::GFx::AS2::Value::ToFunction(&v46, &v39, penv);
          if ( v39.Function )
          {
            destStr.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
            destStr.Result = &v45;
            destStr.ThisPtr = v19;
            memset(&destStr.ThisFunctionRef, 0, 17);
            destStr.Env = penv;
            *(_QWORD *)&destStr.NArgs = 0i64;
            ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))v39.Function->vfptr[3].Finalize_GC)(
              v39.Function,
              &destStr,
              v39.pLocalFrame,
              0i64);
            Scaleform::GFx::AS2::FnCall::~FnCall(&destStr);
          }
          v21 = Scaleform::GFx::AS2::Value::ToString(&v45, &v43, penv, -1);
          Scaleform::GFx::ASString::operator=(result, v21);
          v22 = v43.pNode;
          v15 = v43.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          Flags = v39.Flags;
          if ( (v39.Flags & 2) == 0 )
          {
            Function = v39.Function;
            if ( v39.Function )
            {
              RefCount = v39.Function->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v39.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                Flags = v39.Flags;
              }
            }
          }
          v39.Function = 0i64;
          if ( (Flags & 1) == 0 )
          {
            pLocalFrame = v39.pLocalFrame;
            if ( v39.pLocalFrame )
            {
              v27 = v39.pLocalFrame->RefCount;
              if ( (v27 & 0x3FFFFFF) != 0 )
              {
                v39.pLocalFrame->RefCount = v27 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          v39.pLocalFrame = 0i64;
          if ( v45.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v45);
        }
        --penv->FuncCallNestingLevel;
      }
      else if ( this->T.Type == 6
             && (pStringNode = this->V.pStringNode) != 0i64
             && (v29 = (const char *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::Environment *))(*(_QWORD *)&pStringNode->Size + 8i64))(
                                       &pStringNode->Size,
                                       penv)) != 0i64 )
      {
        v30 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v41, v29);
        Scaleform::GFx::ASString::operator=(result, v30);
        v31 = v41.pNode;
        v15 = v41.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      }
      else
      {
        if ( this->T.Type == 7 && this->V.pStringNode )
          CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, penv);
        else
          CharacterNamePath = (Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24].AVMVersion;
        Scaleform::GFx::ASString::operator=(result, CharacterNamePath);
      }
      if ( v46.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v46);
      return result;
    case 8:
    case 0xB:
      vfptr = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl;
      goto LABEL_51;
    case 9:
      v33 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v42, "[property]");
      Scaleform::GFx::ASString::operator=(result, v33);
      v34 = v42.pNode;
      v15 = v42.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      return result;
    case 0xC:
      v35 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v40, "[resolveHandler]");
      Scaleform::GFx::ASString::operator=(result, v35);
      v36 = v40.pNode;
      v15 = v40.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      return result;
    default:
      vfptr = *(Scaleform::GFx::ASStringNode **)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[17].RefCount;
LABEL_51:
      ++vfptr->RefCount;
      v37 = result->pNode;
      v15 = result->pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      result->pNode = vfptr;
      return result;
  }
}

// File Line: 488
// RVA: 0x7214A0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToDebugString(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, 1);
  return result;
}

// File Line: 495
// RVA: 0x7226B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToStringVersioned(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int version)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rax
  Scaleform::GFx::ASStringNode *vfptr; // rcx

  if ( !this->T.Type || this->T.Type == 10 )
  {
    pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( version - 1 > 5 )
      vfptr = (Scaleform::GFx::ASStringNode *)pObject[18].vfptr;
    else
      vfptr = *(Scaleform::GFx::ASStringNode **)&pObject[7].AVMVersion;
    result->pNode = vfptr;
    ++vfptr->RefCount;
    return result;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, 0);
    return result;
  }
}

// File Line: 515
// RVA: 0x721750
long double __fastcall Scaleform::GFx::AS2::Value::ToNumber(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  char Type; // al
  bool v6; // cc
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  Scaleform::GFx::AS2::ObjectInterface *v8; // rsi
  unsigned __int16 FuncCallNestingLevel; // cx
  double v10; // xmm0_8
  double v11; // xmm6_8
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v16; // eax
  const char *v17; // rax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+18h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+30h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::FnCall v20; // [rsp+58h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value v21; // [rsp+98h] [rbp+17h] BYREF
  __int64 v22; // [rsp+B8h] [rbp+37h]
  double retaddr; // [rsp+E8h] [rbp+67h] BYREF

  v22 = -2i64;
  Type = this->T.Type;
  if ( this->T.Type == 3 )
    return this->NV.NumberValue;
  switch ( Type )
  {
    case 4:
      return (double)this->NV.Int32Value;
    case 5:
      if ( Scaleform::GFx::AS2::StringToNumber(&retaddr, (char *)this->V.pStringNode->pData) )
        return retaddr;
      return Scaleform::GFx::NumberUtil::NaN();
    case 1:
      v6 = penv->StringContext.SWFVersion <= 6u;
      goto LABEL_49;
    case 2:
      if ( this->V.BooleanValue )
        return DOUBLE_1_0;
      return 0.0;
    case 7:
      return Scaleform::GFx::NumberUtil::NaN();
  }
  if ( (Type != 6 || !this->V.pStringNode) && Type != 8 )
  {
    if ( Type && Type != 10 )
      return 0.0;
    v6 = (unsigned int)(unsigned __int8)penv->StringContext.SWFVersion - 1 <= 5;
LABEL_49:
    if ( !v6 )
      return Scaleform::GFx::NumberUtil::NaN();
    return 0.0;
  }
  v21.T.Type = 0;
  v7 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
  v8 = v7;
  if ( penv
    && v7->vfptr->GetMemberRaw(
         v7,
         &penv->StringContext,
         (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].RefCount,
         &v21) )
  {
    FuncCallNestingLevel = penv->FuncCallNestingLevel;
    penv->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel >= 0xFFu )
    {
      v11 = Scaleform::GFx::NumberUtil::NaN();
    }
    else
    {
      v19.T.Type = 0;
      Scaleform::GFx::AS2::Value::ToFunction(&v21, &result, penv);
      if ( result.Function )
      {
        v20.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
        v20.Result = &v19;
        v20.ThisPtr = v8;
        memset(&v20.ThisFunctionRef, 0, 17);
        v20.Env = penv;
        *(_QWORD *)&v20.NArgs = 0i64;
        ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))result.Function->vfptr[3].Finalize_GC)(
          result.Function,
          &v20,
          result.pLocalFrame,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v20);
      }
      if ( (unsigned __int8)(v19.T.Type - 1) > 4u )
        v10 = Scaleform::GFx::NumberUtil::NaN();
      else
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&v19, penv);
      v11 = v10;
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
          v16 = result.pLocalFrame->RefCount;
          if ( (v16 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      result.pLocalFrame = 0i64;
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    --penv->FuncCallNestingLevel;
  }
  else if ( this->T.Type == 7 )
  {
    v11 = Scaleform::GFx::NumberUtil::NaN();
  }
  else
  {
    v17 = (const char *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))v8->vfptr->gap8)(
                          v8,
                          penv);
    if ( v17 )
      v11 = atof(v17);
    else
      v11 = 0.0;
  }
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  return v11;
}

// File Line: 634
// RVA: 0x721610
__int64 __fastcall Scaleform::GFx::AS2::Value::ToInt32(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  __m128d v2; // xmm0
  __int64 result; // rax
  double v4; // xmm6_8
  __m128d v5; // xmm0
  int v6; // ecx

  if ( this->T.Type == 4 )
    return this->NV.UInt32Value;
  v2.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v4 = v2.m128d_f64[0];
  if ( (*(_QWORD *)&v2.m128d_f64[0] & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 || v2.m128d_f64[0] == 0.0 )
    return 0i64;
  if ( v2.m128d_f64[0] >= -2147483648.0 && v2.m128d_f64[0] <= 2147483647.0 )
    return (unsigned int)(int)v2.m128d_f64[0];
  v5 = _mm_and_pd(v2, (__m128d)_xmm);
  v6 = (int)v5.m128d_f64[0];
  if ( (double)v6 != v5.m128d_f64[0] )
    v5.m128d_f64[0] = (double)(v6 - (_mm_movemask_pd(_mm_unpacklo_pd(v5, v5)) & 1));
  result = (unsigned int)(int)fmod(v5.m128d_f64[0], 4294967296.0);
  if ( v4 < 0.0 )
    return (unsigned int)-(int)result;
  return result;
}

// File Line: 663
// RVA: 0x722740
__int64 __fastcall Scaleform::GFx::AS2::Value::ToUInt32(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  __m128d v2; // xmm0
  __int64 result; // rax
  double v4; // xmm6_8
  __m128d v5; // xmm0
  int v6; // ecx

  if ( this->T.Type == 4 )
    return this->NV.UInt32Value;
  v2.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v4 = v2.m128d_f64[0];
  if ( (*(_QWORD *)&v2.m128d_f64[0] & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 || v2.m128d_f64[0] == 0.0 )
    return 0i64;
  if ( v2.m128d_f64[0] >= 0.0 && v2.m128d_f64[0] <= 4294967295.0 )
    return (unsigned int)(int)v2.m128d_f64[0];
  v5 = _mm_and_pd(v2, (__m128d)_xmm);
  v6 = (int)v5.m128d_f64[0];
  if ( (double)v6 != v5.m128d_f64[0] )
    v5.m128d_f64[0] = (double)(v6 - (_mm_movemask_pd(_mm_unpacklo_pd(v5, v5)) & 1));
  result = (unsigned int)(int)fmod(v5.m128d_f64[0], 4294967296.0);
  if ( v4 < 0.0 )
    return (unsigned int)-(int)result;
  return result;
}

// File Line: 688
// RVA: 0x7212C0
char __fastcall Scaleform::GFx::AS2::Value::ToBool(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  char Type; // al
  Scaleform::GFx::ASStringNode *pStringNode; // rdx
  double v6; // xmm6_8
  Scaleform::GFx::ASStringNode *v7; // rax
  long double result; // [rsp+40h] [rbp+8h] BYREF

  Type = this->T.Type;
  if ( this->T.Type == 5 )
  {
    pStringNode = this->V.pStringNode;
    if ( !pStringNode->Size )
      return 0;
    if ( penv->StringContext.SWFVersion > 6u )
    {
      return 1;
    }
    else
    {
      if ( !Scaleform::GFx::AS2::StringToNumber(&result, (char *)pStringNode->pData) )
        return 0;
      v6 = result;
      return !Scaleform::GFx::NumberUtil::IsNaN(result) && v6 != 0.0;
    }
  }
  else
  {
    switch ( Type )
    {
      case 3:
        v7 = this->V.pStringNode;
        if ( ((unsigned __int64)v7 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
          && ((unsigned __int64)v7 & 0xFFFFFFFFFFFFFi64) != 0 )
        {
          return 0;
        }
        return this->NV.NumberValue != 0.0;
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
        return Type == 11;
    }
  }
}

// File Line: 771
// RVA: 0x721A10
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::Value::ToObject(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  int Type; // ecx
  __int64 v5; // rdi
  char v6; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  int v8; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::Object *result; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v15; // rcx
  __int64 v16; // rax
  Scaleform::GFx::AS2::Object *v17; // rbx
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h] BYREF

  Type = (unsigned __int8)this->T.Type;
  if ( Type == 6 )
    return this->V.pObjectValue;
  if ( Type == 8 )
  {
    result = this->V.pObjectValue;
    if ( result )
      return result;
    return 0i64;
  }
  if ( Type != 9 )
  {
    if ( Type == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(this, (Scaleform::GFx::AS2::FunctionRef *)&value, penv);
      v5 = *(_QWORD *)&value.T.Type;
      v6 = *((_BYTE *)&value.NV + 16);
      if ( *(_QWORD *)&value.T.Type )
      {
        if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
        {
          v7 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
          v8 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
          if ( (v8 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v8 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
            v6 = *((_BYTE *)&value.NV + 16);
          }
        }
        *(_QWORD *)&value.T.Type = 0i64;
        if ( (v6 & 1) == 0 )
        {
          pStringNode = value.V.pStringNode;
          if ( value.V.pStringNode )
          {
            RefCount = value.V.pStringNode->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              value.V.pStringNode->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        value.V.pStringNode = 0i64;
        return (Scaleform::GFx::AS2::Object *)v5;
      }
      *(_QWORD *)&value.T.Type = 0i64;
      if ( (*(_BYTE *)(&value.NV + 1) & 1) == 0 )
      {
        v12 = value.V.pStringNode;
        if ( value.V.pStringNode )
        {
          v13 = value.V.pStringNode->RefCount;
          if ( (v13 & 0x3FFFFFF) != 0 )
          {
            value.V.pStringNode->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
          }
        }
      }
      value.V.pStringNode = 0i64;
    }
    return 0i64;
  }
  Target = penv->Target;
  if ( !Target )
    return 0i64;
  v15 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
  v16 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v15 + 8i64))(v15);
  if ( !v16 )
    return 0i64;
  value.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Value::GetPropertyValue(
          this,
          penv,
          (Scaleform::GFx::AS2::ObjectInterface *)(v16 + 8),
          &value) )
  {
    if ( value.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    return 0i64;
  }
  v17 = Scaleform::GFx::AS2::Value::ToObject(&value, penv);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  return v17;
}

// File Line: 824
// RVA: 0x721440
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::Value::ToCharacter(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::GFx::DisplayObject *v4; // rdx
  char v5; // cl
  Scaleform::GFx::InteractiveObject *result; // rax

  if ( this->T.Type != 7 )
    return 0i64;
  if ( !penv )
    return 0i64;
  pStringNode = this->V.pStringNode;
  if ( !pStringNode )
    return 0i64;
  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)pStringNode,
         penv->Target->pASRoot->pMovieImpl);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  v5 = LOBYTE(v3->Scaleform::GFx::DisplayObjectBase::Flags) >> 7;
  result = 0i64;
  if ( (v5 & 1) != 0 )
    return (Scaleform::GFx::InteractiveObject *)v4;
  return result;
}

// File Line: 837
// RVA: 0x721BD0
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::Value::ToObjectInterface(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::GFx::DisplayObject *v4; // rcx
  char *v5; // rcx
  __int64 v6; // rax
  Scaleform::GFx::AS2::Object *v8; // rax

  if ( this->T.Type == 7 )
  {
    if ( penv )
    {
      pStringNode = this->V.pStringNode;
      if ( pStringNode )
      {
        v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)pStringNode,
               penv->Target->pASRoot->pMovieImpl);
        if ( v3 )
        {
          v4 = 0i64;
          if ( SLOBYTE(v3->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
            v4 = v3;
          if ( v4 )
          {
            v5 = (char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset;
            v6 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
            if ( v6 )
              return (Scaleform::GFx::AS2::ObjectInterface *)(v6 + 8);
          }
        }
      }
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(this, penv);
    if ( v8 )
      return &v8->Scaleform::GFx::AS2::ObjectInterface;
  }
  return 0i64;
}

// File Line: 848
// RVA: 0x721570
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ToFunction(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx

  if ( this->T.Type == 8 )
  {
    result->Flags = 0;
    Function = this->V.FunctionValue.Function;
    result->Function = Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    result->pLocalFrame = 0i64;
    pLocalFrame = this->V.FunctionValue.pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(result, pLocalFrame, this->V.FunctionValue.Flags & 1);
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
  return result;
}

// File Line: 861
// RVA: 0x722040
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ToResolveHandler(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result)
{
  bool v3; // zf
  Scaleform::GFx::AS2::FunctionObject *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx

  v3 = this->T.Type == 12;
  result->Flags = 0;
  if ( v3 )
  {
    Function = this->V.FunctionValue.Function;
    result->Function = Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    result->pLocalFrame = 0i64;
    pLocalFrame = this->V.FunctionValue.pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(result, pLocalFrame, this->V.FunctionValue.Flags & 1);
    return result;
  }
  else
  {
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
    return result;
  }
}

// File Line: 869
// RVA: 0x6DF5D0
void __fastcall Scaleform::GFx::AS2::Value::ConvertToNumber(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *pEnv)
{
  double v3; // xmm0_8

  v3 = Scaleform::GFx::AS2::Value::ToNumber(this, pEnv);
  if ( this->T.Type < 5u )
  {
    this->NV.NumberValue = v3;
    this->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 3;
    this->NV.NumberValue = v3;
  }
}

// File Line: 886
// RVA: 0x6DF620
void __fastcall Scaleform::GFx::AS2::Value::ConvertToStringVersioned(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *pEnv,
        unsigned int version)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS2::Value::ToStringVersioned(this, &result, pEnv, version);
  Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 5;
  pNode = result.pNode;
  this->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++pNode->RefCount;
  v5 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 896
// RVA: 0x713130
void __fastcall Scaleform::GFx::AS2::Value::SetAsObject(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASStringNode *obj)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rax
  char v5; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // [rsp+30h] [rbp-18h]
  char v12; // [rsp+38h] [rbp-10h]

  if ( obj && (*(unsigned int (__fastcall **)(unsigned int *))(*(_QWORD *)&obj->Size + 16i64))(&obj->Size) == 23 )
  {
    v4 = (Scaleform::GFx::AS2::FunctionRef *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&obj->Size + 96i64))(
                                               &obj->Size,
                                               &v10);
    Scaleform::GFx::AS2::Value::SetAsFunction(this, v4);
    v5 = v12;
    if ( (v12 & 2) == 0 )
    {
      v6 = v10;
      if ( v10 )
      {
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          v5 = v12;
        }
      }
    }
    v10 = 0i64;
    if ( (v5 & 1) == 0 )
    {
      v8 = v11;
      if ( v11 )
      {
        v9 = v11->RefCount;
        if ( (v9 & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = v9 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
    v11 = 0i64;
  }
  else if ( this->T.Type != 6 || this->V.pStringNode != obj )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 6;
    this->V.pStringNode = obj;
    if ( obj )
      obj->RefCount = (obj->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 912
// RVA: 0x713080
void __fastcall Scaleform::GFx::AS2::Value::SetAsCharacterHandle(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASStringNode *pchar)
{
  if ( this->T.Type != 7 || this->V.pStringNode != pchar )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 7;
    this->V.pStringNode = pchar;
    if ( pchar )
      ++LODWORD(pchar->pData);
  }
}

// File Line: 924
// RVA: 0x713020
void __fastcall Scaleform::GFx::AS2::Value::SetAsCharacter(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::InteractiveObject *pchar)
{
  Scaleform::GFx::CharacterHandle *pObject; // rbx

  if ( pchar )
  {
    pObject = pchar->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pchar);
  }
  else
  {
    pObject = 0i64;
  }
  if ( this->T.Type != 7 || this->V.pCharHandle != pObject )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 7;
    this->V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject;
    if ( pObject )
      ++pObject->RefCount;
  }
}

// File Line: 934
// RVA: 0x713220
void __fastcall Scaleform::GFx::AS2::Value::SetAsObjectInterface(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  bool v4; // cc
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // rax
  Scaleform::GFx::DisplayObject *v6; // rcx
  Scaleform::GFx::ASStringNode *pObject; // rbx
  Scaleform::GFx::ASStringNode *v8; // rbx

  v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&pobj->vfptr->gap8[8])(pobj) - 2 <= 3;
  vfptr = pobj->vfptr;
  if ( v4 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&vfptr->gap8[8])(pobj) - 2 <= 3
      && (v6 = (Scaleform::GFx::DisplayObject *)pobj[1].vfptr) != 0i64 )
    {
      pObject = (Scaleform::GFx::ASStringNode *)v6->pNameHandle.pObject;
      if ( !pObject )
        pObject = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v6);
    }
    else
    {
      pObject = 0i64;
    }
    if ( this->T.Type != 7 || this->V.pStringNode != pObject )
    {
      Scaleform::GFx::AS2::Value::DropRefs(this);
      this->T.Type = 7;
      this->V.pStringNode = pObject;
      if ( pObject )
        ++LODWORD(pObject->pData);
    }
  }
  else
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&vfptr->gap8[8])(pobj) - 6 > 0x26 )
      v8 = 0i64;
    else
      v8 = (Scaleform::GFx::ASStringNode *)&pobj[-2];
    Scaleform::GFx::AS2::Value::SetAsObject(this, v8);
  }
}

// File Line: 944
// RVA: 0x7130C0
void __fastcall Scaleform::GFx::AS2::Value::SetAsFunction(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRefBase *func)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx

  if ( this->T.Type != 8 || this->V.pStringNode != (Scaleform::GFx::ASStringNode *)func->Function )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 8;
    this->V.FunctionValue.Flags = 0;
    Function = func->Function;
    this->V.pStringNode = (Scaleform::GFx::ASStringNode *)func->Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    this->V.FunctionValue.pLocalFrame = 0i64;
    pLocalFrame = func->pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, pLocalFrame, func->Flags & 1);
  }
}

// File Line: 962
// RVA: 0x6D7950
void __fastcall Scaleform::GFx::AS2::Value::Add(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  char Type; // bl
  double v9; // xmm6_8
  double v10; // xmm6_8
  unsigned int SWFVersion; // ebx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rbx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rsi
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS2::Value v22; // [rsp+18h] [rbp-39h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v24; // [rsp+40h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+48h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value result; // [rsp+68h] [rbp+17h] BYREF
  __int64 v27; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::ASString v28; // [rsp+D0h] [rbp+7Fh] BYREF

  v27 = -2i64;
  v25.T.Type = 0;
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v22, v6);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  v7 = Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v25, v7);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  Type = v22.T.Type;
  if ( v22.T.Type == 5 || v25.T.Type == 5 )
  {
    SWFVersion = (unsigned __int8)penv->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v22, &v28, penv, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v28.pNode;
    ++v28.pNode->RefCount;
    pNode = v28.pNode;
    v13 = v28.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v14 = Scaleform::GFx::AS2::Value::ToStringVersioned(&v25, &v24, penv, SWFVersion);
    v15 = Scaleform::GFx::AS2::Value::ToString(&v22, &v23, penv, -1);
    Scaleform::GFx::ASString::operator+(v15, &v28, v14);
    v16 = v23.pNode;
    v13 = v23.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    Type = 5;
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v28.pNode;
    ++v28.pNode->RefCount;
    v17 = v28.pNode;
    v13 = v28.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    v18 = v24.pNode;
    v13 = v24.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    v19 = Scaleform::GFx::AS2::Value::ToString(&v22, &v28, penv, -1);
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 5;
    v20 = v19->pNode;
    this->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v19->pNode;
    ++v20->RefCount;
    v21 = v28.pNode;
    v13 = v28.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  }
  else
  {
    v9 = Scaleform::GFx::AS2::Value::ToNumber(&v25, penv);
    v10 = v9 + Scaleform::GFx::AS2::Value::ToNumber(&v22, penv);
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 3;
    this->NV.NumberValue = v10;
  }
  if ( v25.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v25);
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
}

// File Line: 983
// RVA: 0x6D7B70
void __fastcall Scaleform::GFx::AS2::Value::Add(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        int v2)
{
  Scaleform::GFx::AS2::Value *v6; // rax
  char Type; // bl
  unsigned int SWFVersion; // ebx
  Scaleform::GFx::ASStringNode *pNode; // rcx
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
  Scaleform::GFx::ASString v20; // [rsp+8h] [rbp-29h] BYREF
  Scaleform::GFx::ASString v21; // [rsp+10h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::Value result; // [rsp+40h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v24; // [rsp+B0h] [rbp+7Fh] BYREF

  v22.T.Type = 0;
  v6 = Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
  Scaleform::GFx::AS2::Value::operator=(&v22, v6);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  Type = v22.T.Type;
  if ( v22.T.Type == 5 )
  {
    SWFVersion = (unsigned __int8)penv->StringContext.SWFVersion;
    Scaleform::GFx::AS2::Value::ToStringVersioned(&v22, &v24, penv, SWFVersion);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v24.pNode;
    ++v24.pNode->RefCount;
    pNode = v24.pNode;
    v10 = v24.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result.T.Type = 4;
    result.NV.Int32Value = v2;
    v11 = Scaleform::GFx::AS2::Value::ToStringVersioned(&result, &v21, penv, SWFVersion);
    v12 = Scaleform::GFx::AS2::Value::ToString(&v22, &v20, penv, -1);
    Scaleform::GFx::ASString::operator+(v12, &v24, v11);
    v13 = v20.pNode;
    v10 = v20.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
    Type = 5;
    v22.T.Type = 5;
    v22.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v24.pNode;
    ++v24.pNode->RefCount;
    v14 = v24.pNode;
    v10 = v24.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = v21.pNode;
    v10 = v21.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v16 = Scaleform::GFx::AS2::Value::ToString(&v22, &v24, penv, -1);
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 5;
    v17 = v16->pNode;
    this->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v16->pNode;
    ++v17->RefCount;
    v18 = v24.pNode;
    v10 = v24.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    v19 = Scaleform::GFx::AS2::Value::ToNumber(&v22, penv) + (double)v2;
    if ( this->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 3;
    this->NV.NumberValue = v19;
  }
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
}

// File Line: 1003
// RVA: 0x721100
void __fastcall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  double v6; // xmm6_8
  double v7; // xmm7_8

  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.NumberValue = v6 - v7;
  this->T.Type = 3;
}

// File Line: 1010
// RVA: 0x721170
void __fastcall Scaleform::GFx::AS2::Value::Sub(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        int v2)
{
  double v5; // xmm6_8

  v5 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v5 - (double)v2;
}

// File Line: 1016
// RVA: 0x703160
void __fastcall Scaleform::GFx::AS2::Value::Mul(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  double v6; // xmm7_8
  double v7; // xmm6_8

  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 3;
  this->NV.NumberValue = v7 * v6;
}

// File Line: 1024
// RVA: 0x700440
char __fastcall Scaleform::GFx::AS2::Value::IsEqual(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  char Type; // r9
  char v7; // al
  unsigned __int8 v8; // r8
  char v9; // cl
  bool IsEqual; // bl
  int v12; // ecx
  Scaleform::GFx::AS2::Value *p_result; // rcx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v17; // ecx
  long double v18; // xmm0_8
  long double NumberValue; // xmm7_8
  bool IsNaN; // bl
  int v21; // ecx
  bool v22; // zf
  Scaleform::GFx::ASStringNode *v23; // rax
  Scaleform::GFx::ASString *CharacterNamePath; // rbx
  Scaleform::GFx::AS2::Value result; // [rsp+8h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value va; // [rsp+48h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+68h] [rbp-9h] BYREF
  __int64 v29; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::ASString v30; // [rsp+D8h] [rbp+67h] BYREF
  Scaleform::GFx::ASStringNode *retaddr; // [rsp+E8h] [rbp+77h]

  v29 = -2i64;
  Type = this->T.Type;
  v7 = this->T.Type <= 1u || Type == 10;
  v8 = v->T.Type;
  v9 = v8 <= 1u || v8 == 10;
  if ( v7 || v9 )
    return v7 == v9;
  switch ( Type )
  {
    case 2:
      v28.T.Type = 3;
      v28.V.pStringNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(this, penv));
      IsEqual = Scaleform::GFx::AS2::Value::IsEqual(&v28, penv, v);
      if ( v28.T.Type < 5u )
        return IsEqual;
      p_result = &v28;
      goto LABEL_26;
    case 3:
      if ( v8 != 2 && v8 <= 0xBu )
      {
        v17 = 2368;
        if ( _bittest(&v17, v8) )
        {
          Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, penv, NoHint);
          if ( (unsigned __int8)(result.T.Type - 1) <= 4u )
            goto LABEL_49;
          IsEqual = 0;
          goto LABEL_24;
        }
      }
      v18 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
      NumberValue = this->NV.NumberValue;
      IsNaN = Scaleform::GFx::NumberUtil::IsNaN(NumberValue);
      if ( IsNaN && Scaleform::GFx::NumberUtil::IsNaN(v18) )
        return 1;
      if ( !IsNaN && !Scaleform::GFx::NumberUtil::IsNaN(v18) )
        return NumberValue == v18;
      return 0;
    case 4:
      if ( v8 == 3 )
      {
        result.T.Type = 0;
        goto LABEL_62;
      }
      if ( v8 == 2 )
        return this->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v, penv);
      if ( v8 > 0xBu )
        return this->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v, penv);
      v21 = 2368;
      if ( !_bittest(&v21, v8) )
        return this->NV.Int32Value == Scaleform::GFx::AS2::Value::ToInt32(v, penv);
      Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, penv, NoHint);
      if ( (unsigned __int8)(result.T.Type - 1) <= 4u )
        goto LABEL_49;
      IsEqual = 0;
      goto LABEL_24;
    case 5:
      if ( (unsigned __int8)(v8 - 3) <= 1u )
      {
        v26.T.Type = 3;
        v26.V.pStringNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(this, penv));
        IsEqual = Scaleform::GFx::AS2::Value::IsEqual(&v26, penv, v);
        if ( v26.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v26);
        return IsEqual;
      }
      if ( v8 == 2 )
      {
        va.T.Type = 3;
        va.V.pStringNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(v, penv));
        IsEqual = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &va);
        if ( va.T.Type < 5u )
          return IsEqual;
        Scaleform::GFx::AS2::Value::DropRefs(&va);
        return IsEqual;
      }
      if ( v8 <= 0xBu )
      {
        v12 = 2368;
        if ( _bittest(&v12, v8) )
        {
          Scaleform::GFx::AS2::Value::ToPrimitive(v, &result, penv, NoHint);
          if ( (unsigned __int8)(result.T.Type - 1) > 4u )
            IsEqual = 0;
          else
LABEL_49:
            IsEqual = Scaleform::GFx::AS2::Value::IsEqual(this, penv, &result);
          goto LABEL_24;
        }
      }
      v14 = Scaleform::GFx::AS2::Value::ToString(v, &v30, penv, -1);
      pStringNode = this->V.pStringNode;
      retaddr = pStringNode;
      ++pStringNode->RefCount;
      IsEqual = pStringNode == v14->pNode;
      v22 = pStringNode->RefCount-- == 1;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pStringNode);
      pNode = v30.pNode;
      v22 = v30.pNode->RefCount-- == 1;
      if ( v22 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return IsEqual;
      }
      return IsEqual;
    case 6:
    case 8:
      if ( (unsigned __int8)(v8 - 2) <= 3u )
      {
        Scaleform::GFx::AS2::Value::ToPrimitive(this, &result, penv, NoHint);
        if ( (unsigned __int8)(result.T.Type - 1) > 4u )
          IsEqual = 0;
        else
LABEL_62:
          IsEqual = Scaleform::GFx::AS2::Value::IsEqual(&result, penv, v);
LABEL_24:
        if ( result.T.Type < 5u )
          return IsEqual;
        p_result = &result;
LABEL_26:
        Scaleform::GFx::AS2::Value::DropRefs(p_result);
        return IsEqual;
      }
      if ( (Type != 6 || v8 != 6) && (Type != 8 || v8 != 8) )
        return 0;
      v22 = this->V.pStringNode == v->V.pStringNode;
      break;
    case 7:
      if ( v8 != 7 )
        return 0;
      v23 = this->V.pStringNode;
      if ( !v23 || !v->V.pStringNode )
        return v23 == v->V.pStringNode;
      CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(v, penv);
      return Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, penv)->pNode == CharacterNamePath->pNode;
    default:
      return Type == (char)v8;
  }
  return v22;
}

// File Line: 1150
// RVA: 0x6DEA50
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Value::Compare(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  int v7; // ebx
  bool IsEqual; // al
  Scaleform::GFx::ASString *v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  bool v11; // al
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::ASString *v16; // rax
  bool v17; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  double v19; // xmm0_8
  long double v20; // xmm6_8
  long double v21; // xmm7_8
  bool v22; // al
  Scaleform::GFx::ASString v24; // [rsp+10h] [rbp-39h] BYREF
  Scaleform::GFx::ASString v25; // [rsp+18h] [rbp-31h] BYREF
  __int64 v26; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::AS2::Value v27; // [rsp+28h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value resulta; // [rsp+48h] [rbp-1h] BYREF

  v26 = -2i64;
  v7 = (int)result;
  if ( !(_DWORD)result )
  {
    IsEqual = Scaleform::GFx::AS2::Value::IsEqual(this, penv, v);
    result->T.Type = 2;
    result->V.BooleanValue = IsEqual;
    return result;
  }
  Scaleform::GFx::AS2::Value::ToPrimitive(this, &resulta, penv, NoHint);
  Scaleform::GFx::AS2::Value::ToPrimitive(v, &v27, penv, NoHint);
  if ( resulta.T.Type == 5 && v27.T.Type == 5 )
  {
    if ( v7 >= 0 )
    {
      v15 = Scaleform::GFx::AS2::Value::ToString(&v27, &v24, penv, -1);
      v16 = Scaleform::GFx::AS2::Value::ToString(&resulta, &v25, penv, -1);
      v17 = v16->pNode != v15->pNode && !Scaleform::GFx::ASString::operator<(v16, v15);
      result->T.Type = 2;
      result->V.BooleanValue = v17;
      pNode = v25.pNode;
      v13 = v25.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v14 = v24.pNode;
      v13 = v24.pNode->RefCount-- == 1;
      if ( !v13 )
        goto LABEL_49;
    }
    else
    {
      v9 = Scaleform::GFx::AS2::Value::ToString(&v27, &v25, penv, -1);
      v10 = Scaleform::GFx::AS2::Value::ToString(&resulta, &v24, penv, -1);
      v11 = Scaleform::GFx::ASString::operator<(v10, v9);
      result->T.Type = 2;
      result->V.BooleanValue = v11;
      v12 = v24.pNode;
      v13 = v24.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v14 = v25.pNode;
      v13 = v25.pNode->RefCount-- == 1;
      if ( !v13 )
        goto LABEL_49;
    }
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  else if ( penv->StringContext.SWFVersion > 6u
         && (!resulta.T.Type || resulta.T.Type == 10 || !v27.T.Type || v27.T.Type == 10)
         || ((v19 = Scaleform::GFx::AS2::Value::ToNumber(&resulta, penv), v7 >= 0)
           ? (v21 = v19, v20 = Scaleform::GFx::AS2::Value::ToNumber(&v27, penv))
           : (v20 = v19, v21 = Scaleform::GFx::AS2::Value::ToNumber(&v27, penv)),
             (v25.pNode = *(Scaleform::GFx::ASStringNode **)&v20,
              (*(_QWORD *)&v20 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64)
          && (*(_QWORD *)&v20 & 0xFFFFFFFFFFFFFi64) != 0) )
  {
    result->T.Type = 0;
  }
  else
  {
    v25.pNode = *(Scaleform::GFx::ASStringNode **)&v21;
    if ( (*(_QWORD *)&v21 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
      && (*(_QWORD *)&v21 & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      result->T.Type = 0;
    }
    else
    {
      if ( v20 == v21 )
      {
        v22 = 0;
      }
      else if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v20) && Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v21) )
      {
        v22 = 0;
      }
      else if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v21) && Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v20) )
      {
        v22 = 0;
      }
      else
      {
        v25.pNode = *(Scaleform::GFx::ASStringNode **)&v20;
        if ( v20 == INFINITY )
        {
          v22 = 0;
        }
        else
        {
          v25.pNode = *(Scaleform::GFx::ASStringNode **)&v21;
          if ( v21 == INFINITY )
          {
            v22 = 1;
          }
          else
          {
            v25.pNode = *(Scaleform::GFx::ASStringNode **)&v21;
            if ( v21 == -INFINITY )
            {
              v22 = 0;
            }
            else
            {
              v25.pNode = *(Scaleform::GFx::ASStringNode **)&v20;
              v22 = v20 == -INFINITY || v21 > v20;
            }
          }
        }
      }
      result->T.Type = 2;
      result->V.BooleanValue = v22;
    }
  }
LABEL_49:
  if ( v27.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v27);
  if ( resulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resulta);
  return result;
}

// File Line: 1206
// RVA: 0x720B30
void __fastcall Scaleform::GFx::AS2::Value::StringConcat(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString v10; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+20h] BYREF

  v5 = Scaleform::GFx::AS2::Value::ToString(this, &result, penv, -1);
  Scaleform::GFx::ASString::operator+(v5, &v10, str);
  pNode = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 5;
  v8 = v10.pNode;
  this->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10.pNode;
  ++v8->RefCount;
  v9 = v10.pNode;
  v7 = v10.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 1263
// RVA: 0x6E2CE0
void __fastcall Scaleform::GFx::AS2::Value::DropRefs(Scaleform::GFx::AS2::Value *this)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  bool v3; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObjectValue; // rcx
  unsigned int RefCount; // eax

  switch ( this->T.Type )
  {
    case 5:
    case 0xB:
      pStringNode = this->V.pStringNode;
      v3 = pStringNode->RefCount-- == 1;
      if ( v3 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pStringNode);
      break;
    case 6:
    case 9:
      pObjectValue = this->V.pObjectValue;
      if ( pObjectValue )
      {
        RefCount = pObjectValue->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          pObjectValue->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObjectValue);
        }
        goto LABEL_19;
      }
      break;
    case 7:
      v8 = this->V.pStringNode;
      if ( v8 )
      {
        if ( (int)--LODWORD(v8->pData) > 0 )
        {
LABEL_19:
          this->V.pStringNode = 0i64;
        }
        else
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)v8);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
          this->V.pStringNode = 0i64;
        }
      }
      break;
    case 8:
    case 0xC:
      v4 = this->V.pObjectValue;
      if ( v4 )
      {
        if ( (this->V.FunctionValue.Flags & 2) == 0 )
        {
          v5 = v4->RefCount;
          if ( (v5 & 0x3FFFFFF) != 0 )
          {
            v4->RefCount = v5 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
        v3 = (this->V.FunctionValue.Flags & 1) == 0;
        this->V.pStringNode = 0i64;
        if ( v3 )
        {
          pLocalFrame = this->V.FunctionValue.pLocalFrame;
          if ( pLocalFrame )
          {
            v7 = pLocalFrame->RefCount;
            if ( (v7 & 0x3FFFFFF) != 0 )
            {
              pLocalFrame->RefCount = v7 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        this->V.FunctionValue.pLocalFrame = 0i64;
      }
      break;
    default:
      return;
  }
}

// File Line: 1311
// RVA: 0x721C60
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Value::ToPrimitive(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value::Hint __formal)
{
  char Type; // cl
  Scaleform::GFx::ASStringNode *v8; // rax
  char v9; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  int v11; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ObjectInterface *v16; // rax
  Scaleform::GFx::AS2::ObjectInterface *v17; // r14
  unsigned __int16 FuncCallNestingLevel; // cx
  char v19; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // rcx
  int v21; // edx
  Scaleform::GFx::ASStringNode *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::Value *p_v; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  const char *v26; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value resulta; // [rsp+28h] [rbp-81h] BYREF
  Scaleform::GFx::AS2::Value v31; // [rsp+48h] [rbp-61h] BYREF
  Scaleform::GFx::AS2::FnCall v32; // [rsp+70h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+B0h] [rbp+7h] BYREF
  __int64 v34; // [rsp+D0h] [rbp+27h]
  Scaleform::GFx::ASString v35; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::Value *v36; // [rsp+118h] [rbp+6Fh]

  v36 = result;
  v34 = -2i64;
  Type = this->T.Type;
  if ( (unsigned __int8)(Type - 6) > 2u )
  {
    if ( Type == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(this, (Scaleform::GFx::AS2::FunctionRef *)&resulta, penv);
      v8 = *(Scaleform::GFx::ASStringNode **)&resulta.T.Type;
      if ( *(_QWORD *)&resulta.T.Type )
      {
        result->T.Type = 8;
        result->V.FunctionValue.Flags = 0;
        result->V.pStringNode = v8;
        ++v8->RefCount;
        v8->RefCount &= 0x8FFFFFFF;
        result->V.FunctionValue.pLocalFrame = 0i64;
        if ( resulta.V.pStringNode )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
            &result->V.FunctionValue,
            (Scaleform::GFx::AS2::LocalFrame *)resulta.V.pStringNode,
            *(_BYTE *)(&resulta.NV + 1) & 1);
        v9 = *((_BYTE *)&resulta.NV + 16);
        if ( (*(_BYTE *)(&resulta.NV + 1) & 2) == 0 )
        {
          v10 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&resulta.T.Type;
          if ( *(_QWORD *)&resulta.T.Type )
          {
            v11 = *(_DWORD *)(*(_QWORD *)&resulta.T.Type + 24i64);
            if ( (v11 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(*(_QWORD *)&resulta.T.Type + 24i64) = v11 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
              v9 = *((_BYTE *)&resulta.NV + 16);
            }
          }
        }
        *(_QWORD *)&resulta.T.Type = 0i64;
        if ( (v9 & 1) == 0 )
        {
          pStringNode = resulta.V.pStringNode;
          if ( resulta.V.pStringNode )
          {
            RefCount = resulta.V.pStringNode->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              resulta.V.pStringNode->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        resulta.V.pStringNode = 0i64;
        return result;
      }
      *(_QWORD *)&resulta.T.Type = 0i64;
      if ( (*(_BYTE *)(&resulta.NV + 1) & 1) == 0 )
      {
        v14 = resulta.V.pStringNode;
        if ( resulta.V.pStringNode )
        {
          v15 = resulta.V.pStringNode->RefCount;
          if ( (v15 & 0x3FFFFFF) != 0 )
          {
            resulta.V.pStringNode->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
          }
        }
      }
      resulta.V.pStringNode = 0i64;
    }
    Scaleform::GFx::AS2::Value::Value(result, this);
    return result;
  }
  v31.T.Type = 0;
  v16 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, penv);
  v17 = v16;
  if ( penv
    && v16
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, _DWORD))v16->vfptr->GetMemberRaw)(
         v16,
         &penv->StringContext,
         &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].RefCount,
         &v31,
         0) )
  {
    v.T.Type = 0;
    FuncCallNestingLevel = penv->FuncCallNestingLevel;
    penv->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel < 0xFFu )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v31, (Scaleform::GFx::AS2::FunctionRef *)&resulta, penv);
      if ( *(_QWORD *)&resulta.T.Type )
      {
        v32.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
        v32.Result = &v;
        v32.ThisPtr = v17;
        memset(&v32.ThisFunctionRef, 0, 17);
        v32.Env = penv;
        *(_QWORD *)&v32.NArgs = 0i64;
        (*(void (__fastcall **)(_QWORD, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::ASStringNode *, _QWORD))(**(_QWORD **)&resulta.T.Type + 80i64))(
          *(_QWORD *)&resulta.T.Type,
          &v32,
          resulta.V.pStringNode,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v32);
      }
      v19 = *((_BYTE *)&resulta.NV + 16);
      if ( (*(_BYTE *)(&resulta.NV + 1) & 2) == 0 )
      {
        v20 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&resulta.T.Type;
        if ( *(_QWORD *)&resulta.T.Type )
        {
          v21 = *(_DWORD *)(*(_QWORD *)&resulta.T.Type + 24i64);
          if ( (v21 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_QWORD *)&resulta.T.Type + 24i64) = v21 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
            v19 = *((_BYTE *)&resulta.NV + 16);
          }
        }
      }
      *(_QWORD *)&resulta.T.Type = 0i64;
      if ( (v19 & 1) == 0 )
      {
        v22 = resulta.V.pStringNode;
        if ( resulta.V.pStringNode )
        {
          v23 = resulta.V.pStringNode->RefCount;
          if ( (v23 & 0x3FFFFFF) != 0 )
          {
            resulta.V.pStringNode->RefCount = v23 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v22);
          }
        }
      }
      resulta.V.pStringNode = 0i64;
    }
    --penv->FuncCallNestingLevel;
    Scaleform::GFx::AS2::Value::Value(result, &v);
    if ( v.T.Type < 5u )
      goto LABEL_51;
    p_v = &v;
  }
  else
  {
    resulta.T.Type = 0;
    if ( this->T.Type == 7 && this->V.pStringNode )
    {
      resulta.T.Type = 5;
      resulta.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, penv)->pNode;
      ++resulta.V.pStringNode->RefCount;
    }
    else
    {
      if ( this->T.Type == 6
        && (v25 = this->V.pStringNode) != 0i64
        && (v26 = (const char *)(*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::Environment *))(*(_QWORD *)&v25->Size + 8i64))(
                                  &v25->Size,
                                  penv)) != 0i64 )
      {
        resulta.T.Type = 5;
        resulta.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::Environment::CreateString(
                                                            penv,
                                                            &v35,
                                                            v26)->pNode;
        ++resulta.V.pStringNode->RefCount;
      }
      else
      {
        resulta.T.Type = 5;
        resulta.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::Value::ToString(this, &v35, penv, -1)->pNode;
        ++resulta.V.pStringNode->RefCount;
      }
      pNode = v35.pNode;
      if ( v35.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS2::Value::Value(result, &resulta);
    if ( resulta.T.Type < 5u )
      goto LABEL_51;
    p_v = &resulta;
  }
  Scaleform::GFx::AS2::Value::DropRefs(p_v);
LABEL_51:
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  return result;
}

// File Line: 1385
// RVA: 0x6F4E50
char __fastcall Scaleform::GFx::AS2::Value::GetPropertyValue(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Value *value)
{
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::FnCall v8; // [rsp+48h] [rbp-50h] BYREF

  if ( this->T.Type != 9 || !penv )
    return 0;
  if ( !*(_QWORD *)&this->V.pStringNode->Size )
  {
    if ( penv->vfptr->IsVerboseActionErrors(penv) )
      Scaleform::GFx::AS2::Environment::LogScriptError(penv, "Getter method is null.");
    return 0;
  }
  v.T.Type = 0;
  v8.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  v8.Result = &v;
  v8.ThisPtr = pthis;
  memset(&v8.ThisFunctionRef, 0, 17);
  v8.Env = penv;
  *(_QWORD *)&v8.NArgs = 0i64;
  (*(void (__fastcall **)(_QWORD, Scaleform::GFx::AS2::FnCall *, const char *, _QWORD, __int64))(**(_QWORD **)&this->V.pStringNode->Size
                                                                                               + 80i64))(
    *(_QWORD *)&this->V.pStringNode->Size,
    &v8,
    this->V.pStringNode[1].pData,
    0i64,
    -2i64);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v8);
  Scaleform::GFx::AS2::Value::operator=(value, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 1405
// RVA: 0x71AE70
void __fastcall Scaleform::GFx::AS2::Value::SetPropertyValue(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  int v9; // edx
  Scaleform::GFx::AS2::Value *v10; // rcx
  Scaleform::GFx::AS2::Value *v11; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::AS2::Value v12; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::FnCall v13; // [rsp+50h] [rbp-58h] BYREF

  if ( this->T.Type == 9 && penv )
  {
    if ( this->V.pStringNode[1].pLower )
    {
      v12.T.Type = 0;
      if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      pCurrent = penv->Stack.pCurrent;
      v11 = pCurrent;
      if ( pCurrent )
        Scaleform::GFx::AS2::Value::Value(pCurrent, val);
      v9 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
      v13.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
      v13.Result = &v12;
      v13.ThisPtr = pthis;
      memset(&v13.ThisFunctionRef, 0, 17);
      v13.Env = penv;
      v13.NArgs = 1;
      v13.FirstArgBottomIndex = v9;
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS2::FnCall *, _QWORD, _QWORD, __int64, Scaleform::GFx::AS2::Value *))this->V.pStringNode[1].pLower->$09FB520FFAA77E97CDD800E2BDD737E6::pData
       + 10))(
        this->V.pStringNode[1].pLower,
        &v13,
        *(_QWORD *)&this->V.pStringNode[1].RefCount,
        0i64,
        -2i64,
        v11);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v13);
      v10 = penv->Stack.pCurrent;
      if ( v10->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v10);
      if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
      if ( v12.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v12);
    }
    else if ( penv->vfptr->IsVerboseActionErrors(penv) )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(penv, "Setter method is null.");
    }
  }
}

// File Line: 1425
// RVA: 0x6EEDC0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::GetCharacterNamePath(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx

  pStringNode = this->V.pStringNode;
  if ( pStringNode
    && Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)pStringNode,
         penv->Target->pASRoot->pMovieImpl) )
  {
    return (Scaleform::GFx::ASString *)&this->V.pStringNode->RefCount;
  }
  else
  {
    return (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  }
}

// File Line: 1434
// RVA: 0x712120
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::Value::ResolveFunctionName(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASStringNode *pStringNode; // rdi
  bool v8; // zf
  Scaleform::GFx::AS2::FunctionObject *v9; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString functionName; // [rsp+80h] [rbp+18h] BYREF

  if ( penv && this->T.Type == 11 )
  {
    v6 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    functionName.pNode = v6;
    ++v6->RefCount;
    pStringNode = this->V.pStringNode;
    ++pStringNode->RefCount;
    v8 = v6->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    functionName.pNode = pStringNode;
    v9 = (Scaleform::GFx::AS2::FunctionObject *)Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
                                                  penv->StringContext.pContext,
                                                  &functionName);
    v10 = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
    result->Flags = 0;
    result->Function = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
    result->pLocalFrame = 0i64;
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    v8 = pStringNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pStringNode);
    return result;
  }
  else
  {
    result->Flags = 0;
    result->Function = 0i64;
    result->pLocalFrame = 0i64;
    return result;
  }
}

// File Line: 1447
// RVA: 0x6E2560
void __fastcall Scaleform::GFx::AS2::Value::Div(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  double v6; // xmm6_8
  double v7; // xmm0_8
  double v8; // xmm6_8

  v6 = Scaleform::GFx::AS2::Value::ToNumber(this, penv);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
  if ( (*(_QWORD *)&v6 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&v6 & 0xFFFFFFFFFFFFFi64) != 0
    || (*(_QWORD *)&v7 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&v7 & 0xFFFFFFFFFFFFFi64) != 0 )
  {
    goto LABEL_8;
  }
  if ( v7 == 0.0 )
  {
    if ( v6 == 0.0 )
    {
LABEL_8:
      v8 = Scaleform::GFx::NumberUtil::NaN();
      goto LABEL_13;
    }
    if ( v6 < 0.0 )
      v8 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
    else
      v8 = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
  }
  else
  {
    v8 = v6 / v7;
  }
LABEL_13:
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.NumberValue = v8;
  this->T.Type = 3;
}

// File Line: 1473
// RVA: 0x6CD8D0
void __fastcall Scaleform::GFx::AS2::ValueGuard::ValueGuard(
        Scaleform::GFx::AS2::ValueGuard *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  Scaleform::GFx::DisplayObject *v6; // rax
  Scaleform::GFx::InteractiveObject *v7; // rcx

  this->pEnv = penv;
  Scaleform::GFx::AS2::Value::Value(&this->mValue, val);
  if ( val->T.Type == 7 )
  {
    if ( this->pEnv
      && (pStringNode = val->V.pStringNode) != 0i64
      && (v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                 (Scaleform::GFx::CharacterHandle *)pStringNode,
                 this->pEnv->Target->pASRoot->pMovieImpl)) != 0i64 )
    {
      v7 = 0i64;
      if ( SLOBYTE(v6->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
        v7 = (Scaleform::GFx::InteractiveObject *)v6;
    }
    else
    {
      v7 = 0i64;
    }
    this->pChar = v7;
    if ( v7 )
      ++v7->RefCount;
  }
  else
  {
    this->pChar = 0i64;
  }
}

// File Line: 1486
// RVA: 0x6D28A0
void __fastcall Scaleform::GFx::AS2::ValueGuard::~ValueGuard(Scaleform::GFx::AS2::ValueGuard *this)
{
  Scaleform::GFx::InteractiveObject *pChar; // rcx

  pChar = this->pChar;
  if ( pChar )
    Scaleform::RefCountNTSImpl::Release(pChar);
  if ( this->mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->mValue);
}

// File Line: 1510
// RVA: 0x6DA880
Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *__fastcall Scaleform::GFx::AS2::FnCall::Arg(
        Scaleform::GFx::AS2::FnCall *this,
        int n)
{
  Scaleform::GFx::AS2::Environment *Env; // r8
  unsigned int v3; // r9d

  Env = this->Env;
  v3 = this->FirstArgBottomIndex - n;
  if ( v3 > 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1) + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    return 0i64;
  else
    return (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *)((char *)Env->Stack.Pages.Data.Data[(unsigned __int64)v3 >> 5]
                                                                                  + 32 * (v3 & 0x1F));
}

// File Line: 1527
// RVA: 0x7010E0
__int64 __fastcall Scaleform::GFx::AS2::FnCall::IsVerboseActionErrors(Scaleform::GFx::AS2::FnCall *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Environment *))this->Env->vfptr->IsVerboseActionErrors)(this->Env);
}

