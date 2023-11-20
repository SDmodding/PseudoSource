// File Line: 53
// RVA: 0x80F0B0
__int64 __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::ReadNextPixel(Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this)
{
  unsigned int result; // [rsp+30h] [rbp+8h]

  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readInt(this->PixelArray, &result);
  return result;
}

// File Line: 57
// RVA: 0x82A220
void __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::WriteNextPixel(Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this, unsigned int pixel)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v3; // rdi

  v2 = pixel;
  v3 = this->PixelArray;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeInt(v3, &v, v2);
}

// File Line: 62
// RVA: 0x7EB9A0
unsigned __int64 __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::GetLength(Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this)
{
  return this->PixelArray->Length;
}

// File Line: 76
// RVA: 0x80F0D0
__int64 __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::ReadNextPixel(Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  unsigned int v1; // ebx
  __int64 v2; // rdx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v3; // rax
  int v4; // edx
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value::VU v7; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Value v8; // [rsp+38h] [rbp-30h]

  v1 = 0;
  v8.Flags = 0;
  v8.Bonus.pWeakProxy = 0i64;
  v2 = this->Location;
  this->Location = v2 + 1;
  v3 = this->PixelVector;
  if ( (unsigned int)v2 < LODWORD(v3->V.ValueA.Data.Size) )
  {
    v4 = v3->V.ValueA.Data.Data[v2];
    v1 = 3;
    v8.Flags = 3;
    v7.VS._1.VInt = v4;
    v8.value = v7;
  }
  v5 = v8.value.VS._1.VUInt;
  if ( (char)(v1 & 0x1F) > 9 )
  {
    if ( (v1 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v8.Bonus.pWeakProxy = 0i64;
      v8.value = 0ui64;
      v8.Flags = v1 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
    }
  }
  return v5;
}

// File Line: 82
// RVA: 0x82A290
void __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::WriteNextPixel(Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this, unsigned int pixel)
{
  unsigned int v2; // er8
  bool v3; // zf
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+10h]

  v2 = this->Location;
  this->Location = v2 + 1;
  v.Flags = 3;
  v.Bonus.pWeakProxy = 0i64;
  v.value.VS._1.VInt = pixel;
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Set(
    this->PixelVector,
    &result,
    v2,
    &v,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->PixelVector->pTraits.pObject->pVM->TraitsUint.pObject->vfptr);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v3 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v3 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v.Bonus.pWeakProxy = 0i64;
      v.value = 0ui64;
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 86
// RVA: 0x7EB9B0
unsigned __int64 __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::GetLength(Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  int result; // [rsp+30h] [rbp+8h]

  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)this->PixelVector,
    &result);
  return (unsigned int)result;
}

// File Line: 105
// RVA: 0x76C760
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,11,3,Scaleform::GFx::ASString const &>(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
    result,
    "null");
  return v2;
}

// File Line: 176
// RVA: 0x15881E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_0_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B710 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,0,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet;
  return result;
}

// File Line: 177
// RVA: 0x15880F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_1_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B720 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::rectGet;
  return result;
}

// File Line: 178
// RVA: 0x1588120
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_2_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B730 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,2,bool>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet;
  return result;
}

// File Line: 179
// RVA: 0x1588150
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_3_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B740 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,3,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet;
  return result;
}

// File Line: 180
// RVA: 0x15967F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc4_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_4_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B750 = v1;
  Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::applyFilter;
  return result;
}

// File Line: 181
// RVA: 0x1588180
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::BitmapData___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B760 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData>>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone;
  return result;
}

// File Line: 182
// RVA: 0x15947B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_6_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B770 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::colorTransform;
  return result;
}

// File Line: 183
// RVA: 0x158F380
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_7_Scaleform::GFx::AS3::Value_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B780 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,7,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::compare;
  return result;
}

// File Line: 184
// RVA: 0x1596970
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_8_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_unsigned_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B790 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel;
  return result;
}

// File Line: 185
// RVA: 0x1596AF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc6_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_9_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,bool>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyPixels;
  return result;
}

// File Line: 186
// RVA: 0x15881B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_10_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,10,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::dispose;
  return result;
}

// File Line: 187
// RVA: 0x1596B50
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc6_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_11_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl::Object_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Matrix_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_____ptr64_Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,11,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,bool>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::draw;
  return result;
}

// File Line: 188
// RVA: 0x1594990
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_12_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,12,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect;
  return result;
}

// File Line: 189
// RVA: 0x1596280
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_13_Scaleform::GFx::AS3::Value_const__long_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,13,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill;
  return result;
}

// File Line: 190
// RVA: 0x15949C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_14_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B7F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::generateFilterRect;
  return result;
}

// File Line: 191
// RVA: 0x15962B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_15_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle__unsigned_long_unsigned_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B800 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,15,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>,unsigned long,unsigned long,bool>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *, unsigned int, unsigned int, bool))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getColorBoundsRect;
  return result;
}

// File Line: 192
// RVA: 0x15947E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_16_unsigned_long_long_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B810 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,16,unsigned long,long,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel;
  return result;
}

// File Line: 193
// RVA: 0x1594810
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_17_unsigned_long_long_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B820 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,17,unsigned long,long,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel32;
  return result;
}

// File Line: 194
// RVA: 0x158F3B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_18_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_utils::ByteArray__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B830 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,18,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixels;
  return result;
}

// File Line: 195
// RVA: 0x158F3E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_19_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B840 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,19,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getVector;
  return result;
}

// File Line: 196
// RVA: 0x15969A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_20_bool_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_unsigned_long_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B850 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,20,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::hitTest;
  return result;
}

// File Line: 197
// RVA: 0x158F410
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_21_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B860 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,21,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram;
  return result;
}

// File Line: 198
// RVA: 0x1588210
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_22_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B870 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,22,Scaleform::GFx::AS3::Value const>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *))_;
  return result;
}

// File Line: 199
// RVA: 0x1594840
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_23_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B880 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,23,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge;
  return result;
}

// File Line: 200
// RVA: 0x15969D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_24_Scaleform::GFx::AS3::Value_const__long_unsigned_long_unsigned_long_unsigned_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B890 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise;
  return result;
}

// File Line: 201
// RVA: 0x1594870
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_25_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,25,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap;
  return result;
}

// File Line: 202
// RVA: 0x15948A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_26_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,26,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise;
  return result;
}

// File Line: 203
// RVA: 0x1596B20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc6_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_27_long_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_geom::Point_____ptr64_long_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,27,long,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,long,long,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::pixelDissolve;
  return result;
}

// File Line: 204
// RVA: 0x15948D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_28_Scaleform::GFx::AS3::Value_const__long_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,28,Scaleform::GFx::AS3::Value const,long,long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::scroll;
  return result;
}

// File Line: 205
// RVA: 0x1596220
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_29_Scaleform::GFx::AS3::Value_const__long_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,29,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel;
  return result;
}

// File Line: 206
// RVA: 0x1596250
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc3_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_30_Scaleform::GFx::AS3::Value_const__long_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B8F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,30,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel32;
  return result;
}

// File Line: 207
// RVA: 0x1594900
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_31_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_utils::ByteArray_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B900 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,31,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixels;
  return result;
}

// File Line: 208
// RVA: 0x1594930
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_32_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B910 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,32,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *>::Method = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector;
  return result;
}

// File Line: 209
// RVA: 0x1594960
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_33_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B920 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,33,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold;
  return result;
}

// File Line: 210
// RVA: 0x158F440
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::BitmapData_34_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B930 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,34,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))_;
  return result;
}

// File Line: 225
// RVA: 0x84DF40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, int *result)
{
  Scaleform::Render::ImageBase *v2; // r8
  int *v3; // rbx
  __int64 v4; // rax
  char v5; // [rsp+20h] [rbp-18h]

  v2 = this->pImage.pObject;
  v3 = result;
  if ( v2 )
  {
    v4 = (__int64)v2->vfptr[6].__vecDelDtor(
                    (Scaleform::RefCountImplCore *)&this->pImage.pObject->vfptr,
                    (unsigned int)&v5);
    *v3 = *(_DWORD *)(v4 + 12) - *(_DWORD *)(v4 + 4);
  }
  else
  {
    *result = this->Height;
  }
}

// File Line: 235
// RVA: 0x8594F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::rectGet(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // rbx
  double v4; // xmm0_8
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8
  char ptr; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v9; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value v10; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::Value v11; // [rsp+A0h] [rbp-48h]

  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result;
  v3 = this;
  `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)&ptr, 0.0);
  Scaleform::GFx::AS3::Value::SetNumber(&v9, 0.0);
  v4 = (double)(signed int)v3->Width;
  if ( v4 <= 0.0 )
    v5 = v4 - 0.5;
  else
    v5 = v4 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v10, (double)(signed int)v5);
  v6 = (double)(signed int)v3->Height;
  if ( v6 <= 0.0 )
    v7 = v6 - 0.5;
  else
    v7 = v6 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v11, (double)(signed int)v7);
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)v3->pTraits.pObject->pVM,
    v2,
    v3->pTraits.pObject->pVM[1].ExceptionObj.value.VS._1.VObj,
    4u,
    (Scaleform::GFx::AS3::Value *)&ptr);
  `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 247
// RVA: 0x86AB90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, bool *result)
{
  bool *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // rbx
  Scaleform::Render::ImageBase *v4; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v2 = result;
  v3 = this;
  v4 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
  if ( v4 )
  {
    *v2 = v4[4].RefCount;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eArgumentError, v3->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 256
// RVA: 0x86BF50
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, int *result)
{
  Scaleform::Render::ImageBase *v2; // r8
  int *v3; // rbx
  _DWORD *v4; // rax
  char v5; // [rsp+20h] [rbp-18h]

  v2 = this->pImage.pObject;
  v3 = result;
  if ( v2 )
  {
    v4 = (_DWORD *)v2->vfptr[6].__vecDelDtor(
                     (Scaleform::RefCountImplCore *)&this->pImage.pObject->vfptr,
                     (unsigned int)&v5);
    *v3 = v4[2] - *v4;
  }
  else
  {
    *result = this->Width;
  }
}

// File Line: 266
// RVA: 0x82D0F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::applyFilter(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect, Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint, Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *filter)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v8; // rbx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v13; // r15
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v15; // r13
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::Render::DrawableImage *v17; // r14
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::Render::DrawableImage *v19; // r12
  double v20; // xmm2_8
  double v21; // xmm0_8
  Scaleform::Render::Filter *v22; // rsi
  Scaleform::GFx::AS3::FlashUI *v23; // rcx
  signed int v24; // eax
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::AS3::VM::Error *v26; // rax
  bool v27; // [rsp+30h] [rbp-50h]
  Scaleform::Render::Point<long> v28; // [rsp+38h] [rbp-48h]
  __int64 v29; // [rsp+40h] [rbp-40h]
  Scaleform::Render::Rect<long> sourceRecta; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::VM::Error v31; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v32; // [rsp+68h] [rbp-18h]
  bool resulta; // [rsp+C0h] [rbp+40h]

  v29 = -2i64;
  v6 = sourceRect;
  v7 = sourceBitmapData;
  v8 = this;
  if ( !sourceBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v10 = v31.Message.pNode;
    goto LABEL_4;
  }
  if ( !sourceRect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v8->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v13 = destPoint;
  if ( !destPoint )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v8->pTraits.pObject->pVM,
      v14,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v15 = filter;
  if ( !filter )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v8->pTraits.pObject->pVM,
      v16,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
  if ( !v17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eArgumentError, v8->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v8->pTraits.pObject->pVM,
      v18,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v8, v7);
  v20 = v6->height;
  v21 = v6->width;
  sourceRecta.x1 = (signed int)v6->x;
  sourceRecta.y1 = (signed int)v6->y;
  sourceRecta.x2 = (signed int)(v21 + v6->x);
  sourceRecta.y2 = (signed int)(v20 + v6->y);
  v28.x = (signed int)v13->x;
  v28.y = (signed int)v13->y;
  v22 = v15->FilterData.pObject;
  if ( !v22 )
  {
LABEL_15:
    v23 = v8->pTraits.pObject->pVM->UI;
    v23->vfptr->Output(
      v23,
      Output_Warning,
      "The method BitmapData::applyFilter (unsupported filter type) is not implemented\n");
    return;
  }
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(v8, &resulta);
  v24 = v22->Type;
  if ( !v24 )
  {
LABEL_25:
    Scaleform::Render::DrawableImage::ApplyFilter(v17, v19, &sourceRecta, &v28, v22);
    return;
  }
  if ( v24 <= 0 )
    goto LABEL_15;
  if ( v24 > 3 )
  {
    if ( v24 != 8 )
    {
      if ( v24 != 10 )
        goto LABEL_15;
      Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(v7, &v27);
      if ( v27 != resulta )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v31, eIllegalOperationError, v8->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v8->pTraits.pObject->pVM,
          v25,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_3;
      }
    }
    goto LABEL_25;
  }
  if ( resulta )
    goto LABEL_25;
  Scaleform::GFx::AS3::VM::Error::Error(&v32, eIllegalOperationError, v8->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8->pTraits.pObject->pVM, v26, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  v10 = v32.Message.pNode;
LABEL_4:
  v11 = v10->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 339
// RVA: 0x82F2E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *)this->pTraits.pObject);
  v5 = v2->pObject;
  v6 = v4->pV;
  if ( v4->pV != v2->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v2->pObject = v6;
  }
  v2->pObject->Width = v3->Width;
  v2->pObject->Height = v3->Height;
  v2->pObject->Transparent = v3->Transparent;
  v2->pObject->ClearColor.Raw = v3->ClearColor.Raw;
}

// File Line: 352
// RVA: 0x830EB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::colorTransform(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *cTransform)
{
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rbx
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::Render::DrawableImage *v11; // rbp
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  double v13; // xmm0_8
  double v14; // xmm1_8
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+28h] [rbp-40h]
  Scaleform::Render::Cxform resulta; // [rsp+40h] [rbp-28h]

  v4 = cTransform;
  v5 = rect;
  v6 = this;
  if ( rect )
  {
    if ( cTransform )
    {
      v11 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
      if ( v11 )
      {
        Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(&resulta, v4);
        v13 = v5->x;
        v15.ID = (signed int)v13;
        v14 = v5->y;
        *((_DWORD *)&v15.ID + 1) = (signed int)v14;
        LODWORD(v15.Message.pNode) = (signed int)(v13 + v5->width);
        HIDWORD(v15.Message.pNode) = (signed int)(v14 + v5->height);
        Scaleform::Render::DrawableImage::ColorTransform(v11, (Scaleform::Render::Rect<long> *)&v15, &resulta);
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eArgumentError, v6->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v6->pTraits.pObject->pVM,
        v12,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eIllegalOperationError, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v6->pTraits.pObject->pVM,
        v10,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eIllegalOperationError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  v8 = v15.Message.pNode;
  v9 = v15.Message.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 373
// RVA: 0x831400
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::compare(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *otherBitmapData)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // r15
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::Render::ImageBase *v9; // rcx
  _DWORD *v10; // rax
  unsigned int v11; // ebp
  Scaleform::Render::ImageBase *v12; // rcx
  __int64 v13; // rax
  int v14; // esi
  Scaleform::Render::ImageBase *v15; // rcx
  _DWORD *v16; // rax
  int v17; // er14
  Scaleform::Render::ImageBase *v18; // rcx
  __int64 v19; // rax
  int v20; // ecx
  Scaleform::Render::DrawableImage *v21; // rsi
  Scaleform::Render::DrawableImage *v22; // rdi
  Scaleform::Render::DrawableImage *v23; // rax
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+70h] [rbp+18h]

  v3 = otherBitmapData;
  v4 = result;
  v5 = this;
  if ( otherBitmapData )
  {
    v9 = otherBitmapData->pImage.pObject;
    if ( v9 )
    {
      v10 = (_DWORD *)v9->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)&v28);
      v11 = v10[2] - *v10;
    }
    else
    {
      v11 = otherBitmapData->Width;
    }
    v12 = v3->pImage.pObject;
    if ( v12 )
    {
      v13 = (__int64)v12->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)&v28);
      v14 = *(_DWORD *)(v13 + 12) - *(_DWORD *)(v13 + 4);
    }
    else
    {
      v14 = v3->Height;
    }
    v15 = v5->pImage.pObject;
    if ( v15 )
    {
      v16 = (_DWORD *)v15->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)&v28);
      v17 = v16[2] - *v16;
    }
    else
    {
      v17 = v5->Width;
    }
    v18 = v5->pImage.pObject;
    if ( v18 )
    {
      v19 = (__int64)v18->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)&v28);
      v20 = *(_DWORD *)(v19 + 12) - *(_DWORD *)(v19 + 4);
    }
    else
    {
      v20 = v5->Height;
    }
    if ( v17 == v11 )
    {
      if ( v20 == v14 )
      {
        v21 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v5, v3);
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(v5, &resulta);
        v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                v5,
                resulta.pObject);
        v23 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v5, v5);
        if ( v21 && v22 && v23 )
        {
          Scaleform::Render::DrawableImage::Compare(v22, v23, v21);
          Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::AS3::Object *)&resulta.pObject->vfptr);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v28, eArgumentError, v5->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            v5->pTraits.pObject->pVM,
            v24,
            &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          v25 = v28.Message.pNode;
          v8 = v28.Message.pNode->RefCount == 1;
          --v25->RefCount;
          if ( v8 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        }
        v26 = resulta.pObject;
        if ( resulta.pObject )
        {
          if ( (_QWORD)resulta.pObject & 1 )
          {
            --resulta.pObject;
          }
          else
          {
            v27 = resulta.pObject->RefCount;
            if ( v27 & 0x3FFFFF )
            {
              resulta.pObject->RefCount = v27 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26->vfptr);
            }
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::SetSInt32(v4, -4);
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetSInt32(v4, -3);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v7 = v28.Message.pNode;
    v8 = v28.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 412
// RVA: 0x8324A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect, Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint, unsigned int sourceChannel, unsigned int destChannel)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v7; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v8; // rbp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v9; // rbx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v12; // rsi
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::Render::DrawableImage *v14; // r14
  Scaleform::Render::DrawableImage *v15; // rax
  double v16; // xmm0_8
  double v17; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+38h] [rbp-30h]
  Scaleform::Render::Point<long> v22; // [rsp+80h] [rbp+18h]

  v7 = sourceRect;
  v8 = sourceBitmapData;
  v9 = this;
  if ( sourceBitmapData )
  {
    if ( sourceRect )
    {
      v12 = destPoint;
      if ( destPoint )
      {
        v14 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
        v15 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v9, v8);
        if ( v14 && v15 )
        {
          v22.x = (signed int)v12->x;
          v22.y = (signed int)v12->y;
          v16 = v7->x;
          v21.ID = (signed int)v16;
          v17 = v7->y;
          *((_DWORD *)&v21.ID + 1) = (signed int)v17;
          LODWORD(v21.Message.pNode) = (signed int)(v16 + v7->width);
          HIDWORD(v21.Message.pNode) = (signed int)(v17 + v7->height);
          Scaleform::Render::DrawableImage::CopyChannel(
            v14,
            v15,
            (Scaleform::Render::Rect<long> *)&v21,
            &v22,
            (Scaleform::Render::DrawableImage::ChannelBits)sourceChannel,
            (Scaleform::Render::DrawableImage::ChannelBits)destChannel);
          return;
        }
        Scaleform::GFx::AS3::VM::Error::Error(&v21, eArgumentError, v9->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v9->pTraits.pObject->pVM,
          v18,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v21, eNullPointerError, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v9->pTraits.pObject->pVM,
          v13,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v21, eNullPointerError, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v9->pTraits.pObject->pVM,
        v11,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v9->pTraits.pObject->pVM,
      v10,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  v19 = v21.Message.pNode;
  v20 = v21.Message.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 436
// RVA: 0x832690
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyPixels(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect, Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *alphaBitmapData, Scaleform::GFx::AS3::Instances::fl_geom::Point *alphaPoint, bool mergeAlpha)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v8; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v9; // rbp
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v10; // rbx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v13; // rsi
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::Render::DrawableImage *v15; // r14
  Scaleform::Render::DrawableImage *alphaSource; // r15
  Scaleform::Render::DrawableImage *v17; // r10
  double v18; // xmm0_8
  double v19; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::Render::Point<long> v23; // [rsp+40h] [rbp-38h]
  __int64 v24; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+50h] [rbp-28h]
  Scaleform::Render::Point<long> v26; // [rsp+90h] [rbp+18h]

  v24 = -2i64;
  v8 = sourceRect;
  v9 = sourceBitmapData;
  v10 = this;
  if ( !sourceBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_13;
  }
  if ( !sourceRect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_13;
  }
  v13 = destPoint;
  if ( !destPoint )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10->pTraits.pObject->pVM,
      v14,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_13;
  }
  v15 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
  alphaSource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                  v10,
                  alphaBitmapData);
  v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v10, v9);
  if ( !v17 || !v15 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eArgumentError, v10->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10->pTraits.pObject->pVM,
      v20,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_13:
    v21 = v25.Message.pNode;
    v22 = v25.Message.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    return;
  }
  if ( alphaPoint )
  {
    v26.x = (signed int)alphaPoint->x;
    v26.y = (signed int)alphaPoint->y;
  }
  v23.x = (signed int)v13->x;
  v23.y = (signed int)v13->y;
  v18 = v8->x;
  v25.ID = (signed int)v18;
  v19 = v8->y;
  *((_DWORD *)&v25.ID + 1) = (signed int)v19;
  LODWORD(v25.Message.pNode) = (signed int)(v18 + v8->width);
  HIDWORD(v25.Message.pNode) = (signed int)(v19 + v8->height);
  Scaleform::Render::DrawableImage::CopyPixels(
    v15,
    v17,
    (Scaleform::Render::Rect<long> *)&v25,
    &v23,
    alphaSource,
    &v26,
    mergeAlpha);
}

// File Line: 466
// RVA: 0x835310
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::dispose(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v2; // rbx
  Scaleform::Render::ImageBase *v3; // rcx

  v2 = this;
  v3 = this->pImage.pObject;
  if ( v3 )
    v3->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)result);
  v2->pImage.pObject = 0i64;
  *(_QWORD *)&v2->Width = 0i64;
}

// File Line: 475
// RVA: 0x8357B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::draw(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl::Object *source, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rdi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::AS3::VM::ErrorID v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  Scaleform::Render::Cxform *v11; // rax
  Scaleform::Render::BlendMode v12; // er12
  signed int v13; // er8
  double v14; // xmm0_8
  double v15; // xmm2_8
  Scaleform::Render::DrawableImage *v16; // r15
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::AS3::Traits *v18; // rbx
  char v19; // bl
  Scaleform::Render::DrawableImage *v20; // rax
  Scaleform::Render::Rect<long> *v21; // rdx
  bool v22; // bl
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  Scaleform::GFx::DisplayObjectBase *v29; // rcx
  Scaleform::Render::TreeNode *v30; // rbx
  Scaleform::Render::Rect<long> *v31; // rcx
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  bool v34; // zf
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+38h] [rbp-79h]
  Scaleform::GFx::AS3::Instances::fl::Object *v36; // [rsp+48h] [rbp-69h]
  __int64 v37; // [rsp+50h] [rbp-61h]
  Scaleform::Render::Matrix2x4<float> matrixa; // [rsp+58h] [rbp-59h]
  Scaleform::Render::Cxform cform; // [rsp+78h] [rbp-39h]
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *retaddr; // [rsp+118h] [rbp+67h]
  Scaleform::GFx::ASString *value; // [rsp+120h] [rbp+6Fh]
  double *v42; // [rsp+128h] [rbp+77h]
  bool v43; // [rsp+130h] [rbp+7Fh]

  v35.Message.pNode = (Scaleform::GFx::ASStringNode *)-2i64;
  v4 = source;
  v5 = this;
  if ( !source )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v35, eInvalidArgumentError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_23;
  }
  *(_OWORD *)&matrixa.M[0][0] = _xmm;
  *(__m128 *)&matrixa.M[1][0] = _xmm;
  if ( matrix )
  {
    LODWORD(v35.Message.pNode) = 0;
    LODWORD(v37) = 0;
    *(float *)&v7 = matrix->a;
    v35.ID = v7;
    v8 = matrix->b;
    *(float *)&v36 = v8;
    v9 = matrix->c;
    *((float *)&v35.ID + 1) = v9;
    v10 = matrix->d;
    *((float *)&v36 + 1) = v10;
    *((float *)&v35.Message.pNode + 1) = matrix->tx;
    *((float *)&v37 + 1) = matrix->ty;
    Scaleform::Render::Matrix2x4<float>::Append(&matrixa, (Scaleform::Render::Matrix2x4<float> *)&v35);
  }
  Scaleform::Render::Cxform::Cxform(&cform);
  if ( retaddr )
  {
    v11 = Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(
            (Scaleform::Render::Cxform *)&v35,
            retaddr);
    *(_OWORD *)&cform.M[0][0] = *(_OWORD *)&v11->M[0][0];
    *(_OWORD *)&cform.M[1][0] = *(_OWORD *)&v11->M[1][0];
  }
  v12 = (unsigned int)Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(value);
  v36 = 0i64;
  v37 = 0i64;
  if ( v42 )
  {
    v13 = (signed int)v42[10];
    v14 = v42[8] + v42[9];
    v15 = v42[7] + v42[10];
    LODWORD(v36) = (signed int)v42[9];
    HIDWORD(v36) = v13;
    LODWORD(v37) = (signed int)v14;
    HIDWORD(v37) = (signed int)v15;
  }
  v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(v5, v5);
  if ( !v16 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v35, eArgumentError, v5->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v5->pTraits.pObject->pVM,
      v17,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_23;
  }
  v35.ID = 12;
  v35.Message.pNode = 0i64;
  v36 = v4;
  v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  v18 = v5->pTraits.pObject;
  if ( !v18->pConstructor.pObject )
    v18->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->pTraits.pObject->vfptr);
  v19 = Scaleform::GFx::AS3::VM::IsOfType(
          v5->pTraits.pObject->pVM,
          (Scaleform::GFx::AS3::Value *)&v35,
          (Scaleform::GFx::AS3::ClassTraits::Traits *)v18->pConstructor.pObject->pTraits.pObject);
  Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
  if ( v19 )
  {
    v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
            v5,
            (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v4);
    v21 = (Scaleform::Render::Rect<long> *)&v36;
    if ( !v42 )
      v21 = 0i64;
    Scaleform::Render::DrawableImage::Draw(
      v16,
      (Scaleform::Render::Image *)&v20->vfptr,
      &matrixa,
      &cform,
      v12,
      v21,
      v43);
  }
  else
  {
    v35.ID = 12;
    v35.Message.pNode = 0i64;
    v36 = v4;
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
    v22 = Scaleform::GFx::AS3::VM::IsOfType(
            v5->pTraits.pObject->pVM,
            (Scaleform::GFx::AS3::Value *)&v35,
            "flash.display.DisplayObject",
            v5->pTraits.pObject->pVM->CurrentDomain.pObject);
    Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
    if ( !v22 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v35, eInvalidArgumentError, v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v32,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_23:
      v33 = v35.Message.pNode;
      v34 = v35.Message.pNode->RefCount == 1;
      --v33->RefCount;
      if ( v34 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      return;
    }
    v23 = matrixa.M[0][0];
    v24 = matrixa.M[1][0];
    v25 = matrixa.M[0][1] * 0.0;
    matrixa.M[0][0] = (float)(matrixa.M[0][0] * 0.050000001) + (float)(matrixa.M[0][1] * 0.0);
    v26 = matrixa.M[1][1] * 0.0;
    matrixa.M[1][0] = (float)(matrixa.M[1][0] * 0.050000001) + (float)(matrixa.M[1][1] * 0.0);
    v27 = v23 * 0.0;
    matrixa.M[0][1] = (float)(matrixa.M[0][1] * 0.050000001) + v27;
    v28 = v24 * 0.0;
    matrixa.M[1][1] = (float)(matrixa.M[1][1] * 0.050000001) + v28;
    matrixa.M[1][2] = 0.0;
    matrixa.M[0][2] = 0.0;
    matrixa.M[0][3] = matrixa.M[0][3] + (float)(v27 + v25);
    matrixa.M[1][3] = matrixa.M[1][3] + (float)(v28 + v26);
    v29 = *(Scaleform::GFx::DisplayObjectBase **)&v4[1].RefCount;
    if ( v29 )
    {
      v30 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v29);
      Scaleform::GFx::MovieImpl::UpdateAllRenderNodes((Scaleform::GFx::MovieImpl *)v5->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor);
      v31 = (Scaleform::Render::Rect<long> *)&v36;
      if ( !v42 )
        v31 = 0i64;
      Scaleform::Render::DrawableImage::Draw(v16, v30, &matrixa, &cform, v12, v31);
    }
  }
}

// File Line: 530
// RVA: 0x847680
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect, unsigned int color)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::Render::DrawableImage *v10; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  double v12; // xmm0_8
  double v13; // xmm1_8
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h]
  Scaleform::Render::Color colora; // [rsp+60h] [rbp+18h]

  v4 = color;
  v5 = rect;
  v6 = this;
  if ( rect )
  {
    v10 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
    if ( v10 )
    {
      colora = (Scaleform::Render::Color)v4;
      v12 = v5->x;
      v14.ID = (signed int)v12;
      v13 = v5->y;
      *((_DWORD *)&v14.ID + 1) = (signed int)v13;
      LODWORD(v14.Message.pNode) = (signed int)(v12 + v5->width);
      HIDWORD(v14.Message.pNode) = (signed int)(v13 + v5->height);
      Scaleform::Render::DrawableImage::FillRect(
        v10,
        (Scaleform::Render::Rect<long> *)&v14,
        (Scaleform::Render::Color)&colora);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  v8 = v14.Message.pNode;
  v9 = v14.Message.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 544
// RVA: 0x8486B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, int x, int y, unsigned int color)
{
  int v5; // edi
  int v6; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Color v12; // [rsp+20h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h]
  __int64 v14; // [rsp+38h] [rbp-10h]

  v14 = -2i64;
  v5 = y;
  v6 = x;
  v7 = this;
  v8 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
  if ( v8 )
  {
    v12 = (Scaleform::Render::Color)color;
    v13.ID = v6;
    *((_DWORD *)&v13.ID + 1) = v5;
    Scaleform::Render::DrawableImage::FloodFill(
      v8,
      (Scaleform::Render::Point<long> *)&v13,
      (Scaleform::Render::Color)&v12);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v13.Message.pNode;
    v11 = v13.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 555
// RVA: 0x849F30
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::generateFilterRect(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect, Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *filter)
{
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v6; // r14
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  Scaleform::GFx::AS3::VM::Error v24; // [rsp+30h] [rbp-C8h]
  Scaleform::Render::Rect<float> resulta; // [rsp+40h] [rbp-B8h]
  __int64 v26; // [rsp+50h] [rbp-A8h]
  char ptr; // [rsp+60h] [rbp-98h]
  Scaleform::GFx::AS3::Value v28; // [rsp+78h] [rbp-80h]
  Scaleform::GFx::AS3::Value v29; // [rsp+98h] [rbp-60h]
  Scaleform::GFx::AS3::Value v30; // [rsp+B8h] [rbp-40h]

  v26 = -2i64;
  v4 = filter;
  v5 = sourceRect;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)result;
  v7 = this;
  if ( !sourceRect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v8, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  if ( !filter )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v7->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  if ( !Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v7->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v9 = v24.Message.pNode;
    v10 = v24.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    return;
  }
  resulta = 0i64;
  v13 = (float)(signed int)(v5->height + v5->y) * 20.0;
  v14 = (float)(signed int)(v5->width + v5->x) * 20.0;
  v15 = (float)(signed int)v5->y * 20.0;
  v24.ID = (signed int)(float)((float)(signed int)v5->x * 20.0);
  *((_DWORD *)&v24.ID + 1) = (signed int)v15;
  LODWORD(v24.Message.pNode) = (signed int)v14;
  HIDWORD(v24.Message.pNode) = (signed int)v13;
  Scaleform::Render::DrawableImage::CalcFilterRect(
    &resulta,
    (Scaleform::Render::Rect<long> *)&v24,
    v4->FilterData.pObject);
  `eh vector constructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  v16 = resulta.x1 * 0.050000001;
  if ( (float)(resulta.x1 * 0.050000001) <= 0.0 )
    v17 = v16 - 0.5;
  else
    v17 = v16 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)&ptr, (double)(signed int)v17);
  v18 = resulta.y1 * 0.050000001;
  if ( (float)(resulta.y1 * 0.050000001) <= 0.0 )
    v19 = v18 - 0.5;
  else
    v19 = v18 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v28, (double)(signed int)v19);
  v20 = (float)(resulta.x2 - resulta.x1) * 0.050000001;
  if ( v20 <= 0.0 )
    v21 = v20 - 0.5;
  else
    v21 = v20 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v29, (double)(signed int)v21);
  v22 = (float)(resulta.y2 - resulta.y1) * 0.050000001;
  if ( v22 <= 0.0 )
    v23 = v22 - 0.5;
  else
    v23 = v22 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v30, (double)(signed int)v23);
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)v7->pTraits.pObject->pVM,
    v6,
    v7->pTraits.pObject->pVM[1].ExceptionObj.value.VS._1.VObj,
    4u,
    (Scaleform::GFx::AS3::Value *)&ptr);
  `eh vector destructor iterator'(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 582
// RVA: 0x84AF80
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getColorBoundsRect(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result, unsigned int mask, unsigned int color)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *v6; // r14
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Traits *v12; // rax
  Scaleform::GFx::AS3::CheckResult v13[8]; // [rsp+28h] [rbp-61h]
  Scaleform::Render::Rect<long> resulta; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+40h] [rbp-49h]
  __int64 v16; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-31h]
  int v18; // [rsp+78h] [rbp-11h]
  __int64 v19; // [rsp+80h] [rbp-9h]
  int v20; // [rsp+88h] [rbp-1h]
  int v21; // [rsp+98h] [rbp+Fh]
  __int64 v22; // [rsp+A0h] [rbp+17h]
  int v23; // [rsp+A8h] [rbp+1Fh]
  int v24; // [rsp+B8h] [rbp+2Fh]
  __int64 v25; // [rsp+C0h] [rbp+37h]
  int v26; // [rsp+C8h] [rbp+3Fh]
  bool v27; // [rsp+108h] [rbp+7Fh]

  v16 = -2i64;
  v4 = color;
  v5 = mask;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)result;
  v7 = this;
  v8 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
  if ( v8 )
  {
    Scaleform::Render::DrawableImage::GetColorBoundsRect(v8, &resulta, v5, v4, v27);
    argv.Flags = 2;
    argv.Bonus.pWeakProxy = 0i64;
    argv.value.VS._1.VInt = resulta.x1;
    v18 = 2;
    v19 = 0i64;
    v20 = resulta.y1;
    v21 = 2;
    v22 = 0i64;
    v23 = resulta.x2 - resulta.x1;
    v24 = 2;
    v25 = 0i64;
    v26 = resulta.y2 - resulta.y1;
    v12 = v7->pTraits.pObject;
    *(_QWORD *)&v13[0].Result = &argv;
    v11 = Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
            v12->pVM,
            v13,
            v6,
            "flash.geom.Rectangle",
            4u,
            &argv)->Result == 0;
    `eh vector destructor iterator'(&argv, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v15.Message.pNode;
    v11 = v15.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 596
// RVA: 0x84C2C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, unsigned int *result, int x, int y)
{
  int v4; // edi
  int v5; // esi
  Scaleform::Render::Color *v6; // r14
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Color resulta; // [rsp+20h] [rbp-28h]
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h]

  v13 = -2i64;
  v4 = y;
  v5 = x;
  v6 = (Scaleform::Render::Color *)result;
  v7 = this;
  v8 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( v8 )
  {
    *v6 = *Scaleform::Render::DrawableImage::GetPixel(v8, &resulta, v5, v4);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v14.Message.pNode;
    v11 = v14.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 606
// RVA: 0x84C210
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel32(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, unsigned int *result, int x, int y)
{
  int v4; // edi
  int v5; // esi
  Scaleform::Render::Color *v6; // r14
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Color resulta; // [rsp+20h] [rbp-28h]
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h]

  v13 = -2i64;
  v4 = y;
  v5 = x;
  v6 = (Scaleform::Render::Color *)result;
  v7 = this;
  v8 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( v8 )
  {
    *v6 = *Scaleform::Render::DrawableImage::GetPixel32(v8, &resulta, v5, v4);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v14.Message.pNode;
    v11 = v14.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 616
// RVA: 0x84C370
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixels(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *v4; // r14
  Scaleform::GFx::AS3::Traits *v5; // rax
  Scaleform::GFx::AS3::VM *v6; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::Render::DrawableImage *v10; // rsi
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  double v12; // xmm2_8
  double v13; // xmm0_8
  signed int v14; // er8
  double v15; // xmm2_8
  __int64 v16; // rax
  Scaleform::Render::Rect<long> sourceRect; // [rsp+28h] [rbp-40h]
  Scaleform::Render::DIPixelProvider provider; // [rsp+38h] [rbp-30h]
  __int64 v19; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+48h] [rbp-20h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> resulta; // [rsp+70h] [rbp+8h]

  v3 = rect;
  v4 = result;
  v5 = this->pTraits.pObject;
  v6 = v5->pVM;
  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, v5->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v10 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( !v10 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eArgumentError, v6);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v11, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v8 = v20.Message.pNode;
    v9 = v20.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return;
  }
  v12 = v3->height;
  v13 = v3->width;
  sourceRect.x1 = (signed int)v3->x;
  v14 = (signed int)v3->y;
  sourceRect.y1 = (signed int)v3->y;
  sourceRect.x2 = (signed int)(v13 + v3->x);
  v15 = v12 + v3->y;
  sourceRect.y2 = (signed int)v15;
  if ( sourceRect.x2 != sourceRect.x1 && (signed int)v15 != v14 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
      &resulta,
      (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)v6->TraitsByteArray.pObject->ITraits.pObject);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)resulta.pV);
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
      v4->pObject,
      4 * (sourceRect.y2 - sourceRect.y1) * (sourceRect.x2 - sourceRect.x1));
    v16 = (__int64)v4->pObject;
    provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable';
    v19 = v16;
    Scaleform::Render::DrawableImage::GetPixels(v10, &provider, &sourceRect);
  }
}

// File Line: 642
// RVA: 0x84D160
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getVector(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rdi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::Render::DrawableImage *v9; // rbp
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  double v11; // xmm2_8
  double v12; // xmm0_8
  signed int v13; // er8
  double v14; // xmm2_8
  Scaleform::GFx::AS3::CheckResult *v15; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> v16; // rcx
  unsigned int v17; // eax
  __int64 v18; // rax
  Scaleform::Render::Rect<long> sourceRect; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+48h] [rbp-30h]
  Scaleform::Render::DIPixelProvider provider; // [rsp+58h] [rbp-20h]
  int v22; // [rsp+60h] [rbp-18h]
  __int64 v23; // [rsp+68h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+90h] [rbp+18h]

  v3 = rect;
  v4 = result;
  v5 = this;
  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v9 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( !v9 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eArgumentError, v5->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v5->pTraits.pObject->pVM,
      v10,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v7 = v20.Message.pNode;
    v8 = v20.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  v11 = v3->height;
  v12 = v3->width;
  sourceRect.x1 = (signed int)v3->x;
  v13 = (signed int)v3->y;
  sourceRect.y1 = (signed int)v3->y;
  sourceRect.x2 = (signed int)(v12 + v3->x);
  v14 = v11 + v3->y;
  sourceRect.y2 = (signed int)v14;
  if ( sourceRect.x2 != sourceRect.x1 && (signed int)v14 != v13 )
  {
    v15 = Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
            v5->pTraits.pObject->pVM,
            &resulta,
            v4,
            "Vector.<uint>",
            0,
            0i64);
    v16.pObject = v4->pObject;
    if ( v15->Result )
    {
      Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthSet(
        v16.pObject,
        4 * (sourceRect.y2 - sourceRect.y1) * (sourceRect.x2 - sourceRect.x1));
      v18 = (__int64)v4->pObject;
      provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable';
      v22 = 0;
      v23 = v18;
      Scaleform::Render::DrawableImage::GetPixels(v9, &provider, &sourceRect);
    }
    else if ( v16.pObject )
    {
      if ( (_QWORD)v16.pObject & 1 )
      {
        v4->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v16.pObject - 1);
      }
      else
      {
        v17 = v16.pObject->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v16.pObject->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16.pObject->vfptr);
        }
      }
      v4->pObject = 0i64;
    }
  }
}

// File Line: 667
// RVA: 0x84EA40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::hitTest(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, bool *result, Scaleform::GFx::AS3::Instances::fl_geom::Point *firstPoint, unsigned int firstAlphaThreshold, Scaleform::GFx::AS3::Value *secondObject, Scaleform::GFx::AS3::Instances::fl_geom::Point *secondBitmapDataPoint, unsigned int secondAlphaThreshold)
{
  unsigned int firstThreshold; // esi
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v8; // rdi
  bool *v9; // r15
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v10; // rbx
  Scaleform::Render::DrawableImage *v11; // r14
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  double *v13; // rax
  double v14; // xmm3_8
  double v15; // xmm2_8
  double v16; // xmm1_8
  double v17; // xmm0_8
  long double v18; // rax
  signed int v19; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v20; // rcx
  Scaleform::GFx::ImageResource *v21; // rax
  Scaleform::Render::ImageBase *v22; // rax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  bool v25; // zf
  Scaleform::Render::Point<long> secondPoint; // [rsp+30h] [rbp-30h]
  Scaleform::Render::Point<long> firstPointa; // [rsp+38h] [rbp-28h]
  __int64 v28; // [rsp+40h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+48h] [rbp-18h]

  v28 = -2i64;
  firstThreshold = firstAlphaThreshold;
  v8 = firstPoint;
  v9 = result;
  v10 = this;
  v11 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( !v11 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v29, eArgumentError, v10->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v10->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_21;
  }
  firstPointa.x = (signed int)v8->x;
  firstPointa.y = (signed int)v8->y;
  if ( (unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                          v10->pTraits.pObject->pVM,
                          secondObject,
                          "flash.geom.Rectangle",
                          v10->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    v13 = (double *)secondObject->value.VS._1.VStr;
    v14 = v13[10];
    v15 = v13[7];
    v16 = v13[9];
    v17 = v13[8];
    v29.ID = (signed int)v16;
    *((_DWORD *)&v29.ID + 1) = (signed int)v14;
    LODWORD(v29.Message.pNode) = (signed int)(v17 + v16);
    HIDWORD(v29.Message.pNode) = (signed int)(v15 + v14);
LABEL_5:
    *v9 = Scaleform::Render::DrawableImage::HitTest(
            v11,
            &firstPointa,
            (Scaleform::Render::Rect<long> *)&v29,
            firstThreshold);
    return;
  }
  if ( (unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                          v10->pTraits.pObject->pVM,
                          secondObject,
                          "flash.geom.Point",
                          v10->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    v18 = secondObject->value.VNumber;
    v19 = (signed int)*(double *)(*(_QWORD *)&v18 + 64i64);
    v29.ID = (signed int)*(double *)(*(_QWORD *)&v18 + 56i64);
    *((_DWORD *)&v29.ID + 1) = v19;
    LODWORD(v29.Message.pNode) = v29.ID + 1;
    HIDWORD(v29.Message.pNode) = v19 + 1;
    if ( firstThreshold < 1 )
      firstThreshold = 1;
    goto LABEL_5;
  }
  secondPoint = 0i64;
  if ( !(unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                           v10->pTraits.pObject->pVM,
                           secondObject,
                           "flash.display.Bitmap",
                           v10->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    if ( !(unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                             v10->pTraits.pObject->pVM,
                             secondObject,
                             "flash.display.BitmapData",
                             v10->pTraits.pObject->pVM->CurrentDomain.pObject) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v29, eInvalidArgumentError, v10->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v10->pTraits.pObject->pVM,
        v23,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_21:
      v24 = v29.Message.pNode;
      v25 = v29.Message.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v25 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      return;
    }
    if ( secondBitmapDataPoint )
    {
      secondPoint.x = (signed int)secondBitmapDataPoint->x;
      secondPoint.y = (signed int)secondBitmapDataPoint->y;
    }
    v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
            v10,
            (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)secondObject->value.VS._1.VStr);
LABEL_19:
    *v9 = Scaleform::Render::DrawableImage::HitTest(
            v11,
            v22,
            &firstPointa,
            &secondPoint,
            firstThreshold,
            secondAlphaThreshold);
    return;
  }
  v20 = *(Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)(*(_QWORD *)&secondObject->value.VNumber + 104i64);
  if ( v20 )
  {
    v21 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(v20);
    if ( v21 )
    {
      v22 = v21->pImage;
      if ( v22 )
        goto LABEL_19;
    }
  }
}

// File Line: 724
// RVA: 0x84E190
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *hRect)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v3; // r13
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // r14
  Scaleform::Render::Rect<long> *v5; // rbx
  double v6; // xmm3_8
  double v7; // xmm1_8
  long double v8; // xmm0_8
  long double v9; // xmm2_8
  Scaleform::Render::DrawableImage *v10; // rax
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  unsigned int v14; // er12
  __int64 v15; // r15
  unsigned int v16; // edi
  unsigned int *v17; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rdx
  __int64 v19; // rcx
  unsigned int v20; // eax
  bool v21; // bl
  int v22; // ecx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v28; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v29; // rcx
  long double v30; // rdx
  bool v31; // bl
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v32; // rcx
  unsigned int v33; // eax
  char v34; // [rsp+30h] [rbp-D0h]
  int v35; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v36; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value v37; // [rsp+48h] [rbp-B8h]
  unsigned int v38; // [rsp+68h] [rbp-98h]
  _DWORD *v39; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASStringNode *v40; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v41; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::Value v; // [rsp+88h] [rbp-78h]
  __int64 v43; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::AS3::Value::V2U v44; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::AS3::Value v45; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v46; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS3::Multiname v47; // [rsp+F0h] [rbp-10h]
  __int64 v48; // [rsp+120h] [rbp+20h]
  __int64 v49; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::AS3::Value::VU v50; // [rsp+130h] [rbp+30h]
  __int64 v51; // [rsp+140h] [rbp+40h]
  __int64 v52; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::AS3::Value::VU v53; // [rsp+150h] [rbp+50h]
  __int64 ptr[4]; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::AS3::Value v55; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::AS3::Value argv; // [rsp+1A0h] [rbp+A0h]
  __int64 v57; // [rsp+1C0h] [rbp+C0h]
  unsigned int colors[4][256]; // [rsp+1D0h] [rbp+D0h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+1220h] [rbp+1120h]
  char v60; // [rsp+1228h] [rbp+1128h]

  v57 = -2i64;
  v3 = result;
  v4 = this;
  v43 = 0i64;
  v44.VObj = 0i64;
  v5 = 0i64;
  if ( hRect )
  {
    v6 = hRect->y;
    v7 = hRect->x;
    v8 = hRect->width + v7;
    v9 = hRect->height + v6;
    LODWORD(v43) = (signed int)v7;
    HIDWORD(v43) = (signed int)v6;
    LODWORD(v44.VObj) = (signed int)v8;
    HIDWORD(v44.pTraits) = (signed int)v9;
    v5 = (Scaleform::Render::Rect<long> *)&v43;
  }
  v10 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( v10 )
  {
    Scaleform::Render::DrawableImage::Histogram(v10, v5, colors);
    argv.Flags = 3;
    argv.Bonus.pWeakProxy = 0i64;
    argv.value.VS._1.VInt = 4;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::VM::ConstructBuiltinValue(
           v4->pTraits.pObject->pVM,
           &resulta,
           &v,
           "Vector.<Vector.<Number>>",
           1u,
           &argv)->Result )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v.value.VS._1.VStr);
      `eh vector constructor iterator'(
        ptr,
        8ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure');
      v14 = 0;
      v15 = 0i64;
      while ( 2 )
      {
        v55.Flags = 3;
        v55.Bonus.pWeakProxy = 0i64;
        v55.value.VS._1.VInt = 256;
        if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
               v4->pTraits.pObject->pVM,
               &resulta,
               (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&ptr[v14],
               "Vector.<Number>",
               1u,
               &v55)->Result )
        {
          v16 = 0;
          v17 = colors[v15];
          do
          {
            LODWORD(v48) = 3;
            v49 = 0i64;
            v50.VS._1.VInt = v16;
            v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->pTraits.pObject->pVM->PublicNamespace.pObject->vfptr;
            v35 = 0;
            v36 = v18;
            if ( v18 )
              v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
            __asm { prefetcht1 byte ptr [rbp+1100h+var_10E0]; Prefetch to all cache levels }
            *(_QWORD *)&v37.Flags = v48;
            v37.Bonus.pWeakProxy = 0i64;
            v37.value = v50;
            v19 = ptr[v15];
            v20 = *v17;
            v38 = 3;
            v39 = 0i64;
            LODWORD(v40) = v20;
            v21 = *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, int *, unsigned int *))(*(_QWORD *)v19 + 24i64))(
                              v19,
                              &v60,
                              &v35,
                              &v38) == 0;
            v22 = v38 & 0x1F;
            if ( v22 > 9 )
            {
              if ( (v38 >> 9) & 1 )
              {
                v13 = (*v39)-- == 1;
                if ( v13 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v39 = 0i64;
                v40 = 0i64;
                v41 = 0i64;
                v38 &= 0xFFFFFDE0;
              }
              else
              {
                switch ( v22 )
                {
                  case 10:
                    v23 = v40;
                    v13 = v40->RefCount == 1;
                    --v23->RefCount;
                    if ( v13 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
                    break;
                  case 11:
                  case 12:
                  case 13:
                  case 14:
                  case 15:
                    v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v40;
                    if ( !((unsigned __int8)v40 & 1) )
                      goto LABEL_24;
                    v40 = (Scaleform::GFx::ASStringNode *)((char *)v40 - 1);
                    break;
                  case 16:
                  case 17:
                    v24 = v41;
                    if ( (unsigned __int8)v41 & 1 )
                    {
                      v41 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v41 - 1);
                    }
                    else
                    {
LABEL_24:
                      if ( v24 )
                      {
                        v25 = v24->RefCount;
                        if ( v25 & 0x3FFFFF )
                        {
                          v24->RefCount = v25 - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
                        }
                      }
                    }
                    break;
                  default:
                    break;
                }
              }
            }
            if ( v21 )
            {
              if ( (v37.Flags & 0x1F) > 9 )
              {
                if ( (v37.Flags >> 9) & 1 )
                {
                  v13 = v37.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v13 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v37.Bonus.pWeakProxy = 0i64;
                  v37.value = 0ui64;
                  v37.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v37);
                }
              }
              v32 = v36;
              if ( v36 )
              {
                if ( (unsigned __int8)v36 & 1 )
                {
                  v36 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v36 - 1);
                }
                else
                {
                  v33 = v36->RefCount;
                  if ( v33 & 0x3FFFFF )
                  {
                    v36->RefCount = v33 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v32);
                  }
                }
              }
              goto LABEL_69;
            }
            if ( (v37.Flags & 0x1F) > 9 )
            {
              if ( (v37.Flags >> 9) & 1 )
              {
                v13 = v37.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v13 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v37.Bonus.pWeakProxy = 0i64;
                v37.value = 0ui64;
                v37.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v37);
              }
            }
            v26 = v36;
            if ( v36 )
            {
              if ( (unsigned __int8)v36 & 1 )
              {
                v36 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v36 - 1);
              }
              else
              {
                v27 = v36->RefCount;
                if ( v27 & 0x3FFFFF )
                {
                  v36->RefCount = v27 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
                }
              }
            }
            ++v16;
            ++v17;
          }
          while ( v16 < 0x100 );
          LODWORD(v51) = 3;
          v52 = 0i64;
          v53.VS._1.VInt = v14;
          v28 = (Scaleform::GFx::AS3::GASRefCountBase *)&v4->pTraits.pObject->pVM->PublicNamespace.pObject->vfptr;
          v47.Kind = 0;
          v47.Obj.pObject = v28;
          if ( v28 )
            v28->RefCount = (v28->RefCount + 1) & 0x8FBFFFFF;
          __asm { prefetcht1 byte ptr [rbp+1100h+var_10C0]; Prefetch to all cache levels }
          *(_QWORD *)&v47.Name.Flags = v51;
          v47.Name.Bonus.pWeakProxy = 0i64;
          v47.Name.value = v53;
          v29.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pObject;
          v45.Flags = 0;
          v45.Bonus.pWeakProxy = 0i64;
          v30 = *(double *)&ptr[v15];
          v45.Flags = 12;
          v45.value.VNumber = v30;
          v45.value.VS._2 = v44;
          if ( v30 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v30 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v30 + 32i64) + 1) & 0x8FBFFFFF;
          v31 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v29.pObject->vfptr[1].ForEachChild_GC)(
                            v29,
                            &v34,
                            &v47,
                            &v45) == 0;
          if ( (v45.Flags & 0x1F) > 9 )
          {
            if ( (v45.Flags >> 9) & 1 )
            {
              v13 = v45.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v45.Bonus.pWeakProxy = 0i64;
              v45.value = 0ui64;
              v45.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v45);
            }
          }
          Scaleform::GFx::AS3::Multiname::~Multiname(&v47);
          if ( v31 )
            break;
          `eh vector destructor iterator'(
            &v55,
            0x20ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
          ++v14;
          ++v15;
          if ( v14 < 4 )
            continue;
          `eh vector destructor iterator'(
            ptr,
            8ui64,
            4,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
          if ( (v.Flags & 0x1F) <= 9 )
            goto LABEL_77;
          if ( !((v.Flags >> 9) & 1) )
            goto LABEL_76;
          v13 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v.Bonus.pWeakProxy = 0i64;
          v.value = 0ui64;
          goto LABEL_75;
        }
        break;
      }
LABEL_69:
      `eh vector destructor iterator'(
        &v55,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      `eh vector destructor iterator'(
        ptr,
        8ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
    }
    if ( (v.Flags & 0x1F) <= 9 )
    {
LABEL_77:
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      return;
    }
    if ( !((v.Flags >> 9) & 1) )
    {
LABEL_76:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      goto LABEL_77;
    }
    v13 = v.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v13 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v.Bonus.pWeakProxy = 0i64;
    v.value = 0ui64;
LABEL_75:
    v.Flags &= 0xFFFFFDE0;
    goto LABEL_77;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v46, eArgumentError, v4->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4->pTraits.pObject->pVM, v11, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  v12 = v46.Message.pNode;
  v13 = v46.Message.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 772
// RVA: 0x854280
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rsi
  long double v6; // rbx
  double *v7; // r15
  long double v8; // r12
  Scaleform::Render::DrawableImage *v9; // rbp
  Scaleform::Render::DrawableImage *v10; // r14
  unsigned int *v11; // rbx
  Scaleform::GFx::AS3::Value *v12; // rdi
  signed __int64 v13; // rsi
  double v14; // xmm0_8
  double v15; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::Render::Point<long> destPoint; // [rsp+40h] [rbp-58h]
  __int64 v20; // [rsp+48h] [rbp-50h]
  unsigned int redMult; // [rsp+50h] [rbp-48h]
  unsigned int greenMult; // [rsp+54h] [rbp-44h]
  unsigned int blueMult; // [rsp+58h] [rbp-40h]
  unsigned int alphaMult; // [rsp+5Ch] [rbp-3Ch]
  Scaleform::Render::Rect<long> sourceRect; // [rsp+60h] [rbp-38h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+18h]

  if ( argc == 7 )
  {
    v20 = -2i64;
    v4 = argv;
    v5 = this;
    v6 = argv->value.VNumber;
    v7 = (double *)argv[1].value.VS._1.VStr;
    v8 = argv[2].value.VNumber;
    v9 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                               this,
                                               this);
    v10 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                v5,
                                                *(Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)&v6);
    if ( v10 && v9 )
    {
      v11 = &redMult;
      v12 = v4 + 3;
      v13 = 4i64;
      do
      {
        Scaleform::GFx::AS3::Value::Convert2UInt32(v12, &resulta, v11);
        ++v11;
        ++v12;
        --v13;
      }
      while ( v13 );
      destPoint.x = (signed int)*(double *)(*(_QWORD *)&v8 + 56i64);
      destPoint.y = (signed int)*(double *)(*(_QWORD *)&v8 + 64i64);
      v14 = v7[9];
      sourceRect.x1 = (signed int)v14;
      v15 = v7[10];
      sourceRect.y1 = (signed int)v15;
      sourceRect.x2 = (signed int)(v14 + v7[8]);
      sourceRect.y2 = (signed int)(v15 + v7[7]);
      Scaleform::Render::DrawableImage::Merge(v9, v10, &sourceRect, &destPoint, redMult, greenMult, blueMult, alphaMult);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&sourceRect,
        eArgumentError,
        v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v16,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v17 = *(Scaleform::GFx::ASStringNode **)&sourceRect.x2;
      v18 = *(_DWORD *)(*(_QWORD *)&sourceRect.x2 + 24i64) == 1;
      --v17->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
}

// File Line: 798
// RVA: 0x8554C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, int randomSeed, unsigned int low, unsigned int high, unsigned int channelOptions, bool grayScale)
{
  unsigned int v7; // edi
  int v8; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v9; // rbx
  Scaleform::Render::DrawableImage *v10; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+38h] [rbp-20h]

  v7 = low;
  v8 = randomSeed;
  v9 = this;
  v10 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( v10 )
  {
    Scaleform::Render::DrawableImage::Noise(v10, v8, v7, high, channelOptions, grayScale);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v9->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v9->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v12 = v14.Message.pNode;
    v13 = v14.Message.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
}

// File Line: 809
// RVA: 0x855B80
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // r13
  long double v6; // rax
  long double v7; // rdx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  unsigned int v11; // edi
  unsigned int v12; // er12
  __int64 v13; // rbx
  long double v14; // rdx
  Scaleform::GFx::AS3::Impl::SparseArray *v15; // r14
  unsigned __int64 v16; // rsi
  signed __int64 v17; // rbp
  Scaleform::GFx::AS3::Value *v18; // rax
  Scaleform::Render::DrawableImage *v19; // rbx
  Scaleform::Render::DrawableImage *v20; // rax
  double *v21; // r8
  double v22; // xmm0_8
  double v23; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::AS3::VM::Error v27; // [rsp+30h] [rbp-1098h]
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData; // [rsp+40h] [rbp-1088h]
  Scaleform::GFx::AS3::Value::V1U v29; // [rsp+48h] [rbp-1080h]
  unsigned int *channels; // [rsp+50h] [rbp-1078h]
  __int64 v31; // [rsp+70h] [rbp-1058h]
  char v32[4096]; // [rsp+A0h] [rbp-1028h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+10E0h] [rbp+18h]

  if ( argc >= 3 )
  {
    v31 = -2i64;
    v4 = argv;
    v5 = this;
    sourceBitmapData = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VStr;
    v6 = argv[1].value.VNumber;
    *(long double *)&v27.ID = argv[1].value.VNumber;
    v7 = argv[2].value.VNumber;
    v29 = *(Scaleform::GFx::AS3::Value::V1U *)&argv[2].value.VNumber;
    if ( sourceBitmapData )
    {
      if ( v6 == 0.0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v5->pTraits.pObject->pVM,
          v9,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
      else if ( v7 == 0.0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v5->pTraits.pObject->pVM,
          v10,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
      else
      {
        v11 = 0;
        v12 = argc - 3;
        v13 = 0i64;
        do
        {
          if ( v11 < v12 )
          {
            v14 = v4[v11 + 3].value.VNumber;
            if ( v14 == 0.0 )
            {
              (&channels)[v13] = 0i64;
            }
            else
            {
              (&channels)[v13] = (unsigned int *)&v32[1024 * (unsigned __int64)v11];
              v15 = (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v14 + 56i64);
              v16 = 0i64;
              v17 = 256i64;
              do
              {
                v18 = Scaleform::GFx::AS3::Impl::SparseArray::At(v15, v16);
                Scaleform::GFx::AS3::Value::Convert2UInt32(v18, &resulta, &(&channels)[v13][v16++]);
                --v17;
              }
              while ( v17 );
            }
          }
          else
          {
            (&channels)[v13] = 0i64;
          }
          ++v11;
          ++v13;
        }
        while ( v11 < 4 );
        v19 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                    v5,
                                                    v5);
        v20 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                    v5,
                                                    sourceBitmapData);
        if ( v19 && v20 )
        {
          LODWORD(sourceBitmapData) = (signed int)*(double *)&v29.VStr[1].pLower;
          HIDWORD(sourceBitmapData) = (signed int)*(double *)&v29.VStr[1].RefCount;
          v21 = *(double **)&v27.ID;
          v22 = *(double *)(*(_QWORD *)&v27.ID + 72i64);
          v27.ID = (signed int)v22;
          v23 = v21[10];
          *((_DWORD *)&v27.ID + 1) = (signed int)v23;
          LODWORD(v27.Message.pNode) = (signed int)(v22 + v21[8]);
          HIDWORD(v27.Message.pNode) = (signed int)(v23 + v21[7]);
          Scaleform::Render::DrawableImage::PaletteMap(
            v19,
            v20,
            (Scaleform::Render::Rect<long> *)&v27,
            (Scaleform::Render::Point<long> *)&sourceBitmapData,
            &channels);
          return;
        }
        Scaleform::GFx::AS3::VM::Error::Error(&v27, eArgumentError, v5->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v5->pTraits.pObject->pVM,
          v24,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v8,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    v25 = v27.Message.pNode;
    v26 = v27.Message.pNode->RefCount == 1;
    --v25->RefCount;
    if ( v26 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  }
}

// File Line: 866
// RVA: 0x8564B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // r13
  signed __int64 offsetCount; // r12
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  bool v9; // zf
  signed int v10; // ebx
  bool v11; // al
  char stitch; // r14
  char fractal; // r15
  bool v14; // al
  float *offsets; // rbx
  Scaleform::GFx::AS3::VM::ErrorID v16; // ebx
  Scaleform::GFx::AS3::WeakProxy *v17; // r14
  int v18; // esi
  long double v19; // rcx
  bool v20; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v21; // rcx
  unsigned __int64 v22; // r14
  char *v23; // rsi
  __int64 v24; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v25; // r12
  long double v26; // rdi
  bool v27; // bl
  Scaleform::Render::DrawableImage *v28; // rcx
  Scaleform::GFx::AS3::VM::Error *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::AS3::CheckResult grayScale[8]; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::AS3::CheckResult randomSeed[8]; // [rsp+68h] [rbp-70h]
  unsigned int channelMask[2]; // [rsp+70h] [rbp-68h]
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+78h] [rbp-60h]
  Scaleform::GFx::AS3::Value v; // [rsp+90h] [rbp-48h]
  __int64 v36; // [rsp+B0h] [rbp-28h]
  char Dst; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+2F8h] [rbp+220h]

  v36 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = this;
  LODWORD(offsetCount) = 0;
  *(_DWORD *)&grayScale[4].Result = 0;
  if ( argc < 6 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v34, eWrongArgumentCountError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v8, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v9 = v30->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
    return;
  }
  *(long double *)&v34.Message.pNode = DOUBLE_1_0;
  *(long double *)&v34.ID = DOUBLE_1_0;
  v10 = 1;
  channelMask[0] = 1;
  *(_DWORD *)&randomSeed[4].Result = 0;
  *(_DWORD *)&grayScale[4].Result = 1;
  v11 = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &resulta, (long double *)&v34.Message)->Result )
  {
    v10 = 3;
    *(_DWORD *)&grayScale[4].Result = 3;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(v4 + 1, &grayScale[1], (long double *)&v34)->Result )
    {
      v10 = 7;
      *(_DWORD *)&grayScale[4].Result = 7;
      if ( Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 2, grayScale, channelMask)->Result )
      {
        v10 = 15;
        *(_DWORD *)&grayScale[4].Result = 15;
        if ( Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 3, randomSeed, (unsigned int *)&randomSeed[4])->Result )
          v11 = 0;
      }
    }
  }
  if ( v10 & 8 )
  {
    v10 &= 0xFFFFFFF7;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( v10 & 4 )
  {
    v10 &= 0xFFFFFFFB;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( v10 & 2 )
  {
    v10 &= 0xFFFFFFFD;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( v10 & 1 )
  {
    v10 &= 0xFFFFFFFE;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( v11 )
    return;
  stitch = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 4);
  resulta.Result = stitch;
  fractal = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 5);
  grayScale[0].Result = fractal;
  channelMask[1] = 7;
  v14 = 0;
  if ( v5 >= 7 )
  {
    v10 |= 0x10u;
    *(_DWORD *)&grayScale[4].Result = v10;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 6, randomSeed, &channelMask[1])->Result )
      v14 = 1;
  }
  if ( v10 & 0x10 )
    *(_DWORD *)&grayScale[4].Result = v10 & 0xFFFFFFEF;
  if ( v14 )
    return;
  if ( v5 < 8 )
    grayScale[1].Result = 0;
  else
    grayScale[1].Result = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 7);
  offsets = 0i64;
  if ( v5 < 9 || !*(_QWORD *)&v4[8].value.VNumber )
  {
LABEL_62:
    v28 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                v6,
                                                v6);
    if ( v28 )
    {
      Scaleform::Render::DrawableImage::PerlinNoise(
        v28,
        *(double *)&v34.Message.pNode,
        *(double *)&v34.ID,
        channelMask[0],
        *(unsigned int *)&randomSeed[4].Result,
        stitch,
        fractal,
        channelMask[1],
        grayScale[1].Result,
        offsets,
        offsetCount);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v34, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v29,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  memset(&Dst, 0, 0x200ui64);
  *(_QWORD *)channelMask = &Dst;
  v16 = v4[8].Flags;
  v34.ID = v16;
  v17 = v4[8].Bonus.pWeakProxy;
  v30 = (Scaleform::GFx::ASStringNode *)v4[8].Bonus.pWeakProxy;
  *(long double *)&grayScale[0].Result = v4[8].value.VNumber;
  *(_QWORD *)&randomSeed[0].Result = v4[8].value.VS._2.VObj;
  v18 = v16 & 0x1F;
  if ( v18 > 9 )
  {
    if ( ((unsigned int)v16 >> 9) & 1 )
    {
      ++v17->RefCount;
      goto LABEL_44;
    }
    if ( v18 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v4[8].value.VNumber + 24i64);
    }
    else
    {
      if ( v18 <= 10 )
        goto LABEL_44;
      if ( v18 <= 15 )
      {
        v19 = v4[8].value.VNumber;
      }
      else
      {
        if ( v18 > 17 )
          goto LABEL_44;
        v19 = *(double *)&v4[8].value.VS._2.VObj;
      }
      if ( v19 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v19 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v19 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
LABEL_44:
  v20 = (unsigned __int8)Scaleform::GFx::AS3::VM::IsOfType(
                           v6->pTraits.pObject->pVM,
                           (Scaleform::GFx::AS3::Value *)&v34,
                           "Array",
                           v6->pTraits.pObject->pVM->CurrentDomain.pObject) == 0;
  if ( v18 > 9 )
  {
    if ( ((unsigned int)v16 >> 9) & 1 )
    {
      v9 = v17->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17);
      v30 = 0i64;
      *(_QWORD *)&grayScale[0].Result = 0i64;
      *(_QWORD *)&randomSeed[0].Result = 0i64;
      v34.ID = v16 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v34);
    }
  }
  if ( !v20 )
  {
    v21 = (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v4[8].value.VNumber + 56i64);
    offsetCount = v21->Length;
    if ( (unsigned int)v21->Length > 0x80 )
      offsetCount = 128i64;
    *(_QWORD *)&v34.ID = offsetCount;
    if ( (_DWORD)offsetCount )
    {
      v22 = 0i64;
      v23 = &Dst;
      v24 = (unsigned int)offsetCount;
      v25 = v21;
      do
      {
        *(_QWORD *)v23 = 0i64;
        v26 = Scaleform::GFx::AS3::Impl::SparseArray::At(v25, v22)->value.VNumber;
        v.Flags = 12;
        v.Bonus.pWeakProxy = 0i64;
        v.value.VNumber = v26;
        if ( v26 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v26 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v26 + 32i64) + 1) & 0x8FBFFFFF;
        v27 = Scaleform::GFx::AS3::VM::IsOfType(
                v6->pTraits.pObject->pVM,
                &v,
                "flash.geom.Point",
                v6->pTraits.pObject->pVM->CurrentDomain.pObject);
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        if ( v27 )
        {
          *(float *)v23 = *(double *)(*(_QWORD *)&v26 + 56i64);
          *((float *)v23 + 1) = *(double *)(*(_QWORD *)&v26 + 64i64);
        }
        ++v22;
        v23 += 8;
        --v24;
      }
      while ( v24 );
      LODWORD(offsetCount) = v34.ID;
    }
    fractal = grayScale[0].Result;
    stitch = resulta.Result;
    offsets = *(float **)channelMask;
    goto LABEL_62;
  }
}       ++v22;
        v23 += 8;
        --v24;
      }
      while ( v24 );
      LOD

// File Line: 929
// RVA: 0x857260
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::pixelDissolve(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, int *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect, Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint, int randomSeed, int numPixels, unsigned int fillColor)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v8; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v9; // rsi
  int *v10; // r12
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v11; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v14; // rbp
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  int v16; // er14
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::Render::DrawableImage *v18; // r15
  Scaleform::Render::DrawableImage *v19; // rax
  double v20; // xmm0_8
  double v21; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  Scaleform::Render::Point<long> v25; // [rsp+40h] [rbp-48h]
  __int64 v26; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v27; // [rsp+50h] [rbp-38h]
  Scaleform::Render::Color v28; // [rsp+A0h] [rbp+18h]

  v26 = -2i64;
  v8 = sourceRect;
  v9 = sourceBitmapData;
  v10 = result;
  v11 = this;
  if ( sourceBitmapData )
  {
    if ( sourceRect )
    {
      v14 = destPoint;
      if ( destPoint )
      {
        v16 = numPixels;
        if ( numPixels >= 0 )
        {
          v18 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                      this,
                                                      this);
          v19 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                      v11,
                                                      v9);
          if ( v18 && v19 )
          {
            v28 = (Scaleform::Render::Color)fillColor;
            v25.x = (signed int)v14->x;
            v25.y = (signed int)v14->y;
            v20 = v8->x;
            v27.ID = (signed int)v20;
            v21 = v8->y;
            *((_DWORD *)&v27.ID + 1) = (signed int)v21;
            LODWORD(v27.Message.pNode) = (signed int)(v20 + v8->width);
            HIDWORD(v27.Message.pNode) = (signed int)(v21 + v8->height);
            *v10 = Scaleform::Render::DrawableImage::PixelDissolve(
                     v18,
                     v19,
                     (Scaleform::Render::Rect<long> *)&v27,
                     &v25,
                     randomSeed,
                     v16,
                     (Scaleform::Render::Color)&v28);
            return;
          }
          Scaleform::GFx::AS3::VM::Error::Error(&v27, eArgumentError, v11->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            v11->pTraits.pObject->pVM,
            v22,
            &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v27, eMustBeNonNegative, this->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            v11->pTraits.pObject->pVM,
            v17,
            &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v11->pTraits.pObject->pVM,
          v15,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v11->pTraits.pObject->pVM,
        v13,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v27, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v11->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  v23 = v27.Message.pNode;
  v24 = v27.Message.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}

// File Line: 954
// RVA: 0x85AAC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::scroll(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, int x, int y)
{
  int v4; // edi
  int v5; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rbx
  Scaleform::Render::DrawableImage *v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h]

  v4 = y;
  v5 = x;
  v6 = this;
  v7 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( v7 )
  {
    Scaleform::Render::DrawableImage::Scroll(v7, v5, v4);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v8, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v9 = v11.Message.pNode;
    v10 = v11.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
}

// File Line: 965
// RVA: 0x85BB10
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, int x, int y, unsigned int color)
{
  int v5; // edi
  int v6; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Color c; // [rsp+20h] [rbp-28h]
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h]

  v13 = -2i64;
  v5 = y;
  v6 = x;
  v7 = this;
  v8 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( v8 )
  {
    c = (Scaleform::Render::Color)color;
    Scaleform::Render::DrawableImage::SetPixel(v8, v6, v5, (Scaleform::Render::Color)&c);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v14.Message.pNode;
    v11 = v14.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 975
// RVA: 0x85BA70
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel32(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, int x, int y, unsigned int color)
{
  int v5; // edi
  int v6; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::Render::Color c; // [rsp+20h] [rbp-28h]
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h]

  v13 = -2i64;
  v5 = y;
  v6 = x;
  v7 = this;
  v8 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                             this,
                                             this);
  if ( v8 )
  {
    c = (Scaleform::Render::Color)color;
    Scaleform::Render::DrawableImage::SetPixel32(v8, v6, v5, (Scaleform::Render::Color)&c);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eArgumentError, v7->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v14.Message.pNode;
    v11 = v14.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 985
// RVA: 0x85BBB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixels(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *inputByteArray)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rbx
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::Render::DrawableImage *v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  double v14; // xmm2_8
  double v15; // xmm0_8
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::Render::DIPixelProvider provider; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v19; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+38h] [rbp-20h]

  v4 = inputByteArray;
  v5 = rect;
  v6 = this;
  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  if ( !inputByteArray )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v10,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v8 = v20.Message.pNode;
    v9 = v20.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return;
  }
  provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable';
  v19 = inputByteArray;
  v11 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( v11 )
  {
    v14 = v5->height;
    v15 = v5->width;
    v20.ID = (signed int)v5->x;
    *((_DWORD *)&v20.ID + 1) = (signed int)v5->y;
    LODWORD(v20.Message.pNode) = (signed int)(v15 + v5->x);
    HIDWORD(v20.Message.pNode) = (signed int)(v14 + v5->y);
    if ( !Scaleform::Render::DrawableImage::SetPixels(v11, (Scaleform::Render::Rect<long> *)&v20, &provider)
      && v4->Length < v19->Length )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v20, eEOFError, v6->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v16, &Scaleform::GFx::AS3::fl::ErrorTI);
      v17 = v20.Message.pNode;
      v9 = v20.Message.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v13 = v20.Message.pNode;
    v9 = v20.Message.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}

// File Line: 1007
// RVA: 0x85ED40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *inputVector)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::Render::DrawableImage *v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  double v14; // xmm2_8
  double v15; // xmm0_8
  unsigned int v16; // ebx
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  int v19; // [rsp+20h] [rbp-40h]
  __int64 v20; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+30h] [rbp-30h]
  Scaleform::Render::DIPixelProvider provider; // [rsp+40h] [rbp-20h]
  int v23; // [rsp+48h] [rbp-18h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v24; // [rsp+50h] [rbp-10h]
  int resulta; // [rsp+90h] [rbp+30h]

  v20 = -2i64;
  v4 = inputVector;
  v5 = rect;
  v6 = this;
  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  if ( !inputVector )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eNullPointerError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v10,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v8 = v21.Message.pNode;
    v9 = v21.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return;
  }
  provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable';
  v23 = 0;
  v24 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)inputVector;
  v11 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                              this,
                                              this);
  if ( v11 )
  {
    v14 = v5->height;
    v15 = v5->width;
    v21.ID = (signed int)v5->x;
    *((_DWORD *)&v21.ID + 1) = (signed int)v5->y;
    LODWORD(v21.Message.pNode) = (signed int)(v15 + v5->x);
    HIDWORD(v21.Message.pNode) = (signed int)(v14 + v5->y);
    if ( !Scaleform::Render::DrawableImage::SetPixels(v11, (Scaleform::Render::Rect<long> *)&v21, &provider) )
    {
      Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(
        (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)v4,
        &resulta);
      v16 = resulta;
      Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(v24, &v19);
      if ( v16 < v19 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v21, eInvalidRangeError, v6->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6->pTraits.pObject->pVM, v17, &Scaleform::GFx::AS3::fl::ErrorTI);
        v18 = v21.Message.pNode;
        v9 = v21.Message.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v13 = v21.Message.pNode;
    v9 = v21.Message.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}  --v13->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStr

// File Line: 1030
// RVA: 0x860BE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned int v5; // er15
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // rdi
  long double v7; // r13
  long double v8; // rax
  long double v9; // rcx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  const char *v14; // rcx
  Scaleform::Render::DrawableImage::OperationType op; // er14
  char v16; // r12
  char v17; // al
  char v18; // al
  Scaleform::Render::DrawableImage *v19; // rbx
  Scaleform::Render::ImageBase *v20; // rax
  Scaleform::Render::DrawableImage *v21; // rdx
  Scaleform::Render::Point<long> v22; // rax
  double v23; // xmm0_8
  double v24; // xmm2_8
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::AS3::VM::Error *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  bool v28; // zf
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+30h] [rbp-11h]
  unsigned int color; // [rsp+40h] [rbp-1h]
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+7h]
  unsigned int mask; // [rsp+50h] [rbp+Fh]
  Scaleform::Render::Point<long> destPoint; // [rsp+58h] [rbp+17h]
  unsigned int threshold; // [rsp+60h] [rbp+1Fh]
  __int64 v35; // [rsp+68h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult v36; // [rsp+B8h] [rbp+77h]

  if ( argc >= 5 )
  {
    v35 = -2i64;
    v4 = argv;
    v5 = argc;
    v6 = this;
    v7 = argv->value.VNumber;
    v8 = argv[1].value.VNumber;
    *(long double *)&v29.ID = argv[1].value.VNumber;
    v9 = argv[2].value.VNumber;
    destPoint = *(Scaleform::Render::Point<long> *)&argv[2].value.VNumber;
    if ( v7 == 0.0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v29, eNullPointerError, v6->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v6->pTraits.pObject->pVM,
        v10,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v11 = v29.Message.pNode;
      goto LABEL_51;
    }
    if ( v8 == 0.0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v29, eNullPointerError, v6->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v6->pTraits.pObject->pVM,
        v12,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v11 = v29.Message.pNode;
      goto LABEL_51;
    }
    if ( v9 == 0.0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v29, eNullPointerError, v6->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v6->pTraits.pObject->pVM,
        v13,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v11 = v29.Message.pNode;
      goto LABEL_51;
    }
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv + 3, &resulta);
    v14 = resulta.pNode->pData;
    if ( *resulta.pNode->pData != asc_14169F280[0] || v14[1] != 61 || v14[2] )
    {
      if ( *v14 != asc_14167E65C[0] || v14[1] != asc_14167E65C[1] )
      {
        if ( *v14 != asc_14167E638[0] || v14[1] != asc_14167E638[1] )
        {
          if ( *v14 != asc_14169F27C[0] || v14[1] != 61 || v14[2] )
          {
            if ( *v14 != asc_14186CBC8[0] || v14[1] != 61 || v14[2] )
            {
              if ( *v14 != asc_141743BB0[0] || v14[1] != 61 || v14[2] )
              {
                Scaleform::GFx::AS3::VM::Error::Error(&v29, eInvalidArgumentError, v6->pTraits.pObject->pVM);
                Scaleform::GFx::AS3::VM::ThrowErrorInternal(
                  v6->pTraits.pObject->pVM,
                  v26,
                  &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
                goto LABEL_48;
              }
              op = 4;
            }
            else
            {
              op = 5;
            }
          }
          else
          {
            op = 3;
          }
        }
        else
        {
          op = 2;
        }
      }
      else
      {
        op = 0;
      }
    }
    else
    {
      op = 1;
    }
    color = 0;
    mask = -1;
    v16 = 1;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 4, &v36, &threshold)->Result )
      goto LABEL_50;
    v17 = v5 < 6 || Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 5, &v36, &color)->Result ? 0 : 1;
    if ( v17 )
      goto LABEL_50;
    v18 = v5 < 7 || Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 6, &v36, &mask)->Result ? 0 : 1;
    if ( v18 )
      goto LABEL_50;
    if ( v5 >= 8 )
      v16 = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 7);
    v19 = (Scaleform::Render::DrawableImage *)Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                                v6,
                                                v6);
    v20 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
            v6,
            *(Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)&v7);
    v21 = (Scaleform::Render::DrawableImage *)v20;
    if ( v19 && v20 )
    {
      v22 = destPoint;
      destPoint.x = (signed int)*(double *)(*(_QWORD *)&destPoint + 56i64);
      destPoint.y = (signed int)*(double *)(*(_QWORD *)&v22 + 64i64);
      v23 = *(double *)(*(_QWORD *)&v29.ID + 64i64) + *(double *)(*(_QWORD *)&v29.ID + 72i64);
      v24 = *(double *)(*(_QWORD *)&v29.ID + 56i64) + *(double *)(*(_QWORD *)&v29.ID + 80i64);
      LOBYTE(color) = v16;
      Scaleform::Render::DrawableImage::Threshold(
        v19,
        v21,
        (Scaleform::Render::Rect<long> *)&v29,
        &destPoint,
        op,
        threshold,
        color,
        mask,
        v16);
LABEL_50:
      v11 = resulta.pNode;
LABEL_51:
      v28 = v11->RefCount-- == 1;
      if ( v28 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v29, eArgumentError, v6->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v6->pTraits.pObject->pVM,
      v25,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_48:
    v27 = v29.Message.pNode;
    v28 = v29.Message.pNode->RefCount == 1;
    --v27->RefCount;
    if ( v28 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    goto LABEL_50;
  }
}

// File Line: 1120
// RVA: 0x789A90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::~BitmapData(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v1; // rbx
  Scaleform::GFx::ImageResource *v2; // rcx
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::GFx::Resource *v4; // rcx
  Scaleform::GFx::Resource *v5; // rcx
  Scaleform::Render::ImageBase *v6; // rcx
  Scaleform::GFx::Resource *v7; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vftable';
  v2 = this->pImageResource.pObject;
  if ( v2 )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v2->vfptr);
  v1->pImageResource.pObject = 0i64;
  v3 = v1->pImage.pObject;
  if ( v3 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v3->vfptr[2].__vecDelDtor)(v3);
  v1->pImage.pObject = 0i64;
  v4 = (Scaleform::GFx::Resource *)&v1->pDefImpl.pObject->vfptr;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v1->pDefImpl.pObject = 0i64;
  v5 = (Scaleform::GFx::Resource *)&v1->pDefImpl.pObject->vfptr;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  v6 = v1->pImage.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v6->vfptr[2].__vecDelDtor)(v6);
  v7 = (Scaleform::GFx::Resource *)&v1->pImageResource.pObject->vfptr;
  if ( v7 )
    Scaleform::GFx::Resource::Release(v7);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)v1->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&v1->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 1129
// RVA: 0x7F2D10
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::InitInstance(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, bool extCall)
{
  if ( !extCall )
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(this, 0i64, 0i64);
}

// File Line: 1139
// RVA: 0x7BD9A0
bool __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::ImageResource *imgRes, Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *v3; // rsi
  Scaleform::GFx::ImageResource *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rbx
  Scaleform::GFx::Resource *v6; // rcx
  Scaleform::Render::ImageBase *v7; // rdi
  Scaleform::Render::ImageBase *v8; // rcx
  Scaleform::GFx::Resource *v9; // rcx
  Scaleform::GFx::AS3::ASVM *v10; // rdi
  Scaleform::GFx::MovieDefImpl *v11; // rsi
  Scaleform::GFx::AS3::Traits *v12; // rcx
  bool v13; // bp
  Scaleform::GFx::AS3::MovieRoot *v14; // rbx
  Scaleform::Log *v15; // rdi
  const char *v16; // rdi
  Scaleform::Log *v17; // rbx
  Scaleform::GFx::Resource *v18; // rdi
  Scaleform::GFx::Resource *v19; // rcx
  Scaleform::Render::ImageBase *v20; // rdi
  Scaleform::Render::ImageBase *v21; // rcx
  Scaleform::GFx::Resource *v22; // rdi
  Scaleform::GFx::Resource *v23; // rcx
  Scaleform::GFx::Resource *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+20h] [rbp-48h]
  Scaleform::Ptr<Scaleform::Log> v29; // [rsp+28h] [rbp-40h]
  __int64 v30; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v32; // [rsp+78h] [rbp+10h]
  Scaleform::String symbol; // [rsp+88h] [rbp+20h]

  v30 = -2i64;
  v3 = defImpl;
  v4 = imgRes;
  v5 = this;
  if ( imgRes )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&imgRes->vfptr);
    v6 = (Scaleform::GFx::Resource *)&v5->pImageResource.pObject->vfptr;
    if ( v6 )
      Scaleform::GFx::Resource::Release(v6);
    v5->pImageResource.pObject = v4;
    v7 = v4->pImage;
    if ( v7 )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))v7->vfptr[1].__vecDelDtor)(v7);
    v8 = v5->pImage.pObject;
    if ( v8 )
      ((void (*)(void))v8->vfptr[2].__vecDelDtor)();
    v5->pImage.pObject = v7;
    if ( v3 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v3->vfptr);
    v9 = (Scaleform::GFx::Resource *)&v5->pDefImpl.pObject->vfptr;
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    v5->pDefImpl.pObject = v3;
  }
  else
  {
    v10 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    v11 = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(
            v10,
            (Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr);
    if ( v11 )
    {
      v12 = v5->pTraits.pObject;
      if ( (LOBYTE(v12->Flags) >> 4) & 1 )
      {
        ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **, signed __int64))v12->vfptr[1].Finalize_GC)(
          v12,
          &v32,
          1i64);
        presBindData.pResource.pObject = 0i64;
        presBindData.pBinding = 0i64;
        Scaleform::String::String(&symbol, v32->pData);
        v13 = Scaleform::GFx::MovieImpl::FindExportedResource(v10->pMovieRoot->pMovieImpl, v11, &presBindData, &symbol) == 0;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( v13 )
        {
          v14 = v10->pMovieRoot;
          v15 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v14->pMovieImpl->vfptr, &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v15 )
          {
            v16 = v32->pData;
            v17 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v14->pMovieImpl->vfptr, &v29)->pObject;
            if ( v29.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v29.pObject);
            Scaleform::Log::LogWarning(v17, "Attaching a bitmap with class '%s' failed", v16);
          }
        }
        else if ( presBindData.pResource.pObject
               && (((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) == 256 )
        {
          v18 = presBindData.pResource.pObject;
          if ( presBindData.pResource.pObject )
            Scaleform::Render::RenderBuffer::AddRef(presBindData.pResource.pObject);
          v19 = (Scaleform::GFx::Resource *)&v5->pImageResource.pObject->vfptr;
          if ( v19 )
            Scaleform::GFx::Resource::Release(v19);
          v5->pImageResource.pObject = (Scaleform::GFx::ImageResource *)v18;
          v20 = (Scaleform::Render::ImageBase *)v18[1].vfptr;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::Render::ImageBase *))v20->vfptr[1].__vecDelDtor)(v20);
          v21 = v5->pImage.pObject;
          if ( v21 )
            ((void (*)(void))v21->vfptr[2].__vecDelDtor)();
          v5->pImage.pObject = v20;
          if ( presBindData.pBinding )
          {
            v22 = presBindData.pBinding->pOwnerDefRes;
            if ( v22 )
              Scaleform::Render::RenderBuffer::AddRef(v22);
            v23 = (Scaleform::GFx::Resource *)&v5->pDefImpl.pObject->vfptr;
            if ( v23 )
              Scaleform::GFx::Resource::Release(v23);
            v5->pDefImpl.pObject = (Scaleform::GFx::MovieDefImpl *)v22;
          }
          else
          {
            Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v11->vfptr);
            v24 = (Scaleform::GFx::Resource *)&v5->pDefImpl.pObject->vfptr;
            if ( v24 )
              Scaleform::GFx::Resource::Release(v24);
            v5->pDefImpl.pObject = v11;
          }
        }
        if ( presBindData.pResource.pObject )
          Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
        v25 = v32;
        v26 = v32->RefCount == 1;
        --v25->RefCount;
        if ( v26 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
  }
  return 0;
}

// File Line: 1190
// RVA: 0x7EA2F0
Scaleform::GFx::ImageResource *__fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v1; // rbx
  Scaleform::GFx::ImageResource *result; // rax
  Scaleform::Render::ImageBase *v3; // rdx
  Scaleform::GFx::ImageResource *v4; // rax
  Scaleform::GFx::ImageResource *v5; // rax
  Scaleform::GFx::ImageResource *v6; // rdi
  Scaleform::GFx::Resource *v7; // rcx
  int v8; // [rsp+40h] [rbp+8h]
  Scaleform::Render::ImageBase *v9; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ImageResource *v10; // [rsp+50h] [rbp+18h]

  v1 = this;
  result = this->pImageResource.pObject;
  if ( !result )
  {
    if ( !this->pImage.pObject )
      Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
    v3 = v1->pImage.pObject;
    if ( v3 )
    {
      v9 = v1->pImage.pObject;
      v8 = 2;
      v4 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ImageBase *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              v3,
                                              104i64,
                                              &v8,
                                              -2i64);
      v10 = v4;
      if ( v4 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v4, v1->pImage.pObject, Use_Bitmap);
        v6 = v5;
      }
      else
      {
        v6 = 0i64;
      }
      v7 = (Scaleform::GFx::Resource *)&v1->pImageResource.pObject->vfptr;
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
      v1->pImageResource.pObject = v6;
      result = v6;
    }
    else
    {
      result = 0i64;
    }
  }
  return result;
}

// File Line: 1212
// RVA: 0x7954A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  unsigned int v9; // [rsp+20h] [rbp-28h]
  __int64 v10; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+10h]
  int v13; // [rsp+68h] [rbp+20h]

  v10 = -2i64;
  v3 = argv;
  v4 = argc;
  v5 = this;
  if ( argc >= 2 )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv, &result, &v13)->Result )
    {
      v5->Width = v13;
      if ( Scaleform::GFx::AS3::Value::Convert2Int32(v3 + 1, &result, &v13)->Result )
      {
        v5->Height = v13;
        v9 = -1;
        if ( v4 >= 3 )
          v5->Transparent = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 2);
        if ( v4 >= 4 )
          Scaleform::GFx::AS3::Value::Convert2UInt32(v3 + 3, &result, &v9);
        v5->ClearColor.Raw = v9;
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eWrongArgumentCountError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v7 = v11.Message.pNode;
    v8 = v11.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 1248
// RVA: 0x84B4A0
Scaleform::Render::ImageBase *__fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v3; // rdi
  Scaleform::Render::ImageBase *v5; // rcx
  Scaleform::Render::DrawableImageContext *dicontext; // r14
  Scaleform::Render::ThreadCommandQueue *v7; // rcx
  Scaleform::Render::ImageBase *v8; // rdi
  __int64 v9; // r12
  unsigned int v10; // esi
  unsigned int v11; // ebp
  Scaleform::Render::DrawableImage *v12; // r15
  Scaleform::Render::ImageFormat v13; // eax
  Scaleform::Render::ImageBase *v14; // rax
  Scaleform::Render::DrawableImage *v15; // rax
  Scaleform::Render::ImageBase *v16; // rax
  Scaleform::Render::ImageBase *v17; // rcx
  __int128 v18; // [rsp+38h] [rbp-60h]
  __int64 v19; // [rsp+48h] [rbp-50h]
  __int64 v20; // [rsp+50h] [rbp-48h]
  Scaleform::Render::Color v21; // [rsp+A8h] [rbp+10h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+B0h] [rbp+18h]
  Scaleform::Render::DrawableImage *v23; // [rsp+B8h] [rbp+20h]

  v2 = sourceBitmapData;
  v3 = this;
  if ( !sourceBitmapData )
    return 0i64;
  v5 = sourceBitmapData->pImage.pObject;
  if ( !v5 || ((unsigned int (*)(void))v5->vfptr[3].__vecDelDtor)() != 6 )
  {
    dicontext = Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)v3->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor);
    v7 = dicontext->pRTCommandQueue;
    if ( v7 )
    {
      v8 = 0i64;
      v18 = 0ui64;
      v19 = 0i64;
      v20 = 0i64;
      v7->vfptr->GetRenderInterfaces(v7, (Scaleform::Render::Interfaces *)&v18);
      v9 = v18;
      if ( v2->pImageResource.pObject )
      {
        v15 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    200ui64,
                                                    0i64);
        *(_QWORD *)&v21.Channels.Blue = v15;
        if ( v15 )
        {
          Scaleform::Render::DrawableImage::DrawableImage(v15, 1, v2->pImageResource.pObject->pImage, dicontext);
          v8 = v16;
        }
      }
      else
      {
        v10 = v2->Height;
        v11 = v2->Width;
        if ( v11 * v2->Height > 0xFFFFFF || v11 > 0x1FFF || v10 > 0x1FFF )
          return 0i64;
        v12 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    200ui64,
                                                    0i64);
        v23 = v12;
        if ( v12 )
        {
          v21 = (Scaleform::Render::Color)v2->ClearColor.Raw;
          size.Width = v11;
          size.Height = v10;
          v13 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 104i64))(v9);
          Scaleform::Render::DrawableImage::DrawableImage(
            v12,
            v13,
            (Scaleform::Render::Size<unsigned long>)&size,
            v2->Transparent,
            (Scaleform::Render::Color)&v21,
            dicontext);
          v8 = v14;
        }
      }
      v17 = v2->pImage.pObject;
      if ( v17 )
        ((void (*)(void))v17->vfptr[2].__vecDelDtor)();
      v2->pImage.pObject = v8;
    }
  }
  return v2->pImage.pObject;
}

// File Line: 1405
// RVA: 0x7FF220
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 1427
// RVA: 0x743A00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapData::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::BitmapDataCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapData::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::BitmapDataCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::`vftable';
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
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

