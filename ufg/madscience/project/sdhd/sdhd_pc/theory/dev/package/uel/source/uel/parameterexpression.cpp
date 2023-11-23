// File Line: 7
// RVA: 0x1475F10
__int64 dynamic_initializer_for__UEL::ParameterExpression::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ParameterExpression", 0xFFFFFFFF);
  UEL::ParameterExpression::sClassNameUID = result;
  return result;
}

// File Line: 10
// RVA: 0x1475B40
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorX__()
{
  UFG::qSymbol *v0; // rax
  int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  __int16 v4; // [rsp+48h] [rbp+10h] BYREF
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int16 v6; // [rsp+50h] [rbp+18h] BYREF
  unsigned int mUID; // [rsp+54h] [rbp+1Ch]
  __int16 *v8; // [rsp+58h] [rbp+20h]

  v8 = &v6;
  v6 = 4;
  mUID = UFG::gNullQSymbol.mUID;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "X");
  v1 = v0->mUID;
  *(_OWORD *)&UEL::ParameterExpression::VectorX.mNode.mParent = 0i64;
  qword_1423AD250 = 0i64;
  dword_1423AD258 = v1;
  dword_1423AD260 = v0->mUID;
  *(_WORD *)&stru_1423AD264.mEnableStereo = v4;
  stru_1423AD264.mLineOffset = v5;
  LOWORD(stru_1423AD264.mWidth) = v6;
  stru_1423AD264.mHeight = mUID;
  LOBYTE(stru_1423AD264.mStereo) = 0;
  HIDWORD(stru_1423AD264.mStereo) = 0;
  *(IAmdDxExt **)((char *)&stru_1423AD264.mExtension + 4) = 0i64;
  byte_1423AD288 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorX__);
}

// File Line: 11
// RVA: 0x1475C30
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorY__()
{
  UFG::qSymbol *v0; // rax
  int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  __int16 v4; // [rsp+48h] [rbp+10h] BYREF
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int16 v6; // [rsp+50h] [rbp+18h] BYREF
  unsigned int mUID; // [rsp+54h] [rbp+1Ch]
  __int16 *v8; // [rsp+58h] [rbp+20h]

  v8 = &v6;
  v6 = 4;
  mUID = UFG::gNullQSymbol.mUID;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "Y");
  v1 = v0->mUID;
  *(_OWORD *)&UEL::ParameterExpression::VectorY.mNode.mParent = 0i64;
  qword_1423AD320 = 0i64;
  dword_1423AD328 = v1;
  dword_1423AD330 = v0->mUID;
  *(_WORD *)&stru_1423AD334.mEnableStereo = v4;
  stru_1423AD334.mLineOffset = v5;
  LOWORD(stru_1423AD334.mWidth) = v6;
  stru_1423AD334.mHeight = mUID;
  LOBYTE(stru_1423AD334.mStereo) = 0;
  HIDWORD(stru_1423AD334.mStereo) = 4;
  *(IAmdDxExt **)((char *)&stru_1423AD334.mExtension + 4) = 0i64;
  byte_1423AD358 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorY__);
}

// File Line: 12
// RVA: 0x1475D20
__int64 dynamic_initializer_for__UEL::ParameterExpression::VectorZ__()
{
  UFG::qSymbol *v0; // rax
  unsigned int v1; // ecx
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF
  __int16 v4; // [rsp+48h] [rbp+10h] BYREF
  unsigned int v5; // [rsp+4Ch] [rbp+14h]
  __int16 v6; // [rsp+50h] [rbp+18h] BYREF
  unsigned int mUID; // [rsp+54h] [rbp+1Ch]
  __int16 *v8; // [rsp+58h] [rbp+20h]

  v8 = &v6;
  v6 = 4;
  mUID = UFG::gNullQSymbol.mUID;
  v4 = 4;
  v5 = UFG::gNullQSymbol.mUID;
  v0 = UFG::qSymbol::create_from_string(&result, "Z");
  v1 = v0->mUID;
  *(_OWORD *)&UEL::ParameterExpression::VectorZ.mNode.mParent = 0i64;
  unk_1423AD2D0 = 0i64;
  unk_1423AD2D8 = v1;
  unk_1423AD2E0 = v0->mUID;
  *(_WORD *)&stru_1423AD2E4.mEnableStereo = v4;
  stru_1423AD2E4.mLineOffset = v5;
  LOWORD(stru_1423AD2E4.mWidth) = v6;
  stru_1423AD2E4.mHeight = mUID;
  LOBYTE(stru_1423AD2E4.mStereo) = 0;
  HIDWORD(stru_1423AD2E4.mStereo) = 8;
  *(IAmdDxExt **)((char *)&stru_1423AD2E4.mExtension + 4) = 0i64;
  unk_1423AD308 = 0;
  _((AMD_HD3D *)&v4);
  _((AMD_HD3D *)&v6);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UEL::ParameterExpression::VectorZ__);
}

// File Line: 25
// RVA: 0x24E440
void __fastcall UEL::ParameterExpression::ParameterExpression(
        UEL::ParameterExpression *this,
        const char *name,
        UEL::Expression *withinParameter,
        UEL::Expression *arrayIndex)
{
  UFG::qOffset64<UEL::Expression *> *p_mWithinParameter; // rax
  char *v6; // r8
  UFG::qOffset64<UEL::Expression *> *p_mArrayIndex; // rax
  char *v8; // r9

  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
  this->mType.mValue = 4;
  this->mValueType.mBaseType.mValue = 0;
  this->mValueType.mDetailedType = UFG::gNullQSymbol;
  *(_DWORD *)&this->mResolved = 0;
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::ParameterExpression::`vftable;
  p_mWithinParameter = &this->mWithinParameter;
  if ( withinParameter )
    v6 = (char *)((char *)withinParameter - (char *)p_mWithinParameter);
  else
    v6 = 0i64;
  p_mWithinParameter->mOffset = (__int64)v6;
  p_mArrayIndex = &this->mArrayIndex;
  if ( arrayIndex )
    v8 = (char *)((char *)arrayIndex - (char *)p_mArrayIndex);
  else
    v8 = 0i64;
  p_mArrayIndex->mOffset = (__int64)v8;
  this->mTypeMap = 0i64;
  this->mEnumBinding = 0i64;
  *(_WORD *)&this->mArrayIndexIndexesBitField = 0;
  this->mAlwaysReturns.mBaseType.mValue = 0;
  this->mAlwaysReturns.mDetailedType = UFG::gNullQSymbol;
  UFG::qSymbol::create_from_string(&this->mName, name);
  this->mResolvedOffset = -1;
}

// File Line: 34
// RVA: 0x252E90
char __fastcall UEL::ParameterExpression::Resolve(UEL::ParameterExpression *this, UEL::Runtime *instance)
{
  UFG::qBaseTreeRB *v4; // rbp
  __int64 mOffset; // rax
  char *v6; // rcx
  UEL::ParameterBindingEntry *v7; // rbx
  __int64 v8; // rax
  UEL::Expression *v9; // rcx
  unsigned __int16 mValue; // cx
  __int64 v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  char *v14; // rdx
  unsigned int v15; // eax
  char *v16; // rcx
  bool v17; // bl
  unsigned int v18; // edx
  __int64 v19; // rax
  char *v20; // rcx
  UEL::Value::Type *p_type; // rdx
  unsigned int v22; // eax
  char *v23; // rcx
  unsigned int mUID; // edx
  UFG::qOffset64<UEL::Expression *> *p_mArrayIndex; // r14
  __int64 v26; // rax
  unsigned __int16 v27; // cx
  unsigned __int16 v28; // dx
  char v29; // al
  unsigned int v30; // eax
  char *v31; // rcx
  unsigned int v32; // esi
  UEL::Expression *v33; // rcx
  UEL::Value::Type *ValueType; // rax
  UFG::allocator::free_link *v35; // rax
  UEL::Expression *v36; // r8
  __int64 v37; // rax
  __int64 v38; // rsi
  unsigned int v39; // r15d
  UEL::Expression *v40; // rcx
  UEL::Value::Type *v41; // rax
  unsigned int v42; // r15d
  UEL::Expression *v43; // rcx
  UEL::Value::Type *v44; // rax
  char v45; // al
  char needsCall; // al
  unsigned __int16 v47; // ax
  unsigned int v48; // edx
  UFG::qBaseTreeRB *v49; // rax
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *mParameterBindings; // rax
  __int64 v52; // rax
  UEL::Expression *v53; // rcx
  unsigned int v55; // eax
  UEL::Value::Type result; // [rsp+70h] [rbp+8h] BYREF
  UEL::Value::Type v57; // [rsp+80h] [rbp+18h] BYREF

  v4 = 0i64;
  mOffset = this->mWithinParameter.mOffset;
  if ( mOffset )
  {
    v6 = (char *)&this->mWithinParameter + mOffset;
    if ( v6 )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 16i64))(v6) )
        return 0;
    }
  }
  v7 = 0i64;
  v8 = this->mWithinParameter.mOffset;
  if ( !v8 || (v9 = (UEL::Expression *)((char *)&this->mWithinParameter + v8)) == 0i64 )
  {
    mUID = this->mName.mUID;
    if ( mUID )
      v7 = (UEL::ParameterBindingEntry *)UFG::qBaseTreeRB::Get(&instance->mParameterBindings->mTree, mUID);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    if ( !v7 )
      return 0;
    this->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
    this->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
    this->mAlwaysReturns.mBaseType.mValue = v7->alwaysReturns.mBaseType.mValue;
    v22 = v7->alwaysReturns.mDetailedType.mUID;
LABEL_50:
    this->mAlwaysReturns.mDetailedType.mUID = v22;
    goto LABEL_51;
  }
  UEL::Expression::GetValueType(v9, &result);
  mValue = result.mBaseType.mValue;
  if ( result.mBaseType.mValue == 10 )
  {
    v11 = this->mWithinParameter.mOffset;
    if ( v11 )
      v12 = (char *)&this->mWithinParameter + v11;
    else
      v12 = 0i64;
    mValue = *((_WORD *)v12 + 30);
  }
  if ( (unsigned __int16)(mValue - 7) > 2u )
    return 0;
  v13 = this->mWithinParameter.mOffset;
  v14 = v13 ? (char *)&this->mWithinParameter + v13 : 0i64;
  if ( *((_WORD *)v14 + 4) != 4 )
    return 0;
  if ( mValue != 7 )
  {
    if ( mValue != 8 )
    {
      if ( mValue == 9 || mValue == 10 )
      {
        if ( v13 )
          v23 = (char *)&this->mWithinParameter + v13;
        else
          v23 = 0i64;
        this->mValueType.mBaseType.mValue = *((_WORD *)v23 + 30);
        this->mValueType.mDetailedType.mUID = *((_DWORD *)v23 + 16);
      }
      goto LABEL_51;
    }
    if ( v13 )
      v16 = (char *)&this->mWithinParameter + v13;
    else
      v16 = 0i64;
    v17 = *((_QWORD *)v16 + 5) != 0i64;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    if ( !v17 )
      return 0;
    v18 = this->mName.mUID;
    v19 = this->mWithinParameter.mOffset;
    v20 = v19 ? (char *)&this->mWithinParameter + v19 : 0i64;
    v7 = v18 ? (UEL::ParameterBindingEntry *)UFG::qBaseTreeRB::Get(*((UFG::qBaseTreeRB **)v20 + 5), v18) : 0i64;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    if ( !v7 )
      return 0;
    p_type = &v7->type;
    this->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
    this->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
    if ( (unsigned __int16)(this->mValueType.mBaseType.mValue - 9) <= 1u )
      p_type = &v7->alwaysReturns;
    this->mAlwaysReturns.mBaseType.mValue = p_type->mBaseType.mValue;
    v22 = p_type->mDetailedType.mUID;
    goto LABEL_50;
  }
  v15 = this->mName.mUID;
  if ( v15 == dword_1423AD258 )
  {
    v7 = &UEL::ParameterExpression::VectorX;
  }
  else if ( v15 == dword_1423AD328 )
  {
    v7 = &UEL::ParameterExpression::VectorY;
  }
  else
  {
    if ( v15 != unk_1423AD2D8 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
      return 0;
    }
    v7 = &UEL::ParameterExpression::VectorZ;
  }
  this->mValueType.mBaseType.mValue = v7->type.mBaseType.mValue;
  this->mValueType.mDetailedType.mUID = v7->type.mDetailedType.mUID;
LABEL_51:
  p_mArrayIndex = &this->mArrayIndex;
  v26 = this->mArrayIndex.mOffset;
  if ( v26 && (UFG::qOffset64<UEL::Expression *> *)((char *)p_mArrayIndex + v26) )
  {
    v27 = this->mValueType.mBaseType.mValue;
    if ( v27 <= 0xCu )
      return 0;
    if ( v27 == 23 && UFG::gNullQSymbol.mUID == this->mValueType.mDetailedType.mUID )
      v28 = 5;
    else
      v28 = v27 - 12;
    if ( v27 != 23 || (v29 = 1, UFG::gNullQSymbol.mUID != this->mValueType.mDetailedType.mUID) )
      v29 = 0;
    this->mArrayIndexIndexesBitField = v29;
    v30 = UFG::gNullQSymbol.mUID;
    this->mValueType.mBaseType.mValue = v28;
    this->mValueType.mDetailedType.mUID = v30;
    v31 = (char *)p_mArrayIndex + p_mArrayIndex->mOffset;
    if ( !p_mArrayIndex->mOffset )
      v31 = 0i64;
    (*(void (__fastcall **)(char *, UEL::Runtime *))(*(_QWORD *)v31 + 16i64))(v31, instance);
    v32 = UFG::gNullQSymbol.mUID;
    v33 = (UEL::Expression *)((char *)p_mArrayIndex + p_mArrayIndex->mOffset);
    if ( !p_mArrayIndex->mOffset )
      v33 = 0i64;
    ValueType = UEL::Expression::GetValueType(v33, &result);
    if ( ValueType->mBaseType.mValue == 6 && v32 == ValueType->mDetailedType.mUID )
    {
      v35 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      result = (UEL::Value::Type)v35;
      if ( v35 )
      {
        v36 = (UEL::Expression *)((char *)p_mArrayIndex + p_mArrayIndex->mOffset);
        if ( !p_mArrayIndex->mOffset )
          v36 = 0i64;
        UEL::UnaryExpression::UnaryExpression((UEL::UnaryExpression *)v35, CastToInteger, v36);
        v38 = v37;
      }
      else
      {
        v38 = 0i64;
      }
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, UEL::Runtime *))(*(_QWORD *)v38 + 16i64))(v38, instance) )
        return 0;
      p_mArrayIndex->mOffset = v38 - (_QWORD)p_mArrayIndex;
    }
    v39 = UFG::gNullQSymbol.mUID;
    v40 = (UEL::Expression *)((char *)p_mArrayIndex + p_mArrayIndex->mOffset);
    if ( !p_mArrayIndex->mOffset )
      v40 = 0i64;
    v41 = UEL::Expression::GetValueType(v40, &result);
    if ( v41->mBaseType.mValue == 1 && v39 == v41->mDetailedType.mUID )
      goto LABEL_82;
    v42 = UFG::gNullQSymbol.mUID;
    v43 = (UEL::Expression *)((char *)p_mArrayIndex + p_mArrayIndex->mOffset);
    if ( !p_mArrayIndex->mOffset )
      v43 = 0i64;
    v44 = UEL::Expression::GetValueType(v43, &v57);
    if ( v44->mBaseType.mValue == 6 && v42 == v44->mDetailedType.mUID )
LABEL_82:
      v45 = 1;
    else
      v45 = 0;
    if ( !v45 )
      return 0;
  }
  if ( v7 )
    needsCall = v7->needsCall;
  else
    needsCall = 0;
  this->mNeedsCall = needsCall;
  v47 = this->mValueType.mBaseType.mValue;
  if ( v47 == 8 )
  {
    this->mTypeMap = v7->parameterNameToDataMap;
    goto LABEL_105;
  }
  if ( this->mAlwaysReturns.mBaseType.mValue == 8 )
  {
    v48 = this->mAlwaysReturns.mDetailedType.mUID;
    if ( v48 && (v49 = UFG::qBaseTreeRB::Get(&instance->mParameterBindings->mTree, v48)) != 0i64 )
      mParameterBindings = *(UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> **)&v49->mCount;
    else
      mParameterBindings = instance->mParameterBindings;
    this->mTypeMap = mParameterBindings;
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mAlwaysReturns.mDetailedType);
    if ( !this->mTypeMap )
      return 0;
    goto LABEL_105;
  }
  if ( v47 )
  {
    v52 = this->mWithinParameter.mOffset;
    if ( !v52
      || (v53 = (UEL::Expression *)((char *)&this->mWithinParameter + v52)) == 0i64
      || UEL::Expression::GetValueType(v53, &result)->mBaseType.mValue != 9 )
    {
LABEL_105:
      this->mResolvedOffset = v7->offset;
      goto LABEL_106;
    }
  }
  this->mResolvedOffset = 0;
LABEL_106:
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  if ( this->mResolvedOffset == -1 )
    return 0;
  if ( this->mValueType.mBaseType.mValue == 6 )
  {
    v55 = this->mValueType.mDetailedType.mUID;
    if ( UFG::gNullQSymbol.mUID == v55 )
    {
      if ( v55 )
        v4 = UFG::qBaseTreeRB::Get(&instance->mEnumBindings->mTree, v55);
      this->mEnumBinding = (UEL::EnumBindingEntry *)v4;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
      if ( !this->mEnumBinding )
        return 0;
    }
  }
  this->mResolved = 1;
  return 1;
}

// File Line: 183
// RVA: 0x2512C0
UEL::Value *__fastcall UEL::ParameterExpression::Eval(
        UEL::ParameterExpression *this,
        UEL::Value *result,
        UEL::ParametersBase *parameters,
        UFG::qArray<UEL::Value,0> *args)
{
  UFG::qSymbolUC *v6; // r12
  int v7; // ebx
  bool v8; // r15
  __int64 mOffset; // rax
  char *v10; // rcx
  unsigned int mUID; // eax
  __int64 *v12; // r13
  __int64 v13; // rax
  UEL::Expression *v14; // rcx
  char *v15; // rax
  UFG::qSymbol *v16; // r8
  __int64 mResolvedOffset; // rax
  _QWORD **v18; // rdi
  __int64 v19; // rax
  __int64 v20; // r15
  UEL::Value::Type *ValueType; // rax
  __int64 SizeOfValueType; // rdi
  __int64 v23; // rcx
  char *v24; // rcx
  UEL::Value *v25; // rax
  UFG::qSymbolUC *v26; // rax
  __int64 v27; // rax
  UEL::Expression *v28; // rcx
  unsigned int v29; // r13d
  UEL::Value::Type *v30; // rax
  bool v31; // al
  UEL::Value *v32; // rax
  unsigned int v33; // edi
  int v34; // ebx
  UEL::Value::Type *v35; // rax
  __int64 v36; // rax
  UFG::qSymbolUC *v37; // rax
  UEL::Value::Type *v38; // rax
  __int64 *v39; // rax
  unsigned int v40; // edx
  const char *v41; // rdx
  __int64 v42; // rax
  int *v43; // rax
  __int64 v44; // r8
  int v45; // eax
  unsigned __int64 v46; // rcx
  _QWORD *v47; // rax
  __int64 v48; // rcx
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  unsigned int v52; // xmm0_4
  UFG::qString *v53; // rax
  UEL::Value::Type v55; // [rsp+30h] [rbp-79h] BYREF
  UEL::Value v56; // [rsp+38h] [rbp-71h] BYREF
  UEL::Value::Type p_resulta; // [rsp+58h] [rbp-51h] BYREF
  UEL::Value::Type p_p_resulta; // [rsp+60h] [rbp-49h] BYREF
  __int64 v59[2]; // [rsp+70h] [rbp-39h] BYREF
  __int16 v60; // [rsp+84h] [rbp-25h]
  __int64 v61; // [rsp+90h] [rbp-19h]
  UFG::qString v62; // [rsp+98h] [rbp-11h] BYREF
  UEL::Value::Type resulta; // [rsp+108h] [rbp+5Fh] BYREF
  __int64 v64; // [rsp+118h] [rbp+6Fh]
  __int64 v65; // [rsp+120h] [rbp+77h]
  __int64 v66; // [rsp+128h] [rbp+7Fh]

  v61 = -2i64;
  v6 = 0i64;
  v7 = 0;
  *(_DWORD *)&v55.mBaseType.mValue = 0;
  v56.type.mBaseType.mValue = 0;
  v56.type.mDetailedType = UFG::gNullQSymbol;
  v8 = 0;
  mOffset = this->mWithinParameter.mOffset;
  if ( mOffset && (v10 = (char *)&this->mWithinParameter + mOffset) != 0i64 )
  {
    (*(void (__fastcall **)(char *, __int64 *))(*(_QWORD *)v10 + 24i64))(v10, v59);
    switch ( v60 )
    {
      case 0:
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
LABEL_5:
        result->type.mBaseType.mValue = 0;
        mUID = UFG::gNullQSymbol.mUID;
        goto LABEL_82;
      case 8:
        v12 = (__int64 *)v59[0];
        v13 = this->mWithinParameter.mOffset;
        if ( v13 )
          v14 = (UEL::Expression *)((char *)&this->mWithinParameter + v13);
        else
          v14 = 0i64;
        v8 = UEL::Expression::GetValueType(v14, &resulta)->mBaseType.mValue == 10;
        break;
      case 9:
        v12 = (__int64 *)v59[0];
        break;
      default:
        v12 = v59;
        v8 = 1;
        break;
    }
  }
  else
  {
    v12 = (__int64 *)parameters;
  }
  v15 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  UFG::qString::FormatEx((UFG::qString *)&v56.qVector_w, "(\"%s\"", v15);
  UFG::qString::~qString((UFG::qString *)&v56.qVector_w);
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
  if ( !v12 )
    goto LABEL_5;
  mResolvedOffset = this->mResolvedOffset;
  if ( (_DWORD)mResolvedOffset == -1 )
    goto LABEL_5;
  v18 = (_QWORD **)((char *)v12 + mResolvedOffset);
  v19 = this->mArrayIndex.mOffset;
  if ( v19
    && (UFG::qOffset64<UEL::Expression *> *)((char *)&this->mArrayIndex + v19)
    && !this->mArrayIndexIndexesBitField )
  {
    v20 = (__int64)*v18;
    p_resulta = (UEL::Value::Type)&resulta;
    ValueType = UEL::Expression::GetValueType(this, &resulta);
    SizeOfValueType = UEL::Value::GetSizeOfValueType((UEL::Value::Type)ValueType);
    v23 = this->mArrayIndex.mOffset;
    if ( v23 )
      v24 = (char *)&this->mArrayIndex + v23;
    else
      v24 = 0i64;
    v18 = (_QWORD **)(v20
                    + *(_QWORD *)(*(__int64 (__fastcall **)(char *, UFG::qString *, __int64, __int64, __int64))(*(_QWORD *)v24 + 24i64))(
                                   v24,
                                   &v62,
                                   v64,
                                   v65,
                                   v66)
                    * SizeOfValueType);
    v8 = 1;
  }
  if ( this->mNeedsCall )
  {
    v25 = fastdelegate::FastDelegate0<UEL::Value>::operator()(
            (fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *)v18,
            (UEL::Value *)&v56.qVector_w,
            v16);
    UEL::Value::operator=(&v56, v25);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
    p_p_resulta = (UEL::Value::Type)&p_resulta;
    UEL::Expression::GetValueType(this, &p_resulta);
    p_p_resulta = (UEL::Value::Type)&resulta;
    resulta.mBaseType.mValue = v56.type.mBaseType.mValue;
    resulta.mDetailedType.mUID = v56.type.mDetailedType.mUID;
    v26 = (UFG::qSymbolUC *)UEL::Expression::GetValueType(this, &v55);
    UFG::qSymbol::as_cstr_dbg(v26 + 1);
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v56.type.mDetailedType);
  }
  else
  {
    v27 = this->mWithinParameter.mOffset;
    v31 = 0;
    if ( v27 )
    {
      v28 = (UEL::Expression *)((char *)&this->mWithinParameter + v27);
      if ( v28 )
      {
        v29 = UFG::gNullQSymbol.mUID;
        v7 = 3;
        *(_DWORD *)&v55.mBaseType.mValue = 3;
        v30 = UEL::Expression::GetValueType(v28, &v55);
        if ( v30->mBaseType.mValue == 9 && v29 == v30->mDetailedType.mUID )
          v31 = 1;
      }
    }
    if ( (v7 & 2) != 0 )
    {
      v7 &= ~2u;
      *(_DWORD *)&v55.mBaseType.mValue = v7;
    }
    if ( (v7 & 1) != 0 )
    {
      v7 &= ~1u;
      *(_DWORD *)&v55.mBaseType.mValue = v7;
    }
    if ( v31 )
    {
      v32 = fastdelegate::FastDelegate0<UEL::Value>::operator()(
              (fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *)v18,
              (UEL::Value *)&v56.qVector_w,
              &this->mName);
      UEL::Value::operator=(&v56, v32);
      v33 = UFG::gNullQSymbol.mUID;
      v34 = v7 | 0xC;
      *(_DWORD *)&v55.mBaseType.mValue = v34;
      v35 = UEL::Expression::GetValueType(this, &v55);
      if ( v35->mBaseType.mValue || v33 != v35->mDetailedType.mUID )
      {
        v34 |= 0x10u;
        *(_DWORD *)&v55.mBaseType.mValue = v34;
        UEL::Expression::GetValueType(this, &p_p_resulta);
      }
      v36 = this->mWithinParameter.mOffset;
      if ( v36 )
        v6 = (UFG::qSymbolUC *)((char *)&this->mWithinParameter + v36);
      UFG::qSymbol::as_cstr_dbg(v6 + 17);
      v56.integer = (__int64)&p_resulta;
      UEL::Expression::GetValueType(this, &p_resulta);
      v56.integer = (__int64)&resulta;
      resulta.mBaseType.mValue = v56.type.mBaseType.mValue;
      resulta.mDetailedType.mUID = v56.type.mDetailedType.mUID;
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
      v37 = (UFG::qSymbolUC *)UEL::Expression::GetValueType(this, (UEL::Value::Type *)&v56.qVector_y);
      UFG::qSymbol::as_cstr_dbg(v37 + 1);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v56.type.mDetailedType);
      if ( (v34 & 0x10) != 0 )
      {
        v34 &= ~0x10u;
        *(_DWORD *)&v55.mBaseType.mValue = v34;
      }
      if ( (v34 & 8) != 0 )
      {
        v34 &= ~8u;
        *(_DWORD *)&v55.mBaseType.mValue = v34;
      }
      if ( (v34 & 4) != 0 )
        *(_DWORD *)&v55.mBaseType.mValue = v34 & 0xFFFFFFFB;
    }
    else
    {
      v38 = UEL::Expression::GetValueType(this, (UEL::Value::Type *)&v56.qVector_y);
      v56.type.mBaseType.mValue = v38->mBaseType.mValue;
      v56.type.mDetailedType.mUID = v38->mDetailedType.mUID;
      switch ( v56.type.mBaseType.mValue )
      {
        case 1u:
          v39 = *v18;
          if ( v8 )
            goto LABEL_79;
          v56.integer = *v39;
          break;
        case 2u:
          if ( v8 )
            v40 = *(_DWORD *)v18;
          else
            v40 = *(_DWORD *)*v18;
          v56.type.mBaseType.mValue = 2;
          v56.type.mDetailedType = UFG::gNullQSymbol;
          LODWORD(v56.integer) = (UFG::qWiseSymbol)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&resulta, v40)->mUID;
          break;
        case 3u:
          if ( v8 )
            v41 = (const char *)*v18;
          else
            v41 = (const char *)**v18;
          v56.type.mBaseType.mValue = 2;
          v56.type.mDetailedType = UFG::gNullQSymbol;
          LODWORD(v56.integer) = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&resulta, v41)->mUID;
          break;
        case 4u:
          if ( v8 )
            v56.qSymbol_mUID = *(_DWORD *)v18;
          else
            v56.qSymbol_mUID = *(_DWORD *)*v18;
          break;
        case 5u:
          if ( this->mArrayIndexIndexesBitField )
          {
            v42 = this->mArrayIndex.mOffset;
            if ( v42 )
              v6 = (UFG::qSymbolUC *)((char *)&this->mArrayIndex + v42);
            v43 = (int *)(*(__int64 (__fastcall **)(UFG::qSymbolUC *, float *, __int64, __int64, __int64))(*(_QWORD *)&v6->mUID + 24i64))(
                           v6,
                           &v56.qVector_w,
                           v64,
                           v65,
                           v66);
            v44 = *v43;
            v45 = *v43 & 0x3F;
            if ( v8 )
            {
              v46 = (unsigned __int8)v45;
              v47 = v18[v44 >> 6];
              v56.boolean = _bittest64((const __int64 *)&v47, v46);
            }
            else
            {
              v48 = (*v18)[v44 >> 6];
              v56.boolean = _bittest64(&v48, (unsigned __int8)v45);
            }
          }
          else if ( v8 )
          {
            v56.boolean = *(_BYTE *)v18 != 0;
          }
          else
          {
            v56.boolean = *(_BYTE *)*v18 != 0;
          }
          break;
        case 6u:
          if ( v8 )
            v56.qSymbol_mUID = *(_DWORD *)v18;
          else
            v56.qSymbol_mUID = *(_DWORD *)*v18;
          v56.type.mDetailedType.mUID = this->mEnumBinding->name.mUID;
          break;
        case 7u:
          if ( !v8 )
            v18 = (_QWORD **)*v18;
          v49 = *((float *)v18 + 3);
          v50 = *((float *)v18 + 2);
          v51 = *((float *)v18 + 1);
          v52 = *(_DWORD *)v18;
          v56.type.mBaseType.mValue = 7;
          v56.type.mDetailedType = UFG::gNullQSymbol;
          v56.qSymbol_mUID = v52;
          v56.qVector_y = v51;
          v56.qVector_z = v50;
          v56.qVector_w = v49;
          break;
        case 8u:
          v39 = *v18;
LABEL_79:
          v56.integer = (__int64)v39;
          break;
        case 9u:
          v56.integer = (__int64)v18;
          break;
        default:
          break;
      }
    }
  }
  v53 = UEL::Value::ToString(&v56, &v62);
  UFG::qString::FormatEx((UFG::qString *)&v56.qVector_w, " [%s])", v53->mData);
  UFG::qString::~qString((UFG::qString *)&v56.qVector_w);
  UFG::qString::~qString(&v62);
  result->integer = v56.integer;
  result->qSymbol_mUID = v56.qSymbol_mUID;
  result->qVector_y = v56.qVector_y;
  result->qVector_z = v56.qVector_z;
  result->qVector_w = v56.qVector_w;
  result->type.mBaseType.mValue = v56.type.mBaseType.mValue;
  mUID = v56.type.mDetailedType.mUID;
LABEL_82:
  result->type.mDetailedType.mUID = mUID;
  return result;
}

