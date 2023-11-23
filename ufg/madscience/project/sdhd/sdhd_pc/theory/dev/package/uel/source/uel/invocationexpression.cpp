// File Line: 5
// RVA: 0x1475EF0
__int64 dynamic_initializer_for__UEL::InvocationExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InvocationExpression", 0xFFFFFFFF);
  UEL::InvocationExpression::sClassNameUID = result;
  return result;
}

// File Line: 13
// RVA: 0x24E320
void __fastcall UEL::InvocationExpression::InvocationExpression(
        UEL::InvocationExpression *this,
        const char *identifier,
        UEL::Expression **expressions,
        unsigned int numExpressions)
{
  __int64 v4; // rbx
  __int64 v7; // rdx
  UFG::qOffset64<UEL::Expression *> *mExpressions; // rax
  signed __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rcx
  UFG::qSymbol result; // [rsp+68h] [rbp+20h] BYREF

  v4 = (int)numExpressions;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 3;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::InvocationExpression::`vftable;
  this->mIdentifier.mUID = -1;
  this->mNumExpressions = numExpressions;
  this->mFunctionTableIndex = -1;
  this->mIdentifier = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, identifier)->mUID;
  v7 = 0i64;
  mExpressions = this->mExpressions;
  v9 = (char *)expressions - (char *)this;
  do
  {
    if ( v7 >= v4 )
    {
      mExpressions->mOffset = 0i64;
    }
    else
    {
      v10 = *(__int64 *)((char *)&mExpressions[-4].mOffset + v9);
      if ( v10 )
        v11 = v10 - (_QWORD)mExpressions;
      else
        v11 = 0i64;
      mExpressions->mOffset = v11;
    }
    ++v7;
    ++mExpressions;
  }
  while ( v7 < 8 );
}

// File Line: 34
// RVA: 0x252CE0
bool __fastcall UEL::InvocationExpression::Resolve(UEL::InvocationExpression *this, UEL::Runtime *instance)
{
  int v4; // edi
  UFG::qOffset64<UEL::Expression *> *v5; // rcx
  char *v6; // rcx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v8; // r15
  bool v9; // al
  unsigned int v10; // eax
  int v11; // esi
  unsigned int v12; // ebp
  __int64 mOffset; // rax
  UFG::qOffset64<UEL::Expression *> *v14; // rdi
  UEL::Expression *v15; // rcx
  UEL::Value::Type *ValueType; // rax
  UEL::Expression *v17; // rcx
  UEL::Expression *v18; // rcx
  UEL::Value::Type *v19; // rax
  UEL::Value::Type result; // [rsp+60h] [rbp+8h] BYREF
  UEL::Value::Type v21; // [rsp+70h] [rbp+18h] BYREF
  UEL::Value::Type v22; // [rsp+78h] [rbp+20h] BYREF

  v4 = 0;
  if ( this->mNumExpressions )
  {
    while ( 1 )
    {
      v5 = &this->mExpressions[v4];
      v6 = v5->mOffset ? (char *)v5 + v5->mOffset : 0i64;
      if ( !(*(unsigned __int8 (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v6 + 16i64))(v6, instance) )
        return 0;
      if ( ++v4 >= this->mNumExpressions )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    mUID = this->mIdentifier.mUID;
    if ( mUID )
      v8 = UFG::qBaseTreeRB::Get(&instance->mInvocableBindings->mTree, mUID);
    else
      v8 = 0i64;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mIdentifier);
    if ( v8
      && this->mNumExpressions == BYTE4(v8->mNULL.mParent)
      && ((this->mValueType.mBaseType.mValue = WORD2(v8[1].mNULL.mParent),
           v10 = (unsigned int)v8[1].mNULL.mChild[0],
           this->mValueType.mDetailedType.mUID = v10,
           this->mValueType.mBaseType.mValue)
       || UFG::gNullQSymbol.mUID != v10) )
    {
      v11 = 0;
      this->mFunctionTableIndex = (unsigned int)v8[1].mNULL.mParent;
      if ( this->mNumExpressions )
      {
        while ( 1 )
        {
          v12 = UFG::gNullQSymbol.mUID;
          mOffset = this->mExpressions[v11].mOffset;
          v14 = &this->mExpressions[v11];
          v15 = (UEL::Expression *)((char *)v14 + mOffset);
          if ( !mOffset )
            v15 = 0i64;
          ValueType = UEL::Expression::GetValueType(v15, &result);
          if ( !ValueType->mBaseType.mValue && v12 == ValueType->mDetailedType.mUID )
          {
            v9 = 1;
            this->mNeedsRuntimeResolve = 1;
            return v9;
          }
          v17 = (UEL::Expression *)((char *)v14 + v14->mOffset);
          if ( !v14->mOffset )
            v17 = 0i64;
          UEL::Expression::GetValueType(v17, &v21);
          UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mIdentifier);
          v18 = (UEL::Expression *)((char *)v14 + v14->mOffset);
          if ( !v14->mOffset )
            v18 = 0i64;
          v19 = UEL::Expression::GetValueType(v18, &v22);
          if ( LOWORD(v8->mNULL.mChild[v11]) != v19->mBaseType.mValue
            || HIDWORD(v8->mNULL.mChild[v11]) != v19->mDetailedType.mUID )
          {
            return 0;
          }
          if ( ++v11 >= this->mNumExpressions )
            goto LABEL_28;
        }
      }
      else
      {
LABEL_28:
        v9 = 1;
        this->mResolved = 1;
      }
    }
    else
    {
      return 0;
    }
  }
  return v9;
}

// File Line: 77
// RVA: 0x251030
UEL::Value *__fastcall UEL::InvocationExpression::Eval(
        UEL::InvocationExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  char *v8; // rax
  unsigned int v9; // edi
  UFG::qOffset64<UEL::Expression *> *v10; // rax
  char *v11; // rcx
  UEL::Value *v12; // rax
  UEL::Value *v13; // rax
  UFG::qString *v14; // rax
  UEL::Value v16; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qString resulta; // [rsp+50h] [rbp-88h] BYREF
  __int64 v18; // [rsp+78h] [rbp-60h]
  _OWORD ptr[16]; // [rsp+88h] [rbp-50h] BYREF
  UEL::Value *v20; // [rsp+1C0h] [rbp+E8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  v18 = -2i64;
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mIdentifier);
  UFG::qString::FormatEx(&resulta, "(%s", v8);
  UFG::qString::~qString(&resulta);
  v16.type.mBaseType.mValue = 0;
  v16.type.mDetailedType = UFG::gNullQSymbol;
  `eh vector constructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))UEL::Value::Value);
  v9 = 0;
  if ( this->mNumExpressions )
  {
    do
    {
      v10 = &this->mExpressions[v9];
      if ( v10->mOffset )
        v11 = (char *)v10 + v10->mOffset;
      else
        v11 = 0i64;
      v12 = (UEL::Value *)(*(__int64 (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v11 + 24i64))(
                            v11,
                            &resulta,
                            parameters,
                            args,
                            retaddr);
      UEL::Value::operator=((UEL::Value *)&ptr[2 * v9++], v12);
    }
    while ( v9 < this->mNumExpressions );
    result = v20;
  }
  v13 = UEL::ParametersBase::FunctionTable[this->mFunctionTableIndex]((UEL::Value *)&resulta, (UEL::Value *)ptr);
  v16.type.mBaseType.mValue = v13->type.mBaseType.mValue;
  v16.type.mDetailedType.mUID = v13->type.mDetailedType.mUID;
  switch ( v13->type.mBaseType.mValue )
  {
    case 1u:
    case 3u:
    case 8u:
    case 9u:
    case 0xAu:
      v16.integer = v13->integer;
      break;
    case 2u:
    case 6u:
      v16.qSymbol_mUID = v13->qSymbol_mUID;
      break;
    case 4u:
      v16.qSymbol_mUID = v13->qSymbol_mUID;
      break;
    case 5u:
      v16.boolean = v13->boolean;
      break;
    case 7u:
      v16.qSymbol_mUID = v13->qSymbol_mUID;
      v16.qVector_y = v13->qVector_y;
      v16.qVector_z = v13->qVector_z;
      v16.qVector_w = v13->qVector_w;
      break;
    default:
      break;
  }
  v14 = UEL::Value::ToString(&v16, (UFG::qString *)&resulta.mNext);
  UFG::qString::FormatEx(&resulta, " [%s])", v14->mData);
  UFG::qString::~qString(&resulta);
  UFG::qString::~qString((UFG::qString *)&resulta.mNext);
  result->integer = v16.integer;
  result->qSymbol_mUID = v16.qSymbol_mUID;
  result->qVector_y = v16.qVector_y;
  result->qVector_z = v16.qVector_z;
  result->qVector_w = v16.qVector_w;
  result->type.mBaseType.mValue = v16.type.mBaseType.mValue;
  result->type.mDetailedType.mUID = v16.type.mDetailedType.mUID;
  `eh vector destructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))_);
  return result;
}

