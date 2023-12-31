// File Line: 41
// RVA: 0x85B380
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::setHitTestDisable(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o,
        bool f)
{
  Scaleform::GFx::DisplayObject *pObject; // rcx

  if ( o )
  {
    pObject = o->pDispObj.pObject;
    if ( pObject )
    {
      if ( SLOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      {
        if ( f )
          pObject[1].Id.Id |= 0x800u;
        else
          pObject[1].Id.Id &= ~0x800u;
      }
    }
  }
}

// File Line: 51
// RVA: 0x84B810
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getHitTestDisable(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o)
{
  Scaleform::GFx::DisplayObject *pObject; // rcx

  *result = o
         && (pObject = o->pDispObj.pObject) != 0i64
         && SLOBYTE(pObject->Scaleform::GFx::DisplayObjectBase::Flags) < 0
         && (pObject[1].Id.Id & 0x800) != 0;
}

// File Line: 63
// RVA: 0x85ECE0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::setTopmostLevel(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o,
        bool f)
{
  Scaleform::GFx::InteractiveObject *pObject; // rdx
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  if ( o )
  {
    pObject = (Scaleform::GFx::InteractiveObject *)o->pDispObj.pObject;
    if ( pObject )
    {
      if ( SLOBYTE(pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      {
        if ( f )
          pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 2u;
        else
          pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= ~2u;
        vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
        if ( (pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 2) != 0 )
          Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter((Scaleform::GFx::MovieImpl *)vecDelDtor, pObject);
        else
          Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter((Scaleform::GFx::MovieImpl *)vecDelDtor, pObject);
      }
    }
  }
}

// File Line: 78
// RVA: 0x84D130
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getTopmostLevel(
        Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *o)
{
  Scaleform::GFx::DisplayObject *pObject; // rax
  unsigned __int16 Flags; // cx

  *result = o
         && (pObject = o->pDispObj.pObject) != 0i64
         && (Flags = pObject->Scaleform::GFx::DisplayObjectBase::Flags, (Flags & 0x80u) != 0)
         && (Flags & 2) != 0;
}

// File Line: 99
// RVA: 0x1595530
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB00 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::setHitTestDisable;
  return result;
}

// File Line: 100
// RVA: 0x1591840
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx_1_bool_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB10 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx,1,bool,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getHitTestDisable;
  return result;
}

// File Line: 101
// RVA: 0x1595500
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx_2_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB20 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::setTopmostLevel;
  return result;
}

// File Line: 102
// RVA: 0x1591870
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx_3_bool_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243EB30 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx,3,bool,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::getTopmostLevel;
  return result;
}

// File Line: 131
// RVA: 0x72ED00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::InteractiveObjectEx::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::InteractiveObjectExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::DisplayObjectEx::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::InteractiveObjectEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::InteractiveObjectExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
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
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::InteractiveObjectEx::`vftable;
  }
  return result;
}

