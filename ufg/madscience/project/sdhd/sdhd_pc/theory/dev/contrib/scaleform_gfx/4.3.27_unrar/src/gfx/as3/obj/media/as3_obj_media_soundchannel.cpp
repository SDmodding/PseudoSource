// File Line: 38
// RVA: 0x158D1C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_0_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE30 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,0,double>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::leftPeakGet;
  return result;
}

// File Line: 39
// RVA: 0x158D100
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_1_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE40 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,1,double>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::positionGet;
  return result;
}

// File Line: 40
// RVA: 0x158D130
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_2_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE50 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,2,double>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::rightPeakGet;
  return result;
}

// File Line: 41
// RVA: 0x158D160
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_3_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_media::SoundTransform___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE60 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,3,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform>>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformGet;
  return result;
}

// File Line: 42
// RVA: 0x1592DA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_4_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_media::SoundTransform_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE70 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformSet;
  return result;
}

// File Line: 43
// RVA: 0x158D190
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_5_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EE80 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,5,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::stop;
  return result;
}

// File Line: 51
// RVA: 0x7820D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::SoundChannel(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  this->VMRef = t->pVM;
  this->pImpl.pObject = 0i64;
  this->pImpl.Owner = 1;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::`vftable;
}

// File Line: 57
// RVA: 0x8514A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::leftPeakGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::leftPeakGet() is not implemented\n");
}

// File Line: 64
// RVA: 0x857AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::positionGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::positionGet() is not implemented\n");
}

// File Line: 78
// RVA: 0x859D30
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::rightPeakGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        long double *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::rightPeakGet() is not implemented\n");
}

// File Line: 85
// RVA: 0x85F710
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformGet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::soundTransformGet() is not implemented\n");
}

// File Line: 106
// RVA: 0x85F7A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::soundTransformSet(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::soundTransformSet() is not implemented\n");
}

// File Line: 124
// RVA: 0x8600B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::stop(
        Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method SoundChannel::stop() is not implemented\n");
}

// File Line: 189
// RVA: 0x800060
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 211
// RVA: 0x766A40
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_media::SoundChannel::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_media::SoundChannelCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_media::SoundChannel::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_media::SoundChannelCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_media::SoundChannel::`vftable;
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

