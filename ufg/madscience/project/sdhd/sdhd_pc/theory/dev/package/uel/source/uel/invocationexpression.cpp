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
void __fastcall UEL::InvocationExpression::InvocationExpression(UEL::InvocationExpression *this, const char *identifier, UEL::Expression **expressions, int numExpressions)
{
  signed __int64 v4; // rbx
  UEL::Expression **v5; // rdi
  UEL::InvocationExpression *v6; // rsi
  signed __int64 v7; // rdx
  UFG::qOffset64<UEL::Expression *> *v8; // rax
  signed __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rcx
  UFG::qSymbol result; // [rsp+68h] [rbp+20h]

  v4 = numExpressions;
  v5 = expressions;
  v6 = this;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable';
  this->mType.mValue = 3;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::InvocationExpression::`vftable';
  this->mIdentifier.mUID = -1;
  this->mNumExpressions = numExpressions;
  this->mFunctionTableIndex = -1;
  this->mIdentifier = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, identifier)->mUID;
  v7 = 0i64;
  v8 = v6->mExpressions;
  v9 = (char *)v5 - (char *)v6;
  do
  {
    if ( v7 >= v4 )
    {
      v8->mOffset = 0i64;
    }
    else
    {
      v10 = *(__int64 *)((char *)&v8[-4].mOffset + v9);
      if ( v10 )
        v11 = v10 - (_QWORD)v8;
      else
        v11 = 0i64;
      v8->mOffset = v11;
    }
    ++v7;
    ++v8;
  }
  while ( v7 < 8 );
}

// File Line: 34
// RVA: 0x252CE0
char __fastcall UEL::InvocationExpression::Resolve(UEL::InvocationExpression *this, UEL::Runtime *instance)
{
  UEL::Runtime *v2; // rsi
  UEL::InvocationExpression *v3; // rbx
  unsigned int v4; // edi
  signed __int64 v5; // rax
  signed __int64 v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // rcx
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // r15
  char v11; // al
  unsigned int v12; // eax
  int v13; // esi
  unsigned int v14; // ebp
  __int64 v15; // rax
  UFG::qOffset64<UEL::Expression *> *v16; // rdi
  UEL::Expression *v17; // rcx
  UEL::Value::Type *v18; // rax
  UEL::Expression *v19; // rcx
  UEL::Expression *v20; // rcx
  UEL::Value::Type *v21; // rax
  UEL::Value::Type result; // [rsp+60h] [rbp+8h]
  UEL::Value::Type v23; // [rsp+70h] [rbp+18h]
  UEL::Value::Type v24; // [rsp+78h] [rbp+20h]

  v2 = instance;
  v3 = this;
  v4 = 0;
  if ( this->mNumExpressions )
  {
    while ( 1 )
    {
      v5 = v4 + 4i64;
      v6 = (signed __int64)v3 + 8 * v5;
      v7 = *((_QWORD *)&v3->vfptr + v5);
      v8 = v7 ? v7 + v6 : 0i64;
      if ( !(*(unsigned __int8 (__fastcall **)(signed __int64, UEL::Runtime *))(*(_QWORD *)v8 + 16i64))(v8, v2) )
        break;
      if ( ++v4 >= v3->mNumExpressions )
        goto LABEL_7;
    }
    v11 = 0;
  }
  else
  {
LABEL_7:
    v9 = v3->mIdentifier.mUID;
    if ( v9 )
      v10 = UFG::qBaseTreeRB::Get(&v2->mInvocableBindings->mTree, v9);
    else
      v10 = 0i64;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mIdentifier);
    if ( v10
      && v3->mNumExpressions == BYTE4(v10->mNULL.mParent)
      && ((v3->mValueType.mBaseType.mValue = WORD2(v10[1].mNULL.mParent),
           v12 = (unsigned int)v10[1].mNULL.mChild[0],
           v3->mValueType.mDetailedType.mUID = v12,
           0 != v3->mValueType.mBaseType.mValue)
       || UFG::gNullQSymbol.mUID != v12) )
    {
      v13 = 0;
      v3->mFunctionTableIndex = (unsigned int)v10[1].mNULL.mParent;
      if ( v3->mNumExpressions <= 0 )
      {
LABEL_28:
        v11 = 1;
        v3->mResolved = 1;
      }
      else
      {
        while ( 1 )
        {
          v14 = UFG::gNullQSymbol.mUID;
          v15 = v3->mExpressions[v13].mOffset;
          v16 = &v3->mExpressions[v13];
          v17 = (UEL::Expression *)((char *)v16 + v15);
          if ( !v15 )
            v17 = 0i64;
          v18 = UEL::Expression::GetValueType(v17, &result);
          if ( 0 == v18->mBaseType.mValue && v14 == v18->mDetailedType.mUID )
          {
            v11 = 1;
            v3->mNeedsRuntimeResolve = 1;
            return v11;
          }
          v19 = (UEL::Expression *)((char *)v16 + v16->mOffset);
          if ( !v16->mOffset )
            v19 = 0i64;
          UEL::Expression::GetValueType(v19, &v23);
          UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mIdentifier);
          v20 = (UEL::Expression *)((char *)v16 + v16->mOffset);
          if ( !v16->mOffset )
            v20 = 0i64;
          v21 = UEL::Expression::GetValueType(v20, &v24);
          if ( LOWORD(v10->mNULL.mChild[v13]) != v21->mBaseType.mValue
            || HIDWORD(v10->mNULL.mChild[v13]) != v21->mDetailedType.mUID )
          {
            break;
          }
          if ( ++v13 >= v3->mNumExpressions )
            goto LABEL_28;
        }
        v11 = 0;
      }
    }
    else
    {
      v11 = 0;
    }
  }
  return v11;
}

// File Line: 77
// RVA: 0x251030
UEL::Value *__fastcall UEL::InvocationExpression::Eval(UEL::InvocationExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args)
{
  UFG::qArray<UEL::Value,0> *v4; // r15
  UEL::ParametersBase *v5; // r12
  UEL::Value *v6; // r13
  UEL::InvocationExpression *v7; // rsi
  char *v8; // rax
  unsigned int v9; // edi
  UFG::qOffset64<UEL::Expression *> *v10; // rax
  char *v11; // rcx
  UEL::Value *v12; // rax
  UEL::Value *v13; // rax
  UFG::qString *v14; // rax
  UEL::Value v16; // [rsp+30h] [rbp-A8h]
  UFG::qString resulta; // [rsp+50h] [rbp-88h]
  __int64 v18; // [rsp+78h] [rbp-60h]
  char ptr[256]; // [rsp+88h] [rbp-50h]
  UEL::Value *v20; // [rsp+1C0h] [rbp+E8h]
  void *retaddr; // [rsp+1D8h] [rbp+100h]

  v18 = -2i64;
  v4 = args;
  v5 = parameters;
  v6 = result;
  v7 = this;
  v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mIdentifier);
  UFG::qString::FormatEx(&resulta, "(%s", v8);
  UFG::qString::~qString(&resulta);
  v16.type.mBaseType.mValue = 0;
  v16.type.mDetailedType = UFG::gNullQSymbol;
  `eh vector constructor iterator'(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))UEL::Value::Value);
  v9 = 0;
  if ( v7->mNumExpressions > 0 )
  {
    do
    {
      v10 = &v7->mExpressions[v9];
      if ( v10->mOffset )
        v11 = (char *)v10 + v10->mOffset;
      else
        v11 = 0i64;
      v12 = (UEL::Value *)(*(__int64 (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, void *))(*(_QWORD *)v11 + 24i64))(
                            v11,
                            &resulta,
                            v5,
                            v4,
                            retaddr);
      UEL::Value::operator=((UEL::Value *)&ptr[32 * v9++], v12);
    }
    while ( v9 < v7->mNumExpressions );
    v6 = v20;
  }
  v13 = UEL::ParametersBase::FunctionTable[v7->mFunctionTableIndex]((UEL::Value *)&resulta, (UEL::Value *)ptr);
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
  v14 = UEL::Value::ToString(&v16, (UFG::qString *)((char *)&resulta + 8));
  UFG::qString::FormatEx(&resulta, " [%s])", v14->mData);
  UFG::qString::~qString(&resulta);
  UFG::qString::~qString((UFG::qString *)((char *)&resulta + 8));
  v6->integer = v16.integer;
  v6->qSymbol_mUID = v16.qSymbol_mUID;
  v6->qVector_y = v16.qVector_y;
  v6->qVector_z = v16.qVector_z;
  v6->qVector_w = v16.qVector_w;
  v6->type.mBaseType.mValue = v16.type.mBaseType.mValue;
  v6->type.mDetailedType.mUID = v16.type.mDetailedType.mUID;
  `eh vector destructor iterator'(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))_);
  return v6;
}

