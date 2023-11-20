// File Line: 40
// RVA: 0x825BC0
Scaleform::GFx::AvmInteractiveObjBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::ToAvmInteractiveObjBase(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AvmInteractiveObjBase *result; // rax

  if ( this )
    result = (Scaleform::GFx::AvmInteractiveObjBase *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 44
// RVA: 0x825B80
Scaleform::GFx::AvmTextFieldBase *__fastcall Scaleform::GFx::AS3::AvmButton::ToAvmButttonBase(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AvmTextFieldBase *result; // rax

  if ( this )
    result = (Scaleform::GFx::AvmTextFieldBase *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 48
// RVA: 0x803150
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEvent(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::EventId *id)
{
  return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent((Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr, id);
}

// File Line: 52
// RVA: 0x803820
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventLoad(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v1; // rdx
  Scaleform::GFx::AS3::AvmSprite *v2; // rbx

  v1 = this->pAS3RawPtr;
  v2 = this;
  if ( !v1 )
    v1 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v1 & 1 )
    v1 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v1 - 1);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v1);
  v2->pAS3RawPtr = 0i64;
}

// File Line: 56
// RVA: 0x804160
void __fastcall Scaleform::GFx::AS3::AvmButton::OnEventUnload(Scaleform::GFx::AS3::AvmTextField *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr);
}

// File Line: 71
// RVA: 0x7E5B10
const char *__fastcall Scaleform::GFx::AS3::AvmSprite::GetAbsolutePath(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::String *ppath)
{
  return Scaleform::GFx::AS3::AvmDisplayObj::GetAbsolutePath((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr, ppath);
}

// File Line: 86
// RVA: 0x804610
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnFocus(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::InteractiveObject::FocusEventType *event, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::AS3::AvmInteractiveObj::OnFocus(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr,
    event,
    oldOrNewFocusCh,
    controllerIdx,
    fmt);
}

// File Line: 103
// RVA: 0x7F9340
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::IsTabable(Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v1; // rbx
  BOOL v2; // eax
  __int64 v3; // rcx

  v1 = this;
  LOBYTE(v2) = (*(__int64 (**)(void))(**(_QWORD **)&this[-1].Flags + 472i64))();
  if ( (_BYTE)v2 )
  {
    v3 = *(_QWORD *)&v1[-1].Flags;
    if ( *(_DWORD *)(v3 + 184) & 0x60 )
      LOBYTE(v2) = (*(_DWORD *)(v3 + 184) & 0x60) == 96;
    else
      v2 = *(_WORD *)(v3 + 188) > 0;
  }
  return v2;
}

// File Line: 111
// RVA: 0x7E7770
const char *__fastcall Scaleform::GFx::AS3::AvmButton::GetDefaultASClassName(Scaleform::GFx::AS3::AvmButton *this)
{
  return "flash.display.SimpleButton";
}

