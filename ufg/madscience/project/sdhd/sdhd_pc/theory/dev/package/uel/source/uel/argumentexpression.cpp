// File Line: 5
// RVA: 0x1475E10
__int64 dynamic_initializer_for__UEL::ArgumentUsageExpression::msActiveResolveArguments__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UEL::ArgumentUsageExpression::msActiveResolveArguments__);
}

// File Line: 7
// RVA: 0x1475E30
__int64 dynamic_initializer_for__UEL::ArgumentExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ArgumentExpression", 0xFFFFFFFF);
  UEL::ArgumentExpression::sClassNameUID = result;
  return result;
}

// File Line: 8
// RVA: 0x1475E50
__int64 dynamic_initializer_for__UEL::ArgumentUsageExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ArgumentUsageExpression", 0xFFFFFFFF);
  UEL::ArgumentUsageExpression::sClassNameUID = result;
  return result;
}

// File Line: 18
// RVA: 0x252230
__int64 __fastcall UEL::ArgumentExpression::Resolve(UEL::ArgumentExpression *this, UEL::Runtime *runtime)
{
  __int64 result; // rax

  this->mValueType.mBaseType.mValue = this->mTaggedType.mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = this->mTaggedType.mDetailedType.mUID;
  result = 1i64;
  this->mResolved = 1;
  return result;
}

// File Line: 26
// RVA: 0x24DF70
void __fastcall UEL::ArgumentUsageExpression::ArgumentUsageExpression(
        UEL::ArgumentUsageExpression *this,
        const char *name)
{
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 8;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ArgumentUsageExpression::`vftable;
  this->mName.mUID = -1;
  this->mName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, name)->mUID;
}

// File Line: 31
// RVA: 0x252250
bool __fastcall UEL::ArgumentUsageExpression::Resolve(UEL::ArgumentUsageExpression *this, UEL::Runtime *instance)
{
  UEL::NameExpressionPair *v2; // rbx
  unsigned int v4; // eax
  UEL::NameExpressionPair *p; // r9
  UEL::NameExpressionPair *v6; // rdx
  bool result; // al
  UEL::Expression *expr; // rcx

  v2 = 0i64;
  this->mIndex = -1;
  v4 = 0;
  if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.size )
  {
    p = UEL::ArgumentUsageExpression::msActiveResolveArguments.p;
    v6 = UEL::ArgumentUsageExpression::msActiveResolveArguments.p;
    while ( v6->name.mUID != this->mName.mUID )
    {
      ++v4;
      ++v6;
      if ( v4 >= UEL::ArgumentUsageExpression::msActiveResolveArguments.size )
        goto LABEL_7;
    }
    this->mIndex = v4;
    v2 = &p[v4];
  }
LABEL_7:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  if ( !v2 )
    return 0;
  expr = v2->expr;
  this->mValueType.mBaseType.mValue = expr->mValueType.mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = expr->mValueType.mDetailedType.mUID;
  result = 1;
  this->mResolved = 1;
  return result;
}

// File Line: 53
// RVA: 0x24F6B0
UEL::Value *__fastcall UEL::ArgumentUsageExpression::Eval(
        UEL::ArgumentUsageExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  unsigned int mIndex; // eax
  UFG::qString *v8; // rax
  float qVector_y; // xmm1_4
  float qVector_w; // xmm1_4
  UEL::Value v12; // [rsp+18h] [rbp-31h] BYREF
  __int64 v13; // [rsp+38h] [rbp-11h]
  UFG::qString resulta; // [rsp+40h] [rbp-9h] BYREF
  UFG::qString v15; // [rsp+68h] [rbp+1Fh] BYREF

  v13 = -2i64;
  v12.type.mBaseType.mValue = 0;
  v12.type.mDetailedType = UFG::gNullQSymbol;
  UFG::qString::FormatEx(&resulta, "(ArgumentUsage ", parameters);
  UFG::qString::~qString(&resulta);
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  if ( args )
  {
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    mIndex = this->mIndex;
    if ( mIndex < args->size )
    {
      UEL::Value::operator=(&v12, &args->p[mIndex]);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
      v8 = UEL::Value::ToString(&v12, &v15);
      UFG::qString::FormatEx(&resulta, " [%s])", v8->mData);
      UFG::qString::~qString(&resulta);
      UFG::qString::~qString(&v15);
    }
  }
  result->integer = v12.integer;
  qVector_y = v12.qVector_y;
  result->qSymbol_mUID = v12.qSymbol_mUID;
  result->qVector_y = qVector_y;
  qVector_w = v12.qVector_w;
  result->qVector_z = v12.qVector_z;
  result->qVector_w = qVector_w;
  result->type.mBaseType.mValue = v12.type.mBaseType.mValue;
  result->type.mDetailedType.mUID = v12.type.mDetailedType.mUID;
  return result;
}

