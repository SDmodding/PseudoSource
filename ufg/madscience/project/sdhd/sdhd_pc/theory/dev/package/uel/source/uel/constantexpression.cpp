// File Line: 5
// RVA: 0x1475E90
__int64 dynamic_initializer_for__UEL::ConstantExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConstantExpression", 0xFFFFFFFF);
  UEL::ConstantExpression::sClassNameUID = result;
  return result;
}

// File Line: 9
// RVA: 0x1475FE0
__int64 dynamic_initializer_for__strTrue__()
{
  UFG::qString::qString(&strTrue, "true");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__strTrue__);
}

// File Line: 10
// RVA: 0x1475FB0
__int64 dynamic_initializer_for__strFalse__()
{
  UFG::qString::qString(&strFalse, "false");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__strFalse__);
}

// File Line: 14
// RVA: 0x24E060
void __fastcall UEL::ConstantExpression::ConstantExpression(
        UEL::ConstantExpression *this,
        char *text,
        const char *text2,
        UEL::Value::Type type)
{
  __int16 v8; // r8
  unsigned int v10; // r14d
  int mValue; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  unsigned int mUID; // eax
  UFG::qSymbol result; // [rsp+78h] [rbp+20h] BYREF

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 2;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ConstantExpression::`vftable;
  this->mEntry.mUID = -1;
  this->mResolvedValue.type.mBaseType.mValue = 0;
  this->mResolvedValue.type.mDetailedType = UFG::gNullQSymbol;
  v8 = *(_WORD *)type.mBaseType.mValue;
  if ( *(_WORD *)type.mBaseType.mValue == 2 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&type + 4i64)
    || v8 == 3 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&type + 4i64) )
  {
    v10 = UFG::qStringLength(text);
    if ( v10 < 0x400 )
    {
      UFG::qStringCopy(buffer_1, 128, text + 1, -1);
      buffer_1[v10 - 2] = 0;
    }
  }
  else if ( v8 == 6 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&type + 4i64) )
  {
    this->mResolvedValue.type.mDetailedType = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, text)->mUID;
    this->mEntry = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, text2)->mUID;
  }
  else
  {
    UFG::qStringCopy(buffer_1, 128, text, -1);
  }
  this->mValueType.mBaseType.mValue = *(_WORD *)type.mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&type + 4i64);
  mValue = this->mValueType.mBaseType.mValue;
  this->mResolvedValue.type.mBaseType.mValue = mValue;
  v12 = mValue - 1;
  if ( v12 )
  {
    v13 = v12 - 1;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( v14 )
      {
        v15 = v14 - 1;
        if ( v15 )
        {
          if ( v15 == 1 )
            this->mResolvedValue.boolean = buffer_1 == strTrue.mData;
        }
        else
        {
          this->mResolvedValue.real = UFG::qToFloat(buffer_1, 0.0);
        }
      }
      else
      {
        UEL::Value::SetString(&this->mResolvedValue, buffer_1);
      }
    }
    else
    {
      mUID = UFG::gNullQSymbol.mUID;
      this->mResolvedValue.type.mBaseType.mValue = 2;
      this->mResolvedValue.type.mDetailedType.mUID = mUID;
      LODWORD(this->mResolvedValue.integer) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, buffer_1)->mUID;
    }
  }
  else
  {
    this->mResolvedValue.integer = UFG::qToInt64(buffer_1, 0i64);
  }
}

// File Line: 79
// RVA: 0x252950
char __fastcall UEL::ConstantExpression::Resolve(UEL::ConstantExpression *this, UEL::Runtime *instance)
{
  __int64 v2; // r14
  unsigned __int16 v5; // ax
  unsigned int mUID; // edx
  unsigned int v7; // edi
  UFG::qBaseTreeRB *v8; // rsi
  unsigned __int8 v9; // bp
  unsigned int mStringHash32; // eax
  UFG::qString v12; // [rsp+28h] [rbp-30h] BYREF
  __int64 v13; // [rsp+50h] [rbp-8h]

  v13 = v2;
  switch ( this->mValueType.mBaseType.mValue )
  {
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
      v5 = 1;
      goto LABEL_16;
    case 6u:
      mUID = this->mResolvedValue.type.mDetailedType.mUID;
      v7 = 0;
      if ( mUID )
        v8 = UFG::qBaseTreeRB::Get(&instance->mEnumBindings->mTree, mUID);
      else
        v8 = 0i64;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mResolvedValue.type.mDetailedType);
      if ( !v8 )
        return 0;
      v9 = 0;
      if ( !HIDWORD(v8->mNULL.mParent) )
        goto LABEL_14;
      break;
    default:
      return 0;
  }
  while ( 1 )
  {
    UFG::qString::qString(&v12, *((const char **)&v8->mNULL.mChild[0]->mParent + v7));
    mStringHash32 = v12.mStringHash32;
    if ( v12.mStringHash32 == -1 )
    {
      mStringHash32 = UFG::qStringHash32(v12.mData, 0xFFFFFFFF);
      v12.mStringHash32 = mStringHash32;
    }
    if ( mStringHash32 == this->mEntry.mUID )
      break;
    UFG::qString::~qString(&v12);
    if ( ++v7 >= HIDWORD(v8->mNULL.mParent) )
      goto LABEL_14;
  }
  this->mResolvedValue.qSymbol_mUID = v7;
  v9 = 1;
  UFG::qString::~qString(&v12);
LABEL_14:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mEntry);
  if ( !v9 )
    return 0;
  v5 = v9;
LABEL_16:
  this->mResolved = v5;
  return 1;
}

// File Line: 131
// RVA: 0x250CA0
UEL::Value *__fastcall UEL::ConstantExpression::Eval(
        UEL::ConstantExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *__formal,
        UFG::qArray<UEL::Value,0> *args)
{
  char *v6; // rbx
  char *v7; // rax
  UFG::qString *p_resulta; // rcx
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString resulta; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v13; // [rsp+50h] [rbp-38h] BYREF

  if ( this->mValueType.mBaseType.mValue == 6 )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mEntry);
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mResolvedValue.type.mDetailedType);
    UFG::qString::FormatEx(&resulta, "(\"%s:%s\"", v7, v6);
    p_resulta = &resulta;
  }
  else
  {
    v9 = UEL::Value::ToString(&this->mResolvedValue, &v13);
    UFG::qString::FormatEx(&resulta, "(\"%s\"", v9->mData);
    UFG::qString::~qString(&resulta);
    p_resulta = &v13;
  }
  UFG::qString::~qString(p_resulta);
  v10 = UEL::Value::ToString(&this->mResolvedValue, &resulta);
  UFG::qString::FormatEx(&v13, " [%s])", v10->mData);
  UFG::qString::~qString(&v13);
  UFG::qString::~qString(&resulta);
  result->integer = this->mResolvedValue.integer;
  result->qSymbol_mUID = this->mResolvedValue.qSymbol_mUID;
  result->integer = this->mResolvedValue.integer;
  result->qSymbol_mUID = this->mResolvedValue.qSymbol_mUID;
  result->boolean = this->mResolvedValue.boolean;
  result->qSymbol_mUID = this->mResolvedValue.qSymbol_mUID;
  result->integer = this->mResolvedValue.integer;
  result->integer = this->mResolvedValue.integer;
  result->integer = this->mResolvedValue.integer;
  result->qSymbol_mUID = this->mResolvedValue.qSymbol_mUID;
  result->qVector_y = this->mResolvedValue.qVector_y;
  result->qVector_z = this->mResolvedValue.qVector_z;
  result->qVector_w = this->mResolvedValue.qVector_w;
  result->type.mBaseType.mValue = this->mResolvedValue.type.mBaseType.mValue;
  result->type.mDetailedType.mUID = this->mResolvedValue.type.mDetailedType.mUID;
  return result;
}

