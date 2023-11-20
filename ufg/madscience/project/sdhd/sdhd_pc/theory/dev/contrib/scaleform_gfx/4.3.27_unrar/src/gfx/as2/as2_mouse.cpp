// File Line: 78
// RVA: 0x6CA6A0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::MouseCtorFunction(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::MovieRoot *proot)
{
  Scaleform::GFx::AS2::MovieRoot *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::MouseCtorFunction *v5; // rdi
  __int64 v6; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v7; // rax
  unsigned __int64 v8; // rax
  Scaleform::GFx::AS2::FunctionRef *v9; // rax
  char v10; // al
  Scaleform::GFx::AS2::FunctionObject *v11; // rcx
  unsigned int v12; // edx
  Scaleform::GFx::AS2::LocalFrame *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::AS2::Value v16; // [rsp+40h] [rbp-48h]

  v3 = proot;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  v5->vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable';
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable';
  v5->pListenersArray.pObject = 0i64;
  v5->SetCursorTypeFunc.Flags = 0;
  v5->SetCursorTypeFunc.Function = 0i64;
  v5->SetCursorTypeFunc.pLocalFrame = 0i64;
  v3->pASMouseListener = (Scaleform::GFx::AS2::MouseListener *)&v5->vfptr;
  if ( v5 != (Scaleform::GFx::AS2::MouseCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v4,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(v4, (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr);
  Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(v5, v4, 0i64);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::MouseCtorFunction::StaticFunctionTable,
    7);
  v16.T.Type = 8;
  v7 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, signed __int64))v4->pContext->pHeap->vfptr->Alloc)(
                                                 v6,
                                                 104i64);
  if ( v7 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v7, v4, Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  else
    v8 = 0i64;
  v16.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v16.NV.Int32Value = v8;
  v9 = Scaleform::GFx::AS2::Value::ToFunction(&v16, &result, 0i64);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v5->SetCursorTypeFunc.Function,
    (Scaleform::GFx::AS2::FunctionRefBase *)&v9->Function);
  v10 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v11 = result.Function;
    if ( result.Function )
    {
      v12 = result.Function->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        result.Function->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
        v10 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v10 & 1) )
  {
    v13 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v14 = result.pLocalFrame->RefCount;
      if ( v14 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
      }
    }
  }
  result.pLocalFrame = 0i64;
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  v5->LastClickTime = 0;
}.T.Type >= 5u )
    Sc

// File Line: 99
// RVA: 0x6BFB30
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::MouseCtorFunction *v2; // rsi
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rbx

  v2 = this;
  v3 = prcc;
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    (Scaleform::GFx::AS2::FunctionRefBase *)&this->SetCursorTypeFunc.Function,
    prcc);
  v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pListenersArray.pObject->vfptr;
  if ( v4 )
  {
    if ( --v4->RefCount & 0x3FFFFFF )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(v3, v4);
      v4->RefCount |= 0x4000000u;
      if ( !((v4->RefCount >> 27) & 1) )
      {
        v4->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v3->pLastPtr->pRCC->Roots.gap0;
        v4->pRCC = v3->pLastPtr->pRCC;
        *(_QWORD *)v3->pLastPtr->pRCC->Roots.gap0 = v4;
        v3->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4;
        v3->pLastPtr = v4;
        v4->RefCount |= 0x8000000u;
      }
    }
  }
  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    (Scaleform::GFx::AS2::Object *)&v2->vfptr,
    v3);
}

// File Line: 108
// RVA: 0x6E89C0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::ExecuteForEachChild_GC(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

  if ( operation )
  {
    v3 = operation - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        Scaleform::GFx::AS2::MouseCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::MouseCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}

// File Line: 113
// RVA: 0x6E9D50
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::Finalize_GC(Scaleform::GFx::AS2::SuperObject *this)
{
  Scaleform::GFx::AS2::SuperObject *v1; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v2; // rcx

  v1 = this;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->pWatchpoints->mHash.pTable;
  if ( v2 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v2);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pWatchpoints);
  }
}

// File Line: 119
// RVA: 0x7003D0
bool __fastcall Scaleform::GFx::AS2::MouseCtorFunction::IsEmpty(Scaleform::GFx::AS2::MouseCtorFunction *this)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v1; // rdx
  bool result; // al

  v1 = this->pRCC;
  if ( v1 )
    result = LODWORD(v1[1].vfptr) == 0;
  else
    result = 0;
  return result;
}

// File Line: 126
// RVA: 0x722FA0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v3; // rbx
  Scaleform::GFx::AS2::MouseCtorFunction *v4; // rdi
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-30h]

  v3 = penv;
  v4 = this;
  v11.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, signed __int64))this->vfptr->GetMemberRaw)(
         &this->vfptr,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v11,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v11, v3);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 && (*(unsigned int (**)(void))&v5->vfptr->gap8[8])() == 7 )
    {
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
      v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pListenersArray.pObject->vfptr;
      if ( v7 )
      {
        v8 = v7->RefCount;
        if ( v8 & 0x3FFFFFF )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
      v4->pListenersArray.pObject = v6;
    }
    else
    {
      v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pListenersArray.pObject->vfptr;
      if ( v9 )
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      v4->pListenersArray.pObject = 0i64;
    }
  }
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 264
// RVA: 0x70ACA0
signed __int64 __fastcall Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex, Scaleform::GFx::AS2::ASBuiltinType eventName, Scaleform::GFx::AS2::Value *eventMethod, Scaleform::GFx::ASString *ptargetName, unsigned int button, int delta, bool dblClick)
{
  Scaleform::GFx::AS2::ASBuiltinType v8; // er14
  unsigned int v9; // er15
  Scaleform::GFx::AS2::Environment *v10; // rsi
  Scaleform::GFx::AS2::GlobalContext *v11; // rax
  bool v12; // r12
  signed __int64 v13; // rdi
  char v14; // al
  Scaleform::GFx::AS2::FunctionObject *v15; // rcx
  unsigned int v16; // edx
  Scaleform::GFx::AS2::LocalFrame *v17; // rcx
  unsigned int v18; // eax
  char v19; // al
  Scaleform::GFx::AS2::FunctionObject *v20; // rcx
  unsigned int v21; // edx
  Scaleform::GFx::AS2::LocalFrame *v22; // rcx
  unsigned int v23; // eax
  signed int v25; // ebx
  Scaleform::GFx::AS2::Value *v26; // rax
  __m128 v27; // xmm9
  __m128d v28; // xmm6
  __int64 v29; // rcx
  double v30; // xmm6_8
  Scaleform::GFx::AS2::Value *v31; // rax
  __m128d v32; // xmm6
  __int64 v33; // rcx
  double v34; // xmm6_8
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::GFx::AS2::Value *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rax
  Scaleform::GFx::AS2::Value *v39; // rax
  Scaleform::GFx::AS2::Value *v40; // rcx
  Scaleform::GFx::AS2::Value *v41; // rax
  Scaleform::GFx::AS2::Value *v42; // rax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-40h]
  unsigned int v44; // [rsp+B8h] [rbp+48h]

  v44 = mouseIndex;
  v8 = eventName;
  v9 = mouseIndex;
  v10 = penv;
  v11 = penv->StringContext.pContext;
  v12 = v11->GFxExtensions.Value != 1;
  v13 = 0i64;
  if ( v11->GFxExtensions.Value != 1 || !button || (unsigned int)(eventName - 103) > 1 )
    goto LABEL_26;
  Scaleform::GFx::AS2::Value::ToFunction(eventMethod, &result, penv);
  if ( result.Function )
  {
    if ( ((signed int (__cdecl *)(Scaleform::GFx::AS2::FunctionObject *))result.Function->vfptr[5].Finalize_GC)(result.Function) > 0 )
      goto LABEL_8;
    if ( button <= 1 )
    {
      v12 = 1;
LABEL_8:
      v14 = result.Flags;
      if ( !(result.Flags & 2) )
      {
        v15 = result.Function;
        if ( result.Function )
        {
          v16 = result.Function->RefCount;
          if ( v16 & 0x3FFFFFF )
          {
            result.Function->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
            v14 = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( !(v14 & 1) )
      {
        v17 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v18 = result.pLocalFrame->RefCount;
          if ( v18 & 0x3FFFFFF )
          {
            result.pLocalFrame->RefCount = v18 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
          }
        }
      }
      result.pLocalFrame = 0i64;
LABEL_26:
      v25 = 0;
      if ( v10->StringContext.pContext->GFxExtensions.Value == 1 && !v12 )
      {
        if ( v8 == 103 )
        {
          if ( dblClick )
          {
            ++v10->Stack.pCurrent;
            if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
            v26 = v10->Stack.pCurrent;
            if ( v26 )
            {
              v26->T.Type = 2;
              v26->V.BooleanValue = dblClick;
            }
            v25 = 1;
          }
          v9 = v44;
        }
        if ( v9 < 6 )
          v13 = (signed __int64)&v10->Target->pASRoot->pMovieImpl->mMouseState[v9];
        v27 = (__m128)*(unsigned int *)(v13 + 56);
        v28 = _mm_cvtps_pd((__m128)*(unsigned int *)(v13 + 60));
        v28.m128d_f64[0] = v28.m128d_f64[0] + 0.5;
        v29 = (unsigned int)(signed int)v28.m128d_f64[0];
        if ( v29 != 0x8000000000000000i64 && (double)(signed int)v29 != v28.m128d_f64[0] )
          v28.m128d_f64[0] = (double)(signed int)(v29 - (_mm_movemask_pd(_mm_unpckl_pd(v28, v28)) & 1));
        v30 = v28.m128d_f64[0] * 0.05;
        ++v10->Stack.pCurrent;
        if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
        v31 = v10->Stack.pCurrent;
        if ( v31 )
        {
          v31->T.Type = 3;
          v31->NV.NumberValue = v30;
        }
        v32 = _mm_cvtps_pd(v27);
        v32.m128d_f64[0] = v32.m128d_f64[0] + 0.5;
        v33 = (unsigned int)(signed int)v32.m128d_f64[0];
        if ( v33 != 0x8000000000000000i64 && (double)(signed int)v33 != v32.m128d_f64[0] )
          v32.m128d_f64[0] = (double)(signed int)(v33 - (_mm_movemask_pd(_mm_unpckl_pd(v32, v32)) & 1));
        v34 = v32.m128d_f64[0] * 0.05;
        ++v10->Stack.pCurrent;
        if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
        v35 = v10->Stack.pCurrent;
        if ( v35 )
        {
          v35->T.Type = 3;
          v35->NV.NumberValue = v34;
        }
        ++v10->Stack.pCurrent;
        if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
        v36 = v10->Stack.pCurrent;
        if ( v36 )
        {
          v36->T.Type = 4;
          v36->NV.Int32Value = v9;
        }
        v25 += 3;
      }
      if ( v8 != 105 )
      {
        if ( !ptargetName || v8 != 106 && v12 )
        {
          if ( v25 <= 0 )
            goto LABEL_72;
          ++v10->Stack.pCurrent;
          if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
          v39 = v10->Stack.pCurrent;
          if ( v39 )
            v39->T.Type = 1;
        }
        else
        {
          ++v10->Stack.pCurrent;
          if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
          v37 = v10->Stack.pCurrent;
          if ( v37 )
          {
            v37->T.Type = 5;
            v38 = ptargetName->pNode;
            v37->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)ptargetName->pNode;
            ++v38->RefCount;
          }
        }
        ++v25;
      }
LABEL_72:
      if ( (signed int)v8 >= 103 )
      {
        if ( (signed int)v8 <= 104 )
        {
          if ( button && !v12 )
          {
            ++v10->Stack.pCurrent;
            if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
            v41 = v10->Stack.pCurrent;
            if ( v41 )
            {
              v41->T.Type = 3;
              v41->NV.NumberValue = (double)(signed int)button;
            }
            goto LABEL_92;
          }
          if ( v25 > 0 )
          {
            ++v10->Stack.pCurrent;
            if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
            v42 = v10->Stack.pCurrent;
            if ( v42 )
              v42->T.Type = 1;
            goto LABEL_92;
          }
        }
        else if ( v8 == 106 )
        {
          ++v10->Stack.pCurrent;
          if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
          v40 = v10->Stack.pCurrent;
          if ( v40 )
          {
            v40->T.Type = 4;
            v40->NV.Int32Value = delta;
          }
LABEL_92:
          ++v25;
          return (unsigned int)v25;
        }
      }
      return (unsigned int)v25;
    }
  }
  v19 = result.Flags;
  if ( !(result.Flags & 2) )
  {
    v20 = result.Function;
    if ( result.Function )
    {
      v21 = result.Function->RefCount;
      if ( v21 & 0x3FFFFFF )
      {
        result.Function->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
        v19 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( !(v19 & 1) )
  {
    v22 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v23 = result.pLocalFrame->RefCount;
      if ( v23 & 0x3FFFFFF )
      {
        result.pLocalFrame->RefCount = v23 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v22->vfptr);
      }
    }
  }
  result.pLocalFrame = 0i64;
  return 0xFFFFFFFFi64;
}

// File Line: 353
// RVA: 0x703750
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex, Scaleform::GFx::AS2::ASBuiltinType eventName, Scaleform::GFx::ASString *ptargetName, unsigned int button, int delta, bool dblClick)
{
  Scaleform::GFx::AS2::Environment *v8; // r10
  Scaleform::GFx::AS2::ObjectInterface *v9; // rdx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h]
  unsigned int v11; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS2::ASBuiltinType v12; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString *v13; // [rsp+38h] [rbp-20h]
  unsigned int v14; // [rsp+40h] [rbp-18h]
  int v15; // [rsp+44h] [rbp-14h]
  bool v16; // [rsp+48h] [rbp-10h]

  v8 = penv;
  pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
  v11 = mouseIndex;
  v12 = eventName;
  v13 = ptargetName;
  v14 = button;
  v15 = delta;
  v16 = dblClick;
  if ( this )
    v9 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  else
    v9 = 0i64;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    v8,
    v9,
    (Scaleform::GFx::ASString *)&v8->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
  + (signed int)eventName,
    &pcallback);
}

// File Line: 428
// RVA: 0x706C60
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseMove(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex)
{
  Scaleform::GFx::AS2::Environment *v3; // r10
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdx
  Scaleform::GFx::AS2::LocalFrame **v5; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h]
  unsigned int v7; // [rsp+30h] [rbp-28h]
  int v8; // [rsp+34h] [rbp-24h]
  __int64 v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  char v11; // [rsp+48h] [rbp-10h]

  v3 = penv;
  pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
  v7 = mouseIndex;
  v8 = 105;
  v4 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0;
  v5 = &this[-1].ResolveHandler.pLocalFrame;
  if ( v5 )
    v4 = (Scaleform::GFx::AS2::ObjectInterface *)(v5 + 4);
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    v3,
    v4,
    (Scaleform::GFx::ASString *)&v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].AVMVersion,
    &pcallback);
}

// File Line: 433
// RVA: 0x7063C0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseDown(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex, unsigned int button, Scaleform::GFx::InteractiveObject *ptarget)
{
  int v5; // er15
  __int64 v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // rbp
  Scaleform::GFx::AS2::MouseCtorFunction *v8; // rbx
  bool dblClick; // si
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // r10
  signed __int64 v13; // rax
  signed int v14; // ecx
  signed int v15; // edx
  Scaleform::GFx::CharacterHandle *v16; // rax
  bool v17; // zf
  signed __int64 v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-40h]
  int v21; // [rsp+50h] [rbp-38h]
  int v22; // [rsp+54h] [rbp-34h]
  Scaleform::GFx::InteractiveObject **v23; // [rsp+58h] [rbp-30h]
  int v24; // [rsp+60h] [rbp-28h]
  int v25; // [rsp+64h] [rbp-24h]
  bool v26; // [rsp+68h] [rbp-20h]

  v5 = button;
  v6 = mouseIndex;
  v7 = penv;
  v8 = this;
  dblClick = 0;
  v10 = 0i64;
  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v11 = Scaleform::Timer::GetTicks();
    v12 = (unsigned __int64)((v11 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)
                           + ((unsigned __int64)(v11 - (v11 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64)) >> 1)) >> 9;
    if ( (unsigned int)v6 < 6 )
      v13 = (signed __int64)&v7->Target->pASRoot->pMovieImpl->mMouseState[v6];
    else
      v13 = 0i64;
    v14 = (signed int)(float)(*(float *)(v13 + 56) * 0.050000001);
    v15 = (signed int)(float)(*(float *)(v13 + 60) * 0.050000001);
    if ( (unsigned int)v12 <= v8->RefCount + 300 && v8->RootIndex == v14 )
    {
      dblClick = 0;
      if ( HIDWORD(v8->pPrev) == v15 )
        dblClick = 1;
    }
    v8->RootIndex = v14;
    HIDWORD(v8->pPrev) = v15;
    v8->RefCount = v12;
  }
  if ( ptarget )
  {
    v16 = ptarget->pNameHandle.pObject;
    if ( !v16 )
      v16 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&ptarget->vfptr);
    ptarget = (Scaleform::GFx::InteractiveObject *)v16->NamePath.pNode;
    ++LODWORD(ptarget->vfptr);
    v17 = v8 == (Scaleform::GFx::AS2::MouseCtorFunction *)104;
    v18 = (signed __int64)&v8[-1].ResolveHandler.pLocalFrame;
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
    v21 = v6;
    v22 = 103;
    v23 = &ptarget;
    v24 = v5;
    v25 = 0;
    v26 = dblClick;
    if ( !v17 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(v18 + 32);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v7,
      v10,
      (Scaleform::GFx::ASString *)&v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].pMovieImpl,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
    v19 = (Scaleform::GFx::ASStringNode *)ptarget;
    v17 = LODWORD(ptarget->vfptr) == 1;
    --v19->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)v8 - 104),
      v7,
      v6,
      ASBuiltin_onMouseDown,
      0i64,
      v5,
      0,
      dblClick);
  }
}

// File Line: 466
// RVA: 0x706CE0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseUp(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex, unsigned int button, Scaleform::GFx::InteractiveObject *ptarget)
{
  unsigned int v5; // edi
  unsigned int v6; // esi
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::AS2::MouseCtorFunction *v8; // rbp
  Scaleform::GFx::CharacterHandle *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-30h]
  unsigned int v14; // [rsp+50h] [rbp-28h]
  int v15; // [rsp+54h] [rbp-24h]
  Scaleform::GFx::InteractiveObject **v16; // [rsp+58h] [rbp-20h]
  unsigned int v17; // [rsp+60h] [rbp-18h]
  int v18; // [rsp+64h] [rbp-14h]
  char v19; // [rsp+68h] [rbp-10h]

  v5 = button;
  v6 = mouseIndex;
  v7 = penv;
  v8 = this;
  if ( ptarget )
  {
    v9 = ptarget->pNameHandle.pObject;
    if ( !v9 )
      v9 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&ptarget->vfptr);
    ptarget = (Scaleform::GFx::InteractiveObject *)v9->NamePath.pNode;
    ++LODWORD(ptarget->vfptr);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
    v14 = v6;
    v15 = 104;
    v16 = &ptarget;
    v17 = v5;
    v10 = 0i64;
    v18 = 0;
    v19 = 0;
    if ( v8 != (Scaleform::GFx::AS2::MouseCtorFunction *)104 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(&v8[-1].ResolveHandler.pLocalFrame + 4);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v7,
      v10,
      (Scaleform::GFx::ASString *)&v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].pASSupport,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
    v11 = (Scaleform::GFx::ASStringNode *)ptarget;
    v12 = LODWORD(ptarget->vfptr) == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 104),
      penv,
      mouseIndex,
      ASBuiltin_onMouseUp,
      0i64,
      button,
      0,
      0);
  }
}

// File Line: 477
// RVA: 0x706E00
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseWheel(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, unsigned int mouseIndex, int sdelta, Scaleform::GFx::InteractiveObject *ptarget)
{
  int v5; // edi
  unsigned int v6; // esi
  Scaleform::GFx::AS2::Environment *v7; // rbx
  Scaleform::GFx::AS2::MouseCtorFunction *v8; // rbp
  Scaleform::GFx::CharacterHandle *v9; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-30h]
  unsigned int v14; // [rsp+50h] [rbp-28h]
  int v15; // [rsp+54h] [rbp-24h]
  Scaleform::GFx::InteractiveObject **v16; // [rsp+58h] [rbp-20h]
  int v17; // [rsp+60h] [rbp-18h]
  int v18; // [rsp+64h] [rbp-14h]
  char v19; // [rsp+68h] [rbp-10h]

  v5 = sdelta;
  v6 = mouseIndex;
  v7 = penv;
  v8 = this;
  if ( ptarget )
  {
    v9 = ptarget->pNameHandle.pObject;
    if ( !v9 )
      v9 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&ptarget->vfptr);
    ptarget = (Scaleform::GFx::InteractiveObject *)v9->NamePath.pNode;
    ++LODWORD(ptarget->vfptr);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable';
    v14 = v6;
    v15 = 106;
    v16 = &ptarget;
    v10 = 0i64;
    v17 = 0;
    v18 = v5;
    v19 = 0;
    if ( v8 != (Scaleform::GFx::AS2::MouseCtorFunction *)104 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(&v8[-1].ResolveHandler.pLocalFrame + 4);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v7,
      v10,
      (Scaleform::GFx::ASString *)&v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[29],
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
    v11 = (Scaleform::GFx::ASStringNode *)ptarget;
    v12 = LODWORD(ptarget->vfptr) == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 104),
      penv,
      mouseIndex,
      ASBuiltin_onMouseWheel,
      0i64,
      0,
      sdelta,
      0);
  }
}

// File Line: 488
// RVA: 0x6B5D50
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::Show(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::GFx::MovieImpl *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // edx
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::UserEventHandler *v8; // rcx
  int v9; // [rsp+20h] [rbp-18h]
  char v10; // [rsp+24h] [rbp-14h]
  int v11; // [rsp+28h] [rbp-10h]
  unsigned int v12; // [rsp+2Ch] [rbp-Ch]

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->Env;
  v4 = v3->Target->pASRoot->pMovieImpl;
  if ( v4->pUserEventHandler.pObject )
  {
    v5 = 0;
    if ( v2->NArgs >= 1 )
    {
      v6 = v2->FirstArgBottomIndex;
      v7 = 0i64;
      if ( v6 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
               + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
        v7 = &v3->Stack.Pages.Data.Data[(unsigned __int64)v6 >> 5]->Values[v6 & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToUInt32(v7, v2->Env);
    }
    v8 = v4->pUserEventHandler.pObject;
    v10 = 0;
    v9 = 21;
    v11 = 0;
    v12 = v5;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v8->vfptr[1].__vecDelDtor)(
      v8,
      v4,
      &v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      v2->Env,
      "No user event handler interface is installed; Mouse.show failed.");
  }
}

// File Line: 503
// RVA: 0x6B5A80
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::Hide(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::GFx::MovieImpl *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // edx
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::UserEventHandler *v8; // rcx
  int v9; // [rsp+20h] [rbp-18h]
  char v10; // [rsp+24h] [rbp-14h]
  int v11; // [rsp+28h] [rbp-10h]
  unsigned int v12; // [rsp+2Ch] [rbp-Ch]

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->Env;
  v4 = v3->Target->pASRoot->pMovieImpl;
  if ( v4->pUserEventHandler.pObject )
  {
    v5 = 0;
    if ( v2->NArgs >= 1 )
    {
      v6 = v2->FirstArgBottomIndex;
      v7 = 0i64;
      if ( v6 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
               + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
        v7 = &v3->Stack.Pages.Data.Data[(unsigned __int64)v6 >> 5]->Values[v6 & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToUInt32(v7, v2->Env);
    }
    v8 = v4->pUserEventHandler.pObject;
    v10 = 0;
    v9 = 22;
    v11 = 0;
    v12 = v5;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v8->vfptr[1].__vecDelDtor)(
      v8,
      v4,
      &v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      v2->Env,
      "No user event handler interface is installed; Mouse.hide failed.");
  }
}

// File Line: 518
// RVA: 0x713610
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // r10
  Scaleform::GFx::AS2::Value *v4; // rbx
  signed int v5; // ebp
  Scaleform::GFx::MovieImpl *v6; // rsi
  unsigned int v7; // edx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Environment *v9; // rdx
  unsigned __int64 v10; // r8
  Scaleform::GFx::UserEventHandler *v11; // rcx
  int v12; // [rsp+20h] [rbp-18h]
  char v13; // [rsp+24h] [rbp-14h]
  int v14; // [rsp+28h] [rbp-10h]
  int v15; // [rsp+2Ch] [rbp-Ch]

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->Env;
  v4 = 0i64;
  v5 = 0;
  v6 = v3->Target->pASRoot->pMovieImpl;
  if ( v2->NArgs > 0 )
  {
    v7 = v2->FirstArgBottomIndex;
    v8 = 0i64;
    if ( v7 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v8 = &v3->Stack.Pages.Data.Data[(unsigned __int64)v7 >> 5]->Values[v7 & 0x1F];
    v5 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v2->Env);
  }
  if ( v2->NArgs >= 2 )
  {
    v9 = v2->Env;
    v10 = (unsigned int)(v2->FirstArgBottomIndex - 1);
    if ( (unsigned int)v10 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v4 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(v2->FirstArgBottomIndex) - 1) & 0x1F];
    LODWORD(v4) = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v9);
  }
  v11 = v6->pUserEventHandler.pObject;
  if ( v11 )
  {
    v13 = 0;
    v12 = 23;
    v14 = v5;
    v15 = (signed int)v4;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v11->vfptr[1].__vecDelDtor)(
      v11,
      v6,
      &v12);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      v2->Env,
      "No user event handler interface is installed; Mouse.setCursorType failed.");
  }
}

// File Line: 546
// RVA: 0x6F6DE0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // r9
  signed int v4; // er8
  unsigned int v5; // ebx
  bool v6; // bp
  Scaleform::GFx::MovieImpl *v7; // rsi
  unsigned __int64 v8; // r11
  Scaleform::GFx::AS2::Value *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::AS2::Environment *v11; // rdx
  signed __int64 v12; // r9
  unsigned __int64 v13; // r8
  Scaleform::GFx::AS2::Value *v14; // rcx
  signed __int64 v15; // rax
  signed __int64 v16; // r8
  unsigned int v17; // er11
  Scaleform::GFx::AS2::Value *v18; // r8
  Scaleform::GFx::AS2::Environment *v19; // rdx
  unsigned __int64 v20; // r8
  Scaleform::GFx::AS2::Value *v21; // r9
  long double v22; // xmm0_8
  Scaleform::GFx::AS2::Environment *v23; // rdx
  unsigned __int64 v24; // r8
  float v25; // xmm7_4
  Scaleform::GFx::AS2::Value *v26; // r9
  double v27; // xmm0_8
  Scaleform::GFx::DisplayObjectBase *v28; // rcx
  float v29; // xmm3_4
  float v30; // xmm1_4
  Scaleform::GFx::InteractiveObject *v31; // rax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-48h]
  Scaleform::Render::Point<float> mousePos; // [rsp+80h] [rbp+8h]

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->Env;
  v4 = v2->NArgs;
  v5 = 0;
  v6 = 1;
  v7 = v3->Target->pASRoot->pMovieImpl;
  if ( v4 < 1 )
    goto LABEL_12;
  v8 = (unsigned int)v2->FirstArgBottomIndex;
  v9 = 0i64;
  if ( (unsigned int)v8 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v9 = &v3->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)v8 >> 5]->Values[v8 & 0x1F];
  if ( v9->T.Type == 2 )
  {
    v10 = 0i64;
    if ( (unsigned int)v8 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v10 = &v3->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToBool(v10, v2->Env);
    if ( v2->NArgs < 2 )
      goto LABEL_12;
    v11 = v2->Env;
    v12 = 0i64;
    v13 = (unsigned int)(v2->FirstArgBottomIndex - 1);
    if ( (unsigned int)v13 <= 32 * (LODWORD(v11->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
      v12 = (signed __int64)&v11->Stack.Pages.Data.Data[v13 >> 5]->Values[(LOBYTE(v2->FirstArgBottomIndex) - 1) & 0x1F];
    v14 = (Scaleform::GFx::AS2::Value *)v12;
    goto LABEL_11;
  }
  if ( v4 == 1 )
  {
    v16 = 0i64;
    if ( (unsigned int)v8 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v16 = (signed __int64)&v3->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v11 = v2->Env;
    v14 = (Scaleform::GFx::AS2::Value *)v16;
LABEL_11:
    v5 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v14, v11);
LABEL_12:
    if ( v5 >= ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))v7->vfptr[44].__vecDelDtor)(v7) )
      return;
    if ( v5 < 6 )
      v15 = (signed __int64)&v7->mMouseState[v5];
    else
      v15 = 0i64;
    v30 = *(float *)(v15 + 60);
    mousePos.x = *(float *)(v15 + 56);
    mousePos.y = v30;
    goto LABEL_32;
  }
  if ( v4 < 2 )
    goto LABEL_12;
  if ( v4 >= 3 )
  {
    v17 = v8 - 2;
    v18 = 0i64;
    if ( v17 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
              + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v18 = &v3->Stack.Pages.Data.Data[(unsigned __int64)v17 >> 5]->Values[v17 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToBool(v18, v2->Env);
  }
  v19 = v2->Env;
  v20 = (unsigned int)v2->FirstArgBottomIndex;
  v21 = 0i64;
  if ( (unsigned int)v20 <= 32 * (LODWORD(v19->Stack.Pages.Data.Size) - 1)
                          + (unsigned int)((_QWORD)((char *)v19->Stack.pCurrent - (char *)v19->Stack.pPageStart) >> 5) )
    v21 = &v19->Stack.Pages.Data.Data[v20 >> 5]->Values[v2->FirstArgBottomIndex & 0x1F];
  v22 = Scaleform::GFx::AS2::Value::ToNumber(v21, v19);
  v23 = v2->Env;
  v24 = (unsigned int)(v2->FirstArgBottomIndex - 1);
  v25 = v22 * 20.0;
  v26 = 0i64;
  if ( (unsigned int)v24 <= 32 * (LODWORD(v23->Stack.Pages.Data.Size) - 1)
                          + (unsigned int)((_QWORD)((char *)v23->Stack.pCurrent - (char *)v23->Stack.pPageStart) >> 5) )
    v26 = &v23->Stack.Pages.Data.Data[v24 >> 5]->Values[(LOBYTE(v2->FirstArgBottomIndex) - 1) & 0x1F];
  v27 = Scaleform::GFx::AS2::Value::ToNumber(v26, v23);
  v28 = (Scaleform::GFx::DisplayObjectBase *)&v7->pMainMovie->vfptr;
  if ( v28 )
  {
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v28, &pmat);
    v29 = v27 * 20.0;
    mousePos.x = (float)((float)(pmat.M[0][1] * v29) + (float)(pmat.M[0][0] * v25)) + pmat.M[0][3];
    mousePos.y = (float)((float)(pmat.M[1][1] * v29) + (float)(pmat.M[1][0] * v25)) + pmat.M[1][3];
LABEL_32:
    v31 = Scaleform::GFx::MovieImpl::GetTopMostEntity(v7, &mousePos, v5, v6, 0i64);
    if ( v31 )
      Scaleform::GFx::AS2::Value::SetAsCharacter(v2->Result, v31);
  }
}

// File Line: 618
// RVA: 0x6F4800
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetPosition(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // r9
  Scaleform::GFx::MovieImpl *v4; // r14
  Scaleform::GFx::AS2::PointObject *v5; // rbx
  unsigned int v6; // edi
  unsigned int v7; // edx
  Scaleform::GFx::AS2::Value *v8; // r10
  signed __int64 v9; // rcx
  signed __int64 v10; // rax
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  Scaleform::GFx::AS2::PointObject *v13; // rax
  Scaleform::GFx::AS2::PointObject *v14; // rax
  __m128d v15; // xmm1
  __int64 v16; // rcx
  double v17; // xmm1_8
  __m128d v18; // xmm0
  __int64 v19; // rcx
  unsigned int v20; // eax
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-50h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  v3 = v1->Env;
  v4 = v3->Target->pASRoot->pMovieImpl;
  v5 = 0i64;
  v6 = 0;
  if ( v1->NArgs > 0 )
  {
    v7 = v1->FirstArgBottomIndex;
    v8 = 0i64;
    if ( v7 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v8 = &v3->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v6 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v1->Env);
  }
  if ( v6 < ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))v4->vfptr[44].__vecDelDtor)(v4) )
  {
    if ( v6 < 6 )
    {
      v9 = v6;
      v10 = (signed __int64)&v4->mMouseState[v9];
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (__m128)*(unsigned int *)(v10 + 60);
    v12 = (__m128)*(unsigned int *)(v10 + 56);
    v13 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(signed __int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                v9 * 80,
                                                96i64);
    if ( v13 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v13, v1->Env);
      v5 = v14;
    }
    v15 = _mm_cvtps_pd(v11);
    v15.m128d_f64[0] = v15.m128d_f64[0] + 0.5;
    v16 = (unsigned int)(signed int)v15.m128d_f64[0];
    if ( v16 != 0x8000000000000000i64 && (double)(signed int)v16 != v15.m128d_f64[0] )
      v15.m128d_f64[0] = (double)(signed int)(v16 - (_mm_movemask_pd(_mm_unpckl_pd(v15, v15)) & 1));
    v17 = v15.m128d_f64[0] * 0.05;
    v18 = _mm_cvtps_pd(v12);
    v18.m128d_f64[0] = v18.m128d_f64[0] + 0.5;
    v19 = (unsigned int)(signed int)v18.m128d_f64[0];
    if ( v19 != 0x8000000000000000i64 && (double)(signed int)v19 != v18.m128d_f64[0] )
      v18.m128d_f64[0] = (double)(signed int)(v19 - (_mm_movemask_pd(_mm_unpckl_pd(v18, v18)) & 1));
    pt.x = v18.m128d_f64[0] * 0.05;
    pt.y = v17;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, v1->Env, &pt);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
    if ( v5 )
    {
      v20 = v5->RefCount;
      if ( v20 & 0x3FFFFFF )
      {
        v5->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
      }
    }
  }
}

// File Line: 648
// RVA: 0x6EE960
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // r10
  signed __int64 v4; // rsi
  unsigned int v5; // ebx
  Scaleform::GFx::MovieImpl *v6; // r14
  unsigned int v7; // edx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Value *v9; // rbx
  signed int v10; // esi

  v1 = fn->Result;
  v2 = fn;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 0;
  v3 = v2->Env;
  v4 = 0i64;
  v5 = 0;
  v6 = v3->Target->pASRoot->pMovieImpl;
  if ( v2->NArgs > 0 )
  {
    v7 = v2->FirstArgBottomIndex;
    v8 = 0i64;
    if ( v7 <= 32 * (LODWORD(v3->Stack.Pages.Data.Size) - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v8 = &v3->Stack.Pages.Data.Data[(unsigned __int64)v7 >> 5]->Values[v7 & 0x1F];
    v5 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v2->Env);
  }
  if ( v5 < ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))v6->vfptr[44].__vecDelDtor)(v6) )
  {
    if ( v5 < 6 )
      v4 = (signed __int64)&v6->mMouseState[v5];
    v9 = v2->Result;
    v10 = *(_DWORD *)(v4 + 48);
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2->Result);
    v9->T.Type = 3;
    v9->NV.NumberValue = (double)v10;
  }
}

// File Line: 663
// RVA: 0x717910
bool __fastcall Scaleform::GFx::AS2::MouseCtorFunction::SetMember(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // rbp
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::AS2::MouseCtorFunction *v8; // rsi
  Scaleform::GFx::AS2::GlobalContext *v9; // r11
  Scaleform::GFx::ASMovieRootBase *v10; // r10
  Scaleform::GFx::AS2::FunctionRef *v11; // rax
  char v12; // al
  Scaleform::GFx::AS2::FunctionObject *v13; // rcx
  unsigned int v14; // edx
  Scaleform::GFx::AS2::LocalFrame *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::MovieImpl *v17; // rbx
  bool v18; // bl
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-30h]

  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  v9 = penv->StringContext.pContext;
  v10 = v9->pMovieRoot->pASMovieRoot.pObject;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)v10[35].vfptr )
  {
    if ( v9->GFxExtensions.Value == 1 )
    {
      v11 = Scaleform::GFx::AS2::Value::ToFunction(val, &result, penv);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v8->vfptr,
        (Scaleform::GFx::AS2::FunctionRefBase *)&v11->Function);
      v12 = result.Flags;
      if ( !(result.Flags & 2) )
      {
        v13 = result.Function;
        if ( result.Function )
        {
          v14 = result.Function->RefCount;
          if ( v14 & 0x3FFFFFF )
          {
            result.Function->RefCount = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
            v12 = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( !(v12 & 1) )
      {
        v15 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v16 = result.pLocalFrame->RefCount;
          if ( v16 & 0x3FFFFFF )
          {
            result.pLocalFrame->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
          }
        }
      }
      result.pLocalFrame = 0i64;
      v17 = v7->Target->pASRoot->pMovieImpl;
      if ( (unsigned __int8)Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(
                              (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)v8 - 32),
                              &v7->StringContext) )
        v17->Flags |= 0x1000u;
      else
        v17->Flags &= 0xFFFFEFFF;
    }
  }
  else if ( name->pNode == (Scaleform::GFx::ASStringNode *)v10[24].vfptr )
  {
    v18 = Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&this->vfptr, penv, name, val, flags);
    Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)v8 - 32),
      &v7->StringContext,
      v7);
    return v18;
  }
  return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
}

// File Line: 689
// RVA: 0x6F1FF0
char __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetMember(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // r12
  Scaleform::GFx::AS2::MouseCtorFunction *v6; // r15
  Scaleform::GFx::AS2::ASStringContext *v7; // r14
  Scaleform::GFx::AS2::GlobalContext *v8; // rdi
  Scaleform::GFx::ASStringNode **v9; // rdx
  Scaleform::GFx::ASStringNode *v10; // r9
  long double v12; // xmm1_8
  const char *v13; // rsi
  __int64 v14; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v15; // rax
  __int64 v16; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v17; // rax
  __int64 v18; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v19; // rax
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-20h]

  v4 = pval;
  v5 = name;
  v6 = this;
  v7 = &penv->StringContext;
  v8 = penv->StringContext.pContext;
  if ( v8->GFxExtensions.Value != 1 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v6->vfptr[3].~RefCountBaseGC<323>)(
             v6,
             v7,
             v5,
             v4,
             -2i64);
  v9 = (Scaleform::GFx::ASStringNode **)v8->pMovieRoot->pASMovieRoot.pObject;
  v10 = name->pNode;
  if ( name->pNode == v9[175] )
  {
    Scaleform::GFx::AS2::Value::SetAsFunction(v4, (Scaleform::GFx::AS2::FunctionRefBase *)&this->vfptr);
    return 1;
  }
  if ( v10 == v9[176] )
  {
    if ( v4->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->T.Type = 3;
    v4->V.pStringNode = (Scaleform::GFx::ASStringNode *)4607182418800017408i64;
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v6->vfptr[3].~RefCountBaseGC<323>)(
             v6,
             v7,
             v5,
             v4,
             -2i64);
  }
  if ( v10 == v9[177] )
    goto LABEL_36;
  if ( v10 == v9[178] )
  {
    v12 = DOUBLE_3_0;
LABEL_32:
    Scaleform::GFx::AS2::Value::SetNumber(v4, v12);
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v6->vfptr[3].~RefCountBaseGC<323>)(
             v6,
             v7,
             v5,
             v4,
             -2i64);
  }
  if ( v10 == v9[179] )
  {
    v12 = 0.0;
    goto LABEL_32;
  }
  if ( v10 == v9[180] )
  {
    v12 = DOUBLE_1_0;
    goto LABEL_32;
  }
  if ( v10 == v9[181] )
  {
LABEL_36:
    v12 = DOUBLE_2_0;
    goto LABEL_32;
  }
  v13 = v10->pData;
  if ( !strcmp(v10->pData, "getTopMostEntity") )
  {
    v.T.Type = 8;
    v15 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, signed __int64))v8->pHeap->vfptr->Alloc)(
                                                    v14,
                                                    104i64);
    if ( v15 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v15,
        v7,
        Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity);
    v.V.FunctionValue.Flags = 0;
    *(_OWORD *)&v.NV.Int32Value = (unsigned __int64)v15;
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
  }
  else if ( !strcmp(v13, "getPosition") )
  {
    v.T.Type = 8;
    v17 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, signed __int64))v8->pHeap->vfptr->Alloc)(
                                                    v16,
                                                    104i64);
    if ( v17 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v17,
        v7,
        Scaleform::GFx::AS2::MouseCtorFunction::GetPosition);
    v.V.FunctionValue.Flags = 0;
    *(_OWORD *)&v.NV.Int32Value = (unsigned __int64)v17;
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
  }
  else
  {
    if ( strcmp(v13, "getButtonsState") )
      return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v6->vfptr[3].~RefCountBaseGC<323>)(
               v6,
               v7,
               v5,
               v4,
               -2i64);
    v.T.Type = 8;
    v19 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, signed __int64))v8->pHeap->vfptr->Alloc)(
                                                    v18,
                                                    104i64);
    if ( v19 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v19,
        v7,
        Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState);
    v.V.FunctionValue.Flags = 0;
    *(_OWORD *)&v.NV.Int32Value = (unsigned __int64)v19;
    Scaleform::GFx::AS2::Value::operator=(v4, &v, (__int64)v8);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 742
// RVA: 0x6FB650
_BOOL8 __fastcall Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(Scaleform::GFx::AS2::MouseCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rbx
  Scaleform::GFx::AS2::MouseCtorFunction *v3; // rdi
  Scaleform::GFx::AS2::CFunctionObject *v4; // rax
  bool v5; // bl
  char v6; // al
  Scaleform::GFx::AS2::FunctionObject *v7; // rcx
  unsigned int v8; // edx
  Scaleform::GFx::AS2::LocalFrame *v9; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::Value v13; // [rsp+40h] [rbp-28h]

  v2 = psc;
  v3 = this;
  v13.T.Type = 8;
  v4 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, signed __int64))psc->pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 104i64);
  if ( v4 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(v4, v2, Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  v13.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v13.NV.Int32Value = (unsigned __int64)v4;
  v5 = v3->SetCursorTypeFunc.Function != Scaleform::GFx::AS2::Value::ToFunction(&v13, &result, 0i64)->Function;
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
  result.pLocalFrame = 0i64;
  if ( v13.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v13);
  return v5;
}

// File Line: 752
// RVA: 0x70DCC0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::MouseCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::MouseCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h]
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+38h]
  void *v16; // [rsp+B0h] [rbp+40h]
  Scaleform::MemoryHeap **v17; // [rsp+B8h] [rbp+48h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::MouseCtorFunction *)flags->vfptr->Alloc((Scaleform::MemoryHeap *)result, 168ui64, 0i64);
  v16 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::MouseCtorFunction::MouseCtorFunction(
      v4,
      &psc,
      (Scaleform::GFx::AS2::MovieRoot *)v2->pMovieRoot->pASMovieRoot.pObject);
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)&v4->vfptr;
  v3->pLocalFrame = 0i64;
  v16 = v2->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment> *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v16 + 80i64))(v5, 160i64, 0i64);
  v17 = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      v7,
      v3);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable';
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)&v6->vfptr,
      (Scaleform::GFx::AS2::Object *)&v6->vfptr,
      &psc,
      GAS_MouseFunctionTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v6 = 0i64;
  }
  v16 = v6;
  v17 = &flags;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  flags = (Scaleform::MemoryHeap *)v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Mouse,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  v8 = v2->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  v9 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v14.V.pStringNode = v9;
  if ( v9 )
  {
    ++v9->RefCount;
    v9->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  v10 = v3->pLocalFrame;
  if ( v10 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v14.NV.8,
      v10,
      v3->Flags & 1);
  LOBYTE(flags) = 0;
  v8->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[13].RefCount,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v6 )
  {
    v11 = v6->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v6->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v3;
}>::

