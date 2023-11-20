// File Line: 5
// RVA: 0x1475E10
__int64 dynamic_initializer_for__UEL::ArgumentUsageExpression::msActiveResolveArguments__()
{
  return atexit(dynamic_atexit_destructor_for__UEL::ArgumentUsageExpression::msActiveResolveArguments__);
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
signed __int64 __fastcall UEL::ArgumentExpression::Resolve(UEL::ArgumentExpression *this, UEL::Runtime *runtime)
{
  signed __int64 result; // rax

  this->mValueType.mBaseType.mValue = this->mTaggedType.mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = this->mTaggedType.mDetailedType.mUID;
  result = 1i64;
  this->mResolved = 1;
  return result;
}

// File Line: 26
// RVA: 0x24DF70
void __fastcall UEL::ArgumentUsageExpression::ArgumentUsageExpression(UEL::ArgumentUsageExpression *this, const char *name)
{
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable';
  this->mType.mValue = 8;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ArgumentUsageExpression::`vftable';
  this->mName.mUID = -1;
  this->mName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, name)->mUID;
}

// File Line: 31
// RVA: 0x252250
char __fastcall UEL::ArgumentUsageExpression::Resolve(UEL::ArgumentUsageExpression *this, UEL::Runtime *instance)
{
  signed __int64 v2; // rbx
  UEL::ArgumentUsageExpression *v3; // rdi
  unsigned int v4; // eax
  UEL::NameExpressionPair *v5; // r9
  UEL::NameExpressionPair *v6; // rdx
  char result; // al
  __int64 v8; // rcx

  v2 = 0i64;
  v3 = this;
  this->mIndex = -1;
  v4 = 0;
  if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.size )
  {
    v5 = UEL::ArgumentUsageExpression::msActiveResolveArguments.p;
    v6 = UEL::ArgumentUsageExpression::msActiveResolveArguments.p;
    while ( v6->name.mUID != this->mName.mUID )
    {
      ++v4;
      ++v6;
      if ( v4 >= UEL::ArgumentUsageExpression::msActiveResolveArguments.size )
        goto LABEL_7;
    }
    this->mIndex = v4;
    v2 = (signed __int64)&v5[v4];
  }
LABEL_7:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  if ( !v2 )
    return 0;
  v8 = *(_QWORD *)(v2 + 8);
  v3->mValueType.mBaseType.mValue = *(_WORD *)(v8 + 12);
  v3->mValueType.mDetailedType.mUID = *(_DWORD *)(v8 + 16);
  result = 1;
  v3->mResolved = 1;
  return result;
}

// File Line: 53
// RVA: 0x24F6B0
UEL::Value *__fastcall UEL::ArgumentUsageExpression::Eval(UEL::ArgumentUsageExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args)
{
  UFG::qArray<UEL::Value,0> *v4; // rdi
  UEL::Value *v5; // rbx
  UFG::qSymbolUC *v6; // r14
  unsigned int v7; // eax
  UFG::qString *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm1_4
  UEL::Value v12; // [rsp+18h] [rbp-31h]
  __int64 v13; // [rsp+38h] [rbp-11h]
  UFG::qString resulta; // [rsp+40h] [rbp-9h]
  UFG::qString v15; // [rsp+68h] [rbp+1Fh]

  v13 = -2i64;
  v4 = args;
  v5 = result;
  v6 = (UFG::qSymbolUC *)this;
  v12.type.mBaseType.mValue = 0;
  v12.type.mDetailedType = UFG::gNullQSymbol;
  UFG::qString::FormatEx(&resulta, "(ArgumentUsage ", parameters);
  UFG::qString::~qString(&resulta);
  UFG::qSymbol::as_cstr_dbg(v6 + 6);
  if ( v4 )
  {
    UFG::qSymbol::as_cstr_dbg(v6 + 6);
    v7 = v6[7].mUID;
    if ( v7 < v4->size )
    {
      UEL::Value::operator=(&v12, &v4->p[v7]);
      UFG::qSymbol::as_cstr_dbg(v6 + 6);
      v8 = UEL::Value::ToString(&v12, &v15);
      UFG::qString::FormatEx(&resulta, " [%s])", v8->mData);
      UFG::qString::~qString(&resulta);
      UFG::qString::~qString(&v15);
    }
  }
  v5->integer = v12.integer;
  v9 = v12.qVector_y;
  v5->qSymbol_mUID = v12.qSymbol_mUID;
  v5->qVector_y = v9;
  v10 = v12.qVector_w;
  v5->qVector_z = v12.qVector_z;
  v5->qVector_w = v10;
  v5->type.mBaseType.mValue = v12.type.mBaseType.mValue;
  v5->type.mDetailedType.mUID = v12.type.mDetailedType.mUID;
  return v5;
}

