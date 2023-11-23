// File Line: 5
// RVA: 0x1475F50
__int64 dynamic_initializer_for__UEL::UnaryExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UnaryExpression", 0xFFFFFFFF);
  UEL::UnaryExpression::sClassNameUID = result;
  return result;
}

// File Line: 17
// RVA: 0x24E500
void __fastcall UEL::UnaryExpression::UnaryExpression(
        UEL::UnaryExpression *this,
        UEL::UnaryExpression::Type type,
        UEL::Expression *expression)
{
  UFG::qOffset64<UEL::Expression *> *p_mExpression; // rax
  char *v4; // r8

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->UEL::Expression::mType.mValue = 0;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::UnaryExpression::`vftable;
  p_mExpression = &this->mExpression;
  if ( expression )
    v4 = (char *)((char *)expression - (char *)p_mExpression);
  else
    v4 = 0i64;
  p_mExpression->mOffset = (__int64)v4;
  this->mType.mValue = type;
}

// File Line: 26
// RVA: 0x2533B0
bool __fastcall UEL::UnaryExpression::Resolve(UEL::UnaryExpression *this, UEL::Runtime *runtime)
{
  __int64 mOffset; // rax
  UEL::Expression *v3; // rsi
  char *v5; // rcx
  __int64 v6; // rax
  unsigned int mUID; // ebx
  UEL::Expression *v8; // rcx
  UEL::Value::Type *ValueType; // rax
  unsigned int v10; // eax
  bool v11; // al
  __int64 v12; // rax
  UEL::Expression *v13; // rcx
  __int64 v14; // rax
  unsigned int v15; // ebx
  UEL::Value::Type *v16; // rax
  unsigned int v17; // eax
  __int64 v18; // rax
  unsigned int v19; // r14d
  UEL::Expression *v20; // rcx
  UEL::Value::Type *v21; // rax
  __int64 v22; // rax
  unsigned int v23; // r14d
  UEL::Expression *v24; // rcx
  UEL::Value::Type *v25; // rax
  __int64 v27; // rax
  UEL::Value::Type *v28; // rdx
  __int64 v29; // rax
  UEL::Value::Type *v30; // rax
  UEL::Value::Type v31; // [rsp+24h] [rbp-44h] BYREF
  char v32; // [rsp+2Ch] [rbp-3Ch] BYREF
  UEL::Value::Type v33; // [rsp+34h] [rbp-34h] BYREF
  UEL::Value::Type result; // [rsp+70h] [rbp+8h] BYREF
  UEL::Value::Type v35; // [rsp+80h] [rbp+18h] BYREF
  UEL::Value::Type v36; // [rsp+88h] [rbp+20h] BYREF

  mOffset = this->mExpression.mOffset;
  v3 = 0i64;
  if ( mOffset )
    v5 = (char *)&this->mExpression + mOffset;
  else
    v5 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v5 + 16i64))(v5, runtime);
  v6 = this->mExpression.mOffset;
  mUID = UFG::gNullQSymbol.mUID;
  if ( v6 )
    v8 = (UEL::Expression *)((char *)&this->mExpression + v6);
  else
    v8 = 0i64;
  ValueType = UEL::Expression::GetValueType(v8, &result);
  if ( ValueType->mBaseType.mValue || mUID != ValueType->mDetailedType.mUID )
  {
    switch ( this->mType.mValue )
    {
      case 0:
        v12 = this->mExpression.mOffset;
        if ( v12 )
          v13 = (UEL::Expression *)((char *)&this->mExpression + v12);
        else
          v13 = 0i64;
        UEL::Expression::GetValueType(v13, &result);
        v14 = this->mExpression.mOffset;
        v15 = UFG::gNullQSymbol.mUID;
        if ( v14 )
          v3 = (UEL::Expression *)((char *)&this->mExpression + v14);
        v16 = UEL::Expression::GetValueType(v3, &v35);
        if ( v16->mBaseType.mValue != 5 || v15 != v16->mDetailedType.mUID )
          goto LABEL_19;
        v17 = UFG::gNullQSymbol.mUID;
        this->mValueType.mBaseType.mValue = 5;
        goto LABEL_43;
      case 1:
        v18 = this->mExpression.mOffset;
        v19 = UFG::gNullQSymbol.mUID;
        if ( v18 )
          v20 = (UEL::Expression *)((char *)&this->mExpression + v18);
        else
          v20 = 0i64;
        v21 = UEL::Expression::GetValueType(v20, &v36);
        if ( v21->mBaseType.mValue == 4 && v19 == v21->mDetailedType.mUID
          || ((v22 = this->mExpression.mOffset, v23 = UFG::gNullQSymbol.mUID, !v22)
            ? (v24 = 0i64)
            : (v24 = (UEL::Expression *)((char *)&this->mExpression + v22)),
              (v25 = UEL::Expression::GetValueType(v24, &v31), v25->mBaseType.mValue == 1)
           && v23 == v25->mDetailedType.mUID) )
        {
          v27 = this->mExpression.mOffset;
          if ( v27 )
            v3 = (UEL::Expression *)((char *)&this->mExpression + v27);
          v28 = (UEL::Value::Type *)&v32;
LABEL_42:
          v30 = UEL::Expression::GetValueType(v3, v28);
          this->mValueType.mBaseType.mValue = v30->mBaseType.mValue;
          v17 = v30->mDetailedType.mUID;
LABEL_43:
          this->mValueType.mDetailedType.mUID = v17;
LABEL_44:
          this->mResolved = 1;
          v11 = 1;
        }
        else
        {
LABEL_19:
          v11 = 0;
        }
        break;
      case 2:
        v17 = UFG::gNullQSymbol.mUID;
        this->mValueType.mBaseType.mValue = 4;
        goto LABEL_43;
      case 3:
        v17 = UFG::gNullQSymbol.mUID;
        this->mValueType.mBaseType.mValue = 1;
        goto LABEL_43;
      case 4:
        v17 = UFG::gNullQSymbol.mUID;
        this->mValueType.mBaseType.mValue = 5;
        goto LABEL_43;
      case 5:
        v29 = this->mExpression.mOffset;
        if ( v29 )
          v3 = (UEL::Expression *)((char *)&this->mExpression + v29);
        v28 = &v33;
        goto LABEL_42;
      default:
        goto LABEL_44;
    }
  }
  else
  {
    this->mNeedsRuntimeResolve = 1;
    v10 = UFG::gNullQSymbol.mUID;
    this->mValueType.mBaseType.mValue = 0;
    this->mValueType.mDetailedType.mUID = v10;
    return 1;
  }
  return v11;
}

// File Line: 75
// RVA: 0x251950
UEL::Value *__fastcall UEL::UnaryExpression::Eval(
        UEL::UnaryExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  char *v8; // rdi
  __int64 mOffset; // rax
  unsigned int mUID; // eax
  unsigned int v11; // eax
  __int64 real; // rax
  UFG::qString *v13; // rax
  float v15; // [rsp+10h] [rbp-79h]
  float v16; // [rsp+14h] [rbp-75h]
  float v17; // [rsp+18h] [rbp-71h]
  unsigned __int16 v18; // [rsp+1Ch] [rbp-6Dh]
  unsigned int v19; // [rsp+20h] [rbp-69h]
  UEL::Value ret; // [rsp+30h] [rbp-59h] BYREF
  UEL::Value::Type v21; // [rsp+50h] [rbp-39h] BYREF
  __int64 v22; // [rsp+58h] [rbp-31h]
  UFG::qString resulta; // [rsp+60h] [rbp-29h] BYREF
  UFG::qString v24; // [rsp+88h] [rbp-1h] BYREF
  UEL::Value::Type v25; // [rsp+E8h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+108h] [rbp+7Fh]

  v22 = -2i64;
  v8 = 0i64;
  UFG::qString::FormatEx(&resulta, "(%s ", UEL::UnaryExpressionTypeStrings[(unsigned __int8)this->mType.mValue]);
  UFG::qString::~qString(&resulta);
  mOffset = this->mExpression.mOffset;
  if ( mOffset )
    v8 = (char *)&this->mExpression + mOffset;
  v19 = (unsigned int)retaddr;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *))(*(_QWORD *)v8 + 24i64))(
    v8,
    &ret,
    parameters,
    args);
  switch ( this->mType.mValue )
  {
    case 0:
      if ( this->mNeedsRuntimeResolve )
        mUID = UEL::UnaryExpression::GetRuntimeOpResultType(this, &v25, &ret)->mDetailedType.mUID;
      else
        mUID = this->mValueType.mDetailedType.mUID;
      v19 = mUID;
      ret.boolean = ret.boolean == 0;
      goto LABEL_25;
    case 1:
      if ( this->mNeedsRuntimeResolve )
        v11 = UEL::UnaryExpression::GetRuntimeOpResultType(this, &v21, &ret)->mDetailedType.mUID;
      else
        v11 = this->mValueType.mDetailedType.mUID;
      v19 = v11;
      if ( ret.type.mBaseType.mValue != 4 || UFG::gNullQSymbol.mUID != ret.type.mDetailedType.mUID )
      {
        real = -ret.qSymbol_mUID;
        goto LABEL_24;
      }
      ret.real = ret.real * -1.0;
      goto LABEL_25;
    case 2:
      v19 = UFG::gNullQSymbol.mUID;
      if ( ret.type.mBaseType.mValue == 1 )
        ret.real = (float)ret.enumeration;
      goto LABEL_25;
    case 3:
      v19 = UFG::gNullQSymbol.mUID;
      if ( ret.type.mBaseType.mValue == 4 )
      {
        real = (unsigned int)(int)ret.real;
      }
      else
      {
        if ( ret.type.mBaseType.mValue != 6 )
          goto LABEL_25;
        real = ret.enumeration;
      }
LABEL_24:
      ret.integer = real;
LABEL_25:
      v13 = UEL::Value::ToString(&ret, &v24);
      UFG::qString::FormatEx(&resulta, " [%s])", v13->mData);
      UFG::qString::~qString(&resulta);
      UFG::qString::~qString(&v24);
      result->integer = ret.integer;
      result->qSymbol_mUID = ret.qSymbol_mUID;
      result->qVector_y = v15;
      result->qVector_z = v16;
      result->qVector_w = v17;
      result->type.mBaseType.mValue = v18;
      result->type.mDetailedType.mUID = v19;
      return result;
    case 4:
      v19 = UFG::gNullQSymbol.mUID;
      goto LABEL_25;
    case 5:
      v19 = ret.type.mDetailedType.mUID;
      switch ( ret.type.mBaseType.mValue )
      {
        case 1u:
        case 3u:
        case 8u:
        case 9u:
        case 0xAu:
          real = ret.integer;
          goto LABEL_24;
        default:
          goto LABEL_25;
      }
      goto LABEL_25;
    default:
      goto LABEL_25;
  }
}

// File Line: 208
// RVA: 0x251DA0
UEL::Value::Type *__fastcall UEL::UnaryExpression::GetRuntimeOpResultType(
        UEL::UnaryExpression *this,
        UEL::Value::Type *result,
        UEL::Value *ret)
{
  if ( this->mType.mValue )
  {
    if ( this->mType.mValue == 1 )
    {
      result->mBaseType.mValue = ret->type.mBaseType.mValue;
      result->mDetailedType.mUID = ret->type.mDetailedType.mUID;
    }
    else
    {
      result->mBaseType.mValue = 0;
      result->mDetailedType = UFG::gNullQSymbol;
    }
    return result;
  }
  else
  {
    result->mBaseType.mValue = 5;
    result->mDetailedType = UFG::gNullQSymbol;
    return result;
  }
}

