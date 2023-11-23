// File Line: 59
// RVA: 0x6C7FC0
void __fastcall Scaleform::GFx::AS2::ColorObject::ColorObject(
        Scaleform::GFx::AS2::ColorObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  if ( pcharacter )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pcharacter);
  else
    WeakProxy = 0i64;
  this->pCharacter.pProxy.pObject = WeakProxy;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Color);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 62
// RVA: 0x71C430
void __fastcall Scaleform::GFx::AS2::ColorObject::SetTarget(
        Scaleform::GFx::AS2::ColorObject *this,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::WeakPtrProxy *v5; // rdi
  bool v6; // zf
  Scaleform::WeakPtrProxy *v7; // rdx

  if ( pcharacter )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pcharacter);
    pObject = this->pCharacter.pProxy.pObject;
    v5 = WeakProxy;
    if ( pObject )
    {
      v6 = pObject->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    this->pCharacter.pProxy.pObject = v5;
  }
  else
  {
    v7 = this->pCharacter.pProxy.pObject;
    if ( v7 )
    {
      v6 = v7->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    this->pCharacter.pProxy.pObject = 0i64;
  }
}

