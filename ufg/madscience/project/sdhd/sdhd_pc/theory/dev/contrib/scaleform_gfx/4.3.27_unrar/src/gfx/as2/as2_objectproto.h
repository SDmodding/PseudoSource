// File Line: 87
// RVA: 0x6EEEF0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::GASPrototypeBase::GetConstructor(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::FunctionRef *result)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx

  result->Flags = 0;
  Function = this->Constructor.Function;
  result->Function = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  result->pLocalFrame = 0i64;
  pLocalFrame = this->Constructor.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(result, pLocalFrame, this->Constructor.Flags & 1);
  return result;
}

// File Line: 121
// RVA: 0x6C0250
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // r9
  unsigned __int64 Size; // r9
  unsigned __int64 i; // r8
  Scaleform::GFx::AS2::Object *pObject; // rax
  unsigned int v8; // ecx
  unsigned int v9; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Constructor,
    prcc);
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->__Constructor__,
    prcc);
  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Size = pInterfaces->Data.Size;
    for ( i = 0i64; i < Size; ++i )
    {
      pObject = this->pInterfaces->Data.Data[i].pObject;
      if ( pObject )
      {
        v8 = ++pObject->RefCount;
        if ( (v8 & 0x70000000) != 0 )
        {
          v9 = v8 & 0x8FFFFFFF;
          pObject->RefCount = v9;
          if ( (v9 & 0x8000000) != 0 )
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
  }
}

// File Line: 138
// RVA: 0x6E8920
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this,
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
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}

// File Line: 142
// RVA: 0x6E9500
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // rdx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pWatchpoints);
  }
}

// File Line: 185
// RVA: 0x6C66F0
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
  this->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  this->Constructor.Flags = 0;
  this->Constructor.Function = 0i64;
  this->Constructor.pLocalFrame = 0i64;
  this->__Constructor__.Flags = 0;
  this->__Constructor__.Function = 0i64;
  this->__Constructor__.pLocalFrame = 0i64;
  this->pInterfaces = 0i64;
  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::Init(&this->Scaleform::GFx::AS2::GASPrototypeBase, this, psc, constructor);
}

// File Line: 191
// RVA: 0x6C65A0
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc, pprototype);
  this->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  this->Constructor.Flags = 0;
  this->Constructor.Function = 0i64;
  this->Constructor.pLocalFrame = 0i64;
  this->__Constructor__.Flags = 0;
  this->__Constructor__.Function = 0i64;
  this->__Constructor__.pLocalFrame = 0i64;
  this->pInterfaces = 0i64;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
}

// File Line: 195
// RVA: 0x6D0530
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // rcx

  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 199
// RVA: 0x6EFE80
__int64 __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::GetMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
           this,
           &penv->StringContext,
           name,
           val);
}

// File Line: 205
// RVA: 0x6F3540
bool __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rdi
  Scaleform::GFx::ASStringNode *pNode; // r10
  bool v10; // zf
  bool isConstructor2; // bp
  Scaleform::GFx::ASMovieRootBase *v12; // rdi
  bool v13; // zf

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pNode = name->pNode;
    v10 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&pObject[23].AVMVersion + 16i64) == name->pNode->pLower;
  }
  else
  {
    pNode = name->pNode;
    v10 = *(Scaleform::GFx::ASStringNode **)&pObject[23].AVMVersion == name->pNode;
  }
  isConstructor2 = v10;
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 32),
             psc,
             name,
             val,
             isConstructor2);
  v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v13 = *(Scaleform::GFx::ASStringNode **)&v12[23].pASSupport.pObject->SType == name->pNode->pLower;
  }
  else
  {
    v13 = v12[23].pASSupport.pObject == (Scaleform::GFx::ASSupport *)pNode;
  }
  if ( v13 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 32),
             psc,
             name,
             val,
             isConstructor2);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}

// File Line: 218
// RVA: 0x6D8580
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
    psc,
    index,
    ctor);
}

// File Line: 222
// RVA: 0x6E2B90
bool __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::DoesImplement(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *prototype)
{
  return this == prototype
      || Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(
           &this->Scaleform::GFx::AS2::GASPrototypeBase,
           penv,
           prototype);
}

// File Line: 259
// RVA: 0x6D1570
void __fastcall Scaleform::GFx::AS2::FunctionProto::~FunctionProto(Scaleform::GFx::AS2::FunctionProto *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // rcx

  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 280
// RVA: 0x6C0DD0
void __fastcall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *pObject; // r8
  unsigned int v5; // eax
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *v7; // rdx
  unsigned int v8; // eax
  unsigned int v9; // eax

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  pObject = this->SuperProto.pObject;
  if ( pObject )
  {
    v5 = ++pObject->RefCount;
    if ( (v5 & 0x70000000) != 0 )
    {
      v6 = v5 & 0x8FFFFFFF;
      pObject->RefCount = v6;
      if ( (v6 & 0x8000000) != 0 )
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
  v7 = this->SavedProto.pObject;
  if ( v7 )
  {
    v8 = ++v7->RefCount;
    if ( (v8 & 0x70000000) != 0 )
    {
      v9 = v8 & 0x8FFFFFFF;
      v7->RefCount = v9;
      if ( (v9 & 0x8000000) != 0 )
      {
        v7->pPrev->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::pRCC = v7->pRCC;
        *(_QWORD *)v7->pRCC->Roots.gap0 = v7->pPrev;
        v7->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)prcc->pLastPtr->pRCC->Roots.gap0;
        v7->pRCC = prcc->pLastPtr->pRCC;
        *(_QWORD *)prcc->pLastPtr->pRCC->Roots.gap0 = v7;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v7;
      }
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Constructor,
    prcc);
}

// File Line: 289
// RVA: 0x6E8A00
void __fastcall Scaleform::GFx::AS2::SuperObject::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::SuperObject *this,
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
        Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          this,
          prcc);
    }
    else
    {
      Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        this,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      this,
      prcc);
  }
}

// File Line: 300
// RVA: 0x6CBD90
void __fastcall Scaleform::GFx::AS2::SuperObject::SuperObject(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Object *superProto,
        Scaleform::GFx::AS2::ObjectInterface *_this,
        Scaleform::GFx::AS2::FunctionRef *ctor)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS2::Object::Object(this, (Scaleform::GFx::AS2::ASRefCountCollector *)superProto->pRCC);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  superProto->RefCount = (superProto->RefCount + 1) & 0x8FFFFFFF;
  this->SuperProto.pObject = superProto;
  this->SavedProto.pObject = 0i64;
  this->RealThis = _this;
  this->Constructor.Flags = 0;
  Function = ctor->Function;
  this->Constructor.Function = ctor->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Constructor.pLocalFrame = 0i64;
  pLocalFrame = ctor->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->Constructor, pLocalFrame, ctor->Flags & 1);
  superProto->RefCount = (superProto->RefCount + 1) & 0x8FFFFFFF;
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
  this->pProto.pObject = superProto;
}

// File Line: 303
// RVA: 0x7187A0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[1].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val);
}

// File Line: 307
// RVA: 0x71A0E0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMemberRaw(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val);
}

// File Line: 311
// RVA: 0x6F29A0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::GetMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val);
}

// File Line: 315
// RVA: 0x6F40B0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::GetMemberRaw(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val);
}

// File Line: 319
// RVA: 0x6EB140
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::FindMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Member *pmember)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           pmember);
}

// File Line: 323
// RVA: 0x6E2250
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::DeleteMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[3].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name);
}

// File Line: 327
// RVA: 0x719A50
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMemberFlags(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        __int64 flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[3].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           flags);
}

// File Line: 331
// RVA: 0x724360
void __fastcall Scaleform::GFx::AS2::SuperObject::VisitMembers(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        __int64 visitFlags,
        Scaleform::GFx::AS2::ObjectInterface *instance)
{
  ((void (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[4].EntryCount)(
    &this->ResolveHandler.pLocalFrame->Variables,
    psc,
    pvisitor,
    visitFlags);
}

// File Line: 335
// RVA: 0x6FB640
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::HasMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        __int64 inclPrototypes)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[4].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           inclPrototypes);
}

// File Line: 351
// RVA: 0x6F89D0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::SuperObject::Get__constructor__(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionObject *v4; // rdx
  Scaleform::GFx::AS2::Object *pObject; // rdx

  result->Flags = 0;
  v4 = *(Scaleform::GFx::AS2::FunctionObject **)&this->ArePropertiesSet;
  result->Function = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
  result->pLocalFrame = 0i64;
  pObject = this->SuperProto.pObject;
  if ( pObject )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      result,
      (Scaleform::GFx::AS2::LocalFrame *)pObject,
      (__int64)this->SavedProto.pObject & 1);
  return result;
}

// File Line: 357
// RVA: 0x712F20
void __fastcall Scaleform::GFx::AS2::SuperObject::SetAltProto(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Object *altProto)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::Object *v5; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Object *v9; // rcx
  unsigned int v10; // eax

  pObject = this->SuperProto.pObject;
  if ( altProto != pObject )
  {
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v5 = this->SavedProto.pObject;
    if ( v5 )
    {
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    this->SavedProto.pObject = this->SuperProto.pObject;
    if ( altProto )
      altProto->RefCount = (altProto->RefCount + 1) & 0x8FFFFFFF;
    v7 = this->SuperProto.pObject;
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
    this->SuperProto.pObject = altProto;
    if ( altProto )
      altProto->RefCount = (altProto->RefCount + 1) & 0x8FFFFFFF;
    v9 = this->pProto.pObject;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
    this->pProto.pObject = this->SuperProto.pObject;
  }
}

// File Line: 365
// RVA: 0x710C40
void __fastcall Scaleform::GFx::AS2::SuperObject::ResetAltProto(Scaleform::GFx::AS2::SuperObject *this)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::Object *v3; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *v7; // rcx
  Scaleform::GFx::AS2::Object *v8; // rcx
  unsigned int v9; // eax

  pObject = this->SavedProto.pObject;
  if ( pObject )
  {
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v3 = this->SuperProto.pObject;
    if ( v3 )
    {
      RefCount = v3->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v3->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
    this->SuperProto.pObject = this->SavedProto.pObject;
    v5 = this->SavedProto.pObject;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    this->SavedProto.pObject = 0i64;
    v7 = this->SuperProto.pObject;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = this->pProto.pObject;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    this->pProto.pObject = this->SuperProto.pObject;
  }
}

