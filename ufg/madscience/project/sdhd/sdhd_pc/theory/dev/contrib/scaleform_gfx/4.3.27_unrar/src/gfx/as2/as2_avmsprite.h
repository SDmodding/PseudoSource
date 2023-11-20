// File Line: 112
// RVA: 0x6EE300
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AvmSprite::GetASEnvironment(Scaleform::GFx::AS2::AvmSprite *this)
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
bool __usercall Scaleform::GFx::AS2::AvmSprite::GetMember@<al>(Scaleform::GFx::AS2::AvmSprite *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, Scaleform::GFx::ASString *name@<r8>, Scaleform::GFx::AS2::Value *pval@<r9>, long double a5@<xmm0>)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8),
           penv,
           0i64,
           name,
           a5);
}

// File Line: 177
// RVA: 0x6F38D0
bool __usercall Scaleform::GFx::AS2::AvmSprite::GetMemberRaw@<al>(Scaleform::GFx::AS2::AvmSprite *this@<rcx>, Scaleform::GFx::AS2::ASStringContext *psc@<rdx>, Scaleform::GFx::ASString *name@<r8>, Scaleform::GFx::AS2::Value *pval@<r9>, long double a5@<xmm0>)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 8),
           0i64,
           psc,
           name,
           a5);
}

// File Line: 383
// RVA: 0x6CA920
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::MovieClipObject *v5; // rsi

  v3 = pprototype;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->pSprite.pProxy.pObject = 0i64;
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__((Scaleform::GFx::AS2::MovieClipObject *)((char *)v5 + 32), v4, v3);
  v5->ButtonEventMask = 0;
  v5->HasButtonHandlers = 0;
}

// File Line: 389
// RVA: 0x6CA9A0
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v3; // r14
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->pSprite.pProxy.pObject = 0i64;
  v3->ButtonEventMask = 0;
  v3->HasButtonHandlers = 0;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(v2->StringContext.pContext, v2, ASBuiltin_MovieClip);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)v3 + 32),
    &v2->StringContext,
    v4);
}

// File Line: 399
// RVA: 0x6CAA30
void __fastcall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::GFx::AS2::GlobalContext *gCtxt, Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::Sprite *v3; // rdi
  Scaleform::GFx::AS2::MovieClipObject *v4; // rbx
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v6; // rdx
  Scaleform::WeakPtrProxy *v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rax

  v3 = psprite;
  v4 = this;
  v5 = gCtxt->pMovieRoot;
  if ( v5 )
    v6 = (Scaleform::GFx::AS2::ASRefCountCollector *)v5->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v6 = 0i64;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, v6);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  if ( v3 )
    v7 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v3->vfptr);
  else
    v7 = 0i64;
  v4->pSprite.pProxy.pObject = v7;
  v4->ButtonEventMask = 0;
  v4->HasButtonHandlers = 0;
  v8 = (signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset;
  v9 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v8 + 240i64))(v8);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)v4 + 32),
    (Scaleform::GFx::AS2::ASStringContext *)(v9 + 232),
    *(Scaleform::GFx::AS2::Object **)((char *)&v3->pWeakProxy + 4 * (unsigned __int8)v3->AvmObjOffset));
}

// File Line: 427
// RVA: 0x6F5480
Scaleform::Ptr<Scaleform::GFx::Sprite> *__fastcall Scaleform::GFx::AS2::MovieClipObject::GetSprite(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::Ptr<Scaleform::GFx::Sprite> *result)
{
  Scaleform::Ptr<Scaleform::GFx::Sprite> *v2; // rbx
  Scaleform::GFx::Sprite *v3; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  v2 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    &this->pSprite,
    &resulta);
  v3 = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    v3 = resulta.pObject;
  }
  v2->pObject = v3;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  return v2;
}

// File Line: 435
// RVA: 0x6E31E0
Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__fastcall Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(Scaleform::GFx::AS2::MovieClipObject *this, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *result, Scaleform::GFx::AS2::Object *newproto)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v4; // rsi
  Scaleform::GFx::AS2::MovieClipObject *v5; // rdi
  Scaleform::GFx::AS2::Object *v6; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v9; // rax

  v3 = newproto;
  v4 = result;
  v5 = this;
  v6 = this->pProto.pObject;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  result->pObject = (Scaleform::GFx::AS2::Object *)v5->pProto;
  if ( newproto )
    newproto->RefCount = (newproto->RefCount + 1) & 0x8FFFFFFF;
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->pProto.pObject->vfptr;
  if ( v7 && (v8 = v7->RefCount, v8 & 0x3FFFFFF) )
  {
    v7->RefCount = v8 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    v5->pProto.pObject = v3;
    v9 = v4;
  }
  else
  {
    v5->pProto.pObject = newproto;
    v9 = result;
  }
  return v9;
}

