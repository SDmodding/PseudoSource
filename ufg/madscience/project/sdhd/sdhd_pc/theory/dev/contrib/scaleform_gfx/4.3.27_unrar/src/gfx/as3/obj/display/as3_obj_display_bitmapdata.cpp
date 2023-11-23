// File Line: 53
// RVA: 0x80F0B0
__int64 __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::ReadNextPixel(
        Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this)
{
  unsigned int result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readInt(this->PixelArray, &result);
  return result;
}

// File Line: 57
// RVA: 0x82A220
void __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::WriteNextPixel(
        Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this,
        unsigned int pixel)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *PixelArray; // rdi

  PixelArray = this->PixelArray;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeInt(PixelArray, &v, pixel);
}

// File Line: 62
// RVA: 0x7EB9A0
unsigned __int64 __fastcall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::GetLength(
        Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this)
{
  return this->PixelArray->Length;
}

// File Line: 76
// RVA: 0x80F0D0
__int64 __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::ReadNextPixel(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  char v1; // bl
  __int64 Location; // rdx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *PixelVector; // rax
  int v4; // edx
  unsigned int VUInt; // edi
  Scaleform::GFx::AS3::Value::VU v7; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Value v8; // [rsp+38h] [rbp-30h] BYREF

  v1 = 0;
  v8.Flags = 0;
  v8.Bonus.pWeakProxy = 0i64;
  Location = this->Location;
  this->Location = Location + 1;
  PixelVector = this->PixelVector;
  if ( (unsigned int)Location < LODWORD(PixelVector->V.ValueA.Data.Size) )
  {
    v4 = PixelVector->V.ValueA.Data.Data[Location];
    v1 = 3;
    v8.Flags = 3;
    v7.VS._1.VInt = v4;
    v8.value = v7;
  }
  VUInt = v8.value.VS._1.VUInt;
  if ( (v1 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
  return VUInt;
}

// File Line: 82
// RVA: 0x82A290
void __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::WriteNextPixel(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this,
        int pixel)
{
  unsigned int Location; // r8d
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+10h] BYREF

  Location = this->Location;
  this->Location = Location + 1;
  v.Flags = 3;
  v.Bonus.pWeakProxy = 0i64;
  v.value.VS._1.VInt = pixel;
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Set(
    this->PixelVector,
    &result,
    Location,
    &v,
    this->PixelVector->pTraits.pObject->pVM->TraitsUint.pObject);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      if ( v.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
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
unsigned __int64 __fastcall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::GetLength(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  int result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(
    (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)this->PixelVector,
    &result);
  return (unsigned int)result;
}

// File Line: 105
// RVA: 0x76C760
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,11,3,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    sm,
    result,
    "null");
  return result;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,0,long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, int *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::rectGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,3,long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, int *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet;
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
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, Scaleform::GFx::AS3::Instances::fl_geom::Point *, unsigned int, unsigned int))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel;
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
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,11,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::Object *, Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::draw;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,12,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, unsigned int))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect;
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
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,13,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, int, int, unsigned int))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::generateFilterRect;
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
  Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,15,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>,unsigned long,unsigned long,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *, unsigned int, unsigned int, bool))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getColorBoundsRect;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,18,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixels;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,19,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getVector;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,21,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,22,Scaleform::GFx::AS3::Value const>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *))_;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,23,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge;
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
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, int, unsigned int, unsigned int, unsigned int, bool))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,25,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,26,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,32,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,33,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,34,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *))_;
  return result;
}

// File Line: 225
// RVA: 0x84DF40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::heightGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result)
{
  Scaleform::Render::ImageBase *pObject; // r8
  __int64 v4; // rax
  char v5[24]; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pImage.pObject;
  if ( pObject )
  {
    v4 = (__int64)pObject->vfptr[6].__vecDelDtor(this->pImage.pObject, (unsigned int)v5);
    *result = *(_DWORD *)(v4 + 12) - *(_DWORD *)(v4 + 4);
  }
  else
  {
    *result = this->Height;
  }
}

// File Line: 235
// RVA: 0x8594F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::rectGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  double Width; // xmm0_8
  double v5; // xmm0_8
  double Height; // xmm0_8
  double v7; // xmm0_8
  Scaleform::GFx::AS3::Value ptr; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value v9; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::Value v10; // [rsp+80h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::Value v11; // [rsp+A0h] [rbp-48h] BYREF

  `eh vector constructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  Scaleform::GFx::AS3::Value::SetNumber(&ptr, 0.0);
  Scaleform::GFx::AS3::Value::SetNumber(&v9, 0.0);
  Width = (double)(int)this->Width;
  if ( Width <= 0.0 )
    v5 = Width - 0.5;
  else
    v5 = Width + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v10, (double)(int)v5);
  Height = (double)(int)this->Height;
  if ( Height <= 0.0 )
    v7 = Height - 0.5;
  else
    v7 = Height + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v11, (double)(int)v7);
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    this->pTraits.pObject->pVM[1].ExceptionObj.value.VS._1.VObj,
    4u,
    &ptr);
  `eh vector destructor iterator(&ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 247
// RVA: 0x86AB90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool *result)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    *result = DrawableImageFromBitmapData->Transparent;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v5,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 256
// RVA: 0x86BF50
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::widthGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result)
{
  Scaleform::Render::ImageBase *pObject; // r8
  _DWORD *v4; // rax
  char v5[24]; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pImage.pObject;
  if ( pObject )
  {
    v4 = pObject->vfptr[6].__vecDelDtor(this->pImage.pObject, (unsigned int)v5);
    *result = v4[2] - *v4;
  }
  else
  {
    *result = this->Width;
  }
}

// File Line: 266
// RVA: 0x82D0F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::applyFilter(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *filter)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v12; // r15
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v13; // r13
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r14
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::Render::DrawableImage *v16; // r12
  double height; // xmm2_8
  double width; // xmm0_8
  Scaleform::Render::Filter *pObject; // rsi
  Scaleform::GFx::AS3::FlashUI *UI; // rcx
  int Type; // eax
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  bool v24; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::Render::Point<long> v25; // [rsp+38h] [rbp-48h] BYREF
  __int64 v26; // [rsp+40h] [rbp-40h]
  Scaleform::Render::Rect<long> sourceRecta; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+68h] [rbp-18h] BYREF
  bool resulta; // [rsp+C0h] [rbp+40h] BYREF

  v26 = -2i64;
  if ( !sourceBitmapData || !sourceRect || (v12 = destPoint) == 0i64 || (v13 = filter) == 0i64 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    pNode = v28.Message.pNode;
    goto LABEL_4;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v15,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  v16 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
  height = sourceRect->height;
  width = sourceRect->width;
  sourceRecta.x1 = (int)sourceRect->x;
  sourceRecta.y1 = (int)sourceRect->y;
  sourceRecta.x2 = (int)(width + sourceRect->x);
  sourceRecta.y2 = (int)(height + sourceRect->y);
  v25.x = (int)v12->x;
  v25.y = (int)v12->y;
  pObject = v13->FilterData.pObject;
  if ( !pObject )
  {
LABEL_13:
    UI = this->pTraits.pObject->pVM->UI;
    UI->vfptr->Output(
      UI,
      Output_Warning,
      "The method BitmapData::applyFilter (unsupported filter type) is not implemented\n");
    return;
  }
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(this, &resulta);
  Type = pObject->Type;
  if ( !Type )
  {
LABEL_23:
    Scaleform::Render::DrawableImage::ApplyFilter(DrawableImageFromBitmapData, v16, &sourceRecta, &v25, pObject);
    return;
  }
  if ( Type <= 0 )
    goto LABEL_13;
  if ( Type > 3 )
  {
    if ( Type != 8 )
    {
      if ( Type != 10 )
        goto LABEL_13;
      Scaleform::GFx::AS3::Instances::fl_display::BitmapData::transparentGet(sourceBitmapData, &v24);
      if ( v24 != resulta )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v28, 2077, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this->pTraits.pObject->pVM,
          v22,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_3;
      }
    }
    goto LABEL_23;
  }
  if ( resulta )
    goto LABEL_23;
  Scaleform::GFx::AS3::VM::Error::Error(&v29, 2077, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTraits.pObject->pVM,
    v23,
    &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v29.Message.pNode;
LABEL_4:
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 339
// RVA: 0x82F2E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+30h] [rbp+8h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
               &resulta,
               (Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *)this->pTraits.pObject);
  pObject = result->pObject;
  pV = Instance->pV;
  if ( Instance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  result->pObject->Width = this->Width;
  result->pObject->Height = this->Height;
  result->pObject->Transparent = this->Transparent;
  result->pObject->ClearColor.Raw = this->ClearColor.Raw;
}

// File Line: 352
// RVA: 0x830EB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::colorTransform(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *cTransform)
{
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rbp
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  double x; // xmm0_8
  double y; // xmm1_8
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::Cxform resulta; // [rsp+40h] [rbp-28h] BYREF

  if ( rect && cTransform )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    if ( DrawableImageFromBitmapData )
    {
      Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(&resulta, cTransform);
      x = rect->x;
      v14.ID = (int)x;
      y = rect->y;
      *((_DWORD *)&v14.ID + 1) = (int)y;
      LODWORD(v14.Message.pNode) = (int)(x + rect->width);
      HIDWORD(v14.Message.pNode) = (int)(y + rect->height);
      Scaleform::Render::DrawableImage::ColorTransform(
        DrawableImageFromBitmapData,
        (Scaleform::Render::Rect<long> *)&v14,
        &resulta);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2077, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  pNode = v14.Message.pNode;
  if ( v14.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 373
// RVA: 0x831400
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::compare(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *otherBitmapData)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::Render::ImageBase *pObject; // rcx
  _DWORD *v10; // rax
  unsigned int Width; // ebp
  Scaleform::Render::ImageBase *v12; // rcx
  __int64 v13; // rax
  unsigned int Height; // esi
  Scaleform::Render::ImageBase *v15; // rcx
  _DWORD *v16; // rax
  unsigned int v17; // r14d
  Scaleform::Render::ImageBase *v18; // rcx
  __int64 v19; // rax
  unsigned int v20; // ecx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rsi
  Scaleform::Render::DrawableImage *v22; // rdi
  Scaleform::Render::DrawableImage *v23; // rax
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v26; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+70h] [rbp+18h] BYREF

  if ( otherBitmapData )
  {
    pObject = otherBitmapData->pImage.pObject;
    if ( pObject )
    {
      v10 = pObject->vfptr[6].__vecDelDtor(pObject, (unsigned int)&v28);
      Width = v10[2] - *v10;
    }
    else
    {
      Width = otherBitmapData->Width;
    }
    v12 = otherBitmapData->pImage.pObject;
    if ( v12 )
    {
      v13 = (__int64)v12->vfptr[6].__vecDelDtor(v12, (unsigned int)&v28);
      Height = *(_DWORD *)(v13 + 12) - *(_DWORD *)(v13 + 4);
    }
    else
    {
      Height = otherBitmapData->Height;
    }
    v15 = this->pImage.pObject;
    if ( v15 )
    {
      v16 = v15->vfptr[6].__vecDelDtor(v15, (unsigned int)&v28);
      v17 = v16[2] - *v16;
    }
    else
    {
      v17 = this->Width;
    }
    v18 = this->pImage.pObject;
    if ( v18 )
    {
      v19 = (__int64)v18->vfptr[6].__vecDelDtor(v18, (unsigned int)&v28);
      v20 = *(_DWORD *)(v19 + 12) - *(_DWORD *)(v19 + 4);
    }
    else
    {
      v20 = this->Height;
    }
    if ( v17 == Width )
    {
      if ( v20 == Height )
      {
        DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                        this,
                                        otherBitmapData);
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(this, &resulta);
        v22 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                this,
                resulta.pObject);
        v23 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
        if ( DrawableImageFromBitmapData && v22 && v23 )
        {
          Scaleform::Render::DrawableImage::Compare(v22, v23, DrawableImageFromBitmapData);
          Scaleform::GFx::AS3::Value::Assign(result, resulta.pObject);
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v28, 2015, this->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this->pTraits.pObject->pVM,
            v24,
            &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          pNode = v28.Message.pNode;
          v8 = v28.Message.pNode->RefCount-- == 1;
          if ( v8 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        v26 = resulta.pObject;
        if ( resulta.pObject )
        {
          if ( ((__int64)resulta.pObject & 1) != 0 )
          {
            --resulta.pObject;
          }
          else
          {
            RefCount = resulta.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              resulta.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
            }
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::SetSInt32(result, -4);
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetSInt32(result, -3);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v7 = v28.Message.pNode;
    v8 = v28.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 412
// RVA: 0x8324A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyChannel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        signed int sourceChannel,
        signed int destChannel)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v10; // rsi
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r14
  Scaleform::Render::DrawableImage *v13; // rax
  double x; // xmm0_8
  double y; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Render::Point<long> v20; // [rsp+80h] [rbp+18h] BYREF

  if ( sourceBitmapData && sourceRect && (v10 = destPoint) != 0i64 )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v13 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
    if ( DrawableImageFromBitmapData && v13 )
    {
      v20.x = (int)v10->x;
      v20.y = (int)v10->y;
      x = sourceRect->x;
      v19.ID = (int)x;
      y = sourceRect->y;
      *((_DWORD *)&v19.ID + 1) = (int)y;
      LODWORD(v19.Message.pNode) = (int)(x + sourceRect->width);
      HIDWORD(v19.Message.pNode) = (int)(y + sourceRect->height);
      Scaleform::Render::DrawableImage::CopyChannel(
        DrawableImageFromBitmapData,
        v13,
        (Scaleform::Render::Rect<long> *)&v19,
        &v20,
        (Scaleform::Render::DrawableImage::ChannelBits)sourceChannel,
        (Scaleform::Render::DrawableImage::ChannelBits)destChannel);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v16,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  pNode = v19.Message.pNode;
  if ( v19.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 436
// RVA: 0x832690
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::copyPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *alphaBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *alphaPoint,
        bool mergeAlpha)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v11; // rsi
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r14
  Scaleform::Render::DrawableImage *alphaSource; // r15
  Scaleform::Render::DrawableImage *v15; // r10
  double x; // xmm0_8
  double y; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Point<long> v21; // [rsp+40h] [rbp-38h] BYREF
  __int64 v22; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::VM::Error v23; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::Render::Point<long> v24; // [rsp+90h] [rbp+18h] BYREF

  v22 = -2i64;
  if ( !sourceBitmapData || !sourceRect || (v11 = destPoint) == 0i64 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_12;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  alphaSource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                  this,
                  alphaBitmapData);
  v15 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, sourceBitmapData);
  if ( !v15 || !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v18,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_12:
    pNode = v23.Message.pNode;
    if ( v23.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( alphaPoint )
  {
    v24.x = (int)alphaPoint->x;
    v24.y = (int)alphaPoint->y;
  }
  v21.x = (int)v11->x;
  v21.y = (int)v11->y;
  x = sourceRect->x;
  v23.ID = (int)x;
  y = sourceRect->y;
  *((_DWORD *)&v23.ID + 1) = (int)y;
  LODWORD(v23.Message.pNode) = (int)(x + sourceRect->width);
  HIDWORD(v23.Message.pNode) = (int)(y + sourceRect->height);
  Scaleform::Render::DrawableImage::CopyPixels(
    DrawableImageFromBitmapData,
    v15,
    (Scaleform::Render::Rect<long> *)&v23,
    &v21,
    alphaSource,
    &v24,
    mergeAlpha);
}

// File Line: 466
// RVA: 0x835310
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::dispose(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::ImageBase *pObject; // rcx

  pObject = this->pImage.pObject;
  if ( pObject )
    pObject->vfptr[2].__vecDelDtor(pObject, (unsigned int)result);
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->Width = 0i64;
}

// File Line: 475
// RVA: 0x8357B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::draw(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *source,
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *matrix)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  float a; // xmm0_4
  float b; // xmm1_4
  unsigned int v9; // xmm0_4
  unsigned int v10; // xmm1_4
  Scaleform::Render::BlendMode v11; // r12d
  int v12; // r8d
  double v13; // xmm0_8
  double v14; // xmm2_8
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r15
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  char v18; // bl
  Scaleform::Render::DrawableImage *v19; // rax
  Scaleform::Render::Rect<long> *v20; // rdx
  bool v21; // bl
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  Scaleform::GFx::DisplayObjectBase *v28; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rbx
  Scaleform::Render::Rect<long> *v30; // rcx
  Scaleform::GFx::AS3::VM::Error *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::Render::Cxform v34; // [rsp+38h] [rbp-79h] BYREF
  Scaleform::Render::Matrix2x4<float> matrixa; // [rsp+58h] [rbp-59h] BYREF
  Scaleform::Render::Cxform cform; // [rsp+78h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *retaddr; // [rsp+118h] [rbp+67h]
  Scaleform::GFx::ASString *value; // [rsp+120h] [rbp+6Fh]
  double *v39; // [rsp+128h] [rbp+77h]
  bool v40; // [rsp+130h] [rbp+7Fh]

  *(_QWORD *)&v34.M[0][2] = -2i64;
  if ( !source )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v34, 1508, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_23;
  }
  *(_OWORD *)&matrixa.M[0][0] = _xmm;
  *(__m128 *)&matrixa.M[1][0] = _xmm;
  if ( matrix )
  {
    a = matrix->a;
    v34.M[0][0] = a;
    b = matrix->b;
    v34.M[1][0] = b;
    *(float *)&v9 = matrix->c;
    *(_QWORD *)&v34.M[0][1] = v9;
    *(float *)&v10 = matrix->d;
    *(_QWORD *)&v34.M[1][1] = v10;
    v34.M[0][3] = matrix->tx;
    v34.M[1][3] = matrix->ty;
    Scaleform::Render::Matrix2x4<float>::Append(&matrixa, (Scaleform::Render::Matrix2x4<float> *)&v34);
  }
  Scaleform::Render::Cxform::Cxform(&cform);
  if ( retaddr )
    cform = *Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(&v34, retaddr);
  v11 = (unsigned int)Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(value);
  *(_OWORD *)&v34.M[1][0] = 0ui64;
  if ( v39 )
  {
    v12 = (int)v39[10];
    v13 = v39[8] + v39[9];
    v14 = v39[7] + v39[10];
    LODWORD(v34.M[1][0]) = (int)v39[9];
    LODWORD(v34.M[1][1]) = v12;
    LODWORD(v34.M[1][2]) = (int)v13;
    LODWORD(v34.M[1][3]) = (int)v14;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v34, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v16,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_23;
  }
  LODWORD(v34.M[0][0]) = 12;
  *(_QWORD *)&v34.M[0][2] = 0i64;
  *(_QWORD *)&v34.M[1][0] = source;
  source->RefCount = (source->RefCount + 1) & 0x8FBFFFFF;
  pObject = this->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(this->pTraits.pObject);
  v18 = Scaleform::GFx::AS3::VM::IsOfType(
          this->pTraits.pObject->pVM,
          (Scaleform::GFx::AS3::Value *)&v34,
          (Scaleform::GFx::AS3::ClassTraits::fl::Object *)pObject->pConstructor.pObject->pTraits.pObject);
  Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v34);
  if ( v18 )
  {
    v19 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, source);
    v20 = (Scaleform::Render::Rect<long> *)v34.M[1];
    if ( !v39 )
      v20 = 0i64;
    Scaleform::Render::DrawableImage::Draw(DrawableImageFromBitmapData, v19, &matrixa, &cform, v11, v20, v40);
  }
  else
  {
    LODWORD(v34.M[0][0]) = 12;
    *(_QWORD *)&v34.M[0][2] = 0i64;
    *(_QWORD *)&v34.M[1][0] = source;
    source->RefCount = (source->RefCount + 1) & 0x8FBFFFFF;
    v21 = Scaleform::GFx::AS3::VM::IsOfType(
            this->pTraits.pObject->pVM,
            (Scaleform::GFx::AS3::Value *)&v34,
            "flash.display.DisplayObject",
            this->pTraits.pObject->pVM->CurrentDomain.pObject);
    Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v34);
    if ( !v21 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v34, 1508, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v31,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_23:
      v32 = *(Scaleform::GFx::ASStringNode **)&v34.M[0][2];
      if ( (*(_DWORD *)(*(_QWORD *)&v34.M[0][2] + 24i64))-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      return;
    }
    v22 = matrixa.M[0][0];
    v23 = matrixa.M[1][0];
    v24 = matrixa.M[0][1] * 0.0;
    matrixa.M[0][0] = (float)(matrixa.M[0][0] * 0.050000001) + (float)(matrixa.M[0][1] * 0.0);
    v25 = matrixa.M[1][1] * 0.0;
    matrixa.M[1][0] = (float)(matrixa.M[1][0] * 0.050000001) + (float)(matrixa.M[1][1] * 0.0);
    v26 = v22 * 0.0;
    matrixa.M[0][1] = (float)(matrixa.M[0][1] * 0.050000001) + v26;
    v27 = v23 * 0.0;
    matrixa.M[1][1] = (float)(matrixa.M[1][1] * 0.050000001) + v27;
    matrixa.M[1][2] = 0.0;
    matrixa.M[0][2] = 0.0;
    matrixa.M[0][3] = matrixa.M[0][3] + (float)(v26 + v24);
    matrixa.M[1][3] = matrixa.M[1][3] + (float)(v27 + v25);
    v28 = *(Scaleform::GFx::DisplayObjectBase **)&source->Transparent;
    if ( v28 )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v28);
      Scaleform::GFx::MovieImpl::UpdateAllRenderNodes((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor);
      v30 = (Scaleform::Render::Rect<long> *)v34.M[1];
      if ( !v39 )
        v30 = 0i64;
      Scaleform::Render::DrawableImage::Draw(DrawableImageFromBitmapData, RenderNode, &matrixa, &cform, v11, v30);
    }
  }
}

// File Line: 530
// RVA: 0x847680
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::fillRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::Render::Color color)
{
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  double x; // xmm0_8
  double y; // xmm1_8
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::Render::Color colora; // [rsp+60h] [rbp+18h] BYREF

  if ( rect )
  {
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    if ( DrawableImageFromBitmapData )
    {
      colora = color;
      x = rect->x;
      v14.ID = (int)x;
      y = rect->y;
      *((_DWORD *)&v14.ID + 1) = (int)y;
      LODWORD(v14.Message.pNode) = (int)(x + rect->width);
      HIDWORD(v14.Message.pNode) = (int)(y + rect->height);
      Scaleform::Render::DrawableImage::FillRect(
        DrawableImageFromBitmapData,
        (Scaleform::Render::Rect<long> *)&v14,
        (Scaleform::Render::Color)&colora);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  pNode = v14.Message.pNode;
  if ( v14.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 544
// RVA: 0x8486B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::floodFill(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VM::ErrorID x,
        int y,
        unsigned int color)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Color v12; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h] BYREF
  __int64 v14; // [rsp+38h] [rbp-10h]

  v14 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    v12 = (Scaleform::Render::Color)color;
    v13.ID = x;
    *((_DWORD *)&v13.ID + 1) = y;
    Scaleform::Render::DrawableImage::FloodFill(
      DrawableImageFromBitmapData,
      (Scaleform::Render::Point<long> *)&v13,
      (Scaleform::Render::Color)&v12);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v13.Message.pNode;
    if ( v13.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 555
// RVA: 0x849F30
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::generateFilterRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *filter)
{
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  Scaleform::GFx::AS3::VM::Error v23; // [rsp+30h] [rbp-C8h] BYREF
  Scaleform::Render::Rect<float> resulta; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v25; // [rsp+50h] [rbp-A8h]
  char ptr[24]; // [rsp+60h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value v27; // [rsp+78h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::Value v28; // [rsp+98h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value v29; // [rsp+B8h] [rbp-40h] BYREF

  v25 = -2i64;
  if ( !sourceRect || !filter )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v8,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  if ( !Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    pNode = v23.Message.pNode;
    if ( v23.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  resulta = 0i64;
  v12 = (float)(int)(sourceRect->height + sourceRect->y) * 20.0;
  v13 = (float)(int)(sourceRect->width + sourceRect->x) * 20.0;
  v14 = (float)(int)sourceRect->y * 20.0;
  v23.ID = (int)(float)((float)(int)sourceRect->x * 20.0);
  *((_DWORD *)&v23.ID + 1) = (int)v14;
  LODWORD(v23.Message.pNode) = (int)v13;
  HIDWORD(v23.Message.pNode) = (int)v12;
  Scaleform::Render::DrawableImage::CalcFilterRect(
    &resulta,
    (Scaleform::Render::Rect<long> *)&v23,
    filter->FilterData.pObject);
  `eh vector constructor iterator(ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  v15 = resulta.x1 * 0.050000001;
  if ( (float)(resulta.x1 * 0.050000001) <= 0.0 )
    v16 = v15 - 0.5;
  else
    v16 = v15 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)ptr, (double)(int)v16);
  v17 = resulta.y1 * 0.050000001;
  if ( (float)(resulta.y1 * 0.050000001) <= 0.0 )
    v18 = v17 - 0.5;
  else
    v18 = v17 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v27, (double)(int)v18);
  v19 = (float)(resulta.x2 - resulta.x1) * 0.050000001;
  if ( v19 <= 0.0 )
    v20 = v19 - 0.5;
  else
    v20 = v19 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v28, (double)(int)v20);
  v21 = (float)(resulta.y2 - resulta.y1) * 0.050000001;
  if ( v21 <= 0.0 )
    v22 = v21 - 0.5;
  else
    v22 = v21 + 0.5;
  Scaleform::GFx::AS3::Value::SetNumber(&v29, (double)(int)v22);
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    this->pTraits.pObject->pVM[1].ExceptionObj.value.VS._1.VObj,
    4u,
    (Scaleform::GFx::AS3::Value *)ptr);
  `eh vector destructor iterator(ptr, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 582
// RVA: 0x84AF80
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getColorBoundsRect(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        unsigned int mask,
        unsigned int color)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult v12[8]; // [rsp+28h] [rbp-61h] BYREF
  Scaleform::Render::Rect<long> resulta; // [rsp+30h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+40h] [rbp-49h] BYREF
  __int64 v15; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-31h] BYREF
  int v17; // [rsp+78h] [rbp-11h]
  __int64 v18; // [rsp+80h] [rbp-9h]
  int y1; // [rsp+88h] [rbp-1h]
  int v20; // [rsp+98h] [rbp+Fh]
  __int64 v21; // [rsp+A0h] [rbp+17h]
  int v22; // [rsp+A8h] [rbp+1Fh]
  int v23; // [rsp+B8h] [rbp+2Fh]
  __int64 v24; // [rsp+C0h] [rbp+37h]
  int v25; // [rsp+C8h] [rbp+3Fh]
  bool v26; // [rsp+108h] [rbp+7Fh]

  v15 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    Scaleform::Render::DrawableImage::GetColorBoundsRect(DrawableImageFromBitmapData, &resulta, mask, color, v26);
    argv.Flags = 2;
    argv.Bonus.pWeakProxy = 0i64;
    argv.value.VS._1.VInt = resulta.x1;
    v17 = 2;
    v18 = 0i64;
    y1 = resulta.y1;
    v20 = 2;
    v21 = 0i64;
    v22 = resulta.x2 - resulta.x1;
    v23 = 2;
    v24 = 0i64;
    v25 = resulta.y2 - resulta.y1;
    Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
      this->pTraits.pObject->pVM,
      v12,
      result,
      "flash.geom.Rectangle",
      4u,
      &argv);
    `eh vector destructor iterator(&argv, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 596
// RVA: 0x84C2C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result,
        int x,
        int y)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Color resulta; // [rsp+20h] [rbp-28h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h] BYREF

  v13 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    *result = Scaleform::Render::DrawableImage::GetPixel(DrawableImageFromBitmapData, &resulta, x, y)->Raw;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 606
// RVA: 0x84C210
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixel32(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int *result,
        int x,
        int y)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Color resulta; // [rsp+20h] [rbp-28h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h] BYREF

  v13 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    *result = Scaleform::Render::DrawableImage::GetPixel32(DrawableImageFromBitmapData, &resulta, x, y)->Raw;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 616
// RVA: 0x84C370
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rsi
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  double height; // xmm2_8
  double width; // xmm0_8
  int y; // r8d
  int v15; // edx
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v16; // rax
  Scaleform::Render::Rect<long> sourceRect; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::DIPixelProvider provider; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v19; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+48h] [rbp-20h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> resulta; // [rsp+70h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 2007, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v7, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 2015, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v11, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    pNode = v20.Message.pNode;
    if ( v20.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  height = rect->height;
  width = rect->width;
  sourceRect.x1 = (int)rect->x;
  y = (int)rect->y;
  sourceRect.y1 = y;
  sourceRect.x2 = (int)(width + rect->x);
  v15 = (int)(height + rect->y);
  sourceRect.y2 = v15;
  if ( sourceRect.x2 != sourceRect.x1 && v15 != y )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
      &resulta,
      (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)pVM->TraitsByteArray.pObject->ITraits.pObject);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
      result,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)resulta.pV);
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
      (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)result->pObject,
      4 * (sourceRect.y2 - sourceRect.y1) * (sourceRect.x2 - sourceRect.x1));
    v16 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)result->pObject;
    provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable;
    v19 = v16;
    Scaleform::Render::DrawableImage::GetPixels(DrawableImageFromBitmapData, &provider, &sourceRect);
  }
}

// File Line: 642
// RVA: 0x84D160
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getVector(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rbp
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  double height; // xmm2_8
  double width; // xmm0_8
  int y; // r8d
  int v14; // edx
  Scaleform::GFx::AS3::CheckResult *v15; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v18; // rax
  Scaleform::Render::Rect<long> sourceRect; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::Render::DIPixelProvider provider; // [rsp+58h] [rbp-20h] BYREF
  int v22; // [rsp+60h] [rbp-18h]
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v23; // [rsp+68h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+90h] [rbp+18h] BYREF

  if ( !rect )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v10,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    pNode = v20.Message.pNode;
    if ( v20.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  height = rect->height;
  width = rect->width;
  sourceRect.x1 = (int)rect->x;
  y = (int)rect->y;
  sourceRect.y1 = y;
  sourceRect.x2 = (int)(width + rect->x);
  v14 = (int)(height + rect->y);
  sourceRect.y2 = v14;
  if ( sourceRect.x2 != sourceRect.x1 && v14 != y )
  {
    v15 = Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
            this->pTraits.pObject->pVM,
            &resulta,
            result,
            "Vector.<uint>",
            0,
            0i64);
    pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)result->pObject;
    if ( v15->Result )
    {
      Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthSet(
        pObject,
        4 * (sourceRect.y2 - sourceRect.y1) * (sourceRect.x2 - sourceRect.x1));
      v18 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)result->pObject;
      provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable;
      v22 = 0;
      v23 = v18;
      Scaleform::Render::DrawableImage::GetPixels(DrawableImageFromBitmapData, &provider, &sourceRect);
    }
    else if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      result->pObject = 0i64;
    }
  }
}

// File Line: 667
// RVA: 0x84EA40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::hitTest(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *firstPoint,
        unsigned int firstAlphaThreshold,
        Scaleform::GFx::AS3::Value *secondObject,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *secondBitmapDataPoint,
        unsigned int secondAlphaThreshold)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r14
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  double *VStr; // rax
  double v14; // xmm3_8
  double v15; // xmm2_8
  double v16; // xmm1_8
  double v17; // xmm0_8
  Scaleform::GFx::AS3::Value::V1U v18; // rax
  int v19; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v20; // rcx
  Scaleform::GFx::ImageResource *ImageResource; // rax
  Scaleform::Render::DrawableImage *pImage; // rax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Point<long> secondPoint; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Render::Point<long> firstPointa; // [rsp+38h] [rbp-28h] BYREF
  __int64 v28; // [rsp+40h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+48h] [rbp-18h] BYREF

  v28 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( !DrawableImageFromBitmapData )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v29, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v12,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_21;
  }
  firstPointa.x = (int)firstPoint->x;
  firstPointa.y = (int)firstPoint->y;
  if ( Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         secondObject,
         "flash.geom.Rectangle",
         this->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    VStr = (double *)secondObject->value.VS._1.VStr;
    v14 = VStr[10];
    v15 = VStr[7];
    v16 = VStr[9];
    v17 = VStr[8];
    v29.ID = (int)v16;
    *((_DWORD *)&v29.ID + 1) = (int)v14;
    LODWORD(v29.Message.pNode) = (int)(v17 + v16);
    HIDWORD(v29.Message.pNode) = (int)(v15 + v14);
LABEL_5:
    *result = Scaleform::Render::DrawableImage::HitTest(
                DrawableImageFromBitmapData,
                &firstPointa,
                (Scaleform::Render::Rect<long> *)&v29,
                firstAlphaThreshold);
    return;
  }
  if ( Scaleform::GFx::AS3::VM::IsOfType(
         this->pTraits.pObject->pVM,
         secondObject,
         "flash.geom.Point",
         this->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    v18 = secondObject->value.VS._1;
    v19 = (int)*(double *)&v18.VStr[1].RefCount;
    v29.ID = (int)*(double *)&v18.VStr[1].pLower;
    *((_DWORD *)&v29.ID + 1) = v19;
    LODWORD(v29.Message.pNode) = v29.ID + 1;
    HIDWORD(v29.Message.pNode) = v19 + 1;
    if ( !firstAlphaThreshold )
      firstAlphaThreshold = 1;
    goto LABEL_5;
  }
  secondPoint = 0i64;
  if ( !Scaleform::GFx::AS3::VM::IsOfType(
          this->pTraits.pObject->pVM,
          secondObject,
          "flash.display.Bitmap",
          this->pTraits.pObject->pVM->CurrentDomain.pObject) )
  {
    if ( !Scaleform::GFx::AS3::VM::IsOfType(
            this->pTraits.pObject->pVM,
            secondObject,
            "flash.display.BitmapData",
            this->pTraits.pObject->pVM->CurrentDomain.pObject) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v29, 1508, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v23,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_21:
      pNode = v29.Message.pNode;
      if ( v29.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    if ( secondBitmapDataPoint )
    {
      secondPoint.x = (int)secondBitmapDataPoint->x;
      secondPoint.y = (int)secondBitmapDataPoint->y;
    }
    pImage = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
               this,
               (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)secondObject->value.VS._1.VStr);
LABEL_19:
    *result = Scaleform::Render::DrawableImage::HitTest(
                DrawableImageFromBitmapData,
                pImage,
                &firstPointa,
                &secondPoint,
                firstAlphaThreshold,
                secondAlphaThreshold);
    return;
  }
  v20 = *(Scaleform::GFx::AS3::Instances::fl_display::BitmapData **)&secondObject->value.VS._1.VStr[2].RefCount;
  if ( v20 )
  {
    ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(v20);
    if ( ImageResource )
    {
      pImage = (Scaleform::Render::DrawableImage *)ImageResource->pImage;
      if ( pImage )
        goto LABEL_19;
    }
  }
}

// File Line: 724
// RVA: 0x84E190
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *hRect)
{
  Scaleform::Render::Rect<long> *v5; // rbx
  double y; // xmm3_8
  double x; // xmm1_8
  long double v8; // xmm0_8
  long double v9; // xmm2_8
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rax
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  unsigned int v14; // r12d
  __int64 v15; // r15
  unsigned int v16; // edi
  unsigned int *v17; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx
  __int64 v19; // rcx
  unsigned int v20; // eax
  bool v21; // bl
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // rdx
  Scaleform::GFx::AS3::Instances::fl::Object *v28; // rcx
  Scaleform::GFx::AS3::Value::V1U v29; // rdx
  bool v30; // bl
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v31; // rcx
  unsigned int v32; // eax
  char v33[8]; // [rsp+30h] [rbp-D0h] BYREF
  int v34; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v35; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value v36; // [rsp+48h] [rbp-B8h] BYREF
  int v37; // [rsp+68h] [rbp-98h] BYREF
  _DWORD *v38; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASStringNode *v39; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v40; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::Value v; // [rsp+88h] [rbp-78h] BYREF
  __int64 v42; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value::V2U v43; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::AS3::Value v44; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::VM::Error v45; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::Multiname v46; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v47[2]; // [rsp+120h] [rbp+20h] BYREF
  Scaleform::GFx::AS3::Value::VU v48; // [rsp+130h] [rbp+30h]
  __int64 v49[2]; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::GFx::AS3::Value::VU v50; // [rsp+150h] [rbp+50h]
  __int64 ptr[4]; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::GFx::AS3::Value v52; // [rsp+180h] [rbp+80h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+1A0h] [rbp+A0h] BYREF
  __int64 v54; // [rsp+1C0h] [rbp+C0h]
  unsigned int colors[4][256]; // [rsp+1D0h] [rbp+D0h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+1220h] [rbp+1120h] BYREF
  char v57; // [rsp+1228h] [rbp+1128h] BYREF

  v54 = -2i64;
  v42 = 0i64;
  v43.VObj = 0i64;
  v5 = 0i64;
  if ( hRect )
  {
    y = hRect->y;
    x = hRect->x;
    v8 = hRect->width + x;
    v9 = hRect->height + y;
    LODWORD(v42) = (int)x;
    HIDWORD(v42) = (int)y;
    LODWORD(v43.VObj) = (int)v8;
    HIDWORD(v43.pTraits) = (int)v9;
    v5 = (Scaleform::Render::Rect<long> *)&v42;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    Scaleform::Render::DrawableImage::Histogram(DrawableImageFromBitmapData, v5, colors);
    argv.Flags = 3;
    argv.Bonus.pWeakProxy = 0i64;
    argv.value.VS._1.VInt = 4;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::VM::ConstructBuiltinValue(
           this->pTraits.pObject->pVM,
           &resulta,
           &v,
           "Vector.<Vector.<Number>>",
           1u,
           &argv)->Result )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        result,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v.value.VS._1.VStr);
      `eh vector constructor iterator(
        ptr,
        8ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure);
      v14 = 0;
      v15 = 0i64;
      while ( 2 )
      {
        v52.Flags = 3;
        v52.Bonus.pWeakProxy = 0i64;
        v52.value.VS._1.VInt = 256;
        if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
               this->pTraits.pObject->pVM,
               &resulta,
               (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&ptr[v14],
               "Vector.<Number>",
               1u,
               &v52)->Result )
        {
          v16 = 0;
          v17 = colors[v15];
          do
          {
            LODWORD(v47[0]) = 3;
            v47[1] = 0i64;
            v48.VS._1.VInt = v16;
            pObject = this->pTraits.pObject->pVM->PublicNamespace.pObject;
            v34 = 0;
            v35 = pObject;
            if ( pObject )
              pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
            v36.Flags = 0;
            v36.Bonus.pWeakProxy = 0i64;
            _mm_prefetch((const char *)v47, 2);
            *(_QWORD *)&v36.Flags = v47[0];
            v36.Bonus.pWeakProxy = 0i64;
            v36.value = v48;
            v19 = ptr[v15];
            v20 = *v17;
            v37 = 3;
            v38 = 0i64;
            LODWORD(v39) = v20;
            v21 = *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, int *, int *))(*(_QWORD *)v19 + 24i64))(
                              v19,
                              &v57,
                              &v34,
                              &v37) == 0;
            if ( (v37 & 0x1Fu) > 9 )
            {
              if ( (v37 & 0x200) != 0 )
              {
                v13 = (*v38)-- == 1;
                if ( v13 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                v38 = 0i64;
                v39 = 0i64;
                v40 = 0i64;
                v37 &= 0xFFFFFDE0;
              }
              else
              {
                switch ( v37 & 0x1F )
                {
                  case 0xA:
                    v22 = v39;
                    v13 = v39->RefCount-- == 1;
                    if ( v13 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
                    break;
                  case 0xB:
                  case 0xC:
                  case 0xD:
                  case 0xE:
                  case 0xF:
                    v23 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v39;
                    if ( ((unsigned __int8)v39 & 1) == 0 )
                      goto LABEL_24;
                    v39 = (Scaleform::GFx::ASStringNode *)((char *)v39 - 1);
                    break;
                  case 0x10:
                  case 0x11:
                    v23 = v40;
                    if ( ((unsigned __int8)v40 & 1) != 0 )
                    {
                      v40 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v40 - 1);
                    }
                    else
                    {
LABEL_24:
                      if ( v23 )
                      {
                        RefCount = v23->RefCount;
                        if ( (RefCount & 0x3FFFFF) != 0 )
                        {
                          v23->RefCount = RefCount - 1;
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
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
              if ( (v36.Flags & 0x1F) > 9 )
              {
                if ( (v36.Flags & 0x200) != 0 )
                {
                  v13 = v36.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v13 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&v36.Bonus, 0, 24);
                  v36.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
                }
              }
              v31 = v35;
              if ( v35 )
              {
                if ( ((unsigned __int8)v35 & 1) != 0 )
                {
                  v35 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v35 - 1);
                }
                else
                {
                  v32 = v35->RefCount;
                  if ( (v32 & 0x3FFFFF) != 0 )
                  {
                    v35->RefCount = v32 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
                  }
                }
              }
              goto LABEL_69;
            }
            if ( (v36.Flags & 0x1F) > 9 )
            {
              if ( (v36.Flags & 0x200) != 0 )
              {
                v13 = v36.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v13 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&v36.Bonus, 0, 24);
                v36.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
              }
            }
            v25 = v35;
            if ( v35 )
            {
              if ( ((unsigned __int8)v35 & 1) != 0 )
              {
                v35 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v35 - 1);
              }
              else
              {
                v26 = v35->RefCount;
                if ( (v26 & 0x3FFFFF) != 0 )
                {
                  v35->RefCount = v26 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
                }
              }
            }
            ++v16;
            ++v17;
          }
          while ( v16 < 0x100 );
          LODWORD(v49[0]) = 3;
          v49[1] = 0i64;
          v50.VS._1.VInt = v14;
          v27 = this->pTraits.pObject->pVM->PublicNamespace.pObject;
          v46.Kind = MN_QName;
          v46.Obj.pObject = v27;
          if ( v27 )
            v27->RefCount = (v27->RefCount + 1) & 0x8FBFFFFF;
          v46.Name.Flags = 0;
          v46.Name.Bonus.pWeakProxy = 0i64;
          _mm_prefetch((const char *)v49, 2);
          *(_QWORD *)&v46.Name.Flags = v49[0];
          v46.Name.Bonus.pWeakProxy = 0i64;
          v46.Name.value = v50;
          v28 = result->pObject;
          v44.Flags = 0;
          v44.Bonus.pWeakProxy = 0i64;
          v29.VStr = (Scaleform::GFx::ASStringNode *)ptr[v15];
          v44.Flags = 12;
          v44.value.VS._1 = v29;
          v44.value.VS._2 = v43;
          if ( v29.VStr )
            v29.VStr->Size = (v29.VStr->Size + 1) & 0x8FBFFFFF;
          v30 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v28->vfptr[1].ForEachChild_GC)(
                            v28,
                            v33,
                            &v46,
                            &v44) == 0;
          if ( (v44.Flags & 0x1F) > 9 )
          {
            if ( (v44.Flags & 0x200) != 0 )
            {
              v13 = v44.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v44.Bonus, 0, 24);
              v44.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
            }
          }
          Scaleform::GFx::AS3::Multiname::~Multiname(&v46);
          if ( v30 )
            break;
          `eh vector destructor iterator(
            &v52,
            0x20ui64,
            1,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
          ++v14;
          ++v15;
          if ( v14 < 4 )
            continue;
          `eh vector destructor iterator(
            ptr,
            8ui64,
            4,
            (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
          if ( (v.Flags & 0x1F) <= 9 )
            goto LABEL_76;
          if ( (v.Flags & 0x200) == 0 )
            goto LABEL_75;
          v13 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          goto LABEL_74;
        }
        break;
      }
LABEL_69:
      `eh vector destructor iterator(
        &v52,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      `eh vector destructor iterator(
        ptr,
        8ui64,
        4,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
    }
    if ( (v.Flags & 0x1F) <= 9 )
    {
LABEL_76:
      `eh vector destructor iterator(
        &argv,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      return;
    }
    if ( (v.Flags & 0x200) == 0 )
    {
LABEL_75:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      goto LABEL_76;
    }
    v13 = v.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v13 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_74:
    memset(&v.Bonus, 0, 24);
    v.Flags &= 0xFFFFFDE0;
    goto LABEL_76;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v45, 2015, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTraits.pObject->pVM,
    v11,
    &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v45.Message.pNode;
  v13 = v45.Message.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 772
// RVA: 0x854280
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::merge(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VStr; // rbx
  double *v7; // r15
  Scaleform::GFx::AS3::Value::V1U v8; // r12
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rbp
  Scaleform::Render::DrawableImage *v10; // r14
  unsigned int *v11; // rbx
  Scaleform::GFx::AS3::Value *v12; // rdi
  __int64 v13; // rsi
  double v14; // xmm0_8
  double v15; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::Render::Point<long> destPoint; // [rsp+40h] [rbp-58h] BYREF
  __int64 v20; // [rsp+48h] [rbp-50h]
  unsigned int redMult[4]; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::Render::Rect<long> sourceRect; // [rsp+60h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+18h] BYREF

  if ( argc == 7 )
  {
    v20 = -2i64;
    VStr = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VStr;
    v7 = (double *)argv[1].value.VS._1.VStr;
    v8 = argv[2].value.VS._1;
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v10 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, VStr);
    if ( v10 && DrawableImageFromBitmapData )
    {
      v11 = redMult;
      v12 = argv + 3;
      v13 = 4i64;
      do
      {
        Scaleform::GFx::AS3::Value::Convert2UInt32(v12++, &resulta, v11++);
        --v13;
      }
      while ( v13 );
      destPoint.x = (int)*(double *)&v8.VStr[1].pLower;
      destPoint.y = (int)*(double *)&v8.VStr[1].RefCount;
      v14 = v7[9];
      sourceRect.x1 = (int)v14;
      v15 = v7[10];
      sourceRect.y1 = (int)v15;
      sourceRect.x2 = (int)(v14 + v7[8]);
      sourceRect.y2 = (int)(v15 + v7[7]);
      Scaleform::Render::DrawableImage::Merge(
        DrawableImageFromBitmapData,
        v10,
        &sourceRect,
        &destPoint,
        redMult[0],
        redMult[1],
        redMult[2],
        redMult[3]);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&sourceRect,
        2015,
        this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v16,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v17 = *(Scaleform::GFx::ASStringNode **)&sourceRect.x2;
      if ( (*(_DWORD *)(*(_QWORD *)&sourceRect.x2 + 24i64))-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
}

// File Line: 798
// RVA: 0x8554C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::noise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int randomSeed,
        unsigned int low,
        unsigned int high,
        unsigned int channelOptions,
        bool grayScale)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+38h] [rbp-20h] BYREF

  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    Scaleform::Render::DrawableImage::Noise(
      DrawableImageFromBitmapData,
      randomSeed,
      low,
      high,
      channelOptions,
      grayScale);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v11,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 809
// RVA: 0x855B80
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::paletteMap(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // rax
  Scaleform::GFx::AS3::Value::V1U v7; // rdx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  unsigned int v9; // edi
  unsigned int v10; // r12d
  __int64 v11; // rbx
  Scaleform::GFx::AS3::Value::V1U v12; // rdx
  Scaleform::GFx::AS3::Impl::SparseArray *v13; // r14
  unsigned __int64 v14; // rsi
  __int64 v15; // rbp
  Scaleform::GFx::AS3::Value *v16; // rax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rbx
  Scaleform::Render::DrawableImage *v18; // rax
  double *v19; // r8
  double v20; // xmm0_8
  double v21; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+30h] [rbp-1098h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData; // [rsp+40h] [rbp-1088h] BYREF
  Scaleform::GFx::AS3::Value::V1U v27; // [rsp+48h] [rbp-1080h]
  unsigned int *channels[522]; // [rsp+50h] [rbp-1078h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+10E0h] [rbp+18h] BYREF

  if ( argc >= 3 )
  {
    channels[4] = (unsigned int *)-2i64;
    sourceBitmapData = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VStr;
    v6 = argv[1].value.VS._1;
    *(Scaleform::GFx::AS3::Value::V1U *)&v25.ID = v6;
    v7 = argv[2].value.VS._1;
    v27 = v7;
    if ( sourceBitmapData && v6.VStr && v7.VStr )
    {
      v9 = 0;
      v10 = argc - 3;
      v11 = 0i64;
      do
      {
        if ( v9 < v10 )
        {
          v12 = argv[v9 + 3].value.VS._1;
          if ( v12.VStr )
          {
            channels[v11] = (unsigned int *)&channels[128 * (unsigned __int64)v9 + 10];
            v13 = (Scaleform::GFx::AS3::Impl::SparseArray *)&v12.VStr[1].16;
            v14 = 0i64;
            v15 = 256i64;
            do
            {
              v16 = Scaleform::GFx::AS3::Impl::SparseArray::At(v13, v14);
              Scaleform::GFx::AS3::Value::Convert2UInt32(v16, &resulta, &channels[v11][v14++]);
              --v15;
            }
            while ( v15 );
          }
          else
          {
            channels[v11] = 0i64;
          }
        }
        else
        {
          channels[v11] = 0i64;
        }
        ++v9;
        ++v11;
      }
      while ( v9 < 4 );
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
              this,
              sourceBitmapData);
      if ( DrawableImageFromBitmapData && v18 )
      {
        LODWORD(sourceBitmapData) = (int)*(double *)&v27.VStr[1].pLower;
        HIDWORD(sourceBitmapData) = (int)*(double *)&v27.VStr[1].RefCount;
        v19 = *(double **)&v25.ID;
        v20 = *(double *)(*(_QWORD *)&v25.ID + 72i64);
        v25.ID = (int)v20;
        v21 = v19[10];
        *((_DWORD *)&v25.ID + 1) = (int)v21;
        LODWORD(v25.Message.pNode) = (int)(v20 + v19[8]);
        HIDWORD(v25.Message.pNode) = (int)(v21 + v19[7]);
        Scaleform::Render::DrawableImage::PaletteMap(
          DrawableImageFromBitmapData,
          v18,
          (Scaleform::Render::Rect<long> *)&v25,
          (Scaleform::Render::Point<long> *)&sourceBitmapData,
          channels);
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 2015, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v22,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 2007, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v8,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    pNode = v25.Message.pNode;
    if ( v25.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 866
// RVA: 0x8564B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::perlinNoise(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  __int64 offsetCount; // r12
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  bool v9; // zf
  int v10; // ebx
  bool v11; // al
  char stitch; // r14
  char fractal; // r15
  bool v14; // al
  float *offsets; // rbx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r14
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  bool v19; // r15
  $09FB520FFAA77E97CDD800E2BDD737E6 *v20; // rcx
  unsigned __int64 v21; // r14
  char *v22; // rsi
  __int64 v23; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v24; // r12
  Scaleform::GFx::AS3::Value::V1U v25; // rdi
  bool v26; // bl
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::AS3::CheckResult grayScale[8]; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::AS3::CheckResult randomSeed[8]; // [rsp+68h] [rbp-70h] BYREF
  unsigned int channelMask[2]; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::VM::Error v33; // [rsp+78h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+90h] [rbp-48h] BYREF
  __int64 v35; // [rsp+B0h] [rbp-28h]
  char Dst[552]; // [rsp+B8h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+2F8h] [rbp+220h] BYREF

  v35 = -2i64;
  LODWORD(offsetCount) = 0;
  *(_DWORD *)&grayScale[4].Result = 0;
  if ( argc < 6 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v33, 1063, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v8,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_3:
    v9 = v29->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    return;
  }
  *(long double *)&v33.Message.pNode = DOUBLE_1_0;
  *(long double *)&v33.ID = DOUBLE_1_0;
  v10 = 1;
  channelMask[0] = 1;
  *(_DWORD *)&randomSeed[4].Result = 0;
  *(_DWORD *)&grayScale[4].Result = 1;
  v11 = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &resulta, (long double *)&v33.Message)->Result )
  {
    v10 = 3;
    *(_DWORD *)&grayScale[4].Result = 3;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &grayScale[1], (long double *)&v33)->Result )
    {
      v10 = 7;
      *(_DWORD *)&grayScale[4].Result = 7;
      if ( Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 2, grayScale, channelMask)->Result )
      {
        v10 = 15;
        *(_DWORD *)&grayScale[4].Result = 15;
        if ( Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 3, randomSeed, (unsigned int *)&randomSeed[4])->Result )
          v11 = 0;
      }
    }
  }
  if ( (v10 & 8) != 0 )
  {
    v10 &= ~8u;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( (v10 & 4) != 0 )
  {
    v10 &= ~4u;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( (v10 & 2) != 0 )
  {
    v10 &= ~2u;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( (v10 & 1) != 0 )
  {
    v10 &= ~1u;
    *(_DWORD *)&grayScale[4].Result = v10;
  }
  if ( v11 )
    return;
  stitch = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 4);
  resulta.Result = stitch;
  fractal = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 5);
  grayScale[0].Result = fractal;
  channelMask[1] = 7;
  v14 = 0;
  if ( argc >= 7 )
  {
    v10 |= 0x10u;
    *(_DWORD *)&grayScale[4].Result = v10;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 6, randomSeed, &channelMask[1])->Result )
      v14 = 1;
  }
  if ( (v10 & 0x10) != 0 )
    *(_DWORD *)&grayScale[4].Result = v10 & 0xFFFFFFEF;
  if ( v14 )
    return;
  if ( argc < 8 )
    grayScale[1].Result = 0;
  else
    grayScale[1].Result = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
  offsets = 0i64;
  if ( argc < 9 || !argv[8].value.VS._1.VStr )
  {
LABEL_62:
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    if ( DrawableImageFromBitmapData )
    {
      Scaleform::Render::DrawableImage::PerlinNoise(
        DrawableImageFromBitmapData,
        *(double *)&v33.Message.pNode,
        *(double *)&v33.ID,
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
    Scaleform::GFx::AS3::VM::Error::Error(&v33, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v28,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_3;
  }
  memset(Dst, 0, 0x200ui64);
  *(_QWORD *)channelMask = Dst;
  Flags = argv[8].Flags;
  v33.ID = Flags;
  pWeakProxy = argv[8].Bonus.pWeakProxy;
  v29 = (Scaleform::GFx::ASStringNode *)pWeakProxy;
  *(_QWORD *)&grayScale[0].Result = argv[8].value.VS._1.VStr;
  *(_QWORD *)&randomSeed[0].Result = argv[8].value.VS._2.VObj;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_44;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++argv[8].value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (Flags & 0x1F) <= 0xA )
        goto LABEL_44;
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = argv[8].value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_44;
        VObj = (Scaleform::GFx::AS3::Value::V1U)argv[8].value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_44:
  v19 = !Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           (Scaleform::GFx::AS3::Value *)&v33,
           "Array",
           this->pTraits.pObject->pVM->CurrentDomain.pObject);
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v9 = pWeakProxy->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      v29 = 0i64;
      *(_QWORD *)&grayScale[0].Result = 0i64;
      *(_QWORD *)&randomSeed[0].Result = 0i64;
      v33.ID = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v33);
    }
  }
  if ( !v19 )
  {
    v20 = &argv[8].value.VS._1.VStr[1].16;
    offsetCount = (__int64)v20->pLower;
    if ( (unsigned int)v20->pLower > 0x80 )
      offsetCount = 128i64;
    *(_QWORD *)&v33.ID = offsetCount;
    if ( (_DWORD)offsetCount )
    {
      v21 = 0i64;
      v22 = Dst;
      v23 = (unsigned int)offsetCount;
      v24 = (Scaleform::GFx::AS3::Impl::SparseArray *)v20;
      do
      {
        *(_QWORD *)v22 = 0i64;
        v25 = Scaleform::GFx::AS3::Impl::SparseArray::At(v24, v21)->value.VS._1;
        v.Flags = 12;
        v.Bonus.pWeakProxy = 0i64;
        v.value.VS._1 = v25;
        if ( v25.VStr )
          v25.VStr->Size = (v25.VStr->Size + 1) & 0x8FBFFFFF;
        v26 = Scaleform::GFx::AS3::VM::IsOfType(
                this->pTraits.pObject->pVM,
                &v,
                "flash.geom.Point",
                this->pTraits.pObject->pVM->CurrentDomain.pObject);
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        if ( v26 )
        {
          *(float *)v22 = *(double *)&v25.VStr[1].pLower;
          *((float *)v22 + 1) = *(double *)&v25.VStr[1].RefCount;
        }
        ++v21;
        v22 += 8;
        --v23;
      }
      while ( v23 );
      LODWORD(offsetCount) = v33.ID;
    }
    fractal = grayScale[0].Result;
    stitch = resulta.Result;
    offsets = *(float **)channelMask;
    goto LABEL_62;
  }
}      ++v21;
        v22 += 8;
        --v23;
      }
      while ( v23 );
      LODWORD(offsetCount) = v33.ID;
    }
    fractal = grayScale[0].Result;
    stitch = resulta.Result;
    offsets = *(float **)channelMask;
    goto LABEL_62;
  

// File Line: 929
// RVA: 0x857260
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::pixelDissolve(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        int *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *sourceRect,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *destPoint,
        int randomSeed,
        int numPixels,
        unsigned int fillColor)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v12; // rbp
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  unsigned int v14; // r14d
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // r15
  Scaleform::Render::DrawableImage *v17; // rax
  double x; // xmm0_8
  double y; // xmm1_8
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Point<long> v23; // [rsp+40h] [rbp-48h] BYREF
  __int64 v24; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+50h] [rbp-38h] BYREF
  Scaleform::Render::Color v26; // [rsp+A0h] [rbp+18h] BYREF

  v24 = -2i64;
  if ( sourceBitmapData && sourceRect && (v12 = destPoint) != 0i64 )
  {
    v14 = numPixels;
    if ( numPixels >= 0 )
    {
      DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                      this,
                                      this);
      v17 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
              this,
              sourceBitmapData);
      if ( DrawableImageFromBitmapData && v17 )
      {
        v26 = (Scaleform::Render::Color)fillColor;
        v23.x = (int)v12->x;
        v23.y = (int)v12->y;
        x = sourceRect->x;
        v25.ID = (int)x;
        y = sourceRect->y;
        *((_DWORD *)&v25.ID + 1) = (int)y;
        LODWORD(v25.Message.pNode) = (int)(x + sourceRect->width);
        HIDWORD(v25.Message.pNode) = (int)(y + sourceRect->height);
        *result = Scaleform::Render::DrawableImage::PixelDissolve(
                    DrawableImageFromBitmapData,
                    v17,
                    (Scaleform::Render::Rect<long> *)&v25,
                    &v23,
                    randomSeed,
                    v14,
                    (Scaleform::Render::Color)&v26);
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 2015, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v20,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 2027, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v15,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v13,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  }
  pNode = v25.Message.pNode;
  if ( v25.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 954
// RVA: 0x85AAC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::scroll(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        int x,
        int y)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h] BYREF

  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    Scaleform::Render::DrawableImage::Scroll(DrawableImageFromBitmapData, x, y);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v8,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v11.Message.pNode;
    if ( v11.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 965
// RVA: 0x85BB10
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        int x,
        int y,
        unsigned int color)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Color c; // [rsp+20h] [rbp-28h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h] BYREF

  v13 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    c = (Scaleform::Render::Color)color;
    Scaleform::Render::DrawableImage::SetPixel(DrawableImageFromBitmapData, x, y, (Scaleform::Render::Color)&c);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 975
// RVA: 0x85BA70
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixel32(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        int x,
        int y,
        unsigned int color)
{
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Color c; // [rsp+20h] [rbp-28h] BYREF
  __int64 v13; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-18h] BYREF

  v13 = -2i64;
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  this,
                                  this);
  if ( DrawableImageFromBitmapData )
  {
    c = (Scaleform::Render::Color)color;
    Scaleform::Render::DrawableImage::SetPixel32(DrawableImageFromBitmapData, x, y, (Scaleform::Render::Color)&c);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v9,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 985
// RVA: 0x85BBB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setPixels(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *inputByteArray)
{
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  double height; // xmm2_8
  double width; // xmm0_8
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::DIPixelProvider provider; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v18; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+38h] [rbp-20h] BYREF

  if ( rect && inputByteArray )
  {
    provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::`vftable;
    v18 = inputByteArray;
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    if ( DrawableImageFromBitmapData )
    {
      height = rect->height;
      width = rect->width;
      v19.ID = (int)rect->x;
      *((_DWORD *)&v19.ID + 1) = (int)rect->y;
      LODWORD(v19.Message.pNode) = (int)(width + rect->x);
      HIDWORD(v19.Message.pNode) = (int)(height + rect->y);
      if ( !Scaleform::Render::DrawableImage::SetPixels(
              DrawableImageFromBitmapData,
              (Scaleform::Render::Rect<long> *)&v19,
              &provider)
        && inputByteArray->Length < v18->Length )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v19, 2030, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v15, &Scaleform::GFx::AS3::fl::ErrorTI);
        pNode = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, 2015, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v11,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v12 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v8 = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 1007
// RVA: 0x85ED40
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::setVector(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *rect,
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *inputVector)
{
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  double height; // xmm2_8
  double width; // xmm0_8
  unsigned int v15; // ebx
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v18; // [rsp+20h] [rbp-40h] BYREF
  __int64 v19; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Render::DIPixelProvider provider; // [rsp+40h] [rbp-20h] BYREF
  int v22; // [rsp+48h] [rbp-18h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v23; // [rsp+50h] [rbp-10h]
  int resulta; // [rsp+90h] [rbp+30h] BYREF

  v19 = -2i64;
  if ( rect && inputVector )
  {
    provider.vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::`vftable;
    v22 = 0;
    v23 = inputVector;
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    if ( DrawableImageFromBitmapData )
    {
      height = rect->height;
      width = rect->width;
      v20.ID = (int)rect->x;
      *((_DWORD *)&v20.ID + 1) = (int)rect->y;
      LODWORD(v20.Message.pNode) = (int)(width + rect->x);
      HIDWORD(v20.Message.pNode) = (int)(height + rect->y);
      if ( !Scaleform::Render::DrawableImage::SetPixels(
              DrawableImageFromBitmapData,
              (Scaleform::Render::Rect<long> *)&v20,
              &provider) )
      {
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(inputVector, &resulta);
        v15 = resulta;
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::lengthGet(v23, &v18);
        if ( v15 < v18 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v20, 1506, this->pTraits.pObject->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this->pTraits.pObject->pVM,
            v16,
            &Scaleform::GFx::AS3::fl::ErrorTI);
          pNode = v20.Message.pNode;
          v9 = v20.Message.pNode->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v20, 2015, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v11,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v12 = v20.Message.pNode;
      v9 = v20.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 2007, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v7,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v8 = v20.Message.pNode;
    v9 = v20.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 1030
// RVA: 0x860BE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::threshold(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *VStr; // r13
  Scaleform::GFx::AS3::Value::V1U v8; // rax
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *pData; // rcx
  Scaleform::Render::DrawableImage::OperationType op; // r14d
  char v14; // r12
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // rbx
  Scaleform::Render::DrawableImage *v18; // rax
  Scaleform::Render::DrawableImage *v19; // rdx
  Scaleform::Render::Point<long> v20; // rax
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+30h] [rbp-11h] BYREF
  unsigned int color; // [rsp+40h] [rbp-1h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+7h] BYREF
  unsigned int mask; // [rsp+50h] [rbp+Fh] BYREF
  Scaleform::Render::Point<long> destPoint; // [rsp+58h] [rbp+17h] BYREF
  unsigned int threshold; // [rsp+60h] [rbp+1Fh] BYREF
  __int64 v31; // [rsp+68h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult v32; // [rsp+B8h] [rbp+77h] BYREF

  if ( argc >= 5 )
  {
    v31 = -2i64;
    VStr = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)argv->value.VS._1.VStr;
    v8 = argv[1].value.VS._1;
    *(Scaleform::GFx::AS3::Value::V1U *)&v25.ID = v8;
    v9 = argv[2].value.VS._1;
    destPoint = (Scaleform::Render::Point<long>)v9.VStr;
    if ( !VStr || !v8.VStr || !v9.VStr )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 2007, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v10,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      pNode = v25.Message.pNode;
      goto LABEL_50;
    }
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv + 3, &resulta);
    pData = resulta.pNode->pData;
    if ( *resulta.pNode->pData == asc_14169F280[0] && pData[1] == 61 && !pData[2] )
    {
      op = Operator_LE;
    }
    else if ( *pData == asc_14167E65C[0] && pData[1] == asc_14167E65C[1] )
    {
      op = Operator_LT;
    }
    else if ( *pData == asc_14167E638[0] && pData[1] == asc_14167E638[1] )
    {
      op = Operator_GT;
    }
    else if ( *pData == asc_14169F27C[0] && pData[1] == 61 && !pData[2] )
    {
      op = Operator_GE;
    }
    else if ( *pData == asc_14186CBC8[0] && pData[1] == 61 && !pData[2] )
    {
      op = Operator_NE;
    }
    else
    {
      if ( *pData != asc_141743BB0[0] || pData[1] != 61 || pData[2] )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v25, 1508, this->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this->pTraits.pObject->pVM,
          v22,
          &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        goto LABEL_47;
      }
      op = Operator_EQ;
    }
    color = 0;
    mask = -1;
    v14 = 1;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 4, &v32, &threshold)->Result )
      goto LABEL_49;
    if ( argc >= 6 && !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 5, &v32, &color)->Result )
      goto LABEL_49;
    if ( argc >= 7 && !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 6, &v32, &mask)->Result )
      goto LABEL_49;
    if ( argc >= 8 )
      v14 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 7);
    DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                    this,
                                    this);
    v18 = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, VStr);
    v19 = v18;
    if ( DrawableImageFromBitmapData && v18 )
    {
      v20 = destPoint;
      destPoint.x = (int)*(double *)(*(_QWORD *)&destPoint + 56i64);
      destPoint.y = (int)*(double *)(*(_QWORD *)&v20 + 64i64);
      LOBYTE(color) = v14;
      Scaleform::Render::DrawableImage::Threshold(
        DrawableImageFromBitmapData,
        v19,
        (Scaleform::Render::Rect<long> *)&v25,
        &destPoint,
        op,
        threshold,
        color,
        mask,
        v14);
LABEL_49:
      pNode = resulta.pNode;
LABEL_50:
      v24 = pNode->RefCount-- == 1;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 2015, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v21,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_47:
    v23 = v25.Message.pNode;
    v24 = v25.Message.pNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    goto LABEL_49;
  }
}

// File Line: 1120
// RVA: 0x789A90
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::~BitmapData(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this)
{
  Scaleform::GFx::ImageResource *pObject; // rcx
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::GFx::MovieDefImpl *v4; // rcx
  Scaleform::GFx::MovieDefImpl *v5; // rcx
  Scaleform::Render::ImageBase *v6; // rcx
  Scaleform::GFx::ImageResource *v7; // rcx

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vftable;
  pObject = this->pImageResource.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImageResource.pObject = 0i64;
  v3 = this->pImage.pObject;
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v3->vfptr[2].__vecDelDtor)(v3);
  this->pImage.pObject = 0i64;
  v4 = this->pDefImpl.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  this->pDefImpl.pObject = 0i64;
  v5 = this->pDefImpl.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  v6 = this->pImage.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v6->vfptr[2].__vecDelDtor)(v6);
  v7 = this->pImageResource.pObject;
  if ( v7 )
    Scaleform::GFx::Resource::Release(v7);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 1129
// RVA: 0x7F2D10
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        bool extCall)
{
  if ( !extCall )
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(this, 0i64, 0i64);
}

// File Line: 1139
// RVA: 0x7BD9A0
bool __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::ImageResource *imgRes,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::ImageResource *pObject; // rcx
  Scaleform::Render::ImageBase *pImage; // rdi
  Scaleform::Render::ImageBase *v8; // rcx
  Scaleform::GFx::MovieDefImpl *v9; // rcx
  Scaleform::GFx::AS3::ASVM *pVM; // rdi
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // rsi
  Scaleform::GFx::AS3::Traits *v12; // rcx
  bool v13; // bp
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // rbx
  Scaleform::Log *v15; // rdi
  const char *pData; // rdi
  Scaleform::Log *v17; // rbx
  Scaleform::GFx::ImageResource *v18; // rdi
  Scaleform::GFx::ImageResource *v19; // rcx
  Scaleform::Render::ImageBase *v20; // rdi
  Scaleform::Render::ImageBase *v21; // rcx
  Scaleform::GFx::MovieDefImpl *pOwnerDefImpl; // rdi
  Scaleform::GFx::MovieDefImpl *v23; // rcx
  Scaleform::GFx::MovieDefImpl *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::Ptr<Scaleform::Log> v29; // [rsp+28h] [rbp-40h] BYREF
  __int64 v30; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::ASStringNode *v32; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::String symbol; // [rsp+88h] [rbp+20h] BYREF

  v30 = -2i64;
  if ( imgRes )
  {
    Scaleform::Render::RenderBuffer::AddRef(imgRes);
    pObject = this->pImageResource.pObject;
    if ( pObject )
      Scaleform::GFx::Resource::Release(pObject);
    this->pImageResource.pObject = imgRes;
    pImage = imgRes->pImage;
    if ( pImage )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(pImage);
    v8 = this->pImage.pObject;
    if ( v8 )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))v8->vfptr[2].__vecDelDtor)(v8);
    this->pImage.pObject = pImage;
    if ( defImpl )
      Scaleform::Render::RenderBuffer::AddRef(defImpl);
    v9 = this->pDefImpl.pObject;
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    this->pDefImpl.pObject = defImpl;
  }
  else
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
    if ( ResourceMovieDef )
    {
      v12 = this->pTraits.pObject;
      if ( (v12->Flags & 0x10) != 0 )
      {
        ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **, __int64))v12->vfptr[1].Finalize_GC)(
          v12,
          &v32,
          1i64);
        presBindData.pResource.pObject = 0i64;
        presBindData.pBinding = 0i64;
        Scaleform::String::String(&symbol, v32->pData);
        v13 = !Scaleform::GFx::MovieImpl::FindExportedResource(
                 pVM->pMovieRoot->pMovieImpl,
                 ResourceMovieDef,
                 &presBindData,
                 &symbol);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( v13 )
        {
          pMovieRoot = pVM->pMovieRoot;
          v15 = Scaleform::GFx::StateBag::GetLog(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v15 )
          {
            pData = v32->pData;
            v17 = Scaleform::GFx::StateBag::GetLog(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &v29)->pObject;
            if ( v29.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v29.pObject);
            Scaleform::Log::LogWarning(v17, "Attaching a bitmap with class %s failed", pData);
          }
        }
        else if ( presBindData.pResource.pObject
               && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)(presBindData.pResource.pObject) & 0xFF00) == 256 )
        {
          v18 = (Scaleform::GFx::ImageResource *)presBindData.pResource.pObject;
          if ( presBindData.pResource.pObject )
            Scaleform::Render::RenderBuffer::AddRef(presBindData.pResource.pObject);
          v19 = this->pImageResource.pObject;
          if ( v19 )
            Scaleform::GFx::Resource::Release(v19);
          this->pImageResource.pObject = v18;
          v20 = v18->pImage;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::Render::ImageBase *))v20->vfptr[1].__vecDelDtor)(v20);
          v21 = this->pImage.pObject;
          if ( v21 )
            ((void (__fastcall *)(Scaleform::Render::ImageBase *))v21->vfptr[2].__vecDelDtor)(v21);
          this->pImage.pObject = v20;
          if ( presBindData.pBinding )
          {
            pOwnerDefImpl = presBindData.pBinding->pOwnerDefImpl;
            if ( pOwnerDefImpl )
              Scaleform::Render::RenderBuffer::AddRef(pOwnerDefImpl);
            v23 = this->pDefImpl.pObject;
            if ( v23 )
              Scaleform::GFx::Resource::Release(v23);
            this->pDefImpl.pObject = pOwnerDefImpl;
          }
          else
          {
            Scaleform::Render::RenderBuffer::AddRef(ResourceMovieDef);
            v24 = this->pDefImpl.pObject;
            if ( v24 )
              Scaleform::GFx::Resource::Release(v24);
            this->pDefImpl.pObject = ResourceMovieDef;
          }
        }
        if ( presBindData.pResource.pObject )
          Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
        v25 = v32;
        if ( v32->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
  }
  return 0;
}

// File Line: 1190
// RVA: 0x7EA2F0
Scaleform::GFx::ImageResource *__fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this)
{
  Scaleform::GFx::ImageResource *result; // rax
  Scaleform::Render::ImageBase *pObject; // rdx
  Scaleform::GFx::ImageResource *v4; // rax
  Scaleform::GFx::ImageResource *v5; // rax
  Scaleform::GFx::ImageResource *v6; // rdi
  Scaleform::GFx::ImageResource *v7; // rcx
  int v8; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::ImageBase *v9; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ImageResource *v10; // [rsp+50h] [rbp+18h]

  result = this->pImageResource.pObject;
  if ( !result )
  {
    if ( !this->pImage.pObject )
      Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(this, this);
    pObject = this->pImage.pObject;
    if ( pObject )
    {
      v9 = this->pImage.pObject;
      v8 = 2;
      v4 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ImageBase *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              pObject,
                                              104i64,
                                              &v8,
                                              -2i64);
      v10 = v4;
      if ( v4 )
      {
        Scaleform::GFx::ImageResource::ImageResource(
          v4,
          (Scaleform::Render::ImageSource *)this->pImage.pObject,
          Use_Bitmap);
        v6 = v5;
      }
      else
      {
        v6 = 0i64;
      }
      v7 = this->pImageResource.pObject;
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
      this->pImageResource.pObject = v6;
      return v6;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 1212
// RVA: 0x7954A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v9; // [rsp+20h] [rbp-28h] BYREF
  __int64 v10; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+30h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+10h] BYREF
  int v13; // [rsp+68h] [rbp+20h] BYREF

  v10 = -2i64;
  if ( argc >= 2 )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv, &result, &v13)->Result )
    {
      this->Width = v13;
      if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &result, &v13)->Result )
      {
        this->Height = v13;
        v9 = -1;
        if ( argc >= 3 )
          this->Transparent = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
        if ( argc >= 4 )
          Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 3, &result, &v9);
        this->ClearColor.Raw = v9;
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1063, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v6,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v11.Message.pNode;
    if ( v11.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1248
// RVA: 0x84B4A0
Scaleform::Render::DrawableImage *__fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *sourceBitmapData)
{
  Scaleform::Render::ImageBase *pObject; // rcx
  Scaleform::Render::DrawableImageContext *dicontext; // r14
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  Scaleform::Render::ImageBase *v8; // rdi
  __int64 v9; // r12
  unsigned int Height; // esi
  unsigned int Width; // ebp
  Scaleform::Render::DrawableImage *v12; // r15
  Scaleform::Render::ImageFormat v13; // eax
  Scaleform::Render::ImageBase *v14; // rax
  Scaleform::Render::DrawableImage *v15; // rax
  Scaleform::Render::ImageBase *v16; // rax
  Scaleform::Render::ImageBase *v17; // rcx
  __int64 v18[12]; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::Render::DrawableImage *v19; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::Render::DrawableImage *v21; // [rsp+B8h] [rbp+20h]

  if ( !sourceBitmapData )
    return 0i64;
  pObject = sourceBitmapData->pImage.pObject;
  if ( !pObject
    || ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pObject->vfptr[3].__vecDelDtor)(pObject) != 6 )
  {
    dicontext = Scaleform::GFx::MovieImpl::GetDrawableImageContext((Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor);
    pRTCommandQueue = dicontext->pRTCommandQueue;
    if ( pRTCommandQueue )
    {
      v8 = 0i64;
      memset(v18, 0, 32);
      pRTCommandQueue->vfptr->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)v18);
      v9 = v18[0];
      if ( sourceBitmapData->pImageResource.pObject )
      {
        v15 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    200i64,
                                                    0i64);
        v19 = v15;
        if ( v15 )
        {
          Scaleform::Render::DrawableImage::DrawableImage(
            v15,
            1,
            sourceBitmapData->pImageResource.pObject->pImage,
            dicontext);
          v8 = v16;
        }
      }
      else
      {
        Height = sourceBitmapData->Height;
        Width = sourceBitmapData->Width;
        if ( Width * Height > 0xFFFFFF || Width > 0x1FFF || Height > 0x1FFF )
          return 0i64;
        v12 = (Scaleform::Render::DrawableImage *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    200i64,
                                                    0i64);
        v21 = v12;
        if ( v12 )
        {
          LODWORD(v19) = sourceBitmapData->ClearColor.Raw;
          size = (Scaleform::Render::Size<unsigned long>)__PAIR64__(Height, Width);
          v13 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 104i64))(v9);
          Scaleform::Render::DrawableImage::DrawableImage(
            v12,
            v13,
            (Scaleform::Render::Size<unsigned long>)&size,
            sourceBitmapData->Transparent,
            (Scaleform::Render::Color)&v19,
            dicontext);
          v8 = v14;
        }
      }
      v17 = sourceBitmapData->pImage.pObject;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))v17->vfptr[2].__vecDelDtor)(v17);
      sourceBitmapData->pImage.pObject = v8;
    }
  }
  return (Scaleform::Render::DrawableImage *)sourceBitmapData->pImage.pObject;
}

// File Line: 1405
// RVA: 0x7FF220
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 1427
// RVA: 0x743A00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapData::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::BitmapDataCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapData::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::BitmapDataCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::`vftable;
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

