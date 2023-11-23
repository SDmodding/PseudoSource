// File Line: 25
// RVA: 0x6C7A50
void __fastcall Scaleform::GFx::AS2::BooleanObject::BooleanObject(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->bValue = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Boolean);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 41
// RVA: 0x6F69D0
const char *__fastcall Scaleform::GFx::AS2::BooleanObject::GetTextValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *__formal)
{
  const char *result; // rax

  result = "false";
  if ( LOBYTE(this->ResolveHandler.pLocalFrame) )
    return "true";
  return result;
}

// File Line: 71
// RVA: 0x71D150
void __fastcall Scaleform::GFx::AS2::BooleanObject::SetValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  this->bValue = Scaleform::GFx::AS2::Value::ToBool(v, penv);
}

// File Line: 76
// RVA: 0x6F72B0
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::BooleanObject::GetValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  bool bValue; // al

  bValue = this->bValue;
  result->T.Type = 2;
  result->V.BooleanValue = bValue;
  return result;
}

// File Line: 82
// RVA: 0x6B49E0
void __fastcall Scaleform::GFx::AS2::GAS_BooleanToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 10 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Value *))v4->vfptr->GetMember)(
                                         v4,
                                         &v11);
    v6 = Scaleform::GFx::AS2::Value::ToString(v5, &result, fn->Env, -1);
    v7 = fn->Result;
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 5;
    pNode = v6->pNode;
    v7->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
    ++pNode->RefCount;
    v9 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( v11.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v11);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Boolean");
  }
}

// File Line: 91
// RVA: 0x6B4AB0
void __fastcall Scaleform::GFx::AS2::GAS_BooleanValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  Scaleform::GFx::AS2::Value *v5; // rax
  bool v6; // di
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-30h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 10 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    v5 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Value *))v4->vfptr->GetMember)(
                                         v4,
                                         &v8);
    v6 = Scaleform::GFx::AS2::Value::ToBool(v5, fn->Env);
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v6;
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "Boolean");
  }
}

// File Line: 120
// RVA: 0x6E0350
void __fastcall Scaleform::GFx::AS2::BooleanCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::BooleanCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::BooleanObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::BooleanObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::BooleanCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               104i64);
  if ( v3 )
    Scaleform::GFx::AS2::BooleanObject::BooleanObject(v3, penv);
}

// File Line: 125
// RVA: 0x6F8E50
void __fastcall Scaleform::GFx::AS2::BooleanCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rdi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rax
  char v7; // bl
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::GFx::AS2::Value v12; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+70h] [rbp-28h] BYREF

  v2 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 10
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
      v2 = (Scaleform::GFx::AS2::Value *)&v4[-2];
    if ( fn->NArgs <= 0 )
    {
      v12.T.Type = 0;
      v6 = &v12;
      v7 = 2;
    }
    else
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::Value(&v13, v5->Values);
      v7 = 1;
    }
    Scaleform::GFx::AS2::Value::Value(&v, v6);
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      if ( v12.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v12);
    }
    if ( (v7 & 1) != 0 && v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
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
      LOBYTE(v2) = Scaleform::GFx::AS2::Value::ToBool(v2, Env);
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = (char)v2;
    Result->T.Type = 2;
  }
}

// File Line: 144
// RVA: 0x70CAC0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::BooleanCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment> *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rsi
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment> *flags; // [rsp+B8h] [rbp+40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+C0h] [rbp+48h]
  __int64 *p_flags; // [rsp+C8h] [rbp+50h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  pHeap = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))pHeap->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  p_flags = (__int64 *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::BooleanCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v17.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v17,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v6->pProto.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v6->pProto.pObject = Prototype;
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment> *)pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)pObject, 168ui64, 0i64);
  p_flags = (__int64 *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment>(
      v9,
      &psc,
      v10,
      result);
    v9->Scaleform::GFx::AS2::BooleanObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v9->Scaleform::GFx::AS2::BooleanObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v9->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::BooleanProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v9->Scaleform::GFx::AS2::GASPrototypeBase,
      v9,
      &psc,
      GAS_BooleanFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v9 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v9;
  p_flags = (__int64 *)&flags;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  flags = v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Boolean,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v11 = pgc->pGlobal.pObject;
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
  LOBYTE(flags) = 0;
  v11->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v11->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[8].AVMVersion,
    &v17,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  if ( v9 )
  {
    v14 = v9->RefCount;
    if ( (v14 & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = v14 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  return result;
}

