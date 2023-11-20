// File Line: 87
// RVA: 0x6EEEF0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::GASPrototypeBase::GetConstructor(Scaleform::GFx::AS2::GASPrototypeBase *this, Scaleform::GFx::AS2::FunctionRef *result)
{
  Scaleform::GFx::AS2::FunctionRef *v2; // rbx
  Scaleform::GFx::AS2::FunctionObject *v3; // rdx
  Scaleform::GFx::AS2::LocalFrame *v4; // rdx

  v2 = result;
  result->Flags = 0;
  v3 = this->Constructor.Function;
  v2->Function = v3;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  v2->pLocalFrame = 0i64;
  v4 = this->Constructor.pLocalFrame;
  if ( v4 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v2->Function,
      v4,
      this->Constructor.Flags & 1);
  return v2;
}

// File Line: 121
// RVA: 0x6C0250
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v2; // rdi
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *v3; // rbx
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v4; // r9
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Object *v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // ecx

  v2 = prcc;
  v3 = this;
  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::Object *)&this->vfptr,
    prcc);
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v3->Constructor.Function,
    v2);
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v3->__Constructor__.Function,
    v2);
  v4 = v3->pInterfaces;
  if ( v4 )
  {
    v5 = v4->Data.Size;
    v6 = 0i64;
    if ( v5 )
    {
      do
      {
        v7 = v3->pInterfaces->Data.Data[v6].pObject;
        if ( v7 )
        {
          v8 = ++v7->RefCount;
          if ( v8 & 0x70000000 )
          {
            v9 = v8 & 0x8FFFFFFF;
            v7->RefCount = v9;
            if ( (v9 >> 27) & 1 )
            {
              v7->pPrev->pRCC = v7->pRCC;
              *(_QWORD *)v7->pRCC->Roots.gap0 = v7->pPrev;
              v7->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v2->pLastPtr->pRCC->Roots.gap0;
              v7->pRCC = v2->pLastPtr->pRCC;
              *(_QWORD *)v2->pLastPtr->pRCC->Roots.gap0 = v7;
              v2->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v7;
            }
          }
        }
        ++v6;
      }
      while ( v6 < v5 );
    }
  }
}

// File Line: 138
// RVA: 0x6E8920
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::ExecuteForEachChild_GC(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

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
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v1; // rbx
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v2; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rcx

  v1 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this;
  v2 = this->pInterfaces;
  if ( v2 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2->Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[19].pTable);
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v1 + 6);
  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v1[10].pTable;
  if ( v3 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[10].pTable);
  }
}

// File Line: 185
// RVA: 0x6C66F0
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rbp
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *v7; // r14
  signed __int64 v8; // ST28_8

  v4 = constructor;
  v5 = pprototype;
  v6 = psc;
  v7 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v7->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::RectangleObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v7->vfptr, v6, v5);
  v8 = (signed __int64)&v7->vfptr;
  *(_QWORD *)v8 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  *(_BYTE *)(v8 + 24) = 0;
  *(_QWORD *)(v8 + 8) = 0i64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v7->__Constructor__.Flags = 0;
  v7->__Constructor__.Function = 0i64;
  v7->__Constructor__.pLocalFrame = 0i64;
  v7->pInterfaces = 0i64;
  v7->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  *(_QWORD *)v8 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::Init(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v7->vfptr,
    (Scaleform::GFx::AS2::Object *)&v7->vfptr,
    v6,
    v4);
}

// File Line: 191
// RVA: 0x6C65A0
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *v3; // rbx
  signed __int64 v4; // [rsp+58h] [rbp+20h]

  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc, pprototype);
  v4 = (signed __int64)&v3->vfptr;
  *(_QWORD *)v4 = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
  *(_BYTE *)(v4 + 24) = 0;
  *(_QWORD *)(v4 + 8) = 0i64;
  *(_QWORD *)(v4 + 16) = 0i64;
  v3->__Constructor__.Flags = 0;
  v3->__Constructor__.Function = 0i64;
  v3->__Constructor__.pLocalFrame = 0i64;
  v3->pInterfaces = 0i64;
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  *(_QWORD *)v4 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
}

// File Line: 195
// RVA: 0x6D0530
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment> *v1; // rbx
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = (Scaleform::GFx::AS2::GASPrototypeBase *)&this->vfptr;
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&v1->vfptr);
}

// File Line: 199
// RVA: 0x6EFE80
__int64 __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::GetMember(Scaleform::GFx::AS2::Object *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->vfptr[3].~RefCountBaseGC<323>)(
           this,
           &penv->StringContext,
           name,
           val);
}

// File Line: 205
// RVA: 0x6F3540
bool __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  Scaleform::GFx::ASMovieRootBase *v7; // rdi
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // r10
  bool v10; // zf
  bool isConstructor2; // bp
  Scaleform::GFx::ASMovieRootBase *v12; // rdi
  bool v13; // zf
  bool result; // al

  v4 = val;
  v5 = name;
  v6 = psc;
  v7 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  v8 = this;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = v5->pNode;
    v10 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v7[23].AVMVersion + 16i64) == v5->pNode->pLower;
  }
  else
  {
    v9 = name->pNode;
    v10 = *(Scaleform::GFx::ASStringNode **)&v7[23].AVMVersion == name->pNode;
  }
  isConstructor2 = v10;
  if ( v10 )
    goto LABEL_17;
  v12 = v6->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v6->SWFVersion <= 6u )
  {
    if ( !v9->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v9);
    v13 = *(Scaleform::GFx::ASStringNode **)&v12[23].pASSupport.pObject->SType == v5->pNode->pLower;
  }
  else
  {
    v13 = v12[23].pASSupport.pObject == (Scaleform::GFx::ASSupport *)v9;
  }
  if ( v13 )
LABEL_17:
    result = Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
               (Scaleform::GFx::AS2::GASPrototypeBase *)&v8->pWatchpoints,
               (Scaleform::GFx::AS2::Object *)&v8[-1].__Constructor__,
               v6,
               v5,
               v4,
               isConstructor2);
  else
    result = Scaleform::GFx::AS2::Object::GetMemberRaw((Scaleform::GFx::AS2::Object *)&v8->vfptr, v6, v5, v4);
  return result;
}

// File Line: 218
// RVA: 0x6D8580
void __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorObject,Scaleform::GFx::AS2::Environment>::AddInterface(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::ASStringContext *psc, int index, Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
    psc,
    index,
    ctor);
}

// File Line: 222
// RVA: 0x6E2B90
bool __fastcall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::DoesImplement(Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *prototype)
{
  bool result; // al

  if ( this == (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment> *)prototype )
    result = 1;
  else
    result = Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(
               (Scaleform::GFx::AS2::GASPrototypeBase *)&this->vfptr,
               penv,
               prototype);
  return result;
}

// File Line: 259
// RVA: 0x6D1570
void __fastcall Scaleform::GFx::AS2::FunctionProto::~FunctionProto(Scaleform::GFx::AS2::FunctionProto *this)
{
  Scaleform::GFx::AS2::FunctionProto *v1; // rbx
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2 = (Scaleform::GFx::AS2::GASPrototypeBase *)&this->vfptr;
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::FunctionProto::`vftable;
  v1->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v1->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v2->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable;
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&v1->vfptr);
}

// File Line: 280
// RVA: 0x6C0DD0
void __fastcall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v2; // rbx
  Scaleform::GFx::AS2::SuperObject *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // r8
  unsigned int v5; // eax
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *v7; // rdx
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = prcc;
  v3 = this;
  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::Object *)&this->vfptr,
    prcc);
  v4 = v3->SuperProto.pObject;
  if ( v4 )
  {
    v5 = ++v4->RefCount;
    if ( v5 & 0x70000000 )
    {
      v6 = v5 & 0x8FFFFFFF;
      v4->RefCount = v6;
      if ( (v6 >> 27) & 1 )
      {
        v4->pPrev->pRCC = v4->pRCC;
        *(_QWORD *)v4->pRCC->Roots.gap0 = v4->pPrev;
        v4->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v2->pLastPtr->pRCC->Roots.gap0;
        v4->pRCC = v2->pLastPtr->pRCC;
        *(_QWORD *)v2->pLastPtr->pRCC->Roots.gap0 = v4;
        v2->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4;
      }
    }
  }
  v7 = v3->SavedProto.pObject;
  if ( v7 )
  {
    v8 = ++v7->RefCount;
    if ( v8 & 0x70000000 )
    {
      v9 = v8 & 0x8FFFFFFF;
      v7->RefCount = v9;
      if ( (v9 >> 27) & 1 )
      {
        v7->pPrev->pRCC = v7->pRCC;
        *(_QWORD *)v7->pRCC->Roots.gap0 = v7->pPrev;
        v7->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v2->pLastPtr->pRCC->Roots.gap0;
        v7->pRCC = v2->pLastPtr->pRCC;
        *(_QWORD *)v2->pLastPtr->pRCC->Roots.gap0 = v7;
        v2->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v7;
      }
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v3->Constructor.Function,
    v2);
}

// File Line: 289
// RVA: 0x6E8A00
void __fastcall Scaleform::GFx::AS2::SuperObject::ExecuteForEachChild_GC(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  __int32 v3; // er8

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
void __fastcall Scaleform::GFx::AS2::SuperObject::SuperObject(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::Object *superProto, Scaleform::GFx::AS2::ObjectInterface *_this, Scaleform::GFx::AS2::FunctionRef *ctor)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // r14
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::Object *v6; // rsi
  Scaleform::GFx::AS2::SuperObject *v7; // rdi
  Scaleform::GFx::AS2::FunctionRefBase *v8; // rcx
  Scaleform::GFx::AS2::FunctionObject *v9; // rdx
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax

  v4 = ctor;
  v5 = _this;
  v6 = superProto;
  v7 = this;
  Scaleform::GFx::AS2::Object::Object(
    (Scaleform::GFx::AS2::Object *)&this->vfptr,
    (Scaleform::GFx::AS2::ASRefCountCollector *)superProto->pRCC);
  v7->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v7->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  v7->SuperProto.pObject = v6;
  v7->SavedProto.pObject = 0i64;
  v7->RealThis = v5;
  v8 = (Scaleform::GFx::AS2::FunctionRefBase *)&v7->Constructor.Function;
  v8->Flags = 0;
  v9 = v4->Function;
  v8->Function = v4->Function;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  v7->Constructor.pLocalFrame = 0i64;
  v10 = v4->pLocalFrame;
  if ( v10 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v8, v10, v4->Flags & 1);
  v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->pProto.pObject->vfptr;
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v7->pProto.pObject = v6;
}

// File Line: 303
// RVA: 0x7187A0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMember(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[1].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val);
}

// File Line: 307
// RVA: 0x71A0E0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMemberRaw(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val);
}

// File Line: 311
// RVA: 0x6F29A0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::GetMember(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val);
}

// File Line: 315
// RVA: 0x6F40B0
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::GetMemberRaw(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val);
}

// File Line: 319
// RVA: 0x6EB140
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::FindMember(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Member *pmember)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           pmember);
}

// File Line: 323
// RVA: 0x6E2250
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::DeleteMember(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[3].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name);
}

// File Line: 327
// RVA: 0x719A50
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::SetMemberFlags(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, __int64 flags)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[3].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           flags);
}

// File Line: 331
// RVA: 0x724360
void __fastcall Scaleform::GFx::AS2::SuperObject::VisitMembers(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor, __int64 visitFlags, Scaleform::GFx::AS2::ObjectInterface *instance)
{
  ((void (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[4].EntryCount)(
    &this->ResolveHandler.pLocalFrame->Variables,
    psc,
    pvisitor,
    visitFlags);
}

// File Line: 335
// RVA: 0x6FB640
__int64 __fastcall Scaleform::GFx::AS2::SuperObject::HasMember(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, __int64 inclPrototypes)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, __int64))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[4].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           inclPrototypes);
}

// File Line: 351
// RVA: 0x6F89D0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::SuperObject::Get__constructor__(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // rbx
  Scaleform::GFx::AS2::FunctionObject *v4; // rdx
  Scaleform::GFx::AS2::Object *v5; // rdx

  v3 = result;
  result->Flags = 0;
  v4 = *(Scaleform::GFx::AS2::FunctionObject **)&this->ArePropertiesSet;
  v3->Function = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
  v3->pLocalFrame = 0i64;
  v5 = this->SuperProto.pObject;
  if ( v5 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v3->Function,
      (Scaleform::GFx::AS2::LocalFrame *)v5,
      (_QWORD)this->SavedProto.pObject & 1);
  return v3;
}

// File Line: 357
// RVA: 0x712F20
void __fastcall Scaleform::GFx::AS2::SuperObject::SetAltProto(Scaleform::GFx::AS2::SuperObject *this, Scaleform::GFx::AS2::Object *altProto)
{
  Scaleform::GFx::AS2::SuperObject *v2; // rbx
  Scaleform::GFx::AS2::Object *v3; // rcx
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax

  v2 = this;
  v3 = this->SuperProto.pObject;
  v4 = altProto;
  if ( altProto != v3 )
  {
    if ( v3 )
      v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->SavedProto.pObject->vfptr;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( v6 & 0x3FFFFFF )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v2->SavedProto.pObject = v2->SuperProto.pObject;
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
    v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->SuperProto.pObject->vfptr;
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
    v2->SuperProto.pObject = v4;
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pProto.pObject->vfptr;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
    v2->pProto.pObject = v2->SuperProto.pObject;
  }
}

// File Line: 365
// RVA: 0x710C40
void __fastcall Scaleform::GFx::AS2::SuperObject::ResetAltProto(Scaleform::GFx::AS2::SuperObject *this)
{
  Scaleform::GFx::AS2::SuperObject *v1; // rbx
  Scaleform::GFx::AS2::Object *v2; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *v7; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax

  v1 = this;
  v2 = this->SavedProto.pObject;
  if ( v2 )
  {
    v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
    v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->SuperProto.pObject->vfptr;
    if ( v3 )
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
    v1->SuperProto.pObject = v1->SavedProto.pObject;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->SavedProto.pObject->vfptr;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( v6 & 0x3FFFFFF )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v1->SavedProto.pObject = 0i64;
    v7 = v1->SuperProto.pObject;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->pProto.pObject->vfptr;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    v1->pProto.pObject = v1->SuperProto.pObject;
  }
}

