// File Line: 39
// RVA: 0x883BA0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,6,0,Scaleform::GFx::ASString const &>(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
    result,
    ",");
  return v2;
}

// File Line: 46
// RVA: 0x883BF0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,9,1,Scaleform::GFx::AS3::Value const &>(Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::AS3::Value::GetNull();
  v2->Flags = v3->Flags;
  v2->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
  v2->value.VNumber = v3->value.VNumber;
  v2->value.VS._2.VObj = v3->value.VS._2.VObj;
  if ( (v3->Flags & 0x1F) > 9 )
  {
    if ( (v3->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v3);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v3);
  }
  return v2;
}

// File Line: 112
// RVA: 0x1599250
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_0_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D18 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, unsigned int *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet;
  return result;
}

// File Line: 113
// RVA: 0x159AC30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_1_Scaleform::GFx::AS3::Value_const__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D28 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::lengthSet;
  return result;
}

// File Line: 114
// RVA: 0x159AC60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_2_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D38 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,2,Scaleform::GFx::AS3::Value const,bool>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::fixedSet;
  return result;
}

// File Line: 115
// RVA: 0x15991C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_3_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D48 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,3,bool>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::fixedGet;
  return result;
}

// File Line: 116
// RVA: 0x15991F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_4_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D58 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,4,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString;
  return result;
}

// File Line: 117
// RVA: 0x1599220
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_5_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D68 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,5,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString;
  return result;
}

// File Line: 118
// RVA: 0x159AC90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_6_Scaleform::GFx::ASString_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D78 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3join;
  return result;
}

// File Line: 119
// RVA: 0x159B260
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_7_bool_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D88 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,7,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3every;
  return result;
}

// File Line: 120
// RVA: 0x159B290
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_8_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440D98 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3forEach;
  return result;
}

// File Line: 121
// RVA: 0x159B2C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_9_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DA8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,9,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3map;
  return result;
}

// File Line: 122
// RVA: 0x159B2F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_10_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DB8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,10,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3push;
  return result;
}

// File Line: 123
// RVA: 0x159B3E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_11_bool_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DC8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,11,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3some;
  return result;
}

// File Line: 124
// RVA: 0x159B410
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_12_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DD8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,12,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3unshift;
  return result;
}

// File Line: 125
// RVA: 0x159B440
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_13_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DE8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,13,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3concat;
  return result;
}

// File Line: 126
// RVA: 0x159B470
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_14_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440DF8 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3filter;
  return result;
}

// File Line: 127
// RVA: 0x15992E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_15_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E08 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,15,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3pop;
  return result;
}

// File Line: 128
// RVA: 0x1599280
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_16_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E18 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,16,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3reverse;
  return result;
}

// File Line: 129
// RVA: 0x15992B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_17_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E28 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,17,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3shift;
  return result;
}

// File Line: 130
// RVA: 0x159B320
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_18_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E38 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3slice;
  return result;
}

// File Line: 131
// RVA: 0x159ACC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_19_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E48 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,19,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3sort;
  return result;
}

// File Line: 132
// RVA: 0x159B350
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_20_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E58 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,20,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3splice;
  return result;
}

// File Line: 133
// RVA: 0x159B380
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_21_long_Scaleform::GFx::ASString_const_____ptr64_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E68 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,21,long,Scaleform::GFx::ASString const &,long>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3indexOf;
  return result;
}

// File Line: 134
// RVA: 0x159B3B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_vec::Vector_String_22_long_Scaleform::GFx::ASString_const_____ptr64_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440E78 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,22,long,Scaleform::GFx::ASString const &,long>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3lastIndexOf;
  return result;
}

// File Line: 143
// RVA: 0x89EFE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rax
  Scaleform::MemoryHeap *v5; // r8
  signed __int64 v6; // [rsp+58h] [rbp+10h]
  signed __int64 v7; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`vftable';
  v4 = v2->pVM;
  v5 = v4->MHeap;
  v6 = (signed __int64)&v3->V;
  *(_QWORD *)v6 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  *(_BYTE *)(v6 + 8) = 0;
  *(_QWORD *)(v6 + 16) = v4;
  *(_QWORD *)v6 = &Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`vftable';
  v7 = (signed __int64)&v3->V.ValueA;
  *(_OWORD *)v7 = 0ui64;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_QWORD *)(v7 + 24) = v5;
}

// File Line: 149
// RVA: 0x9213E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this, int *result)
{
  *result = this->Delta;
}

// File Line: 155
// RVA: 0x921400
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::lengthSet(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, unsigned int value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h]

  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&this->V, &resulta, value);
}

// File Line: 162
// RVA: 0x91F760
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::fixedSet(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::Value *result, bool f)
{
  this->V.Fixed = f;
}

// File Line: 169
// RVA: 0x91F750
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::fixedGet(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, bool *result)
{
  *result = this->V.Fixed;
}

// File Line: 181
// RVA: 0x8AFB80
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = Scaleform::GFx::AS3::ArrayBase::ToString(
         (Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr,
         &resulta,
         (Scaleform::GFx::ASString *)&this->pTraits.pObject->pVM->StringManagerRef->Builtins[14])->pNode;
  ++v3->RefCount;
  v4 = v2->pNode;
  v5 = v2->pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v2->pNode = v3;
  v6 = resulta.pNode;
  v5 = resulta.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 187
// RVA: 0x8AF1C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3join(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *separator)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::ArrayBase::ToString((Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr, &resulta, separator)->pNode;
  ++v4->RefCount;
  v5 = v3->pNode;
  v6 = v3->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->pNode = v4;
  v7 = resulta.pNode;
  v6 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 193
// RVA: 0x8AEFB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3every(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, bool *result, Scaleform::GFx::AS3::Value *checker, Scaleform::GFx::AS3::Value *thisObj)
{
  *result = Scaleform::GFx::AS3::ArrayBase::Every(
              (Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr,
              checker,
              thisObj,
              (Scaleform::GFx::AS3::Object *)&this->vfptr);
}

// File Line: 199
// RVA: 0x8AF080
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3forEach(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *eacher, Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::ArrayBase::ForEach(
    (Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr,
    eacher,
    thisObj,
    (Scaleform::GFx::AS3::Object *)&this->vfptr);
}

// File Line: 206
// RVA: 0x8AF360
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3map(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result, Scaleform::GFx::AS3::Value *mapper, Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    mapper,
    thisObj,
    this);
}

// File Line: 212
// RVA: 0x8AF4D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3push(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // rbx
  unsigned __int64 v6; // rbx
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  v4 = result;
  v5 = this;
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBack(
    &this->V,
    argc,
    argv,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->pTraits.pObject->pVM->TraitsString.pObject->vfptr);
  v6 = v5->V.ValueA.Data.Size;
  if ( (v4->Flags & 0x1F) > 9 )
  {
    if ( (v4->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v4);
  }
  v4->Flags &= 0xFFFFFFE3;
  v4->Flags |= 3u;
  LODWORD(v7) = v6;
  v4->value.VNumber = v7;
  v4->value.VS._2 = v8;
}

// File Line: 219
// RVA: 0x8AFA60
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3some(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, bool *result, Scaleform::GFx::AS3::Value *checker, Scaleform::GFx::AS3::Value *thisObj)
{
  *result = Scaleform::GFx::AS3::ArrayBase::Some(
              (Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr,
              checker,
              thisObj,
              (Scaleform::GFx::AS3::Object *)&this->vfptr);
}

// File Line: 225
// RVA: 0x8AFC50
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3unshift(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // rbx
  unsigned __int64 v6; // rbx
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  v4 = result;
  v5 = this;
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Unshift(
    &this->V,
    argc,
    argv,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->pTraits.pObject->pVM->TraitsString.pObject->vfptr);
  v6 = v5->V.ValueA.Data.Size;
  if ( (v4->Flags & 0x1F) > 9 )
  {
    if ( (v4->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v4);
  }
  v4->Flags &= 0xFFFFFFE3;
  v4->Flags |= 3u;
  LODWORD(v7) = v6;
  v4->value.VNumber = v7;
  v4->value.VS._2 = v8;
}

// File Line: 232
// RVA: 0x8AEF10
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3concat(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    this);
}

// File Line: 238
// RVA: 0x8AEFE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3filter(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result, Scaleform::GFx::AS3::Value *checker, Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    checker,
    thisObj,
    this);
}

// File Line: 244
// RVA: 0x8AF400
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3pop(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Pop<Scaleform::GFx::ASString>(
    &this->V,
    result);
}

// File Line: 250
// RVA: 0x8AF7B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3reverse(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v3; // rdi

  v2 = this;
  v3 = result;
  Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy>>(&this->V.ValueA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v2);
}

// File Line: 257
// RVA: 0x8AF8C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3shift(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(
    &this->V,
    result);
}

// File Line: 263
// RVA: 0x8AF9C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3slice(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    this);
}

// File Line: 269
// RVA: 0x8AFA90
void __usercall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3sort(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this@<rcx>, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result@<rdx>, Scaleform::GFx::AS3::Value *comparefn@<r8>, __int64 a4@<rbx>, __int64 a5@<rdi>)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    comparefn,
    this,
    a4,
    a5);
}

// File Line: 275
// RVA: 0x8AFAE0
void __usercall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3splice(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this@<rcx>, Scaleform::GFx::AS3::Value *result@<rdx>, unsigned int argc@<r8d>, Scaleform::GFx::AS3::Value *const argv@<r9>, __int64 a5@<rbx>, __int64 a6@<rdi>)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    a5,
    a6,
    this);
}

// File Line: 281
// RVA: 0x8AF0A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3indexOf(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, int *result, Scaleform::GFx::ASString *value, int from)
{
  int *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // r11
  Scaleform::GFx::ASStringNode *v6; // r10
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // r8
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v10; // rdx
  bool v11; // zf

  v4 = result;
  v5 = this;
  v6 = value->pNode;
  if ( value->pNode )
    ++v6->RefCount;
  if ( from < 0 )
    from += this->V.ValueA.Data.Size;
  v7 = from;
  v8 = v5->V.ValueA.Data.Size;
  if ( from >= (unsigned __int64)(unsigned int)v5->V.ValueA.Data.Size )
  {
LABEL_11:
    *v4 = -1;
  }
  else
  {
    v9 = (unsigned int)v8;
    v10 = &v5->V.ValueA.Data.Data[from];
    while ( v10->pObject != v6 )
    {
      ++v7;
      ++v10;
      if ( v7 >= v9 )
        goto LABEL_11;
    }
    *v4 = v7;
  }
  if ( v6 )
  {
    v11 = v6->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 287
// RVA: 0x8AF220
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3lastIndexOf(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, int *result, Scaleform::GFx::ASString *value, int from)
{
  int *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // r10
  signed __int64 v6; // rax
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v7; // rdx
  bool v8; // zf

  v4 = result;
  v5 = value->pNode;
  if ( value->pNode )
    ++v5->RefCount;
  if ( from < 0 )
    from += this->V.ValueA.Data.Size;
  v6 = LODWORD(this->V.ValueA.Data.Size) - 1i64;
  if ( from < v6 )
    v6 = from;
  if ( v6 < 0 )
  {
LABEL_13:
    *v4 = -1;
  }
  else
  {
    v7 = &this->V.ValueA.Data.Data[v6];
    while ( v7->pObject != v5 )
    {
      --v7;
      if ( --v6 < 0 )
        goto LABEL_13;
    }
    *v4 = v6;
  }
  if ( v5 )
  {
    v8 = v5->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
}

// File Line: 297
// RVA: 0x89F070
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, unsigned int length, bool fixed)
{
  bool v4; // bp
  unsigned int v5; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rax
  Scaleform::MemoryHeap *v9; // rdx
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *v10; // ST28_8
  signed __int64 v11; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+70h] [rbp+18h]

  v4 = fixed;
  v5 = length;
  v6 = t;
  v7 = this;
  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr, t);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`vftable';
  v8 = v6->pVM;
  v9 = v8->MHeap;
  v11 = (signed __int64)&v7->V;
  *(_QWORD *)v11 = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  *(_BYTE *)(v11 + 8) = 0;
  *(_QWORD *)(v11 + 16) = v8;
  *(_QWORD *)v11 = &Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`vftable';
  v10 = &v7->V.ValueA;
  v10->Data.Data = 0i64;
  v10->Data.Size = 0i64;
  v10->Data.Policy.Capacity = 0i64;
  *(_QWORD *)(v11 + 48) = v9;
  if ( Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&v7->V, &result, v5)->Result )
    v7->V.Fixed = v4;
}

// File Line: 305
// RVA: 0x8AED50
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // rsi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]
  unsigned int v7; // [rsp+48h] [rbp+20h]

  v3 = argv;
  v4 = argc;
  v5 = this;
  if ( (!argc
     || Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &result, &v7)->Result
     && Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&v5->V, &result, v7)->Result)
    && v4 > 1 )
  {
    v5->V.Fixed = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 1);
  }
}

// File Line: 323
// RVA: 0x8DBD70
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Value *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // edi
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  v3 = name->Flags;
  v4 = name;
  v5 = name->Flags & 0x1F;
  if ( ind.Index )
  {
    v6 = ind.Index - 1;
    if ( (char)v5 > 9 )
    {
      if ( (v3 >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(name);
    }
    v4->Flags &= 0xFFFFFFE3;
    v4->Flags |= 3u;
    LODWORD(v7) = v6;
    v4->value.VNumber = v7;
    v4->value.VS._2 = v8;
  }
  else
  {
    if ( (char)v5 > 9 )
    {
      if ( (v3 >> 9) & 1 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(name);
        v4->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(name);
    }
    v4->Flags &= 0xFFFFFFE0;
  }
}

// File Line: 331
// RVA: 0x8DBA90
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::GetNextDynPropIndex(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::ArrayBaseVtbl *v3; // rax
  int v4; // ebx
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // rsi
  __int64 v6; // rdi
  unsigned int v7; // eax
  signed __int64 v8; // rdi

  v3 = this->V.vfptr;
  v4 = 0;
  v5 = result;
  v6 = ind.Index;
  result->Index = 0;
  v7 = v3->GetArraySize((Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr);
  v8 = v6 - 1;
  if ( v8 >= 0 )
  {
    if ( v8 >= (unsigned __int64)(v7 - 1) )
      return v5;
    v4 = v8 + 1;
    if ( v8 + 1 < 0 )
      return v5;
  }
  else if ( !v7 )
  {
    return v5;
  }
  v5->Index = v4 + 1;
  return v5;
}

// File Line: 342
// RVA: 0x90A4F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::SetProperty(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Multiname *v4; // rbp
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp-18h]
  unsigned int ind; // [rsp+34h] [rbp-14h]

  v4 = prop_name;
  v5 = this;
  v6 = result;
  v7 = value;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Set(
      v5,
      v6,
      ind,
      v7,
      (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->pTraits.pObject->pVM->TraitsString.pObject->vfptr);
  else
    Scaleform::GFx::AS3::Object::SetProperty((Scaleform::GFx::AS3::Object *)&v5->vfptr, v6, v4, v7);
  return v6;
}

// File Line: 352
// RVA: 0x8DCA50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::GetProperty(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Multiname *v5; // rbp
  Scaleform::GFx::AS3::CheckResult *v6; // rdi
  Scaleform::GFx::AS3::Object *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rbx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h]
  unsigned int ind; // [rsp+24h] [rbp-24h]
  __int64 v15; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+30h] [rbp-18h]

  v15 = -2i64;
  v4 = value;
  v5 = prop_name;
  v6 = result;
  v7 = (Scaleform::GFx::AS3::Object *)&this->vfptr;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    if ( ind >= v7[1].RefCount )
    {
      v8 = v7->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eOutOfRangeError, v8);
      Scaleform::GFx::AS3::VM::ThrowRangeError(v8, v9);
      v10 = v16.Message.pNode;
      v11 = v16.Message.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v6->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(v4, *((Scaleform::GFx::ASStringNode **)&v7[1].pPrev->vfptr + ind));
      v6->Result = 1;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(v7, v6, v5, v4);
  }
  return v6;
}

// File Line: 376
// RVA: 0x8D7360
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::GetDynamicProperty(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *value)
{
  this->V.vfptr->GetValue((Scaleform::GFx::AS3::ArrayBase *)&this->V, ind.Index, value);
}

// File Line: 381
// RVA: 0x8C5530
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::DeleteProperty(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  unsigned int ind; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h]

  v3 = prop_name;
  v4 = this;
  v5 = result;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::RemoveAt(v4, v5, ind);
  else
    Scaleform::GFx::AS3::Object::DeleteProperty((Scaleform::GFx::AS3::Object *)&v4->vfptr, v5, v3);
  return v5;
}

// File Line: 391
// RVA: 0x8E3200
_BOOL8 __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::HasProperty(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::Multiname *prop_name, bool check_prototype)
{
  bool v3; // si
  Scaleform::GFx::AS3::Object *v4; // rbx
  Scaleform::GFx::AS3::Multiname *v5; // rdi
  _BOOL8 v6; // rax
  unsigned int ind; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+20h]

  v3 = check_prototype;
  v4 = (Scaleform::GFx::AS3::Object *)&this->vfptr;
  v5 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(&result, prop_name, &ind)->Result )
    v6 = ind < v4[1].RefCount;
  else
    v6 = Scaleform::GFx::AS3::Object::HasProperty(v4, v5, v3);
  return v6;
}

// File Line: 442
// RVA: 0x159BF70
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[5].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[6].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[7].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[8].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[9].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[10].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[11].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[12].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[13].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[14].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[15].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[16].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[17].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[18].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[19].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[20].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[21].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::ti[22].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 474
// RVA: 0x8EB0F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 493
// RVA: 0x8B8F10
void __fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector_String::Call(Scaleform::GFx::AS3::Classes::fl_vec::Vector_String *this, Scaleform::GFx::AS3::Value *__formal, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::Classes::fl_vec::Vector_String *v6; // rbp
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Traits *v8; // rcx
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v10; // rbx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  unsigned int v14; // eax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> resulta; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::ASStringNode *v18; // [rsp+38h] [rbp-10h]

  v5 = result;
  v6 = this;
  if ( argc == 1 )
  {
    v7 = argv->Flags & 0x1F;
    if ( v7 && (v7 - 12 > 3 && v7 != 10 || *(_QWORD *)&argv->value.VNumber) )
    {
      v8 = this->pTraits.pObject;
      v9 = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)v8[1].vfptr;
      if ( Scaleform::GFx::AS3::VM::GetValueTraits(v8->pVM, argv) == (Scaleform::GFx::AS3::Traits *)v9 )
      {
        Scaleform::GFx::AS3::Value::Assign(v5, argv);
      }
      else
      {
        v10 = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(&resulta, v9)->pV;
        if ( Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
               (Scaleform::GFx::AS3::ArrayBase *)&v10->V.vfptr,
               argv,
               (Scaleform::GFx::AS3::ClassTraits::Traits *)&v10->pTraits.pObject->pVM->TraitsString.pObject->vfptr) )
        {
          Scaleform::GFx::AS3::Value::Assign(v5, (Scaleform::GFx::AS3::Object *)&v10->vfptr);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(
            (Scaleform::GFx::AS3::VM::Error *)&resulta,
            eCheckTypeFailedError,
            v6->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowTypeError(v6->pTraits.pObject->pVM, v11);
          v12 = v18;
          v13 = v18->RefCount == 1;
          --v12->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        }
        if ( !((unsigned __int8)v10 & 1) )
        {
          v14 = v10->RefCount;
          if ( v14 & 0x3FFFFF )
          {
            v10->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
          }
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(result, argv);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&resulta,
      eCoerceArgumentCountError,
      this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v6->pTraits.pObject->pVM, v15);
    v16 = v18;
    v13 = v18->RefCount == 1;
    --v16->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
}

// File Line: 545
// RVA: 0x87DA10
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_vec::Vector_StringCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::`vftable';
    v6->TraitsType = 15;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_vec::Vector_StringCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::`vftable';
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = 15;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector_String::`vftable';
  }
  return v3;
}

