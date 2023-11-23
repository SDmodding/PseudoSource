// File Line: 217
// RVA: 0x1598470
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9B8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::styleNamesGet;
  return result;
}

// File Line: 218
// RVA: 0x1598440
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_1_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9C8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,1,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::clear;
  return result;
}

// File Line: 219
// RVA: 0x1599FD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9D8 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::getStyle;
  return result;
}

// File Line: 220
// RVA: 0x159A000
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9E8 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::parseCSS;
  return result;
}

// File Line: 221
// RVA: 0x159B110
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_4_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9F8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::setStyle;
  return result;
}

// File Line: 222
// RVA: 0x159A030
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_text::StyleSheet_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_text::TextFormat__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243FA08 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::transform;
  return result;
}

// File Line: 236
// RVA: 0x926BF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::styleNamesGet(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(
    UI,
    Output_Warning,
    "The method StyleSheet::styleNamesGet() is not supported because core dependencies have been removed\n");
}

// File Line: 267
// RVA: 0x91E220
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::clear(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(
    UI,
    Output_Warning,
    "The method StyleSheet::clear() is not supported because core dependencies have been removed\n");
}

// File Line: 287
// RVA: 0x920870
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::getStyle(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result,
        Scaleform::GFx::ASString *styleName)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(
    UI,
    Output_Warning,
    "The method StyleSheet::getStyle() is not supported because core dependencies have been removed\n");
}

// File Line: 455
// RVA: 0x921B10
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::parseCSS(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *CSSText)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(
    UI,
    Output_Warning,
    "The method StyleSheet::parseCSS() is not supported because core dependencies have been removed\n");
}

// File Line: 487
// RVA: 0x9267E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::setStyle(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *styleName,
        Scaleform::GFx::AS3::Value *styleObject)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  ((void (__fastcall *)(Scaleform::GFx::AS3::FlashUI *, __int64, const char *, Scaleform::GFx::AS3::Value *))UI->vfptr->Output)(
    UI,
    2i64,
    "The method StyleSheet::setStyle() is not supported because core dependencies have been removed\n",
    styleObject);
}

// File Line: 541
// RVA: 0x9273D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::transform(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result,
        Scaleform::GFx::AS3::Value *formatObject)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(
    UI,
    Output_Warning,
    "The method StyleSheet::transform() is not supported because core dependencies have been removed\n");
}

// File Line: 623
// RVA: 0x8EAFD0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 645
// RVA: 0x86D610
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_text::StyleSheet::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
      v5,
      vm,
      &Scaleform::GFx::AS3::fl_text::StyleSheetCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_text::StyleSheet::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_text::StyleSheetCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

