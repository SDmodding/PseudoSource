// File Line: 59
// RVA: 0x6C7FC0
void __fastcall Scaleform::GFx::AS2::ColorObject::ColorObject(Scaleform::GFx::AS2::ColorObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::AS2::ColorObject *v5; // rdi
  Scaleform::WeakPtrProxy *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax

  v3 = pcharacter;
  v4 = penv;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  if ( v3 )
    v6 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v3->vfptr);
  else
    v6 = 0i64;
  v5->pCharacter.pProxy.pObject = v6;
  v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->StringContext.pContext, ASBuiltin_Color);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, &v4->StringContext, v7);
}

// File Line: 62
// RVA: 0x71C430
void __fastcall Scaleform::GFx::AS2::ColorObject::SetTarget(Scaleform::GFx::AS2::ColorObject *this, Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::GFx::AS2::ColorObject *v2; // rbx
  Scaleform::WeakPtrProxy *v3; // rax
  Scaleform::WeakPtrProxy *v4; // rdx
  Scaleform::WeakPtrProxy *v5; // rdi
  bool v6; // zf
  Scaleform::WeakPtrProxy *v7; // rdx

  v2 = this;
  if ( pcharacter )
  {
    v3 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&pcharacter->vfptr);
    v4 = v2->pCharacter.pProxy.pObject;
    v5 = v3;
    if ( v4 )
    {
      v6 = v4->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v2->pCharacter.pProxy.pObject = v5;
  }
  else
  {
    v7 = this->pCharacter.pProxy.pObject;
    if ( v7 )
    {
      v6 = v7->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v2->pCharacter.pProxy.pObject = 0i64;
  }
}

