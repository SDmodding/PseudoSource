// File Line: 45
// RVA: 0x77F8F0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::Math(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Math::`vftable;
  this->LN10 = 2.302585092994046;
  this->E = 2.718281828459045;
  this->LN2 = 0.6931471805599453;
  this->LOG10E = 0.4342944819032518;
  this->LOG2E = 1.442695040888963;
  this->PI = 3.141592653589793;
  this->SQRT1_2 = 0.7071067811865476;
  this->SQRT2 = 1.414213562373095;
}

// File Line: 50
// RVA: 0x82AAC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::abs(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(x) )
    *result = 0.0;
  else
    *(_QWORD *)result = *(_QWORD *)&x & _xmm;
}

// File Line: 59
// RVA: 0x82AB80
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::acos(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  *result = acos(x);
}

// File Line: 65
// RVA: 0x82D720
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::asin(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  *result = asin(x);
}

// File Line: 71
// RVA: 0x82D870
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::atan(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  *result = atan(x);
}

// File Line: 77
// RVA: 0x82D770
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::atan2(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double y,
        long double x)
{
  double PI; // xmm0_8
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm0_8

  if ( y == INFINITY )
  {
    PI = this->PI;
    if ( x == INFINITY )
    {
      *result = PI * 0.25;
    }
    else
    {
      if ( x == -INFINITY )
        v5 = PI * 0.75;
      else
        v5 = PI * 0.5;
      *result = v5;
    }
  }
  else if ( y == -INFINITY )
  {
    v6 = this->PI;
    if ( x == INFINITY )
    {
      *result = v6 * -0.25;
    }
    else
    {
      if ( x == -INFINITY )
        v7 = v6 * -0.75;
      else
        v7 = v6 * -0.5;
      *result = v7;
    }
  }
  else
  {
    *result = atan2(y, x);
  }
}

// File Line: 102
// RVA: 0x82E990
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::ceil(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  int v3; // ecx

  v3 = (int)x;
  if ( (double)v3 != x )
    x = (double)(!(_mm_movemask_pd(_mm_unpacklo_pd(*(__m128d *)&x, *(__m128d *)&x)) & 1) + v3);
  *result = x;
}

// File Line: 108
// RVA: 0x8328C0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::cos(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  *result = cos(x);
}

// File Line: 114
// RVA: 0x8475A0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::exp(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  *result = exp(x);
}

// File Line: 120
// RVA: 0x848760
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::floor(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  int v3; // ecx

  v3 = (int)x;
  if ( (double)v3 != x )
    x = (double)(v3 - (_mm_movemask_pd(_mm_unpacklo_pd(*(__m128d *)&x, *(__m128d *)&x)) & 1));
  *result = x;
}

// File Line: 126
// RVA: 0x852FC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::log(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  *result = log(x);
}

// File Line: 132
// RVA: 0x85A080
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::round(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  int v3; // ecx

  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
  {
    x = x + 0.5;
    v3 = (int)x;
    if ( (double)v3 != x )
      x = (double)(v3 - (_mm_movemask_pd(_mm_unpacklo_pd(*(__m128d *)&x, *(__m128d *)&x)) & 1));
  }
  *result = x;
}

// File Line: 143
// RVA: 0x85F450
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::sin(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  *result = sin(x);
}

// File Line: 149
// RVA: 0x85F8C0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::sqrt(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x)
{
  *result = sqrt(x);
}

// File Line: 155
// RVA: 0x860A10
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::tan(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  *result = tan(x);
}

// File Line: 161
// RVA: 0x857CA0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::pow(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        double x,
        double y)
{
  if ( y == 0.0 )
  {
    *result = 1.0;
  }
  else if ( (x == 1.0 || x == -1.0) && (*(_QWORD *)&y & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 )
  {
    *result = Scaleform::GFx::NumberUtil::NaN();
  }
  else
  {
    *result = pow(x, y);
  }
}

// File Line: 172
// RVA: 0x8541B0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::max(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  int v7; // ebx
  long double v8; // xmm0_8
  long double v9; // xmm0_8
  Scaleform::GFx::AS3::Boolean3 v10[10]; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h] BYREF

  if ( argc )
  {
    Scaleform::GFx::AS3::Value::Assign(result, argv);
    v7 = 1;
    if ( argc <= 1 )
    {
LABEL_8:
      Scaleform::GFx::AS3::Value::ToNumberValue(result, &resulta);
    }
    else
    {
      while ( Scaleform::GFx::AS3::AbstractLessThan(&resulta, v10, &argv[v7], result)->Result )
      {
        if ( v10[0] == undefined3 )
        {
          v8 = Scaleform::GFx::NumberUtil::NaN();
          Scaleform::GFx::AS3::Value::SetNumber(result, v8);
          return;
        }
        if ( v10[0] == false3 )
          Scaleform::GFx::AS3::Value::Assign(result, &argv[v7]);
        if ( ++v7 >= argc )
          goto LABEL_8;
      }
    }
  }
  else
  {
    v9 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
    Scaleform::GFx::AS3::Value::SetNumber(result, v9);
  }
}

// File Line: 200
// RVA: 0x854560
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::min(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  int v7; // ebx
  long double v8; // xmm0_8
  long double v9; // xmm0_8
  Scaleform::GFx::AS3::Boolean3 v10[10]; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h] BYREF

  if ( argc )
  {
    Scaleform::GFx::AS3::Value::Assign(result, argv);
    v7 = 1;
    if ( argc <= 1 )
    {
LABEL_8:
      Scaleform::GFx::AS3::Value::ToNumberValue(result, &resulta);
    }
    else
    {
      while ( Scaleform::GFx::AS3::AbstractLessThan(&resulta, v10, result, &argv[v7])->Result )
      {
        if ( v10[0] == undefined3 )
        {
          v8 = Scaleform::GFx::NumberUtil::NaN();
          Scaleform::GFx::AS3::Value::SetNumber(result, v8);
          return;
        }
        if ( v10[0] == false3 )
          Scaleform::GFx::AS3::Value::Assign(result, &argv[v7]);
        if ( ++v7 >= argc )
          goto LABEL_8;
      }
    }
  }
  else
  {
    v9 = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
    Scaleform::GFx::AS3::Value::SetNumber(result, v9);
  }
}

// File Line: 228
// RVA: 0x858BE0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::random(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result)
{
  *result = (double)(int)Scaleform::Alg::Random::NextRandom() * 2.328306437080797e-10;
}

// File Line: 235
// RVA: 0x7B2CC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::Call(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::GFx::AS3::VM::Error::Error(&v8, 1075, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v8.Message.pNode;
  if ( v8.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 240
// RVA: 0x7B8AF0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Math::Construct(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::GFx::AS3::VM::Error::Error(&v8, 1076, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v8.Message.pNode;
  if ( v8.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 267
// RVA: 0x1591C90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_0_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AAF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,0,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::abs;
  return result;
}

// File Line: 268
// RVA: 0x1591AE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_1_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB00 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,1,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::acos;
  return result;
}

// File Line: 269
// RVA: 0x1591B10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_2_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB10 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,2,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::asin;
  return result;
}

// File Line: 270
// RVA: 0x1591B40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_3_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB20 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,3,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::atan;
  return result;
}

// File Line: 271
// RVA: 0x15955C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Math_4_double_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,4,double,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::atan2;
  return result;
}

// File Line: 272
// RVA: 0x1591B70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_5_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB40 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,5,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::ceil;
  return result;
}

// File Line: 273
// RVA: 0x1591BA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_6_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB50 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,6,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::cos;
  return result;
}

// File Line: 274
// RVA: 0x1591BD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_7_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB60 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,7,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::exp;
  return result;
}

// File Line: 275
// RVA: 0x1591C00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_8_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB70 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,8,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::floor;
  return result;
}

// File Line: 276
// RVA: 0x1591C30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_9_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB80 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,9,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::log;
  return result;
}

// File Line: 277
// RVA: 0x1591C60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_10_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AB90 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,10,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::round;
  return result;
}

// File Line: 278
// RVA: 0x1591CC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_11_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::sin;
  return result;
}

// File Line: 279
// RVA: 0x1591CF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_12_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,12,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::Classes::fl::Math::sqrt;
  return result;
}

// File Line: 280
// RVA: 0x1591D20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Math_13_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,13,double,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::tan;
  return result;
}

// File Line: 281
// RVA: 0x1595620
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Math_14_double_double_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABD0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,14,double,double,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double, long double))Scaleform::GFx::AS3::Classes::fl::Math::pow;
  return result;
}

// File Line: 282
// RVA: 0x1595650
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Math_15_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,15,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::Math::max;
  return result;
}

// File Line: 283
// RVA: 0x15955F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Math_16_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ABF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,16,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Math *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::Math::min;
  return result;
}

// File Line: 284
// RVA: 0x158B5A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::Math_17_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC00 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::Math,17,double>::Method = Scaleform::GFx::AS3::Classes::fl::Math::random;
  return result;
}

// File Line: 356
// RVA: 0x7409E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Math::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl::Math *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::MathCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Math::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::MathCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl::Math *)MHeap->vfptr->Alloc(MHeap, 136ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl::Math::Math(v9, result->pV);
  return result;
}

