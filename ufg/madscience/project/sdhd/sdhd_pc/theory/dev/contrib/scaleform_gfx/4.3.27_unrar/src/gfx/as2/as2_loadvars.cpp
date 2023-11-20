// File Line: 33
// RVA: 0x6C9FF0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(Scaleform::GFx::AS2::LoadVarsObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbp
  Scaleform::GFx::AS2::LoadVarsObject *v3; // rbx
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::ASString v13; // [rsp+A0h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+20h]

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_LoadVars);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
  if ( v3 != (Scaleform::GFx::AS2::LoadVarsObject *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      &v2->StringContext,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    &v2->StringContext,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
  v3->BytesLoadedCurrent = -1.0;
  v3->BytesLoadedTotal = -1.0;
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    v2,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
  flags.Flags = 1;
  val.T.Type = 5;
  val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)Scaleform::GFx::AS2::Environment::CreateConstString(
                                                  v2,
                                                  &result,
                                                  "application/x-www-form-urlencoded")->pNode;
  ++val.V.pStringNode->RefCount;
  v5 = Scaleform::GFx::AS2::Environment::CreateConstString(v2, &v13, "contentType");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&v3->vfptr,
    &v2->StringContext,
    v5,
    &val,
    &flags);
  v6 = v13.pNode;
  v7 = v13.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v8 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  flags.Flags = 1;
  val.T.Type = 0;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v2, &v13, "loaded");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&v3->vfptr,
    &v2->StringContext,
    v9,
    &val,
    &flags);
  v10 = v13.pNode;
  v7 = v13.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 52
// RVA: 0x717860
bool __fastcall Scaleform::GFx::AS2::LoadVarsObject::SetMember(Scaleform::GFx::AS2::LoadVarsObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbp
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::LoadVarsObject *v7; // rbx
  Scaleform::GFx::AS2::Member value; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS2::PropFlags v10; // [rsp+70h] [rbp+8h]

  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  value.mValue.T = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::LoadVarsObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))this->vfptr[1].~RefCountBaseGC<323>)(
         this,
         &penv->StringContext,
         name,
         &value) )
  {
    value.mValue.T.PropFlags = 0;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Sc)&v7->16,
      v5,
      &value);
  }
  if ( value.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value.mValue);
  v10.Flags = 0;
  return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v7->vfptr, v6, v5, v4, &v10);
}

// File Line: 63
// RVA: 0x7039F0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData(Scaleform::GFx::AS2::LoadVarsObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *src)
{
  Scaleform::GFx::ASString *v3; // r14
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // r9
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  int v9; // er8
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS2::Value *v12; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h]
  int v14; // [rsp+30h] [rbp-28h]
  int v15; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+68h] [rbp+10h]

  v3 = src;
  v4 = penv;
  v5 = (Scaleform::GFx::AS2::ObjectInterface *)this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v6 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v6;
  v17 = v6;
  if ( v6 )
  {
    LOBYTE(v6->pData) = 5;
    v7 = v3->pNode;
    v6->pManager = (Scaleform::GFx::ASStringManager *)v3->pNode;
    ++v7->RefCount;
  }
  if ( v5 )
    v5 += 2;
  v8 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onData");
  v9 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v5 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v14 = 1;
    v15 = v9;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v4, v5, v8, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v12 = v4->Stack.pCurrent;
  if ( v12->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v12);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
}

// File Line: 83
// RVA: 0x703CA0
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::NotifyOnLoad(Scaleform::GFx::AS2::LoadVarsObject *this, Scaleform::GFx::AS2::Environment *penv, bool success)
{
  bool v3; // bp
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  __int64 v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  int v8; // er8
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h]
  int v13; // [rsp+30h] [rbp-28h]
  int v14; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  __int64 v16; // [rsp+68h] [rbp+10h]

  v3 = success;
  v4 = penv;
  v5 = (Scaleform::GFx::AS2::ObjectInterface *)this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v6 = (__int64)v4->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)v6;
  v16 = v6;
  if ( v6 )
  {
    *(_BYTE *)v6 = 2;
    *(_BYTE *)(v6 + 8) = v3;
  }
  if ( v5 )
    v5 += 2;
  v7 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onLoad");
  v8 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v5 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v13 = 1;
    v14 = v8;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v4, v5, v7, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v11 = v4->Stack.pCurrent;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v11);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
}

// File Line: 110
// RVA: 0x6CA1B0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::LoadVarsProto(Scaleform::GFx::AS2::LoadVarsProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::LoadVarsProto *v5; // rbx
  __int64 v6; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-48h]
  __int64 v12; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::CFunctionObject *v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v14; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+88h] [rbp+10h]

  v12 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    pprototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable';
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::LoadVarsProto::FunctionTable,
    &flags);
  flags.Flags = 1;
  v14.T.Type = 8;
  result.pNode = (Scaleform::GFx::ASStringNode *)v4->pContext->pHeap;
  v7 = (Scaleform::GFx::AS2::CFunctionObject *)(*((__int64 (__fastcall **)(__int64, signed __int64))result.pNode->pData
                                                + 10))(
                                                 v6,
                                                 104i64);
  v13 = v7;
  if ( v7 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v7, v4, Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData);
  v14.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v14.NV.Int32Value = (unsigned __int64)v7;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "onData");
  v5->vfptr->SetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr, v4, v8, &v14, &flags);
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
}

// File Line: 120
// RVA: 0x6B7800
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::AddRequestHeader(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
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
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 135
// RVA: 0x6B7880
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Decode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbp
  signed __int64 v5; // r14
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  const char *v9; // rdi
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::String punescapedStr; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v1 = fn;
  if ( fn->NArgs > 0 )
  {
    v2 = fn->ThisPtr;
    if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 27 )
    {
      v3 = v1->ThisPtr;
      v4 = 0i64;
      if ( v3 )
        v5 = (signed __int64)&v3[-2];
      else
        v5 = 0i64;
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
      Scaleform::String::String(&punescapedStr);
      v9 = result.pNode->pData;
      v10 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
      Scaleform::GFx::ASUtils::Unescape(v9, v10, &punescapedStr);
      if ( v5 )
        v4 = (Scaleform::GFx::AS2::ObjectInterface *)(v5 + 32);
      Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v1->Env, v4, &punescapedStr);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v11 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "LoadVars");
    }
  }
}

// File Line: 151
// RVA: 0x6B79D0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::GetBytesLoaded(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  double v4; // xmm6_8
  Scaleform::GFx::AS2::Value *v5; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v4 = *(double *)&v3[6].vfptr;
    v5 = v1->Result;
    if ( v4 >= 0.0 )
    {
      if ( v5->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->NV.NumberValue = v4;
      v5->T.Type = 3;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 168
// RVA: 0x6B7A70
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::GetBytesTotal(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  double v4; // xmm6_8
  Scaleform::GFx::AS2::Value *v5; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v3 -= 2;
    v4 = *(double *)&v3[6].pProto.pObject;
    v5 = v1->Result;
    if ( v4 >= 0.0 )
    {
      if ( v5->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->NV.NumberValue = v4;
      v5->T.Type = 3;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(v5);
      v5->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 185
// RVA: 0x6B7B10
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Load(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  signed __int64 v5; // rdi
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  if ( fn->NArgs )
  {
    v3 = fn->ThisPtr;
    if ( v3 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) == 27 )
    {
      v4 = v1->ThisPtr;
      if ( v4 )
        v5 = (signed __int64)&v4[-2];
      else
        v5 = 0i64;
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
      *(_QWORD *)(v5 + 96) = 0i64;
      Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        (Scaleform::GFx::AS2::LoadVarsObject *)v5,
        result.pNode->pData,
        0);
      v9 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v9);
      v9->T.Type = 2;
      v9->V.BooleanValue = 1;
      v10 = result.pNode;
      v11 = result.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "LoadVars");
    }
  }
  else
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v2->T.Type = 2;
    v2->V.BooleanValue = 0;
  }
}

// File Line: 205
// RVA: 0x6B7D10
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::Send(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
    if ( v3 )
    {
      messageType.Id = 212992;
      Scaleform::Log::LogMessageById(v3, (Scaleform::LogMessageId)&messageType, "LoadVars.send is not implemented.");
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 216
// RVA: 0x6B7D90
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::SendAndLoad(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::LogState *v3; // rax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
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
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 227
// RVA: 0x6B7F00
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  signed __int64 v4; // rdi
  __int64 v5; // rax
  unsigned __int64 v6; // rax
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  void **v12; // [rsp+38h] [rbp-20h]
  __int64 v13; // [rsp+40h] [rbp-18h]
  Scaleform::String *v14; // [rsp+48h] [rbp-10h]
  Scaleform::String str; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 27 )
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      v4 = (signed __int64)&v3[-2];
    else
      v4 = 0i64;
    Scaleform::String::String(&str);
    v5 = (__int64)v1->Env;
    v12 = (void **)&`Scaleform::GFx::AS2::LoadVarsProto::ToString'::`7'::MemberVisitor::`vftable';
    v13 = v5;
    v14 = &str;
    (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, void ***, _QWORD, _QWORD))(*(_QWORD *)(v4 + 32) + 64i64))(
      v4 + 32,
      &v1->Env->StringContext,
      &v12,
      0i64,
      0i64);
    v6 = Scaleform::String::GetLength(&str);
    Scaleform::String::Remove(&str, v6 - 1, 1i64);
    v7 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, &str);
    v8 = v1->Result;
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->T.Type = 5;
    v9 = v7->pNode;
    v8->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v7->pNode;
    ++v9->RefCount;
    v10 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v12 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
    if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 245
// RVA: 0x723800
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::ToString_::_7_::MemberVisitor::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, __int64 flags)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  const char ***v4; // rbx
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-50h]
  Scaleform::String pescapedStr; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+10h]

  v3 = (Scaleform::GFx::AS2::Value *)flags;
  v4 = (const char ***)val;
  v5 = name;
  Scaleform::StringBuffer::StringBuffer(&src, Scaleform::Memory::pGlobalHeap);
  Scaleform::String::String(&pescapedStr);
  Scaleform::GFx::ASUtils::Escape(**v4, *((unsigned int *)*v4 + 8), &pescapedStr);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::StringBuffer::AppendString(&src, "=", -1i64);
  Scaleform::String::Clear(&pescapedStr);
  Scaleform::GFx::AS2::Value::ToString(v3, &result, (Scaleform::GFx::AS2::Environment *)v5[1].pNode, -1);
  Scaleform::GFx::ASUtils::Escape(result.pNode->pData, result.pNode->Size, &pescapedStr);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const char *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::StringBuffer::AppendString(&src, "&", -1i64);
  Scaleform::String::operator=((Scaleform::String *)v5[2].pNode, &src);
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((pescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&src);
}

// File Line: 271
// RVA: 0x6E1BF0
void __fastcall Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v4; // rsi
  Scaleform::GFx::AS2::LoadVarsObject *v5; // rbp
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  const char ***v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned int v12; // er9
  Scaleform::GFx::AS2::Environment *v13; // r8
  Scaleform::GFx::AS2::Value *v14; // r10
  const char ***v15; // rax
  bool v16; // al
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::String data; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString v20; // [rsp+70h] [rbp+18h]
  Scaleform::String v21; // [rsp+78h] [rbp+20h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 27 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
      v5 = (Scaleform::GFx::AS2::LoadVarsObject *)&v3[-2];
    else
      v5 = 0i64;
    v6 = v1->FirstArgBottomIndex;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
    Scaleform::String::String(&v21, **v9);
    v10 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v12 = v1->FirstArgBottomIndex;
    v13 = v1->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v14, &v20, v13, -1);
    Scaleform::String::String(&data, **v15);
    if ( v5 )
      v4 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
    v16 = Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v1->Env, v4, &data);
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnLoad(v5, v1->Env, v16);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((data.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v17 = v20.pNode;
    v11 = v20.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v21.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}

// File Line: 284
// RVA: 0x701F30
__int64 __fastcall Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pchar, Scaleform::String *data)
{
  Scaleform::String *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v4; // r15
  Scaleform::GFx::AS2::Environment *v5; // rsi
  unsigned __int8 v6; // bl
  char v7; // bl
  unsigned int v8; // eax
  char *v9; // r14
  char *v10; // r8
  Scaleform::GFx::ASString *v11; // rax
  char *v12; // r8
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::StringBuffer *v17; // rcx
  char *v18; // r8
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::AS2::Value v25; // [rsp+38h] [rbp-61h]
  char *offset; // [rsp+58h] [rbp-41h]
  Scaleform::StringBuffer v27; // [rsp+60h] [rbp-39h]
  Scaleform::StringBuffer v28; // [rsp+90h] [rbp-9h]
  __int64 v29; // [rsp+C0h] [rbp+27h]
  char v30; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::ASString v31; // [rsp+118h] [rbp+7Fh]

  v29 = -2i64;
  v3 = data;
  v4 = pchar;
  v5 = penv;
  Scaleform::StringBuffer::StringBuffer(&v27, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&v28, Scaleform::Memory::pGlobalHeap);
  if ( !(*(_QWORD *)(v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) )
  {
    v6 = 0;
    goto LABEL_37;
  }
  v7 = 1;
  v8 = Scaleform::String::GetFirstCharAt(v3, 0i64, (const char **)&offset);
  v9 = &customWorldMapCaption;
  if ( v8 )
  {
    while ( 1 )
    {
      if ( v8 == 13 )
      {
        v8 = 10;
      }
      else if ( v8 == 38 )
      {
        v10 = &customWorldMapCaption;
        if ( v28.pData )
          v10 = v28.pData;
        v11 = Scaleform::GFx::AS2::Environment::CreateString(v5, &result, v10, v28.Size);
        v25.T.Type = 5;
        v25.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
        ++v25.V.pStringNode->RefCount;
        v12 = &customWorldMapCaption;
        if ( v27.pData )
          v12 = v27.pData;
        v13 = Scaleform::GFx::AS2::Environment::CreateString(v5, &v31, v12, v27.Size);
        v30 = 0;
        v4->vfptr->SetMember(v4, v5, v13, &v25, (Scaleform::GFx::AS2::PropFlags *)&v30);
        v14 = v31.pNode;
        v15 = v31.pNode->RefCount == 1;
        --v14->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        if ( v25.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v25);
        v16 = result.pNode;
        v15 = result.pNode->RefCount == 1;
        --v16->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        Scaleform::StringBuffer::Clear(&v27);
        Scaleform::StringBuffer::Clear(&v28);
        v7 = 1;
        goto LABEL_24;
      }
      if ( !v7 )
        break;
      if ( v8 != 61 )
      {
        v17 = &v27;
LABEL_23:
        Scaleform::StringBuffer::AppendChar(v17, v8);
        goto LABEL_24;
      }
      v7 = 0;
LABEL_24:
      v8 = Scaleform::String::GetNextChar(v3, (const char **)&offset);
      if ( !v8 )
        goto LABEL_25;
    }
    v17 = &v28;
    goto LABEL_23;
  }
LABEL_25:
  if ( Scaleform::StringBuffer::GetLength(&v27) )
  {
    v18 = &customWorldMapCaption;
    if ( v28.pData )
      v18 = v28.pData;
    v19 = Scaleform::GFx::AS2::Environment::CreateString(v5, &result, v18, v28.Size);
    v25.T.Type = 5;
    v25.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v19->pNode;
    ++v25.V.pStringNode->RefCount;
    if ( v27.pData )
      v9 = v27.pData;
    v20 = Scaleform::GFx::AS2::Environment::CreateString(v5, &v31, v9, v27.Size);
    v30 = 0;
    v4->vfptr->SetMember(v4, v5, v20, &v25, (Scaleform::GFx::AS2::PropFlags *)&v30);
    v21 = v31.pNode;
    v15 = v31.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    if ( v25.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v25);
    v22 = result.pNode;
    v15 = result.pNode->RefCount == 1;
    --v22->RefCount;
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2
    || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 27
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v4 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 1;
  }
  else
  {
    v3 = v1->ThisPtr;
    if ( v3 )
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v3[-2]);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, 0i64);
  }
}

// File Line: 357
// RVA: 0x6E05E0
void __fastcall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::CreateNewObject(Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::LoadVarsObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::LoadVarsObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                this,
                                                112i64);
  if ( v3 )
    Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(v3, v2);
}

// File Line: 362
// RVA: 0x70D870
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::LoadVarsProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v21; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v22; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v21 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v21->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v22 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
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
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v9 = (Scaleform::GFx::AS2::LoadVarsProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                               v5,
                                               176i64,
                                               0i64);
  v21 = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::LoadVarsProto::LoadVarsProto(v9, &psc, v10, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v21 = (Scaleform::MemoryHeap *)v12;
  v22 = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_LoadVars,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = v2->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  v14 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v19.V.pStringNode = v14;
  if ( v14 )
  {
    ++v14->RefCount;
    v14->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  v15 = v3->pLocalFrame;
  if ( v15 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v19.NV.8,
      v15,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v13->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[14],
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v12 )
  {
    v16 = v12->RefCount;
    if ( v16 & 0x3FFFFFF )
    {
      v12->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
    }
  }
  return v3;
}

