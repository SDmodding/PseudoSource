// File Line: 25
// RVA: 0x6C7A50
void __fastcall Scaleform::GFx::AS2::BooleanObject::BooleanObject(Scaleform::GFx::AS2::BooleanObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::BooleanObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->bValue = 0;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Boolean);
  v3->vfptr->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 41
// RVA: 0x6F69D0
const char *__fastcall Scaleform::GFx::AS2::BooleanObject::GetTextValue(Scaleform::GFx::AS2::BooleanObject *this, Scaleform::GFx::AS2::Environment *__formal)
{
  const char *result; // rax

  result = "false";
  if ( LOBYTE(this->ResolveHandler.pLocalFrame) )
    result = "true";
  return result;
}

// File Line: 71
// RVA: 0x71D150
void __fastcall Scaleform::GFx::AS2::BooleanObject::SetValue(Scaleform::GFx::AS2::BooleanObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  this->bValue = Scaleform::GFx::AS2::Value::ToBool(v, penv);
}

// File Line: 76
// RVA: 0x6F72B0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::BooleanObject::GetValue(Scaleform::GFx::AS2::BooleanObject *this, Scaleform::GFx::AS2::Value *result)
{
  bool v2; // al

  v2 = this->bValue;
  result->T.Type = 2;
  result->V.BooleanValue = v2;
  return result;
}

// File Line: 82
// RVA: 0x6B49E0
void __fastcall Scaleform::GFx::AS2::GAS_BooleanToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 10 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)(*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v4 + 32i64))(
                                         v4,
                                         &v11);
    v6 = Scaleform::GFx::AS2::Value::ToString(v5, &result, v1->Env, -1);
    v7 = v1->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    v8 = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++v8->RefCount;
    v9 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( v11.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v11);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Boolean");
  }
}

// File Line: 91
// RVA: 0x6B4AB0
void __fastcall Scaleform::GFx::AS2::GAS_BooleanValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  bool v6; // di
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-30h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 10 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)(*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v4 + 32i64))(
                                         v4,
                                         &v8);
    v6 = Scaleform::GFx::AS2::Value::ToBool(v5, v1->Env);
    v7 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 2;
    v7->V.BooleanValue = v6;
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Boolean");
  }
}

// File Line: 120
// RVA: 0x6E0350
void __fastcall Scaleform::GFx::AS2::BooleanCtorFunction::CreateNewObject(Scaleform::GFx::AS2::BooleanCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::BooleanObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::BooleanObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::BooleanCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               104i64);
  if ( v3 )
    Scaleform::GFx::AS2::BooleanObject::BooleanObject(v3, v2);
}

// File Line: 125
// RVA: 0x6F8E50
void __fastcall Scaleform::GFx::AS2::BooleanCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn, __int64 a2)
{
  Scaleform::GFx::AS2::FnCall *v2; // rsi
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  __int64 v5; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::Value *v7; // rax
  Scaleform::GFx::AS2::Value *v8; // rax
  char v9; // bl
  unsigned __int64 v10; // r8
  Scaleform::GFx::AS2::Environment *v11; // rdx
  Scaleform::GFx::AS2::Value *v12; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::AS2::Value v15; // [rsp+70h] [rbp-28h]

  v2 = fn;
  v3 = 0i64;
  v4 = fn->ThisPtr;
  if ( !v4
    || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *, __int64))&v4->vfptr->gap8[8])(v4, a2) != 10
    || ((unsigned __int8 (__cdecl *)(Scaleform::GFx::AS2::ObjectInterface *, __int64))v2->ThisPtr->vfptr->IsBuiltinPrototype)(
         v2->ThisPtr,
         v5) )
  {
    if ( v2->NArgs )
    {
      v10 = (unsigned int)v2->FirstArgBottomIndex;
      v11 = v2->Env;
      if ( (unsigned int)v10 <= 32 * (LODWORD(v11->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v3 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v2->FirstArgBottomIndex & 0x1F];
      LOBYTE(v3) = Scaleform::GFx::AS2::Value::ToBool(v3, v11);
    }
    v12 = v2->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v12->V.BooleanValue = (char)v3;
    v12->T.Type = 2;
  }
  else
  {
    v6 = v2->ThisPtr;
    if ( v6 )
      v3 = (Scaleform::GFx::AS2::Value *)&v6[-2];
    if ( v2->NArgs <= 0 )
    {
      v14.T.Type = 0;
      v8 = &v14;
      v9 = 2;
    }
    else
    {
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v2, 0);
      Scaleform::GFx::AS2::Value::Value(&v15, v7, (__int64)v3);
      v9 = 1;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v8, (__int64)v3);
    if ( v9 & 2 )
    {
      v9 &= 0xFDu;
      if ( v14.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v14);
    }
    if ( v9 & 1 && v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    (*(void (__fastcall **)(Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v3->T.Type + 24i64))(
      v3,
      v2->Env,
      &v);
    Scaleform::GFx::AS2::Value::operator=(v2->Result, &v, (__int64)v3);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
}

// File Line: 144
// RVA: 0x70CAC0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::BooleanCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment> *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::AS2::LocalFrame *v13; // rdx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-28h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v19; // [rsp+C0h] [rbp+48h]
  Scaleform::GFx::AS2::PropFlags *v20; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v19 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v19->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v20 = (Scaleform::GFx::AS2::PropFlags *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::BooleanCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      flags.Flags = 3;
      v17.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v17,
        &flags);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->pProto.pObject->vfptr;
    if ( v5 )
    {
      v8 = v5->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v5->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v6->pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  v19 = v2->pHeap;
  v9 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment> *)v19->vfptr->Alloc((Scaleform::MemoryHeap *)v5, 168ui64, 0i64);
  v20 = (Scaleform::GFx::AS2::PropFlags *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment>(
      v9,
      &psc,
      v10,
      v3);
    v9->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v9->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v9->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable;
    flags.Flags = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v9->vfptr,
      (Scaleform::GFx::AS2::Object *)&v9->vfptr,
      &psc,
      GAS_BooleanFunctionTable,
      &flags);
  }
  else
  {
    v9 = 0i64;
  }
  v19 = (Scaleform::MemoryHeap *)v9;
  v20 = &flags;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  *(_QWORD *)&flags.Flags = v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Boolean,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v11 = v2->pGlobal.pObject;
  v17.T.Type = 8;
  v17.V.FunctionValue.Flags = 0;
  v12 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v17.V.pStringNode = v12;
  if ( v12 )
  {
    ++v12->RefCount;
    v12->RefCount &= 0x8FFFFFFF;
  }
  v17.V.FunctionValue.pLocalFrame = 0i64;
  v13 = v3->pLocalFrame;
  if ( v13 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v17.NV.8,
      v13,
      v3->Flags & 1);
  flags.Flags = 0;
  v11->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v11->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[8].AVMVersion,
    &v17,
    &flags);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  if ( v9 )
  {
    v14 = v9->RefCount;
    if ( v14 & 0x3FFFFFF )
    {
      v9->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
    }
  }
  return v3;
}

