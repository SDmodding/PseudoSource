// File Line: 64
// RVA: 0x6E9F90
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::Finalize_GC(Scaleform::GFx::AS2::UserDefinedFunctionObject *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rcx

  v1 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this;
  v2 = (Scaleform::Render::RenderBuffer *)this->pContext.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1[12].pTable = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v1 + 6);
  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v1[10].pTable;
  if ( v3 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[10].pTable);
  }
}

// File Line: 72
// RVA: 0x6CD480
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(Scaleform::GFx::AS2::UserDefinedFunctionObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::FunctionHandler *pcontext, void *puserData)
{
  void *v4; // rbp
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax

  v4 = puserData;
  v5 = (Scaleform::GFx::Resource *)pcontext;
  v6 = psc;
  v7 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v7->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v7->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  v7->pContext.pObject = (Scaleform::GFx::FunctionHandler *)v5;
  v7->pUserData = v4;
  v8 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v6->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v7->vfptr, v6, v8);
}

// File Line: 101
// RVA: 0x6FEF90
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::Invoke(Scaleform::GFx::AS2::UserDefinedFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn, Scaleform::GFx::AS2::LocalFrame *__formal, const char *a4)
{
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v5; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rcx
  int v8; // er9
  int v9; // er8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::FnCall fna; // [rsp+30h] [rbp-48h]

  v4 = fn;
  v5 = this;
  if ( this->pContext.pObject )
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
      fna.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      fna.Result = v11;
      fna.ThisPtr = v7;
      fna.ThisFunctionRef.Flags = 0;
      fna.ThisFunctionRef.Function = 0i64;
      fna.ThisFunctionRef.pLocalFrame = 0i64;
      fna.Env = v10;
      fna.NArgs = v9;
      fna.FirstArgBottomIndex = v8;
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(v5, &fna);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&v6[-2]);
      Scaleform::GFx::AS2::FnCall::~FnCall(&fna);
    }
    else
    {
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(v5, v4);
    }
  }
}

// File Line: 117
// RVA: 0x6FF7E0
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(Scaleform::GFx::AS2::UserDefinedFunctionObject *this, Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v3; // r15
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdx
  char v6; // r14
  Scaleform::GFx::Value *v7; // rdx
  int i; // ebx
  unsigned int v9; // edx
  Scaleform::GFx::AS2::Environment *v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r10
  Scaleform::GFx::Value *v12; // rdx
  unsigned __int64 v13; // rdi
  Scaleform::GFx::Value *v14; // rdx
  Scaleform::GFx::Value *v15; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-B8h]
  Scaleform::GFx::Value pdestVal; // [rsp+38h] [rbp-A0h]
  Scaleform::GFx::Value gfxVal; // [rsp+68h] [rbp-70h]
  Scaleform::GFx::AS2::Value value; // [rsp+A0h] [rbp-38h]
  $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *v20; // [rsp+C0h] [rbp-18h]
  Scaleform::GFx::MovieImpl *v21; // [rsp+C8h] [rbp-10h]
  Scaleform::GFx::Value *v22; // [rsp+D0h] [rbp-8h]
  Scaleform::GFx::Value *v23; // [rsp+D8h] [rbp+0h]
  Scaleform::GFx::Value *v24; // [rsp+E0h] [rbp+8h]
  int v25; // [rsp+E8h] [rbp+10h]
  void *v26; // [rsp+F0h] [rbp+18h]
  __int64 v27; // [rsp+F8h] [rbp+20h]
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *v28; // [rsp+138h] [rbp+60h]
  Scaleform::GFx::Value *v29; // [rsp+140h] [rbp+68h]

  v27 = -2i64;
  v2 = fn;
  v3 = this;
  v4 = fn->Env;
  v28 = &pheapAddr;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = 0;
  *(_QWORD *)&gfxVal.Type = 0i64;
  gfxVal.mValue.IValue = 0;
  value.T.Type = 0;
  v5 = fn->ThisPtr;
  if ( v5 )
  {
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&value, v5);
    v6 = value.T.Type;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(&value);
    v6 = 1;
    value.T.Type = 1;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)v4->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    v4,
    &value,
    &pdestVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  v7 = &pheapAddr.Data[pheapAddr.Size - 1];
  v28 = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
  v29 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( v7 )
  {
    v7->pObjectInterface = 0i64;
    v7->Type = pdestVal.Type;
    v7->mValue.NValue = pdestVal.mValue.NValue;
    v7->DataAux = pdestVal.DataAux;
    if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
    {
      v7->pObjectInterface = pdestVal.pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))pdestVal.pObjectInterface->vfptr->gap8)(
        pdestVal.pObjectInterface,
        v7,
        *(_QWORD *)&v7->mValue.NValue);
    }
  }
  for ( i = 0; i < v2->NArgs; ++i )
  {
    gfxVal.pObjectInterface = 0i64;
    pdestVal.mValue.IValue = 0;
    v9 = v2->FirstArgBottomIndex - i;
    v10 = v2->Env;
    v11 = 0i64;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
      v11 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
      (Scaleform::GFx::AS2::MovieRoot *)v4->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v4,
      v11,
      &gfxVal);
    Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v12 = &pheapAddr.Data[pheapAddr.Size - 1];
    v28 = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    v29 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( v12 )
    {
      v12->pObjectInterface = 0i64;
      v12->Type = pdestVal.mValue.IValue;
      *(_QWORD *)&v12->mValue.NValue = pdestVal.DataAux;
      v12->DataAux = (unsigned __int64)gfxVal.pPrev;
      if ( ((unsigned int)pdestVal.mValue.IValue >> 6) & 1 )
      {
        v12->pObjectInterface = gfxVal.pObjectInterface;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))gfxVal.pObjectInterface->vfptr->gap8)(
          gfxVal.pObjectInterface,
          v12,
          *(_QWORD *)&v12->mValue.NValue);
      }
    }
    if ( ((unsigned int)pdestVal.mValue.IValue >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&gfxVal.pObjectInterface->vfptr->gap8[8])(
        gfxVal.pObjectInterface,
        &gfxVal,
        pdestVal.DataAux);
      gfxVal.pObjectInterface = 0i64;
    }
    pdestVal.mValue.IValue = 0;
  }
  v21 = v4->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  v20 = &gfxVal.8;
  v22 = &pdestVal;
  if ( v2->NArgs <= 0 )
    v24 = 0i64;
  else
    v24 = pheapAddr.Data + 1;
  v23 = pheapAddr.Data;
  v25 = LODWORD(pheapAddr.Size) - 1;
  v26 = v3->pUserData;
  v3->pContext.pObject->vfptr[1].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v3->pContext.pObject->vfptr,
    (unsigned int)&v20);
  if ( gfxVal.mValue.BValue & 0x8F )
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(
      (Scaleform::GFx::AS2::MovieRoot *)v4->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (Scaleform::GFx::Value *)((char *)&gfxVal + 8),
      v2->Result);
  if ( (unsigned __int8)v6 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( ((unsigned int)gfxVal.mValue.IValue >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&gfxVal.Type
                                                                                          + 16i64))(
      *(_QWORD *)&gfxVal.Type,
      &gfxVal.8,
      gfxVal.DataAux);
    *(_QWORD *)&gfxVal.Type = 0i64;
  }
  gfxVal.mValue.IValue = 0;
  if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      *(_QWORD *)&pdestVal.mValue.NValue);
    pdestVal.pObjectInterface = 0i64;
  }
  pdestVal.Type = 0;
  v28 = &pheapAddr;
  v13 = pheapAddr.Size;
  v14 = pheapAddr.Data;
  v15 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      if ( ((unsigned int)v15->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v15->pObjectInterface->vfptr->gap8[8])(
          v15->pObjectInterface,
          v15,
          *(_QWORD *)&v15->mValue.NValue);
        v15->pObjectInterface = 0i64;
      }
      v15->Type = 0;
      --v15;
      --v13;
    }
    while ( v13 );
    v14 = pheapAddr.Data;
  }
  if ( v14 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 288
// RVA: 0x704CE0
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ObjectAddRef(Scaleform::GFx::AS2ValueObjectInterface *this, Scaleform::GFx::Value *val, void *pobj)
{
  Scaleform::GFx::Value *v3; // rbx
  Scaleform::GFx::AS2ValueObjectInterface *v4; // rdi
  __int32 v5; // eax
  Scaleform::GFx::AS2::Object *v6; // rax

  v3 = val;
  v4 = this;
  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    ++*((_DWORD *)pobj + 6);
  }
  else if ( v5 == 7 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pobj - 1);
  }
  else if ( v5 > 7 )
  {
    if ( v5 <= 9 )
    {
      v6 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)pobj);
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
    }
    else if ( v5 == 10 )
    {
      ++*(_DWORD *)pobj;
    }
  }
  v3->pPrev = v4->ExternalObjRefs.Root.pPrev;
  v3->pNext = (Scaleform::GFx::Value *)&v4->ExternalObjRefs;
  v4->ExternalObjRefs.Root.pPrev->pNext = v3;
  v4->ExternalObjRefs.Root.pPrev = v3;
}

// File Line: 331
// RVA: 0x704D60
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ObjectRelease(Scaleform::GFx::AS2ValueObjectInterface *this, Scaleform::GFx::Value *val, void *pobj)
{
  void *v3; // rbx
  Scaleform::GFx::Value *v4; // rdi
  __int32 v5; // eax
  Scaleform::GFx::AS2::Object *v6; // rax
  unsigned int v7; // ecx
  bool v8; // zf

  v3 = pobj;
  v4 = val;
  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    v8 = (*((_DWORD *)pobj + 6))-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pobj);
  }
  else if ( v5 == 7 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)((char *)pobj - 24));
  }
  else if ( v5 > 7 )
  {
    if ( v5 <= 9 )
    {
      v6 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)pobj);
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
      }
    }
    else if ( v5 == 10 && --*(_DWORD *)pobj <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)pobj);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  v4->pPrev->pNext = v4->pNext;
  v4->pNext->pPrev = v4->pPrev;
}

// File Line: 381
// RVA: 0x6FB260
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::HasMember(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *name, bool isdobj)
{
  bool v4; // bl
  const char *v5; // r14
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rsi
  Scaleform::GFx::InteractiveObject *v8; // r10
  signed __int64 v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  __int64 v12; // rax
  Scaleform::GFx::ASString *v14; // rax
  bool v15; // bl
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  bool v18; // bl
  Scaleform::GFx::AS2::Value v19; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v4 = isdobj;
  v5 = name;
  v6 = (Scaleform::GFx::CharacterHandle *)pdata;
  v7 = this->pMovieRoot;
  v8 = v7->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  v9 = (signed __int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v9 + 240i64))(v9);
  if ( v4 )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v6, v7);
    if ( !v11 )
      return 0;
    v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                      + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
    if ( !v12 )
      return 0;
    v6 = (Scaleform::GFx::CharacterHandle *)(v12 + 8);
  }
  if ( !v6 )
    return 0;
  v19.T.Type = 0;
  v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v10, &result, v5);
  v15 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v6->RefCount + 32i64))(
          v6,
          v10,
          v14,
          &v19) == 0;
  v16 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v18 = v15 == 0;
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  return v18;
}

// File Line: 402
// RVA: 0x6EFE90
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetMember(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *name, Scaleform::GFx::Value *pval, bool isdobj)
{
  Scaleform::GFx::Value *v5; // rbx
  const char *v6; // r15
  Scaleform::GFx::CharacterHandle *v7; // rsi
  Scaleform::GFx::MovieImpl *v8; // rdi
  Scaleform::GFx::AS2::MovieRoot *v9; // r14
  signed __int64 v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rbp
  Scaleform::GFx::DisplayObject *v12; // rax
  __int64 v13; // rax
  Scaleform::GFx::ASString *v15; // rax
  bool v16; // di
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  char v19; // bl
  Scaleform::GFx::AS2::ObjectInterface *v20; // rdi
  Scaleform::GFx::AS2::Object *v21; // rax
  Scaleform::GFx::AS2::AvmCharacter *v22; // rax
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v5 = pval;
  v6 = name;
  v7 = (Scaleform::GFx::CharacterHandle *)pdata;
  v8 = this->pMovieRoot;
  v9 = (Scaleform::GFx::AS2::MovieRoot *)v8->pASMovieRoot.pObject;
  v10 = (signed __int64)v9->pMovieImpl->pMainMovie + 4 * (unsigned __int8)v9->pMovieImpl->pMainMovie->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v10 + 240i64))(v10);
  if ( isdobj )
  {
    v12 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v7, v8);
    if ( !v12 )
      goto LABEL_6;
    v13 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v12->vfptr
                                                                      + 4 * (unsigned __int8)v12->AvmObjOffset))[1].__vecDelDtor)();
    if ( !v13 )
      goto LABEL_6;
    v7 = (Scaleform::GFx::CharacterHandle *)(v13 + 8);
  }
  if ( !v7 )
  {
LABEL_6:
    if ( v5 )
    {
      if ( ((unsigned int)v5->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v5->pObjectInterface->vfptr->gap8[8])(
          v5->pObjectInterface,
          v5,
          *(_QWORD *)&v5->mValue.NValue);
        v5->pObjectInterface = 0i64;
      }
      v5->Type = 0;
    }
    return 0;
  }
  value.T.Type = 0;
  v15 = Scaleform::GFx::AS2::Environment::CreateString(v11, &result, v6);
  v16 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v7->RefCount + 32i64))(
          v7,
          v11,
          v15,
          &value) == 0;
  v17 = result.pNode;
  v18 = result.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v16 )
  {
    if ( v5 )
    {
      if ( ((unsigned int)v5->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v5->pObjectInterface->vfptr->gap8[8])(
          v5->pObjectInterface,
          v5,
          *(_QWORD *)&v5->mValue.NValue);
        v5->pObjectInterface = 0i64;
      }
      v5->Type = 0;
    }
    v19 = 0;
  }
  else
  {
    if ( value.T.Type == 9 )
    {
      v20 = 0i64;
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::CharacterHandle *))(*(_QWORD *)&v7->RefCount + 16i64))(v7)
         - 6 <= 0x26 )
      {
        v21 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)v7);
        if ( v21 )
          v20 = (Scaleform::GFx::AS2::ObjectInterface *)&v21->vfptr;
      }
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::CharacterHandle *))(*(_QWORD *)&v7->RefCount + 16i64))(v7)
         - 2 <= 3 )
      {
        v22 = Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter((Scaleform::GFx::AS2::ObjectInterface *)v7);
        if ( v22 )
          v20 = (Scaleform::GFx::AS2::ObjectInterface *)&v22->vfptr;
      }
      Scaleform::GFx::AS2::Value::GetPropertyValue(&value, v11, v20, &value);
    }
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v9, v11, &value, v5);
    v19 = 1;
  }
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  return v19;
}

// File Line: 439
// RVA: 0x7151A0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetMember(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *name, Scaleform::GFx::Value *value, bool isdobj)
{
  Scaleform::GFx::Value *v5; // r14
  const char *v6; // r15
  Scaleform::GFx::CharacterHandle *v7; // rbx
  Scaleform::GFx::MovieImpl *v8; // rdi
  Scaleform::GFx::AS2::MovieRoot *v9; // rsi
  Scaleform::GFx::AS2::Environment *v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  __int64 v12; // rax
  Scaleform::GFx::ASString *v14; // rax
  char v15; // bl
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v5 = value;
  v6 = name;
  v7 = (Scaleform::GFx::CharacterHandle *)pdata;
  v8 = this->pMovieRoot;
  v9 = (Scaleform::GFx::AS2::MovieRoot *)v8->pASMovieRoot.pObject;
  v10 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v9->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v9->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  if ( isdobj )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v7, v8);
    if ( !v11 )
      return 0;
    v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                      + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
    if ( !v12 )
      return 0;
    v7 = (Scaleform::GFx::CharacterHandle *)(v12 + 8);
  }
  if ( !v7 )
    return 0;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v9, v5, &pdestVal);
  v14 = Scaleform::GFx::AS2::Environment::CreateString(v10, &result, v6);
  isdobj = 0;
  v15 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, bool *))(*(_QWORD *)&v7->RefCount + 24i64))(
          v7,
          v10,
          v14,
          &pdestVal,
          &isdobj);
  v16 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return v15;
}

// File Line: 454
// RVA: 0x6FDD50
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::Invoke(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *presult, const char *name, Scaleform::GFx::Value *pargs, unsigned __int64 nargs, bool isdobj)
{
  const char *v7; // rdi
  Scaleform::GFx::Value *v8; // r12
  Scaleform::GFx::CharacterHandle *v9; // r14
  Scaleform::GFx::MovieImpl *v10; // rbx
  Scaleform::GFx::AS2::MovieRoot *v11; // r15
  Scaleform::GFx::AS2::Environment *v12; // r13
  Scaleform::GFx::DisplayObject *v13; // rax
  __int64 v14; // rax
  Scaleform::GFx::ASString *v16; // rax
  char v17; // bl
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  char i; // bp
  char v21; // di
  int v22; // esi
  Scaleform::GFx::Value *v23; // rdi
  __int64 v24; // rbp
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS2::Value *v26; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+48h] [rbp-A0h]
  Scaleform::GFx::AS2::Value presulta; // [rsp+68h] [rbp-80h]
  Scaleform::GFx::AS2::Value method; // [rsp+88h] [rbp-60h]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v31; // [rsp+F8h] [rbp+10h]

  v7 = name;
  v8 = presult;
  v9 = (Scaleform::GFx::CharacterHandle *)pdata;
  v10 = this->pMovieRoot;
  v11 = (Scaleform::GFx::AS2::MovieRoot *)v10->pASMovieRoot.pObject;
  v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v11->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  if ( isdobj )
  {
    v13 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v9, v10);
    if ( !v13 )
      return 0;
    v14 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v13->vfptr
                                                                      + 4 * (unsigned __int8)v13->AvmObjOffset))[1].__vecDelDtor)();
    if ( !v14 )
      return 0;
    v9 = (Scaleform::GFx::CharacterHandle *)(v14 + 8);
  }
  if ( !v9 )
    return 0;
  method.T.Type = 0;
  presulta.T.Type = 0;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v12->StringContext, &result, v7);
  v17 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&v9->RefCount + 88i64))(
          v9,
          &v12->StringContext,
          v16,
          &method);
  v18 = result.pNode;
  v19 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v17 )
  {
    v21 = 0;
    pdestVal.T.Type = 0;
    v22 = nargs;
    if ( (signed int)nargs - 1 > -1 )
    {
      v23 = &pargs[(signed int)nargs - 1];
      v24 = (unsigned int)nargs;
      do
      {
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v11, v23, &pdestVal);
        ++v12->Stack.pCurrent;
        if ( v12->Stack.pCurrent >= v12->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v12->Stack);
        v25 = (Scaleform::GFx::ASStringNode *)v12->Stack.pCurrent;
        result.pNode = v25;
        v31 = v25;
        if ( v25 )
          Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v25, &pdestVal, (__int64)v23);
        --v23;
        --v24;
      }
      while ( v24 );
      v21 = pdestVal.T.Type;
    }
    for ( i = Scaleform::GFx::AS2::GAS_Invoke(
                &method,
                &presulta,
                (Scaleform::GFx::AS2::ObjectInterface *)v9,
                v12,
                v22,
                32 * v12->Stack.Pages.Data.Size
              - 32
              + ((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5),
                0i64); v22; --v22 )
    {
      v26 = v12->Stack.pCurrent;
      if ( v26->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v26);
      --v12->Stack.pCurrent;
      if ( v12->Stack.pCurrent < v12->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v12->Stack);
    }
    if ( v8 )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v11, v12, &presulta, v8);
    if ( (unsigned __int8)v21 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  }
  else
  {
    i = 0;
  }
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  return i;
}

// File Line: 496
// RVA: 0x6E1DF0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::DeleteMember(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *name, bool isdobj)
{
  bool v4; // bl
  const char *v5; // r14
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rsi
  Scaleform::GFx::InteractiveObject *v8; // r10
  signed __int64 v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  __int64 v12; // rax
  Scaleform::GFx::ASString *v14; // rax
  char v15; // bl
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v4 = isdobj;
  v5 = name;
  v6 = (Scaleform::GFx::CharacterHandle *)pdata;
  v7 = this->pMovieRoot;
  v8 = v7->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  v9 = (signed __int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v9 + 240i64))(v9);
  if ( v4 )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v6, v7);
    if ( !v11 )
      return 0;
    v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                      + 4 * (unsigned __int8)v11->AvmObjOffset))[1].__vecDelDtor)();
    if ( !v12 )
      return 0;
    v6 = (Scaleform::GFx::CharacterHandle *)(v12 + 8);
  }
  if ( !v6 )
    return 0;
  v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v10, &result, v5);
  v15 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)&v6->RefCount + 48i64))(
          v6,
          &v10->StringContext,
          v14);
  v16 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return v15;
}

// File Line: 505
// RVA: 0x723D60
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor, bool isdobj)
{
  bool v4; // bl
  Scaleform::GFx::Value::ObjectInterface::ObjVisitor *v5; // r15
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rsi
  __int64 v8; // r14
  __int64 v9; // rbp
  Scaleform::GFx::DisplayObject *v10; // rax
  __int64 v11; // rax
  __int64 (__fastcall **v12)(); // [rsp+38h] [rbp-40h]
  __int64 v13; // [rsp+40h] [rbp-38h]
  __int64 v14; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::Value::ObjectInterface::ObjVisitor *v15; // [rsp+50h] [rbp-28h]

  v4 = isdobj;
  v5 = visitor;
  v6 = (Scaleform::GFx::CharacterHandle *)pdata;
  v7 = this->pMovieRoot;
  v8 = (__int64)v7->pASMovieRoot.pObject;
  v9 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 16) + 80i64)
                                        + 4i64
                                        * *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v8 + 16) + 80i64) + 109i64))
                            + 240i64))();
  if ( v4 )
  {
    v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v6, v7);
    if ( v10
      && (v11 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v10->vfptr
                                                                            + 4 * (unsigned __int8)v10->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
    {
      v6 = (Scaleform::GFx::CharacterHandle *)(v11 + 8);
    }
    else
    {
      v6 = 0i64;
    }
  }
  v12 = `Scaleform::GFx::AS2ValueObjectInterface::VisitMembers'::`2'::VisitorProxy::`vftable';
  v13 = v8;
  v14 = v9;
  v15 = v5;
  (*(void (__fastcall **)(Scaleform::GFx::CharacterHandle *, __int64, __int64 (__fastcall ***)(), signed __int64, _QWORD))(*(_QWORD *)&v6->RefCount + 64i64))(
    v6,
    v9 + 232,
    &v12,
    3i64,
    0i64);
}

// File Line: 518
// RVA: 0x723A20
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers_::_2_::VisitorProxy::Visit(Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, __int64 flags)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-40h]

  v3 = val;
  v4 = name;
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)name[1].pNode,
    (Scaleform::GFx::AS2::Environment *)name[2].pNode,
    (Scaleform::GFx::AS2::Value *)flags,
    &pdestVal);
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, _QWORD, Scaleform::GFx::Value *))v4[3].pNode->pData + 2))(
    v4[3].pNode,
    **(_QWORD **)&v3->T.Type,
    &pdestVal);
  if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      *(_QWORD *)&pdestVal.mValue.NValue);
}

// File Line: 592
// RVA: 0x6EE690
__int64 __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetArraySize(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata)
{
  __int64 result; // rax

  if ( pdata )
    result = *((unsigned int *)pdata + 20);
  else
    result = MEMORY[0x70];
  return result;
}

// File Line: 600
// RVA: 0x712FF0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetArraySize(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, unsigned int sz)
{
  if ( pdata )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)pdata - 32), sz);
  else
    Scaleform::GFx::AS2::ArrayObject::Resize(0i64, sz);
  return 1;
}

// File Line: 609
// RVA: 0x6EF6B0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetElement(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, unsigned int idx, Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::Value *v4; // rdi
  __int64 v5; // rsi
  Scaleform::GFx::AS2ValueObjectInterface *v6; // rbp
  char *v7; // rbx
  Scaleform::GFx::AS2::Value *v9; // rsi
  Scaleform::GFx::AS2::MovieRoot *v10; // rbx
  Scaleform::GFx::AS2::Environment *v11; // rax

  v4 = pval;
  v5 = (signed int)idx;
  v6 = this;
  if ( pdata )
    v7 = (char *)pdata - 32;
  else
    v7 = 0i64;
  if ( ((unsigned int)pval->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      *(_QWORD *)&pval->mValue.NValue);
    v4->pObjectInterface = 0i64;
  }
  v4->Type = 0;
  if ( (unsigned int)v5 >= *((_DWORD *)v7 + 28) )
    return 0;
  v9 = *(Scaleform::GFx::AS2::Value **)(*((_QWORD *)v7 + 13) + 8 * v5);
  if ( !v9 )
    return 0;
  v10 = (Scaleform::GFx::AS2::MovieRoot *)v6->pMovieRoot->pASMovieRoot.pObject;
  v11 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v10->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v10->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)(
                                              (char *)v10->pMovieImpl->pMainMovie
                                            + 4 * (unsigned __int8)v10->pMovieImpl->pMainMovie->AvmObjOffset);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v10, v11, v9, v4);
  return 1;
}

// File Line: 627
// RVA: 0x7143B0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetElement(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, unsigned int idx, Scaleform::GFx::Value *value)
{
  __int64 v4; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rbx
  Scaleform::GFx::AS2::MovieRoot *v6; // rcx
  __int64 v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rax
  Scaleform::GFx::AS2::Value *v9; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-30h]
  int v12; // [rsp+70h] [rbp+18h]

  v4 = (signed int)idx;
  if ( pdata )
    v5 = (Scaleform::GFx::AS2::ArrayObject *)((char *)pdata - 32);
  else
    v5 = 0i64;
  v6 = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v6, value, &pdestVal);
  v5->LengthValueOverriden = 0;
  if ( (signed int)v4 >= SLODWORD(v5->Elements.Data.Size) )
    Scaleform::GFx::AS2::ArrayObject::Resize(v5, v4 + 1);
  v7 = v4;
  if ( !v5->Elements.Data.Data[v7] )
  {
    v12 = 323;
    v8 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         v5,
                                         32i64,
                                         &v12,
                                         -2i64);
    v9 = v8;
    if ( v8 )
      v8->T.Type = 0;
    else
      v9 = 0i64;
    v5->Elements.Data.Data[v7] = v9;
  }
  Scaleform::GFx::AS2::Value::operator=(v5->Elements.Data.Data[v7], &pdestVal, v7 * 8);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return 1;
}

// File Line: 640
// RVA: 0x723C10
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitElements(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor, unsigned int idx, int count)
{
  __int64 v5; // rbx
  Scaleform::GFx::Value::ObjectInterface::ArrVisitor *v6; // r14
  char *v7; // rsi
  Scaleform::GFx::AS2::MovieRoot *v8; // r15
  signed __int64 v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // r12
  __int64 v11; // rdx
  int v12; // ecx
  unsigned int v13; // ebp
  signed __int64 v14; // rdi
  Scaleform::GFx::AS2::Value *v15; // r8
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-60h]

  v5 = idx;
  v6 = visitor;
  v7 = (char *)pdata - 32;
  if ( !pdata )
    v7 = 0i64;
  v8 = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = (signed __int64)v8->pMovieImpl->pMainMovie + 4 * (unsigned __int8)v8->pMovieImpl->pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v9 + 240i64))(v9);
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = 0;
  v11 = *((_QWORD *)v7 + 14);
  if ( (unsigned int)v5 < (unsigned int)v11 )
  {
    v12 = count;
    if ( count < 0 )
      v12 = v11 - v5;
    v13 = v5 + v12;
    if ( (unsigned int)v11 < (signed int)v5 + v12 )
      v13 = *((_QWORD *)v7 + 14);
    if ( (unsigned int)v5 < v13 )
    {
      v14 = 8 * v5;
      do
      {
        v15 = *(Scaleform::GFx::AS2::Value **)(v14 + *((_QWORD *)v7 + 13));
        if ( v15 )
        {
          Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v8, v10, v15, &pdestVal);
        }
        else
        {
          if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
              pdestVal.pObjectInterface,
              &pdestVal,
              *(_QWORD *)&pdestVal.mValue.NValue);
            pdestVal.pObjectInterface = 0i64;
          }
          pdestVal.Type = 0;
        }
        v6->vfptr->Visit(v6, v5, &pdestVal);
        LODWORD(v5) = v5 + 1;
        v14 += 8i64;
      }
      while ( (unsigned int)v5 < v13 );
    }
  }
  if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      *(_QWORD *)&pdestVal.mValue.NValue);
}

// File Line: 665
// RVA: 0x70AA20
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::PushBack(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // rbx
  Scaleform::GFx::AS2::MovieRoot *v4; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-30h]

  if ( pdata )
    v3 = (Scaleform::GFx::AS2::ArrayObject *)((char *)pdata - 32);
  else
    v3 = 0i64;
  v4 = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v4, value, &pdestVal);
  Scaleform::GFx::AS2::ArrayObject::PushBack(v3, &pdestVal);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return 1;
}

// File Line: 678
// RVA: 0x708430
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::PopBack(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::Value *v3; // rbx
  char *v4; // rdi
  Scaleform::GFx::AS2::MovieRoot *v5; // rsi
  Scaleform::GFx::AS2::Environment *v6; // rcx
  int v7; // eax
  char result; // al

  v3 = pval;
  if ( pdata )
    v4 = (char *)pdata - 32;
  else
    v4 = 0i64;
  v5 = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v5->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  v7 = *((_DWORD *)v4 + 28);
  if ( v7 > 0 )
  {
    if ( v3 )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
        v5,
        v6,
        *(Scaleform::GFx::AS2::Value **)(*((_QWORD *)v4 + 13) + 8i64 * (v7 - 1)),
        v3);
    if ( *((_QWORD *)v4 + 14) )
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v4, *((_DWORD *)v4 + 28) - 1);
    result = 1;
  }
  else
  {
    if ( v3 )
    {
      if ( ((unsigned int)v3->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v3->pObjectInterface->vfptr->gap8[8])(
          v3->pObjectInterface,
          v3,
          *(_QWORD *)&v3->mValue.NValue);
        v3->pObjectInterface = 0i64;
      }
      v3->Type = 0;
    }
    result = 0;
  }
  return result;
}

// File Line: 703
// RVA: 0x70FF40
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::RemoveElements(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, unsigned int idx, int count)
{
  char *v4; // rcx
  unsigned int v5; // eax
  unsigned int v7; // eax

  if ( pdata )
    v4 = (char *)pdata - 32;
  else
    v4 = 0i64;
  v5 = *((_DWORD *)v4 + 28);
  if ( idx >= v5 )
    return 0;
  if ( count < 0 )
    count = v5 - idx;
  v7 = v5 - idx;
  if ( v7 < count )
    count = v7;
  Scaleform::GFx::AS2::ArrayObject::RemoveElements((Scaleform::GFx::AS2::ArrayObject *)v4, idx, count);
  return 1;
}

// File Line: 717
// RVA: 0x6EF5F0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayMatrix(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // xmm3_4
  float v11; // xmm5_4

  v3 = pmat;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( v4 )
  {
    v4 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[2].__vecDelDtor)(v4);
    v5 = *((float *)&v4->pWeakProxy + 1);
    v6 = *((float *)&v4->RefCount + 1) * 0.050000001;
    v7 = *(float *)&v4->vfptr;
    v8 = *(float *)&v4->vfptr;
    v9 = *((float *)&v4->vfptr + 1);
    v10 = v4->RefCount;
    v11 = *(float *)&v4->pWeakProxy;
    v3->M[1][3] = *((float *)&v4->vfptr + 1) * 0.050000001;
    LOBYTE(v4) = 1;
    v3->M[1][1] = v5;
    v3->M[1][2] = v7;
    v3->M[0][0] = v8;
    v3->M[0][1] = v9;
    LODWORD(v3->M[0][2]) = v10;
    v3->M[0][3] = v6;
    v3->M[1][0] = v11;
  }
  return (char)v4;
}

// File Line: 732
// RVA: 0x6F87E0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetWorldMatrix(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmata; // [rsp+20h] [rbp-28h]

  v3 = pmat;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( v4 )
  {
    *(_OWORD *)&pmata.M[0][0] = _xmm;
    *(__m128 *)&pmata.M[1][0] = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &pmata);
    v5 = pmata.M[0][1];
    LOBYTE(v4) = 1;
    v6 = pmata.M[0][3];
    v7 = pmata.M[1][3];
    v3->M[0][0] = pmata.M[0][0];
    v8 = pmata.M[0][2];
    v3->M[0][1] = v5;
    v9 = pmata.M[1][0];
    v3->M[0][2] = v8;
    v10 = pmata.M[1][1];
    v3->M[1][0] = v9;
    v11 = pmata.M[1][2];
    v3->M[1][1] = v10;
    v3->M[0][3] = v6 * 0.050000001;
    v3->M[1][2] = v11;
    v3->M[1][3] = v7 * 0.050000001;
  }
  return (char)v4;
}

// File Line: 747
// RVA: 0x7141F0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayMatrix(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rdi
  int v6; // xmm0_4
  float v7; // xmm2_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  float v13; // xmm4_4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128d v16; // xmm0
  __m128d v17; // xmm2
  double v18; // xmm1_8
  int v19; // [rsp+20h] [rbp-39h]
  float v20; // [rsp+24h] [rbp-35h]
  int v21; // [rsp+28h] [rbp-31h]
  float v22; // [rsp+2Ch] [rbp-2Dh]
  int v23; // [rsp+30h] [rbp-29h]
  int v24; // [rsp+34h] [rbp-25h]
  int v25; // [rsp+38h] [rbp-21h]
  float v26; // [rsp+3Ch] [rbp-1Dh]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+40h] [rbp-19h]

  v3 = mat;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( !v4 || !Scaleform::Render::Matrix2x4<float>::IsValid(v3) )
    return 0;
  v6 = LODWORD(v3->M[0][0]);
  v7 = v3->M[0][3];
  v20 = v3->M[0][1];
  v8 = LODWORD(v3->M[1][1]);
  v19 = v6;
  v9 = LODWORD(v3->M[0][2]);
  v24 = v8;
  v10 = v3->M[1][3] * 20.0;
  v21 = v9;
  v11 = LODWORD(v3->M[1][0]);
  v22 = v7 * 20.0;
  v23 = v11;
  v12 = LODWORD(v3->M[1][2]);
  v26 = v10;
  v25 = v12;
  v4->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, (unsigned int)&v19);
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &geomData);
  v13 = v3->M[1][0];
  v14 = (__m128)LODWORD(v3->M[0][0]);
  v15 = (__m128)LODWORD(v3->M[0][1]);
  geomData.X = (signed int)v3->M[0][3];
  v16 = _mm_cvtps_pd(v14);
  v17 = _mm_cvtps_pd(v15);
  geomData.Y = (signed int)v3->M[1][3];
  v16.m128d_f64[0] = v16.m128d_f64[0] * v16.m128d_f64[0] + v13 * v13;
  v18 = v3->M[1][1] * v3->M[1][1];
  geomData.XScale = COERCE_DOUBLE(_mm_sqrt_pd(v16)) * 100.0;
  v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v18;
  geomData.YScale = COERCE_DOUBLE(_mm_sqrt_pd(v17)) * 100.0;
  geomData.Rotation = atan2(v13, v14.m128_f32[0]) * 180.0 * 0.3183098861837907;
  Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &geomData);
  return 1;
}

// File Line: 780
// RVA: 0x6EFD30
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetMatrix3D(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::Render::Matrix3x4<float> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm6_4
  float v6; // xmm8_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  unsigned int v11; // xmm11_4
  int v12; // xmm12_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // xmm3_4
  float v16; // xmm5_4

  v3 = pmat;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( v4 )
  {
    v4 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[4].__vecDelDtor)(v4);
    v5 = *((float *)&v4->pWeakProxy + 1);
    v6 = *((float *)&v4->vfptr + 1) * 0.050000001;
    v7 = *((float *)&v4->RefCount + 1) * 0.050000001;
    v8 = *(float *)&v4->vfptr;
    v9 = *(float *)&v4->pASRoot;
    v10 = *((float *)&v4->pASRoot + 1);
    v11 = v4->Id.Id;
    v12 = v4->Depth;
    v13 = *(float *)&v4->vfptr;
    v14 = *((float *)&v4->vfptr + 1);
    v15 = v4->RefCount;
    v16 = *(float *)&v4->pWeakProxy;
    LOBYTE(v4) = 1;
    v3->M[0][0] = v13;
    v3->M[0][1] = v14;
    LODWORD(v3->M[0][2]) = v15;
    v3->M[0][3] = v7;
    v3->M[1][0] = v16;
    v3->M[1][1] = v5;
    v3->M[1][2] = v8;
    v3->M[1][3] = v6;
    v3->M[2][0] = v9;
    v3->M[2][1] = v10;
    LODWORD(v3->M[2][2]) = v11;
    LODWORD(v3->M[2][3]) = v12;
  }
  return (char)v4;
}

// File Line: 797
// RVA: 0x714F90
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetMatrix3D(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix3x4<float> *mat)
{
  Scaleform::Render::Matrix3x4<float> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rdi
  int v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // xmm0_4
  int v12; // xmm1_4
  int v13; // xmm0_4
  int v14; // xmm1_4
  __m128 v15; // xmm2
  float v16; // [rsp+20h] [rbp-49h]
  int v17; // [rsp+24h] [rbp-45h]
  float v18; // [rsp+28h] [rbp-41h]
  float v19; // [rsp+2Ch] [rbp-3Dh]
  int v20; // [rsp+30h] [rbp-39h]
  int v21; // [rsp+34h] [rbp-35h]
  float v22; // [rsp+38h] [rbp-31h]
  float v23; // [rsp+3Ch] [rbp-2Dh]
  int v24; // [rsp+40h] [rbp-29h]
  int v25; // [rsp+44h] [rbp-25h]
  int v26; // [rsp+48h] [rbp-21h]
  int v27; // [rsp+4Ch] [rbp-1Dh]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+50h] [rbp-19h]
  float eX; // [rsp+D0h] [rbp+67h]
  float eY; // [rsp+D8h] [rbp+6Fh]

  v3 = mat;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( !v4 || !Scaleform::Render::Matrix3x4<float>::IsValid(v3) )
    return 0;
  v6 = LODWORD(v3->M[0][1]);
  v7 = v3->M[0][3];
  v8 = v3->M[1][3];
  v16 = v3->M[0][0];
  v18 = v3->M[0][2];
  v9 = LODWORD(v3->M[1][0]);
  v17 = v6;
  v10 = LODWORD(v3->M[1][1]);
  v20 = v9;
  v22 = v3->M[1][2];
  v11 = LODWORD(v3->M[2][0]);
  v21 = v10;
  v12 = LODWORD(v3->M[2][1]);
  v24 = v11;
  v13 = LODWORD(v3->M[2][2]);
  v25 = v12;
  v14 = LODWORD(v3->M[2][3]);
  v26 = v13;
  v27 = v14;
  v19 = v7 * 20.0;
  v23 = v8 * 20.0;
  v4->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, (unsigned int)&v16);
  *(_QWORD *)&geomData.X = 0i64;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &geomData);
  v15 = (__m128)LODWORD(v3->M[0][2]);
  v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v3->M[1][2] * v3->M[1][2]);
  geomData.Z = v3->M[2][3];
  v15.m128_f32[0] = v15.m128_f32[0] + (float)(v3->M[2][2] * v3->M[2][2]);
  geomData.ZScale = COERCE_FLOAT(_mm_sqrt_ps(v15)) * 100.0;
  Scaleform::Render::Matrix3x4<float>::GetEulerAngles(v3, &eX, &eY, 0i64);
  geomData.XRotation = eX * 180.0 * 0.3183098861837907;
  geomData.YRotation = eY * 180.0 * 0.3183098861837907;
  Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &geomData);
  return 1;
}

// File Line: 834
// RVA: 0x700390
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::IsDisplayObjectActive(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata)
{
  return Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot) != 0i64;
}

// File Line: 843
// RVA: 0x6F46D0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetParent(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pparent)
{
  Scaleform::GFx::AS2ValueObjectInterface *v3; // rdi
  Scaleform::GFx::Value *v4; // rbx
  Scaleform::GFx::DisplayObject *v5; // rax
  Scaleform::GFx::DisplayObject *v6; // rcx
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::GFx::CharacterHandle *v8; // rdi
  Scaleform::GFx::ASMovieRootBase *v9; // rsi
  Scaleform::GFx::MovieImpl *v10; // rdx
  Scaleform::GFx::Value::ObjectInterface *v11; // rsi
  Scaleform::GFx::DisplayObject *v12; // rax
  unsigned __int16 v13; // cx

  v3 = this;
  v4 = pparent;
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  if ( v5 )
  {
    v6 = (Scaleform::GFx::DisplayObject *)&v5->pParent->vfptr;
    if ( v6 )
    {
      v7 = v3->pMovieRoot;
      v8 = v6->pNameHandle.pObject;
      v9 = v7->pASMovieRoot.pObject;
      if ( !v8 )
        v8 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v6);
      v10 = v9->pMovieImpl;
      v11 = v10->pObjectInterface;
      v12 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, v10);
      if ( v12 && ((v13 = v12->Flags, (v13 >> 10) & 1) || (v13 & 0x80u) != 0) )
      {
        if ( ((unsigned int)v4->Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v4->pObjectInterface->vfptr->gap8[8])(
            v4->pObjectInterface,
            v4,
            *(_QWORD *)&v4->mValue.NValue);
          v4->pObjectInterface = 0i64;
        }
        v4->Type = 74;
        *(_QWORD *)&v4->mValue.NValue = v8;
        v4->pObjectInterface = v11;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::CharacterHandle *))v11->vfptr->gap8)(
          v11,
          v4,
          v8);
        LOBYTE(v5) = 1;
      }
      else
      {
        LOBYTE(v5) = 0;
      }
    }
    else
    {
      if ( ((unsigned int)v4->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v4->pObjectInterface->vfptr->gap8[8])(
          v4->pObjectInterface,
          v4,
          *(_QWORD *)&v4->mValue.NValue);
        v4->pObjectInterface = 0i64;
      }
      v4->Type = 1;
      LOBYTE(v5) = 1;
    }
  }
  return (char)v5;
}

// File Line: 865
// RVA: 0x6EF180
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayInfo(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::Value::DisplayInfo *v3; // rbx
  Scaleform::GFx::TextField *v4; // rax
  Scaleform::GFx::TextField *v5; // rdi
  long double v6; // xmm0_8
  long double v7; // xmm7_8
  long double v8; // xmm8_8
  long double v9; // xmm9_8
  long double v10; // xmm11_8
  long double v11; // xmm10_8
  long double v12; // xmm6_8
  char v13; // al
  long double v14; // xmm0_8
  long double v15; // xmm1_8
  long double v16; // xmm1_8
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // xmm0_4
  int v20; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm0_4
  int v28; // xmm1_4
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm0_4
  int v36; // xmm1_4
  int v37; // xmm0_4
  int v38; // xmm1_4
  int v39; // xmm0_4
  int v40; // xmm1_4
  int v41; // xmm0_4
  int v42; // xmm1_4
  int v43; // xmm0_4
  int v44; // xmm1_4
  unsigned __int64 v45; // rdx
  int v47; // [rsp+20h] [rbp-E0h]
  int v48; // [rsp+24h] [rbp-DCh]
  int v49; // [rsp+28h] [rbp-D8h]
  int v50; // [rsp+2Ch] [rbp-D4h]
  int v51; // [rsp+30h] [rbp-D0h]
  int v52; // [rsp+34h] [rbp-CCh]
  int v53; // [rsp+38h] [rbp-C8h]
  int v54; // [rsp+3Ch] [rbp-C4h]
  int v55; // [rsp+40h] [rbp-C0h]
  int v56; // [rsp+44h] [rbp-BCh]
  int v57; // [rsp+48h] [rbp-B8h]
  int v58; // [rsp+4Ch] [rbp-B4h]
  int Dst; // [rsp+50h] [rbp-B0h]
  int v60; // [rsp+54h] [rbp-ACh]
  int v61; // [rsp+58h] [rbp-A8h]
  int v62; // [rsp+5Ch] [rbp-A4h]
  int v63; // [rsp+60h] [rbp-A0h]
  int v64; // [rsp+64h] [rbp-9Ch]
  int v65; // [rsp+68h] [rbp-98h]
  int v66; // [rsp+6Ch] [rbp-94h]
  int v67; // [rsp+70h] [rbp-90h]
  int v68; // [rsp+74h] [rbp-8Ch]
  int v69; // [rsp+78h] [rbp-88h]
  int v70; // [rsp+7Ch] [rbp-84h]
  int v71; // [rsp+80h] [rbp-80h]
  int v72; // [rsp+84h] [rbp-7Ch]
  int v73; // [rsp+88h] [rbp-78h]
  int v74; // [rsp+8Ch] [rbp-74h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+90h] [rbp-70h]

  v3 = pinfo;
  v4 = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(
                                      (Scaleform::GFx::CharacterHandle *)pdata,
                                      this->pMovieRoot);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    geomData.Rotation = 0.0;
    v6 = *(double *)&_xmm;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, &geomData);
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[81].__vecDelDtor)(v5) == 4 )
    {
      Scaleform::GFx::TextField::GetPosition(v5, v3);
    }
    else
    {
      v7 = geomData.Rotation;
      v8 = geomData.XScale;
      v9 = geomData.YScale;
      v10 = (double)geomData.X * 0.05;
      v11 = (double)geomData.Y * 0.05;
      v12 = (float)(Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr)->M[0][3]
                  * 100.0);
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[59].__vecDelDtor)(v5);
      v14 = geomData.Z;
      v3->Visible = v13;
      v3->VarsSet |= 0x7FFu;
      v15 = geomData.XRotation;
      v3->Z = v14;
      v6 = geomData.YRotation;
      v3->XRotation = v15;
      v16 = geomData.ZScale;
      v3->X = v10;
      v3->Y = v11;
      v3->Rotation = v7;
      v3->XScale = v8;
      v3->YScale = v9;
      v3->Alpha = v12;
      v3->YRotation = v6;
      v3->ZScale = v16;
    }
    ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[40].__vecDelDtor)(v5);
    v3->VarsSet |= 0x800u;
    v3->FOV = v6;
    memset(&Dst, 0, 0x40ui64);
    Dst = 1065353216;
    v64 = 1065353216;
    v69 = 1065353216;
    v74 = 1065353216;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->vfptr[6].__vecDelDtor)(
           v5,
           &Dst,
           0i64) )
    {
      v17 = Dst;
      v18 = v60;
      v3->VarsSet |= 0x1000u;
      LODWORD(v3->ProjectionMatrix3D.M[0][0]) = v17;
      v19 = v61;
      LODWORD(v3->ProjectionMatrix3D.M[0][1]) = v18;
      v20 = v62;
      LODWORD(v3->ProjectionMatrix3D.M[0][2]) = v19;
      v21 = v63;
      LODWORD(v3->ProjectionMatrix3D.M[0][3]) = v20;
      v22 = v64;
      LODWORD(v3->ProjectionMatrix3D.M[1][0]) = v21;
      v23 = v65;
      LODWORD(v3->ProjectionMatrix3D.M[1][1]) = v22;
      v24 = v66;
      LODWORD(v3->ProjectionMatrix3D.M[1][2]) = v23;
      v25 = v67;
      LODWORD(v3->ProjectionMatrix3D.M[1][3]) = v24;
      v26 = v68;
      LODWORD(v3->ProjectionMatrix3D.M[2][0]) = v25;
      v27 = v69;
      LODWORD(v3->ProjectionMatrix3D.M[2][1]) = v26;
      v28 = v70;
      LODWORD(v3->ProjectionMatrix3D.M[2][2]) = v27;
      v29 = v71;
      LODWORD(v3->ProjectionMatrix3D.M[2][3]) = v28;
      v30 = v72;
      LODWORD(v3->ProjectionMatrix3D.M[3][0]) = v29;
      v31 = v73;
      LODWORD(v3->ProjectionMatrix3D.M[3][1]) = v30;
      v32 = v74;
      LODWORD(v3->ProjectionMatrix3D.M[3][2]) = v31;
      LODWORD(v3->ProjectionMatrix3D.M[3][3]) = v32;
    }
    memset(&v47, 0, 0x30ui64);
    v47 = 1065353216;
    v52 = 1065353216;
    v57 = 1065353216;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->vfptr[9].__vecDelDtor)(
           v5,
           &v47,
           0i64) )
    {
      v33 = v47;
      v34 = v48;
      v3->VarsSet |= 0x2000u;
      LODWORD(v3->ViewMatrix3D.M[0][0]) = v33;
      v35 = v49;
      LODWORD(v3->ViewMatrix3D.M[0][1]) = v34;
      v36 = v50;
      LODWORD(v3->ViewMatrix3D.M[0][2]) = v35;
      v37 = v51;
      LODWORD(v3->ViewMatrix3D.M[0][3]) = v36;
      v38 = v52;
      LODWORD(v3->ViewMatrix3D.M[1][0]) = v37;
      v39 = v53;
      LODWORD(v3->ViewMatrix3D.M[1][1]) = v38;
      v40 = v54;
      LODWORD(v3->ViewMatrix3D.M[1][2]) = v39;
      v41 = v55;
      LODWORD(v3->ViewMatrix3D.M[1][3]) = v40;
      v42 = v56;
      LODWORD(v3->ViewMatrix3D.M[2][0]) = v41;
      v43 = v57;
      LODWORD(v3->ViewMatrix3D.M[2][1]) = v42;
      v44 = v58;
      LODWORD(v3->ViewMatrix3D.M[2][2]) = v43;
      LODWORD(v3->ViewMatrix3D.M[2][3]) = v44;
    }
    v4 = (Scaleform::GFx::TextField *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
    v45 = (signed __int64)((unsigned __int128)((signed __int64)((char *)v4
                                                              - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)
                                                              - 56)
                                             * (signed __int128)5270498306774157605i64) >> 64) >> 4;
    LODWORD(v4) = *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                       + 8 * ((unsigned int)v45 + (v45 >> 63))
                                       + 40)
                           + 10i64) & 0xC;
    v3->VarsSet |= 0x4000u;
    v3->EdgeAAMode = (signed int)v4;
    LOBYTE(v4) = 1;
  }
  return (char)v4;
}

// File Line: 910
// RVA: 0x7137D0
bool __usercall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayInfo@<al>(Scaleform::GFx::AS2ValueObjectInterface *this@<rcx>, void *pdata@<rdx>, Scaleform::GFx::Value::DisplayInfo *cinfo@<r8>, double a4@<xmm0>)
{
  Scaleform::GFx::Value::DisplayInfo *v4; // rsi
  Scaleform::GFx::DisplayObject *v5; // rax
  Scaleform::GFx::TextField *v6; // rdi
  char v7; // r14
  bool v8; // r15
  Scaleform::Render::EdgeAAMode v9; // ebx
  Scaleform::Render::TreeNode *v10; // rax
  Scaleform::Render::Cxform *v11; // rax
  signed __int64 v12; // rdx
  double v13; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v14; // rax
  double v15; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v16; // rax
  long double v17; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v18; // rbx
  long double v19; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v20; // rbx
  unsigned __int16 v21; // cx
  long double v22; // xmm6_8
  Scaleform::RefCountNTSImplCoreVtbl *v23; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v24; // rbx
  __int64 v25; // rax
  __m128d v26; // xmm0
  __m128d v27; // xmm11
  __m128d v28; // xmm10
  unsigned __int16 v29; // r14
  __m128 v30; // xmm7
  float v31; // xmm6_4
  __m128 v32; // xmm9
  float v33; // xmm8_4
  float v34; // xmm0_4
  long double v35; // xmm0_8
  double v36; // xmm1_8
  double v37; // xmm6_8
  __m128d v38; // xmm2
  double v39; // xmm7_8
  double v40; // xmm3_8
  __m128d v41; // xmm1
  double v42; // xmm8_8
  double v43; // xmm6_8
  long double v44; // xmm0_8
  double v45; // xmm0_8
  double v46; // xmm6_8
  double v47; // xmm1_8
  double v48; // xmm0_8
  double v49; // xmm14_8
  double v50; // xmm0_8
  double v51; // xmm1_8
  __int64 v52; // rcx
  __int64 v53; // rcx
  bool v54; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v55; // rax
  double v56; // xmm11_8
  double v57; // xmm11_8
  double v58; // xmm10_8
  double v59; // xmm10_8
  unsigned __int64 v61; // [rsp+20h] [rbp-E0h]
  double v62; // [rsp+20h] [rbp-E0h]
  unsigned __int64 v63; // [rsp+28h] [rbp-D8h]
  Scaleform::Render::Cxform v64; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Cxform v65; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Point<float> result; // [rsp+140h] [rbp+40h]
  double v67; // [rsp+148h] [rbp+48h]
  long double v68; // [rsp+158h] [rbp+58h]

  v4 = cinfo;
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v6 = (Scaleform::GFx::TextField *)v5;
  if ( !v5 )
    return (char)v5;
  v7 = 0;
  v8 = ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v5->vfptr[81].__vecDelDtor)(v5) == 4;
  if ( (v4->VarsSet >> 14) & 1 )
  {
    v9 = v4->EdgeAAMode;
    v10 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    Scaleform::Render::TreeNode::SetEdgeAAMode(v10, v9);
  }
  if ( (LOBYTE(v4->VarsSet) >> 5) & 1 )
  {
    a4 = v4->Alpha;
    result = *(Scaleform::Render::Point<float> *)&v4->Alpha;
    if ( (*(_QWORD *)&result & 0x7FF0000000000000i64) != 9218868437227405312i64
      || !(*(_QWORD *)&result & 0xFFFFFFFFFFFFFi64) )
    {
      v11 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
      *(_OWORD *)&v65.M[0][0] = *(_OWORD *)&v11->M[0][0];
      a4 = v4->Alpha * 0.01;
      *(_OWORD *)&v65.M[1][0] = *(_OWORD *)&v11->M[1][0];
      v65.M[0][3] = *(float *)&a4;
      Scaleform::GFx::DisplayObjectBase::SetCxform((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr, &v65);
      v6->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, 0);
    }
  }
  if ( (LOBYTE(v4->VarsSet) >> 6) & 1 )
    v6->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, v4->Visible);
  v12 = -4503599627370496i64;
  if ( SLOBYTE(v4->VarsSet) < 0 )
  {
    v13 = v4->Z;
    result = *(Scaleform::Render::Point<float> *)&v4->Z;
    if ( (*(_QWORD *)&result & 0x7FF0000000000000i64) == 9218868437227405312i64
      && *(_QWORD *)&result & 0xFFFFFFFFFFFFFi64 )
    {
      v13 = 0.0;
    }
    *(double *)&result = v13;
    if ( v13 == -1.797693134862316e308/*-Inf*/ || (*(double *)&result = v13, v13 == 1.797693134862316e308/*+Inf*/) )
      v13 = 0.0;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    v14 = v6->pGeomData;
    v12 = -4503599627370496i64;
    if ( v13 != v14->Z )
    {
      v14->Z = v13;
      v7 = 1;
    }
  }
  if ( (v4->VarsSet >> 10) & 1 )
  {
    v15 = v4->ZScale;
    result = *(Scaleform::Render::Point<float> *)&v4->ZScale;
    if ( (*(_QWORD *)&result & 0x7FF0000000000000i64) == 9218868437227405312i64
      && *(_QWORD *)&result & 0xFFFFFFFFFFFFFi64
      || (*(double *)&result = v15, v15 == -1.797693134862316e308/*-Inf*/)
      || (*(double *)&result = v15, v15 == 1.797693134862316e308/*+Inf*/) )
    {
      v15 = DOUBLE_100_0;
    }
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    v16 = v6->pGeomData;
    if ( v15 != v16->ZScale )
    {
      v16->ZScale = v15;
      v7 = 1;
    }
  }
  if ( v4->VarsSet & 0x100 )
  {
    v17 = v4->XRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    v18 = v6->pGeomData;
    if ( v17 != v18->XRotation )
    {
      a4 = fmod(v17, 360.0);
      if ( a4 <= 180.0 )
      {
        if ( a4 < -180.0 )
          a4 = a4 + 360.0;
      }
      else
      {
        a4 = a4 + -360.0;
      }
      v18->XRotation = a4;
      v7 = 1;
    }
  }
  if ( (v4->VarsSet >> 9) & 1 )
  {
    v19 = v4->YRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    v20 = v6->pGeomData;
    if ( v19 != v20->YRotation )
    {
      a4 = fmod(v19, 360.0);
      if ( a4 <= 180.0 )
      {
        if ( a4 < -180.0 )
          a4 = a4 + 360.0;
        v20->YRotation = a4;
      }
      else
      {
        a4 = a4 + -360.0;
        v20->YRotation = a4;
      }
      goto LABEL_42;
    }
  }
  if ( v7 )
LABEL_42:
    ((void (__fastcall *)(Scaleform::GFx::TextField *))v6->vfptr[13].__vecDelDtor)(v6);
  v21 = v4->VarsSet;
  if ( (v21 >> 11) & 1 )
  {
    v22 = v4->FOV;
    v6->vfptr[40].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, v12);
    if ( v22 != a4 )
    {
      v23 = v6->vfptr;
      fmod(v22, 180.0);
      ((void (__fastcall *)(Scaleform::GFx::TextField *))v23[39].__vecDelDtor)(v6);
    }
  }
  else
  {
    if ( (v21 >> 12) & 1 )
      v6->vfptr[7].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, (unsigned int)&v4->ProjectionMatrix3D);
    if ( (v4->VarsSet >> 13) & 1 )
      v6->vfptr[10].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, (unsigned int)&v4->ViewMatrix3D);
  }
  if ( v4->VarsSet & 0x1F )
  {
    if ( v8 )
    {
      v6->Flags |= 0x2000u;
      Scaleform::GFx::TextField::SetDirtyFlag(v6);
    }
    v6->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, 0);
    v24 = v6->pGeomData;
    v25 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v6->vfptr[2].__vecDelDtor)(v6);
    *(_OWORD *)&v64.M[0][0] = *(_OWORD *)v25;
    *(_QWORD *)&v64.M[1][0] = *(_QWORD *)(v25 + 16);
    v26 = (__m128d)*(unsigned int *)(v25 + 24);
    *(_QWORD *)&v64.M[1][2] = *(_QWORD *)(v25 + 24);
    if ( v8 && v4->VarsSet & 3 )
    {
      Scaleform::GFx::TextField::TransformToTextRectSpace(v6, &result, v4);
      v27 = _mm_cvtps_pd((__m128)LODWORD(result.x));
      v28 = _mm_cvtps_pd((__m128)LODWORD(result.y));
    }
    else
    {
      if ( v4->VarsSet & 1 )
        v27 = (__m128d)*(unsigned __int64 *)&v4->X;
      else
        v27 = (__m128d)v61;
      if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
        v28 = (__m128d)*(unsigned __int64 *)&v4->Y;
      else
        v28 = (__m128d)v63;
    }
    v29 = v4->VarsSet;
    if ( v29 & 0x1C )
    {
      v30 = (__m128)LODWORD(v24->OrigMatrix.M[0][0]);
      v31 = v24->OrigMatrix.M[1][0];
      v32 = (__m128)LODWORD(v24->OrigMatrix.M[0][1]);
      v33 = v24->OrigMatrix.M[1][1];
      v65.M[0][2] = v24->OrigMatrix.M[0][2];
      v34 = v24->OrigMatrix.M[1][2];
      v65.M[0][3] = v64.M[0][3];
      v65.M[1][3] = v64.M[1][3];
      *(_QWORD *)&v65.M[0][0] = __PAIR__(v32.m128_u32[0], v30.m128_u32[0]);
      v65.M[1][0] = v31;
      *(_QWORD *)&v65.M[1][1] = __PAIR__(LODWORD(v34), LODWORD(v33));
      v35 = atan2(v31, v30.m128_f32[0]);
      v36 = v31;
      v37 = v24->Rotation;
      v38 = _mm_cvtps_pd(v30);
      v38.m128d_f64[0] = v38.m128d_f64[0] * v38.m128d_f64[0] + v36 * v36;
      v62 = v35;
      v39 = v24->YScale * 0.01;
      v40 = v33;
      v41 = _mm_cvtps_pd(v32);
      v42 = v24->XScale * 0.01;
      result = (Scaleform::Render::Point<float>)*(_OWORD *)&_mm_sqrt_pd(v38);
      v41.m128d_f64[0] = v41.m128d_f64[0] * v41.m128d_f64[0] + v40 * v40;
      *(_QWORD *)&v67 = (unsigned __int128)_mm_sqrt_pd(v41);
      v43 = v37 * 3.141592653589793 * 0.005555555555555556;
      if ( ((unsigned __int8)v29 >> 2) & 1 )
        v44 = v4->Rotation;
      else
        v44 = Scaleform::GFx::NumberUtil::NaN();
      v68 = v44;
      if ( (*(_QWORD *)&v44 & 0x7FF0000000000000i64) != 9218868437227405312i64
        || !(*(_QWORD *)&v44 & 0xFFFFFFFFFFFFFi64) )
      {
        v45 = fmod(v44, 360.0);
        v46 = v45;
        if ( v45 <= 180.0 )
        {
          if ( v45 < -180.0 )
            v46 = v45 + 360.0;
        }
        else
        {
          v46 = v45 + -360.0;
        }
        v24->Rotation = v46;
        v43 = v46 * 3.141592653589793 * 0.005555555555555556;
      }
      if ( (LOBYTE(v4->VarsSet) >> 3) & 1 )
      {
        v47 = DOUBLE_0_01;
        v48 = v4->XScale * 0.01;
      }
      else
      {
        v48 = Scaleform::GFx::NumberUtil::NaN();
        v47 = DOUBLE_0_01;
      }
      v49 = *(double *)&result;
      if ( v48 != v42 )
      {
        v68 = v48;
        if ( (*(_QWORD *)&v48 & 0x7FF0000000000000i64) != 9218868437227405312i64 )
        {
          v24->XScale = v4->XScale;
          if ( v49 == 0.0 || v48 > 1.0e16 )
          {
            v48 = 0.0;
            v49 = DOUBLE_1_0;
          }
          v42 = v48;
        }
      }
      if ( (LOBYTE(v4->VarsSet) >> 4) & 1 )
        v50 = v4->YScale * v47;
      else
        v50 = Scaleform::GFx::NumberUtil::NaN();
      v51 = v67;
      if ( v50 != v39 )
      {
        *(double *)&result = v50;
        if ( (*(_QWORD *)&v50 & 0x7FF0000000000000i64) != 9218868437227405312i64 )
        {
          v24->YScale = v4->YScale;
          if ( v51 == 0.0 || v50 > 1.0e16 )
          {
            v50 = 0.0;
            v51 = DOUBLE_1_0;
          }
          v39 = v50;
        }
      }
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        (Scaleform::Render::Matrix2x4<float> *)&v65,
        v42 / v49,
        v39 / v51,
        v43 - v62);
      v64 = v65;
      v26.m128d_f64[1] = *(long double *)&v65.M[1][2];
    }
    if ( v4->VarsSet & 1 )
      v26 = v27;
    else
      v26.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0];
    if ( (*(_QWORD *)&v26.m128d_f64[0] & 0x7FF0000000000000i64) != 9218868437227405312i64
      || !(*(_QWORD *)&v26.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) )
    {
      result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0];
      if ( *(_QWORD *)&v26.m128d_f64[0] == -4503599627370496i64
        || (result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0],
            *(_QWORD *)&v26.m128d_f64[0] == 9218868437227405312i64) )
      {
        v26 = 0i64;
      }
      v26.m128d_f64[0] = v26.m128d_f64[0] * 20.0;
      v52 = (unsigned int)(signed int)v26.m128d_f64[0];
      if ( v52 != 0x8000000000000000i64 && (double)(signed int)v52 != v26.m128d_f64[0] )
        v26.m128d_f64[0] = (double)(signed int)(v52 - (_mm_movemask_pd(_mm_unpckl_pd(v26, v26)) & 1));
      v24->X = (signed int)v26.m128d_f64[0];
      v26 = (__m128d)COERCE_UNSIGNED_INT((float)(signed int)v26.m128d_f64[0]);
      v64.M[0][3] = *(float *)v26.m128d_f64;
    }
    if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
      v26 = v28;
    else
      v26.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0];
    if ( (*(_QWORD *)&v26.m128d_f64[0] & 0x7FF0000000000000i64) != 9218868437227405312i64
      || !(*(_QWORD *)&v26.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) )
    {
      result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0];
      if ( *(_QWORD *)&v26.m128d_f64[0] == -4503599627370496i64
        || (result = *(Scaleform::Render::Point<float> *)&v26.m128d_f64[0],
            *(_QWORD *)&v26.m128d_f64[0] == 9218868437227405312i64) )
      {
        v26 = 0i64;
      }
      v26.m128d_f64[0] = v26.m128d_f64[0] * 20.0;
      v53 = (unsigned int)(signed int)v26.m128d_f64[0];
      if ( v53 != 0x8000000000000000i64 && (double)(signed int)v53 != v26.m128d_f64[0] )
        v26.m128d_f64[0] = (double)(signed int)(v53 - (_mm_movemask_pd(_mm_unpckl_pd(v26, v26)) & 1));
      v24->Y = (signed int)v26.m128d_f64[0];
      v64.M[1][3] = (float)(signed int)v26.m128d_f64[0];
    }
    if ( v64.M[0][0] >= -3.4028235e38
      && v64.M[0][0] <= 3.4028235e38
      && v64.M[0][1] >= -3.4028235e38
      && v64.M[0][1] <= 3.4028235e38
      && v64.M[0][2] >= -3.4028235e38
      && v64.M[0][2] <= 3.4028235e38
      && v64.M[0][3] >= -3.4028235e38
      && v64.M[0][3] <= 3.4028235e38
      && v64.M[1][0] >= -3.4028235e38
      && v64.M[1][0] <= 3.4028235e38
      && v64.M[1][1] >= -3.4028235e38
      && v64.M[1][1] <= 3.4028235e38
      && v64.M[1][2] >= -3.4028235e38
      && v64.M[1][2] <= 3.4028235e38
      && v64.M[1][3] >= -3.4028235e38
      && v64.M[1][3] <= 3.4028235e38 )
    {
      v54 = Scaleform::GFx::DisplayObjectBase::Has3D((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr) == 0;
      v55 = v6->vfptr;
      if ( v54 )
        v55[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, (unsigned int)&v64);
      else
        ((void (__fastcall *)(Scaleform::GFx::TextField *))v55[13].__vecDelDtor)(v6);
    }
    if ( v8 )
    {
      if ( v4->VarsSet & 1 )
      {
        v56 = v27.m128d_f64[0] * 20.0;
        if ( v56 <= 0.0 )
          v57 = v56 - 0.5;
        else
          v57 = v56 + 0.5;
        v24->X = (signed int)v57;
      }
      if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
      {
        v58 = v28.m128d_f64[0] * 20.0;
        if ( v58 <= 0.0 )
          v59 = v58 - 0.5;
        else
          v59 = v58 + 0.5;
        v24->Y = (signed int)v59;
      }
    }
  }
  LOBYTE(v5) = 1;
  return (char)v5;
}

// File Line: 1188
// RVA: 0x71C6E0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetText(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *ptext, bool reqHtml)
{
  bool v4; // di
  const char *v5; // rbp
  void *v6; // r14
  Scaleform::GFx::AS2ValueObjectInterface *v7; // rsi
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  __int64 v11; // rbx
  unsigned int v12; // eax
  char v13; // cl
  unsigned int v14; // eax
  char v16; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+48h] [rbp-30h]
  unsigned int v18; // [rsp+50h] [rbp-28h]
  const char *v19; // [rsp+58h] [rbp-20h]

  v4 = reqHtml;
  v5 = ptext;
  v6 = pdata;
  v7 = this;
  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( !v8 )
    return (char)v8;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[81].__vecDelDtor)(v8) == 4 )
  {
    v12 = v9->Flags;
    v13 = (v9->Flags >> 1) & 1;
    if ( v4 )
    {
      if ( !v13 )
      {
        v14 = v12 | 2;
LABEL_13:
        v9->Flags = v14;
        goto LABEL_14;
      }
    }
    else if ( v13 )
    {
      v14 = v12 & 0xFFFFFFFD;
      goto LABEL_13;
    }
LABEL_14:
    Scaleform::GFx::TextField::SetTextValue(v9, v5, v4, 1);
    LOBYTE(v8) = 1;
    return (char)v8;
  }
  v17 = 0i64;
  v18 = 6;
  v19 = v5;
  v10 = "text";
  if ( v4 )
    v10 = "htmlText";
  v11 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, void *, const char *, char *, char))&v7->vfptr->gap8[32])(
          v7,
          v6,
          v10,
          &v16,
          1);
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
    v17 = 0i64;
  }
  v18 = 0;
  LOBYTE(v8) = v11;
  return (char)v8;
}

// File Line: 1205
// RVA: 0x71C810
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetText(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const wchar_t *ptext, bool reqHtml)
{
  bool v4; // di
  const wchar_t *v5; // rsi
  void *v6; // rbp
  Scaleform::GFx::AS2ValueObjectInterface *v7; // r14
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // ST20_1
  __int64 v12; // rbx
  char v14; // [rsp+38h] [rbp-40h]
  __int64 v15; // [rsp+48h] [rbp-30h]
  unsigned int v16; // [rsp+50h] [rbp-28h]
  const wchar_t *v17; // [rsp+58h] [rbp-20h]

  v4 = reqHtml;
  v5 = ptext;
  v6 = pdata;
  v7 = this;
  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( v8 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[81].__vecDelDtor)(v8) == 4 )
    {
      Scaleform::GFx::TextField::SetText(v9, v5, v4);
      LOBYTE(v8) = 1;
    }
    else
    {
      v15 = 0i64;
      v16 = 7;
      v17 = v5;
      v10 = "text";
      if ( v4 )
        v10 = "htmlText";
      v11 = 1;
      v12 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, void *, const char *, char *, char))&v7->vfptr->gap8[32])(
              v7,
              v6,
              v10,
              &v14,
              v11);
      if ( (v16 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const wchar_t *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
        v15 = 0i64;
      }
      v16 = 0;
      LOBYTE(v8) = v12;
    }
  }
  return (char)v8;
}

// File Line: 1222
// RVA: 0x6F6680
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetText(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pval, bool reqHtml)
{
  bool v4; // bp
  Scaleform::GFx::Value *v5; // r14
  void *v6; // rdi
  Scaleform::GFx::AS2ValueObjectInterface *v7; // rbx
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rsi
  const char *v10; // r8
  char v11; // ST20_1
  Scaleform::GFx::AS2::MovieRoot *v12; // rdi
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS2::Value value; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v4 = reqHtml;
  v5 = pval;
  v6 = pdata;
  v7 = this;
  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( v8 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[81].__vecDelDtor)(v8) == 4 )
    {
      v12 = (Scaleform::GFx::AS2::MovieRoot *)v7->pMovieRoot->pASMovieRoot.pObject;
      v13 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v12->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v12->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
      Scaleform::GFx::TextField::GetText(v9, &result, v4);
      value.T.Type = 5;
      value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
      ++value.V.pStringNode->RefCount;
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v12, v13, &value, v5);
      Scaleform::GFx::AS2::Value::DropRefs(&value);
      v14 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      LOBYTE(v8) = 1;
    }
    else
    {
      v10 = "text";
      if ( v4 )
        v10 = "htmlText";
      v11 = 1;
      LOBYTE(v8) = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, void *, const char *, Scaleform::GFx::Value *, char))&v7->vfptr->gap8[24])(
                     v7,
                     v6,
                     v10,
                     v5,
                     v11);
    }
  }
  return (char)v8;
}

// File Line: 1244
// RVA: 0x6FB030
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, const char *frame, bool stop)
{
  bool v4; // si
  const char *v5; // rdi
  Scaleform::GFx::DisplayObject *v6; // rax
  __int64 v7; // r9
  Scaleform::GFx::DisplayObject *v8; // rbx
  unsigned int v10; // [rsp+30h] [rbp+8h]

  v4 = stop;
  v5 = frame;
  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v8 = v6;
  if ( !v6 )
    return 0;
  if ( !((v6->Flags >> 10) & 1) )
    return 0;
  LOBYTE(v7) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, const char *, unsigned int *, __int64))v6->vfptr[108].__vecDelDtor)(
          v6,
          v5,
          &v10,
          v7) )
    return 0;
  v8->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v10);
  v8->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v4 != 0);
  return 1;
}

// File Line: 1263
// RVA: 0x6FAFA0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, unsigned int frame, bool stop)
{
  bool v4; // di
  unsigned int v5; // esi
  Scaleform::GFx::DisplayObject *v6; // rax
  Scaleform::GFx::DisplayObject *v7; // rbx

  v4 = stop;
  v5 = frame;
  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v7 = v6;
  if ( !v6 || !((v6->Flags >> 10) & 1) )
    return 0;
  v6->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, v5 - 1);
  v7->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, v4 != 0);
  return 1;
}

// File Line: 1278
// RVA: 0x6EF100
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetCxform(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Cxform *pcx)
{
  Scaleform::Render::Cxform *v3; // rdi
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObjectBase *v5; // rbx
  char result; // al
  Scaleform::Render::Cxform *v7; // rax
  __int128 v8; // xmm1

  v3 = pcx;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v5 = (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr;
  if ( !v4
    || ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[81].__vecDelDtor)(v4) != 4
    && !((v5->Flags >> 10) & 1) )
  {
    return 0;
  }
  v7 = Scaleform::GFx::DisplayObjectBase::GetCxform(v5);
  *(_OWORD *)&v3->M[0][0] = *(_OWORD *)&v7->M[0][0];
  v8 = *(_OWORD *)&v7->M[1][0];
  result = 1;
  *(_OWORD *)&v3->M[1][0] = v8;
  return result;
}

// File Line: 1292
// RVA: 0x713750
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetCxform(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::Cxform *v3; // rdi
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObjectBase *v5; // rbx

  v3 = cx;
  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v5 = (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr;
  if ( !v4
    || ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[81].__vecDelDtor)(v4) != 4
    && !((v5->Flags >> 10) & 1) )
  {
    return 0;
  }
  Scaleform::GFx::DisplayObjectBase::SetCxform(v5, v3);
  v5->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, 0);
  return 1;
}

// File Line: 1309
// RVA: 0x6DF9D0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::CreateEmptyMovieClip(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pmc, const char *instanceName)
{
  const char *v4; // r15
  Scaleform::GFx::Value *v5; // r14
  Scaleform::GFx::AS2ValueObjectInterface *v6; // rdi
  Scaleform::GFx::DisplayObject *v7; // rax
  Scaleform::GFx::DisplayObject *v8; // rbx
  Scaleform::GFx::AS2::MovieRoot *v9; // rdi
  Scaleform::GFx::AS2::Environment *v10; // rsi
  int v11; // eax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v13; // r10
  __int64 v14; // rax
  Scaleform::GFx::DisplayObject *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rax
  char v19; // di
  Scaleform::Render::Cxform v21; // [rsp+28h] [rbp-71h]
  Scaleform::Render::Matrix2x4<float> v22; // [rsp+48h] [rbp-51h]
  Scaleform::Render::RenderBuffer *v23; // [rsp+68h] [rbp-31h]
  int v24; // [rsp+70h] [rbp-29h]
  int v25; // [rsp+74h] [rbp-25h]
  int v26; // [rsp+78h] [rbp-21h]
  __int64 v27; // [rsp+80h] [rbp-19h]
  char v28[6]; // [rsp+88h] [rbp-11h]
  Scaleform::GFx::AS2::Value value; // [rsp+98h] [rbp-1h]
  __int64 v30; // [rsp+B8h] [rbp+1Fh]
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+5Fh]
  __int64 v32; // [rsp+100h] [rbp+67h]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  v30 = -2i64;
  v4 = instanceName;
  v5 = pmc;
  v6 = this;
  v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v8 = v7;
  if ( !v7 || !((v7->Flags >> 10) & 1) )
    return 0;
  v9 = (Scaleform::GFx::AS2::MovieRoot *)v6->pMovieRoot->pASMovieRoot.pObject;
  v10 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v9->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v9->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  v11 = (signed int)retaddr;
  if ( (signed int)retaddr < 0 )
  {
    v11 = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v8[1].pRenNode) - 0x3FFF;
    if ( v11 < 0 )
      v11 = 0;
  }
  v21 = Scaleform::Render::Cxform::Identity;
  v22 = Scaleform::Render::Matrix2x4<float>::Identity;
  v23 = 0i64;
  v24 = 0;
  *(_DWORD *)&v28[2] = 16777220;
  *(_DWORD *)v28 = 786432;
  v25 = v11 + 0x4000;
  v26 = 65537;
  v27 = 0i64;
  if ( (unsigned int)(v11 + 0x4000) > 0x7EFFFFFD )
  {
    v19 = 0;
  }
  else
  {
    v12 = Scaleform::GFx::AS2::Environment::CreateString(v10, &result, v4);
    v13 = v8->vfptr;
    *(_OWORD *)&v21.M[1][0] = 0ui64;
    LODWORD(v21.M[0][2]) = 1;
    v21.M[0][0] = -6.8056469e38/*NaN*/;
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, __int64, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64))v13[118].__vecDelDtor)(
            v8,
            &v21,
            v12,
            0i64,
            0i64,
            *(_QWORD *)&v21.M[0][0],
            *(_QWORD *)&v21.M[0][2],
            0i64,
            0i64,
            *(_QWORD *)&v22.M[0][0],
            *(_QWORD *)&v22.M[0][2],
            *(_QWORD *)&v22.M[1][0],
            *(_QWORD *)&v22.M[1][2]);
    v15 = (Scaleform::GFx::DisplayObject *)v14;
    if ( v14 )
      ++*(_DWORD *)(v14 + 8);
    v32 = v14;
    v16 = result.pNode;
    v17 = result.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( v15 )
    {
      v15->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v15->vfptr, 0);
      value.T.Type = 7;
      v18 = (Scaleform::GFx::ASStringNode *)v15->pNameHandle.pObject;
      if ( !v18 )
        v18 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v15);
      value.V.pStringNode = v18;
      if ( v18 )
        ++LODWORD(v18->pData);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v9, v10, &value, v5);
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    }
    v19 = 1;
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v15->vfptr);
  }
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  return v19;
}

// File Line: 1354
// RVA: 0x6DAE60
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::AttachMovie(Scaleform::GFx::AS2ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pmc, const char *symbolName, const char *instanceName, int depth, Scaleform::GFx::MemberValueSet *initArgs)
{
  const char *v7; // rdi
  Scaleform::GFx::AS2ValueObjectInterface *v8; // rbx
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::DisplayObject *v10; // rsi
  Scaleform::GFx::AS2::MovieRoot *v11; // r12
  Scaleform::GFx::AS2::Environment *v12; // r13
  unsigned int v13; // er14
  Scaleform::GFx::MovieImpl *v14; // rbx
  Scaleform::GFx::MovieDefImpl *v15; // rax
  bool v16; // bl
  Scaleform::GFx::CharacterHandle *v17; // rax
  const char *v18; // rdx
  int v19; // eax
  char v20; // si
  Scaleform::GFx::Resource *v21; // rdx
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  Scaleform::GFx::AS2::Object *v25; // rbx
  Scaleform::GFx::MemberValueSet *v26; // r15
  __int64 v27; // rdi
  Scaleform::GFx::AS2::MovieRoot *v28; // rsi
  signed __int64 v29; // rdi
  Scaleform::GFx::ASStringNode *v30; // rcx
  bool v31; // zf
  signed __int64 v32; // rdi
  Scaleform::GFx::ASString *v33; // rax
  __int64 v34; // rax
  Scaleform::GFx::DisplayObject *v35; // rdi
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rax
  unsigned int v38; // eax
  Scaleform::GFx::CharacterHandle *v39; // rax
  __int64 argsTopOff; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS2::MovieRoot *v43; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::ASString v45; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::DisplayObject *v46; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::Resource *v47; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::Resource *v48; // [rsp+88h] [rbp-78h]
  __int64 v49; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS2::Object *v50; // [rsp+98h] [rbp-68h]
  Scaleform::Render::Cxform v51; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::Matrix2x4<float> v52; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::RenderBuffer *v53; // [rsp+E0h] [rbp-20h]
  int v54; // [rsp+E8h] [rbp-18h]
  int v55; // [rsp+ECh] [rbp-14h]
  int v56; // [rsp+F0h] [rbp-10h]
  __int64 v57; // [rsp+F8h] [rbp-8h]
  char v58[6]; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+110h] [rbp+10h]
  __int64 v60; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS2::Value value; // [rsp+138h] [rbp+38h]
  __int64 v62; // [rsp+158h] [rbp+58h]
  char v63; // [rsp+1A0h] [rbp+A0h]
  Scaleform::String symbol; // [rsp+1A8h] [rbp+A8h]
  Scaleform::GFx::Value *v65; // [rsp+1B0h] [rbp+B0h]

  v65 = pmc;
  v60 = -2i64;
  v7 = symbolName;
  v8 = this;
  v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v10 = v9;
  v46 = v9;
  if ( !v9 || !((v9->Flags >> 10) & 1) )
    return 0;
  v11 = (Scaleform::GFx::AS2::MovieRoot *)v8->pMovieRoot->pASMovieRoot.pObject;
  v43 = v11;
  v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)v11->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  v13 = 0;
  presBindData.pResource.pObject = 0i64;
  presBindData.pBinding = 0i64;
  Scaleform::String::String(&symbol, v7);
  v14 = v10->pASRoot->pMovieImpl;
  v15 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v10->vfptr[66].__vecDelDtor)(v10);
  v16 = Scaleform::GFx::MovieImpl::FindExportedResource(v14, v15, &presBindData, &symbol) == 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v16 )
  {
    v17 = v10->pNameHandle.pObject;
    if ( !v17 )
      v17 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
    v18 = "%s.attachMovie() failed - export name \"%s\" is not found.";
  }
  else
  {
    v19 = ((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)();
    if ( _bittest(&v19, 0xFu) )
    {
      v48 = 0i64;
      v49 = 0i64;
      v21 = presBindData.pResource.pObject;
      v47 = presBindData.pResource.pObject;
      v48 = presBindData.pBinding->pOwnerDefRes;
      v22 = depth;
      if ( depth < 0 )
      {
        v22 = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v10[1].pRenNode)
            - 0x3FFF;
        if ( v22 < 0 )
          v22 = 0;
        v21 = v47;
      }
      v23 = (int)v21[1].vfptr;
      v51 = Scaleform::Render::Cxform::Identity;
      v52 = Scaleform::Render::Matrix2x4<float>::Identity;
      v53 = 0i64;
      v54 = 0;
      *(_DWORD *)&v58[2] = 16777220;
      *(_DWORD *)v58 = 786432;
      v55 = v22 + 0x4000;
      v56 = v23;
      v57 = 0i64;
      v24 = v22 + 0x4000;
      if ( (unsigned int)(v22 + 0x4000) > 0x7EFFFFFD )
      {
        v39 = v10->pNameHandle.pObject;
        if ( !v39 )
        {
          v39 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
          v24 = v55;
        }
        LODWORD(argsTopOff) = v24;
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v10->vfptr,
          "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
          v39->NamePath.pNode->pData,
          v7,
          argsTopOff);
        v20 = 0;
      }
      else
      {
        v25 = 0i64;
        v50 = 0i64;
        v26 = initArgs;
        if ( !initArgs )
          goto LABEL_57;
        v25 = Scaleform::GFx::AS2::Environment::OperatorNew(
                v12,
                v12->StringContext.pContext->pGlobal.pObject,
                (Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8],
                0,
                -1);
        v50 = v25;
        if ( v26->Data.Size )
        {
          v27 = 0i64;
          v28 = v43;
          do
          {
            v29 = (signed __int64)&v26->Data.Data[v27];
            Scaleform::GFx::AS2::Environment::CreateString(v12, &result, (Scaleform::String *)v29);
            pdestVal.T.Type = 0;
            Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v28, (Scaleform::GFx::Value *)(v29 + 8), &pdestVal);
            v63 = 0;
            v25->vfptr->SetMember(
              (Scaleform::GFx::AS2::ObjectInterface *)&v25->vfptr,
              v12,
              &result,
              &pdestVal,
              (Scaleform::GFx::AS2::PropFlags *)&v63);
            if ( pdestVal.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
            v30 = result.pNode;
            v31 = result.pNode->RefCount == 1;
            --v30->RefCount;
            if ( v31 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v30);
            v27 = ++v13;
          }
          while ( v13 < v26->Data.Size );
          v10 = v46;
          v11 = v43;
        }
        v32 = (signed __int64)&v25->vfptr;
        if ( !v25 )
LABEL_57:
          v32 = 0i64;
        v33 = Scaleform::GFx::AS2::Environment::CreateString(v12, &v45, instanceName);
        v34 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, signed __int64, signed int, signed int, Scaleform::GFx::Resource **, _QWORD))v10->vfptr[118].__vecDelDtor)(
                v10,
                &v51,
                v33,
                0i64,
                v32,
                -1,
                1,
                &v47,
                0i64);
        v35 = (Scaleform::GFx::DisplayObject *)v34;
        if ( v34 )
          ++*(_DWORD *)(v34 + 8);
        v62 = v34;
        v36 = v45.pNode;
        v31 = v45.pNode->RefCount == 1;
        --v36->RefCount;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        if ( v35 )
        {
          v35->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v35->vfptr, 0);
          if ( Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v10->vfptr) >= 6 )
          {
            value.T.Type = 7;
            v37 = (Scaleform::GFx::ASStringNode *)v35->pNameHandle.pObject;
            if ( !v37 )
              v37 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v35);
            value.V.pStringNode = v37;
            if ( v37 )
              ++LODWORD(v37->pData);
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v11, v12, &value, v65);
            Scaleform::GFx::AS2::Value::DropRefs(&value);
          }
        }
        v20 = 1;
        if ( v35 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v35->vfptr);
        if ( v25 )
        {
          v38 = v25->RefCount;
          if ( v38 & 0x3FFFFFF )
          {
            v25->RefCount = v38 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
          }
        }
      }
      if ( v53 )
        Scaleform::RefCountImpl::Release(v53);
      goto LABEL_51;
    }
    v17 = v10->pNameHandle.pObject;
    if ( !v17 )
      v17 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
    v18 = "%s.attachMovie() failed - \"%s\" is not a movieclip.";
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
    (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v10->vfptr,
    v18,
    v17->NamePath.pNode->pData,
    v7);
  v20 = 0;
LABEL_51:
  if ( presBindData.pResource.pObject )
    Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
  return v20;
}

// File Line: 1439
// RVA: 0x7220D0
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ToString(Scaleform::GFx::AS2ValueObjectInterface *this, Scaleform::String *pstr, Scaleform::GFx::Value *thisVal)
{
  Scaleform::GFx::Value *v3; // rsi
  Scaleform::String *v4; // rbp
  Scaleform::GFx::AS2::MovieRoot *v5; // rbx
  signed __int64 v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rdi
  const char ***v8; // rax
  Scaleform::String *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-40h]
  Scaleform::String v13; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h]

  v3 = thisVal;
  v4 = pstr;
  v5 = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (signed __int64)v5->pMovieImpl->pMainMovie + 4 * (unsigned __int8)v5->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v6 + 240i64))(v6);
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v5, v3, &pdestVal);
  v8 = (const char ***)Scaleform::GFx::AS2::Value::ToString(&pdestVal, &result, v7, -1);
  Scaleform::String::String(&v13, **v8);
  Scaleform::String::operator=(v4, v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
}

// File Line: 1517
// RVA: 0x723410
Scaleform::GFx::AS2::MovieRoot::Value2ASValue

// File Line: 1582
// RVA: 0x6D7420
void __fastcall Scaleform::GFx::AS2::MovieRoot::ASValue2Value(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *value, Scaleform::GFx::Value *pdestVal)
{
  Scaleform::GFx::Value *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rbp
  Scaleform::GFx::AS2::Environment *v6; // r14
  Scaleform::GFx::AS2::MovieRoot *v7; // r13
  Scaleform::GFx::Value::ValueType v8; // edx
  Scaleform::Render::RenderBuffer *v9; // rsi
  signed int v10; // er15
  __int32 v11; // edi
  __int64 v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rbp
  __int64 v16; // rdi
  Scaleform::GFx::MovieImpl::WideStringStorage *v17; // rax
  Scaleform::Render::RenderBuffer *v18; // rax
  Scaleform::GFx::AS2::ObjectInterface *v19; // rdi
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::CharacterHandle *v21; // r8
  Scaleform::GFx::AS2::ObjectInterface *v22; // rax
  Scaleform::GFx::InteractiveObject *v23; // rax
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h]

  v4 = pdestVal;
  v5 = value;
  v6 = penv;
  v7 = this;
  v8 = pdestVal->Type;
  v9 = 0i64;
  v10 = 8;
  if ( (v8 & 0x80u) == 0 )
  {
    v12 = (unsigned __int8)value->T.Type;
    if ( (unsigned int)v12 <= 8 )
      JUMPOUT(__CS__, (unsigned int)dword_1406D7738[v12] + 5368709120i64);
    v11 = 6;
  }
  else
  {
    v11 = pdestVal->Type & 0xF;
  }
  if ( ((unsigned int)v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal->pObjectInterface->vfptr->gap8[8])(
      pdestVal->pObjectInterface,
      pdestVal,
      *(_QWORD *)&pdestVal->mValue.NValue);
    v4->pObjectInterface = 0i64;
  }
  switch ( v11 )
  {
    case 0:
    case 1:
      v4->Type = v11;
      return;
    case 2:
      v4->Type = 2;
      v4->mValue.BValue = Scaleform::GFx::AS2::Value::ToBool(v5, v6);
      return;
    case 3:
      v4->Type = 3;
      v4->mValue.IValue = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v6);
      return;
    case 4:
      v4->Type = 4;
      v4->mValue.IValue = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v6);
      return;
    case 5:
      v4->Type = 5;
      v4->mValue.NValue = Scaleform::GFx::AS2::Value::ToNumber(v5, v6);
      return;
    case 6:
      Scaleform::GFx::AS2::Value::ToString(v5, &result, v6, -1);
      v4->Type = 70;
      v4->mValue = (Scaleform::GFx::Value::ValueUnion)result.pNode;
      v4->pObjectInterface = v7->pMovieImpl->pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *))v7->pMovieImpl->pObjectInterface->vfptr->gap8)(
        v7->pMovieImpl->pObjectInterface,
        v4);
      goto LABEL_15;
    case 7:
      Scaleform::GFx::AS2::Value::ToString(v5, &result, v6, -1);
      v15 = result.pNode;
      v16 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode) + 1;
      v17 = (Scaleform::GFx::MovieImpl::WideStringStorage *)v7->pMovieImpl->pHeap->vfptr->Alloc(
                                                              v7->pMovieImpl->pHeap,
                                                              2 * v16 + 31,
                                                              0i64);
      v4->Type = 71;
      if ( v17 )
      {
        Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(v17, v15, (unsigned int)v16);
        v9 = v18;
      }
      *(_QWORD *)&v4->mValue.NValue = (char *)v9 + 24;
      v4->pObjectInterface = v7->pMovieImpl->pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *))v7->pMovieImpl->pObjectInterface->vfptr->gap8)(
        v7->pMovieImpl->pObjectInterface,
        v4);
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
LABEL_15:
      v13 = result.pNode;
      v14 = result.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      return;
    case 8:
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, v6);
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v19->vfptr->gap8[8])(v19) - 6 <= 0x26 )
      {
        v20 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(v19);
        if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v20->vfptr->gap8[8])(&v20->vfptr) == 7 )
          v10 = 9;
      }
      v4->Type = v10 | 0x40;
      *(_QWORD *)&v4->mValue.NValue = v19;
      v21 = (Scaleform::GFx::CharacterHandle *)v19;
      goto LABEL_31;
    case 10:
      v22 = Scaleform::GFx::AS2::Value::ToObjectInterface(v5, v6);
      if ( v22 )
      {
        v23 = Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v22);
        v4->Type = 74;
        v21 = v23->pNameHandle.pObject;
        if ( !v21 )
          v21 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v23->vfptr);
        *(_QWORD *)&v4->mValue.NValue = v21;
LABEL_31:
        v4->pObjectInterface = v7->pMovieImpl->pObjectInterface;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::CharacterHandle *))v7->pMovieImpl->pObjectInterface->vfptr->gap8)(
          v7->pMovieImpl->pObjectInterface,
          v4,
          v21);
      }
      else
      {
        v4->Type = 0;
      }
      break;
    default:
      return;
  }
}

// File Line: 1699
// RVA: 0x6E0F10
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateObjectInterface(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::MovieImpl *movie)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  Scaleform::GFx::Value::ObjectInterface *v3; // rax
  Scaleform::List<Scaleform::GFx::Value,Scaleform::GFx::Value> *v4; // rcx

  v2 = movie;
  v3 = (Scaleform::GFx::Value::ObjectInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                   this,
                                                   32i64);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable';
    v3->pMovieRoot = v2;
    v4 = &v3->ExternalObjRefs;
    v4->Root.pPrev = (Scaleform::GFx::Value *)v4;
    v4->Root.pNext = (Scaleform::GFx::Value *)v4;
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2ValueObjectInterface::`vftable';
    v2->pObjectInterface = v3;
  }
  else
  {
    v2->pObjectInterface = 0i64;
  }
}

// File Line: 1706
// RVA: 0x6E16D0
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateString(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pvalue, const char *pstring)
{
  const char *v3; // rbx
  Scaleform::GFx::Value *v4; // rsi
  Scaleform::GFx::AS2::MovieRoot *v5; // rbp
  char *v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v3 = pstring;
  v4 = pvalue;
  v5 = this;
  v6 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(char *))(*(_QWORD *)v6 + 240i64))(v6);
  Scaleform::GFx::AS2::Environment::CreateString(v7, &result, v3);
  value.T.Type = 5;
  value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++value.V.pStringNode->RefCount;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v5, v7, &value, v4);
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 1713
// RVA: 0x6E1850
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateStringW(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pvalue, const wchar_t *pstring)
{
  const wchar_t *v3; // rbx
  Scaleform::GFx::Value *v4; // rdi
  Scaleform::GFx::AS2::MovieRoot *v5; // rsi
  char *v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rbp
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v3 = pstring;
  v4 = pvalue;
  v5 = this;
  v6 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(char *))(*(_QWORD *)v6 + 240i64))(v6);
  Scaleform::GFx::AS2::Environment::CreateString(v7, &result, v3);
  if ( ((unsigned int)v4->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v4->pObjectInterface->vfptr->gap8[8])(
      v4->pObjectInterface,
      v4,
      *(_QWORD *)&v4->mValue.NValue);
    v4->pObjectInterface = 0i64;
  }
  v4->Type = 135;
  value.T.Type = 5;
  value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++value.V.pStringNode->RefCount;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v5, v7, &value, v4);
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 1722
// RVA: 0x6E0A00
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateObject(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pvalue, const char *className, Scaleform::GFx::Value *pargs, unsigned int nargs)
{
  Scaleform::GFx::Value *v5; // r14
  const char *v6; // r12
  Scaleform::GFx::Value *v7; // r13
  Scaleform::GFx::AS2::MovieRoot *v8; // rbx
  Scaleform::GFx::AS2::Environment *v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // rsi
  Scaleform::GFx::AS2::Object *v11; // rdi
  int v12; // er15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // rbx
  Scaleform::GFx::Value *v14; // rsi
  __int64 v15; // r14
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::GlobalContext *v17; // rbx
  Scaleform::GFx::AS2::Object *v18; // rcx
  Scaleform::GFx::AS2::Object *v19; // rbx
  char *v20; // rax
  unsigned __int64 v21; // rsi
  signed __int64 v22; // r14
  Scaleform::GFx::ASStringNode *v23; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rsi
  unsigned int v25; // eax
  Scaleform::GFx::ASStringNode *v26; // rcx
  bool v27; // zf
  unsigned int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::AS2::Value *v36; // rax
  Scaleform::GFx::AS2::Value *v37; // rcx
  Scaleform::GFx::AS2::Value *v38; // rax
  unsigned int v39; // eax
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ASString v41; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS2::Object *v42; // [rsp+58h] [rbp-A8h]
  void *v43; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS2::Environment *penv; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::ASStringContext *v45; // [rsp+70h] [rbp-90h]
  __int64 v46; // [rsp+78h] [rbp-88h]
  char Dst; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS2::MovieRoot *v48; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::ASString result; // [rsp+1D0h] [rbp+D0h]

  v48 = this;
  v46 = -2i64;
  v5 = pargs;
  v6 = className;
  v7 = pvalue;
  v8 = this;
  v9 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  v10 = v9;
  penv = v9;
  v11 = 0i64;
  v42 = 0i64;
  if ( v6 )
  {
    v12 = nargs;
    if ( nargs && (signed int)(nargs - 1) > -1 )
    {
      v13 = &v9->Stack;
      v14 = &v5[nargs - 1];
      v15 = nargs;
      do
      {
        pdestVal.T.Type = 0;
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v48, v14, &pdestVal);
        ++v13->pCurrent;
        if ( v13->pCurrent >= v13->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v13);
        v16 = (Scaleform::GFx::ASStringNode *)v13->pCurrent;
        result.pNode = v16;
        v43 = v16;
        if ( v16 )
          Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v16, &pdestVal, 0i64);
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
        --v14;
        --v15;
      }
      while ( v15 );
      v12 = nargs;
      v10 = penv;
    }
    if ( strchr(v6, 46) )
    {
      v45 = &v10->StringContext;
      v17 = v10->StringContext.pContext;
      v18 = v17->pGlobal.pObject;
      if ( v18 )
        v18->RefCount = (v18->RefCount + 1) & 0x8FFFFFFF;
      v19 = v17->pGlobal.pObject;
      v43 = v19;
      while ( 1 )
      {
        v20 = strchr(v6, 46);
        if ( !v20 )
        {
LABEL_45:
          v10 = penv;
          v31 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v41, v6);
          v11 = Scaleform::GFx::AS2::Environment::OperatorNew(v10, v19, v31, v12, -1);
          v42 = v11;
          v32 = v41.pNode;
          v27 = v41.pNode->RefCount == 1;
          --v32->RefCount;
          if ( v27 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v32);
          if ( v19 )
          {
            v33 = v19->RefCount;
            if ( v33 & 0x3FFFFFF )
            {
              v19->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
            }
          }
          goto LABEL_52;
        }
        v21 = v20 - v6 + 1;
        v22 = (signed __int64)(v20 + 1);
        if ( v21 > 0x100 )
          v21 = 256i64;
        memmove(&Dst, v6, v21 - 1);
        *((_BYTE *)&v46 + v21 + 7) = 0;
        v6 = (const char *)v22;
        pdestVal.T.Type = 0;
        v41.pNode = 0i64;
        Scaleform::GFx::AS2::ASStringContext::CreateString(v45, &result, &Dst);
        if ( !v19->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v19->vfptr, v45, &result, &pdestVal) )
          break;
        v23 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObject(&pdestVal, 0i64);
        v24 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v23;
        if ( v23 )
          v23->RefCount = (v23->RefCount + 1) & 0x8FFFFFFF;
        v41.pNode = v23;
        if ( v23 )
          v23->RefCount = (v23->RefCount + 1) & 0x8FFFFFFF;
        v25 = v19->RefCount;
        if ( v25 & 0x3FFFFFF )
        {
          v19->RefCount = v25 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
        }
        v19 = (Scaleform::GFx::AS2::Object *)v24;
        v43 = v24;
        v26 = result.pNode;
        v27 = result.pNode->RefCount == 1;
        --v26->RefCount;
        if ( v27 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        if ( v24 )
        {
          v28 = v24->RefCount;
          if ( v28 & 0x3FFFFFF )
          {
            v24->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          }
        }
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
        if ( !v22 )
          goto LABEL_45;
      }
      if ( ((unsigned int)v7->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v7->pObjectInterface->vfptr->gap8[8])(
          v7->pObjectInterface,
          v7,
          *(_QWORD *)&v7->mValue.NValue);
        v7->pObjectInterface = 0i64;
      }
      v7->Type = 0;
      v29 = result.pNode;
      v27 = result.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v27 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      if ( v19 )
      {
        v30 = v19->RefCount;
        if ( v30 & 0x3FFFFFF )
        {
          v19->RefCount = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
        }
      }
    }
    else
    {
      v34 = Scaleform::GFx::AS2::Environment::CreateString(v10, &result, v6);
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              v10,
              v10->StringContext.pContext->pGlobal.pObject,
              v34,
              v12,
              -1);
      v42 = v11;
      v35 = result.pNode;
      v27 = result.pNode->RefCount == 1;
      --v35->RefCount;
      if ( v27 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
LABEL_52:
      if ( v11 )
      {
        Scaleform::GFx::AS2::Value::Value(&pdestVal, v11);
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v48, v10, v36, v7);
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      }
      else
      {
        if ( ((unsigned int)v7->Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v7->pObjectInterface->vfptr->gap8[8])(
            v7->pObjectInterface,
            v7,
            *(_QWORD *)&v7->mValue.NValue);
          v7->pObjectInterface = 0i64;
        }
        v7->Type = 0;
      }
      for ( ; v12; --v12 )
      {
        v37 = v10->Stack.pCurrent;
        if ( v37->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v37);
        --v10->Stack.pCurrent;
        if ( v10->Stack.pCurrent < v10->Stack.pPageStart )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v10->Stack);
      }
    }
  }
  else
  {
    v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
            v9,
            v9->StringContext.pContext->pGlobal.pObject,
            (Scaleform::GFx::ASString *)&v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8],
            0,
            -1);
    v42 = v11;
    Scaleform::GFx::AS2::Value::Value(&pdestVal, v11);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v8, v10, v38, v7);
    if ( pdestVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  }
  if ( v11 )
  {
    v39 = v11->RefCount;
    if ( v39 & 0x3FFFFFF )
    {
      v11->RefCount = v39 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
    }
  }
}

// File Line: 1804
// RVA: 0x6DF700
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateArray(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pvalue)
{
  Scaleform::GFx::Value *v2; // rdi
  Scaleform::GFx::AS2::MovieRoot *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rbp
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value value; // [rsp+38h] [rbp-30h]

  v2 = pvalue;
  v3 = this;
  v4 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->pMovieImpl->pMainMovie->vfptr + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset))[30].__vecDelDtor)();
  v5 = Scaleform::GFx::AS2::Environment::OperatorNew(
         v4,
         v4->StringContext.pContext->pGlobal.pObject,
         (Scaleform::GFx::ASString *)&v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
         0,
         -1);
  Scaleform::GFx::AS2::Value::Value(&value, v5);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v3, v4, &value, v2);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( v5 )
  {
    v6 = v5->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v5->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 1817
// RVA: 0x6DFE80
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateFunction(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pvalue, Scaleform::GFx::FunctionHandler *pfc, void *puserData)
{
  void *v4; // rdi
  Scaleform::GFx::FunctionHandler *v5; // rsi
  Scaleform::GFx::Value *v6; // r15
  Scaleform::GFx::AS2::MovieRoot *v7; // rbp
  char *v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // r14
  __int64 v11; // rcx
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value value; // [rsp+48h] [rbp-50h]

  v4 = puserData;
  v5 = pfc;
  v6 = pvalue;
  v7 = this;
  v8 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v9 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v8 + 240i64))(v8);
  v10 = (Scaleform::GFx::AS2::Environment *)v9;
  value.T.Type = 0;
  v12 = (Scaleform::GFx::AS2::UserDefinedFunctionObject *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)(*(_QWORD *)(v9 + 232) + 48i64) + 80i64))(
                                                            v11,
                                                            112i64);
  if ( v12 )
  {
    Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(v12, &v10->StringContext, v5, v4);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  if ( v14 )
    v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  value.T.Type = 8;
  value.V.FunctionValue.Flags = 0;
  value.V.pStringNode = v14;
  if ( v14 )
    v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
  value.V.FunctionValue.pLocalFrame = 0i64;
  if ( v14 )
  {
    v15 = v14->RefCount;
    if ( v15 & 0x3FFFFFF )
    {
      v14->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
    }
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v7, v10, &value, v6);
  if ( v14 )
  {
    v16 = v14->RefCount;
    if ( v16 & 0x3FFFFFF )
    {
      v14->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
    }
  }
  Scaleform::GFx::AS2::Value::DropRefs(&value);
}

