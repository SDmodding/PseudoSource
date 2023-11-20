// File Line: 49
// RVA: 0x7E95A0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::GetEventClass(Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *this)
{
  return this->pTraits.pObject->pVM[1].OpStack.pStack;
}

// File Line: 54
// RVA: 0x7B61B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::Clone(Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // r15
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rdi
  signed __int64 v5; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int v8; // eax

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  *((_BYTE *)&v4[1].RefCount + 4) = v3->AltKey;
  *((_BYTE *)&v4[1].RefCount + 5) = v3->CtrlKey;
  *((_BYTE *)&v4[1].RefCount + 6) = v3->ShiftKey;
  LODWORD(v4[1].vfptr) = v3->Delta;
  v5 = (signed __int64)&v3->RelatedObj;
  v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v4[1].8;
  if ( &v3->RelatedObj != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *)&v4[1].8 )
  {
    if ( *(_QWORD *)v5 )
      *(_DWORD *)(*(_QWORD *)v5 + 32i64) = (*(_DWORD *)(*(_QWORD *)v5 + 32i64) + 1) & 0x8FBFFFFF;
    v7 = *v6;
    if ( *v6 )
    {
      if ( (unsigned __int8)v7 & 1 )
      {
        *v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v7 - 1);
      }
      else
      {
        v8 = v7->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          v7->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    *v6 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v5;
  }
  v4[1].pNext = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->LocalX;
  v4[1].pPrev = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->LocalY;
  v4[1].RefCount = v3->ButtonsMask;
  LODWORD(v4[1].pTraits.pObject) = v3->mouseIdx;
  return v2;
}

// File Line: 90
// RVA: 0x7FFC40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 134
// RVA: 0x75FDA0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::MouseEventEx::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::MouseEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::MouseEvent::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::MouseEventEx::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::MouseEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::`vftable';
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
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::MouseEventEx::`vftable';
    LODWORD(v10[1].vfptr) = 0;
    HIDWORD(v10[1].vfptr) = 1;
    LODWORD(v10[1]._pRCC) = 2;
  }
  return v3;
}

