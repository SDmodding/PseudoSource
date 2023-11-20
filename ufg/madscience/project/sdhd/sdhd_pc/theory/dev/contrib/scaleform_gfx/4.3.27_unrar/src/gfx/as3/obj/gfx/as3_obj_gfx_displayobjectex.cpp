// File Line: 40
// RVA: 0x8349C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::disableBatching(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o, bool b)
{
  if ( o )
    Scaleform::GFx::DisplayObjectBase::DisableBatching(
      (Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr,
      b);
}

// File Line: 51
// RVA: 0x8509A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::isBatchingDisabled(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, bool *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  if ( o )
    *result = Scaleform::GFx::DisplayObjectBase::IsBatchingDisabled((Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr);
}

// File Line: 62
// RVA: 0x85E850
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererString(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o, Scaleform::GFx::ASString *s)
{
  if ( o )
    Scaleform::GFx::DisplayObjectBase::SetRendererString(
      (Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr,
      s->pNode->pData);
}

// File Line: 73
// RVA: 0x84CC70
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererString(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *v4; // rdi
  const char *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+18h]

  if ( o )
  {
    v3 = result;
    v4 = this;
    v5 = Scaleform::GFx::DisplayObjectBase::GetRendererString((Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr);
    if ( v5 )
    {
      Scaleform::GFx::ASString::operator=(v3, v5);
    }
    else
    {
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
             (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->pTraits.pObject->pVM->StringManagerRef->Builtins,
             &resulta)->pNode;
      ++v6->RefCount;
      v7 = v3->pNode;
      v8 = v3->pNode->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      v3->pNode = v6;
      v9 = resulta.pNode;
      v8 = resulta.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
  }
}

// File Line: 88
// RVA: 0x85E830
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererFloat(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o, long double f)
{
  float v4; // xmm1_4

  if ( o )
  {
    v4 = f;
    Scaleform::GFx::DisplayObjectBase::SetRendererFloat(
      (Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr,
      v4);
  }
}

// File Line: 99
// RVA: 0x84CC40
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererFloat(Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx *this, long double *result, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *o)
{
  if ( o )
    *result = Scaleform::GFx::DisplayObjectBase::GetRendererFloat((Scaleform::GFx::DisplayObjectBase *)&o->pDispObj.pObject->vfptr);
}

// File Line: 121
// RVA: 0x1594E70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::disableBatching;
  return result;
}

// File Line: 122
// RVA: 0x1590280
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_1_bool_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,1,bool,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::isBatchingDisabled;
  return result;
}

// File Line: 123
// RVA: 0x1594E10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_2_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererString;
  return result;
}

// File Line: 124
// RVA: 0x15902B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_3_Scaleform::GFx::ASString_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAD0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,3,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererString;
  return result;
}

// File Line: 125
// RVA: 0x1594E40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_4_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *,double>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::setRendererFloat;
  return result;
}

// File Line: 126
// RVA: 0x15902E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx_5_double_Scaleform::GFx::AS3::Instances::fl_display::DisplayObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EAF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx,5,double,Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::getRendererFloat;
  return result;
}

// File Line: 159
// RVA: 0x757610
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::DisplayObjectEx::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::DisplayObjectExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::DisplayObjectEx::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::DisplayObjectExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::DisplayObjectEx::`vftable;
  }
  return v3;
}

