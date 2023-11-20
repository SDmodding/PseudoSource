// File Line: 67
// RVA: 0x7E7800
const char *__fastcall Scaleform::GFx::AS3::AvmTextField::GetDefaultASClassName(Scaleform::GFx::AS3::AvmTextField *this)
{
  return "flash.text.TextField";
}

// File Line: 77
// RVA: 0x803800
char __fastcall Scaleform::GFx::AS3::AvmTextField::OnEvent(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::EventId *id)
{
  return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr, id);
}

// File Line: 126
// RVA: 0x804A40
bool __fastcall Scaleform::GFx::AS3::AvmTextField::OnKeyEvent(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::EventId *e, int *__formal)
{
  Scaleform::GFx::AS3::AvmTextField *v3; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rcx

  v3 = this;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].AppDomain;
  if ( v4 || v3[-1].pClassName )
  {
    if ( !v4 )
      v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v3[-1].pClassName;
    if ( (unsigned __int8)v4 & 1 )
      v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v4 - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      v4,
      e,
      *(Scaleform::GFx::DisplayObject **)&v3[-1].Flags);
  }
  return 0;
}

// File Line: 139
// RVA: 0x7F8610
bool __fastcall Scaleform::GFx::AS3::AvmTextField::IsFocusEnabled(Scaleform::GFx::AS3::AvmTextField *this, Scaleform::GFx::FocusMovedType fmt)
{
  bool result; // al

  if ( fmt == 2 )
    result = Scaleform::GFx::TextField::IsReadOnly(*(Scaleform::GFx::TextField **)&this[-1].Flags) == 0;
  else
    result = 1;
  return result;
}

