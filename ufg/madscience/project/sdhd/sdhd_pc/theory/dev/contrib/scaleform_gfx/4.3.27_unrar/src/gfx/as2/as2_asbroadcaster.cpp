// File Line: 29
// RVA: 0x6C72E0
void __fastcall Scaleform::GFx::AS2::AsBroadcaster::AsBroadcaster(Scaleform::GFx::AS2::AsBroadcaster *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::AsBroadcaster *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsBroadcaster::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_AsBroadcaster);
  v3->vfptr->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 41
// RVA: 0x6A8CA0
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::AddListener(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v4 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v2);
    Scaleform::GFx::AS2::AsBroadcaster::AddListener(v1->Env, v1->ThisPtr, v5);
    v6 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 2;
    v6->V.BooleanValue = 1;
  }
}

// File Line: 53
// RVA: 0x6A8D20
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::BroadcastMessage(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // r10
  int v6; // er8
  int v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-20h]
  int v13; // [rsp+30h] [rbp-18h]
  int v14; // [rsp+34h] [rbp-14h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

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
    v5 = v1->Env;
    v6 = ((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5)
       + 32 * v5->Stack.Pages.Data.Size
       - 36;
    v7 = v1->NArgs - 1;
    v8 = v1->ThisPtr;
    if ( v8 )
    {
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
      v13 = v7;
      v14 = v6;
      Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v5, v8, &result, &pcallback);
      pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    }
    v9 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->T.Type = 0;
    v10 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 65
// RVA: 0x6A8E20
void __fastcall Scaleform::GFx::AS2::AsBroadcasterProto::RemoveListener(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  bool v6; // al
  Scaleform::GFx::AS2::Value *v7; // rbx
  bool v8; // di

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v4 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v2);
    v6 = Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(v1->Env, v1->ThisPtr, v5);
    v7 = v1->Result;
    v8 = v6;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->V.BooleanValue = v8;
    v7->T.Type = 2;
  }
}

// File Line: 105
// RVA: 0x6A9FE0
void __fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Initialize(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::AS2::Environment *v8; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v4 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v2);
    v6 = v1->Result;
    v7 = v5;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v6->T.Type = 0;
    v8 = v1->Env;
    if ( v7 )
      Scaleform::GFx::AS2::NameFunction::AddConstMembers(v7, &v8->StringContext, GAS_AsBcFunctionTable, 1);
    Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(&v8->StringContext, v7);
  }
}

// File Line: 128
// RVA: 0x6FD5F0
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // rsi
  Scaleform::GFx::AS2::ASStringContext *v3; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rbx
  Scaleform::GFx::AS2::Value *v8; // rax
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Value v10; // [rsp+38h] [rbp-30h]
  Scaleform::MemoryHeap *v11; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS2::ArrayObject *v12; // [rsp+80h] [rbp+18h]

  v2 = pobj;
  v3 = psc;
  if ( !pobj )
    return 0;
  v11 = psc->pContext->pHeap;
  v5 = (Scaleform::GFx::AS2::ArrayObject *)v11->vfptr->Alloc((Scaleform::MemoryHeap *)psc, 144ui64, 0i64);
  v12 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v5, v3);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v12 = (Scaleform::GFx::AS2::ArrayObject *)v7;
  LOBYTE(v11) = 1;
  Scaleform::GFx::AS2::Value::Value(&v10, v7);
  v2->vfptr->SetMemberRaw(
    v2,
    v3,
    (Scaleform::GFx::ASString *)&v3->pContext->pMovieRoot->pASMovieRoot.pObject[24],
    v8,
    (Scaleform::GFx::AS2::PropFlags *)&v11);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  if ( v7 )
  {
    v9 = v7->RefCount;
    if ( v9 & 0x3FFFFFF )
    {
      v7->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->vfptr);
    }
  }
  return 1;
}

// File Line: 138
// RVA: 0x6D8860
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::AddListener(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Environment *v4; // r15
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  unsigned int v7; // edi
  unsigned __int64 v8; // rbp
  __int64 v9; // rsi
  Scaleform::GFx::AS2::Value *v10; // rcx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::AS2::Value v16; // [rsp+48h] [rbp-40h]

  v3 = plistener;
  v4 = penv;
  if ( !pthis || !plistener )
    return 0;
  v16.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, signed __int64))pthis->vfptr->GetMemberRaw)(
         pthis,
         &penv->StringContext,
         &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v16,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v16, v4);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 )
    {
      if ( (*(unsigned int (**)(void))&v5->vfptr->gap8[8])() == 7 )
      {
        v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
        v7 = 0;
        v8 = v6->Elements.Data.Size;
        if ( (_DWORD)v8 )
        {
          v9 = 0i64;
          while ( 1 )
          {
            v10 = v6->Elements.Data.Data[v9];
            if ( v10 )
            {
              if ( Scaleform::GFx::AS2::Value::ToObjectInterface(v10, v4) == v3 )
                break;
            }
            ++v7;
            ++v9;
            if ( v7 >= (unsigned int)v8 )
              goto LABEL_15;
          }
          v11 = v6->RefCount;
          if ( v11 & 0x3FFFFFF )
          {
            v6->RefCount = v11 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
          }
          v12 = 0;
          goto LABEL_20;
        }
LABEL_15:
        val.T.Type = 0;
        Scaleform::GFx::AS2::Value::SetAsObjectInterface(&val, v3);
        Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v13 = v6->RefCount;
        if ( v13 & 0x3FFFFFF )
        {
          v6->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
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
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::AS2::Environment *v4; // rbp
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  bool v7; // sf
  int v8; // esi
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Value *v10; // rcx
  unsigned int v11; // eax
  char v12; // bl
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value v15; // [rsp+28h] [rbp-40h]

  v3 = plistener;
  v4 = penv;
  if ( !pthis || !plistener )
    return 0;
  v15.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, signed __int64))pthis->vfptr->GetMemberRaw)(
         pthis,
         &penv->StringContext,
         &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v15,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v15, v4);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 )
    {
      if ( (*(unsigned int (**)(void))&v5->vfptr->gap8[8])() == 7 )
      {
        v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
        v8 = v6->Elements.Data.Size - 1;
        v7 = v8 < 0;
        v9 = v8;
        while ( !v7 )
        {
          v10 = v6->Elements.Data.Data[v9];
          if ( v10 && Scaleform::GFx::AS2::Value::ToObjectInterface(v10, v4) == v3 )
          {
            Scaleform::GFx::AS2::ArrayObject::RemoveElements(v6, v8, 1);
            v11 = v6->RefCount;
            if ( v11 & 0x3FFFFFF )
            {
              v6->RefCount = v11 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
            }
            v12 = 1;
            goto LABEL_17;
          }
          --v8;
          v7 = --v9 < 0;
        }
        v13 = v6->RefCount;
        if ( v13 & 0x3FFFFFF )
        {
          v6->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
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
void __fastcall Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage_::_4_::LocalInvokeCallback::Invoke(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::FunctionRef *method, _QWORD *a4)
{
  int v4; // er10
  int v5; // eax
  char v6; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-70h]
  void **v12; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::AS2::Value *v13; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::AS2::FunctionRef *v14; // [rsp+58h] [rbp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // [rsp+60h] [rbp-38h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // [rsp+68h] [rbp-30h]
  char v17; // [rsp+70h] [rbp-28h]
  Scaleform::GFx::AS2::ObjectInterface *v18; // [rsp+78h] [rbp-20h]
  int v19; // [rsp+80h] [rbp-18h]
  int v20; // [rsp+84h] [rbp-14h]

  v11.T.Type = 0;
  v4 = HIDWORD(penv->Stack.pCurrent);
  v5 = (int)penv->Stack.pCurrent;
  v12 = &Scaleform::GFx::AS2::FnCall::`vftable;
  v13 = &v11;
  v14 = method;
  v17 = 0;
  v15 = 0i64;
  v16 = 0i64;
  v18 = pthis;
  v19 = v5;
  v20 = v4;
  (*(void (__fastcall **)(_QWORD, void ***, _QWORD, _QWORD, signed __int64))(*(_QWORD *)*a4 + 80i64))(
    *a4,
    &v12,
    a4[1],
    0i64,
    -2i64);
  v12 = &Scaleform::GFx::AS2::FnCall::`vftable;
  v6 = v17;
  if ( !(v17 & 2) )
  {
    v7 = v15;
    if ( v15 )
    {
      v8 = v15->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v15->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        v6 = v17;
      }
    }
  }
  v15 = 0i64;
  if ( !(v6 & 1) )
  {
    v9 = v16;
    if ( v16 )
    {
      v10 = v16->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        v16->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  v16 = 0i64;
  v12 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 222
// RVA: 0x6DB7C0
char __fastcall Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::ASString *eventName, Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *pcallback)
{
  Scaleform::GFx::AS2::Environment *v4; // r15
  Scaleform::GFx::AS2::Object *v6; // rax
  __int64 v7; // r13
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::GFx::AS2::ArrayObject *v9; // rax
  Scaleform::GFx::AS2::ArrayObject *v10; // rax
  Scaleform::GFx::AS2::ArrayObject *v11; // rbx
  unsigned __int64 v12; // rax
  __int64 v13; // r12
  __int64 v14; // r13
  Scaleform::GFx::AS2::Value **v15; // rax
  Scaleform::GFx::AS2::Value *v16; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v17; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rbx
  Scaleform::RefCountNTSImpl *v19; // rdi
  Scaleform::GFx::InteractiveObject *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rax
  char v22; // al
  Scaleform::GFx::AS2::FunctionObject *v23; // rcx
  unsigned int v24; // edx
  Scaleform::GFx::AS2::LocalFrame *v25; // rcx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  int v29; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+8h] [rbp-61h]
  void *v31; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::AS2::Object *v32; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::AS2::Value v33; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::AS2::Value v34; // [rsp+50h] [rbp-19h]
  __int64 v35; // [rsp+70h] [rbp+7h]
  Scaleform::GFx::AS2::ArrayObject *v36; // [rsp+78h] [rbp+Fh]
  __int64 v37; // [rsp+80h] [rbp+17h]
  Scaleform::GFx::AS2::ArrayObject *v38; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::ASString *v39; // [rsp+E0h] [rbp+77h]
  __int64 v40; // [rsp+E8h] [rbp+7Fh]

  v37 = -2i64;
  v4 = penv;
  if ( !pthis )
    return 0;
  v33.T.Type = 0;
  if ( pthis->vfptr->GetMemberRaw(
         pthis,
         &penv->StringContext,
         (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v33) )
  {
    v6 = Scaleform::GFx::AS2::Value::ToObject(&v33, v4);
    v7 = (__int64)v6;
    v32 = v6;
    if ( v6 )
    {
      if ( (*(unsigned int (**)(void))&v6->vfptr->gap8[8])() == 7 )
      {
        *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
        v35 = v7;
        if ( *(_DWORD *)(v7 + 112) > 0 )
        {
          v9 = (Scaleform::GFx::AS2::ArrayObject *)v4->StringContext.pContext->pHeap->vfptr->Alloc(v8, 144ui64, 0i64);
          v31 = v9;
          if ( v9 )
          {
            Scaleform::GFx::AS2::ArrayObject::ArrayObject(v9, v4);
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
            v4->StringContext.pContext->pHeap,
            (Scaleform::GFx::AS2::ArrayObject *)v7);
          v12 = v11->Elements.Data.Size;
          if ( (_DWORD)v12 )
          {
            v13 = 0i64;
            v14 = (unsigned int)v12;
            do
            {
              v15 = v11->Elements.Data.Data;
              v16 = v15[v13];
              if ( v16 )
              {
                v17 = Scaleform::GFx::AS2::Value::ToObjectInterface(v15[v13], v4);
                if ( v17 )
                {
                  v18 = 0i64;
                  v19 = 0i64;
                  v31 = 0i64;
                  if ( v16->T.Type == 7 )
                  {
                    v20 = Scaleform::GFx::AS2::Value::ToCharacter(v16, v4);
                    v19 = (Scaleform::RefCountNTSImpl *)&v20->vfptr;
                    if ( v20 )
                      ++v20->RefCount;
                    v31 = v20;
                  }
                  else
                  {
                    v21 = Scaleform::GFx::AS2::Value::ToObject(v16, v4);
                    v18 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v21->vfptr;
                    if ( v21 )
                      v21->RefCount = (v21->RefCount + 1) & 0x8FFFFFFF;
                  }
                  v34.T.Type = 0;
                  if ( v17->vfptr->GetMemberRaw(v17, &v4->StringContext, v39, &v34) )
                  {
                    Scaleform::GFx::AS2::Value::ToFunction(&v34, &result, v4);
                    if ( result.Function )
                      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FunctionRef *))(*(_QWORD *)v40 + 8i64))(
                        v40,
                        v4,
                        v17,
                        &result);
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
                  }
                  if ( v34.T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(&v34);
                  if ( v19 )
                    Scaleform::RefCountNTSImpl::Release(v19);
                  if ( v18 )
                  {
                    v27 = v18->RefCount;
                    if ( v27 & 0x3FFFFFF )
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
          if ( v28 & 0x3FFFFFF )
          {
            v11->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
          }
        }
        v29 = *(_DWORD *)(v7 + 24);
        if ( v29 & 0x3FFFFFF )
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
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::Object *v3; // rbx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2
    || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) != 36
    || ((unsigned __int8 (__cdecl *)(Scaleform::GFx::AS2::ObjectInterface *))v1->ThisPtr->vfptr->IsBuiltinPrototype)(v1->ThisPtr) )
  {
    v5 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v5->T.Type = 1;
  }
  else
  {
    v3 = (Scaleform::GFx::AS2::Object *)v1->ThisPtr;
    if ( v3 )
    {
      v3 = (Scaleform::GFx::AS2::Object *)((char *)v3 - 32);
      if ( v3 )
        v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v3);
    if ( v3 )
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->vfptr);
      }
    }
  }
}

// File Line: 286
// RVA: 0x6E0300
void __fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::CreateNewObject(Scaleform::GFx::AS2::AsBroadcasterCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::AsBroadcaster *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::AsBroadcaster *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AsBroadcasterCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               96i64);
  if ( v3 )
    Scaleform::GFx::AS2::AsBroadcaster::AsBroadcaster(v3, v2);
}

// File Line: 292
// RVA: 0x70C3E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment> *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rsi
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS2::LocalFrame *v14; // rdx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v18; // [rsp+50h] [rbp-28h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v20; // [rsp+C0h] [rbp+48h]
  Scaleform::GFx::AS2::PropFlags *v21; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v20 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v20->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)v4;
  v21 = (Scaleform::GFx::AS2::PropFlags *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[6].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)Scaleform::GFx::AS2::AsBroadcasterCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6[2].pProto.pObject )
    {
      flags.Flags = 3;
      v18.T.Type = 10;
      v6[2].vfptr->SetMemberRaw(
        v6 + 2,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v18,
        &flags);
      if ( v18.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v18);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6[2].pProto.pObject->vfptr;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v6[2].pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcasterCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6[2].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcasterCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      v6 + 2,
      &psc,
      Scaleform::GFx::AS2::AsBroadcasterCtorFunction::StaticFunctionTable,
      7);
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)v6;
  v3->pLocalFrame = 0i64;
  v20 = v2->pHeap;
  v10 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment> *)v20->vfptr->Alloc(v5, 160ui64, 0i64);
  v21 = (Scaleform::GFx::AS2::PropFlags *)v10;
  if ( v10 )
  {
    v11 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>(
      v10,
      &psc,
      v11,
      v3);
    v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v10->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable;
    flags.Flags = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v10->vfptr,
      (Scaleform::GFx::AS2::Object *)&v10->vfptr,
      &psc,
      GAS_AsBcFunctionTable,
      &flags);
  }
  else
  {
    v10 = 0i64;
  }
  v20 = (Scaleform::MemoryHeap *)v10;
  v21 = &flags;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  *(_QWORD *)&flags.Flags = v10;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_AsBroadcaster,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v12 = v2->pGlobal.pObject;
  v18.T.Type = 8;
  v18.V.FunctionValue.Flags = 0;
  v13 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v18.V.pStringNode = v13;
  if ( v13 )
  {
    ++v13->RefCount;
    v13->RefCount &= 0x8FFFFFFF;
  }
  v18.V.FunctionValue.pLocalFrame = 0i64;
  v14 = v3->pLocalFrame;
  if ( v14 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v18.NV.8,
      v14,
      v3->Flags & 1);
  flags.Flags = 0;
  v12->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v12->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[11].pASSupport,
    &v18,
    &flags);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  if ( v10 )
  {
    v15 = v10->RefCount;
    if ( v15 & 0x3FFFFFF )
    {
      v10->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
  return v3;
}

