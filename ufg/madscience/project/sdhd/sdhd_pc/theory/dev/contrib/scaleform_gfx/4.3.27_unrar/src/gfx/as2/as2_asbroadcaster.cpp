// File Line: 29
// RVA: 0x6C72E0
void __fastcall Scaleform::GFx::AS2::AsBroadcaster::AsBroadcaster(
        Scaleform::GFx::AS2::AsBroadcaster *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsBroadcaster::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_AsBroadcaster);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 41
// RVA: 0x6A8CA0
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::AddListener(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, Env);
    Scaleform::GFx::AS2::AsBroadcaster::AddListener(fn->Env, fn->ThisPtr, v5);
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 1;
  }
}

// File Line: 53
// RVA: 0x6A8D20
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::BroadcastMessage(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // r10
  int v6; // r8d
  int v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdx
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-20h] BYREF
  int v13; // [rsp+30h] [rbp-18h]
  int v14; // [rsp+34h] [rbp-14h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
    v5 = fn->Env;
    v6 = v5->Stack.pCurrent - v5->Stack.pPageStart + 32 * v5->Stack.Pages.Data.Size - 36;
    v7 = fn->NArgs - 1;
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      v13 = v7;
      v14 = v6;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v5, ThisPtr, &result, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    v9 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->T.Type = 0;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 65
// RVA: 0x6A8E20
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::RemoveListener(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  bool v6; // al
  Scaleform::GFx::AS2::Value *Result; // rbx
  bool v8; // di

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, Env);
    v6 = Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(fn->Env, fn->ThisPtr, v5);
    Result = fn->Result;
    v8 = v6;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v8;
    Result->T.Type = 2;
  }
}

// File Line: 105
// RVA: 0x6A9FE0
void __fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Initialize(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::AS2::Environment *v8; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, Env);
    Result = fn->Result;
    v7 = v5;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
    v8 = fn->Env;
    if ( v7 )
      Scaleform::GFx::AS2::NameFunction::AddConstMembers(v7, &v8->StringContext, GAS_AsBcFunctionTable, 1);
    Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(&v8->StringContext, v7);
  }
}

// File Line: 128
// RVA: 0x6FD5F0
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
        Scaleform::MemoryHeap *psc,
        Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  Scaleform::GFx::AS2::ArrayObject *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::GFx::AS2::Value *v8; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v10; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *SetLimit; // [rsp+78h] [rbp+10h] BYREF
  void *v12; // [rsp+80h] [rbp+18h]

  if ( !pobj )
    return 0;
  SetLimit = (Scaleform::MemoryHeap *)psc->vfptr->SetLimit;
  v5 = (Scaleform::GFx::AS2::ArrayObject *)SetLimit->vfptr->Alloc(psc, 144ui64, 0i64);
  v12 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v5, (Scaleform::GFx::AS2::ASStringContext *)psc);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v12 = v7;
  LOBYTE(SetLimit) = 1;
  Scaleform::GFx::AS2::Value::Value(&v10, v7);
  pobj->vfptr->SetMemberRaw(
    pobj,
    (Scaleform::GFx::AS2::ASStringContext *)psc,
    (Scaleform::GFx::ASString *)(*((_QWORD *)psc->vfptr->SetLimitHandler + 3) + 960i64),
    v8,
    (Scaleform::GFx::AS2::PropFlags *)&SetLimit);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  if ( v7 )
  {
    RefCount = v7->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v7->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
    }
  }
  return 1;
}

// File Line: 138
// RVA: 0x6D8860
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::AddListener(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  unsigned int v7; // edi
  unsigned __int64 Size; // rbp
  __int64 v9; // rsi
  Scaleform::GFx::AS2::Value *v10; // rcx
  unsigned int RefCount; // eax
  char v12; // bl
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+48h] [rbp-40h] BYREF

  if ( !pthis || !plistener )
    return 0;
  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, __int64))pthis->vfptr->GetMemberRaw)(
         pthis,
         &penv->StringContext,
         &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v16,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v16, penv);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v5->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
        v7 = 0;
        Size = v6->Elements.Data.Size;
        if ( (_DWORD)Size )
        {
          v9 = 0i64;
          while ( 1 )
          {
            v10 = v6->Elements.Data.Data[v9];
            if ( v10 )
            {
              if ( Scaleform::GFx::AS2::Value::ToObjectInterface(v10, penv) == plistener )
                break;
            }
            ++v7;
            ++v9;
            if ( v7 >= (unsigned int)Size )
              goto LABEL_15;
          }
          RefCount = v6->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v6->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          }
          v12 = 0;
          goto LABEL_20;
        }
LABEL_15:
        val.T.Type = 0;
        Scaleform::GFx::AS2::Value::SetAsObjectInterface(&val, plistener);
        Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v13 = v6->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          v6->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
  }
  v12 = 1;
LABEL_20:
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  return v12;
}

// File Line: 168
// RVA: 0x710190
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  bool v7; // sf
  int v8; // esi
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Value *v10; // rcx
  unsigned int RefCount; // eax
  char v12; // bl
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value v15; // [rsp+28h] [rbp-40h] BYREF

  if ( !pthis || !plistener )
    return 0;
  v15.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, __int64))pthis->vfptr->GetMemberRaw)(
         pthis,
         &penv->StringContext,
         &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v15,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v15, penv);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v5->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
        v8 = v6->Elements.Data.Size - 1;
        v7 = v8 < 0;
        v9 = v8;
        while ( !v7 )
        {
          v10 = v6->Elements.Data.Data[v9];
          if ( v10 && Scaleform::GFx::AS2::Value::ToObjectInterface(v10, penv) == plistener )
          {
            Scaleform::GFx::AS2::ArrayObject::RemoveElements(v6, v8, 1);
            RefCount = v6->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v6->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
            }
            v12 = 1;
            goto LABEL_17;
          }
          --v8;
          v7 = --v9 < 0;
        }
        v13 = v6->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          v6->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
  }
  v12 = 0;
LABEL_17:
  if ( v15.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  return v12;
}

// File Line: 211
// RVA: 0x6FE810
void __fastcall Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage_::_4_::LocalInvokeCallback::Invoke(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::FunctionRef *method,
        _QWORD *a4)
{
  int pCurrent_high; // r10d
  int pCurrent; // eax
  char v6; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-70h] BYREF
  __int64 v12[3]; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // [rsp+60h] [rbp-38h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // [rsp+68h] [rbp-30h]
  char v15; // [rsp+70h] [rbp-28h]
  Scaleform::GFx::AS2::ObjectInterface *v16; // [rsp+78h] [rbp-20h]
  int v17; // [rsp+80h] [rbp-18h]
  int v18; // [rsp+84h] [rbp-14h]

  v11.T.Type = 0;
  pCurrent_high = HIDWORD(penv->Stack.pCurrent);
  pCurrent = (int)penv->Stack.pCurrent;
  v12[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v12[1] = (__int64)&v11;
  v12[2] = (__int64)method;
  v15 = 0;
  v13 = 0i64;
  v14 = 0i64;
  v16 = pthis;
  v17 = pCurrent;
  v18 = pCurrent_high;
  (*(void (__fastcall **)(_QWORD, __int64 *, _QWORD, _QWORD, __int64))(*(_QWORD *)*a4 + 80i64))(
    *a4,
    v12,
    a4[1],
    0i64,
    -2i64);
  v12[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v6 = v15;
  if ( (v15 & 2) == 0 )
  {
    v7 = v13;
    if ( v13 )
    {
      RefCount = v13->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v13->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        v6 = v15;
      }
    }
  }
  v13 = 0i64;
  if ( (v6 & 1) == 0 )
  {
    v9 = v14;
    if ( v14 )
    {
      v10 = v14->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        v14->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  v14 = 0i64;
  v12[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 222
// RVA: 0x6DB7C0
// bad sp value at call has been detected, the output may be wrong!
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::ASString *eventName,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *pcallback)
{
  Scaleform::GFx::AS2::Object *v6; // rax
  __int64 v7; // r13
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::GFx::AS2::ArrayObject *v9; // rax
  Scaleform::GFx::AS2::ArrayObject *v10; // rax
  Scaleform::GFx::AS2::ArrayObject *v11; // rbx
  unsigned __int64 Size; // rax
  __int64 v13; // r12
  __int64 v14; // r13
  Scaleform::GFx::AS2::Value **Data; // rax
  Scaleform::GFx::AS2::Value *v16; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v17; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rbx
  Scaleform::RefCountNTSImpl *v19; // rdi
  Scaleform::GFx::InteractiveObject *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  int v29; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+8h] [rbp-61h] BYREF
  void *v31; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::AS2::Object *v32; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::AS2::Value v33; // [rsp+30h] [rbp-39h] BYREF
  Scaleform::GFx::AS2::Value v34; // [rsp+50h] [rbp-19h] BYREF
  __int64 v35; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::AS2::ArrayObject *v36; // [rsp+78h] [rbp+Fh]
  __int64 v37; // [rsp+80h] [rbp+17h]
  Scaleform::GFx::AS2::ArrayObject *v38; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::ASString *v39; // [rsp+E0h] [rbp+77h]
  __int64 v40; // [rsp+E8h] [rbp+7Fh]

  v37 = -2i64;
  if ( !pthis )
    return 0;
  v33.T.Type = 0;
  if ( pthis->vfptr->GetMemberRaw(
         pthis,
         &penv->StringContext,
         (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v33) )
  {
    v6 = Scaleform::GFx::AS2::Value::ToObject(&v33, penv);
    v7 = (__int64)v6;
    v32 = v6;
    if ( v6 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v6->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
        v35 = v7;
        if ( *(int *)(v7 + 112) > 0 )
        {
          v9 = (Scaleform::GFx::AS2::ArrayObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(v8, 144i64, 0i64);
          v31 = v9;
          if ( v9 )
          {
            Scaleform::GFx::AS2::ArrayObject::ArrayObject(v9, penv);
            v11 = v10;
          }
          else
          {
            v11 = 0i64;
          }
          v38 = v11;
          v36 = v11;
          Scaleform::GFx::AS2::ArrayObject::MakeDeepCopyFrom(
            v11,
            penv->StringContext.pContext->pHeap,
            (Scaleform::GFx::AS2::ArrayObject *)v7);
          Size = v11->Elements.Data.Size;
          if ( (_DWORD)Size )
          {
            v13 = 0i64;
            v14 = (unsigned int)Size;
            do
            {
              Data = v11->Elements.Data.Data;
              v16 = Data[v13];
              if ( v16 )
              {
                v17 = Scaleform::GFx::AS2::Value::ToObjectInterface(Data[v13], penv);
                if ( v17 )
                {
                  v18 = 0i64;
                  v19 = 0i64;
                  v31 = 0i64;
                  if ( v16->T.Type == 7 )
                  {
                    v20 = Scaleform::GFx::AS2::Value::ToCharacter(v16, penv);
                    v19 = v20;
                    if ( v20 )
                      ++v20->RefCount;
                    v31 = v20;
                  }
                  else
                  {
                    v21 = Scaleform::GFx::AS2::Value::ToObject(v16, penv);
                    v18 = v21;
                    if ( v21 )
                      v21->RefCount = (v21->RefCount + 1) & 0x8FFFFFFF;
                  }
                  v34.T.Type = 0;
                  if ( v17->vfptr->GetMemberRaw(v17, &penv->StringContext, v39, &v34) )
                  {
                    Scaleform::GFx::AS2::Value::ToFunction(&v34, &result, penv);
                    if ( result.Function )
                      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FunctionRef *))(*(_QWORD *)v40 + 8i64))(
                        v40,
                        penv,
                        v17,
                        &result);
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
                        v26 = result.pLocalFrame->RefCount;
                        if ( (v26 & 0x3FFFFFF) != 0 )
                        {
                          result.pLocalFrame->RefCount = v26 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
                        }
                      }
                    }
                    result.pLocalFrame = 0i64;
                  }
                  if ( v34.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v34);
                  if ( v19 )
                    Scaleform::RefCountNTSImpl::Release(v19);
                  if ( v18 )
                  {
                    v27 = v18->RefCount;
                    if ( (v27 & 0x3FFFFFF) != 0 )
                    {
                      v18->RefCount = v27 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
                    }
                  }
                  v11 = v38;
                }
              }
              ++v13;
              --v14;
            }
            while ( v14 );
            v7 = (__int64)v32;
          }
          v28 = v11->RefCount;
          if ( (v28 & 0x3FFFFFF) != 0 )
          {
            v11->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          }
        }
        v29 = *(_DWORD *)(v7 + 24);
        if ( (v29 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v7 + 24) = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7);
        }
      }
    }
  }
  if ( v33.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
  return 1;
}

// File Line: 274
// RVA: 0x6F8CD0
void __fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::Object *v3; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 36
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v3 = (Scaleform::GFx::AS2::Object *)fn->ThisPtr;
    if ( v3 )
    {
      v3 = (Scaleform::GFx::AS2::Object *)((char *)v3 - 32);
      if ( v3 )
        v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
    if ( v3 )
    {
      RefCount = v3->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v3->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 1;
  }
}

// File Line: 286
// RVA: 0x6E0300
void __fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::AsBroadcasterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::AsBroadcaster *v3; // rax

  v3 = (Scaleform::GFx::AS2::AsBroadcaster *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AsBroadcasterCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               96i64);
  if ( v3 )
    Scaleform::GFx::AS2::AsBroadcaster::AsBroadcaster(v3, penv);
}

// File Line: 292
// RVA: 0x70C3E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment> *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rsi
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v18; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment> *flags; // [rsp+B8h] [rbp+40h] BYREF
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::AsBroadcasterCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(flags) = 3;
      v18.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v18,
        (Scaleform::GFx::AS2::PropFlags *)&flags);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsBroadcasterCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcasterCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &psc,
      Scaleform::GFx::AS2::AsBroadcasterCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v10 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment> *)pHeap->vfptr->Alloc(v5, 160ui64, 0i64);
  p_flags = (__int64 *)v10;
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>(
      v10,
      &psc,
      v11,
      result);
    v10->Scaleform::GFx::AS2::AsBroadcaster::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->Scaleform::GFx::AS2::AsBroadcaster::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v10->Scaleform::GFx::AS2::GASPrototypeBase,
      v10,
      &psc,
      GAS_AsBcFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v10 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v10;
  p_flags = (__int64 *)&flags;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  flags = v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_AsBroadcaster,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v12 = pgc->pGlobal.pObject;
  v18.T.Type = 8;
  v18.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v18.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v18.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v18.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(flags) = 0;
  v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v12->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[11].pASSupport,
    &v18,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v10 )
  {
    v15 = v10->RefCount;
    if ( (v15 & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  return result;
}

