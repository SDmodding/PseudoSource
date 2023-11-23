// File Line: 40
// RVA: 0x825BC0
Scaleform::GFx::AvmInteractiveObjBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::ToAvmInteractiveObjBase(
        Scaleform::GFx::AS3::AvmTextField *this)
{
  if ( this )
    return &this->Scaleform::GFx::AvmInteractiveObjBase;
  else
    return 0i64;
}

// File Line: 44
// RVA: 0x825B80
Scaleform::GFx::AvmTextFieldBase *__fastcall Scaleform::GFx::AS3::AvmButton::ToAvmButttonBase(
        Scaleform::GFx::AS3::AvmTextField *this)
{
  if ( this )
    return &this->Scaleform::GFx::AvmTextFieldBase;
  else
    return 0i64;
}

// File Line: 48
// RVA: 0x803150
// attributes: thunk
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEvent(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::EventId *id)
{
  return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(this, id);
}

// File Line: 52
// RVA: 0x803820
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventLoad(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rdx

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
  this->pAS3RawPtr = 0i64;
}

// File Line: 56
// RVA: 0x804160
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::AvmButton::OnEventUnload(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload(this);
}

// File Line: 71
// RVA: 0x7E5B10
// attributes: thunk
const char *__fastcall Scaleform::GFx::AS3::AvmSprite::GetAbsolutePath(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::String *ppath)
{
  return Scaleform::GFx::AS3::AvmDisplayObj::GetAbsolutePath(this, ppath);
}

// File Line: 86
// RVA: 0x804610
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnFocus(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::AS3::AvmInteractiveObj::OnFocus(this, event, oldOrNewFocusCh, controllerIdx, fmt);
}

// File Line: 103
// RVA: 0x7F9340
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::IsTabable(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  int v2; // eax
  __int64 v3; // rcx

  LOBYTE(v2) = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                                                 + 472i64))(*(_QWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
  if ( (_BYTE)v2 )
  {
    v3 = *(_QWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags;
    if ( (*(_DWORD *)(v3 + 184) & 0x60) != 0 )
      LOBYTE(v2) = (*(_DWORD *)(v3 + 184) & 0x60) == 96;
    else
      return *(_WORD *)(v3 + 188) > 0;
  }
  return v2;
}

// File Line: 111
// RVA: 0x7E7770
const char *__fastcall Scaleform::GFx::AS3::AvmButton::GetDefaultASClassName(Scaleform::GFx::AS3::AvmButton *this)
{
  return "flash.display.SimpleButton";
}

