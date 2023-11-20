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
  return atexit(dynamic_atexit_destructor_for__strTrue__);
}

// File Line: 10
// RVA: 0x1475FB0
__int64 dynamic_initializer_for__strFalse__()
{
  UFG::qString::qString(&strFalse, "false");
  return atexit(dynamic_atexit_destructor_for__strFalse__);
}

// File Line: 14
// RVA: 0x24E060
void __fastcall UEL::ConstantExpression::ConstantExpression(UEL::ConstantExpression *this, const char *text, const char *text2, UEL::Value::Type type)
{
  UEL::Value::Type v4; // rsi
  const char *v5; // r14
  const char *v6; // rbp
  UEL::ConstantExpression *v7; // rbx
  __int16 v8; // r8
  bool v9; // dl
  unsigned int v10; // er14
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // eax
  UFG::qSymbol result; // [rsp+78h] [rbp+20h]

  v4 = type;
  v5 = text2;
  v6 = text;
  v7 = this;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 2;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ConstantExpression::`vftable;
  this->mEntry.mUID = -1;
  this->mResolvedValue.type.mBaseType.mValue = 0;
  this->mResolvedValue.type.mDetailedType = UFG::gNullQSymbol;
  v8 = **(_WORD **)&type;
  v9 = 2 == **(_WORD **)&type && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&type + 4i64)
    || v8 == 3 && UFG::gNullQSymbol.mUID == *(_DWORD *)(*(_QWORD *)&type + 4i64);
  if ( v9 )
  {
    v10 = UFG::qStringLength(v6);
    if ( v10 < 0x400 )
    {
      UFG::qStringCopy(buffer_1, 128, v6 + 1, -1);
      buffer_1[v10 - 2] = 0;
    }
  }
  else if ( v8 != 6 || UFG::gNullQSymbol.mUID != *(_DWORD *)(*(_QWORD *)&type + 4i64) )
  {
    UFG::qStringCopy(buffer_1, 128, v6, -1);
  }
  else
  {
    this->mResolvedValue.type.mDetailedType = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, v6)->mUID;
    v7->mEntry = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, v5)->mUID;
  }
  v7->mValueType.mBaseType.mValue = **(_WORD **)&v4;
  v7->mValueType.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&v4 + 4i64);
  v11 = v7->mValueType.mBaseType.mValue;
  v7->mResolvedValue.type.mBaseType.mValue = v11;
  v12 = v11 - 1;
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
            v7->mResolvedValue.boolean = buffer_1 == strTrue.mData;
        }
        else
        {
          v7->mResolvedValue.real = UFG::qToFloat(buffer_1, 0.0);
        }
      }
      else
      {
        UEL::Value::SetString(&v7->mResolvedValue, buffer_1);
      }
    }
    else
    {
      v16 = UFG::gNullQSymbol.mUID;
      v7->mResolvedValue.type.mBaseType.mValue = 2;
      v7->mResolvedValue.type.mDetailedType.mUID = v16;
      LODWORD(v7->mResolvedValue.integer) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, buffer_1)->mUID;
    }
  }
  else
  {
    v7->mResolvedValue.integer = UFG::qToInt64(buffer_1, 0i64);
  }
}

// File Line: 79
// RVA: 0x252950
char __usercall UEL::ConstantExpression::Resolve@<al>(UEL::ConstantExpression *this@<rcx>, UEL::Runtime *instance@<rdx>, __int64 a3@<r14>)
{
  UEL::Runtime *v3; // r9
  UEL::ConstantExpression *v4; // rbx
  signed __int16 v5; // ax
  unsigned int v6; // edx
  unsigned int v7; // edi
  UFG::qBaseTreeRB *v8; // rsi
  unsigned __int8 v9; // bp
  int v10; // edx
  unsigned int v11; // eax
  UFG::qString v13; // [rsp+28h] [rbp-30h]
  __int64 v14; // [rsp+50h] [rbp-8h]

  v14 = a3;
  v3 = instance;
  v4 = this;
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
      v6 = this->mResolvedValue.type.mDetailedType.mUID;
      v7 = 0;
      if ( v6 )
        v8 = UFG::qBaseTreeRB::Get(&v3->mEnumBindings->mTree, v6);
      else
        v8 = 0i64;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mResolvedValue.type.mDetailedType);
      if ( !v8 )
        return 0;
      v9 = 0;
      if ( HIDWORD(v8->mNULL.mParent) <= 0 )
        goto LABEL_14;
      break;
    default:
      return 0;
  }
  while ( 1 )
  {
    UFG::qString::qString(&v13, *((const char **)&v8->mNULL.mChild[0]->mParent + v7));
    v11 = v13.mStringHash32;
    if ( v13.mStringHash32 == -1 )
    {
      v11 = UFG::qStringHash32(v13.mData, v13.mStringHash32 | v10);
      v13.mStringHash32 = v11;
    }
    if ( v11 == v4->mEntry.mUID )
      break;
    UFG::qString::~qString(&v13);
    if ( ++v7 >= HIDWORD(v8->mNULL.mParent) )
      goto LABEL_14;
  }
  v4->mResolvedValue.qSymbol_mUID = v7;
  v9 = 1;
  UFG::qString::~qString(&v13);
LABEL_14:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mEntry);
  if ( !v9 )
    return 0;
  v5 = v9;
LABEL_16:
  v4->mResolved = v5;
  return 1;
}

// File Line: 131
// RVA: 0x250CA0
UEL::Value *__fastcall UEL::ConstantExpression::Eval(UEL::ConstantExpression *this, UEL::Value *result, UEL::ParametersBase *__formal, UFG::qArray<UEL::Value,0> *args)
{
  UEL::Value *v4; // rsi
  UEL::ConstantExpression *v5; // rdi
  char *v6; // rbx
  char *v7; // rax
  UFG::qString *v8; // rcx
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString resulta; // [rsp+28h] [rbp-60h]
  UFG::qString v13; // [rsp+50h] [rbp-38h]

  v4 = result;
  v5 = this;
  if ( this->mValueType.mBaseType.mValue == 6 )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mEntry);
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->mResolvedValue.type.mDetailedType);
    UFG::qString::FormatEx(&resulta, "(\"%s:%s\"", v7, v6, -2i64);
    v8 = &resulta;
  }
  else
  {
    v9 = UEL::Value::ToString(&this->mResolvedValue, &v13);
    UFG::qString::FormatEx(&resulta, "(\"%s\"", v9->mData);
    UFG::qString::~qString(&resulta);
    v8 = &v13;
  }
  UFG::qString::~qString(v8);
  v10 = UEL::Value::ToString(&v5->mResolvedValue, &resulta);
  UFG::qString::FormatEx(&v13, " [%s])", v10->mData);
  UFG::qString::~qString(&v13);
  UFG::qString::~qString(&resulta);
  v4->integer = v5->mResolvedValue.integer;
  v4->qSymbol_mUID = v5->mResolvedValue.qSymbol_mUID;
  v4->integer = v5->mResolvedValue.integer;
  v4->qSymbol_mUID = v5->mResolvedValue.qSymbol_mUID;
  v4->boolean = v5->mResolvedValue.boolean;
  v4->qSymbol_mUID = v5->mResolvedValue.qSymbol_mUID;
  v4->integer = v5->mResolvedValue.integer;
  v4->integer = v5->mResolvedValue.integer;
  v4->integer = v5->mResolvedValue.integer;
  v4->qSymbol_mUID = v5->mResolvedValue.qSymbol_mUID;
  v4->qVector_y = v5->mResolvedValue.qVector_y;
  v4->qVector_z = v5->mResolvedValue.qVector_z;
  v4->qVector_w = v5->mResolvedValue.qVector_w;
  v4->type.mBaseType.mValue = v5->mResolvedValue.type.mBaseType.mValue;
  v4->type.mDetailedType.mUID = v5->mResolvedValue.type.mDetailedType.mUID;
  return v4;
}

