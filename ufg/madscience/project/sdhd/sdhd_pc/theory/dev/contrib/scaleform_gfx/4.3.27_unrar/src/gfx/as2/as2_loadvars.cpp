// File Line: 33
// RVA: 0x6C9FF0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v13; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_LoadVars);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  if ( this != (Scaleform::GFx::AS2::LoadVarsObject *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    &penv->StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface);
  this->BytesLoadedCurrent = -1.0;
  this->BytesLoadedTotal = -1.0;
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    penv,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->Scaleform::GFx::AS2::ObjectInterface);
  flags.Flags = 1;
  val.T.Type = 5;
  val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::Environment::CreateConstString(
                                                  penv,
                                                  &result,
                                                  "application/x-www-form-urlencoded")->pNode;
  ++val.V.pStringNode->RefCount;
  v5 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v13, "contentType");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v5,
    &val,
    &flags);
  pNode = v13.pNode;
  v7 = v13.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v8 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  flags.Flags = 1;
  val.T.Type = 0;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v13, "loaded");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    v9,
    &val,
    &flags);
  v10 = v13.pNode;
  v7 = v13.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 52
// RVA: 0x717860
bool __fastcall Scaleform::GFx::AS2::LoadVarsObject::SetMember(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Member value; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::PropFlags v10; // [rsp+70h] [rbp+8h] BYREF

  value.mValue.T = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::LoadVarsObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[1].~RefCountBaseGC<323>)(
         this,
         &penv->StringContext,
         name,
         &value) )
  {
    value.mValue.T.PropFlags = 0;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)&this->16,
      name,
      &value);
  }
  if ( value.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value.mValue);
  v10.Flags = 0;
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, &v10);
}

// File Line: 63
// RVA: 0x7039F0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::AS2::Value *pCurrent; // r9
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASString *v8; // rax
  int v9; // r8d
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS2::Value *v12; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h] BYREF
  int v14; // [rsp+30h] [rbp-28h]
  int v15; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::Value *v17; // [rsp+68h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = penv->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
  v17 = pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 5;
    pNode = src->pNode;
    pCurrent->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)src->pNode;
    ++pNode->RefCount;
  }
  if ( this )
    this = (Scaleform::GFx::AS2::LoadVarsObject *)((char *)this + 32);
  v8 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onData");
  v9 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( this )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v14 = 1;
    v15 = v9;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      (Scaleform::GFx::AS2::ObjectInterface *)this,
      v8,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v10 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v12 = penv->Stack.pCurrent;
  if ( v12->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v12);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
}

// File Line: 83
// RVA: 0x703CA0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::NotifyOnLoad(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        bool success)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  Scaleform::GFx::ASString *v7; // rax
  int v8; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h] BYREF
  int v13; // [rsp+30h] [rbp-28h]
  int v14; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::Value *v16; // [rsp+68h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = penv->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
  v16 = pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 2;
    pCurrent->V.BooleanValue = success;
  }
  if ( this )
    this = (Scaleform::GFx::AS2::LoadVarsObject *)((char *)this + 32);
  v7 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoad");
  v8 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( this )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v13 = 1;
    v14 = v8;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      (Scaleform::GFx::AS2::ObjectInterface *)this,
      v7,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = penv->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
}

// File Line: 110
// RVA: 0x6CA1B0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::LoadVarsProto(
        Scaleform::GFx::AS2::LoadVarsProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  __int64 v6; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-48h] BYREF
  __int64 v12; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::CFunctionObject *v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v14; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+88h] [rbp+10h] BYREF

  v12 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::LoadVarsObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::LoadVarsObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable;
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::LoadVarsProto::FunctionTable,
    &flags);
  flags.Flags = 1;
  v14.T.Type = 8;
  result.pNode = (Scaleform::GFx::ASStringNode *)psc->pContext->pHeap;
  v7 = (Scaleform::GFx::AS2::CFunctionObject *)(*((__int64 (__fastcall **)(__int64, __int64))result.pNode->pData + 10))(
                                                 v6,
                                                 104i64);
  v13 = v7;
  if ( v7 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v7, psc, Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData);
  v14.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v14.NV.Int32Value = (unsigned __int64)v7;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "onData");
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::LoadVarsObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v8,
    &v14,
    &flags);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
}

// File Line: 120
// RVA: 0x6B7800
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::AddRequestHeader(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
    if ( v3 )
    {
      messageType.Id = 212992;
      Scaleform::Log::LogMessageById(
        v3,
        (Scaleform::LogMessageId)&messageType,
        "LoadVars.addRequestHeader is not implemented.");
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 135
// RVA: 0x6B7880
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Decode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v5; // r14
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  const char *pData; // rdi
  unsigned int Length; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  if ( fn->NArgs > 0 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
    {
      v3 = fn->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = v3 - 2;
      else
        v5 = 0i64;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
      Scaleform::String::String(&punescapedStr);
      pData = result.pNode->pData;
      Length = Scaleform::GFx::ASConstString::GetLength(&result);
      Scaleform::GFx::ASUtils::Unescape(pData, Length, &punescapedStr);
      if ( v5 )
        v4 = v5 + 2;
      Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(fn->Env, v4, &punescapedStr);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "LoadVars");
    }
  }
}

// File Line: 151
// RVA: 0x6B79D0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::GetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  double v4; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v4 = *(double *)&v3[6].vfptr;
    Result = fn->Result;
    if ( v4 >= 0.0 )
    {
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->NV.NumberValue = v4;
      Result->T.Type = 3;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 168
// RVA: 0x6B7A70
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::GetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  double v4; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v4 = *(double *)&v3[6].pProto.pObject;
    Result = fn->Result;
    if ( v4 >= 0.0 )
    {
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->NV.NumberValue = v4;
      Result->T.Type = 3;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 185
// RVA: 0x6B7B10
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Load(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  if ( fn->NArgs )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
    {
      v4 = fn->ThisPtr;
      if ( v4 )
        v5 = v4 - 2;
      else
        v5 = 0i64;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
      v5[6].vfptr = 0i64;
      Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        (Scaleform::GFx::AS2::LoadVarsObject *)v5,
        result.pNode->pData,
        LM_None);
      v9 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v9);
      v9->T.Type = 2;
      v9->V.BooleanValue = 1;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid this is used for a method of %s class.\n",
        "LoadVars");
    }
  }
  else
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->T.Type = 2;
    v2->V.BooleanValue = 0;
  }
}

// File Line: 205
// RVA: 0x6B7D10
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Send(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
    if ( v3 )
    {
      messageType.Id = 212992;
      Scaleform::Log::LogMessageById(v3, (Scaleform::LogMessageId)&messageType, "LoadVars.send is not implemented.");
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 216
// RVA: 0x6B7D90
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::SendAndLoad(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
    if ( v3 )
    {
      messageType.Id = 212992;
      Scaleform::Log::LogMessageById(
        v3,
        (Scaleform::LogMessageId)&messageType,
        "LoadVars.sendAndLoad is not implemented.");
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 227
// RVA: 0x6B7F00
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rax
  unsigned __int64 Length; // rax
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  __int64 v12[4]; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::String str; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      v4 = v3 - 2;
    else
      v4 = 0i64;
    Scaleform::String::String(&str);
    Env = fn->Env;
    v12[0] = (__int64)&`Scaleform::GFx::AS2::LoadVarsProto::ToString::`7::MemberVisitor::`vftable;
    v12[1] = (__int64)Env;
    v12[2] = (__int64)&str;
    v4[2].vfptr->VisitMembers(
      v4 + 2,
      &fn->Env->StringContext,
      (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)v12,
      0,
      0i64);
    Length = Scaleform::String::GetLength(&str);
    Scaleform::String::Remove(&str, Length - 1, 1i64);
    v7 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, &str);
    v8 = fn->Result;
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->T.Type = 5;
    pNode = v7->pNode;
    v8->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v7->pNode;
    ++pNode->RefCount;
    v10 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v12[0] = (__int64)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 245
// RVA: 0x723800
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::ToString_::_7_::MemberVisitor::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::Value *flags)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::String pescapedStr; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+10h] BYREF

  Scaleform::StringBuffer::StringBuffer(&src, Scaleform::Memory::pGlobalHeap);
  Scaleform::String::String(&pescapedStr);
  Scaleform::GFx::ASUtils::Escape(
    **(const char ***)&val->T.Type,
    *(unsigned int *)(*(_QWORD *)&val->T.Type + 32i64),
    &pescapedStr);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::StringBuffer::AppendString(&src, "=", -1i64);
  Scaleform::String::Clear(&pescapedStr);
  Scaleform::GFx::AS2::Value::ToString(flags, &result, (Scaleform::GFx::AS2::Environment *)name[1].pNode, -1);
  Scaleform::GFx::ASUtils::Escape(result.pNode->pData, result.pNode->Size, &pescapedStr);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::StringBuffer::AppendString(&src, "&", -1i64);
  Scaleform::String::operator=((Scaleform::String *)name[2].pNode, &src);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&src);
}

// File Line: 271
// RVA: 0x6E1BF0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v4; // rsi
  Scaleform::GFx::AS2::LoadVarsObject *v5; // rbp
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  unsigned int v12; // r9d
  Scaleform::GFx::AS2::Environment *v13; // r8
  Scaleform::GFx::AS2::Value *v14; // r10
  Scaleform::GFx::ASString *v15; // rax
  bool v16; // al
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::String data; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v20; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::String v21; // [rsp+78h] [rbp+20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::AS2::LoadVarsObject *)&v3[-2];
    else
      v5 = 0i64;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
    Scaleform::String::String(&v21, v9->pNode->pData);
    pNode = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = fn->FirstArgBottomIndex;
    v13 = fn->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = Scaleform::GFx::AS2::Value::ToString(v14, &v20, v13, -1);
    Scaleform::String::String(&data, v15->pNode->pData);
    if ( v5 )
      v4 = &v5->Scaleform::GFx::AS2::ObjectInterface;
    v16 = Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(fn->Env, v4, &data);
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnLoad(v5, fn->Env, v16);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((data.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v17 = v20.pNode;
    v11 = v20.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v21.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 284
// RVA: 0x701F30
__int64 __fastcall Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pchar,
        Scaleform::String *data)
{
  unsigned __int8 v6; // bl
  char v7; // bl
  unsigned int FirstCharAt; // eax
  char *v9; // r14
  char *pData; // r8
  Scaleform::GFx::ASString *v11; // rax
  char *v12; // r8
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::StringBuffer *v17; // rcx
  char *v18; // r8
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::Value v25; // [rsp+38h] [rbp-61h] BYREF
  char *offset; // [rsp+58h] [rbp-41h] BYREF
  Scaleform::StringBuffer v27; // [rsp+60h] [rbp-39h] BYREF
  Scaleform::StringBuffer v28; // [rsp+90h] [rbp-9h] BYREF
  __int64 v29; // [rsp+C0h] [rbp+27h]
  char v30; // [rsp+110h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v31; // [rsp+118h] [rbp+7Fh] BYREF

  v29 = -2i64;
  Scaleform::StringBuffer::StringBuffer(&v27, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&v28, Scaleform::Memory::pGlobalHeap);
  if ( (*(_QWORD *)(data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    v6 = 0;
    goto LABEL_37;
  }
  v7 = 1;
  FirstCharAt = Scaleform::String::GetFirstCharAt(data, 0i64, (const char **)&offset);
  v9 = &customCaption;
  if ( FirstCharAt )
  {
    while ( 1 )
    {
      if ( FirstCharAt == 13 )
      {
        FirstCharAt = 10;
      }
      else if ( FirstCharAt == 38 )
      {
        pData = &customCaption;
        if ( v28.pData )
          pData = v28.pData;
        v11 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, pData, v28.Size);
        v25.T.Type = 5;
        v25.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
        ++v25.V.pStringNode->RefCount;
        v12 = &customCaption;
        if ( v27.pData )
          v12 = v27.pData;
        v13 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v31, v12, v27.Size);
        v30 = 0;
        pchar->vfptr->SetMember(pchar, penv, v13, &v25, (Scaleform::GFx::AS2::PropFlags *)&v30);
        pNode = v31.pNode;
        v15 = v31.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v25.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v25);
        v16 = result.pNode;
        v15 = result.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        Scaleform::StringBuffer::Clear(&v27);
        Scaleform::StringBuffer::Clear(&v28);
        v7 = 1;
        goto LABEL_24;
      }
      if ( !v7 )
        break;
      if ( FirstCharAt != 61 )
      {
        v17 = &v27;
LABEL_23:
        Scaleform::StringBuffer::AppendChar(v17, FirstCharAt);
        goto LABEL_24;
      }
      v7 = 0;
LABEL_24:
      FirstCharAt = Scaleform::String::GetNextChar(data, (const char **)&offset);
      if ( !FirstCharAt )
        goto LABEL_25;
    }
    v17 = &v28;
    goto LABEL_23;
  }
LABEL_25:
  if ( Scaleform::StringBuffer::GetLength(&v27) )
  {
    v18 = &customCaption;
    if ( v28.pData )
      v18 = v28.pData;
    v19 = Scaleform::GFx::AS2::Environment::CreateString(penv, &result, v18, v28.Size);
    v25.T.Type = 5;
    v25.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v19->pNode;
    ++v25.V.pStringNode->RefCount;
    if ( v27.pData )
      v9 = v27.pData;
    v20 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v31, v9, v27.Size);
    v30 = 0;
    pchar->vfptr->SetMember(pchar, penv, v20, &v25, (Scaleform::GFx::AS2::PropFlags *)&v30);
    v21 = v31.pNode;
    v15 = v31.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    v22 = result.pNode;
    v15 = result.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  v6 = 1;
LABEL_37:
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v28);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v27);
  return v6;
}

// File Line: 345
// RVA: 0x6F9630
void __fastcall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 27
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v3 = fn->ThisPtr;
    if ( v3 )
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&v3[-2]);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0i64);
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 1;
  }
}

// File Line: 357
// RVA: 0x6E05E0
void __fastcall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::LoadVarsObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::LoadVarsObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                this,
                                                112i64);
  if ( v3 )
    Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(v3, penv);
}

// File Line: 362
// RVA: 0x70D870
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LoadVarsProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_objproto; // [rsp+C8h] [rbp+50h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  pHeap = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))pHeap->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  p_objproto = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::LoadVarsProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                               pObject,
                                               176i64,
                                               0i64);
  pHeap = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::LoadVarsProto::LoadVarsProto(v9, &psc, v10, result);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v12;
  p_objproto = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_LoadVars,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = pgc->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v19.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v19.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v13->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[14],
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v12 )
  {
    v16 = v12->RefCount;
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      v12->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
    }
  }
  return result;
}

