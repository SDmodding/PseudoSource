// File Line: 47
// RVA: 0x7E94E0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *this)
{
  return this->pTraits.pObject->pVM[1].RegisterFile.pRF;
}

// File Line: 52
// RVA: 0x7B5D70
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx::Clone(
        Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *p_RelatedObj; // r15
  Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *p_pTraits; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *vfptr; // rcx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  p_RelatedObj = &this->RelatedObj;
  p_pTraits = (Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx *)&result->pObject[1].pTraits;
  if ( &this->RelatedObj != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *)p_pTraits )
  {
    if ( p_RelatedObj->pObject )
      p_RelatedObj->pObject->RefCount = (p_RelatedObj->pObject->RefCount + 1) & 0x8FBFFFFF;
    vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)p_pTraits->vfptr;
    if ( p_pTraits->vfptr )
    {
      if ( ((unsigned __int8)vfptr & 1) != 0 )
      {
        p_pTraits->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)&vfptr[-1].RefCount + 7);
      }
      else
      {
        RefCount = vfptr->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          vfptr->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(vfptr);
        }
      }
    }
    p_pTraits->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)p_RelatedObj->pObject;
  }
  LOBYTE(pObject[1].vfptr) = this->ShiftKey;
  HIDWORD(pObject[1].vfptr) = this->KeyCode;
  LODWORD(pObject[1].pNext) = this->controllerIdx;
  return result;
}

// File Line: 81
// RVA: 0x7FF5E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::FocusEventEx> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 103
// RVA: 0x733450
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusEventEx::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::FocusEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::FocusEvent::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusEventEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::FocusEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::FocusEvent::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::FocusEventEx::`vftable;
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

