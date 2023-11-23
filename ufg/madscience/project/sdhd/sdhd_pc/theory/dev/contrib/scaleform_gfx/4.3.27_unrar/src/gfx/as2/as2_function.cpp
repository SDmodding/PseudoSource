// File Line: 106
// RVA: 0x6D1540
void __fastcall Scaleform::GFx::AS2::FunctionObject::~FunctionObject(Scaleform::GFx::AS2::FunctionObject *this)
{
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 110
// RVA: 0x71B170
void __fastcall Scaleform::GFx::AS2::FunctionObject::SetPrototype(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASStringNode *pprototype)
{
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::Value v6; // [rsp+38h] [rbp-30h] BYREF
  char v7; // [rsp+70h] [rbp+8h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v6, pprototype);
  v7 = 0;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v5,
    (Scaleform::GFx::AS2::PropFlags *)&v7);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
}

// File Line: 116
// RVA: 0x71B000
void __fastcall Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // rsi
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-20h] BYREF

  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  ((void (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__)(&this->Scaleform::GFx::AS2::ObjectInterface);
  Scaleform::GFx::AS2::ObjectInterface::Get_constructor(&pprototype->Scaleform::GFx::AS2::ObjectInterface, &result, psc);
  if ( result.Function )
    Scaleform::GFx::AS2::ObjectInterface::Set_constructor(v5, psc, &result);
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
      v10 = result.pLocalFrame->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}

// File Line: 126
// RVA: 0x7214E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::FunctionObject::ToFunction(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::FunctionRef *result)
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
void __fastcall Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        Scaleform::GFx::AS2::CFunctionObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pFunction = 0i64;
}

// File Line: 176
// RVA: 0x6C7E60
void __fastcall Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        Scaleform::GFx::AS2::CFunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        void (__fastcall *func)(Scaleform::GFx::AS2::FnCall *))
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pFunction = func;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
}

// File Line: 181
// RVA: 0x6D11B0
void __fastcall Scaleform::GFx::AS2::CFunctionObject::~CFunctionObject(Scaleform::GFx::AS2::CFunctionObject *this)
{
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 186
// RVA: 0x6FE130
void __fastcall Scaleform::GFx::AS2::CFunctionObject::Invoke(
        Scaleform::GFx::AS2::CFunctionObject *this,
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::LocalFrame *__formal,
        const char *a4)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rbx
  Scaleform::GFx::AS2::ObjectInterface *vfptr; // rcx
  int FirstArgBottomIndex; // r9d
  int NArgs; // r8d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *Result; // rax
  Scaleform::GFx::AS2::FnCall v12; // [rsp+30h] [rbp-48h] BYREF

  if ( this->pFunction )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, const char *, __int64))ThisPtr->vfptr->IsSuper)(
           fn->ThisPtr,
           fn,
           __formal,
           a4,
           -2i64) )
    {
      vfptr = (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr[5].vfptr;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      NArgs = fn->NArgs;
      Env = fn->Env;
      Result = fn->Result;
      v12.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
      v12.Result = Result;
      v12.ThisPtr = vfptr;
      memset(&v12.ThisFunctionRef, 0, 17);
      v12.Env = Env;
      v12.NArgs = NArgs;
      v12.FirstArgBottomIndex = FirstArgBottomIndex;
      this->pFunction(&v12);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&ThisPtr[-2]);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v12);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, const char *))this->pFunction)(
        fn,
        fn,
        __formal,
        a4);
    }
  }
}

// File Line: 203
// RVA: 0x6EF840
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::GetEnvironment(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  return fn->Env;
}

// File Line: 209
// RVA: 0x7003F0
bool __fastcall Scaleform::GFx::AS2::CFunctionObject::IsEqual(
        Scaleform::GFx::AS2::CFunctionObject *this,
        Scaleform::GFx::AS2::FunctionObject *f)
{
  return ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *))f->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].Finalize_GC)(f)
      && this->pFunction == (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))f[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
}

// File Line: 232
// RVA: 0x6C7360
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ActionBuffer *ab,
        unsigned int start,
        unsigned int length,
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::InteractiveObject *Target; // rbp
  Scaleform::GFx::CharacterHandle *pObject; // rdi
  Scaleform::GFx::CharacterHandle *v15; // rsi

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pMovieRoot = 0i64;
  this->TargetHandle.pObject = 0i64;
  if ( ab )
    ++ab->RefCount;
  this->pActionBuffer.pObject = ab;
  this->WithStack.Data.Data = 0i64;
  this->WithStack.Data.Size = 0i64;
  this->WithStack.Data.Policy.Capacity = 0i64;
  this->StartPc = start;
  this->Length = length;
  v11 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++v11->RefCount;
  this->Args.Data.Data = 0i64;
  this->Args.Data.Size = 0i64;
  this->Args.Data.Policy.Capacity = 0i64;
  this->Args.Data.DefaultValue.Register = 0;
  this->Args.Data.DefaultValue.Name.pNode = v11;
  v12 = ++v11->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  this->Function2Flags = 0;
  *(_WORD *)&this->ExecType = (unsigned __int8)execType;
  if ( pwithStack )
    Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>::operator=(
      &this->WithStack,
      pwithStack);
  if ( (unsigned int)(execType - 3) > 1 )
  {
    Target = penv->Target;
    pObject = Target->pNameHandle.pObject;
    if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(Target)) != 0i64 )
      ++pObject->RefCount;
    v15 = this->TargetHandle.pObject;
    if ( v15 )
    {
      if ( --v15->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v15);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
      }
    }
    this->TargetHandle.pObject = pObject;
    this->pMovieRoot = Target->pASRoot->pMovieImpl;
  }
}

// File Line: 250
// RVA: 0x6E0720
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::CreateNewObject(
        Scaleform::GFx::AS2::ObjectCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *v3; // rax

  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        96i64);
  if ( v3 )
    Scaleform::GFx::AS2::Object::Object(v3, penv);
}

// File Line: 262
// RVA: 0x6EF770
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AsFunctionObject::GetEnvironment(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rdx
  Scaleform::GFx::DisplayObject *v6; // rax
  Scaleform::GFx::AS2::Environment *Env; // rdi
  Scaleform::GFx::InteractiveObject *v8; // rbx
  char *v9; // rcx
  __int64 v10; // rax

  pMovieRoot = this->pMovieRoot;
  if ( pMovieRoot
    && (v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->TargetHandle.pObject, pMovieRoot)) != 0i64 )
  {
    Env = 0i64;
    v8 = 0i64;
    if ( SLOBYTE(v6->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      v8 = (Scaleform::GFx::InteractiveObject *)v6;
    if ( v8 )
      ++v8->RefCount;
  }
  else
  {
    Env = 0i64;
    v8 = 0i64;
  }
  if ( v8 )
  {
    v9 = (char *)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
    v10 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 8i64))(v9);
    Env = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10);
  }
  if ( ptargetCh )
  {
    if ( v8 )
      ++v8->RefCount;
    if ( ptargetCh->pObject )
      Scaleform::RefCountNTSImpl::Release(ptargetCh->pObject);
    ptargetCh->pObject = v8;
  }
  if ( !Env )
    Env = fn->Env;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  return Env;
}

// File Line: 309
// RVA: 0x71E450
void __fastcall Scaleform::GFx::AS2::InvokeContext::Setup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::AsFunctionObject *pThis; // rbx
  Scaleform::GFx::AS2::Environment *pOurEnv; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *p_CallStack; // rdi
  _QWORD *p_pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *ThisPtr; // r12
  Scaleform::GFx::AS2::Environment *v8; // rcx
  Scaleform::GFx::AS2::LocalFrame *NewLocalFrame; // rax
  Scaleform::GFx::AS2::LocalFrame *v10; // rbx
  Scaleform::GFx::AS2::LocalFrame *pObject; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::LocalFrame *v13; // rdi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::ASString *pStr; // rdi
  Scaleform::GFx::InteractiveObject *pNode; // rbx
  Scaleform::GFx::InteractiveObject *v19; // rcx
  Scaleform::GFx::AS2::Object *v20; // rbx
  Scaleform::GFx::AS2::Object *v21; // rcx
  unsigned int v22; // eax
  int SWFVersion; // r15d
  Scaleform::GFx::AS2::Environment *v24; // rdx
  Scaleform::GFx::ASString *v25; // r14
  __int64 v26; // rbx
  __int64 v27; // rcx
  __int64 v28; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // rcx
  int v30; // eax
  Scaleform::GFx::AS2::LocalFrame *v31; // rax
  Scaleform::GFx::AS2::Environment *Env; // rbx
  Scaleform::GFx::InteractiveObject *Target; // rbx
  Scaleform::GFx::InteractiveObject *v34; // rcx
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::AS2::Value *v36; // rax
  unsigned __int64 Size; // r14
  Scaleform::GFx::AS2::FnCall *mFnCall; // rax
  int i; // edi
  Scaleform::GFx::AS2::FnCall *v40; // rax
  unsigned int v41; // edx
  Scaleform::GFx::AS2::Environment *v42; // r9
  Scaleform::GFx::AS2::Value *v43; // r8
  Scaleform::GFx::ASString *p_Name; // rdx
  Scaleform::GFx::AS2::Environment *v45; // r9
  __int64 v46; // rbx
  __int64 v47; // rcx
  __int64 v48; // rbx
  int v49; // eax
  __int64 Size_low; // r12
  __int64 v51; // r15
  __int64 v52; // r12
  Scaleform::GFx::ASString *v53; // r14
  Scaleform::GFx::AS2::Environment *v54; // rdx
  __int64 v55; // rdi
  __int64 v56; // rcx
  __int64 v57; // rdi
  __int64 v58; // rbx
  __int64 v59; // rax
  __int64 *v60; // rax
  signed __int64 v61; // rax
  __int64 v62; // rdx
  __int64 v63; // rcx
  int v64; // eax
  unsigned __int64 v65; // rdx
  Scaleform::GFx::AS2::FnCall *v66; // rax
  int v67; // edi
  __int64 v68; // r13
  __int64 v69; // r15
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // r10
  unsigned __int64 Register; // r8
  Scaleform::GFx::AS2::FnCall *v72; // rax
  Scaleform::GFx::AS2::Environment *v73; // r9
  unsigned int v74; // edx
  unsigned __int64 v75; // rax
  __int64 v76; // rcx
  Scaleform::GFx::AS2::Value *v77; // r8
  Scaleform::GFx::AS2::Value *v78; // r14
  Scaleform::GFx::AS2::Environment *v79; // rbx
  unsigned __int64 v80; // rcx
  Scaleform::GFx::AS2::Value *GlobalRegister; // rcx
  __int64 v82; // r15
  __int64 v83; // r14
  __int64 v84; // r15
  Scaleform::GFx::ASString *v85; // rdx
  Scaleform::GFx::AS2::Environment *v86; // r8
  __int64 v87; // rbx
  __int64 v88; // rcx
  __int64 v89; // rbx
  int v90; // eax
  Scaleform::GFx::ASStringNode *v91; // rdi
  unsigned __int16 Function2Flags; // cx
  Scaleform::GFx::ASStringNode *v93; // rbx
  const char *pMethodName; // r8
  Scaleform::GFx::ASString *String; // r15
  Scaleform::GFx::AS2::Environment *v96; // r14
  unsigned int *p_Size; // rdi
  __int64 v98; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v99; // rdi
  Scaleform::GFx::ASStringNode *v100; // rcx
  unsigned int v102; // eax
  unsigned int v103; // eax
  Scaleform::GFx::ASString *v104; // rax
  Scaleform::GFx::ASStringNode *v105; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int v108; // edx
  Scaleform::GFx::AS2::LocalFrame *v109; // rcx
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // r13d
  Scaleform::GFx::AS2::Environment *v113; // rbx
  unsigned __int64 v114; // rcx
  Scaleform::GFx::AS2::Value *v115; // rcx
  Scaleform::GFx::AS2::Environment *v116; // r14
  unsigned __int64 v117; // rbx
  Scaleform::GFx::AS2::Value *v118; // rbx
  bool v119; // cc
  Scaleform::GFx::ASString v120; // rax
  Scaleform::GFx::DisplayObject *v121; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rbx
  Scaleform::GFx::ASStringNode *v123; // rdx
  Scaleform::GFx::AS2::Environment *v124; // rdx
  Scaleform::GFx::ASString *v125; // r15
  __int64 v126; // r14
  __int64 v127; // rcx
  __int64 v128; // r14
  __int64 v129; // rbx
  Scaleform::GFx::AS2::LocalFrame *v130; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v131; // rcx
  int v132; // eax
  __int64 v133; // rbx
  unsigned __int16 v134; // r8
  Scaleform::GFx::ASString *v135; // rax
  __int64 v136; // rax
  int v137; // r14d
  __int64 v138; // r15
  Scaleform::GFx::AS2::FnCall *v139; // rax
  unsigned int v140; // edx
  Scaleform::GFx::AS2::Environment *v141; // r8
  Scaleform::GFx::AS2::Value *v142; // r12
  _BYTE *v143; // rax
  _BYTE *v144; // rcx
  Scaleform::GFx::AS2::Environment *v145; // r14
  unsigned __int64 v146; // rcx
  Scaleform::GFx::AS2::Value *v147; // rcx
  Scaleform::GFx::ASString *v148; // rax
  Scaleform::GFx::ASString *v149; // r12
  Scaleform::GFx::AS2::Environment *v150; // r8
  Scaleform::GFx::ASString *p_pMovieImpl; // r13
  __int64 v152; // r14
  __int64 v153; // rcx
  __int64 v154; // r14
  __int64 v155; // r15
  __int64 v156; // r10
  __int64 v157; // r11
  Scaleform::GFx::AS2::LocalFrame *v158; // r9
  Scaleform::GFx::AS2::LocalFrame *v159; // rdx
  Scaleform::GFx::AS2::LocalFrame **v160; // r8
  Scaleform::GFx::ASStringNode *v161; // rcx
  Scaleform::GFx::AS2::LocalFrame *v162; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v163; // rcx
  int v164; // eax
  Scaleform::GFx::AS2::Value *v165; // rax
  Scaleform::GFx::AS2::Value *v166; // rax
  Scaleform::GFx::AS2::Environment *v167; // r14
  unsigned __int64 v168; // rcx
  int v169; // r13d
  Scaleform::GFx::AS2::Value *v170; // rcx
  unsigned int v171; // r13d
  Scaleform::GFx::AS2::Environment *v172; // rdx
  Scaleform::GFx::ASString *v173; // r8
  __int64 v174; // r14
  __int64 v175; // rcx
  __int64 v176; // r14
  int v177; // eax
  Scaleform::GFx::AS2::Environment *v178; // r15
  Scaleform::GFx::InteractiveObject *v179; // r12
  unsigned __int64 v180; // r14
  Scaleform::GFx::AS2::Value *v181; // r14
  Scaleform::GFx::DisplayObject *v182; // rax
  Scaleform::GFx::CharacterHandle *v183; // r15
  Scaleform::GFx::AS2::Environment *v184; // r14
  unsigned __int64 v185; // rcx
  Scaleform::GFx::AS2::Value *v186; // rcx
  Scaleform::GFx::AS2::Environment *v187; // rsi
  Scaleform::GFx::ASStringNode *v188; // r14
  unsigned __int64 v189; // rcx
  Scaleform::GFx::AS2::Value *v190; // rcx
  int v191; // eax
  unsigned int v192; // eax
  __int64 v193; // [rsp+40h] [rbp-49h] BYREF
  __int64 v194; // [rsp+48h] [rbp-41h]
  __int64 v195; // [rsp+50h] [rbp-39h]
  _QWORD *v196; // [rsp+58h] [rbp-31h] BYREF
  __int64 v197; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+68h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-9h] BYREF
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+F0h] [rbp+67h] BYREF
  _QWORD *p_pData; // [rsp+F8h] [rbp+6Fh]
  _QWORD *p_vfptr; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::ASStringNode *v203; // [rsp+108h] [rbp+7Fh]

  v195 = -2i64;
  pThis = this->pThis;
  pOurEnv = this->pOurEnv;
  if ( this->pThis )
    pThis->RefCount = (pThis->RefCount + 1) & 0x8FFFFFFF;
  key.pStr = (Scaleform::GFx::ASString *)pThis;
  p_CallStack = &pOurEnv->CallStack;
  if ( ++p_CallStack->pCurrent >= p_CallStack->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PushPage(p_CallStack);
  p_pObject = &p_CallStack->pCurrent->pObject;
  p_pData = p_pObject;
  p_vfptr = p_pObject;
  if ( p_pObject )
  {
    if ( pThis )
      pThis->RefCount = (pThis->RefCount + 1) & 0x8FFFFFFF;
    *p_pObject = pThis;
  }
  if ( pThis )
  {
    RefCount = pThis->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pThis->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pThis);
    }
  }
  ThisPtr = (Scaleform::GFx::ASString *)this->mFnCall->ThisPtr;
  v8 = this->pOurEnv;
  p_vfptr = &v8->StringContext.pContext->pHeap->vfptr;
  v196 = p_vfptr;
  this->LocalStackTop = v8->LocalFrames.Data.Size;
  if ( (unsigned __int8)(this->pThis->ExecType - 1) <= 1u )
  {
    NewLocalFrame = Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(v8);
    v10 = NewLocalFrame;
    if ( NewLocalFrame )
      NewLocalFrame->RefCount = (NewLocalFrame->RefCount + 1) & 0x8FFFFFFF;
    pObject = this->CurLocalFrame.pObject;
    if ( pObject )
    {
      v12 = pObject->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    this->CurLocalFrame.pObject = v10;
    v13 = v10;
    pLocalFrame = this->pLocalFrame;
    if ( pLocalFrame )
      pLocalFrame->RefCount = (pLocalFrame->RefCount + 1) & 0x8FFFFFFF;
    v15 = v13->PrevFrame.pObject;
    if ( v15 )
    {
      v16 = v15->RefCount;
      if ( (v16 & 0x3FFFFFF) != 0 )
      {
        v15->RefCount = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
      }
    }
    v13->PrevFrame.pObject = pLocalFrame;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::AddFrameBarrier(v8);
  }
  pStr = ThisPtr;
  key.pStr = ThisPtr;
  if ( ThisPtr )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))ThisPtr->pNode->pLower)(ThisPtr) - 2 > 3 )
      pNode = 0i64;
    else
      pNode = (Scaleform::GFx::InteractiveObject *)ThisPtr[2].pNode;
    if ( pNode )
      ++pNode->RefCount;
    v19 = this->PassedThisCh.pObject;
    if ( v19 )
      Scaleform::RefCountNTSImpl::Release(v19);
    this->PassedThisCh.pObject = pNode;
    v20 = (Scaleform::GFx::AS2::Object *)&ThisPtr[-4];
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))ThisPtr->pNode->pLower)(ThisPtr) - 6 > 0x26 )
      v20 = 0i64;
    if ( v20 )
      v20->RefCount = (v20->RefCount + 1) & 0x8FFFFFFF;
    v21 = this->PassedThisObj.pObject;
    if ( v21 )
    {
      v22 = v21->RefCount;
      if ( (v22 & 0x3FFFFFF) != 0 )
      {
        v21->RefCount = v22 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
      }
    }
    this->PassedThisObj.pObject = v20;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::ASString *))ThisPtr->pNode[3].pData)(ThisPtr) )
      ThisPtr = (Scaleform::GFx::ASString *)ThisPtr[10].pNode;
  }
  if ( this->pThis->ExecType != 2 )
  {
    SWFVersion = (unsigned __int8)this->pOurEnv->StringContext.SWFVersion;
    if ( ThisPtr )
    {
      v.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v, (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr);
      v24 = this->pOurEnv;
      v25 = (Scaleform::GFx::ASString *)&v24->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
      v26 = (__int64)&v24->LocalFrames.Data.Data[v24->LocalFrames.Data.Size];
      v27 = *(_QWORD *)(v26 - 8);
      if ( v27 )
        *(_DWORD *)(v27 + 24) = (*(_DWORD *)(v27 + 24) + 1) & 0x8FFFFFFF;
      v28 = *(_QWORD *)(v26 - 8);
      p_pData = (_QWORD *)v28;
      if ( v28 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v28 + 32),
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&result,
          v25,
          v24->StringContext.SWFVersion > 6u);
        if ( result.Function
          && (vfptr = result.Function->vfptr) != 0i64
          && (__int64)result.pLocalFrame <= (__int64)vfptr->Finalize_GC )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)&vfptr[2 * (__int64)result.pLocalFrame + 1].Finalize_GC,
            &v);
        }
        else
        {
          result.Function = (Scaleform::GFx::AS2::FunctionObject *)v25;
          result.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)&v;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v28 + 32),
            (void *)(v28 + 32),
            (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
            v25->pNode->HashFlags);
        }
        pStr = key.pStr;
      }
      if ( v28 )
      {
        v30 = *(_DWORD *)(v28 + 24);
        if ( (v30 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v28 + 24) = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v28);
        }
      }
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
    }
    if ( SWFVersion >= 6 )
    {
      v31 = this->CurLocalFrame.pObject;
      if ( v31 )
        v31->SuperThis = (Scaleform::GFx::AS2::ObjectInterface *)pStr;
    }
    if ( this->CurLocalFrame.pObject )
    {
      Env = this->mFnCall->Env;
      if ( Env )
      {
        if ( SWFVersion >= 5 )
        {
          if ( this->pOurEnv != Env )
          {
            Target = Env->Target;
            if ( Target )
              ++Target->RefCount;
            v34 = this->FnEnvCh.pObject;
            if ( v34 )
              Scaleform::RefCountNTSImpl::Release(v34);
            this->FnEnvCh.pObject = Target;
          }
          this->CurLocalFrame.pObject->Env = this->mFnCall->Env;
          this->CurLocalFrame.pObject->NArgs = this->mFnCall->NArgs;
          this->CurLocalFrame.pObject->FirstArgBottomIndex = this->mFnCall->FirstArgBottomIndex;
          v35 = Scaleform::GFx::AS2::Environment::CallTop(this->pOurEnv, &v, 0);
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Callee, v35);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
          v36 = Scaleform::GFx::AS2::Environment::CallTop(this->pOurEnv, &v, 1u);
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Caller, v36);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
      }
    }
    Size = this->pThis->Args.Data.Size;
    mFnCall = this->mFnCall;
    if ( mFnCall->NArgs < (int)Size )
      LODWORD(Size) = mFnCall->NArgs;
    for ( i = 0; i < (int)Size; ++i )
    {
      v40 = this->mFnCall;
      v41 = v40->FirstArgBottomIndex - i;
      v42 = v40->Env;
      v43 = 0i64;
      if ( v41 <= 32 * ((unsigned int)v42->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v42->Stack.pCurrent - v42->Stack.pPageStart) )
        v43 = &v42->Stack.Pages.Data.Data[v41 >> 5]->Values[v41 & 0x1F];
      p_Name = &this->pThis->Args.Data.Data[i].Name;
      v45 = this->pOurEnv;
      v46 = (__int64)&v45->LocalFrames.Data.Data[v45->LocalFrames.Data.Size];
      v47 = *(_QWORD *)(v46 - 8);
      if ( v47 )
        *(_DWORD *)(v47 + 24) = (*(_DWORD *)(v47 + 24) + 1) & 0x8FFFFFFF;
      v48 = *(_QWORD *)(v46 - 8);
      key.pStr = (Scaleform::GFx::ASString *)v48;
      if ( v48 )
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v48 + 32),
          p_Name,
          v43,
          v45->StringContext.SWFVersion > 6u);
      if ( v48 )
      {
        v49 = *(_DWORD *)(v48 + 24);
        if ( (v49 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v48 + 24) = v49 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v48);
        }
      }
    }
    Size_low = SLODWORD(this->pThis->Args.Data.Size);
    if ( i < Size_low )
    {
      v51 = i;
      v52 = Size_low - i;
      do
      {
        v.T.Type = 0;
        v53 = &this->pThis->Args.Data.Data[v51].Name;
        v54 = this->pOurEnv;
        v55 = (__int64)&v54->LocalFrames.Data.Data[v54->LocalFrames.Data.Size];
        v56 = *(_QWORD *)(v55 - 8);
        if ( v56 )
          *(_DWORD *)(v56 + 24) = (*(_DWORD *)(v56 + 24) + 1) & 0x8FFFFFFF;
        v57 = *(_QWORD *)(v55 - 8);
        p_pData = (_QWORD *)v57;
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
              v193 = v57 + 32;
              v194 = v61;
            }
            else
            {
              v193 = 0i64;
              v194 = 0i64;
            }
            v60 = &v193;
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
              v196 = (_QWORD *)(v57 + 32);
              v197 = v59;
            }
            else
            {
              v196 = 0i64;
              v197 = 0i64;
            }
            v60 = (__int64 *)&v196;
          }
          v62 = v60[1];
          if ( *v60 && (v63 = *(_QWORD *)*v60) != 0 && v62 <= *(_QWORD *)(v63 + 8) )
          {
            Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)(48 * v62 + v63 + 32), &v);
          }
          else
          {
            result.Function = (Scaleform::GFx::AS2::FunctionObject *)v53;
            result.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)&v;
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
          if ( (v64 & 0x3FFFFFF) != 0 )
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
    &this->pOurEnv->LocalRegister.Data,
    this->pOurEnv->LocalRegister.Data.Size + (unsigned __int8)this->pThis->LocalRegisterCount);
  v65 = this->pThis->Args.Data.Size;
  v66 = this->mFnCall;
  if ( v66->NArgs < (int)v65 )
    LODWORD(v65) = v66->NArgs;
  v67 = 0;
  v68 = (int)v65;
  if ( (int)v65 > 0 )
  {
    v69 = 0i64;
    do
    {
      Data = this->pThis->Args.Data.Data;
      Register = (unsigned int)Data[v69].Register;
      v72 = this->mFnCall;
      v73 = v72->Env;
      v74 = v72->FirstArgBottomIndex - v67;
      v75 = v73->Stack.Pages.Data.Size;
      v76 = v73->Stack.pCurrent - v73->Stack.pPageStart;
      if ( (_DWORD)Register )
      {
        v78 = 0i64;
        if ( v74 <= 32 * ((int)v75 - 1) + (int)v76 )
          v78 = &v73->Stack.Pages.Data.Data[v74 >> 5]->Values[v74 & 0x1F];
        v79 = this->pOurEnv;
        v80 = v79->LocalRegister.Data.Size;
        if ( Register < v80 )
        {
          GlobalRegister = &v79->LocalRegister.Data.Data[v80 - Register - 1];
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            this->pOurEnv,
            "Invalid local register %d, stack only has %d entries",
            Register,
            (unsigned int)v80);
          GlobalRegister = v79->GlobalRegister;
        }
        Scaleform::GFx::AS2::Value::operator=(GlobalRegister, v78);
      }
      else
      {
        v77 = 0i64;
        if ( v74 <= 32 * ((int)v75 - 1) + (int)v76 )
          v77 = &v73->Stack.Pages.Data.Data[v74 >> 5]->Values[v74 & 0x1F];
        Scaleform::GFx::AS2::Environment::AddLocal(this->pOurEnv, &Data[v67].Name, v77);
      }
      ++v67;
      ++v69;
      --v68;
    }
    while ( v68 );
  }
  v82 = SLODWORD(this->pThis->Args.Data.Size);
  if ( v67 < v82 )
  {
    v83 = v67;
    v84 = v82 - v67;
    do
    {
      if ( !this->pThis->Args.Data.Data[v83].Register )
      {
        v.T.Type = 0;
        v85 = &this->pThis->Args.Data.Data[v67].Name;
        v86 = this->pOurEnv;
        v87 = (__int64)&v86->LocalFrames.Data.Data[v86->LocalFrames.Data.Size];
        v88 = *(_QWORD *)(v87 - 8);
        if ( v88 )
          *(_DWORD *)(v88 + 24) = (*(_DWORD *)(v88 + 24) + 1) & 0x8FFFFFFF;
        v89 = *(_QWORD *)(v87 - 8);
        p_pData = (_QWORD *)v89;
        if ( v89 )
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v89 + 32),
            v85,
            &v,
            v86->StringContext.SWFVersion > 6u);
        if ( v89 )
        {
          v90 = *(_DWORD *)(v89 + 24);
          if ( (v90 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v89 + 24) = v90 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v89);
          }
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
      }
      ++v67;
      ++v83;
      --v84;
    }
    while ( v84 );
  }
  v91 = 0i64;
  v203 = 0i64;
  Function2Flags = this->pThis->Function2Flags;
  if ( (Function2Flags & 0x10) != 0 || (Function2Flags & 0x20) == 0 )
  {
    v93 = key.pStr[1].pNode;
    if ( v93 )
      v93->RefCount = (v93->RefCount + 1) & 0x8FFFFFFF;
    p_pData = &v93->pData;
    if ( v93 )
    {
      pMethodName = this->pMethodName;
      if ( pMethodName )
      {
        String = Scaleform::GFx::AS2::Environment::CreateString(
                   this->pOurEnv,
                   (Scaleform::GFx::ASString *)&key,
                   pMethodName);
        v96 = this->pOurEnv;
        p_Size = &v93->Size;
        if ( v93 == (Scaleform::GFx::ASStringNode *)-32i64 )
        {
LABEL_158:
          v99 = 0i64;
        }
        else
        {
          while ( !(*(unsigned __int8 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)p_Size + 72i64))(
                     p_Size,
                     &v96->StringContext,
                     String,
                     0i64) )
          {
            v98 = *((_QWORD *)p_Size + 1);
            if ( v98 )
            {
              p_Size = (unsigned int *)(v98 + 32);
              if ( p_Size )
                continue;
            }
            goto LABEL_158;
          }
          v99 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(p_Size - 8);
          if ( v99 )
            v99->RefCount = (v99->RefCount + 1) & 0x8FFFFFFF;
        }
        v193 = (__int64)v99;
        v100 = (Scaleform::GFx::ASStringNode *)key.pStr;
        if ( LODWORD(key.pStr[3].pNode)-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v100);
        if ( v99 )
        {
          v99->RefCount = (v99->RefCount + 1) & 0x8FFFFFFF;
          v102 = v93->RefCount;
          if ( (v102 & 0x3FFFFFF) != 0 )
          {
            v93->RefCount = v102 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v93);
          }
          v93 = (Scaleform::GFx::ASStringNode *)v99;
          p_pData = &v99->vfptr;
        }
        if ( v99 )
        {
          v103 = v99->RefCount;
          if ( (v103 & 0x3FFFFFF) != 0 )
          {
            v99->RefCount = v103 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v99);
          }
        }
      }
      (*(void (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::ASStringContext *))(*(_QWORD *)&v93->Size + 112i64))(
        &v93->Size,
        &result,
        &this->pOurEnv->StringContext);
      v104 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD *, __int64, _QWORD))(*p_vfptr + 80i64))(
                                           p_vfptr,
                                           144i64,
                                           0i64);
      key.pStr = v104;
      if ( v104 )
      {
        Scaleform::GFx::AS2::SuperObject::SuperObject(
          (Scaleform::GFx::AS2::SuperObject *)v104,
          (Scaleform::GFx::AS2::Object *)v93[1].pData,
          (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr,
          &result);
        v91 = v105;
      }
      else
      {
        v91 = 0i64;
      }
      v203 = v91;
      Flags = result.Flags;
      if ( (result.Flags & 2) == 0 )
      {
        Function = result.Function;
        if ( result.Function )
        {
          v108 = result.Function->RefCount;
          if ( (v108 & 0x3FFFFFF) != 0 )
          {
            result.Function->RefCount = v108 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            Flags = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( (Flags & 1) == 0 )
      {
        v109 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v110 = result.pLocalFrame->RefCount;
          if ( (v110 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v110 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v109);
          }
        }
      }
      result.pLocalFrame = 0i64;
    }
    if ( v93 )
    {
      v111 = v93->RefCount;
      if ( (v111 & 0x3FFFFFF) != 0 )
      {
        v93->RefCount = v111 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v93);
      }
    }
  }
  v112 = 1;
  LODWORD(p_pData) = 1;
  if ( (this->pThis->Function2Flags & 1) != 0 )
  {
    if ( ThisPtr )
    {
      v113 = this->pOurEnv;
      v114 = v113->LocalRegister.Data.Size;
      if ( v114 > 1 )
      {
        v115 = &v113->LocalRegister.Data.Data[v114 - 2];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          this->pOurEnv,
          "Invalid local register %d, stack only has %d entries",
          1i64,
          (unsigned int)v114);
        v115 = v113->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(v115, (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr);
    }
    else
    {
      v116 = this->pOurEnv;
      v117 = v116->LocalRegister.Data.Size;
      if ( v117 > 1 )
      {
        v118 = &v116->LocalRegister.Data.Data[v117 - 2];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          this->pOurEnv,
          "Invalid local register %d, stack only has %d entries",
          1i64,
          (unsigned int)v117);
        v118 = v116->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::DropRefs(v118);
      v118->T.Type = 0;
    }
    v112 = 2;
    LODWORD(p_pData) = 2;
  }
  if ( (this->pThis->Function2Flags & 2) == 0 )
  {
    v.T.Type = 0;
    if ( ThisPtr )
    {
      v119 = ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))ThisPtr->pNode->pLower)(ThisPtr) - 2 <= 3;
      v120.pNode = ThisPtr->pNode;
      if ( v119 )
      {
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v120.pNode->pLower)(ThisPtr) - 2 <= 3
          && (v121 = (Scaleform::GFx::DisplayObject *)ThisPtr[2].pNode) != 0i64 )
        {
          CharacterHandle = (Scaleform::GFx::ASStringNode *)v121->pNameHandle.pObject;
          if ( !CharacterHandle )
            CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v121);
        }
        else
        {
          CharacterHandle = 0i64;
        }
        if ( v.T.Type != 7 || v.V.pStringNode != CharacterHandle )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v);
          v.T.Type = 7;
          v.V.pStringNode = CharacterHandle;
          if ( CharacterHandle )
            ++LODWORD(CharacterHandle->pData);
        }
      }
      else
      {
        if ( ((unsigned int (__fastcall *)(Scaleform::GFx::ASString *))v120.pNode->pLower)(ThisPtr) - 6 > 0x26 )
          v123 = 0i64;
        else
          v123 = (Scaleform::GFx::ASStringNode *)&ThisPtr[-4];
        Scaleform::GFx::AS2::Value::SetAsObject(&v, v123);
      }
    }
    v124 = this->pOurEnv;
    v125 = (Scaleform::GFx::ASString *)&v124->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20];
    v126 = (__int64)&v124->LocalFrames.Data.Data[v124->LocalFrames.Data.Size];
    v127 = *(_QWORD *)(v126 - 8);
    if ( v127 )
      *(_DWORD *)(v127 + 24) = (*(_DWORD *)(v127 + 24) + 1) & 0x8FFFFFFF;
    v128 = *(_QWORD *)(v126 - 8);
    v193 = v128;
    if ( !v128 )
      goto LABEL_228;
    v129 = v128 + 32;
    if ( v124->StringContext.SWFVersion <= 6u )
    {
      key.pStr = v125;
      if ( !v125->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v125->pNode);
      if ( *(_QWORD *)v129 )
      {
        v130 = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v128 + 32),
                                                    &key,
                                                    v125->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v129 + 8i64));
        if ( (__int64)v130 >= 0 )
        {
          result.Function = (Scaleform::GFx::AS2::FunctionObject *)(v128 + 32);
          goto LABEL_223;
        }
      }
    }
    else if ( *(_QWORD *)v129 )
    {
      v130 = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                                                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v128 + 32),
                                                  v125,
                                                  v125->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v129 + 8i64));
      if ( (__int64)v130 >= 0 )
      {
        result.Function = (Scaleform::GFx::AS2::FunctionObject *)(v128 + 32);
LABEL_223:
        result.pLocalFrame = v130;
        if ( result.Function
          && (v131 = result.Function->vfptr) != 0i64
          && (__int64)result.pLocalFrame <= (__int64)v131->Finalize_GC )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)&v131[2 * (__int64)result.pLocalFrame + 1].Finalize_GC,
            &v);
        }
        else
        {
          result.Function = (Scaleform::GFx::AS2::FunctionObject *)v125;
          result.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)&v;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v128 + 32),
            (void *)(v128 + 32),
            (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
            v125->pNode->HashFlags);
        }
LABEL_228:
        if ( v128 )
        {
          v132 = *(_DWORD *)(v128 + 24);
          if ( (v132 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v128 + 24) = v132 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v128);
          }
        }
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        goto LABEL_233;
      }
    }
    v130 = 0i64;
    result.Function = 0i64;
    goto LABEL_223;
  }
LABEL_233:
  v133 = 0i64;
  v193 = 0i64;
  v134 = this->pThis->Function2Flags;
  if ( (v134 & 4) != 0 || (v134 & 8) == 0 )
  {
    v135 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD *, __int64, _QWORD))(*p_vfptr + 80i64))(
                                         p_vfptr,
                                         144i64,
                                         0i64);
    key.pStr = v135;
    if ( v135 )
    {
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v135, this->pOurEnv);
      v133 = v136;
    }
    else
    {
      v133 = 0i64;
    }
    v193 = v133;
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v133, this->mFnCall->NArgs);
    v137 = 0;
    v138 = 0i64;
    if ( this->mFnCall->NArgs > 0 )
    {
      p_vfptr = (_QWORD *)v133;
      do
      {
        v139 = this->mFnCall;
        v140 = v139->FirstArgBottomIndex - v137;
        v141 = v139->Env;
        v142 = 0i64;
        if ( v140 <= 32 * ((unsigned int)v141->Stack.Pages.Data.Size - 1)
                   + (unsigned int)(v141->Stack.pCurrent - v141->Stack.pPageStart) )
          v142 = &v141->Stack.Pages.Data.Data[v140 >> 5]->Values[v140 & 0x1F];
        if ( v138 >= 0 && v137 < *(_DWORD *)(v133 + 112) )
        {
          *(_BYTE *)(v133 + 140) = 0;
          if ( !*(_QWORD *)(*(_QWORD *)(v133 + 104) + 8 * v138) )
          {
            LODWORD(key.pStr) = 323;
            v143 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     v133,
                     32i64,
                     &key);
            v144 = v143;
            v196 = v143;
            if ( v143 )
              *v143 = 0;
            else
              v144 = 0i64;
            *(_QWORD *)(*(_QWORD *)(v133 + 104) + 8 * v138) = v144;
          }
          Scaleform::GFx::AS2::Value::operator=(
            *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v133 + 104) + 8 * v138),
            v142);
        }
        ++v137;
        ++v138;
      }
      while ( v137 < this->mFnCall->NArgs );
    }
  }
  if ( (this->pThis->Function2Flags & 4) != 0 )
  {
    v145 = this->pOurEnv;
    v146 = v145->LocalRegister.Data.Size;
    if ( v112 < v146 )
    {
      v147 = &v145->LocalRegister.Data.Data[v146 - v112 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        this->pOurEnv,
        "Invalid local register %d, stack only has %d entries",
        v112,
        (unsigned int)v146);
      v147 = v145->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v147, (Scaleform::GFx::ASStringNode *)v133);
    LODWORD(p_pData) = v112 + 1;
  }
  if ( (this->pThis->Function2Flags & 8) == 0 )
  {
    Scaleform::GFx::AS2::Value::Value(&v, (Scaleform::GFx::ASStringNode *)v133);
    v149 = v148;
    key.pStr = v148;
    v150 = this->pOurEnv;
    p_pMovieImpl = (Scaleform::GFx::ASString *)&v150->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl;
    v152 = (__int64)&v150->LocalFrames.Data.Data[v150->LocalFrames.Data.Size];
    v153 = *(_QWORD *)(v152 - 8);
    if ( v153 )
      *(_DWORD *)(v153 + 24) = (*(_DWORD *)(v153 + 24) + 1) & 0x8FFFFFFF;
    v154 = *(_QWORD *)(v152 - 8);
    p_vfptr = (_QWORD *)v154;
    if ( v154 )
    {
      v155 = v154 + 32;
      if ( v150->StringContext.SWFVersion <= 6u )
      {
        key.pStr = p_pMovieImpl;
        if ( !p_pMovieImpl->pNode->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(p_pMovieImpl->pNode);
        if ( *(_QWORD *)v155
          && (v162 = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v154 + 32),
                                                          &key,
                                                          p_pMovieImpl->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v155 + 8i64)),
              (__int64)v162 >= 0) )
        {
          result.Function = (Scaleform::GFx::AS2::FunctionObject *)(v154 + 32);
        }
        else
        {
          v162 = 0i64;
          result.Function = 0i64;
        }
        result.pLocalFrame = v162;
      }
      else
      {
        v156 = *(_QWORD *)v155;
        if ( !*(_QWORD *)v155 )
          goto LABEL_270;
        v157 = *(_QWORD *)(v156 + 8);
        v158 = (Scaleform::GFx::AS2::LocalFrame *)((unsigned int)v157 & p_pMovieImpl->pNode->HashFlags);
        v159 = v158;
        v160 = (Scaleform::GFx::AS2::LocalFrame **)(48i64 * (_QWORD)v158 + v156 + 16);
        if ( *v160 == (Scaleform::GFx::AS2::LocalFrame *)-2i64
          || (Scaleform::GFx::AS2::LocalFrame *)((unsigned int)v157 & *(&v160[1]->RefCount + 1)) != v158 )
        {
          goto LABEL_270;
        }
        while ( 1 )
        {
          v161 = (Scaleform::GFx::ASStringNode *)v160[1];
          if ( (Scaleform::GFx::AS2::LocalFrame *)((unsigned int)v157 & v161->HashFlags) == v158
            && v161 == p_pMovieImpl->pNode )
          {
            break;
          }
          v159 = *v160;
          if ( *v160 == (Scaleform::GFx::AS2::LocalFrame *)-1i64 )
            goto LABEL_270;
          v160 = (Scaleform::GFx::AS2::LocalFrame **)(48i64 * (_QWORD)v159 + v156 + 16);
        }
        if ( (__int64)v159 >= 0 )
        {
          result.Function = (Scaleform::GFx::AS2::FunctionObject *)(v154 + 32);
          result.pLocalFrame = v159;
        }
        else
        {
LABEL_270:
          result.Function = 0i64;
          result.pLocalFrame = 0i64;
        }
        v149 = key.pStr;
      }
      if ( result.Function
        && (v163 = result.Function->vfptr) != 0i64
        && (__int64)result.pLocalFrame <= (__int64)v163->Finalize_GC )
      {
        Scaleform::GFx::AS2::Value::operator=(
          (Scaleform::GFx::AS2::Value *)&v163[2 * (__int64)result.pLocalFrame + 1].Finalize_GC,
          (Scaleform::GFx::AS2::Value *)v149);
      }
      else
      {
        result.Function = (Scaleform::GFx::AS2::FunctionObject *)p_pMovieImpl;
        result.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v149;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v154 + 32),
          (void *)(v154 + 32),
          (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
          p_pMovieImpl->pNode->HashFlags);
      }
    }
    if ( v154 )
    {
      v164 = *(_DWORD *)(v154 + 24);
      if ( (v164 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(v154 + 24) = v164 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v154);
      }
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    LOBYTE(key.pStr) = 7;
    v165 = Scaleform::GFx::AS2::Environment::CallTop(this->pOurEnv, &v, 0);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString::NoCaseKey *))(*(_QWORD *)(v133 + 32) + 80i64))(
      v133 + 32,
      &this->pOurEnv->StringContext,
      &this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].pASSupport,
      v165,
      &key);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    LOBYTE(key.pStr) = 7;
    v166 = Scaleform::GFx::AS2::Environment::CallTop(this->pOurEnv, &v, 1u);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, char *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASString::NoCaseKey *))(*(_QWORD *)(v133 + 32) + 80i64))(
      v133 + 32,
      &this->pOurEnv->StringContext,
      &this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].AVMVersion,
      v166,
      &key);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (this->pThis->Function2Flags & 0x10) != 0 )
  {
    v167 = this->pOurEnv;
    v168 = v167->LocalRegister.Data.Size;
    v169 = (int)p_pData;
    if ( (unsigned int)p_pData < v168 )
    {
      v170 = &v167->LocalRegister.Data.Data[v168 - (unsigned int)p_pData - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        this->pOurEnv,
        "Invalid local register %d, stack only has %d entries",
        (unsigned int)p_pData,
        (unsigned int)v168);
      v170 = v167->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v170, v91);
    v171 = v169 + 1;
  }
  else
  {
    v171 = (unsigned int)p_pData;
  }
  if ( (this->pThis->Function2Flags & 0x20) == 0 )
  {
    v.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObject(&v, v91);
    v172 = this->pOurEnv;
    v173 = (Scaleform::GFx::ASString *)v172->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v174 = (__int64)&v172->LocalFrames.Data.Data[v172->LocalFrames.Data.Size];
    v175 = *(_QWORD *)(v174 - 8);
    if ( v175 )
      *(_DWORD *)(v175 + 24) = (*(_DWORD *)(v175 + 24) + 1) & 0x8FFFFFFF;
    v176 = *(_QWORD *)(v174 - 8);
    key.pStr = (Scaleform::GFx::ASString *)v176;
    if ( v176 )
      Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
        (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v176 + 32),
        v173 + 101,
        &v,
        v172->StringContext.SWFVersion > 6u);
    if ( v176 )
    {
      v177 = *(_DWORD *)(v176 + 24);
      if ( (v177 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(v176 + 24) = v177 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v176);
      }
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (this->pThis->Function2Flags & 0x40) != 0 )
  {
    v178 = this->pOurEnv;
    v179 = v178->Target;
    v180 = v178->LocalRegister.Data.Size;
    if ( v171 < v180 )
    {
      v181 = &v178->LocalRegister.Data.Data[v180 - v171 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        this->pOurEnv,
        "Invalid local register %d, stack only has %d entries",
        v171,
        (unsigned int)v180);
      v181 = v178->GlobalRegister;
    }
    v182 = (Scaleform::GFx::DisplayObject *)v179->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                              v179,
                                              0);
    if ( v182 )
    {
      v183 = v182->pNameHandle.pObject;
      if ( !v183 )
        v183 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v182);
    }
    else
    {
      v183 = 0i64;
    }
    if ( v181->T.Type != 7 || v181->V.pCharHandle != v183 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v181);
      v181->T.Type = 7;
      v181->V.pStringNode = (Scaleform::GFx::ASStringNode *)v183;
      if ( v183 )
        ++v183->RefCount;
    }
    ++v171;
  }
  if ( SLOBYTE(this->pThis->Function2Flags) < 0 )
  {
    v.T.Type = 0;
    Scaleform::GFx::AS2::Environment::GetVariable(
      this->pOurEnv,
      (Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].AVMVersion,
      &v,
      0i64);
    v184 = this->pOurEnv;
    v185 = v184->LocalRegister.Data.Size;
    if ( v171 < v185 )
    {
      v186 = &v184->LocalRegister.Data.Data[v185 - v171 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        this->pOurEnv,
        "Invalid local register %d, stack only has %d entries",
        v171,
        (unsigned int)v185);
      v186 = v184->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::operator=(v186, &v);
    ++v171;
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( (this->pThis->Function2Flags & 0x100) != 0 )
  {
    v187 = this->pOurEnv;
    v188 = (Scaleform::GFx::ASStringNode *)v187->StringContext.pContext->pGlobal.pObject;
    v189 = v187->LocalRegister.Data.Size;
    if ( v171 < v189 )
    {
      v190 = &v187->LocalRegister.Data.Data[v189 - v171 - 1];
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
        v187,
        "Invalid local register %d, stack only has %d entries",
        v171,
        (unsigned int)v189);
      v190 = v187->GlobalRegister;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(v190, v188);
  }
  if ( v133 )
  {
    v191 = *(_DWORD *)(v133 + 24);
    if ( (v191 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v133 + 24) = v191 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v133);
    }
  }
  if ( v91 )
  {
    v192 = v91->RefCount;
    if ( (v192 & 0x3FFFFFF) != 0 )
    {
      v91->RefCount = v192 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v91);
    }
  }
} Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v91);
    }
  }
}

// File Line: 568
// RVA: 0x6DD250
void __fastcall Scaleform::GFx::AS2::InvokeContext::Cleanup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::Environment *pOurEnv; // rbx
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *p_CallStack; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-30h] BYREF

  pObject = this->PassedThisObj.pObject;
  if ( pObject )
  {
    v3 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
    if ( v3 )
    {
      if ( v3->vfptr->IsSuper(v3) )
        Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&v3[-2]);
    }
  }
  if ( this->pThis->ExecType != 2 || (this->pThis->Function2Flags & 2) == 0 )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::SetLocal(
      this->pOurEnv,
      (Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20],
      &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( this->pThis->ExecType != 2 || (this->pThis->Function2Flags & 0x20) == 0 )
  {
    val.T.Type = 0;
    Scaleform::GFx::AS2::Environment::SetLocal(
      this->pOurEnv,
      (Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].RefCount,
      &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pOurEnv->LocalFrames,
    (unsigned int)this->LocalStackTop);
  if ( this->pThis->ExecType == 2 )
    Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->pOurEnv->LocalRegister.Data,
      this->pOurEnv->LocalRegister.Data.Size - (unsigned __int8)this->pThis->LocalRegisterCount);
  pOurEnv = this->pOurEnv;
  if ( pOurEnv )
  {
    p_CallStack = &pOurEnv->CallStack;
    v6 = p_CallStack->pCurrent->pObject;
    if ( v6 )
    {
      RefCount = v6->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    if ( --p_CallStack->pCurrent < p_CallStack->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(p_CallStack);
  }
}

// File Line: 604
// RVA: 0x6FDFB0
void __fastcall Scaleform::GFx::AS2::AsFunctionObject::Invoke(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::LocalFrame *localFrame,
        const char *pmethodName)
{
  Scaleform::GFx::AS2::Environment *Env; // r8
  unsigned __int16 FuncCallNestingLevel; // cx
  Scaleform::GFx::AS2::LocalFrame *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::InvokeContext v12; // [rsp+50h] [rbp-68h] BYREF

  v12.pThis = this;
  v12.mFnCall = fn;
  v12.pLocalFrame = localFrame;
  v12.pMethodName = pmethodName;
  memset(&v12.TargetCh, 0, 40);
  Env = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AsFunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *))this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].ExecuteForEachChild_GC)(
                                              this,
                                              fn,
                                              &v12.TargetCh);
  v12.pOurEnv = Env;
  if ( (Env->Target->Flags & 0x10) != 0 )
  {
    Env = fn->Env;
    v12.pOurEnv = Env;
  }
  FuncCallNestingLevel = Env->FuncCallNestingLevel;
  Env->FuncCallNestingLevel = FuncCallNestingLevel + 1;
  if ( FuncCallNestingLevel < 0xFFu )
  {
    Scaleform::GFx::AS2::InvokeContext::Setup(&v12);
    Scaleform::GFx::AS2::ActionBuffer::Execute(
      this->pActionBuffer.pObject,
      v12.pOurEnv,
      this->StartPc,
      this->Length,
      fn->Result,
      &this->WithStack,
      (Scaleform::GFx::AS2::ActionBuffer::ExecuteType)(unsigned __int8)this->ExecType);
    Scaleform::GFx::AS2::InvokeContext::Cleanup(&v12);
  }
  --v12.pOurEnv->FuncCallNestingLevel;
  pObject = v12.CurLocalFrame.pObject;
  if ( v12.CurLocalFrame.pObject )
  {
    RefCount = v12.CurLocalFrame.pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v12.CurLocalFrame.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v10 = v12.PassedThisObj.pObject;
  if ( v12.PassedThisObj.pObject )
  {
    v11 = v12.PassedThisObj.pObject->RefCount;
    if ( (v11 & 0x3FFFFFF) != 0 )
    {
      v12.PassedThisObj.pObject->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  if ( v12.PassedThisCh.pObject )
    Scaleform::RefCountNTSImpl::Release(v12.PassedThisCh.pObject);
  if ( v12.FnEnvCh.pObject )
    Scaleform::RefCountNTSImpl::Release(v12.FnEnvCh.pObject);
  if ( v12.TargetCh.pObject )
    Scaleform::RefCountNTSImpl::Release(v12.TargetCh.pObject);
}

// File Line: 669
// RVA: 0x6DAA70
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::Assign(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::FunctionRefBase *orig)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rsi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FunctionObject *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS2::FunctionObject *v8; // rcx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::LocalFrame *v10; // rcx
  unsigned int v11; // eax

  if ( this != orig )
  {
    Function = this->Function;
    if ( (this->Flags & 2) == 0 )
    {
      if ( Function )
      {
        if ( Function != orig->Function )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v6 = this->Function;
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          }
        }
      }
    }
    v7 = (this->Flags & 2) == 0;
    this->Function = orig->Function;
    if ( v7 )
    {
      v8 = orig->Function;
      if ( orig->Function )
      {
        if ( Function != v8 )
          v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      }
    }
    pLocalFrame = orig->pLocalFrame;
    if ( pLocalFrame )
    {
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(this, pLocalFrame, orig->Flags & 1);
    }
    else
    {
      v10 = this->pLocalFrame;
      if ( v10 && (this->Flags & 1) == 0 )
      {
        v11 = v10->RefCount;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          v10->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
        }
      }
      this->Flags &= ~1u;
      this->pLocalFrame = 0i64;
    }
  }
}

// File Line: 706
// RVA: 0x714F10
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::LocalFrame *localFrame,
        bool internal)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int RefCount; // eax

  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    if ( (this->Flags & 1) == 0 )
    {
      RefCount = pLocalFrame->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->pLocalFrame = localFrame;
  if ( internal )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( localFrame )
  {
    if ( (this->Flags & 1) == 0 )
      localFrame->RefCount = (localFrame->RefCount + 1) & 0x8FFFFFFF;
  }
}

// File Line: 719
// RVA: 0x6BF8A0
void __fastcall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rbx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rbx

  Function = this->Function;
  if ( this->Function )
  {
    if ( (--Function->RefCount & 0x3FFFFFF) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, Function);
      Function->RefCount |= 0x4000000u;
      if ( (Function->RefCount & 0x8000000) == 0 )
      {
        Function->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        Function->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = Function;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)Function;
        prcc->pLastPtr = Function;
        Function->RefCount |= 0x8000000u;
      }
    }
  }
  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    if ( (--pLocalFrame->RefCount & 0x3FFFFFF) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pLocalFrame);
      pLocalFrame->RefCount |= 0x4000000u;
      if ( (pLocalFrame->RefCount & 0x8000000) == 0 )
      {
        pLocalFrame->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        pLocalFrame->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = pLocalFrame;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pLocalFrame;
        prcc->pLastPtr = pLocalFrame;
        pLocalFrame->RefCount |= 0x8000000u;
      }
    }
  }
}

// File Line: 748
// RVA: 0x6F94A0
void __fastcall Scaleform::GFx::AS2::FunctionProto::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned __int64 FirstArgBottomIndex; // r10
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::Value *v6; // rdx
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::CFunctionObject *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rbx
  unsigned int RefCount; // eax

  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v5->T.Type == 8 || v5->T.Type == 11 )
      goto LABEL_10;
    v6 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v6->T.Type == 11 )
    {
LABEL_10:
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v8 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v8);
    }
    else
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 1;
    }
  }
  else
  {
    v9 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   fn,
                                                   104i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v9, fn->Env);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v11);
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
}

// File Line: 772
// RVA: 0x6B4960
void __fastcall Scaleform::GFx::AS2::FunctionProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::ASStringNode *pMovieImpl; // rax

  Result = fn->Result;
  pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->T.Type = 5;
  pMovieImpl = (Scaleform::GFx::ASStringNode *)pObject[24].pMovieImpl;
  Result->V.pStringNode = pMovieImpl;
  ++pMovieImpl->RefCount;
}

// File Line: 777
// RVA: 0x6B49B0
void __fastcall Scaleform::GFx::AS2::FunctionProto::ValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&ThisPtr[-2]);
  else
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0i64);
}

// File Line: 784
// RVA: 0x6B4090
void __fastcall Scaleform::GFx::AS2::FunctionProto::Apply(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rbx
  Scaleform::RefCountNTSImpl *vfptr; // rdi
  __int64 v4; // r12
  Scaleform::GFx::AS2::Value *Result; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v9; // r9
  Scaleform::GFx::AS2::ObjectInterface *v10; // rax
  Scaleform::GFx::AS2::ObjectInterface *v11; // r14
  unsigned int v12; // r9d
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
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *ThisPtr; // r14
  Scaleform::GFx::AS2::Environment *v29; // r8
  int v30; // edx
  char v31; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v34; // rcx
  unsigned int v35; // eax
  unsigned int v36; // eax
  Scaleform::GFx::AS2::Environment *v37; // r14
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  unsigned int v39; // eax
  unsigned int v40; // eax
  Scaleform::GFx::AS2::Value *v; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::AS2::Value *va; // [rsp+20h] [rbp-69h]
  void **v43; // [rsp+28h] [rbp-61h] BYREF
  Scaleform::GFx::AS2::Value *v44; // [rsp+30h] [rbp-59h]
  __int64 v45; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v47; // [rsp+48h] [rbp-41h]
  char v48; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Environment *v49; // [rsp+58h] [rbp-31h]
  int v50; // [rsp+60h] [rbp-29h]
  int v51; // [rsp+64h] [rbp-25h]
  __int64 v52; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::AS2::Value v53; // [rsp+70h] [rbp-19h] BYREF
  __int64 v54; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS2::Value *v55; // [rsp+98h] [rbp+Fh]
  __int64 v56; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v57; // [rsp+F8h] [rbp+6Fh]

  v54 = -2i64;
  v2 = 0i64;
  v57 = 0i64;
  vfptr = 0i64;
  v56 = 0i64;
  LODWORD(v4) = 0;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  v6 = 0i64;
  v52 = 0i64;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v9 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObjectInterface(v9, Env);
    v11 = v10;
    v56 = (__int64)v10;
    if ( v10 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->vfptr->gap8[8])(v10) - 2 > 3 )
      {
        v2 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11[-2];
        v57 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11[-2];
        if ( v11 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
          v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
      }
      else if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v11->vfptr->gap8[8])(v11) - 2 > 3 )
      {
        vfptr = 0i64;
      }
      else
      {
        vfptr = (Scaleform::RefCountNTSImpl *)v11[1].vfptr;
        if ( vfptr )
          ++vfptr->RefCount;
      }
    }
  }
  if ( fn->NArgs >= 2 )
  {
    v12 = fn->FirstArgBottomIndex - 1;
    v13 = fn->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v13);
    v16 = (__int64)v15;
    if ( v15 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v15->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v15->Scaleform::GFx::AS2::ObjectInterface) == 7 )
      {
        *(_DWORD *)(v16 + 24) = (*(_DWORD *)(v16 + 24) + 1) & 0x8FFFFFFF;
        v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v16;
        v52 = v16;
        v4 = *(_QWORD *)(v16 + 112);
        if ( (int)v4 > 0 )
        {
          v17 = (int)v4 - 1;
          if ( (int)v4 - 1 >= 0 )
          {
            v18 = v16;
            do
            {
              v19 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v18 + 104) + 8 * v17);
              va = v19;
              v20 = fn->Env;
              if ( ++v20->Stack.pCurrent >= v20->Stack.pPageEnd )
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v20->Stack);
                v19 = va;
              }
              v = v20->Stack.pCurrent;
              v55 = v;
              if ( v )
                Scaleform::GFx::AS2::Value::Value(v55, v19);
              --v17;
            }
            while ( v17 >= 0 );
            v2 = v57;
          }
        }
      }
    }
  }
  v53.T.Type = 0;
  if ( fn->ThisFunctionRef.Function )
  {
    v21 = fn->Env;
    v22 = v21->Stack.pCurrent - v21->Stack.pPageStart + 32 * v21->Stack.Pages.Data.Size - 32;
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v44 = &v53;
    v45 = v56;
    v48 = 0;
    v46 = 0i64;
    v47 = 0i64;
    v49 = v21;
    v50 = v4;
    v51 = v22;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD, Scaleform::GFx::AS2::Value *))fn->ThisFunctionRef.Function->vfptr[3].Finalize_GC)(
      fn->ThisFunctionRef.Function,
      &v43,
      fn->ThisFunctionRef.pLocalFrame,
      0i64,
      v);
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v23 = v48;
    if ( (v48 & 2) == 0 )
    {
      v24 = v46;
      if ( v46 )
      {
        RefCount = v46->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v46->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          v23 = v48;
        }
      }
    }
    v46 = 0i64;
    if ( (v23 & 1) == 0 )
    {
      v26 = v47;
      if ( v47 )
      {
        v27 = v47->RefCount;
        if ( (v27 & 0x3FFFFFF) != 0 )
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
    ThisPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)fn->ThisPtr;
    if ( ThisPtr )
    {
      if ( --ThisPtr )
        ThisPtr->RefCount = (ThisPtr->RefCount + 1) & 0x8FFFFFFF;
    }
    v29 = fn->Env;
    v30 = v29->Stack.pCurrent - v29->Stack.pPageStart + 32 * v29->Stack.Pages.Data.Size - 32;
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v44 = &v53;
    v45 = v56;
    v48 = 0;
    v46 = 0i64;
    v47 = 0i64;
    v49 = v29;
    v50 = v4;
    v51 = v30;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, void ***, _QWORD, _QWORD, Scaleform::GFx::AS2::Value *))ThisPtr->vfptr[3].Finalize_GC)(
      ThisPtr,
      &v43,
      0i64,
      0i64,
      v);
    v43 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v31 = v48;
    if ( (v48 & 2) == 0 )
    {
      v32 = v46;
      if ( v46 )
      {
        v33 = v46->RefCount;
        if ( (v33 & 0x3FFFFFF) != 0 )
        {
          v46->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
          v31 = v48;
        }
      }
    }
    v46 = 0i64;
    if ( (v31 & 1) == 0 )
    {
      v34 = v47;
      if ( v47 )
      {
        v35 = v47->RefCount;
        if ( (v35 & 0x3FFFFFF) != 0 )
        {
          v47->RefCount = v35 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
        }
      }
    }
    v47 = 0i64;
    v43 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v36 = ThisPtr->RefCount;
    if ( (v36 & 0x3FFFFFF) != 0 )
    {
      ThisPtr->RefCount = v36 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(ThisPtr);
    }
  }
  if ( (int)v4 > 0 )
  {
    v37 = fn->Env;
    do
    {
      pCurrent = v37->Stack.pCurrent;
      if ( pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
      if ( --v37->Stack.pCurrent < v37->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v37->Stack);
      LODWORD(v4) = v4 - 1;
    }
    while ( (_DWORD)v4 );
  }
  Scaleform::GFx::AS2::Value::operator=(fn->Result, &v53);
  if ( v53.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v53);
  if ( v6 )
  {
    v39 = v6->RefCount;
    if ( (v39 & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = v39 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  if ( vfptr )
    Scaleform::RefCountNTSImpl::Release(vfptr);
  if ( v2 )
  {
    v40 = v2->RefCount;
    if ( (v40 & 0x3FFFFFF) != 0 )
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
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rbx
  Scaleform::RefCountNTSImpl *vfptr; // rdi
  int v4; // r12d
  Scaleform::GFx::AS2::Value *Result; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::ObjectInterface *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // r14
  int NArgs; // eax
  int i; // r15d
  unsigned int v13; // edx
  Scaleform::GFx::AS2::Environment *v14; // rsi
  Scaleform::GFx::AS2::Value *v15; // r14
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Environment *v17; // r8
  int v18; // edx
  char v19; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *ThisPtr; // rsi
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
  void **v36; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::GFx::AS2::Value *p_v; // [rsp+28h] [rbp-61h]
  __int64 v38; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v39; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v40; // [rsp+40h] [rbp-49h]
  char v41; // [rsp+48h] [rbp-41h]
  Scaleform::GFx::AS2::Environment *v42; // [rsp+50h] [rbp-39h]
  int v43; // [rsp+58h] [rbp-31h]
  int v44; // [rsp+5Ch] [rbp-2Dh]
  void *v45; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::Value v; // [rsp+68h] [rbp-21h] BYREF
  __int64 v47; // [rsp+88h] [rbp-1h]
  Scaleform::GFx::AS2::Value *v48; // [rsp+90h] [rbp+7h]
  __int64 v49; // [rsp+F0h] [rbp+67h]

  v47 = -2i64;
  v2 = 0i64;
  vfptr = 0i64;
  v49 = 0i64;
  v4 = 0;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObjectInterface(v8, Env);
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
        vfptr = 0i64;
      }
      else
      {
        vfptr = (Scaleform::RefCountNTSImpl *)v10[1].vfptr;
        if ( vfptr )
          ++vfptr->RefCount;
      }
    }
  }
  NArgs = fn->NArgs;
  if ( NArgs >= 2 )
  {
    v4 = NArgs - 1;
    for ( i = NArgs - 1; i >= 1; --i )
    {
      v13 = fn->FirstArgBottomIndex - i;
      v14 = fn->Env;
      v15 = 0i64;
      if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
                + (unsigned int)(v14->Stack.pCurrent - v14->Stack.pPageStart) )
        v15 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
      if ( ++v14->Stack.pCurrent >= v14->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v14->Stack);
      pCurrent = v14->Stack.pCurrent;
      v48 = pCurrent;
      v45 = pCurrent;
      if ( pCurrent )
        Scaleform::GFx::AS2::Value::Value(pCurrent, v15);
    }
  }
  v.T.Type = 0;
  if ( fn->ThisFunctionRef.Function )
  {
    v17 = fn->Env;
    v18 = v17->Stack.pCurrent - v17->Stack.pPageStart + 32 * v17->Stack.Pages.Data.Size - 32;
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    p_v = &v;
    v38 = v49;
    v41 = 0;
    v39 = 0i64;
    v40 = 0i64;
    v42 = v17;
    v43 = v4;
    v44 = v18;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD))fn->ThisFunctionRef.Function->vfptr[3].Finalize_GC)(
      fn->ThisFunctionRef.Function,
      &v36,
      fn->ThisFunctionRef.pLocalFrame,
      0i64);
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v19 = v41;
    if ( (v41 & 2) == 0 )
    {
      v20 = v39;
      if ( v39 )
      {
        RefCount = v39->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v39->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
          v19 = v41;
        }
      }
    }
    v39 = 0i64;
    if ( (v19 & 1) == 0 )
    {
      v22 = v40;
      if ( v40 )
      {
        v23 = v40->RefCount;
        if ( (v23 & 0x3FFFFFF) != 0 )
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
    ThisPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)fn->ThisPtr;
    if ( ThisPtr )
    {
      if ( --ThisPtr )
        ThisPtr->RefCount = (ThisPtr->RefCount + 1) & 0x8FFFFFFF;
    }
    v45 = ThisPtr;
    v25 = fn->Env;
    v26 = v25->Stack.pCurrent - v25->Stack.pPageStart + 32 * v25->Stack.Pages.Data.Size - 32;
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    p_v = &v;
    v38 = v49;
    v41 = 0;
    v39 = 0i64;
    v40 = 0i64;
    v42 = v25;
    v43 = v4;
    v44 = v26;
    ((void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, void ***, _QWORD, _QWORD))ThisPtr->vfptr[3].Finalize_GC)(
      ThisPtr,
      &v36,
      0i64,
      0i64);
    v36 = &Scaleform::GFx::AS2::FnCall::`vftable;
    v27 = v41;
    if ( (v41 & 2) == 0 )
    {
      v28 = v39;
      if ( v39 )
      {
        v29 = v39->RefCount;
        if ( (v29 & 0x3FFFFFF) != 0 )
        {
          v39->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
          v27 = v41;
        }
      }
    }
    v39 = 0i64;
    if ( (v27 & 1) == 0 )
    {
      v30 = v40;
      if ( v40 )
      {
        v31 = v40->RefCount;
        if ( (v31 & 0x3FFFFFF) != 0 )
        {
          v40->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
        }
      }
    }
    v40 = 0i64;
    v36 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
    v32 = ThisPtr->RefCount;
    if ( (v32 & 0x3FFFFFF) != 0 )
    {
      ThisPtr->RefCount = v32 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(ThisPtr);
    }
  }
  if ( v4 > 0 )
  {
    v33 = fn->Env;
    do
    {
      v34 = v33->Stack.pCurrent;
      if ( v34->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v34);
      if ( --v33->Stack.pCurrent < v33->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v33->Stack);
      --v4;
    }
    while ( v4 );
  }
  Scaleform::GFx::AS2::Value::operator=(fn->Result, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( vfptr )
    Scaleform::RefCountNTSImpl::Release(vfptr);
  if ( v2 )
  {
    v35 = v2->RefCount;
    if ( (v35 & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = v35 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
} ( (v35 & 0x3FFFFFF) != 0 )
    {
      v2->RefCount = v35 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
    }
  }
}

