// File Line: 33
// RVA: 0x1589F50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::FrameLabel_0_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243BE60 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,0,long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *, int *))Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet;
  return result;
}

// File Line: 34
// RVA: 0x1589F20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::FrameLabel_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243BE70 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel,1,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::nameGet;
  return result;
}

// File Line: 50
// RVA: 0x851610
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        unsigned int *result)
{
  *result = this->SA.Length;
}

// File Line: 57
// RVA: 0x854F20
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::nameGet(
        Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = this->FrameName.pNode;
  ++pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    result->pNode = pNode;
  }
  else
  {
    result->pNode = pNode;
  }
}

// File Line: 92
// RVA: 0x7FF610
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::FrameLabel> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 114
// RVA: 0x748030
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::FrameLabel::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::FrameLabelCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::FrameLabel::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::FrameLabelCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel::`vftable;
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

