// File Line: 35
// RVA: 0x6D2410
void __fastcall Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
}

// File Line: 46
// RVA: 0x721410
Scaleform::GFx::AS2::ObjectInterfaceVtbl *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToCharacter(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&this->vfptr->gap8[8])(this) - 2 > 3 )
    return 0i64;
  else
    return this[1].vfptr;
}

// File Line: 51
// RVA: 0x721270
Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&this->vfptr->gap8[8])(this) - 2 > 3 )
    return 0i64;
  else
    return &this[-1].pProto;
}

// File Line: 56
// RVA: 0x721240
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToASObject(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&this->vfptr->gap8[8])(this) - 6 > 0x26 )
    return 0i64;
  else
    return this - 2;
}

// File Line: 96
// RVA: 0x721530
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToFunction(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::FunctionRef *result)
{
  result->Flags = 0;
  result->Function = 0i64;
  result->pLocalFrame = 0i64;
  return result;
}

// File Line: 101
// RVA: 0x6EB150
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::ObjectInterface::FindOwner(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rbx

  v5 = this;
  if ( !this )
    return 0i64;
  while ( !v5->vfptr->HasMember(v5, psc, name, 0) )
  {
    pObject = v5->pProto.pObject;
    if ( pObject )
    {
      v5 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
      if ( v5 )
        continue;
    }
    return 0i64;
  }
  return v5 - 2;
}

// File Line: 143
// RVA: 0x6CB100
void __fastcall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASRefCountCollector *pcc)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = pcc;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  this->pProto.pObject = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = 0i64;
}

// File Line: 151
// RVA: 0x6CB1C0
void __fastcall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *pLoadQueueHead; // rax
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  if ( psc->pContext && (pMovieRoot = psc->pContext->pMovieRoot) != 0i64 )
    pLoadQueueHead = (Scaleform::GFx::AS2::RefCountCollector<323> *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = pLoadQueueHead;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  this->pProto.pObject = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = 0i64;
}

// File Line: 160
// RVA: 0x6CB2A0
void __fastcall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *proto)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *pLoadQueueHead; // rax

  if ( psc->pContext && (pMovieRoot = psc->pContext->pMovieRoot) != 0i64 )
    pLoadQueueHead = (Scaleform::GFx::AS2::RefCountCollector<323> *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = pLoadQueueHead;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  this->pProto.pObject = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    proto);
}

// File Line: 167
// RVA: 0x6CB370
void __fastcall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v5; // rcx
  Scaleform::GFx::AS2::RefCountCollector<323> *v6; // rax
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Target = penv->Target;
  if ( Target )
  {
    v5 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
    v6 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5)
                                                                                             + 24)
                                                                                 + 32i64)
                                                                     + 56i64)
                                                         + 32i64);
  }
  else
  {
    v6 = 0i64;
  }
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = v6;
  this->RefCount = 1;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  this->pProto.pObject = 0i64;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Object);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 173
// RVA: 0x6D2300
void __fastcall Scaleform::GFx::AS2::Object::~Object(Scaleform::GFx::AS2::Object *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // rsi
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rdi
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int v9; // eax

  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v2 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWatchpoints);
  }
  if ( (this->ResolveHandler.Flags & 2) == 0 )
  {
    Function = this->ResolveHandler.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  this->ResolveHandler.Function = 0i64;
  if ( (this->ResolveHandler.Flags & 1) == 0 )
  {
    pLocalFrame = this->ResolveHandler.pLocalFrame;
    if ( pLocalFrame )
    {
      v7 = pLocalFrame->RefCount;
      if ( (v7 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->ResolveHandler.pLocalFrame = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  pObject = v2->pProto.pObject;
  if ( pObject )
  {
    v9 = pObject->RefCount;
    if ( (v9 & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
}

// File Line: 186
// RVA: 0x6C0A50
void __fastcall Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Member> *p_Members; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 v5; // rdi
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rcx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v12; // rcx
  char EntryCount; // al
  unsigned __int64 v14; // rdx
  int v15; // eax
  unsigned int v16; // eax
  unsigned __int64 v17; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v18; // rcx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v20; // rax
  unsigned __int64 v21; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v22; // rax
  signed __int64 v23; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v24; // rcx
  char *v25; // rdi
  char v26; // al
  __int64 v27; // rdx
  int v28; // eax
  unsigned int v29; // eax
  unsigned __int64 v30; // rcx
  unsigned __int64 *v31; // rax
  Scaleform::GFx::AS2::Object *pObject; // rdx
  unsigned int v33; // eax
  unsigned int v34; // eax
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Member> *v35; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *v36; // [rsp+20h] [rbp-18h]
  unsigned __int64 v37; // [rsp+28h] [rbp-10h]

  p_Members = &this->Members;
  pTable = this->Members.mHash.pTable;
  v5 = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    v9 = 0i64;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v9;
      v8 += 3;
    }
    while ( v9 <= SizeMask );
    v35 = p_Members;
    v37 = v9;
  }
  else
  {
    v35 = 0i64;
    v37 = 0i64;
  }
  v10 = v37;
  while ( v35 )
  {
    v11 = v35->mHash.pTable;
    if ( !v35->mHash.pTable || v10 > (signed __int64)v11->SizeMask )
      break;
    v12 = &v11[3 * v10];
    EntryCount = v12[2].EntryCount;
    if ( EntryCount == 8 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v12[2].SizeMask,
        prcc);
      goto LABEL_20;
    }
    if ( EntryCount != 6 || (v14 = v12[2].SizeMask) == 0 )
    {
      if ( EntryCount != 9 )
        goto LABEL_20;
      v14 = v12[2].SizeMask;
    }
    v15 = ++*(_DWORD *)(v14 + 24);
    if ( (v15 & 0x70000000) != 0 )
    {
      v16 = v15 & 0x8FFFFFFF;
      *(_DWORD *)(v14 + 24) = v16;
      if ( (v16 & 0x8000000) != 0 )
      {
        *(_QWORD *)(*(_QWORD *)(v14 + 16) + 8i64) = *(_QWORD *)(v14 + 8);
        *(_QWORD *)(*(_QWORD *)(v14 + 8) + 16i64) = *(_QWORD *)(v14 + 16);
        *(_QWORD *)(v14 + 16) = *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0;
        *(_QWORD *)(v14 + 8) = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = v14;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v14;
      }
    }
LABEL_20:
    v17 = v35->mHash.pTable->SizeMask;
    if ( v10 <= (__int64)v17 && ++v10 <= v17 )
    {
      v18 = &v35->mHash.pTable[3 * v10 + 1];
      do
      {
        if ( v18->EntryCount != -2i64 )
          break;
        ++v10;
        v18 += 3;
      }
      while ( v10 <= v17 );
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->ResolveHandler,
    prcc);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    v20 = pWatchpoints->mHash.pTable;
    if ( pWatchpoints->mHash.pTable )
    {
      v21 = v20->SizeMask;
      v22 = v20 + 1;
      do
      {
        if ( v22->EntryCount != -2i64 )
          break;
        ++v5;
        v22 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v22 + 72);
      }
      while ( v5 <= v21 );
      v36 = this->pWatchpoints;
    }
    else
    {
      v36 = 0i64;
    }
    v23 = v5;
    while ( v36 )
    {
      v24 = v36->mHash.pTable;
      if ( !v36->mHash.pTable || v23 > (signed __int64)v24->SizeMask )
        break;
      v25 = (char *)v24 + 72 * v23;
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)(v25 + 32),
        prcc);
      v26 = v25[56];
      if ( v26 == 8 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          (Scaleform::GFx::AS2::FunctionRefBase *)(v25 + 64),
          prcc);
        goto LABEL_46;
      }
      if ( v26 != 6 || (v27 = *((_QWORD *)v25 + 8)) == 0 )
      {
        if ( v26 != 9 )
          goto LABEL_46;
        v27 = *((_QWORD *)v25 + 8);
      }
      v28 = ++*(_DWORD *)(v27 + 24);
      if ( (v28 & 0x70000000) != 0 )
      {
        v29 = v28 & 0x8FFFFFFF;
        *(_DWORD *)(v27 + 24) = v29;
        if ( (v29 & 0x8000000) != 0 )
        {
          *(_QWORD *)(*(_QWORD *)(v27 + 16) + 8i64) = *(_QWORD *)(v27 + 8);
          *(_QWORD *)(*(_QWORD *)(v27 + 8) + 16i64) = *(_QWORD *)(v27 + 16);
          *(_QWORD *)(v27 + 16) = *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0;
          *(_QWORD *)(v27 + 8) = prcc->pLastPtr->pRCC;
          *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = v27;
          prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v27;
        }
      }
LABEL_46:
      v30 = v36->mHash.pTable->SizeMask;
      if ( v23 <= (__int64)v30 && ++v23 <= v30 )
      {
        v31 = &v36->mHash.pTable[4 * v23 + 1].EntryCount + v23;
        do
        {
          if ( *v31 != -2i64 )
            break;
          ++v23;
          v31 += 9;
        }
        while ( v23 <= v30 );
      }
    }
  }
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    v33 = ++pObject->RefCount;
    if ( (v33 & 0x70000000) != 0 )
    {
      v34 = v33 & 0x8FFFFFFF;
      pObject->RefCount = v34;
      if ( (v34 & 0x8000000) != 0 )
      {
        pObject->pPrev->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::pRCC = pObject->pRCC;
        *(_QWORD *)pObject->pRCC->Roots.gap0 = pObject->pPrev;
        pObject->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        pObject->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
      }
    }
  }
}

// File Line: 213
// RVA: 0x6E89E0
void __fastcall Scaleform::GFx::AS2::Object::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Object *this,
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
        Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
  }
}

// File Line: 244
// RVA: 0x6F7330
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Object::GetValue(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Value *result)
{
  result->T.Type = 0;
  return result;
}

// File Line: 249
// RVA: 0x717AF0
char __fastcall Scaleform::GFx::AS2::Object::SetMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::ObjectInterface *v9; // rdi
  __int64 Index; // rdx
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> ****p_Pages; // rbx
  __int64 v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rax
  __int64 *v16; // r8
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  __int64 v18; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pHash; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::GFx::AS2::Value *v21; // rsi
  __int64 v23; // rax
  Scaleform::RefCountNTSImpl *v24; // rbx
  __int64 v25; // rcx
  __int64 v26; // rax
  Scaleform::GFx::AS2::Value *v27; // rbx
  char v28; // al
  Scaleform::GFx::AS2::Value *p_resultVal; // rcx
  char v30; // bl
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringNode *pNode; // r8
  Scaleform::GFx::AS2::FunctionRef *v33; // rax
  char v34; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v35; // rcx
  int v36; // edx
  Scaleform::GFx::ASStringNode *v37; // rcx
  unsigned int v38; // eax
  bool v39; // zf
  Scaleform::GFx::AS2::GlobalContext *pContext; // r8
  Scaleform::GFx::ASStringNode *pLower; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // rbx
  Scaleform::GFx::AS2::Object *v43; // rax
  Scaleform::GFx::InteractiveObject *v44; // rax
  Scaleform::GFx::AS2::FunctionRef *v45; // rax
  char v46; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v47; // rcx
  int v48; // edx
  Scaleform::GFx::ASStringNode *v49; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::InteractiveObject *Target; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+38h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> ****v53; // [rsp+48h] [rbp-39h] BYREF
  __int64 v54; // [rsp+50h] [rbp-31h]
  Scaleform::GFx::AS2::Value v55; // [rsp+58h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value resultVal; // [rsp+78h] [rbp-9h] BYREF
  char PropFlags; // [rsp+E0h] [rbp+5Fh] BYREF
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+E8h] [rbp+67h] BYREF

  if ( (_S10_15 & 1) == 0 )
  {
    _S10_15 |= 1u;
    notsetVal_0.T.Type = 10;
    atexit(Scaleform::GFx::AS2::Object::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__);
  }
  PropFlags = 0;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->16,
    &result,
    name,
    penv->StringContext.SWFVersion > 6u);
  v9 = 0i64;
  Index = result.Index;
  if ( !result.pHash || !result.pHash->pTable || result.Index > (signed __int64)result.pHash->pTable->SizeMask )
  {
    pRCC = this->pRCC;
    if ( pRCC )
    {
      while ( 1 )
      {
        if ( LOBYTE(pRCC->ListRoot.RefCount) )
        {
          p_Pages = &pRCC->Roots.Pages;
          if ( penv->StringContext.SWFVersion <= 6u )
          {
            key.pStr = name;
            if ( !name->pNode->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
            if ( *p_Pages
              && (v15 = (Scaleform::GFx::ASStringNode *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pRCC->Roots.Pages,
                                                          &key,
                                                          name->pNode->HashFlags & (unsigned __int64)(*p_Pages)[1]),
                  (__int64)v15 >= 0) )
            {
              *(_QWORD *)&v55.T.Type = &pRCC->Roots.Pages;
              v55.V.pStringNode = v15;
            }
            else
            {
              *(_OWORD *)&v55.T.Type = 0ui64;
            }
            v14 = &v55;
          }
          else
          {
            if ( *p_Pages
              && (v13 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pRCC->Roots.Pages,
                          name,
                          name->pNode->HashFlags & (unsigned __int64)(*p_Pages)[1]),
                  v13 >= 0) )
            {
              v53 = &pRCC->Roots.Pages;
              v54 = v13;
            }
            else
            {
              v53 = 0i64;
              v54 = 0i64;
            }
            v14 = (Scaleform::GFx::AS2::Value *)&v53;
          }
          v16 = *(__int64 **)&v14->T.Type;
          pStringNode = v14->V.pStringNode;
          if ( *(_QWORD *)&v14->T.Type )
          {
            v18 = *v16;
            if ( *v16 )
            {
              if ( (__int64)pStringNode <= *(_QWORD *)(v18 + 8) )
                break;
            }
          }
        }
        pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pRCC->Roots.MaxPages;
        if ( !pRCC )
          goto LABEL_28;
      }
      if ( *(_BYTE *)(v18 + 48i64 * (_QWORD)pStringNode + 32) == 9 )
      {
        pHash = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > **)&v14->T.Type;
        Index = (__int64)v14->V.pStringNode;
        goto LABEL_30;
      }
LABEL_28:
      Index = result.Index;
    }
  }
  pHash = result.pHash;
LABEL_30:
  if ( pHash && (pTable = pHash->pTable) != 0i64 && Index <= (signed __int64)pTable->SizeMask )
  {
    v21 = (Scaleform::GFx::AS2::Value *)&pTable[3 * Index + 2];
    PropFlags = v21->T.PropFlags;
    if ( (PropFlags & 4) != 0 )
      return 0;
    if ( v21->T.Type == 9 )
    {
      Scaleform::GFx::AS2::Value::Value(&v55, (Scaleform::GFx::AS2::Value *)&pTable[3 * Index + 2]);
      v23 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::LocalFrame **))this[-1].ResolveHandler.pLocalFrame->Env)(&this[-1].ResolveHandler.pLocalFrame);
      v24 = (Scaleform::RefCountNTSImpl *)v23;
      if ( v23 )
        ++*(_DWORD *)(v23 + 8);
      key.pStr = (Scaleform::GFx::ASString *)v23;
      if ( v23 )
      {
        v25 = v23 + 4i64 * *(unsigned __int8 *)(v23 + 109);
        v26 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 8i64))(v25);
        if ( v26 )
          v9 = (Scaleform::GFx::AS2::ObjectInterface *)(v26 + 8);
      }
      else if ( this != (Scaleform::GFx::AS2::Object *)32 )
      {
        v9 = (Scaleform::GFx::AS2::ObjectInterface *)this;
      }
      Scaleform::GFx::AS2::Value::SetPropertyValue(&v55, penv, v9, val);
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
      if ( v55.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v55);
      return 1;
    }
  }
  else
  {
    PropFlags = flags->Flags;
    v21 = 0i64;
  }
  resultVal.T.Type = 0;
  v27 = val;
  if ( this->Members.mHash.pTable )
  {
    v28 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(
            (Scaleform::GFx::AS2::Object *)((char *)this - 32),
            penv,
            name,
            val,
            &resultVal);
    p_resultVal = &resultVal;
    if ( !v28 )
      p_resultVal = val;
    v27 = p_resultVal;
  }
  if ( v21 )
  {
    if ( val->T.Type == 9 )
      LOBYTE(this->ResolveHandler.Function) = 1;
    if ( penv->StringContext.SWFVersion <= 6u )
    {
      if ( !name->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
      pContext = penv->StringContext.pContext;
      pLower = name->pNode->pLower;
      if ( (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl->vfptr != pLower )
      {
        if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pContext->pMovieRoot->pASMovieRoot.pObject[24].RefCount
                                              + 16i64) == pLower )
        {
          if ( val->T.Type != 10 )
          {
            v45 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&v55, penv);
            Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&this->RefCount, v45);
            v46 = *((_BYTE *)&v55.NV + 16);
            if ( (*(_BYTE *)(&v55.NV + 1) & 2) == 0 )
            {
              v47 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v55.T.Type;
              if ( *(_QWORD *)&v55.T.Type )
              {
                v48 = *(_DWORD *)(*(_QWORD *)&v55.T.Type + 24i64);
                if ( (v48 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&v55.T.Type + 24i64) = v48 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v47);
                  v46 = *((_BYTE *)&v55.NV + 16);
                }
              }
            }
            *(_QWORD *)&v55.T.Type = 0i64;
            if ( (v46 & 1) == 0 )
            {
              v49 = v55.V.pStringNode;
              if ( v55.V.pStringNode )
              {
                RefCount = v55.V.pStringNode->RefCount;
                if ( (RefCount & 0x3FFFFFF) != 0 )
                {
                  v55.V.pStringNode->RefCount = RefCount - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v49);
                }
              }
            }
LABEL_87:
            v55.V.pStringNode = 0i64;
          }
LABEL_88:
          v27 = &notsetVal_0;
          goto LABEL_93;
        }
        v39 = name->pNode == *(Scaleform::GFx::ASStringNode **)&pContext->pMovieRoot->pASMovieRoot.pObject[28].RefCount;
LABEL_90:
        if ( v39 )
        {
          Target = penv->Target;
          if ( Target )
            Target->pASRoot->pMovieImpl->Flags |= 0x80000u;
        }
        goto LABEL_93;
      }
    }
    else
    {
      pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      pNode = name->pNode;
      if ( name->pNode != (Scaleform::GFx::ASStringNode *)pObject[23].pMovieImpl )
      {
        if ( pNode == *(Scaleform::GFx::ASStringNode **)&pObject[24].RefCount )
        {
          if ( val->T.Type != 10 )
          {
            v33 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&v55, penv);
            Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&this->RefCount, v33);
            v34 = *((_BYTE *)&v55.NV + 16);
            if ( (*(_BYTE *)(&v55.NV + 1) & 2) == 0 )
            {
              v35 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v55.T.Type;
              if ( *(_QWORD *)&v55.T.Type )
              {
                v36 = *(_DWORD *)(*(_QWORD *)&v55.T.Type + 24i64);
                if ( (v36 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&v55.T.Type + 24i64) = v36 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v35);
                  v34 = *((_BYTE *)&v55.NV + 16);
                }
              }
            }
            *(_QWORD *)&v55.T.Type = 0i64;
            if ( (v34 & 1) == 0 )
            {
              v37 = v55.V.pStringNode;
              if ( v55.V.pStringNode )
              {
                v38 = v55.V.pStringNode->RefCount;
                if ( (v38 & 0x3FFFFFF) != 0 )
                {
                  v55.V.pStringNode->RefCount = v38 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v37);
                  v55.V.pStringNode = 0i64;
                  v27 = &notsetVal_0;
LABEL_93:
                  Scaleform::GFx::AS2::Value::operator=(v21, v27);
                  v30 = 1;
                  goto LABEL_94;
                }
              }
            }
            goto LABEL_87;
          }
          goto LABEL_88;
        }
        v39 = pNode == *(Scaleform::GFx::ASStringNode **)&pObject[28].RefCount;
        goto LABEL_90;
      }
    }
    if ( val->T.Type != 10 )
    {
      vfptr = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
      v43 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))vfptr[4].Finalize_GC)(
        this,
        &penv->StringContext,
        v43);
      v44 = penv->Target;
      if ( v44 )
        v44->pASRoot->pMovieImpl->Flags |= 0x80000u;
    }
    v27 = &notsetVal_0;
    goto LABEL_93;
  }
  v30 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].Finalize_GC)(
          this,
          &penv->StringContext,
          name,
          v27,
          &PropFlags);
LABEL_94:
  if ( resultVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
  return v30;
}

// File Line: 381
// RVA: 0x1587B70
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__notsetVal__()
{
  return atexit((int (__fastcall *)())Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__notsetVal__);
}

// File Line: 384
// RVA: 0x719C20
char __fastcall Scaleform::GFx::AS2::Object::SetMemberRaw(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::MovieImpl *v11; // rdx
  Scaleform::GFx::ASStringNode **v12; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v14; // rbx
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::FunctionRef *v16; // rax
  char v17; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  int v19; // edx
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int v21; // eax
  $AEF441711F8527ABAC4F0458E5B46D3D *v22; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // r8
  Scaleform::GFx::ASStringNode *v24; // rax
  Scaleform::GFx::MovieImpl *pMovieRoot; // rcx
  Scaleform::GFx::ASMovieRootBase *pObject; // rdx
  Scaleform::GFx::ASStringNode *pLower; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // rbx
  Scaleform::GFx::AS2::Object *v29; // rax
  Scaleform::GFx::AS2::FunctionRef *v30; // rax
  char v31; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // rcx
  int v33; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // r8
  __int64 v37; // rcx
  char v38; // bl
  Scaleform::GFx::AS2::Value result; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+80h] [rbp+30h] BYREF

  v9 = val;
  if ( !BYTE1(this->ResolveHandler.Function)
    && val->T.Type == 6
    && name->pNode == (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].vfptr )
  {
    v10 = Scaleform::GFx::AS2::Value::ToObject(val, 0i64);
    if ( v10 )
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v10->Scaleform::GFx::AS2::ObjectInterface) == 7 )
        BYTE1(this->ResolveHandler.Function) = 1;
    }
  }
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pMovieRoot = psc->pContext->pMovieRoot;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pLower = name->pNode->pLower;
    if ( (Scaleform::GFx::ASStringNode *)pObject[23].pMovieImpl->vfptr == pLower )
    {
      if ( val->T.Type != 10 )
      {
        vfptr = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
        v29 = Scaleform::GFx::AS2::Value::ToObject(val, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))vfptr[4].Finalize_GC)(
          this,
          psc,
          v29);
        if ( psc->pContext )
          psc->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v9 = &notsetVal;
    }
    else if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[24].RefCount + 16i64) == pLower )
    {
      if ( val->T.Type != 10 )
      {
        v30 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&result, 0i64);
        Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&this->RefCount, v30);
        v31 = *((_BYTE *)&result.NV + 16);
        if ( (*(_BYTE *)(&result.NV + 1) & 2) == 0 )
        {
          v32 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
          if ( *(_QWORD *)&result.T.Type )
          {
            v33 = *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64);
            if ( (v33 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64) = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
              v31 = *((_BYTE *)&result.NV + 16);
            }
          }
        }
        *(_QWORD *)&result.T.Type = 0i64;
        if ( (v31 & 1) == 0 )
        {
          pStringNode = result.V.pStringNode;
          if ( result.V.pStringNode )
          {
            RefCount = result.V.pStringNode->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              result.V.pStringNode->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        result.V.pStringNode = 0i64;
      }
      v9 = &notsetVal;
    }
    else if ( name->pNode == *(Scaleform::GFx::ASStringNode **)&pObject[28].RefCount && psc->pContext )
    {
      pMovieRoot->Flags |= 0x80000u;
    }
    key.pStr = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v22 = &this->16;
    pPrev = this->pPrev;
    if ( !pPrev )
      goto LABEL_58;
    v24 = (Scaleform::GFx::ASStringNode *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->16,
                                            &key,
                                            name->pNode->HashFlags & (__int64)pPrev->pRCC);
  }
  else
  {
    v11 = psc->pContext->pMovieRoot;
    v12 = (Scaleform::GFx::ASStringNode **)v11->pASMovieRoot.pObject;
    pNode = name->pNode;
    if ( name->pNode == v12[117] )
    {
      if ( val->T.Type != 10 )
      {
        v14 = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
        v15 = Scaleform::GFx::AS2::Value::ToObject(val, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v14[4].Finalize_GC)(
          this,
          psc,
          v15);
        if ( psc->pContext )
          psc->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v9 = &notsetVal;
    }
    else if ( pNode == v12[121] )
    {
      if ( val->T.Type != 10 )
      {
        v16 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&result, 0i64);
        Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&this->RefCount, v16);
        v17 = *((_BYTE *)&result.NV + 16);
        if ( (*(_BYTE *)(&result.NV + 1) & 2) == 0 )
        {
          v18 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
          if ( *(_QWORD *)&result.T.Type )
          {
            v19 = *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64);
            if ( (v19 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(*(_QWORD *)&result.T.Type + 24i64) = v19 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
              v17 = *((_BYTE *)&result.NV + 16);
            }
          }
        }
        *(_QWORD *)&result.T.Type = 0i64;
        if ( (v17 & 1) == 0 )
        {
          v20 = result.V.pStringNode;
          if ( result.V.pStringNode )
          {
            v21 = result.V.pStringNode->RefCount;
            if ( (v21 & 0x3FFFFFF) != 0 )
            {
              result.V.pStringNode->RefCount = v21 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v20);
            }
          }
        }
        result.V.pStringNode = 0i64;
      }
      v9 = &notsetVal;
    }
    else if ( pNode == v12[141] && psc->pContext )
    {
      v11->Flags |= 0x80000u;
    }
    v22 = &this->16;
    v23 = this->pPrev;
    if ( !v23 )
      goto LABEL_58;
    v24 = (Scaleform::GFx::ASStringNode *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                                            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->16,
                                            name,
                                            name->pNode->HashFlags & (__int64)v23->pRCC);
  }
  if ( (__int64)v24 >= 0 )
  {
    *(_QWORD *)&result.T.Type = v22;
    result.V.pStringNode = v24;
    goto LABEL_59;
  }
LABEL_58:
  *(_OWORD *)&result.T.Type = 0ui64;
LABEL_59:
  if ( val->T.Type == 9 )
    LOBYTE(this->ResolveHandler.Function) = 1;
  if ( *(_QWORD *)&result.T.Type
    && (v37 = **(_QWORD **)&result.T.Type) != 0
    && (__int64)result.V.pStringNode <= *(_QWORD *)(v37 + 8) )
  {
    Scaleform::GFx::AS2::Value::operator=(
      (Scaleform::GFx::AS2::Value *)(48 * (__int64)result.V.pStringNode + v37 + 32),
      v9);
  }
  else
  {
    v38 = flags->Flags;
    Scaleform::GFx::AS2::Value::Value(&result, v9);
    result.T.PropFlags = v38;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)v22,
      name,
      (Scaleform::GFx::AS2::Member *)&result);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
  }
  return 1;
}

// File Line: 517
// RVA: 0x6F3960
char __fastcall Scaleform::GFx::AS2::Object::GetMemberRaw(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // r14
  char v5; // bp
  bool v6; // cc
  char *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // r10
  Scaleform::GFx::ASMovieRootBase *v12; // rax
  __int64 v13; // r9
  __int64 v14; // rsi
  __int64 v15; // r11
  __int64 v16; // rdx
  __int64 *v17; // r8
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rdx
  Scaleform::GFx::AS2::LocalFrame *v20; // rdx
  Scaleform::GFx::AS2::Value *v22; // rdx
  bool v23; // zf
  Scaleform::GFx::AS2::Value *v24; // rcx
  Scaleform::GFx::AS2::Object *v25; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASMovieRootBase *pObject; // rdx
  Scaleform::GFx::ASStringNode *pLower; // rcx
  __int64 v29; // rax
  char *v30; // rsi
  signed __int64 v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rdx
  Scaleform::GFx::AS2::LocalFrame *v33; // rdx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+50h] [rbp+8h] BYREF

  p_pLocalFrame = &this[-1].ResolveHandler.pLocalFrame;
  v5 = 0;
  v6 = psc->SWFVersion <= 6u;
  key.pStr = (Scaleform::GFx::ASString *)&this[-1].ResolveHandler.pLocalFrame;
  v10 = (char *)&this[-1].ResolveHandler.pLocalFrame;
  if ( v6 )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    key.pStr = name;
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    if ( v10 )
    {
      while ( 1 )
      {
        pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
        pLower = name->pNode->pLower;
        if ( (Scaleform::GFx::ASStringNode *)pObject[23].pMovieImpl->vfptr == pLower )
          goto LABEL_31;
        if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[24].RefCount + 16i64) == pLower )
        {
LABEL_29:
          v24 = val;
          if ( !*((_QWORD *)v10 + 7) )
            goto LABEL_33;
          Scaleform::GFx::AS2::Value::SetAsFunction(val, (Scaleform::GFx::AS2::FunctionRefBase *)(v10 + 56));
          return 1;
        }
        v29 = *((_QWORD *)v10 + 6);
        v30 = v10 + 48;
        if ( v29 )
        {
          v31 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v10
                + 6,
                  &key,
                  *(_QWORD *)(v29 + 8) & name->pNode->HashFlags);
          if ( v31 >= 0 && v10 != (char *)-48i64 && *(_QWORD *)v30 && v31 <= *(_QWORD *)(*(_QWORD *)v30 + 8i64) )
          {
            v22 = (Scaleform::GFx::AS2::Value *)(48 * v31 + *(_QWORD *)v30 + 32i64);
            if ( v22->T.Type != 10 )
              goto LABEL_28;
            v23 = v10 == (char *)p_pLocalFrame;
LABEL_26:
            if ( !v23 )
              return (*(__int64 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*((_QWORD *)v10 + 4) + 88i64))(
                       v10 + 32,
                       psc,
                       name,
                       val);
LABEL_28:
            Scaleform::GFx::AS2::Value::operator=(val, v22);
            return 1;
          }
        }
        if ( !v5 && *((_QWORD *)v10 + 7) )
        {
          Scaleform::GFx::AS2::Value::DropRefs(val);
          val->T.Type = 12;
          val->V.FunctionValue.Flags = 0;
          v32 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)v10 + 7);
          val->V.pStringNode = v32;
          if ( v32 )
            v32->RefCount = (v32->RefCount + 1) & 0x8FFFFFFF;
          val->V.FunctionValue.pLocalFrame = 0i64;
          v33 = (Scaleform::GFx::AS2::LocalFrame *)*((_QWORD *)v10 + 8);
          if ( v33 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&val->V.FunctionValue, v33, v10[72] & 1);
          v5 = 1;
        }
        v10 = (char *)*((_QWORD *)v10 + 5);
        if ( !v10 )
          return 0;
      }
    }
    return 0;
  }
  if ( this == (Scaleform::GFx::AS2::Object *)32 )
    return 0;
  while ( 1 )
  {
    v11 = name->pNode;
    v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( name->pNode == (Scaleform::GFx::ASStringNode *)v12[23].pMovieImpl )
      break;
    if ( v11 == *(Scaleform::GFx::ASStringNode **)&v12[24].RefCount )
      goto LABEL_29;
    v13 = *((_QWORD *)v10 + 6);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 8);
      v15 = (unsigned int)v14 & v11->HashFlags;
      v16 = v15;
      v17 = (__int64 *)(48 * v15 + v13 + 16);
      if ( *v17 != -2 && ((unsigned int)v14 & *(_DWORD *)(v17[1] + 28)) == v15 )
      {
        while ( 1 )
        {
          v18 = (Scaleform::GFx::ASStringNode *)v17[1];
          if ( ((unsigned int)v14 & v18->HashFlags) == v15 && v18 == v11 )
            break;
          v16 = *v17;
          if ( *v17 == -1 )
            goto LABEL_15;
          v17 = (__int64 *)(48 * v16 + v13 + 16);
        }
        if ( v16 >= 0 && v10 != (char *)-48i64 && v16 <= v14 )
        {
          v22 = (Scaleform::GFx::AS2::Value *)(48 * v16 + v13 + 32);
          if ( v22->T.Type != 10 )
            goto LABEL_28;
          v23 = v10 == (char *)key.pStr;
          goto LABEL_26;
        }
      }
    }
LABEL_15:
    if ( !v5 && *((_QWORD *)v10 + 7) )
    {
      Scaleform::GFx::AS2::Value::DropRefs(val);
      val->T.Type = 12;
      val->V.FunctionValue.Flags = 0;
      v19 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)v10 + 7);
      val->V.pStringNode = v19;
      if ( v19 )
        v19->RefCount = (v19->RefCount + 1) & 0x8FFFFFFF;
      val->V.FunctionValue.pLocalFrame = 0i64;
      v20 = (Scaleform::GFx::AS2::LocalFrame *)*((_QWORD *)v10 + 8);
      if ( v20 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&val->V.FunctionValue, v20, v10[72] & 1);
      v5 = 1;
    }
    v10 = (char *)*((_QWORD *)v10 + 5);
    if ( !v10 )
      return 0;
  }
LABEL_31:
  v25 = (Scaleform::GFx::AS2::Object *)*((_QWORD *)v10 + 5);
  v24 = val;
  if ( v25 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(val, v25);
    return 1;
  }
  else
  {
LABEL_33:
    Scaleform::GFx::AS2::Value::DropRefs(v24);
    val->T.Type = 0;
    return 1;
  }
}

// File Line: 648
// RVA: 0x6EB120
bool __fastcall Scaleform::GFx::AS2::Object::FindMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Member *pmember)
{
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324> > *v4; // rcx

  v4 = (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->16;
  if ( psc->SWFVersion > 6u )
    return Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Get(
             v4,
             name,
             pmember);
  else
    return Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
             v4,
             name,
             pmember);
}

// File Line: 655
// RVA: 0x6E21A0
char __fastcall Scaleform::GFx::AS2::Object::DeleteMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  $AEF441711F8527ABAC4F0458E5B46D3D *v3; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v6; // rax
  __int64 Index; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::GFx::MovieImpl *pMovieRoot; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+20h] [rbp-18h] BYREF

  v3 = &this->16;
  v6 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
         (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->16,
         &result,
         name,
         psc->SWFVersion > 6u);
  Index = v6->Index;
  if ( !v6->pHash )
    return 0;
  pTable = v6->pHash->pTable;
  if ( !pTable || Index > (signed __int64)pTable->SizeMask || (pTable[3 * Index + 2].EntryCount & 0x200) != 0 )
    return 0;
  pMovieRoot = psc->pContext->pMovieRoot;
  if ( name->pNode == *(Scaleform::GFx::ASStringNode **)&pMovieRoot->pASMovieRoot.pObject[28].RefCount )
  {
    if ( psc->pContext )
      pMovieRoot->Flags |= 0x80000u;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v3,
    name);
  return 1;
}

// File Line: 673
// RVA: 0x7199D0
__int64 __fastcall Scaleform::GFx::AS2::Object::SetMemberFlags(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        char flags)
{
  unsigned __int8 v7; // bl
  Scaleform::GFx::AS2::Member value; // [rsp+28h] [rbp-30h] BYREF

  value.mValue.T = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *, __int64))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[1].~RefCountBaseGC<323>)(
         this,
         psc,
         name,
         &value,
         -2i64) )
  {
    value.mValue.T.PropFlags = flags;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)&this->16,
      name,
      &value);
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( value.mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value.mValue);
  return v7;
}

// File Line: 691
// RVA: 0x724130
void __fastcall Scaleform::GFx::AS2::Object::VisitMembers(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        Scaleform::GFx::AS2::ObjectInterface *instance)
{
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v6; // r14
  $AEF441711F8527ABAC4F0458E5B46D3D *v8; // r11
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // r10
  Scaleform::GFx::AS2::Object *v10; // r15
  Scaleform::GFx::ASStringNode *v11; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v12; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v13; // rbp
  __int64 pStringNode; // rdi
  __int64 *v15; // rsi
  __int64 v16; // rax
  __int64 v17; // r14
  __int64 v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r8
  char v20; // bl
  Scaleform::GFx::AS2::Object *v21; // rcx
  Scaleform::GFx::ASString *v22; // rdx
  unsigned __int64 v23; // rcx
  _QWORD *v24; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // rcx
  Scaleform::GFx::AS2::Value v26; // [rsp+40h] [rbp-58h] BYREF

  v6 = pvisitor;
  v8 = &this->16;
  pPrev = this->pPrev;
  v10 = 0i64;
  if ( pPrev )
  {
    v11 = 0i64;
    v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)&pPrev->16;
    do
    {
      if ( *v12 != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)-2i64 )
        break;
      v11 = (Scaleform::GFx::ASStringNode *)((char *)v11 + 1);
      v12 += 6;
    }
    while ( (Scaleform::GFx::AS2::RefCountCollector<323> *)v11 <= pPrev->pRCC );
    *(_QWORD *)&v26.T.Type = v8;
    v26.V.pStringNode = v11;
  }
  else
  {
    *(_OWORD *)&v26.T.Type = 0ui64;
  }
  v13 = instance;
  pStringNode = (__int64)v26.V.pStringNode;
  v15 = *(__int64 **)&v26.T.Type;
  while ( v15 )
  {
    v16 = *v15;
    if ( !*v15 || pStringNode > *(_QWORD *)(v16 + 8) )
      break;
    v17 = 48 * pStringNode;
    v18 = 48 * pStringNode + v16;
    v19 = (Scaleform::GFx::AS2::Value *)(v18 + 32);
    v20 = *(_BYTE *)(v18 + 33);
    if ( (v20 & 1) != 0 && (visitFlags & 4) == 0 )
    {
      v6 = pvisitor;
    }
    else if ( v19->T.Type == 10 )
    {
      v26.T.Type = 0;
      if ( (visitFlags & 8) == 0 )
      {
        if ( instance )
        {
          v21 = (Scaleform::GFx::AS2::Object *)instance;
        }
        else
        {
          v21 = 0i64;
          if ( this != (Scaleform::GFx::AS2::Object *)32 )
            v21 = this;
        }
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, __int64, Scaleform::GFx::AS2::Value *))v21->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
          v21,
          psc,
          v17 + *v15 + 24,
          &v26);
      }
      v22 = (Scaleform::GFx::ASString *)(v17 + *v15 + 24);
      v6 = pvisitor;
      pvisitor->vfptr->Visit(pvisitor, v22, &v26, v20);
      if ( v26.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v26);
    }
    else
    {
      v6 = pvisitor;
      pvisitor->vfptr->Visit(pvisitor, (Scaleform::GFx::ASString *)(v18 + 24), v19, v20);
    }
    v23 = *(_QWORD *)(*v15 + 8);
    if ( pStringNode <= (__int64)v23 && ++pStringNode <= v23 )
    {
      v24 = (_QWORD *)(*v15 + 48 * pStringNode + 16);
      do
      {
        if ( *v24 != -2i64 )
          break;
        ++pStringNode;
        v24 += 6;
      }
      while ( pStringNode <= v23 );
    }
  }
  if ( (visitFlags & 1) != 0 )
  {
    pRCC = this->pRCC;
    if ( pRCC )
    {
      if ( !instance )
      {
        if ( this != (Scaleform::GFx::AS2::Object *)32 )
          v10 = this;
        v13 = (Scaleform::GFx::AS2::ObjectInterface *)v10;
      }
      (*(void (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, _QWORD, Scaleform::GFx::AS2::ObjectInterface *))(pRCC->Roots.NumPages + 64))(
        &pRCC->Roots.NumPages,
        psc,
        v6,
        visitFlags,
        v13);
    }
  }
}Roots.NumPages + 64))(
   

// File Line: 726
// RVA: 0x6FB550
__int64 __fastcall Scaleform::GFx::AS2::Object::HasMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        __int64 inclPrototypes)
{
  char v4; // bp
  char Type; // di
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v10; // rbx
  __int64 v11; // rax
  __int64 p_SizeMask; // rbx
  Scaleform::GFx::AS2::Value *v13; // rbx
  unsigned __int8 v14; // bl
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // rcx
  Scaleform::GFx::AS2::Value v17; // [rsp+28h] [rbp-40h] BYREF

  v4 = inclPrototypes;
  Type = 0;
  v17.T = 0;
  v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->16;
  v10.pTable = v9->pTable;
  if ( v9->pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v9,
                name,
                name->pNode->HashFlags & v10.pTable->SizeMask),
        v11 >= 0)
    && (p_SizeMask = (__int64)&v10.pTable[3 * v11 + 1].SizeMask) != 0 )
  {
    v13 = (Scaleform::GFx::AS2::Value *)(p_SizeMask + 8);
    Scaleform::GFx::AS2::Value::operator=(&v17, v13);
    v17.T.PropFlags = v13->T.PropFlags;
    v14 = 1;
    Type = v17.T.Type;
  }
  else if ( v4 && (pRCC = this->pRCC) != 0i64 )
  {
    LOBYTE(inclPrototypes) = 1;
    v14 = (*(__int64 (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64, __int64))(pRCC->Roots.NumPages + 72))(
            &pRCC->Roots.NumPages,
            psc,
            name,
            inclPrototypes,
            -2i64);
  }
  else
  {
    v14 = 0;
  }
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  return v14;
}

// File Line: 740
// RVA: 0x6FDA80
char __fastcall Scaleform::GFx::AS2::Object::InstanceOf(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *prototype,
        bool inclInterfaces)
{
  Scaleform::GFx::AS2::Object *pObject; // rbx

  pObject = (Scaleform::GFx::AS2::Object *)((char *)this - 32);
  if ( this != (Scaleform::GFx::AS2::Object *)32 )
  {
    do
    {
      if ( inclInterfaces )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[1].~RefCountBaseGC<323>)(
               pObject,
               penv,
               prototype) )
        {
          return 1;
        }
      }
      else if ( pObject == prototype )
      {
        return 1;
      }
      pObject = pObject->pProto.pObject;
    }
    while ( pObject );
  }
  return 0;
}

// File Line: 756
// RVA: 0x7245A0
char __fastcall Scaleform::GFx::AS2::Object::Watch(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *prop,
        Scaleform::GFx::AS2::FunctionRef *callback,
        Scaleform::GFx::AS2::Value *userData)
{
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  char *v12; // rbx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v17; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-20h] BYREF

  memset(&orig, 0, 17);
  v.T.Type = 0;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, callback);
  Scaleform::GFx::AS2::Value::operator=(&v, userData);
  if ( !this->Members.mHash.pTable )
  {
    v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)psc->pContext->pHeap->vfptr->Alloc(v8, 8i64, 0i64);
    if ( v9 )
    {
      result.pHash = v9;
      v9->pTable = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    this->Members.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)v9;
  }
  pTable = this->Members.mHash.pTable;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)pTable,
    &result,
    prop,
    psc->SWFVersion > 6u);
  if ( result.pHash && (v11 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v11->SizeMask )
  {
    v12 = (char *)v11 + 72 * result.Index;
    Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)(v12 + 32), &orig);
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)(v12 + 56), &v);
  }
  else
  {
    result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)prop;
    result.Index = (__int64)&orig;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pTable,
      pTable,
      (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
      prop->pNode->HashFlags);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  Flags = orig.Flags;
  if ( (orig.Flags & 2) == 0 )
  {
    Function = orig.Function;
    if ( orig.Function )
    {
      RefCount = orig.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        orig.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = orig.Flags;
      }
    }
  }
  orig.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = orig.pLocalFrame;
    if ( orig.pLocalFrame )
    {
      v17 = orig.pLocalFrame->RefCount;
      if ( (v17 & 0x3FFFFFF) != 0 )
      {
        orig.pLocalFrame->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  return 1;
}

// File Line: 770
// RVA: 0x722D00
char __fastcall Scaleform::GFx::AS2::Object::Unwatch(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *prop)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > v7; // rsi
  __int64 v8; // rax
  unsigned __int64 *v9; // rax
  Scaleform::GFx::AS2::Object::Watchpoint *CaseInsensitive; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rsi
  Scaleform::GFx::ASString *v12; // rbx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+40h] [rbp+8h] BYREF

  pTable = this->Members.mHash.pTable;
  if ( !pTable )
    return 0;
  if ( psc->SWFVersion <= 6u )
  {
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)pTable,
                        prop);
  }
  else
  {
    v7.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)pTable->EntryCount;
    if ( !pTable->EntryCount )
      return 0;
    v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pTable,
           prop,
           prop->pNode->HashFlags & v7.mHash.pTable->SizeMask);
    if ( v8 < 0 )
      return 0;
    v9 = &v7.mHash.pTable[1].SizeMask + 9 * v8;
    if ( !v9 )
      return 0;
    CaseInsensitive = (Scaleform::GFx::AS2::Object::Watchpoint *)(v9 + 1);
  }
  if ( !CaseInsensitive )
    return 0;
  v11 = this->Members.mHash.pTable;
  if ( psc->SWFVersion <= 6u )
  {
    key.pStr = prop;
    if ( !prop->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(prop->pNode);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString::NoCaseKey>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v11,
      &key);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->Members.mHash.pTable,
      prop);
  }
  v12 = (Scaleform::GFx::ASString *)this->Members.mHash.pTable;
  if ( !v12->pNode || !v12->pNode->pData )
  {
    key.pStr = (Scaleform::GFx::ASString *)this->Members.mHash.pTable;
    if ( v12 )
    {
      key.pStr = v12;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v12);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
    }
    this->Members.mHash.pTable = 0i64;
  }
  return 1;
}

// File Line: 788
// RVA: 0x6FFBA0
__int64 __fastcall Scaleform::GFx::AS2::Object::InvokeWatchpoint(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *prop,
        Scaleform::GFx::AS2::Value *newVal,
        Scaleform::GFx::AS2::Value *resultVal)
{
  Scaleform::GFx::AS2::ObjectInterface *v9; // r12
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > v11; // rbx
  __int64 v12; // rax
  __int64 v13; // r14
  Scaleform::GFx::AS2::Object::Watchpoint *CaseInsensitive; // r14
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  char vfptr; // di
  __int64 v17; // rax
  Scaleform::RefCountNTSImpl *v18; // rdi
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // r9
  int v22; // edx
  int v23; // esi
  int v24; // edx
  unsigned __int8 v25; // bl
  Scaleform::GFx::AS2::FnCall v27; // [rsp+20h] [rbp-71h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+60h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-11h] BYREF
  __int64 v30; // [rsp+A0h] [rbp+Fh]

  v30 = -2i64;
  v.T.Type = 0;
  v9 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    penv,
    prop,
    &v);
  v28.T.Type = 0;
  pWatchpoints = this->pWatchpoints;
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        pWatchpoints,
                        prop);
  }
  else
  {
    v11.mHash.pTable = pWatchpoints->mHash.pTable;
    if ( !pWatchpoints->mHash.pTable )
      goto LABEL_43;
    v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            &pWatchpoints->mHash,
            prop,
            prop->pNode->HashFlags & v11.mHash.pTable->SizeMask);
    if ( v12 < 0 )
      goto LABEL_43;
    v13 = (__int64)(&v11.mHash.pTable[1].SizeMask + 9 * v12);
    if ( !v13 )
      goto LABEL_43;
    CaseInsensitive = (Scaleform::GFx::AS2::Object::Watchpoint *)(v13 + 8);
  }
  if ( !CaseInsensitive || !this->pWatchpoints )
  {
LABEL_43:
    v25 = 0;
    goto LABEL_44;
  }
  p_Stack = &penv->Stack;
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  if ( p_Stack->pCurrent )
    Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &CaseInsensitive->UserData);
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  if ( p_Stack->pCurrent )
    Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, newVal);
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  if ( p_Stack->pCurrent )
    Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &v);
  vfptr = 5;
  LOBYTE(v27.vfptr) = 5;
  v27.Result = (Scaleform::GFx::AS2::Value *)prop->pNode;
  ++*((_DWORD *)&v27.Result->NV + 6);
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  if ( p_Stack->pCurrent )
  {
    Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, (Scaleform::GFx::AS2::Value *)&v27);
    vfptr = (char)v27.vfptr;
  }
  if ( (unsigned __int8)vfptr >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v27);
  v17 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[2].Finalize_GC)(this);
  v18 = (Scaleform::RefCountNTSImpl *)v17;
  if ( v17 )
    ++*(_DWORD *)(v17 + 8);
  if ( v17 )
  {
    v19 = v17 + 4i64 * *(unsigned __int8 *)(v17 + 109);
    v20 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 8i64))(v19);
    v21 = v20 + 8;
    if ( !v20 )
      v21 = 0i64;
    v22 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    v27.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
    v27.Result = &v28;
    *(_OWORD *)&v27.ThisPtr = (unsigned __int64)v21;
    v27.ThisFunctionRef.Flags = 0;
    v27.ThisFunctionRef.pLocalFrame = 0i64;
    v27.Env = penv;
    v23 = 4;
    v27.NArgs = 4;
    v27.FirstArgBottomIndex = v22;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))CaseInsensitive->Callback.Function->vfptr[3].Finalize_GC)(
      CaseInsensitive->Callback.Function,
      &v27,
      CaseInsensitive->Callback.pLocalFrame,
      0i64);
  }
  else
  {
    v24 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    v27.vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
    v27.Result = &v28;
    *(_OWORD *)&v27.ThisPtr = (unsigned __int64)v9;
    v27.ThisFunctionRef.Flags = 0;
    v27.ThisFunctionRef.pLocalFrame = 0i64;
    v27.Env = penv;
    v23 = 4;
    v27.NArgs = 4;
    v27.FirstArgBottomIndex = v24;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))CaseInsensitive->Callback.Function->vfptr[3].Finalize_GC)(
      CaseInsensitive->Callback.Function,
      &v27,
      CaseInsensitive->Callback.pLocalFrame,
      0i64);
  }
  Scaleform::GFx::AS2::FnCall::~FnCall(&v27);
  do
  {
    if ( p_Stack->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
    --p_Stack->pCurrent;
    if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
    --v23;
  }
  while ( v23 );
  Scaleform::GFx::AS2::Value::operator=(resultVal, &v28);
  if ( v18 )
    Scaleform::RefCountNTSImpl::Release(v18);
  v25 = 1;
LABEL_44:
  if ( v28.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v28);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v25;
}

// File Line: 826
// RVA: 0x6D1650
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(Scaleform::GFx::AS2::GASPrototypeBase *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // rdi
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::LocalFrame *v9; // rcx
  unsigned int v10; // eax

  this->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>(&pInterfaces->Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pInterfaces);
  }
  if ( (this->__Constructor__.Flags & 2) == 0 )
  {
    Function = this->__Constructor__.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  this->__Constructor__.Function = 0i64;
  if ( (this->__Constructor__.Flags & 1) == 0 )
  {
    pLocalFrame = this->__Constructor__.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->__Constructor__.pLocalFrame = 0i64;
  if ( (this->Constructor.Flags & 2) == 0 )
  {
    v7 = this->Constructor.Function;
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
  this->Constructor.Function = 0i64;
  if ( (this->Constructor.Flags & 1) == 0 )
  {
    v9 = this->Constructor.pLocalFrame;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  this->Constructor.pLocalFrame = 0i64;
}

// File Line: 836
// RVA: 0x6FD0E0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::NameFunction *funcTable,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Object *v10; // rbp
  __int64 v11; // r14
  Scaleform::GFx::AS2::NameFunction *v12; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v13; // r13
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rbx
  void (__fastcall *Function)(Scaleform::GFx::AS2::FnCall *); // rdi
  Scaleform::GFx::ASString *v17; // rax
  unsigned int RefCount; // eax
  unsigned int v20; // eax
  Scaleform::GFx::AS2::Value v21; // [rsp+60h] [rbp-58h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+18h] BYREF
  Scaleform::GFx::AS2::Object *v23; // [rsp+D8h] [rbp+20h]

  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  v10 = Prototype;
  if ( Prototype )
    Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
  v23 = Prototype;
  v11 = 0i64;
  if ( funcTable->Name )
  {
    v12 = funcTable;
    v13 = &pthis->Scaleform::GFx::AS2::ObjectInterface;
    do
    {
      v14 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::ASStringNode *, __int64))psc->pContext->pHeap->vfptr->Alloc)(
                                             pNode,
                                             104i64);
      v15 = v14;
      if ( v14 )
      {
        Function = v12->Function;
        Scaleform::GFx::AS2::Object::Object(v14, psc);
        v15->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
        v15->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
        v15->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
        v15->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
        v15[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Function;
        Scaleform::GFx::AS2::Object::Set__proto__(
          (Scaleform::GFx::AS2::Object *)&v15->Scaleform::GFx::AS2::ObjectInterface,
          psc,
          v10);
      }
      else
      {
        v15 = 0i64;
      }
      v21.T.Type = 8;
      v21.V.FunctionValue.Flags = 0;
      v21.V.pStringNode = (Scaleform::GFx::ASStringNode *)v15;
      if ( v15 )
        v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
      v21.V.FunctionValue.pLocalFrame = 0i64;
      v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, v12->Name);
      v13->vfptr->SetMemberRaw(v13, psc, v17, &v21, flags);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      if ( v15 )
      {
        RefCount = v15->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v15->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
        }
      }
      v12 = &funcTable[++v11];
    }
    while ( v12->Name );
  }
  if ( v10 )
  {
    v20 = v10->RefCount;
    if ( (v20 & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
}

// File Line: 851
// RVA: 0x6FBAB0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::Init(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::FunctionObject *Function; // rbx
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Value ctor; // [rsp+38h] [rbp-30h] BYREF
  char v11; // [rsp+70h] [rbp+8h] BYREF

  ctor.T.Type = 8;
  ctor.V.FunctionValue.Flags = 0;
  ctor.V.pStringNode = (Scaleform::GFx::ASStringNode *)constructor->Function;
  if ( ctor.V.pStringNode )
    ctor.V.pStringNode->RefCount = (ctor.V.pStringNode->RefCount + 1) & 0x8FFFFFFF;
  ctor.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = constructor->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&ctor.V.FunctionValue, pLocalFrame, constructor->Flags & 1);
  Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(this, pthis, psc, &ctor);
  if ( ctor.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ctor);
  v11 = 3;
  Function = this->Constructor.Function;
  Scaleform::GFx::AS2::Value::Value(&ctor, (Scaleform::GFx::ASStringNode *)pthis);
  Function->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &Function->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v9,
    (Scaleform::GFx::AS2::PropFlags *)&v11);
  if ( ctor.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ctor);
}

// File Line: 858
// RVA: 0x713510
char __fastcall Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *ctor)
{
  Scaleform::GFx::AS2::FunctionRef *v7; // rax
  char Flags; // dl
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::FunctionRef v14; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v15; // [rsp+50h] [rbp-28h] BYREF
  char v16; // [rsp+80h] [rbp+8h] BYREF

  v7 = Scaleform::GFx::AS2::Value::ToFunction(ctor, &v14, 0i64);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->Constructor, v7);
  Flags = v14.Flags;
  if ( (v14.Flags & 2) == 0 )
  {
    Function = v14.Function;
    if ( v14.Function )
    {
      RefCount = v14.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v14.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = v14.Flags;
      }
    }
  }
  v14.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = v14.pLocalFrame;
    if ( v14.pLocalFrame )
    {
      v12 = v14.pLocalFrame->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        v14.pLocalFrame->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  v14.pLocalFrame = 0i64;
  v16 = 3;
  v15.T.Type = 10;
  pthis->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pthis->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
    &v15,
    (Scaleform::GFx::AS2::PropFlags *)&v16);
  if ( v15.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v15);
  return 1;
}

// File Line: 866
// RVA: 0x6D85D0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        int index,
        Scaleform::GFx::AS2::FunctionObject *pinterface)
{
  unsigned __int64 v4; // rsi
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rax
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v10; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value v14; // [rsp+38h] [rbp-30h] BYREF

  v4 = index;
  if ( this->pInterfaces || pinterface )
  {
    v14.T.Type = 0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, __int64))pinterface->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
           &pinterface->Scaleform::GFx::AS2::ObjectInterface,
           psc,
           &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v14,
           -2i64) )
    {
      v8 = Scaleform::GFx::AS2::Value::ToObject(&v14, 0i64);
      v9 = v8;
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      v10 = &this->pInterfaces->Data.Data[v4];
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      pObject = v10->pObject;
      if ( v10->pObject )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      v10->pObject = (Scaleform::GFx::AS2::Object *)v9;
      if ( v9 )
      {
        v13 = v9->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
    }
    if ( v14.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v14);
  }
  else
  {
    v6 = (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)psc->pContext->pHeap->vfptr->Alloc(this, 24i64, 0i64);
    v7 = (Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *)v6;
    if ( v6 )
    {
      v6->Data = 0i64;
      v6->Size = 0i64;
      v6->Policy.Capacity = 0i64;
      Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        v6,
        v4);
    }
    else
    {
      v7 = 0i64;
    }
    this->pInterfaces = v7;
  }
}

// File Line: 881
// RVA: 0x6E2BD0
char __fastcall Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *prototype,
        __int64 a4)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // rax
  int v8; // edi
  unsigned __int64 Size; // rbp
  __int64 i; // rsi
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v11; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *Data; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rbx
  unsigned int RefCount; // eax
  unsigned int v16; // eax
  __int64 v18; // [rsp+20h] [rbp-38h]

  v18 = -2i64;
  pInterfaces = this->pInterfaces;
  if ( !pInterfaces )
    return 0;
  v8 = 0;
  Size = pInterfaces->Data.Size;
  if ( !(_DWORD)Size )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    v11 = this->pInterfaces;
    Data = v11->Data.Data;
    pObject = v11->Data.Data[i].pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v14 = Data[i].pObject;
    if ( v14 )
    {
      LOBYTE(a4) = 1;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *, __int64, __int64))v14[1].vfptr[6].ExecuteForEachChild_GC)(
             &v14[1],
             penv,
             prototype,
             a4,
             v18) )
      {
        break;
      }
    }
    if ( v14 )
    {
      RefCount = v14->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v14->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
      }
    }
    if ( ++v8 >= (unsigned int)Size )
      return 0;
  }
  v16 = v14->RefCount;
  if ( (v16 & 0x3FFFFFF) != 0 )
  {
    v14->RefCount = v16 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
  }
  return 1;
}

// File Line: 895
// RVA: 0x6F40C0
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  char Type; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rax
  bool v11; // zf
  unsigned __int64 *p_SizeMask; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r8
  signed __int64 v14; // rax
  __int64 v15; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rbx
  Scaleform::GFx::AS2::FunctionRef *Constructor; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::LocalFrame *v24; // rdi
  Scaleform::GFx::ASStringNode *v25; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned __int8 v27; // bl
  unsigned int v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // eax
  Scaleform::GFx::AS2::FunctionRefBase v32; // [rsp+0h] [rbp-59h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+18h] [rbp-41h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::Value v35; // [rsp+50h] [rbp-9h] BYREF
  __int64 v36; // [rsp+70h] [rbp+17h]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+B8h] [rbp+5Fh] BYREF
  Scaleform::GFx::AS2::ASStringContext *v38; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::AS2::Value *retaddr; // [rsp+D0h] [rbp+77h]
  char v40; // [rsp+D8h] [rbp+7Fh]

  v36 = -2i64;
  v.T = 0;
  Type = 10;
  v35.T.Type = 10;
  if ( psc->SWFVersion <= 6u )
  {
    key.pStr = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pTable = pthis->Members.mHash.pTable;
    if ( !pTable )
      goto LABEL_13;
    v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pthis->Members,
            &key,
            name->pNode->HashFlags & pTable->SizeMask);
    if ( v14 < 0 )
      goto LABEL_13;
    v15 = 3 * v14;
    v16 = pthis->Members.mHash.pTable;
    v11 = &v16[v15 + 1].SizeMask == 0i64;
    p_SizeMask = &v16[v15 + 1].SizeMask;
  }
  else
  {
    v8 = pthis->Members.mHash.pTable;
    if ( !v8 )
      goto LABEL_13;
    v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pthis->Members,
           name,
           name->pNode->HashFlags & v8->SizeMask);
    if ( v9 < 0 )
      goto LABEL_13;
    v10 = 3 * v9;
    v11 = &v8[v10 + 1].SizeMask == 0i64;
    p_SizeMask = &v8[v10 + 1].SizeMask;
  }
  if ( !v11 )
  {
    v17 = (Scaleform::GFx::AS2::Value *)(p_SizeMask + 1);
    Scaleform::GFx::AS2::Value::operator=(&v, v17);
    v.T.PropFlags = v17->T.PropFlags;
    Scaleform::GFx::AS2::Value::operator=(&v35, &v);
    Type = v35.T.Type;
    if ( v35.T.Type != 10 )
    {
      Scaleform::GFx::AS2::Value::operator=(retaddr, &v35);
      Type = v35.T.Type;
LABEL_44:
      v27 = 1;
      goto LABEL_45;
    }
  }
LABEL_13:
  memset(&v32, 0, 17);
  if ( v40 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&v32, &this->__Constructor__);
  }
  else
  {
    Constructor = Scaleform::GFx::AS2::GASPrototypeBase::GetConstructor(this, &result);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&v32, Constructor);
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
        v23 = result.pLocalFrame->RefCount;
        if ( (v23 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
  v24 = v32.pLocalFrame;
  v25 = (Scaleform::GFx::ASStringNode *)v32.Function;
  if ( v32.Function )
  {
    if ( retaddr->T.Type != 8 || retaddr->V.pStringNode != (Scaleform::GFx::ASStringNode *)v32.Function )
    {
      Scaleform::GFx::AS2::Value::DropRefs(retaddr);
      retaddr->T.Type = 8;
      retaddr->V.FunctionValue.Flags = 0;
      retaddr->V.pStringNode = v25;
      v25->RefCount = (v25->RefCount + 1) & 0x8FFFFFFF;
      retaddr->V.FunctionValue.pLocalFrame = 0i64;
      if ( v24 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&retaddr->V.FunctionValue, v24, v32.Flags & 1);
    }
    goto LABEL_35;
  }
  Scaleform::GFx::AS2::Value::DropRefs(retaddr);
  retaddr->T.Type = 0;
  pObject = pthis->pProto.pObject;
  if ( !pObject )
  {
LABEL_35:
    if ( (v32.Flags & 2) == 0 )
    {
      if ( v25 )
      {
        v29 = v25->RefCount;
        if ( (v29 & 0x3FFFFFF) != 0 )
        {
          v25->RefCount = v29 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v25);
        }
      }
    }
    v32.Function = 0i64;
    if ( (v32.Flags & 1) == 0 )
    {
      if ( v24 )
      {
        v30 = v24->RefCount;
        if ( (v30 & 0x3FFFFFF) != 0 )
        {
          v24->RefCount = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
        }
      }
    }
    v32.pLocalFrame = 0i64;
    goto LABEL_44;
  }
  v27 = pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
          &pObject->Scaleform::GFx::AS2::ObjectInterface,
          v38,
          name,
          retaddr);
  v32.Function = 0i64;
  if ( (v32.Flags & 1) == 0 )
  {
    if ( v24 )
    {
      v28 = v24->RefCount;
      if ( (v28 & 0x3FFFFFF) != 0 )
      {
        v24->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
  }
  v32.pLocalFrame = 0i64;
LABEL_45:
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v35);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v27;
}

// File Line: 952
// RVA: 0x6CB470
void __fastcall Scaleform::GFx::AS2::ObjectProto::ObjectProto(
        Scaleform::GFx::AS2::ObjectProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable;
}

// File Line: 962
// RVA: 0x6B2BF0
void __fastcall Scaleform::GFx::AS2::ObjectProto::AddProperty(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // r10
  unsigned int v5; // r10d
  Scaleform::GFx::AS2::Environment *v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  char v8; // r15
  Scaleform::GFx::AS2::FunctionObject *v9; // rdi
  Scaleform::GFx::AS2::LocalFrame *v10; // rsi
  unsigned int v11; // r8d
  Scaleform::GFx::AS2::Environment *v12; // r14
  Scaleform::GFx::AS2::Value *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::FunctionRef *v15; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  char *v22; // rcx
  __int64 v23; // r12
  __int64 v24; // r14
  Scaleform::GFx::AS2::FunctionObject *v25; // rax
  Scaleform::GFx::AS2::Value *v26; // rbx
  unsigned int v27; // eax
  unsigned int v28; // eax
  Scaleform::GFx::AS2::Value *v29; // rbx
  char v30; // al
  Scaleform::GFx::AS2::FunctionObject *v31; // rcx
  unsigned int v32; // edx
  Scaleform::GFx::AS2::LocalFrame *v33; // rcx
  unsigned int v34; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v37; // rbx
  Scaleform::GFx::AS2::FunctionRef v38; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase v39; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::FunctionRef v40; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::GFx::AS2::Value v41; // [rsp+78h] [rbp-1h] BYREF
  __int64 v42; // [rsp+98h] [rbp+1Fh]
  Scaleform::MemoryHeap *pHeap; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+6Fh] BYREF
  __int64 v45; // [rsp+F0h] [rbp+77h]

  v42 = -2i64;
  if ( fn->NArgs < 2 )
  {
    v37 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v37);
    v37->T.Type = 2;
    v37->V.BooleanValue = 0;
  }
  else
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
    v5 = fn->FirstArgBottomIndex - 1;
    v6 = fn->Env;
    v7 = 0i64;
    if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v6->Stack.pCurrent - v6->Stack.pPageStart) )
      v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v7, &v38, v6);
    if ( v38.Function )
    {
      v8 = 0;
      v9 = 0i64;
      memset(&v39, 0, 17);
      v10 = 0i64;
      if ( fn->NArgs >= 3 )
      {
        v11 = fn->FirstArgBottomIndex - 2;
        v12 = fn->Env;
        v13 = 0i64;
        if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
          v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
        if ( v13->T.Type == 8 || v13->T.Type == 11 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v15 = Scaleform::GFx::AS2::Value::ToFunction(v14, &v40, v12);
          Scaleform::GFx::AS2::FunctionRefBase::Assign(&v39, v15);
          Flags = v40.Flags;
          if ( (v40.Flags & 2) == 0 )
          {
            Function = v40.Function;
            if ( v40.Function )
            {
              RefCount = v40.Function->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                v40.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
                Flags = v40.Flags;
              }
            }
          }
          v40.Function = 0i64;
          if ( (Flags & 1) == 0 )
          {
            pLocalFrame = v40.pLocalFrame;
            if ( v40.pLocalFrame )
            {
              v20 = v40.pLocalFrame->RefCount;
              if ( (v20 & 0x3FFFFFF) != 0 )
              {
                v40.pLocalFrame->RefCount = v20 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          v40.pLocalFrame = 0i64;
          v8 = v39.Flags;
          v10 = v39.pLocalFrame;
          v9 = v39.Function;
        }
      }
      Target = fn->Env->Target;
      if ( Target )
      {
        v22 = (char *)Target + 4 * (unsigned __int8)Target->AvmObjOffset;
        v23 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((*(__int64 (__fastcall **)(char *))(*(_QWORD *)v22 + 8i64))(v22)
                                                            + 24)
                                                + 32i64)
                                    + 56i64)
                        + 32i64);
      }
      else
      {
        v23 = 0i64;
      }
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v41.T.Type = 9;
      v24 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64))pHeap->vfptr->Alloc)(Target, 80i64);
      v45 = v24;
      if ( v24 )
      {
        *(_QWORD *)v24 = &Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
        *(_QWORD *)(v24 + 8) = v23;
        *(_DWORD *)(v24 + 24) = 1;
        *(_QWORD *)v24 = &Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::ValueProperty>::`vftable;
        *(_QWORD *)v24 = &Scaleform::GFx::AS2::ValueProperty::`vftable;
        *(_BYTE *)(v24 + 48) = 0;
        *(_QWORD *)(v24 + 32) = v38.Function;
        v25 = v38.Function;
        if ( v38.Function )
        {
          ++v38.Function->RefCount;
          v25->RefCount &= 0x8FFFFFFF;
        }
        *(_QWORD *)(v24 + 40) = 0i64;
        if ( v38.pLocalFrame )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
            (Scaleform::GFx::AS2::FunctionRefBase *)(v24 + 32),
            v38.pLocalFrame,
            v38.Flags & 1);
        *(_BYTE *)(v24 + 72) = 0;
        *(_QWORD *)(v24 + 56) = v9;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
        *(_QWORD *)(v24 + 64) = 0i64;
        if ( v10 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
            (Scaleform::GFx::AS2::FunctionRefBase *)(v24 + 56),
            v10,
            v8 & 1);
      }
      else
      {
        v24 = 0i64;
      }
      v41.V.pStringNode = (Scaleform::GFx::ASStringNode *)v24;
      LOBYTE(pHeap) = 0;
      fn->ThisPtr->vfptr->SetMemberRaw(
        fn->ThisPtr,
        &fn->Env->StringContext,
        &result,
        &v41,
        (Scaleform::GFx::AS2::PropFlags *)&pHeap);
      v26 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v26);
      v26->T.Type = 2;
      v26->V.BooleanValue = 1;
      if ( v41.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v41);
      if ( (v8 & 2) == 0 )
      {
        if ( v9 )
        {
          v27 = v9->RefCount;
          if ( (v27 & 0x3FFFFFF) != 0 )
          {
            v9->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
          }
        }
      }
      v39.Function = 0i64;
      if ( (v8 & 1) == 0 )
      {
        if ( v10 )
        {
          v28 = v10->RefCount;
          if ( (v28 & 0x3FFFFFF) != 0 )
          {
            v10->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
          }
        }
      }
      v39.pLocalFrame = 0i64;
    }
    else
    {
      v29 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v29);
      v29->T.Type = 2;
      v29->V.BooleanValue = 0;
    }
    v30 = v38.Flags;
    if ( (v38.Flags & 2) == 0 )
    {
      v31 = v38.Function;
      if ( v38.Function )
      {
        v32 = v38.Function->RefCount;
        if ( (v32 & 0x3FFFFFF) != 0 )
        {
          v38.Function->RefCount = v32 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v31);
          v30 = v38.Flags;
        }
      }
    }
    v38.Function = 0i64;
    if ( (v30 & 1) == 0 )
    {
      v33 = v38.pLocalFrame;
      if ( v38.pLocalFrame )
      {
        v34 = v38.pLocalFrame->RefCount;
        if ( (v34 & 0x3FFFFFF) != 0 )
        {
          v38.pLocalFrame->RefCount = v34 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v33);
        }
      }
    }
    v38.pLocalFrame = 0i64;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 987
// RVA: 0x6B3020
void __fastcall Scaleform::GFx::AS2::ObjectProto::HasOwnProperty(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  char v6; // di
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v4 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD, __int64))fn->ThisPtr->vfptr->HasMember)(
         fn->ThisPtr,
         &fn->Env->StringContext,
         v5,
         0i64,
         -2i64);
  v7 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->T.Type = 2;
  v7->V.BooleanValue = v6;
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 994
// RVA: 0x6B32F0
void __fastcall Scaleform::GFx::AS2::ObjectProto::Watch_(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int v2; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // r10
  unsigned int v5; // edx
  Scaleform::GFx::AS2::Environment *v6; // r9
  Scaleform::GFx::AS2::Value *v7; // r8
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::ASString *v11; // rax
  bool v12; // di
  Scaleform::GFx::AS2::Value *v13; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v16; // rbx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value *v22; // rbx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v24; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v25; // [rsp+80h] [rbp+8h] BYREF

  if ( fn->NArgs < 2 )
  {
    v22 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v22);
    v22->T.Type = 2;
    v22->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex - 1;
    Env = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
             + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v4, &result, Env);
    if ( result.Function )
    {
      v24.T.Type = 0;
      if ( fn->NArgs >= 3 )
      {
        v5 = fn->FirstArgBottomIndex - 2;
        v6 = fn->Env;
        v7 = 0i64;
        if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
                 + (unsigned int)(v6->Stack.pCurrent - v6->Stack.pPageStart) )
          v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v24, v7);
      }
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      v9 = fn->Env;
      v10 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
        v10 = &v9->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &v25, v9, -1);
      v12 = fn->ThisPtr->vfptr->Watch(fn->ThisPtr, &fn->Env->StringContext, v11, &result, &v24);
      v13 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v13);
      v13->T.Type = 2;
      v13->V.BooleanValue = v12;
      pNode = v25.pNode;
      if ( v25.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v24.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
    }
    else
    {
      v16 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v16);
      v16->T.Type = 2;
      v16->V.BooleanValue = 0;
    }
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
        v21 = result.pLocalFrame->RefCount;
        if ( (v21 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
}

// File Line: 1017
// RVA: 0x6B3520
void __fastcall Scaleform::GFx::AS2::ObjectProto::Unwatch_(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  bool v6; // di
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v10; // rbx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  if ( fn->NArgs < 1 )
  {
    v10 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v10);
    v10->T.Type = 2;
    v10->V.BooleanValue = 0;
  }
  else
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
    v6 = fn->ThisPtr->vfptr->Unwatch(fn->ThisPtr, &fn->Env->StringContext, v5);
    v7 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 2;
    v7->V.BooleanValue = v6;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1029
// RVA: 0x6B30E0
void __fastcall Scaleform::GFx::AS2::ObjectProto::IsPropertyEnumerable(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  char v5; // di
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  if ( fn->NArgs < 1 )
  {
    v9 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->T.Type = 2;
    v9->V.BooleanValue = 0;
  }
  else
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v4 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD, __int64))fn->ThisPtr->vfptr->HasMember)(
           fn->ThisPtr,
           &fn->Env->StringContext,
           &result,
           0i64,
           -2i64);
    if ( v5 )
    {
      v10.T = 0;
      fn->ThisPtr->vfptr->FindMember(fn->ThisPtr, &fn->Env->StringContext, &result, (Scaleform::GFx::AS2::Member *)&v10);
      if ( (v10.T.PropFlags & 1) != 0 )
        v5 = 0;
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
    }
    v6 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 2;
    v6->V.BooleanValue = v5;
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1050
// RVA: 0x6B3210
void __fastcall Scaleform::GFx::AS2::ObjectProto::IsPrototypeOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  Scaleform::GFx::AS2::Value *v3; // r8
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  bool v8; // al
  Scaleform::GFx::AS2::Value *Result; // rbx
  bool v10; // di
  Scaleform::GFx::AS2::Value *v11; // rbx

  if ( fn->NArgs < 1
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr)
     - 2 <= 3 )
  {
    goto LABEL_9;
  }
  ThisPtr = fn->ThisPtr;
  v3 = 0i64;
  v4 = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2];
  if ( !ThisPtr )
    v4 = 0i64;
  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v3 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObjectInterface(v3, Env);
  if ( v7 )
  {
    v8 = v7->vfptr->InstanceOf(v7, fn->Env, v4, 0);
    Result = fn->Result;
    v10 = v8;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v10;
    Result->T.Type = 2;
  }
  else
  {
LABEL_9:
    v11 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v11);
    v11->V.BooleanValue = 0;
    v11->T.Type = 2;
  }
}

// File Line: 1067
// RVA: 0x6B35F0
void __fastcall Scaleform::GFx::AS2::ObjectProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::ASStringNode *pMovieImpl; // rax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  Scaleform::GFx::DisplayObject *vfptr; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rax
  Scaleform::GFx::ASString *CharacterNamePath; // rdi
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASMovieRootBase *v11; // rdi
  Scaleform::GFx::AS2::Value v12; // [rsp+28h] [rbp-30h] BYREF

  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 23 )
  {
    pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    pMovieImpl = (Scaleform::GFx::ASStringNode *)pObject[24].pMovieImpl;
LABEL_21:
    Result->V.pStringNode = pMovieImpl;
    ++pMovieImpl->RefCount;
    return;
  }
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr)
     - 2 > 3 )
  {
    v11 = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    pMovieImpl = *(Scaleform::GFx::ASStringNode **)&v11[24].AVMVersion;
    goto LABEL_21;
  }
  ThisPtr = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) - 2 > 3 )
    vfptr = 0i64;
  else
    vfptr = (Scaleform::GFx::DisplayObject *)ThisPtr[1].vfptr;
  v12.T.Type = 7;
  if ( vfptr )
  {
    CharacterHandle = (Scaleform::GFx::ASStringNode *)vfptr->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(vfptr);
    v12.V.pStringNode = CharacterHandle;
    if ( CharacterHandle )
      ++LODWORD(CharacterHandle->pData);
  }
  else
  {
    v12.V.pStringNode = 0i64;
  }
  CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(&v12, fn->Env);
  v9 = fn->Result;
  if ( v9->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v9);
  v9->T.Type = 5;
  pNode = CharacterNamePath->pNode;
  v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)CharacterNamePath->pNode;
  ++pNode->RefCount;
  Scaleform::GFx::AS2::Value::DropRefs(&v12);
}

// File Line: 1077
// RVA: 0x6B3730
void __fastcall Scaleform::GFx::AS2::ObjectProto::ValueOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value::SetAsObjectInterface(fn->Result, fn->ThisPtr);
}

// File Line: 1085
// RVA: 0x6F9950
void __fastcall Scaleform::GFx::AS2::ObjectProto::GlobalCtor(unsigned __int64 fn)
{
  unsigned __int64 v1; // rdi
  unsigned int v2; // r8d
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v3; // rdx
  Scaleform::GFx::AS2::Value *v4; // r10
  char v5; // r8
  char Type; // dl
  long double v7; // xmm0_8
  bool v8; // al
  Scaleform::GFx::ASString *v9; // rax
  __int64 v11; // rbx
  __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rax
  __int64 v14; // rax
  char Flags; // dl
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v19; // eax
  int v20; // eax
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v22; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+20h] BYREF
  __int64 v25; // [rsp+A8h] [rbp+28h]
  Scaleform::GFx::AS2::Object *v26; // [rsp+B0h] [rbp+30h]

  v1 = fn;
  if ( *(int *)(fn + 56) >= 1 )
  {
    v2 = *(_DWORD *)(fn + 60);
    v3 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(*(_QWORD *)(fn + 48) + 8i64);
    v4 = 0i64;
    fn = 32 * ((unsigned int)*(_QWORD *)(*(_QWORD *)(fn + 48) + 48i64) - 1)
       + (unsigned int)(((__int64)v3->pCurrent - *(_QWORD *)(*(_QWORD *)(fn + 48) + 16i64)) >> 5);
    if ( v2 <= (unsigned int)fn )
    {
      fn = v2 >> 5;
      v4 = &v3->Pages.Data.Data[fn]->Values[v2 & 0x1F];
    }
    v5 = 0;
    v22.T.Type = 0;
    Type = v4->T.Type;
    if ( (unsigned __int8)(v4->T.Type - 3) > 1u )
    {
      if ( Type != 2 )
      {
        if ( Type == 5 )
        {
          v9 = Scaleform::GFx::AS2::Value::ToString(v4, &result, *(Scaleform::GFx::AS2::Environment **)(v1 + 48), -1);
          v.T.Type = 5;
          v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v9->pNode;
          ++v.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::Value::operator=(&v22, &v);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
          fn = (unsigned __int64)result.pNode;
          if ( result.pNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)fn);
        }
        else
        {
          if ( (unsigned __int8)(Type - 6) > 1u )
          {
LABEL_21:
            if ( (unsigned __int8)v5 >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v22);
            goto LABEL_23;
          }
          Scaleform::GFx::AS2::Value::operator=(&v22, v4);
        }
LABEL_17:
        v5 = v22.T.Type;
        if ( v22.T.Type && v22.T.Type != 10 )
        {
          Scaleform::GFx::AS2::Value::operator=(*(Scaleform::GFx::AS2::Value **)(v1 + 8), &v22);
          if ( v22.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v22);
          return;
        }
        goto LABEL_21;
      }
      v8 = Scaleform::GFx::AS2::Value::ToBool(v4, *(Scaleform::GFx::AS2::Environment **)(v1 + 48));
      v.T.Type = 2;
      v.V.BooleanValue = v8;
      Scaleform::GFx::AS2::Value::operator=(&v22, &v);
    }
    else
    {
      v7 = Scaleform::GFx::AS2::Value::ToNumber(v4, *(Scaleform::GFx::AS2::Environment **)(v1 + 48));
      v.T.Type = 3;
      v.NV.NumberValue = v7;
      Scaleform::GFx::AS2::Value::operator=(&v22, &v);
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    goto LABEL_17;
  }
LABEL_23:
  result.pNode = 0i64;
  v11 = *(_QWORD *)(v1 + 16);
  if ( v11 )
  {
    v12 = v11 - 32;
    if ( v12 )
    {
      ++*(_DWORD *)(v12 + 24);
      *(_DWORD *)(v12 + 24) &= 0x8FFFFFFF;
    }
  }
  else
  {
    v25 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 48) + 232i64) + 48i64);
    v13 = (Scaleform::GFx::AS2::Object *)(*(__int64 (__fastcall **)(unsigned __int64, __int64))(*(_QWORD *)v25 + 80i64))(
                                           fn,
                                           96i64);
    v26 = v13;
    if ( v13 )
    {
      Scaleform::GFx::AS2::Object::Object(v13, *(Scaleform::GFx::AS2::Environment **)(v1 + 48));
      v12 = v14;
    }
    else
    {
      v12 = 0i64;
    }
  }
  result.pNode = (Scaleform::GFx::ASStringNode *)v12;
  Scaleform::GFx::AS2::Environment::GetConstructor(
    *(Scaleform::GFx::AS2::Environment **)(v1 + 48),
    &ctorFunc,
    ASBuiltin_Object);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    (Scaleform::GFx::AS2::ObjectInterface *)(v12 + 32),
    (Scaleform::GFx::AS2::ASStringContext *)(*(_QWORD *)(v1 + 48) + 232i64),
    &ctorFunc);
  Scaleform::GFx::AS2::Value::SetAsObject(*(Scaleform::GFx::AS2::Value **)(v1 + 8), (Scaleform::GFx::AS2::Object *)v12);
  Flags = ctorFunc.Flags;
  if ( (ctorFunc.Flags & 2) == 0 )
  {
    Function = ctorFunc.Function;
    if ( ctorFunc.Function )
    {
      RefCount = ctorFunc.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        ctorFunc.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        Flags = ctorFunc.Flags;
      }
    }
  }
  ctorFunc.Function = 0i64;
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = ctorFunc.pLocalFrame;
    if ( ctorFunc.pLocalFrame )
    {
      v19 = ctorFunc.pLocalFrame->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        ctorFunc.pLocalFrame->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  ctorFunc.pLocalFrame = 0i64;
  if ( v12 )
  {
    v20 = *(_DWORD *)(v12 + 24);
    if ( (v20 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v12 + 24) = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
    }
  }
}

// File Line: 1152
// RVA: 0x6B2030
void __fastcall Scaleform::GFx::AS2::ObjectCtorFunction::RegisterClassA(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  __int64 NArgs; // r8
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::GlobalContext *pContext; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // r10
  unsigned int v9; // r9d
  Scaleform::GFx::AS2::Environment *v10; // r10
  Scaleform::GFx::AS2::Value *v11; // r8
  Scaleform::GFx::AS2::Value *v12; // rdx
  bool v13; // di
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::AS2::Value *v17; // r11
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_mHash; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v19; // r11
  Scaleform::GFx::ASStringNode *pNode; // rax
  unsigned __int64 SizeMask; // r14
  signed __int64 v22; // r10
  signed __int64 v23; // r8
  unsigned __int64 *v24; // r9
  Scaleform::GFx::ASStringNode *v25; // rdx
  Scaleform::GFx::AS2::FunctionRef *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS2::Value *v28; // rbx
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+28h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRef v36; // [rsp+38h] [rbp-18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+20h] BYREF
  Scaleform::GFx::ASString v38; // [rsp+78h] [rbp+28h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  NArgs = (unsigned int)fn->NArgs;
  if ( (int)NArgs < 2 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Too few parameters for Object.registerClass (%d)",
      NArgs);
    return;
  }
  Env = fn->Env;
  pContext = Env->StringContext.pContext;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  v7 = 0i64;
  v8 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v8, &result, Env, -1);
  v9 = fn->FirstArgBottomIndex - 1;
  v10 = fn->Env;
  v11 = 0i64;
  if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
           + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
    v11 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
  if ( v11->T.Type == 8 || v11->T.Type == 11 )
  {
    v17 = 0i64;
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
      v17 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v17, &v36, fn->Env);
    p_mHash = &pContext->RegisteredClasses.mHash;
    if ( fn->Env->StringContext.SWFVersion <= 6u )
    {
      v38.pNode = (Scaleform::GFx::ASStringNode *)&result;
      pNode = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        pNode = result.pNode;
      }
      if ( p_mHash->pTable )
      {
        v26 = (Scaleform::GFx::AS2::FunctionRef *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                    p_mHash,
                                                    (Scaleform::GFx::ASString::NoCaseKey *)&v38,
                                                    pNode->HashFlags & p_mHash->pTable->SizeMask);
        if ( (__int64)v26 >= 0 )
        {
          key.pFirst = (Scaleform::GFx::ASString *)p_mHash;
          key.pSecond = v26;
          pNode = result.pNode;
          goto LABEL_36;
        }
        pNode = result.pNode;
      }
    }
    else
    {
      v19.pTable = p_mHash->pTable;
      pNode = result.pNode;
      if ( p_mHash->pTable )
      {
        SizeMask = v19.pTable->SizeMask;
        v22 = (unsigned int)SizeMask & result.pNode->HashFlags;
        v23 = v22;
        v24 = &v19.pTable[2 * v22 + 1].EntryCount + v22;
        if ( *v24 != -2i64 && ((unsigned int)SizeMask & *(_DWORD *)(v24[1] + 28)) == v22 )
        {
          while ( 1 )
          {
            v25 = (Scaleform::GFx::ASStringNode *)v24[1];
            if ( ((unsigned int)SizeMask & v25->HashFlags) == v22 && v25 == result.pNode )
              break;
            v23 = *v24;
            if ( *v24 == -1i64 )
              goto LABEL_35;
            v24 = &v19.pTable[2 * v23 + 1].EntryCount + v23;
          }
          if ( v23 >= 0 )
          {
            key.pFirst = (Scaleform::GFx::ASString *)p_mHash;
            key.pSecond = (Scaleform::GFx::AS2::FunctionRef *)v23;
            goto LABEL_36;
          }
        }
      }
    }
LABEL_35:
    key.pFirst = 0i64;
    key.pSecond = 0i64;
LABEL_36:
    if ( key.pFirst && (v27 = key.pFirst->pNode) != 0i64 && (__int64)key.pSecond <= (__int64)v27->pManager )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v27[(__int64)key.pSecond].Size,
        &v36);
    }
    else
    {
      key.pFirst = &result;
      key.pSecond = &v36;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        p_mHash,
        p_mHash,
        &key,
        pNode->HashFlags);
    }
    v28 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v28);
    v28->T.Type = 2;
    v28->V.BooleanValue = 1;
    Flags = v36.Flags;
    if ( (v36.Flags & 2) == 0 )
    {
      Function = v36.Function;
      if ( v36.Function )
      {
        RefCount = v36.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v36.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = v36.Flags;
        }
      }
    }
    v36.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = v36.pLocalFrame;
      if ( v36.pLocalFrame )
      {
        v33 = v36.pLocalFrame->RefCount;
        if ( (v33 & 0x3FFFFFF) != 0 )
        {
          v36.pLocalFrame->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    v36.pLocalFrame = 0i64;
    goto LABEL_50;
  }
  v12 = 0i64;
  if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
           + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
    v12 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
  if ( v12->T.Type == 1 )
  {
    v13 = Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(pContext, &v10->StringContext, &result);
    v14 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v14);
    v14->T.Type = 2;
    v14->V.BooleanValue = v13;
  }
  else
  {
    if ( v9 <= 32 * ((unsigned int)v10->Stack.Pages.Data.Size - 1)
             + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
      v7 = &v10->Stack.Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v7, &v38, fn->Env, -1);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Second parameter of Object.registerClass(%s, %s) should be function or null",
      result.pNode->pData,
      v38.pNode->pData);
    v15 = v38.pNode;
    v16 = v38.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
LABEL_50:
  v34 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
}

// File Line: 1189
// RVA: 0x6E0540
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::FunctionCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::FunctionCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rdi
  Scaleform::GFx::AS2::Object *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rbx

  p_StringContext = &penv->StringContext;
  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        104i64);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  Scaleform::GFx::AS2::Object::Object(v3, p_StringContext);
  v4->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = 0i64;
  return v4;
}

