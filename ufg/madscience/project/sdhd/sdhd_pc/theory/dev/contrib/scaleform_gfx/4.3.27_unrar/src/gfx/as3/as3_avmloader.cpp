// File Line: 29
// RVA: 0x77AF80
void __fastcall Scaleform::GFx::AS3::AvmLoader::AvmLoader(Scaleform::GFx::AS3::AvmLoader *this, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::AS3::AvmLoader *v5; // rdi
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v6; // rbx
  Scaleform::GFx::AvmDisplayObjContainerBase *v7; // ST38_8

  v5 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
    (Scaleform::GFx::DisplayObjContainer *)&this->vfptr,
    pdefImpl,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  v6 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)&v5->vfptr;
  *(_QWORD *)&id.Id = (char *)v5 + 272;
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&v5->vfptr,
    (Scaleform::GFx::InteractiveObject *)&v5->vfptr);
  v7 = (Scaleform::GFx::AvmDisplayObjContainerBase *)&v5->vfptr;
  v7->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  v7->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  v7->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable;
  v6->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v5->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v7->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable;
  v5->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v5->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v6->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v5->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v5->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable;
}

// File Line: 33
// RVA: 0x789990
void __fastcall Scaleform::GFx::AS3::AvmLoader::~AvmLoader(Scaleform::GFx::AS3::AvmLoader *this)
{
  Scaleform::GFx::AS3::AvmLoader *v1; // rbx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v2 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)&this->vfptr;
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmLoader::`vftable;
  v1->AvmObjOffset = 0;
  Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer(v2);
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer((Scaleform::GFx::DisplayObjContainer *)&v1->vfptr);
}

