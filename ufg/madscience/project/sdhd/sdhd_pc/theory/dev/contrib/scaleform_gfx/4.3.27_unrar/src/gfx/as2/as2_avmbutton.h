// File Line: 68
// RVA: 0x705BC0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::OnEventLoad(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rax
  __int64 v2; // [rsp+20h] [rbp-28h] BYREF
  int v3; // [rsp+28h] [rbp-20h]
  char v4; // [rsp+2Ch] [rbp-1Ch]
  int v5; // [rsp+30h] [rbp-18h]

  v2 = 1i64;
  v3 = 0;
  v4 = 0;
  vfptr = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
  v5 = 65280;
  vfptr->OnEvent(this, (Scaleform::GFx::EventId *)&v2);
}

// File Line: 77
// RVA: 0x707230
char __fastcall Scaleform::GFx::AS2::AvmTextField::OnUnloading(Scaleform::GFx::AS2::AvmTextField *this, bool __formal)
{
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->pDispObj);
  return 1;
}

// File Line: 89
// RVA: 0x6EE490
// attributes: thunk
const char *__fastcall Scaleform::GFx::AS2::AvmSprite::GetAbsolutePath(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::String *ppath)
{
  return Scaleform::GFx::AS2::AvmCharacter::GetAbsolutePath(this, ppath);
}

// File Line: 94
// RVA: 0x6DF670
void __fastcall Scaleform::GFx::AS2::AvmCharacter::CloneInternalData(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v3; // rax
  char *v4; // rcx

  if ( poldChar )
  {
    v4 = (char *)poldChar + 4 * (unsigned __int8)poldChar->AvmObjOffset;
    v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 8i64))(v4);
  }
  else
  {
    v3 = 0i64;
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Assign(
    &this->EventHandlers.mHash,
    &this->EventHandlers,
    v3 + 4);
}

// File Line: 104
// RVA: 0x706340
// attributes: thunk
void __fastcall Scaleform::GFx::AS2::AvmButton::OnFocus(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        int controllerIdx)
{
  Scaleform::GFx::AS2::AvmCharacter::OnFocus(this, event, oldOrNewFocusCh, controllerIdx);
}

// File Line: 121
// RVA: 0x700890
bool __fastcall Scaleform::GFx::AS2::AvmButton::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  return fmt != GFx_FocusMovedByMouse;
}

// File Line: 127
// RVA: 0x700C90
// attributes: thunk
bool __fastcall Scaleform::GFx::AS2::AvmSprite::IsTabable(Scaleform::GFx::AS2::AvmSprite *this)
{
  return Scaleform::GFx::AS2::AvmCharacter::IsTabable(this);
}

// File Line: 173
// RVA: 0x6E9B40
void __fastcall Scaleform::GFx::AS2::ColorObject::Finalize_GC(Scaleform::GFx::AS2::MovieClipObject *this)
{
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // rcx

  pObject = this->pSprite.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->Members);
  pWatchpoints = this->pWatchpoints;
  if ( pWatchpoints )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pWatchpoints->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pWatchpoints);
  }
}

// File Line: 182
// RVA: 0x6C7AD0
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(
        Scaleform::GFx::AS2::ButtonObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pButton.pProxy.pObject = 0i64;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
}

// File Line: 189
// RVA: 0x6C7BE0
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(
        Scaleform::GFx::AS2::ButtonObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::InteractiveObject *pbutton)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  _QWORD *v6; // rbx
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // rdx
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  char *v9; // rcx
  Scaleform::GFx::AS2::ASStringContext *v10; // rdx
  Scaleform::GFx::AS2::Object *v11; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v14; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_pButton; // [rsp+88h] [rbp+10h] BYREF

  pMovieRoot = gCtxt->pMovieRoot;
  v6 = 0i64;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  p_pButton = &this->pButton;
  if ( pbutton )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pbutton);
  else
    WeakProxy = 0i64;
  this->pButton.pProxy.pObject = WeakProxy;
  if ( pbutton )
  {
    v9 = (char *)pbutton + 4 * (unsigned __int8)pbutton->AvmObjOffset;
    v6 = (_QWORD *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 8i64))(v9);
  }
  v10 = (Scaleform::GFx::AS2::ASStringContext *)((*(__int64 (__fastcall **)(_QWORD *))(*v6 + 240i64))(v6) + 232);
  v11 = (Scaleform::GFx::AS2::Object *)v6[2];
  if ( !this->pProto.pObject )
  {
    LOBYTE(p_pButton) = 3;
    v14.T.Type = 10;
    this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      v10,
      (Scaleform::GFx::ASString *)&v10->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
      &v14,
      (Scaleform::GFx::AS2::PropFlags *)&p_pButton);
    if ( v14.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v14);
  }
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
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
  this->pProto.pObject = v11;
}

// File Line: 197
// RVA: 0x6C7B50
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(
        Scaleform::GFx::AS2::ButtonObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pButton.pProxy.pObject = 0i64;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Button);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 204
// RVA: 0x6EE250
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::TextFieldObject::GetASCharacter(
        Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v4; // [rsp+48h] [rbp+10h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->pTextField,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    pObject = result.pObject;
  }
  v4 = pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  return pObject;
}

