// File Line: 280
// RVA: 0x897EC0


// File Line: 285
// RVA: 0x91E120
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::capsLockGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *this,
        bool *result)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  char v3; // r8
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al

  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  v3 = *((_BYTE *)vecDelDtor + 10831);
  if ( (v3 & 2) != 0 )
    v4 = v3 & 4 | 2;
  else
    v4 = v3 & 4;
  if ( (v3 & 1) != 0 )
    v5 = v4 | 1;
  else
    v5 = v4 & 0xFE;
  if ( *((_BYTE *)vecDelDtor + 10858) )
    v6 = v5 | 0x10;
  else
    v6 = v5 & 0xEF;
  if ( *((_BYTE *)vecDelDtor + 10859) )
    v7 = v6 | 8;
  else
    v7 = v6 & 0xF7;
  *result = (v7 & 8) != 0;
}

// File Line: 301
// RVA: 0x9218D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::numLockGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *this,
        bool *result)
{
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  char v3; // r8
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al

  vecDelDtor = this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor;
  v3 = *((_BYTE *)vecDelDtor + 10831);
  if ( (v3 & 2) != 0 )
    v4 = v3 & 4 | 2;
  else
    v4 = v3 & 4;
  if ( (v3 & 1) != 0 )
    v5 = v4 | 1;
  else
    v5 = v4 & 0xFE;
  if ( *((_BYTE *)vecDelDtor + 10858) )
    v6 = v5 | 0x10;
  else
    v6 = v5 & 0xEF;
  if ( *((_BYTE *)vecDelDtor + 10859) )
    v7 = v6 | 8;
  else
    v7 = v6 & 0xF7;
  *result = (v7 & 0x10) != 0;
}

// File Line: 331
// RVA: 0x1598230
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Keyboard_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440288 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,0,bool>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::capsLockGet;
  return result;
}

// File Line: 332
// RVA: 0x15981D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Keyboard_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440298 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,1,bool>::Method = Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::numLockGet;
  return result;
}

// File Line: 333
// RVA: 0x1598200
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_ui::Keyboard_2_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_1424402A8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_ui::Keyboard,2,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 607
// RVA: 0x87F6E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::Keyboard::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *v10; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_ui::KeyboardCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::Keyboard::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, vm, &Scaleform::GFx::AS3::fl_ui::KeyboardCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *)MHeap->vfptr->Alloc(MHeap, 1632ui64, 0i64);
  if ( v10 )
    Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::Keyboard(v10, result->pV);
  return result;
}

