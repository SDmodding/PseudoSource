// File Line: 377
// RVA: 0x719A60
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMemberRaw(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rbx
  __int64 v9; // rax

  vfptr = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
  v9 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, Scaleform::GFx::AS2::ASStringContext *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(
         &this[-1].EventHandlers,
         psc);
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))vfptr->ToAvmButttonBase)(
           this,
           v9,
           name,
           val);
}

// File Line: 382
// RVA: 0x6F3870
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::GetMemberRaw(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rbx
  __int64 v8; // rax

  vfptr = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
  v8 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, Scaleform::GFx::AS2::ASStringContext *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(
         &this[-1].EventHandlers,
         psc);
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))vfptr->ToAvmTextFieldBase)(
           this,
           v8,
           name,
           val);
}

// File Line: 456
// RVA: 0x6EE700
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetBounds(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // rbx
  Scaleform::GFx::ResourceVtbl *vfptr; // rdi
  Scaleform::Render::Rect<float> *v7; // rax
  char v9[24]; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pDef.pObject;
  vfptr = pObject->vfptr;
  ((void (__fastcall *)(Scaleform::GFx::AS2::GenericDisplayObj *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[17].__vecDelDtor)(this);
  v7 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, char *))vfptr[1].GetResourceReport)(
                                           pObject,
                                           v9);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v7);
  return result;
}

// File Line: 460
// RVA: 0x6F5150
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetRectBounds(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // rbx
  Scaleform::GFx::ResourceVtbl *vfptr; // rdi
  Scaleform::Render::Rect<float> *v7; // rax
  char v9[24]; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pDef.pObject;
  vfptr = pObject->vfptr;
  ((void (__fastcall *)(Scaleform::GFx::AS2::GenericDisplayObj *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[17].__vecDelDtor)(this);
  v7 = (Scaleform::Render::Rect<float> *)vfptr[2].__vecDelDtor(pObject, (unsigned int)v9);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v7);
  return result;
}

