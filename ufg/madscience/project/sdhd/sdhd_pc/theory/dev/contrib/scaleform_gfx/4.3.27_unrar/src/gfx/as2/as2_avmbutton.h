// File Line: 68
// RVA: 0x705BC0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::OnEventLoad(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v1; // rax
  __int64 v2; // [rsp+20h] [rbp-28h]
  int v3; // [rsp+28h] [rbp-20h]
  char v4; // [rsp+2Ch] [rbp-1Ch]
  int v5; // [rsp+30h] [rbp-18h]

  v2 = 1i64;
  v3 = 0;
  v4 = 0;
  v1 = this->vfptr;
  v5 = 65280;
  v1->OnEvent((Scaleform::GFx::AvmDisplayObjBase *)&this->vfptr, (Scaleform::GFx::EventId *)&v2);
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
const char *__fastcall Scaleform::GFx::AS2::AvmSprite::GetAbsolutePath(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::String *ppath)
{
  return Scaleform::GFx::AS2::AvmCharacter::GetAbsolutePath((Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr, ppath);
}

// File Line: 94
// RVA: 0x6DF670
void __fastcall Scaleform::GFx::AS2::AvmCharacter::CloneInternalData(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::GFx::AS2::AvmTextField *v2; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v3; // rax

  v2 = this;
  if ( poldChar )
    v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&poldChar->vfptr + 4 * (unsigned __int8)poldChar->AvmObjOffset))[1].__vecDelDtor)((char *)poldChar + 4 * (unsigned __int8)poldChar->AvmObjOffset);
  else
    v3 = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Assign(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&v2->EventHandlers.mHash.pTable,
    &v2->EventHandlers,
    v3 + 4);
}

// File Line: 104
// RVA: 0x706340
void __fastcall Scaleform::GFx::AS2::AvmButton::OnFocus(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::InteractiveObject::FocusEventType *event, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx)
{
  Scaleform::GFx::AS2::AvmCharacter::OnFocus(
    (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
    event,
    oldOrNewFocusCh,
    controllerIdx);
}

// File Line: 121
// RVA: 0x700890
bool __fastcall Scaleform::GFx::AS2::AvmButton::IsFocusEnabled(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::FocusMovedType fmt)
{
  return fmt != 1;
}

// File Line: 127
// RVA: 0x700C90
bool __fastcall Scaleform::GFx::AS2::AvmSprite::IsTabable(Scaleform::GFx::AS2::AvmSprite *this)
{
  return Scaleform::GFx::AS2::AvmCharacter::IsTabable((Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr);
}

// File Line: 173
// RVA: 0x6E9B40
void __fastcall Scaleform::GFx::AS2::ColorObject::Finalize_GC(Scaleform::GFx::AS2::MovieClipObject *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v1; // rbx
  Scaleform::WeakPtrProxy *v2; // rdx
  bool v3; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v4; // rcx

  v1 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this;
  v2 = this->pSprite.pProxy.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v1 + 6);
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v1[10].pTable;
  if ( v4 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v4);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1[10].pTable);
  }
}

// File Line: 182
// RVA: 0x6C7AD0
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(Scaleform::GFx::AS2::ButtonObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::ButtonObject *v5; // rsi

  v3 = pprototype;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->pButton.pProxy.pObject = 0i64;
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
}

// File Line: 189
// RVA: 0x6C7BE0
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(Scaleform::GFx::AS2::ButtonObject *this, Scaleform::GFx::AS2::GlobalContext *gCtxt, Scaleform::GFx::InteractiveObject *pbutton)
{
  Scaleform::GFx::InteractiveObject *v3; // rdi
  Scaleform::GFx::AS2::ButtonObject *v4; // rsi
  Scaleform::GFx::MovieImpl *v5; // rax
  _QWORD *v6; // rbx
  Scaleform::GFx::AS2::ASRefCountCollector *v7; // rdx
  Scaleform::WeakPtrProxy *v8; // rax
  __int64 v9; // rdx
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Value v13; // [rsp+38h] [rbp-40h]
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v14; // [rsp+88h] [rbp+10h]

  v3 = pbutton;
  v4 = this;
  v5 = gCtxt->pMovieRoot;
  v6 = 0i64;
  if ( v5 )
    v7 = (Scaleform::GFx::AS2::ASRefCountCollector *)v5->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v7 = 0i64;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, v7);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v14 = &v4->pButton;
  if ( v3 )
    v8 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v3->vfptr);
  else
    v8 = 0i64;
  v4->pButton.pProxy.pObject = v8;
  if ( v3 )
    v6 = (_QWORD *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                               + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)();
  v9 = (*(__int64 (__fastcall **)(_QWORD *))(*v6 + 240i64))(v6) + 232;
  v10 = (Scaleform::GFx::AS2::Object *)v6[2];
  if ( !v4->pProto.pObject )
  {
    LOBYTE(v14) = 3;
    v13.T.Type = 10;
    v4->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v9,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 936i64),
      &v13,
      (Scaleform::GFx::AS2::PropFlags *)&v14);
    if ( v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
  }
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pProto.pObject->vfptr;
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v4->pProto.pObject = v10;
}

// File Line: 197
// RVA: 0x6C7B50
void __fastcall Scaleform::GFx::AS2::ButtonObject::ButtonObject(Scaleform::GFx::AS2::ButtonObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ButtonObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->pButton.pProxy.pObject = 0i64;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_Button);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 204
// RVA: 0x6EE250
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::TextFieldObject::GetASCharacter(Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::Sprite *v1; // rbx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::Sprite *v4; // [rsp+48h] [rbp+10h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->pTextField,
    &result);
  v1 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v1 = result.pObject;
  }
  v4 = v1;
  if ( v1 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v1->vfptr);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  return v1;
}

