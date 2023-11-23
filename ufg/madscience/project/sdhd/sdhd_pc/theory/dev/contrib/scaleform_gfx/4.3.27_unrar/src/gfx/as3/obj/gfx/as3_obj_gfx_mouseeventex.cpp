// File Line: 49
// RVA: 0x7E95A0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *this)
{
  return this->pTraits.pObject->pVM[1].OpStack.pStack;
}

// File Line: 54
// RVA: 0x7B61B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::Clone(
        Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *p_RelatedObj; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  *((_BYTE *)&pObject[1].RefCount + 4) = this->AltKey;
  *((_BYTE *)&pObject[1].RefCount + 5) = this->CtrlKey;
  *((_BYTE *)&pObject[1].RefCount + 6) = this->ShiftKey;
  LODWORD(pObject[1].vfptr) = this->Delta;
  p_RelatedObj = &this->RelatedObj;
  v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&pObject[1].8;
  if ( &this->RelatedObj != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *)&pObject[1].8 )
  {
    if ( p_RelatedObj->pObject )
      p_RelatedObj->pObject->RefCount = (p_RelatedObj->pObject->RefCount + 1) & 0x8FBFFFFF;
    v7 = *v6;
    if ( *v6 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        *v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v7 - 1);
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    *v6 = p_RelatedObj->pObject;
  }
  pObject[1].pNext = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->LocalX;
  pObject[1].pPrev = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->LocalY;
  pObject[1].RefCount = this->ButtonsMask;
  LODWORD(pObject[1].pTraits.pObject) = this->mouseIdx;
  return result;
}

// File Line: 90
// RVA: 0x7FFC40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 134
// RVA: 0x75FDA0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::MouseEventEx::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::MouseEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::MouseEvent::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::MouseEventEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::MouseEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::`vftable;
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
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::MouseEventEx::`vftable;
    LODWORD(v10[1].vfptr) = 0;
    HIDWORD(v10[1].vfptr) = 1;
    LODWORD(v10[1]._pRCC) = 2;
  }
  return result;
}

