// File Line: 75
// RVA: 0x94B190
void __fastcall Scaleform::Render::StateData::Interface::~Interface(Scaleform::Render::StateData::Interface *this)
{
  this->vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface::`vftable';
}

// File Line: 115
// RVA: 0x9548C0
void __fastcall Scaleform::Render::StateData::Interface_RefCountImpl::AddRef(Scaleform::Render::StateData::Interface_RefCountImpl *this, void *data, Scaleform::Render::StateData::Interface::RefBehaviour __formal)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)data + 2, 1u);
}

// File Line: 119
// RVA: 0x9A7960
void __fastcall Scaleform::Render::StateData::Interface_RefCountImpl::Release(Scaleform::Render::StateData::Interface_RefCountImpl *this, void *data, Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != 2 && !_InterlockedDecrement((volatile signed __int32 *)data + 2) )
  {
    if ( data )
      (**(void (__fastcall ***)(void *, signed __int64))data)(data, 1i64);
  }
}

// File Line: 236
// RVA: 0x6D2590
void __fastcall Scaleform::Render::StateBag::~StateBag(Scaleform::Render::StateBag *this)
{
  JUMPOUT(this->ArraySize, 0i64, Scaleform::Render::StateData::destroyBag_NotEmpty);
}

