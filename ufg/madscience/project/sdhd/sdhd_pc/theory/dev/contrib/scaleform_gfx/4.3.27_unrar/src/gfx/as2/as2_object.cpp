// File Line: 35
// RVA: 0x6D2410
void __fastcall Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::Object *v1; // rcx
  unsigned int v2; // eax

  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v1 = this->pProto.pObject;
  if ( v1 )
  {
    v2 = v1->RefCount;
    if ( v2 & 0x3FFFFFF )
    {
      v1->RefCount = v2 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->vfptr);
    }
  }
}

// File Line: 46
// RVA: 0x721410
Scaleform::GFx::AS2::ObjectInterfaceVtbl *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToCharacter(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *result; // rax

  v1 = this;
  if ( (*(unsigned int (**)(void))&this->vfptr->gap8[8])() - 2 > 3 )
    result = 0i64;
  else
    result = v1[1].vfptr;
  return result;
}

// File Line: 51
// RVA: 0x721270
Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *result; // rax

  v1 = this;
  if ( (*(unsigned int (**)(void))&this->vfptr->gap8[8])() - 2 > 3 )
    result = 0i64;
  else
    result = &v1[-1].pProto;
  return result;
}

// File Line: 56
// RVA: 0x721240
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToASObject(Scaleform::GFx::AS2::ObjectInterface *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *result; // rax

  v1 = this;
  if ( (*(unsigned int (**)(void))&this->vfptr->gap8[8])() - 6 > 0x26 )
    result = 0i64;
  else
    result = v1 - 2;
  return result;
}

// File Line: 96
// RVA: 0x721530
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ObjectInterface::ToFunction(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::FunctionRef *result)
{
  result->Flags = 0;
  result->Function = 0i64;
  result->pLocalFrame = 0i64;
  return result;
}

// File Line: 101
// RVA: 0x6EB150
Scaleform::GFx::AS2::ObjectInterface *__fastcall Scaleform::GFx::AS2::ObjectInterface::FindOwner(Scaleform::GFx::AS2::ObjectInterface *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Object *v6; // rbx

  v3 = name;
  v4 = psc;
  v5 = this;
  if ( !this )
    return 0i64;
  while ( !v5->vfptr->HasMember(v5, v4, v3, 0) )
  {
    v6 = v5->pProto.pObject;
    if ( v6 )
    {
      v5 = (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr;
      if ( v5 )
        continue;
    }
    return 0i64;
  }
  return v5 - 2;
}

// File Line: 143
// RVA: 0x6CB100
void __fastcall Scaleform::GFx::AS2::Object::Object(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASRefCountCollector *pcc)
{
  Scaleform::GFx::AS2::Object *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rcx
  unsigned int v5; // eax

  v2 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)&pcc->vfptr;
  this->RefCount = 1;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  v3 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v3->pProto.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  v4 = this->pProto.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount;
    if ( v5 & 0x3FFFFFF )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
    }
  }
  v2->pProto.pObject = 0i64;
}

// File Line: 151
// RVA: 0x6CB1C0
void __fastcall Scaleform::GFx::AS2::Object::Object(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // rax
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rcx
  unsigned int v7; // eax

  v2 = this;
  if ( psc->pContext && (v3 = psc->pContext->pMovieRoot) != 0i64 )
    v4 = (Scaleform::GFx::AS2::RefCountCollector<323> *)v3->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v4 = 0i64;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = v4;
  this->RefCount = 1;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  v5 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v5->pProto.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Members.mHash.pTable = 0i64;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0i64;
  this->ResolveHandler.pLocalFrame = 0i64;
  this->pWatchpoints = 0i64;
  *(_WORD *)&this->ArePropertiesSet = 0;
  v6 = this->pProto.pObject;
  if ( v6 )
  {
    v7 = v6->RefCount;
    if ( v7 & 0x3FFFFFF )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  v2->pProto.pObject = 0i64;
}

// File Line: 160
// RVA: 0x6CB2A0
void __fastcall Scaleform::GFx::AS2::Object::Object(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *proto)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::MovieImpl *v4; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *v5; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // rcx

  v3 = this;
  if ( psc->pContext && (v4 = psc->pContext->pMovieRoot) != 0i64 )
    v5 = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v5 = 0i64;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->pRCC = v5;
  this->RefCount = 1;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  v6 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v6->pProto.pObject = 0i64;
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->Members.mHash.pTable = 0i64;
  v3->ResolveHandler.Flags = 0;
  v3->ResolveHandler.Function = 0i64;
  v3->ResolveHandler.pLocalFrame = 0i64;
  v3->pWatchpoints = 0i64;
  *(_WORD *)&v3->ArePropertiesSet = 0;
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)((char *)v3 + 32), psc, proto);
}

// File Line: 167
// RVA: 0x6CB370
void __fastcall Scaleform::GFx::AS2::Object::Object(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::Object *v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // rcx
  signed __int64 v5; // rcx
  Scaleform::GFx::AS2::RefCountCollector<323> *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::AS2::Object *v8; // rax

  v2 = penv;
  v3 = this;
  v4 = penv->Target;
  if ( v4 )
  {
    v5 = (signed __int64)v4 + 4 * (unsigned __int8)v4->AvmObjOffset;
    v6 = *(Scaleform::GFx::AS2::RefCountCollector<323> **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v5 + 8i64))(v5)
                                                                                             + 24)
                                                                                 + 32i64)
                                                                     + 56i64)
                                                         + 32i64);
  }
  else
  {
    v6 = 0i64;
  }
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  v3->pRCC = v6;
  v3->RefCount = 1;
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::`vftable;
  v7 = (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr;
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v7->pProto.pObject = 0i64;
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->Members.mHash.pTable = 0i64;
  v3->ResolveHandler.Flags = 0;
  v3->ResolveHandler.Function = 0i64;
  v3->ResolveHandler.pLocalFrame = 0i64;
  v3->pWatchpoints = 0i64;
  *(_WORD *)&v3->ArePropertiesSet = 0;
  v8 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Object);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)((char *)v3 + 32), &v2->StringContext, v8);
}

// File Line: 173
// RVA: 0x6D2300
void __fastcall Scaleform::GFx::AS2::Object::~Object(Scaleform::GFx::AS2::Object *this)
{
  Scaleform::GFx::AS2::Object *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rsi
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *v3; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v2 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Object::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3 = this->pWatchpoints;
  if ( v3 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v3->mHash.pTable);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  if ( !(v1->ResolveHandler.Flags & 2) )
  {
    v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ResolveHandler.Function->vfptr;
    if ( v4 )
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
  }
  v1->ResolveHandler.Function = 0i64;
  if ( !(v1->ResolveHandler.Flags & 1) )
  {
    v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ResolveHandler.pLocalFrame->vfptr;
    if ( v6 )
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
  }
  v1->ResolveHandler.pLocalFrame = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->Members);
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pProto.pObject->vfptr;
  if ( v8 )
  {
    v9 = v8->RefCount;
    if ( v9 & 0x3FFFFFF )
    {
      v8->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  v1->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
}

// File Line: 186
// RVA: 0x6C0A50
void __fastcall Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Member> *v2; // r8
  Scaleform::GFx::AS2::Object *v3; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v4; // rcx
  unsigned __int64 v5; // rdi
  Scaleform::GFx::AS2::RefCountCollector<323> *v6; // rsi
  unsigned __int64 v7; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rcx
  unsigned __int64 v9; // rax
  __int64 v10; // rbx
  __int64 v11; // r14
  __int64 v12; // rcx
  signed __int64 v13; // rcx
  char v14; // al
  __int64 v15; // rdx
  int v16; // eax
  unsigned int v17; // eax
  unsigned __int64 v18; // rdx
  _QWORD *v19; // rcx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *v20; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v21; // rax
  unsigned __int64 v22; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v23; // rax
  __int64 v24; // rbx
  __int64 v25; // r14
  __int64 v26; // rcx
  signed __int64 v27; // rdi
  char v28; // al
  __int64 v29; // rdx
  int v30; // eax
  unsigned int v31; // eax
  unsigned __int64 v32; // rcx
  _QWORD *v33; // rax
  Scaleform::GFx::AS2::Object *v34; // rdx
  unsigned int v35; // eax
  unsigned int v36; // eax
  __m128i v37; // [rsp+20h] [rbp-18h]

  v2 = &this->Members;
  v3 = this;
  v4 = this->Members.mHash.pTable;
  v5 = 0i64;
  v6 = prcc;
  if ( v4 )
  {
    v7 = v4->SizeMask;
    v8 = v4 + 1;
    v9 = 0i64;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v9;
      v8 += 3;
    }
    while ( v9 <= v7 );
    v37.m128i_i64[0] = (__int64)v2;
    v37.m128i_i64[1] = v9;
  }
  else
  {
    v37 = 0ui64;
  }
  _mm_store_si128(&v37, v37);
  v10 = v37.m128i_i64[1];
  v11 = v37.m128i_i64[0];
  while ( v11 )
  {
    v12 = *(_QWORD *)v11;
    if ( !*(_QWORD *)v11 || v10 > *(_QWORD *)(v12 + 8) )
      break;
    v13 = 48 * v10 + v12;
    v14 = *(_BYTE *)(v13 + 32);
    if ( v14 == 8 )
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)(v13 + 40),
        v6);
      goto LABEL_20;
    }
    if ( v14 != 6 || (v15 = *(_QWORD *)(v13 + 40)) == 0 )
    {
      if ( v14 != 9 )
        goto LABEL_20;
      v15 = *(_QWORD *)(v13 + 40);
    }
    v16 = ++*(_DWORD *)(v15 + 24);
    if ( v16 & 0x70000000 )
    {
      v17 = v16 & 0x8FFFFFFF;
      *(_DWORD *)(v15 + 24) = v17;
      if ( (v17 >> 27) & 1 )
      {
        *(_QWORD *)(*(_QWORD *)(v15 + 16) + 8i64) = *(_QWORD *)(v15 + 8);
        *(_QWORD *)(*(_QWORD *)(v15 + 8) + 16i64) = *(_QWORD *)(v15 + 16);
        *(_QWORD *)(v15 + 16) = *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0;
        *(_QWORD *)(v15 + 8) = v6->pLastPtr->pRCC;
        *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0 = v15;
        v6->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v15;
      }
    }
LABEL_20:
    v18 = *(_QWORD *)(*(_QWORD *)v11 + 8i64);
    if ( v10 <= (signed __int64)v18 && ++v10 <= v18 )
    {
      v19 = (_QWORD *)(48 * v10 + *(_QWORD *)v11 + 16i64);
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v10;
        v19 += 6;
      }
      while ( v10 <= v18 );
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v3->ResolveHandler.Function,
    v6);
  v20 = v3->pWatchpoints;
  if ( v20 )
  {
    v21 = v20->mHash.pTable;
    if ( v20->mHash.pTable )
    {
      v22 = v21->SizeMask;
      v23 = v21 + 1;
      do
      {
        if ( v23->EntryCount != -2i64 )
          break;
        ++v5;
        v23 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)((char *)v23 + 72);
      }
      while ( v5 <= v22 );
      v37.m128i_i64[0] = (__int64)v3->pWatchpoints;
    }
    else
    {
      v37.m128i_i64[0] = 0i64;
    }
    v37.m128i_i64[1] = v5;
    _mm_store_si128(&v37, v37);
    v24 = v37.m128i_i64[1];
    v25 = v37.m128i_i64[0];
    while ( 1 )
    {
      if ( !v25 )
        break;
      v26 = *(_QWORD *)v25;
      if ( !*(_QWORD *)v25 || v24 > *(_QWORD *)(v26 + 8) )
        break;
      v27 = v26 + 72 * v24;
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)(v27 + 32),
        v6);
      v28 = *(_BYTE *)(v27 + 56);
      if ( v28 == 8 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          (Scaleform::GFx::AS2::FunctionRefBase *)(v27 + 64),
          v6);
        goto LABEL_46;
      }
      if ( v28 != 6 || (v29 = *(_QWORD *)(v27 + 64)) == 0 )
      {
        if ( v28 != 9 )
          goto LABEL_46;
        v29 = *(_QWORD *)(v27 + 64);
      }
      v30 = ++*(_DWORD *)(v29 + 24);
      if ( v30 & 0x70000000 )
      {
        v31 = v30 & 0x8FFFFFFF;
        *(_DWORD *)(v29 + 24) = v31;
        if ( (v31 >> 27) & 1 )
        {
          *(_QWORD *)(*(_QWORD *)(v29 + 16) + 8i64) = *(_QWORD *)(v29 + 8);
          *(_QWORD *)(*(_QWORD *)(v29 + 8) + 16i64) = *(_QWORD *)(v29 + 16);
          *(_QWORD *)(v29 + 16) = *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0;
          *(_QWORD *)(v29 + 8) = v6->pLastPtr->pRCC;
          *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0 = v29;
          v6->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v29;
        }
      }
LABEL_46:
      v32 = *(_QWORD *)(*(_QWORD *)v25 + 8i64);
      if ( v24 <= (signed __int64)v32 && ++v24 <= v32 )
      {
        v33 = (_QWORD *)(*(_QWORD *)v25 + 8 * (v24 + 8 * v24 + 2));
        do
        {
          if ( *v33 != -2i64 )
            break;
          ++v24;
          v33 += 9;
        }
        while ( v24 <= v32 );
      }
    }
  }
  v34 = v3->pProto.pObject;
  if ( v34 )
  {
    v35 = ++v34->RefCount;
    if ( v35 & 0x70000000 )
    {
      v36 = v35 & 0x8FFFFFFF;
      v34->RefCount = v36;
      if ( (v36 >> 27) & 1 )
      {
        v34->pPrev->pRCC = v34->pRCC;
        *(_QWORD *)v34->pRCC->Roots.gap0 = v34->pPrev;
        v34->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v6->pLastPtr->pRCC->Roots.gap0;
        v34->pRCC = v6->pLastPtr->pRCC;
        *(_QWORD *)v6->pLastPtr->pRCC->Roots.gap0 = v34;
        v6->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v34;
      }
    }
  }
}

// File Line: 213
// RVA: 0x6E89E0
void __fastcall Scaleform::GFx::AS2::Object::ExecuteForEachChild_GC(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

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
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Object::GetValue(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Value *result)
{
  result->T.Type = 0;
  return result;
}

// File Line: 249
// RVA: 0x717AF0
char __fastcall Scaleform::GFx::AS2::Object::SetMember(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r12
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // r15
  Scaleform::GFx::AS2::Object *v8; // r13
  Scaleform::GFx::AS2::ObjectInterface *v9; // rdi
  __int64 v10; // rdx
  Scaleform::GFx::AS2::RefCountCollector<323> *v11; // rsi
  signed __int64 v12; // rbx
  signed __int64 v13; // rax
  Scaleform::GFx::AS2::Value *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rax
  __int64 *v16; // r8
  Scaleform::GFx::ASStringNode *v17; // rcx
  __int64 v18; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v19; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v20; // rcx
  Scaleform::GFx::AS2::Value *v21; // rsi
  __int64 v23; // rax
  Scaleform::RefCountNTSImpl *v24; // rbx
  __int64 v25; // rax
  Scaleform::GFx::AS2::Value *v26; // rbx
  char v27; // al
  Scaleform::GFx::AS2::Value *v28; // rcx
  char v29; // bl
  Scaleform::GFx::ASMovieRootBase *v30; // rcx
  Scaleform::GFx::ASString v31; // r8
  Scaleform::GFx::AS2::FunctionRef *v32; // rax
  char v33; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v34; // rcx
  int v35; // edx
  Scaleform::GFx::ASStringNode *v36; // rcx
  unsigned int v37; // eax
  bool v38; // zf
  Scaleform::GFx::AS2::GlobalContext *v39; // r8
  Scaleform::GFx::ASStringNode *v40; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v41; // rbx
  Scaleform::GFx::AS2::Object *v42; // rax
  Scaleform::GFx::InteractiveObject *v43; // rax
  Scaleform::GFx::AS2::FunctionRef *v44; // rax
  char v45; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // rcx
  int v47; // edx
  Scaleform::GFx::ASStringNode *v48; // rcx
  unsigned int v49; // eax
  Scaleform::GFx::InteractiveObject *v50; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+38h] [rbp-49h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> ****v52; // [rsp+48h] [rbp-39h]
  __int64 v53; // [rsp+50h] [rbp-31h]
  Scaleform::GFx::AS2::Value v54; // [rsp+58h] [rbp-29h]
  Scaleform::GFx::AS2::Value resultVal; // [rsp+78h] [rbp-9h]
  char v56; // [rsp+E0h] [rbp+5Fh]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+E8h] [rbp+67h]

  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  if ( !(_S10_15 & 1) )
  {
    _S10_15 |= 1u;
    notsetVal_0.T.Type = 10;
    atexit(Scaleform::GFx::AS2::Object::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__);
  }
  v56 = 0;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&v8->16,
    &result,
    v6,
    v7->StringContext.SWFVersion > 6u);
  v9 = 0i64;
  v10 = result.Index;
  if ( !result.pHash || !result.pHash->pTable || result.Index > (signed __int64)result.pHash->pTable->SizeMask )
  {
    v11 = v8->pRCC;
    if ( v11 )
    {
      while ( 1 )
      {
        if ( LOBYTE(v11->ListRoot.RefCount) )
        {
          v12 = (signed __int64)&v11->Roots.Pages;
          if ( v7->StringContext.SWFVersion <= 6u )
          {
            key.pStr = v6;
            if ( !v6->pNode->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
            if ( *(_QWORD *)v12
              && (v15 = (Scaleform::GFx::ASStringNode *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v11->Roots.Pages,
                                                          &key,
                                                          v6->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v12 + 8i64)),
                  (signed __int64)v15 >= 0) )
            {
              *(_QWORD *)&v54.T.Type = (char *)v11 + 48;
              v54.V.pStringNode = v15;
            }
            else
            {
              *(_OWORD *)&v54.T.Type = 0ui64;
            }
            v14 = &v54;
          }
          else
          {
            if ( *(_QWORD *)v12
              && (v13 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v11->Roots.Pages,
                          v6,
                          v6->pNode->HashFlags & *(_QWORD *)(*(_QWORD *)v12 + 8i64)),
                  v13 >= 0) )
            {
              v52 = &v11->Roots.Pages;
              v53 = v13;
            }
            else
            {
              v52 = 0i64;
              v53 = 0i64;
            }
            v14 = (Scaleform::GFx::AS2::Value *)&v52;
          }
          v16 = *(__int64 **)&v14->T.Type;
          v17 = v14->V.pStringNode;
          if ( *(_QWORD *)&v14->T.Type )
          {
            v18 = *v16;
            if ( *v16 )
            {
              if ( (signed __int64)v17 <= *(_QWORD *)(v18 + 8) )
                break;
            }
          }
        }
        v11 = (Scaleform::GFx::AS2::RefCountCollector<323> *)v11->Roots.MaxPages;
        if ( !v11 )
          goto LABEL_28;
      }
      if ( *(_BYTE *)(v18 + 48i64 * (_QWORD)v17 + 32) == 9 )
      {
        v19 = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > **)&v14->T.Type;
        v10 = (__int64)v14->V.pStringNode;
        goto LABEL_30;
      }
LABEL_28:
      v10 = result.Index;
    }
  }
  v19 = result.pHash;
LABEL_30:
  if ( v19 && (v20 = v19->pTable) != 0i64 && v10 <= (signed __int64)v20->SizeMask )
  {
    v21 = (Scaleform::GFx::AS2::Value *)&v20[3 * v10 + 2];
    v56 = v21->T.PropFlags;
    if ( v56 & 4 )
      return 0;
    if ( v21->T.Type == 9 )
    {
      Scaleform::GFx::AS2::Value::Value(&v54, (Scaleform::GFx::AS2::Value *)&v20[3 * v10 + 2], 0i64);
      v23 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::LocalFrame **))v8[-1].ResolveHandler.pLocalFrame->Env)(&v8[-1].ResolveHandler.pLocalFrame);
      v24 = (Scaleform::RefCountNTSImpl *)v23;
      if ( v23 )
        ++*(_DWORD *)(v23 + 8);
      key.pStr = (Scaleform::GFx::ASString *)v23;
      if ( v23 )
      {
        v25 = (*(__int64 (**)(void))(*(_QWORD *)(v23 + 4i64 * *(unsigned __int8 *)(v23 + 109)) + 8i64))();
        if ( v25 )
          v9 = (Scaleform::GFx::AS2::ObjectInterface *)(v25 + 8);
      }
      else if ( v8 != (Scaleform::GFx::AS2::Object *)32 )
      {
        v9 = (Scaleform::GFx::AS2::ObjectInterface *)v8;
      }
      Scaleform::GFx::AS2::Value::SetPropertyValue(&v54, v7, v9, v5);
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release(v24);
      if ( v54.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v54);
      return 1;
    }
  }
  else
  {
    v56 = flags->Flags;
    v21 = 0i64;
  }
  resultVal.T.Type = 0;
  v26 = v5;
  if ( v8->Members.mHash.pTable )
  {
    v27 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(
            (Scaleform::GFx::AS2::Object *)((char *)v8 - 32),
            v7,
            v6,
            v5,
            &resultVal);
    v28 = &resultVal;
    if ( !v27 )
      v28 = v5;
    v26 = v28;
  }
  if ( v21 )
  {
    if ( v5->T.Type == 9 )
      LOBYTE(v8->ResolveHandler.Function) = 1;
    if ( v7->StringContext.SWFVersion <= 6u )
    {
      if ( !v6->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
      v39 = v7->StringContext.pContext;
      v40 = v6->pNode->pLower;
      if ( (Scaleform::GFx::ASStringNode *)v39->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl->vfptr != v40 )
      {
        if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v39->pMovieRoot->pASMovieRoot.pObject[24].RefCount + 16i64) == v40 )
        {
          if ( v5->T.Type != 10 )
          {
            v44 = Scaleform::GFx::AS2::Value::ToFunction(v5, (Scaleform::GFx::AS2::FunctionRef *)&v54, v7);
            Scaleform::GFx::AS2::FunctionRefBase::Assign(
              (Scaleform::GFx::AS2::FunctionRefBase *)&v8->RefCount,
              (Scaleform::GFx::AS2::FunctionRefBase *)&v44->Function);
            v45 = *((_BYTE *)&v54.NV + 16);
            if ( !(*((char *)&v54.NV + 16) & 2) )
            {
              v46 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v54.T.Type;
              if ( *(_QWORD *)&v54.T.Type )
              {
                v47 = *(_DWORD *)(*(_QWORD *)&v54.T.Type + 24i64);
                if ( v47 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v54.T.Type + 24i64) = v47 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
                  v45 = *((_BYTE *)&v54.NV + 16);
                }
              }
            }
            *(_QWORD *)&v54.T.Type = 0i64;
            if ( !(v45 & 1) )
            {
              v48 = v54.V.pStringNode;
              if ( v54.V.pStringNode )
              {
                v49 = v54.V.pStringNode->RefCount;
                if ( v49 & 0x3FFFFFF )
                {
                  v54.V.pStringNode->RefCount = v49 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v48);
                }
              }
            }
LABEL_87:
            v54.V.pStringNode = 0i64;
          }
LABEL_88:
          v26 = &notsetVal_0;
          goto LABEL_93;
        }
        v38 = v6->pNode == *(Scaleform::GFx::ASStringNode **)&v39->pMovieRoot->pASMovieRoot.pObject[28].RefCount;
LABEL_90:
        if ( v38 )
        {
          v50 = v7->Target;
          if ( v50 )
            v50->pASRoot->pMovieImpl->Flags |= 0x80000u;
        }
        goto LABEL_93;
      }
    }
    else
    {
      v30 = v7->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v31.pNode = v6->pNode;
      if ( v6->pNode != (Scaleform::GFx::ASStringNode *)v30[23].pMovieImpl )
      {
        if ( v31.pNode == *(Scaleform::GFx::ASStringNode **)&v30[24].RefCount )
        {
          if ( v5->T.Type != 10 )
          {
            v32 = Scaleform::GFx::AS2::Value::ToFunction(v5, (Scaleform::GFx::AS2::FunctionRef *)&v54, v7);
            Scaleform::GFx::AS2::FunctionRefBase::Assign(
              (Scaleform::GFx::AS2::FunctionRefBase *)&v8->RefCount,
              (Scaleform::GFx::AS2::FunctionRefBase *)&v32->Function);
            v33 = *((_BYTE *)&v54.NV + 16);
            if ( !(*((char *)&v54.NV + 16) & 2) )
            {
              v34 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v54.T.Type;
              if ( *(_QWORD *)&v54.T.Type )
              {
                v35 = *(_DWORD *)(*(_QWORD *)&v54.T.Type + 24i64);
                if ( v35 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v54.T.Type + 24i64) = v35 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
                  v33 = *((_BYTE *)&v54.NV + 16);
                }
              }
            }
            *(_QWORD *)&v54.T.Type = 0i64;
            if ( !(v33 & 1) )
            {
              v36 = v54.V.pStringNode;
              if ( v54.V.pStringNode )
              {
                v37 = v54.V.pStringNode->RefCount;
                if ( v37 & 0x3FFFFFF )
                {
                  v54.V.pStringNode->RefCount = v37 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v36);
                  v54.V.pStringNode = 0i64;
                  v26 = &notsetVal_0;
LABEL_93:
                  Scaleform::GFx::AS2::Value::operator=(v21, v26, 0i64);
                  v29 = 1;
                  goto LABEL_94;
                }
              }
            }
            goto LABEL_87;
          }
          goto LABEL_88;
        }
        v38 = v31.pNode == *(Scaleform::GFx::ASStringNode **)&v30[28].RefCount;
        goto LABEL_90;
      }
    }
    if ( v5->T.Type != 10 )
    {
      v41 = v8->vfptr;
      v42 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v41[4].Finalize_GC)(
        v8,
        &v7->StringContext,
        v42);
      v43 = v7->Target;
      if ( v43 )
        v43->pASRoot->pMovieImpl->Flags |= 0x80000u;
    }
    v26 = &notsetVal_0;
    goto LABEL_93;
  }
  v29 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))v8->vfptr[3].Finalize_GC)(
          v8,
          &v7->StringContext,
          v6,
          v26,
          &v56);
LABEL_94:
  if ( resultVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
  return v29;
}

// File Line: 381
// RVA: 0x1587B70
__int64 Scaleform::GFx::AS2::_dynamic_initializer_for__notsetVal__()
{
  return atexit(Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__notsetVal__);
}

// File Line: 384
// RVA: 0x719C20
char __fastcall Scaleform::GFx::AS2::Object::SetMemberRaw(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // rsi
  Scaleform::GFx::ASString *v6; // r13
  Scaleform::GFx::AS2::ASStringContext *v7; // r14
  Scaleform::GFx::AS2::Object *v8; // r12
  Scaleform::GFx::AS2::Value *v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::MovieImpl *v11; // rdx
  Scaleform::GFx::ASMovieRootBase *v12; // rcx
  Scaleform::GFx::ASString v13; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v14; // rbx
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::FunctionRef *v16; // rax
  char v17; // al
  Scaleform::GFx::AS2::FunctionObject *v18; // rcx
  unsigned int v19; // edx
  Scaleform::GFx::AS2::LocalFrame *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::FunctionObject *v22; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // r8
  Scaleform::GFx::AS2::LocalFrame *v24; // rax
  Scaleform::GFx::MovieImpl *v25; // rcx
  Scaleform::GFx::ASMovieRootBase *v26; // rdx
  Scaleform::GFx::ASStringNode *v27; // r10
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v28; // rbx
  Scaleform::GFx::AS2::Object *v29; // rax
  Scaleform::GFx::AS2::FunctionRef *v30; // rax
  char v31; // al
  Scaleform::GFx::AS2::FunctionObject *v32; // rcx
  unsigned int v33; // edx
  Scaleform::GFx::AS2::LocalFrame *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v36; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v37; // rcx
  char v38; // bl
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-20h]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+80h] [rbp+30h]

  v5 = val;
  v6 = name;
  v7 = psc;
  v8 = this;
  v9 = val;
  if ( !BYTE1(this->ResolveHandler.Function)
    && val->T.Type == 6
    && name->pNode == (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].vfptr )
  {
    v10 = Scaleform::GFx::AS2::Value::ToObject(val, 0i64);
    if ( v10 )
    {
      if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v10->vfptr->gap8[8])(&v10->vfptr) == 7 )
        BYTE1(v8->ResolveHandler.Function) = 1;
    }
  }
  if ( v7->SWFVersion <= 6u )
  {
    if ( !v6->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
    v25 = v7->pContext->pMovieRoot;
    v26 = v25->pASMovieRoot.pObject;
    v27 = v6->pNode->pLower;
    if ( (Scaleform::GFx::ASStringNode *)v26[23].pMovieImpl->vfptr == v27 )
    {
      if ( v5->T.Type != 10 )
      {
        v28 = v8->vfptr;
        v29 = Scaleform::GFx::AS2::Value::ToObject(v5, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v28[4].Finalize_GC)(
          v8,
          v7,
          v29);
        if ( v7->pContext )
          v7->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v9 = &notsetVal;
    }
    else if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v26[24].RefCount + 16i64) == v27 )
    {
      if ( v5->T.Type != 10 )
      {
        v30 = Scaleform::GFx::AS2::Value::ToFunction(v5, &result, 0i64);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v8->RefCount,
          (Scaleform::GFx::AS2::FunctionRefBase *)&v30->Function);
        v31 = result.Flags;
        if ( !(result.Flags & 2) )
        {
          v32 = result.Function;
          if ( result.Function )
          {
            v33 = result.Function->RefCount;
            if ( v33 & 0x3FFFFFF )
            {
              result.Function->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
              v31 = result.Flags;
            }
          }
        }
        result.Function = 0i64;
        if ( !(v31 & 1) )
        {
          v34 = result.pLocalFrame;
          if ( result.pLocalFrame )
          {
            v35 = result.pLocalFrame->RefCount;
            if ( v35 & 0x3FFFFFF )
            {
              result.pLocalFrame->RefCount = v35 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v34->vfptr);
            }
          }
        }
        result.pLocalFrame = 0i64;
      }
      v9 = &notsetVal;
    }
    else if ( v6->pNode == *(Scaleform::GFx::ASStringNode **)&v26[28].RefCount && v7->pContext )
    {
      v25->Flags |= 0x80000u;
    }
    key.pStr = v6;
    if ( !v6->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
    v22 = (Scaleform::GFx::AS2::FunctionObject *)&v8->16;
    v36 = v8->pPrev;
    if ( !v36 )
      goto LABEL_58;
    v24 = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v8->16,
                                               &key,
                                               v6->pNode->HashFlags & (_QWORD)v36->pRCC);
  }
  else
  {
    v11 = v7->pContext->pMovieRoot;
    v12 = v11->pASMovieRoot.pObject;
    v13.pNode = v6->pNode;
    if ( v6->pNode == (Scaleform::GFx::ASStringNode *)v12[23].pMovieImpl )
    {
      if ( v5->T.Type != 10 )
      {
        v14 = v8->vfptr;
        v15 = Scaleform::GFx::AS2::Value::ToObject(v5, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v14[4].Finalize_GC)(
          v8,
          v7,
          v15);
        if ( v7->pContext )
          v7->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v9 = &notsetVal;
    }
    else if ( v13.pNode == *(Scaleform::GFx::ASStringNode **)&v12[24].RefCount )
    {
      if ( v5->T.Type != 10 )
      {
        v16 = Scaleform::GFx::AS2::Value::ToFunction(v5, &result, 0i64);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v8->RefCount,
          (Scaleform::GFx::AS2::FunctionRefBase *)&v16->Function);
        v17 = result.Flags;
        if ( !(result.Flags & 2) )
        {
          v18 = result.Function;
          if ( result.Function )
          {
            v19 = result.Function->RefCount;
            if ( v19 & 0x3FFFFFF )
            {
              result.Function->RefCount = v19 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v18->vfptr);
              v17 = result.Flags;
            }
          }
        }
        result.Function = 0i64;
        if ( !(v17 & 1) )
        {
          v20 = result.pLocalFrame;
          if ( result.pLocalFrame )
          {
            v21 = result.pLocalFrame->RefCount;
            if ( v21 & 0x3FFFFFF )
            {
              result.pLocalFrame->RefCount = v21 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
            }
          }
        }
        result.pLocalFrame = 0i64;
      }
      v9 = &notsetVal;
    }
    else if ( v13.pNode == *(Scaleform::GFx::ASStringNode **)&v12[28].RefCount && v7->pContext )
    {
      v11->Flags |= 0x80000u;
    }
    v22 = (Scaleform::GFx::AS2::FunctionObject *)&v8->16;
    v23 = v8->pPrev;
    if ( !v23 )
      goto LABEL_58;
    v24 = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                                               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v8->16,
                                               v6,
                                               v6->pNode->HashFlags & (_QWORD)v23->pRCC);
  }
  if ( (signed __int64)v24 >= 0 )
  {
    result.Function = v22;
    result.pLocalFrame = v24;
    goto LABEL_59;
  }
LABEL_58:
  result.Function = 0i64;
  result.pLocalFrame = 0i64;
LABEL_59:
  _mm_store_si128((__m128i *)&result, *(__m128i *)&result.Function);
  if ( v5->T.Type == 9 )
    LOBYTE(v8->ResolveHandler.Function) = 1;
  if ( result.Function
    && (v37 = result.Function->vfptr) != 0i64
    && (_QWORD)result.pLocalFrame <= (_QWORD)v37->Finalize_GC )
  {
    Scaleform::GFx::AS2::Value::operator=(
      (Scaleform::GFx::AS2::Value *)&v37[2 * (_QWORD)result.pLocalFrame + 1].Finalize_GC,
      v9,
      (__int64)v9);
  }
  else
  {
    v38 = flags->Flags;
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)&result, v9, (__int64)v9);
    BYTE1(result.Function) = v38;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Sc)v22,
      v6,
      (Scaleform::GFx::AS2::Member *)&result);
    if ( LOBYTE(result.Function) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&result);
  }
  return 1;
}

// File Line: 517
// RVA: 0x6F3960
char __fastcall Scaleform::GFx::AS2::Object::GetMemberRaw(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame **v4; // r14
  char v5; // bp
  bool v6; // cf
  Scaleform::GFx::AS2::Value *v7; // rdi
  Scaleform::GFx::ASString *v8; // r15
  Scaleform::GFx::AS2::ASStringContext *v9; // r13
  char *v10; // rbx
  Scaleform::GFx::ASString v11; // r10
  Scaleform::GFx::ASMovieRootBase *v12; // rax
  __int64 v13; // r9
  __int64 v14; // rsi
  __int64 v15; // r11
  __int64 v16; // rdx
  __int64 *v17; // r8
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::FunctionRefBase *v19; // rcx
  Scaleform::GFx::AS2::FunctionObject *v20; // rdx
  Scaleform::GFx::AS2::LocalFrame *v21; // rdx
  char result; // al
  Scaleform::GFx::AS2::Value *v23; // rdx
  bool v24; // zf
  Scaleform::GFx::AS2::Value *v25; // rcx
  Scaleform::GFx::AS2::Object *v26; // rdx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASMovieRootBase *v28; // rdx
  Scaleform::GFx::ASStringNode *v29; // rcx
  __int64 v30; // rax
  signed __int64 v31; // rsi
  signed __int64 v32; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v33; // rcx
  Scaleform::GFx::AS2::FunctionObject *v34; // rdx
  Scaleform::GFx::AS2::LocalFrame *v35; // rdx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+50h] [rbp+8h]

  v4 = &this[-1].ResolveHandler.pLocalFrame;
  v5 = 0;
  v6 = psc->SWFVersion < 6u;
  v24 = psc->SWFVersion == 6;
  v7 = val;
  v8 = name;
  v9 = psc;
  key.pStr = (Scaleform::GFx::ASString *)&this[-1].ResolveHandler.pLocalFrame;
  v10 = (char *)&this[-1].ResolveHandler.pLocalFrame;
  if ( v6 || v24 )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v27 = v8->pNode;
    key.pStr = v8;
    if ( !v27->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v27);
    if ( v10 )
    {
      while ( 1 )
      {
        v28 = v9->pContext->pMovieRoot->pASMovieRoot.pObject;
        v29 = v8->pNode->pLower;
        if ( (Scaleform::GFx::ASStringNode *)v28[23].pMovieImpl->vfptr == v29 )
          goto LABEL_32;
        if ( *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v28[24].RefCount + 16i64) == v29 )
        {
LABEL_30:
          v25 = v7;
          if ( !*((_QWORD *)v10 + 7) )
            goto LABEL_34;
          Scaleform::GFx::AS2::Value::SetAsFunction(v7, (Scaleform::GFx::AS2::FunctionRefBase *)(v10 + 56));
          return 1;
        }
        v30 = *((_QWORD *)v10 + 6);
        v31 = (signed __int64)(v10 + 48);
        if ( v30 )
        {
          v32 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v10
                + 6,
                  &key,
                  *(_QWORD *)(v30 + 8) & v8->pNode->HashFlags);
          if ( v32 >= 0 && v10 != (char *)-48i64 && *(_QWORD *)v31 && v32 <= *(_QWORD *)(*(_QWORD *)v31 + 8i64) )
          {
            v23 = (Scaleform::GFx::AS2::Value *)(48 * v32 + *(_QWORD *)v31 + 32i64);
            if ( v23->T.Type != 10 )
              goto LABEL_29;
            v24 = v10 == (char *)v4;
LABEL_27:
            if ( !v24 )
              return (*(__int64 (__fastcall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*((_QWORD *)v10 + 4) + 88i64))(
                       v10 + 32,
                       v9,
                       v8,
                       v7);
LABEL_29:
            Scaleform::GFx::AS2::Value::operator=(v7, v23, (__int64)v7);
            return 1;
          }
        }
        if ( !v5 && *((_QWORD *)v10 + 7) )
        {
          Scaleform::GFx::AS2::Value::DropRefs(v7);
          v7->T.Type = 12;
          v33 = (Scaleform::GFx::AS2::FunctionRefBase *)&v7->NV.8;
          v33->Flags = 0;
          v34 = (Scaleform::GFx::AS2::FunctionObject *)*((_QWORD *)v10 + 7);
          v33->Function = v34;
          if ( v34 )
            v34->RefCount = (v34->RefCount + 1) & 0x8FFFFFFF;
          v7->V.FunctionValue.pLocalFrame = 0i64;
          v35 = (Scaleform::GFx::AS2::LocalFrame *)*((_QWORD *)v10 + 8);
          if ( v35 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v33, v35, v10[72] & 1);
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
    v11.pNode = v8->pNode;
    v12 = v9->pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( v8->pNode == (Scaleform::GFx::ASStringNode *)v12[23].pMovieImpl )
      break;
    if ( v11.pNode == *(Scaleform::GFx::ASStringNode **)&v12[24].RefCount )
      goto LABEL_30;
    v13 = *((_QWORD *)v10 + 6);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v13 + 8);
      v15 = (unsigned int)v14 & v11.pNode->HashFlags;
      v16 = v15;
      v17 = (__int64 *)(48 * v15 + v13 + 16);
      if ( *v17 != -2 && ((unsigned int)v14 & *(_DWORD *)(v17[1] + 28)) == v15 )
      {
        while ( 1 )
        {
          v18 = (Scaleform::GFx::ASStringNode *)v17[1];
          if ( ((unsigned int)v14 & v18->HashFlags) == v15 && v18 == v11.pNode )
            break;
          v16 = *v17;
          if ( *v17 == -1 )
            goto LABEL_15;
          v17 = (__int64 *)(48 * v16 + v13 + 16);
        }
        if ( v16 >= 0 && v10 != (char *)-48i64 && v16 <= v14 )
        {
          v23 = (Scaleform::GFx::AS2::Value *)(48 * v16 + v13 + 32);
          if ( v23->T.Type != 10 )
            goto LABEL_29;
          v24 = v10 == (char *)key.pStr;
          goto LABEL_27;
        }
      }
    }
LABEL_15:
    if ( !v5 && *((_QWORD *)v10 + 7) )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v7);
      v7->T.Type = 12;
      v19 = (Scaleform::GFx::AS2::FunctionRefBase *)&v7->NV.8;
      v19->Flags = 0;
      v20 = (Scaleform::GFx::AS2::FunctionObject *)*((_QWORD *)v10 + 7);
      v19->Function = v20;
      if ( v20 )
        v20->RefCount = (v20->RefCount + 1) & 0x8FFFFFFF;
      v7->V.FunctionValue.pLocalFrame = 0i64;
      v21 = (Scaleform::GFx::AS2::LocalFrame *)*((_QWORD *)v10 + 8);
      if ( v21 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v19, v21, v10[72] & 1);
      v5 = 1;
    }
    v10 = (char *)*((_QWORD *)v10 + 5);
    if ( !v10 )
      return 0;
  }
LABEL_32:
  v26 = (Scaleform::GFx::AS2::Object *)*((_QWORD *)v10 + 5);
  v25 = v7;
  if ( v26 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(v7, v26);
    result = 1;
  }
  else
  {
LABEL_34:
    Scaleform::GFx::AS2::Value::DropRefs(v25);
    v7->T.Type = 0;
    result = 1;
  }
  return result;
}GFx::AS2::Value::SetAsObject(v7, v26);
    result = 1;
  }
  else
  {
LABEL_34:
    Scaleform::GFx::AS2::Val

// File Line: 648
// RVA: 0x6EB120
bool __fastcall Scaleform::GFx::AS2::Object::FindMember(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Member *pmember)
{
  JUMPOUT(
    psc->SWFVersion > 6u,
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Get);
  return Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
           (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->16,
           name,
           pmember);
}

// File Line: 655
// RVA: 0x6E21A0
char __fastcall Scaleform::GFx::AS2::Object::DeleteMember(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v6; // rax
  __int64 v7; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // rcx
  Scaleform::GFx::MovieImpl *v9; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+20h] [rbp-18h]

  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->16;
  v4 = psc;
  v5 = name;
  v6 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
         (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->16,
         &result,
         name,
         psc->SWFVersion > 6u);
  v7 = v6->Index;
  if ( !v6->pHash )
    return 0;
  v8 = v6->pHash->pTable;
  if ( !v8 || v7 > (signed __int64)v8->SizeMask || v8[3 * v7 + 2].EntryCount & 0x200 )
    return 0;
  v9 = v4->pContext->pMovieRoot;
  if ( v5->pNode == *(Scaleform::GFx::ASStringNode **)&v9->pASMovieRoot.pObject[28].RefCount )
  {
    if ( v4->pContext )
      v9->Flags |= 0x80000u;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
    v3,
    v5);
  return 1;
}

// File Line: 673
// RVA: 0x7199D0
__int64 __fastcall Scaleform::GFx::AS2::Object::SetMemberFlags(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, const char flags)
{
  char v4; // si
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::Object *v6; // rbx
  unsigned __int8 v7; // bl
  Scaleform::GFx::AS2::Member value; // [rsp+28h] [rbp-30h]

  v4 = flags;
  v5 = name;
  v6 = this;
  value.mValue.T = 0;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *, signed __int64))this->vfptr[1].~RefCountBaseGC<323>)(
         this,
         psc,
         name,
         &value,
         -2i64) )
  {
    value.mValue.T.PropFlags = v4;
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Sc)&v6->16,
      v5,
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
void __fastcall Scaleform::GFx::AS2::Object::VisitMembers(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor, unsigned int visitFlags, Scaleform::GFx::AS2::ObjectInterface *instance)
{
  unsigned int v5; // er12
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v6; // r14
  Scaleform::GFx::AS2::Object *v7; // r13
  $AEF441711F8527ABAC4F0458E5B46D3D *v8; // r11
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // r10
  Scaleform::GFx::AS2::ObjectInterface *v10; // r15
  Scaleform::GFx::ASStringNode *v11; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v12; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v13; // rbp
  signed __int64 v14; // rdi
  __int64 *v15; // rsi
  __int64 v16; // rax
  signed __int64 v17; // r14
  signed __int64 v18; // rdx
  Scaleform::GFx::AS2::Value *v19; // r8
  char v20; // bl
  Scaleform::GFx::AS2::ObjectInterface *v21; // rcx
  signed __int64 v22; // rdx
  unsigned __int64 v23; // rcx
  _QWORD *v24; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *v25; // rcx
  Scaleform::GFx::AS2::Value v26; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::ASStringContext *v27; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v28; // [rsp+B0h] [rbp+18h]

  v28 = pvisitor;
  v27 = psc;
  v5 = visitFlags;
  v6 = pvisitor;
  v7 = this;
  v8 = &this->16;
  v9 = this->pPrev;
  v10 = 0i64;
  if ( v9 )
  {
    v11 = 0i64;
    v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v9->16;
    do
    {
      if ( *v12 != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)-2i64 )
        break;
      v11 = (Scaleform::GFx::ASStringNode *)((char *)v11 + 1);
      v12 += 6;
    }
    while ( (Scaleform::GFx::AS2::RefCountCollector<323> *)v11 <= v9->pRCC );
    *(_QWORD *)&v26.T.Type = v8;
    v26.V.pStringNode = v11;
  }
  else
  {
    *(_OWORD *)&v26.T.Type = 0ui64;
  }
  _mm_store_si128((__m128i *)&v26, *(__m128i *)&v26.T.Type);
  v13 = instance;
  v14 = (signed __int64)v26.V.pStringNode;
  v15 = *(__int64 **)&v26.T.Type;
  while ( v15 )
  {
    v16 = *v15;
    if ( !*v15 || v14 > *(_QWORD *)(v16 + 8) )
      break;
    v17 = 48 * v14;
    v18 = 48 * v14 + v16;
    v19 = (Scaleform::GFx::AS2::Value *)(v18 + 32);
    v20 = *(_BYTE *)(v18 + 33);
    if ( v20 & 1 && !(v5 & 4) )
    {
      v6 = v28;
    }
    else if ( v19->T.Type == 10 )
    {
      v26.T.Type = 0;
      if ( !(v5 & 8) )
      {
        if ( instance )
        {
          v21 = instance;
        }
        else
        {
          v21 = 0i64;
          if ( v7 != (Scaleform::GFx::AS2::Object *)32 )
            v21 = (Scaleform::GFx::AS2::ObjectInterface *)v7;
        }
        v21->vfptr->GetMemberRaw(v21, v27, (Scaleform::GFx::ASString *)(v17 + *v15 + 24), &v26);
      }
      v22 = v17 + *v15 + 24;
      v6 = v28;
      v28->vfptr->Visit(v28, (Scaleform::GFx::ASString *)v22, &v26, v20);
      if ( v26.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v26);
    }
    else
    {
      v6 = v28;
      v28->vfptr->Visit(v28, (Scaleform::GFx::ASString *)(v18 + 24), v19, v20);
    }
    v23 = *(_QWORD *)(*v15 + 8);
    if ( v14 <= (signed __int64)v23 && ++v14 <= v23 )
    {
      v24 = (_QWORD *)(*v15 + 48 * v14 + 16);
      do
      {
        if ( *v24 != -2i64 )
          break;
        ++v14;
        v24 += 6;
      }
      while ( v14 <= v23 );
    }
  }
  if ( v5 & 1 )
  {
    v25 = v7->pRCC;
    if ( v25 )
    {
      if ( !instance )
      {
        if ( v7 != (Scaleform::GFx::AS2::Object *)32 )
          v10 = (Scaleform::GFx::AS2::ObjectInterface *)v7;
        v13 = v10;
      }
      (*(void (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, _QWORD, Scaleform::GFx::AS2::ObjectInterface *))(v25->Roots.NumPages + 64))(
        &v25->Roots.NumPages,
        v27,
        v6,
        v5,
        v13);
    }
  }
}

// File Line: 726
// RVA: 0x6FB550
__int64 __usercall Scaleform::GFx::AS2::Object::HasMember@<rax>(Scaleform::GFx::AS2::Object *this@<rcx>, Scaleform::GFx::AS2::ASStringContext *psc@<rdx>, Scaleform::GFx::ASString *name@<r8>, __int64 inclPrototypes@<r9>, __int64 a5@<rdi>)
{
  char v5; // bp
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS2::ASStringContext *v7; // r15
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v10; // rbx
  signed __int64 v11; // rax
  signed __int64 v12; // rbx
  Scaleform::GFx::AS2::Value *v13; // rbx
  unsigned __int8 v14; // bl
  Scaleform::GFx::AS2::RefCountCollector<323> *v15; // rcx
  Scaleform::GFx::AS2::Value v17; // [rsp+28h] [rbp-40h]

  v5 = inclPrototypes;
  v6 = name;
  v7 = psc;
  v8 = this;
  LOBYTE(a5) = 0;
  v17.T = 0;
  v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->16;
  v10.pTable = v9->pTable;
  if ( v9->pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v9,
                name,
                name->pNode->HashFlags & v10.pTable->SizeMask),
        v11 >= 0)
    && (v12 = (signed __int64)&v10.pTable[3 * v11 + 1].SizeMask) != 0 )
  {
    v13 = (Scaleform::GFx::AS2::Value *)(v12 + 8);
    Scaleform::GFx::AS2::Value::operator=(&v17, v13, a5);
    v17.T.PropFlags = v13->T.PropFlags;
    v14 = 1;
    LOBYTE(a5) = v17.T.Type;
  }
  else if ( v5 && (v15 = v8->pRCC) != 0i64 )
  {
    LOBYTE(inclPrototypes) = 1;
    v14 = (*(__int64 (__fastcall **)(unsigned __int64 *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64, signed __int64))(v15->Roots.NumPages + 72))(
            &v15->Roots.NumPages,
            v7,
            v6,
            inclPrototypes,
            -2i64);
  }
  else
  {
    v14 = 0;
  }
  if ( (unsigned __int8)a5 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  return v14;
}

// File Line: 740
// RVA: 0x6FDA80
char __fastcall Scaleform::GFx::AS2::Object::InstanceOf(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *prototype, bool inclInterfaces)
{
  Scaleform::GFx::AS2::LocalFrame **v4; // rbx
  bool v5; // si
  Scaleform::GFx::AS2::Object *v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rbp

  v4 = &this[-1].ResolveHandler.pLocalFrame;
  v5 = inclInterfaces;
  v6 = prototype;
  v7 = penv;
  if ( this != (Scaleform::GFx::AS2::Object *)32 )
  {
    do
    {
      if ( v5 )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::LocalFrame **, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(*v4)->PrevFrame.pObject)(
               v4,
               v7,
               v6) )
        {
          return 1;
        }
      }
      else if ( v4 == (Scaleform::GFx::AS2::LocalFrame **)v6 )
      {
        return 1;
      }
      v4 = (Scaleform::GFx::AS2::LocalFrame **)v4[5];
    }
    while ( v4 );
  }
  return 0;
}

// File Line: 756
// RVA: 0x7245A0
char __fastcall Scaleform::GFx::AS2::Object::Watch(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *prop, Scaleform::GFx::AS2::FunctionRef *callback, Scaleform::GFx::AS2::Value *userData)
{
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  Scaleform::GFx::AS2::Object *v7; // rbx
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v9; // rax
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v11; // rcx
  __int64 v12; // rbx
  char v13; // al
  Scaleform::GFx::AS2::FunctionObject *v14; // rcx
  unsigned int v15; // edx
  Scaleform::GFx::AS2::LocalFrame *v16; // rcx
  unsigned int v17; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator result; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-20h]

  v5 = prop;
  v6 = psc;
  v7 = this;
  orig.Flags = 0;
  orig.Function = 0i64;
  orig.pLocalFrame = 0i64;
  v.T.Type = 0;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, (Scaleform::GFx::AS2::FunctionRefBase *)&callback->Function);
  Scaleform::GFx::AS2::Value::operator=(&v, userData, (__int64)v5);
  if ( !v7->Members.mHash.pTable )
  {
    v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v6->pContext->pHeap->vfptr->Alloc(v8, 8ui64, 0i64);
    if ( v9 )
    {
      result.pHash = v9;
      v9->pTable = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    v7->Members.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)v9;
  }
  v10 = (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)v7->Members.mHash.pTable;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    v10,
    &result,
    v5,
    v6->SWFVersion > 6u);
  if ( result.pHash && (v11 = result.pHash->pTable) != 0i64 && result.Index <= (signed __int64)v11->SizeMask )
  {
    v12 = (__int64)v11 + 72 * result.Index;
    Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)(v12 + 32), &orig);
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)(v12 + 56), &v, (__int64)v5);
  }
  else
  {
    result.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5;
    result.Index = (__int64)&orig;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v10->mHash.pTable,
      v10,
      (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&result,
      v5->pNode->HashFlags);
  }
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v13 = orig.Flags;
  if ( !(orig.Flags & 2) )
  {
    v14 = orig.Function;
    if ( orig.Function )
    {
      v15 = orig.Function->RefCount;
      if ( v15 & 0x3FFFFFF )
      {
        orig.Function->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
        v13 = orig.Flags;
      }
    }
  }
  orig.Function = 0i64;
  if ( !(v13 & 1) )
  {
    v16 = orig.pLocalFrame;
    if ( orig.pLocalFrame )
    {
      v17 = orig.pLocalFrame->RefCount;
      if ( v17 & 0x3FFFFFF )
      {
        orig.pLocalFrame->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
      }
    }
  }
  return 1;
}

// File Line: 770
// RVA: 0x722D00
char __fastcall Scaleform::GFx::AS2::Object::Unwatch(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *prop)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rbp
  Scaleform::GFx::AS2::Object *v5; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v6; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > v7; // rsi
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  Scaleform::GFx::AS2::Object::Watchpoint *v10; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v11; // rsi
  Scaleform::GFx::ASString *v12; // rbx
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+40h] [rbp+8h]

  v3 = prop;
  v4 = psc;
  v5 = this;
  v6 = this->Members.mHash.pTable;
  if ( !v6 )
    return 0;
  if ( psc->SWFVersion <= 6u )
  {
    v10 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)v6,
            prop);
  }
  else
  {
    v7.mHash.pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)v6->EntryCount;
    if ( !v6->EntryCount )
      return 0;
    v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v6,
           prop,
           prop->pNode->HashFlags & v7.mHash.pTable->SizeMask);
    if ( v8 < 0 )
      return 0;
    v9 = (signed __int64)v7.mHash.pTable + 8 * (9 * v8 + 3);
    if ( !v9 )
      return 0;
    v10 = (Scaleform::GFx::AS2::Object::Watchpoint *)(v9 + 8);
  }
  if ( !v10 )
    return 0;
  v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5->Members.mHash.pTable;
  if ( v4->SWFVersion <= 6u )
  {
    key.pStr = v3;
    if ( !v3->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v3->pNode);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString::NoCaseKey>(
      v11,
      &key);
  }
  else
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v5->Members.mHash.pTable,
      v3);
  }
  v12 = (Scaleform::GFx::ASString *)v5->Members.mHash.pTable;
  if ( !v12->pNode || !v12->pNode->pData )
  {
    key.pStr = (Scaleform::GFx::ASString *)v5->Members.mHash.pTable;
    if ( v12 )
    {
      key.pStr = v12;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v12);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
    }
    v5->Members.mHash.pTable = 0i64;
  }
  return 1;
}

// File Line: 788
// RVA: 0x6FFBA0
__int64 __fastcall Scaleform::GFx::AS2::Object::InvokeWatchpoint(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *prop, Scaleform::GFx::AS2::Value *newVal, Scaleform::GFx::AS2::Value *resultVal)
{
  Scaleform::GFx::AS2::Value *v5; // rdi
  Scaleform::GFx::ASString *v6; // r15
  Scaleform::GFx::AS2::Environment *v7; // r13
  Scaleform::GFx::AS2::Object *v8; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v9; // r12
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *v10; // rcx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > v11; // rbx
  signed __int64 v12; // rax
  signed __int64 v13; // r14
  Scaleform::GFx::AS2::Object::Watchpoint *v14; // r14
  Scaleform::GFx::AS2::Value **v15; // rbx
  __int64 v16; // rax
  Scaleform::RefCountNTSImpl *v17; // rdi
  __int64 v18; // rax
  signed __int64 v19; // r9
  int v20; // edx
  signed int v21; // esi
  int v22; // edx
  unsigned __int8 v23; // bl
  Scaleform::GFx::AS2::Value v25; // [rsp+20h] [rbp-71h]
  __int64 v26; // [rsp+40h] [rbp-51h]
  char v27; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS2::Environment *v28; // [rsp+50h] [rbp-41h]
  int v29; // [rsp+58h] [rbp-39h]
  int v30; // [rsp+5Ch] [rbp-35h]
  Scaleform::GFx::AS2::Value v31; // [rsp+60h] [rbp-31h]
  Scaleform::GFx::AS2::Value v; // [rsp+80h] [rbp-11h]
  __int64 v33; // [rsp+A0h] [rbp+Fh]

  v33 = -2i64;
  v5 = newVal;
  v6 = prop;
  v7 = penv;
  v8 = this;
  v.T.Type = 0;
  v9 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  this->vfptr->GetMember((Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr, penv, prop, &v);
  v31.T.Type = 0;
  v10 = (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > *)&v8->pWatchpoints->mHash;
  if ( v7->StringContext.SWFVersion <= 6u )
  {
    v14 = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
            v10,
            v6);
  }
  else
  {
    v11.mHash.pTable = v10->mHash.pTable;
    if ( !v10->mHash.pTable )
      goto LABEL_43;
    v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v10->mHash.pTable,
            v6,
            v6->pNode->HashFlags & v11.mHash.pTable->SizeMask);
    if ( v12 < 0 )
      goto LABEL_43;
    v13 = (signed __int64)(&v11.mHash.pTable[1].SizeMask + 9 * v12);
    if ( !v13 )
      goto LABEL_43;
    v14 = (Scaleform::GFx::AS2::Object::Watchpoint *)(v13 + 8);
  }
  if ( !v14 || !v8->pWatchpoints )
  {
LABEL_43:
    v23 = 0;
    goto LABEL_44;
  }
  v15 = &v7->Stack.pCurrent;
  ++*v15;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  if ( *v15 )
    Scaleform::GFx::AS2::Value::Value(*v15, &v14->UserData, (__int64)v5);
  ++*v15;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  if ( *v15 )
    Scaleform::GFx::AS2::Value::Value(*v15, v5, (__int64)v5);
  ++*v15;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  if ( *v15 )
    Scaleform::GFx::AS2::Value::Value(*v15, &v, (__int64)v5);
  LOBYTE(v5) = 5;
  v25.T.Type = 5;
  v25.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v6->pNode;
  ++v25.V.pStringNode->RefCount;
  ++*v15;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  if ( *v15 )
  {
    Scaleform::GFx::AS2::Value::Value(*v15, &v25, (__int64)v5);
    LOBYTE(v5) = v25.T.Type;
  }
  if ( (unsigned __int8)v5 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v25);
  v16 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *))v8->vfptr[2].Finalize_GC)(v8);
  v17 = (Scaleform::RefCountNTSImpl *)v16;
  if ( v16 )
    ++*(_DWORD *)(v16 + 8);
  if ( v16 )
  {
    v18 = (*(__int64 (**)(void))(*(_QWORD *)(v16 + 4i64 * *(unsigned __int8 *)(v16 + 109)) + 8i64))();
    v19 = v18 + 8;
    if ( !v18 )
      v19 = 0i64;
    v20 = ((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5)
        + 32 * v7->Stack.Pages.Data.Size
        - 32;
    *(_QWORD *)&v25.T.Type = &Scaleform::GFx::AS2::FnCall::`vftable;
    v25.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v31;
    *((_OWORD *)&v25.NV + 1) = (unsigned __int64)v19;
    v27 = 0;
    v26 = 0i64;
    v28 = v7;
    v21 = 4;
    v29 = 4;
    v30 = v20;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::LocalFrame *, _QWORD, void **, Scaleform::GFx::AS2::Value *, signed __int64, _QWORD, _QWORD, _QWORD, Scaleform::GFx::AS2::Environment *, _QWORD))v14->Callback.Function->vfptr[3].Finalize_GC)(
      v14->Callback.Function,
      &v25,
      v14->Callback.pLocalFrame,
      0i64,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v31,
      v19,
      0i64,
      0i64,
      *(_QWORD *)&v27,
      v7,
      *(_QWORD *)&v29);
  }
  else
  {
    v22 = ((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5)
        + 32 * v7->Stack.Pages.Data.Size
        - 32;
    *(_QWORD *)&v25.T.Type = &Scaleform::GFx::AS2::FnCall::`vftable;
    v25.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v31;
    *((_OWORD *)&v25.NV + 1) = (unsigned __int64)v9;
    v27 = 0;
    v26 = 0i64;
    v28 = v7;
    v21 = 4;
    v29 = 4;
    v30 = v22;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::LocalFrame *, _QWORD, void **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ObjectInterface *, _QWORD, _QWORD, _QWORD, Scaleform::GFx::AS2::Environment *, _QWORD))v14->Callback.Function->vfptr[3].Finalize_GC)(
      v14->Callback.Function,
      &v25,
      v14->Callback.pLocalFrame,
      0i64,
      &Scaleform::GFx::AS2::FnCall::`vftable,
      &v31,
      v9,
      0i64,
      0i64,
      *(_QWORD *)&v27,
      v7,
      *(_QWORD *)&v29);
  }
  Scaleform::GFx::AS2::FnCall::~FnCall((Scaleform::GFx::AS2::FnCall *)&v25);
  do
  {
    if ( (*v15)->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(*v15);
    --*v15;
    if ( v7->Stack.pCurrent < v7->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v7->Stack);
    --v21;
  }
  while ( v21 );
  Scaleform::GFx::AS2::Value::operator=(resultVal, &v31, (__int64)v17);
  if ( v17 )
    Scaleform::RefCountNTSImpl::Release(v17);
  v23 = 1;
LABEL_44:
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v23;
}

// File Line: 826
// RVA: 0x6D1650
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(Scaleform::GFx::AS2::GASPrototypeBase *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v1; // rbx
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v2; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  v2 = this->pInterfaces;
  if ( v2 )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  if ( !(v1->__Constructor__.Flags & 2) )
  {
    v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->__Constructor__.Function->vfptr;
    if ( v3 )
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
  }
  v1->__Constructor__.Function = 0i64;
  if ( !(v1->__Constructor__.Flags & 1) )
  {
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->__Constructor__.pLocalFrame->vfptr;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( v6 & 0x3FFFFFF )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
  }
  v1->__Constructor__.pLocalFrame = 0i64;
  if ( !(v1->Constructor.Flags & 2) )
  {
    v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->Constructor.Function->vfptr;
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
  v1->Constructor.Function = 0i64;
  if ( !(v1->Constructor.Flags & 1) )
  {
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->Constructor.pLocalFrame->vfptr;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  v1->Constructor.pLocalFrame = 0i64;
}

// File Line: 836
// RVA: 0x6FD0E0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::Object *pthis, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::NameFunction *funcTable, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::NameFunction *v5; // r12
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::Object *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS2::Object *v10; // rbp
  __int64 v11; // r14
  signed __int64 v12; // rsi
  signed __int64 v13; // r13
  Scaleform::GFx::AS2::Object *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v16; // rdi
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // zf
  unsigned int v19; // eax
  unsigned int v20; // eax
  Scaleform::GFx::AS2::Value v21; // [rsp+60h] [rbp-58h]
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+18h]
  Scaleform::GFx::AS2::Object *v23; // [rsp+D8h] [rbp+20h]

  v5 = funcTable;
  v6 = psc;
  v7 = pthis;
  v8 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  v10 = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  v23 = v8;
  v11 = 0i64;
  if ( v5->Name )
  {
    v12 = (signed __int64)v5;
    v13 = (signed __int64)&v7->vfptr;
    do
    {
      v14 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::ASStringNode *, signed __int64))v6->pContext->pHeap->vfptr->Alloc)(
                                             v9,
                                             104i64);
      v15 = v14;
      if ( v14 )
      {
        v16 = *(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)(v12 + 8);
        Scaleform::GFx::AS2::Object::Object(v14, v6);
        v15->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
        v15->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
        v15->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
        v15->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
        v15[1].vfptr = v16;
        Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)((char *)v15 + 32), v6, v10);
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
      v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v6, &result, *(const char **)v12);
      (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v13 + 80i64))(
        v13,
        v6,
        v17,
        &v21,
        flags);
      v9 = result.pNode;
      v18 = result.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
      if ( v15 )
      {
        v19 = v15->RefCount;
        if ( v19 & 0x3FFFFFF )
        {
          v15->RefCount = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
        }
      }
      v12 = (signed __int64)&v5[++v11];
    }
    while ( *(_QWORD *)v12 );
  }
  if ( v10 )
  {
    v20 = v10->RefCount;
    if ( v20 & 0x3FFFFFF )
    {
      v10->RefCount = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
}

// File Line: 851
// RVA: 0x6FBAB0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::Init(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::Object *pthis, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::Object *v5; // rsi
  Scaleform::GFx::AS2::GASPrototypeBase *v6; // rbx
  Scaleform::GFx::AS2::LocalFrame *v7; // rdx
  Scaleform::GFx::AS2::FunctionObject *v8; // rbx
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Value ctor; // [rsp+38h] [rbp-30h]
  char v11; // [rsp+70h] [rbp+8h]

  v4 = psc;
  v5 = pthis;
  v6 = this;
  ctor.T.Type = 8;
  ctor.V.FunctionValue.Flags = 0;
  ctor.V.pStringNode = (Scaleform::GFx::ASStringNode *)constructor->Function;
  if ( ctor.V.pStringNode )
    ctor.V.pStringNode->RefCount = (ctor.V.pStringNode->RefCount + 1) & 0x8FFFFFFF;
  ctor.V.FunctionValue.pLocalFrame = 0i64;
  v7 = constructor->pLocalFrame;
  if ( v7 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&ctor.NV.8,
      v7,
      constructor->Flags & 1);
  Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(v6, v5, v4, &ctor);
  if ( ctor.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ctor);
  v11 = 3;
  v8 = v6->Constructor.Function;
  Scaleform::GFx::AS2::Value::Value(&ctor, v5);
  v8->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
    v9,
    (Scaleform::GFx::AS2::PropFlags *)&v11);
  if ( ctor.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ctor);
}

// File Line: 858
// RVA: 0x713510
char __fastcall Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::Object *pthis, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Value *ctor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::Object *v5; // rsi
  Scaleform::GFx::AS2::GASPrototypeBase *v6; // rbx
  Scaleform::GFx::AS2::FunctionRef *v7; // rax
  char v8; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // [rsp+40h] [rbp-38h]
  char v16; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-28h]
  char v18; // [rsp+80h] [rbp+8h]

  v4 = psc;
  v5 = pthis;
  v6 = this;
  v7 = Scaleform::GFx::AS2::Value::ToFunction(ctor, (Scaleform::GFx::AS2::FunctionRef *)&v14, 0i64);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v6->Constructor.Function,
    (Scaleform::GFx::AS2::FunctionRefBase *)&v7->Function);
  v8 = v16;
  if ( !(v16 & 2) )
  {
    v9 = v14;
    if ( v14 )
    {
      v10 = v14->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        v14->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        v8 = v16;
      }
    }
  }
  v14 = 0i64;
  if ( !(v8 & 1) )
  {
    v11 = v15;
    if ( v15 )
    {
      v12 = v15->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v15->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
  v15 = 0i64;
  v18 = 3;
  v17.T.Type = 10;
  v5->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
    &v17,
    (Scaleform::GFx::AS2::PropFlags *)&v18);
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  return 1;
}

// File Line: 866
// RVA: 0x6D85D0
void __fastcall Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::ASStringContext *psc, int index, Scaleform::GFx::AS2::FunctionObject *pinterface)
{
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS2::GASPrototypeBase *v5; // rdi
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rax
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v7; // rbx
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v10; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value v14; // [rsp+38h] [rbp-30h]

  v4 = index;
  v5 = this;
  if ( this->pInterfaces || pinterface )
  {
    v14.T.Type = 0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, signed __int64))pinterface->vfptr->GetMemberRaw)(
           &pinterface->vfptr,
           psc,
           &psc->pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
           &v14,
           -2i64) )
    {
      v8 = Scaleform::GFx::AS2::Value::ToObject(&v14, 0i64);
      v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr;
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v5->pInterfaces->Data.Data[v4];
      if ( v8 )
        v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
      v11 = *v10;
      if ( *v10 )
      {
        v12 = v11->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          v11->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      *v10 = v9;
      if ( v9 )
      {
        v13 = v9->RefCount;
        if ( v13 & 0x3FFFFFF )
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
    v6 = (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)psc->pContext->pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 24ui64, 0i64);
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
    v5->pInterfaces = v7;
  }
}

// File Line: 881
// RVA: 0x6E2BD0
char __fastcall Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *prototype, __int64 a4)
{
  Scaleform::GFx::AS2::Object *v4; // r15
  Scaleform::GFx::AS2::Environment *v5; // r12
  Scaleform::GFx::AS2::GASPrototypeBase *v6; // r14
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v7; // rax
  unsigned int v8; // edi
  unsigned __int64 v9; // rbp
  __int64 v10; // rsi
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v11; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  signed __int64 v18; // [rsp+20h] [rbp-38h]

  v18 = -2i64;
  v4 = prototype;
  v5 = penv;
  v6 = this;
  v7 = this->pInterfaces;
  if ( !v7 )
    return 0;
  v8 = 0;
  v9 = v7->Data.Size;
  if ( !(_DWORD)v9 )
    return 0;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v6->pInterfaces;
    v12 = v11->Data.Data;
    v13 = v11->Data.Data[v10].pObject;
    if ( v13 )
      v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
    v14 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12[v10].pObject->vfptr;
    if ( v14 )
    {
      LOBYTE(a4) = 1;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *, __int64, signed __int64))v14[1].vfptr[6].ExecuteForEachChild_GC)(
             &v14[1],
             v5,
             v4,
             a4,
             v18) )
      {
        break;
      }
    }
    if ( v14 )
    {
      v15 = v14->RefCount;
      if ( v15 & 0x3FFFFFF )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
      }
    }
    ++v8;
    ++v10;
    if ( v8 >= (unsigned int)v9 )
      return 0;
  }
  v16 = v14->RefCount;
  if ( v16 & 0x3FFFFFF )
  {
    v14->RefCount = v16 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
  }
  return 1;
}

// File Line: 895
// RVA: 0x6F40C0
__int64 __usercall Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor@<rax>(Scaleform::GFx::AS2::GASPrototypeBase *this@<rcx>, Scaleform::GFx::AS2::Object *pthis@<rdx>, Scaleform::GFx::AS2::ASStringContext *psc@<r8>, Scaleform::GFx::ASString *name@<r9>, Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *a5@<rdi>)
{
  Scaleform::GFx::ASString *v5; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v6; // r13
  Scaleform::GFx::AS2::GASPrototypeBase *v7; // rsi
  char v8; // r15
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  bool v11; // zf
  signed __int64 v12; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v13; // r8
  signed __int64 v14; // rax
  signed __int64 v15; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rbx
  Scaleform::GFx::AS2::FunctionRef *v18; // rax
  char v19; // al
  Scaleform::GFx::AS2::FunctionObject *v20; // rcx
  unsigned int v21; // edx
  Scaleform::GFx::AS2::LocalFrame *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS2::LocalFrame *v24; // rdi
  Scaleform::GFx::AS2::FunctionObject *v25; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v26; // rcx
  unsigned __int8 v27; // bl
  unsigned int v28; // eax
  Scaleform::GFx::AS2::FunctionRefBase *v29; // rcx
  unsigned int v30; // eax
  unsigned int v31; // eax
  Scaleform::GFx::AS2::FunctionRefBase v33; // [rsp+0h] [rbp-59h]
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+18h] [rbp-41h]
  Scaleform::GFx::AS2::Value v; // [rsp+30h] [rbp-29h]
  Scaleform::GFx::AS2::Value v36; // [rsp+50h] [rbp-9h]
  __int64 v37; // [rsp+70h] [rbp+17h]
  Scaleform::GFx::ASString::NoCaseKey key; // [rsp+B8h] [rbp+5Fh]
  __int64 v39; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::AS2::Value *retaddr; // [rsp+D0h] [rbp+77h]
  char v41; // [rsp+D8h] [rbp+7Fh]

  v37 = -2i64;
  v5 = name;
  v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pthis;
  v7 = this;
  v.T = 0;
  v8 = 10;
  v36.T.Type = 10;
  if ( psc->SWFVersion <= 6u )
  {
    key.pStr = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v13 = v6[6].pTable;
    if ( !v13 )
      goto LABEL_13;
    v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
            v6 + 6,
            &key,
            v5->pNode->HashFlags & v13->SizeMask);
    if ( v14 < 0 )
      goto LABEL_13;
    v15 = 3 * v14;
    v16 = v6[6].pTable;
    v11 = &v16[v15 + 1].SizeMask == 0i64;
    v12 = (signed __int64)&v16[v15 + 1].SizeMask;
  }
  else
  {
    a5 = pthis->Members.mHash.pTable;
    if ( !a5 )
      goto LABEL_13;
    v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pthis->Members,
           name,
           name->pNode->HashFlags & a5->SizeMask);
    if ( v9 < 0 )
      goto LABEL_13;
    v10 = 3 * v9;
    v11 = &a5[v10 + 1].SizeMask == 0i64;
    v12 = (signed __int64)&a5[v10 + 1].SizeMask;
  }
  if ( !v11 )
  {
    v17 = (Scaleform::GFx::AS2::Value *)(v12 + 8);
    Scaleform::GFx::AS2::Value::operator=(&v, v17, (__int64)a5);
    v.T.PropFlags = v17->T.PropFlags;
    Scaleform::GFx::AS2::Value::operator=(&v36, &v, (__int64)a5);
    v8 = v36.T.Type;
    if ( v36.T.Type != 10 )
    {
      Scaleform::GFx::AS2::Value::operator=(retaddr, &v36, (__int64)a5);
      v8 = v36.T.Type;
LABEL_44:
      v27 = 1;
      goto LABEL_45;
    }
  }
LABEL_13:
  v33.Flags = 0;
  v33.Function = 0i64;
  v33.pLocalFrame = 0i64;
  if ( v41 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::Assign(
      &v33,
      (Scaleform::GFx::AS2::FunctionRefBase *)&v7->__Constructor__.Function);
  }
  else
  {
    v18 = Scaleform::GFx::AS2::GASPrototypeBase::GetConstructor(v7, &result);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&v33, (Scaleform::GFx::AS2::FunctionRefBase *)&v18->Function);
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
  }
  v24 = v33.pLocalFrame;
  v25 = v33.Function;
  if ( v33.Function )
  {
    if ( retaddr->T.Type != 8 || retaddr->V.pStringNode != (Scaleform::GFx::ASStringNode *)v33.Function )
    {
      Scaleform::GFx::AS2::Value::DropRefs(retaddr);
      retaddr->T.Type = 8;
      v29 = (Scaleform::GFx::AS2::FunctionRefBase *)&retaddr->NV.8;
      v29->Flags = 0;
      v29->Function = v25;
      v25->RefCount = (v25->RefCount + 1) & 0x8FFFFFFF;
      v29->pLocalFrame = 0i64;
      if ( v24 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v29, v24, v33.Flags & 1);
    }
    goto LABEL_35;
  }
  Scaleform::GFx::AS2::Value::DropRefs(retaddr);
  retaddr->T.Type = (char)v25;
  v26 = v6[5].pTable;
  if ( !v26 )
  {
LABEL_35:
    if ( !(v33.Flags & 2) )
    {
      if ( v25 )
      {
        v30 = v25->RefCount;
        if ( v30 & 0x3FFFFFF )
        {
          v25->RefCount = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
        }
      }
    }
    v33.Function = 0i64;
    if ( !(v33.Flags & 1) )
    {
      if ( v24 )
      {
        v31 = v24->RefCount;
        if ( v31 & 0x3FFFFFF )
        {
          v24->RefCount = v31 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v24->vfptr);
        }
      }
    }
    v33.pLocalFrame = 0i64;
    goto LABEL_44;
  }
  v27 = (*(__int64 (__fastcall **)(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(v26[2].EntryCount + 88))(
          v26 + 2,
          v39,
          v5,
          retaddr);
  v33.Function = 0i64;
  if ( !(v33.Flags & 1) )
  {
    if ( v24 )
    {
      v28 = v24->RefCount;
      if ( v28 & 0x3FFFFFF )
      {
        v24->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v24->vfptr);
      }
    }
  }
  v33.pLocalFrame = 0i64;
LABEL_45:
  if ( (unsigned __int8)v8 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v36);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return v27;
}

// File Line: 952
// RVA: 0x6CB470
void __fastcall Scaleform::GFx::AS2::ObjectProto::ObjectProto(Scaleform::GFx::AS2::ObjectProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::ObjectProto *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    pprototype);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable;
}

// File Line: 962
// RVA: 0x6B2BF0
void __fastcall Scaleform::GFx::AS2::ObjectProto::AddProperty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // r10
  unsigned int v5; // er10
  Scaleform::GFx::AS2::Environment *v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r9
  char v8; // r15
  Scaleform::GFx::AS2::FunctionObject *v9; // rdi
  Scaleform::GFx::AS2::LocalFrame *v10; // rsi
  unsigned int v11; // er8
  Scaleform::GFx::AS2::Environment *v12; // r14
  Scaleform::GFx::AS2::Value *v13; // rdx
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::FunctionRef *v15; // rax
  char v16; // al
  Scaleform::GFx::AS2::FunctionObject *v17; // rcx
  unsigned int v18; // edx
  Scaleform::GFx::AS2::LocalFrame *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::InteractiveObject *v21; // rcx
  __int64 v22; // r12
  __int64 v23; // r14
  Scaleform::GFx::AS2::FunctionRefBase *v24; // rcx
  Scaleform::GFx::AS2::FunctionObject *v25; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v26; // rcx
  Scaleform::GFx::AS2::Value *v27; // rbx
  unsigned int v28; // eax
  unsigned int v29; // eax
  Scaleform::GFx::AS2::Value *v30; // rbx
  char v31; // al
  Scaleform::GFx::AS2::FunctionObject *v32; // rcx
  unsigned int v33; // edx
  Scaleform::GFx::AS2::LocalFrame *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::ASStringNode *v36; // rcx
  bool v37; // zf
  Scaleform::GFx::AS2::Value *v38; // rbx
  Scaleform::GFx::AS2::FunctionRef v39; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::FunctionRefBase v40; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS2::FunctionRef v41; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v42; // [rsp+78h] [rbp-1h]
  __int64 v43; // [rsp+98h] [rbp+1Fh]
  Scaleform::MemoryHeap *v44; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+6Fh]
  __int64 v46; // [rsp+F0h] [rbp+77h]

  v43 = -2i64;
  v1 = fn;
  if ( fn->NArgs < 2 )
  {
    v38 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v38->T.Type = 2;
    v38->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
    v5 = v1->FirstArgBottomIndex - 1;
    v6 = v1->Env;
    v7 = 0i64;
    if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
      v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v7, &v39, v6);
    if ( v39.Function )
    {
      v8 = 0;
      v40.Flags = 0;
      v9 = 0i64;
      v40.Function = 0i64;
      v10 = 0i64;
      v40.pLocalFrame = 0i64;
      if ( v1->NArgs >= 3 )
      {
        v11 = v1->FirstArgBottomIndex - 2;
        v12 = v1->Env;
        v13 = 0i64;
        if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
          v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
        if ( v13->T.Type == 8 || v13->T.Type == 11 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
          v15 = Scaleform::GFx::AS2::Value::ToFunction(v14, &v41, v12);
          Scaleform::GFx::AS2::FunctionRefBase::Assign(&v40, (Scaleform::GFx::AS2::FunctionRefBase *)&v15->Function);
          v16 = v41.Flags;
          if ( !(v41.Flags & 2) )
          {
            v17 = v41.Function;
            if ( v41.Function )
            {
              v18 = v41.Function->RefCount;
              if ( v18 & 0x3FFFFFF )
              {
                v41.Function->RefCount = v18 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v17->vfptr);
                v16 = v41.Flags;
              }
            }
          }
          v41.Function = 0i64;
          if ( !(v16 & 1) )
          {
            v19 = v41.pLocalFrame;
            if ( v41.pLocalFrame )
            {
              v20 = v41.pLocalFrame->RefCount;
              if ( v20 & 0x3FFFFFF )
              {
                v41.pLocalFrame->RefCount = v20 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v19->vfptr);
              }
            }
          }
          v41.pLocalFrame = 0i64;
          v8 = v40.Flags;
          v10 = v40.pLocalFrame;
          v9 = v40.Function;
        }
      }
      v21 = v1->Env->Target;
      if ( v21 )
        v22 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v21->vfptr + 4 * (unsigned __int8)v21->AvmObjOffset))[1].__vecDelDtor)()
                                                            + 24)
                                                + 32i64)
                                    + 56i64)
                        + 32i64);
      else
        v22 = 0i64;
      v44 = v1->Env->StringContext.pContext->pHeap;
      v42.T.Type = 9;
      v23 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64))v44->vfptr->Alloc)(v21, 80i64);
      v46 = v23;
      if ( v23 )
      {
        *(_QWORD *)v23 = &Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
        *(_QWORD *)(v23 + 8) = v22;
        *(_DWORD *)(v23 + 24) = 1;
        *(_QWORD *)v23 = &Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::ValueProperty>::`vftable;
        *(_QWORD *)v23 = &Scaleform::GFx::AS2::ValueProperty::`vftable;
        v24 = (Scaleform::GFx::AS2::FunctionRefBase *)(v23 + 32);
        v24->Flags = 0;
        v24->Function = v39.Function;
        v25 = v39.Function;
        if ( v39.Function )
        {
          ++v39.Function->RefCount;
          v25->RefCount &= 0x8FFFFFFF;
        }
        *(_QWORD *)(v23 + 40) = 0i64;
        if ( v39.pLocalFrame )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v24, v39.pLocalFrame, v39.Flags & 1);
        v26 = (Scaleform::GFx::AS2::FunctionRefBase *)(v23 + 56);
        v26->Flags = 0;
        v26->Function = v9;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
        *(_QWORD *)(v23 + 64) = 0i64;
        if ( v10 )
          Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v26, v10, v8 & 1);
      }
      else
      {
        v23 = 0i64;
      }
      v42.V.pStringNode = (Scaleform::GFx::ASStringNode *)v23;
      LOBYTE(v44) = 0;
      v1->ThisPtr->vfptr->SetMemberRaw(
        v1->ThisPtr,
        &v1->Env->StringContext,
        &result,
        &v42,
        (Scaleform::GFx::AS2::PropFlags *)&v44);
      v27 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v27);
      v27->T.Type = 2;
      v27->V.BooleanValue = 1;
      if ( v42.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v42);
      if ( !(v8 & 2) )
      {
        if ( v9 )
        {
          v28 = v9->RefCount;
          if ( v28 & 0x3FFFFFF )
          {
            v9->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
          }
        }
      }
      v40.Function = 0i64;
      if ( !(v8 & 1) )
      {
        if ( v10 )
        {
          v29 = v10->RefCount;
          if ( v29 & 0x3FFFFFF )
          {
            v10->RefCount = v29 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
          }
        }
      }
      v40.pLocalFrame = 0i64;
    }
    else
    {
      v30 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v30);
      v30->T.Type = 2;
      v30->V.BooleanValue = 0;
    }
    v31 = v39.Flags;
    if ( !(v39.Flags & 2) )
    {
      v32 = v39.Function;
      if ( v39.Function )
      {
        v33 = v39.Function->RefCount;
        if ( v33 & 0x3FFFFFF )
        {
          v39.Function->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
          v31 = v39.Flags;
        }
      }
    }
    v39.Function = 0i64;
    if ( !(v31 & 1) )
    {
      v34 = v39.pLocalFrame;
      if ( v39.pLocalFrame )
      {
        v35 = v39.pLocalFrame->RefCount;
        if ( v35 & 0x3FFFFFF )
        {
          v39.pLocalFrame->RefCount = v35 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v34->vfptr);
        }
      }
    }
    v39.pLocalFrame = 0i64;
    v36 = result.pNode;
    v37 = result.pNode->RefCount == 1;
    --v36->RefCount;
    if ( v37 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  }
}

// File Line: 987
// RVA: 0x6B3020
void __fastcall Scaleform::GFx::AS2::ObjectProto::HasOwnProperty(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  char v6; // di
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->FirstArgBottomIndex;
  v3 = fn->Env;
  v4 = 0i64;
  if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD, signed __int64))v1->ThisPtr->vfptr->HasMember)(
         v1->ThisPtr,
         &v1->Env->StringContext,
         v5,
         0i64,
         -2i64);
  v7 = v1->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->T.Type = 2;
  v7->V.BooleanValue = v6;
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 994
// RVA: 0x6B32F0
void __fastcall Scaleform::GFx::AS2::ObjectProto::Watch_(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // r10
  unsigned int v5; // edx
  Scaleform::GFx::AS2::Environment *v6; // r9
  Scaleform::GFx::AS2::Value *v7; // r8
  unsigned int v8; // er9
  Scaleform::GFx::AS2::Environment *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  Scaleform::GFx::ASString *v11; // rax
  bool v12; // di
  Scaleform::GFx::AS2::Value *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS2::Value *v16; // rbx
  char v17; // al
  Scaleform::GFx::AS2::FunctionObject *v18; // rcx
  unsigned int v19; // edx
  Scaleform::GFx::AS2::LocalFrame *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value *v22; // rbx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::Value v24; // [rsp+50h] [rbp-28h]
  Scaleform::GFx::ASString v25; // [rsp+80h] [rbp+8h]

  v1 = fn;
  if ( fn->NArgs < 2 )
  {
    v22 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v22->T.Type = 2;
    v22->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex - 1;
    v3 = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v4, &result, v3);
    if ( result.Function )
    {
      v24.T.Type = 0;
      if ( v1->NArgs >= 3 )
      {
        v5 = v1->FirstArgBottomIndex - 2;
        v6 = v1->Env;
        v7 = 0i64;
        if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
                 + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
          v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
        Scaleform::GFx::AS2::Value::operator=(&v24, v7);
      }
      v8 = v1->FirstArgBottomIndex;
      v9 = v1->Env;
      v10 = 0i64;
      if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
        v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
      v11 = Scaleform::GFx::AS2::Value::ToString(v10, &v25, v9, -1);
      v12 = v1->ThisPtr->vfptr->Watch(v1->ThisPtr, &v1->Env->StringContext, v11, &result, &v24);
      v13 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v13);
      v13->T.Type = 2;
      v13->V.BooleanValue = v12;
      v14 = v25.pNode;
      v15 = v25.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v24.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v24);
    }
    else
    {
      v16 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v16);
      v16->T.Type = 2;
      v16->V.BooleanValue = 0;
    }
    v17 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v18 = result.Function;
      if ( result.Function )
      {
        v19 = result.Function->RefCount;
        if ( v19 & 0x3FFFFFF )
        {
          result.Function->RefCount = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v18->vfptr);
          v17 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v17 & 1) )
    {
      v20 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v21 = result.pLocalFrame->RefCount;
        if ( v21 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
        }
      }
    }
    result.pLocalFrame = 0i64;
  }
}rm::GFx::AS2::RefCountBaseGC<323> *)&v20->vfptr);
        }
      }
    }
    result.pLocalF

// File Line: 1017
// RVA: 0x6B3520
void __fastcall Scaleform::GFx::AS2::ObjectProto::Unwatch_(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  bool v6; // di
  Scaleform::GFx::AS2::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS2::Value *v10; // rbx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  if ( fn->NArgs < 1 )
  {
    v10 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v10->T.Type = 2;
    v10->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
    v6 = v1->ThisPtr->vfptr->Unwatch(v1->ThisPtr, &v1->Env->StringContext, v5);
    v7 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 2;
    v7->V.BooleanValue = v6;
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 1029
// RVA: 0x6B30E0
void __fastcall Scaleform::GFx::AS2::ObjectProto::IsPropertyEnumerable(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  char v5; // di
  Scaleform::GFx::AS2::Value *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v1 = fn;
  if ( fn->NArgs < 1 )
  {
    v9 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v9->T.Type = 2;
    v9->V.BooleanValue = 0;
  }
  else
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = fn->Env;
    v4 = 0i64;
    if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
      v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD, signed __int64))v1->ThisPtr->vfptr->HasMember)(
           v1->ThisPtr,
           &v1->Env->StringContext,
           &result,
           0i64,
           -2i64);
    if ( v5 )
    {
      v10.T = 0;
      v1->ThisPtr->vfptr->FindMember(v1->ThisPtr, &v1->Env->StringContext, &result, (Scaleform::GFx::AS2::Member *)&v10);
      if ( v10.T.PropFlags & 1 )
        v5 = 0;
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
    }
    v6 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 2;
    v6->V.BooleanValue = v5;
    v7 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 1050
// RVA: 0x6B3210
void __fastcall Scaleform::GFx::AS2::ObjectProto::IsPrototypeOf(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rax
  Scaleform::GFx::AS2::Value *v3; // r8
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS2::ObjectInterface *v7; // rax
  bool v8; // al
  Scaleform::GFx::AS2::Value *v9; // rbx
  bool v10; // di
  Scaleform::GFx::AS2::Value *v11; // rbx

  v1 = fn;
  if ( fn->NArgs < 1 || (*(unsigned int (**)(void))&fn->ThisPtr->vfptr->gap8[8])() - 2 <= 3 )
    goto LABEL_12;
  v2 = v1->ThisPtr;
  v3 = 0i64;
  v4 = (signed __int64)&v2[-2];
  if ( !v2 )
    v4 = 0i64;
  v5 = v1->Env;
  v6 = (unsigned int)v1->FirstArgBottomIndex;
  if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
    v3 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObjectInterface(v3, v5);
  if ( v7 )
  {
    v8 = v7->vfptr->InstanceOf(v7, v1->Env, (Scaleform::GFx::AS2::Object *)v4, 0);
    v9 = v1->Result;
    v10 = v8;
    Scaleform::GFx::AS2::Value::DropRefs(v9);
    v9->V.BooleanValue = v10;
    v9->T.Type = 2;
  }
  else
  {
LABEL_12:
    v11 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v11);
    v11->V.BooleanValue = 0;
    v11->T.Type = 2;
  }
}

// File Line: 1067
// RVA: 0x6B35F0
void __fastcall Scaleform::GFx::AS2::ObjectProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::ASMovieRootBase *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::AS2::ObjectInterface *v5; // rdi
  Scaleform::GFx::DisplayObject *v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rax
  Scaleform::GFx::ASString *v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASMovieRootBase *v11; // rdi
  Scaleform::GFx::AS2::Value v12; // [rsp+28h] [rbp-30h]

  v1 = fn;
  if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 23 )
  {
    v2 = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v3 = v1->Result;
    if ( v3->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v3);
    v3->T.Type = 5;
    v4 = (Scaleform::GFx::ASStringNode *)v2[24].pMovieImpl;
LABEL_21:
    v3->V.pStringNode = v4;
    ++v4->RefCount;
    return;
  }
  if ( (*(unsigned int (**)(void))&v1->ThisPtr->vfptr->gap8[8])() - 2 > 3 )
  {
    v11 = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v3 = v1->Result;
    if ( v3->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v3);
    v3->T.Type = 5;
    v4 = *(Scaleform::GFx::ASStringNode **)&v11[24].AVMVersion;
    goto LABEL_21;
  }
  v5 = v1->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->vfptr->gap8[8])(v1->ThisPtr) - 2 > 3 )
    v6 = 0i64;
  else
    v6 = (Scaleform::GFx::DisplayObject *)v5[1].vfptr;
  v12.T.Type = 7;
  if ( v6 )
  {
    v7 = (Scaleform::GFx::ASStringNode *)v6->pNameHandle.pObject;
    if ( !v7 )
      v7 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v6);
    v12.V.pStringNode = v7;
    if ( v7 )
      ++LODWORD(v7->pData);
  }
  else
  {
    v12.V.pStringNode = 0i64;
  }
  v8 = Scaleform::GFx::AS2::Value::GetCharacterNamePath(&v12, v1->Env);
  v9 = v1->Result;
  if ( v9->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v9);
  v9->T.Type = 5;
  v10 = v8->pNode;
  v9->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v8->pNode;
  ++v10->RefCount;
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
void __fastcall Scaleform::GFx::AS2::ObjectProto::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  unsigned int v2; // er8
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v3; // rdx
  Scaleform::GFx::AS2::Value *v4; // r10
  char v5; // r8
  char v6; // dl
  long double v7; // xmm0_8
  bool v8; // al
  Scaleform::GFx::ASString *v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS2::ObjectInterface *v11; // rbx
  signed __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rax
  signed __int64 v14; // rax
  char v15; // dl
  Scaleform::GFx::AS2::FunctionObject *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::LocalFrame *v18; // rcx
  unsigned int v19; // eax
  int v20; // eax
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS2::Value v22; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+20h]
  Scaleform::MemoryHeap *v25; // [rsp+A8h] [rbp+28h]
  Scaleform::GFx::AS2::Object *v26; // [rsp+B0h] [rbp+30h]

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->FirstArgBottomIndex;
    v3 = &fn->Env->Stack;
    v4 = 0i64;
    fn = (Scaleform::GFx::AS2::FnCall *)(32 * ((unsigned int)fn->Env->Stack.Pages.Data.Size - 1)
                                       + (unsigned int)((_QWORD)((char *)v3->pCurrent - (char *)fn->Env->Stack.pPageStart) >> 5));
    if ( v2 <= (unsigned int)fn )
    {
      fn = (Scaleform::GFx::AS2::FnCall *)(v2 >> 5);
      v4 = &v3->Pages.Data.Data[(_QWORD)fn]->Values[v2 & 0x1F];
    }
    v5 = 0;
    v22.T.Type = 0;
    v6 = v4->T.Type;
    if ( (unsigned __int8)(v4->T.Type - 3) > 1u )
    {
      if ( v6 != 2 )
      {
        if ( v6 == 5 )
        {
          v9 = Scaleform::GFx::AS2::Value::ToString(v4, &result, v1->Env, -1);
          v.T.Type = 5;
          v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v9->pNode;
          ++v.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::Value::operator=(&v22, &v, (__int64)v1);
          if ( v.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
          fn = (Scaleform::GFx::AS2::FnCall *)result.pNode;
          v10 = result.pNode->RefCount == 1;
          --LODWORD(fn->ThisFunctionRef.Function);
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)fn);
        }
        else
        {
          if ( (unsigned __int8)(v6 - 6) > 1u )
          {
LABEL_21:
            if ( (unsigned __int8)v5 >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v22);
            goto LABEL_23;
          }
          Scaleform::GFx::AS2::Value::operator=(&v22, v4, (__int64)v1);
        }
LABEL_17:
        v5 = v22.T.Type;
        if ( v22.T.Type && v22.T.Type != 10 )
        {
          Scaleform::GFx::AS2::Value::operator=(v1->Result, &v22, (__int64)v1);
          if ( v22.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v22);
          return;
        }
        goto LABEL_21;
      }
      v8 = Scaleform::GFx::AS2::Value::ToBool(v4, v1->Env);
      v.T.Type = 2;
      v.V.BooleanValue = v8;
      Scaleform::GFx::AS2::Value::operator=(&v22, &v, (__int64)v1);
    }
    else
    {
      v7 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1->Env);
      v.T.Type = 3;
      v.NV.NumberValue = v7;
      Scaleform::GFx::AS2::Value::operator=(&v22, &v, (__int64)v1);
    }
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    goto LABEL_17;
  }
LABEL_23:
  result.pNode = 0i64;
  v11 = v1->ThisPtr;
  if ( v11 )
  {
    v12 = (signed __int64)&v11[-2];
    if ( v12 )
    {
      ++*(_DWORD *)(v12 + 24);
      *(_DWORD *)(v12 + 24) &= 0x8FFFFFFF;
    }
  }
  else
  {
    v25 = v1->Env->StringContext.pContext->pHeap;
    v13 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v25->vfptr->Alloc)(
                                           fn,
                                           96i64);
    v26 = v13;
    if ( v13 )
    {
      Scaleform::GFx::AS2::Object::Object(v13, v1->Env);
      v12 = v14;
    }
    else
    {
      v12 = 0i64;
    }
  }
  result.pNode = (Scaleform::GFx::ASStringNode *)v12;
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, &ctorFunc, ASBuiltin_Object);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    (Scaleform::GFx::AS2::ObjectInterface *)(v12 + 32),
    &v1->Env->StringContext,
    &ctorFunc);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)v12);
  v15 = ctorFunc.Flags;
  if ( !(ctorFunc.Flags & 2) )
  {
    v16 = ctorFunc.Function;
    if ( ctorFunc.Function )
    {
      v17 = ctorFunc.Function->RefCount;
      if ( v17 & 0x3FFFFFF )
      {
        ctorFunc.Function->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
        v15 = ctorFunc.Flags;
      }
    }
  }
  ctorFunc.Function = 0i64;
  if ( !(v15 & 1) )
  {
    v18 = ctorFunc.pLocalFrame;
    if ( ctorFunc.pLocalFrame )
    {
      v19 = ctorFunc.pLocalFrame->RefCount;
      if ( v19 & 0x3FFFFFF )
      {
        ctorFunc.pLocalFrame->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v18->vfptr);
      }
    }
  }
  ctorFunc.pLocalFrame = 0i64;
  if ( v12 )
  {
    v20 = *(_DWORD *)(v12 + 24);
    if ( v20 & 0x3FFFFFF )
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
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::GlobalContext *v4; // rbx
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Value *v6; // rdi
  Scaleform::GFx::AS2::Value *v7; // r10
  unsigned int v8; // er9
  Scaleform::GFx::AS2::Environment *v9; // r10
  Scaleform::GFx::AS2::Value *v10; // r8
  Scaleform::GFx::AS2::Value *v11; // rdx
  bool v12; // di
  Scaleform::GFx::AS2::Value *v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS2::Value *v16; // r11
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v17; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v18; // r11
  Scaleform::GFx::ASStringNode *v19; // rax
  unsigned __int64 v20; // r14
  Scaleform::GFx::AS2::FunctionRef *v21; // r10
  Scaleform::GFx::AS2::FunctionRef *v22; // r8
  signed __int64 v23; // r9
  Scaleform::GFx::ASStringNode *v24; // rdx
  Scaleform::GFx::AS2::FunctionRef *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS2::Value *v27; // rbx
  char v28; // al
  Scaleform::GFx::AS2::FunctionObject *v29; // rcx
  unsigned int v30; // edx
  Scaleform::GFx::AS2::LocalFrame *v31; // rcx
  unsigned int v32; // eax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::AS2::FunctionRef v35; // [rsp+38h] [rbp-18h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+20h]
  Scaleform::GFx::ASString v37; // [rsp+78h] [rbp+28h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( v1->NArgs < 2 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(v1->Env, "Error: Too few parameters for Object.registerClass (%d)");
    return;
  }
  v3 = v1->Env;
  v4 = v3->StringContext.pContext;
  v5 = v1->FirstArgBottomIndex;
  v6 = 0i64;
  v7 = 0i64;
  if ( v5 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v7 = &v3->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v7, &result, v3, -1);
  v8 = v1->FirstArgBottomIndex - 1;
  v9 = v1->Env;
  v10 = 0i64;
  if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
    v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  if ( v10->T.Type == 8 || v10->T.Type == 11 )
  {
    v16 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v16 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v16, &v35, v1->Env);
    v17 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v4->RegisteredClasses.mHash.pTable;
    if ( v1->Env->StringContext.SWFVersion <= 6u )
    {
      v37.pNode = (Scaleform::GFx::ASStringNode *)&result;
      v19 = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        v19 = result.pNode;
      }
      if ( v17->pTable )
      {
        v25 = (Scaleform::GFx::AS2::FunctionRef *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                                                    v17,
                                                    (Scaleform::GFx::ASString::NoCaseKey *)&v37,
                                                    v19->HashFlags & v17->pTable->SizeMask);
        if ( (signed __int64)v25 >= 0 )
        {
          key.pFirst = (Scaleform::GFx::ASString *)v17;
          key.pSecond = v25;
          v19 = result.pNode;
          goto LABEL_36;
        }
        v19 = result.pNode;
      }
    }
    else
    {
      v18.pTable = v17->pTable;
      v19 = result.pNode;
      if ( v17->pTable )
      {
        v20 = v18.pTable->SizeMask;
        v21 = (Scaleform::GFx::AS2::FunctionRef *)((unsigned int)v20 & result.pNode->HashFlags);
        v22 = v21;
        v23 = (signed __int64)v18.pTable + 8 * ((_QWORD)v21 + 4 * (_QWORD)v21 + 2);
        if ( *(_QWORD *)v23 != -2i64
          && (Scaleform::GFx::AS2::FunctionRef *)((unsigned int)v20 & *(_DWORD *)(*(_QWORD *)(v23 + 8) + 28i64)) == v21 )
        {
          while ( 1 )
          {
            v24 = *(Scaleform::GFx::ASStringNode **)(v23 + 8);
            if ( (Scaleform::GFx::AS2::FunctionRef *)((unsigned int)v20 & v24->HashFlags) == v21 && v24 == result.pNode )
              break;
            v22 = *(Scaleform::GFx::AS2::FunctionRef **)v23;
            if ( *(_QWORD *)v23 == -1i64 )
              goto LABEL_35;
            v23 = (signed __int64)v18.pTable + 8 * ((_QWORD)v22 + 4 * (_QWORD)v22 + 2);
          }
          if ( (signed __int64)v22 >= 0 )
          {
            key.pFirst = (Scaleform::GFx::ASString *)v17;
            key.pSecond = v22;
            goto LABEL_36;
          }
        }
      }
    }
LABEL_35:
    key.pFirst = 0i64;
    key.pSecond = 0i64;
LABEL_36:
    if ( key.pFirst && (v26 = key.pFirst->pNode) != 0i64 && (_QWORD)key.pSecond <= (_QWORD)v26->pManager )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v26[(_QWORD)key.pSecond].Size,
        (Scaleform::GFx::AS2::FunctionRefBase *)&v35.Function);
    }
    else
    {
      key.pFirst = &result;
      key.pSecond = &v35;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        v17,
        v17,
        &key,
        v19->HashFlags);
    }
    v27 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v27->T.Type = 2;
    v27->V.BooleanValue = 1;
    v28 = v35.Flags;
    if ( !(v35.Flags & 2) )
    {
      v29 = v35.Function;
      if ( v35.Function )
      {
        v30 = v35.Function->RefCount;
        if ( v30 & 0x3FFFFFF )
        {
          v35.Function->RefCount = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v29->vfptr);
          v28 = v35.Flags;
        }
      }
    }
    v35.Function = 0i64;
    if ( !(v28 & 1) )
    {
      v31 = v35.pLocalFrame;
      if ( v35.pLocalFrame )
      {
        v32 = v35.pLocalFrame->RefCount;
        if ( v32 & 0x3FFFFFF )
        {
          v35.pLocalFrame->RefCount = v32 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v31->vfptr);
        }
      }
    }
    v35.pLocalFrame = 0i64;
    goto LABEL_50;
  }
  v11 = 0i64;
  if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
    v11 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  if ( v11->T.Type == 1 )
  {
    v12 = Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(v4, &v9->StringContext, &result);
    v13 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v13->T.Type = 2;
    v13->V.BooleanValue = v12;
  }
  else
  {
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v6 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    Scaleform::GFx::AS2::Value::ToString(v6, &v37, v1->Env, -1);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Second parameter of Object.registerClass(%s, %s) should be function or null",
      result.pNode->pData,
      v37.pNode->pData,
      -2i64);
    v14 = v37.pNode;
    v15 = v37.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
LABEL_50:
  v33 = result.pNode;
  v15 = result.pNode->RefCount == 1;
  --v33->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
}

// File Line: 1189
// RVA: 0x6E0540
Scaleform::GFx::AS2::Object *__fastcall Scaleform::GFx::AS2::FunctionCtorFunction::CreateNewObject(Scaleform::GFx::AS2::FunctionCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rdi
  Scaleform::GFx::AS2::Object *v3; // rax
  Scaleform::GFx::AS2::Object *v4; // rbx

  v2 = &penv->StringContext;
  v3 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                        this,
                                        104i64);
  v4 = v3;
  if ( !v3 )
    return 0i64;
  Scaleform::GFx::AS2::Object::Object(v3, v2);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v4[1].vfptr = 0i64;
  return v4;
}

