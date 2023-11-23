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
  __int64 mOffset; // rax
  _QWORD *v3; // rcx
  unsigned int i; // ebx
  UFG::qOffset64<UEL::ArgumentExpression *> *v5; // rcx
  _QWORD *v6; // rcx

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::FragmentExpression::`vftable;
  mOffset = this->mExpression.mOffset;
  if ( mOffset )
  {
    v3 = (__int64 *)((char *)&this->mExpression.mOffset + mOffset);
    if ( v3 )
    {
      *v3 = &UEL::Expression::`vftable;
      operator delete[](v3);
    }
  }
  for ( i = 0; i < this->mNumArguments; ++i )
  {
    v5 = &this->mArguments[i];
    if ( v5->mOffset )
      v6 = (__int64 *)((char *)&v5->mOffset + v5->mOffset);
    else
      v6 = 0i64;
    if ( v6 )
    {
      *v6 = &UEL::Expression::`vftable;
      operator delete[](v6);
    }
  }
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
}

// File Line: 38
// RVA: 0x252A90
bool __fastcall UEL::FragmentExpression::Resolve(UEL::FragmentExpression *this, UEL::Runtime *instance)
{
  __int64 i; // rsi
  __int64 mOffset; // rax
  UFG::qOffset64<UEL::ArgumentExpression *> *v6; // rdi
  char *v7; // rcx
  __int64 size; // r14
  unsigned int v9; // ebx
  unsigned int v10; // edx
  __int64 v11; // rax
  UEL::NameExpressionPair *v12; // rcx
  UEL::Expression *v13; // rax
  __int64 v14; // rax
  char *v15; // rcx
  UEL::Expression **p_expr; // rbx

  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  for ( i = 0i64; (unsigned int)i < this->mNumArguments; v12->expr = v13 )
  {
    mOffset = this->mArguments[i].mOffset;
    v6 = &this->mArguments[i];
    if ( mOffset )
      v7 = (char *)v6 + mOffset;
    else
      v7 = 0i64;
    (*(void (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v7 + 16i64))(v7, instance);
    size = UEL::ArgumentUsageExpression::msActiveResolveArguments.size;
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
    v11 = v6->mOffset;
    v12 = &UEL::ArgumentUsageExpression::msActiveResolveArguments.p[size];
    if ( v6->mOffset )
      v11 += (__int64)v6;
    v12->name.mUID = *(_DWORD *)(v11 + 24);
    v13 = (UEL::Expression *)v6->mOffset;
    if ( v6->mOffset )
      v13 = (UEL::Expression *)((char *)v13 + (_QWORD)v6);
    i = (unsigned int)(i + 1);
  }
  v14 = this->mExpression.mOffset;
  if ( v14 )
    v15 = (char *)&this->mExpression + v14;
  else
    v15 = 0i64;
  this->mResolved = (*(unsigned __int8 (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v15 + 16i64))(v15, instance);
  if ( UEL::ArgumentUsageExpression::msActiveResolveArguments.p )
  {
    p_expr = &UEL::ArgumentUsageExpression::msActiveResolveArguments.p[-1].expr;
    `eh vector destructor iterator(
      UEL::ArgumentUsageExpression::msActiveResolveArguments.p,
      0x10ui64,
      (int)UEL::ArgumentUsageExpression::msActiveResolveArguments.p[-1].expr,
      (void (__fastcall *)(void *))_);
    operator delete[](p_expr);
  }
  UEL::ArgumentUsageExpression::msActiveResolveArguments.p = 0i64;
  *(_QWORD *)&UEL::ArgumentUsageExpression::msActiveResolveArguments.size = 0i64;
  return this->mResolved != 0;
}

// File Line: 55
// RVA: 0x250DF0
UEL::Value *__fastcall UEL::FragmentExpression::Eval(
        UEL::FragmentExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args,
        UFG::qStringBuilder *debugStringBuilder)
{
  __int64 mOffset; // rax
  char *v7; // rcx

  mOffset = this->mExpression.mOffset;
  if ( mOffset )
    v7 = (char *)&this->mExpression + mOffset;
  else
    v7 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v7 + 24i64))(
    v7,
    result,
    parameters,
    args,
    debugStringBuilder);
  return result;
}

// File Line: 64
// RVA: 0x24E260
void __fastcall UEL::FragmentInvocationExpression::FragmentInvocationExpression(
        UEL::FragmentInvocationExpression *this,
        const char *name,
        int numArgs,
        UEL::Expression **args)
{
  __int64 v5; // rbx
  __int64 v7; // rdx
  UFG::qOffset64<UEL::Expression *> *mArguments; // rax
  signed __int64 v9; // rdi
  __int64 v10; // rcx
  __int64 v11; // rcx

  v5 = numArgs;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 7;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::FragmentInvocationExpression::`vftable;
  this->mFragmentTableIndex = -1;
  UFG::qSymbol::create_from_string(&this->mName, name);
  this->mNumArguments = v5;
  v7 = 0i64;
  mArguments = this->mArguments;
  v9 = (char *)args - (char *)this;
  do
  {
    if ( v7 >= v5 )
    {
      mArguments->mOffset = 0i64;
    }
    else
    {
      v10 = *(__int64 *)((char *)&mArguments[-3].mOffset + v9);
      if ( v10 )
        v11 = v10 - (_QWORD)mArguments;
      else
        v11 = 0i64;
      mArguments->mOffset = v11;
    }
    ++v7;
    ++mArguments;
  }
  while ( v7 < 8 );
}

// File Line: 77
// RVA: 0x252C10
bool __fastcall UEL::FragmentInvocationExpression::Resolve(
        UEL::FragmentInvocationExpression *this,
        UEL::Runtime *instance)
{
  UFG::qBaseTreeRB *v2; // rsi
  int v5; // ebx
  UFG::qOffset64<UEL::Expression *> *v6; // rcx
  char *v7; // rcx
  unsigned int mUID; // edx
  bool result; // al

  v2 = 0i64;
  v5 = 0;
  if ( this->mNumArguments )
  {
    while ( 1 )
    {
      v6 = &this->mArguments[v5];
      v7 = v6->mOffset ? (char *)v6 + v6->mOffset : 0i64;
      if ( !(*(unsigned __int8 (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v7 + 16i64))(v7, instance) )
        break;
      if ( ++v5 >= this->mNumArguments )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    mUID = this->mName.mUID;
    if ( mUID )
      v2 = UFG::qBaseTreeRB::Get(&instance->mFragmentBindings->mTree, mUID);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    if ( v2 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
      if ( this->mNumArguments == BYTE4(v2->mNULL.mParent) )
      {
        this->mValueType.mBaseType.mValue = WORD2(v2->mNULL.mChild[0]);
        this->mValueType.mDetailedType.mUID = (unsigned int)v2->mNULL.mChild[1];
        this->mFragmentTableIndex = (unsigned int)v2->mNULL.mChild[0];
        result = 1;
        this->mResolved = 1;
        return result;
      }
    }
  }
  return 0;
}

// File Line: 102
// RVA: 0x250E30
UEL::Value *__fastcall UEL::FragmentInvocationExpression::Eval(
        UEL::FragmentInvocationExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args,
        UFG::qStringBuilder *debugStringBuilder)
{
  UEL::Value *v6; // r15
  unsigned int v8; // edi
  UFG::qOffset64<UEL::Expression *> *v9; // rcx
  char *v10; // rcx
  UEL::Value *v11; // r14
  __int64 size; // rbp
  unsigned int v13; // ebx
  unsigned int v14; // edx
  char *v15; // rcx
  char *v16; // rdx
  char *v17; // rcx
  UFG::qString *v18; // rax
  UFG::qSymbol *p_mDetailedType; // rbx
  UFG::qArray<UEL::Value,0> v21; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qString resulta; // [rsp+48h] [rbp-90h] BYREF
  UFG::qString v23; // [rsp+70h] [rbp-68h] BYREF

  v6 = result;
  UFG::qString::FormatEx(&resulta, "(FragmentInvocation ");
  UFG::qString::~qString(&resulta);
  v21.p = 0i64;
  *(_QWORD *)&v21.size = 0i64;
  v8 = 0;
  if ( this->mNumArguments )
  {
    do
    {
      v9 = &this->mArguments[v8];
      if ( v9->mOffset )
        v10 = (char *)v9 + v9->mOffset;
      else
        v10 = 0i64;
      v11 = (UEL::Value *)(*(__int64 (__fastcall **)(char *, UFG::qString *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v10 + 24i64))(
                            v10,
                            &resulta,
                            parameters,
                            args,
                            debugStringBuilder);
      size = v21.size;
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
      UEL::Value::operator=(&v21.p[size], v11);
      ++v8;
    }
    while ( v8 < this->mNumArguments );
    v6 = result;
  }
  if ( UEL::ParametersBase::FragmentTable.mOffset )
    v15 = (char *)&UEL::ParametersBase::FragmentTable + UEL::ParametersBase::FragmentTable.mOffset;
  else
    v15 = 0i64;
  v16 = &v15[8 * this->mFragmentTableIndex];
  if ( *(_QWORD *)v16 )
    v17 = &v16[*(_QWORD *)v16];
  else
    v17 = 0i64;
  (*(void (__fastcall **)(char *, UEL::Value *, UEL::ParametersBase *, UFG::qArray<UEL::Value,0> *, UFG::qStringBuilder *))(*(_QWORD *)v17 + 24i64))(
    v17,
    v6,
    parameters,
    &v21,
    debugStringBuilder);
  v18 = UEL::Value::ToString(v6, &v23);
  UFG::qString::FormatEx(&resulta, " [%s])", v18->mData);
  UFG::qString::~qString(&resulta);
  UFG::qString::~qString(&v23);
  if ( v21.p )
  {
    p_mDetailedType = &v21.p[-1].type.mDetailedType;
    `eh vector destructor iterator(v21.p, 0x20ui64, v21.p[-1].type.mDetailedType.mUID, (void (__fastcall *)(void *))_);
    operator delete[](p_mDetailedType);
  }
  return v6;
}

