// File Line: 30
// RVA: 0x6C8640
void __fastcall Scaleform::GFx::AS2::ExternalInterface::ExternalInterface(Scaleform::GFx::AS2::ExternalInterface *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ExternalInterface *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterface::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterface::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_ExternalInterface);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 55
// RVA: 0x6C86C0
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::ExternalInterfaceCtorFunction(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rdi
  Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *v3; // rbx
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS2::Value v7; // [rsp+38h] [rbp-40h]
  char v8; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+20h]

  v2 = psc;
  v3 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GlobalCtor);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v7.T.Type = 10;
  v4 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "available");
  v8 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v4,
    &v7,
    (Scaleform::GFx::AS2::PropFlags *)&v8);
  v5 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::StaticFunctionTable,
    7);
}

// File Line: 64
// RVA: 0x6F1EE0
char __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GetMember(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *v7; // r14
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString *v9; // rsi
  bool v10; // zf
  bool v11; // si
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ExternalInterface *v13; // rbx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "available");
  v9 = v8;
  if ( v6->StringContext.SWFVersion <= 6u )
  {
    if ( !v8->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v8->pNode);
    if ( !v5->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
    v10 = v9->pNode->pLower == v5->pNode->pLower;
  }
  else
  {
    v10 = v8->pNode == v5->pNode;
  }
  v11 = v10;
  v12 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !v11 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v7->vfptr[3].~RefCountBaseGC<323>)(
             v7,
             &v6->StringContext,
             v5,
             v4,
             -2i64);
  v13 = v6->Target->pASRoot->pMovieImpl->pExtIntfHandler.pObject;
  Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->T.Type = 2;
  v4->V.BooleanValue = v13 != 0i64;
  return 1;
}

// File Line: 78
// RVA: 0x6BB040
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::AddCallback(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbp
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::MovieImpl *v4; // r14
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Value *v6; // r10
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::CharacterHandle *v10; // rsi
  Scaleform::GFx::AS2::Object *v11; // rbx
  unsigned int v12; // er10
  Scaleform::GFx::AS2::Environment *v13; // r9
  Scaleform::GFx::AS2::Value *v14; // r8
  unsigned __int64 v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rdx
  Scaleform::GFx::CharacterHandle *v18; // rcx
  Scaleform::GFx::DisplayObject *v19; // rax
  Scaleform::GFx::DisplayObject *v20; // rdi
  Scaleform::GFx::AS2::Value *v21; // r11
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::AS2::Value *v23; // rdi
  unsigned int v24; // eax
  char v25; // al
  Scaleform::GFx::AS2::FunctionObject *v26; // rcx
  unsigned int v27; // edx
  Scaleform::GFx::AS2::LocalFrame *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::ASStringNode *v30; // rcx
  bool v31; // zf
  Scaleform::GFx::AS2::FunctionRef func; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::CharacterHandle *v34; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::AS2::Object *v35; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::DisplayObject *v36; // [rsp+98h] [rbp+20h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->NArgs >= 3 )
  {
    v3 = v1->Env;
    v4 = v3->Target->pASRoot->pMovieImpl;
    v5 = v1->FirstArgBottomIndex;
    v6 = 0i64;
    if ( v5 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v6 = &v3->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v6, &result, v3, -1);
    v7 = v1->FirstArgBottomIndex - 2;
    v8 = v1->Env;
    v9 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v9, &func, v8);
    v10 = 0i64;
    v34 = 0i64;
    v11 = 0i64;
    v35 = 0i64;
    v12 = v1->FirstArgBottomIndex - 1;
    v13 = v1->Env;
    v14 = 0i64;
    if ( v12 <= 32 * ((unsigned int)v13->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5) )
      v14 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
    v15 = v13->Stack.Pages.Data.Size;
    v16 = (_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5;
    if ( v14->T.Type == 7 )
    {
      v17 = 0i64;
      if ( v12 <= 32 * ((signed int)v15 - 1) + (signed int)v16 )
        v17 = (signed __int64)&v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
      if ( *(_BYTE *)v17 == 7
        && v13
        && (v18 = *(Scaleform::GFx::CharacterHandle **)(v17 + 8)) != 0i64
        && (v19 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v18, v13->Target->pASRoot->pMovieImpl)) != 0i64 )
      {
        v20 = 0i64;
        if ( SLOBYTE(v19->Flags) < 0 )
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
        v10 = v20->pNameHandle.pObject;
        if ( v10 || (v10 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v20)) != 0i64 )
          ++v10->RefCount;
        v34 = v10;
      }
      if ( v20 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v20->vfptr);
    }
    else
    {
      v21 = 0i64;
      if ( v12 <= 32 * ((signed int)v15 - 1) + (signed int)v16 )
        v21 = &v13->Stack.Pages.Data.Data[v12 >> 5]->Values[v12 & 0x1F];
      v22 = Scaleform::GFx::AS2::Value::ToObject(v21, v1->Env);
      v11 = v22;
      if ( v22 )
        v22->RefCount = (v22->RefCount + 1) & 0x8FFFFFFF;
      v35 = v22;
    }
    Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(
      (Scaleform::GFx::AS2::MovieRoot *)v4->pASMovieRoot.pObject,
      &result,
      v10,
      v11,
      &func);
    v23 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v23->T.Type = 2;
    v23->V.BooleanValue = 1;
    if ( v11 )
    {
      v24 = v11->RefCount;
      if ( v24 & 0x3FFFFFF )
      {
        v11->RefCount = v24 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
      }
    }
    if ( v10 )
    {
      if ( --v10->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v10);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
      }
    }
    v25 = func.Flags;
    if ( !(func.Flags & 2) )
    {
      v26 = func.Function;
      if ( func.Function )
      {
        v27 = func.Function->RefCount;
        if ( v27 & 0x3FFFFFF )
        {
          func.Function->RefCount = v27 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v26->vfptr);
          v25 = func.Flags;
        }
      }
    }
    func.Function = 0i64;
    if ( !(v25 & 1) )
    {
      v28 = func.pLocalFrame;
      if ( func.pLocalFrame )
      {
        v29 = func.pLocalFrame->RefCount;
        if ( v29 & 0x3FFFFFF )
        {
          func.pLocalFrame->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v28->vfptr);
        }
      }
    }
    func.pLocalFrame = 0i64;
    v30 = result.pNode;
    v31 = result.pNode->RefCount == 1;
    --v30->RefCount;
    if ( v31 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  }
}

// File Line: 106
// RVA: 0x6BBA20
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Call(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Environment *v2; // rcx
  Scaleform::GFx::MovieImpl *v3; // r15
  __int64 v4; // rbp
  Scaleform::GFx::ASStringNode *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r10
  Scaleform::GFx::ASStringNode *v9; // rdi
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::MemoryHeap *v12; // rcx
  char *v13; // r13
  unsigned int v14; // er14
  Scaleform::GFx::ASStringNode *v15; // rdi
  unsigned int v16; // edx
  Scaleform::GFx::AS2::Environment *v17; // r9
  Scaleform::GFx::AS2::Value *v18; // r8
  Scaleform::GFx::Value *v19; // r9
  Scaleform::GFx::ASMovieRootBase *v20; // rdi
  const char *v21; // r8
  _QWORD *v22; // rdi
  __int64 v23; // rsi
  Scaleform::GFx::AS2::Value *v24; // rbx
  char v25; // [rsp+40h] [rbp-218h]
  Scaleform::GFx::ASString result; // [rsp+268h] [rbp+10h]
  Scaleform::GFx::ASStringNode *v27; // [rsp+270h] [rbp+18h]

  v1 = fn;
  v2 = fn->Env;
  v3 = v2->Target->pASRoot->pMovieImpl;
  if ( v3->pExtIntfHandler.pObject )
  {
    LODWORD(v4) = 0;
    v5 = *(Scaleform::GFx::ASStringNode **)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
    ++v5->RefCount;
    if ( v1->NArgs < 1 )
      goto LABEL_34;
    v6 = v1->FirstArgBottomIndex;
    v7 = v1->Env;
    v8 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToString(v8, &result, v7, -1)->pNode;
    ++v9->RefCount;
    v10 = v5->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v5 = v9;
    v11 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v4 = (unsigned int)(v1->NArgs - 1);
    if ( (unsigned int)v4 <= 0xA )
    {
LABEL_34:
      v13 = &v25;
    }
    else
    {
      v12 = v1->Env->StringContext.pContext->pHeap;
      v13 = (char *)v12->vfptr->Alloc(v12, 48 * v4, 0i64);
    }
    v14 = 0;
    if ( (_DWORD)v4 )
    {
      v15 = (Scaleform::GFx::ASStringNode *)v13;
      do
      {
        v16 = v1->FirstArgBottomIndex - v14 - 1;
        v17 = v1->Env;
        v18 = 0i64;
        if ( v16 <= 32 * ((unsigned int)v17->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v17->Stack.pCurrent - (char *)v17->Stack.pPageStart) >> 5) )
          v18 = &v17->Stack.Pages.Data.Data[v16 >> 5]->Values[v16 & 0x1F];
        result.pNode = v15;
        v27 = v15;
        if ( v15 )
        {
          v15->pLower = 0i64;
          v15->RefCount = 0;
          v19 = (Scaleform::GFx::Value *)v15;
        }
        else
        {
          v19 = 0i64;
        }
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
          (Scaleform::GFx::AS2::MovieRoot *)v3->pASMovieRoot.pObject,
          v1->Env,
          v18,
          v19);
        ++v14;
        v15 = (Scaleform::GFx::ASStringNode *)((char *)v15 + 48);
      }
      while ( v14 < (unsigned int)v4 );
    }
    v20 = v3->pASMovieRoot.pObject;
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v20[2].RefCount);
    LOBYTE(v20[2].RefCount) = 0;
    v21 = 0i64;
    if ( v5->Size )
      v21 = v5->pData;
    ((void (__fastcall *)(Scaleform::GFx::ExternalInterface *, Scaleform::GFx::MovieImpl *, const char *, char *, _DWORD))v3->pExtIntfHandler.pObject->vfptr[1].__vecDelDtor)(
      v3->pExtIntfHandler.pObject,
      v3,
      v21,
      v13,
      v4);
    Scaleform::GFx::AS2::Value::operator=(
      v1->Result,
      (Scaleform::GFx::AS2::Value *)&v3->pASMovieRoot.pObject[2].RefCount);
    if ( (_DWORD)v4 )
    {
      v22 = v13 + 16;
      v23 = (unsigned int)v4;
      do
      {
        if ( (*((_DWORD *)v22 + 2) >> 6) & 1 )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v22 + 16i64))(*v22, v22 - 2, v22[2]);
          *v22 = 0i64;
        }
        *((_DWORD *)v22 + 2) = 0;
        v22 += 6;
        --v23;
      }
      while ( v23 );
    }
    if ( (unsigned int)v4 > 0x3C )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
    v10 = v5->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::LogScriptWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall> *)&v1->vfptr,
      "ExternalInterface.call - handler is not installed.");
    v24 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v24->T.Type = 0;
  }
}

// File Line: 162
// RVA: 0x6F9480
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
}

// File Line: 167
// RVA: 0x6E04F0
void __fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::CreateNewObject(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ExternalInterface *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::ExternalInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                   this,
                                                   96i64);
  if ( v3 )
    Scaleform::GFx::AS2::ExternalInterface::ExternalInterface(v3, v2);
}

// File Line: 173
// RVA: 0x70D690
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::AS2::LocalFrame *v9; // rdx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v13; // [rsp+50h] [rbp-28h]
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+30h]
  void *v15; // [rsp+B0h] [rbp+38h]
  Scaleform::MemoryHeap **v16; // [rsp+B8h] [rbp+40h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))flags->vfptr->Alloc)(
                                                               result,
                                                               104i64);
  v15 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::ExternalInterfaceCtorFunction(v4, &psc);
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)&v4->vfptr;
  v3->pLocalFrame = 0i64;
  v15 = v2->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment> *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v15 + 80i64))(v5, 160i64, 0i64);
  v16 = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      v7,
      v3);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v6->vfptr,
      (Scaleform::GFx::AS2::Object *)&v6->vfptr,
      &psc,
      GFx_EIFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v6 = 0i64;
  }
  v15 = v6;
  v16 = &flags;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  flags = (Scaleform::MemoryHeap *)v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_ExternalInterface,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v13.T.Type = 8;
  v13.V.FunctionValue.Flags = 0;
  v8 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v13.V.pStringNode = v8;
  if ( v8 )
  {
    ++v8->RefCount;
    v8->RefCount &= 0x8FFFFFFF;
  }
  v13.V.FunctionValue.pLocalFrame = 0i64;
  v9 = v3->pLocalFrame;
  if ( v9 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v13.NV.8,
      v9,
      v3->Flags & 1);
  LOBYTE(flags) = 0;
  v2->FlashExternalPackage->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v2->FlashExternalPackage->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[13].pMovieImpl,
    &v13,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v13.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v13);
  if ( v6 )
  {
    v10 = v6->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v6->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v3;
}

