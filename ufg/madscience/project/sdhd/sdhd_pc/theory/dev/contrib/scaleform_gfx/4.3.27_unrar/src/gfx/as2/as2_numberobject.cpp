// File Line: 29
// RVA: 0x6CB070
void __fastcall Scaleform::GFx::AS2::NumberObject::NumberObject(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::NumberObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::NumberObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->mValue = 0.0;
  Scaleform::StringLH::StringLH(&this->StringValue);
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Number);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 45
// RVA: 0x6F69F0
const char *__fastcall Scaleform::GFx::AS2::NumberObject::GetTextValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  const char *v3; // rax
  char destStr[72]; // [rsp+20h] [rbp-48h] BYREF

  v3 = Scaleform::GFx::NumberUtil::ToString(*(long double *)&this->ResolveHandler.pLocalFrame, destStr, 0x40ui64, 10);
  Scaleform::String::operator=((Scaleform::String *)&this->ResolveHandler.Flags, v3);
  return (const char *)((*(_QWORD *)&this->ResolveHandler.Flags & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 53
// RVA: 0x71D170
void __fastcall Scaleform::GFx::AS2::NumberObject::SetValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  this->mValue = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
}

// File Line: 58
// RVA: 0x6F72F0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::NumberObject::GetValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  long double mValue; // xmm0_8

  mValue = this->mValue;
  result->T.Type = 3;
  result->NV.NumberValue = mValue;
  return result;
}

// File Line: 96
// RVA: 0x6AA680
void __fastcall Scaleform::GFx::AS2::GAS_NumberToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  int v6; // eax
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  const char *v9; // rax
  Scaleform::GFx::ASString *v10; // rsi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  char destStr[64]; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 9 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = v3 - 2;
    if ( !v3 )
      v5 = 0i64;
    v6 = 10;
    if ( fn->NArgs > 0 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    }
    v9 = Scaleform::GFx::NumberUtil::ToString(*(long double *)&v5[6].vfptr, destStr, 0x40ui64, v6);
    Scaleform::String::operator=((Scaleform::String *)&v5[6].pProto, v9);
    v10 = Scaleform::GFx::AS2::Environment::CreateString(
            fn->Env,
            &result,
            (const char *)(((unsigned __int64)v5[6].pProto.pObject & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v11 = fn->Result;
    if ( v11->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v11->T.Type = 5;
    pNode = v10->pNode;
    v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10->pNode;
    ++pNode->RefCount;
    v13 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Number");
  }
}

// File Line: 111
// RVA: 0x6AA7C0
void __fastcall Scaleform::GFx::AS2::GAS_NumberValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-40h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 9 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Value *))v4->vfptr->GetMember)(
                                         v4,
                                         &v8);
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, fn->Env);
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Number");
  }
}

// File Line: 153
// RVA: 0x6CAF50
void __fastcall Scaleform::GFx::AS2::NumberCtorFunction::NumberCtorFunction(
        Scaleform::GFx::AS2::NumberCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  __int64 v4; // rbx
  __int64 v5; // rax
  Scaleform::GFx::AS2::GASNameNumberFunc *v6; // rdi
  long double v7; // xmm0_8
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-50h] BYREF
  char v12; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::NumberCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::NumberCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = 0i64;
  if ( GASNumberConstTable[0].Name )
  {
    v5 = 0i64;
    v6 = GASNumberConstTable;
    do
    {
      v12 = 7;
      v7 = GASNumberConstTable[v5].Function();
      v11.T.Type = 3;
      v11.NV.NumberValue = v7;
      v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, v6->Name);
      this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &this->Scaleform::GFx::AS2::ObjectInterface,
        psc,
        v8,
        &v11,
        (Scaleform::GFx::AS2::PropFlags *)&v12);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v11.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v11);
      v5 = ++v4;
      v6 = &GASNumberConstTable[v4];
    }
    while ( v6->Name );
  }
}

// File Line: 162
// RVA: 0x6F97B0
void __fastcall Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rax
  char v7; // bl
  long double v8; // xmm6_8
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+50h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+70h] [rbp-38h] BYREF

  v2 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 9
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
      v2 = (Scaleform::GFx::AS2::Value *)&v4[-2];
    if ( fn->NArgs <= 0 )
    {
      v13.T.Type = 0;
      v6 = &v13;
      v7 = 2;
    }
    else
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::Value(&v14, v5->Values);
      v7 = 1;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v6);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      if ( v13.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v13);
    }
    if ( (v7 & 1) != 0 && v14.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v14);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v2->T.Type + 24i64))(
      v2,
      fn->Env,
      &v);
    Scaleform::GFx::AS2::Value::operator=(fn->Result, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  else
  {
    if ( fn->NArgs )
    {
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      Env = fn->Env;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v2 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v2, Env);
    }
    else
    {
      v8 = 0.0;
    }
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v8;
  }
}

// File Line: 176
// RVA: 0x6E06D0
void __fastcall Scaleform::GFx::AS2::NumberCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::NumberCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::NumberObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::NumberObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::NumberCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                              this,
                                              112i64);
  if ( v3 )
    Scaleform::GFx::AS2::NumberObject::NumberObject(v3, penv);
}

// File Line: 182
// RVA: 0x70E290
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::NumberCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::NumberCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::AS2::Object *Prototype; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *pObject; // rbx
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  int v14; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h] BYREF
  __int64 flags; // [rsp+D0h] [rbp+50h] BYREF
  void *pHeap; // [rsp+D8h] [rbp+58h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::NumberCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                    result,
                                                    104i64,
                                                    0i64);
  flags = (__int64)v4;
  if ( v4 )
    Scaleform::GFx::AS2::NumberCtorFunction::NumberCtorFunction(v4, &psc);
  else
    v6 = 0i64;
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v7 = (*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(v5, 176i64, 0i64);
  if ( v7 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v7, &psc);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::NumberObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::NumberObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 96) = 0i64;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v7 + 104));
    if ( !*(_QWORD *)(v7 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v17.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v7 + 32) + 80i64))(
        v7 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v17,
        &objproto);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    v9 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v7 + 40);
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
    *(_QWORD *)(v7 + 40) = Prototype;
    flags = v7 + 112;
    *(_QWORD *)(v7 + 112) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v7 + 136) = 0;
    *(_QWORD *)(v7 + 120) = 0i64;
    *(_QWORD *)(v7 + 128) = 0i64;
    *(_BYTE *)(v7 + 160) = 0;
    *(_QWORD *)(v7 + 144) = 0i64;
    *(_QWORD *)(v7 + 152) = 0i64;
    *(_QWORD *)(v7 + 168) = 0i64;
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 112) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v7 + 112),
      (Scaleform::GFx::AS2::Object *)v7,
      &psc,
      result);
    *(_QWORD *)v7 = &Scaleform::GFx::AS2::NumberProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v7 + 32) = &Scaleform::GFx::AS2::NumberProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v7 + 112) = &Scaleform::GFx::AS2::NumberProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v7 + 112),
      (Scaleform::GFx::AS2::Object *)v7,
      &psc,
      NumberFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v7 = 0i64;
  }
  flags = v7;
  pHeap = &objproto;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v7;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Number,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  pObject = pgc->pGlobal.pObject;
  v17.T.Type = 8;
  v17.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v17.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v17.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v17.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
    &v17,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  if ( v7 )
  {
    v14 = *(_DWORD *)(v7 + 24);
    if ( (v14 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v7 + 24) = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
    }
  }
  return result;
}

