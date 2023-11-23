// File Line: 78
// RVA: 0x6CA6A0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::MouseCtorFunction(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::MovieRoot *proot)
{
  __int64 v6; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v7; // rax
  unsigned __int64 v8; // rax
  Scaleform::GFx::AS2::FunctionRef *v9; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+40h] [rbp-48h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::MouseListener::vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::MouseListener::vfptr = (Scaleform::GFx::AS2::MouseListenerVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable;
  this->pListenersArray.pObject = 0i64;
  this->SetCursorTypeFunc.Flags = 0;
  this->SetCursorTypeFunc.Function = 0i64;
  this->SetCursorTypeFunc.pLocalFrame = 0i64;
  proot->pASMouseListener = &this->Scaleform::GFx::AS2::MouseListener;
  if ( this != (Scaleform::GFx::AS2::MouseCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(psc, &this->Scaleform::GFx::AS2::ObjectInterface);
  Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(this, psc, 0i64);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::MouseCtorFunction::StaticFunctionTable,
    7);
  v16.T.Type = 8;
  v7 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))psc->pContext->pHeap->vfptr->Alloc)(
                                                 v6,
                                                 104i64);
  if ( v7 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
      v7,
      psc,
      Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  else
    v8 = 0i64;
  v16.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v16.NV.Int32Value = v8;
  v9 = Scaleform::GFx::AS2::Value::ToFunction(&v16, &result, 0i64);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->SetCursorTypeFunc, v9);
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
      v14 = result.pLocalFrame->RefCount;
      if ( (v14 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  result.pLocalFrame = 0i64;
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  this->LastClickTime = 0;
}

// File Line: 99
// RVA: 0x6BFB30
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::ArrayObject *pObject; // rbx

  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    &this->SetCursorTypeFunc,
    prcc);
  pObject = this->pListenersArray.pObject;
  if ( pObject )
  {
    if ( (--pObject->RefCount & 0x3FFFFFF) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pObject);
      pObject->RefCount |= 0x4000000u;
      if ( (pObject->RefCount & 0x8000000) == 0 )
      {
        pObject->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        pObject->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
        prcc->pLastPtr = pObject;
        pObject->RefCount |= 0x8000000u;
      }
    }
  }
  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
}

// File Line: 108
// RVA: 0x6E89C0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  int v3; // r8d

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
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx

  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pWatchpoints);
  }
}

// File Line: 119
// RVA: 0x7003D0
bool __fastcall Scaleform::GFx::AS2::MouseCtorFunction::IsEmpty(Scaleform::GFx::AS2::MouseCtorFunction *this)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // rdx

  pRCC = this->pRCC;
  return pRCC && LODWORD(pRCC[1].vfptr) == 0;
}

// File Line: 126
// RVA: 0x722FA0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::ArrayObject *v6; // rbx
  Scaleform::GFx::AS2::ArrayObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ArrayObject *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-30h] BYREF

  v11.T.Type = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         psc,
         &psc->pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v11,
         -2i64) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v11, penv);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5
      && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v5->Scaleform::GFx::AS2::ObjectInterface) == 7 )
    {
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
      pObject = this->pListenersArray.pObject;
      if ( pObject )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      this->pListenersArray.pObject = v6;
    }
    else
    {
      v9 = this->pListenersArray.pObject;
      if ( v9 )
      {
        v10 = v9->RefCount;
        if ( (v10 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      this->pListenersArray.pObject = 0i64;
    }
  }
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}

// File Line: 264
// RVA: 0x70ACA0
__int64 __fastcall Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        int eventName,
        Scaleform::GFx::AS2::Value *eventMethod,
        Scaleform::GFx::ASString *ptargetName,
        unsigned int button,
        int delta,
        bool dblClick)
{
  unsigned int v9; // r15d
  Scaleform::GFx::AS2::GlobalContext *pContext; // rax
  bool v12; // r12
  Scaleform::GFx::MouseState *v13; // rdi
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v18; // eax
  char v19; // al
  Scaleform::GFx::AS2::FunctionObject *v20; // rcx
  unsigned int v21; // edx
  Scaleform::GFx::AS2::LocalFrame *v22; // rcx
  unsigned int v23; // eax
  int v25; // ebx
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  __m128 x_low; // xmm9
  __m128d v28; // xmm6
  int v29; // ecx
  double v30; // xmm6_8
  Scaleform::GFx::AS2::Value *v31; // rax
  __m128d v32; // xmm6
  int v33; // ecx
  double v34; // xmm6_8
  Scaleform::GFx::AS2::Value *v35; // rax
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::GFx::AS2::Value *v37; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS2::Value *v39; // rax
  Scaleform::GFx::AS2::Value *v40; // rcx
  Scaleform::GFx::AS2::Value *v41; // rax
  Scaleform::GFx::AS2::Value *v42; // rax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-40h] BYREF

  v9 = mouseIndex;
  pContext = penv->StringContext.pContext;
  v12 = pContext->GFxExtensions.Value != 1;
  v13 = 0i64;
  if ( pContext->GFxExtensions.Value != 1 || !button || (unsigned int)(eventName - 103) > 1 )
    goto LABEL_26;
  Scaleform::GFx::AS2::Value::ToFunction(eventMethod, &result, penv);
  if ( result.Function )
  {
    if ( ((int (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *))result.Function->vfptr[5].Finalize_GC)(result.Function) > 0 )
      goto LABEL_8;
    if ( button <= 1 )
    {
      v12 = 1;
LABEL_8:
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
          v18 = result.pLocalFrame->RefCount;
          if ( (v18 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v18 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      result.pLocalFrame = 0i64;
LABEL_26:
      v25 = 0;
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 && !v12 )
      {
        if ( eventName == 103 )
        {
          if ( dblClick )
          {
            if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
            pCurrent = penv->Stack.pCurrent;
            if ( pCurrent )
            {
              pCurrent->T.Type = 2;
              pCurrent->V.BooleanValue = dblClick;
            }
            v25 = 1;
          }
          v9 = mouseIndex;
        }
        if ( v9 < 6 )
          v13 = &penv->Target->pASRoot->pMovieImpl->mMouseState[v9];
        x_low = (__m128)LODWORD(v13->LastPosition.x);
        v28 = _mm_cvtps_pd((__m128)LODWORD(v13->LastPosition.y));
        v28.m128d_f64[0] = v28.m128d_f64[0] + 0.5;
        v29 = (int)v28.m128d_f64[0];
        if ( (double)v29 != v28.m128d_f64[0] )
          v28.m128d_f64[0] = (double)(v29 - (_mm_movemask_pd(_mm_unpacklo_pd(v28, v28)) & 1));
        v30 = v28.m128d_f64[0] * 0.05;
        if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
        v31 = penv->Stack.pCurrent;
        if ( v31 )
        {
          v31->T.Type = 3;
          v31->NV.NumberValue = v30;
        }
        v32 = _mm_cvtps_pd(x_low);
        v32.m128d_f64[0] = v32.m128d_f64[0] + 0.5;
        v33 = (int)v32.m128d_f64[0];
        if ( (double)v33 != v32.m128d_f64[0] )
          v32.m128d_f64[0] = (double)(v33 - (_mm_movemask_pd(_mm_unpacklo_pd(v32, v32)) & 1));
        v34 = v32.m128d_f64[0] * 0.05;
        if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
        v35 = penv->Stack.pCurrent;
        if ( v35 )
        {
          v35->T.Type = 3;
          v35->NV.NumberValue = v34;
        }
        if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
        v36 = penv->Stack.pCurrent;
        if ( v36 )
        {
          v36->T.Type = 4;
          v36->NV.Int32Value = v9;
        }
        v25 += 3;
      }
      if ( eventName != 105 )
      {
        if ( ptargetName && (eventName == 106 || !v12) )
        {
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v37 = penv->Stack.pCurrent;
          if ( v37 )
          {
            v37->T.Type = 5;
            pNode = ptargetName->pNode;
            v37->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)ptargetName->pNode;
            ++pNode->RefCount;
          }
        }
        else
        {
          if ( v25 <= 0 )
            goto LABEL_72;
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v39 = penv->Stack.pCurrent;
          if ( v39 )
            v39->T.Type = 1;
        }
        ++v25;
      }
LABEL_72:
      if ( eventName >= 103 )
      {
        if ( eventName <= 104 )
        {
          if ( button && !v12 )
          {
            if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
            v41 = penv->Stack.pCurrent;
            if ( v41 )
            {
              v41->T.Type = 3;
              v41->NV.NumberValue = (double)(int)button;
            }
            goto LABEL_92;
          }
          if ( v25 > 0 )
          {
            if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
            v42 = penv->Stack.pCurrent;
            if ( v42 )
              v42->T.Type = 1;
            goto LABEL_92;
          }
        }
        else if ( eventName == 106 )
        {
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v40 = penv->Stack.pCurrent;
          if ( v40 )
          {
            v40->T.Type = 4;
            v40->NV.Int32Value = delta;
          }
LABEL_92:
          ++v25;
        }
      }
      return (unsigned int)v25;
    }
  }
  v19 = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    v20 = result.Function;
    if ( result.Function )
    {
      v21 = result.Function->RefCount;
      if ( (v21 & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
        v19 = result.Flags;
      }
    }
  }
  result.Function = 0i64;
  if ( (v19 & 1) == 0 )
  {
    v22 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v23 = result.pLocalFrame->RefCount;
      if ( (v23 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v23 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
      }
    }
  }
  result.pLocalFrame = 0i64;
  return 0xFFFFFFFFi64;
}

// File Line: 353
// RVA: 0x703750
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        int eventName,
        Scaleform::GFx::ASString *ptargetName,
        unsigned int button,
        int delta,
        bool dblClick)
{
  Scaleform::GFx::AS2::ObjectInterface *v9; // rdx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h] BYREF
  unsigned int v11; // [rsp+30h] [rbp-28h]
  int v12; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::ASString *v13; // [rsp+38h] [rbp-20h]
  unsigned int v14; // [rsp+40h] [rbp-18h]
  int v15; // [rsp+44h] [rbp-14h]
  bool v16; // [rsp+48h] [rbp-10h]

  pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable;
  v11 = mouseIndex;
  v12 = eventName;
  v13 = ptargetName;
  v14 = button;
  v15 = delta;
  v16 = dblClick;
  if ( this )
    v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v9 = 0i64;
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    penv,
    v9,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion
  + eventName,
    &pcallback);
}

// File Line: 428
// RVA: 0x706C60
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseMove(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex)
{
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdx
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-30h] BYREF
  unsigned int v7; // [rsp+30h] [rbp-28h]
  int v8; // [rsp+34h] [rbp-24h]
  __int64 v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  char v11; // [rsp+48h] [rbp-10h]

  pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable;
  v7 = mouseIndex;
  v8 = 105;
  v4 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0;
  p_pLocalFrame = &this[-1].ResolveHandler.pLocalFrame;
  if ( p_pLocalFrame )
    v4 = (Scaleform::GFx::AS2::ObjectInterface *)(p_pLocalFrame + 4);
  Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
    penv,
    v4,
    (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].AVMVersion,
    &pcallback);
}

// File Line: 433
// RVA: 0x7063C0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseDown(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        unsigned int button,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  __int64 v6; // r14
  char dblClick; // si
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdi
  unsigned __int64 v11; // r10
  Scaleform::GFx::MouseState *v12; // rax
  unsigned int v13; // ecx
  int v14; // edx
  Scaleform::GFx::CharacterHandle *pObject; // rax
  bool v16; // zf
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-40h] BYREF
  int v20; // [rsp+50h] [rbp-38h]
  int v21; // [rsp+54h] [rbp-34h]
  Scaleform::GFx::InteractiveObject **p_ptarget; // [rsp+58h] [rbp-30h]
  unsigned int v23; // [rsp+60h] [rbp-28h]
  int v24; // [rsp+64h] [rbp-24h]
  char v25; // [rsp+68h] [rbp-20h]

  v6 = mouseIndex;
  dblClick = 0;
  v10 = 0i64;
  if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    v11 = Scaleform::Timer::GetTicks() / 0x3E8;
    if ( (unsigned int)v6 < 6 )
      v12 = &penv->Target->pASRoot->pMovieImpl->mMouseState[v6];
    else
      v12 = 0i64;
    v13 = (int)(float)(v12->LastPosition.x * 0.050000001);
    v14 = (int)(float)(v12->LastPosition.y * 0.050000001);
    if ( (unsigned int)v11 <= this->RefCount + 300 && this->RootIndex == v13 )
      dblClick = HIDWORD(this->pPrev) == v14;
    this->RootIndex = v13;
    HIDWORD(this->pPrev) = v14;
    this->RefCount = v11;
  }
  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    ptarget = (Scaleform::GFx::InteractiveObject *)pObject->NamePath.pNode;
    ++LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr);
    v16 = this == (Scaleform::GFx::AS2::MouseCtorFunction *)104;
    p_pLocalFrame = &this[-1].ResolveHandler.pLocalFrame;
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable;
    v20 = v6;
    v21 = 103;
    p_ptarget = &ptarget;
    v23 = button;
    v24 = 0;
    v25 = dblClick;
    if ( !v16 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(p_pLocalFrame + 4);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v10,
      (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].pMovieImpl,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    v18 = (Scaleform::GFx::ASStringNode *)ptarget;
    v16 = LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr)-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 104),
      penv,
      v6,
      103,
      0i64,
      button,
      0,
      dblClick);
  }
}

// File Line: 466
// RVA: 0x706CE0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseUp(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        unsigned int button,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-30h] BYREF
  unsigned int v14; // [rsp+50h] [rbp-28h]
  int v15; // [rsp+54h] [rbp-24h]
  Scaleform::GFx::InteractiveObject **p_ptarget; // [rsp+58h] [rbp-20h]
  unsigned int v17; // [rsp+60h] [rbp-18h]
  int v18; // [rsp+64h] [rbp-14h]
  char v19; // [rsp+68h] [rbp-10h]

  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    ptarget = (Scaleform::GFx::InteractiveObject *)pObject->NamePath.pNode;
    ++LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable;
    v14 = mouseIndex;
    v15 = 104;
    p_ptarget = &ptarget;
    v17 = button;
    v10 = 0i64;
    v18 = 0;
    v19 = 0;
    if ( this != (Scaleform::GFx::AS2::MouseCtorFunction *)104 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(&this[-1].ResolveHandler.pLocalFrame + 4);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v10,
      (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[28].pASSupport,
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    v11 = (Scaleform::GFx::ASStringNode *)ptarget;
    if ( LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr)-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 104),
      penv,
      mouseIndex,
      104,
      0i64,
      button,
      0,
      0);
  }
}

// File Line: 477
// RVA: 0x706E00
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseWheel(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        int sdelta,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::AS2::ObjectInterface *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+48h] [rbp-30h] BYREF
  unsigned int v14; // [rsp+50h] [rbp-28h]
  int v15; // [rsp+54h] [rbp-24h]
  Scaleform::GFx::InteractiveObject **p_ptarget; // [rsp+58h] [rbp-20h]
  int v17; // [rsp+60h] [rbp-18h]
  int v18; // [rsp+64h] [rbp-14h]
  char v19; // [rsp+68h] [rbp-10h]

  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    ptarget = (Scaleform::GFx::InteractiveObject *)pObject->NamePath.pNode;
    ++LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::`vftable;
    v14 = mouseIndex;
    v15 = 106;
    p_ptarget = &ptarget;
    v10 = 0i64;
    v17 = 0;
    v18 = sdelta;
    v19 = 0;
    if ( this != (Scaleform::GFx::AS2::MouseCtorFunction *)104 )
      v10 = (Scaleform::GFx::AS2::ObjectInterface *)(&this[-1].ResolveHandler.pLocalFrame + 4);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v10,
      (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[29],
      &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
    v11 = (Scaleform::GFx::ASStringNode *)ptarget;
    if ( LODWORD(ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr)-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 104),
      penv,
      mouseIndex,
      106,
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
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  unsigned int v5; // eax
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::UserEventHandler *pObject; // rcx
  int v9; // [rsp+20h] [rbp-18h] BYREF
  char v10; // [rsp+24h] [rbp-14h]
  int v11; // [rsp+28h] [rbp-10h]
  unsigned int v12; // [rsp+2Ch] [rbp-Ch]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( pMovieImpl->pUserEventHandler.pObject )
  {
    v5 = 0;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToUInt32(v7, fn->Env);
    }
    pObject = pMovieImpl->pUserEventHandler.pObject;
    v10 = 0;
    v9 = 21;
    v11 = 0;
    v12 = v5;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      pMovieImpl,
      &v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      fn->Env,
      "No user event handler interface is installed; Mouse.show failed.");
  }
}

// File Line: 503
// RVA: 0x6B5A80
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::Hide(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  unsigned int v5; // eax
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Value *v7; // r10
  Scaleform::GFx::UserEventHandler *pObject; // rcx
  int v9; // [rsp+20h] [rbp-18h] BYREF
  char v10; // [rsp+24h] [rbp-14h]
  int v11; // [rsp+28h] [rbp-10h]
  unsigned int v12; // [rsp+2Ch] [rbp-Ch]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( pMovieImpl->pUserEventHandler.pObject )
  {
    v5 = 0;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToUInt32(v7, fn->Env);
    }
    pObject = pMovieImpl->pUserEventHandler.pObject;
    v10 = 0;
    v9 = 22;
    v11 = 0;
    v12 = v5;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      pMovieImpl,
      &v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      fn->Env,
      "No user event handler interface is installed; Mouse.hide failed.");
  }
}

// File Line: 518
// RVA: 0x713610
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r10
  Scaleform::GFx::AS2::Value *v4; // rbx
  int v5; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Environment *v9; // rdx
  unsigned __int64 v10; // r8
  Scaleform::GFx::UserEventHandler *pObject; // rcx
  int v12; // [rsp+20h] [rbp-18h] BYREF
  char v13; // [rsp+24h] [rbp-14h]
  int v14; // [rsp+28h] [rbp-10h]
  int v15; // [rsp+2Ch] [rbp-Ch]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  v4 = 0i64;
  v5 = 0;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, fn->Env);
  }
  if ( fn->NArgs >= 2 )
  {
    v9 = fn->Env;
    v10 = (unsigned int)(fn->FirstArgBottomIndex - 1);
    if ( (unsigned int)v10 <= 32 * (LODWORD(v9->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
      v4 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
    LODWORD(v4) = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, v9);
  }
  pObject = pMovieImpl->pUserEventHandler.pObject;
  if ( pObject )
  {
    v13 = 0;
    v12 = 23;
    v14 = v5;
    v15 = (int)v4;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      pMovieImpl,
      &v12);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      fn->Env,
      "No user event handler interface is installed; Mouse.setCursorType failed.");
  }
}

// File Line: 546
// RVA: 0x6F6DE0
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r9
  int NArgs; // r8d
  unsigned int v5; // ebx
  bool v6; // bp
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  unsigned __int64 FirstArgBottomIndex; // r11
  Scaleform::GFx::AS2::Value *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::AS2::Environment *v11; // rdx
  __int64 v12; // r9
  unsigned __int64 v13; // r8
  Scaleform::GFx::AS2::Value *v14; // rcx
  __int64 v15; // rax
  __int64 v16; // r8
  unsigned int v17; // r11d
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
  Scaleform::GFx::DisplayObjectBase *pMainMovie; // rcx
  float v29; // xmm3_4
  float v30; // xmm1_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::Render::Point<float> mousePos; // [rsp+80h] [rbp+8h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  NArgs = fn->NArgs;
  v5 = 0;
  v6 = 1;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( NArgs < 1 )
    goto LABEL_12;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v9 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v9 = &Env->Stack.Pages.Data.Data[(unsigned __int64)(unsigned int)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  if ( v9->T.Type == 2 )
  {
    v10 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v10 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToBool(v10, fn->Env);
    if ( fn->NArgs < 2 )
      goto LABEL_12;
    v11 = fn->Env;
    v12 = 0i64;
    v13 = (unsigned int)(fn->FirstArgBottomIndex - 1);
    if ( (unsigned int)v13 <= 32 * (LODWORD(v11->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v11->Stack.pCurrent - v11->Stack.pPageStart) )
      v12 = (__int64)&v11->Stack.Pages.Data.Data[v13 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
    v14 = (Scaleform::GFx::AS2::Value *)v12;
    goto LABEL_11;
  }
  if ( NArgs == 1 )
  {
    v16 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v16 = (__int64)&Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v11 = fn->Env;
    v14 = (Scaleform::GFx::AS2::Value *)v16;
LABEL_11:
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v14, v11);
LABEL_12:
    if ( v5 >= ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[44].__vecDelDtor)(pMovieImpl) )
      return;
    if ( v5 < 6 )
      v15 = (__int64)&pMovieImpl->mMouseState[v5];
    else
      v15 = 0i64;
    v30 = *(float *)(v15 + 60);
    mousePos.x = *(float *)(v15 + 56);
    mousePos.y = v30;
    goto LABEL_31;
  }
  if ( NArgs >= 3 )
  {
    v17 = FirstArgBottomIndex - 2;
    v18 = 0i64;
    if ( v17 <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v18 = &Env->Stack.Pages.Data.Data[(unsigned __int64)v17 >> 5]->Values[v17 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToBool(v18, fn->Env);
  }
  v19 = fn->Env;
  v20 = (unsigned int)fn->FirstArgBottomIndex;
  v21 = 0i64;
  if ( (unsigned int)v20 <= 32 * (LODWORD(v19->Stack.Pages.Data.Size) - 1)
                          + (unsigned int)(v19->Stack.pCurrent - v19->Stack.pPageStart) )
    v21 = &v19->Stack.Pages.Data.Data[v20 >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v22 = Scaleform::GFx::AS2::Value::ToNumber(v21, v19);
  v23 = fn->Env;
  v24 = (unsigned int)(fn->FirstArgBottomIndex - 1);
  v25 = v22 * 20.0;
  v26 = 0i64;
  if ( (unsigned int)v24 <= 32 * (LODWORD(v23->Stack.Pages.Data.Size) - 1)
                          + (unsigned int)(v23->Stack.pCurrent - v23->Stack.pPageStart) )
    v26 = &v23->Stack.Pages.Data.Data[v24 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
  v27 = Scaleform::GFx::AS2::Value::ToNumber(v26, v23);
  pMainMovie = pMovieImpl->pMainMovie;
  if ( pMainMovie )
  {
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
    v29 = v27 * 20.0;
    mousePos.x = (float)((float)(pmat.M[0][1] * v29) + (float)(pmat.M[0][0] * v25)) + pmat.M[0][3];
    mousePos.y = (float)((float)(pmat.M[1][1] * v29) + (float)(pmat.M[1][0] * v25)) + pmat.M[1][3];
LABEL_31:
    TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(pMovieImpl, &mousePos, v5, v6, 0i64);
    if ( TopMostEntity )
      Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, TopMostEntity);
  }
}

// File Line: 618
// RVA: 0x6F4800
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetPosition(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  Scaleform::GFx::AS2::PointObject *v5; // rbx
  unsigned int v6; // edi
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Value *v8; // r10
  __int64 v9; // rcx
  __int64 v10; // rax
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  Scaleform::GFx::AS2::PointObject *v13; // rax
  Scaleform::GFx::AS2::PointObject *v14; // rax
  __m128d v15; // xmm1
  int v16; // ecx
  double v17; // xmm1_8
  __m128d v18; // xmm0
  int v19; // ecx
  unsigned int RefCount; // eax
  Scaleform::Render::Point<double> pt; // [rsp+28h] [rbp-50h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v5 = 0i64;
  v6 = 0;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, fn->Env);
  }
  if ( v6 < ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[44].__vecDelDtor)(pMovieImpl) )
  {
    if ( v6 < 6 )
    {
      v9 = v6;
      v10 = (__int64)&pMovieImpl->mMouseState[v9];
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (__m128)*(unsigned int *)(v10 + 60);
    v12 = (__m128)*(unsigned int *)(v10 + 56);
    v13 = (Scaleform::GFx::AS2::PointObject *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                v9 * 80,
                                                96i64);
    if ( v13 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v13, (Scaleform::GFx::AS2::ASStringContext *)fn->Env);
      v5 = v14;
    }
    v15 = _mm_cvtps_pd(v11);
    v15.m128d_f64[0] = v15.m128d_f64[0] + 0.5;
    v16 = (int)v15.m128d_f64[0];
    if ( (double)v16 != v15.m128d_f64[0] )
      v15.m128d_f64[0] = (double)(v16 - (_mm_movemask_pd(_mm_unpacklo_pd(v15, v15)) & 1));
    v17 = v15.m128d_f64[0] * 0.05;
    v18 = _mm_cvtps_pd(v12);
    v18.m128d_f64[0] = v18.m128d_f64[0] + 0.5;
    v19 = (int)v18.m128d_f64[0];
    if ( (double)v19 != v18.m128d_f64[0] )
      v18.m128d_f64[0] = (double)(v19 - (_mm_movemask_pd(_mm_unpacklo_pd(v18, v18)) & 1));
    pt.x = v18.m128d_f64[0] * 0.05;
    pt.y = v17;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, fn->Env, &pt);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
    if ( v5 )
    {
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
  }
}

// File Line: 648
// RVA: 0x6EE960
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::AS2::Environment *Env; // r10
  __int64 v4; // rsi
  unsigned int v5; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  unsigned int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Value *v8; // r9
  Scaleform::GFx::AS2::Value *v9; // rbx
  int v10; // esi

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  v4 = 0i64;
  v5 = 0;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( fn->NArgs > 0 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v8 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, fn->Env);
  }
  if ( v5 < ((unsigned int (__fastcall *)(Scaleform::GFx::MovieImpl *))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[44].__vecDelDtor)(pMovieImpl) )
  {
    if ( v5 < 6 )
      v4 = (__int64)&pMovieImpl->mMouseState[v5];
    v9 = fn->Result;
    v10 = *(_DWORD *)(v4 + 48);
    if ( v9->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v9->T.Type = 3;
    v9->NV.NumberValue = (double)v10;
  }
}

// File Line: 663
// RVA: 0x717910
bool __fastcall Scaleform::GFx::AS2::MouseCtorFunction::SetMember(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // r11
  Scaleform::GFx::ASMovieRootBase *pObject; // r10
  Scaleform::GFx::AS2::FunctionRef *v11; // rax
  char v12; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  bool v18; // bl
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-30h] BYREF

  pContext = penv->StringContext.pContext;
  pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[35].vfptr )
  {
    if ( pContext->GFxExtensions.Value == 1 )
    {
      v11 = Scaleform::GFx::AS2::Value::ToFunction(val, &result, penv);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::MouseListener,
        v11);
      v12 = result.Flags;
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
            v12 = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( (v12 & 1) == 0 )
      {
        pLocalFrame = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v16 = result.pLocalFrame->RefCount;
          if ( (v16 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      result.pLocalFrame = 0i64;
      pMovieImpl = penv->Target->pASRoot->pMovieImpl;
      if ( Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(
             (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 32),
             &penv->StringContext) )
      {
        pMovieImpl->Flags |= 0x1000u;
      }
      else
      {
        pMovieImpl->Flags &= ~0x1000u;
      }
    }
  }
  else if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[24].vfptr )
  {
    v18 = Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
    Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 32),
      &penv->StringContext,
      penv);
    return v18;
  }
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}

// File Line: 689
// RVA: 0x6F1FF0
char __fastcall Scaleform::GFx::AS2::MouseCtorFunction::GetMember(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r14
  Scaleform::GFx::AS2::GlobalContext *pContext; // rdi
  Scaleform::GFx::ASStringNode **pObject; // rdx
  Scaleform::GFx::ASStringNode *pNode; // r9
  long double v12; // xmm1_8
  const char *pData; // rsi
  __int64 v14; // rcx
  Scaleform::GFx::AS2::CFunctionObject *v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-20h] BYREF

  p_StringContext = &penv->StringContext;
  pContext = penv->StringContext.pContext;
  if ( pContext->GFxExtensions.Value != 1 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             pval,
             -2i64);
  pObject = (Scaleform::GFx::ASStringNode **)pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( name->pNode == pObject[175] )
  {
    Scaleform::GFx::AS2::Value::SetAsFunction(
      pval,
      (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::MouseListener);
    return 1;
  }
  if ( pNode == pObject[176] )
  {
    if ( pval->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pval);
    pval->T.Type = 3;
    pval->V.pStringNode = (Scaleform::GFx::ASStringNode *)0x3FF0000000000000i64;
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             pval,
             -2i64);
  }
  if ( pNode == pObject[177] )
    goto LABEL_16;
  if ( pNode == pObject[178] )
  {
    v12 = DOUBLE_3_0;
LABEL_31:
    Scaleform::GFx::AS2::Value::SetNumber(pval, v12);
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             pval,
             -2i64);
  }
  if ( pNode == pObject[179] )
  {
    v12 = 0.0;
    goto LABEL_31;
  }
  if ( pNode == pObject[180] )
  {
    v12 = DOUBLE_1_0;
    goto LABEL_31;
  }
  if ( pNode == pObject[181] )
  {
LABEL_16:
    v12 = DOUBLE_2_0;
    goto LABEL_31;
  }
  pData = pNode->pData;
  if ( !strcmp(pNode->pData, "getTopMostEntity") )
  {
    v.T.Type = 8;
    v15 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))pContext->pHeap->vfptr->Alloc)(
                                                    v14,
                                                    104i64);
    if ( v15 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v15,
        p_StringContext,
        Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity);
  }
  else if ( !strcmp(pData, "getPosition") )
  {
    v.T.Type = 8;
    v15 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))pContext->pHeap->vfptr->Alloc)(
                                                    v16,
                                                    104i64);
    if ( v15 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v15,
        p_StringContext,
        Scaleform::GFx::AS2::MouseCtorFunction::GetPosition);
  }
  else
  {
    if ( strcmp(pData, "getButtonsState") )
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
               this,
               p_StringContext,
               name,
               pval,
               -2i64);
    v.T.Type = 8;
    v15 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))pContext->pHeap->vfptr->Alloc)(
                                                    v17,
                                                    104i64);
    if ( v15 )
      Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
        v15,
        p_StringContext,
        Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState);
  }
  v.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v.NV.Int32Value = (unsigned __int64)v15;
  Scaleform::GFx::AS2::Value::operator=(pval, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}

// File Line: 742
// RVA: 0x6FB650
_BOOL8 __fastcall Scaleform::GFx::AS2::MouseCtorFunction::HasOverloadedCursorTypeFunction(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::CFunctionObject *v4; // rax
  bool v5; // bl
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v10; // edx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v13; // [rsp+40h] [rbp-28h] BYREF

  v13.T.Type = 8;
  v4 = (Scaleform::GFx::AS2::CFunctionObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MouseCtorFunction *, __int64))psc->pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 104i64);
  if ( v4 )
    Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
      v4,
      psc,
      Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  v13.V.FunctionValue.Flags = 0;
  *(_OWORD *)&v13.NV.Int32Value = (unsigned __int64)v4;
  v5 = this->SetCursorTypeFunc.Function != Scaleform::GFx::AS2::Value::ToFunction(&v13, &result, 0i64)->Function;
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
  result.pLocalFrame = 0i64;
  if ( v13.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v13);
  return v5;
}

// File Line: 752
// RVA: 0x70DCC0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::MouseCtorFunction::Register(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::MouseCtorFunction *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *pObject; // r14
  Scaleform::GFx::ASStringNode *vfptr; // rax
  Scaleform::GFx::AS2::LocalFrame *pPrev; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+A8h] [rbp+38h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+B0h] [rbp+40h]
  Scaleform::MemoryHeap **p_flags; // [rsp+B8h] [rbp+48h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::MouseCtorFunction *)flags->vfptr->Alloc(result, 168ui64, 0i64);
  pHeap = (Scaleform::MemoryHeap *)v4;
  if ( v4 )
    Scaleform::GFx::AS2::MouseCtorFunction::MouseCtorFunction(
      v4,
      &psc,
      (Scaleform::GFx::AS2::MovieRoot *)pgc->pMovieRoot->pASMovieRoot.pObject);
  LOBYTE(result->pNext) = 0;
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v4;
  result->pPrev = 0i64;
  pHeap = pgc->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment> *)pHeap->vfptr->Alloc(v5, 160ui64, 0i64);
  p_flags = (Scaleform::MemoryHeap **)v6;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::MouseObject,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      Prototype,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    v6->Scaleform::GFx::AS2::MouseObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::MouseObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MouseProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v6->Scaleform::GFx::AS2::GASPrototypeBase,
      v6,
      &psc,
      GAS_MouseFunctionTable,
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
    ASBuiltin_Mouse,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&flags);
  pObject = pgc->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  vfptr = (Scaleform::GFx::ASStringNode *)result->vfptr;
  v14.V.pStringNode = vfptr;
  if ( vfptr )
  {
    ++vfptr->RefCount;
    vfptr->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  pPrev = (Scaleform::GFx::AS2::LocalFrame *)result->pPrev;
  if ( pPrev )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v14.V.FunctionValue, pPrev, (__int64)result->pNext & 1);
  LOBYTE(flags) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[13].RefCount,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&flags);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
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

