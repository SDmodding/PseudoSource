// File Line: 64
// RVA: 0x6E9F90
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::Finalize_GC(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx

  pObject = (Scaleform::Render::RenderBuffer *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pContext.pObject = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pWatchpoints);
  }
}

// File Line: 72
// RVA: 0x6CD480
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::Resource *pcontext,
        void *puserData)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  if ( pcontext )
    Scaleform::Render::RenderBuffer::AddRef(pcontext);
  this->pContext.pObject = (Scaleform::GFx::FunctionHandler *)pcontext;
  this->pUserData = puserData;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
}

// File Line: 101
// RVA: 0x6FEF90
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::Invoke(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
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
  Scaleform::GFx::AS2::FnCall fna; // [rsp+30h] [rbp-48h] BYREF

  if ( this->pContext.pObject )
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
      fna.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
      fna.Result = Result;
      fna.ThisPtr = vfptr;
      memset(&fna.ThisFunctionRef, 0, 17);
      fna.Env = Env;
      fna.NArgs = NArgs;
      fna.FirstArgBottomIndex = FirstArgBottomIndex;
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(this, &fna);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto((Scaleform::GFx::AS2::SuperObject *)&ThisPtr[-2]);
      Scaleform::GFx::AS2::FnCall::~FnCall(&fna);
    }
    else
    {
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(this, fn);
    }
  }
}

// File Line: 117
// RVA: 0x6FF7E0
void __fastcall Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // rsi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdx
  char Type; // r14
  Scaleform::GFx::Value *v7; // rdx
  int i; // ebx
  unsigned int v9; // edx
  Scaleform::GFx::AS2::Environment *v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r10
  Scaleform::GFx::Value *v12; // rdx
  unsigned __int64 Size; // rdi
  Scaleform::GFx::Value *Data; // rdx
  Scaleform::GFx::Value *v15; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::GFx::Value pdestVal; // [rsp+38h] [rbp-A0h] BYREF
  Scaleform::GFx::Value gfxVal; // [rsp+68h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::Value value; // [rsp+A0h] [rbp-38h] BYREF
  __int64 v20[4]; // [rsp+C0h] [rbp-18h] BYREF
  Scaleform::GFx::Value *v21; // [rsp+E0h] [rbp+8h]
  int v22; // [rsp+E8h] [rbp+10h]
  void *pUserData; // [rsp+F0h] [rbp+18h]
  __int64 v24; // [rsp+F8h] [rbp+20h]
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+138h] [rbp+60h]
  Scaleform::GFx::Value *v26; // [rsp+140h] [rbp+68h]

  v24 = -2i64;
  Env = fn->Env;
  p_pheapAddr = &pheapAddr;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = VT_Undefined;
  *(_QWORD *)&gfxVal.Type = 0i64;
  gfxVal.mValue.IValue = 0;
  value.T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&value, ThisPtr);
    Type = value.T.Type;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(&value);
    Type = 1;
    value.T.Type = 1;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    Env,
    &value,
    &pdestVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  v7 = &pheapAddr.Data[pheapAddr.Size - 1];
  p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)v7;
  v26 = v7;
  if ( v7 )
  {
    v7->pObjectInterface = 0i64;
    v7->Type = pdestVal.Type;
    v7->mValue.pString = pdestVal.mValue.pString;
    v7->DataAux = pdestVal.DataAux;
    if ( (pdestVal.Type & 0x40) != 0 )
    {
      v7->pObjectInterface = pdestVal.pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))pdestVal.pObjectInterface->vfptr->gap8)(
        pdestVal.pObjectInterface,
        v7,
        v7->mValue);
    }
  }
  for ( i = 0; i < fn->NArgs; ++i )
  {
    gfxVal.pObjectInterface = 0i64;
    pdestVal.mValue.IValue = 0;
    v9 = fn->FirstArgBottomIndex - i;
    v10 = fn->Env;
    v11 = 0i64;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
      v11 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
      (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      Env,
      v11,
      &gfxVal);
    Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v12 = &pheapAddr.Data[pheapAddr.Size - 1];
    p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)v12;
    v26 = v12;
    if ( v12 )
    {
      v12->pObjectInterface = 0i64;
      v12->Type = pdestVal.mValue.IValue;
      v12->mValue.pString = (const char *)pdestVal.DataAux;
      v12->DataAux = (unsigned __int64)gfxVal.pPrev;
      if ( (pdestVal.mValue.BValue & 0x40) != 0 )
      {
        v12->pObjectInterface = gfxVal.pObjectInterface;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))gfxVal.pObjectInterface->vfptr->gap8)(
          gfxVal.pObjectInterface,
          v12,
          v12->mValue);
      }
    }
    if ( (pdestVal.mValue.BValue & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&gfxVal.pObjectInterface->vfptr->gap8[8])(
        gfxVal.pObjectInterface,
        &gfxVal,
        pdestVal.DataAux);
      gfxVal.pObjectInterface = 0i64;
    }
    pdestVal.mValue.IValue = 0;
  }
  v20[1] = (__int64)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  v20[0] = (__int64)&gfxVal.8;
  v20[2] = (__int64)&pdestVal;
  if ( fn->NArgs <= 0 )
    v21 = 0i64;
  else
    v21 = pheapAddr.Data + 1;
  v20[3] = (__int64)pheapAddr.Data;
  v22 = LODWORD(pheapAddr.Size) - 1;
  pUserData = this->pUserData;
  this->pContext.pObject->vfptr[1].__vecDelDtor(this->pContext.pObject, (unsigned int)v20);
  if ( (gfxVal.mValue.BValue & 0x8F) != 0 )
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(
      (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      (Scaleform::GFx::Value *)&gfxVal.8,
      fn->Result);
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( (gfxVal.mValue.BValue & 0x40) != 0 )
  {
    (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&gfxVal.Type
                                                                                          + 16i64))(
      *(_QWORD *)&gfxVal.Type,
      &gfxVal.8,
      gfxVal.DataAux);
    *(_QWORD *)&gfxVal.Type = 0i64;
  }
  gfxVal.mValue.IValue = 0;
  if ( (pdestVal.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      pdestVal.mValue);
    pdestVal.pObjectInterface = 0i64;
  }
  pdestVal.Type = VT_Undefined;
  p_pheapAddr = &pheapAddr;
  Size = pheapAddr.Size;
  Data = pheapAddr.Data;
  v15 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      if ( (v15->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v15->pObjectInterface->vfptr->gap8[8])(
          v15->pObjectInterface,
          v15,
          v15->mValue);
        v15->pObjectInterface = 0i64;
      }
      v15->Type = VT_Undefined;
      --v15;
      --Size;
    }
    while ( Size );
    Data = pheapAddr.Data;
  }
  if ( Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 288
// RVA: 0x704CE0
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ObjectAddRef(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        Scaleform::GFx::Resource *pobj)
{
  __int32 v5; // eax
  Scaleform::GFx::AS2::Object *v6; // rax

  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    ++LODWORD(pobj[1].vfptr);
  }
  else if ( v5 == 7 )
  {
    Scaleform::Render::RenderBuffer::AddRef(pobj - 1);
  }
  else if ( (val->Type & 0x8Fu) > 7 )
  {
    if ( (val->Type & 0x8Fu) <= 9 )
    {
      v6 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)pobj);
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
    }
    else if ( v5 == 10 )
    {
      ++LODWORD(pobj->vfptr);
    }
  }
  val->pPrev = this->ExternalObjRefs.Root.pPrev;
  val->pNext = (Scaleform::GFx::Value *)&this->ExternalObjRefs;
  this->ExternalObjRefs.Root.pPrev->pNext = val;
  this->ExternalObjRefs.Root.pPrev = val;
}

// File Line: 331
// RVA: 0x704D60
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ObjectRelease(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        Scaleform::GFx::ASStringNode *pobj)
{
  __int32 v5; // eax
  Scaleform::GFx::AS2::Object *v6; // rax
  unsigned int RefCount; // ecx

  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    if ( pobj->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pobj);
  }
  else if ( v5 == 7 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)&pobj[-1].16);
  }
  else if ( (val->Type & 0x8Fu) > 7 )
  {
    if ( (val->Type & 0x8Fu) <= 9 )
    {
      v6 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)pobj);
      RefCount = v6->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    else if ( v5 == 10 && (int)--LODWORD(pobj->pData) <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)pobj);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pobj);
    }
  }
  val->pPrev->pNext = val->pNext;
  val->pNext->Scaleform::ListNode<Scaleform::GFx::Value>::$41EDDC8CC4664C9FE26D4D23F9ACAEE4::pPrev = val->pPrev;
}

// File Line: 381
// RVA: 0x6FB260
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::HasMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *name,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rsi
  Scaleform::GFx::InteractiveObject *pMainMovie; // r10
  char *v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::ASString *v15; // rax
  bool v16; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v19; // bl
  Scaleform::GFx::AS2::Value v20; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  pMovieRoot = this->pMovieRoot;
  pMainMovie = pMovieRoot->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  v9 = (char *)pMainMovie + 4 * (unsigned __int8)pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 240i64))(v9);
  if ( isdobj )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( !v11 )
      return 0;
    v12 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset;
    v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
    if ( !v13 )
      return 0;
    pdata = (Scaleform::GFx::CharacterHandle *)(v13 + 8);
  }
  if ( !pdata )
    return 0;
  v20.T.Type = 0;
  v15 = Scaleform::GFx::AS2::Environment::CreateConstString(v10, &result, name);
  v16 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&pdata->RefCount + 32i64))(
          pdata,
          v10,
          v15,
          &v20) == 0;
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v19 = !v16;
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  return v19;
}

// File Line: 402
// RVA: 0x6EFE90
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *name,
        Scaleform::GFx::Value *pval,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rdi
  Scaleform::GFx::AS2::MovieRoot *pObject; // r14
  __int64 v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rbp
  Scaleform::GFx::DisplayObject *v12; // rax
  char *v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::ASString *v16; // rax
  bool v17; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v20; // bl
  Scaleform::GFx::AS2::ObjectInterface *v21; // rdi
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::AS2::AvmCharacter *v23; // rax
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  pMovieRoot = this->pMovieRoot;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  v10 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10);
  if ( isdobj )
  {
    v12 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( !v12 )
      goto LABEL_6;
    v13 = (char *)v12 + 4 * (unsigned __int8)v12->AvmObjOffset;
    v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
    if ( !v14 )
      goto LABEL_6;
    pdata = (Scaleform::GFx::CharacterHandle *)(v14 + 8);
  }
  if ( !pdata )
  {
LABEL_6:
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          pval->mValue);
        pval->pObjectInterface = 0i64;
      }
      pval->Type = VT_Undefined;
    }
    return 0;
  }
  value.T.Type = 0;
  v16 = Scaleform::GFx::AS2::Environment::CreateString(v11, &result, name);
  v17 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&pdata->RefCount + 32i64))(
          pdata,
          v11,
          v16,
          &value) == 0;
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v17 )
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          pval->mValue);
        pval->pObjectInterface = 0i64;
      }
      pval->Type = VT_Undefined;
    }
    v20 = 0;
  }
  else
  {
    if ( value.T.Type == 9 )
    {
      v21 = 0i64;
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::CharacterHandle *))(*(_QWORD *)&pdata->RefCount + 16i64))(pdata)
         - 6 <= 0x26 )
      {
        v22 = Scaleform::GFx::AS2::ObjectInterface::ToASObject((Scaleform::GFx::AS2::ObjectInterface *)pdata);
        if ( v22 )
          v21 = &v22->Scaleform::GFx::AS2::ObjectInterface;
      }
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::CharacterHandle *))(*(_QWORD *)&pdata->RefCount + 16i64))(pdata)
         - 2 <= 3 )
      {
        v23 = Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter((Scaleform::GFx::AS2::ObjectInterface *)pdata);
        if ( v23 )
          v21 = &v23->Scaleform::GFx::AS2::ObjectInterface;
      }
      Scaleform::GFx::AS2::Value::GetPropertyValue(&value, v11, v21, &value);
    }
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v11, &value, pval);
    v20 = 1;
  }
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  return v20;
}0 = 1;
  }
  if ( value.T.Type >= 5u 

// File Line: 439
// RVA: 0x7151A0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *name,
        Scaleform::GFx::Value *value,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rdi
  Scaleform::GFx::AS2::MovieRoot *pObject; // rsi
  __int64 v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rbp
  Scaleform::GFx::DisplayObject *v12; // rax
  char *v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::ASString *v16; // rax
  char v17; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  pMovieRoot = this->pMovieRoot;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  v10 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10);
  if ( isdobj )
  {
    v12 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( !v12 )
      return 0;
    v13 = (char *)v12 + 4 * (unsigned __int8)v12->AvmObjOffset;
    v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
    if ( !v14 )
      return 0;
    pdata = (Scaleform::GFx::CharacterHandle *)(v14 + 8);
  }
  if ( !pdata )
    return 0;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &pdestVal);
  v16 = Scaleform::GFx::AS2::Environment::CreateString(v11, &result, name);
  isdobj = 0;
  v17 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, bool *))(*(_QWORD *)&pdata->RefCount + 24i64))(
          pdata,
          v11,
          v16,
          &pdestVal,
          &isdobj);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return v17;
}

// File Line: 454
// RVA: 0x6FDD50
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::Invoke(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *presult,
        const char *name,
        Scaleform::GFx::Value *pargs,
        unsigned __int64 nargs,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rbx
  Scaleform::GFx::AS2::MovieRoot *pObject; // r15
  __int64 v12; // rcx
  Scaleform::GFx::AS2::Environment *v13; // r13
  Scaleform::GFx::DisplayObject *v14; // rax
  char *v15; // rcx
  __int64 v16; // rax
  Scaleform::GFx::ASString *v18; // rax
  char v19; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char i; // bp
  char Type; // di
  int v24; // esi
  Scaleform::GFx::Value *v25; // rdi
  __int64 v26; // rbp
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  Scaleform::GFx::AS2::Value *v28; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+48h] [rbp-A0h] BYREF
  Scaleform::GFx::AS2::Value presulta; // [rsp+68h] [rbp-80h] BYREF
  Scaleform::GFx::AS2::Value method; // [rsp+88h] [rbp-60h] BYREF
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v33; // [rsp+F8h] [rbp+10h]

  pMovieRoot = this->pMovieRoot;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  v12 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v13 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 240i64))(v12);
  if ( isdobj )
  {
    v14 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( !v14 )
      return 0;
    v15 = (char *)v14 + 4 * (unsigned __int8)v14->AvmObjOffset;
    v16 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v15 + 8i64))(v15);
    if ( !v16 )
      return 0;
    pdata = (Scaleform::GFx::CharacterHandle *)(v16 + 8);
  }
  if ( !pdata )
    return 0;
  method.T.Type = 0;
  presulta.T.Type = 0;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v13->StringContext, &result, name);
  v19 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)&pdata->RefCount + 88i64))(
          pdata,
          &v13->StringContext,
          v18,
          &method);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v19 )
  {
    Type = 0;
    pdestVal.T.Type = 0;
    v24 = nargs;
    if ( (int)nargs - 1 > -1 )
    {
      v25 = &pargs[(int)nargs - 1];
      v26 = (unsigned int)nargs;
      do
      {
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, v25, &pdestVal);
        if ( ++v13->Stack.pCurrent >= v13->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v13->Stack);
        pCurrent = (Scaleform::GFx::ASStringNode *)v13->Stack.pCurrent;
        result.pNode = pCurrent;
        v33 = pCurrent;
        if ( pCurrent )
          Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, &pdestVal);
        --v25;
        --v26;
      }
      while ( v26 );
      Type = pdestVal.T.Type;
    }
    for ( i = Scaleform::GFx::AS2::GAS_Invoke(
                &method,
                &presulta,
                (Scaleform::GFx::AS2::ObjectInterface *)pdata,
                v13,
                v24,
                32 * v13->Stack.Pages.Data.Size - 32 + v13->Stack.pCurrent - v13->Stack.pPageStart,
                0i64); v24; --v24 )
    {
      v28 = v13->Stack.pCurrent;
      if ( v28->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v28);
      if ( --v13->Stack.pCurrent < v13->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
    }
    if ( presult )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v13, &presulta, presult);
    if ( (unsigned __int8)Type >= 5u )
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
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *name,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rsi
  Scaleform::GFx::InteractiveObject *pMainMovie; // r10
  char *v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::ASString *v15; // rax
  char v16; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  pMovieRoot = this->pMovieRoot;
  pMainMovie = pMovieRoot->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  v9 = (char *)pMainMovie + 4 * (unsigned __int8)pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 240i64))(v9);
  if ( isdobj )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( !v11 )
      return 0;
    v12 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset;
    v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12);
    if ( !v13 )
      return 0;
    pdata = (Scaleform::GFx::CharacterHandle *)(v13 + 8);
  }
  if ( !pdata )
    return 0;
  v15 = Scaleform::GFx::AS2::Environment::CreateConstString(v10, &result, name);
  v16 = (*(__int64 (__fastcall **)(Scaleform::GFx::CharacterHandle *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)&pdata->RefCount + 48i64))(
          pdata,
          &v10->StringContext,
          v15);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v16;
}

// File Line: 505
// RVA: 0x723D60
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        bool isdobj)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rsi
  __int64 pObject; // r14
  __int64 v9; // rcx
  __int64 v10; // rbp
  Scaleform::GFx::DisplayObject *v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  __int64 v14[5]; // [rsp+38h] [rbp-40h] BYREF

  pMovieRoot = this->pMovieRoot;
  pObject = (__int64)pMovieRoot->pASMovieRoot.pObject;
  v9 = *(_QWORD *)(*(_QWORD *)(pObject + 16) + 80i64)
     + 4i64 * *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(pObject + 16) + 80i64) + 109i64);
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 240i64))(v9);
  if ( isdobj )
  {
    v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, pMovieRoot);
    if ( v11
      && (v12 = (char *)v11 + 4 * (unsigned __int8)v11->AvmObjOffset,
          (v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 8i64))(v12)) != 0) )
    {
      pdata = (Scaleform::GFx::CharacterHandle *)(v13 + 8);
    }
    else
    {
      pdata = 0i64;
    }
  }
  v14[0] = (__int64)`Scaleform::GFx::AS2ValueObjectInterface::VisitMembers::`2::VisitorProxy::`vftable;
  v14[1] = pObject;
  v14[2] = v10;
  v14[3] = (__int64)visitor;
  (*(void (__fastcall **)(Scaleform::GFx::CharacterHandle *, __int64, __int64 *, __int64, _QWORD))(*(_QWORD *)&pdata->RefCount
                                                                                                 + 64i64))(
    pdata,
    v10 + 232,
    v14,
    3i64,
    0i64);
}

// File Line: 518
// RVA: 0x723A20
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers_::_2_::VisitorProxy::Visit(
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::Value *flags)
{
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-40h] BYREF

  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = VT_Undefined;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)name[1].pNode,
    (Scaleform::GFx::AS2::Environment *)name[2].pNode,
    flags,
    &pdestVal);
  (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, _QWORD, Scaleform::GFx::Value *))name[3].pNode->pData + 2))(
    name[3].pNode,
    **(_QWORD **)&val->T.Type,
    &pdestVal);
  if ( (pdestVal.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      pdestVal.mValue);
}

// File Line: 592
// RVA: 0x6EE690
__int64 __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        unsigned int *pdata)
{
  if ( pdata )
    return pdata[20];
  else
    return MEMORY[0x70];
}

// File Line: 600
// RVA: 0x712FF0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        int sz)
{
  if ( pdata )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)(pdata - 32), sz);
  else
    Scaleform::GFx::AS2::ArrayObject::Resize(0i64, sz);
  return 1;
}

// File Line: 609
// RVA: 0x6EF6B0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        int idx,
        Scaleform::GFx::Value *pval)
{
  __int64 v5; // rsi
  char *v7; // rbx
  Scaleform::GFx::AS2::Value *v9; // rsi
  Scaleform::GFx::AS2::MovieRoot *pObject; // rbx
  __int64 v11; // rcx
  Scaleform::GFx::AS2::Environment *v12; // rax

  v5 = idx;
  if ( pdata )
    v7 = pdata - 32;
  else
    v7 = 0i64;
  if ( (pval->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      pval->mValue);
    pval->pObjectInterface = 0i64;
  }
  pval->Type = VT_Undefined;
  if ( (unsigned int)v5 >= *((_DWORD *)v7 + 28) )
    return 0;
  v9 = *(Scaleform::GFx::AS2::Value **)(*((_QWORD *)v7 + 13) + 8 * v5);
  if ( !v9 )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v11 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v12 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 240i64))(v11);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v12, v9, pval);
  return 1;
}

// File Line: 627
// RVA: 0x7143B0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        int idx,
        Scaleform::GFx::Value *value)
{
  __int64 v4; // rdi
  Scaleform::GFx::AS2::ArrayObject *v5; // rbx
  Scaleform::GFx::AS2::MovieRoot *pObject; // rcx
  __int64 v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rax
  Scaleform::GFx::AS2::Value *v9; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-30h] BYREF
  int v12; // [rsp+70h] [rbp+18h] BYREF

  v4 = idx;
  if ( pdata )
    v5 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 32);
  else
    v5 = 0i64;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &pdestVal);
  v5->LengthValueOverriden = 0;
  if ( (int)v4 >= SLODWORD(v5->Elements.Data.Size) )
    Scaleform::GFx::AS2::ArrayObject::Resize(v5, v4 + 1);
  v7 = v4;
  if ( !v5->Elements.Data.Data[v7] )
  {
    v12 = 323;
    v8 = (Scaleform::GFx::AS2::Value *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::ArrayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
  Scaleform::GFx::AS2::Value::operator=(v5->Elements.Data.Data[v7], &pdestVal);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return 1;
}

// File Line: 640
// RVA: 0x723C10
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  __int64 v5; // rbx
  char *v7; // rsi
  Scaleform::GFx::AS2::MovieRoot *pObject; // r15
  __int64 v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // r12
  __int64 v11; // rdx
  int v12; // ecx
  unsigned int v13; // ebp
  __int64 v14; // rdi
  Scaleform::GFx::AS2::Value *v15; // r8
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-60h] BYREF

  v5 = idx;
  v7 = pdata - 32;
  if ( !pdata )
    v7 = 0i64;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 240i64))(v9);
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = VT_Undefined;
  v11 = *((_QWORD *)v7 + 14);
  if ( (unsigned int)v5 < (unsigned int)v11 )
  {
    v12 = count;
    if ( count < 0 )
      v12 = v11 - v5;
    v13 = v5 + v12;
    if ( (unsigned int)v11 < (int)v5 + v12 )
      v13 = *((_QWORD *)v7 + 14);
    if ( (unsigned int)v5 < v13 )
    {
      v14 = 8 * v5;
      do
      {
        v15 = *(Scaleform::GFx::AS2::Value **)(v14 + *((_QWORD *)v7 + 13));
        if ( v15 )
        {
          Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v10, v15, &pdestVal);
        }
        else
        {
          if ( (pdestVal.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
              pdestVal.pObjectInterface,
              &pdestVal,
              pdestVal.mValue);
            pdestVal.pObjectInterface = 0i64;
          }
          pdestVal.Type = VT_Undefined;
        }
        visitor->vfptr->Visit(visitor, v5, &pdestVal);
        LODWORD(v5) = v5 + 1;
        v14 += 8i64;
      }
      while ( (unsigned int)v5 < v13 );
    }
  }
  if ( (pdestVal.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      pdestVal.mValue);
}

// File Line: 665
// RVA: 0x70AA20
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::PushBack(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // rbx
  Scaleform::GFx::AS2::MovieRoot *pObject; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-30h] BYREF

  if ( pdata )
    v3 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 32);
  else
    v3 = 0i64;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &pdestVal);
  Scaleform::GFx::AS2::ArrayObject::PushBack(v3, &pdestVal);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  return 1;
}

// File Line: 678
// RVA: 0x708430
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::PopBack(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  char *v4; // rdi
  Scaleform::GFx::AS2::MovieRoot *pObject; // rsi
  __int64 v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rcx
  int v8; // eax

  if ( pdata )
    v4 = pdata - 32;
  else
    v4 = 0i64;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 240i64))(v6);
  v8 = *((_DWORD *)v4 + 28);
  if ( v8 > 0 )
  {
    if ( pval )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
        pObject,
        v7,
        *(Scaleform::GFx::AS2::Value **)(*((_QWORD *)v4 + 13) + 8i64 * (v8 - 1)),
        pval);
    if ( *((_QWORD *)v4 + 14) )
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v4, *((_DWORD *)v4 + 28) - 1);
    return 1;
  }
  else
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          pval->mValue);
        pval->pObjectInterface = 0i64;
      }
      pval->Type = VT_Undefined;
    }
    return 0;
  }
}

// File Line: 703
// RVA: 0x70FF40
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        unsigned int count)
{
  char *v4; // rcx
  unsigned int v5; // eax
  unsigned int v7; // eax

  if ( pdata )
    v4 = pdata - 32;
  else
    v4 = 0i64;
  v5 = *((_DWORD *)v4 + 28);
  if ( idx >= v5 )
    return 0;
  if ( (count & 0x80000000) != 0 )
    count = v5 - idx;
  v7 = v5 - idx;
  if ( v7 < count )
    count = v7;
  Scaleform::GFx::AS2::ArrayObject::RemoveElements((Scaleform::GFx::AS2::ArrayObject *)v4, idx, count);
  return 1;
}

// File Line: 717
// RVA: 0x6EF5F0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm5_4

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v4 )
  {
    v4 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v4);
    v5 = *((float *)&v4->pWeakProxy + 1);
    v6 = *((float *)&v4->RefCount + 1) * 0.050000001;
    v7 = *(float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr;
    v8 = *(float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v9 = *((float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
         + 1);
    v10 = *(float *)&v4->RefCount;
    v11 = *(float *)&v4->pWeakProxy;
    pmat->M[1][3] = *((float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr
                    + 1)
                  * 0.050000001;
    LOBYTE(v4) = 1;
    pmat->M[1][1] = v5;
    pmat->M[1][2] = v7;
    pmat->M[0][0] = v8;
    pmat->M[0][1] = v9;
    pmat->M[0][2] = v10;
    pmat->M[0][3] = v6;
    pmat->M[1][0] = v11;
  }
  return (char)v4;
}

// File Line: 732
// RVA: 0x6F87E0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetWorldMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmata; // [rsp+20h] [rbp-28h] BYREF

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v4 )
  {
    *(_OWORD *)&pmata.M[0][0] = _xmm;
    *(__m128 *)&pmata.M[1][0] = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v4, &pmata);
    v5 = pmata.M[0][1];
    LOBYTE(v4) = 1;
    v6 = pmata.M[0][3];
    v7 = pmata.M[1][3];
    pmat->M[0][0] = pmata.M[0][0];
    v8 = pmata.M[0][2];
    pmat->M[0][1] = v5;
    v9 = pmata.M[1][0];
    pmat->M[0][2] = v8;
    v10 = pmata.M[1][1];
    pmat->M[1][0] = v9;
    v11 = pmata.M[1][2];
    pmat->M[1][1] = v10;
    pmat->M[0][3] = v6 * 0.050000001;
    pmat->M[1][2] = v11;
    pmat->M[1][3] = v7 * 0.050000001;
  }
  return (char)v4;
}

// File Line: 747
// RVA: 0x7141F0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::GFx::DisplayObject *v4; // rdi
  int v6; // xmm0_4
  float v7; // xmm2_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm1_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  float v13; // xmm4_4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128d v16; // xmm0
  __m128d v17; // xmm2
  double v18; // xmm1_8
  int v19[8]; // [rsp+20h] [rbp-39h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+40h] [rbp-19h] BYREF

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v4 || !Scaleform::Render::Matrix2x4<float>::IsValid(mat) )
    return 0;
  v6 = LODWORD(mat->M[0][0]);
  v7 = mat->M[0][3];
  v19[1] = LODWORD(mat->M[0][1]);
  v8 = LODWORD(mat->M[1][1]);
  v19[0] = v6;
  v9 = LODWORD(mat->M[0][2]);
  v19[5] = v8;
  *(float *)&v10 = mat->M[1][3] * 20.0;
  v19[2] = v9;
  v11 = LODWORD(mat->M[1][0]);
  *(float *)&v19[3] = v7 * 20.0;
  v19[4] = v11;
  v12 = LODWORD(mat->M[1][2]);
  v19[7] = v10;
  v19[6] = v12;
  v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
    v4,
    (unsigned int)v19);
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v4, &geomData);
  v13 = mat->M[1][0];
  v14 = (__m128)LODWORD(mat->M[0][0]);
  v15 = (__m128)LODWORD(mat->M[0][1]);
  geomData.X = (int)mat->M[0][3];
  v16 = _mm_cvtps_pd(v14);
  v17 = _mm_cvtps_pd(v15);
  geomData.Y = (int)mat->M[1][3];
  v16.m128d_f64[0] = v16.m128d_f64[0] * v16.m128d_f64[0] + v13 * v13;
  v18 = mat->M[1][1] * mat->M[1][1];
  geomData.XScale = _mm_sqrt_pd(v16).m128d_f64[0] * 100.0;
  v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v18;
  geomData.YScale = _mm_sqrt_pd(v17).m128d_f64[0] * 100.0;
  geomData.Rotation = atan2(v13, v14.m128_f32[0]) * 180.0 * 0.3183098861837907;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v4, &geomData);
  return 1;
}

// File Line: 780
// RVA: 0x6EFD30
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  float v5; // xmm6_4
  float v6; // xmm8_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v4 )
  {
    v4 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v4);
    v5 = *((float *)&v4->pWeakProxy + 1);
    v6 = *((float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr
         + 1)
       * 0.050000001;
    v7 = *((float *)&v4->RefCount + 1) * 0.050000001;
    v8 = *(float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr;
    v9 = *(float *)&v4->pASRoot;
    v10 = *((float *)&v4->pASRoot + 1);
    v11 = *(float *)&v4->Id.Id;
    v12 = *(float *)&v4->Depth;
    v13 = *(float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v14 = *((float *)&v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
          + 1);
    v15 = *(float *)&v4->RefCount;
    v16 = *(float *)&v4->pWeakProxy;
    LOBYTE(v4) = 1;
    pmat->M[0][0] = v13;
    pmat->M[0][1] = v14;
    pmat->M[0][2] = v15;
    pmat->M[0][3] = v7;
    pmat->M[1][0] = v16;
    pmat->M[1][1] = v5;
    pmat->M[1][2] = v8;
    pmat->M[1][3] = v6;
    pmat->M[2][0] = v9;
    pmat->M[2][1] = v10;
    pmat->M[2][2] = v11;
    pmat->M[2][3] = v12;
  }
  return (char)v4;
}

// File Line: 797
// RVA: 0x714F90
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Matrix3x4<float> *mat)
{
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
  int v16[12]; // [rsp+20h] [rbp-49h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+50h] [rbp-19h] BYREF
  float eX; // [rsp+D0h] [rbp+67h] BYREF
  float eY; // [rsp+D8h] [rbp+6Fh] BYREF

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v4 || !Scaleform::Render::Matrix3x4<float>::IsValid(mat) )
    return 0;
  v6 = LODWORD(mat->M[0][1]);
  v7 = mat->M[0][3];
  v8 = mat->M[1][3];
  v16[0] = LODWORD(mat->M[0][0]);
  v16[2] = LODWORD(mat->M[0][2]);
  v9 = LODWORD(mat->M[1][0]);
  v16[1] = v6;
  v10 = LODWORD(mat->M[1][1]);
  v16[4] = v9;
  v16[6] = LODWORD(mat->M[1][2]);
  v11 = LODWORD(mat->M[2][0]);
  v16[5] = v10;
  v12 = LODWORD(mat->M[2][1]);
  v16[8] = v11;
  v13 = LODWORD(mat->M[2][2]);
  v16[9] = v12;
  v14 = LODWORD(mat->M[2][3]);
  v16[10] = v13;
  v16[11] = v14;
  *(float *)&v16[3] = v7 * 20.0;
  *(float *)&v16[7] = v8 * 20.0;
  v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[5].__vecDelDtor(
    v4,
    (unsigned int)v16);
  *(_QWORD *)&geomData.X = 0i64;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v4, &geomData);
  v15 = (__m128)LODWORD(mat->M[0][2]);
  v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(mat->M[1][2] * mat->M[1][2]);
  geomData.Z = mat->M[2][3];
  v15.m128_f32[0] = v15.m128_f32[0] + (float)(mat->M[2][2] * mat->M[2][2]);
  geomData.ZScale = _mm_sqrt_ps(v15).m128_f32[0] * 100.0;
  Scaleform::Render::Matrix3x4<float>::GetEulerAngles(mat, &eX, &eY, 0i64);
  geomData.XRotation = eX * 180.0 * 0.3183098861837907;
  geomData.YRotation = eY * 180.0 * 0.3183098861837907;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v4, &geomData);
  return 1;
}

// File Line: 834
// RVA: 0x700390
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata)
{
  return Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot) != 0i64;
}

// File Line: 843
// RVA: 0x6F46D0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetParent(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pparent)
{
  Scaleform::GFx::DisplayObject *v5; // rax
  Scaleform::GFx::DisplayObject *v6; // rcx
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::CharacterHandle *pObject; // rdi
  Scaleform::GFx::ASMovieRootBase *v9; // rsi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rsi
  Scaleform::GFx::DisplayObject *v12; // rax
  unsigned __int16 Flags; // cx

  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v5 )
  {
    v6 = v5->pParent;
    if ( v6 )
    {
      pMovieRoot = this->pMovieRoot;
      pObject = v6->pNameHandle.pObject;
      v9 = pMovieRoot->pASMovieRoot.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v6);
      pMovieImpl = v9->pMovieImpl;
      pObjectInterface = pMovieImpl->pObjectInterface;
      v12 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, pMovieImpl);
      if ( v12
        && ((Flags = v12->Scaleform::GFx::DisplayObjectBase::Flags, (Flags & 0x400) != 0) || (Flags & 0x80u) != 0) )
      {
        if ( (pparent->Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pparent->pObjectInterface->vfptr->gap8[8])(
            pparent->pObjectInterface,
            pparent,
            pparent->mValue);
          pparent->pObjectInterface = 0i64;
        }
        pparent->Type = VT_DisplayObject|0x40;
        pparent->mValue.pString = (const char *)pObject;
        pparent->pObjectInterface = pObjectInterface;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::CharacterHandle *))pObjectInterface->vfptr->gap8)(
          pObjectInterface,
          pparent,
          pObject);
        LOBYTE(v5) = 1;
      }
      else
      {
        LOBYTE(v5) = 0;
      }
    }
    else
    {
      if ( (pparent->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pparent->pObjectInterface->vfptr->gap8[8])(
          pparent->pObjectInterface,
          pparent,
          pparent->mValue);
        pparent->pObjectInterface = 0i64;
      }
      pparent->Type = VT_Null;
      LOBYTE(v5) = 1;
    }
  }
  return (char)v5;
}

// File Line: 865
// RVA: 0x6EF180
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::TextField *RenderNode; // rax
  Scaleform::GFx::TextField *v5; // rdi
  long double Rotation; // xmm7_8
  long double XScale; // xmm8_8
  long double YScale; // xmm9_8
  long double v9; // xmm11_8
  long double v10; // xmm10_8
  long double v11; // xmm6_8
  char v12; // al
  long double Z; // xmm0_8
  long double XRotation; // xmm1_8
  long double YRotation; // xmm0_8
  long double ZScale; // xmm1_8
  long double v17; // xmm0_8
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // xmm0_4
  int v25; // xmm1_4
  int v26; // xmm0_4
  int v27; // xmm1_4
  int v28; // xmm0_4
  int v29; // xmm1_4
  int v30; // xmm0_4
  int v31; // xmm1_4
  int v32; // xmm0_4
  int v33; // xmm1_4
  int v34; // xmm0_4
  int v35; // xmm1_4
  int v36; // xmm0_4
  int v37; // xmm1_4
  int v38; // xmm0_4
  int v39; // xmm1_4
  int v40; // xmm0_4
  int v41; // xmm1_4
  int v42; // xmm0_4
  int v43; // xmm1_4
  int v44; // xmm0_4
  int v45; // xmm1_4
  unsigned __int64 v46; // rdx
  int v48[12]; // [rsp+20h] [rbp-E0h] BYREF
  int Dst[16]; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+90h] [rbp-70h] BYREF

  RenderNode = (Scaleform::GFx::TextField *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v5 = RenderNode;
  if ( RenderNode )
  {
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(RenderNode, &geomData);
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v5) == 4 )
    {
      Scaleform::GFx::TextField::GetPosition(v5, pinfo);
    }
    else
    {
      Rotation = geomData.Rotation;
      XScale = geomData.XScale;
      YScale = geomData.YScale;
      v9 = (double)geomData.X * 0.05;
      v10 = (double)geomData.Y * 0.05;
      v11 = (float)(Scaleform::GFx::DisplayObjectBase::GetCxform(v5)->M[0][3] * 100.0);
      v12 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(v5);
      Z = geomData.Z;
      pinfo->Visible = v12;
      pinfo->VarsSet |= 0x7FFu;
      XRotation = geomData.XRotation;
      pinfo->Z = Z;
      YRotation = geomData.YRotation;
      pinfo->XRotation = XRotation;
      ZScale = geomData.ZScale;
      pinfo->X = v9;
      pinfo->Y = v10;
      pinfo->Rotation = Rotation;
      pinfo->XScale = XScale;
      pinfo->YScale = YScale;
      pinfo->Alpha = v11;
      pinfo->YRotation = YRotation;
      pinfo->ZScale = ZScale;
    }
    v17 = ((double (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[40].__vecDelDtor)(v5);
    pinfo->VarsSet |= 0x800u;
    pinfo->FOV = v17;
    memset(Dst, 0, sizeof(Dst));
    Dst[0] = 1065353216;
    Dst[5] = 1065353216;
    Dst[10] = 1065353216;
    Dst[15] = 1065353216;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
           v5,
           Dst,
           0i64) )
    {
      v18 = Dst[0];
      v19 = Dst[1];
      pinfo->VarsSet |= 0x1000u;
      LODWORD(pinfo->ProjectionMatrix3D.M[0][0]) = v18;
      v20 = Dst[2];
      LODWORD(pinfo->ProjectionMatrix3D.M[0][1]) = v19;
      v21 = Dst[3];
      LODWORD(pinfo->ProjectionMatrix3D.M[0][2]) = v20;
      v22 = Dst[4];
      LODWORD(pinfo->ProjectionMatrix3D.M[0][3]) = v21;
      v23 = Dst[5];
      LODWORD(pinfo->ProjectionMatrix3D.M[1][0]) = v22;
      v24 = Dst[6];
      LODWORD(pinfo->ProjectionMatrix3D.M[1][1]) = v23;
      v25 = Dst[7];
      LODWORD(pinfo->ProjectionMatrix3D.M[1][2]) = v24;
      v26 = Dst[8];
      LODWORD(pinfo->ProjectionMatrix3D.M[1][3]) = v25;
      v27 = Dst[9];
      LODWORD(pinfo->ProjectionMatrix3D.M[2][0]) = v26;
      v28 = Dst[10];
      LODWORD(pinfo->ProjectionMatrix3D.M[2][1]) = v27;
      v29 = Dst[11];
      LODWORD(pinfo->ProjectionMatrix3D.M[2][2]) = v28;
      v30 = Dst[12];
      LODWORD(pinfo->ProjectionMatrix3D.M[2][3]) = v29;
      v31 = Dst[13];
      LODWORD(pinfo->ProjectionMatrix3D.M[3][0]) = v30;
      v32 = Dst[14];
      LODWORD(pinfo->ProjectionMatrix3D.M[3][1]) = v31;
      v33 = Dst[15];
      LODWORD(pinfo->ProjectionMatrix3D.M[3][2]) = v32;
      LODWORD(pinfo->ProjectionMatrix3D.M[3][3]) = v33;
    }
    memset(v48, 0, sizeof(v48));
    v48[0] = 1065353216;
    v48[5] = 1065353216;
    v48[10] = 1065353216;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
           v5,
           v48,
           0i64) )
    {
      v34 = v48[0];
      v35 = v48[1];
      pinfo->VarsSet |= 0x2000u;
      LODWORD(pinfo->ViewMatrix3D.M[0][0]) = v34;
      v36 = v48[2];
      LODWORD(pinfo->ViewMatrix3D.M[0][1]) = v35;
      v37 = v48[3];
      LODWORD(pinfo->ViewMatrix3D.M[0][2]) = v36;
      v38 = v48[4];
      LODWORD(pinfo->ViewMatrix3D.M[0][3]) = v37;
      v39 = v48[5];
      LODWORD(pinfo->ViewMatrix3D.M[1][0]) = v38;
      v40 = v48[6];
      LODWORD(pinfo->ViewMatrix3D.M[1][1]) = v39;
      v41 = v48[7];
      LODWORD(pinfo->ViewMatrix3D.M[1][2]) = v40;
      v42 = v48[8];
      LODWORD(pinfo->ViewMatrix3D.M[1][3]) = v41;
      v43 = v48[9];
      LODWORD(pinfo->ViewMatrix3D.M[2][0]) = v42;
      v44 = v48[10];
      LODWORD(pinfo->ViewMatrix3D.M[2][1]) = v43;
      v45 = v48[11];
      LODWORD(pinfo->ViewMatrix3D.M[2][2]) = v44;
      LODWORD(pinfo->ViewMatrix3D.M[2][3]) = v45;
    }
    RenderNode = (Scaleform::GFx::TextField *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
    v46 = (__int64)((unsigned __int128)((__int64)((__int64)RenderNode
                                                - ((unsigned __int64)RenderNode & 0xFFFFFFFFFFFFF000ui64)
                                                - 56)
                                      * (__int128)0x4924924924924925i64) >> 64) >> 4;
    LODWORD(RenderNode) = *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)RenderNode & 0xFFFFFFFFFFFFF000ui64)
                                                           + 0x20)
                                               + 8 * ((unsigned int)v46 + (v46 >> 63))
                                               + 40)
                                   + 10i64) & 0xC;
    pinfo->VarsSet |= 0x4000u;
    pinfo->EdgeAAMode = (int)RenderNode;
    LOBYTE(RenderNode) = 1;
  }
  return (char)RenderNode;
}

// File Line: 910
// RVA: 0x7137D0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::TextField *v5; // rdi
  char v6; // r14
  bool v7; // r15
  Scaleform::Render::EdgeAAMode EdgeAAMode; // ebx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::Cxform *Cxform; // rax
  double Alpha; // xmm0_8
  unsigned __int64 v12; // rdx
  double Z; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  double ZScale; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v16; // rax
  long double XRotation; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v18; // rbx
  double v19; // xmm0_8
  long double YRotation; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v21; // rbx
  double v22; // xmm0_8
  unsigned __int16 VarsSet; // cx
  long double FOV; // xmm6_8
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v26; // rbx
  __int64 v27; // rax
  __m128d v28; // xmm0
  __m128d v29; // xmm11
  __m128d v30; // xmm10
  unsigned __int16 v31; // r14
  __m128 v32; // xmm7
  float v33; // xmm6_4
  __m128 v34; // xmm9
  float v35; // xmm8_4
  float v36; // xmm0_4
  long double v37; // xmm0_8
  double v38; // xmm1_8
  double Rotation; // xmm6_8
  __m128d v40; // xmm2
  double v41; // xmm7_8
  double v42; // xmm3_8
  __m128d v43; // xmm1
  double v44; // xmm8_8
  double v45; // xmm6_8
  long double v46; // xmm0_8
  double v47; // xmm0_8
  double v48; // xmm6_8
  double v49; // xmm1_8
  double v50; // xmm0_8
  double v51; // xmm14_8
  double v52; // xmm0_8
  double v53; // xmm1_8
  int v54; // ecx
  int v55; // ecx
  bool v56; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v57; // rax
  double v58; // xmm11_8
  double v59; // xmm11_8
  double v60; // xmm10_8
  double v61; // xmm10_8
  unsigned __int64 v63; // [rsp+20h] [rbp-E0h]
  double v64; // [rsp+20h] [rbp-E0h]
  unsigned __int64 v65; // [rsp+28h] [rbp-D8h]
  Scaleform::Render::Cxform v66; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Cxform v67; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+140h] [rbp+40h] BYREF
  double v69; // [rsp+148h] [rbp+48h]
  long double v70; // [rsp+158h] [rbp+58h]

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v5 = (Scaleform::GFx::TextField *)v4;
  if ( !v4 )
    return (char)v4;
  v6 = 0;
  v7 = ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v4) == 4;
  if ( (cinfo->VarsSet & 0x4000) != 0 )
  {
    EdgeAAMode = cinfo->EdgeAAMode;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, EdgeAAMode);
  }
  if ( (cinfo->VarsSet & 0x20) != 0 )
  {
    result = *(Scaleform::Render::Point<float> *)&cinfo->Alpha;
    if ( (*(_QWORD *)&result & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
      || (*(_QWORD *)&result & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v5);
      *(_OWORD *)&v67.M[0][0] = *(_OWORD *)&Cxform->M[0][0];
      Alpha = cinfo->Alpha;
      *(_OWORD *)&v67.M[1][0] = *(_OWORD *)&Cxform->M[1][0];
      v67.M[0][3] = Alpha * 0.01;
      Scaleform::GFx::DisplayObjectBase::SetCxform(v5, &v67);
      v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        v5,
        0);
    }
  }
  if ( (cinfo->VarsSet & 0x40) != 0 )
    v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
      v5,
      cinfo->Visible);
  v12 = 0xFFF0000000000000ui64;
  if ( SLOBYTE(cinfo->VarsSet) < 0 )
  {
    Z = cinfo->Z;
    *(double *)&result = Z;
    if ( (*(_QWORD *)&Z & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
      && (*(_QWORD *)&result & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      Z = 0.0;
    }
    *(double *)&result = Z;
    if ( Z == -INFINITY || (*(double *)&result = Z, Z == INFINITY) )
      Z = 0.0;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
    pGeomData = v5->pGeomData;
    v12 = 0xFFF0000000000000ui64;
    if ( Z != pGeomData->Z )
    {
      pGeomData->Z = Z;
      v6 = 1;
    }
  }
  if ( (cinfo->VarsSet & 0x400) != 0 )
  {
    ZScale = cinfo->ZScale;
    *(double *)&result = ZScale;
    if ( (*(_QWORD *)&ZScale & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
      && (*(_QWORD *)&result & 0xFFFFFFFFFFFFFi64) != 0
      || (*(double *)&result = ZScale, ZScale == -INFINITY)
      || (*(double *)&result = ZScale, ZScale == INFINITY) )
    {
      ZScale = DOUBLE_100_0;
    }
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
    v16 = v5->pGeomData;
    if ( ZScale != v16->ZScale )
    {
      v16->ZScale = ZScale;
      v6 = 1;
    }
  }
  if ( (cinfo->VarsSet & 0x100) != 0 )
  {
    XRotation = cinfo->XRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
    v18 = v5->pGeomData;
    if ( XRotation != v18->XRotation )
    {
      v19 = fmod(XRotation, 360.0);
      if ( v19 <= 180.0 )
      {
        if ( v19 < -180.0 )
          v19 = v19 + 360.0;
      }
      else
      {
        v19 = v19 + -360.0;
      }
      v18->XRotation = v19;
      v6 = 1;
    }
  }
  if ( (cinfo->VarsSet & 0x200) != 0 )
  {
    YRotation = cinfo->YRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
    v21 = v5->pGeomData;
    if ( YRotation != v21->YRotation )
    {
      v22 = fmod(YRotation, 360.0);
      if ( v22 <= 180.0 )
      {
        if ( v22 < -180.0 )
          v22 = v22 + 360.0;
        v21->YRotation = v22;
      }
      else
      {
        v21->YRotation = v22 + -360.0;
      }
      goto LABEL_42;
    }
  }
  if ( v6 )
LABEL_42:
    ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(v5);
  VarsSet = cinfo->VarsSet;
  if ( (VarsSet & 0x800) != 0 )
  {
    FOV = cinfo->FOV;
    if ( FOV != ((double (__fastcall *)(Scaleform::GFx::TextField *, unsigned __int64))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[40].__vecDelDtor)(
                  v5,
                  v12) )
    {
      vfptr = v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      fmod(FOV, 180.0);
      ((void (__fastcall *)(Scaleform::GFx::TextField *))vfptr[39].__vecDelDtor)(v5);
    }
  }
  else
  {
    if ( (VarsSet & 0x1000) != 0 )
      v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[7].__vecDelDtor(
        v5,
        (unsigned int)&cinfo->ProjectionMatrix3D);
    if ( (cinfo->VarsSet & 0x2000) != 0 )
      v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[10].__vecDelDtor(
        v5,
        (unsigned int)&cinfo->ViewMatrix3D);
  }
  if ( (cinfo->VarsSet & 0x1F) != 0 )
  {
    if ( v7 )
    {
      v5->Flags |= 0x2000u;
      Scaleform::GFx::TextField::SetDirtyFlag(v5);
    }
    v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      v5,
      0);
    v26 = v5->pGeomData;
    v27 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v5);
    *(_OWORD *)&v66.M[0][0] = *(_OWORD *)v27;
    *(_QWORD *)&v66.M[1][0] = *(_QWORD *)(v27 + 16);
    v28 = (__m128d)*(unsigned int *)(v27 + 24);
    *(_QWORD *)&v66.M[1][2] = *(_QWORD *)(v27 + 24);
    if ( v7 && (cinfo->VarsSet & 3) != 0 )
    {
      Scaleform::GFx::TextField::TransformToTextRectSpace(v5, &result, cinfo);
      v29 = _mm_cvtps_pd((__m128)LODWORD(result.x));
      v30 = _mm_cvtps_pd((__m128)LODWORD(result.y));
    }
    else
    {
      if ( (cinfo->VarsSet & 1) != 0 )
        v29 = (__m128d)*(unsigned __int64 *)&cinfo->X;
      else
        v29 = (__m128d)v63;
      if ( (cinfo->VarsSet & 2) != 0 )
        v30 = (__m128d)*(unsigned __int64 *)&cinfo->Y;
      else
        v30 = (__m128d)v65;
    }
    v31 = cinfo->VarsSet;
    if ( (v31 & 0x1C) != 0 )
    {
      v32 = (__m128)LODWORD(v26->OrigMatrix.M[0][0]);
      v33 = v26->OrigMatrix.M[1][0];
      v34 = (__m128)LODWORD(v26->OrigMatrix.M[0][1]);
      v35 = v26->OrigMatrix.M[1][1];
      v67.M[0][2] = v26->OrigMatrix.M[0][2];
      v36 = v26->OrigMatrix.M[1][2];
      v67.M[0][3] = v66.M[0][3];
      v67.M[1][3] = v66.M[1][3];
      *(_QWORD *)&v67.M[0][0] = __PAIR64__(v34.m128_u32[0], v32.m128_u32[0]);
      v67.M[1][0] = v33;
      *(_QWORD *)&v67.M[1][1] = __PAIR64__(LODWORD(v36), LODWORD(v35));
      v37 = atan2(v33, v32.m128_f32[0]);
      v38 = v33;
      Rotation = v26->Rotation;
      v40 = _mm_cvtps_pd(v32);
      v40.m128d_f64[0] = v40.m128d_f64[0] * v40.m128d_f64[0] + v38 * v38;
      v64 = v37;
      v41 = v26->YScale * 0.01;
      v42 = v35;
      v43 = _mm_cvtps_pd(v34);
      v44 = v26->XScale * 0.01;
      result = (Scaleform::Render::Point<float>)*(_OWORD *)&_mm_sqrt_pd(v40);
      v43.m128d_f64[0] = v43.m128d_f64[0] * v43.m128d_f64[0] + v42 * v42;
      *(_QWORD *)&v69 = *(_OWORD *)&_mm_sqrt_pd(v43);
      v45 = Rotation * 3.141592653589793 * 0.005555555555555556;
      if ( (v31 & 4) != 0 )
        v46 = cinfo->Rotation;
      else
        v46 = Scaleform::GFx::NumberUtil::NaN();
      v70 = v46;
      if ( (*(_QWORD *)&v46 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
        || (*(_QWORD *)&v46 & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        v47 = fmod(v46, 360.0);
        v48 = v47;
        if ( v47 <= 180.0 )
        {
          if ( v47 < -180.0 )
            v48 = v47 + 360.0;
        }
        else
        {
          v48 = v47 + -360.0;
        }
        v26->Rotation = v48;
        v45 = v48 * 3.141592653589793 * 0.005555555555555556;
      }
      if ( (cinfo->VarsSet & 8) != 0 )
      {
        v49 = DOUBLE_0_01;
        v50 = cinfo->XScale * 0.01;
      }
      else
      {
        v50 = Scaleform::GFx::NumberUtil::NaN();
        v49 = DOUBLE_0_01;
      }
      v51 = *(double *)&result;
      if ( v50 != v44 )
      {
        v70 = v50;
        if ( (*(_QWORD *)&v50 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
        {
          v26->XScale = cinfo->XScale;
          if ( v51 == 0.0 || v50 > 1.0e16 )
          {
            v50 = 0.0;
            v51 = DOUBLE_1_0;
          }
          v44 = v50;
        }
      }
      if ( (cinfo->VarsSet & 0x10) != 0 )
        v52 = cinfo->YScale * v49;
      else
        v52 = Scaleform::GFx::NumberUtil::NaN();
      v53 = v69;
      if ( v52 != v41 )
      {
        *(double *)&result = v52;
        if ( (*(_QWORD *)&v52 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
        {
          v26->YScale = cinfo->YScale;
          if ( v53 == 0.0 || v52 > 1.0e16 )
          {
            v52 = 0.0;
            v53 = DOUBLE_1_0;
          }
          v41 = v52;
        }
      }
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        (Scaleform::Render::Matrix2x4<float> *)&v67,
        v44 / v51,
        v41 / v53,
        v45 - v64);
      v66 = v67;
      v28.m128d_f64[1] = *(long double *)&v67.M[1][2];
    }
    if ( (cinfo->VarsSet & 1) != 0 )
      v28 = v29;
    else
      v28.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0];
    if ( (*(_QWORD *)&v28.m128d_f64[0] & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
      || (*(_QWORD *)&v28.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0];
      if ( *(_QWORD *)&v28.m128d_f64[0] == 0xFFF0000000000000ui64
        || (result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0],
            *(_QWORD *)&v28.m128d_f64[0] == 0x7FF0000000000000i64) )
      {
        v28 = 0i64;
      }
      v28.m128d_f64[0] = v28.m128d_f64[0] * 20.0;
      v54 = (int)v28.m128d_f64[0];
      if ( (double)v54 != v28.m128d_f64[0] )
        v28.m128d_f64[0] = (double)(v54 - (_mm_movemask_pd(_mm_unpacklo_pd(v28, v28)) & 1));
      v26->X = (int)v28.m128d_f64[0];
      v28 = (__m128d)COERCE_UNSIGNED_INT((float)(int)v28.m128d_f64[0]);
      v66.M[0][3] = *(float *)v28.m128d_f64;
    }
    if ( (cinfo->VarsSet & 2) != 0 )
      v28 = v30;
    else
      v28.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0];
    if ( (*(_QWORD *)&v28.m128d_f64[0] & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
      || (*(_QWORD *)&v28.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0];
      if ( *(_QWORD *)&v28.m128d_f64[0] == 0xFFF0000000000000ui64
        || (result = *(Scaleform::Render::Point<float> *)&v28.m128d_f64[0],
            *(_QWORD *)&v28.m128d_f64[0] == 0x7FF0000000000000i64) )
      {
        v28 = 0i64;
      }
      v28.m128d_f64[0] = v28.m128d_f64[0] * 20.0;
      v55 = (int)v28.m128d_f64[0];
      if ( (double)v55 != v28.m128d_f64[0] )
        v28.m128d_f64[0] = (double)(v55 - (_mm_movemask_pd(_mm_unpacklo_pd(v28, v28)) & 1));
      v26->Y = (int)v28.m128d_f64[0];
      v66.M[1][3] = (float)(int)v28.m128d_f64[0];
    }
    if ( v66.M[0][0] >= -3.4028235e38
      && v66.M[0][0] <= 3.4028235e38
      && v66.M[0][1] >= -3.4028235e38
      && v66.M[0][1] <= 3.4028235e38
      && v66.M[0][2] >= -3.4028235e38
      && v66.M[0][2] <= 3.4028235e38
      && v66.M[0][3] >= -3.4028235e38
      && v66.M[0][3] <= 3.4028235e38
      && v66.M[1][0] >= -3.4028235e38
      && v66.M[1][0] <= 3.4028235e38
      && v66.M[1][1] >= -3.4028235e38
      && v66.M[1][1] <= 3.4028235e38
      && v66.M[1][2] >= -3.4028235e38
      && v66.M[1][2] <= 3.4028235e38
      && v66.M[1][3] >= -3.4028235e38
      && v66.M[1][3] <= 3.4028235e38 )
    {
      v56 = !Scaleform::GFx::DisplayObjectBase::Has3D(v5);
      v57 = v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      if ( v56 )
        v57[3].__vecDelDtor(v5, (unsigned int)&v66);
      else
        ((void (__fastcall *)(Scaleform::GFx::TextField *))v57[13].__vecDelDtor)(v5);
    }
    if ( v7 )
    {
      if ( (cinfo->VarsSet & 1) != 0 )
      {
        v58 = v29.m128d_f64[0] * 20.0;
        if ( v58 <= 0.0 )
          v59 = v58 - 0.5;
        else
          v59 = v58 + 0.5;
        v26->X = (int)v59;
      }
      if ( (cinfo->VarsSet & 2) != 0 )
      {
        v60 = v30.m128d_f64[0] * 20.0;
        if ( v60 <= 0.0 )
          v61 = v60 - 0.5;
        else
          v61 = v60 + 0.5;
        v26->Y = (int)v61;
      }
    }
  }
  LOBYTE(v4) = 1;
  return (char)v4;
}

// File Line: 1188
// RVA: 0x71C6E0
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *ptext,
        bool reqHtml)
{
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // bl
  unsigned int Flags; // eax
  unsigned int v13; // eax
  char v15[16]; // [rsp+38h] [rbp-40h] BYREF
  __int64 v16; // [rsp+48h] [rbp-30h]
  int v17; // [rsp+50h] [rbp-28h]
  const char *v18; // [rsp+58h] [rbp-20h]

  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( !v8 )
    return (char)v8;
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v8) == 4 )
  {
    Flags = v9->Flags;
    if ( reqHtml )
    {
      if ( (v9->Flags & 2) == 0 )
      {
        v13 = Flags | 2;
LABEL_13:
        v9->Flags = v13;
      }
    }
    else if ( (v9->Flags & 2) != 0 )
    {
      v13 = Flags & 0xFFFFFFFD;
      goto LABEL_13;
    }
    Scaleform::GFx::TextField::SetTextValue(v9, ptext, reqHtml, 1);
    LOBYTE(v8) = 1;
    return (char)v8;
  }
  v16 = 0i64;
  v17 = 6;
  v18 = ptext;
  v10 = "text";
  if ( reqHtml )
    v10 = "htmlText";
  v11 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, Scaleform::GFx::CharacterHandle *, const char *, char *, char))&this->vfptr->gap8[32])(
          this,
          pdata,
          v10,
          v15,
          1);
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 0;
  LOBYTE(v8) = v11;
  return (char)v8;
}

// File Line: 1205
// RVA: 0x71C810
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const wchar_t *ptext,
        bool reqHtml)
{
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // bl
  char v13[16]; // [rsp+38h] [rbp-40h] BYREF
  __int64 v14; // [rsp+48h] [rbp-30h]
  int v15; // [rsp+50h] [rbp-28h]
  const wchar_t *v16; // [rsp+58h] [rbp-20h]

  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( v8 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v8) == 4 )
    {
      Scaleform::GFx::TextField::SetText(v9, ptext, reqHtml);
      LOBYTE(v8) = 1;
    }
    else
    {
      v14 = 0i64;
      v15 = 7;
      v16 = ptext;
      v10 = "text";
      if ( reqHtml )
        v10 = "htmlText";
      v11 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, Scaleform::GFx::CharacterHandle *, const char *, char *, char))&this->vfptr->gap8[32])(
              this,
              pdata,
              v10,
              v13,
              1);
      if ( (v15 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const wchar_t *))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
        v14 = 0i64;
      }
      v15 = 0;
      LOBYTE(v8) = v11;
    }
  }
  return (char)v8;
}

// File Line: 1222
// RVA: 0x6F6680
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pval,
        bool reqHtml)
{
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::TextField *v9; // rsi
  const char *v10; // r8
  Scaleform::GFx::AS2::MovieRoot *pObject; // rdi
  __int64 v12; // rcx
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v17; // [rsp+20h] [rbp-58h]
  Scaleform::GFx::AS2::Value value; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v9 = (Scaleform::GFx::TextField *)v8;
  if ( v8 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v8) == 4 )
    {
      pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
      v12 = (__int64)pObject->pMovieImpl->pMainMovie
          + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
      v13 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 240i64))(v12);
      Scaleform::GFx::TextField::GetText(v9, &result, reqHtml);
      value.T.Type = 5;
      value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
      ++result.pNode->RefCount;
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v13, &value, pval);
      Scaleform::GFx::AS2::Value::DropRefs(&value);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      LOBYTE(v8) = 1;
    }
    else
    {
      v10 = "text";
      if ( reqHtml )
        v10 = "htmlText";
      v17 = 1;
      LOBYTE(v8) = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2ValueObjectInterface *, Scaleform::GFx::CharacterHandle *, const char *, Scaleform::GFx::Value *, char))&this->vfptr->gap8[24])(
                     this,
                     pdata,
                     v10,
                     pval,
                     v17);
    }
  }
  return (char)v8;
}

// File Line: 1244
// RVA: 0x6FB030
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *frame,
        bool stop)
{
  Scaleform::GFx::DisplayObject *v6; // rax
  __int64 v7; // r9
  Scaleform::GFx::DisplayObject *v8; // rbx
  unsigned int v10; // [rsp+30h] [rbp+8h] BYREF

  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v8 = v6;
  if ( !v6 )
    return 0;
  if ( (v6->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  LOBYTE(v7) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, const char *, unsigned int *, __int64))v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[108].__vecDelDtor)(
          v6,
          frame,
          &v10,
          v7) )
    return 0;
  v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
    v8,
    v10);
  v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
    v8,
    stop);
  return 1;
}

// File Line: 1263
// RVA: 0x6FAFA0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        unsigned int frame,
        bool stop)
{
  Scaleform::GFx::DisplayObject *v6; // rax
  Scaleform::GFx::DisplayObject *v7; // rbx

  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v7 = v6;
  if ( !v6 || (v6->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  v6->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
    v6,
    frame - 1);
  v7->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
    v7,
    stop);
  return 1;
}

// File Line: 1278
// RVA: 0x6EF100
bool __fastcall Scaleform::GFx::AS2ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Cxform *pcx)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObjectBase *v5; // rbx
  bool result; // al
  Scaleform::Render::Cxform *Cxform; // rax
  __int128 v8; // xmm1

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v5 = v4;
  if ( !v4
    || ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v4) != 4
    && (v5->Flags & 0x400) == 0 )
  {
    return 0;
  }
  Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v5);
  *(_OWORD *)&pcx->M[0][0] = *(_OWORD *)&Cxform->M[0][0];
  v8 = *(_OWORD *)&Cxform->M[1][0];
  result = 1;
  *(_OWORD *)&pcx->M[1][0] = v8;
  return result;
}

// File Line: 1292
// RVA: 0x713750
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::SetCxform(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::GFx::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObjectBase *v5; // rbx

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v5 = v4;
  if ( !v4
    || ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v4) != 4
    && (v5->Flags & 0x400) == 0 )
  {
    return 0;
  }
  Scaleform::GFx::DisplayObjectBase::SetCxform(v5, cx);
  v5->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
    v5,
    0);
  return 1;
}

// File Line: 1309
// RVA: 0x6DF9D0
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        const char *instanceName)
{
  Scaleform::GFx::DisplayObject *v7; // rax
  Scaleform::GFx::DisplayObject *v8; // rbx
  Scaleform::GFx::AS2::MovieRoot *pObject; // rdi
  __int64 v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rsi
  int v12; // eax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // r10
  __int64 v15; // rax
  Scaleform::GFx::DisplayObject *v16; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rax
  char v20; // di
  Scaleform::Render::Cxform v22[2]; // [rsp+28h] [rbp-71h] BYREF
  Scaleform::Render::RenderBuffer *v23; // [rsp+68h] [rbp-31h]
  int v24; // [rsp+70h] [rbp-29h]
  int v25; // [rsp+74h] [rbp-25h]
  int v26; // [rsp+78h] [rbp-21h]
  __int64 v27; // [rsp+80h] [rbp-19h]
  _DWORD v28[4]; // [rsp+88h] [rbp-11h]
  Scaleform::GFx::AS2::Value value; // [rsp+98h] [rbp-1h] BYREF
  __int64 v30; // [rsp+B8h] [rbp+1Fh]
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+5Fh] BYREF
  __int64 v32; // [rsp+100h] [rbp+67h]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  v30 = -2i64;
  v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v8 = v7;
  if ( !v7 || (v7->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v10 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10);
  v12 = (int)retaddr;
  if ( (int)retaddr < 0 )
  {
    v12 = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v8[1].pRenNode) - 0x3FFF;
    if ( v12 < 0 )
      v12 = 0;
  }
  v22[0] = Scaleform::Render::Cxform::Identity;
  v22[1] = (Scaleform::Render::Cxform)Scaleform::Render::Matrix2x4<float>::Identity;
  v23 = 0i64;
  v24 = 0;
  LOWORD(v28[1]) = 256;
  v28[0] = 786432;
  v25 = v12 + 0x4000;
  v26 = 65537;
  v27 = 0i64;
  if ( (unsigned int)(v12 + 0x4000) > 0x7EFFFFFD )
  {
    v20 = 0;
  }
  else
  {
    v13 = Scaleform::GFx::AS2::Environment::CreateString(v11, &result, instanceName);
    vfptr = v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    *(_OWORD *)&v22[0].M[1][0] = 0ui64;
    LODWORD(v22[0].M[0][2]) = 1;
    v22[0].M[0][0] = NAN;
    v15 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD))vfptr[118].__vecDelDtor)(
            v8,
            v22,
            v13,
            0i64,
            0i64);
    v16 = (Scaleform::GFx::DisplayObject *)v15;
    if ( v15 )
      ++*(_DWORD *)(v15 + 8);
    v32 = v15;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v16 )
    {
      v16->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        v16,
        0);
      value.T.Type = 7;
      CharacterHandle = (Scaleform::GFx::ASStringNode *)v16->pNameHandle.pObject;
      if ( !CharacterHandle )
        CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
      value.V.pStringNode = CharacterHandle;
      if ( CharacterHandle )
        ++LODWORD(CharacterHandle->pData);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v11, &value, pmc);
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    }
    v20 = 1;
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
  }
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  return v20;
}

// File Line: 1354
// RVA: 0x6DAE60
char __fastcall Scaleform::GFx::AS2ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        const char *symbolName,
        const char *instanceName,
        int depth,
        Scaleform::GFx::MemberValueSet *initArgs)
{
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::GFx::DisplayObject *v10; // rsi
  Scaleform::GFx::AS2::MovieRoot *pObject; // r12
  __int64 v12; // rcx
  Scaleform::GFx::AS2::Environment *v13; // r13
  unsigned int v14; // r14d
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::GFx::MovieDefImpl *v16; // rax
  bool v17; // bl
  Scaleform::GFx::CharacterHandle *CharacterHandle; // rax
  Scaleform::GFx::CharacterHandle *v19; // rax
  char v20; // si
  Scaleform::GFx::Resource *v21; // rdx
  int v22; // ecx
  int vfptr; // eax
  int v24; // edx
  Scaleform::GFx::AS2::Object *v25; // rbx
  Scaleform::GFx::MemberValueSet *v26; // r15
  __int64 v27; // rdi
  Scaleform::GFx::AS2::MovieRoot *v28; // rsi
  __int64 v29; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v31; // zf
  Scaleform::GFx::AS2::ObjectInterface *v32; // rdi
  Scaleform::GFx::ASString *v33; // rax
  __int64 v34; // rax
  Scaleform::GFx::DisplayObject *v35; // rdi
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v39; // rax
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS2::MovieRoot *v42; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::ASString v44; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::DisplayObject *v45; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::Resource *v46; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::Resource *pOwnerDefRes; // [rsp+88h] [rbp-78h]
  __int64 v48; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS2::Object *v49; // [rsp+98h] [rbp-68h]
  Scaleform::Render::Cxform v50[2]; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::RenderBuffer *v51; // [rsp+E0h] [rbp-20h]
  int v52; // [rsp+E8h] [rbp-18h]
  int v53; // [rsp+ECh] [rbp-14h]
  int v54; // [rsp+F0h] [rbp-10h]
  __int64 v55; // [rsp+F8h] [rbp-8h]
  int v56; // [rsp+100h] [rbp+0h]
  __int16 v57; // [rsp+104h] [rbp+4h]
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+110h] [rbp+10h] BYREF
  __int64 v59; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS2::Value value; // [rsp+138h] [rbp+38h] BYREF
  __int64 v61; // [rsp+158h] [rbp+58h]
  char v62; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::String symbol; // [rsp+1A8h] [rbp+A8h] BYREF
  Scaleform::GFx::Value *v64; // [rsp+1B0h] [rbp+B0h]

  v64 = pmc;
  v59 = -2i64;
  v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v10 = v9;
  v45 = v9;
  if ( !v9 || (v9->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v42 = pObject;
  v12 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v13 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 240i64))(v12);
  v14 = 0;
  presBindData.pResource.pObject = 0i64;
  presBindData.pBinding = 0i64;
  Scaleform::String::String(&symbol, symbolName);
  pMovieImpl = v10->pASRoot->pMovieImpl;
  v16 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v10->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(v10);
  v17 = !Scaleform::GFx::MovieImpl::FindExportedResource(pMovieImpl, v16, &presBindData, &symbol);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v17 )
  {
    CharacterHandle = v10->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v10->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - export name \"%s\" is not found.",
      CharacterHandle->NamePath.pNode->pData,
      symbolName);
  }
  else
  {
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)(presBindData.pResource.pObject) & 0x8000) != 0 )
    {
      pOwnerDefRes = 0i64;
      v48 = 0i64;
      v21 = presBindData.pResource.pObject;
      v46 = presBindData.pResource.pObject;
      pOwnerDefRes = presBindData.pBinding->pOwnerDefRes;
      v22 = depth;
      if ( depth < 0 )
      {
        v22 = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v10[1].pRenNode)
            - 0x3FFF;
        if ( v22 < 0 )
          v22 = 0;
        v21 = v46;
      }
      vfptr = (int)v21[1].vfptr;
      v50[0] = Scaleform::Render::Cxform::Identity;
      v50[1] = (Scaleform::Render::Cxform)Scaleform::Render::Matrix2x4<float>::Identity;
      v51 = 0i64;
      v52 = 0;
      v57 = 256;
      v56 = 786432;
      v53 = v22 + 0x4000;
      v54 = vfptr;
      v55 = 0i64;
      v24 = v22 + 0x4000;
      if ( (unsigned int)(v22 + 0x4000) > 0x7EFFFFFD )
      {
        v39 = v10->pNameHandle.pObject;
        if ( !v39 )
        {
          v39 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
          v24 = v53;
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &v10->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
          v39->NamePath.pNode->pData,
          symbolName,
          v24);
        v20 = 0;
      }
      else
      {
        v25 = 0i64;
        v49 = 0i64;
        v26 = initArgs;
        if ( !initArgs )
          goto LABEL_29;
        v25 = Scaleform::GFx::AS2::Environment::OperatorNew(
                v13,
                v13->StringContext.pContext->pGlobal.pObject,
                (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8],
                0,
                -1);
        v49 = v25;
        if ( v26->Data.Size )
        {
          v27 = 0i64;
          v28 = v42;
          do
          {
            v29 = (__int64)&v26->Data.Data[v27];
            Scaleform::GFx::AS2::Environment::CreateString(v13, &result, (Scaleform::String *)v29);
            pdestVal.T.Type = 0;
            Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v28, (Scaleform::GFx::Value *)(v29 + 8), &pdestVal);
            v62 = 0;
            v25->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
              &v25->Scaleform::GFx::AS2::ObjectInterface,
              v13,
              &result,
              &pdestVal,
              (Scaleform::GFx::AS2::PropFlags *)&v62);
            if ( pdestVal.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
            pNode = result.pNode;
            v31 = result.pNode->RefCount-- == 1;
            if ( v31 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
            v27 = ++v14;
          }
          while ( v14 < v26->Data.Size );
          v10 = v45;
          pObject = v42;
        }
        v32 = &v25->Scaleform::GFx::AS2::ObjectInterface;
        if ( !v25 )
LABEL_29:
          v32 = 0i64;
        v33 = Scaleform::GFx::AS2::Environment::CreateString(v13, &v44, instanceName);
        v34 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, Scaleform::GFx::AS2::ObjectInterface *, int, int, Scaleform::GFx::Resource **, _QWORD))v10->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
                v10,
                v50,
                v33,
                0i64,
                v32,
                -1,
                1,
                &v46,
                0i64);
        v35 = (Scaleform::GFx::DisplayObject *)v34;
        if ( v34 )
          ++*(_DWORD *)(v34 + 8);
        v61 = v34;
        v36 = v44.pNode;
        v31 = v44.pNode->RefCount-- == 1;
        if ( v31 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        if ( v35 )
        {
          v35->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
            v35,
            0);
          if ( Scaleform::GFx::DisplayObjectBase::GetVersion(v10) >= 6 )
          {
            value.T.Type = 7;
            v37 = (Scaleform::GFx::ASStringNode *)v35->pNameHandle.pObject;
            if ( !v37 )
              v37 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v35);
            value.V.pStringNode = v37;
            if ( v37 )
              ++LODWORD(v37->pData);
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v13, &value, v64);
            Scaleform::GFx::AS2::Value::DropRefs(&value);
          }
        }
        v20 = 1;
        if ( v35 )
          Scaleform::RefCountNTSImpl::Release(v35);
        if ( v25 )
        {
          RefCount = v25->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v25->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
          }
        }
      }
      if ( v51 )
        Scaleform::RefCountImpl::Release(v51);
      goto LABEL_51;
    }
    v19 = v10->pNameHandle.pObject;
    if ( !v19 )
      v19 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v10);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v10->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - \"%s\" is not a movieclip.",
      v19->NamePath.pNode->pData,
      symbolName);
  }
  v20 = 0;
LABEL_51:
  if ( presBindData.pResource.pObject )
    Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
  return v20;
}

// File Line: 1439
// RVA: 0x7220D0
void __fastcall Scaleform::GFx::AS2ValueObjectInterface::ToString(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::Value *thisVal)
{
  Scaleform::GFx::AS2::MovieRoot *pObject; // rbx
  __int64 v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::String *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::String v13; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h] BYREF

  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (__int64)pObject->pMovieImpl->pMainMovie + 4 * (unsigned __int8)pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 240i64))(v6);
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, thisVal, &pdestVal);
  v8 = Scaleform::GFx::AS2::Value::ToString(&pdestVal, &result, v7, -1);
  Scaleform::String::String(&v13, v8->pNode->pData);
  Scaleform::String::operator=(pstr, v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
}

// File Line: 1517
// RVA: 0x723410
Scaleform::GFx::AS2::MovieRoot::Value2ASValue

// File Line: 1582
// RVA: 0x6D7420
void __fastcall Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *value,
        Scaleform::GFx::Value *pdestVal)
{
  Scaleform::GFx::Value::ValueType Type; // edx
  Scaleform::Render::RenderBuffer *v9; // rsi
  int v10; // r15d
  __int32 v11; // edi
  __int64 v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rbp
  __int64 v16; // rdi
  Scaleform::GFx::MovieImpl::WideStringStorage *v17; // rax
  Scaleform::Render::RenderBuffer *v18; // rax
  Scaleform::GFx::AS2::ObjectInterface *v19; // rdi
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::CharacterHandle *pObject; // r8
  Scaleform::GFx::AS2::ObjectInterface *v22; // rax
  Scaleform::GFx::InteractiveObject *v23; // rax
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+20h] BYREF

  Type = pdestVal->Type;
  v9 = 0i64;
  v10 = 8;
  if ( (Type & 0x80u) == 0 )
  {
    v12 = (unsigned __int8)value->T.Type;
    if ( (unsigned int)v12 <= 8 )
      __asm { jmp     rcx; Indirect Near Jump }
    v11 = 6;
  }
  else
  {
    v11 = pdestVal->Type & 0xF;
  }
  if ( (Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal->pObjectInterface->vfptr->gap8[8])(
      pdestVal->pObjectInterface,
      pdestVal,
      pdestVal->mValue);
    pdestVal->pObjectInterface = 0i64;
  }
  switch ( v11 )
  {
    case 0:
    case 1:
      pdestVal->Type = v11;
      return;
    case 2:
      pdestVal->Type = VT_Boolean;
      pdestVal->mValue.BValue = Scaleform::GFx::AS2::Value::ToBool(value, penv);
      return;
    case 3:
      pdestVal->Type = VT_Int;
      pdestVal->mValue.IValue = (int)Scaleform::GFx::AS2::Value::ToNumber(value, penv);
      return;
    case 4:
      pdestVal->Type = VT_UInt;
      pdestVal->mValue.IValue = (int)Scaleform::GFx::AS2::Value::ToNumber(value, penv);
      return;
    case 5:
      pdestVal->Type = VT_Number;
      pdestVal->mValue.NValue = Scaleform::GFx::AS2::Value::ToNumber(value, penv);
      return;
    case 6:
      Scaleform::GFx::AS2::Value::ToString(value, &result, penv, -1);
      pdestVal->Type = VT_String|0x40;
      pdestVal->mValue = (Scaleform::GFx::Value::ValueUnion)result.pNode;
      pdestVal->pObjectInterface = this->pMovieImpl->pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *))this->pMovieImpl->pObjectInterface->vfptr->gap8)(
        this->pMovieImpl->pObjectInterface,
        pdestVal);
      goto LABEL_15;
    case 7:
      Scaleform::GFx::AS2::Value::ToString(value, &result, penv, -1);
      pNode = result.pNode;
      v16 = Scaleform::GFx::ASConstString::GetLength(&result) + 1;
      v17 = (Scaleform::GFx::MovieImpl::WideStringStorage *)this->pMovieImpl->pHeap->vfptr->Alloc(
                                                              this->pMovieImpl->pHeap,
                                                              2 * v16 + 31,
                                                              0i64);
      pdestVal->Type = VT_StringW|0x40;
      if ( v17 )
      {
        Scaleform::GFx::MovieImpl::WideStringStorage::WideStringStorage(v17, pNode, (unsigned int)v16);
        v9 = v18;
      }
      pdestVal->mValue.pString = (const char *)&v9->pManager;
      pdestVal->pObjectInterface = this->pMovieImpl->pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *))this->pMovieImpl->pObjectInterface->vfptr->gap8)(
        this->pMovieImpl->pObjectInterface,
        pdestVal);
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
LABEL_15:
      v13 = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      return;
    case 8:
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(value, penv);
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v19->vfptr->gap8[8])(v19) - 6 <= 0x26 )
      {
        v20 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(v19);
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v20->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v20->Scaleform::GFx::AS2::ObjectInterface) == 7 )
          v10 = 9;
      }
      pdestVal->Type = v10 | 0x40;
      pdestVal->mValue.pString = (const char *)v19;
      pObject = (Scaleform::GFx::CharacterHandle *)v19;
      goto LABEL_31;
    case 10:
      v22 = Scaleform::GFx::AS2::Value::ToObjectInterface(value, penv);
      if ( v22 )
      {
        v23 = Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v22);
        pdestVal->Type = VT_DisplayObject|0x40;
        pObject = v23->pNameHandle.pObject;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v23);
        pdestVal->mValue.pString = (const char *)pObject;
LABEL_31:
        pdestVal->pObjectInterface = this->pMovieImpl->pObjectInterface;
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::CharacterHandle *))this->pMovieImpl->pObjectInterface->vfptr->gap8)(
          this->pMovieImpl->pObjectInterface,
          pdestVal,
          pObject);
      }
      else
      {
        pdestVal->Type = VT_Undefined;
      }
      return;
    default:
      return;
  }
}

// File Line: 1699
// RVA: 0x6E0F10
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateObjectInterface(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::MovieImpl *movie)
{
  Scaleform::GFx::Value::ObjectInterface *v3; // rax

  v3 = (Scaleform::GFx::Value::ObjectInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                   this,
                                                   32i64);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable;
    v3->pMovieRoot = movie;
    v3->ExternalObjRefs.Root.pPrev = (Scaleform::GFx::Value *)&v3->ExternalObjRefs;
    v3->ExternalObjRefs.Root.pNext = (Scaleform::GFx::Value *)&v3->ExternalObjRefs;
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2ValueObjectInterface::`vftable;
    movie->pObjectInterface = v3;
  }
  else
  {
    movie->pObjectInterface = 0i64;
  }
}

// File Line: 1706
// RVA: 0x6E16D0
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateString(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const char *pstring)
{
  char *v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  v6 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 240i64))(v6);
  Scaleform::GFx::AS2::Environment::CreateString(v7, &result, pstring);
  value.T.Type = 5;
  value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++result.pNode->RefCount;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v7, &value, pvalue);
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1713
// RVA: 0x6E1850
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateStringW(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const wchar_t *pstring)
{
  char *v6; // rcx
  Scaleform::GFx::AS2::Environment *v7; // rbp
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value value; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  v6 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 240i64))(v6);
  Scaleform::GFx::AS2::Environment::CreateString(v7, &result, pstring);
  if ( (pvalue->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pvalue->pObjectInterface->vfptr->gap8[8])(
      pvalue->pObjectInterface,
      pvalue,
      pvalue->mValue);
    pvalue->pObjectInterface = 0i64;
  }
  pvalue->Type = VT_ConvertStringW;
  value.T.Type = 5;
  value.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
  ++result.pNode->RefCount;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v7, &value, pvalue);
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1722
// RVA: 0x6E0A00
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateObject(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const char *className,
        Scaleform::GFx::Value *pargs,
        int nargs)
{
  char *v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rax
  Scaleform::GFx::AS2::Environment *v11; // rsi
  Scaleform::GFx::AS2::Object *v12; // rdi
  int v13; // r15d
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  Scaleform::GFx::Value *v15; // rsi
  __int64 v16; // r14
  Scaleform::GFx::ASStringNode *pCurrent; // rcx
  Scaleform::GFx::AS2::GlobalContext *pContext; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::Object *v20; // rbx
  char *v21; // rax
  unsigned __int64 v22; // rsi
  const char *v23; // r14
  Scaleform::GFx::ASStringNode *v24; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v25; // rsi
  unsigned int v26; // eax
  Scaleform::GFx::ASStringNode *v27; // rcx
  bool v28; // zf
  unsigned int v29; // eax
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS2::Value *v37; // rax
  Scaleform::GFx::AS2::Value *v38; // rcx
  Scaleform::GFx::AS2::Value *v39; // rax
  unsigned int v40; // eax
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ASString v42; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS2::Object *v43; // [rsp+58h] [rbp-A8h]
  void *v44; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS2::Environment *penv; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [rsp+70h] [rbp-90h]
  __int64 v47; // [rsp+78h] [rbp-88h]
  char Dst[224]; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::ASString result; // [rsp+1D0h] [rbp+D0h] BYREF

  v47 = -2i64;
  v9 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 240i64))(v9);
  v11 = v10;
  penv = v10;
  v12 = 0i64;
  v43 = 0i64;
  if ( className )
  {
    v13 = nargs;
    if ( nargs && nargs - 1 > -1 )
    {
      p_Stack = &v10->Stack;
      v15 = &pargs[nargs - 1];
      v16 = (unsigned int)nargs;
      do
      {
        pdestVal.T.Type = 0;
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v15, &pdestVal);
        if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
        pCurrent = (Scaleform::GFx::ASStringNode *)p_Stack->pCurrent;
        result.pNode = pCurrent;
        v44 = pCurrent;
        if ( pCurrent )
          Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)pCurrent, &pdestVal);
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
        --v15;
        --v16;
      }
      while ( v16 );
      v13 = nargs;
      v11 = penv;
    }
    if ( strchr(className, 46) )
    {
      p_StringContext = &v11->StringContext;
      pContext = v11->StringContext.pContext;
      pObject = pContext->pGlobal.pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
      v20 = pContext->pGlobal.pObject;
      v44 = v20;
      while ( 1 )
      {
        v21 = strchr(className, 46);
        if ( !v21 )
        {
LABEL_45:
          v11 = penv;
          v32 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v42, className);
          v12 = Scaleform::GFx::AS2::Environment::OperatorNew(v11, v20, v32, v13, -1);
          v43 = v12;
          pNode = v42.pNode;
          v28 = v42.pNode->RefCount-- == 1;
          if ( v28 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( v20 )
          {
            RefCount = v20->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v20->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
            }
          }
          goto LABEL_52;
        }
        v22 = v21 - className + 1;
        v23 = v21 + 1;
        if ( v22 > 0x100 )
          v22 = 256i64;
        memmove(Dst, className, v22 - 1);
        Dst[v22 - 1] = 0;
        className = v23;
        pdestVal.T.Type = 0;
        v42.pNode = 0i64;
        Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &result, Dst);
        if ( !v20->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
                &v20->Scaleform::GFx::AS2::ObjectInterface,
                p_StringContext,
                &result,
                &pdestVal) )
          break;
        v24 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Value::ToObject(&pdestVal, 0i64);
        v25 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v24;
        if ( v24 )
          v24->RefCount = (v24->RefCount + 1) & 0x8FFFFFFF;
        v42.pNode = v24;
        if ( v24 )
          v24->RefCount = (v24->RefCount + 1) & 0x8FFFFFFF;
        v26 = v20->RefCount;
        if ( (v26 & 0x3FFFFFF) != 0 )
        {
          v20->RefCount = v26 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
        }
        v20 = (Scaleform::GFx::AS2::Object *)v25;
        v44 = v25;
        v27 = result.pNode;
        v28 = result.pNode->RefCount-- == 1;
        if ( v28 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        if ( v25 )
        {
          v29 = v25->RefCount;
          if ( (v29 & 0x3FFFFFF) != 0 )
          {
            v25->RefCount = v29 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
          }
        }
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
        if ( !v23 )
          goto LABEL_45;
      }
      if ( (pvalue->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pvalue->pObjectInterface->vfptr->gap8[8])(
          pvalue->pObjectInterface,
          pvalue,
          pvalue->mValue);
        pvalue->pObjectInterface = 0i64;
      }
      pvalue->Type = VT_Undefined;
      v30 = result.pNode;
      v28 = result.pNode->RefCount-- == 1;
      if ( v28 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      if ( v20 )
      {
        v31 = v20->RefCount;
        if ( (v31 & 0x3FFFFFF) != 0 )
        {
          v20->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
        }
      }
    }
    else
    {
      v35 = Scaleform::GFx::AS2::Environment::CreateString(v11, &result, className);
      v12 = Scaleform::GFx::AS2::Environment::OperatorNew(
              v11,
              v11->StringContext.pContext->pGlobal.pObject,
              v35,
              v13,
              -1);
      v43 = v12;
      v36 = result.pNode;
      v28 = result.pNode->RefCount-- == 1;
      if ( v28 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
LABEL_52:
      if ( v12 )
      {
        Scaleform::GFx::AS2::Value::Value(&pdestVal, (Scaleform::GFx::ASStringNode *)v12);
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v11, v37, pvalue);
        if ( pdestVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      }
      else
      {
        if ( (pvalue->Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pvalue->pObjectInterface->vfptr->gap8[8])(
            pvalue->pObjectInterface,
            pvalue,
            pvalue->mValue);
          pvalue->pObjectInterface = 0i64;
        }
        pvalue->Type = VT_Undefined;
      }
      for ( ; v13; --v13 )
      {
        v38 = v11->Stack.pCurrent;
        if ( v38->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v38);
        if ( --v11->Stack.pCurrent < v11->Stack.pPageStart )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v11->Stack);
      }
    }
  }
  else
  {
    v12 = Scaleform::GFx::AS2::Environment::OperatorNew(
            v10,
            v10->StringContext.pContext->pGlobal.pObject,
            (Scaleform::GFx::ASString *)&v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8],
            0,
            -1);
    v43 = v12;
    Scaleform::GFx::AS2::Value::Value(&pdestVal, (Scaleform::GFx::ASStringNode *)v12);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v11, v39, pvalue);
    if ( pdestVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  }
  if ( v12 )
  {
    v40 = v12->RefCount;
    if ( (v40 & 0x3FFFFFF) != 0 )
    {
      v12->RefCount = v40 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
    }
  }
}

// File Line: 1804
// RVA: 0x6DF700
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue)
{
  char *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rbp
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value value; // [rsp+38h] [rbp-30h] BYREF

  v4 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v5 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 240i64))(v4);
  v6 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                         v5,
                                         v5->StringContext.pContext->pGlobal.pObject,
                                         (Scaleform::GFx::ASString *)&v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount,
                                         0,
                                         -1);
  Scaleform::GFx::AS2::Value::Value(&value, v6);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v5, &value, pvalue);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6);
    }
  }
}

// File Line: 1817
// RVA: 0x6DFE80
void __fastcall Scaleform::GFx::AS2::MovieRoot::CreateFunction(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        Scaleform::GFx::Resource *pfc,
        void *puserData)
{
  char *v8; // rcx
  Scaleform::GFx::AS2::Environment *v9; // r14
  __int64 v10; // rcx
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rbx
  unsigned int RefCount; // eax
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value value; // [rsp+48h] [rbp-50h] BYREF

  v8 = (char *)this->pMovieImpl->pMainMovie + 4 * (unsigned __int8)this->pMovieImpl->pMainMovie->AvmObjOffset;
  v9 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 240i64))(v8);
  value.T.Type = 0;
  v11 = (Scaleform::GFx::AS2::UserDefinedFunctionObject *)((__int64 (__fastcall *)(__int64, __int64))v9->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                            v10,
                                                            112i64);
  if ( v11 )
  {
    Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(v11, &v9->StringContext, pfc, puserData);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  if ( v13 )
    v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  value.T.Type = 8;
  value.V.FunctionValue.Flags = 0;
  value.V.pStringNode = v13;
  if ( v13 )
    v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
  value.V.FunctionValue.pLocalFrame = 0i64;
  if ( v13 )
  {
    RefCount = v13->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v13->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v13);
    }
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v9, &value, pvalue);
  if ( v13 )
  {
    v15 = v13->RefCount;
    if ( (v15 & 0x3FFFFFF) != 0 )
    {
      v13->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v13);
    }
  }
  Scaleform::GFx::AS2::Value::DropRefs(&value);
}

