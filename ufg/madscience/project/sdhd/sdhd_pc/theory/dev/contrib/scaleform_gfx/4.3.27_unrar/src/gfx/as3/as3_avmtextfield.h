// File Line: 67
// RVA: 0x7E7800
const char *__fastcall Scaleform::GFx::AS3::AvmTextField::GetDefaultASClassName(
        Scaleform::GFx::AS3::AvmTextField *this)
{
  return "flash.text.TextField";
}

// File Line: 77
// RVA: 0x803800
// attributes: thunk
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::EventId *id)
{
  return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
}

// File Line: 126
// RVA: 0x804A40
bool __fastcall Scaleform::GFx::AS3::AvmTextField::OnKeyEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::EventId *e,
        int *__formal)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *AppDomain; // rcx

  AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].AppDomain;
  if ( AppDomain || this[-1].pClassName )
  {
    if ( !AppDomain )
      AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pClassName;
    if ( ((unsigned __int8)AppDomain & 1) != 0 )
      AppDomain = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)AppDomain - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      AppDomain,
      e,
      *(Scaleform::GFx::DisplayObject **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
  }
  return 0;
}

// File Line: 139
// RVA: 0x7F8610
bool __fastcall Scaleform::GFx::AS3::AvmTextField::IsFocusEnabled(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  return fmt != GFx_FocusMovedByKeyboard
      || !Scaleform::GFx::TextField::IsReadOnly(*(Scaleform::GFx::TextField **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
}

