// File Line: 35
// RVA: 0x77D8F0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::GamePad(Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *v2; // rbx
  signed __int64 v3; // rcx
  Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *v4; // [rsp+60h] [rbp+8h]

  v4 = this;
  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::`vftable;
  v3 = (signed __int64)&v2->PAD_NONE;
  *(_DWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0i64;
  v2->PAD_BACK.Flags = 0;
  v2->PAD_BACK.Bonus.pWeakProxy = 0i64;
  v2->PAD_START.Flags = 0;
  v2->PAD_START.Bonus.pWeakProxy = 0i64;
  v2->PAD_A.Flags = 0;
  v2->PAD_A.Bonus.pWeakProxy = 0i64;
  v2->PAD_B.Flags = 0;
  v2->PAD_B.Bonus.pWeakProxy = 0i64;
  v2->PAD_X.Flags = 0;
  v2->PAD_X.Bonus.pWeakProxy = 0i64;
  v2->PAD_Y.Flags = 0;
  v2->PAD_Y.Bonus.pWeakProxy = 0i64;
  v2->PAD_R1.Flags = 0;
  v2->PAD_R1.Bonus.pWeakProxy = 0i64;
  v2->PAD_L1.Flags = 0;
  v2->PAD_L1.Bonus.pWeakProxy = 0i64;
  v2->PAD_R2.Flags = 0;
  v2->PAD_R2.Bonus.pWeakProxy = 0i64;
  v2->PAD_L2.Flags = 0;
  v2->PAD_L2.Bonus.pWeakProxy = 0i64;
  v2->PAD_UP.Flags = 0;
  v2->PAD_UP.Bonus.pWeakProxy = 0i64;
  v2->PAD_DOWN.Flags = 0;
  v2->PAD_DOWN.Bonus.pWeakProxy = 0i64;
  v2->PAD_RIGHT.Flags = 0;
  v2->PAD_RIGHT.Bonus.pWeakProxy = 0i64;
  v2->PAD_LEFT.Flags = 0;
  v2->PAD_LEFT.Bonus.pWeakProxy = 0i64;
  v2->PAD_PLUS.Flags = 0;
  v2->PAD_PLUS.Bonus.pWeakProxy = 0i64;
  v2->PAD_MINUS.Flags = 0;
  v2->PAD_MINUS.Bonus.pWeakProxy = 0i64;
  v2->PAD_1.Flags = 0;
  v2->PAD_1.Bonus.pWeakProxy = 0i64;
  v2->PAD_2.Flags = 0;
  v2->PAD_2.Bonus.pWeakProxy = 0i64;
  v2->PAD_H.Flags = 0;
  v2->PAD_H.Bonus.pWeakProxy = 0i64;
  v2->PAD_C.Flags = 0;
  v2->PAD_C.Bonus.pWeakProxy = 0i64;
  v2->PAD_Z.Flags = 0;
  v2->PAD_Z.Bonus.pWeakProxy = 0i64;
  v2->PAD_O.Flags = 0;
  v2->PAD_O.Bonus.pWeakProxy = 0i64;
  v2->PAD_T.Flags = 0;
  v2->PAD_T.Bonus.pWeakProxy = 0i64;
  v2->PAD_S.Flags = 0;
  v2->PAD_S.Bonus.pWeakProxy = 0i64;
  v2->PAD_SELECT.Flags = 0;
  v2->PAD_SELECT.Bonus.pWeakProxy = 0i64;
  v2->PAD_HOME.Flags = 0;
  v2->PAD_HOME.Bonus.pWeakProxy = 0i64;
  v2->PAD_RT.Flags = 0;
  v2->PAD_RT.Bonus.pWeakProxy = 0i64;
  v2->PAD_LT.Flags = 0;
  v2->PAD_LT.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_NONE, 0);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_BACK, 0xFF00u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_A, 0xFF02u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_B, 0xFF03u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_X, 0xFF04u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_Y, 0xFF05u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_R1, 0xFF06u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_L1, 0xFF07u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_R2, 0xFF08u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_L2, 0xFF09u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_UP, 0xFF0Au);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_DOWN, 0xFF0Bu);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_RIGHT, 0xFF0Cu);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_LEFT, 0xFF0Du);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_PLUS, 0xFF0Eu);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_MINUS, 0xFF0Fu);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_1, 0xFF10u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_2, 0xFF11u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_H, 0xFF12u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v4->PAD_C, 0xFF13u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_Z, 0xFF14u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_O, 0xFF15u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_T, 0xFF16u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_S, 0xFF17u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_SELECT, 0xFF18u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_HOME, 0xFF19u);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_RT, 0xFF1Au);
  Scaleform::GFx::AS3::Value::SetUInt32(&v2->PAD_LT, 0xFF1Bu);
}

// File Line: 86
// RVA: 0x1589FB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::GamePad_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ECA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::GamePad,0,bool>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *, bool *))Scaleform::GFx::AS3::Classes::fl_system::Capabilities::hasScreenPlaybackGet;
  return result;
}

// File Line: 141
// RVA: 0x760B30
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::GamePad::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::GamePadCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::GamePad::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::GamePadCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *)v4->vfptr->Alloc(v4, 1000ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::GamePad(v9, v3->pV);
  return v3;
}

