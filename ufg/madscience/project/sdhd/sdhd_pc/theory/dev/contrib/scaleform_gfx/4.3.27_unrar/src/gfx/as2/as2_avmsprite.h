// File Line: 112
// RVA: 0x6EE300
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AvmSprite::GetASEnvironment(
        Scaleform::GFx::AS2::AvmSprite *this)
{
  return &this->ASEnvironment;
}

// File Line: 133
// RVA: 0x6EFCA0
__int64 __fastcall Scaleform::GFx::AS2::AvmSprite::GetLevel(Scaleform::GFx::AS2::AvmSprite *this)
{
  return *((unsigned int *)&this->ASEnvironment.ThrowingValue.NV + 6);
}

// File Line: 169
// RVA: 0x6F0830
bool __fastcall Scaleform::GFx::AS2::AvmSprite::GetMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8),
           penv,
           0i64,
           name);
}

// File Line: 177
// RVA: 0x6F38D0
bool __fastcall Scaleform::GFx::AS2::AvmSprite::GetMemberRaw(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8),
           0i64,
           psc,
           name);
}

// File Line: 383
// RVA: 0x6CA920
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pSprite.pProxy.pObject = 0i64;
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
}

// File Line: 389
// RVA: 0x6CA9A0
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *ActualPrototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pSprite.pProxy.pObject = 0i64;
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      penv->StringContext.pContext,
                      penv,
                      ASBuiltin_MovieClip);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    ActualPrototype);
}

// File Line: 399
// RVA: 0x6CAA30
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // rdx
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  char *v8; // rcx
  __int64 v9; // rax

  pMovieRoot = gCtxt->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  if ( psprite )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(psprite);
  else
    WeakProxy = 0i64;
  this->pSprite.pProxy.pObject = WeakProxy;
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
  v8 = (char *)psprite + 4 * (unsigned __int8)psprite->AvmObjOffset;
  v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 240i64))(v8);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)(v9 + 232),
    *(Scaleform::GFx::AS2::Object **)((char *)&psprite->pWeakProxy + 4 * (unsigned __int8)psprite->AvmObjOffset));
}

// File Line: 427
// RVA: 0x6F5480
Scaleform::Ptr<Scaleform::GFx::Sprite> *__fastcall Scaleform::GFx::AS2::MovieClipObject::GetSprite(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> *result)
{
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    &this->pSprite,
    &resulta);
  pObject = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    pObject = resulta.pObject;
  }
  result->pObject = pObject;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
  return result;
}

// File Line: 435
// RVA: 0x6E31E0
Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__fastcall Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::Ptr<Scaleform::GFx::AS2::Object> *result,
        Scaleform::GFx::AS2::Object *newproto)
{
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::Object *v7; // rcx
  unsigned int RefCount; // eax

  pObject = this->pProto.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  result->pObject = (Scaleform::GFx::AS2::Object *)this->pProto;
  if ( newproto )
    newproto->RefCount = (newproto->RefCount + 1) & 0x8FFFFFFF;
  v7 = this->pProto.pObject;
  if ( v7 && (RefCount = v7->RefCount, (RefCount & 0x3FFFFFF) != 0) )
  {
    v7->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    this->pProto.pObject = newproto;
    return result;
  }
  else
  {
    this->pProto.pObject = newproto;
    return result;
  }
}

