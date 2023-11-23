// File Line: 30
// RVA: 0x6C8640
void __fastcall Scaleform::GFx::AS2::ExternalInterface::ExternalInterface(
        Scaleform::GFx::AS2::ExternalInterface *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterface::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterface::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(
                penv->StringContext.pContext,
                ASBuiltin_ExternalInterface);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 55
// RVA: 0x6C86C0
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::ExternalInterfaceCtorFunction(
        Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-40h] BYREF
  char v8; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+20h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    this,
    psc,
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v7.T.Type = 10;
  v4 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "available");
  v8 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v4,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::StaticFunctionTable,
    7);
}

// File Line: 64
// RVA: 0x6F1EE0
char __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GetMember(
        Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString *v9; // rsi
  bool v10; // zf
  bool v11; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ExternalInterface *pObject; // rbx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "available");
  v9 = v8;
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !v8->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v8->pNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v9->pNode->pLower == name->pNode->pLower;
  }
  else
  {
    v10 = v8->pNode == name->pNode;
  }
  v11 = v10;
  pNode = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !v11 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             &penv->StringContext,
             name,
             val,
             -2i64);
  pObject = penv->Target->pASRoot->pMovieImpl->pExtIntfHandler.pObject;
  Scaleform::GFx::AS2::Value::DropRefs(val);
  val->T.Type = 2;
  val->V.BooleanValue = pObject != 0i64;
  return 1;
}

// File Line: 78
// RVA: 0x6BB040
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::AddCallback(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Value *v6; // r10
  unsigned int v7; // r9d
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::CharacterHandle *pObject; // rsi
  Scaleform::GFx::AS2::Object *v11; // rbx
  unsigned int v12; // r10d
  Scaleform::GFx::AS2::Environment *v13; // r9
  Scaleform::GFx::AS2::Value *v14; // r8
  unsigned __int64 Size; // rax
  __int64 v16; // rcx
  __int64 v17; // rdx
  Scaleform::GFx::CharacterHandle *v18; // rcx
  Scaleform::GFx::DisplayObject *v19; // rax
  Scaleform::GFx::DisplayObject *v20; // rdi
  Scaleform::GFx::AS2::Value *v21; // r11
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::AS2::Value *v23; // rdi
  unsigned int RefCount; // eax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int v27; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::FunctionRef func; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::CharacterHandle *v34; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::AS2::Object *v35; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::DisplayObject *v36; // [rsp+98h] [rbp+20h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs >= 3 )
  {
    Env = fn->Env;
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v6 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v6, &result, Env, -1);
    v7 = fn->FirstArgBottomIndex - 2;
    v8 = fn->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v8->Stack.pCurrent - v8->Stack.pPageStart) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v9, &func, v8);
    pObject = 0i64;
    v34 = 0i64;
    v11 = 0i64;
    v35 = 0i64;
    v12 = fn->FirstArgBottomIndex - 1;
    v13 = fn->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v13->Stack.pCurrent - v13->Stack.pPageStart) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    Size = v13->Stack.Pages.Data.Size;
    v16 = v13->Stack.pCurrent - v13->Stack.pPageStart;
    if ( v14->T.Type == 7 )
    {
      v17 = 0i64;
      if ( v12 <= 32 * ((int)Size - 1) + (int)v16 )
        v17 = (__int64)&v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
      if ( *(_BYTE *)v17 == 7
        && v13
        && (v18 = *(Scaleform::GFx::CharacterHandle **)(v17 + 8)) != 0i64
        && (v19 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v18, v13->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v20 = 0i64;
        if ( SLOBYTE(v19->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
          v20 = v19;
        if ( v20 )
          ++v20->RefCount;
      }
      else
      {
        v20 = 0i64;
      }
      v36 = v20;
      if ( v20 )
      {
        pObject = v20->pNameHandle.pObject;
        if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v20)) != 0i64 )
          ++pObject->RefCount;
        v34 = pObject;
      }
      if ( v20 )
        Scaleform::RefCountNTSImpl::Release(v20);
    }
    else
    {
      v21 = 0i64;
      if ( v12 <= 32 * ((int)Size - 1) + (int)v16 )
        v21 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
      v22 = Scaleform::GFx::AS2::Value::ToObject(v21, fn->Env);
      v11 = v22;
      if ( v22 )
        v22->RefCount = (v22->RefCount + 1) & 0x8FFFFFFF;
      v35 = v22;
    }
    Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(
      (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject,
      &result,
      pObject,
      v11,
      &func);
    v23 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v23);
    v23->T.Type = 2;
    v23->V.BooleanValue = 1;
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    if ( pObject )
    {
      if ( --pObject->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
    }
    Flags = func.Flags;
    if ( (func.Flags & 2) == 0 )
    {
      Function = func.Function;
      if ( func.Function )
      {
        v27 = func.Function->RefCount;
        if ( (v27 & 0x3FFFFFF) != 0 )
        {
          func.Function->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = func.Flags;
        }
      }
    }
    func.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = func.pLocalFrame;
      if ( func.pLocalFrame )
      {
        v29 = func.pLocalFrame->RefCount;
        if ( (v29 & 0x3FFFFFF) != 0 )
        {
          func.pLocalFrame->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    func.pLocalFrame = 0i64;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 106
// RVA: 0x6BBA20
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Call(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r15
  __int64 v4; // rbp
  Scaleform::GFx::ASStringNode *v5; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::MemoryHeap *pHeap; // rcx
  char *v14; // r13
  unsigned int v15; // r14d
  Scaleform::GFx::ASStringNode *v16; // rdi
  unsigned int v17; // edx
  Scaleform::GFx::AS2::Environment *v18; // r9
  Scaleform::GFx::AS2::Value *v19; // r8
  Scaleform::GFx::Value *v20; // r9
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  const char *pData; // r8
  _QWORD *v23; // rdi
  __int64 v24; // rsi
  Scaleform::GFx::AS2::Value *v25; // rbx
  char v26; // [rsp+40h] [rbp-218h] BYREF
  Scaleform::GFx::ASString result; // [rsp+268h] [rbp+10h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [rsp+270h] [rbp+18h]

  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( pMovieImpl->pExtIntfHandler.pObject )
  {
    LODWORD(v4) = 0;
    v5 = *(Scaleform::GFx::ASStringNode **)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v5->RefCount;
    if ( fn->NArgs < 1 )
      goto LABEL_11;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v7 = fn->Env;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
      v8 = &v7->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1);
    pNode = v9->pNode;
    ++v9->pNode->RefCount;
    v11 = v5->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v5 = pNode;
    v12 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v4 = (unsigned int)(fn->NArgs - 1);
    if ( (unsigned int)v4 <= 0xA )
    {
LABEL_11:
      v14 = &v26;
    }
    else
    {
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v14 = (char *)pHeap->vfptr->Alloc(pHeap, 48 * v4, 0i64);
    }
    v15 = 0;
    if ( (_DWORD)v4 )
    {
      v16 = (Scaleform::GFx::ASStringNode *)v14;
      do
      {
        v17 = fn->FirstArgBottomIndex - v15 - 1;
        v18 = fn->Env;
        v19 = 0i64;
        if ( v17 <= 32 * ((unsigned int)v18->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v18->Stack.pCurrent - v18->Stack.pPageStart) )
          v19 = &v18->Stack.Pages.Data.Data[v17 >> 5]->Values[v17 & 0x1F];
        result.pNode = v16;
        v28 = v16;
        if ( v16 )
        {
          v16->pLower = 0i64;
          v16->RefCount = 0;
          v20 = (Scaleform::GFx::Value *)v16;
        }
        else
        {
          v20 = 0i64;
        }
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
          (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject,
          fn->Env,
          v19,
          v20);
        ++v15;
        v16 = (Scaleform::GFx::ASStringNode *)((char *)v16 + 48);
      }
      while ( v15 < (unsigned int)v4 );
    }
    pObject = pMovieImpl->pASMovieRoot.pObject;
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pObject[2].RefCount);
    LOBYTE(pObject[2].RefCount) = 0;
    pData = 0i64;
    if ( v5->Size )
      pData = v5->pData;
    ((void (__fastcall *)(Scaleform::GFx::ExternalInterface *, Scaleform::GFx::MovieImpl *, const char *, char *, _DWORD))pMovieImpl->pExtIntfHandler.pObject->vfptr[1].__vecDelDtor)(
      pMovieImpl->pExtIntfHandler.pObject,
      pMovieImpl,
      pData,
      v14,
      v4);
    Scaleform::GFx::AS2::Value::operator=(
      fn->Result,
      (Scaleform::GFx::AS2::Value *)&pMovieImpl->pASMovieRoot.pObject[2].RefCount);
    if ( (_DWORD)v4 )
    {
      v23 = v14 + 16;
      v24 = (unsigned int)v4;
      do
      {
        if ( (v23[1] & 0x40) != 0 )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v23 + 16i64))(*v23, v23 - 2, v23[2]);
          *v23 = 0i64;
        }
        *((_DWORD *)v23 + 2) = 0;
        v23 += 6;
        --v24;
      }
      while ( v24 );
    }
    if ( (unsigned int)v4 > 0x3C )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14);
    v11 = v5->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptWarning(
      fn,
      "ExternalInterface.call - handler is not installed.");
    v25 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v25);
    v25->T.Type = 0;
  }
}

// File Line: 162
// RVA: 0x6F9480
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
}

// File Line: 167
// RVA: 0x6E04F0
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ExternalInterface *v3; // rax

  v3 = (Scaleform::GFx::AS2::ExternalInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   this,
                                                   96i64);
  if ( v3 )
    Scaleform::GFx::AS2::ExternalInterface::ExternalInterface(v3, penv);
}

// File Line: 173
// RVA: 0x70D690
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+30h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+B0h] [rbp+38h]
  Scaleform::MemoryHeap **p_flags; // [rsp+B8h] [rbp+40h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))flags->vfptr->Alloc)(
                                                               result,
                                                               104i64);
  pHeap = (Scaleform::MemoryHeap *)v4;
  if ( v4 )
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::ExternalInterfaceCtorFunction(v4, &psc);
  result->Flags = 0;
  result->Function = v4;
  result->pLocalFrame = 0i64;
  pHeap = pgc->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment> *)pHeap->vfptr->Alloc(v5, 160ui64, 0i64);
  p_flags = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      Prototype,
      result);
    v6->Scaleform::GFx::AS2::ExternalInterface::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::ExternalInterface::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v6->Scaleform::GFx::AS2::GASPrototypeBase,
      v6,
      &psc,
      GFx_EIFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v6 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v6;
  p_flags = &flags;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  flags = (Scaleform::MemoryHeap *)v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_ExternalInterface,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v13.T.Type = 8;
  v13.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v13.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v13.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v13.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(flags) = 0;
  pgc->FlashExternalPackage->vfptr->SetMemberRaw(
    &pgc->FlashExternalPackage->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[13].pMovieImpl,
    &v13,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v13.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v13);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

