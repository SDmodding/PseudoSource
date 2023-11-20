// File Line: 106
// RVA: 0x6D1540
void __fastcall Scaleform::GFx::AS2::FunctionObject::~FunctionObject(Scaleform::GFx::AS2::FunctionObject *this)
{
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&this->vfptr);
}

// File Line: 110
// RVA: 0x71B170
void __fastcall Scaleform::GFx::AS2::FunctionObject::SetPrototype(Scaleform::GFx::AS2::FunctionObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::ASStringContext *v3; // rdi
  Scaleform::GFx::AS2::FunctionObject *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::Value v6; // [rsp+38h] [rbp-30h]
  char v7; // [rsp+70h] [rbp+8h]

  v3 = psc;
  v4 = this;
  Scaleform::GFx::AS2::Value::Value(&v6, pprototype);
  v7 = 0;
  v4->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
    v3,
    (Scaleform::GFx::ASString *)&v3->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v5,
    (Scaleform::GFx::AS2::PropFlags *)&v7);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
}

// File Line: 116
// RVA: 0x71B000
void __fastcall Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(Scaleform::GFx::AS2::FunctionObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rsi
  char v6; // al
  Scaleform::GFx::AS2::FunctionObject *v7; // rcx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::LocalFrame *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-20h]

  v3 = pprototype;
  v4 = psc;
  v5 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))this->vfptr->Set__proto__)(&this->vfptr);
  Scaleform::GFx::AS2::ObjectInterface::Get_constructor((Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr, &result, v4);
  if ( result.Function )
    Scaleform::GFx::AS2::ObjectInterface::Set_constructor(v5, v4, &result);
  v6 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v7 = result.Function;
    if ( result.Function )
    {
      v8 = result.Function->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        result.Function->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->vfptr);
        v6 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v6 & 1) )
  {
    v9 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v10 = result.pLocalFrame->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
      }
    }
  }
}

// File Line: 126
// RVA: 0x7214E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::FunctionObject::ToFunction(Scaleform::GFx::AS2::FunctionObject *this, Scaleform::GFx::AS2::FunctionRef *result)
{
  bool v2; // zf
  Scaleform::GFx::AS2::FunctionObject *v3; // rcx

  result->Flags = 0;
  v2 = this == (Scaleform::GFx::AS2::FunctionObject *)32;
  v3 = (Scaleform::GFx::AS2::FunctionObject *)((char *)this - 32);
  result->Function = v3;
  if ( !v2 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  result->pLocalFrame = 0i64;
  return result;
}

// File Line: 153
// RVA: 0x6C7E00
void __fastcall Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(Scaleform::GFx::AS2::CFunctionObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::CFunctionObject *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2->pFunction = 0i64;
}

// File Line: 176
// RVA: 0x6C7E60
void __fastcall Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(Scaleform::GFx::AS2::CFunctionObject *this, Scaleform::GFx::AS2::ASStringContext *psc, void (__fastcall *func)(Scaleform::GFx::AS2::FnCall *))
{
  void (__fastcall *v3)(Scaleform::GFx::AS2::FnCall *); // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::CFunctionObject *v5; // r14
  Scaleform::GFx::AS2::Object *v6; // rax

  v3 = func;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->pFunction = v3;
  v6 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v6);
}

// File Line: 181
// RVA: 0x6D11B0
void __fastcall Scaleform::GFx::AS2::CFunctionObject::~CFunctionObject(Scaleform::GFx::AS2::CFunctionObject *this)
{
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&this->vfptr);
}

// File Line: 186
// RVA: 0x6FE130
void __fastcall Scaleform::GFx::AS2::CFunctionObject::Invoke(Scaleform::GFx::AS2::CFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn, Scaleform::GFx::AS2::LocalFrame *__formal, const char *a4)
{
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::CFunctionObject *v5; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  int v8; // er9
  int v9; // er8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  Scaleform::GFx::AS2::Value *v11; // rax
  signed __int64 v12; // [rsp+20h] [rbp-58h]
  Scaleform::GFx::AS2::FnCall v13; // [rsp+30h] [rbp-48h]

  v12 = -2i64;
  v4 = fn;
  v5 = this;
  if ( this->pFunction )
  {
    v6 = fn->ThisPtr;
    if ( v6
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, const char *, signed __int64))v6->vfptr->IsSuper)(
           fn->ThisPtr,
           fn,
           __formal,
           a4,
           -2i64) )
    {
      v7 = (Scaleform::GFx::AS2::ObjectInterface *)v6[5].vfptr;
      v8 = v4->FirstArgBottomIndex;
      v9 = v4->NArgs;
      v10 = v4->Env;
      v11 = v4->Result;
      v13.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
      v13.Result = v11;
      v13.ThisPtr = v7;
      v13.ThisFunctionRef.Flags = 0;
      v13.ThisFunctionRef.Function = 0i64;
      v13.ThisFunctionRef.pLocalFrame = 0i64;
      v13.Env = v10;
      v13.NArgs = v9;
      v13.FirstArgBottomIndex = v8;
      v5->pFunction(&v13);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&v6[-2]);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v13);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, const char *, signed __int64))v5->pFunction)(
        v4,
        fn,
        __formal,
        a4,
        v12);
    }
  }
}

// File Line: 203
// RVA: 0x6EF840
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::GetEnvironment(Scaleform::GFx::AS2::UserDefinedFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  return fn->Env;
}

// File Line: 209
// RVA: 0x7003F0
bool __fastcall Scaleform::GFx::AS2::CFunctionObject::IsEqual(Scaleform::GFx::AS2::CFunctionObject *this, Scaleform::GFx::AS2::FunctionObject *f)
{
  Scaleform::GFx::AS2::CFunctionObject *v2; // rdi
  Scaleform::GFx::AS2::FunctionObject *v3; // rbx

  v2 = this;
  v3 = f;
  return ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *))f->vfptr[4].Finalize_GC)(f)
      && v2->pFunction == (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v3[1].vfptr;
}

// File Line: 232
// RVA: 0x6C7360
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(Scaleform::GFx::AS2::AsFunctionObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ActionBuffer *ab, unsigned int start, unsigned int length, Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack, Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  unsigned int v7; // er14
  Scaleform::GFx::AS2::ActionBuffer *v8; // rdi
  Scaleform::GFx::AS2::Environment *v9; // rbp
  Scaleform::GFx::AS2::AsFunctionObject *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  signed __int64 v12; // ST28_8
  bool v13; // zf
  Scaleform::GFx::DisplayObject *v14; // rbp
  Scaleform::GFx::CharacterHandle *v15; // rdi
  Scaleform::GFx::CharacterHandle *v16; // rsi
  signed __int64 v17; // [rsp+78h] [rbp+10h]
  signed __int64 v18; // [rsp+78h] [rbp+10h]

  v7 = start;
  v8 = ab;
  v9 = penv;
  v10 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v10->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v10->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v10->pMovieRoot = 0i64;
  v10->TargetHandle.pObject = 0i64;
  if ( v8 )
    ++v8->RefCount;
  v10->pActionBuffer.pObject = v8;
  v17 = (signed __int64)&v10->WithStack;
  *(_OWORD *)v17 = 0ui64;
  *(_QWORD *)(v17 + 16) = 0i64;
  v10->StartPc = v7;
  v10->Length = length;
  v11 = *(Scaleform::GFx::ASStringNode **)&v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++v11->RefCount;
  v18 = (signed __int64)&v10->Args;
  *(_OWORD *)v18 = 0ui64;
  *(_QWORD *)(v18 + 16) = 0i64;
  v12 = (signed __int64)&v10->Args.Data.DefaultValue;
  *(_DWORD *)v12 = 0;
  *(_QWORD *)(v12 + 8) = v11;
  v13 = ++v11->RefCount == 1;
  --v11->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v10->Function2Flags = 0;
  *(_WORD *)&v10->ExecType = (unsigned __int8)execType;
  if ( pwithStack )
    Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>::operator=(
      &v10->WithStack,
      pwithStack);
  if ( (unsigned int)(execType - 3) > 1 )
  {
    v14 = (Scaleform::GFx::DisplayObject *)&v9->Target->vfptr;
    v15 = v14->pNameHandle.pObject;
    if ( v15 || (v15 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v14)) != 0i64 )
      ++v15->RefCount;
    v16 = v10->TargetHandle.pObject;
    if ( v16 )
    {
      if ( --v16->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v16);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    v10->TargetHandle.pObject = v15;
    v10->pMovieRoot = v14->pASRoot->pMovieImpl;
  }
}

// File Line: 250
// RVA: 0x6E0720
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::CreateNewObject(Scaleform::GFx::AS2::ObjectCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::Object *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        96i64);
  if ( v3 )
    Scaleform::GFx::AS2::Object::Object(v3, v2);
}

// File Line: 262
// RVA: 0x6EF770
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AsFunctionObject::GetEnvironment(Scaleform::GFx::AS2::AsFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  Scaleform::RefCountNTSImpl **v3; // rsi
  Scaleform::GFx::AS2::FnCall *v4; // rbp
  Scaleform::GFx::MovieImpl *v5; // rdx
  Scaleform::GFx::DisplayObject *v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::DisplayObject *v8; // rbx
  signed __int64 v9; // rcx
  __int64 v10; // rax

  v3 = (Scaleform::RefCountNTSImpl **)ptargetCh;
  v4 = fn;
  v5 = this->pMovieRoot;
  if ( v5 && (v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->TargetHandle.pObject, v5)) != 0i64 )
  {
    v7 = 0i64;
    v8 = 0i64;
    if ( SLOBYTE(v6->Flags) < 0 )
      v8 = v6;
    if ( v8 )
      ++v8->RefCount;
  }
  else
  {
    v7 = 0i64;
    v8 = 0i64;
  }
  if ( v8 )
  {
    v9 = (signed __int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
    v10 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v9 + 8i64))(v9);
    v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10);
  }
  if ( v3 )
  {
    if ( v8 )
      ++v8->RefCount;
    if ( *v3 )
      Scaleform::RefCountNTSImpl::Release(*v3);
    *v3 = (Scaleform::RefCountNTSImpl *)&v8->vfptr;
  }
  if ( !v7 )
    v7 = (__int64)v4->Env;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v8->vfptr);
  return (Scaleform::GFx::AS2::Environment *)v7;
}

// File Line: 309
// RVA: 0x71E450
void __fastcall Scaleform::GFx::AS2::InvokeContext::Setup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::InvokeContext *v1; // rsi
  Scaleform::GFx::AS2::AsFunctionObject *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *v4; // rdi
  _QWORD *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::ASString *v7; // r12
  Scaleform::GFx::AS2::Environment *v8; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rax
  Scaleform::GFx::AS2::LocalFrame *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::LocalFrame *v13; // rdi
  Scaleform::GFx::AS2::LocalFrame *v14; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::ASString *v17; // rdi
  Scaleform::GFx::InteractiveObject *v18; // rbx
  Scaleform::RefCountNTSImpl *v19; // rcx
  signed __int64 v20; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // rcx
  unsigned int v22; // eax
  signed int v23; // er15
  Scaleform::GFx::AS2::Environment *v24; // rdx
  Scaleform::GFx::ASString *v25; // r14
  signed __int64 v26; // rbx
  __int64 v27; // rcx
  __int64 v28; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v29; // rcx
  int v30; // eax
  Scaleform::GFx::AS2::LocalFrame *v31; // rax
  Scaleform::GFx::AS2::Environment *v32; // rbx
  Scaleform::GFx::InteractiveObject *v33; // rbx
  Scaleform::RefCountNTSImpl *v34; // rcx
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::AS2::Value *v36; // rax
  unsigned __int64 v37; // r14
  Scaleform::GFx::AS2::FnCall *v38; // rax
  signed int i; // edi
  Scaleform::GFx::AS2::FnCall *v40; // rax
  unsigned int v41; // edx
  Scaleform::GFx::AS2::Environment *v42; // r9
  Scaleform::GFx::AS2::Value *v43; // r8
  Scaleform::GFx::ASString *v44; // rdx
  Scaleform::GFx::AS2::Environment *v45; // r9
  signed __int64 v46; // rbx
  __int64 v47; // rcx
  __int64 v48; // rbx
  int v49; // eax
  signed __int64 v50; // r12
  signed __int64 v51; // r15
  signed __int64 v52; // r12
  Scaleform::GFx::ASString *v53; // r14
  Scaleform::GFx::AS2::Environment *v54; // rdx
  signed __int64 v55; // rdi
  __int64 v56; // rcx
  __int64 v57; // rdi
  signed __int64 v58; // rbx
  signed __int64 v59; // rax
  __int64 *v60; // rax
  signed __int64 v61; // rax
  __int64 v62; // rdx
  __int64 v63; // rcx
  int v64; // eax
  unsigned __int64 v65; // rdx
  Scaleform::GFx::AS2::FnCall *v66; // rax
  __int64 v67; // rdi
  __int64 v68; // r13
  __int64 v69; // r15
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v70; // r10
  unsigned __int64 v71; // r8
  Scaleform::GFx::AS2::FnCall *v72; // rax
  Scaleform::GFx::AS2::Environment *v73; // r9
  unsigned int v74; // edx
  unsigned __int64 v75; // rax
  __int64 v76; // rcx
  Scaleform::GFx::AS2::Value *v77; // r8
  Scaleform::GFx::AS2::Value *v78; // r14
  Scaleform::GFx::AS2::Environment *v79; // rbx
  unsigned __int64 v80; // rcx
  Scaleform::GFx::AS2::Value *v81; // rcx
  signed __int64 v82; // r15
  signed __int64 v83; // r14
  signed __int64 v84; // r15
  Scaleform::GFx::ASString *v85; // rdx
  Scaleform::GFx::AS2::Environment *v86; // r8
  signed __int64 v87; // rbx
  __int64 v88; // rcx
  __int64 v89; // rbx
  int v90; // eax
  Scaleform::GFx::AS2::Object *v91; // rdi
  unsigned __int16 v92; // cx
  Scaleform::GFx::ASStringNode *v93; // rbx
  const char *v94; // r8
  Scaleform::GFx::ASString *v95; // r15
  Scaleform::GFx::AS2::Environment *v96; // r14
  unsigned int *v97; // rdi
  __int64 v98; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v99; // rdi
  Scaleform::GFx::ASStringNode *v100; // rcx
  bool v101; // zf
  unsigned int v102; // eax
  unsigned int v103; // eax
  Scaleform::GFx::ASString *v104; // rax
  Scaleform::GFx::AS2::Object *v105; // rax
  char v106; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v107; // rcx
  int v108; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v109; // rcx
  int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // er13
  Scaleform::GFx::AS2::Environment *v113; // rbx
  unsigned __int64 v114; // rcx
  Scaleform::GFx::AS2::Value *v115; // rcx
  Scaleform::GFx::AS2::Environment *v116; // r14
  unsigned __int64 v117; // rbx
  Scaleform::GFx::AS2::Value *v118; // rbx
  unsigned int v119; // eax
  bool v120; // cf
  Scaleform::GFx::ASString v121; // rax
  Scaleform::GFx::DisplayObject *v122; // rcx
  Scaleform::GFx::ASStringNode *v123; // rbx
  Scaleform::GFx::AS2::Object *v124; // rdx
  Scaleform::GFx::AS2::Environment *v125; // rdx
  Scaleform::GFx::ASString *v126; // r15
  signed __int64 v127; // r14
  __int64 v128; // rcx
  __int64 v129; // r14
  signed __int64 v130; // rbx
  __int64 v131; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v132; // rcx
  int v133; // eax
  __int64 v134; // rbx
  unsigned __int16 v135; // r8
  Scaleform::GFx::ASString *v136; // rax
  __int64 v137; // rax
  int v138; // er14
  __int64 v139; // r15
  Scaleform::GFx::AS2::FnCall *v140; // rax
  unsigned int v141; // edx
  Scaleform::GFx::AS2::Environment *v142; // r8
  Scaleform::GFx::AS2::Value *v143; // r12
  _BYTE *v144; // rax
  _BYTE *v145; // rcx
  Scaleform::GFx::AS2::Environment *v146; // r14
  unsigned __int64 v147; // rcx
  Scaleform::GFx::AS2::Value *v148; // rcx
  Scaleform::GFx::ASString *v149; // rax
  Scaleform::GFx::ASString *v150; // r12
  Scaleform::GFx::AS2::Environment *v151; // r8
  Scaleform::GFx::ASString *v152; // r13
  signed __int64 v153; // r14
  __int64 v154; // rcx
  __int64 v155; // r14
  signed __int64 v156; // r15
  __int64 v157; // r10
  __int64 v158; // r11
  __int64 v159; // r9
  __int64 v160; // rdx
  __int64 *v161; // r8
  Scaleform::GFx::ASStringNode *v162; // rcx
  __int64 v163; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v164; // rcx
  int v165; // eax
  Scaleform::GFx::AS2::Value *v166; // rax
  Scaleform::GFx::AS2::Value *v167; // rax
  Scaleform::GFx::AS2::Environment *v168; // r14
  unsigned __int64 v169; // rcx
  int v170; // er13
  Scaleform::GFx::AS2::Value *v171; // rcx
  unsigned int v172; // er13
  Scaleform::GFx::AS2::Environment *v173; // rdx
  Scaleform::GFx::ASString *v174; // r8
  signed __int64 v175; // r14
  __int64 v176; // rcx
  __int64 v177; // r14
  int v178; // eax
  Scaleform::GFx::AS2::Environment *v179; // r15
  Scaleform::GFx::InteractiveObject *v180; // r12
  unsigned __int64 v181; // r14
  Scaleform::GFx::AS2::Value *v182; // r14
  Scaleform::GFx::DisplayObject *v183; // rax
  Scaleform::GFx::CharacterHandle *v184; // r15
  Scaleform::GFx::AS2::Environment *v185; // r14
  unsigned __int64 v186; // rcx
  Scaleform::GFx::AS2::Value *v187; // rcx
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *v188; // rsi
  Scaleform::GFx::AS2::Object *v189; // r14
  unsigned __int64 v190; // rcx
  Scaleform::GFx::AS2::Value *v191; // rcx
  int v192; // eax
  unsigned int v193; // eax
  Scaleform::GFx::InteractiveObject **ppnewTarget; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::AS2::Value *powner; // [rsp+28h] [rbp-61h]
  __int64 excludeFlags[2]; // [rsp+30h] [rbp-59h]
  __int64 v197; // [rsp+40h] [rbp-49h]
  __int64 v198; // [rsp+48h] [rbp-41h]
  __int64 v199; // [rsp+50h] [rbp-39h]
  _QWORD *v200; // [rsp+58h] [rbp-31h]
  __int64 v201; // [rsp+60h] [rbp-29h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+68h] [rbp-21h]
  char v203; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+F0h] [rbp+67h]
  _QWORD *v206; // [rsp+F8h] [rbp+6Fh]
  _QWORD *v207; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::AS2::Object *v208; // [rsp+108h] [rbp+7Fh]

  v199 = -2i64;
  v1 = this;
  v2 = this->pThis;
  v3 = this->pOurEnv;
  if ( this->pThis )
    v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
  key.pStr = (Scaleform::GFx::ASString *)v2;
  v4 = &v3->CallStack;
  ++v4->pCurrent;
  if ( v4->pCurrent >= v4->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PushPage(v4);
  v5 = &v4->pCurrent->pObject;
  v206 = v5;
  v207 = v5;
  if ( v5 )
  {
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    *v5 = v2;
  }
  if ( v2 )
  {
    v6 = v2->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v2->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
    }
  }
  v7 = (Scaleform::GFx::ASString *)v1->mFnCall->ThisPtr;
  v8 = v1->pOurEnv;
  v207 = &v8->StringContext.pContext->pHeap->vfptr;
  v200 = v207;
  v1->LocalStackTop = v8->LocalFrames.Data.Size;
  if ( (unsigned __int8)(v1->pThis->ExecType - 1) <= 1u )
  {
    v9 = Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(v8);
    v10 = (Scaleform::GFx::AS2::LocalFrame *)v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
    v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->CurLocalFrame.pObject->vfptr;
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    v1->CurLocalFrame.pObject = v10;
    v13 = v10;
    v14 = v1->pLocalFrame;
    if ( v14 )
      v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
    v15 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->PrevFrame.pObject->vfptr;
    if ( v15 )
    {
      v16 = v15->RefCount;
      if ( v16 & 0x3FFFFFF )
      {
        v15->RefCount = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
      }
    }
    v13->PrevFrame.pObject = v14;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::AddFrameBarrier(v8);
  }
  v17 = v7;
  key.pStr = v7;
  if ( v7 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v7->pNode->pLower)(v7) - 2 > 3 )
      v18 = 0i64;
    else
      v18 = (Scaleform::GFx::InteractiveObject *)v7[2].pNode;
    if ( v18 )
      ++v18->RefCount;
    v19 = (Scaleform::RefCountNTSImpl *)&v1->PassedThisCh.pObject->vfptr;
    if ( v19 )
      Scaleform::RefCountNTSImpl::Release(v19);
    v1->PassedThisCh.pObject = v18;
    v20 = (signed __int64)&v7[-4];
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v7->pNode->pLower)(v7) - 6 > 0x26 )
      v20 = 0i64;
    if ( v20 )
      *(_DWORD *)(v20 + 24) = (*(_DWORD *)(v20 + 24) + 1) & 0x8FFFFFFF;
    v21 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->PassedThisObj.pObject->vfptr;
    if ( v21 )
    {
      v22 = v21->RefCount;
      if ( v22 & 0x3FFFFFF )
      {
        v21->RefCount = v22 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
      }
    }
    v1->PassedThisObj.pObject = (Scaleform::GFx::AS2::Object *)v20;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASString *))v7->pNode[3].pData)(v7) )
      v7 = (Scaleform::GFx::ASString *)v7[10].pNode;
  }
  if ( v1->pThis->ExecType != 2 )
  {
    v23 = (unsigned __int8)v1->pOurEnv->StringContext.SWFVersion;
    if ( v7 )
    {
      v.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, (Scaleform::GFx::AS2::ObjectInterface *)v7);
      v24 = v1->pOurEnv;
      v25 = (Scaleform::GFx::ASString *)&v24->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
      v26 = (signed __int64)&v24->LocalFrames.Data.Data[v24->LocalFrames.Data.Size];
      v27 = *(_QWORD *)(v26 - 8);
      if ( v27 )
        *(_DWORD *)(v27 + 24) = (*(_DWORD *)(v27 + 24) + 1) & 0x8FFFFFFF;
      v28 = *(_QWORD *)(v26 - 8);
      v206 = (_QWORD *)v28;
      if ( v28 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v28 + 32),
          &result,
          v25,
          v24->StringContext.SWFVersion > 6u);
        if ( result.pHash && (v29 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v29->SizeMask )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)&v29[3 * result.Index + 2],
            &v,
            (__int64)v17);
        }
        else
        {
          result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v25;
          result.Index = (__int64)&v;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v28 + 32),
            (void *)(v28 + 32),
            (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
            v25->pNode->HashFlags);
        }
        v17 = key.pStr;
      }
      if ( v28 )
      {
        v30 = *(_DWORD *)(v28 + 24);
        if ( v30 & 0x3FFFFFF )
        {
          *(_DWORD *)(v28 + 24) = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v28);
        }
      }
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
    }
    if ( v23 >= 6 )
    {
      v31 = v1->CurLocalFrame.pObject;
      if ( v31 )
        v31->SuperThis = (Scaleform::GFx::AS2::ObjectInterface *)v17;
    }
    if ( v1->CurLocalFrame.pObject )
    {
      v32 = v1->mFnCall->Env;
      if ( v32 )
      {
        if ( v23 >= 5 )
        {
          if ( v1->pOurEnv != v32 )
          {
            v33 = v32->Target;
            if ( v33 )
              ++v33->RefCount;
            v34 = (Scaleform::RefCountNTSImpl *)&v1->FnEnvCh.pObject->vfptr;
            if ( v34 )
              Scaleform::RefCountNTSImpl::Release(v34);
            v1->FnEnvCh.pObject = v33;
          }
          v1->CurLocalFrame.pObject->Env = v1->mFnCall->Env;
          v1->CurLocalFrame.pObject->NArgs = v1->mFnCall->NArgs;
          v1->CurLocalFrame.pObject->FirstArgBottomIndex = v1->mFnCall->FirstArgBottomIndex;
          v35 = Scaleform::GFx::AS2::Environment::CallTop(v1->pOurEnv, &v, 0);
          Scaleform::GFx::AS2::Value::operator=(&v1->CurLocalFrame.pObject->Callee, v35, (__int64)v17);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
          v36 = Scaleform::GFx::AS2::Environment::CallTop(v1->pOurEnv, &v, 1);
          Scaleform::GFx::AS2::Value::operator=(&v1->CurLocalFrame.pObject->Caller, v36, (__int64)v17);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
    }
    v37 = v1->pThis->Args.Data.Size;
    v38 = v1->mFnCall;
    if ( v38->NArgs < (signed int)v37 )
      LODWORD(v37) = v38->NArgs;
    for ( i = 0; i < (signed int)v37; ++i )
    {
      v40 = v1->mFnCall;
      v41 = v40->FirstArgBottomIndex - i;
      v42 = v40->Env;
      v43 = 0i64;
      if ( v41 <= 32 * ((unsigned int)v42->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v42->Stack.pCurrent - (char *)v42->Stack.pPageStart) >> 5) )
        v43 = &v42->Stack.Pages.Data.Data[v41 >> 5]->Values[v41 & 0x1F];
      v44 = &v1->pThis->Args.Data.Data[i].Name;
      v45 = v1->pOurEnv;
      v46 = (signed __int64)&v45->LocalFrames.Data.Data[v45->LocalFrames.Data.Size];
      v47 = *(_QWORD *)(v46 - 8);
      if ( v47 )
        *(_DWORD *)(v47 + 24) = (*(_DWORD *)(v47 + 24) + 1) & 0x8FFFFFFF;
      v48 = *(_QWORD *)(v46 - 8);
      key.pStr = (Scaleform::GFx::ASString *)v48;
      if ( v48 )
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v48 + 32),
          v44,
          v43,
          v45->StringContext.SWFVersion > 6u);
      if ( v48 )
      {
        v49 = *(_DWORD *)(v48 + 24);
        if ( v49 & 0x3FFFFFF )
        {
          *(_DWORD *)(v48 + 24) = v49 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v48);
        }
      }
    }
    v50 = SLODWORD(v1->pThis->Args.Data.Size);
    if ( i < v50 )
    {
      v51 = i;
      v52 = v50 - i;
      do
      {
        v.T.Type = 0;
        v53 = &v1->pThis->Args.Data.Data[v51].Name;
        v54 = v1->pOurEnv;
        v55 = (signed __int64)&v54->LocalFrames.Data.Data[v54->LocalFrames.Data.Size];
        v56 = *(_QWORD *)(v55 - 8);
        if ( v56 )
          *(_DWORD *)(v56 + 24) = (*(_DWORD *)(v56 + 24) + 1) & 0x8FFFFFFF;
        v57 = *(_QWORD *)(v55 - 8);
        v206 = (_QWORD *)v57;
        if ( v57 )
        {
          v58 = v57 + 32;
          if ( v54->StringContext.SWFVersion <= 6u )
          {
            key.pStr = v53;
            if ( !v53->pNode->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v53->pNode);
            if ( *(_QWORD *)v58
              && (v61 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v57 + 32),
                          &key,
                          v53->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v58 + 8i64)),
                  v61 >= 0) )
            {
              v197 = v57 + 32;
              v198 = v61;
            }
            else
            {
              v197 = 0i64;
              v198 = 0i64;
            }
            v60 = &v197;
          }
          else
          {
            if ( *(_QWORD *)v58
              && (v59 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v57 + 32),
                          v53,
                          v53->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v58 + 8i64)),
                  v59 >= 0) )
            {
              v200 = (_QWORD *)(v57 + 32);
              v201 = v59;
            }
            else
            {
              v200 = 0i64;
              v201 = 0i64;
            }
            v60 = (__int64 *)&v200;
          }
          v62 = v60[1];
          if ( *v60 && (v63 = *(_QWORD *)*v60) != 0 && v62 <= *(_QWORD *)(v63 + 8) )
          {
            Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)(48 * v62 + v63 + 32), &v, v57);
          }
          else
          {
            result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v53;
            result.Index = (__int64)&v;
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
              (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v57 + 32),
              (void *)(v57 + 32),
              (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
              v53->pNode->HashFlags);
          }
        }
        if ( v57 )
        {
          v64 = *(_DWORD *)(v57 + 24);
          if ( v64 & 0x3FFFFFF )
          {
            *(_DWORD *)(v57 + 24) = v64 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v57);
          }
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        ++v51;
        --v52;
      }
      while ( v52 );
    }
    return;
  }
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->pOurEnv->LocalRegister.Data,
    v1->pOurEnv->LocalRegister.Data.Size + (unsigned __int8)v1->pThis->LocalRegisterCount);
  v65 = v1->pThis->Args.Data.Size;
  v66 = v1->mFnCall;
  if ( v66->NArgs < (signed int)v65 )
    LODWORD(v65) = v66->NArgs;
  v67 = 0i64;
  v68 = (signed int)v65;
  if ( (signed int)v65 > 0 )
  {
    v69 = 0i64;
    do
    {
      v70 = v1->pThis->Args.Data.Data;
      v71 = (unsigned int)v70[v69].Register;
      v72 = v1->mFnCall;
      v73 = v72->Env;
      v74 = v72->FirstArgBottomIndex - v67;
      v75 = v73->Stack.Pages.Data.Size;
      v76 = (_QWORD)((char *)v73->Stack.pCurrent - (char *)v73->Stack.pPageStart) >> 5;
      if ( (_DWORD)v71 )
      {
        v78 = 0i64;
        if ( v74 <= 32 * ((signed int)v75 - 1) + (signed int)v76 )
          v78 = &v73->Stack.Pages.Data.Data[v74 >> 5]->Values[v74 & 0x1F];
        v79 = v1->pOurEnv;
        v80 = v79->LocalRegister.Data.Size;
        if ( v71 < v80 )
        {
          v81 = &v79->LocalRegister.Data.Data[v80 - v71 - 1];
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
            "Invalid local register %d, stack only has %d entries",
            v71,
            (unsigned int)v80);
          v81 = v79->GlobalRegister;
        }
        Scaleform::GFx::AS2::Value::operator=(v81, v78, v67);
      }
      else
      {
        v77 = 0i64;
        if ( v74 <= 32 * ((signed int)v75 - 1) + (signed int)v76 )
          v77 = &v73->Stack.Pages.Data.Data[v74 >> 5]->Values[v74 & 0x1F];
        Scaleform::GFx::AS2::Environment::AddLocal(v1->pOurEnv, &v70[(signed int)v67].Name, v77);
      }
      v67 = (unsigned int)(v67 + 1);
      ++v69;
      --v68;
    }
    while ( v68 );
  }
  v82 = SLODWORD(v1->pThis->Args.Data.Size);
  if ( (signed int)v67 < v82 )
  {
    v83 = (signed int)v67;
    v84 = v82 - (signed int)v67;
    do
    {
      if ( !v1->pThis->Args.Data.Data[v83].Register )
      {
        v.T.Type = 0;
        v85 = &v1->pThis->Args.Data.Data[(signed int)v67].Name;
        v86 = v1->pOurEnv;
        v87 = (signed __int64)&v86->LocalFrames.Data.Data[v86->LocalFrames.Data.Size];
        v88 = *(_QWORD *)(v87 - 8);
        if ( v88 )
          *(_DWORD *)(v88 + 24) = (*(_DWORD *)(v88 + 24) + 1) & 0x8FFFFFFF;
        v89 = *(_QWORD *)(v87 - 8);
        v206 = (_QWORD *)v89;
        if ( v89 )
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v89 + 32),
            v85,
            &v,
            v86->StringContext.SWFVersion > 6u);
        if ( v89 )
        {
          v90 = *(_DWORD *)(v89 + 24);
          if ( v90 & 0x3FFFFFF )
          {
            *(_DWORD *)(v89 + 24) = v90 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v89);
          }
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
      }
      LODWORD(v67) = v67 + 1;
      ++v83;
      --v84;
    }
    while ( v84 );
  }
  v91 = 0i64;
  v208 = 0i64;
  v92 = v1->pThis->Function2Flags;
  if ( v92 & 0x10 || !(v92 & 0x20) )
  {
    v93 = key.pStr[1].pNode;
    if ( v93 )
      v93->RefCount = (v93->RefCount + 1) & 0x8FFFFFFF;
    v206 = &v93->pData;
    if ( v93 )
    {
      v94 = v1->pMethodName;
      if ( v94 )
      {
        v95 = Scaleform::GFx::AS2::Environment::CreateString(v1->pOurEnv, (Scaleform::GFx::ASString *)&key, v94);
        v96 = v1->pOurEnv;
        v97 = &v93->Size;
        if ( v93 == (Scaleform::GFx::ASStringNode *)-32i64 )
        {
LABEL_158:
          v99 = 0i64;
        }
        else
        {
          while ( !(*(unsigned __int8 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)v97 + 72i64))(
                     v97,
                     &v96->StringContext,
                     v95,
                     0i64) )
          {
            v98 = *((_QWORD *)v97 + 1);
            if ( v98 )
            {
              v97 = (unsigned int *)(v98 + 32);
              if ( v97 )
                continue;
            }
            goto LABEL_158;
          }
          v99 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(v97 - 8);
          if ( v99 )
            v99->RefCount = (v99->RefCount + 1) & 0x8FFFFFFF;
        }
        v197 = (__int64)v99;
        v100 = (Scaleform::GFx::ASStringNode *)key.pStr;
        v101 = LODWORD(key.pStr[3].pNode) == 1;
        --v100->RefCount;
        if ( v101 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v100);
        if ( v99 )
        {
          v99->RefCount = (v99->RefCount + 1) & 0x8FFFFFFF;
          v102 = v93->RefCount;
          if ( v102 & 0x3FFFFFF )
          {
            v93->RefCount = v102 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v93);
          }
          v93 = (Scaleform::GFx::ASStringNode *)v99;
          v206 = &v99->vfptr;
        }
        if ( v99 )
        {
          v103 = v99->RefCount;
          if ( v103 & 0x3FFFFFF )
          {
            v99->RefCount = v103 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v99);
          }
        }
      }
      (*(void (__fastcall **)(unsigned int *, Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *, Scaleform::GFx::AS2::ASStringContext *))(*(_QWORD *)&v93->Size + 112i64))(
        &v93->Size,
        &result,
        &v1->pOurEnv->StringContext);
      v104 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64, _QWORD))(*v207 + 80i64))(
                                           v207,
                                           144i64,
                                           0i64);
      key.pStr = v104;
      if ( v104 )
      {
        Scaleform::GFx::AS2::SuperObject::SuperObject(
          (Scaleform::GFx::AS2::SuperObject *)v104,
          (Scaleform::GFx::AS2::Object *)v93[1].pData,
          (Scaleform::GFx::AS2::ObjectInterface *)v7,
          (Scaleform::GFx::AS2::FunctionRef *)&result);
        v91 = v105;
      }
      else
      {
        v91 = 0i64;
      }
      v208 = v91;
      v106 = v203;
      if ( !(v203 & 2) )
      {
        v107 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)result.pHash;
        if ( result.pHash )
        {
          v108 = (int)result.pHash[3].pTable;
          if ( v108 & 0x3FFFFFF )
          {
            LODWORD(result.pHash[3].pTable) = v108 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v107);
            v106 = v203;
          }
        }
      }
      result.pHash = 0i64;
      if ( !(v106 & 1) )
      {
        v109 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)result.Index;
        if ( result.Index )
        {
          v110 = *(_DWORD *)(result.Index + 24);
          if ( v110 & 0x3FFFFFF )
          {
            *(_DWORD *)(result.Index + 24) = v110 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v109);
          }
        }
      }
      result.Index = 0i64;
    }
    if ( v93 )
    {
      v111 = v93->RefCount;
      if ( v111 & 0x3FFFFFF )
      {
        v93->RefCount = v111 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v93);
      }
    }
  }
  v112 = 1;
  LODWORD(v206) = 1;
  if ( v1->pThis->Function2Flags & 1 )
  {
    if ( v7 )
    {
      v113 = v1->pOurEnv;
      v114 = v113->LocalRegister.Data.Size;
      if ( v114 > 1 )
      {
        v115 = &v113->LocalRegister.Data.Data[v114 - 2];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
          "Invalid local register %d, stack only has %d entries",
          1i64,
          (unsigned int)v114);
        v115 = v113->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(v115, (Scaleform::GFx::AS2::ObjectInterface *)v7);
    }
    else
    {
      v116 = v1->pOurEnv;
      v117 = v116->LocalRegister.Data.Size;
      if ( v117 > 1 )
      {
        v118 = &v116->LocalRegister.Data.Data[v117 - 2];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
          "Invalid local register %d, stack only has %d entries",
          1i64,
          (unsigned int)v117);
        v118 = v116->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::DropRefs(v118);
      v118->T.Type = 0;
    }
    v112 = 2;
    LODWORD(v206) = 2;
  }
  if ( !(v1->pThis->Function2Flags & 2) )
  {
    v.T.Type = 0;
    if ( v7 )
    {
      v119 = (unsigned __int64)((__int64 (__fastcall *)(Scaleform::GFx::ASString *))v7->pNode->pLower)(v7) - 2;
      v120 = v119 < 3;
      v101 = v119 == 3;
      v121.pNode = v7->pNode;
      if ( v120 || v101 )
      {
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v121.pNode->pLower)(v7) - 2 <= 3
          && (v122 = (Scaleform::GFx::DisplayObject *)v7[2].pNode) != 0i64 )
        {
          v123 = (Scaleform::GFx::ASStringNode *)v122->pNameHandle.pObject;
          if ( !v123 )
            v123 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v122);
        }
        else
        {
          v123 = 0i64;
        }
        if ( v.T.Type != 7 || v.V.pStringNode != v123 )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v);
          v.T.Type = 7;
          v.V.pStringNode = v123;
          if ( v123 )
            ++LODWORD(v123->pData);
        }
      }
      else
      {
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v121.pNode->pLower)(v7) - 6 > 0x26 )
          v124 = 0i64;
        else
          v124 = (Scaleform::GFx::AS2::Object *)&v7[-4];
        Scaleform::GFx::AS2::Value::SetAsObject(&v, v124);
      }
    }
    v125 = v1->pOurEnv;
    v126 = (Scaleform::GFx::ASString *)&v125->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
    v127 = (signed __int64)&v125->LocalFrames.Data.Data[v125->LocalFrames.Data.Size];
    v128 = *(_QWORD *)(v127 - 8);
    if ( v128 )
      *(_DWORD *)(v128 + 24) = (*(_DWORD *)(v128 + 24) + 1) & 0x8FFFFFFF;
    v129 = *(_QWORD *)(v127 - 8);
    v197 = v129;
    if ( !v129 )
      goto LABEL_228;
    v130 = v129 + 32;
    if ( v125->StringContext.SWFVersion <= 6u )
    {
      key.pStr = v126;
      if ( !v126->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v126->pNode);
      if ( *(_QWORD *)v130 )
      {
        v131 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                 (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v129 + 32),
                 &key,
                 v126->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v130 + 8i64));
        if ( v131 >= 0 )
        {
          result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v129 + 32);
          goto LABEL_223;
        }
      }
    }
    else if ( *(_QWORD *)v130 )
    {
      v131 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v129 + 32),
               v126,
               v126->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v130 + 8i64));
      if ( v131 >= 0 )
      {
        result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v129 + 32);
LABEL_223:
        result.Index = v131;
        if ( result.pHash && (v132 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v132->SizeMask )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)&v132[3 * result.Index + 2],
            &v,
            (__int64)v91);
        }
        else
        {
          result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v126;
          result.Index = (__int64)&v;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v129 + 32),
            (void *)(v129 + 32),
            (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
            v126->pNode->HashFlags);
        }
LABEL_228:
        if ( v129 )
        {
          v133 = *(_DWORD *)(v129 + 24);
          if ( v133 & 0x3FFFFFF )
          {
            *(_DWORD *)(v129 + 24) = v133 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v129);
          }
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        goto LABEL_233;
      }
    }
    v131 = 0i64;
    result.pHash = 0i64;
    goto LABEL_223;
  }
LABEL_233:
  v134 = 0i64;
  v197 = 0i64;
  v135 = v1->pThis->Function2Flags;
  if ( v135 & 4 || !(v135 & 8) )
  {
    v136 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64, _QWORD))(*v207 + 80i64))(
                                         v207,
                                         144i64,
                                         0i64);
    key.pStr = v136;
    if ( v136 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v136, v1->pOurEnv);
      v134 = v137;
    }
    else
    {
      v134 = 0i64;
    }
    v197 = v134;
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v134, v1->mFnCall->NArgs);
    v138 = 0;
    v139 = 0i64;
    if ( v1->mFnCall->NArgs > 0 )
    {
      v207 = (_QWORD *)v134;
      do
      {
        v140 = v1->mFnCall;
        v141 = v140->FirstArgBottomIndex - v138;
        v142 = v140->Env;
        v143 = 0i64;
        if ( v141 <= 32 * ((unsigned int)v142->Stack.Pages.Data.Size - 1)
                   + (unsigned int)((_QWORD)((char *)v142->Stack.pCurrent - (char *)v142->Stack.pPageStart) >> 5) )
          v143 = &v142->Stack.Pages.Data.Data[v141 >> 5]->Values[v141 & 0x1F];
        if ( v139 >= 0 && v138 < *(_DWORD *)(v134 + 112) )
        {
          *(_BYTE *)(v134 + 140) = 0;
          if ( !*(_QWORD *)(*(_QWORD *)(v134 + 104) + 8 * v139) )
          {
            LODWORD(key.pStr) = 323;
            v144 = (_BYTE *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              (const void *)v134,
                              32ui64,
                              (Scaleform::AllocInfo *)&key);
            v145 = v144;
            v200 = v144;
            if ( v144 )
              *v144 = 0;
            else
              v145 = 0i64;
            *(_QWORD *)(*(_QWORD *)(v134 + 104) + 8 * v139) = v145;
          }
          Scaleform::GFx::AS2::Value::operator=(
            *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v134 + 104) + 8 * v139),
            v143,
            (__int64)v91);
        }
        ++v138;
        ++v139;
      }
      while ( v138 < v1->mFnCall->NArgs );
    }
  }
  if ( v1->pThis->Function2Flags & 4 )
  {
    v146 = v1->pOurEnv;
    v147 = v146->LocalRegister.Data.Size;
    if ( v112 < v147 )
    {
      v148 = &v146->LocalRegister.Data.Data[v147 - v112 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
        "Invalid local register %d, stack only has %d entries",
        v112,
        (unsigned int)v147);
      v148 = v146->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v148, (Scaleform::GFx::AS2::Object *)v134);
    LODWORD(v206) = v112 + 1;
  }
  if ( !(v1->pThis->Function2Flags & 8) )
  {
    Scaleform::GFx::AS2::Value::Value(&v, (Scaleform::GFx::AS2::Object *)v134);
    v150 = v149;
    key.pStr = v149;
    v151 = v1->pOurEnv;
    v152 = (Scaleform::GFx::ASString *)&v151->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl;
    v153 = (signed __int64)&v151->LocalFrames.Data.Data[v151->LocalFrames.Data.Size];
    v154 = *(_QWORD *)(v153 - 8);
    if ( v154 )
      *(_DWORD *)(v154 + 24) = (*(_DWORD *)(v154 + 24) + 1) & 0x8FFFFFFF;
    v155 = *(_QWORD *)(v153 - 8);
    v207 = (_QWORD *)v155;
    if ( v155 )
    {
      v156 = v155 + 32;
      if ( v151->StringContext.SWFVersion <= 6u )
      {
        key.pStr = v152;
        if ( !v152->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v152->pNode);
        if ( *(_QWORD *)v156
          && (v163 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                       (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v155 + 32),
                       &key,
                       v152->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v156 + 8i64)),
              v163 >= 0) )
        {
          result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v155 + 32);
        }
        else
        {
          v163 = 0i64;
          result.pHash = 0i64;
        }
        result.Index = v163;
      }
      else
      {
        v157 = *(_QWORD *)v156;
        if ( !*(_QWORD *)v156 )
          goto LABEL_270;
        v158 = *(_QWORD *)(v157 + 8);
        v159 = (unsigned int)v158 & v152->pNode->HashFlags;
        v160 = v159;
        v161 = (__int64 *)(48 * v159 + v157 + 16);
        if ( *v161 == -2 || ((unsigned int)v158 & *(_DWORD *)(v161[1] + 28)) != v159 )
          goto LABEL_270;
        while ( 1 )
        {
          v162 = (Scaleform::GFx::ASStringNode *)v161[1];
          if ( ((unsigned int)v158 & v162->HashFlags) == v159 && v162 == v152->pNode )
            break;
          v160 = *v161;
          if ( *v161 == -1 )
            goto LABEL_270;
          v161 = (__int64 *)(48 * v160 + v157 + 16);
        }
        if ( v160 >= 0 )
        {
          result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v155 + 32);
          result.Index = v160;
        }
        else
        {
LABEL_270:
          result.pHash = 0i64;
          result.Index = 0i64;
        }
        v150 = key.pStr;
      }
      if ( result.pHash && (v164 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v164->SizeMask )
      {
        Scaleform::GFx::AS2::Value::operator=(
          (Scaleform::GFx::AS2::Value *)&v164[3 * result.Index + 2],
          (Scaleform::GFx::AS2::Value *)v150,
          (__int64)v91);
      }
      else
      {
        result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v152;
        result.Index = (__int64)v150;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v155 + 32),
          (void *)(v155 + 32),
          (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
          v152->pNode->HashFlags);
      }
    }
    if ( v155 )
    {
      v165 = *(_DWORD *)(v155 + 24);
      if ( v165 & 0x3FFFFFF )
      {
        *(_DWORD *)(v155 + 24) = v165 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v155);
      }
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    LOBYTE(key.pStr) = 7;
    v166 = Scaleform::GFx::AS2::Environment::CallTop(v1->pOurEnv, &v, 0);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString::NoCaseKey *))(*(_QWORD *)(v134 + 32) + 80i64))(
      v134 + 32,
      &v1->pOurEnv->StringContext,
      &v1->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pASSupport,
      v166,
      &key);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    LOBYTE(key.pStr) = 7;
    v167 = Scaleform::GFx::AS2::Environment::CallTop(v1->pOurEnv, &v, 1);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString::NoCaseKey *))(*(_QWORD *)(v134 + 32) + 80i64))(
      v134 + 32,
      &v1->pOurEnv->StringContext,
      &v1->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].AVMVersion,
      v167,
      &key);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( v1->pThis->Function2Flags & 0x10 )
  {
    v168 = v1->pOurEnv;
    v169 = v168->LocalRegister.Data.Size;
    v170 = (signed int)v206;
    if ( (unsigned int)v206 < v169 )
    {
      v171 = &v168->LocalRegister.Data.Data[v169 - (unsigned int)v206 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
        "Invalid local register %d, stack only has %d entries",
        (unsigned int)v206,
        (unsigned int)v169);
      v171 = v168->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v171, v91);
    v172 = v170 + 1;
  }
  else
  {
    v172 = (unsigned int)v206;
  }
  if ( !(v1->pThis->Function2Flags & 0x20) )
  {
    v.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObject(&v, v91);
    v173 = v1->pOurEnv;
    v174 = (Scaleform::GFx::ASString *)v173->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v175 = (signed __int64)&v173->LocalFrames.Data.Data[v173->LocalFrames.Data.Size];
    v176 = *(_QWORD *)(v175 - 8);
    if ( v176 )
      *(_DWORD *)(v176 + 24) = (*(_DWORD *)(v176 + 24) + 1) & 0x8FFFFFFF;
    v177 = *(_QWORD *)(v175 - 8);
    key.pStr = (Scaleform::GFx::ASString *)v177;
    if ( v177 )
      Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
        (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v177 + 32),
        v174 + 101,
        &v,
        v173->StringContext.SWFVersion > 6u);
    if ( v177 )
    {
      v178 = *(_DWORD *)(v177 + 24);
      if ( v178 & 0x3FFFFFF )
      {
        *(_DWORD *)(v177 + 24) = v178 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v177);
      }
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( v1->pThis->Function2Flags & 0x40 )
  {
    v179 = v1->pOurEnv;
    v180 = v179->Target;
    v181 = v179->LocalRegister.Data.Size;
    if ( v172 < v181 )
    {
      v182 = &v179->LocalRegister.Data.Data[v181 - v172 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
        "Invalid local register %d, stack only has %d entries",
        v172,
        (unsigned int)v181);
      v182 = v179->GlobalRegister;
    }
    v183 = (Scaleform::GFx::DisplayObject *)v180->vfptr[68].__vecDelDtor(
                                              (Scaleform::RefCountNTSImplCore *)&v180->vfptr,
                                              0);
    if ( v183 )
    {
      v184 = v183->pNameHandle.pObject;
      if ( !v184 )
        v184 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v183);
    }
    else
    {
      v184 = 0i64;
    }
    if ( v182->T.Type != 7 || v182->V.pCharHandle != v184 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v182);
      v182->T.Type = 7;
      v182->V.pStringNode = (Scaleform::GFx::ASStringNode *)v184;
      if ( v184 )
        ++v184->RefCount;
    }
    ++v172;
  }
  if ( SLOBYTE(v1->pThis->Function2Flags) < 0 )
  {
    v.T.Type = 0;
    LODWORD(excludeFlags[0]) = 0;
    powner = 0i64;
    ppnewTarget = 0i64;
    Scaleform::GFx::AS2::Environment::GetVariable(
      v1->pOurEnv,
      (Scaleform::GFx::ASString *)&v1->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].AVMVersion,
      &v,
      0i64);
    v185 = v1->pOurEnv;
    v186 = v185->LocalRegister.Data.Size;
    if ( v172 < v186 )
    {
      v187 = &v185->LocalRegister.Data.Data[v186 - v172 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr,
        "Invalid local register %d, stack only has %d entries",
        v172,
        (unsigned int)v186,
        0i64,
        0i64,
        excludeFlags[0]);
      v187 = v185->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::operator=(v187, &v, (__int64)v91);
    ++v172;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( v1->pThis->Function2Flags & 0x100 )
  {
    v188 = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v1->pOurEnv->vfptr;
    v189 = (Scaleform::GFx::AS2::Object *)v188[29].vfptr[6].__vecDelDtor;
    v190 = (unsigned __int64)v188[26].vfptr;
    if ( v172 < v190 )
    {
      v191 = (Scaleform::GFx::AS2::Value *)&v188[25].vfptr[2 * (v190 - v172 - 1)];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        v188,
        "Invalid local register %d, stack only has %d entries",
        v172,
        (unsigned int)v190,
        ppnewTarget,
        powner,
        excludeFlags[0]);
      v191 = (Scaleform::GFx::AS2::Value *)&v188[9];
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v191, v189);
  }
  if ( v134 )
  {
    v192 = *(_DWORD *)(v134 + 24);
    if ( v192 & 0x3FFFFFF )
    {
      *(_DWORD *)(v134 + 24) = v192 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v134);
    }
  }
  if ( v91 )
  {
    v193 = v91->RefCount;
    if ( v193 & 0x3FFFFFF )
    {
      v91->RefCount = v193 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v91->vfptr);
    }
  }
}eGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v91->vfptr);
    }
  }
}

// File Line: 568
// RVA: 0x6DD250
void __fastcall Scaleform::GFx::AS2::InvokeContext::Cleanup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::InvokeContext *v1; // rbx
  Scaleform::GFx::AS2::Object *v2; // rdi
  signed __int64 v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *v5; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->PassedThisObj.pObject;
  if ( v2 )
  {
    v3 = (signed __int64)&v2->vfptr;
    if ( v3 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v3 + 120i64))(v3) )
        Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)(v3 - 32));
    }
  }
  if ( v1->pThis->ExecType != 2 || !(v1->pThis->Function2Flags & 2) )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::SetLocal(
      v1->pOurEnv,
      (Scaleform::GFx::ASString *)&v1->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20],
      &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( v1->pThis->ExecType != 2 || !(v1->pThis->Function2Flags & 0x20) )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::SetLocal(
      v1->pOurEnv,
      (Scaleform::GFx::ASString *)&v1->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].RefCount,
      &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->pOurEnv->LocalFrames,
    (unsigned int)v1->LocalStackTop);
  if ( v1->pThis->ExecType == 2 )
    Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v1->pOurEnv->LocalRegister.Data,
      v1->pOurEnv->LocalRegister.Data.Size - (unsigned __int8)v1->pThis->LocalRegisterCount);
  v4 = v1->pOurEnv;
  if ( v4 )
  {
    v5 = &v4->CallStack;
    v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5->pCurrent->pObject;
    if ( v6 )
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    --v5->pCurrent;
    if ( v5->pCurrent < v5->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(v5);
  }
}

// File Line: 604
// RVA: 0x6FDFB0
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::Invoke(Scaleform::GFx::AS2::AsFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn, Scaleform::GFx::AS2::LocalFrame *localFrame, const char *pmethodName)
{
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::AsFunctionObject *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r8
  unsigned __int16 v7; // cx
  Scaleform::GFx::AS2::LocalFrame *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::Object *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::InvokeContext v12; // [rsp+50h] [rbp-68h]

  v4 = fn;
  v5 = this;
  v12.pThis = this;
  v12.mFnCall = fn;
  v12.pLocalFrame = localFrame;
  v12.pMethodName = pmethodName;
  v12.TargetCh.pObject = 0i64;
  v12.FnEnvCh.pObject = 0i64;
  v12.PassedThisCh.pObject = 0i64;
  v12.PassedThisObj.pObject = 0i64;
  v12.CurLocalFrame.pObject = 0i64;
  v6 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AsFunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *))this->vfptr[3].ExecuteForEachChild_GC)(
                                             this,
                                             fn,
                                             &v12.TargetCh);
  v12.pOurEnv = v6;
  if ( (LOBYTE(v6->Target->Flags) >> 4) & 1 )
  {
    v6 = v4->Env;
    v12.pOurEnv = v4->Env;
  }
  v7 = v6->FuncCallNestingLevel;
  v6->FuncCallNestingLevel = v7 + 1;
  if ( v7 < 0xFFu )
  {
    Scaleform::GFx::AS2::InvokeContext::Setup(&v12);
    Scaleform::GFx::AS2::ActionBuffer::Execute(
      v5->pActionBuffer.pObject,
      v12.pOurEnv,
      v5->StartPc,
      v5->Length,
      v4->Result,
      &v5->WithStack,
      (Scaleform::GFx::AS2::ActionBuffer::ExecuteType)(unsigned __int8)v5->ExecType);
    Scaleform::GFx::AS2::InvokeContext::Cleanup(&v12);
  }
  --v12.pOurEnv->FuncCallNestingLevel;
  v8 = v12.CurLocalFrame.pObject;
  if ( v12.CurLocalFrame.pObject )
  {
    v9 = v12.CurLocalFrame.pObject->RefCount;
    if ( v9 & 0x3FFFFFF )
    {
      v12.CurLocalFrame.pObject->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr);
    }
  }
  v10 = v12.PassedThisObj.pObject;
  if ( v12.PassedThisObj.pObject )
  {
    v11 = v12.PassedThisObj.pObject->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v12.PassedThisObj.pObject->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
  if ( v12.PassedThisCh.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12.PassedThisCh.pObject->vfptr);
  if ( v12.FnEnvCh.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12.FnEnvCh.pObject->vfptr);
  if ( v12.TargetCh.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12.TargetCh.pObject->vfptr);
}

// File Line: 669
// RVA: 0x6DAA70
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::Assign(Scaleform::GFx::AS2::FunctionRefBase *this, Scaleform::GFx::AS2::FunctionRefBase *orig)
{
  Scaleform::GFx::AS2::FunctionObject *v2; // rsi
  Scaleform::GFx::AS2::FunctionRefBase *v3; // rdi
  Scaleform::GFx::AS2::FunctionRefBase *v4; // rbx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::FunctionObject *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS2::FunctionObject *v8; // rcx
  Scaleform::GFx::AS2::LocalFrame *v9; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int v11; // eax

  if ( this != orig )
  {
    v2 = this->Function;
    v3 = orig;
    v4 = this;
    if ( !(this->Flags & 2) )
    {
      if ( v2 )
      {
        if ( v2 != orig->Function )
        {
          v5 = v2->RefCount;
          if ( v5 & 0x3FFFFFF )
          {
            v6 = this->Function;
            v2->RefCount = v5 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
          }
        }
      }
    }
    v7 = (v4->Flags & 2) == 0;
    v4->Function = v3->Function;
    if ( v7 )
    {
      v8 = v3->Function;
      if ( v3->Function )
      {
        if ( v2 != v8 )
          v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      }
    }
    v9 = v3->pLocalFrame;
    if ( v9 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v4, v9, v3->Flags & 1);
    }
    else
    {
      v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pLocalFrame->vfptr;
      if ( v10 && !(v4->Flags & 1) )
      {
        v11 = v10->RefCount;
        if ( v11 & 0x3FFFFFF )
        {
          v10->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
        }
      }
      v4->Flags &= 0xFEu;
      v4->pLocalFrame = 0i64;
    }
  }
}

// File Line: 706
// RVA: 0x714F10
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(Scaleform::GFx::AS2::FunctionRefBase *this, Scaleform::GFx::AS2::LocalFrame *localFrame, bool internal)
{
  Scaleform::GFx::AS2::FunctionRefBase *v3; // rbx
  Scaleform::GFx::AS2::LocalFrame *v4; // rcx
  bool v5; // si
  Scaleform::GFx::AS2::LocalFrame *v6; // rdi
  unsigned int v7; // eax

  v3 = this;
  v4 = this->pLocalFrame;
  v5 = internal;
  v6 = localFrame;
  if ( v4 )
  {
    if ( !(v3->Flags & 1) )
    {
      v7 = v4->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v4->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
      }
    }
  }
  v3->pLocalFrame = v6;
  if ( v5 )
    v3->Flags |= 1u;
  else
    v3->Flags &= 0xFEu;
  if ( v6 )
  {
    if ( !(v3->Flags & 1) )
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 719
// RVA: 0x6BF8A0
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(Scaleform::GFx::AS2::FunctionRefBase *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::FunctionObject *v2; // rbx
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rdi
  Scaleform::GFx::AS2::FunctionRefBase *v4; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rbx

  v2 = this->Function;
  v3 = prcc;
  v4 = this;
  if ( this->Function )
  {
    if ( --v2->RefCount & 0x3FFFFFF )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(
        prcc,
        (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
      v2->RefCount |= 0x4000000u;
      if ( !((v2->RefCount >> 27) & 1) )
      {
        v2->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v3->pLastPtr->pRCC->Roots.gap0;
        v2->pRCC = v3->pLastPtr->pRCC;
        *(_QWORD *)v3->pLastPtr->pRCC->Roots.gap0 = v2;
        v3->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v2;
        v3->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr;
        v2->RefCount |= 0x8000000u;
      }
    }
  }
  v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pLocalFrame->vfptr;
  if ( v5 )
  {
    if ( --v5->RefCount & 0x3FFFFFF )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(v3, v5);
      v5->RefCount |= 0x4000000u;
      if ( !((v5->RefCount >> 27) & 1) )
      {
        v5->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v3->pLastPtr->pRCC->Roots.gap0;
        v5->pRCC = v3->pLastPtr->pRCC;
        *(_QWORD *)v3->pLastPtr->pRCC->Roots.gap0 = v5;
        v3->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v5;
        v3->pLastPtr = v5;
        v5->RefCount |= 0x8000000u;
      }
    }
  }
}

// File Line: 748
// RVA: 0x6F94A0
void __fastcall Scaleform::GFx::AS2::FunctionProto::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  unsigned __int64 v2; // r10
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::Value *v6; // rdx
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::CFunctionObject *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rbx
  unsigned int v12; // eax

  v1 = fn;
  if ( fn->NArgs == 1 )
  {
    v2 = (unsigned int)fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)v2 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v5 = &v3->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)v2 >> 5]->Values[v2 & 0x1F];
    if ( v5->T.Type == 8 || v5->T.Type == 11 )
      goto LABEL_21;
    v6 = 0i64;
    if ( (unsigned int)v2 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v6 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    if ( v6->T.Type == 11 )
    {
LABEL_21:
      if ( (unsigned int)v2 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
        v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, v3);
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v8);
    }
    else
    {
      v7 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
      v7->T.Type = 1;
    }
  }
  else
  {
    v9 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   fn,
                                                   104i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v9, v1->Env);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v11);
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
      }
    }
  }
}

// File Line: 772
// RVA: 0x6B4960
void __fastcall Scaleform::GFx::AS2::FunctionProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::ASMovieRootBase *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rax

  v1 = fn->Result;
  v2 = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v1->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 5;
  v3 = (Scaleform::GFx::ASStringNode *)v2[24].pMovieImpl;
  v1->V.pStringNode = v3;
  ++v3->RefCount;
}

// File Line: 777
// RVA: 0x6B49B0
void __fastcall Scaleform::GFx::AS2::FunctionProto::ValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rax

  v1 = fn->ThisPtr;
  if ( v1 )
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&v1[-2]);
  else
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0i64);
}

// File Line: 784
// RVA: 0x6B4090
void __fastcall Scaleform::GFx::AS2::FunctionProto::Apply(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rbx
  Scaleform::RefCountNTSImpl *v3; // rdi
  __int64 v4; // r12
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rsi
  unsigned int v7; // er10
  Scaleform::GFx::AS2::Environment *v8; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::ObjectInterface *v11; // r14
  unsigned int v12; // er9
  Scaleform::GFx::AS2::Environment *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // r10
  Scaleform::GFx::AS2::Object *v15; // rax
  __int64 v16; // r14
  __int64 v17; // r15
  __int64 v18; // rbx
  Scaleform::GFx::AS2::Value *v19; // rdx
  Scaleform::GFx::AS2::Environment *v20; // r14
  Scaleform::GFx::AS2::Environment *v21; // r8
  int v22; // edx
  char v23; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // r14
  Scaleform::GFx::AS2::Environment *v29; // r8
  int v30; // edx
  char v31; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v34; // rcx
  unsigned int v35; // eax
  unsigned int v36; // eax
  Scaleform::GFx::AS2::Environment *v37; // r14
  Scaleform::GFx::AS2::Value *v38; // rcx
  unsigned int v39; // eax
  unsigned int v40; // eax
  Scaleform::GFx::AS2::Value *v; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::AS2::Value *va; // [rsp+20h] [rbp-69h]
  void **v43; // [rsp+28h] [rbp-61h]
  Scaleform::GFx::AS2::Value *v44; // [rsp+30h] [rbp-59h]
  __int64 v45; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v47; // [rsp+48h] [rbp-41h]
  char v48; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Environment *v49; // [rsp+58h] [rbp-31h]
  int v50; // [rsp+60h] [rbp-29h]
  int v51; // [rsp+64h] [rbp-25h]
  __int64 v52; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::AS2::Value v53; // [rsp+70h] [rbp-19h]
  __int64 v54; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS2::Value *v55; // [rsp+98h] [rbp+Fh]
  __int64 v56; // [rsp+F0h] [rbp+67h]
  signed __int64 v57; // [rsp+F8h] [rbp+6Fh]

  v54 = -2i64;
  v1 = fn;
  v2 = 0i64;
  v57 = 0i64;
  v3 = 0i64;
  v56 = 0i64;
  LODWORD(v4) = 0;
  v5 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v5->T.Type = 0;
  v6 = 0i64;
  v52 = 0i64;
  if ( v1->NArgs >= 1 )
  {
    v7 = v1->FirstArgBottomIndex;
    v8 = v1->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObjectInterface(v9, v8);
    v11 = v10;
    v56 = (__int64)v10;
    if ( v10 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->vfptr->gap8[8])(v10) - 2 > 3 )
      {
        v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11[-2];
        v57 = (signed __int64)&v11[-2];
        if ( v11 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
          v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
      }
      else if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v11->vfptr->gap8[8])(v11) - 2 > 3 )
      {
        v3 = 0i64;
      }
      else
      {
        v3 = (Scaleform::RefCountNTSImpl *)v11[1].vfptr;
        if ( v3 )
          ++v3->RefCount;
      }
    }
  }
  if ( v1->NArgs >= 2 )
  {
    v12 = v1->FirstArgBottomIndex - 1;
    v13 = v1->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v13);
    v16 = (__int64)v15;
    if ( v15 )
    {
      if ( (*(unsigned int (**)(void))&v15->vfptr->gap8[8])() == 7 )
      {
        *(_DWORD *)(v16 + 24) = (*(_DWORD *)(v16 + 24) + 1) & 0x8FFFFFFF;
        v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v16;
        v52 = v16;
        v4 = *(_QWORD *)(v16 + 112);
        if ( (signed int)v4 > 0 )
        {
          v17 = (signed int)v4 - 1;
          if ( (signed int)v4 - 1 >= 0 )
          {
            v18 = v16;
            do
            {
              v19 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v18 + 104) + 8 * v17);
              va = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v18 + 104) + 8 * v17);
              v20 = v1->Env;
              ++v20->Stack.pCurrent;
              if ( v20->Stack.pCurrent >= v20->Stack.pPageEnd )
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v20->Stack);
                v19 = va;
              }
              v = v20->Stack.pCurrent;
              v55 = v20->Stack.pCurrent;
              if ( v55 )
                Scaleform::GFx::AS2::Value::Value(v55, v19);
              --v17;
            }
            while ( v17 >= 0 );
            v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v57;
          }
        }
      }
    }
  }
  v53.T.Type = 0;
  if ( v1->ThisFunctionRef.Function )
  {
    v21 = v1->Env;
    v22 = ((_QWORD)((char *)v21->Stack.pCurrent - (char *)v21->Stack.pPageStart) >> 5)
        + 32 * v21->Stack.Pages.Data.Size
        - 32;
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v44 = &v53;
    v45 = v56;
    v48 = 0;
    v46 = 0i64;
    v47 = 0i64;
    v49 = v21;
    v50 = v4;
    v51 = v22;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD, Scaleform::GFx::AS2::Value *, void **, Scaleform::GFx::AS2::Value *, __int64))v1->ThisFunctionRef.Function->vfptr[3].Finalize_GC)(
      v1->ThisFunctionRef.Function,
      &v43,
      v1->ThisFunctionRef.pLocalFrame,
      0i64,
      v,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v53,
      v56);
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v23 = v48;
    if ( !(v48 & 2) )
    {
      v24 = v46;
      if ( v46 )
      {
        v25 = v46->RefCount;
        if ( v25 & 0x3FFFFFF )
        {
          v46->RefCount = v25 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          v23 = v48;
        }
      }
    }
    v46 = 0i64;
    if ( !(v23 & 1) )
    {
      v26 = v47;
      if ( v47 )
      {
        v27 = v47->RefCount;
        if ( v27 & 0x3FFFFFF )
        {
          v47->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
        }
      }
    }
    v47 = 0i64;
    v43 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  }
  else
  {
    v28 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v1->ThisPtr;
    if ( v28 )
    {
      --v28;
      if ( v28 )
        v28->RefCount = (v28->RefCount + 1) & 0x8FFFFFFF;
    }
    v29 = v1->Env;
    v30 = ((_QWORD)((char *)v29->Stack.pCurrent - (char *)v29->Stack.pPageStart) >> 5)
        + 32 * v29->Stack.Pages.Data.Size
        - 32;
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v44 = &v53;
    v45 = v56;
    v48 = 0;
    v46 = 0i64;
    v47 = 0i64;
    v49 = v29;
    v50 = v4;
    v51 = v30;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, void ***, _QWORD, _QWORD, Scaleform::GFx::AS2::Value *, void **, Scaleform::GFx::AS2::Value *, __int64))v28->vfptr[3].Finalize_GC)(
      v28,
      &v43,
      0i64,
      0i64,
      v,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v53,
      v56);
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v31 = v48;
    if ( !(v48 & 2) )
    {
      v32 = v46;
      if ( v46 )
      {
        v33 = v46->RefCount;
        if ( v33 & 0x3FFFFFF )
        {
          v46->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
          v31 = v48;
        }
      }
    }
    v46 = 0i64;
    if ( !(v31 & 1) )
    {
      v34 = v47;
      if ( v47 )
      {
        v35 = v47->RefCount;
        if ( v35 & 0x3FFFFFF )
        {
          v47->RefCount = v35 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
        }
      }
    }
    v47 = 0i64;
    v43 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v36 = v28->RefCount;
    if ( v36 & 0x3FFFFFF )
    {
      v28->RefCount = v36 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
    }
  }
  if ( (signed int)v4 > 0 )
  {
    v37 = v1->Env;
    do
    {
      v38 = v37->Stack.pCurrent;
      if ( v38->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v38);
      --v37->Stack.pCurrent;
      if ( v37->Stack.pCurrent < v37->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v37->Stack);
      LODWORD(v4) = v4 - 1;
    }
    while ( (_DWORD)v4 );
  }
  Scaleform::GFx::AS2::Value::operator=(v1->Result, &v53);
  if ( v53.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v53);
  if ( v6 )
  {
    v39 = v6->RefCount;
    if ( v39 & 0x3FFFFFF )
    {
      v6->RefCount = v39 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  if ( v2 )
  {
    v40 = v2->RefCount;
    if ( v40 & 0x3FFFFFF )
    {
      v2->RefCount = v40 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
}

// File Line: 847
// RVA: 0x6B4540
void __fastcall Scaleform::GFx::AS2::FunctionProto::Call(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rbx
  Scaleform::RefCountNTSImpl *v3; // rdi
  int v4; // er12
  Scaleform::GFx::AS2::Value *v5; // rsi
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // r14
  signed int v11; // eax
  int i; // er15
  unsigned int v13; // edx
  Scaleform::GFx::AS2::Environment *v14; // rsi
  Scaleform::GFx::AS2::Value *v15; // r14
  Scaleform::GFx::AS2::Value *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // r8
  int v18; // edx
  char v19; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rsi
  Scaleform::GFx::AS2::Environment *v25; // r8
  int v26; // edx
  char v27; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // rcx
  unsigned int v31; // eax
  unsigned int v32; // eax
  Scaleform::GFx::AS2::Environment *v33; // rsi
  Scaleform::GFx::AS2::Value *v34; // rcx
  unsigned int v35; // eax
  void **v36; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::AS2::Value *v37; // [rsp+28h] [rbp-61h]
  __int64 v38; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v39; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v40; // [rsp+40h] [rbp-49h]
  char v41; // [rsp+48h] [rbp-41h]
  Scaleform::GFx::AS2::Environment *v42; // [rsp+50h] [rbp-39h]
  int v43; // [rsp+58h] [rbp-31h]
  int v44; // [rsp+5Ch] [rbp-2Dh]
  void *v45; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::Value v; // [rsp+68h] [rbp-21h]
  __int64 v47; // [rsp+88h] [rbp-1h]
  Scaleform::GFx::AS2::Value *v48; // [rsp+90h] [rbp+7h]
  __int64 v49; // [rsp+F0h] [rbp+67h]

  v47 = -2i64;
  v1 = fn;
  v2 = 0i64;
  v3 = 0i64;
  v49 = 0i64;
  v4 = 0;
  v5 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v5->T.Type = 0;
  if ( v1->NArgs >= 1 )
  {
    v6 = v1->FirstArgBottomIndex;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v8, v7);
    v10 = v9;
    v49 = (__int64)v9;
    if ( v9 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v9->vfptr->gap8[8])(v9) - 2 > 3 )
      {
        v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10[-2];
        if ( v10 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
          v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
      }
      else if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->vfptr->gap8[8])(v10) - 2 > 3 )
      {
        v3 = 0i64;
      }
      else
      {
        v3 = (Scaleform::RefCountNTSImpl *)v10[1].vfptr;
        if ( v3 )
          ++v3->RefCount;
      }
    }
  }
  v11 = v1->NArgs;
  if ( v11 >= 2 )
  {
    v4 = v11 - 1;
    for ( i = v11 - 1; i >= 1; --i )
    {
      v13 = v1->FirstArgBottomIndex - i;
      v14 = v1->Env;
      v15 = 0i64;
      if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
        v15 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
      ++v14->Stack.pCurrent;
      if ( v14->Stack.pCurrent >= v14->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v14->Stack);
      v16 = v14->Stack.pCurrent;
      v48 = v16;
      v45 = v16;
      if ( v16 )
        Scaleform::GFx::AS2::Value::Value(v16, v15);
    }
  }
  v.T.Type = 0;
  if ( v1->ThisFunctionRef.Function )
  {
    v17 = v1->Env;
    v18 = ((_QWORD)((char *)v17->Stack.pCurrent - (char *)v17->Stack.pPageStart) >> 5)
        + 32 * v17->Stack.Pages.Data.Size
        - 32;
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v37 = &v;
    v38 = v49;
    v41 = 0;
    v39 = 0i64;
    v40 = 0i64;
    v42 = v17;
    v43 = v4;
    v44 = v18;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD, void **, Scaleform::GFx::AS2::Value *, __int64))v1->ThisFunctionRef.Function->vfptr[3].Finalize_GC)(
      v1->ThisFunctionRef.Function,
      &v36,
      v1->ThisFunctionRef.pLocalFrame,
      0i64,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v,
      v49);
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v19 = v41;
    if ( !(v41 & 2) )
    {
      v20 = v39;
      if ( v39 )
      {
        v21 = v39->RefCount;
        if ( v21 & 0x3FFFFFF )
        {
          v39->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
          v19 = v41;
        }
      }
    }
    v39 = 0i64;
    if ( !(v19 & 1) )
    {
      v22 = v40;
      if ( v40 )
      {
        v23 = v40->RefCount;
        if ( v23 & 0x3FFFFFF )
        {
          v40->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
        }
      }
    }
    v40 = 0i64;
    v36 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  }
  else
  {
    v24 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v1->ThisPtr;
    if ( v24 )
    {
      --v24;
      if ( v24 )
        v24->RefCount = (v24->RefCount + 1) & 0x8FFFFFFF;
    }
    v45 = v24;
    v25 = v1->Env;
    v26 = ((_QWORD)((char *)v25->Stack.pCurrent - (char *)v25->Stack.pPageStart) >> 5)
        + 32 * v25->Stack.Pages.Data.Size
        - 32;
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v37 = &v;
    v38 = v49;
    v41 = 0;
    v39 = 0i64;
    v40 = 0i64;
    v42 = v25;
    v43 = v4;
    v44 = v26;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, void ***, _QWORD, _QWORD, void **, Scaleform::GFx::AS2::Value *, __int64))v24->vfptr[3].Finalize_GC)(
      v24,
      &v36,
      0i64,
      0i64,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v,
      v49);
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v27 = v41;
    if ( !(v41 & 2) )
    {
      v28 = v39;
      if ( v39 )
      {
        v29 = v39->RefCount;
        if ( v29 & 0x3FFFFFF )
        {
          v39->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
          v27 = v41;
        }
      }
    }
    v39 = 0i64;
    if ( !(v27 & 1) )
    {
      v30 = v40;
      if ( v40 )
      {
        v31 = v40->RefCount;
        if ( v31 & 0x3FFFFFF )
        {
          v40->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
        }
      }
    }
    v40 = 0i64;
    v36 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v32 = v24->RefCount;
    if ( v32 & 0x3FFFFFF )
    {
      v24->RefCount = v32 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
    }
  }
  if ( v4 > 0 )
  {
    v33 = v1->Env;
    do
    {
      v34 = v33->Stack.pCurrent;
      if ( v34->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v34);
      --v33->Stack.pCurrent;
      if ( v33->Stack.pCurrent < v33->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v33->Stack);
      --v4;
    }
    while ( v4 );
  }
  Scaleform::GFx::AS2::Value::operator=(v1->Result, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  if ( v2 )
  {
    v35 = v2->RefCount;
    if ( v35 & 0x3FFFFFF )
    {
      v2->RefCount = v35 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
}ue::DropRefs(&v);
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  if ( v2 )
  {
    v3

