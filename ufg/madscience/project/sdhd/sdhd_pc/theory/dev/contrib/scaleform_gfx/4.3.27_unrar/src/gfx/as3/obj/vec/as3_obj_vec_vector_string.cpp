// File Line: 39
// RVA: 0x883BA0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,6,0,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(sm, result, ",");
  return result;
}

// File Line: 46
// RVA: 0x883BF0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,9,1,Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value *Null; // rax

  Null = Scaleform::GFx::AS3::Value::GetNull();
  result->Flags = Null->Flags;
  result->Bonus.pWeakProxy = Null->Bonus.pWeakProxy;
  result->value = Null->value;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
  }
  return result;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, unsigned int *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,2,Scaleform::GFx::AS3::Value const,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::fixedSet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,3,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::fixedGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,4,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,5,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3join;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,7,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3every;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3forEach;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,10,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3push;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,11,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, bool *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3some;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,12,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3unshift;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,13,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3concat;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,16,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3reverse;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3slice;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,19,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3sort;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,20,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3splice;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::MemoryHeap *MHeap; // r8

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`vftable;
  pVM = t->pVM;
  MHeap = pVM->MHeap;
  this->V.vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable;
  this->V.Fixed = 0;
  this->V.VMRef = pVM;
  this->V.vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`vftable;
  this->V.ValueA.Data.Data = 0i64;
  this->V.ValueA.Data.Size = 0i64;
  this->V.ValueA.Data.Policy.Capacity = 0i64;
  this->V.ValueA.Data.pHeap = MHeap;
}

// File Line: 149
// RVA: 0x9213E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        int *result)
{
  *result = this->Delta;
}

// File Line: 155
// RVA: 0x921400
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&this->V, &resulta, value);
}

// File Line: 162
// RVA: 0x91F760
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::fixedSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *result,
        bool f)
{
  this->V.Fixed = f;
}

// File Line: 169
// RVA: 0x91F750
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::fixedGet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        bool *result)
{
  *result = this->V.Fixed;
}

// File Line: 181
// RVA: 0x8AFB80
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3toLocaleString(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v3 = Scaleform::GFx::AS3::ArrayBase::ToString(
         &this->V,
         &resulta,
         (Scaleform::GFx::ASString *)&this->pTraits.pObject->pVM->StringManagerRef->Builtins[14]);
  pNode = v3->pNode;
  ++v3->pNode->RefCount;
  v5 = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  result->pNode = pNode;
  v7 = resulta.pNode;
  v6 = resulta.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 187
// RVA: 0x8AF1C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::AS3join(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *separator)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v4 = Scaleform::GFx::AS3::ArrayBase::ToString(&this->V, &resulta, separator);
  pNode = v4->pNode;
  ++v4->pNode->RefCount;
  v6 = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  result->pNode = pNode;
  v8 = resulta.pNode;
  v7 = resulta.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 193
// RVA: 0x8AEFB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::AS3every(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        bool *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
{
  *result = Scaleform::GFx::AS3::ArrayBase::Every(&this->V, checker, thisObj, this);
}

// File Line: 199
// RVA: 0x8AF080
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3forEach(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *eacher,
        Scaleform::GFx::AS3::Value *thisObj)
{
  Scaleform::GFx::AS3::ArrayBase::ForEach(&this->V, eacher, thisObj, this);
}

// File Line: 206
// RVA: 0x8AF360
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3map(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::Value *mapper,
        Scaleform::GFx::AS3::Value *thisObj)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3push(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned __int64 Size; // rbx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBack(
    &this->V,
    argc,
    argv,
    this->pTraits.pObject->pVM->TraitsString.pObject);
  Size = this->V.ValueA.Data.Size;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags &= 0xFFFFFFE3;
  result->Flags |= 3u;
  v7.VInt = Size;
  result->value.VS._1 = v7;
  result->value.VS._2 = v8;
}

// File Line: 219
// RVA: 0x8AFA60
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3some(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        bool *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
{
  *result = Scaleform::GFx::AS3::ArrayBase::Some(&this->V, checker, thisObj, this);
}

// File Line: 225
// RVA: 0x8AFC50
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3unshift(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned __int64 Size; // rbx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Unshift(
    &this->V,
    argc,
    argv,
    this->pTraits.pObject->pVM->TraitsString.pObject);
  Size = this->V.ValueA.Data.Size;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags &= 0xFFFFFFE3;
  result->Flags |= 3u;
  v7.VInt = Size;
  result->value.VS._1 = v7;
  result->value.VS._2 = v8;
}

// File Line: 232
// RVA: 0x8AEF10
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3concat(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3filter(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::Value *checker,
        Scaleform::GFx::AS3::Value *thisObj)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3pop(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Pop<Scaleform::GFx::ASString>(
    &this->V,
    result);
}

// File Line: 250
// RVA: 0x8AF7B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy>>(&this->V.ValueA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
}

// File Line: 257
// RVA: 0x8AF8C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3shift(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(
    &this->V,
    result);
}

// File Line: 263
// RVA: 0x8AF9C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3slice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3sort(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::Value *comparefn)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    comparefn,
    this);
}

// File Line: 275
// RVA: 0x8AFAE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3splice(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
    &this->V,
    result,
    argc,
    argv,
    this);
}

// File Line: 281
// RVA: 0x8AF0A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3indexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        int *result,
        Scaleform::GFx::ASString *value,
        int from)
{
  Scaleform::GFx::ASStringNode *pNode; // r10
  unsigned __int64 v7; // rcx
  unsigned __int64 Size; // rdx
  unsigned __int64 v9; // r8
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v10; // rdx

  pNode = value->pNode;
  if ( value->pNode )
    ++pNode->RefCount;
  if ( from < 0 )
    from += this->V.ValueA.Data.Size;
  v7 = from;
  Size = this->V.ValueA.Data.Size;
  if ( from >= (unsigned __int64)(unsigned int)Size )
  {
LABEL_11:
    *result = -1;
  }
  else
  {
    v9 = (unsigned int)Size;
    v10 = &this->V.ValueA.Data.Data[from];
    while ( v10->pObject != pNode )
    {
      ++v7;
      ++v10;
      if ( v7 >= v9 )
        goto LABEL_11;
    }
    *result = v7;
  }
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 287
// RVA: 0x8AF220
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3lastIndexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        int *result,
        Scaleform::GFx::ASString *value,
        int from)
{
  Scaleform::GFx::ASStringNode *pNode; // r10
  __int64 v6; // rax
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v7; // rdx

  pNode = value->pNode;
  if ( value->pNode )
    ++pNode->RefCount;
  if ( from < 0 )
    from += this->V.ValueA.Data.Size;
  v6 = LODWORD(this->V.ValueA.Data.Size) - 1i64;
  if ( from < v6 )
    v6 = from;
  if ( v6 < 0 )
  {
LABEL_13:
    *result = -1;
  }
  else
  {
    v7 = &this->V.ValueA.Data.Data[v6];
    while ( v7->pObject != pNode )
    {
      --v7;
      if ( --v6 < 0 )
        goto LABEL_13;
    }
    *result = v6;
  }
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 297
// RVA: 0x89F070
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::MemoryHeap *MHeap; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+70h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::`vftable;
  pVM = t->pVM;
  MHeap = pVM->MHeap;
  this->V.vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable;
  this->V.Fixed = 0;
  this->V.VMRef = pVM;
  this->V.vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::`vftable;
  this->V.ValueA.Data.Data = 0i64;
  this->V.ValueA.Data.Size = 0i64;
  this->V.ValueA.Data.Policy.Capacity = 0i64;
  this->V.ValueA.Data.pHeap = MHeap;
  if ( Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&this->V, &result, length)->Result )
    this->V.Fixed = fixed;
}

// File Line: 305
// RVA: 0x8AED50
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF
  unsigned int v7; // [rsp+48h] [rbp+20h] BYREF

  if ( (!argc
     || Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &result, &v7)->Result
     && Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(&this->V, &result, v7)->Result)
    && argc > 1 )
  {
    this->V.Fixed = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 1);
  }
}

// File Line: 323
// RVA: 0x8DBD70
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int Flags; // ecx
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value::V1U v6; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = name->Flags;
  if ( ind.Index )
  {
    v5 = ind.Index - 1;
    if ( (name->Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(name);
    }
    name->Flags &= 0xFFFFFFE3;
    name->Flags |= 3u;
    v6.VInt = v5;
    name->value.VS._1 = v6;
    name->value.VS._2 = v7;
  }
  else
  {
    if ( (name->Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(name);
        name->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(name);
    }
    name->Flags &= 0xFFFFFFE0;
  }
}

// File Line: 331
// RVA: 0x8DBA90
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::ArrayBaseVtbl *vfptr; // rax
  int v4; // ebx
  __int64 Index; // rdi
  unsigned int v7; // eax
  __int64 v8; // rdi

  vfptr = this->V.vfptr;
  v4 = 0;
  Index = ind.Index;
  result->Index = 0;
  v7 = vfptr->GetArraySize(&this->V);
  v8 = Index - 1;
  if ( v8 >= 0 )
  {
    if ( v8 >= (unsigned __int64)(v7 - 1) )
      return result;
    v4 = v8 + 1;
    if ( v8 + 1 < 0 )
      return result;
  }
  else if ( !v7 )
  {
    return result;
  }
  result->Index = v4 + 1;
  return result;
}

// File Line: 342
// RVA: 0x90A4F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp-18h] BYREF
  unsigned int ind[5]; // [rsp+34h] [rbp-14h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Set(
      this,
      result,
      ind[0],
      value,
      this->pTraits.pObject->pVM->TraitsString.pObject);
  else
    Scaleform::GFx::AS3::Object::SetProperty(this, result, prop_name, value);
  return result;
}

// File Line: 352
// RVA: 0x8DCA50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::GetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-28h] BYREF
  unsigned int ind; // [rsp+24h] [rbp-24h] BYREF
  __int64 v15; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+30h] [rbp-18h] BYREF

  v15 = -2i64;
  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, &ind)->Result )
  {
    if ( ind >= LODWORD(this->V.ValueA.Data.Size) )
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, 1125, pVM);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v9);
      pNode = v16.Message.pNode;
      if ( v16.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(value, this->V.ValueA.Data.Data[ind].pObject);
      result->Result = 1;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(this, result, prop_name, value);
  }
  return result;
}

// File Line: 376
// RVA: 0x8D7360
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  this->V.vfptr->GetValue(&this->V, ind.Index, value);
}

// File Line: 381
// RVA: 0x8C5530
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned int ind[6]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name, ind)->Result )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::RemoveAt(this, result, ind[0]);
  else
    Scaleform::GFx::AS3::Object::DeleteProperty(this, result, prop_name);
  return result;
}

// File Line: 391
// RVA: 0x8E3200
_BOOL8 __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::HasProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        bool check_prototype)
{
  unsigned int ind[6]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&result, prop_name, ind)->Result )
    return ind[0] < LODWORD(this->V.ValueA.Data.Size);
  else
    return Scaleform::GFx::AS3::Object::HasProperty(this, prop_name, check_prototype);
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 493
// RVA: 0x8B8F10
void __fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector_String::Call(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *vfptr; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pV; // rbx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM::Error resulta; // [rsp+30h] [rbp-18h] BYREF

  if ( argc == 1 )
  {
    v7 = argv->Flags & 0x1F;
    if ( v7 && (v7 - 12 > 3 && v7 != 10 || argv->value.VS._1.VStr) )
    {
      pObject = this->pTraits.pObject;
      vfptr = (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)pObject[1].vfptr;
      if ( Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv) == vfptr )
      {
        Scaleform::GFx::AS3::Value::Assign(result, argv);
      }
      else
      {
        pV = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&resulta,
               vfptr)->pV;
        if ( Scaleform::GFx::AS3::ArrayBase::AppendCoerce(&pV->V, argv, pV->pTraits.pObject->pVM->TraitsString.pObject) )
        {
          Scaleform::GFx::AS3::Value::Assign(result, pV);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&resulta, 1034, this->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v11);
          pNode = resulta.Message.pNode;
          v13 = resulta.Message.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        if ( ((unsigned __int8)pV & 1) == 0 )
        {
          RefCount = pV->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pV->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
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
    Scaleform::GFx::AS3::VM::Error::Error(&resulta, 1112, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->pTraits.pObject->pVM, v15);
    v16 = resulta.Message.pNode;
    v13 = resulta.Message.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
}

// File Line: 545
// RVA: 0x87DA10
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_vec::Vector_StringCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::`vftable;
    v6->TraitsType = Traits_Vector_String;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_vec::Vector_StringCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::`vftable;
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = Traits_Vector_String;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector_String::`vftable;
  }
  return result;
}

