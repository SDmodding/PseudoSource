// File Line: 75
// RVA: 0x94B190
void __fastcall Scaleform::Render::StateData::Interface::~Interface(Scaleform::Render::StateData::Interface *this)
{
  this->vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface::`vftable;
}

// File Line: 115
// RVA: 0x9548C0
void __fastcall Scaleform::Render::StateData::Interface_RefCountImpl::AddRef(
        Scaleform::Render::StateData::Interface_RefCountImpl *this,
        volatile signed __int32 *data,
        Scaleform::Render::StateData::Interface::RefBehaviour __formal)
{
  _InterlockedExchangeAdd(data + 2, 1u);
}

// File Line: 119
// RVA: 0x9A7960
void __fastcall Scaleform::Render::StateData::Interface_RefCountImpl::Release(
        Scaleform::Render::StateData::Interface_RefCountImpl *this,
        volatile signed __int32 *data,
        Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != Ref_ReleaseTreeNodeOnly && !_InterlockedDecrement(data + 2) )
  {
    if ( data )
      (**(void (__fastcall ***)(volatile signed __int32 *, __int64))data)(data, 1i64);
  }
}

// File Line: 236
// RVA: 0x6D2590
void __fastcall Scaleform::Render::StateBag::~StateBag(Scaleform::Render::StateBag *this)
{
  if ( this->ArraySize )
    Scaleform::Render::StateData::destroyBag_NotEmpty(this);
}

