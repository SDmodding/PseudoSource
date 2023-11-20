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
void __fastcall UEL::UnaryExpression::UnaryExpression(UEL::UnaryExpression *this, UEL::UnaryExpression::Type type, UEL::Expression *expression)
{
  UFG::qOffset64<UEL::Expression *> *v3; // rax
  char *v4; // r8

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable';
  this->mType.mValue = 0;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::UnaryExpression::`vftable';
  v3 = &this->mExpression;
  if ( expression )
    v4 = (char *)((char *)expression - (char *)v3);
  else
    v4 = 0i64;
  v3->mOffset = (__int64)v4;
  this->mType.mValue = type;
}

// File Line: 26
// RVA: 0x2533B0
char __fastcall UEL::UnaryExpression::Resolve(UEL::UnaryExpression *this, UEL::Runtime *runtime)
{
  __int64 v2; // rax
  UEL::Expression *v3; // rsi
  UEL::UnaryExpression *v4; // rdi
  char *v5; // rcx
  __int64 v6; // rax
  unsigned int v7; // ebx
  UEL::Expression *v8; // rcx
  UEL::Value::Type *v9; // rax
  unsigned int v10; // eax
  char v11; // al
  __int64 v12; // rax
  UEL::Expression *v13; // rcx
  __int64 v14; // rax
  unsigned int v15; // ebx
  UEL::Value::Type *v16; // rax
  unsigned int v17; // eax
  __int64 v18; // rax
  unsigned int v19; // er14
  UEL::Expression *v20; // rcx
  UEL::Value::Type *v21; // rax
  __int64 v22; // rax
  unsigned int v23; // er14
  UEL::Expression *v24; // rcx
  UEL::Value::Type *v25; // rax
  bool v26; // al
  __int64 v27; // rax
  UEL::Value::Type *v28; // rdx
  __int64 v29; // rax
  UEL::Value::Type *v30; // rax
  UEL::Value::Type v31; // [rsp+24h] [rbp-44h]
  char v32; // [rsp+2Ch] [rbp-3Ch]
  UEL::Value::Type v33; // [rsp+34h] [rbp-34h]
  UEL::Value::Type result; // [rsp+70h] [rbp+8h]
  UEL::Value::Type v35; // [rsp+80h] [rbp+18h]
  UEL::Value::Type v36; // [rsp+88h] [rbp+20h]

  v2 = this->mExpression.mOffset;
  v3 = 0i64;
  v4 = this;
  if ( v2 )
    v5 = (char *)&this->mExpression + v2;
  else
    v5 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v5 + 16i64))(v5, runtime);
  v6 = v4->mExpression.mOffset;
  v7 = UFG::gNullQSymbol.mUID;
  if ( v6 )
    v8 = (UEL::Expression *)((char *)&v4->mExpression + v6);
  else
    v8 = 0i64;
  v9 = UEL::Expression::GetValueType(v8, &result);
  if ( 0 != v9->mBaseType.mValue || v7 != v9->mDetailedType.mUID )
  {
    switch ( v4->mType.mValue )
    {
      case 0:
        v12 = v4->mExpression.mOffset;
        if ( v12 )
          v13 = (UEL::Expression *)((char *)&v4->mExpression + v12);
        else
          v13 = 0i64;
        UEL::Expression::GetValueType(v13, &result);
        v14 = v4->mExpression.mOffset;
        v15 = UFG::gNullQSymbol.mUID;
        if ( v14 )
          v3 = (UEL::Expression *)((char *)&v4->mExpression + v14);
        v16 = UEL::Expression::GetValueType(v3, &v35);
        if ( v16->mBaseType.mValue != 5 || v15 != v16->mDetailedType.mUID )
          goto LABEL_19;
        v17 = UFG::gNullQSymbol.mUID;
        v4->mValueType.mBaseType.mValue = 5;
        goto LABEL_43;
      case 1:
        v18 = v4->mExpression.mOffset;
        v19 = UFG::gNullQSymbol.mUID;
        if ( v18 )
          v20 = (UEL::Expression *)((char *)&v4->mExpression + v18);
        else
          v20 = 0i64;
        v21 = UEL::Expression::GetValueType(v20, &v36);
        v26 = 1;
        if ( v21->mBaseType.mValue != 4 || v19 != v21->mDetailedType.mUID )
        {
          v22 = v4->mExpression.mOffset;
          v23 = UFG::gNullQSymbol.mUID;
          v24 = (UEL::Expression *)(v22 ? (UFG::qOffset64<UEL::Expression *> *)((char *)&v4->mExpression + v22) : 0i64);
          v25 = UEL::Expression::GetValueType(v24, &v31);
          if ( 1 != v25->mBaseType.mValue || v23 != v25->mDetailedType.mUID )
            v26 = 0;
        }
        if ( v26 )
        {
          v27 = v4->mExpression.mOffset;
          if ( v27 )
            v3 = (UEL::Expression *)((char *)&v4->mExpression + v27);
          v28 = (UEL::Value::Type *)&v32;
LABEL_42:
          v30 = UEL::Expression::GetValueType(v3, v28);
          v4->mValueType.mBaseType.mValue = v30->mBaseType.mValue;
          v17 = v30->mDetailedType.mUID;
LABEL_43:
          v4->mValueType.mDetailedType.mUID = v17;
LABEL_44:
          v4->mResolved = 1;
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
        v4->mValueType.mBaseType.mValue = 4;
        goto LABEL_43;
      case 3:
        v17 = UFG::gNullQSymbol.mUID;
        v4->mValueType.mBaseType.mValue = 1;
        goto LABEL_43;
      case 4:
        v17 = UFG::gNullQSymbol.mUID;
        v4->mValueType.mBaseType.mValue = 5;
        goto LABEL_43;
      case 5:
        v29 = v4->mExpression.mOffset;
        if ( v29 )
          v3 = (UEL::Expression *)((char *)&v4->mExpression + v29);
        v28 = &v33;
        goto LABEL_42;
      default:
        goto LABEL_44;
    }
  }
  else
  {
    v4->mNeedsRuntimeResolve = 1;
    v10 = UFG::gNullQSymbol.mUID;
    v4->mValueType.mBaseType.mValue = 0;
    v4->mValueType.mDetailedType.mUID = v10;
    v11 = 1;
  }
  return v11;
}

// File Line: 75
// RVA: 0x251950
UEL::Value *__fastcall UEL::UnaryExpression::Eval(UEL::UnaryExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args)
{
  UFG::qArray<UEL::Value,0> *v4; // r14
  UEL::ParametersBase *v5; // r15
  UEL::Value *v6; // rsi
  UEL::UnaryExpression *v7; // rbx
  signed __int64 v8; // rdi
  __int64 v9; // rax
  UEL::Value::Type *v10; // rax
  unsigned __int16 v11; // ST1C_2
  unsigned int v12; // eax
  unsigned __int16 v13; // ST1C_2
  UEL::Value::Type *v14; // rax
  unsigned __int16 v15; // ST1C_2
  unsigned int v16; // eax
  unsigned __int16 v17; // ST1C_2
  __int64 v18; // rax
  UFG::qString *v19; // rax
  float v20; // ST10_4
  float v21; // ST14_4
  float v22; // ST18_4
  unsigned __int16 v23; // ST1C_2
  unsigned int v25; // [rsp+20h] [rbp-69h]
  UEL::Value ret; // [rsp+30h] [rbp-59h]
  UEL::Value::Type v27; // [rsp+50h] [rbp-39h]
  __int64 v28; // [rsp+58h] [rbp-31h]
  UFG::qString resulta; // [rsp+60h] [rbp-29h]
  UFG::qString v30; // [rsp+88h] [rbp-1h]
  UEL::Value::Type v31; // [rsp+E8h] [rbp+5Fh]
  void *retaddr; // [rsp+108h] [rbp+7Fh]

  v28 = -2i64;
  v4 = args;
  v5 = parameters;
  v6 = result;
  v7 = this;
  v8 = 0i64;
  UFG::qString::FormatEx(&resulta, "(%s ", UEL::UnaryExpressionTypeStrings[(unsigned __int8)this->mType.mValue]);
  UFG::qString::~qString(&resulta);
  v9 = v7->mExpression.mOffset;
  if ( v9 )
    v8 = (signed __int64)&v7->mExpression + v9;
  (*(void (__fastcall **)(signed __int64, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v8 + 24i64))(
    v8,
    &ret,
    v5,
    v4,
    retaddr);
  switch ( v7->mType.mValue )
  {
    case 0:
      if ( v7->mNeedsRuntimeResolve )
      {
        v10 = UEL::UnaryExpression::GetRuntimeOpResultType(v7, &v31, &ret);
        v11 = v10->mBaseType.mValue;
        v12 = v10->mDetailedType.mUID;
      }
      else
      {
        v13 = v7->mValueType.mBaseType.mValue;
        v12 = v7->mValueType.mDetailedType.mUID;
      }
      v25 = v12;
      ret.boolean = ret.boolean == 0;
      goto LABEL_25;
    case 1:
      if ( v7->mNeedsRuntimeResolve )
      {
        v14 = UEL::UnaryExpression::GetRuntimeOpResultType(v7, &v27, &ret);
        v15 = v14->mBaseType.mValue;
        v16 = v14->mDetailedType.mUID;
      }
      else
      {
        v17 = v7->mValueType.mBaseType.mValue;
        v16 = v7->mValueType.mDetailedType.mUID;
      }
      v25 = v16;
      if ( 4 != ret.type.mBaseType.mValue || UFG::gNullQSymbol.mUID != ret.type.mDetailedType.mUID )
      {
        v18 = -ret.qSymbol_mUID;
        goto LABEL_24;
      }
      ret.real = ret.real * -1.0;
      goto LABEL_25;
    case 2:
      v25 = UFG::gNullQSymbol.mUID;
      if ( ret.type.mBaseType.mValue == 1 )
        ret.real = (float)ret.enumeration;
      goto LABEL_25;
    case 3:
      v25 = UFG::gNullQSymbol.mUID;
      if ( ret.type.mBaseType.mValue == 4 )
      {
        v18 = (unsigned int)(signed int)ret.real;
      }
      else
      {
        if ( ret.type.mBaseType.mValue != 6 )
          goto LABEL_25;
        v18 = ret.enumeration;
      }
LABEL_24:
      ret.integer = v18;
LABEL_25:
      v19 = UEL::Value::ToString(&ret, &v30);
      UFG::qString::FormatEx(&resulta, " [%s])", v19->mData);
      UFG::qString::~qString(&resulta);
      UFG::qString::~qString(&v30);
      v6->integer = ret.integer;
      v6->qSymbol_mUID = ret.qSymbol_mUID;
      v6->qVector_y = v20;
      v6->qVector_z = v21;
      v6->qVector_w = v22;
      v6->type.mBaseType.mValue = v23;
      v6->type.mDetailedType.mUID = v25;
      return v6;
    case 4:
      v25 = UFG::gNullQSymbol.mUID;
      goto LABEL_25;
    case 5:
      v25 = ret.type.mDetailedType.mUID;
      switch ( ret.type.mBaseType.mValue )
      {
        case 1u:
        case 3u:
        case 8u:
        case 9u:
        case 0xAu:
          v18 = ret.integer;
          goto LABEL_24;
        case 2u:
        case 4u:
        case 5u:
        case 6u:
        case 7u:
          goto LABEL_25;
      }
      goto LABEL_25;
    default:
      goto LABEL_25;
  }
}e 5u:
        cas

// File Line: 208
// RVA: 0x251DA0
UEL::Value::Type *__fastcall UEL::UnaryExpression::GetRuntimeOpResultType(UEL::UnaryExpression *this, UEL::Value::Type *result, UEL::Value *ret)
{
  UEL::Value::Type *v3; // rax

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
    v3 = result;
  }
  else
  {
    result->mBaseType.mValue = 5;
    result->mDetailedType = UFG::gNullQSymbol;
    v3 = result;
  }
  return v3;
}

