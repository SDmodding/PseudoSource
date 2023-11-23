// File Line: 91
// RVA: 0x7F0B20
Scaleform::GFx::AS3::Stage *__fastcall Scaleform::GFx::AS3::Stage::GetTopParent(
        Scaleform::GFx::AS3::Stage *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // r8

  pParent = this->pParent;
  if ( pParent )
    return (Scaleform::GFx::AS3::Stage *)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                           this->pParent,
                                           ignoreLockRoot);
  else
    return this;
}

// File Line: 117
// RVA: 0x77B190
void __fastcall Scaleform::GFx::AS3::AvmStage::AvmStage(
        Scaleform::GFx::AS3::AvmStage *this,
        Scaleform::GFx::DisplayObjContainer *pobj)
{
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(this, pobj);
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStage::`vftable;
}

// File Line: 128
// RVA: 0x7E77E0
const char *__fastcall Scaleform::GFx::AS3::AvmStage::GetDefaultASClassName(Scaleform::GFx::AS3::AvmStage *this)
{
  return "flash.display.Stage";
}

