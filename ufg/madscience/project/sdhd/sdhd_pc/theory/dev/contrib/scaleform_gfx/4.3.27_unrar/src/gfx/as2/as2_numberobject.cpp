// File Line: 29
// RVA: 0x6CB070
void __fastcall Scaleform::GFx::AS2::NumberObject::NumberObject(Scaleform::GFx::AS2::NumberObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::StringLH *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = (Scaleform::StringLH *)this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->HeapTypeBits = (unsigned __int64)&Scaleform::GFx::AS2::NumberObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3[4].HeapTypeBits = (unsigned __int64)&Scaleform::GFx::AS2::NumberObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3[12].HeapTypeBits = 0i64;
  Scaleform::StringLH::StringLH(v3 + 13);
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Number);
  (*(void (__fastcall **)(Scaleform::StringLH *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(v3[4].HeapTypeBits + 104))(
    v3 + 4,
    &v2->StringContext,
    v4);
}

// File Line: 45
// RVA: 0x6F69F0
const char *__fastcall Scaleform::GFx::AS2::NumberObject::GetTextValue(Scaleform::GFx::AS2::NumberObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::NumberObject *v2; // rbx
  const char *v3; // rax
  char destStr; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = Scaleform::GFx::NumberUtil::ToString(*(long double *)&this->ResolveHandler.pLocalFrame, &destStr, 0x40ui64, 10);
  Scaleform::String::operator=((Scaleform::String *)&v2->ResolveHandler.Flags, v3);
  return (const char *)((*(_QWORD *)&v2->ResolveHandler.Flags & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 53
// RVA: 0x71D170
void __fastcall Scaleform::GFx::AS2::NumberObject::SetValue(Scaleform::GFx::AS2::NumberObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  this->mValue = Scaleform::GFx::AS2::Value::ToNumber(v, penv);
}

// File Line: 58
// RVA: 0x6F72F0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::NumberObject::GetValue(Scaleform::GFx::AS2::NumberObject *this, Scaleform::GFx::AS2::Value *result)
{
  long double v2; // xmm0_8

  v2 = this->mValue;
  result->T.Type = 3;
  result->NV.NumberValue = v2;
  return result;
}

// File Line: 96
// RVA: 0x6AA680
void __fastcall Scaleform::GFx::AS2::GAS_NumberToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // r9
  signed __int64 v5; // rbx
  int v6; // eax
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  const char *v9; // rax
  Scaleform::GFx::ASString *v10; // rsi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  char destStr; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 9 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)&v3[-2];
    if ( !v3 )
      v5 = 0i64;
    v6 = 10;
    if ( v1->NArgs > 0 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v4 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v6 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
    }
    v9 = Scaleform::GFx::NumberUtil::ToString(*(long double *)(v5 + 96), &destStr, 0x40ui64, v6);
    Scaleform::String::operator=((Scaleform::String *)(v5 + 104), v9);
    v10 = Scaleform::GFx::AS2::Environment::CreateString(
            v1->Env,
            &result,
            (const char *)((*(_QWORD *)(v5 + 104) & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v11 = v1->Result;
    if ( v11->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v11->T.Type = 5;
    v12 = v10->pNode;
    v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10->pNode;
    ++v12->RefCount;
    v13 = result.pNode;
    v14 = result.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Number");
  }
}

// File Line: 111
// RVA: 0x6AA7C0
void __fastcall Scaleform::GFx::AS2::GAS_NumberValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  long double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-40h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 9 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)(*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v4 + 32i64))(
                                         v4,
                                         &v8);
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1->Env);
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Number");
  }
}

// File Line: 153
// RVA: 0x6CAF50
void __usercall Scaleform::GFx::AS2::NumberCtorFunction::NumberCtorFunction(Scaleform::GFx::AS2::NumberCtorFunction *this@<rcx>, Scaleform::GFx::AS2::ASStringContext *psc@<rdx>, Scaleform::GFx::ASStringNode *a3@<xmm0>)
{
  Scaleform::GFx::AS2::ASStringContext *v3; // rbp
  Scaleform::GFx::AS2::NumberCtorFunction *v4; // rsi
  __int64 v5; // rbx
  __int64 v6; // rax
  Scaleform::GFx::AS2::GASNameNumberFunc *v7; // rdi
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value v11; // [rsp+38h] [rbp-50h]
  char v12; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h]

  v3 = psc;
  v4 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::NumberCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::NumberCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5 = 0i64;
  if ( GASNumberConstTable[0].Name )
  {
    v6 = 0i64;
    v7 = GASNumberConstTable;
    do
    {
      v12 = 7;
      GASNumberConstTable[v6].Function();
      v11.T.Type = 3;
      v11.V.pStringNode = a3;
      v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v3, &result, v7->Name);
      ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v4->vfptr->SetMemberRaw)(
        &v4->vfptr,
        v3,
        v8,
        &v11);
      v9 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( v11.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v11);
      v6 = ++v5;
      v7 = &GASNumberConstTable[v5];
    }
    while ( v7->Name );
  }
}

// File Line: 162
// RVA: 0x6F97B0
void __fastcall Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn, __int64 a2)
{
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  __int64 v5; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rax
  char v9; // bl
  long double v10; // xmm6_8
  unsigned __int64 v11; // r8
  Scaleform::GFx::AS2::Environment *v12; // rdx
  Scaleform::GFx::AS2::Value *v13; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-78h]
  Scaleform::GFx::AS2::Value v15; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS2::Value v16; // [rsp+70h] [rbp-38h]

  v2 = fn;
  v3 = 0i64;
  v4 = fn->ThisPtr;
  if ( !v4
    || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *, __int64))&v4->vfptr->gap8[8])(v4, a2) != 9
    || ((unsigned __int8 (__cdecl *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))v2->ThisPtr->vfptr->IsBuiltinPrototype)(
         v2->ThisPtr,
         v5) )
  {
    if ( v2->NArgs )
    {
      v11 = (unsigned int)v2->FirstArgBottomIndex;
      v12 = v2->Env;
      if ( (unsigned int)v11 <= 32 * (LODWORD(v12->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
        v3 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v2->FirstArgBottomIndex & 0x1F];
      v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v12);
    }
    else
    {
      v10 = 0.0;
    }
    v13 = v2->Result;
    if ( v13->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v13->T.Type = 3;
    v13->NV.NumberValue = v10;
  }
  else
  {
    v6 = v2->ThisPtr;
    if ( v6 )
      v3 = (Scaleform::GFx::AS2::Value *)&v6[-2];
    if ( v2->NArgs <= 0 )
    {
      v15.T.Type = 0;
      v8 = &v15;
      v9 = 2;
    }
    else
    {
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v2, 0);
      Scaleform::GFx::AS2::Value::Value(&v16, v7, (__int64)v2);
      v9 = 1;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v8, (__int64)v2);
    if ( v9 & 2 )
    {
      v9 &= 0xFDu;
      if ( v15.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v15);
    }
    if ( v9 & 1 && v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v3->T.Type + 24i64))(
      v3,
      v2->Env,
      &v);
    Scaleform::GFx::AS2::Value::operator=(v2->Result, &v, (__int64)v2);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
}

// File Line: 176
// RVA: 0x6E06D0
void __fastcall Scaleform::GFx::AS2::NumberCtorFunction::CreateNewObject(Scaleform::GFx::AS2::NumberCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::NumberObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::NumberObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::NumberCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                              this,
                                              112i64);
  if ( v3 )
    Scaleform::GFx::AS2::NumberObject::NumberObject(v3, v2);
}

// File Line: 182
// RVA: 0x70E290
Scaleform::GFx::AS2::FunctionRef *__usercall Scaleform::GFx::AS2::NumberCtorFunction::Register@<rax>(Scaleform::GFx::AS2::FunctionRef *result@<rcx>, Scaleform::GFx::AS2::GlobalContext *pgc@<rdx>, Scaleform::GFx::ASStringNode *a3@<xmm0>)
{
  Scaleform::GFx::AS2::GlobalContext *v3; // r14
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  Scaleform::GFx::AS2::NumberCtorFunction *v5; // rax
  __int64 v6; // rcx
  Scaleform::GFx::AS2::FunctionObject *v7; // rax
  __int64 v8; // rdi
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int v11; // eax
  signed __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h]
  __int64 flags; // [rsp+D0h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v22; // [rsp+D8h] [rbp+58h]

  v3 = pgc;
  v4 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v5 = (Scaleform::GFx::AS2::NumberCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                    result,
                                                    104i64,
                                                    0i64);
  flags = (__int64)v5;
  if ( v5 )
    Scaleform::GFx::AS2::NumberCtorFunction::NumberCtorFunction(v5, &psc, a3);
  else
    v7 = 0i64;
  v4->Flags = 0;
  v4->Function = v7;
  v4->pLocalFrame = 0i64;
  v22 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v3->pHeap;
  v8 = ((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v22->pObject->pWatchpoints)(v6, 176i64, 0i64);
  if ( v8 )
  {
    v9 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v3, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v8, &psc);
    *(_QWORD *)v8 = &Scaleform::GFx::AS2::NumberObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v8 + 32) = &Scaleform::GFx::AS2::NumberObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)(v8 + 96) = 0i64;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v8 + 104));
    if ( !*(_QWORD *)(v8 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v8 + 32) + 80i64))(
        v8 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        &objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
    v10 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v8 + 40);
    if ( v10 )
    {
      v11 = v10->RefCount;
      if ( v11 & 0x3FFFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    *(_QWORD *)(v8 + 40) = v9;
    v12 = v8 + 112;
    flags = v12;
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v12 + 24) = 0;
    *(_QWORD *)(v12 + 8) = 0i64;
    *(_QWORD *)(v12 + 16) = 0i64;
    *(_BYTE *)(v8 + 160) = 0;
    *(_QWORD *)(v8 + 144) = 0i64;
    *(_QWORD *)(v8 + 152) = 0i64;
    *(_QWORD *)(v8 + 168) = 0i64;
    *(_QWORD *)v8 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v8 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v8 + 112),
      (Scaleform::GFx::AS2::Object *)v8,
      &psc,
      v4);
    *(_QWORD *)v8 = &Scaleform::GFx::AS2::NumberProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v8 + 32) = &Scaleform::GFx::AS2::NumberProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_QWORD *)v12 = &Scaleform::GFx::AS2::NumberProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v8 + 112),
      (Scaleform::GFx::AS2::Object *)v8,
      &psc,
      NumberFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v8 = 0i64;
  }
  flags = v8;
  v22 = &objproto;
  if ( v8 )
    *(_DWORD *)(v8 + 24) = (*(_DWORD *)(v8 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v8;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v3,
    ASBuiltin_Number,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = v3->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  v14 = (Scaleform::GFx::ASStringNode *)v4->Function;
  v19.V.pStringNode = v14;
  if ( v14 )
  {
    ++v14->RefCount;
    v14->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  v15 = v4->pLocalFrame;
  if ( v15 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v19.NV.8,
      v15,
      v4->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v13->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v3->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v8 )
  {
    v16 = *(_DWORD *)(v8 + 24);
    if ( v16 & 0x3FFFFFF )
    {
      *(_DWORD *)(v8 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8);
    }
  }
  return v4;
}

