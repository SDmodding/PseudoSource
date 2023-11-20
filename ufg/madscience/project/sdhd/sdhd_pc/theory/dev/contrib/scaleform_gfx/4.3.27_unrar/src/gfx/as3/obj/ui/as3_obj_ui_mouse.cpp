// File Line: 41
// RVA: 0x91E660
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorSet(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr,
    value,
    0);
}

// File Line: 50
// RVA: 0x91E640
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorGet(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr,
    result,
    0);
}

// File Line: 59
// RVA: 0x920DA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::hide(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::StateBag *v2; // rdx
  Scaleform::GFx::StateBagVtbl *v3; // rcx
  Scaleform::GFx::StateBag *v4; // rdi
  Scaleform::GFx::LogState *v5; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **v6; // rax
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  __int64 v9; // [rsp+30h] [rbp-18h]
  Scaleform::Ptr<Scaleform::GFx::LogState> resulta; // [rsp+50h] [rbp+8h]

  v2 = (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  v3 = v2[69].vfptr;
  if ( v3 )
  {
    v8 = 0;
    v7 = 22;
    v9 = 0i64;
    (*((void (__fastcall **)(Scaleform::GFx::StateBagVtbl *, Scaleform::GFx::StateBag *, int *))v3->GetStateBagImpl + 1))(
      v3,
      v2,
      &v7);
  }
  else
  {
    v4 = v2 + 2;
    v5 = Scaleform::GFx::StateBag::GetLogState(v2 + 2, &resulta)->pObject;
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    if ( v5 )
    {
      v6 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **)Scaleform::GFx::StateBag::GetLogState(v4, &resulta);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        *v6 + 3,
        "No user event handler interface is installed; Mouse.hide failed.");
      if ( resulta.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    }
  }
}

// File Line: 77
// RVA: 0x9269A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Mouse::show(Scaleform::GFx::AS3::Classes::fl_ui::Mouse *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::StateBag *v2; // rdx
  Scaleform::GFx::StateBagVtbl *v3; // rcx
  Scaleform::GFx::StateBag *v4; // rdi
  Scaleform::GFx::LogState *v5; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **v6; // rax
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  __int64 v9; // [rsp+30h] [rbp-18h]
  Scaleform::Ptr<Scaleform::GFx::LogState> resulta; // [rsp+50h] [rbp+8h]

  v2 = (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  v3 = v2[69].vfptr;
  if ( v3 )
  {
    v8 = 0;
    v7 = 21;
    v9 = 0i64;
    (*((void (__fastcall **)(Scaleform::GFx::StateBagVtbl *, Scaleform::GFx::StateBag *, int *))v3->GetStateBagImpl + 1))(
      v3,
      v2,
      &v7);
  }
  else
  {
    v4 = v2 + 2;
    v5 = Scaleform::GFx::StateBag::GetLogState(v2 + 2, &resulta)->pObject;
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    if ( v5 )
    {
      v6 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> **)Scaleform::GFx::StateBag::GetLogState(v4, &resulta);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        *v6 + 3,
        "No user event handler interface is installed; Mouse.hide failed.");
      if ( resulta.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
    }
  }
}

// File Line: 104
// RVA: 0x1599DF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_ui::Mouse_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402B8 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorSet;
  return result;
}

// File Line: 105
// RVA: 0x1598260
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Mouse_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402C8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,1,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::cursorGet;
  return result;
}

// File Line: 106
// RVA: 0x1598290
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Mouse_2_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402D8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,2,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::hide;
  return result;
}

// File Line: 107
// RVA: 0x15982C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Mouse_3_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402E8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Mouse,3,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Mouse::show;
  return result;
}

// File Line: 136
// RVA: 0x8753F0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::Mouse::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_ui::MouseCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::Mouse::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, v2, &Scaleform::GFx::AS3::fl_ui::MouseCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                        v4,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, v3->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_ui::Mouse::`vftable;
  }
  return v3;
}

