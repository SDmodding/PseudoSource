// File Line: 7
// RVA: 0x1475EB0
__int64 dynamic_initializer_for__UEL::FragmentExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FragmentExpression", 0xFFFFFFFF);
  UEL::FragmentExpression::sClassNameUID = result;
  return result;
}

// File Line: 8
// RVA: 0x1475ED0
__int64 dynamic_initializer_for__UEL::FragmentInvocationExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FragmentInvocationExpression", 0xFFFFFFFF);
  UEL::FragmentInvocationExpression::sClassNameUID = result;
  return result;
}

// File Line: 29
// RVA: 0x24E640
void __fastcall UEL::FragmentExpression::~FragmentExpression(UEL::FragmentExpression *this)
{
  UEL::FragmentExpression *v1; // rdi
  __int64 v2; // rax
  _QWORD *v3; // rcx
  unsigned int v4; // ebx
  UEL::ExpressionVtbl **v5; // rcx
  _QWORD *v6; // rcx

  v1 = this;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::FragmentExpression::`vftable;
  v2 = this->mExpression.mOffset;
  if ( v2 )
  {
    v3 = (__int64 *)((char *)&this->mExpression.mOffset + v2);
    if ( v3 )
    {
      *v3 = &UEL::Expression::`vftable;
      operator delete[](v3);
    }
  }
  v4 = 0;
  if ( v1->mNumArguments )
  {
    do
    {
      v5 = &v1->vfptr + v4 + 3i64;
      if ( *v5 )
        v6 = (UEL::ExpressionVtbl **)((char *)v5 + (_QWORD)*v5);
      else
        v6 = 0i64;
      if ( v6 )
      {
        *v6 = &UEL::Expression::`vftable;
        operator delete[](v6);
      }
      ++v4;
    }
    while ( v4 < v1->mNumArguments );
  }
  v1->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
}

// File Line: 38
// RVA: 0x252A90
bool __fastcall UEL::FragmentExpression::Resolve(UEL::FragmentExpression *this, UEL::Runtime *instance)
{
  UEL::FragmentExpression *v2; // rbp
  UEL::Runtime *v3; // r15
  __int64 v4; // rsi
  __int64 v5; // rax
  signed __int64 v6; // rdi
  signed __int64 v7; // rcx
  __int64 v8; // r14
  unsigned int v9; // ebx
  unsigned int v10; // edx
  UEL::Expression *v11; // rax
  UEL::NameExpressionPair *v12; // rcx
  UEL::Expression *v13; // rax
  __int64 v14; // rax
  signed __int64 v15; // rcx
  UEL::Expression **v16; // rbx

  v2 = this;
  v3 = instance;
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  v4 = 0i64;
  if ( v2->mNumArguments )
  {
    do
    {
      v5 = v2->mArguments[v4].mOffset;
      v6 = (signed __int64)&v2->mArguments[v4];
      if ( v5 )
        v7 = v5 + v6;
      else
        v7 = 0i64;
      (*(void (__fastcall **)(signed __int64, UEL::Runtime *))(*(_QWORD *)v7 + 16i64))(v7, v3);
      v8 = UEL::ArgumentUsageExpression::msActiveResolveArguments.size;
      v9 = UEL::ArgumentUsageExpression::msActiveResolveArguments.size + 1;
      if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.size + 1 > UEL::ArgumentUsageExpression::msActiveResolveArguments.capacity )
      {
        if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.capacity )
          v10 = 2 * UEL::ArgumentUsageExpression::msActiveResolveArguments.capacity;
        else
          v10 = 1;
        for ( ; v10 < v9; v10 *= 2 )
          ;
        if ( v10 - v9 > 0x10000 )
          v10 = UEL::ArgumentUsageExpression::msActiveResolveArguments.size + 65537;
        UFG::qArray<UEL::NameExpressionPair,0>::Reallocate(
          &UEL::ArgumentUsageExpression::msActiveResolveArguments,
          v10,
          "qArray.Add");
      }
      UEL::ArgumentUsageExpression::msActiveResolveArguments.size = v9;
      v11 = *(UEL::Expression **)v6;
      v12 = &UEL::ArgumentUsageExpression::msActiveResolveArguments.p[v8];
      if ( *(_QWORD *)v6 )
        v11 = (UEL::Expression *)((char *)v11 + v6);
      v12->name.mUID = (unsigned int)v11[1].vfptr;
      v13 = *(UEL::Expression **)v6;
      if ( *(_QWORD *)v6 )
        v13 = (UEL::Expression *)((char *)v13 + v6);
      v4 = (unsigned int)(v4 + 1);
      v12->expr = v13;
    }
    while ( (unsigned int)v4 < v2->mNumArguments );
  }
  v14 = v2->mExpression.mOffset;
  if ( v14 )
    v15 = (signed __int64)&v2->mExpression + v14;
  else
    v15 = 0i64;
  v2->mResolved = (*(unsigned __int8 (__fastcall **)(signed __int64, UEL::Runtime *))(*(_QWORD *)v15 + 16i64))(v15, v3);
  if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.p )
  {
    v16 = &UEL::ArgumentUsageExpression::msActiveResolveArguments.p[-1].expr;
    `eh vector destructor iterator(
      UEL::ArgumentUsageExpression::msActiveResolveArguments.p,
      0x10ui64,
      (int)UEL::ArgumentUsageExpression::msActiveResolveArguments.p[-1].expr,
      (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
  UEL::ArgumentUsageExpression::msActiveResolveArguments.p = 0i64;
  *(_QWORD *)&UEL::ArgumentUsageExpression::msActiveResolveArguments.size = 0i64;
  return v2->mResolved != 0;
}

// File Line: 55
// RVA: 0x250DF0
UEL::Value *__fastcall UEL::FragmentExpression::Eval(UEL::FragmentExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args, UFG::qStringBuilder *debugStringBuilder)
{
  __int64 v5; // rax
  UEL::Value *v6; // rbx
  char *v7; // rcx

  v5 = this->mExpression.mOffset;
  v6 = result;
  if ( v5 )
    v7 = (char *)&this->mExpression + v5;
  else
    v7 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v7 + 24i64))(
    v7,
    result,
    parameters,
    args,
    debugStringBuilder);
  return v6;
}

// File Line: 64
// RVA: 0x24E260
void __fastcall UEL::FragmentInvocationExpression::FragmentInvocationExpression(UEL::FragmentInvocationExpression *this, const char *name, int numArgs, UEL::Expression **args)
{
  UEL::Expression **v4; // rdi
  signed __int64 v5; // rbx
  UEL::FragmentInvocationExpression *v6; // rsi
  signed __int64 v7; // rdx
  UFG::qOffset64<UEL::Expression *> *v8; // rax
  signed __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rcx

  v4 = args;
  v5 = numArgs;
  v6 = this;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 7;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::FragmentInvocationExpression::`vftable;
  this->mFragmentTableIndex = -1;
  UFG::qSymbol::create_from_string(&this->mName, name);
  v6->mNumArguments = v5;
  v7 = 0i64;
  v8 = v6->mArguments;
  v9 = (char *)v4 - (char *)v6;
  do
  {
    if ( v7 >= v5 )
    {
      v8->mOffset = 0i64;
    }
    else
    {
      v10 = *(__int64 *)((char *)&v8[-3].mOffset + v9);
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

// File Line: 77
// RVA: 0x252C10
char __fastcall UEL::FragmentInvocationExpression::Resolve(UEL::FragmentInvocationExpression *this, UEL::Runtime *instance)
{
  UFG::qBaseTreeRB *v2; // rsi
  UFG::qBaseTreeRB **v3; // r14
  UEL::FragmentInvocationExpression *v4; // rdi
  unsigned int v5; // ebx
  signed __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  unsigned int v10; // edx
  char result; // al

  v2 = 0i64;
  v3 = (UFG::qBaseTreeRB **)instance;
  v4 = this;
  v5 = 0;
  if ( this->mNumArguments )
  {
    while ( 1 )
    {
      v6 = v5 + 3i64;
      v7 = (signed __int64)v4 + 8 * v6;
      v8 = *((_QWORD *)&v4->vfptr + v6);
      v9 = v8 ? v8 + v7 : 0i64;
      if ( !(*(unsigned __int8 (__fastcall **)(signed __int64, UFG::qBaseTreeRB **))(*(_QWORD *)v9 + 16i64))(v9, v3) )
        break;
      if ( ++v5 >= v4->mNumArguments )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v10 = v4->mName.mUID;
    if ( v10 )
      v2 = UFG::qBaseTreeRB::Get(*v3, v10);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mName);
    if ( v2 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->mName);
      if ( v4->mNumArguments == BYTE4(v2->mNULL.mParent) )
      {
        v4->mValueType.mBaseType.mValue = WORD2(v2->mNULL.mChild[0]);
        v4->mValueType.mDetailedType.mUID = (unsigned int)v2->mNULL.mChild[1];
        v4->mFragmentTableIndex = (unsigned int)v2->mNULL.mChild[0];
        result = 1;
        v4->mResolved = 1;
        return result;
      }
    }
  }
  return 0;
}

// File Line: 102
// RVA: 0x250E30
UEL::Value *__fastcall UEL::FragmentInvocationExpression::Eval(UEL::FragmentInvocationExpression *this, UEL::Value *result, UEL::ParametersBase *parameters, UFG::qArray<UEL::Value,0> *args, UFG::qStringBuilder *debugStringBuilder)
{
  UEL::ParametersBase *v5; // r12
  UEL::Value *v6; // r15
  UEL::FragmentInvocationExpression *v7; // rsi
  unsigned int v8; // edi
  UEL::ExpressionVtbl **v9; // rcx
  char *v10; // rcx
  UEL::Value *v11; // r14
  __int64 v12; // rbp
  unsigned int v13; // ebx
  unsigned int v14; // edx
  char *v15; // rcx
  char *v16; // rdx
  char *v17; // rcx
  UFG::qString *v18; // rax
  UFG::qSymbol *v19; // rbx
  UFG::qArray<UEL::Value,0> v21; // [rsp+38h] [rbp-A0h]
  UFG::qString resulta; // [rsp+48h] [rbp-90h]
  UFG::qString v23; // [rsp+70h] [rbp-68h]
  UEL::Value *v24; // [rsp+E8h] [rbp+10h]
  UFG::qArray<UEL::Value,0> *v25; // [rsp+F8h] [rbp+20h]

  v25 = args;
  v24 = result;
  v5 = parameters;
  v6 = result;
  v7 = this;
  UFG::qString::FormatEx(&resulta, "(FragmentInvocation ");
  UFG::qString::~qString(&resulta);
  v21.p = 0i64;
  *(_QWORD *)&v21.size = 0i64;
  v8 = 0;
  if ( v7->mNumArguments )
  {
    do
    {
      v9 = &v7->vfptr + v8 + 3i64;
      if ( *v9 )
        v10 = (char *)v9 + (_QWORD)*v9;
      else
        v10 = 0i64;
      v11 = (UEL::Value *)(*(__int64 (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v10 + 24i64))(
                            v10,
                            &resulta,
                            v5,
                            v25,
                            debugStringBuilder);
      v12 = v21.size;
      v13 = v21.size + 1;
      if ( v21.size + 1 > v21.capacity )
      {
        if ( v21.capacity )
          v14 = 2 * v21.capacity;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 - v13 > 0x10000 )
          v14 = v21.size + 65537;
        UFG::qArray<UEL::Value,0>::Reallocate(&v21, v14, "qArray.Add");
      }
      v21.size = v13;
      UEL::Value::operator=(&v21.p[v12], v11);
      ++v8;
    }
    while ( v8 < v7->mNumArguments );
    v6 = v24;
  }
  if ( UEL::ParametersBase::FragmentTable.mOffset )
    v15 = (char *)&UEL::ParametersBase::FragmentTable + UEL::ParametersBase::FragmentTable.mOffset;
  else
    v15 = 0i64;
  v16 = &v15[8 * v7->mFragmentTableIndex];
  if ( *(_QWORD *)v16 )
    v17 = &v16[*(_QWORD *)v16];
  else
    v17 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v17 + 24i64))(
    v17,
    v6,
    v5,
    &v21,
    debugStringBuilder);
  v18 = UEL::Value::ToString(v6, &v23);
  UFG::qString::FormatEx(&resulta, " [%s])", v18->mData);
  UFG::qString::~qString(&resulta);
  UFG::qString::~qString(&v23);
  if ( v21.p )
  {
    v19 = &v21.p[-1].type.mDetailedType;
    `eh vector destructor iterator(v21.p, 0x20ui64, v21.p[-1].type.mDetailedType.mUID, (void (__fastcall *)(void *))_);
    operator delete[](v19);
  }
  return v6;
}

